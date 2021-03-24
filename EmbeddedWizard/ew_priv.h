/*********************************************************************
* @file
* ew_priv.h
*
* @brief
* EW module - private API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef EW_PRIV_H
#define EW_PRIV_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>
#include "fsl_snvs_lp.h"
#include "EW_pub.h"
#include "TEST_pub.h"
#include "BC_motocon_pub_type.h"

// save Home index and Meter setting into the last page in EEPROM
// the first 4 bits are of meter setting
// the last 4 bits are of Home index
#define LAST_PAGE_HOME_SHIFT    ( 0 )
#define LAST_PAGE_METER_SHIFT   ( 4 )

#define IGN_OFF_TASK_CLOSE_DISPLAY      ( 1 << 0 )
#define IGN_OFF_TASK_WRITE_LAST_PAGE    ( 1 << 1 )
#define IGN_OFF_TASK_ALL                ( IGN_OFF_TASK_CLOSE_DISPLAY | IGN_OFF_TASK_WRITE_LAST_PAGE )

typedef struct
    {
    CoreKeyCode code;
    key_state   state;
    } ew_key_event;

void ew_device_interface_init( void );
void ew_device_interface_deinit( void );
int  ew_device_interface_process( void );
void ew_key_init( void );
CoreRoot ew_get_core_root();
ew_key_event ew_get_key_event( void );
void ew_device_test_init( void );
void ew_device_test_deinit( void );
int ew_device_test_proc( void );

void ew_device_system_init( void );
void ew_device_system_deinit( void );
int ew_device_system_proc( void );
void ew_get_software_version( char* version );
void ew_get_bt_software_version( char* version );
void ew_get_esn( void );
void ew_get_rtc_time( snvs_lp_srtc_datetime_t* srtc_datetime );
void ew_request_qrcode( int pixel_per_mod );
EnumOperationMode ew_get_operation_mode( void );
void ew_set_operation_mode( EnumOperationMode mode );
bool ew_is_operation_mode_ready( void );

void ew_power_init( void );
int  ew_power_ignition_status( void );
void ew_power_update_ignoff_task_status( uint32_t task );

XBool ew_is_debug_build( void );
void ew_reset_to_factory_default( void );
void ew_done_factory_reset( void );
void ew_reboot_system( void );

void ew_device_navi_init( void );
void ew_device_navi_deinit( void );
int ew_device_navi_proc( void );
bool ew_navi_is_map_frame_ready( void );
bool ew_navi_is_route_guidance_started( void );

void ew_device_mm_init( void );
void ew_device_mm_deinit( void );
int ew_device_mm_proc( void );
mm_media_player_obj* ew_get_media_player_state( void );
void ew_send_command( ams_remote_command command );

void ew_device_bluetooth_init( void );
void ew_device_bluetooth_deinit( void );
int  ew_device_bluetooth_proc( void );
void ew_bt_get_local_device_name( uint8_t** device_name );
void ew_bt_get_local_device_address( uint8_t* device_addr );
void ew_bt_set_enable( bool state );
bool ew_bt_get_enable( void );
void ew_bt_set_discoverable( bool state );
bool ew_bt_get_discoverable( void );
void ew_bt_set_autoconnect( bool state );
bool ew_bt_get_autoconnect( void );
void ew_bt_get_btc_connecting_device_name( uint8_t** device_name );
bool ew_bt_is_max_paired_device_num( void );
int  ew_bt_get_paired_device_num( void );
void ew_bt_get_paired_device_at_index( const int paired_device_idx, uint8_t** device_name, bool* is_connected );
void ew_bt_connect_paired_device( const int paired_device_idx );
void ew_bt_disconnect_paired_device( const int paired_device_idx );
void ew_bt_unpair_paired_device( const int paired_device_idx );
bool ew_bt_is_ble_paired_device( const int paired_device_idx );
EnumBtcPairingState ew_get_blc_pairing_state( void );
uint32_t ew_get_ble_pincode( void );
EnumBlePairingState ew_get_ble_pairing_state( void );
uint32_t ew_get_btc_passkey( void );
void ew_set_ble_advertisement( const bool enable );

void ew_device_vi_init( void );
void ew_device_vi_deinit( void );
int  ew_device_vi_proc( void );

void ew_device_weather_init( void );
void ew_device_weather_deinit( void );
int ew_device_weather_proc( void );
bc_motocon_weather_info_t* ew_get_weather_info_obj( const int index );
void ew_get_weather_loc( char** location );
void ew_send_weather_info_req( void );
void ew_send_vehicle_setting_req( void );
int ew_get_weather_week_day( void );

#ifdef __cplusplus
}
#endif

#endif /* EW_PRIV_H */

