/*********************************************************************
* @file  bt_log.c
* @brief Bluetooth Manager Log interface definition.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <stdarg.h>
#include <stdio.h>

#include "fsl_debug_console.h"
#include "RTC_pub.h"

#include "bt_log.h"

/*--------------------------------------------------------------------
                        Definitions
--------------------------------------------------------------------*/
#define BT_LOG_BUF_SIZE ( 150 )

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
static const char s_log_severity_names[][4] =
    {
    /* BT_LOG_FATAL   */ "FTL",
    /* BT_LOG_ERROR   */ "ERR",
    /* BT_LOG_WARNING */ "WAR",
    /* BT_LOG_INFO    */ "INF",
    /* BT_LOG_DBG     */ "DBG",
    /* BT_LOG_VERBOSE */ "VER"
    };

/*--------------------------------------------------------------------
                        VARIABLES
--------------------------------------------------------------------*/
static BT_log_severity_e s_log_level = BT_LOG_INFO;

/*--------------------------------------------------------------------
                        PROTOTYPES
--------------------------------------------------------------------*/
static const char* BT_log_severity_to_string
    (
    const BT_log_severity_e severity
    );

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
/*================================================================================================
@brief   Print the debug message to standard output
@details Print the debug message to standard output
@return  None
@retval  None
================================================================================================*/
void BT_log
    (
    const BT_log_severity_e severity,
    const char* file_name,
    const char* func_name,
    const uint32_t line_num,
    ...
    )
{
va_list v_list;
char* format;
const char* severity_name;
char log_buf[BT_LOG_BUF_SIZE];
snvs_lp_srtc_datetime_t datetime;

if( ( severity < 0 ) || ( severity >= BT_LOG_SEVERITY_INVALID ) || ( severity > s_log_level ) )
    {
    return;
    }

RTC_get_datetime( &datetime );

severity_name = BT_log_severity_to_string( severity );

va_start( v_list, line_num );
format = va_arg( v_list, char* );
vsnprintf( log_buf, ( sizeof( log_buf ) - 1 ), format, v_list );
va_end( v_list );

PRINTF( "[BT][%02u-%02u %02u:%02u:%02u][%s][%s/%s:%u] %s\r\n",
        datetime.month, datetime.day, datetime.hour, datetime.minute, datetime.second,
        severity_name, file_name, func_name, line_num,
        log_buf );
}

/*================================================================================================
@brief   Set the log level
@details Set the log level
@return  None
@retval  None
================================================================================================*/
void BT_log_set_level
    (
    const BT_log_severity_e severity
    )
{
if( ( severity >= 0 ) && ( severity < BT_LOG_SEVERITY_INVALID ) )
    {
    s_log_level = severity;
    }
}

/*================================================================================================
@brief   Convert the log severity to string
@details Convert the log severity to string
@return  None
@retval  String of the log severity
================================================================================================*/
static const char* BT_log_severity_to_string
    (
    const BT_log_severity_e severity
    )
{
if( ( severity < 0 ) && ( severity >= ( sizeof( s_log_severity_names ) / sizeof( s_log_severity_names[0] ) ) ) )
    {
    return NULL;
    }
return s_log_severity_names[severity];
}

#ifdef __cplusplus
}
#endif
