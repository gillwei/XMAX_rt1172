/*******************************************************************************
* @file
* NAVILITE_pub.h
*
* @brief
* NAVILITE public header file
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
********************************************************************************/
#ifndef NAVILITE_PUB_H
#define NAVILITE_PUB_H

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <stdint.h>  // for uint8_t etc
#include <stdbool.h> // for bool
#include <stddef.h>  // for NULL
#include <string.h>  // for memset()

#include "NAVILITE_config.h"
#include "NAVILITE_pub_protocol.h"
#include "NAVILITE_util.h"
#include "JPEG_pub.h"

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/
/* enum types */

typedef enum tagNAVILITE_INIT_MODE_TYPE
    {
    NAVILITE_INIT_NORMAL,    /* connect to BT */
    NAVILITE_INIT_FAKE_DATA, /* did not connect to bt and use fake data for testing HMI */
    NAVILITE_INIT_TBD,
    } navilite_init_mode_type;

typedef enum tagNAVILITE_CONN_MODE_TYPE
    {
    NAVILITE_CONN_BT_IAP2 = 1,
    NAVILITE_CONN_BT_SPP = 2,
    NAVILITE_CONN_TBD = 3
    } navilite_conn_mode_type;

typedef enum tagNAVILITE_IMAGE_TYPE
    {
    NAVILITE_IMAGE_NAVIGATION,
    NAVILITE_IMAGE_JCV,
    NAVILITE_IMAGE_POILIST_FAV,
    NAVILITE_IMAGE_POILIST_GAS,
    NAVILITE_IMAGE_OTHER
    } navilite_image_type;

typedef enum tagNAVILITE_NAVIEVENT_TYPE
    {
    NAVILITE_NAVIEVENT_TYPE_TRAFFIC,
    NAVILITE_NAVIEVENT_TYPE_SPEED,
    NAVILITE_NAVIEVENT_TYPE_CAMERA,
    NAVILITE_NAVIEVENT_TYPE_BORDER,
    NAVILITE_NAVIEVENT_TYPE_SCHOOL,
    NAVILITE_NAVIEVENT_TYPE_OTHER
    } navilite_navievent_type;

typedef enum tagNAVILITE_CONTENT_MODE_TYPE
    {
    NAVILITE_CONTENT_MODE_BUSY = 0, // busy mask page / busy indicator
    NAVILITE_CONTENT_MODE_TBT = 1, // from MAP to TBT
    NAVILITE_CONTENT_MODE_MAP = 2 // from TBT to MAP
    } navilite_content_mode_type;

typedef enum tagNAVILITE_EVENT_CAMERA_EXTRA_SUBTYPE
    {
    NAVILITE_CAM_TYPE_CHECK_FIXED = 0, // A permanent spot check - e.g. a GATSO.
    NAVILITE_CAM_TYPE_CHECK_TEMPORARY = 1, // A site with infrastructure (e.g. lines on road) but no permanent camera.
    NAVILITE_CAM_TYPE_MOBILE = 2, // A stretch of road enforced with mobile cameras/radar guns.
    NAVILITE_CAM_TYPE_AVERAGE = 3, // A stretch of road where the average vehicle speed is measured e.g. a SPECS system.
    NAVILITE_CAM_TYPE_VARIABLE = 4, // A camera with a speed limit that can be changed.
    NAVILITE_CAM_TYPE_RED_LIGHT = 5, // A red-light camera
    NAVILITE_CAM_TYPE_USER = 6, // Camera location reported by user
    NAVILITE_CAM_TYPE_MOBILE_ZONE = 7, // A stretch of road enforced with mobile cameras/radar guns. Realtime reported.
    NAVILITE_CAM_TYPE_DANGEROUS_ZONE = 8, // A Dangerous Zone (French regulations)
    NAVILITE_CAM_TYPE_DANGEROUS_POINT = 9, // A Dangerous Point (French regulations)
    NAVILITE_CAM_TYPE_RISK_ZONE = 10, // A Risk Zone (French regulations)
    NAVILITE_CAM_TYPE_UNKNOWN = 11
    } navilite_navievent_camera_extra_subtype;

// argument used for start/stop list request
typedef enum tagNAVILITE_CONTENT_TYPE
    {
    NAVILITE_CONTENT_TYPE_NAVI_IMAGE = 1, // reserved for code refactor
    NAVILITE_CONTENT_TYPE_TBT_LIST = 2,
    NAVILITE_CONTENT_TYPE_FAVORITE_LIST = 3,
    NAVILITE_CONTENT_TYPE_GASSTATION_LIST = 4
    } navilite_content_type;

