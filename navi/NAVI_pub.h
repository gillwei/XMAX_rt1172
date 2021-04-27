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

#define MAX_STR_SIZE                 ( 16 )
#define MAX_ROAD_NAME_SIZE           ( 64 )
#define MAX_TBT_DESCRIPTION_SIZE     ( 64 )
#define MAX_TBT_DIST_UNIT_SIZE       ( 16 )

// TODO: Once navilite protocol defines event & camera type, we will reuse them and remove the following event & camera enum.
typedef enum
    {
    NAVIEVENT_TYPE_TRAFFIC,
    NAVIEVENT_TYPE_SPEED,
    NAVIEVENT_TYPE_CAMERA,
    NAVIEVENT_TYPE_BORDER,
    NAVIEVENT_TYPE_SCHOOL,
    NAVIEVENT_TYPE_OTHER
    } navi_event_type;

typedef enum
    {
    NAVI_CAM_TYPE_CHECK_FIXED,
    NAVI_CAM_TYPE_CHECK_TEMPORARY,
    NAVI_CAM_TYPE_MOBILE,
    NAVI_CAM_TYPE_AVERAGE,
    NAVI_CAM_TYPE_VARIABLE,
    NAVI_CAM_TYPE_RED_LIGHT,
    NAVI_CAM_TYPE_USER,
    NAVI_CAM_TYPE_MOBILE_ZONE,
    NAVI_CAM_TYPE_DANGEROUS_ZONE,
    NAVI_CAM_TYPE_DANGEROUS_POINT,
    NAVI_CAM_TYPE_RISK_ZONE,
    NAVI_CAM_TYPE_UNKNOWN
    } navi_event_camera_type;

typedef struct
    {
    navi_event_type event_type;
    navi_event_camera_type camera_type;
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
    bool is_navigating;
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

#ifdef __cplusplus
}
#endif

#endif /* NAVI_PUB_H */

