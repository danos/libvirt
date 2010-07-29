/*
 * Copyright IBM Corp. 2008
 * Copyright Red Hat 2008
 *
 * lxc_container.c: file description
 *
 * Authors:
 *  David L. Leskovec <dlesko at linux.vnet.ibm.com>
 *  Daniel P. Berrange <berrange@redhat.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include <config.h>

#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/mount.h>
#include <sys/wait.h>
#include <unistd.h>
#include <mntent.h>

/* Yes, we want linux private one, for _syscall2() macro */
#include <linux/unistd.h>

/* For MS_MOVE */
#include <linux/fs.h>

#include "lxc_container.h"
#include "util.h"
#include "memory.h"
#include "veth.h"

#define DEBUG(fmt,...) VIR_DEBUG(__FILE__, fmt, __VA_ARGS__)
#define DEBUG0(msg) VIR_DEBUG(__FILE__, "%s", msg)

/*
 * GLibc headers are behind the kernel, so we define these
 * constants if they're not present already.
 */

#ifndef CLONE_NEWPID
#define CLONE_NEWPID  0x20000000
#endif
#ifndef CLONE_NEWUTS
#define CLONE_NEWUTS  0x04000000
#endif
#ifndef CLONE_NEWUSER
#define CLONE_NEWUSER 0x10000000
#endif
#ifndef CLONE_NEWIPC
#define CLONE_NEWIPC  0x08000000
#endif
#ifndef CLONE_NEWNET
#define CLONE_NEWNET  0x40000000 /* New network namespace */
#endif

/* messages between parent and container */
typedef char lxc_message_t;
#define LXC_CONTINUE_MSG 'c'

typedef struct __lxc_child_argv lxc_child_argv_t;
struct __lxc_child_argv {
    virDomainDefPtr config;
    unsigned int nveths;
    char **veths;
    int monitor;
    char *ttyPath;
};


/**
 * lxcContainerExecInit:
 * @vmDef: Ptr to vm definition structure
 *
 * Exec the container init string. The container init will replace then
 * be running in the current process
 *
 * Does not return
 */
static int lxcContainerExecInit(virDomainDefPtr vmDef)
{
    const char *const argv[] = {
        vmDef->os.init,
        NULL,
    };

    return execve(argv[0], (char **)argv, NULL);
}

/**
 * lxcContainerSetStdio:
 * @control: the conrol FD
 * @ttyPath: Name of tty to set as the container console
 *
 * Sets the given tty as the primary conosole for the container as well as
 * stdout, stdin and stderr.
 *
 * Returns 0 on success or -1 in case of error
 */
static int lxcContainerSetStdio(int control, int ttyfd)
{
    int rc = -1;
    int open_max, i;

    if (setsid() < 0) {
        lxcError(NULL, NULL, VIR_ERR_INTERNAL_ERROR,
                 _("setsid failed: %s"), strerror(errno));
        goto cleanup;
    }

    if (ioctl(ttyfd, TIOCSCTTY, NULL) < 0) {
        lxcError(NULL, NULL, VIR_ERR_INTERNAL_ERROR,
                 _("ioctl(TIOCSTTY) failed: %s"), strerror(errno));
        goto cleanup;
    }

    /* Just in case someone forget to set FD_CLOEXEC, explicitly
     * close all FDs before executing the container */
    open_max = sysconf (_SC_OPEN_MAX);
    for (i = 0; i < open_max; i++)
        if (i != ttyfd && i != control)
            close(i);

    if (dup2(ttyfd, 0) < 0) {
        lxcError(NULL, NULL, VIR_ERR_INTERNAL_ERROR,
                 _("dup2(stdin) failed: %s"), strerror(errno));
        goto cleanup;
    }

    if (dup2(ttyfd, 1) < 0) {
        lxcError(NULL, NULL, VIR_ERR_INTERNAL_ERROR,
                 _("dup2(stdout) failed: %s"), strerror(errno));
        goto cleanup;
    }

    if (dup2(ttyfd, 2) < 0) {
        lxcError(NULL, NULL, VIR_ERR_INTERNAL_ERROR,
                 _("dup2(stderr) failed: %s"), strerror(errno));
        goto cleanup;
    }

    rc = 0;

cleanup:
    return rc;
}

