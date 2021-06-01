/*********************************************************************
* @file
* bc_motocon_listener.c
*
* @brief
* MotoConSDK module - listener
*
* Copyright 2020-2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <bc_motocon_priv.h>
#include <BC_motocon_pub.h>
#include <BC_motocon_pub_type.h>
#include "Enum.h"
#include "EW_pub.h"
#include "NTF_pub.h"
#include "VI_pub.h"
#include "OTA_pub.h"
#include "PM_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define MOTOCON_LINKCARD_MODEL      ( 1 )

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
void bc_motocon_listener_connection_status( const bool connected );
void bc_motocon_datetime_received( const bc_motocon_time_t* time );
void bc_motocon_datetime_changed( void );
void bc_motocon_listener_language_type( const uint8_t language_type );
void bc_motocon_notification_received( const bc_motocon_notification_v2_t* notification );
void bc_motocon_listener_battery( const uint8_t battery, const bc_motocon_battery_t battery_type );
void bc_motocon_incoming_call_received( const bc_motocon_incoming_call_info_t* incoming_call_information );
void bc_motocon_listener_phone_thermal( const bc_motocon_thermal_state_t thermal_state );
void bc_motocon_listener_bt_headset_state( const bc_motocon_bt_headset_state_t headset_state );
void bc_motocon_volume_changed( const uint8_t level, const bc_motocon_volume_type_t type );
void bc_motocon_notification_category_changed( const bc_motocon_notification_category_t* notification_category );
void bc_motocon_ota_update_info( const bc_motocon_ota_update_info_t* info );
void bc_motocon_phone_volume_controllable( const bool enable );
void bc_motocon_listener_phone_signal_level( const uint8_t level );
void bc_motocon_phonecall_state_changed( const bc_motocon_call_state_t call_state );
void bc_motocon_ignition_state_request_received( void );

void BC_motocon_answer_call_callback( const uint32_t uid );
void BC_motocon_decline_call_callback( const uint32_t uid );
void BC_motocon_phonecall_volume_control_callback( const EnumVolumeControl control );

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/
static bc_motocon_callback_t motocon_callback =
    {
    .connected_status_changed_callback = bc_motocon_listener_connection_status,
    .datetime_changed_callback         = bc_motocon_datetime_changed,
    .vehicle_datetime_callback         = bc_motocon_datetime_received,
    .language_type_callback            = bc_motocon_listener_language_type,
    .notification_callback             = bc_motocon_notification_received,
    .battery_callback                  = bc_motocon_listener_battery,
    .incoming_call_info_callback       = bc_motocon_incoming_call_received,
    .thermal_callback                  = bc_motocon_listener_phone_thermal,
    .bt_headset_state_callback         = bc_motocon_listener_bt_headset_state,
    .volume_level_callback             = bc_motocon_volume_changed,
    .notification_category_callback    = bc_motocon_notification_category_changed,
    .volume_controllable_callback      = bc_motocon_phone_volume_controllable,
    .ota_update_info_callback          = bc_motocon_ota_update_info,
    .cell_signal_callback              = bc_motocon_listener_phone_signal_level,
    .call_changed_callback             = bc_motocon_phonecall_state_changed,
    .ignition_state_request_callback   = bc_motocon_ignition_state_request_received
    };

static notification_callback_t motocon_notification_callback =
    {
    BC_motocon_answer_call_callback,
    BC_motocon_decline_call_callback,
    BC_motocon_phonecall_volume_control_callback
    };
static bool is_ntf_connected;
static bool is_request_from_clock = false;

static uint8_t phone_language_type;
static uint8_t phone_battery_percentage;
static uint8_t phone_cell_signal_level;
static bool phone_volume_controllable;
static bc_motocon_battery_t phone_battery_charging_status;
static bc_motocon_thermal_state_t phone_thermal_state;
static bc_motocon_bt_headset_state_t phone_headset_state;
static uint32_t phone_call_volume;
static bool motocon_connected;
static bc_motocon_ota_update_info_t ota_update_info;

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @private
* send_linkcard_info
*
* Send LinkCard info for checking if there is a new software update
*
*********************************************************************/
static void send_linkcard_info
    (
    void
    )
{
bc_motocon_ota_linkcard_info_t info;
uint32_t esn = EW_get_esn();

info.current_firmware_ver = SW_VERSION;
info.linkcard_model = MOTOCON_LINKCARD_MODEL;
info.serial_number[0] = ( esn >> 24 ) & 0xFF;
info.serial_number[1] = ( esn >> 16 ) & 0xFF;
info.serial_number[2] = ( esn >> 8  ) & 0xFF;
info.serial_number[3] = esn & 0xFF;
if( OTA_SYS_PARTITION_A == OTA_get_sys_parition() )
    {
    info.new_program_position = OTA_SYS_PARTITION_B;
    }
else
    {
    info.new_program_position = OTA_SYS_PARTITION_A;
    }

BC_motocon_send_ota_linkcard_info( &info );
}

