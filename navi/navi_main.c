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
#define APP_INIT_DONE               ( 1 )

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
typedef bool ( *esn_update )( navilite_callback_func_esn_sent cb );
typedef bool ( *route_cal_update )( navilite_callback_func_routecalcprogress cb );
typedef bool ( *zoom_level_update )( navilite_callback_func_zoomlevel cb );
typedef bool ( *dialog_event_update )( navilite_callback_func_dialogevent cb );
typedef bool ( *via_point_update )( navilite_callback_func_viapointcount cb );
typedef bool ( *next_turn_dist_update )( navilite_callback_func_nextturndistance cb );
typedef bool ( *active_tbt_item_update )( navilite_callback_func_activetbtitem cb );
typedef bool ( *tbt_list_update )( navilite_callback_func_nexttbtlist cb );
typedef bool ( *poi_list_update )( navilite_callback_func_nexttpoilist cb );
typedef bool ( *bt_throughput_update )( navilite_callback_func_content_mode_switch cb );
typedef bool ( *navi_init_setting_update )( navilite_callback_func_appsetting cb );

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
    (generic_fc_ptr)NAVILITE_register_update_callback_viapointcount,
    (generic_fc_ptr)NAVILITE_register_update_callback_nextturndistance,
    (generic_fc_ptr)NAVILITE_register_update_callback_activetbtlistitem,
    (generic_fc_ptr)NAVILITE_register_update_callback_tbtlist,
    (generic_fc_ptr)NAVILITE_register_update_callback_favlist,
    (generic_fc_ptr)NAVILITE_register_update_callback_gaslist,
    (generic_fc_ptr)NAVILITE_register_update_callback_content_mode_switch,
    (generic_fc_ptr)NAVILITE_register_update_callback_appsetting
    };

static navi_data_type navi_data_obj;
static bool is_navi_app_connected;
static bool is_navi_app_init;
static EnumNaviZoomInOutStatusType zoom_inout_status = EnumNaviZoomInOutStatusTypeNORMAL;
static EnumNaviBtThroughputUIMode navi_bt_throughput_ui_mode = EnumNaviBtThroughputUIModeTOTAL;

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
        navi_data_obj.image_type = mode;
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
PRINTF( "%s: road name: %s, size: %d\r\n", __FUNCTION__, (char*)road_name, road_name_size );
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
PRINTF( "%s: ESN: %s \r\n", __FUNCTION__, esn_decimal );
NAVILITE_report_app_esn( ( uint8_t* )esn_decimal );
}

