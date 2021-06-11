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
    EnumNaviAlertType navi_evnt_type,
    EnumNaviCameraType navi_evnt_extra_subtype
    )
{
bool res = false;
PRINTF( "%s\r\n", __FUNCTION__ );

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
PRINTF( "%s\r\n", __FUNCTION__ );

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
PRINTF( "%s\r\n", __FUNCTION__ );

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
* navi_set_alert_type
*
* Set received alert type to navi event obj.
*
*********************************************************************/
static EnumNaviAlertType navi_set_alert_type
    (
    navilite_navievent_type navi_evnt_type
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
EnumNaviAlertType alert_type = EnumNaviAlertTypeTOTAL;
switch( navi_evnt_type )
    {
    case NAVILITE_NAVIEVENT_TYPE_TRAFFIC:
        alert_type = EnumNaviAlertTypeTRAFFIC;
        break;
    case NAVILITE_NAVIEVENT_TYPE_SPEED:
        alert_type = EnumNaviAlertTypeSPEED;
        break;
    case NAVILITE_NAVIEVENT_TYPE_CAMERA:
        alert_type = EnumNaviAlertTypeCAMERA;
        break;
    case NAVILITE_NAVIEVENT_TYPE_BORDER:
        alert_type = EnumNaviAlertTypeBORDER;
        break;
    case NAVILITE_NAVIEVENT_TYPE_SCHOOL:
        alert_type = EnumNaviAlertTypeSCHOOL;
        break;
    case NAVILITE_NAVIEVENT_TYPE_OTHER:
        alert_type = EnumNaviAlertTypeOTHER;
        break;
    default:
        break;
    }
return alert_type;
}

/*********************************************************************
*
* @private
* navi_set_camera_type
*
* Set received camera type to navi event obj.
*
*********************************************************************/
static EnumNaviCameraType navi_set_camera_type
    (
    navilite_navievent_extra_subtype navi_camera_type
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
EnumNaviCameraType camera_type = EnumNaviCameraTypeTYPE_UNDEFINED;
switch( navi_camera_type )
    {
    case NAVILITE_CAM_TYPE_CHECK_FIXED:
        camera_type = EnumNaviCameraTypeCHECK_FIXED;
        break;
    case NAVILITE_CAM_TYPE_CHECK_TEMPORARY:
        camera_type = EnumNaviCameraTypeCHECK_TEMPORARY;
        break;
    case NAVILITE_CAM_TYPE_MOBILE:
        camera_type = EnumNaviCameraTypeMOBILE;
        break;
    case NAVILITE_CAM_TYPE_AVERAGE:
        camera_type = EnumNaviCameraTypeAVERAGE;
        break;
    case NAVILITE_CAM_TYPE_VARIABLE:
        camera_type = EnumNaviCameraTypeVARIABLE;
        break;
    case NAVILITE_CAM_TYPE_RED_LIGHT:
        camera_type = EnumNaviCameraTypeRED_LIGHT;
        break;
    case NAVILITE_CAM_TYPE_USER:
        camera_type = EnumNaviCameraTypeUSER;
        break;
    case NAVILITE_CAM_TYPE_MOBILE_ZONE:
        camera_type = EnumNaviCameraTypeMOBILE_ZONE;
        break;
    case NAVILITE_CAM_TYPE_DANGEROUS_ZONE:
        camera_type = EnumNaviCameraTypeDANGEROUS_ZONE;
        break;
    case NAVILITE_CAM_TYPE_DANGEROUS_POINT:
        camera_type = EnumNaviCameraTypeDANGEROUS_POINT;
        break;
    case NAVILITE_CAM_TYPE_RISK_ZONE:
        camera_type = EnumNaviCameraTypeRISK_ZONE;
        break;
    case NAVILITE_CAM_TYPE_UNKNOWN:
        camera_type = EnumNaviCameraTypeUNKNOWN;
        break;
    case NAVILITE_BORDER_TYPE_STATE:
        camera_type = EnumNaviCameraTypeSTATE_BORDER;
        break;
    case NAVILITE_BORDER_TYPE_COUNTRY:
        camera_type = EnumNaviCameraTypeCOUNTRY_BORDER;
        break;
    case NAVILITE_EVENT_EXTRA_SUBTYPE_UNDEFINED:
        camera_type = EnumNaviCameraTypeTYPE_UNDEFINED;
        break;
    default:
        break;
    }
return camera_type;
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
PRINTF( "%s\r\n", __FUNCTION__ );
if( pdTRUE == xSemaphoreTake( event_buffer_semphr_hndl, ticks_to_wait ) )
    {
    int idx = 1;
    int length = 0;
    navi_event_type navi_event;

    EnumNaviAlertType navi_alert_type = navi_set_alert_type( navi_evnt_type );
    EnumNaviCameraType navi_camera_type = navi_set_camera_type( navi_evnt_extra_subtype );

    // If visibility is false and the camera type is undefined, it means that user have already passed the speed camera/school zone.
    if( !visibility &&
        EnumNaviCameraTypeTYPE_UNDEFINED == navi_camera_type )
        {
        PRINTF( "%s: Event is finished.\r\n", __FUNCTION__ );
        event_state = FINISH_EVENT;
        }
    else if( EnumNaviAlertTypeSPEED != navi_alert_type &&
             EnumNaviAlertTypeTRAFFIC != navi_alert_type &&
             navi_search_event( navi_alert_type, navi_camera_type ) )
        {
        event_state = UPDATE_EVENT;
        }
    else
        {
        event_state = SET_EVENT;
        }

    switch( navi_evnt_type )
        {
        case NAVILITE_NAVIEVENT_TYPE_TRAFFIC:
            // Traffic event doesn't have any distance or speed. Fill empty data to event object.
            memset( navi_event.speed, 0, MAX_STR_SIZE );
            memset( navi_event.dist, 0, MAX_STR_SIZE );
            memcpy( navi_event.desc, str, MAX_EVENT_DESCRIPTION_SIZE );
            if( str_size < MAX_EVENT_DESCRIPTION_SIZE )
                {
                navi_event.desc[str_size] = '\0';
                }
            else
                {
                navi_event.desc[MAX_EVENT_DESCRIPTION_SIZE-1] = '\0';
                }
            navi_event.event_type = navi_alert_type;
            navi_event.camera_type = navi_camera_type;
            navi_event.visibility = visibility;
            navi_event.desc_size = str_size;
            navi_handle_event( navi_event );
            break;
        case NAVILITE_NAVIEVENT_TYPE_BORDER:
            memcpy( navi_event.dist, str, MAX_STR_SIZE );
            if( str_size < MAX_STR_SIZE )
                {
                navi_event.dist[str_size] = '\0';
                }
            else
                {
                navi_event.dist[MAX_STR_SIZE-1] = '\0';
                }
            navi_event.event_type = navi_alert_type;
            navi_event.camera_type = navi_camera_type;
            navi_event.visibility = visibility;
            navi_event.desc_size = str_size;
            if( SET_EVENT == event_state )
                {
                navi_event.is_displayed = false;
                }
            navi_handle_event( navi_event );
            break;
        case NAVILITE_NAVIEVENT_TYPE_SPEED:
            // Speeding event doesn't have any distance or speed. Fill empty data to event object.
            memset( navi_event.speed, 0, MAX_STR_SIZE );
            memset( navi_event.dist, 0, MAX_STR_SIZE );
            navi_event.event_type = navi_alert_type;
            navi_event.camera_type = navi_camera_type;
            navi_event.visibility = visibility;
            navi_event.desc_size = str_size;
            navi_handle_event( navi_event );
            break;
        case NAVILITE_NAVIEVENT_TYPE_SCHOOL:
            memcpy( navi_event.dist, str, MAX_STR_SIZE );
            if( str_size < MAX_STR_SIZE )
                {
                navi_event.dist[str_size] = '\0';
                }
            else
                {
                navi_event.dist[MAX_STR_SIZE-1] = '\0';
                }
            navi_event.event_type = navi_alert_type;
            navi_event.camera_type = navi_camera_type;
            navi_event.visibility = visibility;
            navi_event.desc_size = str_size;
            if( SET_EVENT == event_state )
                {
                navi_event.is_displayed = false;
                }
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
            navi_event.event_type = navi_alert_type;
            navi_event.camera_type = navi_camera_type;
            navi_event.visibility = visibility;
            navi_event.desc_size = str_size;
            if( SET_EVENT == event_state )
                {
                navi_event.is_displayed = false;
                }
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
PRINTF( "%s\r\n", __FUNCTION__ );
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
            event_buffer[i].event_type = EnumNaviAlertTypeTOTAL;
            event_buffer[i].camera_type = EnumNaviCameraTypeTYPE_UNDEFINED;
            event_buffer[i].desc_size = 0;
            event_buffer[i].visibility = 0;
            event_buffer[i].is_displayed = false;
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
    PRINTF( "%s , event count : %d \r\n", __FUNCTION__, event_count );
    if( event_count >= 1 )
        {
        for( int i = 0; i < event_count; i++ )
            {
            if( EnumNaviAlertTypeSPEED != event_buffer[i].event_type )
                {
                *event_data = event_buffer[i];
                res = true;
                }
            }
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
PRINTF( "%s\r\n", __FUNCTION__ );
if( MAX_STR_SIZE * 2 > str_size )
    {
    result = navi_add_event( str, str_size, navi_evnt_type, navi_evnt_extra_subtype, visibility );
    if( ERR_NONE == result )
        {
            switch( event_state )
            {
            case SET_EVENT:
                PRINTF( "%s: New Alert Update\r\n", __FUNCTION__ );
                EW_notify_navi_alert_update();
                break;
            case UPDATE_EVENT:
                PRINTF( "%s: Alert Dist Update\r\n", __FUNCTION__ );
                EW_notify_alert_distance_update();
                break;
            case FINISH_EVENT:
                PRINTF( "%s: Remove Alert\r\n", __FUNCTION__ );
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
}

/*********************************************************************
*
* @public
* NAVI_get_alert_distance
*
* Get navi event from navi event buffer.
*
* @param dist         Pointer to event distance.
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
* @public
* NAVI_is_specified_event_received
*
* Check if specified event is in the navi event buffer.
*
* @return True if specified event is in the navi event buffer.
*         False if specified event is not in the navi event buffer.
*
*********************************************************************/
bool NAVI_is_specified_event_received
    (
    EnumNaviAlertType alert_type,
    EnumNaviCameraType camera_type
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
bool res = false;
if( pdTRUE == xSemaphoreTake( event_buffer_semphr_hndl, ticks_to_wait ) )
    {
    if( navi_search_event( alert_type, camera_type ) )
        {
        res = true;
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
* @public
* NAVI_remove_specified_event
*
* Remove the specified event.
*
* @param alert_type    Alert type.
* @param camera_type   Camera type.
*
*********************************************************************/
void NAVI_remove_specified_event
    (
    EnumNaviAlertType alert_type,
    EnumNaviCameraType camera_type
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
if( pdTRUE == xSemaphoreTake( event_buffer_semphr_hndl, ticks_to_wait ) )
    {
    for( int i = 0; i < event_count; i++ )
    {
    if( alert_type == event_buffer[i].event_type &&
        camera_type == event_buffer[i].camera_type )
        {
        if( i != ( event_count -1 ) )
            {
            event_buffer[i] = event_buffer[i+1];
            }
        event_count--;
        }
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
* NAVI_get_alert_display_status
*
* Get the display status of current alert.
*
* @return True if current event has been displayed.
*         False if current event is not displayed yet.
*
*********************************************************************/
bool NAVI_get_alert_display_status
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
bool res = false;
if( pdTRUE == xSemaphoreTake( event_buffer_semphr_hndl, ticks_to_wait ) )
    {
    res = event_buffer[event_idx].is_displayed;
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
* @public
* NAVI_enable_alert_display_flag
*
* Set true to current alert's flag in order to indicate current
* alert has already been displayed.
*
*********************************************************************/
void NAVI_enable_alert_display_flag
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
if( pdTRUE == xSemaphoreTake( event_buffer_semphr_hndl, ticks_to_wait ) )
    {
    event_buffer[event_idx].is_displayed = true;
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
* NAVI_get_reroute_alert_message
*
* Get reroute alert message
*
* @param alert_message         Pointer to reroute alert message.
*
*********************************************************************/
void NAVI_get_reroute_alert_message
    (
    char** alert_message
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
if( pdTRUE == xSemaphoreTake( event_buffer_semphr_hndl, ticks_to_wait ) )
    {
    for( int i = 0; i < event_count; i++ )
        {
        if( EnumNaviAlertTypeTRAFFIC == event_buffer[i].event_type &&
            EnumNaviCameraTypeTYPE_UNDEFINED == event_buffer[i].camera_type )
            {
            *alert_message = event_buffer[i].desc;
            }
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