/*********************************************************************
*
* @private
* notify_motocon_notification_disconnected
*
* Notify MotoCon notification is connected
*
*********************************************************************/
static void notify_motocon_notification_connected
    (
    void
    )
{
if( !is_ntf_connected )
    {
    is_ntf_connected = true;
    NTF_notify_connected( NOTIFICATION_PROTOCOL_MOTOCON, &motocon_notification_callback );
    }
}

/*********************************************************************
*
* @private
* notify_motocon_notification_disconnected
*
* Notify MotoCon notification is disconnected
*
*********************************************************************/
static void notify_motocon_notification_disconnected
    (
    void
    )
{
if( is_ntf_connected )
    {
    is_ntf_connected = false;
    phone_call_volume = 0;
    NTF_notify_disconnected( NOTIFICATION_PROTOCOL_MOTOCON );
    }
}

/*********************************************************************
*
* @private
* bc_motocon_listener_connection_status
*
* Notify EW the MotoCon connection status
*
* @param connected True: MotoCon connected. False: MotoCon disconnected.
*
*********************************************************************/
void bc_motocon_listener_connection_status
    (
    const bool connected
    )
{
motocon_connected = connected;
EW_notify_motocon_event_received( EnumMotoConRxEventCONNECTION_STATUS );
if( connected )
    {
    BC_motocon_send_language_type_request();
    BC_motocon_send_vehicle_setting_request();
    send_linkcard_info();

    /* update RTC time and meter clock if Auto Adjustment is enabled */
    if( EW_get_clk_auto_adj() )
        {
        is_request_from_clock = true;
        }
    }
else
    {
    phone_volume_controllable = false;
    notify_motocon_notification_disconnected();

    memset( &ota_update_info, 0, sizeof( bc_motocon_ota_update_info_t ) );
    EW_notify_system_event_received( EnumSystemRxEventSW_UPDATE_DISABLE );
    }
}

/*********************************************************************
*
* @private
* bc_motocon_datetime_changed
*
* Callback function when receiving the datetime change notification
* via MotoCon
*
*********************************************************************/
void bc_motocon_datetime_changed
    (
    void
    )
{
BC_MOTOCON_PRINTF( "%s\r\n", __FUNCTION__ );
/* update RTC time and meter clock if Auto Adjustment is enabled */
if( EW_get_clk_auto_adj() )
    {
    is_request_from_clock = true;
    BC_motocon_send_vehicle_setting_request();
    }
}

/*********************************************************************
*
* @private
* bc_motocon_datetime_received
*
* Callback function when receiving the datetime via MotoCon
*
* @param time Pointer to the smartphone time of bc_motocon_time_t type
*
*********************************************************************/
void bc_motocon_datetime_received
    (
    const bc_motocon_time_t* time
    )
{
BC_MOTOCON_PRINTF( "%s %d %d/%d %d:%d:%d\r\n", __FUNCTION__, time->year, time->mon, time->day, time->hour, time->min, time->sec );

bc_ancs_set_phone_connected_time( time );

if( EW_get_clk_auto_adj() )
    {
    snvs_lp_srtc_datetime_t srtc_datetime;

    srtc_datetime.year = time->year;
    srtc_datetime.month = time->mon;
    srtc_datetime.day = time->day;
    srtc_datetime.hour = time->hour;
    srtc_datetime.minute = time->min;
    srtc_datetime.second = time->sec;
    RTC_set_dateTime( &srtc_datetime );

    // The variable is_request_from_clock is only set to True when the datetime request is from clock.
    if( is_request_from_clock )
        {
        is_request_from_clock = false;
        VI_clock_notify_meter_time_updated( srtc_datetime );
        }
    }
}

