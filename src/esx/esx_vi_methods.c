
/*
 * esx_vi_methods.c: client for the VMware VI API 2.5 to manage ESX hosts
 *
 * Copyright (C) 2010 Red Hat, Inc.
 * Copyright (C) 2009-2010 Matthias Bolte <matthias.bolte@googlemail.com>
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
 */

#include <config.h>

#include "buf.h"
#include "memory.h"
#include "logging.h"
#include "uuid.h"
#include "esx_vi_methods.h"
#include "esx_util.h"

#define VIR_FROM_THIS VIR_FROM_ESX



#define ESX_VI__METHOD__CHECK_OUTPUT__None                                    \
    /* nothing */



#define ESX_VI__METHOD__CHECK_OUTPUT__NotNone                                 \
    if (output == NULL || *output != 0) {                                     \
        ESX_VI_ERROR(VIR_ERR_INTERNAL_ERROR, "%s", _("Invalid argument"));    \
        return -1;                                                            \
    }



#define ESX_VI__METHOD__CHECK_OUTPUT__RequiredItem                            \
    ESX_VI__METHOD__CHECK_OUTPUT__NotNone



#define ESX_VI__METHOD__CHECK_OUTPUT__RequiredList                            \
    ESX_VI__METHOD__CHECK_OUTPUT__NotNone



#define ESX_VI__METHOD__CHECK_OUTPUT__OptionalItem                            \
    ESX_VI__METHOD__CHECK_OUTPUT__NotNone



#define ESX_VI__METHOD__CHECK_OUTPUT__OptionalList                            \
    ESX_VI__METHOD__CHECK_OUTPUT__NotNone



#define ESX_VI__METHOD__DESERIALIZE_OUTPUT__None(_type)                       \
    /* nothing */



#define ESX_VI__METHOD__DESERIALIZE_OUTPUT__RequiredItem(_type)               \
    if (esxVI_##_type##_Deserialize(response->node, output) < 0) {            \
        goto failure;                                                         \
    }



#define ESX_VI__METHOD__DESERIALIZE_OUTPUT__RequiredList(_type)               \
    if (esxVI_##_type##_DeserializeList(response->node, output) < 0) {        \
        goto failure;                                                         \
    }



#define ESX_VI__METHOD__DESERIALIZE_OUTPUT__OptionalItem(_type)               \
    if (response->node != NULL &&                                             \
        esxVI_##_type##_Deserialize(response->node, output) < 0) {            \
        goto failure;                                                         \
    }



#define ESX_VI__METHOD__DESERIALIZE_OUTPUT__OptionalList(_type)               \
    if (response->node != NULL &&                                             \
        esxVI_##_type##_DeserializeList(response->node, output) < 0) {        \
        goto failure;                                                         \
    }



