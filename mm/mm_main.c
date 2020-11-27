/*********************************************************************
* @file
* mm_main.c
*
* @brief
* Media manager module - main
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
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

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

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
mm_update_elapsed_time();
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
                    HCI_avrc_play();
                    break;
                case AMS_REMOTE_COMMAND_PAUSE:
                    HCI_avrc_pause();
                    break;
                case AMS_REMOTE_COMMAND_NEXT_TRACK:
                    mm_stop_elapsed_timer();
                    HCI_avrc_play_next_track();
                    break;
                case AMS_REMOTE_COMMAND_PREVIOUS_TRACK:
                    mm_stop_elapsed_timer();
                    HCI_avrc_play_previous_track();
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
mm_ams_avrc_handler_init();

BaseType_t result = xTaskCreate( task_main, MM_TASK_NAME, MM_TASK_STACK_SIZE, NULL, MM_TASK_PRIORITY, NULL );
configASSERT( pdPASS == result );

mm_event_group = xEventGroupCreate();

remote_command = xQueueCreate( MM_QUEUE_LENGTH, sizeof( ams_remote_command ) );
configASSERT( NULL != remote_command );

create_elapsed_timer();
}
