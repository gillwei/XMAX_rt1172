/*********************************************************************
* @file
* navilite_hmi_integration.c
*
* @brief
* NAVILITE module - hmi integration
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "limits.h"
#include "task.h"
#include "semphr.h"
#include "ewrte.h"
#include "fsl_debug_console.h"
#include "EW_pub.h"
#include "NAVILITE_pub.h"
#include "NAVI_pub.h"
#include "NAVILITE_util.h"

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
* @private
* hmi_jpeg_decode_done
*
* Callback API for finishing JPEG decoding
*
* @param int result of JPEG decoding
*            return 1 when success, otherwise fail
*
*********************************************************************/
void hmi_jpeg_decode_done
    (
    int result
    )
{
if( 1 == result )
    {
    EW_notify_navi_map_update();
    }
else
    {
    NAVILITE_PRINTF( "%s fail %d\r\n", __FUNCTION__, result );
    }
}

/*********************************************************************
*
* @private
* navilite_hmi_init_setup
*
* any setup procedure can be placed here, such as read ESN id
*
*********************************************************************/
void navilite_hmi_init_setup
    (
    void
    )
{
NAVILITE_PRINTF( "[NAVILITE-HMI] hmi init setup code can be placed here if necessary !\r\n" );
}

/*********************************************************************
*
* @private
* hmi_update_callback_preconnected
*
* Callback API for navilite session is preconnected (ESN not acked)
*
* @param mode mode type for connection
*
*********************************************************************/
static void hmi_update_callback_preconnected
    (
    uint8_t mode
    )
{
NAVILITE_PRINTF( "[NAVILITE-HMI] NAVILITE session pre-connected (ESN not acked yet)!\r\n" );
// Send ESN to establish navilite session
// Once the ESN ack is received, the hmi_update_callback_connected will be called
#if( NAVILITE_ESN_REPORT_SUPPORT )
    NAVILITE_report_app_esn( ( uint8_t* )"1234567890" );
#endif
/* TODO: integrate with real ESN ID from EMW interface and validate the ESN on app */
}

/*********************************************************************
*
* @private
* hmi_update_callback_connected
*
* Callback API for navilite session is connected
*
* @param mode mode type for connection
*
*********************************************************************/
static void hmi_update_callback_connected
    (
    uint8_t mode
    )
{
NAVILITE_PRINTF( "[NAVILITE-HMI] NAVILITE session connected!\r\n" );
}

/*********************************************************************
*
* @private
* hmi_update_callback_disconnected
*
* Callback API for navilite session is disconnected
*
* @param mode mode type for connection
*
*********************************************************************/
static void hmi_update_callback_disconnected
    (
    uint8_t mode
    )
{
NAVILITE_PRINTF( "[NAVILITE-HMI] NAVILITE session disconnected!\r\n" );
}

/*********************************************************************
*
* @private
* hmi_update_callback_esn_sent
*
* Callback API for navilite ESN id is sent to app, and acked
*
*********************************************************************/
static void hmi_update_callback_esn_sent
    (
    void
    )
{
NAVILITE_PRINTF( "[ESN acked] ESN ID is sent to app!\r\n" );
if( NAVILITE_request_app_start_imageframe_update() == true )
    {
    NAVILITE_PRINTF( "[NAVILITE-CB] Start Image Frame Update Request Sent!\r\n" );
    }
else
    {
    NAVILITE_PRINTF( "[NAVILITE-CB] Start Image Frame Update Request Failed!\r\n" );
    }
}

