/*********************************************************************
* @file
* vi_trip_time.c
*
* @brief
* Vehicle information module - trip time
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "task.h"

#include "semphr.h"
#include "ewrte.h"
#include "fsl_debug_console.h"
#include "EEPM_pub.h"
#include "EW_pub.h"
#include "VI_pub.h"
#include "vi_priv.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define MAX_TRIP_TIME_SEC   ( 362340 ) /* 99hr 99min: ((99*60)+99)*60 */

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
static uint32_t trip_time_sec;
static bool     is_trip_time_valid = false;

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @public
* VI_trip_time_write_cb
*
* Callback of write trip time to EEPROM
*
* @param result True if write success. False if write fail.
* @param value Pointer to the trip time of uint8_t*, length TRIP_TIME_LENGTH
*
*********************************************************************/
void VI_trip_time_write_cb
    (
    bool  result,
    void* value
    )
{
if( !result )
    {
    PRINTF( "wt trip time cb fail\r\n" );
    }
EW_power_update_ignoff_task_status( IGN_OFF_TASK_WRITE_TRIP_TIME );
}

/*********************************************************************
*
* @public
* VI_trip_time_read_cb
*
* Callback of read trip time from EEPROM
*
* @param result True if read success. False if read fail.
* @param value Pointer to the trip time of uint8_t*, length TRIP_TIME_LENGTH
*
*********************************************************************/
void VI_trip_time_read_cb
    (
    bool  result,
    void* value
    )
{
uint8_t* eep_trip_time = (uint8_t*)value;
uint32_t eep_trip_time_sec = 0;

if( result )
    {
    eep_trip_time_sec = ( eep_trip_time[3] << 24 ) | ( eep_trip_time[2] << 16 ) | ( eep_trip_time[1] << 8 ) | eep_trip_time[0];
    PRINTF( "rd trip time %d\r\n", eep_trip_time_sec );

    // Handle all 0xFF initial data from EEPROM
    if( EEPROM_INVALID_VAL_4_BYTE == eep_trip_time_sec )
        {
        trip_time_sec = 0;
        }
    else
        {
        trip_time_sec = eep_trip_time_sec;
        }
    }
else
    {
    PRINTF( "rd trip time cb fail\r\n" );
    }

is_trip_time_valid = result;
}

/*********************************************************************
*
* @public
* VI_trip_time_count
*
* Count trip time in second
*
*********************************************************************/
void VI_trip_time_count
    (
    void
    )
{
if( is_trip_time_valid &&
    MAX_TRIP_TIME_SEC > trip_time_sec )
    {
    uint32_t next_trip_time_sec = trip_time_sec + 1;

    // notify UI trip time changed in minute resolution
    if( ( next_trip_time_sec / 60 ) != ( trip_time_sec / 60 ) )
        {
        EW_notify_vi_data_received( EnumVehicleRxTypeTRIP_TIME );
        }

    trip_time_sec = next_trip_time_sec;
    }
}

/*********************************************************************
*
* @public
* VI_trip_time_save
*
* Save trip time to EEPROM
*
*********************************************************************/
void VI_trip_time_save
    (
    void
    )
{
if( is_trip_time_valid )
    {
    if( pdFALSE == EEPM_set_trip_time( trip_time_sec, VI_trip_time_write_cb ) )
        {
        PRINTF( "wt trip time fail\r\n" );
        EW_power_update_ignoff_task_status( IGN_OFF_TASK_WRITE_TRIP_TIME );
        }
    }
else
    {
    EW_power_update_ignoff_task_status( IGN_OFF_TASK_WRITE_TRIP_TIME );
    }
}

/*********************************************************************
*
* @private
* vi_trip_time_get_current
*
* Get current trip time
*
* @param current_trip_time_sec Pointer to the current trip time
* @return Valid status of trip time
*
*********************************************************************/
bool vi_trip_time_get_current
    (
    uint32_t* current_trip_time_sec
    )
{
if( MAX_TRIP_TIME_SEC >= trip_time_sec )
    {
    *current_trip_time_sec = trip_time_sec;
    }
else
    {
    *current_trip_time_sec = MAX_TRIP_TIME_SEC;
    }
return is_trip_time_valid;
}

/*********************************************************************
*
* @private
* vi_trip_time_reset
*
* Reset trip time
*
*********************************************************************/
void vi_trip_time_reset
    (
    void
    )
{
trip_time_sec = 0;
}

/*********************************************************************
*
* @private
* vi_trip_time_init
*
* Initialize vehicle information module - trip time
*
*********************************************************************/
void vi_trip_time_init
    (
    void
    )
{
if( pdFALSE == EEPM_get_trip_time( VI_trip_time_read_cb ) )
    {
    PRINTF( "rd trip time fail\r\n" );
    }
}
