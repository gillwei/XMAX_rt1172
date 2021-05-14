/*********************************************************************
* @file
* mm_main.c
*
* @brief
* Media manager module - main
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "ewrte.h"
#include "event_groups.h"
#include "EW_pub.h"
#include "fsl_debug_console.h"
#include "queue.h"
#include "HCI_pub.h"
#include "GRM_pub_prj.h"
#include "mm_priv.h"
#include "MM_pub.h"
#include "BC_ams_pub.h"
#include "BC_motocon_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define MM_TASK_PRIORITY   ( TASK_PRIO_MEDIA_MNGR )
#define MM_TASK_STACK_SIZE ( configMINIMAL_STACK_SIZE * 4 )
#define MM_TASK_NAME       "mm_task"
#define MM_QUEUE_LENGTH    ( 10 )
#define MM_COMPUTE_ELAPSED_TIME_DURATION_MS    ( 500 )

#define EVENT_AMS_CMD_RECEIVED ( 1 << 0 )
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
static QueueHandle_t remote_command = NULL;
static EventGroupHandle_t mm_event_group = NULL;
static TimerHandle_t elapsed_timer_handle;
static mm_media_player_obj media_player;

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @private
* mm_ams_gatt_update_elapsed_time
*
* Update elapsed time
*
*********************************************************************/
void mm_ams_gatt_update_elapsed_time
    (
    void
    )
{
if( media_player.playback_state == MP_PLAYBACK_STATUS_PLAYING ||
    media_player.playback_state == MP_PLAYBACK_STATUS_FAST_FORWARDING ||
    media_player.playback_state == MP_PLAYBACK_STATUS_REWINDING )
    {
    uint32_t elapsed_time_sec = ( media_player.start_elapsed_time_ms +
        ( uint32_t )( ( float )( xTaskGetTickCount() - media_player.start_elapsed_time_tick ) * media_player.playback_rate ) ) / 1000;

    if( media_player.current_elapsed_time_sec != elapsed_time_sec )
        {
        media_player.current_elapsed_time_sec = elapsed_time_sec;
        EW_notify_playback_time_changed();
        }
    }
}

/*********************************************************************
*
* @private
* mm_timer_callback
*
* A timer callback function which calls time update function.
*
* @param timer_handle The handle of delay timer.
*
*********************************************************************/
static void mm_timer_callback
    (
    TimerHandle_t timer_handle
    )
{
if( media_player.current_elapsed_time_sec < media_player.duration_sec )
    {
    mm_ams_gatt_update_elapsed_time();
    }
else
    {
    mm_stop_elapsed_timer();
    }
}

/*********************************************************************
*
* @private
* create_elapsed_timer
*
* Create the elapsed timer to notify the elapsed time information
* to embedded wizard
*
*********************************************************************/
static void create_elapsed_timer
    (
    void
    )
{
elapsed_timer_handle = xTimerCreate( "elapsed_timer", pdMS_TO_TICKS( MM_COMPUTE_ELAPSED_TIME_DURATION_MS ), pdTRUE, ( void * ) 0, mm_timer_callback );
configASSERT( NULL != elapsed_timer_handle );
}

/*********************************************************************
*
* @private
* mm_start_elapsed_timer
*
* Start timer to update elapsed time.
*
*********************************************************************/
void mm_start_elapsed_timer
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
BaseType_t result = xTimerStart( elapsed_timer_handle, 0 );
configASSERT( result == pdPASS );
}

/*********************************************************************
*
* @private
* mm_stop_elapsed_timer
*
* Stop timer to stop the update of elapsed time.
*
*********************************************************************/
void mm_stop_elapsed_timer
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
BaseType_t result = xTimerStop( elapsed_timer_handle, 0 );
configASSERT( result == pdPASS );
}

/*********************************************************************
*
* @private
* mm_queue_cmd
*
* Insert user command to queue.
*
* @param send_cmd ams remote command type.
* @return Result of sending command to queue.
*
*********************************************************************/
bool mm_queue_cmd
    (
    ams_remote_command send_cmd
    )
{
bool cmd_sent = true;
if( pdTRUE != xQueueSend( remote_command, &send_cmd, 0 ) )
    {
    cmd_sent = false;
    EwPrint( "%s err\r\n", __FUNCTION__ );
    }
xEventGroupSetBits( mm_event_group, EVENT_AMS_CMD_RECEIVED );
return cmd_sent;
}

/*********************************************************************
*
* @public
* MM_ams_gatt_get_media_player_state
*
* Obtain media player state data
* @return media player state data
*
*********************************************************************/
mm_media_player_obj* MM_ams_gatt_get_media_player_state
    (
    void
    )
{
return &media_player;
}

/*********************************************************************
*
* @public
* MM_update_playback_status
*
* Decide to stop timer of song based on Ble connected status.
* @param ble_cnnt_status BLE connected status.
*
*********************************************************************/
void MM_update_playback_status
    (
    const bool ble_cnnt_status
    )
{
if( !ble_cnnt_status )
    {
    mm_stop_elapsed_timer();
    }
EW_notify_ams_ble_connected();
}

/*********************************************************************
*
* @public
* MM_send_command
*
* Send user command to queue.
*
* @param command Ams remote command type.
* @return Result of sending command.
*
*********************************************************************/
bool MM_send_command
    (
    ams_remote_command command
    )
{
return mm_queue_cmd( command );
}

