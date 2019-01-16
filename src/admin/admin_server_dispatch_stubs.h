/* Automatically generated from ./admin/admin_protocol.x by gendispatch.pl.
 * Do not edit this file.  Any changes you make will be lost.
 */
static int adminDispatchClientClose(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    admin_client_close_args *args);
static int adminDispatchClientCloseHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret ATTRIBUTE_UNUSED)
{
  int rv;
  virThreadJobSet("adminDispatchClientClose");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p",
            server, client, msg, rerr, args, ret);
  rv = adminDispatchClientClose(server, client, msg, rerr, args);
  virThreadJobClear(rv);
  return rv;
}
static int adminDispatchClientClose(
    virNetServerPtr server ATTRIBUTE_UNUSED,
    virNetServerClientPtr client,
    virNetMessagePtr msg ATTRIBUTE_UNUSED,
    virNetMessageErrorPtr rerr,
    admin_client_close_args *args)
{
    int rv = -1;
    virNetServerPtr srv = NULL;
    virNetServerClientPtr clnt = NULL;
    struct daemonAdmClientPrivate *priv =
        virNetServerClientGetPrivateData(client);

    if (!priv->dmn) {
        virReportError(VIR_ERR_INTERNAL_ERROR, "%s", _("connection not open"));
        goto cleanup;
    }

    if (!(srv = get_nonnull_server(priv->dmn, args->clnt.srv)))
        goto cleanup;

    if (!(clnt = get_nonnull_client(srv, args->clnt)))
        goto cleanup;

    if (adminClientClose(clnt, args->flags) < 0)
        goto cleanup;

    rv = 0;

cleanup:
    if (rv < 0)
        virNetMessageSaveError(rerr);
    virObjectUnref(clnt);
    virObjectUnref(srv);
    return rv;
}



static int adminDispatchClientGetInfo(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    admin_client_get_info_args *args,
    admin_client_get_info_ret *ret);
static int adminDispatchClientGetInfoHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret)
{
  int rv;
  virThreadJobSet("adminDispatchClientGetInfo");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p",
            server, client, msg, rerr, args, ret);
  rv = adminDispatchClientGetInfo(server, client, msg, rerr, args, ret);
  virThreadJobClear(rv);
  return rv;
}
/* adminDispatchClientGetInfo body has to be implemented manually */



static int adminDispatchConnectClose(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr);
static int adminDispatchConnectCloseHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args ATTRIBUTE_UNUSED,
    void *ret ATTRIBUTE_UNUSED)
{
  int rv;
  virThreadJobSet("adminDispatchConnectClose");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p",
            server, client, msg, rerr, args, ret);
  rv = adminDispatchConnectClose(server, client, msg, rerr);
  virThreadJobClear(rv);
  return rv;
}
/* adminDispatchConnectClose body has to be implemented manually */



static int adminDispatchConnectGetLibVersion(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    admin_connect_get_lib_version_ret *ret);
static int adminDispatchConnectGetLibVersionHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args ATTRIBUTE_UNUSED,
    void *ret)
{
  int rv;
  virThreadJobSet("adminDispatchConnectGetLibVersion");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p",
            server, client, msg, rerr, args, ret);
  rv = adminDispatchConnectGetLibVersion(server, client, msg, rerr, ret);
  virThreadJobClear(rv);
  return rv;
}
static int adminDispatchConnectGetLibVersion(
    virNetServerPtr server ATTRIBUTE_UNUSED,
    virNetServerClientPtr client,
    virNetMessagePtr msg ATTRIBUTE_UNUSED,
    virNetMessageErrorPtr rerr,
    admin_connect_get_lib_version_ret *ret)
{
    int rv = -1;
    unsigned long long libVer;
    struct daemonAdmClientPrivate *priv =
        virNetServerClientGetPrivateData(client);

    if (!priv->dmn) {
        virReportError(VIR_ERR_INTERNAL_ERROR, "%s", _("connection not open"));
        goto cleanup;
    }

    if (adminConnectGetLibVersion(priv->dmn, &libVer) < 0)
        goto cleanup;

    ret->libVer = libVer;
    rv = 0;

cleanup:
    if (rv < 0)
        virNetMessageSaveError(rerr);
    return rv;
}



static int adminDispatchConnectGetLoggingFilters(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    admin_connect_get_logging_filters_args *args,
    admin_connect_get_logging_filters_ret *ret);
