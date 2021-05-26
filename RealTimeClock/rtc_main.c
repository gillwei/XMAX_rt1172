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
snvs_lp_srtc_datetime_t srtcDate;
snvs_lp_srtc_config_t snvsSrtcConfig;

/* Init SNVS_LP */
SNVS_LP_SRTC_GetDefaultConfig( &snvsSrtcConfig );
SNVS_LP_SRTC_Init( SNVS, &snvsSrtcConfig );

PRINTF( "%s ok\r\n", __FUNCTION__ );

/* Set a start date time and start RT */
srtcDate.year   = 2022U;
srtcDate.month  = 1U;
srtcDate.day    = 1U;
srtcDate.hour   = 0U;
srtcDate.minute = 0;
srtcDate.second = 0;

/* Set SRTC time to default time and date and start the SRTC */
SNVS_LP_SRTC_SetDatetime( SNVS, &srtcDate );
SNVS_LP_SRTC_StartTimer( SNVS );
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