/*********************************************************************
*
* @private
* bc_motocon_listener_language_type
*
* Notify EW language type from the smartphone
*
* @param language_type Language type
*
*********************************************************************/
void bc_motocon_listener_language_type
    (
    const uint8_t language_type
    )
{
phone_language_type = language_type;
EW_notify_motocon_event_received( EnumMotoConRxEventPHONE_LANGUAGE );
}

/*********************************************************************
*
* @private
* bc_motocon_notification_received
*
* Notify notification received
*
* @param notification MotoCon notification v2
*
*********************************************************************/
void bc_motocon_notification_received
    (
    const bc_motocon_notification_v2_t* notification
    )
{
notification_time_t received_time;
received_time.year   = notification->time.year;
received_time.month  = notification->time.mon;
received_time.day    = notification->time.day;
received_time.hour   = notification->time.hour;
received_time.minute = notification->time.min;
received_time.second = notification->time.sec;

EnumNotificationCategory category = EnumNotificationCategoryMESSAGE;
if( BC_MOTOCON_NOTIFICATION_CATEGORY_MISSED_CALL == notification->category )
    {
    category = EnumNotificationCategoryMISSED_CALL;
    }

if( motocon_connected )
    {
    notify_motocon_notification_connected();
    NTF_add_notification( notification->uid, (const uint8_t*)notification->title, (const uint8_t*)notification->subtitle, (const uint8_t*)notification->detail, category, received_time );
    }
}

/*********************************************************************
*
* @private
* bc_motocon_incoming_call_received
*
* Notify incoming call received
*
* @param incoming_call_information Pointer to incoming call info
*
*********************************************************************/
void bc_motocon_incoming_call_received
    (
    const bc_motocon_incoming_call_info_t* incoming_call_information
    )
{
uint8_t caller[PHONE_CALLER_MAX_LEN];
if( 0 < incoming_call_information->name_len )
    {
    memcpy( caller, incoming_call_information->name, MIN( PHONE_CALLER_MAX_LEN, incoming_call_information->name_len ) );
    caller[PHONE_CALLER_MAX_LEN - 1] = '\0';
    }
else if( 0 < incoming_call_information->phone_number_len )
    {
    memcpy( caller, incoming_call_information->phone_number, MIN( PHONE_CALLER_MAX_LEN, incoming_call_information->phone_number_len ) );
    caller[PHONE_CALLER_MAX_LEN - 1] = '\0';
    }
else
    {
    caller[0] = '\0';
    }

if( motocon_connected )
    {
    notify_motocon_notification_connected();
    NTF_notify_incoming_call_started( 0, caller, phone_volume_controllable );
    }
}

/*********************************************************************
*
* @private
* bc_motocon_phonecall_state_changed
*
* Notify phone call state changed
*
* @param call_state Phone call state of bc_motocon_call_state_t type
*
*********************************************************************/
void bc_motocon_phonecall_state_changed
    (
    const bc_motocon_call_state_t call_state
    )
{
if( motocon_connected )
    {
    switch( call_state )
        {
        case BC_MOTOCON_CALL_STARTED:
            NTF_notify_active_call_started( 0, NULL, phone_volume_controllable );
            break;
        case BC_MOTOCON_CALL_ENDED:
            NTF_notify_active_call_stopped( 0 );
            break;
        default:
            break;
        }
    }
}

/*********************************************************************
*
* @private
* bc_motocon_ignition_state_request_received
*
* Notify ignition state request received
*
*********************************************************************/
void bc_motocon_ignition_state_request_received
    (
    void
    )
{
if( PM_IGN_ON == PM_get_ign_status() )
    {
    BC_motocon_send_ignition_state_response( BC_MOTOCON_IGNITION_STATE_ON );
    }
else
    {
    BC_motocon_send_ignition_state_response( BC_MOTOCON_IGNITION_STATE_OFF );
    }
}

/*********************************************************************
*
* @private
* bc_motocon_phone_volume_controllable
*
* Notify phone volume controllable status
*
* @param enable Phone volume controllable status
*
*********************************************************************/
void bc_motocon_volume_changed
    (
    const uint8_t level,
    const bc_motocon_volume_type_t type
    )
{
if( BC_MOTOCON_VOLUME_PHONE == type )
    {
    phone_call_volume = level;
    EW_notify_phone_call_volume_changed();
    }
}

