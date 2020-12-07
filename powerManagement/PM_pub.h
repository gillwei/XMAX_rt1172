/*********************************************************************
* @file
* PM_pub.h
*
* @brief
* power management module - public API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef PM_PUB_H
#define PM_PUB_H


#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "fsl_common.h"
#include "FreeRTOSConfig.h"
#include "projdefs.h"
#include "portmacro.h"
#include "board.h"

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define PM_IGN_ON   ( 0 )
#define PM_IGN_OFF  ( 1 )
/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        VARIABLES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
void PM_init
    (
    void
    );

void PM_register_callback
    (
    const char* const    name,
    void ( *func_ptr ) ( bool )
    );

void PM_unregister_callback
    (
    const char* const    moduleName
    );

void PM_system_reset
    (
    void
    );

#ifdef __cplusplus
}
#endif

#endif /*PM_PUB_H */

