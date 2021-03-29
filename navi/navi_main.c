/*********************************************************************
* @file
* navi_main.c
*
* @brief
* Navigation module - main
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "task.h"
#include "semphr.h"
#include "ewrte.h"
#include "fsl_debug_console.h"
#include "JPEG_pub.h"
#include "EW_pub.h"
#include "NAVI_pub.h"
#include "navi_priv.h"
#include "NAVILITE_pub.h"
#include "error_code.h"
#include <stdio.h>

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define MAX_TBT_SIZE            50

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
typedef bool ( *generic_fc_ptr )( void );
typedef bool ( *navi_preconnect )( navilite_callback_func_preconnected cb );
typedef bool ( *navi_connect )( navilite_callback_func_connected cb );
typedef bool ( *navi_disconnect )( navilite_callback_func_disconnected cb );
typedef bool ( *image_frame_update )( navilite_callback_func_imageframe cb );
typedef bool ( *current_road_update )( navilite_callback_func_currentroadname cb );
typedef bool ( *eta_update )( navilite_callback_func_eta cb );
typedef bool ( *day_night_update )( navilite_callback_func_daynightmode cb );
typedef bool ( *event_update )( navilite_callback_func_navieventtext cb );
typedef bool ( *navigation_status_update )( navilite_callback_func_navigationstatus cb );
typedef bool ( *speed_limit_update )( navilite_callback_func_speedlimit cb );
typedef bool ( *home_setting_update )( navilite_callback_func_homelocationsetting cb );
typedef bool ( *office_setting_update )( navilite_callback_func_officelocationsetting cb );
typedef bool ( *active_tbt_update )( navilite_callback_func_activetbtitem cb );
typedef bool ( *tbt_list_update )( navilite_callback_func_nexttbtlist cb );
typedef bool ( *esn_update )( navilite_callback_func_esn_sent cb );
typedef bool ( *route_cal_update )( navilite_callback_func_routecalcprogress cb );
typedef bool ( *zoom_level_update )( navilite_callback_func_zoomlevel cb );
typedef bool ( *dialog_event_update )( navilite_callback_func_dialogevent cb );
typedef bool ( *via_point_update )( navilite_callback_func_viapointcount cb );

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/
static generic_fc_ptr navi_funtion_table[NAVILITE_FUNC_CNT] =
    {
    (generic_fc_ptr)NAVILITE_register_update_callback_preconnected,
    (generic_fc_ptr)NAVILITE_register_update_callback_connected,
    (generic_fc_ptr)NAVILITE_register_update_callback_disconnected,
    (generic_fc_ptr)NAVILITE_register_update_callback_imageframe,
    (generic_fc_ptr)NAVILITE_register_update_callback_currentroadname,
    (generic_fc_ptr)NAVILITE_register_update_callback_eta,
    (generic_fc_ptr)NAVILITE_register_update_callback_daynightmode,
    (generic_fc_ptr)NAVILITE_register_update_callback_navieventtext,
    (generic_fc_ptr)NAVILITE_register_update_callback_navigationstatus,
    (generic_fc_ptr)NAVILITE_register_update_callback_speedlimit,
    (generic_fc_ptr)NAVILITE_register_update_callback_homelocationsetting,
    (generic_fc_ptr)NAVILITE_register_update_callback_officelocationsetting,
    (generic_fc_ptr)NAVILITE_register_update_callback_esn_sent,
    (generic_fc_ptr)NAVILITE_register_update_callback_routecalcprogress,
    (generic_fc_ptr)NAVILITE_register_update_callback_zoomlevel,
    (generic_fc_ptr)NAVILITE_register_update_callback_dialogevent,
    (generic_fc_ptr)NAVILITE_register_update_callback_viapointcount
    };

static navi_data_type navi_data_obj;
static navi_dialog_type navi_dialog_obj;
static bool is_navi_app_connected;
static bool is_navi_app_init_setting_completed;
/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @public
* NAVI_jpeg_decode_finished
*
* The callback function receiving the JPEG decode finished status
* from the JPEG module.
*
* @param result The result of JPEG decode.
*
*********************************************************************/
void NAVI_jpeg_decode_finished
    (
    int result
    )
{
PRINTF( "%s: %d\r\n", __FUNCTION__, result );
if( RESULT_SUCCESS == result )
    {
    EW_notify_navi_map_update();
    }
}

