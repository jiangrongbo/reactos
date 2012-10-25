/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         ReactOS User API Server DLL
 * FILE:            win32ss/user/winsrv/server.c
 * PURPOSE:         Server APIs
 * PROGRAMMERS:     Eric Kohl
 *                  Hermes Belusca-Maito (hermes.belusca@sfr.fr)
 */

/* INCLUDES ******************************************************************/

#include "winsrv.h"

#define NDEBUG
#include <debug.h>


/* GLOBALS *******************************************************************/

static BOOLEAN ServicesProcessIdValid = FALSE;
static ULONG_PTR ServicesProcessId;


/* FUNCTIONS *****************************************************************/

CSR_API(SrvRegisterServicesProcess)
{
    PCSRSS_REGISTER_SERVICES_PROCESS RegisterServicesProcessRequest = &((PUSER_API_MESSAGE)ApiMessage)->Data.RegisterServicesProcessRequest;

    if (ServicesProcessIdValid == TRUE)
    {
        /* Only accept a single call */
        return STATUS_INVALID_PARAMETER;
    }
    else
    {
        ServicesProcessId = (ULONG_PTR)RegisterServicesProcessRequest->ProcessId;
        ServicesProcessIdValid = TRUE;
        return STATUS_SUCCESS;
    }
}

/* EOF */
