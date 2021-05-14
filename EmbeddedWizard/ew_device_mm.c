/*********************************************************************
* @file
* ew_device_mm.c
*
* @brief
* EW module - Media manager related device interface implementation
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "ewrte.h"
#include "ew_bsp_inout.h"
#include "ew_bsp_clock.h"
#include "ew_bsp_event.h"
#include "ew_priv.h"
#include "DeviceInterface.h"
#include <string.h>
#include <stdbool.h>
#include "MM_pub.h"
#include "MM_pub_ams_type.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/

#ifdef _DeviceInterfaceMediaManagerDeviceClass_
    typedef int mm_device_function( void );
#endif

#ifdef _DeviceInterfaceMediaManagerDeviceClass__NotifyTitleChanged_
    static int ew_notify_title_changed( void );
#endif

#ifdef _DeviceInterfaceMediaManagerDeviceClass__NotifyAlbumChanged_
    static int ew_notify_album_changed( void );
#endif

#ifdef _DeviceInterfaceMediaManagerDeviceClass__NotifyArtistChanged_
    static int ew_notify_artist_changed( void );
#endif

#ifdef _DeviceInterfaceMediaManagerDeviceClass__NotifyPlayBackTimeChanged_
    static int ew_notify_playback_time_changed( void );
#endif

#ifdef _DeviceInterfaceMediaManagerDeviceClass__NotifyAmsBleConnectedStatusChanged_
    static int ew_notify_ams_connected_status_changed( void );
#endif

#ifdef _DeviceInterfaceMediaManagerDeviceClass__NotfiyMotoConMusicInfoUpdated_
    static int ew_notify_motocon_music_info_changed( void );
#endif

#ifdef _DeviceInterfaceMediaManagerDeviceClass__NotifyMediaVolumeUpdated_
    static int ew_notify_volume_info_changed( void );
#endif

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
#ifdef _DeviceInterfaceMediaManagerDeviceClass_
    static DeviceInterfaceMediaManagerDeviceClass device_object = 0;

    static int is_title_changed = 0;
    static int is_album_changed = 0;
    static int is_artist_changed = 0;
    static int is_playback_time_changed = 0;
    static int is_ams_ble_connected = 0;
    static int is_motocon_music_info_changed = 0;
    static int is_volume_changed = 0;

    mm_device_function* const mm_function_lookup_table[] =
        {
        #ifdef _DeviceInterfaceMediaManagerDeviceClass__NotifyTitleChanged_
            ew_notify_title_changed,
        #endif
        #ifdef _DeviceInterfaceMediaManagerDeviceClass__NotifyAlbumChanged_
            ew_notify_album_changed,
        #endif
        #ifdef _DeviceInterfaceMediaManagerDeviceClass__NotifyArtistChanged_
            ew_notify_artist_changed,
        #endif
        #ifdef _DeviceInterfaceMediaManagerDeviceClass__NotifyPlayBackTimeChanged_
            ew_notify_playback_time_changed,
        #endif
        #ifdef _DeviceInterfaceMediaManagerDeviceClass__NotifyAmsBleConnectedStatusChanged_
            ew_notify_ams_connected_status_changed,
        #endif
        #ifdef _DeviceInterfaceMediaManagerDeviceClass__NotfiyMotoConMusicInfoUpdated_
            ew_notify_motocon_music_info_changed,
        #endif
        #ifdef _DeviceInterfaceMediaManagerDeviceClass__NotifyMediaVolumeUpdated_
            ew_notify_volume_info_changed
        #endif
        };

    const int num_of_mm_func = sizeof( mm_function_lookup_table )/sizeof( mm_device_function* );
#endif

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
/*********************************************************************
*
* @private
* ew_device_mm_init
*
* Embedded Wizard Media manager device interface initialization
*
*********************************************************************/
void ew_device_mm_init
    (
    void
    )
{
#ifdef _DeviceInterfaceMediaManagerDeviceClass_
     /*
       Get access to the counterpart of this device driver: get access to the
       device class that is created as autoobject within your Embedded Wizard
       project. For this purpose you can call the function EwGetAutoObject().
       This function contains two paramters: The pointer to the autoobject and
       the class of the autoobject.
       Assuming you have implemented the class 'DeviceClass' within the unit
       'Application' and you have an autoobject with the name 'Device', make
       the following call:
       EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass );
    */
    device_object = EwGetAutoObject( &DeviceInterfaceMediaManagerDevice, DeviceInterfaceMediaManagerDeviceClass );
    /*
       Once you have the access to the autoobject, lock it as long as you need
       the access (typically, until your device driver is closed). By locking
       the autoobject, you can ensure that the object of the device class will
       be kept within the memory and not freed by the Garbage Collector.
       Once the device class is locked, you can easily store it within a static
       variable to access the driver class during the runtime.
    */
    EwLockObject( device_object );
#endif
}

