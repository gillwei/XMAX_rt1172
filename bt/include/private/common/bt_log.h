/*********************************************************************
* @file  bt_log.h
* @brief Bluetooth Manager Log interface declaration.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifndef _BT_LOG_H_
#define _BT_LOG_H_

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "bt_types.h"

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
#define BT_LOG( severity, ... ) BT_log( severity, __FILE__, __func__, __LINE__, __VA_ARGS__ )

#define BT_LOG_FATAL( ... )   BT_LOG( BT_LOG_FATAL, __VA_ARGS__ )
#define BT_LOG_ERROR( ... )   BT_LOG( BT_LOG_ERROR, __VA_ARGS__ )
#define BT_LOG_WARNING( ... ) BT_LOG( BT_LOG_WARNING, __VA_ARGS__ )
#define BT_LOG_INFO( ... )    BT_LOG( BT_LOG_INFO, __VA_ARGS__ )
#define BT_LOG_DEBUG( ... )   BT_LOG( BT_LOG_DEBUG, __VA_ARGS__ )
#define BT_LOG_VERBOSE( ... ) BT_LOG( BT_LOG_VERBOSE, __VA_ARGS__ )

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
void BT_log
    (
    const BT_log_severity_e severity,
    const char* file_name,
    const char* func_name,
    const uint32_t line_num,
    ...
    );

void BT_log_set_level
    (
    const BT_log_severity_e severity
    );

#ifdef __cplusplus
}
#endif

#endif // _BT_LOG_H_
