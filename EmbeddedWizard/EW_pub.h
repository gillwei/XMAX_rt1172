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

typedef enum
    {
    KEY_STATE_RELEASE,
    KEY_STATE_PRESS
    } key_state;

void EW_init( void );
void EW_notify_navi_map_update( void );
void EW_notify_engine_speed_changed( int speed );
void EW_send_key_event( CoreKeyCode code, key_state state );
void EW_clear_key_state( void );
void EW_notify_title_changed( void );
void EW_notify_album_changed( void );
void EW_notify_artist_changed( void );
void EW_notify_playback_time_changed( void );
void EW_notify_playback_state_changed( void );

void EW_test_display_pattern( int index );
void EW_quit_test( void );
void EW_start_burn_in( void );
void EW_update_burn_in_time( const uint32_t time_sec );
void EW_show_burn_in_result( const bool result );

void EW_notify_bt_paired_device_status_changed( void );
void EW_notify_bt_connection_result( const bt_connection_result_type result );
void EW_notify_bt_passkey_generated( const char* pin );
void EW_notify_bt_fw_update_status( EnumBtFwStatus status, char* version );

void EW_notify_qrcode_ready( const char* qr_code_text );

void EW_notify_dd_mode_state_changed( void );
void EW_notify_weather_info_update( void );

#ifdef __cplusplus
}
#endif

#endif /* EW_PUB_H */

