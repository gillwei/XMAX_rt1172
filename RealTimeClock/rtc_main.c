/*********************************************************************
* @file
* rtc_main.c
*
* Brief Real Time Clock interface for RTC read/write.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "fsl_debug_console.h"
#include "board.h"

#include "pin_mux.h"
#include "clock_config.h"

#include "RTC_pub.h"
#include <time.h>

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define DEFAULT_RTC_YEAR    ( 2020 )
#define DEFAULT_RTC_MONTH   ( 1 )
#define DEFAULT_RTC_DAY     ( 1 )
#define DEFAULT_RTC_HOUR    ( 1 )
#define DEFAULT_RTC_MINUTE  ( 0 )
#define DEFAULT_RTC_SEC     ( 0 )

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

/*********************************************************************
*
* @public
* RTC_init
*
* @brief Initializes the LP RTC parameter
*
*********************************************************************/
void RTC_init
    (
    void
    )
{
snvs_lp_srtc_config_t snvsSrtcConfig;

/* Init SNVS_LP */
SNVS_LP_SRTC_GetDefaultConfig( &snvsSrtcConfig );
SNVS_LP_SRTC_Init( SNVS, &snvsSrtcConfig );

PRINTF( "%s ok\r\n", __FUNCTION__ );

/* Set a start date time and start RT */
RTC_reset();
SNVS_LP_SRTC_StartTimer( SNVS );
}

/*********************************************************************
*
* @public
* RTC_reset
*
* @brief Reset RTC to the default time
*
*********************************************************************/
void RTC_reset
    (
    void
    )
{
/* reset RTC */
snvs_lp_srtc_datetime_t datetime;
datetime.year   = DEFAULT_RTC_YEAR;
datetime.month  = DEFAULT_RTC_MONTH;
datetime.day    = DEFAULT_RTC_DAY;
datetime.hour   = DEFAULT_RTC_HOUR;
datetime.minute = DEFAULT_RTC_MINUTE;
datetime.second = DEFAULT_RTC_SEC;
RTC_set_dateTime( &datetime );
}

/*********************************************************************
*
* @public
* RTC_set_dateTime
*
* @brief set the RTC with specified datetime
*
* @param datetime pointer of specified datetime value
*
*********************************************************************/
status_t RTC_set_dateTime
    (
    snvs_lp_srtc_datetime_t * datetime
    )
{
status_t ret;
ret = SNVS_LP_SRTC_SetDatetime( SNVS, datetime );
return ret;
}

/*********************************************************************
*
* @public
* RTC_get_datetime
*
* @brief get the RTC datetime
*
* @param datetime pointer of returned datetime
*
*********************************************************************/
void RTC_get_datetime
    (
    snvs_lp_srtc_datetime_t * datetime
    )
{
SNVS_LP_SRTC_GetDatetime( SNVS, datetime );
}

/*********************************************************************
*
* @public
* RTC_convert_datetime_to_epoch_sec
*
* @brief Convert RTC datetime to second
*
* @param datetime pointer of returned datetime
*
*********************************************************************/
uint64_t RTC_convert_datetime_to_epoch_sec
    (
    const snvs_lp_srtc_datetime_t* datetime
    )
{
uint64_t timestamp;
struct tm converted_time;
time_t epoch_time;

converted_time.tm_year = datetime->year - 1900;
converted_time.tm_mon = datetime->month - 1;
converted_time.tm_mday = datetime->day;
converted_time.tm_hour = datetime->hour;
converted_time.tm_min = datetime->minute;
converted_time.tm_sec = datetime->second;
converted_time.tm_isdst = -1;
epoch_time = mktime( &converted_time );
timestamp = epoch_time;

return timestamp;
}
