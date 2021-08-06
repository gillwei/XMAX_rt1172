/*********************************************************************
* @file  cm_prv.h
* @brief Defines the Connection Manager private procedures
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifndef _CM_PRV_H_
#define _CM_PRV_H_

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "fsl_debug_console.h"

#define CM_PRINT_ENABLE 1
#if CM_PRINT_ENABLE
    #define CM_PRINT PRINTF
#else
    #define CM_PRINT
#endif

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/


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
//void CM_log
//    (
//    const char *format, ...
//    );


#ifdef __cplusplus
}
#endif

#endif // _CM_TYPES_H_