/*********************************************************************
* @file
* ew_tacho.h
*
* @brief
* EW module - tacho visualizer
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef EW_TACHO_H
#define EW_TACHO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define TACHO_DEFAULT_FULLSCALE         ( EnumTachoFullScaleRPM15000 )
#define TACHO_DEFAULT_REDZONE_BEGIN     ( 15000 )

#define TACHO_COLORBASE_WIDTH           ( 449 )
#define TACHO_COLORBASE_HEIGHT          ( 234 )
#define TACHO_COLORBASE_COLOR_DEPTH     ( 3 )       /* RGB888 for 1 pixel */

typedef struct
    {
    int32_t x1;
    int32_t y1;
    int32_t x2;
    int32_t y2;
    } boundary_s;

typedef struct
    {
    int32_t up_mask_y1;
    int32_t up_mask_y2;
    int32_t down_mask_y1;
    int32_t down_mask_y2;
    boundary_s up_colorbase_boundary;
    boundary_s down_colorbase_boundary;
    } tacho_display_param;

typedef enum
    {
    TACHO_COLORBASE_PART_UP,
    TACHO_COLORBASE_PART_DOWN
    } tacho_colorbase_part_e;

void ew_tacho_load_colorbase( void );
void ew_tacho_get_colorbase( uint8_t** color_base );

int32_t  ew_tacho_get_fullscale( void );
uint32_t ew_tacho_get_readzone_begin( void );
void     ew_tacho_set_y_mask( const int32_t up_mask_y1, const int32_t up_mask_y2, const int32_t down_mask_y1, const int32_t down_mask_y2 );
void     ew_tacho_set_colorbase_bounds
            (
            const int up_colorbase_bounds_x1, const int up_colorbase_bounds_y1, const int up_colorbase_bounds_x2, const int up_colorbase_bounds_y2,
            const int low_colorbase_boudns_x1, const int low_colorbase_bounds_y1, const int low_colorbase_bounds_x2, const int low_colorbase_bounds_y2
            );
tacho_display_param* ew_tacho_get_display_param();

#ifdef __cplusplus
}
#endif

#endif /* EW_TACHO_H */