/*********************************************************************
*
* @private
* hmi_update_callback_imageframe
*
* Callback API for image frame update
*
* @param image data pointer of image frame received
* @param image_size data size of image frame received
* @param mode mode type for the image frame
*
*********************************************************************/
static void hmi_update_callback_imageframe
    (
    uint8_t* image,
    uint16_t image_size,
    navilite_image_type mode
    )
{
NAVILITE_PRINTF( "\r\n[ImageFrame] image size = %d, addr = 0x%x mode=%d, FB=%d,FB1=%d,FB256=%d,LB=%d\r\n", image_size, image, mode, image[ 0 ], image[ 1 ], image[ 256 ], image[ image_size - 1 ] );

if( image_size > 0 && JPEG_is_valid( image, image_size ) )
    {
    uint8_t* jpeg_buf = (uint8_t*)JPEG_get_jpeg_buffer();
    NAVILITE_PRINTF( "DEBUG: JPEG_get_jpeg_buffer = 0x%x\r\n",jpeg_buf );
    if( NULL != jpeg_buf )
        {
        memcpy( jpeg_buf, image, image_size );
        JPEG_notify_received( image_size, jpeg_buf, &hmi_jpeg_decode_done );
        }
    else
        {
        NAVILITE_PRINTF( "# ERROR: JPEG BUFFER NOT AVAIL\r\n" );
        }
    }
else
    {
    NAVILITE_PRINTF( "# ERROR: INVALID JPEG DATA\r\n");
    }
}

/*********************************************************************
*
* @private
* hmi_update_callback_currentroadname
*
* Callback API for current road name update
*
* @param current_roadname data pointer of road name recieved
*        contains null if road name is empty
* @param str_size data size of road name string received
*
*********************************************************************/
static void hmi_update_callback_currentroadname
    (
    uint8_t* str,
    uint8_t str_size
    )
{
NAVILITE_PRINTF( "\r\n[NAVILITE-CB] [RoadName：%d]:", str_size );
if( str != NULL)
    {
    NAVILITE_print_utf8( str, str_size );
    }
else
    {
    NAVILITE_PRINTF( "<NULL>" );
    }
NAVILITE_PRINTF( "\r\n" );
}

/*********************************************************************
*
* @private
* hmi_update_callback_eta
*
* Callback API for ETA update
*
* @param value value of ETA received
*
*********************************************************************/
static void  hmi_update_callback_eta
    (
    uint32_t value
    )
{
NAVILITE_PRINTF( "\r\n[NAVILITE-CB] [ETA value]:%d\r\n", value );
}

/*********************************************************************
*
* @private
* hmi_update_callback_bt_timeout
*
* Callback API for bt timeout update
*
* @param value value of bt timeout received
*
*********************************************************************/
static void  hmi_update_callback_bt_timeout
    (
    uint8_t value
    )
{
NAVILITE_PRINTF( "\r\n[NAVILITE-CB] [BT timeout value]:%d\r\n", value );
}

/*********************************************************************
*
* @private
* hmi_update_callback_speedlimit
*
* Callback API for speed limit
*
* @param speed_limit value of speed limit received
*
*********************************************************************/
static void hmi_update_callback_speedlimit
    (
    uint16_t speed_limit
    )
{
NAVILITE_PRINTF( "\r\n[NAVILITE-CB] [speed limit:%d]", speed_limit );
}

/*********************************************************************
*
* @private
* hmi_update_callback_navieventtext
*
* Callback API for navi event info update
*
* @param str navi event text update
* @param str_size navi event text size
* @param navi_event_type event type of the navi event
* @param visibility visibility of the event info on UI
*
*********************************************************************/
static void hmi_update_callback_navieventtext
    (
    uint8_t* str,
    uint8_t str_size,
    navilite_navievent_type navi_event_type,
    navilite_navievent_camera_extra_subtype navi_event_extra_subtype,
    uint8_t visibility
    )
{
NAVILITE_PRINTF( "\r\n[NAVILITE-CB] [ NaviEvent event_type: %d, extra subtype:%d visibility:%d event_text:", navi_event_type, navi_event_extra_subtype, visibility );
NAVILITE_print_utf8( str, str_size );
NAVILITE_PRINTF( "\r\n" );
}