static int adminDispatchConnectGetLoggingFiltersHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret)
{
  int rv;
  virThreadJobSet("adminDispatchConnectGetLoggingFilters");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p",
            server, client, msg, rerr, args, ret);
  rv = adminDispatchConnectGetLoggingFilters(server, client, msg, rerr, args, ret);
  virThreadJobClear(rv);
  return rv;
}
/* adminDispatchConnectGetLoggingFilters body has to be implemented manually */



static int adminDispatchConnectGetLoggingOutputs(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    admin_connect_get_logging_outputs_args *args,
    admin_connect_get_logging_outputs_ret *ret);
static int adminDispatchConnectGetLoggingOutputsHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret)
{
  int rv;
  virThreadJobSet("adminDispatchConnectGetLoggingOutputs");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p",
            server, client, msg, rerr, args, ret);
  rv = adminDispatchConnectGetLoggingOutputs(server, client, msg, rerr, args, ret);
  virThreadJobClear(rv);
  return rv;
}
/* adminDispatchConnectGetLoggingOutputs body has to be implemented manually */



static int adminDispatchConnectListServers(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    admin_connect_list_servers_args *args,
    admin_connect_list_servers_ret *ret);
static int adminDispatchConnectListServersHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret)
{
  int rv;
  virThreadJobSet("adminDispatchConnectListServers");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p",
            server, client, msg, rerr, args, ret);
  rv = adminDispatchConnectListServers(server, client, msg, rerr, args, ret);
  virThreadJobClear(rv);
  return rv;
}
static int adminDispatchConnectListServers(
    virNetServerPtr server ATTRIBUTE_UNUSED,
    virNetServerClientPtr client,
    virNetMessagePtr msg ATTRIBUTE_UNUSED,
    virNetMessageErrorPtr rerr,
    admin_connect_list_servers_args *args,
    admin_connect_list_servers_ret *ret)
{
    int rv = -1;
    ssize_t i;
    virNetServerPtr *result = NULL;
    int nresults = 0;
    struct daemonAdmClientPrivate *priv =
        virNetServerClientGetPrivateData(client);

    if (!priv->dmn) {
        virReportError(VIR_ERR_INTERNAL_ERROR, "%s", _("connection not open"));
        goto cleanup;
    }

    if ((nresults = 
            adminConnectListServers(priv->dmn,
                                    args->need_results ? &result : NULL,
                                    args->flags)) < 0)
        goto cleanup;

    if (nresults > ADMIN_SERVER_LIST_MAX) {
        virReportError(VIR_ERR_INTERNAL_ERROR,
                       _("Too many servers '%d' for limit '%d'"),
                       nresults, ADMIN_SERVER_LIST_MAX);
        goto cleanup;
    }

    if (result && nresults) {
        if (VIR_ALLOC_N(ret->servers.servers_val, nresults) < 0)
            goto cleanup;

        ret->servers.servers_len = nresults;
        for (i = 0; i < nresults; i++)
            if (make_nonnull_server(ret->servers.servers_val + i, result[i]) < 0)
                goto cleanup;
    } else {
        ret->servers.servers_len = 0;
        ret->servers.servers_val = NULL;
    }

    ret->ret = nresults;
    rv = 0;

cleanup:
    if (rv < 0)
        virNetMessageSaveError(rerr);
    if (result) {
        for (i = 0; i < nresults; i++)
            virObjectUnref(result[i]);
    }
    VIR_FREE(result);
    return rv;
}



static int adminDispatchConnectLookupServer(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    admin_connect_lookup_server_args *args,
    admin_connect_lookup_server_ret *ret);
static int adminDispatchConnectLookupServerHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret)
{
  int rv;
  virThreadJobSet("adminDispatchConnectLookupServer");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p",
            server, client, msg, rerr, args, ret);
  rv = adminDispatchConnectLookupServer(server, client, msg, rerr, args, ret);
  virThreadJobClear(rv);
  return rv;
}
static int adminDispatchConnectLookupServer(
    virNetServerPtr server ATTRIBUTE_UNUSED,
    virNetServerClientPtr client,
    virNetMessagePtr msg ATTRIBUTE_UNUSED,
    virNetMessageErrorPtr rerr,
    admin_connect_lookup_server_args *args,
    admin_connect_lookup_server_ret *ret)
{
    int rv = -1;
    virNetServerPtr srv = NULL;
    struct daemonAdmClientPrivate *priv =
        virNetServerClientGetPrivateData(client);

    if (!priv->dmn) {
        virReportError(VIR_ERR_INTERNAL_ERROR, "%s", _("connection not open"));
        goto cleanup;
    }

    if ((srv = adminConnectLookupServer(priv->dmn, args->name, args->flags)) == NULL)
        goto cleanup;

    if (make_nonnull_server(&ret->srv, srv) < 0)
        goto cleanup;

    rv = 0;

cleanup:
    if (rv < 0)
        virNetMessageSaveError(rerr);
    virObjectUnref(srv);
    return rv;
}



