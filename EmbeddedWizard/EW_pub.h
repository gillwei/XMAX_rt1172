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

// #include "Enum.h"
#include "Core.h"
// #include "MM_pub_ams_type.h"
// #include "BTM_pub.h"

typedef enum
    {
    KEY_STATE_RELEASE,
    KEY_STATE_PRESS
    } key_state;

void EW_init( void );
// void EW_notify_navi_map_update( void );
// void EW_notify_engine_speed_changed( int speed );
// void EW_send_key_event( CoreKeyCode code, key_state state );
// void EW_clear_key_state( void );
// void EW_notify_text_ready( const char* str );
// void EW_notify_image_ready( void );
// void EW_notify_scene_changed( void );
// void EW_notify_title_changed( void );
// void EW_notify_album_changed( void );
// void EW_notify_artist_changed( void );
// void EW_notify_playback_time_changed( void );
// void EW_notify_playback_state_changed( void );
// void EW_test_display_pattern( int index );
// void EW_quit_test( void );

// void EW_notify_bt_connection_result( const bt_connection_result_type result );
// void EW_notify_bt_passkey_generated( const char* pin );
// void EW_notify_bt_fw_update_status( EnumBtFwStatus status, char* version );

#ifdef __cplusplus
}
#endif

#endif /* EW_PUB_H */

