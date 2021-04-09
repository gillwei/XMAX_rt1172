/*********************************************************************
* @file
* ntf_main.c
*
* @brief
* The main program of the notification.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "task.h"
#include "semphr.h"
#include "fsl_debug_console.h"
#include "error_code.h"
#include "ntf_priv.h"
#include "EW_pub.h"
#include "BC_motocon_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define MAX_ACTIVE_CALL_NUM         ( 2 )
#define INVALID_INDEX               ( -1 )
#define PHONE_CALL_STATE_DELAY_MS   ( 1000 )

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
typedef struct
    {
    uint32_t uid;
    uint32_t duration_ms;
    uint8_t  caller[PHONE_CALLER_MAX_LEN];
    } active_call_status_t;

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/
static notification_protocol_t notification_protocol = NOTIFICATION_PROTOCOL_NONE;
static notification_callback_t *notification_callback;
static EnumPhoneCallState phonecall_state = EnumPhoneCallStateIDLE;
static uint32_t incoming_call_uid;
static uint8_t  incoming_call_caller[PHONE_CALLER_MAX_LEN];
static bool     is_phone_call_volume_controllable;
static int32_t  active_call_num = 0;
static uint8_t  null_caller = '\0';
static active_call_status_t active_call_table[MAX_ACTIVE_CALL_NUM];
static TimerHandle_t phone_call_state_timer_handle = NULL;

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
/*********************************************************************
*
* @private
* lookup_active_call_uid
*
* Look for the index of active call table with uid
*
* @param uid Unique notification id
* @return Index of the active call
*
*********************************************************************/
static int32_t lookup_active_call_uid
    (
    const uint32_t uid
    )
{
int32_t idx = INVALID_INDEX;
for( int32_t i = 0; i < active_call_num; i++ )
    {
    if( active_call_table[i].uid == uid )
        {
        idx = i;
        break;
        }
    }
return idx;
}

/*********************************************************************
*
* @private
* add_active_call
*
* Add the active call of uid into the active call table
*
* @param uid Unique notification id
* @param caller Pointer to the caller string
*
*********************************************************************/
static void add_active_call
    (
    const uint32_t uid,
    const uint8_t* caller
    )
{
int32_t found_idx = lookup_active_call_uid( uid );

if( INVALID_INDEX == found_idx &&
    MAX_ACTIVE_CALL_NUM > active_call_num )
    {
    active_call_table[active_call_num].uid = uid;
    active_call_table[active_call_num].duration_ms = 0;
    memcpy( active_call_table[active_call_num].caller, caller, PHONE_CALLER_MAX_LEN );
    active_call_num++;
    }
}

/*********************************************************************
*
* @private
* remove_active_call
*
* Remove the active call of uid
*
* @param uid Unique notification id
*
*********************************************************************/
static void remove_active_call
    (
    const uint32_t uid
    )
{
int found_idx = lookup_active_call_uid( uid );
if( INVALID_INDEX < found_idx )
    {
    for( int32_t i = found_idx; i < active_call_num - 1; i++ )
        {
        active_call_table[i] = active_call_table[i+1];
        }
    active_call_num--;
    }
}

/*********************************************************************
*
* @private
* PhoneCallStateTimerCallback
*
* Callback function of the phone call state timer
*
* @param xTimerHandle Phone call state timer handle
*
*********************************************************************/
static void PhoneCallStateTimerCallback
    (
    TimerHandle_t xTimerHandle
    )
{
NTF_PRINTF( "%s\r\n" );
xTimerStop( phone_call_state_timer_handle , 0 );

if( EnumPhoneCallStateINCOMING_STOPPED == phonecall_state )
    {
    if( 0 < active_call_num )
        {
        phonecall_state = EnumPhoneCallStateACTIVE;
        }
    else
        {
        phonecall_state = EnumPhoneCallStateIDLE;
        }
    EW_notify_phone_call_state_changed();
    }
}

