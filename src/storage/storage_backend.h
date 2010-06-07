/*
 * storage_backend.h: internal storage driver backend contract
 *
 * Copyright (C) 2007-2010 Red Hat, Inc.
 * Copyright (C) 2007-2008 Daniel P. Berrange
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
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
 *
 * Author: Daniel P. Berrange <berrange@redhat.com>
 */

#ifndef __VIR_STORAGE_BACKEND_H__
# define __VIR_STORAGE_BACKEND_H__

# include <stdint.h>
# include "internal.h"
# include "storage_conf.h"

typedef char * (*virStorageBackendFindPoolSources)(virConnectPtr conn, const char *srcSpec, unsigned int flags);
typedef int (*virStorageBackendStartPool)(virConnectPtr conn, virStoragePoolObjPtr pool);
typedef int (*virStorageBackendBuildPool)(virConnectPtr conn, virStoragePoolObjPtr pool, unsigned int flags);
typedef int (*virStorageBackendRefreshPool)(virConnectPtr conn, virStoragePoolObjPtr pool);
typedef int (*virStorageBackendStopPool)(virConnectPtr conn, virStoragePoolObjPtr pool);
typedef int (*virStorageBackendDeletePool)(virConnectPtr conn, virStoragePoolObjPtr pool, unsigned int flags);

typedef int (*virStorageBackendBuildVol)(virConnectPtr conn,
                                         virStoragePoolObjPtr pool, virStorageVolDefPtr vol);
typedef int (*virStorageBackendCreateVol)(virConnectPtr conn, virStoragePoolObjPtr pool, virStorageVolDefPtr vol);
typedef int (*virStorageBackendRefreshVol)(virConnectPtr conn, virStoragePoolObjPtr pool, virStorageVolDefPtr vol);
typedef int (*virStorageBackendDeleteVol)(virConnectPtr conn, virStoragePoolObjPtr pool, virStorageVolDefPtr vol, unsigned int flags);
typedef int (*virStorageBackendBuildVolFrom)(virConnectPtr conn, virStoragePoolObjPtr pool,
                                             virStorageVolDefPtr origvol, virStorageVolDefPtr newvol,
                                             unsigned int flags);

/* File creation/cloning functions used for cloning between backends */
int virStorageBackendCreateRaw(virConnectPtr conn,
                               virStoragePoolObjPtr pool,
                               virStorageVolDefPtr vol,
                               virStorageVolDefPtr inputvol,
                               unsigned int flags);
virStorageBackendBuildVolFrom
virStorageBackendGetBuildVolFromFunction(virStorageVolDefPtr vol,
                                         virStorageVolDefPtr inputvol);
int virStorageBackendFindFSImageTool(char **tool);
virStorageBackendBuildVolFrom
virStorageBackendFSImageToolTypeToFunc(int tool_type);


typedef struct _virStorageBackend virStorageBackend;
typedef virStorageBackend *virStorageBackendPtr;

struct _virStorageBackend {
    int type;

    virStorageBackendFindPoolSources findPoolSources;
    virStorageBackendStartPool startPool;
    virStorageBackendBuildPool buildPool;
    virStorageBackendRefreshPool refreshPool;
    virStorageBackendStopPool stopPool;
    virStorageBackendDeletePool deletePool;

    virStorageBackendBuildVol buildVol;
    virStorageBackendBuildVolFrom buildVolFrom;
    virStorageBackendCreateVol createVol;
    virStorageBackendRefreshVol refreshVol;
    virStorageBackendDeleteVol deleteVol;
};

virStorageBackendPtr virStorageBackendForType(int type);


int virStorageBackendUpdateVolInfo(virStorageVolDefPtr vol,
                                   int withCapacity);

int virStorageBackendUpdateVolTargetInfo(virStorageVolTargetPtr target,
                                         unsigned long long *allocation,
                                         unsigned long long *capacity);
int virStorageBackendUpdateVolTargetInfoFD(virStorageVolTargetPtr target,
                                           int fd,
                                           unsigned long long *allocation,
                                           unsigned long long *capacity);
int
virStorageBackendUpdateVolTargetFormatFD(virStorageVolTargetPtr target,
                                         int fd);

char *virStorageBackendStablePath(virStoragePoolObjPtr pool,
                                  const char *devpath);

typedef int (*virStorageBackendListVolRegexFunc)(virStoragePoolObjPtr pool,
                                                 char **const groups,
                                                 void *data);
typedef int (*virStorageBackendListVolNulFunc)(virStoragePoolObjPtr pool,
                                               size_t n_tokens,
                                               char **const groups,
                                               void *data);

int virStorageBackendRunProgRegex(virStoragePoolObjPtr pool,
                                  const char *const*prog,
                                  int nregex,
                                  const char **regex,
                                  int *nvars,
                                  virStorageBackendListVolRegexFunc func,
                                  void *data,
                                  int *exitstatus);

int virStorageBackendRunProgNul(virStoragePoolObjPtr pool,
                                const char **prog,
                                size_t n_columns,
                                virStorageBackendListVolNulFunc func,
                                void *data);


#endif /* __VIR_STORAGE_BACKEND_H__ */