/*********************************************************************
*
* @private
* bc_motocon_phone_volume_controllable
*
* Notify phone volume controllable status
*
* @param enable Phone volume controllable status
*
*********************************************************************/
void bc_motocon_notification_category_changed
    (
    const bc_motocon_notification_category_t* notification_category
    )
{
bc_ancs_set_category_filter( notification_category );
}

/*********************************************************************
*
* @private
* bc_motocon_ota_update_info
*
* OTA update information callback
*
* @param info Pointer to OTA update information
*
*********************************************************************/
void bc_motocon_ota_update_info
    (
    const bc_motocon_ota_update_info_t* info
    )
{
BC_MOTOCON_PRINTF( "%s\r\n", __FUNCTION__ );

memcpy( &ota_update_info, info, sizeof( bc_motocon_ota_update_info_t ) );

if( info->enable )
    {
    EW_notify_system_event_received( EnumSystemRxEventSW_UPDATE_ENABLE );
    }
else
    {
    EW_notify_system_event_received( EnumSystemRxEventSW_UPDATE_DISABLE );
    }
}

/*********************************************************************
*
* @private
* bc_motocon_phone_volume_controllable
*
* Notify phone volume controllable status
*
* @param enable Phone volume controllable status
*
*********************************************************************/
void bc_motocon_phone_volume_controllable
    (
    const bool enable
    )
{
BC_MOTOCON_PRINTF( "%s %d\r\n", __FUNCTION__, enable );
phone_volume_controllable = enable;
}

/*********************************************************************
*
* @private
* bc_motocon_listener_battery
*
* Notify EW smartphone battery status
*
* @param battery Battery percentage
* @param battery_type Battery charging status
*
*********************************************************************/
void bc_motocon_listener_battery
    (
    const uint8_t battery,
    const bc_motocon_battery_t battery_type
    )
{
phone_battery_percentage = battery;
phone_battery_charging_status = battery_type;
EW_notify_motocon_event_received( EnumMotoConRxEventPHONE_BATTERY );
}

/*********************************************************************
*
* @private
* bc_motocon_listener_phone_thermal
*
* Notify EW phone thermal state
*
* @param thermal_state Phone thermal state
*
*********************************************************************/
void bc_motocon_listener_phone_thermal
    (
    const bc_motocon_thermal_state_t thermal_state
    )
{
phone_thermal_state = thermal_state;
EW_notify_motocon_event_received( EnumMotoConRxEventPHONE_THERMAL );
}

/*********************************************************************
*
* @private
* bc_motocon_listener_phone_signal_level
*
* Notify EW phone cell signal level
*
* @param level Phone cell signal level (0-4)
*
*********************************************************************/
void bc_motocon_listener_phone_signal_level
    (
    const uint8_t level
    )
{
phone_cell_signal_level = level;
EW_notify_motocon_event_received( EnumMotoConRxEventPHONE_CELL_SIGNAL_LEVEL );
}

/*********************************************************************
*
* @private
* bc_motocon_listener_bt_headset_state
*
* Notify EW the smartphone headset connection status
*
* @param headset_state Smartphone headset connection status
*
*********************************************************************/
void bc_motocon_listener_bt_headset_state
    (
    const bc_motocon_bt_headset_state_t headset_state
    )
{
phone_headset_state = headset_state;
EW_notify_motocon_event_received( EnumMotoConRxEventPHONE_HEADSET );
}

/*********************************************************************
*
* @public
* BC_motocon_get_language_type
*
* Get the language type of the smartphone
*
* @return Language type of the smartphone
*
*********************************************************************/
uint8_t BC_motocon_get_language_type
    (
    void
    )
{
return phone_language_type;
}

/*********************************************************************
*
* @public
* BC_motocon_get_battery_percentage
*
* Get the battery percentage type of the smartphone
*
* @return Battery percentage of the smartphone
*
*********************************************************************/
uint8_t BC_motocon_get_battery_percentage
    (
    void
    )
{
return phone_battery_percentage;
}