/*********************************************************************
*
* @public
* NAVI_get_navi_obj
*
* Get navi object.
*
*********************************************************************/
navi_data_type* NAVI_get_navi_obj
    (
    void
    )
{
return &navi_data_obj;
}

/*********************************************************************
*
* @private
* navi_image_frame_update
*
* Notify navigation module that image data(JPEG) is updated.
*
* @param image_addr Navilite JPEG buffer address
* @param image_size JPEG file size
* @param mode       Image type
*
*********************************************************************/
static void navi_image_frame_update
    (
    uint8_t* image_addr,
    uint16_t image_size,
    navilite_image_type mode
    )
{
PRINTF( "%s: size: %d, mode: %d\r\n", __FUNCTION__, image_size, mode );

if( image_size > 0 && JPEG_is_valid( image_addr, image_size ) )
    {
    uint8_t* jpeg_buf = (uint8_t*)JPEG_get_jpeg_buffer();
    if( NULL != jpeg_buf )
        {
        memcpy( jpeg_buf, image_addr, image_size );
        JPEG_notify_received( image_size, jpeg_buf, &NAVI_jpeg_decode_finished );
        }
    else
        {
        PRINTF( "%s, JPEG buffer is not available\r\n", __FUNCTION__ );
        }
    }
else
    {
    PRINTF( "%s, Invalid JPEG data\r\n", __FUNCTION__ );
    }
}

/*********************************************************************
*
* @private
* navi_cur_road_update
*
* Notify navigation module that current road is updated.
*
* @param road_name        The string of current road name.
* @param road_name_size   Size of current road name.
*
*********************************************************************/
static void navi_cur_road_update
    (
    uint8_t* road_name,
    uint8_t  road_name_size
    )
{
PRINTF( "%s: road name: %s, size: %d\r\n", __FUNCTION__, road_name, road_name_size );
strncpy( navi_data_obj.current_road, ( char* )road_name, MAX_ROAD_NAME_SIZE );
if( MAX_ROAD_NAME_SIZE > road_name_size )
    {
    navi_data_obj.current_road[road_name_size] = '\0';
    }
else
    {
    navi_data_obj.current_road[MAX_ROAD_NAME_SIZE-1] = '\0';
    }
EW_notify_current_road_update();
}

/*********************************************************************
*
* @private
* navi_eta_update
*
* Notify navigation module that ETA is updated.
*
* @param value  Value of ETA.
*
*********************************************************************/
static void navi_eta_update
    (
    uint32_t value
    )
{
PRINTF( "%s: ETA: %d\r\n", __FUNCTION__, value );
navi_data_obj.eta = value;
EW_notify_eta_update();
}

/*********************************************************************
*
* @private
* navi_esn_update
*
* Notify navigation module that navi app has received ESN.
*
*********************************************************************/
static void navi_esn_update
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
if( true == NAVILITE_request_app_start_imageframe_update() )
    {
    PRINTF( "%s, Send image frame request\r\n", __FUNCTION__ );
    }
else
    {
    PRINTF( "%s, Fail to send image frame request\r\n", __FUNCTION__ );
    is_navi_app_init_setting_completed = false;
    }
}

/*********************************************************************
*
* @private
* navi_preconnect_update
*
* Notify navigation module that navi app is preconnect.
*
*********************************************************************/
static void navi_preconnect_update
    (
    uint8_t mode
    )
{
PRINTF( "%s: %d\r\n", __FUNCTION__, mode );
uint32_t esn = EW_get_esn();
char esn_decimal[ESN_STR_MAX_LEN + 1];
sprintf( esn_decimal, "%010u", esn );
NAVILITE_report_app_esn( ( uint8_t* )esn_decimal );
}