/*********************************************************************
*
* @public
* NTF_answer_call
*
* Answer phone call
*
*********************************************************************/
void NTF_answer_call
    (
    void
    )
{
NTF_PRINTF( "%s, %d\r\n", __FUNCTION__, phonecall_state );
if( EnumPhoneCallStateINCOMING_STARTED == phonecall_state &&
    NULL != notification_callback &&
    NULL != notification_callback->notification_answer_call_callback )
    {
    notification_callback->notification_answer_call_callback( incoming_call_uid );
    }
}

/*********************************************************************
*
* @public
* NTF_decline_call
*
* Decline phone call
*
*********************************************************************/
void NTF_decline_call
    (
    void
    )
{
NTF_PRINTF( "%s, %d\r\n", __FUNCTION__, phonecall_state );
if( EnumPhoneCallStateINCOMING_STARTED == phonecall_state &&
    NULL != notification_callback &&
    NULL != notification_callback->notification_decline_call_callback )
    {
    notification_callback->notification_decline_call_callback( incoming_call_uid );
    }
}

/*********************************************************************
*
* @public
* NTF_add_notification
*
* Add notification
*
* @param uid Unique notification id
* @param title Pointer to the title buffer
* @param subtitle Pointer to the subtitle buffer
* @param message Pointer to the message buffer
* @param category Notification category
* @param received_time Notification received time
*
* @return Result of adding to notification buffer
*
*********************************************************************/
int NTF_add_notification
    (
    const uint32_t uid,
    const uint8_t* title,
    const uint8_t* subtitle,
    const uint8_t* message,
    const EnumNotificationCategory category,
    const notification_time_t      received_time
    )
{
int result = ERR_NONE;
NTF_PRINTF( "%s %d %s %d\r\n", __FUNCTION__, uid, title, category );

if( BC_motocon_is_connected() )
    {
    result = ntf_buffer_add_notification( uid, title, subtitle, message, category, received_time );
    if( ERR_NONE == result )
        {
        EW_notify_notification_list_updated();
        }
    }
return result;
}

/*********************************************************************
*
* @public
* NTF_get_notification_at_idx
*
* Get notification at the specified index of the notification list
*
* @param idx Index of notification list
* @param uid Unique notification id
* @param title Pointer to the title buffer
* @param title_length Size of the title buffer
* @param message Pointer to the message buffer
* @param message_length Size of the message buffer
* @param category Pointer to the category
* @param received_time Pointer to the received time
*
* @return Result of getting notification at the specified index
*
*********************************************************************/
int NTF_get_notification_at_idx
    (
    const uint32_t idx,
    uint32_t*      uid,
    uint16_t*      call_repitition,
    uint8_t*       title,
    const uint32_t title_length,
    uint8_t*       message,
    const uint32_t message_length,
    EnumNotificationCategory* category,
    notification_time_t*      received_time
    )
{
return ntf_buffer_get_notification_at_idx( idx, uid, call_repitition, title, title_length, message, message_length, category, received_time );
}

/*********************************************************************
*
* @public
* NTF_delete_notification
*
* Delete the notification of specified UID
*
* @param uid Unique notification id
*
*********************************************************************/
void NTF_delete_notification
    (
    const uint32_t uid
    )
{
NTF_PRINTF( "%s %d\r\n", __FUNCTION__, uid );
ntf_buffer_delete_notification_of_uid( uid );
EW_notify_notification_list_updated();
}

/*********************************************************************
*
* @public
* NTF_notify_notification_deleted
*
* Notify UI the notification of UID is deleted from the smartphone
*
* @param uid Unique notification id
*
*********************************************************************/
void NTF_notify_notification_deleted
    (
    const uint32_t uid
    )
{
NTF_PRINTF( "%s uid: %d\r\n", __FUNCTION__, uid );
int found_idx = lookup_active_call_uid( uid );
if( INVALID_INDEX < found_idx )
    {
    NTF_notify_active_call_stopped( uid );
    }
}