/*********************************************************************
*
* @private
* hmi_update_callback_homelocationsetting
*
* Callback API for home location setting status
*
* @param is_home_location status of current home setting
*
*********************************************************************/
static void hmi_update_callback_homelocationsetting
    (
    uint8_t is_home_location
    )
{
NAVILITE_PRINTF( "\r\n[NAVILITE-CB] home location setting:%d", is_home_location );
}

/*********************************************************************
*
* @private
* hmi_update_callback_officelocationsetting
*
* Callback API for office location setting status
*
* @param is_office_location status of current home setting
*
*********************************************************************/
static void hmi_update_callback_officelocationsetting
    (
    uint8_t is_office_location
    )
{
NAVILITE_PRINTF( "\r\n[NAVILITE-CB] office location setting:%d", is_office_location );
}

/*********************************************************************
*
* @private
* hmi_update_callback_viapointcount
*
* Callback API for via point count status
*
* @param via_point_count number of current via point count
*
*********************************************************************/
static void hmi_update_callback_viapointcount
    (
    uint8_t via_point_count
    )
{
NAVILITE_PRINTF( "\r\n[NAVILITE-CB] via point count:%d", via_point_count );
}

/*********************************************************************
*
* @private
* hmi_update_callback_navigationstatus
*
* Callback API for navigation status
*
* @param is_navigating is navigating now
*
*********************************************************************/
static void hmi_update_callback_navigationstatus
    (
    uint8_t is_navigating
    )
{
NAVILITE_PRINTF( "\r\n[NAVILITE-CB] navigation status:%d", is_navigating );
}

/*********************************************************************
*
* @private
* hmi_update_callback_daynightmode
*
* Callback API for day/night mode status
*
* @param mode status of day/night mode
*
*********************************************************************/
static void hmi_update_callback_daynightmode
    (
    navilite_daynight_mode_type mode
    )
{
NAVILITE_PRINTF( "\r\n[NAVILITE-CB] daynight mode: %d", mode );
}

/*********************************************************************
*
* @private
* hmi_update_callback_zoomlevel
*
* Callback API for zoomlevel update
*
* @param current_level current zoom level
* @param max_level max zoom level limit
*
*********************************************************************/
static void hmi_update_callback_zoomlevel
    (
    uint8_t current_level,
    uint8_t max_level
    )
{
NAVILITE_PRINTF( "\r\n[NAVILITE-CB] zoom level: current:%d, max(%d) ", current_level, max_level );
}

/*********************************************************************
*
* @private
* hmi_update_callback_routecalcprogress
*
* Callback API for route process update
*
* @param progress route calculating progress in percentage
*
*********************************************************************/
static void hmi_update_callback_routecalcprogress  //timeout:10s and automatically callback to
    (
    uint8_t progress
    )
{
NAVILITE_PRINTF( "\r\n[NAVILITE-CB] Route Calc Progress: %d ", progress );
}

/*********************************************************************
*
* @private
* hmi_update_callback_activetbtlistitem
*
* Callback API for active tbt list item update
*
* @param tbt_index active tbt list item index
*        This index value is used to know which active TBT list item need to be
*        shown.
*
*********************************************************************/
static void hmi_update_callback_activetbtlistitem
    (
    uint16_t tbt_index
    )
{
PRINTF( "\r\n[NAVILITE-CB] Active TBT list item index to show: %d\r\n", tbt_index );
}

