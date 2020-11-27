/*********************************************************************
* @file
* mm_ams_avrc_handler.c
*
* @brief
* Media manager module - AVRC AMS handler
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
#include "timers.h"

#include "mm_config.h"
#include "mm_priv.h"
#include "MM_pub.h"
/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define MEDIA_DELAY_TIME_MS    ( 600 )
typedef bool (* ams_avrc_handler_cb )( ams_remote_command command );

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/
typedef struct
    {
    ams_avrc_handler_cb      callback;
    bool                     is_connected;
    } ams_avrc_handler_type;

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/
static ams_avrc_handler_type ams_avrc_handler;
static mm_media_player_obj media_player;
static TimerHandle_t delay_timer_handle;
/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @private
* mm_start_delay_timer
*
* Start delay timer to delay sending time information.
*
*********************************************************************/
void mm_start_delay_timer
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
BaseType_t result = xTimerStart( delay_timer_handle, 0 );
configASSERT( result == pdPASS );
}

/*********************************************************************
*
* @private
* mm_timer_callback
*
* A timer callback function which stops delay timer and send time
* info to embedded wizard.
*
* @param timer_handle The handle of delay timer.
*
*********************************************************************/
static void mm_delay_timer_callback
    (
    TimerHandle_t timer_handle
    )
{
BaseType_t result = xTimerStop( timer_handle, 0 );
configASSERT( result == pdPASS );
EW_notify_playback_time_changed();
}

/*********************************************************************
*
* @private
* create_delay_timer
*
* Create the delay timer to delay the time information
* to embedded wizard.
*
*********************************************************************/
static void create_delay_timer
    (
    void
    )
{
delay_timer_handle = xTimerCreate( "mm_delay_timer", pdMS_TO_TICKS( MEDIA_DELAY_TIME_MS ), pdTRUE, ( void * ) 0, mm_delay_timer_callback );
configASSERT( NULL != delay_timer_handle );
}

/*********************************************************************
*
* @private
* mm_ams_avrc_handler_init
*
* Initialize AMS handler.
*
*********************************************************************/
void mm_ams_avrc_handler_init
    (
    void
    )
{
ams_avrc_handler.callback = mm_queue_cmd;
ams_avrc_handler.is_connected = true;
create_delay_timer();
}

/*********************************************************************
*
* @private
* mm_ams_avrc_handler_disconnect
*
* Reset internal media player state to default values.
*
*********************************************************************/
void mm_ams_avrc_handler_disconnect
    (
    void
    )
{
ams_avrc_handler.is_connected = false;
MM_reset_media_player_state();
}

/*********************************************************************
*
* @public
* MM_get_handler_status
*
* Check current ams handler status
*
* @return Ams handler status ( connect/disconnect )
*
*********************************************************************/
bool MM_get_handler_status
    (
    void
    )
{
return ams_avrc_handler.is_connected;
}

/*********************************************************************
*
* @public
* MM_send_command
*
* Send user command to queue.
*
* @param command Ams remote command type.
* @return Result of sending command.
*
*********************************************************************/
bool MM_send_command
    (
    ams_remote_command command
    )
{

bool command_sent = false;

if( NULL != ams_avrc_handler.callback )
    {
    command_sent = ams_avrc_handler.callback( command );
    }
return command_sent;
}

/*********************************************************************
*
* @public
* MM_get_media_player_state
*
* Obtain media player state data
* @return media player state data
*
*********************************************************************/
mm_media_player_obj MM_get_media_player_state
    (
    void
    )
{
return media_player;
}

/*********************************************************************
*
* @private
* MM_reset_media_player_state
*
* Reset media player state data
*
*********************************************************************/
void MM_reset_media_player_state
    (
    void
    )
{
media_player.playback_state = MP_PLAYBACK_STATUS_INVALID;
media_player.playback_volume = 0.0;
media_player.repeat_mode = MP_REPEAT_MODE_INVALID;
media_player.shuffle_mode = MP_SHUFFLE_MODE_INVALID;
media_player.duration_sec = 0;
media_player.start_elapsed_time_ms = 0;
media_player.start_elapsed_time_tick = 0;
media_player.playback_rate = 0.0;
media_player.queue_index = 0;
media_player.queue_count = 0;
memset( media_player.str.player_name, 0, sizeof(char)*MEDIA_STRING_MAX_LENGTH );
memset( media_player.str.track_album, 0, sizeof(char)*MEDIA_STRING_MAX_LENGTH );
memset( media_player.str.track_artist, 0, sizeof(char)*MEDIA_STRING_MAX_LENGTH );
memset( media_player.str.track_title, 0, sizeof(char)*MEDIA_STRING_MAX_LENGTH );
}

