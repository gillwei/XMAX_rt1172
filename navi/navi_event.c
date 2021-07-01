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
typedef enum
    {
    SET_EVENT,
    UPDATE_EVENT,
    FINISH_EVENT,
    IDLE
    } navi_event_state;

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/
static SemaphoreHandle_t event_buffer_semphr_hndl;
static navi_event_type event_buffer[MAX_EVENT_QUEUE_SIZE];
static navi_event_state event_state = IDLE;
static int32_t event_count = 0;
static int32_t event_idx = 0;
static int32_t ticks_to_wait = pdMS_TO_TICKS( 500 );

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @private
* navi_search_event
*
* Search the corresponding event in the event buffer.
*
*********************************************************************/
static bool navi_search_event
    (
    navilite_navievent_type navi_evnt_type,
    navilite_navievent_extra_subtype navi_evnt_extra_subtype
    )
{
bool res = false;
PRINTF( "%s: Search Event\r\n", __FUNCTION__ );

for( int i = 0; i < event_count; i++ )
    {
    if( navi_evnt_type == event_buffer[i].event_type &&
        navi_evnt_extra_subtype == event_buffer[i].camera_type )
        {
        res = true;
        }
    }
return res;
}

/*********************************************************************
*
* @private
* navi_update_event_by_idx
*
* Update the specific event stored in the event buffer.
*
*********************************************************************/
static void navi_update_event_by_idx
    (
    navi_event_type navi_event
    )
{
PRINTF( "%s: Search by index\r\n", __FUNCTION__ );

for( int i = 0; i < event_count; i++ )
    {
    if( navi_event.event_type == event_buffer[i].event_type &&
        navi_event.camera_type == event_buffer[i].camera_type )
        {
        event_buffer[i] = navi_event;
        event_idx = i;
        PRINTF( "%s: %d\r\n", __FUNCTION__, event_idx );
        }
    }
}

/*********************************************************************
*
* @private
* navi_handle_event
*
* Handle event based on different states.
*
*********************************************************************/
static void navi_handle_event
    (
    navi_event_type navi_event
    )
{
PRINTF( "%s: Handle event\r\n", __FUNCTION__ );

switch( event_state )
    {
    case SET_EVENT:
        PRINTF( "%s, %d\r\n", __FUNCTION__, event_count );
        if( event_count >= 0 &&
            event_count < MAX_EVENT_QUEUE_SIZE )
            {
            event_buffer[event_count] = navi_event;
            event_count++;
            }
        else
            {
            PRINTF( "%s: Buffer is full\r\n", __FUNCTION__ );
            }
        break;
    case UPDATE_EVENT:
        navi_update_event_by_idx( navi_event );
        break;
    case FINISH_EVENT:
        navi_update_event_by_idx( navi_event );
        break;
    default:
        break;
    }
}

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
    navilite_navievent_extra_subtype navi_evnt_extra_subtype,
    uint8_t visibility
    )
{
int result = ERR_NONE;
PRINTF( "%s: Add Event\r\n", __FUNCTION__ );
if( pdTRUE == xSemaphoreTake( event_buffer_semphr_hndl, ticks_to_wait ) )
    {
    int idx = 1;
    int length = 0;
    navi_event_type navi_event;

    // If visibility is false and the content of str is ";", it means that user have already passed the speed camera/school zone.
    if( !visibility &&
        1 == strlen( (char*)str ) &&
        !strncmp( (char*)str, ";", 1 ) )
        {
        PRINTF( "%s: Event is finished.\r\n", __FUNCTION__ );
        event_state = FINISH_EVENT;
        }
    else if( navi_search_event( navi_evnt_type, navi_evnt_extra_subtype ) )
        {
        event_state = UPDATE_EVENT;
        }
    else
        {
        event_state = SET_EVENT;
        }

    switch( navi_evnt_type )
        {
        case NAVILITE_NAVIEVENT_TYPE_SCHOOL:
            memcpy( navi_event.dist, str, MAX_STR_SIZE );
            navi_event.dist[str_size] = '\0';
            navi_event.event_type = navi_evnt_type;
            navi_event.visibility = visibility;
            navi_event.desc_size = str_size;
            navi_handle_event( navi_event );
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
            navi_handle_event( navi_event );
            break;
            }
        default:
            PRINTF( "%s: Unexpected event type 0x%x\r\n", __FUNCTION__, navi_evnt_type );
            result = ERR_BUF_OPERATION;
            break;
        }
    xSemaphoreGive( event_buffer_semphr_hndl );
    }