/*********************************************************************
*
* @public
* NTF_notify_incoming_call_started
*
* Notify incoming call started
*
* @param uid Unique notification id of this incoming call
* @param caller The caller's name or phone number
* @param is_volume_controllable Volume controllable status
*
*********************************************************************/
void NTF_notify_incoming_call_started
    (
    const uint32_t uid,
    const uint8_t* caller,
    const bool     is_volume_controllable
    )
{
NTF_PRINTF( "%s %d %s %d\r\n", __FUNCTION__, uid, caller, is_volume_controllable );

if( BC_motocon_is_connected() )
    {
    int caller_len = strlen( (char*)caller);
    is_phone_call_volume_controllable = is_volume_controllable;
    phonecall_state = EnumPhoneCallStateINCOMING_STARTED;
    incoming_call_uid = uid;
    int string_length = MIN( PHONE_CALLER_MAX_LEN - 1, caller_len );
    memcpy( incoming_call_caller, caller, string_length );
    incoming_call_caller[string_length] = '\0';

    EW_notify_phone_call_state_changed();
    }
}

/*********************************************************************
*
* @public
* NTF_notify_incoming_call_stopped
*
* Notify incoming call stopped
*
* @param uid Unique notification id
*
*********************************************************************/
void NTF_notify_incoming_call_stopped
    (
    const uint32_t uid
    )
{
NTF_PRINTF( "%s %d\r\n", __FUNCTION__, uid );
if( BC_motocon_is_connected() )
    {
    phonecall_state = EnumPhoneCallStateINCOMING_STOPPED;
    xTimerStart( phone_call_state_timer_handle , 0 );
    }
}

/*********************************************************************
*
* @public
* NTF_notify_active_call_started
*
* Notify notification center that active call is started
*
* @param uid Unique notification id of this active call
* @param caller Caller's name or phone number
* @param is_volume_controllable Volume controllable status
*
*********************************************************************/
void NTF_notify_active_call_started
    (
    const uint32_t uid,
    const uint8_t* caller,
    const bool     is_volume_controllable
    )
{
NTF_PRINTF( "%s %d %d\r\n", __FUNCTION__, uid, is_volume_controllable );
if( BC_motocon_is_connected() )
    {
    is_phone_call_volume_controllable = is_volume_controllable;
    if( NULL == caller )
        {
        add_active_call( uid, incoming_call_caller );
        }
    else
        {
        add_active_call( uid, caller );
        }

    phonecall_state = EnumPhoneCallStateACTIVE;
    EW_notify_phone_call_state_changed();
    }
}

/*********************************************************************
*
* @public
* NTF_notify_active_call_stopped
*
* Notify notification center that active call is stopped
*
* @param uid Unique notification id of this active call
*
*********************************************************************/
void NTF_notify_active_call_stopped
    (
    const uint32_t uid
    )
{
NTF_PRINTF( "%s %d\r\n", __FUNCTION__, uid );
EnumPhoneCallState new_phonecall_state = EnumPhoneCallStateIDLE;
if( BC_motocon_is_connected() )
    {
    remove_active_call( uid );
    if( active_call_num > 0 )
        {
        new_phonecall_state = EnumPhoneCallStateACTIVE;
        }

    if( phonecall_state != new_phonecall_state )
        {
        phonecall_state = new_phonecall_state;
        EW_notify_phone_call_state_changed();
        }
    }
}

/*********************************************************************
*
* @public
* NTF_get_phonecall_state
*
* Get phone call state
*
* @return Phone call state
*
*********************************************************************/
EnumPhoneCallState NTF_get_phonecall_state
    (
    void
    )
{
return phonecall_state;
}

/*********************************************************************
*
* @public
* NTF_get_incoming_call_caller
*
* Get caller name or number of the incoming call
*
* @param Pointer to pointer of the caller string
*
*********************************************************************/
void NTF_get_incoming_call_caller
    (
    uint8_t** caller
    )
{
*caller = incoming_call_caller;
}

/*********************************************************************
*
* @public
* NTF_get_active_call_caller
*
* Get caller name or number of the active call
*
* @param Pointer to pointer of the caller string
*
*********************************************************************/
void NTF_get_active_call_caller
    (
    uint8_t** caller
    )
{
NTF_PRINTF( "%s %d\r\n", __FUNCTION__, active_call_num );
if( 0 < active_call_num )
    {
    *caller = active_call_table[active_call_num-1].caller;
    }
else
    {
    *caller = &null_caller;
    }
}

