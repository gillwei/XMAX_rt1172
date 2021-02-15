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

#define MAX_STR_SIZE            ( 16 )
#define MAX_ROAD_NAME_SIZE      ( 64 )

typedef enum
    {
    NAVIEVENT_TYPE_TRAFFIC,
    NAVIEVENT_TYPE_SPEED,
    NAVIEVENT_TYPE_CAMERA,
    NAVIEVENT_TYPE_BORDER,
    NAVIEVENT_TYPE_SCHOOL,
    NAVIEVENT_TYPE_OTHER
    } navi_event_type;

typedef struct
    {
    navi_event_type event_type;
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

void NAVI_init( void );
void NAVI_jpeg_data_received( uint32_t jpeg_size, uint8_t* buffer_addr );

#ifdef __cplusplus
}
#endif

#endif /* NAVI_PUB_H */

