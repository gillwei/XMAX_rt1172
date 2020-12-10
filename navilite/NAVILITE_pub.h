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

typedef enum tagNAVILITE_SWITCH_TYPE
    {
    NAVILITE_ENABLE_TYPE_ENABLE = 1,
    NAVILITE_ENABLE_TYPE_DISABLE = 0
    } navilite_switch_type;

typedef enum tagNAVILITE_DAYNIGHT_TYPE
    {
    NAVILITE_DAYNIGHT_DAY_MODE,
    NAVILITE_DAYNIGHT_NIGHT_MODE
    } navilite_daynight_type;

/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/
/* Data structure for NaviLight TBT lists API */

typedef struct tagNAVILITE_TBT_LIST_TYPE
    {
    uint32_t list_index;
    uint8_t icon_index;
    uint8_t desc_size;
    uint8_t dist_size;
    uint8_t* desc;
    uint8_t* distance;
    } navilite_tbt_list_type;

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
typedef void ( *navilite_callback_func_connected )( uint8_t mode );
typedef void ( *navilite_callback_func_disconnected )( uint8_t mode );

// content notification
typedef void ( *navilite_callback_func_imageframe )( uint8_t* image, uint16_t image_size, navilite_image_type mode );
typedef void ( *navilite_callback_func_eta )( uint32_t value );
typedef void ( *navilite_callback_func_remaindist )( uint8_t* str, uint8_t str_size );
typedef void ( *navilite_callback_func_currentroadname )( uint8_t* str, uint8_t str_size );
typedef void ( *navilite_callback_func_nextturndistance )( uint8_t* str, uint8_t str_size );
typedef void ( *navilite_callback_func_nexttbtlist )( navilite_tbt_list_type *list, uint8_t list_size );
typedef void ( *navilite_callback_func_activetbtitem )( uint8_t active_tbt_index);
typedef void ( *navilite_callback_func_navieventtext )( uint8_t* str, uint8_t str_size, navilite_navievent_type navi_event_type, uint8_t visibility );
typedef void ( *navilite_callback_func_homelocationsetting )( uint8_t is_home_location );
typedef void ( *navilite_callback_func_officelocationsetting )( uint8_t is_office_location );
typedef void ( *navilite_callback_func_hardkeyreportrequest )( uint8_t enable );
typedef void ( *navilite_callback_func_zoomlevel )( uint8_t current_level, uint8_t max_level );
typedef void ( *navilite_callback_func_routecalcprogress )( uint8_t progress ); // timeout:10s and automatically callback to
typedef void ( *navilite_callback_func_daynightmode )( navilite_daynight_type mode ); // daynight mode update
typedef void ( *navilite_callback_func_speedlimit )( uint8_t speed ); // speed limit
typedef void ( *navilite_callback_func_viapointcount )( uint16_t via_point_count ); // via point count

/* Helper Utitilty (indirect callback API) */
typedef void ( *navilite_callback_func_tbtmodestatus )( uint8_t is_tbt ); // when TBT/image is updated, this callback will fire

typedef struct tagNAVILITE_CONTENT_UPDATE_CALLBACKS
    {
    navilite_callback_func_connected callback_func_connected;
    navilite_callback_func_disconnected callback_func_disconnected;
    navilite_callback_func_imageframe callback_func_imageframe;
    navilite_callback_func_eta callback_func_eta;
    navilite_callback_func_currentroadname callback_func_currentroadname;
    navilite_callback_func_nextturndistance callback_func_nextturndistance;
    navilite_callback_func_nexttbtlist callback_func_nexttbtist;
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
    } navilite_content_update_callbacks_type;

typedef struct tagNAVILITE_ACK_STATE_CALLBACKS
    {
    uint8_t esn_ack;
    uint8_t frame_ack;
    } navilite_ack_table_type;

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
#define NAVILITE_DELM " "    //! Delimiter for separating value/unit or so

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
bool NAVILITE_register_update_callback_eta( navilite_callback_func_eta callback_func );
bool NAVILITE_register_update_callback_currentroadname( navilite_callback_func_currentroadname callback_func );
bool NAVILITE_register_update_callback_nextturndistance( navilite_callback_func_nextturndistance callback_func );
bool NAVILITE_register_update_callback_tbtlist( navilite_callback_func_nexttbtlist callback_func );
bool NAVILITE_register_update_callback_activetbtlistitem( navilite_callback_func_activetbtitem callback_func );
bool NAVILITE_register_update_callback_navieventtext( navilite_callback_func_navieventtext callback_func );
bool NAVILITE_register_update_callback_homelocationsetting( navilite_callback_func_homelocationsetting callback_func );
bool NAVILITE_register_update_callback_officelocationsetting( navilite_callback_func_officelocationsetting callback_func );
bool NAVILITE_register_update_callback_zoomlevel( navilite_callback_func_zoomlevel callback_func );
bool NAVILITE_register_update_callback_routecalcprogress( navilite_callback_func_routecalcprogress callback_func );
bool NAVILITE_register_update_callback_daynightmode( navilite_callback_func_daynightmode callback_func );

/* NaviLight Connection Event API */
bool NAVILITE_register_update_callback_connected();
bool NAVILITE_register_update_callback_disconnected();

/* NaviLite protocol parsing */
void NAVILITE_parse_data( uint8_t *, uint32_t );

/* NaviLite Data Transfer API for queuing hci data buffers */
void NAVILITE_queue_hci_buffer( uint8_t *, uint32_t );

/* NaviLite transportation API */
bool NAVILITE_send( uint8_t *, uint32_t );
bool NAVILITE_receive( uint8_t *, uint32_t );

/* NaviLite App Request API (Request Mobile App to do something) */
bool NAVILITE_request_app_startroute( uint16_t route_index ); //! request navilite mobile app to start routing
bool NAVILITE_request_app_stoproute();        //! request navilite mobile app to stop routing
bool NAVILITE_request_app_skip_nextwaypoint(); //! request navilite mobile app to skip next way point
bool NAVILITE_request_app_zoomin();           //! request navilite mobile app to zoom in map and report status
bool NAVILITE_request_app_zoomout();          //! request navilite mobile app to zoom out map and report status
bool NAVILITE_request_app_gohome();           //! request navilite mobile app to navigate home
bool NAVILITE_request_app_gooffice();         //! request navilite mobile app to navigate office
bool NAVILITE_request_app_get_recentlist( void ); //! request navilite mobile app to send recent list
bool NAVILITE_request_app_get_favoritlist( void ); //! request navilite mobile app to send favorite list
bool NAVILITE_request_app_get_stationlist( void ); //! request navilite mobile app to send station list

/* NaviLite vehicle or other info report to Mobile App */
bool NAVILITE_report_app_service_ack( uint8_t service_ack );         //! report meter speed to navilite mobile app
bool NAVILITE_report_app_esn( uint8_t* esn );                //! report device ID to navilite mobile app
bool NAVILITE_report_app_sysinfo( uint8_t* sysinfo );             //! report device ID to navilite mobile app

#ifdef __cplusplus
}
#endif

#endif /*NAVILITE_PUB_H */