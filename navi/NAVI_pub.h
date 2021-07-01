/*********************************************************************
* @file
* NAVI_pub.h
*
* @brief
* Navigation module - public API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef NAVI_PUB_H
#define NAVI_PUB_H

#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>
#include <stdbool.h>
#include "NAVILITE_pub.h"
#include "Enum.h"

#define MAX_STR_SIZE                 ( 16 )
#define MAX_ROAD_NAME_SIZE           ( 64 )
#define MAX_DIALOG_DESCRIPTION_SIZE  ( 64 )
#define MAX_TBT_DESCRIPTION_SIZE     ( 64 )
#define MAX_POI_DESCRIPTION_SIZE     ( 48 )
#define MAX_TBT_DIST_UNIT_SIZE       ( 16 )
#define MAX_POI_DIST_UNIT_SIZE       ( 16 )
#define MAX_EVENT_QUEUE_SIZE         ( 10 )
#define MAX_TBT_SIZE                 ( 50 )
#define MAX_POI_SIZE                 ( 50 )
#define TBT_NEXT_UPDATE_IDX          ( 40 )     // This is the predefined index that navi app will send more tbt items if tbt list size is over 50.

typedef enum
    {
    NAVILITE_FUNC_PRECONNECT,
    NAVILITE_FUNC_CONNECT,
    NAVILITE_FUNC_DISCONNECT,
    NAVILITE_FUNC_IMAGE_FRAME_UPDATE,
    NAVILITE_FUNC_CURRENT_ROAD_UPDATE,
    NAVILITE_FUNC_ETA_UPDATE,
    NAVILITE_FUNC_DAY_NIGHT_UPDATE,
    NAVILITE_FUNC_NAVI_EVENT_UPDATE,
    NAVILITE_FUNC_NAVIGATION_STATUS,
    NAVILITE_FUNC_SPEED_LIMIT_UPDATE,
    NAVILITE_FUNC_HOME_SETTING_UPDATE,
    NAVILITE_FUNC_OFFICE_SETTING_UPDATE,
    NAVILITE_FUNC_ESN_UPDATE,
    NAVILITE_FUNC_ROUTE_CAL_UPDATE,
    NAVILITE_FUNC_ZOOM_LEVEL_UPDATE,
    NAVILITE_FUNC_DIALOG_EVENT_UPDATE,
    NAVILITE_FUNC_VIA_POINT_UPDATE,
    NAVILITE_FUNC_NEXT_TURN_DIST_UPDATE,
    NAVILITE_FUNC_ACTIVE_TBT_UPDATE,
    NAVILITE_FUNC_TBT_LIST_UPDATE,
    NAVILITE_FUNC_FAV_LIST_UPDATE,
    NAVILITE_FUNC_GAS_LIST_UPDATE,
    NAVILITE_FUNC_CNT
    } navilite_func;

typedef struct
    {
    uint8_t dialog_id;
    navilite_dialog_type dialog_type;
    char dialog_message[MAX_DIALOG_DESCRIPTION_SIZE];
    uint8_t dialog_message_size;
    uint8_t timeout;
    EnumNaviButtonType default_selected_button;
    } navi_dialog_type;

typedef struct
    {
    navilite_navievent_type event_type;
    navilite_navievent_extra_subtype camera_type;
    char speed[MAX_STR_SIZE];
    char dist[MAX_STR_SIZE];
    uint8_t desc_size;
    uint8_t visibility;
    } navi_event_type;

typedef struct
    {
    char current_road[MAX_ROAD_NAME_SIZE];
    uint32_t eta;
    uint32_t speed_limit;
    uint8_t daynight;
    navi_event_type navi_event;
    uint8_t is_navigating;
    uint8_t is_home_set;
    uint8_t is_office_set;
    uint8_t via_points;
    uint8_t route_cal_progress;
    navilite_image_type image_type;
    } navi_data_type;

typedef struct
    {
    uint32_t list_idx;
    uint32_t icon_idx;
    float    distance;
    char     dist_unit[MAX_TBT_DIST_UNIT_SIZE];
    char     description[MAX_TBT_DESCRIPTION_SIZE];
    }navi_tbt_data_type;

typedef struct
    {
    uint32_t  list_idx;
    float    distance;
    char     dist_unit[MAX_POI_DIST_UNIT_SIZE];
    char     description[MAX_POI_DESCRIPTION_SIZE];
    }navi_poi_data_type;

void NAVI_init( void );
void NAVI_jpeg_data_received( uint32_t jpeg_size, uint8_t* buffer_addr );
navi_data_type* NAVI_get_navi_obj( void );
navi_dialog_type* NAVI_get_navi_dialog_obj( void );
bool NAVI_get_navigation_status( void );
void NAVI_start_map_update( void );
void NAVI_stop_map_update( void );
bool NAVI_get_event( navi_event_type* event_data );
void NAVI_remove_event_from_buffer( void );
void NAVI_send_zoom_in_request( void );
void NAVI_send_zoom_out_request( void );
EnumNaviDialogType NAVI_get_dialog_type( void );
void NAVI_send_selected_dialog( EnumNaviButtonType button_type );
void NAVI_get_dialog_message( char** dialog_message );
bool NAVI_get_connect_status( void );
void NAVI_send_stop_route_request( void );
void NAVI_send_skip_next_waypoint_request( void );
void NAVI_send_go_home_request( EnumNaviRouteOptionType route_option_type );
void NAVI_send_go_office_request( EnumNaviRouteOptionType route_option_type );
EnumNaviZoomInOutStatusType NAVI_get_zoom_inout_status( void );
void NAVI_get_alert_distance( char** dist );
bool NAVI_is_tbt_message_displayed( void );
uint16_t NAVI_get_tbt_list_size( void );
void NAVI_reset_tbt_buffer( void );
bool NAVI_get_tbt_item( const int tbt_index, uint32_t* icon_index, float* distance, char** dist_unit, char** description );
void NAVI_send_start_route_request( uint32_t list_idx, EnumNaviRouteOptionType route_option_type );
void NAVI_reset_poi_buffer( void );
bool NAVI_get_poi_item( const int poi_index, float* distance, char** dist_unit, char** description );
uint16_t NAVI_get_poi_list_size( void );
void NAVI_poi_list_request( EnumNaviPoiListType poi_list_type, bool is_enabled );
bool NAVI_is_Jcv_recevied( void );

#ifdef __cplusplus
}
#endif

#endif /* NAVI_PUB_H */