#define ESX_VI__METHOD(_name, _this_from_service, _parameters, _output_type,  \
                       _occurrence, _validate, _serialize)                    \
    int                                                                       \
    esxVI_##_name _parameters                                                 \
    {                                                                         \
        int result = 0;                                                       \
        const char *methodName = #_name;                                      \
        virBuffer buffer = VIR_BUFFER_INITIALIZER;                            \
        char *request = NULL;                                                 \
        esxVI_Response *response = NULL;                                      \
                                                                              \
        ESX_VI__METHOD__PARAMETER__THIS__##_this_from_service                 \
                                                                              \
        ESX_VI__METHOD__CHECK_OUTPUT__##_occurrence                           \
                                                                              \
        _validate                                                             \
                                                                              \
        virBufferAddLit(&buffer, ESX_VI__SOAP__REQUEST_HEADER);               \
        virBufferAddLit(&buffer, "<"#_name" xmlns=\"urn:vim25\">");           \
                                                                              \
        _serialize                                                            \
                                                                              \
        virBufferAddLit(&buffer, "</"#_name">");                              \
        virBufferAddLit(&buffer, ESX_VI__SOAP__REQUEST_FOOTER);               \
                                                                              \
        if (virBufferError(&buffer)) {                                        \
            virReportOOMError();                                              \
            goto failure;                                                     \
        }                                                                     \
                                                                              \
        request = virBufferContentAndReset(&buffer);                          \
                                                                              \
        if (esxVI_Context_Execute(ctx, methodName, request, &response,        \
                                  esxVI_Occurrence_##_occurrence) < 0) {      \
            goto failure;                                                     \
        }                                                                     \
                                                                              \
        ESX_VI__METHOD__DESERIALIZE_OUTPUT__##_occurrence(_output_type)       \
                                                                              \
      cleanup:                                                                \
        VIR_FREE(request);                                                    \
        esxVI_Response_Free(&response);                                       \
                                                                              \
        return result;                                                        \
                                                                              \
      failure:                                                                \
        virBufferFreeAndReset(&buffer);                                       \
                                                                              \
        result = -1;                                                          \
                                                                              \
        goto cleanup;                                                         \
    }



#define ESX_VI__METHOD__PARAMETER__THIS_FROM_SERVICE(_type, _name)            \
    esxVI_##_type *_this = NULL;                                              \
                                                                              \
    if (ctx->service == NULL) {                                               \
        ESX_VI_ERROR(VIR_ERR_INTERNAL_ERROR, "%s", _("Invalid call"));        \
        return -1;                                                            \
    }                                                                         \
                                                                              \
    _this = ctx->service->_name;



#define ESX_VI__METHOD__PARAMETER__THIS__/* explicit _this */                 \
    /* nothing */



#define ESX_VI__METHOD__PARAMETER__THIS__perfManager                          \
    ESX_VI__METHOD__PARAMETER__THIS_FROM_SERVICE(ManagedObjectReference,      \
                                                 perfManager)



#define ESX_VI__METHOD__PARAMETER__THIS__propertyCollector                    \
    ESX_VI__METHOD__PARAMETER__THIS_FROM_SERVICE(ManagedObjectReference,      \
                                                 propertyCollector)



#define ESX_VI__METHOD__PARAMETER__THIS__searchIndex                          \
    ESX_VI__METHOD__PARAMETER__THIS_FROM_SERVICE(ManagedObjectReference,      \
                                                 searchIndex)



#define ESX_VI__METHOD__PARAMETER__THIS__sessionManager                       \
    ESX_VI__METHOD__PARAMETER__THIS_FROM_SERVICE(ManagedObjectReference,      \
                                                 sessionManager)



/*
 * A required parameter must be != 0 (NULL for pointers, "undefined" == 0 for
 * enumeration values).
 *
 * To be used as part of ESX_VI__METHOD.
 */
#define ESX_VI__METHOD__PARAMETER__REQUIRE(_name)                             \
    if (_name == 0) {                                                         \
        ESX_VI_ERROR(VIR_ERR_INTERNAL_ERROR,                                  \
                     "Required parameter '%s' is missing for call to %s",     \
                     #_name, methodName);                                     \
        return -1;                                                            \
    }



#define ESX_VI__METHOD__PARAMETER__SERIALIZE(_type, _name)                    \
    if (esxVI_##_type##_Serialize(_name, #_name, &buffer) < 0) {              \
        goto failure;                                                         \
    }



#define ESX_VI__METHOD__PARAMETER__SERIALIZE_LIST(_type, _name)               \
    if (esxVI_##_type##_SerializeList(_name, #_name, &buffer) < 0) {          \
        goto failure;                                                         \
    }



#define ESX_VI__METHOD__PARAMETER__SERIALIZE_VALUE(_type, _name)              \
    if (esxVI_##_type##_SerializeValue(_name, #_name, &buffer) < 0) {         \
        goto failure;                                                         \
    }



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * VI Methods
 */

int
esxVI_RetrieveServiceContent(esxVI_Context *ctx,
                             esxVI_ServiceContent **serviceContent)
{
    int result = 0;
    const char *request = ESX_VI__SOAP__REQUEST_HEADER
                            "<RetrieveServiceContent xmlns=\"urn:vim25\">"
                              "<_this xmlns=\"urn:vim25\" "
                                     "xsi:type=\"ManagedObjectReference\" "
                                     "type=\"ServiceInstance\">"
                                "ServiceInstance"
                              "</_this>"
                            "</RetrieveServiceContent>"
                          ESX_VI__SOAP__REQUEST_FOOTER;
    esxVI_Response *response = NULL;

    if (serviceContent == NULL || *serviceContent != NULL) {
        ESX_VI_ERROR(VIR_ERR_INTERNAL_ERROR, "%s", _("Invalid argument"));
        return -1;
    }

    if (esxVI_Context_Execute(ctx, "RetrieveServiceContent", request,
                              &response, esxVI_Occurrence_RequiredItem) < 0 ||
        esxVI_ServiceContent_Deserialize(response->node, serviceContent) < 0) {
        goto failure;
    }

  cleanup:
    esxVI_Response_Free(&response);

    return result;

  failure:
    result = -1;

    goto cleanup;
}



/* esxVI_ValidateMigration */
ESX_VI__METHOD(ValidateMigration, /* special _this */,
               (esxVI_Context *ctx,
                esxVI_ManagedObjectReference *vm,          /* required, list */
                esxVI_VirtualMachinePowerState state,      /* optional */
                esxVI_String *testType,                    /* optional, list */
                esxVI_ManagedObjectReference *pool,        /* optional */
                esxVI_ManagedObjectReference *host,        /* optional */
                esxVI_Event **output),                     /* optional, list */
               Event, OptionalList,
{
    ESX_VI__METHOD__PARAMETER__REQUIRE(vm)
},
{
    virBufferAddLit(&buffer, "<_this xmlns=\"urn:vim25\" "
                                    "xsi:type=\"ManagedObjectReference\" "
                                    "type=\"ServiceInstance\">"
                               "ServiceInstance"
                             "</_this>");
    ESX_VI__METHOD__PARAMETER__SERIALIZE_LIST(ManagedObjectReference, vm)
    ESX_VI__METHOD__PARAMETER__SERIALIZE(VirtualMachinePowerState, state)
    ESX_VI__METHOD__PARAMETER__SERIALIZE_LIST(String, testType)
    ESX_VI__METHOD__PARAMETER__SERIALIZE(ManagedObjectReference, pool)
    ESX_VI__METHOD__PARAMETER__SERIALIZE(ManagedObjectReference, host)
})



#include "esx_vi_methods.generated.c"