/*********************************************************************
*
* @private
* navi_connect_update
*
* Notify navigation module that navi app is connected.
*
*********************************************************************/
static void navi_connect_update
    (
    uint8_t mode
    )
{
PRINTF( "%s: %d\r\n", __FUNCTION__, mode );
is_navi_app_connected = false;
if( NAVILITE_CONN_TBD != mode )
    {
    is_navi_app_connected = true;
    is_navi_app_init_setting_completed = true;
    }
}

/*********************************************************************
*
* @private
* navi_disconnect_update
*
* Notify navigation module that navi app is disconnected.
*
*********************************************************************/
static void navi_disconnect_update
    (
    uint8_t mode
    )
{
PRINTF( "%s: %d\r\n", __FUNCTION__, mode );
is_navi_app_connected = false;
is_navi_app_init_setting_completed = false;
}

/*********************************************************************
*
* @private
* navi_speed_limit_update
*
* Notify navigation module that speed limit is updated.
*
* @param spd_lmt  Value of speed limit.
*
*********************************************************************/
static void navi_speed_limit_update
    (
    uint16_t spd_lmt
    )
{
PRINTF( "%s: Speed Limit: %d\r\n", __FUNCTION__, spd_lmt );
navi_data_obj.speed_limit = spd_lmt;
EW_notify_speed_limit_update();
}

/*********************************************************************
*
* @private
* navi_day_night_update
*
* Notify navigation module that daynight mode is updated.
*
* @param dn_mode  Value of daynight mode.
*
*********************************************************************/
static void navi_day_night_update
    (
    navilite_daynight_type dn_mode
    )
{
PRINTF( "%s: Day night mode : %d\r\n", __FUNCTION__, dn_mode );
navi_data_obj.daynight = dn_mode;
EW_notify_daynight_mode_update();
}

/*********************************************************************
*
* @private
* navi_event_update
*
* Notify navigation module that navigation event is updated.
*
* @param str                        Navigation event text.
* @param str_size                   Size of navigation event text.
* @param navi_event_type            Navigation event type.
* @param navi_evnt_extra_subtype    Extra type of navigation event.
* @param visibility                 The visibility of navigation event.
*
*********************************************************************/
static void navi_event_update
    (
    uint8_t* str,
    uint8_t str_size,
    navilite_navievent_type navi_evnt_type,
    navilite_navievent_camera_extra_subtype navi_evnt_extra_subtype,
    uint8_t visibility
    )
{
PRINTF( "%s: Event update: %s, %d, %d, %d, %d\r\n", __FUNCTION__, str, str_size, navi_evnt_type, navi_evnt_extra_subtype, visibility );
if( NULL != str )
    {
    navi_send_event_to_queue( str, str_size, navi_evnt_type, navi_evnt_extra_subtype, visibility );
    }
else
    {
    PRINTF( "%s: Event content is empty\r\n", __FUNCTION__ );
    }
}

/*********************************************************************
*
* @private
* navi_navigation_status_update
*
* Notify navigation module if route guidance is started or not.
*
* @param is_navigating The status of route guidance.
*
*********************************************************************/
static void navi_navigation_status_update
    (
    uint8_t is_navigating
    )
{
PRINTF( "%s: Is route guidance started : %d\r\n", __FUNCTION__, is_navigating );
navi_data_obj.is_navigating = is_navigating;

EW_notify_navigating_status_update();
}

/*********************************************************************
*
* @private
* navi_home_setting_update
*
* Notify navigation module if Home is set or not.
*
* @param is_home_set  variable indicates home is set or not.
*
*********************************************************************/
static void navi_home_setting_update
    (
    uint8_t is_home_set
    )
{
PRINTF( "%s: Home location : %d\r\n", __FUNCTION__, is_home_set );
EW_notify_home_setting_update( is_home_set );
}

/*********************************************************************
*
* @private
* navi_office_setting_update
*
* Notify navigation module if Office is set or not.
*
* @param is_office_set  variable indicates office is set or not.
*
*********************************************************************/
static void navi_office_setting_update
    (
    uint8_t is_office_set
    )
{
PRINTF( "%s: Office location : %d\r\n", __FUNCTION__, is_office_set );
EW_notify_office_setting_update( is_office_set );
}