/*********************************************************************
*
* @private
* ew_device_mm_deinit
*
* Embedded Wizard Media manager device interface de-initialization
*
*********************************************************************/
void ew_device_mm_deinit
    (
    void
    )
{
#ifdef _DeviceInterfaceMediaManagerDeviceClass_
    if( device_object )
        {
        EwUnlockObject( device_object );
        }
    device_object = 0;
#endif
}

/*********************************************************************
*
* @private
* ew_device_mm_proc
*
* Select the function from media manager function table and execute it.
*
*********************************************************************/
int ew_device_mm_proc
    (
    void
    )
{
int need_update = 0;

#ifdef _DeviceInterfaceMediaManagerDeviceClass_
    if( device_object == 0 ||
        num_of_mm_func == 0 )
        {
        return 0;
        }

    for( int i = 0; i < num_of_mm_func; i++ )
        {
        if( mm_function_lookup_table[i]() )
            {
            need_update = 1;
            }
        }
#endif
return need_update;
}

/*********************************************************************
*
* @private
* ew_notify_title_changed
*
* Notify title of track to EW GUI.
*
*********************************************************************/
#ifdef _DeviceInterfaceMediaManagerDeviceClass__NotifyTitleChanged_
static int ew_notify_title_changed
    (
    void
    )
{
int need_update = 0;
if( is_title_changed )
    {
    is_title_changed = 0;
    mm_media_player_obj* media_player = NULL;
    media_player = MM_ams_gatt_get_media_player_state();
    XString xstring_title = EwNewStringUtf8( ( const unsigned char* )media_player->str.track_title, ( int )strlen( media_player->str.track_title ) );
    DeviceInterfaceMediaManagerDeviceClass__NotifyTitleChanged( device_object, xstring_title );
    need_update = 1;
    }
return need_update;
}
#endif

/*********************************************************************
*
* @private
* ew_notify_album_changed
*
* Notify album to EW GUI.
*
*********************************************************************/
#ifdef _DeviceInterfaceMediaManagerDeviceClass__NotifyAlbumChanged_
static int ew_notify_album_changed
    (
    void
    )
{
int need_update = 0;
if( is_album_changed )
    {
    is_album_changed = 0;
    mm_media_player_obj* media_player = NULL;
    media_player = MM_ams_gatt_get_media_player_state();
    XString xstring_album = EwNewStringUtf8( ( const unsigned char* )media_player->str.track_album, ( int )strlen( media_player->str.track_album ) );
    DeviceInterfaceMediaManagerDeviceClass__NotifyAlbumChanged( device_object, xstring_album );
    need_update = 1;
    }
return need_update;
}
#endif

/*********************************************************************
*
* @private
* ew_notify_artist_changed
*
* Notify artist name to EW GUI.
*
*********************************************************************/
#ifdef _DeviceInterfaceMediaManagerDeviceClass__NotifyArtistChanged_
static int ew_notify_artist_changed
    (
    void
    )
{
int need_update = 0;
if( is_artist_changed )
    {
    is_artist_changed = 0;
    mm_media_player_obj* media_player = NULL;
    media_player = MM_ams_gatt_get_media_player_state();
    XString xstring_artist = EwNewStringUtf8( ( const unsigned char* )media_player->str.track_artist, ( int )strlen( media_player->str.track_artist ) );
    DeviceInterfaceMediaManagerDeviceClass__NotifyArtistChanged( device_object, xstring_artist );
    need_update = 1;
    }
return need_update;
}
#endif

/*********************************************************************
*
* @private
* ew_notify_playback_time_changed
*
* Notify elapsed time/duration to EW GUI.
*
*********************************************************************/
#ifdef _DeviceInterfaceMediaManagerDeviceClass__NotifyPlayBackTimeChanged_
static int ew_notify_playback_time_changed
    (
    void
    )
{
int need_update = 0;
if( is_playback_time_changed )
    {
    is_playback_time_changed = 0;
    mm_media_player_obj* media_player = NULL;
    media_player = MM_ams_gatt_get_media_player_state();
    DeviceInterfaceMediaManagerDeviceClass__NotifyPlayBackTimeChanged( device_object, media_player->current_elapsed_time_sec, media_player->duration_sec );
    need_update = 1;
    }
return need_update;
}
#endif

/*********************************************************************
*
* @private
* ew_notify_ams_connected_status_changed
*
* Notify music info received from MotoCon SDK to EW GUI.
*
*********************************************************************/
#ifdef _DeviceInterfaceMediaManagerDeviceClass__NotifyAmsBleConnectedStatusChanged_
static int ew_notify_ams_connected_status_changed
    (
    void
    )
{
int need_update = 0;
if( is_ams_ble_connected )
    {
    is_ams_ble_connected = 0;
    DeviceInterfaceMediaManagerDeviceClass__NotifyAmsBleConnectedStatusChanged( device_object );
    need_update = 1;
    }
return need_update;
}
#endif