typedef enum tagNAVILITE_SWITCH_TYPE
    {
    NAVILITE_ENABLE_TYPE_ENABLE = 1,
    NAVILITE_ENABLE_TYPE_DISABLE = 0
    } navilite_switch_type;

typedef enum tagNAVILITE_NAVIGATION_STATUS_TYPE
    {
    NAVILITE_STATE_INACTIVE    = 0,  ///< NAV state is inactive
    NAVILITE_STATE_NAVIGATING  = 1,  ///< Navigating status
    } navilite_navigation_status_type;

typedef enum tagNAVILITE_TBTLIST_ACTON_TYPE
    {
    NAVILITE_TBTLIST_ACTION_LISTSIZE = 1,  ///< list size notify
    NAVILITE_TBTLIST_ACTION_ITEMADD  = 2,  ///< list item add notify
    NAVILITE_TBTLIST_ACTION_OTHER    = 0
    } navilite_tbt_list_action_type;

typedef enum tagNAVILITE_POILIST_ACTON_TYPE
    {
    NAVILITE_POILIST_ACTION_LISTSIZE = 1,  ///< list size notify
    NAVILITE_POILIST_ACTION_ITEMADD  = 2,  ///< list item add notify
    NAVILITE_POILIST_ACTION_OTHER    = 0
    } navilite_poi_list_action_type;
/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/
/* Data structure for NaviLight TBT lists API */

typedef struct tagNAVILITE_TBT_LIST_TYPE
    {
    uint16_t list_item_index;
    uint8_t icon_index;
    uint8_t desc_size;
    uint8_t dist_unit_size;
    uint32_t distance; // NOTE: storage as FP32
    uint8_t* distance_unit;
    uint8_t* desc;
    } navilite_tbt_list_type;

typedef struct tagNAVILITE_POI_LIST_TYPE
    {
    uint32_t list_item_index;
    uint8_t desc_size;
    uint8_t dist_unit_size;
    uint32_t distance;
    uint8_t* distance_unit;
    uint8_t* desc;
    } navilite_poi_list_type;

/* Fav/Gas list define based on poi list type */
typedef navilite_poi_list_type navilite_fav_list_type;
typedef navilite_poi_list_type navilite_gas_list_type;


/* Navigation Events */
typedef struct tagNAVILITE_NAVIEVENT_TEXT_TYPE
    {
    navilite_navievent_type event_type; /* Traffic/Speed Camera/Border/School */
    uint8_t* desc;
    uint8_t desc_size;
    uint8_t visibility; /* show 1/hide 0*/
    } navilite_navievent_text_type;

/* NaviLight Callback Typdefs for NaviLite Content notification register API*/

// connect/disconnect event when BT SPP/IAP2 connection is made
typedef void ( *navilite_callback_func_preconnected )( uint8_t mode );
typedef void ( *navilite_callback_func_connected )( uint8_t mode );
typedef void ( *navilite_callback_func_disconnected )( uint8_t mode );

// ESN id notification, once sent and ack to/from mobile app
typedef void ( *navilite_callback_func_esn_sent )( void ); // ESN id notify

// content notification
typedef void ( *navilite_callback_func_imageframe )( uint8_t* image, uint16_t image_size, navilite_image_type mode );
typedef void ( *navilite_callback_func_eta )( uint32_t value );
typedef void ( *navilite_callback_func_bt_timeout )( uint8_t value );
typedef void ( *navilite_callback_func_content_mode_switch )( navilite_content_mode_type mode, uint8_t throughput_timeout );
typedef void ( *navilite_callback_func_currentroadname )( uint8_t* str, uint8_t str_size );
typedef void ( *navilite_callback_func_nextturndistance )( uint8_t icon_index, uint32_t distance, uint8_t* dist_unit_str, uint8_t dist_unit_str_size );
typedef void ( *navilite_callback_func_nexttbtlist )( navilite_tbt_list_action_type action, navilite_tbt_list_type* list, uint16_t list_item_index, uint16_t list_total_items, uint16_t list_item_total_recevied, uint8_t has_more_items_on_next_request );
typedef void ( *navilite_callback_func_nexttpoilist )( navilite_poi_list_action_type action, navilite_poi_list_type* list, uint16_t list_item_index, uint16_t list_total_items, uint16_t list_item_total_recevied, uint8_t has_more_items_on_next_request );
typedef void ( *navilite_callback_func_activetbtitem )( uint16_t active_tbt_index);
typedef void ( *navilite_callback_func_navieventtext )( uint8_t* str, uint8_t str_size, navilite_navievent_type navi_event_type, navilite_navievent_camera_extra_subtype navi_extra_sub_type, uint8_t visibility );
typedef void ( *navilite_callback_func_homelocationsetting )( uint8_t is_home_location );
typedef void ( *navilite_callback_func_officelocationsetting )( uint8_t is_office_location );
typedef void ( *navilite_callback_func_zoomlevel )( uint8_t current_level, uint8_t max_level );
typedef void ( *navilite_callback_func_routecalcprogress )( uint8_t progress ); // timeout:10s and automatically callback to
typedef void ( *navilite_callback_func_daynightmode )( navilite_daynight_mode_type mode ); // daynight mode update
typedef void ( *navilite_callback_func_speedlimit )( uint16_t speed_limit ); // speed limit
typedef void ( *navilite_callback_func_viapointcount )( uint8_t via_point_count ); // via point count
typedef void ( *navilite_callback_func_navigationstatus )( uint8_t navigation_status ); // navigation status
typedef void ( *navilite_callback_func_dialogevent )( uint8_t dialog_id, navilite_dialog_type dialog_type, uint8_t* message, uint8_t message_size, uint8_t timeout, uint8_t default_choice ); // dialog event

