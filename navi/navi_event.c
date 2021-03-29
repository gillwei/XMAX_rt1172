/*********************************************************************
* @file
* navi_event.c
*
* @brief
* Navigation module - Handle navigation event
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "fsl_debug_console.h"
#include "EW_pub.h"
#include "NAVI_pub.h"
#include "navi_priv.h"
#include "NAVILITE_pub.h"
#include "error_code.h"

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
static QueueHandle_t event_queue;

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @private
* navi_add_event
*
* Add navi event.
*
* @param str                            Event message.
* @param str_size                       Event message size.
* @param navi_evnt_type                 Event type.
* @param navi_evnt_extra_subtype        Extra type of event.
* @param visibility                     Visibility of event.
* @return                               Result of adding navigation event to event buffer.
*
*********************************************************************/
int navi_add_event
    (
    uint8_t* str,
    uint8_t str_size,
    navilite_navievent_type navi_evnt_type,
    navilite_navievent_camera_extra_subtype navi_evnt_extra_subtype,
    uint8_t visibility
    )
{
int idx = 1;
int length = 0;
int result = ERR_NONE;
navi_event_stat navi_event;

switch( navi_evnt_type )
    {
    case NAVILITE_NAVIEVENT_TYPE_SCHOOL:
        memcpy( navi_event.dist, str, MAX_STR_SIZE );
        navi_event.dist[str_size] = '\0';
        navi_event.event_type = navi_evnt_type;
        navi_event.visibility = visibility;
        navi_event.desc_size = str_size;
        if( pdFALSE == xQueueSend( event_queue, &navi_event, 0 ) )
            {
            PRINTF( "%s: Navi event xQueueSend error\r\n", __FUNCTION__ );
            }
        break;
    case NAVILITE_NAVIEVENT_TYPE_CAMERA:
        {
        char* cur_str = ( char* )str;
        char* next_str = strtok( cur_str, ";" );
        while( NULL != next_str )
            {
            if( idx == 1 )
                {
                length = strlen( next_str );
                memcpy( navi_event.speed, next_str, MAX_STR_SIZE );
                navi_event.speed[length] = '\0';
                }
            else
                {
                length = str_size - length;
                memcpy( navi_event.dist, next_str, MAX_STR_SIZE );
                navi_event.dist[length] = '\0';
                }
            next_str = strtok( NULL, ";" );
            idx++;
            }
        navi_event.event_type = navi_evnt_type;
        navi_event.camera_type = navi_evnt_extra_subtype;
        navi_event.visibility = visibility;
        navi_event.desc_size = str_size;
        if( pdFALSE == xQueueSend( event_queue, &navi_event, 0 ) )
            {
            PRINTF( "%s: Navi event xQueueSend error\r\n", __FUNCTION__ );
            }
        break;
        }
    default:
        PRINTF( "%s: Unexpected event type\r\n", __FUNCTION__ );
        result = ERR_BUF_OPERATION;
        break;
    }
return result;
}

/*********************************************************************
*
* @public
* NAVI_reset_event_buffer
*
* Reset event buffer.
*
*********************************************************************/
void NAVI_reset_event_buffer
    (
    void
    )
{
if( pdFALSE == xQueueReset( event_queue ) )
    {
    PRINTF( "%s: Navi event xQueueReset error\r\n", __FUNCTION__ );
    }
}

/*********************************************************************
*
* @public
* NAVI_get_event
*
* Get navi event from navi event buffer.
*
* @param event_data   Pointer to event data.
* @return             Result of getting navigation event.
*
*********************************************************************/
bool NAVI_get_event
    (
    navi_event_stat* event_data
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
bool res = false;
navi_event_stat navi_event;
if( pdTRUE == xQueueReceive( event_queue, &navi_event, 0 ) )
    {
    res = true;
    *event_data = navi_event;
    }
else
    {
    PRINTF( "%s: Navi event xQueueReceive error\r\n", __FUNCTION__ );
    }
return res;
}

/*********************************************************************
*
* @private
* navi_send_event_to_queue
*
* @param str                            Event message.
* @param str_size                       Event message size.
* @param navi_evnt_type                 Event type.
* @param navi_evnt_extra_subtype        Extra type of event.
* @param visibility                     Visibility of event.
*
*********************************************************************/
void navi_send_event_to_queue
    (
    uint8_t* str,
    uint8_t str_size,
    navilite_navievent_type navi_evnt_type,
    navilite_navievent_camera_extra_subtype navi_evnt_extra_subtype,
    uint8_t visibility
    )
{
int result = ERR_NONE;

if( MAX_STR_SIZE * 2 > str_size )
    {
    result = navi_add_event( str, str_size, navi_evnt_type, navi_evnt_extra_subtype, visibility );
    if( ERR_NONE == result )
        {
        EW_notify_navi_event_update();
        }
    }
else
    {
    PRINTF( "%s: Unexpected length of navi event message: %d\r\n", __FUNCTION__, str_size );
    }
PRINTF( "%s: Result: %d\r\n", __FUNCTION__, result );
}

/*********************************************************************
*
* @private
* navi_event_init
*
* Initialize navi event buffer
*
*********************************************************************/
void navi_event_init
    (
    void
    )
{
event_queue = xQueueCreate( MAX_EVENT_QUEUE_SIZE, sizeof( navi_event_stat ) );
configASSERT( NULL != event_queue );
}

