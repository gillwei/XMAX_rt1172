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
#define MAX_TBT_DIST_UNIT_SIZE       ( 16 )
#define MAX_EVENT_QUEUE_SIZE         ( 10 )

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
    NAVILITE_FUNC_CNT
    } navilite_func;

typedef struct
    {
    uint8_t dialog_id;
    navilite_dialog_type dialog_type;
    char dialog_message[MAX_DIALOG_DESCRIPTION_SIZE];
    uint8_t dialog_message_size;
    } navi_dialog_type;

typedef struct
    {
    navilite_navievent_type event_type;
    navilite_navievent_camera_extra_subtype camera_type;
    char speed[MAX_STR_SIZE];
    char dist[MAX_STR_SIZE];
    uint8_t desc_size;
    uint8_t visibility;
    } navi_event_stat;

typedef struct
    {
    char current_road[MAX_ROAD_NAME_SIZE];
    uint32_t eta;
    uint32_t speed_limit;
    uint8_t daynight;
    navi_event_stat navi_event;
    uint8_t is_navigating;
    uint8_t route_cal_progress;
    } navi_data_type;

typedef struct
    {
    uint32_t list_idx;
    uint32_t icon_idx;
    uint16_t distance;
    char     dist_unit[MAX_TBT_DIST_UNIT_SIZE];
    char     description[MAX_TBT_DESCRIPTION_SIZE];
    }navi_tbt_data_type;

void NAVI_init( void );
void NAVI_jpeg_data_received( uint32_t jpeg_size, uint8_t* buffer_addr );
navi_data_type* NAVI_get_navi_obj( void );
bool NAVI_get_navigation_status( void );
void NAVI_stop_map_update( void );
bool NAVI_get_event( navi_event_stat* event_data );
void NAVI_reset_event_buffer( void );
void NAVI_send_zoom_in_request( void );
void NAVI_send_zoom_out_request( void );
EnumNaviDialogType NAVI_get_dialog_type( void );
void NAVI_send_selected_dialog( EnumNaviButtonType button_type );
void NAVI_get_dialog_message( char** dialog_message );
bool NAVI_get_connect_status( void );
bool NAVI_get_navi_app_setup_status( void );
void NAVI_send_stop_route_request( void );
void NAVI_send_skip_next_waypoint_request( void );
void NAVI_send_go_home_request( void );
void NAVI_send_go_office_request( void );

#ifdef __cplusplus
}
#endif

#endif /* NAVI_PUB_H */