/*********************************************************************
*
* @public
* NTF_is_phonecall_volume_controllable
*
* Get if phone call volume is controllable
*
* @return Phone call volume controllable
*
*********************************************************************/
bool NTF_is_phonecall_volume_controllable
    (
    void
    )
{
return is_phone_call_volume_controllable;
}

/*********************************************************************
*
* @public
* NTF_phonecall_volume_control
*
* Control phone call volume
*
* @param control Volume up/down control
*
*********************************************************************/
void NTF_phonecall_volume_control
    (
    const EnumVolumeControl control
    )
{
NTF_PRINTF( "%s %d\r\n", __FUNCTION__, control );
if( EnumPhoneCallStateACTIVE == phonecall_state &&
    NULL != notification_callback &&
    NULL != notification_callback->notification_volume_control_callback )
    {
    notification_callback->notification_volume_control_callback( control );
    }
else
    {
    PRINTF( "%s ignore\r\n", __FUNCTION__ );
    }
}

/*********************************************************************
*
* @public
* NTF_get_active_call_duration
*
* Get active call duration (MS)
*
* @return Active all duration (MS)
*
*********************************************************************/
uint32_t NTF_get_active_call_duration
    (
    void
    )
{
uint32_t duration_ms = 0;
if( EnumPhoneCallStateACTIVE == phonecall_state &&
    0 < active_call_num )
    {
    duration_ms = active_call_table[active_call_num - 1].duration_ms;
    }
return duration_ms;
}

/*********************************************************************
*
* @public
* NTF_update_active_call_duration
*
* Counting active call duration
*
*********************************************************************/
void NTF_update_active_call_duration
    (
    void
    )
{
if( EnumPhoneCallStateACTIVE == phonecall_state )
    {
    for( int i = 0; i < active_call_num; i++ )
        {
        active_call_table[i].duration_ms += UPDATE_TIME_PERIOD_MS;
        }
    }
}

/*********************************************************************
*
* @public
* NTF_notify_connected
*
* Notify ANCS/MotoCon is connected
*
* @param protocol ANCS or MotoCon
* @param callback Pointer to callback functions for delete notification/answer call/decline call
*
*********************************************************************/
void NTF_notify_connected
    (
    const notification_protocol_t protocol,
    notification_callback_t*      callback
    )
{
NTF_PRINTF( "%s %d\r\n", __FUNCTION__, protocol );
notification_protocol = protocol;
notification_callback = callback;
phonecall_state       = EnumPhoneCallStateIDLE;
active_call_num       = 0;
}

/*********************************************************************
*
* @public
* NTF_notify_disconnected
*
* Notify notification ANCS/MotoCon is disconnected
*
* @param protocol ANCS or MotoCon
*
*********************************************************************/
void NTF_notify_disconnected
    (
    const notification_protocol_t protocol
    )
{
NTF_PRINTF( "%s %d\r\n", __FUNCTION__, protocol );
// Handle ANCS disconnecetd for iPhone or MotoCon disconnected for iPhone/Android phone
if( notification_protocol == protocol ||
    NOTIFICATION_PROTOCOL_MOTOCON == protocol )
    {
    notification_protocol = NOTIFICATION_PROTOCOL_NONE;
    notification_callback = NULL;

    active_call_num = 0;
    phonecall_state = EnumPhoneCallStateIDLE;
    EW_notify_phone_call_state_changed();

    ntf_buffer_reset();
    EW_notify_notification_list_updated();
    }
}

/*********************************************************************
*
* @public
* NTF_init
*
* Init notification
*
*********************************************************************/
void NTF_init
    (
    void
    )
{
ntf_buffer_init();
phone_call_state_timer_handle = xTimerCreate( "PhoneCallStateTimer", PHONE_CALL_STATE_DELAY_MS, pdTRUE, ( void * ) 0, PhoneCallStateTimerCallback );
configASSERT( NULL != phone_call_state_timer_handle );
}
