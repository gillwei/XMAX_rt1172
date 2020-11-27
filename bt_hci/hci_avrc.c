/*********************************************************************
* @file
* hci_avrc.c
*
* This file includes the functions which handle AVRC controller events
* and avrc controller commands.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "HCI_pub.h"
#include "hci_control_api.h"
#include "fsl_debug_console.h"

#include "MM_pub.h"
#include "MM_pub_ams_type.h"
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

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @public
* HCI_avrc_play
*
* Send AVRC play command.
*
*********************************************************************/
void HCI_avrc_play
    (
    void
    )
{
uint16_t command = HCI_CONTROL_AVRC_CONTROLLER_COMMAND_PLAY;
uint8_t  handle[2] = {0x0, 0x0};
HCI_wiced_send_command( command, handle, 2 );
}

/*********************************************************************
*
* @public
* HCI_avrc_pause
*
* Send AVRC pause command.
*
*********************************************************************/
void HCI_avrc_pause
    (
    void
    )
{
uint16_t command = HCI_CONTROL_AVRC_CONTROLLER_COMMAND_PAUSE;
uint8_t  handle[2] = {0x0, 0x0};
HCI_wiced_send_command( command, handle, 2 );
}

/*********************************************************************
*
* @public
* HCI_avrc_play_next_track
*
* Send AVRC next track command.
*
*********************************************************************/
void HCI_avrc_play_next_track
    (
    void
    )
{
uint16_t command = HCI_CONTROL_AVRC_CONTROLLER_COMMAND_NEXT_TRACK;
uint8_t  handle[2] = {0x0, 0x0};
HCI_wiced_send_command( command, handle, 2 );
}

/*********************************************************************
*
* @public
* HCI_avrc_play_previous_track
*
* Send AVRC previous track command.
*
*********************************************************************/
void HCI_avrc_play_previous_track
    (
    void
    )
{
uint16_t command = HCI_CONTROL_AVRC_CONTROLLER_COMMAND_PREVIOUS_TRACK;
uint8_t  handle[2] = {0x0, 0x0};
HCI_wiced_send_command( command, handle, 2 );
}

/*********************************************************************
*
* @private
* hci_avrc_event_handler
*
* Processes all incoming AVRC events.
*
* @param event  The events received from UART
* @param opcode HCI packet ID
* @param length Data payload size
* @param data   Extracted payload data
*
*********************************************************************/
void hci_avrc_event_handler
    (
    const uint16_t opcode,
    const uint16_t length,
    const uint8_t* data
    )
{
int32_t elapsed_time_sec = 0;
uint8_t attribute_string[MEDIA_STRING_MAX_LENGTH];
int     attribute_len = 0;

switch( opcode )
    {
    case HCI_CONTROL_AVRC_CONTROLLER_EVENT_CONNECTED:
        PRINTF( "avrc connected\r\n" );
        break;

    case HCI_CONTROL_AVRC_CONTROLLER_EVENT_DISCONNECTED:
        PRINTF( "avrc disconnected\r\n" );
        break;

    case HCI_CONTROL_AVRC_CONTROLLER_EVENT_CURRENT_TRACK_INFO:
        {
        attribute_len = ( data[5] << 8 ) | data[4];

        // Since UI would not be able to display a very long track/album/artisit string,
        // We decide to cut off string if it's over maximum length.
        if( attribute_len >= MEDIA_STRING_MAX_LENGTH )
            {
            attribute_len = MEDIA_STRING_MAX_LENGTH;
            }

        memcpy( attribute_string, &data[6], attribute_len );
        attribute_string[attribute_len] = '\0';

        switch( data[3] )
            {
            case 1:
                PRINTF( "title: %s\r\n", attribute_string );
                MM_set_track_data( AMS_TRACK_ATTRIBUTE_ID_TITLE, attribute_len, attribute_string );
                break;
            case 2:
                PRINTF( "artist: %s\r\n", attribute_string );
                MM_set_track_data( AMS_TRACK_ATTRIBUTE_ID_ARTIST, attribute_len, attribute_string );
                break;
            case 3:
                PRINTF( "album name : %s\r\n", attribute_string );
                MM_set_track_data( AMS_TRACK_ATTRIBUTE_ID_ALBUM, attribute_len, attribute_string );
                break;
            case 4:
                PRINTF( "track number: %s\r\n", attribute_string );
                break;
            case 5:
                PRINTF( "number of tracks: %s\r\n", attribute_string );
                break;
            case 6:
                PRINTF( "genre: %s\r\n", attribute_string );
                break;
            case 7:
                PRINTF( "play time: %s\r\n", attribute_string );
                MM_set_track_data( AMS_TRACK_ATTRIBUTE_ID_DURATION, attribute_len, attribute_string );
                break;
            default:
                PRINTF( "invalid attribute id: %d\r\n", data[3] );
                break;
            }
        }
        break;

    case HCI_CONTROL_AVRC_CONTROLLER_EVENT_PLAY_STATUS:
        {
        switch( data[2] )
            {
            case 0:
                PRINTF( "stopped\r\n" );
                break;
            case 1:
                MM_set_playback_state( AMS_PLAYBACK_STATE_PLAYING );
                break;
            case 2:
                MM_set_playback_state( AMS_PLAYBACK_STATE_PAUSED );
                break;
            case 3:
                MM_set_playback_state( AMS_PLAYBACK_STATE_FAST_FORWARDING );
                break;
            case 4:
                MM_set_playback_state( AMS_PLAYBACK_STATE_REWINDING );
                break;
            default:
                PRINTF( "Unsupported Playback State: %d\r\n", data[2] );
                break;
            }
        }
        break;

    case HCI_CONTROL_AVRC_CONTROLLER_EVENT_PLAY_POSITION:
        {
        elapsed_time_sec = ( data[5] << 24 ) | ( data[4] << 16 ) | ( data[3] << 8 ) | data[2];
        PRINTF( "Received elapsed time in sec: %d\r\n", elapsed_time_sec );
        MM_set_elapsed_time( elapsed_time_sec );
        }
        break;

    case HCI_CONTROL_AVRC_CONTROLLER_EVENT_TRACK_CHANGE:
    case HCI_CONTROL_AVRC_CONTROLLER_EVENT_TRACK_END:
    case HCI_CONTROL_AVRC_CONTROLLER_EVENT_TRACK_START:
    case HCI_CONTROL_AVRC_CONTROLLER_EVENT_SETTING_AVAILABLE:
    case HCI_CONTROL_AVRC_CONTROLLER_EVENT_SETTING_CHANGE:
    case HCI_CONTROL_AVRC_CONTROLLER_EVENT_PLAYER_CHANGE:
    case HCI_CONTROL_AVRC_CONTROLLER_EVENT_PLAY_STATUS_INFO:
    case HCI_CONTROL_AVRC_CONTROLLER_EVENT_COMMAND_STATUS:
        break;

    default:
        PRINTF( "invalid opcode: %02x\r\n", opcode );
        break;
    }
}