/*********************************************************************
*
* @private
* navi_route_cal_update
*
* Notify navigation module that the route calculation progress is updated.
*
* @param progress  variable indicates the route calculation progress.
*
*********************************************************************/
static void navi_route_cal_update
    (
    uint8_t progress
    )
{
PRINTF( "%s: Route calculation progress : %d\r\n", __FUNCTION__, progress );
navi_data_obj.route_cal_progress = progress;
EW_notify_route_cal_progress_update();
}

/*********************************************************************
*
* @private
* navi_zoom_level_update
*
* Notify navigation module that the zoom level is updated.
*
* @param current_level  variable indicates the current zoom level.
* @param max_level      variable indicates the maximum zoom level.
*
*********************************************************************/
static void navi_zoom_level_update
    (
    uint8_t current_level,
    uint8_t max_level
    )
{
PRINTF( "%s: Zoom level is updated: %d, %d\r\n", __FUNCTION__, current_level, max_level );
if( current_level == max_level )
    {
    EW_notify_zoom_level_update( false );
    }
else if( current_level == 0 )
    {
    EW_notify_zoom_level_update( false );
    }
else
    {
    EW_notify_zoom_level_update( true );
    }
}

/*********************************************************************
*
* @private
* navi_dialog_event_update
*
* Notify navigation module that the dialog event is updated.
*
* @param dialog_id      Dialog id.
* @param dialog_type    Type of dialog.
* @param message        Dialog message.
* @param message_size   Size of dialog message.
*
*********************************************************************/
static void navi_dialog_event_update
    (
    uint8_t dialog_id,
    navilite_dialog_type dialog_type,
    uint8_t* message,
    uint8_t message_size
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );

navi_dialog_obj.dialog_id = dialog_id;
navi_dialog_obj.dialog_type = dialog_type;
strncpy( navi_dialog_obj.dialog_message, ( char* )message, MAX_DIALOG_DESCRIPTION_SIZE );
if( MAX_DIALOG_DESCRIPTION_SIZE > message_size )
    {
    navi_data_obj.current_road[message_size] = '\0';
    }
else
    {
    navi_data_obj.current_road[MAX_DIALOG_DESCRIPTION_SIZE-1] = '\0';
    }
EW_notify_dialog_event_update();
}

/*********************************************************************
*
* @private
* navi_via_point_update
*
* Notify navigation module that the via point is updated.
*
* @param via_point_count number of current via point count.
*
*********************************************************************/
static void navi_via_point_update
    (
    uint8_t via_point_count
    )
{
PRINTF( "%s: Number of via point : %d\r\n", __FUNCTION__, via_point_count );

}

/*********************************************************************
*
* @private
* navi_active_tbt_update
*
* Notify navigation module that active tbt item is updated.
*
* @param index  The index of active tbt item.
*
*********************************************************************/
static void navi_active_tbt_update
    (
    uint8_t index
    )
{
//TODO: Wait for navilite protocol to support this function.
PRINTF( "%s: Active TBT index : %d\r\n", __FUNCTION__, index );
if( MAX_TBT_SIZE > index )
    {
    EW_notify_active_tbt_item_update( index );
    }
else
    {
    PRINTF( "%s: Invalid active TBT index\r\n", __FUNCTION__ );
    }
}

/*********************************************************************
*
* @private
* navi_next_turn_dist_update
*
* Notify navigation module that next turn distance is updated.
*
* @param icon_index            Index of Tbt icon.
* @param next_turn_dist        String of next turn distance.
* @param dist_size             Size of next turn distance string.
*
*********************************************************************/
static void navi_next_turn_dist_update
    (
    uint8_t icon_index,
    uint8_t* next_turn_dist,
    uint8_t dist_size
    )
{
PRINTF( "%s: Next turn index:%d, Next turn dist: %s, Size:%d \r\n", __FUNCTION__, icon_index, next_turn_dist, dist_size );
}

