/*********************************************************************
* @file
* ew_tacho.c
*
* @brief
* EW module - tacho visualizer
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "ewrte.h"
#include "ew_bsp_inout.h"
#include "ew_bsp_event.h"
#include "ew_priv.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "Enum.h"
#include "VI_pub.h"

#include "ew_tacho.h"
#include "ew_tacho_colorbase_10000_8000.h"
#include "ew_tacho_colorbase_10000_8500.h"
#include "ew_tacho_colorbase_10000_9000.h"
#include "ew_tacho_colorbase_10000_9500.h"
#include "ew_tacho_colorbase_10000_10000.h"
#include "ew_tacho_colorbase_15000_10000.h"
#include "ew_tacho_colorbase_15000_10500.h"
#include "ew_tacho_colorbase_15000_11000.h"
#include "ew_tacho_colorbase_15000_11500.h"
#include "ew_tacho_colorbase_15000_12000.h"
#include "ew_tacho_colorbase_15000_12500.h"
#include "ew_tacho_colorbase_15000_13000.h"
#include "ew_tacho_colorbase_15000_13500.h"
#include "ew_tacho_colorbase_15000_14000.h"
#include "ew_tacho_colorbase_15000_14500.h"
#include "ew_tacho_colorbase_15000_15000.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define LZ77_SLIDING_WINDOW_SIZE            ( 4096 )
#define LZ77_SYMBOL_OFFSET_SHIFT            ( 20 )
#define LZ77_SYMBOL_LENGTH_SHIFT            ( 8 )
#define LZ77_BYTES_PER_SYMBOLE              ( 4 )

#define TACHO_COLORBASE_RGB888_SIZE         ( TACHO_COLORBASE_WIDTH * TACHO_COLORBASE_HEIGHT * 3 )
#define TACHO_FULLSCALE_NUM                 ( 2 )
#define TACHO_1000RPM_REDZONE_BEGIN_NUM     ( 5 )
#define TACHO_1500RPM_REDZONE_BEGIN_NUM     ( 11 )

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
typedef struct
    {
    int32_t offset;
    int32_t length;
    uint8_t data;
    } lz77_symbol;

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/
static const uint32_t supported_fullscale[TACHO_FULLSCALE_NUM] = { 10000, 15000 };
static const uint32_t supported_10000rpm_redzone_begin[TACHO_1000RPM_REDZONE_BEGIN_NUM] = { 8000, 8500, 9000, 9500, 10000 };
static const uint32_t supported_15000rpm_redzone_begin[TACHO_1500RPM_REDZONE_BEGIN_NUM] = { 10000, 10500, 11000, 11500, 12000, 12500, 13000, 13500, 14000, 14500, 15000 };

static EnumTachoFullScale tacho_fullscale;
static uint32_t tacho_redzone_begin;
static tacho_display_param display_param;

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/
AT_NONCACHEABLE_SECTION_ALIGN( uint8_t tacho_colorbase_rgb888[TACHO_COLORBASE_RGB888_SIZE], 32 );

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
/*********************************************************************
*
* @private
* lz77_decompress
*
* Decompress with lz77
*
* @param in        Pointer to input buffer
* @param in_length Input data length
* @param out       Pointer to output buffer
* @param out       Output buffer size
*
*********************************************************************/
static int lz77_decompress
    (
    const uint8_t* in,
    const uint32_t in_length,
    uint8_t* out,
    const uint32_t out_buffer_size
    )
{
int32_t sliding_window_start = -LZ77_SLIDING_WINDOW_SIZE;
int32_t in_idx  = 0;
int32_t out_idx = 0;
int32_t copy_start_idx = 0;
int32_t i = 0;
uint32_t* in_symbol;
lz77_symbol symbol;
uint32_t* original_file_size = (uint32_t*)&in[0]; /* byte 0-3: original file size */

for( in_idx = 4; in_idx < in_length; in_idx += LZ77_BYTES_PER_SYMBOLE )
    {
    in_symbol = (uint32_t*)( &in[in_idx] );
    symbol.offset = ( *in_symbol >> LZ77_SYMBOL_OFFSET_SHIFT ) & 0xFFF;
    symbol.length = ( *in_symbol >> LZ77_SYMBOL_LENGTH_SHIFT ) & 0xFFF;
    symbol.data   = *in_symbol & 0xFF;

    // copy data of length from the offset of sliding window
    if( symbol.length > 0 )
        {
        copy_start_idx = sliding_window_start + symbol.offset;
        if( copy_start_idx >= 0 )
            {
            for( i = copy_start_idx; i < copy_start_idx + symbol.length; i++ )
                {
                out[out_idx] = out[i];
                out_idx++;
                }
            }
        else
            {
            EwPrint("Err negative sliding window offset %d\n", copy_start_idx);
            }
        }

    if( out_idx > *original_file_size )
        {
        EwPrint( "Err: lz77 decompressed %d > %d\n", out_idx, *original_file_size );
        break;
        }
    else if( out_idx == *original_file_size && symbol.data == '\0' )
        {
        /* neglect the trailing NULL */
        }
    else
        {
        out[out_idx] = symbol.data;
        out_idx++;
        }

    sliding_window_start += symbol.length + 1;
    }

return out_idx;
}