/*********************************************************************
*
* @private
* navi_app_init_update
*
* Notify navigation module that navi app is initialized.
*
*********************************************************************/
static void navi_app_init_update
    (
    uint16_t app_setting_status
    )
{
PRINTF( "%s: %d\r\n", __FUNCTION__, app_setting_status );
int app_init_state = app_setting_status & ( 1 << 0 );
if( APP_INIT_DONE == app_init_state )
    {
    is_navi_app_init = true;
    }
else
    {
    is_navi_app_init = false;
    }
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
    EW_notify_connect_status_update();
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
EW_notify_disconnect_status_update();
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
    navilite_daynight_mode_type dn_mode
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
    navilite_navievent_extra_subtype navi_evnt_extra_subtype,
    uint8_t visibility
    )
{
PRINTF( "%s: Event update: %s, %d, %d, %d, %d\r\n", __FUNCTION__, (char*)str, str_size, navi_evnt_type, navi_evnt_extra_subtype, visibility );
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

// clean via point when route guidance is stopped.
// clean tbt buffer when route guidance is stopped.
if( 0 == navi_data_obj.is_navigating )
    {
    navi_data_obj.via_points = 0;
    NAVI_reset_tbt_buffer();
    }

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
navi_data_obj.is_home_set = is_home_set;
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
navi_data_obj.is_office_set = is_office_set;
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
* @param zoom_level_scale_str string of zoom level scale
* @param zoom_level_scale_str_size string size of zoom level scale
*
*********************************************************************/
static void navi_zoom_level_update
    (
    uint8_t current_level,
    uint8_t max_level,
    uint8_t* zoom_level_scale_str,
    uint8_t zoom_level_scale_str_size
    )
{
PRINTF( "%s: %d, %d, %s\r\n", __FUNCTION__, current_level, max_level, (char*)zoom_level_scale_str );

memcpy( navi_data_obj.zoom_level, zoom_level_scale_str, MAX_STR_SIZE );
if( zoom_level_scale_str_size < MAX_STR_SIZE )
    {
    navi_data_obj.zoom_level[zoom_level_scale_str_size] = '\0';
    }
else
    {
    navi_data_obj.zoom_level[MAX_STR_SIZE-1] = '\0';
    }

if( current_level == max_level )
    {
    zoom_inout_status = EnumNaviZoomInOutStatusTypeREACH_MAXIMUM;
    }
else if( current_level == 0 )
    {
    zoom_inout_status = EnumNaviZoomInOutStatusTypeREACH_MINIMUM;
    }
else
    {
    zoom_inout_status = EnumNaviZoomInOutStatusTypeNORMAL;
    }
EW_notify_zoom_level_update();
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
* @param timeout        Timeout.
* @param default_choice Default selected button.
*
*********************************************************************/
static void navi_dialog_event_update
    (
    uint8_t dialog_id,
    navilite_dialog_type dialog_type,
    uint8_t* message,
    uint8_t message_size,
    uint8_t timeout,
    uint8_t default_choice
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
navi_add_dialog( dialog_id, dialog_type, (char*)message, message_size, timeout, default_choice );
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
PRINTF( "%s: %d\r\n", __FUNCTION__, via_point_count );
navi_data_obj.via_points = via_point_count;
EW_notify_via_point_update();
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
    uint16_t active_tbt_index
    )
{
PRINTF( "%s: Active TBT index : %d\r\n", __FUNCTION__, active_tbt_index );
navi_update_active_tbt_item( active_tbt_index );
}

/*********************************************************************
*
* @private
* navi_next_turn_dist_update
*
* Notify navigation module that next turn distance is updated.
*
* @param icon_index            Index of Tbt icon.
* @param distance              Next turn distance
* @param unit_str              String of next turn distance unit
* @param unit_str_size         Size of next turn distance unit string.
*
*********************************************************************/
static void navi_next_turn_dist_update
    (
    uint8_t icon_index,
    uint32_t distance,
    uint8_t* unit_str,
    uint8_t unit_str_size
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );

navi_set_tbt_item( icon_index, distance, unit_str, unit_str_size );
}

/*********************************************************************
*
* @private
* navi_tbt_list_update
*
* Notify navigation module that TBT list is updated.
*
* @param action                         TBT update action type.
* @param list_item                      Received tbt list item.
* @param list_item_no                   The number of tbt list item.
* @param list_total_items               Total tbt list items for the received tbt list.
* @param list_total_items_recevied      Current index of received tbt item.
* @param has_more_items_on_next_request Indicates whether there are more tbt items after the received tbt list.
*
*********************************************************************/
static void navi_tbt_list_update
    (
    navilite_tbt_list_action_type action,
    navilite_tbt_list_type* list_item,
    uint16_t list_item_no,
    uint16_t list_total_items,
    uint16_t list_total_items_recevied,
    uint8_t has_more_items_on_next_request
    )
{
int result = ERR_NONE;
switch( action )
    {
    case NAVILITE_TBTLIST_ACTION_LISTSIZE:
        PRINTF( "%s: Tbt list size:%d \r\n", __FUNCTION__, list_total_items );
        navi_notify_more_tbt_item( has_more_items_on_next_request, list_total_items );
        break;
    case NAVILITE_TBTLIST_ACTION_ITEMADD:
        PRINTF( "%s: Tbt list item index:%d \r\n", __FUNCTION__, list_item->list_item_index );
        navi_add_tbt_item( list_item );
        break;
    default:
        PRINTF( "%s: Unexpected type\r\n", __FUNCTION__ );
        break;
    }
PRINTF( "%s: Result: %d\r\n", __FUNCTION__, result );
}

/*********************************************************************
*
* @private
* navi_poi_list_update
*
* Notify navigation module that Fav/Gas list is updated.
*
* @param action                         Poi list action type.
* @param list_item                      Received poi list item.
* @param list_item_no                   The number of poi list item.
* @param list_total_items               Total poi list items for the received poi list.
* @param list_total_items_recevied      Current index of received poi item.
* @param has_more_items_on_next_request Indicates whether there are more poi items after the received poi list.
*
*********************************************************************/
static void navi_poi_list_update
    (
    navilite_poi_list_action_type action,
    navilite_poi_list_type* list_item,
    uint16_t list_item_no,
    uint16_t list_total_items,
    uint16_t list_total_items_recevied,
    uint8_t has_more_items_on_next_request
    )
{
PRINTF( "%s \r\n", __FUNCTION__ );
switch( action )
    {
    case NAVILITE_POILIST_ACTION_LISTSIZE:
        PRINTF( "%s: Poi list size:%d \r\n", __FUNCTION__, list_total_items );
        navi_notify_more_poi_item( list_total_items );
        // If there is no favorite places/ gas stations, navi app only tells LC list size is 0 and no further data is sent.
        // In this case, notify UI and let UI show message indicates no data.
        if( 0 == list_total_items )
            {
            EW_notify_poi_list_update();
            }
        break;
    case NAVILITE_POILIST_ACTION_ITEMADD:
        PRINTF( "%s: List item size: %d \r\n", __FUNCTION__, list_item->desc_size );
        navi_add_poi_item( list_item );
        break;
    default:
        PRINTF( "%s: Unexpected type\r\n", __FUNCTION__ );
        break;
    }
}

/*********************************************************************
*
* @private
* navi_bt_throughput_update
*
* Notify navigation module that bt throughput is updated.
*
* @param mode                           Determine which UI should be displayed.
* @param throughput_timeout             Timeout
*
*********************************************************************/
static void navi_bt_throughput_update
    (
    navilite_content_mode_type mode,
    uint8_t throughput_timeout
    )
{
PRINTF( "%s, Mode: %d\r\n", __FUNCTION__, mode );
navi_bt_throughput_ui_mode = (EnumNaviBtThroughputUIMode)mode;
EW_notify_bt_throughput_status_update();
}

/*********************************************************************
*
* @public
* NAVI_is_Jcv_recevied
*
* Check if the received image frame is JCV or not.
*
*********************************************************************/
bool NAVI_is_Jcv_recevied
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
return ( navi_data_obj.image_type == NAVILITE_IMAGE_JCV )? true : false;
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
PRINTF( "%s: %d\r\n", __FUNCTION__, navi_data_obj.is_navigating );
return navi_data_obj.is_navigating? true : false;
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
* NAVI_start_map_update
*
* Start map update
*
*********************************************************************/
void NAVI_start_map_update
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
NAVILITE_request_app_start_imageframe_update();
}