/*********************************************************************
*
* @private
* navi_tbt_list_update
*
* Notify navigation module that TBT list is updated.
*
* @param list_addr   TBT list address.
* @param list_size   TBT list size.
*
*********************************************************************/
static void navi_tbt_list_update
    (
    navilite_tbt_list_type *list_addr,
    uint8_t list_size
    )
{
//TODO: Wait for navilite protocol to support this function.
PRINTF( "%s: Size:%d \r\n", __FUNCTION__, list_size );
}

/*********************************************************************
*
* @public
* NAVI_get_navigation_status
*
* Obtain navigation status
*
*********************************************************************/
bool NAVI_get_navigation_status
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
return navi_data_obj.is_navigating? true : false;
}

/*********************************************************************
*
* @public
* NAVI_get_dialog_type
*
* Obtain navi dialog type.
*
*********************************************************************/
EnumNaviDialogType NAVI_get_dialog_type
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
EnumNaviDialogType navi_dialog_type;
switch( navi_dialog_obj.dialog_type )
    {
    case NAVILITE_DIALOGTYPE_OK:
        navi_dialog_type = EnumNaviDialogTypeDIALOG_OK;
        break;
    case NAVILITE_DIALOGTYPE_OK_CANCEL:
        navi_dialog_type = EnumNaviDialogTypeDIALOG_OK_CANCEL;
        break;
    case NAVILITE_DIALOGTYPE_YES_NO:
        navi_dialog_type = EnumNaviDialogTypeDIALOG_YES_NO;
        break;
    case NAVILITE_DIALOGTYPE_YES_NO_CANCEL:
        navi_dialog_type = EnumNaviDialogTypeDIALOG_YES_NO_CANCEL;
        break;
    case NAVILITE_DIALOGTYPE_DISMISS_DIALOG:
        navi_dialog_type = EnumNaviDialogTypeDIALOG_DISMISS;
        break;
    default:
        PRINTF( "%s: Unknown dialog type\r\n", __FUNCTION__ );
        break;
    }
return navi_dialog_type;
}

/*********************************************************************
*
* @public
* NAVI_get_dialog_message
*
* Obtain the content of dialog
*
*********************************************************************/
void NAVI_get_dialog_message
    (
    char** dialog_message
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
*dialog_message = navi_dialog_obj.dialog_message;
}

/*********************************************************************
*
* @public
* NAVI_stop_map_update
*
* Stop map update
*
*********************************************************************/
void NAVI_stop_map_update
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
NAVILITE_request_app_stop_imageframe_update();
}

/*********************************************************************
*
* @public
* NAVI_send_stop_route_request
*
* Send stop route request.
*
*********************************************************************/
void NAVI_send_stop_route_request
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
NAVILITE_request_app_stoproute();
}

/*********************************************************************
*
* @public
* NAVI_send_skip_next_waypoint_request
*
* Send skip next waypoint request.
*
*********************************************************************/
void NAVI_send_skip_next_waypoint_request
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
NAVILITE_request_app_skip_nextwaypoint();
}

/*********************************************************************
*
* @public
* NAVI_get_connect_status
*
* Get navi app connect status
*
*********************************************************************/
bool NAVI_get_connect_status
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
return is_navi_app_connected;
}

/*********************************************************************
*
* @public
* NAVI_get_navi_app_setup_status
*
* Get navi app setup status
*
*********************************************************************/
bool NAVI_get_navi_app_setup_status
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
return is_navi_app_init_setting_completed;
}

/*********************************************************************
*
* @public
* NAVI_send_go_home_request
*
* Send go home request.
*
*********************************************************************/
void NAVI_send_go_home_request
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
NAVILITE_request_app_gohome();
}

/*********************************************************************
*
* @public
* NAVI_send_go_office_request
*
* Send go office request.
*
*********************************************************************/
void NAVI_send_go_office_request
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
NAVILITE_request_app_gooffice();
}

/*********************************************************************
*
* @public
* NAVI_send_zoom_in_request
*
* Send zoom in request.
*
*********************************************************************/
void NAVI_send_zoom_in_request
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
NAVILITE_request_app_zoomin();
}