/*********************************************************************
*
* @private
* hmi_update_callback_tbtlist
*
* Callback API for list item size/data update
* NOTE: To save bt bandwidth, please call NAVILITE_request_app_enable_content_update with
*       NAVILITE_CONTENT_TYPE_NAVI_IMAGE/NAVILITE_ENABLE_TYPE_DISABLE to disable navi image transfer.
*
* @param action what kind of action it is
* @param list_item data pointer to a list item received
*        when action is NAVILITE_TBTLIST_ACTION_ITEMADD
* @param list_item_index the index number that list item data begins to
*        when action is NAVILITE_TBTLIST_ACTION_ITEMADD
* @param list_total_items the total list items will be available
*        when action is NAVILITE_TBTLIST_ACTION_LISTSIZE
*        ( aka: how many items in this tbt list )
* @param list_total_items_recevied current list total items count currently received
*        when action is NAVILITE_TBTLIST_ACTION_ITEMADD
* @param has_more_items_on_next_request true if there will be more items coming on next request
*        otherwise, false. This value only available when action is NAVILITE_TBTLIST_ACTION_LISTSIZE
*
*********************************************************************/
static void hmi_update_callback_tbtlist
    (
    navilite_tbt_list_action_type action,
    navilite_tbt_list_type *list_item,
    uint16_t list_item_no,
    uint16_t list_total_items,
    uint16_t list_total_items_recevied,
    uint8_t has_more_items_on_next_request
    )
{
if( action == NAVILITE_TBTLIST_ACTION_LISTSIZE )
    {
    PRINTF( "\r\n*[NAVILITE-CB NAVILITE_TBTLIST_ACTION_LISTSIZE] TBT LIST ITEM SIZE REQUEST: %d, more data in this request?%d", list_total_items, has_more_items_on_next_request );
    // Integration Note: allocate memory size before receiving the list items.
    }
else if( action == NAVILITE_TBTLIST_ACTION_ITEMADD )
    {
    PRINTF( "\r\n[NAVILITE-CB NAVILITE_TBTLIST_ACTION_ITEMADD]  TBT item add notify for list item no: %d\r\n", list_item_no );
    if( list_total_items_recevied > list_total_items )
        {
        PRINTF( "\r\nWARNING: the list item count exceeds the item count previously request (NAVILITE_TBTLIST_ACTION_LISTSIZE)! should be less or equal to %d\r\n", list_total_items );
        }
    // Integration Note: replace the following API demo codes for HMI integration
    PRINTF( "* TBT LIST ITEM ADD - list item index:%d progress:(%d/%d)\r\n", list_item_no, list_total_items_recevied, list_total_items );
    PRINTF( " list item index:%d\r\n", list_item->list_item_index );
    PRINTF( " icon index:%d\r\n", list_item->icon_index );
    PRINTF( " desc size:%d\r\n", list_item->desc_size );
    PRINTF( " dist unit size:%d\r\n", list_item->dist_unit_size );
    PRINTF( " distance * 100:" );
    // Float value conversion
    // NOTE: since float number console print requires another library, so
    // here uses float value * 100 to show integer value instead without modifying existed project's setting.
    float float_val = 0;
    float_val = NAVILITE_bytes_to_float( list_item->distance );
    PRINTF( "%d\r\n ",(int)( (float)float_val * 100) );
    PRINTF( " distance unit:" );
    NAVILITE_print_utf8( list_item->distance_unit, list_item->dist_unit_size );
    PRINTF( "\r\n" );
    PRINTF( " desc : " );
    NAVILITE_print_utf8( list_item->desc, list_item->desc_size  );
    PRINTF( "\r\n" );
    }
}

/*********************************************************************
*
* @private
* hmi_update_callback_dialogevent
*
* Callback API for dialog event
*
* @param dialog_id dialog id for the event
* @param dialog_type dialog_type for the event
* @param message message content to show
* @param message_size size of message content
*
*********************************************************************/
static void hmi_update_callback_dialogevent
    (
    uint8_t dialog_id,
    navilite_dialog_type dialog_type,
    uint8_t* message,
    uint8_t message_size
    )
{
if( dialog_type != NAVILITE_DIALOGTYPE_DISMISS_DIALOG )
    {
    NAVILITE_PRINTF( "[NAVILITE-CB] DIALOG_SHOW(dialog_id:%d, dialog_type:%d, dialog_size:%d, message:", dialog_id, dialog_type, message_size );
    NAVILITE_print_utf8( message, message_size );
    }
else
    {
    NAVILITE_PRINTF( "[NAVILITE-CB] DIALOG_DISMISS(dialog_id:%d)", dialog_id );
    }
NAVILITE_PRINTF( "\r\n" );
}