/*********************************************************************
*
* @public
* NAVI_start_content_update
*
* Start content update. This is called when low bt throughput.
*
*********************************************************************/
void NAVI_start_content_update
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
NAVILITE_request_app_enable_content_update( NAVILITE_CONTENT_TYPE_NAVI_IMAGE_FOR_LOW_THROUGHPUT_MODE, true );
}

/*********************************************************************
*
* @public
* NAVI_stop_content_update
*
* Stop content update. This is called when low bt throughput.
*
*********************************************************************/
void NAVI_stop_content_update
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
NAVILITE_request_app_enable_content_update( NAVILITE_CONTENT_TYPE_NAVI_IMAGE_FOR_LOW_THROUGHPUT_MODE, false );
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
* NAVI_get_app_init_status
*
* Get navi app init status
*
*********************************************************************/
bool NAVI_get_app_init_status
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
return is_navi_app_init;
}

/*********************************************************************
*
* @public
* NAVI_get_zoom_inout_status
*
* Get the current zoom in/out button status
*
*********************************************************************/
EnumNaviZoomInOutStatusType NAVI_get_zoom_inout_status
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
return zoom_inout_status;
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
    EnumNaviRouteOptionType route_option_type
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
switch( route_option_type )
    {
    case EnumNaviRouteOptionTypeNEW_ROUTE:
        NAVILITE_request_app_gohome( NAVILITE_ROUTE_NEW_ROUTE );
        break;
    case EnumNaviRouteOptionTypeNEXT_STOP:
        NAVILITE_request_app_gohome( NAVILITE_ROUTE_NEXT_STOP );
        break;
    case EnumNaviRouteOptionTypeLAST_STOP:
        NAVILITE_request_app_gohome( NAVILITE_ROUTE_LAST_STOP );
        break;
    default:
        PRINTF( "%s: Unknown route option type\r\n", __FUNCTION__ );
        break;
    }
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
    EnumNaviRouteOptionType route_option_type
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
switch( route_option_type )
    {
    case EnumNaviRouteOptionTypeNEW_ROUTE:
        NAVILITE_request_app_gooffice( NAVILITE_ROUTE_NEW_ROUTE );
        break;
    case EnumNaviRouteOptionTypeNEXT_STOP:
        NAVILITE_request_app_gooffice( NAVILITE_ROUTE_NEXT_STOP );
        break;
    case EnumNaviRouteOptionTypeLAST_STOP:
        NAVILITE_request_app_gooffice( NAVILITE_ROUTE_LAST_STOP );
        break;
    default:
        PRINTF( "%s: Unknown route option type\r\n", __FUNCTION__ );
        break;
    }
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
* NAVI_send_start_route_request
*
* Send request to start route guidance.
*
* @param list_idx The selected index of favorite list.
*
*********************************************************************/
void NAVI_send_start_route_request
    (
    uint32_t list_idx,
    EnumNaviRouteOptionType route_option_type
    )
{
PRINTF( "%s, List Index: %d\r\n", __FUNCTION__, list_idx );

uint32_t poi_list_idx = navi_get_poi_list_index( list_idx );
PRINTF( "%s, Poi Index: %d\r\n", __FUNCTION__, poi_list_idx );

switch( route_option_type )
    {
    case EnumNaviRouteOptionTypeNEW_ROUTE:
        NAVILITE_request_app_startroute( poi_list_idx, NAVILITE_ROUTE_NEW_ROUTE );
        break;
    case EnumNaviRouteOptionTypeNEXT_STOP:
        NAVILITE_request_app_startroute( poi_list_idx, NAVILITE_ROUTE_NEXT_STOP );
        break;
    case EnumNaviRouteOptionTypeLAST_STOP:
        NAVILITE_request_app_startroute( poi_list_idx, NAVILITE_ROUTE_LAST_STOP );
        break;
    default:
        PRINTF( "%s: Unknown route option type\r\n", __FUNCTION__ );
        break;
    }
}

