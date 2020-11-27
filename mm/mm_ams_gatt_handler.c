/*********************************************************************
* @file
* mm_ams_gatt_handler.c
*
* @brief
* Media manager module - GATT AMS handler
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "EW_pub.h"
#include "fsl_debug_console.h"
#include <stdlib.h>
#include <stdint.h>

#include "mm_config.h"
#include "mm_priv.h"
#include "MM_pub.h"
/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/
#if( MM_GATT )
    static mm_media_player_obj media_player;
#endif
/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
#if( MM_GATT )
    static ams_media_event_update_attribute_type mm_process_entity_attribute_data
        (
        ams_entity_id                           entity_id,
        uint8_t                                 attribute_id,           // Type depends on entity_id
        ams_entity_update_flags_type            entity_update_flags,
        char const * const                      value
        );

    static ams_media_event_update_attribute_type mm_parse_player_attribute_data
        (
        mm_media_player_obj *               mp,
        ams_player_attribute_id_type        player_attribute_id,
        ams_entity_update_flags_type        entity_update_flags,
        char const * const                  value,
        uint32_t                            received_time
        );

    static ams_media_event_update_attribute_type mm_parse_queue_attribute_data
        (
        mm_media_player_obj *               mp,
        ams_queue_attribute_id_type         queue_attribute_id,
        ams_entity_update_flags_type        entity_update_flags,
        char const * const                  value
        );

    static ams_media_event_update_attribute_type mm_parse_track_attribute_data
        (
        mm_media_player_obj *                   mp,
        ams_track_attribute_id_type             track_attribute_id,
        ams_entity_update_flags_type            entity_update_flags,
        char const * const                      value
        );
#endif

/*********************************************************************
*
* @private
* mm_ams_handler_entity_update_received
*
* Handle Entity update data. Data should be formatted based on AMS
* entity update characteristic spec.
*
* @param data           Entity data.
* @param data_length    Length of entity data.
*********************************************************************/
#if( MM_GATT )
    void mm_ams_handler_entity_update_received
        (
        uint8_t const * const     data,
        uint16_t                  data_length
        )
    {
    ams_media_event_update_attribute_type media_event_attribute = AMS_MEDIA_EVENT_CNT;
    if( ams_handler.is_connected )
        {
        // First 3 bytes are hardcoded at Entity ID, Attribute ID and EntityUpdateFlags.
        if( data_length < 3 )
            {
            PRINTF("Something went wrong\n");
            }
        else if( data_length == 3 )
            {
            media_event_attribute = mm_process_entity_attribute_data( data[0], data[1], data[2], NULL );
            if( AMS_MEDIA_EVENT_CNT != media_event_attribute )
                {
                EW_notify_media_player_state_updated( media_event_attribute );
                }
            }
        else
            {
            // Minus 3 bytes to obtain the length of data.
            uint16_t value_len = data_length - 3;
            char* value_str = ( char* )malloc( ( value_len + 1 )* sizeof( char ) );
            memcpy( value_str, &data[3], value_len );
            value_str[value_len] = '\0';
            media_event_attribute = mm_process_entity_attribute_data( data[0], data[1], data[2], value_str );
            if( AMS_MEDIA_EVENT_CNT != media_event_attribute )
                {
                EW_notify_media_player_state_updated( media_event_attribute );
                }
            }
        }
    }
#endif

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
#if( MM_GATT )
    static ams_media_event_update_attribute_type mm_process_entity_attribute_data
        (
        ams_entity_id                           entity_id,
        uint8_t                                 attribute_id,
        ams_entity_update_flags_type            entity_update_flags,
        char const * const                      value
        )
    {
    ams_media_event_update_attribute_type media_event_attribute = AMS_MEDIA_EVENT_CNT;
    taskENTER_CRITICAL();
    PRINTF( "Entity: %d, Attribute: %d, Flags: 0x%02X, Value='%s'\r\n", entity_id, attribute_id, entity_update_flags, value ? value : NULL );
    uint32_t received_time = xTaskGetTickCount();
    switch( entity_id )
        {
        case AMS_ENTITY_ID_PLAYER:
            media_event_attribute = mm_parse_player_attribute_data( &media_player, attribute_id, entity_update_flags, value, received_time );
            break;
        case AMS_ENTITY_ID_QUEUE:
            media_event_attribute = mm_parse_queue_attribute_data( &media_player, attribute_id, entity_update_flags, value );
            break;
        case AMS_ENTITY_ID_TRACK:
            media_event_attribute = mm_parse_track_attribute_data( &media_player, attribute_id, entity_update_flags, value );
            break;
        default:
            PRINTF( "Something unexpected?\r\n" );
            break;
        }
    taskEXIT_CRITICAL();
    return media_event_attribute;
    }