/**
 * lxcContainerSendContinue:
 * @monitor: control FD to child
 *
 * Sends the continue message via the socket pair stored in the vm
 * structure.
 *
 * Returns 0 on success or -1 in case of error
 */
int lxcContainerSendContinue(int control)
{
    int rc = -1;
    lxc_message_t msg = LXC_CONTINUE_MSG;
    int writeCount = 0;

    writeCount = safewrite(control, &msg, sizeof(msg));
    if (writeCount != sizeof(msg)) {
        lxcError(NULL, NULL, VIR_ERR_INTERNAL_ERROR,
                 _("unable to send container continue message: %s"),
                 strerror(errno));
        goto error_out;
    }

    rc = 0;

error_out:
    return rc;
}

/**
 * lxcContainerWaitForContinue:
 * @control: control FD from parent
 *
 * This function will wait for the container continue message from the
 * parent process.  It will send this message on the socket pair stored in
 * the vm structure once it has completed the post clone container setup.
 *
 * Returns 0 on success or -1 in case of error
 */
static int lxcContainerWaitForContinue(int control)
{
    lxc_message_t msg;
    int readLen;

    readLen = saferead(control, &msg, sizeof(msg));
    if (readLen != sizeof(msg) ||
        msg != LXC_CONTINUE_MSG) {
        lxcError(NULL, NULL, VIR_ERR_INTERNAL_ERROR,
                 _("Failed to read the container continue message: %s"),
                 strerror(errno));
        return -1;
    }
    close(control);

    DEBUG0("Received container continue message");

    return 0;
}


/**
 * lxcEnableInterfaces:
 * @vm: Pointer to vm structure
 *
 * This function will enable the interfaces for this container.
 *
 * Returns 0 on success or nonzero in case of error
 */
static int lxcContainerEnableInterfaces(unsigned int nveths,
                                        char **veths)
{
    int rc = 0;
    unsigned int i;

    for (i = 0 ; i < nveths ; i++) {
        DEBUG("Enabling %s", veths[i]);
        rc =  vethInterfaceUpOrDown(veths[i], 1);
        if (0 != rc) {
            goto error_out;
        }
    }

    /* enable lo device only if there were other net devices */
    if (veths)
        rc = vethInterfaceUpOrDown("lo", 1);

error_out:
    return rc;
}


//_syscall2(int, pivot_root, char *, newroot, const char *, oldroot)
extern int pivot_root(const char * new_root,const char * put_old);

static int lxcContainerChildMountSort(const void *a, const void *b)
{
  const char **sa = (const char**)a;
  const char **sb = (const char**)b;

  /* Delibrately reversed args - we need to unmount deepest
     children first */
  return strcmp(*sb, *sa);
}

static int lxcContainerPivotRoot(virDomainFSDefPtr root)
{
    char *oldroot;

    /* First step is to ensure the new root itself is
       a mount point */
    if (mount(root->src, root->src, NULL, MS_BIND, NULL) < 0) {
        lxcError(NULL, NULL, VIR_ERR_INTERNAL_ERROR,
                 _("failed to bind new root %s: %s"),
                 root->src, strerror(errno));
        return -1;
    }

    if (asprintf(&oldroot, "%s/.oldroot", root->src) < 0) {
        oldroot = NULL;
        lxcError(NULL, NULL, VIR_ERR_NO_MEMORY, NULL);
        return -1;
    }

    if (virFileMakePath(oldroot) < 0) {
        VIR_FREE(oldroot);
        lxcError(NULL, NULL, VIR_ERR_INTERNAL_ERROR,
                 _("failed to create %s: %s"),
                 oldroot, strerror(errno));
        return -1;
    }

    /* The old root directory will live at /.oldroot after
     * this and will soon be unmounted completely */
    if (pivot_root(root->src, oldroot) < 0) {
        VIR_FREE(oldroot);
        lxcError(NULL, NULL, VIR_ERR_INTERNAL_ERROR,
                 _("failed to pivot root %s to %s: %s"),
                 oldroot, root->src, strerror(errno));
        return -1;
    }
    VIR_FREE(oldroot);

    /* CWD is undefined after pivot_root, so go to / */
    if (chdir("/") < 0) {
        return -1;
    }

    return 0;
}