/* Helper Utitilty (indirect callback API) */
typedef void ( *navilite_callback_func_tbtmodestatus )( uint8_t is_tbt ); // when TBT/image is updated, this callback will fire

typedef struct tagNAVILITE_CONTENT_UPDATE_CALLBACKS
    {
    navilite_callback_func_connected callback_func_preconnected;
    navilite_callback_func_connected callback_func_connected;
    navilite_callback_func_disconnected callback_func_disconnected;
    navilite_callback_func_esn_sent callback_func_esn_sent;
    navilite_callback_func_imageframe callback_func_imageframe;
    navilite_callback_func_eta callback_func_eta;
    navilite_callback_func_bt_timeout callback_func_bt_timeout;
    navilite_callback_func_content_mode_switch callback_func_content_mode_switch;
    navilite_callback_func_currentroadname callback_func_currentroadname;
    navilite_callback_func_nextturndistance callback_func_nextturndistance;
    navilite_callback_func_nexttbtlist callback_func_nexttbtist;
    navilite_callback_func_nexttpoilist callback_func_nextfavlist;
    navilite_callback_func_nexttpoilist callback_func_nextgaslist;
    navilite_callback_func_activetbtitem callback_func_activetbtitem;
    navilite_callback_func_navieventtext callback_func_navieventtext;
    navilite_callback_func_homelocationsetting callback_func_homelocationsetting;
    navilite_callback_func_officelocationsetting callback_func_officelocationsetting;
    navilite_callback_func_zoomlevel callback_func_zoomlevel;
    navilite_callback_func_routecalcprogress callback_func_routecalcprogress; //! timeout:10s and automatically callback to
    navilite_callback_func_daynightmode callback_func_daynightmode;
    navilite_callback_func_tbtmodestatus callback_func_tbtmodestatus;
    navilite_callback_func_speedlimit callback_func_speedlimit;
    navilite_callback_func_viapointcount callback_func_viapointcount;
    navilite_callback_func_navigationstatus callback_func_navigationstatus;
    navilite_callback_func_dialogevent callback_func_dialogevent;
    } navilite_content_update_callbacks_type;

typedef struct tagNAVILITE_ACK_STATE_CALLBACKS
    {
    uint8_t esn_ack;
    uint8_t frame_ack;
    } navilite_ack_table_type;

typedef struct tagNAVILTE_SESSION_STATE
    {
    uint8_t session_id[6]; // bt address 6 bytes as session id
    uint8_t navigation_status; // 1 - navigating 0 - non navigating
    uint8_t office_status; // is office setting set? 1 - set , 0 - no
    uint8_t home_status; // is home setting set? 1 - set, 0 - no
    uint8_t inited;
    uint8_t auth_request_sent;
    uint32_t last_received_content_tick; // tick timestamp for last received content target (image/tbt)
    uint8_t bt_throughput_skip_request; // skip request when bt throughput is met
    } navilite_session_status_type;
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
#define NAVILITE_DELM ";"    //! Delimiter for separating value/unit or so

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/

/* NaviLite HMI Integration setup API */
void NAVILITE_hmi_integration_setup( void );

/* NaviLite event injection */
void NAVILITE_event_injection( void );

/* NaviLight Connection Management API */
void NAVILITE_init( void );
void NAVILITE_connect( navilite_conn_mode_type mode );
navilite_conn_mode_type NAVILITE_get_connect_mode();
void NAVILITE_disconnect( void );

