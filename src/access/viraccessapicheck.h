/* Automatically generated by gendispatch.pl.
 * Do not edit this file.  Any changes you make will be lost.
 */
#include "internal.h"
#include "domain_conf.h"
#include "network_conf.h"
#include "secret_conf.h"
#include "storage_conf.h"
#include "nwfilter_conf.h"
#include "node_device_conf.h"
#include "interface_conf.h"

extern int virConnectBaselineCPUEnsureACL(virConnectPtr conn);
extern int virConnectCompareCPUEnsureACL(virConnectPtr conn);
extern int virConnectDomainEventDeregisterEnsureACL(virConnectPtr conn);
extern int virConnectDomainEventDeregisterAnyEnsureACL(virConnectPtr conn);
extern int virConnectDomainEventRegisterEnsureACL(virConnectPtr conn);
extern int virConnectDomainEventRegisterAnyEnsureACL(virConnectPtr conn);
extern int virConnectDomainXMLFromNativeEnsureACL(virConnectPtr conn);
extern int virConnectDomainXMLToNativeEnsureACL(virConnectPtr conn);
extern int virConnectFindStoragePoolSourcesEnsureACL(virConnectPtr conn);
extern int virConnectGetCapabilitiesEnsureACL(virConnectPtr conn);
extern int virConnectGetHostnameEnsureACL(virConnectPtr conn);
extern int virConnectGetLibVersionEnsureACL(virConnectPtr conn);
extern int virConnectGetMaxVcpusEnsureACL(virConnectPtr conn);
extern int virConnectGetSysinfoEnsureACL(virConnectPtr conn);
extern int virConnectGetTypeEnsureACL(virConnectPtr conn);
extern int virConnectGetURIEnsureACL(virConnectPtr conn);
extern int virConnectGetVersionEnsureACL(virConnectPtr conn);
extern int virConnectListAllDomainsEnsureACL(virConnectPtr conn);
extern int virConnectListAllDomainsCheckACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virConnectListAllInterfacesEnsureACL(virConnectPtr conn);
extern int virConnectListAllInterfacesCheckACL(virConnectPtr conn, virInterfaceDefPtr iface);
extern int virConnectListAllNetworksEnsureACL(virConnectPtr conn);
extern int virConnectListAllNetworksCheckACL(virConnectPtr conn, virNetworkDefPtr network);
extern int virConnectListAllNodeDevicesEnsureACL(virConnectPtr conn);
extern int virConnectListAllNodeDevicesCheckACL(virConnectPtr conn, virNodeDeviceDefPtr device);
extern int virConnectListAllNWFiltersEnsureACL(virConnectPtr conn);
extern int virConnectListAllNWFiltersCheckACL(virConnectPtr conn, virNWFilterDefPtr nwfilter);
extern int virConnectListAllSecretsEnsureACL(virConnectPtr conn);
extern int virConnectListAllSecretsCheckACL(virConnectPtr conn, virSecretDefPtr secret);
extern int virConnectListAllStoragePoolsEnsureACL(virConnectPtr conn);
extern int virConnectListAllStoragePoolsCheckACL(virConnectPtr conn, virStoragePoolDefPtr pool);
extern int virConnectListDefinedDomainsEnsureACL(virConnectPtr conn);
extern int virConnectListDefinedDomainsCheckACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virConnectListDefinedInterfacesEnsureACL(virConnectPtr conn);
extern int virConnectListDefinedInterfacesCheckACL(virConnectPtr conn, virInterfaceDefPtr iface);
extern int virConnectListDefinedNetworksEnsureACL(virConnectPtr conn);
extern int virConnectListDefinedNetworksCheckACL(virConnectPtr conn, virNetworkDefPtr network);
extern int virConnectListDefinedStoragePoolsEnsureACL(virConnectPtr conn);
extern int virConnectListDefinedStoragePoolsCheckACL(virConnectPtr conn, virStoragePoolDefPtr pool);
extern int virConnectListDomainsEnsureACL(virConnectPtr conn);
extern int virConnectListDomainsCheckACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virConnectListInterfacesEnsureACL(virConnectPtr conn);
extern int virConnectListInterfacesCheckACL(virConnectPtr conn, virInterfaceDefPtr iface);
extern int virConnectListNetworksEnsureACL(virConnectPtr conn);
extern int virConnectListNetworksCheckACL(virConnectPtr conn, virNetworkDefPtr network);
extern int virConnectListNWFiltersEnsureACL(virConnectPtr conn);
extern int virConnectListNWFiltersCheckACL(virConnectPtr conn, virNWFilterDefPtr nwfilter);
extern int virConnectListSecretsEnsureACL(virConnectPtr conn);
extern int virConnectListSecretsCheckACL(virConnectPtr conn, virSecretDefPtr secret);
extern int virConnectListStoragePoolsEnsureACL(virConnectPtr conn);
extern int virConnectListStoragePoolsCheckACL(virConnectPtr conn, virStoragePoolDefPtr pool);
extern int virConnectNumOfDefinedDomainsEnsureACL(virConnectPtr conn);
extern int virConnectNumOfDefinedDomainsCheckACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virConnectNumOfDefinedInterfacesEnsureACL(virConnectPtr conn);
extern int virConnectNumOfDefinedInterfacesCheckACL(virConnectPtr conn, virInterfaceDefPtr iface);
extern int virConnectNumOfDefinedNetworksEnsureACL(virConnectPtr conn);
extern int virConnectNumOfDefinedNetworksCheckACL(virConnectPtr conn, virNetworkDefPtr network);
extern int virConnectNumOfDefinedStoragePoolsEnsureACL(virConnectPtr conn);
extern int virConnectNumOfDefinedStoragePoolsCheckACL(virConnectPtr conn, virStoragePoolDefPtr pool);
extern int virConnectNumOfDomainsEnsureACL(virConnectPtr conn);
extern int virConnectNumOfDomainsCheckACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virConnectNumOfInterfacesEnsureACL(virConnectPtr conn);
extern int virConnectNumOfInterfacesCheckACL(virConnectPtr conn, virInterfaceDefPtr iface);
extern int virConnectNumOfNetworksEnsureACL(virConnectPtr conn);
extern int virConnectNumOfNetworksCheckACL(virConnectPtr conn, virNetworkDefPtr network);
extern int virConnectNumOfNWFiltersEnsureACL(virConnectPtr conn);
extern int virConnectNumOfNWFiltersCheckACL(virConnectPtr conn, virNWFilterDefPtr nwfilter);
extern int virConnectNumOfSecretsEnsureACL(virConnectPtr conn);
extern int virConnectNumOfSecretsCheckACL(virConnectPtr conn, virSecretDefPtr secret);
extern int virConnectNumOfStoragePoolsEnsureACL(virConnectPtr conn);
extern int virConnectNumOfStoragePoolsCheckACL(virConnectPtr conn, virStoragePoolDefPtr pool);
extern int virConnectOpenEnsureACL(virConnectPtr conn);
extern int virConnectSupportsFeatureEnsureACL(virConnectPtr conn);
extern int virDomainAbortJobEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainAttachDeviceEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainAttachDeviceFlagsEnsureACL(virConnectPtr conn, virDomainDefPtr domain, unsigned int flags);
extern int virDomainBlockCommitEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainBlockJobAbortEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainBlockJobSetSpeedEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainBlockPeekEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainBlockPullEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainBlockRebaseEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainBlockResizeEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainBlockStatsEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainBlockStatsFlagsEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainCoreDumpEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainCreateEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainCreateWithFlagsEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainCreateXMLEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainDefineXMLEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainDestroyEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainDestroyFlagsEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainDetachDeviceEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainDetachDeviceFlagsEnsureACL(virConnectPtr conn, virDomainDefPtr domain, unsigned int flags);
extern int virDomainFSTrimEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetAutostartEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetBlkioParametersEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetBlockInfoEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetBlockIoTuneEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetBlockJobInfoEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetControlInfoEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetCPUStatsEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetDiskErrorsEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetEmulatorPinInfoEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetHostnameEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetInfoEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetInterfaceParametersEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetJobInfoEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetJobStatsEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetMaxMemoryEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetMaxVcpusEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetMemoryParametersEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetMetadataEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetNumaParametersEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetOSTypeEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetSchedulerParametersEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetSchedulerParametersFlagsEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetSchedulerTypeEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetSecurityLabelEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetSecurityLabelListEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetStateEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetVcpuPinInfoEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetVcpusEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetVcpusFlagsEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainGetXMLDescEnsureACL(virConnectPtr conn, virDomainDefPtr domain, unsigned int flags);
extern int virDomainHasCurrentSnapshotEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainHasManagedSaveImageEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainInjectNMIEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainInterfaceStatsEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainIsActiveEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainIsPersistentEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainIsUpdatedEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainListAllSnapshotsEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainLookupByIDEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainLookupByNameEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainLookupByUUIDEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainManagedSaveEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainManagedSaveRemoveEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainMemoryPeekEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainMemoryStatsEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainMigrateBegin3EnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainMigrateBegin3ParamsEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainMigrateConfirm3EnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainMigrateConfirm3ParamsEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainMigrateFinishEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainMigrateFinish2EnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainMigrateFinish3EnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainMigrateFinish3ParamsEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainMigrateGetCompressionCacheEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainMigrateGetMaxSpeedEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainMigratePerformEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainMigratePerform3EnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainMigratePerform3ParamsEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainMigratePrepareEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainMigratePrepare2EnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainMigratePrepare3EnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainMigratePrepare3ParamsEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainMigratePrepareTunnelEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainMigratePrepareTunnel3EnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainMigratePrepareTunnel3ParamsEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainMigrateSetCompressionCacheEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainMigrateSetMaxDowntimeEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainMigrateSetMaxSpeedEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainOpenChannelEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainOpenConsoleEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainOpenGraphicsEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainPinEmulatorEnsureACL(virConnectPtr conn, virDomainDefPtr domain, unsigned int flags);
extern int virDomainPinVcpuEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainPinVcpuFlagsEnsureACL(virConnectPtr conn, virDomainDefPtr domain, unsigned int flags);
extern int virDomainPMSuspendForDurationEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainPMWakeupEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainRebootEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainResetEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainRestoreEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainRestoreFlagsEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainResumeEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainRevertToSnapshotEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainSaveEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainSaveFlagsEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainSaveImageDefineXMLEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainSaveImageGetXMLDescEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainScreenshotEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainSendKeyEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainSendProcessSignalEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainSetAutostartEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainSetBlkioParametersEnsureACL(virConnectPtr conn, virDomainDefPtr domain, unsigned int flags);
extern int virDomainSetBlockIoTuneEnsureACL(virConnectPtr conn, virDomainDefPtr domain, unsigned int flags);
extern int virDomainSetInterfaceParametersEnsureACL(virConnectPtr conn, virDomainDefPtr domain, unsigned int flags);
extern int virDomainSetMaxMemoryEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainSetMemoryEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainSetMemoryFlagsEnsureACL(virConnectPtr conn, virDomainDefPtr domain, unsigned int flags);
extern int virDomainSetMemoryParametersEnsureACL(virConnectPtr conn, virDomainDefPtr domain, unsigned int flags);
extern int virDomainSetMetadataEnsureACL(virConnectPtr conn, virDomainDefPtr domain, unsigned int flags);
extern int virDomainSetNumaParametersEnsureACL(virConnectPtr conn, virDomainDefPtr domain, unsigned int flags);
extern int virDomainSetSchedulerParametersEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainSetSchedulerParametersFlagsEnsureACL(virConnectPtr conn, virDomainDefPtr domain, unsigned int flags);
extern int virDomainSetVcpusEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainSetVcpusFlagsEnsureACL(virConnectPtr conn, virDomainDefPtr domain, unsigned int flags);
extern int virDomainShutdownEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainShutdownFlagsEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainSnapshotCreateXMLEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainSnapshotCurrentEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainSnapshotDeleteEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainSnapshotGetParentEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainSnapshotGetXMLDescEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainSnapshotHasMetadataEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainSnapshotIsCurrentEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainSnapshotListAllChildrenEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainSnapshotListChildrenNamesEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainSnapshotListNamesEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainSnapshotLookupByNameEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainSnapshotNumEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainSnapshotNumChildrenEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainSuspendEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainUndefineEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainUndefineFlagsEnsureACL(virConnectPtr conn, virDomainDefPtr domain);
extern int virDomainUpdateDeviceFlagsEnsureACL(virConnectPtr conn, virDomainDefPtr domain, unsigned int flags);
extern int virInterfaceChangeBeginEnsureACL(virConnectPtr conn);
extern int virInterfaceChangeCommitEnsureACL(virConnectPtr conn);
extern int virInterfaceChangeRollbackEnsureACL(virConnectPtr conn);
extern int virInterfaceCreateEnsureACL(virConnectPtr conn, virInterfaceDefPtr iface);
extern int virInterfaceDefineXMLEnsureACL(virConnectPtr conn, virInterfaceDefPtr iface);
extern int virInterfaceDestroyEnsureACL(virConnectPtr conn, virInterfaceDefPtr iface);
extern int virInterfaceGetXMLDescEnsureACL(virConnectPtr conn, virInterfaceDefPtr iface);
extern int virInterfaceIsActiveEnsureACL(virConnectPtr conn, virInterfaceDefPtr iface);
extern int virInterfaceLookupByMACStringEnsureACL(virConnectPtr conn, virInterfaceDefPtr iface);
extern int virInterfaceLookupByNameEnsureACL(virConnectPtr conn, virInterfaceDefPtr iface);
extern int virInterfaceUndefineEnsureACL(virConnectPtr conn, virInterfaceDefPtr iface);
extern int virNetworkCreateEnsureACL(virConnectPtr conn, virNetworkDefPtr network);
extern int virNetworkCreateXMLEnsureACL(virConnectPtr conn, virNetworkDefPtr network);
extern int virNetworkDefineXMLEnsureACL(virConnectPtr conn, virNetworkDefPtr network);
extern int virNetworkDestroyEnsureACL(virConnectPtr conn, virNetworkDefPtr network);
extern int virNetworkGetAutostartEnsureACL(virConnectPtr conn, virNetworkDefPtr network);
extern int virNetworkGetBridgeNameEnsureACL(virConnectPtr conn, virNetworkDefPtr network);
extern int virNetworkGetXMLDescEnsureACL(virConnectPtr conn, virNetworkDefPtr network);
extern int virNetworkIsActiveEnsureACL(virConnectPtr conn, virNetworkDefPtr network);
extern int virNetworkIsPersistentEnsureACL(virConnectPtr conn, virNetworkDefPtr network);
extern int virNetworkLookupByNameEnsureACL(virConnectPtr conn, virNetworkDefPtr network);
extern int virNetworkLookupByUUIDEnsureACL(virConnectPtr conn, virNetworkDefPtr network);
extern int virNetworkSetAutostartEnsureACL(virConnectPtr conn, virNetworkDefPtr network);
extern int virNetworkUndefineEnsureACL(virConnectPtr conn, virNetworkDefPtr network);
extern int virNetworkUpdateEnsureACL(virConnectPtr conn, virNetworkDefPtr network, unsigned int flags);
extern int virNodeDeviceCreateXMLEnsureACL(virConnectPtr conn, virNodeDeviceDefPtr device);
extern int virNodeDeviceDestroyEnsureACL(virConnectPtr conn, virNodeDeviceDefPtr device);
extern int virNodeDeviceDetachFlagsEnsureACL(virConnectPtr conn, virNodeDeviceDefPtr device);
extern int virNodeDeviceDettachEnsureACL(virConnectPtr conn, virNodeDeviceDefPtr device);
extern int virNodeDeviceGetParentEnsureACL(virConnectPtr conn, virNodeDeviceDefPtr device);
extern int virNodeDeviceGetXMLDescEnsureACL(virConnectPtr conn, virNodeDeviceDefPtr device);
extern int virNodeDeviceListCapsEnsureACL(virConnectPtr conn, virNodeDeviceDefPtr device);
extern int virNodeDeviceLookupByNameEnsureACL(virConnectPtr conn, virNodeDeviceDefPtr device);
extern int virNodeDeviceLookupSCSIHostByWWNEnsureACL(virConnectPtr conn, virNodeDeviceDefPtr device);
extern int virNodeDeviceNumOfCapsEnsureACL(virConnectPtr conn, virNodeDeviceDefPtr device);
extern int virNodeDeviceReAttachEnsureACL(virConnectPtr conn, virNodeDeviceDefPtr device);
extern int virNodeDeviceResetEnsureACL(virConnectPtr conn, virNodeDeviceDefPtr device);
extern int virNodeGetCellsFreeMemoryEnsureACL(virConnectPtr conn);
extern int virNodeGetCPUMapEnsureACL(virConnectPtr conn);
extern int virNodeGetCPUStatsEnsureACL(virConnectPtr conn);
extern int virNodeGetFreeMemoryEnsureACL(virConnectPtr conn);
extern int virNodeGetInfoEnsureACL(virConnectPtr conn);
extern int virNodeGetMemoryParametersEnsureACL(virConnectPtr conn);
extern int virNodeGetMemoryStatsEnsureACL(virConnectPtr conn);
extern int virNodeGetSecurityModelEnsureACL(virConnectPtr conn);
extern int virNodeListDevicesEnsureACL(virConnectPtr conn);
extern int virNodeListDevicesCheckACL(virConnectPtr conn, virNodeDeviceDefPtr device);
extern int virNodeNumOfDevicesEnsureACL(virConnectPtr conn);
extern int virNodeNumOfDevicesCheckACL(virConnectPtr conn, virNodeDeviceDefPtr device);
extern int virNodeSetMemoryParametersEnsureACL(virConnectPtr conn);
extern int virNodeSuspendForDurationEnsureACL(virConnectPtr conn);
extern int virNWFilterDefineXMLEnsureACL(virConnectPtr conn, virNWFilterDefPtr nwfilter);
extern int virNWFilterGetXMLDescEnsureACL(virConnectPtr conn, virNWFilterDefPtr nwfilter);
extern int virNWFilterLookupByNameEnsureACL(virConnectPtr conn, virNWFilterDefPtr nwfilter);
extern int virNWFilterLookupByUUIDEnsureACL(virConnectPtr conn, virNWFilterDefPtr nwfilter);
extern int virNWFilterUndefineEnsureACL(virConnectPtr conn, virNWFilterDefPtr nwfilter);
extern int virSecretDefineXMLEnsureACL(virConnectPtr conn, virSecretDefPtr secret);
extern int virSecretGetValueEnsureACL(virConnectPtr conn, virSecretDefPtr secret);
extern int virSecretGetXMLDescEnsureACL(virConnectPtr conn, virSecretDefPtr secret);
extern int virSecretLookupByUsageEnsureACL(virConnectPtr conn, virSecretDefPtr secret);
extern int virSecretLookupByUUIDEnsureACL(virConnectPtr conn, virSecretDefPtr secret);
extern int virSecretSetValueEnsureACL(virConnectPtr conn, virSecretDefPtr secret);
extern int virSecretUndefineEnsureACL(virConnectPtr conn, virSecretDefPtr secret);
extern int virStoragePoolBuildEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool);
extern int virStoragePoolCreateEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool);
extern int virStoragePoolCreateXMLEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool);
extern int virStoragePoolDefineXMLEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool);
extern int virStoragePoolDeleteEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool);
extern int virStoragePoolDestroyEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool);
extern int virStoragePoolGetAutostartEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool);
extern int virStoragePoolGetInfoEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool);
extern int virStoragePoolGetXMLDescEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool);
extern int virStoragePoolIsActiveEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool);
extern int virStoragePoolIsPersistentEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool);
extern int virStoragePoolListAllVolumesEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool);
extern int virStoragePoolListAllVolumesCheckACL(virConnectPtr conn, virStoragePoolDefPtr pool, virStorageVolDefPtr vol);
extern int virStoragePoolListVolumesEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool);
extern int virStoragePoolListVolumesCheckACL(virConnectPtr conn, virStoragePoolDefPtr pool, virStorageVolDefPtr vol);
extern int virStoragePoolLookupByNameEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool);
extern int virStoragePoolLookupByUUIDEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool);
extern int virStoragePoolLookupByVolumeEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool);
extern int virStoragePoolNumOfVolumesEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool);
extern int virStoragePoolNumOfVolumesCheckACL(virConnectPtr conn, virStoragePoolDefPtr pool, virStorageVolDefPtr vol);
extern int virStoragePoolRefreshEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool);
extern int virStoragePoolSetAutostartEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool);
extern int virStoragePoolUndefineEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool);
extern int virStorageVolCreateXMLEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool, virStorageVolDefPtr vol);
extern int virStorageVolCreateXMLFromEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool, virStorageVolDefPtr vol);
extern int virStorageVolDeleteEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool, virStorageVolDefPtr vol);
extern int virStorageVolDownloadEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool, virStorageVolDefPtr vol);
extern int virStorageVolGetInfoEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool, virStorageVolDefPtr vol);
extern int virStorageVolGetPathEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool, virStorageVolDefPtr vol);
extern int virStorageVolGetXMLDescEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool, virStorageVolDefPtr vol);
extern int virStorageVolLookupByKeyEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool, virStorageVolDefPtr vol);
extern int virStorageVolLookupByNameEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool, virStorageVolDefPtr vol);
extern int virStorageVolLookupByPathEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool, virStorageVolDefPtr vol);
extern int virStorageVolResizeEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool, virStorageVolDefPtr vol);
extern int virStorageVolUploadEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool, virStorageVolDefPtr vol);
extern int virStorageVolWipeEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool, virStorageVolDefPtr vol);
extern int virStorageVolWipePatternEnsureACL(virConnectPtr conn, virStoragePoolDefPtr pool, virStorageVolDefPtr vol);