static int lxcContainerPopulateDevices(void)
{
    int i;
    const struct {
        int maj;
        int min;
        mode_t mode;
        const char *path;
    } devs[] = {
        { 1, 3, 0666, "/dev/null" },
        { 1, 5, 0666, "/dev/zero" },
        { 1, 7, 0666, "/dev/full" },
        { 5, 1, 0600, "/dev/console" },
        { 1, 8, 0666, "/dev/random" },
        { 1, 9, 0666, "/dev/urandom" },
    };

    if (virFileMakePath("/dev") < 0 ||
        mount("none", "/dev", "tmpfs", 0, NULL) < 0) {
        lxcError(NULL, NULL, VIR_ERR_INTERNAL_ERROR,
                 _("failed to mount /dev tmpfs for container: %s"),
                 strerror(errno));
        return -1;
    }
    /* Move old devpts into container, since we have to
       connect to the master ptmx which was opened in
       the parent.
       XXX This sucks, we need to figure out how to get our
       own private devpts for isolation
    */
    if (virFileMakePath("/dev/pts") < 0 ||
        mount("/.oldroot/dev/pts", "/dev/pts", NULL,
              MS_MOVE, NULL) < 0) {
        lxcError(NULL, NULL, VIR_ERR_INTERNAL_ERROR,
                 _("failed to move /dev/pts into container: %s"),
                 strerror(errno));
        return -1;
    }

    /* Populate /dev/ with a few important bits */
    for (i = 0 ; i < ARRAY_CARDINALITY(devs) ; i++) {
        dev_t dev = makedev(devs[i].maj, devs[i].min);
        if (mknod(devs[i].path, 0, dev) < 0 ||
            chmod(devs[i].path, devs[i].mode)) {
            lxcError(NULL, NULL, VIR_ERR_INTERNAL_ERROR,
                     _("failed to make device %s: %s"),
                     devs[i].path, strerror(errno));
            return -1;
        }
    }

    return 0;
}


static int lxcContainerMountNewFS(virDomainDefPtr vmDef)
{
    virDomainFSDefPtr tmp;

    /* Pull in rest of container's mounts */
    for (tmp = vmDef->fss; tmp; tmp = tmp->next) {
        char *src;
        if (STREQ(tmp->dst, "/"))
            continue;
        // XXX fix
        if (tmp->type != VIR_DOMAIN_FS_TYPE_MOUNT)
            continue;

        if (asprintf(&src, "/.oldroot/%s", tmp->src) < 0) {
            lxcError(NULL, NULL, VIR_ERR_NO_MEMORY, NULL);
            return -1;
        }

        if (virFileMakePath(tmp->dst) < 0 ||
            mount(src, tmp->dst, NULL, MS_BIND, NULL) < 0) {
            VIR_FREE(src);
            lxcError(NULL, NULL, VIR_ERR_INTERNAL_ERROR,
                     _("failed to mount %s at %s for container: %s"),
                     tmp->src, tmp->dst, strerror(errno));
            return -1;
        }
        VIR_FREE(src);
    }

    return 0;
}