/*********************************************************************
*
* @private
* hmi_update_callback_nextturndistance
*
* Callback API for next turn distance
*
* @param icon_index icon index to show
* @param distance distance variable (uint32_t), requires float conversion
* @param dist_unit_str unit string (UTF8)
* @param dist_unit_size unit string size
*
*********************************************************************/
static void hmi_update_callback_nextturndistance
    (
    uint8_t icon_index,
    uint32_t distance,
    uint8_t* dist_unit_str,
    uint8_t dist_unit_size
    )
{
// Float value conversion for distance during hmi integration
// NOTE: since float number console print requires another library, so
// here uses float value * 100 to show integer value instead without modifying existed project's setting.
// ex: float float_dist;
//     float_dist = (float)NAVILITE_bytes_to_float( distance );
NAVILITE_PRINTF( "[NAVILITE-CB] NextTurnDistance icon_index:%d, distance:%d, dist_unit_size:%d, dist_unit_str:", icon_index, distance, dist_unit_size );
NAVILITE_print_utf8( dist_unit_str, dist_unit_size );
NAVILITE_PRINTF( "\r\n" );
}

/*********************************************************************
*
* @public
* NAVILITE_hmi_integration_setup
*
* HMI integration setup entry for callback register using the navilite callbacks
*
*********************************************************************/
void NAVILITE_hmi_integration_setup
    (
    void
    )
{
// HMI integration example to setup user-defined callbacks.
// when data is received, the user-defined callback will be triggered.
NAVILITE_PRINTF("\r\n[HMI integration setup by registering the navi content API's callbacks for image mode, roadname update, and etc]\r\n");
NAVILITE_register_update_callback_preconnected( hmi_update_callback_preconnected );
NAVILITE_register_update_callback_connected( hmi_update_callback_connected );
NAVILITE_register_update_callback_disconnected( hmi_update_callback_disconnected );
NAVILITE_register_update_callback_esn_sent( hmi_update_callback_esn_sent );
NAVILITE_register_update_callback_imageframe( hmi_update_callback_imageframe );
NAVILITE_register_update_callback_currentroadname( hmi_update_callback_currentroadname );
NAVILITE_register_update_callback_eta( hmi_update_callback_eta );
NAVILITE_register_update_callback_bt_timeout( hmi_update_callback_bt_timeout );
NAVILITE_register_update_callback_speedlimit( hmi_update_callback_speedlimit );
NAVILITE_register_update_callback_navieventtext( hmi_update_callback_navieventtext );
NAVILITE_register_update_callback_homelocationsetting( hmi_update_callback_homelocationsetting );
NAVILITE_register_update_callback_daynightmode( hmi_update_callback_daynightmode );
NAVILITE_register_update_callback_officelocationsetting( hmi_update_callback_officelocationsetting );
NAVILITE_register_update_callback_zoomlevel( hmi_update_callback_zoomlevel );
NAVILITE_register_update_callback_navigationstatus( hmi_update_callback_navigationstatus );
NAVILITE_register_update_callback_viapointcount( hmi_update_callback_viapointcount );
NAVILITE_register_update_callback_routecalcprogress( hmi_update_callback_routecalcprogress );
NAVILITE_register_update_callback_dialogevent( hmi_update_callback_dialogevent );
NAVILITE_register_update_callback_nextturndistance( hmi_update_callback_nextturndistance );
NAVILITE_register_update_callback_activetbtlistitem( hmi_update_callback_activetbtlistitem );
NAVILITE_register_update_callback_tbtlist( hmi_update_callback_tbtlist );
}
