/*********************************************************************
* @file
* vi_clock.c
*
* @brief
* Vehicle information module - process clock info
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "task.h"

#include "ewrte.h"
#include "fsl_debug_console.h"
#include "VI_pub.h"
#include "vi_priv.h"
#include "EW_pub.h"
#include "BC_motocon_pub.h"
#include "RTC_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define WAIT_TIME_TO_SEND_CLK_TO_METER_MS               ( 10000 )
#define WAIT_TIME_TO_CHECK_METER_CLK_AUTO_ADJ_STATUS    ( 500 )

#define METER_CLOCK_STATE_IDLE                  ( true )
#define METER_CLOCK_STATE_REQUEST               ( false )

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
typedef enum
    {
    CLK_UPDATE_STATE_IDLE,
    CLK_UPDATE_STATE_WAITING_10_SEC,
    CLK_UPDATE_STATE_CHECK_AFTER_500_MS
    } clk_update_state_enum;

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/
static TimerHandle_t clock_timer_handle;
static clk_update_state_enum clk_update_state = CLK_UPDATE_STATE_IDLE;

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @private
* start_timer
*
* Start timer with specified period
*
* @param period_ms Period in ms
*
*********************************************************************/
static void start_timer
    (
    const uint32_t period_ms
    )
{
BaseType_t result = xTimerChangePeriod( clock_timer_handle, pdMS_TO_TICKS( period_ms ), 0 );
configASSERT( result == pdPASS );
result = xTimerStart( clock_timer_handle, 0 );
configASSERT( result == pdPASS );
}

/*********************************************************************
*
* @private
* stop_timer
*
* Stop timer
*
*********************************************************************/
static void stop_timer
    (
    void
    )
{
if( pdTRUE == xTimerIsTimerActive( clock_timer_handle ) )
    {
    BaseType_t result = xTimerStop( clock_timer_handle, 0 );
    configASSERT( result == pdPASS );
    }
}

/*********************************************************************
*
* @private
* clock_timer_callback
*
* Clock timer callback function
*
* @param timer_handle The handle of clock timer.
*
*********************************************************************/
static void clock_timer_callback
    (
    TimerHandle_t timer_handle
    )
{
snvs_lp_srtc_datetime_t srtc_datetime;
uint32_t clk_adj_status;

switch( clk_update_state )
    {
    case CLK_UPDATE_STATE_WAITING_10_SEC:
        RTC_get_datetime( &srtc_datetime );
        VI_clock_notify_meter_time_updated( srtc_datetime );
        break;
    case CLK_UPDATE_STATE_CHECK_AFTER_500_MS:
        VI_get_rx_data_uint( EnumVehicleRxTypeCLOCK_ADJUSTMENT_STATUS, &clk_adj_status );
        if( METER_CLOCK_STATE_IDLE == clk_adj_status )
            {
            /* meter has received the clock successfully */
            clk_update_state = CLK_UPDATE_STATE_IDLE;
            }
        else
            {
            /* meter does not receive the clock successfully, retry */
            RTC_get_datetime( &srtc_datetime );
            VI_clock_notify_meter_time_updated( srtc_datetime );
            }
        break;
    default:
        break;
    }
}

/*********************************************************************
*
* @public
* VI_clock_notify_meter_time_updated
*
* Update time to Meter.
*
* @param datetime the received datetime
*
*********************************************************************/
void VI_clock_notify_meter_time_updated
    (
    const snvs_lp_srtc_datetime_t datetime
    )
{
stop_timer();

/* If the current second is 50 or later, wait 10 seconds before sending clock to meter */
if( datetime.second < 50 )
    {
    uint64_t unix_timestamp = RTC_convert_datetime_to_epoch_sec( &datetime );
    VI_set_tx_data( EnumVehicleTxTypeCLOCK_DATE, unix_timestamp );

    clk_update_state = CLK_UPDATE_STATE_CHECK_AFTER_500_MS;
    start_timer( WAIT_TIME_TO_CHECK_METER_CLK_AUTO_ADJ_STATUS );
    }
else
    {
    clk_update_state = CLK_UPDATE_STATE_WAITING_10_SEC;
    start_timer( WAIT_TIME_TO_SEND_CLK_TO_METER_MS );
    }
}

/*********************************************************************
*
* @public
* VI_clock_send_rtc_time_to_meter
*
* Send RTC time to meter
*
*********************************************************************/
void VI_clock_send_rtc_time_to_meter
    (
    void
    )
{
snvs_lp_srtc_datetime_t datetime;
RTC_get_datetime( &datetime );
VI_clock_notify_meter_time_updated( datetime );
}

/*********************************************************************
*
* @public
* vi_clock_notify_meter_clk_adj_status_changed
*
* Notify the status of clk_adj_status from meter is changed
*
* @param meter_clock_adj_status False: meter requests clk
*                               True:  meter received clk
*
*********************************************************************/
void vi_clock_notify_meter_clk_adj_status_changed
    (
    const uint32_t meter_clock_adj_status
    )
{
switch( meter_clock_adj_status )
    {
    case METER_CLOCK_STATE_IDLE:
        /* meter has received the clock successfully, so no need to check after 500ms */
        if( CLK_UPDATE_STATE_CHECK_AFTER_500_MS == clk_update_state )
            {
            stop_timer();
            clk_update_state = CLK_UPDATE_STATE_IDLE;
            }
        break;
    case METER_CLOCK_STATE_REQUEST:
        if( EW_get_clk_auto_adj() && BC_motocon_is_connected() )
            {
            /* get smartphone time if Auto Adjustment is enabled and MotoCon is connected */
            BC_motocon_set_request_from_clock();
            BC_motocon_send_vehicle_setting_request();
            }
        else
            {
            VI_clock_send_rtc_time_to_meter();
            }
        break;
    default:
        break;
    }
}

/*********************************************************************
*
* @private
* vi_clock_init
*
* Initialize vehicle clock timer
*
*********************************************************************/
void vi_clock_init
    (
    void
    )
{
clock_timer_handle = xTimerCreate( "clock_update_timer", pdMS_TO_TICKS( WAIT_TIME_TO_SEND_CLK_TO_METER_MS ), pdFALSE, ( void* ) 0, clock_timer_callback );
configASSERT( NULL != clock_timer_handle );
}
