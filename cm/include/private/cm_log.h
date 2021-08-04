/*********************************************************************
* @file  cm_log.h
* @brief Connection Manager Log interface declaration.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifndef _CM_LOG_H_
#define _CM_LOG_H_

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "cm_types.h"

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
#define CM_LOG( severity, ... ) CM_log( severity, __FILE__, __func__, __LINE__, __VA_ARGS__ )

#define CM_LOG_FATAL( ... )   CM_LOG( CM_LOG_FATAL, __VA_ARGS__ )
#define CM_LOG_ERROR( ... )   CM_LOG( CM_LOG_ERROR, __VA_ARGS__ )
#define CM_LOG_WARNING( ... ) CM_LOG( CM_LOG_WARNING, __VA_ARGS__ )
#define CM_LOG_INFO( ... )    CM_LOG( CM_LOG_INFO, __VA_ARGS__ )
#define CM_LOG_DEBUG( ... )   CM_LOG( CM_LOG_DEBUG, __VA_ARGS__ )
#define CM_LOG_VERBOSE( ... ) CM_LOG( CM_LOG_VERBOSE, __VA_ARGS__ )

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
void CM_log
    (
    const CM_log_severity_e severity,
    const char* file_name,
    const char* func_name,
    const uint32_t line_num,
    ...
    );

void CM_log_set_level
    (
    const CM_log_severity_e severity
    );

#ifdef __cplusplus
}
#endif

#endif // _CM_LOG_H_