static int lxcContainerUnmountOldFS(void)
{
    struct mntent *mntent;
    char **mounts = NULL;
    int nmounts = 0;
    FILE *procmnt;
    int i;

    if (!(procmnt = setmntent("/proc/mounts", "r"))) {
        lxcError(NULL, NULL, VIR_ERR_INTERNAL_ERROR,
                 _("failed to read /proc/mounts: %s"),
                 strerror(errno));
        return -1;
    }
    while ((mntent = getmntent(procmnt)) != NULL) {
        if (!STRPREFIX(mntent->mnt_dir, "/.oldroot"))
            continue;

        if (VIR_REALLOC_N(mounts, nmounts+1) < 0) {
            endmntent(procmnt);
            lxcError(NULL, NULL, VIR_ERR_NO_MEMORY, NULL);
            return -1;
        }
        if (!(mounts[nmounts++] = strdup(mntent->mnt_dir))) {
            endmntent(procmnt);
            lxcError(NULL, NULL, VIR_ERR_NO_MEMORY, NULL);
            return -1;
        }
    }
    endmntent(procmnt);

    qsort(mounts, nmounts, sizeof(mounts[0]),
          lxcContainerChildMountSort);

    for (i = 0 ; i < nmounts ; i++) {
        if (umount(mounts[i]) < 0) {
            lxcError(NULL, NULL, VIR_ERR_INTERNAL_ERROR,
                     _("failed to unmount %s: %s"),
                     mounts[i], strerror(errno));
            return -1;
        }
        VIR_FREE(mounts[i]);
    }
    VIR_FREE(mounts);

    return 0;
}


/* Got a FS mapped to /, we're going the pivot_root
 * approach to do a better-chroot-than-chroot
 * this is based on this thread http://lkml.org/lkml/2008/3/5/29
 */
static int lxcContainerSetupPivotRoot(virDomainDefPtr vmDef,
                                      virDomainFSDefPtr root)
{
    if (lxcContainerPivotRoot(root) < 0)
        return -1;

    if (virFileMakePath("/proc") < 0 ||
        mount("none", "/proc", "proc", 0, NULL) < 0) {
        lxcError(NULL, NULL, VIR_ERR_INTERNAL_ERROR,
                 _("failed to mount /proc for container: %s"),
                 strerror(errno));
        return -1;
    }

    if (lxcContainerPopulateDevices() < 0)
        return -1;

    if (lxcContainerMountNewFS(vmDef) < 0)
        return -1;

    if (lxcContainerUnmountOldFS() < 0)
        return -1;

    return 0;
}

/* Nothing mapped to /, we're using the main root,
   but with extra stuff mapped in */
static int lxcContainerSetupExtraMounts(virDomainDefPtr vmDef)
{
    virDomainFSDefPtr tmp;

    for (tmp = vmDef->fss; tmp; tmp = tmp->next) {
        // XXX fix to support other mount types
        if (tmp->type != VIR_DOMAIN_FS_TYPE_MOUNT)
            continue;

        if (mount(tmp->src,
                  tmp->dst,
                  NULL,
                  MS_BIND,
                  NULL) < 0) {
            lxcError(NULL, NULL, VIR_ERR_INTERNAL_ERROR,
                     _("failed to mount %s at %s for container: %s"),
                     tmp->src, tmp->dst, strerror(errno));
            return -1;
        }
    }

    /* mount /proc */
    if (mount("lxcproc", "/proc", "proc", 0, NULL) < 0) {
        lxcError(NULL, NULL, VIR_ERR_INTERNAL_ERROR,
                 _("failed to mount /proc for container: %s"),
                 strerror(errno));
        return -1;
    }

    return 0;
}

static int lxcContainerSetupMounts(virDomainDefPtr vmDef)
{
    virDomainFSDefPtr tmp;
    virDomainFSDefPtr root = NULL;

    for (tmp = vmDef->fss; tmp && !root; tmp = tmp->next) {
        if (tmp->type != VIR_DOMAIN_FS_TYPE_MOUNT)
            continue;
        if (STREQ(tmp->dst, "/"))
            root = tmp;
    }

    if (root)
        return lxcContainerSetupPivotRoot(vmDef, root);
    else
        return lxcContainerSetupExtraMounts(vmDef);
}

