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

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
void bc_motocon_listener_connection_status( const bool connected );
void bc_motocon_listener_language_type( const uint8_t language_type );
void bc_motocon_listener_battery( const uint8_t battery, const bc_motocon_battery_t battery_type );
void bc_motocon_listener_phone_thermal( const bc_motocon_thermal_state_t thermal_state );
void bc_motocon_listener_bt_headset_state( const bc_motocon_bt_headset_state_t headset_state );
void bc_motocon_listener_phone_signal_level( const uint8_t level );

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
    bc_motocon_listener_connection_status,  // connected_status_changed_callback
    NULL,                                   // weather_location_callback
    NULL,                                   // weather_info_callback
    NULL,                                   // vehicle_info_subscribe_callback
    NULL,                                   // datetime_changed_callback
    NULL,                                   // vehicle_datetime_callback
    bc_motocon_listener_language_type,      // language_type_callback
    NULL,                                   // notification_callback
    NULL,                                   // can_related_callback
    NULL,                                   // can_request_callback
    NULL,                                   // injection_request_callback
    bc_motocon_listener_battery,            // battery_callback
    NULL,                                   // bt_music_meta_data_callback
    NULL,                                   // incoming_call_info_callback
    bc_motocon_listener_phone_thermal,      // thermal_callback
    bc_motocon_listener_bt_headset_state,   // bt_headset_state_callback
    NULL,                                   // volume_level_callback
    NULL,                                   // notification_category_callback
    NULL,                                   // volume_controllable_callback
    NULL,                                   // ota_update_info_callback
    NULL,                                   // ccuid_request_callback
    bc_motocon_listener_phone_signal_level, // cell_signal_callback
    NULL                                    // call_changed_callback
    };

static uint8_t phone_language_type;
static uint8_t phone_battery_percentage;
static uint8_t phone_cell_signal_level;
static bc_motocon_battery_t phone_battery_charging_status;
static bc_motocon_thermal_state_t phone_thermal_state;
static bc_motocon_bt_headset_state_t phone_headset_state;

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
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
EW_notify_motocon_event_received( EnumMotoConRxEventCONNECTION_STATUS );
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