#endif

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
#if( MM_GATT )
    static ams_media_event_update_attribute_type mm_parse_player_attribute_data
        (
        mm_media_player_obj *               mp,
        ams_player_attribute_id_type        player_attribute_id,
        ams_entity_update_flags_type        entity_update_flags,
        char const * const                  value,
        uint32_t                            received_time
        )
    {
    ams_media_event_update_attribute_type media_event_attribute = AMS_MEDIA_EVENT_CNT;
    switch( player_attribute_id )
        {
        case AMS_PLAYER_ATTRIBUTE_ID_NAME:
            PRINTF( "Player name is '%s'\r\n", value ? value : NULL );
            strncpy( mp->str.player_name, value, MEDIA_STRING_MAX_LENGTH );
            media_event_attribute = AMS_MEDIA_EVENT_PLAYER_ATTRIBUTE_ID_NAME;
            break;
        case AMS_PLAYER_ATTRIBUTE_ID_PLAYBACK_INFO:
            {
            int val_idx = 1;
            char* cur_str = value;
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
                    mp->start_elapsed_time_tick = received_time;
                    PRINTF( "Elapsed time: %d ms (at %d)\r\n", mp->start_elapsed_time_ms, mp->start_elapsed_time_tick );
                    media_event_attribute = AMS_MEDIA_EVENT_PLAYER_ATTRIBUTE_ID_PLAYBACK_INFO;
                    }
                next_str = strtok( NULL, "," );
                val_idx++;
                }
            }
            break;
        case AMS_PLAYER_ATTRIBUTE_ID_VOLUME:
            mp->playback_volume = ( float )atof( value );
            PRINTF( "Volume: %0.5f\r\n", mp->playback_volume );
            media_event_attribute = AMS_MEDIA_EVENT_PLAYER_ATTRIBUTE_ID_VOLUME;
            break;
        default:
            PRINTF( "Invalid attribute id: %d\r\n", player_attribute_id );
            break;
        }
    return media_event_attribute;
    }
#endif