/**
 * lxcChild:
 * @argv: Pointer to container arguments
 *
 * This function is run in the process clone()'d in lxcStartContainer.
 * Perform a number of container setup tasks:
 *     Setup container file system
 *     mount container /proca
 * Then exec's the container init
 *
 * Returns 0 on success or -1 in case of error
 */
static int lxcContainerChild( void *data )
{
    lxc_child_argv_t *argv = data;
    virDomainDefPtr vmDef = argv->config;
    int ttyfd;

    if (NULL == vmDef) {
        lxcError(NULL, NULL, VIR_ERR_INTERNAL_ERROR,
                 _("lxcChild() passed invalid vm definition"));
        return -1;
    }

    if (lxcContainerSetupMounts(vmDef) < 0)
        return -1;

    ttyfd = open(argv->ttyPath, O_RDWR|O_NOCTTY);
    if (ttyfd < 0) {
        lxcError(NULL, NULL, VIR_ERR_INTERNAL_ERROR,
                 _("open(%s) failed: %s"), argv->ttyPath, strerror(errno));
        return -1;
    }

    if (lxcContainerSetStdio(argv->monitor, ttyfd) < 0) {
        close(ttyfd);
        return -1;
    }
    close(ttyfd);

    /* Wait for interface devices to show up */
    if (lxcContainerWaitForContinue(argv->monitor) < 0)
        return -1;

    /* enable interfaces */
    if (lxcContainerEnableInterfaces(argv->nveths, argv->veths) < 0)
        return -1;

    /* this function will only return if an error occured */
    return lxcContainerExecInit(vmDef);
}

/**
 * lxcContainerStart:
 * @driver: pointer to driver structure
 * @vm: pointer to virtual machine structure
 *
 * Starts a container process by calling clone() with the namespace flags
 *
 * Returns PID of container on success or -1 in case of error
 */
int lxcContainerStart(virDomainDefPtr def,
                      unsigned int nveths,
                      char **veths,
                      int control,
                      char *ttyPath)
{
    pid_t pid;
    int flags;
    int stacksize = getpagesize() * 4;
    char *stack, *stacktop;
    lxc_child_argv_t args = { def, nveths, veths, control, ttyPath };

    /* allocate a stack for the container */
    if (VIR_ALLOC_N(stack, stacksize) < 0) {
        lxcError(NULL, NULL, VIR_ERR_NO_MEMORY, NULL);
        return -1;
    }
    stacktop = stack + stacksize;

    flags = CLONE_NEWPID|CLONE_NEWNS|CLONE_NEWUTS|CLONE_NEWUSER|CLONE_NEWIPC|SIGCHLD;

    if (def->nets != NULL)
        flags |= CLONE_NEWNET;

    pid = clone(lxcContainerChild, stacktop, flags, &args);
    VIR_FREE(stack);
    DEBUG("clone() returned, %d", pid);

    if (pid < 0) {
        lxcError(NULL, NULL, VIR_ERR_INTERNAL_ERROR,
                 _("clone() failed, %s"), strerror(errno));
        return -1;
    }

    return pid;
}

static int lxcContainerDummyChild(void *argv ATTRIBUTE_UNUSED)
{
    _exit(0);
}

int lxcContainerAvailable(int features)
{
    int flags = CLONE_NEWPID|CLONE_NEWNS|CLONE_NEWUTS|CLONE_NEWUSER|
        CLONE_NEWIPC|SIGCHLD;
    int cpid;
    char *childStack;
    char *stack;
    int childStatus;

    if (features & LXC_CONTAINER_FEATURE_NET)
        flags |= CLONE_NEWNET;

    if (VIR_ALLOC_N(stack, getpagesize() * 4) < 0) {
        DEBUG0("Unable to allocate stack");
        return -1;
    }

    childStack = stack + (getpagesize() * 4);

    cpid = clone(lxcContainerDummyChild, childStack, flags, NULL);
    VIR_FREE(stack);
    if (cpid < 0) {
        DEBUG("clone call returned %s, container support is not enabled",
              strerror(errno));
        return -1;
    } else {
        waitpid(cpid, &childStatus, 0);
    }

    return 0;
}
