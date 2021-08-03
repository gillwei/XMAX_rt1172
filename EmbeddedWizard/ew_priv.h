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
#include "NTF_pub.h"
#include "ew_tacho.h"

// the last page in EEPROM includes
// home group index (1,2,3): 2 bits
// navigation setting (0,1,2): 2 bits
// meter setting (0,1,2,3): 4 bits
#define LAST_PAGE_HOME_GROUP_SHIFT          ( 6 )
#define LAST_PAGE_NAVI_SETTING_SHIFT        ( 4 )
#define LAST_PAGE_HOME_GROUP_MASK           ( 0x3 )
#define LAST_PAGE_NAVIGATION_SETTING_MASK   ( 0x3 )
#define LAST_PAGE_METER_DISP_SETTING_MASK   ( 0xF )

#define FACTORY_RESET_BT_MANAGER    ( 1 << 0 )
#define FACTORY_RESET_LANGUAGE      ( 1 << 1 )
#define FACTORY_RESET_LAST_PAGE     ( 1 << 2 )
#define FACTORY_RESET_CLK_AUTO_ADJ  ( 1 << 3 )
#define FACTORY_RESET_TOTAL         ( FACTORY_RESET_BT_MANAGER | FACTORY_RESET_LANGUAGE | FACTORY_RESET_LAST_PAGE | FACTORY_RESET_CLK_AUTO_ADJ )

#define DEFAULT_CLK_AUTO_ADJUSTMENT     ( 1 )

typedef struct
    {
    CoreKeyCode code;
    key_state   state;
    } ew_key_event;

typedef enum
    {
    LANGUAGE_SRC_PRIORITY_EEPROM,
    LANGUAGE_SRC_PRIORITY_PHONE
    } language_src_prority_e;

void ew_system_int( void );
void ew_start_ota( void );
void ew_system_set_language( const language_src_prority_e lang_src_prority, const EnumLanguage language );

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
void ew_send_system_command( const EnumSystemTxCmd command );
int32_t ew_system_get_status( const EnumSystemStatus status_type );
void ew_get_software_version( char* version );
void ew_set_last_page( const EnumHomeGroup home_group, const EnumMeterDisplay meter_display_setting, const EnumNavigationView navigation_view_setting );
EnumHomeGroup ew_get_last_home_group( void );
EnumMeterDisplay ew_get_meter_display_setting( void );
EnumNavigationView ew_get_navigation_view_setting( void );
void ew_get_esn( void );
void ew_get_rtc_time( snvs_lp_srtc_datetime_t* srtc_datetime );
void ew_set_operation_mode( EnumOperationMode mode );
bool ew_is_operation_mode_ready( void );
int  ew_handle_special_characters( const uint8_t* in_str, uint8_t** out_str );
void ew_update_factory_reset_status( const uint32_t status );

void ew_power_init( void );
void ew_save_last_status( void );

XBool ew_is_debug_build( void );
void ew_reboot_system( void );

void ew_device_navi_init( void );
void ew_device_navi_deinit( void );
int ew_device_navi_proc( void );
bool ew_navi_is_map_frame_ready( void );

void ew_device_mm_init( void );
void ew_device_mm_deinit( void );
int ew_device_mm_proc( void );
mm_media_player_obj* ew_get_media_player_state( void );
void ew_send_command( ams_remote_command command );

void ew_device_notification_init( void );
void ew_device_notification_deinit( void );
int  ew_device_notification_proc( void );

void ew_device_bluetooth_init( void );
void ew_device_bluetooth_deinit( void );
int  ew_device_bluetooth_proc( void );
void ew_device_bt_create_queue( void );
void ew_bt_get_btc_connecting_device_name( uint8_t** device_name );
uint32_t ew_get_btc_passkey( void );
void ew_send_motocon_command( const EnumMotoConTx command );

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

void ew_get_copyright( const int index, uint8_t** copyright_title, uint8_t** copyright_content );
int ew_get_num_of_licenses( void );
void ew_set_rtc_time( snvs_lp_srtc_datetime_t* srtc_datetime );
void ew_set_clk_auto_adj( bool is_clk_auto_adj );

#ifdef __cplusplus
}
#endif

#endif /* EW_PRIV_H */