/*********************************************************************
*
* @private
* mm_parse_queue_attribute_data
*
* Process received queue attribute data.
*
* @param mp                     Media player object.
* @param queue_attribute_id     Queue Attribute id.
* @param entity_update_flags    Entity data update flags.
* @param value                  Entity data.
*
*********************************************************************/
#if( MM_GATT )
    static ams_media_event_update_attribute_type mm_parse_queue_attribute_data
        (
        mm_media_player_obj *               mp,
        ams_queue_attribute_id_type         queue_attribute_id,
        ams_entity_update_flags_type        entity_update_flags,
        char const * const                  value
        )
    {
    ams_media_event_update_attribute_type media_event_attribute = AMS_MEDIA_EVENT_CNT;
    switch( queue_attribute_id )
        {
        case AMS_QUEUE_ATTRIBUTE_ID_INDEX:
            mp->queue_index = value ? atoi( value ) : 0;
            PRINTF( "Queue index: %d\r\n", mp->queue_index );
            media_event_attribute = AMS_MEDIA_EVENT_QUEUE_ATTRIBUTE_ID_INDEX;
            break;
        case AMS_QUEUE_ATTRIBUTE_ID_COUNT:
            mp->queue_index = value ? atoi( value ) : 0;
            PRINTF( "Queue count: %d\r\n", mp->queue_count );
            media_event_attribute = AMS_MEDIA_EVENT_QUEUE_ATTRIBUTE_ID_COUNT;
            break;
        case AMS_QUEUE_ATTRIBUTE_ID_SHUFFLE_MODE:
            if( value )
                {
                switch( atoi( value ) )
                    {
                    case AMS_SHUFFLE_MODE_OFF:
                        mp->shuffle_mode = MP_SHUFFLE_MODE_OFF;
                        break;

                    case AMS_SHUFFLE_MODE_ONE:
                        mp->shuffle_mode = MP_SHUFFLE_MODE_ONE;
                        break;

                    case AMS_SHUFFLE_MODE_ALL:
                        mp->shuffle_mode = MP_SHUFFLE_MODE_ALL;
                        break;

                    default:
                        PRINTF( "Invalid shuffle mode\r\n" );
                        break;
                    }
                PRINTF( "Shuffle Mode: %d\r\n", mp->shuffle_mode );
                media_event_attribute = AMS_MEDIA_EVENT_QUEUE_ATTRIBUTE_ID_SHUFFLE_MODE;
                }
            break;
        case AMS_QUEUE_ATTRIBUTE_ID_REPEAT_MODE:
            if( value )
                {
                switch( atoi( value ) )
                    {
                    case AMS_REPEAT_MODE_OFF:
                        mp->repeat_mode = MP_REPEAT_MODE_OFF;
                        break;

                    case AMS_REPEAT_MODE_ONE:
                        mp->repeat_mode = MP_REPEAT_MODE_ONE;
                        break;

                    case AMS_REPEAT_MODE_ALL:
                        mp->repeat_mode = MP_REPEAT_MODE_ALL;
                        break;

                    default:
                        PRINTF( "Invalid repeat mode\r\n" );
                        break;
                    }
                PRINTF( "Repeat Mode: %d\r\n", mp->repeat_mode );
                media_event_attribute = AMS_MEDIA_EVENT_QUEUE_ATTRIBUTE_ID_REPEAT_MODE;
                }
            break;
        default:
            PRINTF( "Unsupported queue attribute mode %d\r\n", queue_attribute_id );
            break;
        }
    return media_event_attribute;
    }
#endif

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
#if( MM_GATT )
    static ams_media_event_update_attribute_type mm_parse_track_attribute_data
        (
        mm_media_player_obj *                   mp,
        ams_track_attribute_id_type             track_attribute_id,
        ams_entity_update_flags_type            entity_update_flags,
        char const * const                      value
        )
    {
    ams_media_event_update_attribute_type media_event_attribute = AMS_MEDIA_EVENT_CNT;
    switch( track_attribute_id )
        {
        case AMS_TRACK_ATTRIBUTE_ID_ARTIST:
            PRINTF( "Artist = '%s'\r\n", value ? value : NULL );
            strncpy( mp->str.track_artist, value, MEDIA_STRING_MAX_LENGTH );
            media_event_attribute = AMS_MEDIA_EVENT_TRACK_ATTRIBUTE_ID_ARTIST;
            break;
        case AMS_TRACK_ATTRIBUTE_ID_ALBUM:
            PRINTF( "Album = '%s'\r\n", value ? value : NULL );
            strncpy( mp->str.track_album, value, MEDIA_STRING_MAX_LENGTH );
            media_event_attribute = AMS_MEDIA_EVENT_TRACK_ATTRIBUTE_ID_ALBUM;
            break;
        case AMS_TRACK_ATTRIBUTE_ID_TITLE:
            PRINTF( "Title = '%s'\r\n", value ? value : NULL );
            strncpy( mp->str.track_title, value, MEDIA_STRING_MAX_LENGTH );
            media_event_attribute = AMS_MEDIA_EVENT_TRACK_ATTRIBUTE_ID_TITLE;
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
                media_event_attribute = AMS_MEDIA_EVENT_TRACK_ATTRIBUTE_ID_DURATION;
                }
            break;
        default:
            PRINTF( "Unsupported Track Attribute ID %d\r\n", track_attribute_id );
            break;
        }
    return media_event_attribute;
    }
#endif
