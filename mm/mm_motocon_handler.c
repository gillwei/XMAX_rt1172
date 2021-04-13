

/*********************************************************************
* @file
* mm_mototcon_handler.c
*
* @brief
* Media manager module - motocon music handler
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "task.h"
#include "fsl_debug_console.h"
#include "EW_pub.h"
#include "MM_pub.h"
#include "MM_pub_ams_type.h"
#include "mm_priv.h"
#include "BC_motocon_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
void MM_receive_music_info( const bc_motocon_bt_music_meta_data_t* music_meta_data );

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/
static bc_motocon_callback_t music_callback =
    {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    MM_receive_music_info,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
    };

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @private
* MM_receive_music_info
*
* Receive music information from MotoCon SDK.
* @param music_meta_data meta data of music information.
*
*********************************************************************/
void MM_receive_music_info
    (
    const bc_motocon_bt_music_meta_data_t* music_meta_data
    )
{
mm_media_player_obj* media_player = NULL;
media_player = MM_ams_gatt_get_media_player_state();

// Copy data to media player object.
strncpy( media_player->str.track_artist, ( char* )music_meta_data->artist, MEDIA_STRING_MAX_LENGTH );
if( MEDIA_STRING_MAX_LENGTH > music_meta_data->artist_len )
    {
    media_player->str.track_artist[music_meta_data->artist_len] = '\0';
    }
else
    {
    media_player->str.track_artist[MEDIA_STRING_MAX_LENGTH-1] = '\0';
    }

strncpy( media_player->str.track_album, ( char* )music_meta_data->album, MEDIA_STRING_MAX_LENGTH );
if( MEDIA_STRING_MAX_LENGTH > music_meta_data->album_len )
    {
    media_player->str.track_album[music_meta_data->album_len] = '\0';
    }
else
    {
    media_player->str.track_album[MEDIA_STRING_MAX_LENGTH-1] = '\0';
    }

strncpy( media_player->str.track_title, ( char* )music_meta_data->song, MEDIA_STRING_MAX_LENGTH );
if( MEDIA_STRING_MAX_LENGTH > music_meta_data->song_len )
    {
    media_player->str.track_title[music_meta_data->song_len] = '\0';
    }
else
    {
    media_player->str.track_title[MEDIA_STRING_MAX_LENGTH-1] = '\0';
    }

media_player->duration_sec = music_meta_data->duration_time;
if( ( music_meta_data->duration_time - media_player->duration_sec ) >= 0.5 )
    {
    media_player->duration_sec++;
    }

EW_notify_motocon_music_info_changed();
}

/*********************************************************************
*
* @public
* mm_motocon_init
*
* Media manager module - Init.
*
*********************************************************************/
void mm_motocon_init
    (
    void
    )
{
BC_motocon_register_callback( &music_callback );
}