/*********************************************************************
*
* @private
* get_fullscale
*
* Get fullscale of tachometer
*
* @return Full scale of tachometer
*
*********************************************************************/
static EnumTachoFullScale get_fullscale
    (
    void
    )
{
EnumTachoFullScale fullscale;
uint32_t fullscale_value;
bool     is_supported = false;

VI_get_rx_data_uint( EnumVehicleRxTypeTACHO_FULLSCALE, &fullscale_value );

for( int i = 0; i < TACHO_FULLSCALE_NUM; i++ )
    {
    if( supported_fullscale[i] == fullscale_value )
        {
        is_supported = true;
        break;
        }
    }

if( is_supported )
    {
    if( 10000 == fullscale_value )
        {
        fullscale = EnumTachoFullScaleRPM10000;
        }
    else
        {
        fullscale = EnumTachoFullScaleRPM15000;
        }
    }
else
    {
    fullscale = TACHO_DEFAULT_FULLSCALE;
    }

return fullscale;
}

/*********************************************************************
*
* @private
* get_redzone_begin
*
* Get red zone begin of tachometer
*
* @param fullscale Tacho visualizer full scale
* @return Red zone begin of tachometer
*
*********************************************************************/
static uint32_t get_redzone_begin
    (
    const EnumTachoFullScale fullscale
    )
{
uint32_t redzone_begin = TACHO_DEFAULT_REDZONE_BEGIN;
uint32_t max_regzone_begin;
bool     is_supported = false;
int      redzone_begin_num;
const uint32_t* supported_redzone_begin;

VI_get_rx_data_uint( EnumVehicleRxTypeTACHO_REDZONE_BEGIN, &redzone_begin );

switch( fullscale )
    {
    case EnumTachoFullScaleRPM10000:
        supported_redzone_begin = supported_10000rpm_redzone_begin;
        max_regzone_begin = supported_10000rpm_redzone_begin[ TACHO_1000RPM_REDZONE_BEGIN_NUM - 1 ];
        redzone_begin_num = TACHO_1000RPM_REDZONE_BEGIN_NUM;
        break;
    case EnumTachoFullScaleRPM15000:
        supported_redzone_begin = supported_15000rpm_redzone_begin;
        max_regzone_begin = supported_15000rpm_redzone_begin[ TACHO_1500RPM_REDZONE_BEGIN_NUM - 1 ];
        redzone_begin_num = TACHO_1500RPM_REDZONE_BEGIN_NUM;
        break;
    default:
        break;
    }

for( int i = 0; i < redzone_begin_num; i++ )
    {
    if( supported_redzone_begin[i] == redzone_begin )
        {
        is_supported = true;
        break;
        }
    }

if( !is_supported )
    {
    redzone_begin = max_regzone_begin;
    }

return redzone_begin;
}