else
    {
    PRINTF( "%s: Semaphore is hold by another task\r\n", __FUNCTION__ );
    }

return result;
}

/*********************************************************************
*
* @public
* NAVI_remove_event_from_buffer
*
* Remove current event from buffer
*
*********************************************************************/
void NAVI_remove_event_from_buffer
    (
    void
    )
{
PRINTF( "%s: remove event from buffer\r\n", __FUNCTION__ );
if( pdTRUE == xSemaphoreTake( event_buffer_semphr_hndl, ticks_to_wait ) )
    {
    if( event_count > 1 )
        {
        for( int i = 1; i < event_count; i++ )
            {
            event_buffer[i-1] = event_buffer[i];
            }
        event_count--;
        }
    else if( event_count == 1 )
        {
        PRINTF( "%s, Reset event buffer\r\n", __FUNCTION__ );
        for( int i = 0; i < MAX_EVENT_QUEUE_SIZE; i++ )
            {
            memset( event_buffer[i].speed, 0, MAX_STR_SIZE );
            memset( event_buffer[i].dist, 0, MAX_STR_SIZE );
            event_buffer[i].event_type = NAVILITE_NAVIEVENT_TYPE_OTHER;
            event_buffer[i].camera_type = NAVILITE_CAM_TYPE_UNKNOWN;
            event_buffer[i].desc_size = 0;
            event_buffer[i].visibility = 0;
            }
        event_count = 0;
        event_state = IDLE;
        }
    else
        {
        PRINTF( "%s, no event\r\n", __FUNCTION__ );
        }
    xSemaphoreGive( event_buffer_semphr_hndl );
    }
else
    {
    PRINTF( "%s: Semaphore is hold by another task\r\n", __FUNCTION__ );
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
    navi_event_type* event_data
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
bool res = false;
if( pdTRUE == xSemaphoreTake( event_buffer_semphr_hndl, ticks_to_wait ) )
    {
    if( event_count >= 1 )
        {
        res = true;
        *event_data = event_buffer[0];
        }
    else
        {
        res = false;
        }
    xSemaphoreGive( event_buffer_semphr_hndl );
    }
else
    {
    PRINTF( "%s: Semaphore is hold by another task\r\n", __FUNCTION__ );
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
    navilite_navievent_extra_subtype navi_evnt_extra_subtype,
    uint8_t visibility
    )
{
int result = ERR_NONE;
PRINTF( "%s: Event update\r\n", __FUNCTION__ );
if( MAX_STR_SIZE * 2 > str_size )
    {
    result = navi_add_event( str, str_size, navi_evnt_type, navi_evnt_extra_subtype, visibility );
    if( ERR_NONE == result )
        {
            switch( event_state )
            {
            case SET_EVENT:
                EW_notify_navi_event_update();
                break;
            case UPDATE_EVENT:
                EW_notify_alert_distance_update();
                break;
            case FINISH_EVENT:
                NAVI_remove_event_from_buffer();
                break;
            default:
                break;
            }
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
* @public
* NAVI_get_alert_distance
*
* Get navi event from navi event buffer.
*
* @param event_data   Pointer to event data.
* @return             Result of getting navigation event.
*
*********************************************************************/
void NAVI_get_alert_distance
    (
    char** dist
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
if( pdTRUE == xSemaphoreTake( event_buffer_semphr_hndl, ticks_to_wait ) )
    {
    *dist = event_buffer[event_idx].dist;
    xSemaphoreGive( event_buffer_semphr_hndl );
    }
else
    {
    PRINTF( "%s: Semaphore is hold by another task\r\n", __FUNCTION__ );
    }
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
event_buffer_semphr_hndl = xSemaphoreCreateBinary();
configASSERT( NULL != event_buffer_semphr_hndl );
xSemaphoreGive( event_buffer_semphr_hndl );
}