/* NaviLight Content Notification API */
bool NAVILITE_register_update_callback_imageframe( navilite_callback_func_imageframe callback_func );
bool NAVILITE_register_update_callback_speedlimit( navilite_callback_func_speedlimit callback_func );
bool NAVILITE_register_update_callback_eta( navilite_callback_func_eta callback_func );
bool NAVILITE_register_update_callback_currentroadname( navilite_callback_func_currentroadname callback_func );
bool NAVILITE_register_update_callback_nextturndistance( navilite_callback_func_nextturndistance callback_func );
bool NAVILITE_register_update_callback_tbtlist( navilite_callback_func_nexttbtlist callback_func );
bool NAVILITE_register_update_callback_favlist( navilite_callback_func_nexttpoilist callback_func );
bool NAVILITE_register_update_callback_gaslist( navilite_callback_func_nexttpoilist callback_func );
bool NAVILITE_register_update_callback_activetbtlistitem( navilite_callback_func_activetbtitem callback_func );
bool NAVILITE_register_update_callback_navieventtext( navilite_callback_func_navieventtext callback_func );
bool NAVILITE_register_update_callback_homelocationsetting( navilite_callback_func_homelocationsetting callback_func );
bool NAVILITE_register_update_callback_officelocationsetting( navilite_callback_func_officelocationsetting callback_func );
bool NAVILITE_register_update_callback_zoomlevel( navilite_callback_func_zoomlevel callback_func );
bool NAVILITE_register_update_callback_routecalcprogress( navilite_callback_func_routecalcprogress callback_func );
bool NAVILITE_register_update_callback_daynightmode( navilite_callback_func_daynightmode callback_func );
bool NAVILITE_register_update_callback_esn_sent( navilite_callback_func_esn_sent callback_func );
bool NAVILITE_register_update_callback_navigationstatus( navilite_callback_func_navigationstatus callback_func );
bool NAVILITE_register_update_callback_viapointcount( navilite_callback_func_viapointcount callback_func );
bool NAVILITE_register_update_callback_routecalcprogress( navilite_callback_func_routecalcprogress callback_func );
bool NAVILITE_register_update_callback_bt_timeout( navilite_callback_func_bt_timeout callback_func );
bool NAVILITE_register_update_callback_dialogevent( navilite_callback_func_dialogevent callback_func );

/* NaviLight Connection Event API */
bool NAVILITE_register_update_callback_preconnected();
bool NAVILITE_register_update_callback_connected();
bool NAVILITE_register_update_callback_disconnected();

/* NaviLite protocol parsing */
bool NAVILITE_parse_data( uint8_t*, uint32_t );

/* NaviLite Data Transfer API for queuing hci data buffers */
void NAVILITE_queue_hci_buffer( uint8_t*, uint32_t );

/* NaviLite transportation API */
bool NAVILITE_send( uint8_t*, uint32_t );
bool NAVILITE_send_as_mobile( uint8_t*, uint32_t );
bool NAVILITE_receive( uint8_t*, uint32_t );

/* NaviLite App Request API (Request Mobile App to do something) */
bool NAVILITE_request_app_startroute( uint32_t route_index, navilite_route_option_type route_option ); //! request navilite mobile app to start routing
bool NAVILITE_request_app_stoproute();        //! request navilite mobile app to stop routing
bool NAVILITE_request_app_skip_nextwaypoint(); //! request navilite mobile app to skip next way point
bool NAVILITE_request_app_zoomin();           //! request navilite mobile app to zoom in map and report status
bool NAVILITE_request_app_zoomout();          //! request navilite mobile app to zoom out map and report status
bool NAVILITE_request_app_gohome( navilite_route_option_type route_option );  //! request navilite mobile app to navigate home
bool NAVILITE_request_app_gooffice( navilite_route_option_type route_option );  //! request navilite mobile app to navigate office
bool NAVILITE_request_app_start_imageframe_update(); //! request navilite mobile app to start image frame update
bool NAVILITE_request_app_stop_imageframe_update(); //! request navilite mobile app to stop image frame update
bool NAVILITE_request_app_enable_content_update( navilite_content_type content_type, navilite_switch_type enable ); //! request navilite mobile app to enable dedicated content update

/* NaviLite vehicle or other info report to Mobile App */
bool NAVILITE_report_app_service_ack( uint8_t service_ack );         //! report meter speed to navilite mobile app
bool NAVILITE_report_app_esn( uint8_t* esn );                //! report device ID to navilite mobile app
bool NAVILITE_report_app_sysinfo( uint8_t* sysinfo );             //! report device ID to navilite mobile app
bool NAVILITE_report_app_dialog_select( uint8_t dialog_id, navilite_button_type button_type ); //! report dialog selection to navilite mobile app

/* NaviLite Status API for navigation */
bool NAVILITE_is_app_navigating();
bool NAVILITE_is_app_home_setting_set();
bool NAVILITE_is_app_office_setting_set();
#ifdef __cplusplus
}
#endif

#endif /*NAVILITE_PUB_H */