static int adminDispatchConnectOpen(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    admin_connect_open_args *args);
static int adminDispatchConnectOpenHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret ATTRIBUTE_UNUSED)
{
  int rv;
  virThreadJobSet("adminDispatchConnectOpen");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p",
            server, client, msg, rerr, args, ret);
  rv = adminDispatchConnectOpen(server, client, msg, rerr, args);
  virThreadJobClear(rv);
  return rv;
}
/* adminDispatchConnectOpen body has to be implemented manually */



static int adminDispatchConnectSetLoggingFilters(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    admin_connect_set_logging_filters_args *args);
static int adminDispatchConnectSetLoggingFiltersHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret ATTRIBUTE_UNUSED)
{
  int rv;
  virThreadJobSet("adminDispatchConnectSetLoggingFilters");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p",
            server, client, msg, rerr, args, ret);
  rv = adminDispatchConnectSetLoggingFilters(server, client, msg, rerr, args);
  virThreadJobClear(rv);
  return rv;
}
static int adminDispatchConnectSetLoggingFilters(
    virNetServerPtr server ATTRIBUTE_UNUSED,
    virNetServerClientPtr client,
    virNetMessagePtr msg ATTRIBUTE_UNUSED,
    virNetMessageErrorPtr rerr,
    admin_connect_set_logging_filters_args *args)
{
    int rv = -1;
    char *filters;
    struct daemonAdmClientPrivate *priv =
        virNetServerClientGetPrivateData(client);

    if (!priv->dmn) {
        virReportError(VIR_ERR_INTERNAL_ERROR, "%s", _("connection not open"));
        goto cleanup;
    }

    filters = args->filters ? *args->filters : NULL;

    if (adminConnectSetLoggingFilters(priv->dmn, filters, args->flags) < 0)
        goto cleanup;

    rv = 0;

cleanup:
    if (rv < 0)
        virNetMessageSaveError(rerr);
    return rv;
}



static int adminDispatchConnectSetLoggingOutputs(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    admin_connect_set_logging_outputs_args *args);
static int adminDispatchConnectSetLoggingOutputsHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret ATTRIBUTE_UNUSED)
{
  int rv;
  virThreadJobSet("adminDispatchConnectSetLoggingOutputs");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p",
            server, client, msg, rerr, args, ret);
  rv = adminDispatchConnectSetLoggingOutputs(server, client, msg, rerr, args);
  virThreadJobClear(rv);
  return rv;
}
static int adminDispatchConnectSetLoggingOutputs(
    virNetServerPtr server ATTRIBUTE_UNUSED,
    virNetServerClientPtr client,
    virNetMessagePtr msg ATTRIBUTE_UNUSED,
    virNetMessageErrorPtr rerr,
    admin_connect_set_logging_outputs_args *args)
{
    int rv = -1;
    char *outputs;
    struct daemonAdmClientPrivate *priv =
        virNetServerClientGetPrivateData(client);

    if (!priv->dmn) {
        virReportError(VIR_ERR_INTERNAL_ERROR, "%s", _("connection not open"));
        goto cleanup;
    }

    outputs = args->outputs ? *args->outputs : NULL;

    if (adminConnectSetLoggingOutputs(priv->dmn, outputs, args->flags) < 0)
        goto cleanup;

    rv = 0;

cleanup:
    if (rv < 0)
        virNetMessageSaveError(rerr);
    return rv;
}



static int adminDispatchServerGetClientLimits(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    admin_server_get_client_limits_args *args,
    admin_server_get_client_limits_ret *ret);
static int adminDispatchServerGetClientLimitsHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret)
{
  int rv;
  virThreadJobSet("adminDispatchServerGetClientLimits");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p",
            server, client, msg, rerr, args, ret);
  rv = adminDispatchServerGetClientLimits(server, client, msg, rerr, args, ret);
  virThreadJobClear(rv);
  return rv;
}
/* adminDispatchServerGetClientLimits body has to be implemented manually */



static int adminDispatchServerGetThreadpoolParameters(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    admin_server_get_threadpool_parameters_args *args,
    admin_server_get_threadpool_parameters_ret *ret);
static int adminDispatchServerGetThreadpoolParametersHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret)
{
  int rv;
  virThreadJobSet("adminDispatchServerGetThreadpoolParameters");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p",
            server, client, msg, rerr, args, ret);
  rv = adminDispatchServerGetThreadpoolParameters(server, client, msg, rerr, args, ret);
  virThreadJobClear(rv);
  return rv;
}
/* adminDispatchServerGetThreadpoolParameters body has to be implemented manually */



static int adminDispatchServerListClients(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    admin_server_list_clients_args *args,
    admin_server_list_clients_ret *ret);
static int adminDispatchServerListClientsHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret)
{
  int rv;
  virThreadJobSet("adminDispatchServerListClients");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p",
            server, client, msg, rerr, args, ret);
  rv = adminDispatchServerListClients(server, client, msg, rerr, args, ret);
  virThreadJobClear(rv);
  return rv;
}
static int adminDispatchServerListClients(
    virNetServerPtr server ATTRIBUTE_UNUSED,
    virNetServerClientPtr client,
    virNetMessagePtr msg ATTRIBUTE_UNUSED,
    virNetMessageErrorPtr rerr,
    admin_server_list_clients_args *args,
    admin_server_list_clients_ret *ret)
{
    int rv = -1;
    ssize_t i;
    virNetServerPtr srv = NULL;
    virNetServerClientPtr *result = NULL;
    int nresults = 0;
    struct daemonAdmClientPrivate *priv =
        virNetServerClientGetPrivateData(client);

    if (!priv->dmn) {
        virReportError(VIR_ERR_INTERNAL_ERROR, "%s", _("connection not open"));
        goto cleanup;
    }

    if (!(srv = get_nonnull_server(priv->dmn, args->srv)))
        goto cleanup;

    if ((nresults = 
            adminServerListClients(srv,
                                   args->need_results ? &result : NULL,
                                   args->flags)) < 0)
        goto cleanup;

    if (nresults > ADMIN_CLIENT_LIST_MAX) {
        virReportError(VIR_ERR_INTERNAL_ERROR,
                       _("Too many clients '%d' for limit '%d'"),
                       nresults, ADMIN_CLIENT_LIST_MAX);
        goto cleanup;
    }

    if (result && nresults) {
        if (VIR_ALLOC_N(ret->clients.clients_val, nresults) < 0)
            goto cleanup;

        ret->clients.clients_len = nresults;
        for (i = 0; i < nresults; i++) {
            if (make_nonnull_client(ret->clients.clients_val + i, result[i]) < 0)
                goto cleanup;
            if (make_nonnull_server(&ret->clients.clients_val[i].srv, srv) < 0)
                goto cleanup;
        }
    } else {
        ret->clients.clients_len = 0;
        ret->clients.clients_val = NULL;
    }

    ret->ret = nresults;
    rv = 0;

cleanup:
    if (rv < 0)
        virNetMessageSaveError(rerr);
    virObjectUnref(srv);
    if (result) {
        for (i = 0; i < nresults; i++)
            virObjectUnref(result[i]);
    }
    VIR_FREE(result);
    return rv;
}



static int adminDispatchServerLookupClient(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    admin_server_lookup_client_args *args,
    admin_server_lookup_client_ret *ret);
static int adminDispatchServerLookupClientHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret)
{
  int rv;
  virThreadJobSet("adminDispatchServerLookupClient");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p",
            server, client, msg, rerr, args, ret);
  rv = adminDispatchServerLookupClient(server, client, msg, rerr, args, ret);
  virThreadJobClear(rv);
  return rv;
}
static int adminDispatchServerLookupClient(
    virNetServerPtr server ATTRIBUTE_UNUSED,
    virNetServerClientPtr client,
    virNetMessagePtr msg ATTRIBUTE_UNUSED,
    virNetMessageErrorPtr rerr,
    admin_server_lookup_client_args *args,
    admin_server_lookup_client_ret *ret)
{
    int rv = -1;
    virNetServerPtr srv = NULL;
    virNetServerClientPtr clnt = NULL;
    struct daemonAdmClientPrivate *priv =
        virNetServerClientGetPrivateData(client);

    if (!priv->dmn) {
        virReportError(VIR_ERR_INTERNAL_ERROR, "%s", _("connection not open"));
        goto cleanup;
    }

    if (!(srv = get_nonnull_server(priv->dmn, args->srv)))
        goto cleanup;

    if ((clnt = adminServerLookupClient(srv, args->id, args->flags)) == NULL)
        goto cleanup;

    if (make_nonnull_client(&ret->clnt, clnt) < 0)
        goto cleanup;

    if (make_nonnull_server(&ret->clnt.srv, srv) < 0)
        goto cleanup;

    rv = 0;

cleanup:
    if (rv < 0)
        virNetMessageSaveError(rerr);
    virObjectUnref(srv);
    virObjectUnref(clnt);
    return rv;
}



static int adminDispatchServerSetClientLimits(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    admin_server_set_client_limits_args *args);
static int adminDispatchServerSetClientLimitsHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret ATTRIBUTE_UNUSED)
{
  int rv;
  virThreadJobSet("adminDispatchServerSetClientLimits");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p",
            server, client, msg, rerr, args, ret);
  rv = adminDispatchServerSetClientLimits(server, client, msg, rerr, args);
  virThreadJobClear(rv);
  return rv;
}
/* adminDispatchServerSetClientLimits body has to be implemented manually */



static int adminDispatchServerSetThreadpoolParameters(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    admin_server_set_threadpool_parameters_args *args);
static int adminDispatchServerSetThreadpoolParametersHelper(
    virNetServerPtr server,
    virNetServerClientPtr client,
    virNetMessagePtr msg,
    virNetMessageErrorPtr rerr,
    void *args,
    void *ret ATTRIBUTE_UNUSED)
{
  int rv;
  virThreadJobSet("adminDispatchServerSetThreadpoolParameters");
  VIR_DEBUG("server=%p client=%p msg=%p rerr=%p args=%p ret=%p",
            server, client, msg, rerr, args, ret);
  rv = adminDispatchServerSetThreadpoolParameters(server, client, msg, rerr, args);
  virThreadJobClear(rv);
  return rv;
}
/* adminDispatchServerSetThreadpoolParameters body has to be implemented manually */



