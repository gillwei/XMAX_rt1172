/*********************************************************************
* @file
* mm_ams_gatt_handler.c
*
* @brief
* Media manager module - GATT AMS handler
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "EW_pub.h"
#include "fsl_debug_console.h"
#include <stdlib.h>
#include <stdint.h>
#include "task.h"

#include "mm_priv.h"
#include "MM_pub.h"
/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
static void mm_process_entity_attribute_data
    (
    ams_entity_id                           entity_id,
    uint8_t                                 attribute_id,           // Type depends on entity_id
    ams_entity_update_flags_type            entity_update_flags,
    char const * const                      value
    );

static void mm_parse_player_attribute_data
    (
    mm_media_player_obj *               mp,
    ams_player_attribute_id_type        player_attribute_id,
    ams_entity_update_flags_type        entity_update_flags,
    char const * const                  value,
    uint32_t                            received_time
    );

static void mm_parse_track_attribute_data
    (
    mm_media_player_obj *                   mp,
    ams_track_attribute_id_type             track_attribute_id,
    ams_entity_update_flags_type            entity_update_flags,
    char const * const                      value
    );
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
/*********************************************************************
*
* @public
* MM_ams_handler_entity_update_received
*
* Handle Entity update data. Data should be formatted based on AMS
* entity update characteristic spec.
*
* @param data           Entity data.
* @param data_length    Length of entity data.
*********************************************************************/
void MM_ams_handler_entity_update_received
    (
    uint8_t const * const     data,
    uint16_t                  data_length
    )
{
// First 3 bytes are hardcoded at Entity ID, Attribute ID and EntityUpdateFlags.
if( data_length < 3 )
    {
    PRINTF( "Err: invalid AMS entity update data length %d\r\n", data_length );
    }
else
    {
    // Minus 3 bytes to obtain the length of data.
    uint16_t value_len = data_length - 3;
    char value_str[value_len + 1];
    memset( value_str, 0, sizeof( value_str ) );
    memcpy( value_str, &data[3], sizeof( value_str ) );
    value_str[value_len] = '\0';

    mm_process_entity_attribute_data( data[0], data[1], data[2], value_str );
    }
}


/*********************************************************************
*
* @private
* mm_process_entity_attribute_data
*
* Process received entity update data.
*
* @param entity_id              Entity data id.
* @param attribute_id           Attribute id.
* @param entity_update_flags    Entity data update flags.
* @param value                  Entity data.
*
*********************************************************************/

static void mm_process_entity_attribute_data
    (
    ams_entity_id                           entity_id,
    uint8_t                                 attribute_id,
    ams_entity_update_flags_type            entity_update_flags,
    char const * const                      value
    )
{
PRINTF( "Entity: %d, Attribute: %d, Flags: 0x%02X, Value='%s'\r\n", entity_id, attribute_id, entity_update_flags, value ? value : NULL );
uint32_t received_time = xTaskGetTickCount();
mm_media_player_obj* media_player = NULL;
media_player = MM_ams_gatt_get_media_player_state();

switch( entity_id )
    {
    case AMS_ENTITY_ID_PLAYER:
        mm_parse_player_attribute_data( media_player, attribute_id, entity_update_flags, value, received_time );
        break;
    case AMS_ENTITY_ID_TRACK:
        mm_parse_track_attribute_data( media_player, attribute_id, entity_update_flags, value );
        break;
    default:
        PRINTF( "Err: Invalid entity id: %d\r\n", entity_id );
        break;
    }
}

