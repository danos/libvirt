
/*
 * Copyright IBM Corp. 2009
 *
 * phyp_driver.c: ssh layer to access Power Hypervisors
 *
 * Authors:
 *  Eduardo Otubo <otubo at linux.vnet.ibm.com>
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

#include "conf/capabilities.h"
#include "conf/domain_conf.h"
#include <config.h>
#include <libssh2.h>

#define LPAR_EXEC_ERR -1
#define SSH_CONN_ERR -2         /* error while trying to connect to remote host */
#define SSH_CMD_ERR -3          /* error while trying to execute the remote cmd */

typedef struct _ConnectionData ConnectionData;
typedef ConnectionData *ConnectionDataPtr;
struct _ConnectionData {
    LIBSSH2_SESSION *session;
    int sock;
};

/* This is the lpar (domain) struct that relates
 * the ID with UUID generated by the API
 * */
typedef struct _lpar lpar_t;
typedef lpar_t *lparPtr;
struct _lpar {
    unsigned char uuid[VIR_UUID_BUFLEN];
    int id;
};

/* Struct that holds how many lpars (domains) we're
 * handling and a pointer to an array of lpar structs
 * */
typedef struct _uuid_table uuid_table_t;
typedef uuid_table_t *uuid_tablePtr;
struct _uuid_table {
    int nlpars;
    lparPtr *lpars;
};

/* This is the main structure of the driver
 * */
typedef struct _phyp_driver phyp_driver_t;
typedef phyp_driver_t *phyp_driverPtr;
struct _phyp_driver {
    uuid_tablePtr uuid_table;
    virCapsPtr caps;
    int vios_id;
    char *managed_system;
};

int phypCheckSPFreeSapce(virConnectPtr conn, int required_size, char *sp);

int phypGetVIOSPartitionID(virConnectPtr conn);

virCapsPtr phypCapsInit(void);

int phypBuildLpar(virConnectPtr conn, virDomainDefPtr def);

int phypUUIDTable_WriteFile(virConnectPtr conn);

int phypUUIDTable_ReadFile(virConnectPtr conn);

int phypUUIDTable_AddLpar(virConnectPtr conn, unsigned char *uuid, int id);

int phypUUIDTable_RemLpar(virConnectPtr conn, int id);

int phypUUIDTable_Pull(virConnectPtr conn);

int phypUUIDTable_Push(virConnectPtr conn);

int phypUUIDTable_Init(virConnectPtr conn);

void phypUUIDTable_Free(uuid_tablePtr uuid_table);

int escape_specialcharacters(char *src, char *dst, size_t dstlen);

int waitsocket(int socket_fd, LIBSSH2_SESSION * session);

int phypGetLparUUID(unsigned char *uuid, int lpar_id, virConnectPtr conn);

int phypRegister(void);

int phypGetLparState(virConnectPtr conn, unsigned int lpar_id);

unsigned long phypGetLparMem(virConnectPtr conn,
                             const char *managed_system, int lpar_id,
                             int type);

unsigned long phypGetLparCPU(virConnectPtr conn,
                             const char *managed_system, int lpar_id);

unsigned long phypGetLparCPUGeneric(virConnectPtr conn,
                                    const char *managed_system,
                                    int lpar_id, int type);

int phypGetRemoteSlot(virConnectPtr conn, const char *managed_system,
                      const char *lpar_name);

char *phypGetBackingDevice(virConnectPtr conn, const char *managed_system,
                           char *lpar_name);

int phypDiskType(virConnectPtr conn, char *backing_device);

LIBSSH2_SESSION *openSSHSession(virConnectPtr conn, virConnectAuthPtr auth,
                                int *internal_socket);