/*********************************************************************
* @file
* MM_pub.h
*
* @brief
* Media manager module - Public API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef MM_PUB_H
#define MM_PUB_H

#ifdef __cplusplus
extern "C"{
#endif

#include "MM_pub_ams_type.h"

void MM_init( void );
mm_media_player_obj MM_get_media_player_state( void );
bool MM_get_handler_status( void );
bool MM_send_command( ams_remote_command command );
mm_media_player_obj MM_get_media_player_state( void );
void MM_reset_media_player_state( void );

void MM_set_track_data( const ams_track_attribute_id_type track_attribute_id, const int len, uint8_t const * const value );
void MM_set_playback_state( const ams_playback_state_type playback_state );
void MM_set_elapsed_time( const uint32_t elapsed_time_sec );

#ifdef __cplusplus
}
#endif

#endif /* MM_PUB_H */