/*********************************************************************
*
* @private
* mm_parse_player_attribute_data
*
* Process received player attribute data.
*
* @param mp                     Media player object.
* @param player_attribute_id    Player Attribute id.
* @param entity_update_flags    Entity data update flags.
* @param value                  Entity data.
* @param received_time          Time when receiving entity data.
*
*********************************************************************/
static void mm_parse_player_attribute_data
    (
    mm_media_player_obj *               mp,
    ams_player_attribute_id_type        player_attribute_id,
    ams_entity_update_flags_type        entity_update_flags,
    char const * const                  value,
    uint32_t                            received_time
    )
{
switch( player_attribute_id )
    {
    case AMS_PLAYER_ATTRIBUTE_ID_NAME:
        PRINTF( "Player name is '%s'\r\n", value ? value : NULL );
        strncpy( mp->str.player_name, value, MEDIA_STRING_MAX_LENGTH );
        break;
    case AMS_PLAYER_ATTRIBUTE_ID_PLAYBACK_INFO:
        {
        int val_idx = 1;
        char* cur_str = ( char* )value;
        char* next_str = strtok( cur_str, "," );

        while( NULL != next_str )
            {
            if( val_idx == 1 )
                {
                // First value, playback state.
                switch( atoi( next_str ) )
                    {
                    case AMS_PLAYBACK_STATE_PAUSED:
                        mp->playback_state = MP_PLAYBACK_STATUS_PAUSED;
                        break;
                    case AMS_PLAYBACK_STATE_PLAYING:
                        mp->playback_state = MP_PLAYBACK_STATUS_PLAYING;
                        break;
                    case AMS_PLAYBACK_STATE_REWINDING:
                        mp->playback_state = MP_PLAYBACK_STATUS_REWINDING;
                        break;
                    case AMS_PLAYBACK_STATE_FAST_FORWARDING:
                        mp->playback_state = MP_PLAYBACK_STATUS_FAST_FORWARDING;
                        break;
                    default:
                        PRINTF( "Unsupported playback state %d\r\n", atoi( next_str ) );
                        break;
                    }
                PRINTF( "Playback state: %d\r\n", mp->playback_state );
                }
            else if( val_idx == 2)
                {
                // Second value, playback rate.
                mp->playback_rate = ( float )atof( next_str );
                PRINTF( "Playback rate: %.2f\r\n", mp->playback_rate );
                }
            else
                {
                // Third value, elapsed time.
                mp->start_elapsed_time_ms = ( uint32_t )( 1000.0f * ( float )atof( next_str ) );
                mp->current_elapsed_time_sec = mp->start_elapsed_time_ms / 1000;
                mp->start_elapsed_time_tick = received_time;
                PRINTF( "Elapsed time: %d ms (at %d)\r\n", mp->start_elapsed_time_ms, mp->start_elapsed_time_tick );
                if( mp->playback_state == MP_PLAYBACK_STATUS_PLAYING )
                    {
                    mm_start_elapsed_timer();
                    }
                else
                    {
                    mm_stop_elapsed_timer();
                    }
                EW_notify_playback_time_changed();
                }
            next_str = strtok( NULL, "," );
            val_idx++;
            }
        }
        break;
    // TODO: Enable when implementing volume control SCR.
    /*case AMS_PLAYER_ATTRIBUTE_ID_VOLUME:
        mp->playback_volume = ( float )atof( value );
        PRINTF( "Volume: %.2f\r\n", mp->playback_volume );
        break;*/
    default:
        PRINTF( "Invalid attribute id: %d\r\n", player_attribute_id );
        break;
    }
}

/*********************************************************************
*
* @private
* mm_parse_track_attribute_data
*
* Process received track attribute data.
*
* @param mp                     Media player object.
* @param queue_attribute_id     Track Attribute id.
* @param entity_update_flags    Entity data update flags.
* @param value                  Entity data.
*
*********************************************************************/
static void mm_parse_track_attribute_data
    (
    mm_media_player_obj *                   mp,
    ams_track_attribute_id_type             track_attribute_id,
    ams_entity_update_flags_type            entity_update_flags,
    char const * const                      value
    )
{
switch( track_attribute_id )
    {
    case AMS_TRACK_ATTRIBUTE_ID_ARTIST:
        PRINTF( "Artist = '%s'\r\n", value ? value : NULL );
        strncpy( mp->str.track_artist, value, MEDIA_STRING_MAX_LENGTH );
        EW_notify_artist_changed();
        break;
    case AMS_TRACK_ATTRIBUTE_ID_ALBUM:
        PRINTF( "Album = '%s'\r\n", value ? value : NULL );
        strncpy( mp->str.track_album, value, MEDIA_STRING_MAX_LENGTH );
        EW_notify_album_changed();
        break;
    case AMS_TRACK_ATTRIBUTE_ID_TITLE:
        PRINTF( "Title = '%s'\r\n", value ? value : NULL );
        strncpy( mp->str.track_title, value, MEDIA_STRING_MAX_LENGTH );
        EW_notify_title_changed();
        break;
    case AMS_TRACK_ATTRIBUTE_ID_DURATION:
        if( value )
            {
            PRINTF( "Duration = '%s'\r\n", value ? value : NULL );
            float duration_sec = atof( value );
            mp->duration_sec = (uint32_t)( duration_sec );
            if( ( duration_sec - mp->duration_sec ) >= 0.5 )
                {
                mp->duration_sec++;
                }
            }
        EW_notify_playback_time_changed();
        break;
    default:
        PRINTF( "Unsupported Track Attribute ID %d\r\n", track_attribute_id );
        break;
    }
}