/*********************************************************************
*
* @private
* mm_update_elased_time
*
* Update elapsed time
*
*********************************************************************/
#if( MM_AVRC )
    void mm_update_elapsed_time
        (
        void
        )
    {
    if( media_player.playback_state == MP_PLAYBACK_STATUS_PLAYING )
        {
        uint32_t elapsed_time_sec = ( media_player.start_elapsed_time_ms +
            ( uint32_t )( ( float )( xTaskGetTickCount() - media_player.start_elapsed_time_tick ) * media_player.playback_rate ) ) / 1000;

        if( media_player.current_elapsed_time_sec != elapsed_time_sec )
            {
            media_player.current_elapsed_time_sec = elapsed_time_sec;
            EW_notify_playback_time_changed();
            }
        }
    }
#endif

/*********************************************************************
*
* @public
* MM_set_track_data
*
* Set track attribute data.
* @param track_attribute_id Attribute id of a track
* @param len                Length of attribute data string.
* @param value              Attribute data string.
*
*********************************************************************/
#if( MM_AVRC )
    void MM_set_track_data
        (
        const ams_track_attribute_id_type       track_attribute_id,
        const int                               len,
        uint8_t const * const                   value
        )
    {
    switch( track_attribute_id )
        {
        case AMS_TRACK_ATTRIBUTE_ID_ARTIST:
            PRINTF( "Artist = '%s'\r\n", value ? value : NULL );
            strncpy( media_player.str.track_artist, ( const char* ) value, MEDIA_STRING_MAX_LENGTH );
            EW_notify_artist_changed();
            break;
        case AMS_TRACK_ATTRIBUTE_ID_ALBUM:
            PRINTF( "Album name is = '%s'\r\n", value ? value : NULL );
            strncpy( media_player.str.track_album, ( const char* ) value, MEDIA_STRING_MAX_LENGTH );
            EW_notify_album_changed();
            break;
        case AMS_TRACK_ATTRIBUTE_ID_TITLE:
            PRINTF( "Title = '%s'\r\n", value ? value : NULL );
            strncpy( media_player.str.track_title, ( const char* ) value, MEDIA_STRING_MAX_LENGTH );
            EW_notify_title_changed();
            break;
        case AMS_TRACK_ATTRIBUTE_ID_DURATION:
            if( value )
                {
                PRINTF( "Duration = '%s'\r\n", value ? value : NULL );
                float duration_sec = atof( ( const char* ) value );
                media_player.duration_sec = ( uint32_t )( duration_sec );
                if( ( duration_sec - media_player.duration_sec ) >= 0.5  )
                    {
                    media_player.duration_sec++;
                    }
                EW_notify_playback_time_changed();
                }
            break;
        default:
            PRINTF( "Unsupported Track Attribute ID %d\r\n", track_attribute_id );
            break;
        }
    }
#endif

/*********************************************************************
*
* @public
* MM_set_track_data
*
* Set playback state
*
* @param playback_state Playback status.
*
*********************************************************************/
#if( MM_AVRC )
    void MM_set_playback_state
        (
        const ams_playback_state_type   playback_state
        )
    {
    switch( playback_state )
        {
        case AMS_PLAYBACK_STATE_PAUSED:
            media_player.playback_state = MP_PLAYBACK_STATUS_PAUSED;
            PRINTF( "PAUSED.\r\n" );
            break;
        case AMS_PLAYBACK_STATE_PLAYING:
            media_player.playback_state = MP_PLAYBACK_STATUS_PLAYING;
            PRINTF( "PLAYING.\r\n" );
            break;
        case AMS_PLAYBACK_STATE_REWINDING:
            media_player.playback_state = MP_PLAYBACK_STATUS_REWINDING;
            PRINTF( "REWINDING. \r\n" );
            break;
        case AMS_PLAYBACK_STATE_FAST_FORWARDING:
            media_player.playback_state = MP_PLAYBACK_STATUS_FAST_FORWARDING;
            PRINTF( "FAST-FORWARDING. \r\n" );
            break;
        }
    EW_notify_playback_state_changed();
    }
#endif

/*********************************************************************
*
* @public
* MM_set_elapsed_time
*
* Set elapsed time
*
* @param elapsed_time_sec Elapsed time in second.
*
*********************************************************************/
#if( MM_AVRC )
    void MM_set_elapsed_time
        (
        const uint32_t elapsed_time_sec
        )
    {
    media_player.current_elapsed_time_sec = elapsed_time_sec;
    media_player.start_elapsed_time_ms    = elapsed_time_sec * 1000;
    media_player.start_elapsed_time_tick  = xTaskGetTickCount();
    if( media_player.playback_state == MP_PLAYBACK_STATUS_PLAYING )
        {
        media_player.playback_rate = 1.0;
        mm_start_elapsed_timer();
        }
    else
        {
        media_player.playback_rate = 0.0;
        mm_stop_elapsed_timer();
        }

    // When playing the next track, iPhone sends the zero elapsed time followed by the duration.
    // If notifying the play time before receiving the duration of next track,
    // the UI will show the remain time of last track, then change to the remain time of next track.
    // To avoid this flickering of remain time, we delay sending time info to UI when the elapsed time is zero.
    if( elapsed_time_sec == 0 )
        {
        mm_start_delay_timer();
        }
        else
        {
        EW_notify_playback_time_changed();
        }
    }
#endif
