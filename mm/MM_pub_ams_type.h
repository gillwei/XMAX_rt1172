/*********************************************************************
* @file
* MM_pub_ams_type.h
*
* @brief
* Media manager module - public API
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef MM_PUB_AMS_TYPE_H
#define MM_PUB_AMS_TYPE_H

#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>
#define MEDIA_STRING_MAX_LENGTH 64

/* Media player state defination */

typedef enum
    {
    MP_PLAYBACK_STATUS_PAUSED,
    MP_PLAYBACK_STATUS_PLAYING,
    MP_PLAYBACK_STATUS_REWINDING,
    MP_PLAYBACK_STATUS_FAST_FORWARDING,
    MP_PLAYBACK_STATUS_INVALID
    } media_player_playback_status;

typedef enum
    {
    MP_SHUFFLE_MODE_OFF,
    MP_SHUFFLE_MODE_ONE,
    MP_SHUFFLE_MODE_ALL,

    MP_SHUFFLE_MODE_INVALID
    } media_player_shuffle_mode;

typedef enum
    {
    MP_REPEAT_MODE_OFF,
    MP_REPEAT_MODE_ONE,
    MP_REPEAT_MODE_ALL,

    MP_REPEAT_MODE_INVALID
    } media_player_repeat_mode;

/* AMS remote command */

typedef enum
    {
    AMS_REMOTE_COMMAND_PLAY,
    AMS_REMOTE_COMMAND_PAUSE,
    AMS_REMOTE_COMMAND_TOGGLE_PLAY_PAUSE,
    AMS_REMOTE_COMMAND_NEXT_TRACK,
    AMS_REMOTE_COMMAND_PREVIOUS_TRACK,
    AMS_REMOTE_COMMAND_VOLUME_UP,
    AMS_REMOTE_COMMAND_VOLUME_DOWN,
    AMS_REMOTE_COMMAND_ADVANCE_REPEAT_MODE,
    AMS_REMOTE_COMMAND_ADVANCE_SHUFFLE_MODE,
    AMS_REMOTE_COMMAND_SKIP_FORWARD,
    AMS_REMOTE_COMMAND_SKIP_BACKWARD,
    AMS_REMOTE_COMMAND_LIKE_TRACK,
    AMS_REMOTE_COMMAND_DISLIKE_TRACK,
    AMS_REMOTE_COMMAND_BOOKMARK_TRACK,

    AMS_REMOTE_COMMAND_CNT
    } ams_remote_command;

/* AMS entity */

typedef enum
    {
    AMS_ENTITY_ID_PLAYER,
    AMS_ENTITY_ID_QUEUE,
    AMS_ENTITY_ID_TRACK
    } ams_entity_id;

/* AMS entity flag */

typedef enum
    {
    AMS_ENTITY_FLAGS_TRUNCATED
    } ams_entity_update_flags_type;

/* Player attribute constants */

typedef enum
    {
    AMS_PLAYER_ATTRIBUTE_ID_NAME,
    AMS_PLAYER_ATTRIBUTE_ID_PLAYBACK_INFO,
    AMS_PLAYER_ATTRIBUTE_ID_VOLUME
    } ams_player_attribute_id_type;

typedef enum
    {
    AMS_PLAYBACK_STATE_PAUSED,
    AMS_PLAYBACK_STATE_PLAYING,
    AMS_PLAYBACK_STATE_REWINDING,
    AMS_PLAYBACK_STATE_FAST_FORWARDING
    } ams_playback_state_type;

/* Queue attribute constants */

typedef enum
    {
    AMS_QUEUE_ATTRIBUTE_ID_INDEX,
    AMS_QUEUE_ATTRIBUTE_ID_COUNT,
    AMS_QUEUE_ATTRIBUTE_ID_SHUFFLE_MODE,
    AMS_QUEUE_ATTRIBUTE_ID_REPEAT_MODE
    } ams_queue_attribute_id_type;

typedef enum
    {
    AMS_SHUFFLE_MODE_OFF,
    AMS_SHUFFLE_MODE_ONE,
    AMS_SHUFFLE_MODE_ALL
    } ams_shuffle_mode_type;

typedef enum
    {
    AMS_REPEAT_MODE_OFF,
    AMS_REPEAT_MODE_ONE,
    AMS_REPEAT_MODE_ALL
    } ams_repeat_mode_type;

/* Track attribute constants */

typedef enum
    {
    AMS_TRACK_ATTRIBUTE_ID_ARTIST,
    AMS_TRACK_ATTRIBUTE_ID_ALBUM,
    AMS_TRACK_ATTRIBUTE_ID_TITLE,
    AMS_TRACK_ATTRIBUTE_ID_DURATION
    } ams_track_attribute_id_type;

/* AMS attribute event types */

typedef enum
    {
    AMS_MEDIA_EVENT_PLAYER_ATTRIBUTE_ID_NAME,
    AMS_MEDIA_EVENT_PLAYER_ATTRIBUTE_ID_PLAYBACK_INFO,
    AMS_MEDIA_EVENT_PLAYER_ATTRIBUTE_ID_VOLUME,

    AMS_MEDIA_EVENT_QUEUE_ATTRIBUTE_ID_INDEX,
    AMS_MEDIA_EVENT_QUEUE_ATTRIBUTE_ID_COUNT,
    AMS_MEDIA_EVENT_QUEUE_ATTRIBUTE_ID_SHUFFLE_MODE,
    AMS_MEDIA_EVENT_QUEUE_ATTRIBUTE_ID_REPEAT_MODE,

    AMS_MEDIA_EVENT_TRACK_ATTRIBUTE_ID_ARTIST,
    AMS_MEDIA_EVENT_TRACK_ATTRIBUTE_ID_ALBUM,
    AMS_MEDIA_EVENT_TRACK_ATTRIBUTE_ID_TITLE,
    AMS_MEDIA_EVENT_TRACK_ATTRIBUTE_ID_DURATION,

    AMS_MEDIA_EVENT_INACTIVE,

    AMS_MEDIA_EVENT_CNT
    } ams_media_event_update_attribute_type;

/* Media player state data structure */

typedef struct
    {
    char track_album[MEDIA_STRING_MAX_LENGTH];
    char track_artist[MEDIA_STRING_MAX_LENGTH];
    char track_title[MEDIA_STRING_MAX_LENGTH];
    char player_name[MEDIA_STRING_MAX_LENGTH];
    } string_data;

typedef struct
    {
    string_data                     str;
    uint32_t                        duration_sec;
    float                           playback_volume;
    float                           playback_rate;
    media_player_shuffle_mode       shuffle_mode;
    media_player_repeat_mode        repeat_mode;
    uint32_t                        queue_index;
    uint32_t                        queue_count;
    uint32_t                        current_elapsed_time_sec;
    uint32_t                        start_elapsed_time_ms;
    uint32_t                        start_elapsed_time_tick;
    media_player_playback_status    playback_state;
    } mm_media_player_obj;

#ifdef __cplusplus
}
#endif

#endif /* MM_PUB_AMS_TYPE_H */