/*********************************************************************
*
* @private
* ew_tacho_set_colorbase_bounds
*
* Set tacho color base bounds from (x1,y1) to (x2,y2)
*
* @param up_colorbase_bounds_x1 x coordinate of the up colorbase bounds start point
* @param up_colorbase_bounds_y1 y coordinate of the up colorbase bounds start point
* @param up_colorbase_bounds_x2 x coordinate of the up colorbase bounds end point
* @param up_colorbase_bounds_y2 y coordinate of the up colorbase bounds end point
* @param down_colorbase_bounds_x1 x coordinate of the down colorbase bounds start point
* @param down_colorbase_bounds_y1 y coordinate of the down colorbase bounds start point
* @param down_colorbase_bounds_x2 x coordinate of the down colorbase bounds end point
* @param down_colorbase_bounds_y2 y coordinate of the down colorbase bounds end point
*
*********************************************************************/
void ew_tacho_set_colorbase_bounds
    (
    const int up_colorbase_bounds_x1,
    const int up_colorbase_bounds_y1,
    const int up_colorbase_bounds_x2,
    const int up_colorbase_bounds_y2,
    const int low_colorbase_boudns_x1,
    const int low_colorbase_bounds_y1,
    const int low_colorbase_bounds_x2,
    const int low_colorbase_bounds_y2
    )
{
display_param.up_colorbase_boundary.x1 = up_colorbase_bounds_x1;
display_param.up_colorbase_boundary.y1 = up_colorbase_bounds_y1;
display_param.up_colorbase_boundary.x2 = up_colorbase_bounds_x2;
display_param.up_colorbase_boundary.y2 = up_colorbase_bounds_y2;

display_param.down_colorbase_boundary.x1 = low_colorbase_boudns_x1;
display_param.down_colorbase_boundary.y1 = low_colorbase_bounds_y1;
display_param.down_colorbase_boundary.x2 = low_colorbase_bounds_x2;
display_param.down_colorbase_boundary.y2 = low_colorbase_bounds_y2;
}

/*********************************************************************
*
* @private
* ew_tacho_get_colorbase
*
* Get tacho color base
*
* @param color_base Pointer to the tacho color base
*
*********************************************************************/
void ew_tacho_get_colorbase
    (
    uint8_t** color_base
    )
{
*color_base = tacho_colorbase_rgb888;
}