/*********************************************************************
*
* @private
* ew_notify_motocon_music_info_changed
*
* Notify music info received from MotoCon SDK to EW GUI.
*
*********************************************************************/
#ifdef _DeviceInterfaceMediaManagerDeviceClass__NotfiyMotoConMusicInfoUpdated_
static int ew_notify_motocon_music_info_changed
    (
    void
    )
{
int need_update = 0;
if( is_motocon_music_info_changed )
    {
    is_motocon_music_info_changed = 0;
    DeviceInterfaceMediaManagerDeviceClass__NotfiyMotoConMusicInfoUpdated( device_object );
    need_update = 1;
    }
return need_update;
}
#endif

/*********************************************************************
*
* @private
* ew_notify_volume_info_changed
*
* Notify volume info received from AMS/MotoCon SDK to EW GUI.
*
*********************************************************************/
#ifdef _DeviceInterfaceMediaManagerDeviceClass__NotifyMediaVolumeUpdated_
static int ew_notify_volume_info_changed
    (
    void
    )
{
int need_update = 0;
if( is_volume_changed )
    {
    is_volume_changed = 0;
    DeviceInterfaceMediaManagerDeviceClass__NotifyMediaVolumeUpdated( device_object );
    need_update = 1;
    }
return need_update;
}
#endif

/*********************************************************************
*
* @private
* ew_get_media_player_state
*
* Obtain media player state data.
* @return media player state data.
*
*********************************************************************/
mm_media_player_obj* ew_get_media_player_state
    (
    void
    )
{
return MM_ams_gatt_get_media_player_state();
}

/*********************************************************************
*
* @private
* ew_send_command
*
* Send a user command executed in EW GUI.
*
* @param command Ams remote command type.
*
*********************************************************************/
void ew_send_command
    (
    ams_remote_command command
    )
{
EwPrint( "%s: MM_send_command: %d\r\n", __FUNCTION__, command );
if( !MM_send_command( command ) )
    {
    EwPrint( "Send command Failed in MM_send_command\r\n" );
    }
}

/*********************************************************************
*
* @public
* EW_notify_title_changed
*
* Inform EW GUI the song tile is changed
*
*********************************************************************/
void EW_notify_title_changed
    (
    void
    )
{
#ifdef _DeviceInterfaceMediaManagerDeviceClass_
    is_title_changed = 1;
    EwBspEventTrigger();
#endif
}

/*********************************************************************
*
* @public
* EW_notify_album_changed
*
* Inform EW GUI the album is changed
*
*********************************************************************/
void EW_notify_album_changed
    (
    void
    )
{
#ifdef _DeviceInterfaceMediaManagerDeviceClass_
    is_album_changed = 1;
    EwBspEventTrigger();
#endif
}

/*********************************************************************
*
* @public
* EW_notify_artist_changed
*
* Inform EW GUI the artist is changed
*
*********************************************************************/
void EW_notify_artist_changed
    (
    void
    )
{
#ifdef _DeviceInterfaceMediaManagerDeviceClass_
    is_artist_changed = 1;
    EwBspEventTrigger();
#endif
}

/*********************************************************************
*
* @public
* EW_notify_playback_time_changed
*
* Inform EW GUI the playback time is changed
*
*********************************************************************/
void EW_notify_playback_time_changed
    (
    void
    )
{
#ifdef _DeviceInterfaceMediaManagerDeviceClass_
    is_playback_time_changed = 1;
    EwBspEventTrigger();
#endif
}

/*********************************************************************
*
* @public
* EW_notify_ams_ble_connected
*
* Inform EW GUI the AMS is connected.
*
*********************************************************************/
void EW_notify_ams_ble_connected
    (
    void
    )
{
#ifdef _DeviceInterfaceMediaManagerDeviceClass_
    is_ams_ble_connected = 1;
    EwBspEventTrigger();
#endif
}

/*********************************************************************
*
* @public
* EW_notify_motocon_music_info_changed
*
* Inform EW GUI the music info received via MotoCon SDK is changed
*
*********************************************************************/
void EW_notify_motocon_music_info_changed
    (
    void
    )
{
#ifdef _DeviceInterfaceMediaManagerDeviceClass_
    is_motocon_music_info_changed = 1;
    EwBspEventTrigger();
#endif
}

/*********************************************************************
*
* @public
* EW_notify_volume_changed
*
* Inform EW GUI the volume info is received.
*
*********************************************************************/
void EW_notify_volume_changed
    (
    void
    )
{
#ifdef _DeviceInterfaceMediaManagerDeviceClass_
    is_volume_changed = 1;
    EwBspEventTrigger();
#endif
}