virNetServerProgramProc adminProcs[] = {
{ /* Unused 0 */
   NULL,
   0,
   (xdrproc_t)xdr_void,
   0,
   (xdrproc_t)xdr_void,
   true,
   0
},
{ /* Method ConnectOpen => 1 */
   adminDispatchConnectOpenHelper,
   sizeof(admin_connect_open_args),
   (xdrproc_t)xdr_admin_connect_open_args,
   0,
   (xdrproc_t)xdr_void,
   true,
   0
},
{ /* Method ConnectClose => 2 */
   adminDispatchConnectCloseHelper,
   0,
   (xdrproc_t)xdr_void,
   0,
   (xdrproc_t)xdr_void,
   true,
   0
},
{ /* Method ConnectGetLibVersion => 3 */
   adminDispatchConnectGetLibVersionHelper,
   0,
   (xdrproc_t)xdr_void,
   sizeof(admin_connect_get_lib_version_ret),
   (xdrproc_t)xdr_admin_connect_get_lib_version_ret,
   true,
   0
},
{ /* Method ConnectListServers => 4 */
   adminDispatchConnectListServersHelper,
   sizeof(admin_connect_list_servers_args),
   (xdrproc_t)xdr_admin_connect_list_servers_args,
   sizeof(admin_connect_list_servers_ret),
   (xdrproc_t)xdr_admin_connect_list_servers_ret,
   true,
   0
},
{ /* Method ConnectLookupServer => 5 */
   adminDispatchConnectLookupServerHelper,
   sizeof(admin_connect_lookup_server_args),
   (xdrproc_t)xdr_admin_connect_lookup_server_args,
   sizeof(admin_connect_lookup_server_ret),
   (xdrproc_t)xdr_admin_connect_lookup_server_ret,
   true,
   0
},
{ /* Method ServerGetThreadpoolParameters => 6 */
   adminDispatchServerGetThreadpoolParametersHelper,
   sizeof(admin_server_get_threadpool_parameters_args),
   (xdrproc_t)xdr_admin_server_get_threadpool_parameters_args,
   sizeof(admin_server_get_threadpool_parameters_ret),
   (xdrproc_t)xdr_admin_server_get_threadpool_parameters_ret,
   true,
   0
},
{ /* Method ServerSetThreadpoolParameters => 7 */
   adminDispatchServerSetThreadpoolParametersHelper,
   sizeof(admin_server_set_threadpool_parameters_args),
   (xdrproc_t)xdr_admin_server_set_threadpool_parameters_args,
   0,
   (xdrproc_t)xdr_void,
   true,
   0
},
{ /* Method ServerListClients => 8 */
   adminDispatchServerListClientsHelper,
   sizeof(admin_server_list_clients_args),
   (xdrproc_t)xdr_admin_server_list_clients_args,
   sizeof(admin_server_list_clients_ret),
   (xdrproc_t)xdr_admin_server_list_clients_ret,
   true,
   0
},
{ /* Method ServerLookupClient => 9 */
   adminDispatchServerLookupClientHelper,
   sizeof(admin_server_lookup_client_args),
   (xdrproc_t)xdr_admin_server_lookup_client_args,
   sizeof(admin_server_lookup_client_ret),
   (xdrproc_t)xdr_admin_server_lookup_client_ret,
   true,
   0
},
{ /* Method ClientGetInfo => 10 */
   adminDispatchClientGetInfoHelper,
   sizeof(admin_client_get_info_args),
   (xdrproc_t)xdr_admin_client_get_info_args,
   sizeof(admin_client_get_info_ret),
   (xdrproc_t)xdr_admin_client_get_info_ret,
   true,
   0
},
{ /* Method ClientClose => 11 */
   adminDispatchClientCloseHelper,
   sizeof(admin_client_close_args),
   (xdrproc_t)xdr_admin_client_close_args,
   0,
   (xdrproc_t)xdr_void,
   true,
   0
},
{ /* Method ServerGetClientLimits => 12 */
   adminDispatchServerGetClientLimitsHelper,
   sizeof(admin_server_get_client_limits_args),
   (xdrproc_t)xdr_admin_server_get_client_limits_args,
   sizeof(admin_server_get_client_limits_ret),
   (xdrproc_t)xdr_admin_server_get_client_limits_ret,
   true,
   0
},
{ /* Method ServerSetClientLimits => 13 */
   adminDispatchServerSetClientLimitsHelper,
   sizeof(admin_server_set_client_limits_args),
   (xdrproc_t)xdr_admin_server_set_client_limits_args,
   0,
   (xdrproc_t)xdr_void,
   true,
   0
},
{ /* Method ConnectGetLoggingOutputs => 14 */
   adminDispatchConnectGetLoggingOutputsHelper,
   sizeof(admin_connect_get_logging_outputs_args),
   (xdrproc_t)xdr_admin_connect_get_logging_outputs_args,
   sizeof(admin_connect_get_logging_outputs_ret),
   (xdrproc_t)xdr_admin_connect_get_logging_outputs_ret,
   true,
   0
},
{ /* Method ConnectGetLoggingFilters => 15 */
   adminDispatchConnectGetLoggingFiltersHelper,
   sizeof(admin_connect_get_logging_filters_args),
   (xdrproc_t)xdr_admin_connect_get_logging_filters_args,
   sizeof(admin_connect_get_logging_filters_ret),
   (xdrproc_t)xdr_admin_connect_get_logging_filters_ret,
   true,
   0
},
{ /* Method ConnectSetLoggingOutputs => 16 */
   adminDispatchConnectSetLoggingOutputsHelper,
   sizeof(admin_connect_set_logging_outputs_args),
   (xdrproc_t)xdr_admin_connect_set_logging_outputs_args,
   0,
   (xdrproc_t)xdr_void,
   true,
   0
},
{ /* Method ConnectSetLoggingFilters => 17 */
   adminDispatchConnectSetLoggingFiltersHelper,
   sizeof(admin_connect_set_logging_filters_args),
   (xdrproc_t)xdr_admin_connect_set_logging_filters_args,
   0,
   (xdrproc_t)xdr_void,
   true,
   0
},
};
size_t adminNProcs = ARRAY_CARDINALITY(adminProcs);