/*********************************************************************
*
* @private
* ew_tacho_load_colorbase
*
* Load color base of specified full scale and red zone begin
*
*********************************************************************/
void ew_tacho_load_colorbase
    (
    void
    )
{
tacho_fullscale = get_fullscale();
tacho_redzone_begin = get_redzone_begin( tacho_fullscale );
const uint8_t* tacho_colorbase_lz77_data = NULL;
uint32_t tacho_colorbase_lz77_len;

if( EnumTachoFullScaleRPM10000 == tacho_fullscale )
    {
    switch( tacho_redzone_begin )
        {
        case 8000:
            tacho_colorbase_lz77_data = TACHO_COLORBASE_10000RPM_8000RED;
            tacho_colorbase_lz77_len  = TACHO_COLORBASE_10000RPM_8000RED_LEN;
            break;
        case 8500:
            tacho_colorbase_lz77_data = TACHO_COLORBASE_10000RPM_8500RED;
            tacho_colorbase_lz77_len  = TACHO_COLORBASE_10000RPM_8500RED_LEN;
            break;
        case 9000:
            tacho_colorbase_lz77_data = TACHO_COLORBASE_10000RPM_9000RED;
            tacho_colorbase_lz77_len  = TACHO_COLORBASE_10000RPM_9000RED_LEN;
            break;
        case 9500:
            tacho_colorbase_lz77_data = TACHO_COLORBASE_10000RPM_9500RED;
            tacho_colorbase_lz77_len  = TACHO_COLORBASE_10000RPM_9500RED_LEN;
            break;
        case 10000:
            tacho_colorbase_lz77_data = TACHO_COLORBASE_10000RPM_10000RED;
            tacho_colorbase_lz77_len  = TACHO_COLORBASE_10000RPM_10000RED_LEN;
            break;
        default:
            break;
        }
    }
else if( EnumTachoFullScaleRPM15000 == tacho_fullscale )
    {
    switch( tacho_redzone_begin )
        {
        case 10000:
            tacho_colorbase_lz77_data = TACHO_COLORBASE_15000RPM_10000RED;
            tacho_colorbase_lz77_len  = TACHO_COLORBASE_15000RPM_10000RED_LEN;
            break;
        case 10500:
            tacho_colorbase_lz77_data = TACHO_COLORBASE_15000RPM_10500RED;
            tacho_colorbase_lz77_len  = TACHO_COLORBASE_15000RPM_10500RED_LEN;
            break;
        case 11000:
            tacho_colorbase_lz77_data = TACHO_COLORBASE_15000RPM_11000RED;
            tacho_colorbase_lz77_len  = TACHO_COLORBASE_15000RPM_11000RED_LEN;
            break;
        case 11500:
            tacho_colorbase_lz77_data = TACHO_COLORBASE_15000RPM_11500RED;
            tacho_colorbase_lz77_len  = TACHO_COLORBASE_15000RPM_11500RED_LEN;
            break;
        case 12000:
            tacho_colorbase_lz77_data = TACHO_COLORBASE_15000RPM_12000RED;
            tacho_colorbase_lz77_len  = TACHO_COLORBASE_15000RPM_12000RED_LEN;
            break;
        case 12500:
            tacho_colorbase_lz77_data = TACHO_COLORBASE_15000RPM_12500RED;
            tacho_colorbase_lz77_len  = TACHO_COLORBASE_15000RPM_12500RED_LEN;
            break;
        case 13000:
            tacho_colorbase_lz77_data = TACHO_COLORBASE_15000RPM_13000RED;
            tacho_colorbase_lz77_len  = TACHO_COLORBASE_15000RPM_13000RED_LEN;
            break;
        case 13500:
            tacho_colorbase_lz77_data = TACHO_COLORBASE_15000RPM_13500RED;
            tacho_colorbase_lz77_len  = TACHO_COLORBASE_15000RPM_13500RED_LEN;
            break;
        case 14000:
            tacho_colorbase_lz77_data = TACHO_COLORBASE_15000RPM_14000RED;
            tacho_colorbase_lz77_len  = TACHO_COLORBASE_15000RPM_14000RED_LEN;
            break;
        case 14500:
            tacho_colorbase_lz77_data = TACHO_COLORBASE_15000RPM_14500RED;
            tacho_colorbase_lz77_len  = TACHO_COLORBASE_15000RPM_14500RED_LEN;
            break;
        case 15000:
            tacho_colorbase_lz77_data = TACHO_COLORBASE_15000RPM_15000RED;
            tacho_colorbase_lz77_len  = TACHO_COLORBASE_15000RPM_15000RED_LEN;
            break;
        default:
            break;
        }
    }
else
    {
    /* empty */
    }

if( NULL != tacho_colorbase_lz77_data )
    {
    uint32_t start_tick = xTaskGetTickCount();
    lz77_decompress( tacho_colorbase_lz77_data, tacho_colorbase_lz77_len, tacho_colorbase_rgb888, TACHO_COLORBASE_RGB888_SIZE );
    EwPrint( "%s: %d ms\r\n", __FUNCTION__, ( xTaskGetTickCount() - start_tick ) );
    }
else
    {
    EwPrint( "Err: null tacho base\r\n" );
    }
}

/*********************************************************************
*
* @private
* ew_tacho_set_y_mask
*
* Set the start/end row of the y mask
*
* @param up_mask_y1   Start row of the up mask
* @param up_mask_y2,  End row of the up mask
* @param down_mask_y1 Start row of the down mask
* @param down_mask_y2 End row of the down mask
*
*********************************************************************/
void ew_tacho_set_y_mask
    (
    const int32_t up_mask_y1,
    const int32_t up_mask_y2,
    const int32_t down_mask_y1,
    const int32_t down_mask_y2
    )
{
display_param.up_mask_y1 = up_mask_y1;
display_param.up_mask_y2 = up_mask_y2;
display_param.down_mask_y1 = down_mask_y1;
display_param.down_mask_y2 = down_mask_y2;
}

/*********************************************************************
*
* @private
* ew_tacho_get_display_param
*
* Get tacho display parameters
*
* @return Tacho full scale
*
*********************************************************************/
tacho_display_param* ew_tacho_get_display_param
    (
    void
    )
{
return &display_param;
}

/*********************************************************************
*
* @private
* ew_tacho_get_fullscale
*
* Get tacho full scale
*
* @return Tacho full scale
*
*********************************************************************/
int32_t ew_tacho_get_fullscale
    (
    void
    )
{
return (int32_t)tacho_fullscale;
}

/*********************************************************************
*
* @private
* ew_tacho_get_readzone_begin
*
* Get tacho red zone begin
*
* @return Tacho red zone begin
*
*********************************************************************/
uint32_t ew_tacho_get_readzone_begin
    (
    void
    )
{
return tacho_redzone_begin;
}
