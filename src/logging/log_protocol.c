#include <config.h>
/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "log_protocol.h"
#include "internal.h"

bool_t
xdr_virLogManagerProtocolUUID (XDR *xdrs, virLogManagerProtocolUUID objp)
{

         if (!xdr_opaque (xdrs, objp, VIR_UUID_BUFLEN))
                 return FALSE;
        return TRUE;
}

bool_t
xdr_virLogManagerProtocolNonNullString (XDR *xdrs, virLogManagerProtocolNonNullString *objp)
{

         if (!xdr_string (xdrs, objp, VIR_LOG_MANAGER_PROTOCOL_STRING_MAX))
                 return FALSE;
        return TRUE;
}

bool_t
xdr_virLogManagerProtocolString (XDR *xdrs, virLogManagerProtocolString *objp)
{

         if (!xdr_pointer (xdrs, (char **)objp, sizeof (virLogManagerProtocolNonNullString), (xdrproc_t) xdr_virLogManagerProtocolNonNullString))
                 return FALSE;
        return TRUE;
}

bool_t
xdr_virLogManagerProtocolDomain (XDR *xdrs, virLogManagerProtocolDomain *objp)
{

         if (!xdr_virLogManagerProtocolUUID (xdrs, objp->uuid))
                 return FALSE;
         if (!xdr_virLogManagerProtocolNonNullString (xdrs, &objp->name))
                 return FALSE;
        return TRUE;
}

bool_t
xdr_virLogManagerProtocolLogFilePosition (XDR *xdrs, virLogManagerProtocolLogFilePosition *objp)
{

         if (!xdr_uint64_t (xdrs, &objp->inode))
                 return FALSE;
         if (!xdr_uint64_t (xdrs, &objp->offset))
                 return FALSE;
        return TRUE;
}

bool_t
xdr_virLogManagerProtocolDomainOpenLogFileArgs (XDR *xdrs, virLogManagerProtocolDomainOpenLogFileArgs *objp)
{

         if (!xdr_virLogManagerProtocolNonNullString (xdrs, &objp->driver))
                 return FALSE;
         if (!xdr_virLogManagerProtocolDomain (xdrs, &objp->dom))
                 return FALSE;
         if (!xdr_u_int (xdrs, &objp->flags))
                 return FALSE;
        return TRUE;
}

bool_t
xdr_virLogManagerProtocolDomainOpenLogFileRet (XDR *xdrs, virLogManagerProtocolDomainOpenLogFileRet *objp)
{

         if (!xdr_virLogManagerProtocolLogFilePosition (xdrs, &objp->pos))
                 return FALSE;
        return TRUE;
}

bool_t
xdr_virLogManagerProtocolDomainGetLogFilePositionArgs (XDR *xdrs, virLogManagerProtocolDomainGetLogFilePositionArgs *objp)
{

         if (!xdr_virLogManagerProtocolNonNullString (xdrs, &objp->driver))
                 return FALSE;
         if (!xdr_virLogManagerProtocolDomain (xdrs, &objp->dom))
                 return FALSE;
         if (!xdr_u_int (xdrs, &objp->flags))
                 return FALSE;
        return TRUE;
}

bool_t
xdr_virLogManagerProtocolDomainGetLogFilePositionRet (XDR *xdrs, virLogManagerProtocolDomainGetLogFilePositionRet *objp)
{

         if (!xdr_virLogManagerProtocolLogFilePosition (xdrs, &objp->pos))
                 return FALSE;
        return TRUE;
}

bool_t
xdr_virLogManagerProtocolDomainReadLogFileArgs (XDR *xdrs, virLogManagerProtocolDomainReadLogFileArgs *objp)
{

         if (!xdr_virLogManagerProtocolNonNullString (xdrs, &objp->driver))
                 return FALSE;
         if (!xdr_virLogManagerProtocolDomain (xdrs, &objp->dom))
                 return FALSE;
         if (!xdr_virLogManagerProtocolLogFilePosition (xdrs, &objp->pos))
                 return FALSE;
         if (!xdr_uint64_t (xdrs, &objp->maxlen))
                 return FALSE;
         if (!xdr_u_int (xdrs, &objp->flags))
                 return FALSE;
        return TRUE;
}

bool_t
xdr_virLogManagerProtocolDomainReadLogFileRet (XDR *xdrs, virLogManagerProtocolDomainReadLogFileRet *objp)
{

         if (!xdr_virLogManagerProtocolNonNullString (xdrs, &objp->data))
                 return FALSE;
        return TRUE;
}

bool_t
xdr_virLogManagerProtocolProcedure (XDR *xdrs, virLogManagerProtocolProcedure *objp)
{

         if (!xdr_enum (xdrs, (enum_t *) objp))
                 return FALSE;
        return TRUE;
}
