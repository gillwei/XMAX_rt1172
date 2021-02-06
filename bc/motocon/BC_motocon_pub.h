/*********************************************************************
* @file
* BC_motocon_pub.h
*
* @brief
* MotoConSDK module - public API
*
* Copyright 2020-2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef BC_MOTOCON_PUB_H
#define BC_MOTOCON_PUB_H

#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "BC_motocon_pub_type.h"
#include <stdbool.h>

/*--------------------------------------------------------------------
                          LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define ENABLE_MOTOCON_DEBUG_LOG ( 1 )
#define ENABLE_MOTOCON_HCI_LINK  ( 0 )

/*--------------------------------------------------------------------
                                TYPES
--------------------------------------------------------------------*/
typedef struct
    {
    void ( *connected_status_changed_callback ) ( const bool connected );
    void ( *weather_location_callback ) ( const uint8_t length, const uint8_t* content );
    void ( *weather_info_callback ) ( const bc_motocon_weather_info_t* weather_info );
    void ( *vehicle_info_subscribe_callback ) ( const uint16_t subscribe_interval );
    void ( *datetime_changed_callback ) ( void );
    void ( *vehicle_datetime_callback ) ( const bc_motocon_time_t* time );
    void ( *language_type_callback ) ( const bc_motocon_language_t language_type );
    void ( *notification_callback ) ( const bc_motocon_notification_v2_t* notification );
    void ( *can_related_callback ) ( const bc_motocon_command_code_t command, const uint32_t size, const uint8_t* data ); /* 0x0101 ~ 0x0112 */
    void ( *can_request_callback ) ( void );
    void ( *injection_request_callback ) ( void );
    void ( *battery_callback ) ( const uint8_t battery, const bc_motocon_battery_t battery_type );
    void ( *bt_music_meta_data_callback ) ( const bc_motocon_bt_music_meta_data_t* music_meta_data );
    void ( *incoming_call_info_callback ) ( const bc_motocon_incoming_call_info_t* incoming_call_information );
    void ( *thermal_callback ) ( const bc_motocon_thermal_state_t thermal_state );
    void ( *bt_headset_state_callback ) ( const bc_motocon_bt_headset_state_t headset_state );
    void ( *volume_level_callback ) ( const uint8_t level );
    void ( *notification_category_callback ) ( const bc_motocon_notification_category_t* notification_category );
    void ( *volume_controllable_callback ) ( const bool enable );
    void ( *ota_update_info_callback ) ( const bc_motocon_ota_update_info_t* info );
    } bc_motocon_callback_t;

typedef enum
    {
    BC_MOTOCON_SEND_RESULT_SUCCESS,
    BC_MOTOCON_SEND_RESULT_INVALID_INPUT,
    BC_MOTOCON_SEND_RESULT_INVALID_TYPE,
    BC_MOTOCON_SEND_RESULT_BLE_ERROR,
    BC_MOTOCON_SEND_RESULT_DDT_BUSY,
    BC_MOTOCON_SEND_RESULT_DDT_TIMEOUT,
    BC_MOTOCON_SEND_RESULT_DDT_COMPLETE
    } bc_motocon_send_result_t;

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              VARIABLES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
bool BC_motocon_register_callback( bc_motocon_callback_t* callback );

bool BC_motocon_unregister_callback( bc_motocon_callback_t* callback );

bool BC_motocon_is_connected( void );

bc_motocon_send_result_t BC_motocon_send_lib_version( const uint8_t major, const uint8_t minor, const uint8_t micro );

bc_motocon_send_result_t BC_motocon_send_weather_request( void );

bc_motocon_send_result_t BC_motocon_send_vehicle_info( const bc_motocon_vehicle_info_t* info );

bc_motocon_send_result_t BC_motocon_send_vehicle_setting_request( void );

bc_motocon_send_result_t BC_motocon_send_language_type_request( void );

bc_motocon_send_result_t BC_motocon_send_can_related_data( const bc_motocon_command_code_t command, const uint32_t size, const uint8_t* data, void ( *result_callback ) ( const bc_motocon_send_result_t ) );

bc_motocon_send_result_t BC_motocon_send_can_response( const uint32_t size, const uint8_t* data, void ( *result_callback ) ( const bc_motocon_send_result_t ) );

bc_motocon_send_result_t BC_motocon_send_injection_quantity( const uint8_t* injection_quantity );

bc_motocon_send_result_t BC_motocon_send_bt_music_control( bc_motocon_bt_music_control_t control );

bc_motocon_send_result_t BC_motocon_send_incoming_call_control( bc_motocon_incoming_call_control_t control );

bc_motocon_send_result_t BC_motocon_send_headset_state_request( void );

bc_motocon_send_result_t BC_motocon_send_volume_control( bc_motocon_volume_control_t control );

bc_motocon_send_result_t BC_motocon_send_volume_controllable_request( void );

bc_motocon_send_result_t BC_motocon_send_create_ota_request( void );

bc_motocon_send_result_t BC_motocon_send_ota_linkcard_info( const bc_motocon_ota_linkcard_info_t* info );

uint8_t BC_motocon_get_language_type( void );

uint8_t BC_motocon_get_battery_percentage( void );

bc_motocon_battery_t BC_motocon_get_battery_charging_state( void );

bc_motocon_thermal_state_t BC_motocon_get_phone_thermal( void );

bc_motocon_bt_headset_state_t BC_motocon_get_bt_headset_state( void );

#ifdef __cplusplus
}
#endif

#endif /* BC_MOTOCON_PUB_H */