/*********************************************************************
*
* @public
* NAVI_get_navi_bt_throughput_ui_mode
*
* Obtain the corresponding navi ui mode based on the current BT throughput
*
*********************************************************************/
EnumNaviBtThroughputUIMode NAVI_get_navi_bt_throughput_ui_mode
    (
    void
    )
{
PRINTF( "%s \r\n", __FUNCTION__ );
return navi_bt_throughput_ui_mode;
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
navi_tbt_init();
navi_poi_init();
navi_dialog_init();

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
        case NAVILITE_FUNC_NEXT_TURN_DIST_UPDATE:
            result = ( (next_turn_dist_update)navi_funtion_table[i] )( navi_next_turn_dist_update );
            break;
        case NAVILITE_FUNC_ACTIVE_TBT_UPDATE:
            result = ( (active_tbt_item_update)navi_funtion_table[i] )( navi_active_tbt_update );
            break;
        case NAVILITE_FUNC_TBT_LIST_UPDATE:
            result = ( (tbt_list_update)navi_funtion_table[i] )( navi_tbt_list_update );
            break;
        case NAVILITE_FUNC_FAV_LIST_UPDATE:
            result = ( (poi_list_update)navi_funtion_table[i] )( navi_poi_list_update );
            break;
        case NAVILITE_FUNC_GAS_LIST_UPDATE:
            result = ( (poi_list_update)navi_funtion_table[i] )( navi_poi_list_update );
            break;
        case NAVILITE_FUNC_BT_THROUGHPUT_UPDATE:
            result = ( (bt_throughput_update)navi_funtion_table[i] )( navi_bt_throughput_update );
            break;
        case NAVILITE_FUNC_INIT_UPDATE:
            result = ( (navi_init_setting_update)navi_funtion_table[i] )( navi_app_init_update );
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

