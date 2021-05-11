/*********************************************************************
* @file
* EW_pub.h
*
* @brief
* EW module - public API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef EW_PUB_H
#define EW_PUB_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "Enum.h"
#include "Core.h"
#include "MM_pub_ams_type.h"
#include "BTM_pub.h"
#include "RTC_pub.h"

#define CCUID_PREFIX                    "000603" /* product id: 00, device type id: 06, supplier id: 03 */
#define CCUID_PREFIX_LENGTH             ( 6 )
#define CCUID_VARIANCE_LENGTH           ( 8 )
#define PASSKEY_LENGTH                  ( 6 )
#define UNIT_ID_DUMMY_LENGTH            ( 4 )
#define UNIT_ID_LENGTH                  ( 24 )

#define UPDATE_TIME_PERIOD_MS           ( 500 )
#define ESN_STR_MAX_LEN                 ( 10 )

#define IGN_OFF_TASK_DISPLAY_OFF        ( 1 << 0 )
#define IGN_OFF_TASK_WRITE_LAST_PAGE    ( 1 << 1 )
#define IGN_OFF_TASK_WRITE_TRIP_TIME    ( 1 << 2 )
#define IGN_OFF_TASK_ALL                ( IGN_OFF_TASK_DISPLAY_OFF | IGN_OFF_TASK_WRITE_LAST_PAGE | IGN_OFF_TASK_WRITE_TRIP_TIME )

typedef enum
    {
    KEY_STATE_RELEASE,
    KEY_STATE_PRESS
    } key_state;

typedef enum
    {
    OPENING_EVENT_TFT_BACKLIGHT_ON,
    OPENING_EVENT_OP_MODE_READY
    } opening_event;

void EW_init( void );
void EW_notify_opening_event( const opening_event event );
bool EW_get_operation_mode( EnumOperationMode* mode );
void EW_reset_to_factory_default( void );
void EW_power_update_ignoff_task_status( uint32_t task );
void EW_notify_system_event_received( const EnumSystemRxEvent system_rx_event );

uint8_t* EW_get_ccuid( void );
uint16_t EW_get_qrcode_dummy( void );
uint32_t EW_get_qrcode_passkey( void );
uint32_t EW_get_esn( void );

void EW_notify_navi_map_update( void );
void EW_notify_engine_speed_changed( int speed );
void EW_send_key_event( const CoreKeyCode code, const key_state state );
void EW_clear_key_state( void );
void EW_notify_title_changed( void );
void EW_notify_album_changed( void );
void EW_notify_artist_changed( void );
void EW_notify_playback_time_changed( void );
void EW_notify_ams_ble_connected( void );
void EW_notify_motocon_music_info_changed( void );
void EW_notify_volume_changed( void );

void EW_test_display_pattern( int index );
void EW_quit_test( void );
void EW_start_burn_in( void );
void EW_update_burn_in_time( const uint32_t time_sec );
void EW_show_burn_in_result( const bool result );
void EW_notify_inspection_request( EnumInspectionMode mode, EnumInspectionDisplay display_pattern );

void EW_notify_bt_paired_device_status_changed( void );
void EW_notify_bt_connection_result( const bt_connection_result_type result );
void EW_notify_bt_passkey_generated( const uint8_t* device_name, const uint32_t passkey );
void EW_notify_btc_pairing_state_changed( const EnumBtcPairingState state );
void EW_notify_bt_fw_update_status( EnumBtFwStatus status, char* version );
void EW_notify_ble_pairing_state_changed( const EnumBlePairingState state, const uint32_t param );
void EW_notify_motocon_event_received( const EnumMotoConRxEvent event );

void EW_notify_qrcode_ready( void );
void EW_change_unit_id( const uint8_t* new_ccuid_variance, const uint32_t new_passkey, const uint16_t new_dummy );

void EW_notify_dd_mode_state_changed( void );
void EW_notify_vi_data_received( const EnumVehicleRxType rx_type );

void EW_notify_weather_info_update( void );

void EW_notify_current_road_update( void );
void EW_notify_eta_update( void );
void EW_notify_daynight_mode_update( void );
void EW_notify_speed_limit_update( void );
void EW_notify_navi_event_update( void );
void EW_notify_navigating_status_update( void );
void EW_notify_tbt_list_update( void );
void EW_notify_route_cal_progress_update( void );
void EW_notify_zoom_level_update( void );
void EW_notify_dialog_event_update( void );
void EW_notify_via_point_update( void );
void EW_notify_home_setting_update( void );
void EW_notify_office_setting_update( void );


void EW_notify_notification_list_updated( void );
void EW_notify_phone_call_state_changed( void );
void EW_notify_phone_call_volume_changed( void );

bool EW_get_clk_auto_adj( void );
void EW_notify_alert_distance_update( void );

#ifdef __cplusplus
}
#endif

#endif /* EW_PUB_H */