/*********************************************************************
*
* @private
* task_main
*
* Main loop of the media manager task.
*
*********************************************************************/
static void task_main
    (
    void* arg
    )
{
ams_remote_command recv_cmd;
EventBits_t mm_event_bits;

while( true )
    {
    mm_event_bits = xEventGroupWaitBits
                    (
                    mm_event_group,
                    EVENT_AMS_CMD_RECEIVED,
                    pdTRUE,
                    pdFALSE,
                    portMAX_DELAY
                    );

    if( EVENT_AMS_CMD_RECEIVED == ( mm_event_bits & EVENT_AMS_CMD_RECEIVED ) )
        {
        while( pdPASS == xQueueReceive( remote_command, &recv_cmd, portMAX_DELAY ) )
            {
            switch( recv_cmd )
                {
                case AMS_REMOTE_COMMAND_PLAY:
                    if( BC_ams_is_ams_connected() )
                        {
                        BC_ams_send_remote_control( AMS_REMOTE_COMMAND_PLAY );
                        }
                    else if( BC_motocon_is_connected() )
                        {
                        // TODO: Because MotoCon SDK is not completed yet, I can only set playback state here in order to make UI reflect the play/pause status when
                        // sending play/pause remote command from LC. Once Yamaha updates MotoCon SDK regarding playback state. We have to remove below setting.
                        media_player.playback_state = MP_PLAYBACK_STATUS_PLAYING;
                        media_player.playback_rate = 1.0;
                        media_player.start_elapsed_time_tick = xTaskGetTickCount();
                        mm_start_elapsed_timer();
                        BC_motocon_send_bt_music_control( BC_MOTOCON_MUSIC_PLAY );
                        }
                    else
                        {
                        PRINTF( "%s, play command can not be sent due to disconnection of AMS and MotoCon\r\n", __FUNCTION__ );
                        }
                    break;
                case AMS_REMOTE_COMMAND_PAUSE:
                    if( BC_ams_is_ams_connected() )
                        {
                        BC_ams_send_remote_control( AMS_REMOTE_COMMAND_PAUSE );
                        }
                    else if( BC_motocon_is_connected() )
                        {
                        // TODO: Because MotoCon SDK is not completed yet, I can only set playback state here in order to make UI reflect the play/pause status when
                        // sending play/pause remote command from LC. Once Yamaha updates MotoCon SDK regarding playback state. We have to remove below setting.
                        media_player.playback_state = MP_PLAYBACK_STATUS_PAUSED;
                        mm_stop_elapsed_timer();
                        BC_motocon_send_bt_music_control( BC_MOTOCON_MUSIC_PAUSE );
                        }
                    else
                        {
                        PRINTF( "%s, pause command can not be sent due to disconnection of AMS and MotoCon\r\n", __FUNCTION__ );
                        }
                    break;
                case AMS_REMOTE_COMMAND_NEXT_TRACK:
                    mm_stop_elapsed_timer();
                    if( BC_ams_is_ams_connected() )
                        {
                        BC_ams_send_remote_control( AMS_REMOTE_COMMAND_NEXT_TRACK );
                        }
                    else if( BC_motocon_is_connected() )
                        {
                        BC_motocon_send_bt_music_control( BC_MOTOCON_MUSIC_NEXT_TRACK );
                        }
                    else
                        {
                        PRINTF( "%s, next track command can not be sent due to disconnection of AMS and MotoCon\r\n", __FUNCTION__ );
                        }
                    break;
                case AMS_REMOTE_COMMAND_PREVIOUS_TRACK:
                    mm_stop_elapsed_timer();
                    if( BC_ams_is_ams_connected() )
                        {
                        BC_ams_send_remote_control( AMS_REMOTE_COMMAND_PREVIOUS_TRACK );
                        }
                    else if( BC_motocon_is_connected() )
                        {
                        BC_motocon_send_bt_music_control( BC_MOTOCON_MUSIC_PREVIOUS_TRACK );
                        }
                    else
                        {
                        PRINTF( "%s, previous track command can not be sent due to disconnection of AMS and MotoCon\r\n", __FUNCTION__ );
                        }
                    break;
                case AMS_REMOTE_COMMAND_VOLUME_UP:
                    if( BC_ams_is_ams_connected() )
                        {
                        BC_ams_send_remote_control( AMS_REMOTE_COMMAND_VOLUME_UP );
                        }
                    else if( BC_motocon_is_connected() )
                        {
                        BC_motocon_send_volume_control( BC_MOTOCON_MEDIA_VOLUME_UP );
                        }
                    else
                        {
                        PRINTF( "%s, volume up command can not be sent due to disconnection of AMS and MotoCon\r\n", __FUNCTION__ );
                        }
                    break;
                case AMS_REMOTE_COMMAND_VOLUME_DOWN:
                    if( BC_ams_is_ams_connected() )
                        {
                        BC_ams_send_remote_control( AMS_REMOTE_COMMAND_VOLUME_DOWN );
                        }
                    else if( BC_motocon_is_connected() )
                        {
                        BC_motocon_send_volume_control( BC_MOTOCON_MEDIA_VOLUME_DOWN );
                        }
                    else
                        {
                        PRINTF( "%s, volume down command can not be sent due to disconnection of AMS and MotoCon\r\n", __FUNCTION__ );
                        }
                    break;
                default:
                    break;
                }
            }
        }
    }

vTaskDelete( NULL );
}

/*********************************************************************
*
* @public
* MM_init
*
* Init media manager module.
*
*********************************************************************/
void MM_init
    (
    void
    )
{
BaseType_t result = xTaskCreate( task_main, MM_TASK_NAME, MM_TASK_STACK_SIZE, NULL, MM_TASK_PRIORITY, NULL );
configASSERT( pdPASS == result );

mm_event_group = xEventGroupCreate();

remote_command = xQueueCreate( MM_QUEUE_LENGTH, sizeof( ams_remote_command ) );
configASSERT( NULL != remote_command );

create_elapsed_timer();

mm_motocon_init();
}