/*********************************************************************
*
* @public
* BC_motocon_get_battery_charging_state
*
* Get the battery charging state of the smartphone
*
* @return Battery charging state of the smartphone
*
*********************************************************************/
bc_motocon_battery_t BC_motocon_get_battery_charging_state
    (
    void
    )
{
return phone_battery_charging_status;
}

/*********************************************************************
*
* @public
* BC_motocon_get_phone_thermal
*
* Get the phone thermal of the smartphone
*
* @return Phone thermal of the smartphone
*
*********************************************************************/
bc_motocon_thermal_state_t BC_motocon_get_phone_thermal
    (
    void
    )
{
return phone_thermal_state;
}

/*********************************************************************
*
* @public
* BC_motocon_get_bt_headset_state
*
* Get the headset connection status of the smartphone
*
* @return Headset connection status of the smartphone
*
*********************************************************************/
bc_motocon_bt_headset_state_t BC_motocon_get_bt_headset_state
    (
    void
    )
{
return phone_headset_state;
}

/*********************************************************************
*
* @public
* BC_motocon_get_phone_cell_signal_level
*
* Get the cell signal level of the smartphone
*
* @return Cell signal level of the smartphone
*
*********************************************************************/
uint8_t BC_motocon_get_phone_cell_signal_level
    (
    void
    )
{
return phone_cell_signal_level;
}

/*********************************************************************
*
* @public
* BC_motocon_answer_call_callback
*
* Callback function from UI to answer the phone call
*
* @param uid Unique notification id
*
*********************************************************************/
void BC_motocon_answer_call_callback
    (
    const uint32_t uid
    )
{
BC_MOTOCON_PRINTF( "%s\r\n", __FUNCTION__ );
BC_motocon_send_incoming_call_control( BC_MOTOCON_CALL_ANSWER );
}

/*********************************************************************
*
* @public
* BC_motocon_decline_call_callback
*
* Callback function from UI to decline the phone call
*
* @param uid Unique notification id
*
*********************************************************************/
void BC_motocon_decline_call_callback
    (
    const uint32_t uid
    )
{
BC_MOTOCON_PRINTF( "%s\r\n", __FUNCTION__ );
BC_motocon_send_incoming_call_control( BC_MOTOCON_CALL_REJECT );
}

/*********************************************************************
*
* @public
* BC_motocon_phonecall_volume_control_callback
*
* Callback function from UI to control phone call volume
*
* @param control Volume control
*
*********************************************************************/
void BC_motocon_phonecall_volume_control_callback
    (
    const EnumVolumeControl control
    )
{
BC_MOTOCON_PRINTF( "%s %d\r\n", __FUNCTION__, control );
switch( control )
    {
    case EnumVolumeControlUP:
        BC_motocon_send_volume_control( BC_MOTOCON_VOLUME_UP );
        break;
    case EnumVolumeControlDOWN:
        BC_motocon_send_volume_control( BC_MOTOCON_VOLUME_DOWN );
        break;
    default:
        BC_MOTOCON_PRINTF( "invalid %d\r\n", control );
        break;
    }
}

/*********************************************************************
*
* @public
* BC_motocon_get_phonecall_volume
*
* Get phone call volume
*
* @return Phone call volume from 0 to 100
*
*********************************************************************/
uint32_t BC_motocon_get_phonecall_volume
    (
    void
    )
{
BC_MOTOCON_PRINTF( "%s %d\r\n", __FUNCTION__, phone_call_volume );
return phone_call_volume;
}

/*********************************************************************
*
* @public
* BC_motocon_get_ota_update_info
*
* Get OTA update info
*
* @return Pointer to OTA update info
*
*********************************************************************/
bc_motocon_ota_update_info_t* BC_motocon_get_ota_update_info
    (
    void
    )
{
return &ota_update_info;
}

/*********************************************************************
*
* @public
* BC_motocon_set_request_from_clock
*
* Set if the time request is from clock
*
*********************************************************************/
void BC_motocon_set_request_from_clock
    (
    void
    )
{
BC_MOTOCON_PRINTF( "%s\r\n", __FUNCTION__ );
is_request_from_clock = true;
}

/*********************************************************************
*
* @private
* bc_motocon_listener_init
*
* Get the language type of the smartphone
*
* @return Language type of the smartphone
*
*********************************************************************/
void bc_motocon_listener_init
    (
    void
    )
{
BC_motocon_register_callback( &motocon_callback );
}