/*********************************************************************
*
* @public
* NAVI_send_zoom_out_request
*
* Send zoom out request.
*
*********************************************************************/
void NAVI_send_zoom_out_request
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
NAVILITE_request_app_zoomout();
}

/*********************************************************************
*
* @public
* NAVI_send_selected_dialog
*
* Send selected dialog id and its type
*
* @param button_type Type of button on the selected dialog.
*
*********************************************************************/
void NAVI_send_selected_dialog
    (
    EnumNaviButtonType button_type
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
NAVILITE_report_app_dialog_select( navi_dialog_obj.dialog_id, (navilite_button_type)button_type );
}

/*********************************************************************
*
* @public
* NAVI_init
*
* Initialize navigation module
*
*********************************************************************/
void NAVI_init
    (
    void
    )
{
bool result;
navi_event_init();

for( int i = 0; i < NAVILITE_FUNC_CNT; i++ )
    {
    switch( i )
        {
        case NAVILITE_FUNC_PRECONNECT:
            result = ( (navi_preconnect)navi_funtion_table[i] )( navi_preconnect_update );
            break;
        case NAVILITE_FUNC_CONNECT:
            result = ( (navi_connect)navi_funtion_table[i] )( navi_connect_update );
            break;
        case NAVILITE_FUNC_DISCONNECT:
            result = ( (navi_disconnect)navi_funtion_table[i] )( navi_disconnect_update );
            break;
        case NAVILITE_FUNC_IMAGE_FRAME_UPDATE:
            result = ( (image_frame_update)navi_funtion_table[i] )( navi_image_frame_update );
            break;
        case NAVILITE_FUNC_CURRENT_ROAD_UPDATE:
            result = ( (current_road_update)navi_funtion_table[i] )( navi_cur_road_update );
            break;
        case NAVILITE_FUNC_ETA_UPDATE:
            result = ( (eta_update)navi_funtion_table[i] )( navi_eta_update );
            break;
        case NAVILITE_FUNC_DAY_NIGHT_UPDATE:
            result = ( (day_night_update)navi_funtion_table[i] )( navi_day_night_update );
            break;
        case NAVILITE_FUNC_NAVI_EVENT_UPDATE:
            result = ( (event_update)navi_funtion_table[i] )( navi_event_update );
            break;
        case NAVILITE_FUNC_NAVIGATION_STATUS:
            result = ( (navigation_status_update)navi_funtion_table[i] )( navi_navigation_status_update );
            break;
        case NAVILITE_FUNC_SPEED_LIMIT_UPDATE:
            result = ( (speed_limit_update)navi_funtion_table[i] )( navi_speed_limit_update );
            break;
        case NAVILITE_FUNC_HOME_SETTING_UPDATE:
            result = ( (home_setting_update)navi_funtion_table[i] )( navi_home_setting_update );
            break;
        case NAVILITE_FUNC_OFFICE_SETTING_UPDATE:
            result = ( (office_setting_update)navi_funtion_table[i] )( navi_office_setting_update );
            break;
        case NAVILITE_FUNC_ESN_UPDATE:
            result = ( (esn_update)navi_funtion_table[i] )( navi_esn_update );
            break;
        case NAVILITE_FUNC_ROUTE_CAL_UPDATE:
            result = ( (route_cal_update)navi_funtion_table[i] )( navi_route_cal_update );
            break;
        case NAVILITE_FUNC_ZOOM_LEVEL_UPDATE:
            result = ( (zoom_level_update)navi_funtion_table[i] )( navi_zoom_level_update );
            break;
        case NAVILITE_FUNC_DIALOG_EVENT_UPDATE:
            result = ( (dialog_event_update)navi_funtion_table[i] )( navi_dialog_event_update );
            break;
        case NAVILITE_FUNC_VIA_POINT_UPDATE:
            result = ( (via_point_update)navi_funtion_table[i] )( navi_via_point_update );
            break;
        default:
            PRINTF( "Unexpected navilite function.\r\n" );
            break;
        }
    if( !result )
        {
        PRINTF( "navilite function registration is failed.\r\n" );
        }
    }
}

