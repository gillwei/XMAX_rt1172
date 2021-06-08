/*********************************************************************
* @file
* ew_external_bmp.c
*
* @brief
* EW module - load external bmp
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "fsl_common.h"

#include "ewconfig.h"
#include "ewrte.h"
#include "ewgfxdriver.h"
#include "ewextgfx.h"
#include "ewgfxdefs.h"

#if( EW_FRAME_BUFFER_COLOR_FORMAT_RGB888 == EW_FRAME_BUFFER_COLOR_FORMAT )
    #include "ewextpxl_RGB888.h"
#elif( EW_FRAME_BUFFER_COLOR_FORMAT_RGB565 == EW_FRAME_BUFFER_COLOR_FORMAT )
    #include "ewextpxl_RGB565.h"
#endif

#include "ewgfx.h"
#include "JPEG_pub.h"
#include "QR_pub.h"
#include "ew_priv.h"
#include "ew_tacho.h"
#include "ew_tacho_x_mask.h"
#include "ew_tacho_y_mask.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define ew_load_external_bmp    EwLoadExternBitmap
#define ALPHA_DEFAULT           ( 255 )

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
* load_external_map
*
* Load external RGB data to XBitmap.
*
* @return XBitmap
*
*********************************************************************/
static XBitmap* load_external_map
    (
    void
    )
{
XBitmap*      bitmap = NULL;
XPoint        frame_size;
XRect         bmp_lock_area;
XBitmapLock*  lock;
unsigned int* dest;
int           ofs;
int           x;
int           y;
unsigned int  alpha = ALPHA_DEFAULT;
buffer_info*  rgb_buffer_handle;
uint8_t*      rgb_buffer;
int           image_width;
int           image_height;

rgb_buffer_handle = JPEG_take_rgb();
if( NULL != rgb_buffer_handle )
    {
    rgb_buffer   = rgb_buffer_handle->addr;
    image_width  = rgb_buffer_handle->image_width;
    image_height = rgb_buffer_handle->image_height;

    /* create a new bitmap with the previously determined size */
    frame_size.X = image_width;
    frame_size.Y = image_height;
    bitmap       = EwCreateBitmap( EW_PIXEL_FORMAT_NATIVE, frame_size, 0, 1 );

    /* check if enough memory to create the bitmap */
    if( NULL == bitmap )
        {
        EwPrint( "%s: Err: create bitmap fail\r\n", __FUNCTION__ );
        return NULL;
        }

    /* lock the entire bitmap for write operation */
    bmp_lock_area.Point1.X = 0;
    bmp_lock_area.Point1.Y = 0;
    bmp_lock_area.Point2.X = image_width;
    bmp_lock_area.Point2.Y = image_height;
    lock = EwLockBitmap( bitmap, 0, bmp_lock_area, 0, 1 );

    /* Get the pointer to the first pixel within the locked bitmap.
     * In the RGBA8888 format every pixel is a 32-bit value (unsigned int).
     * Additionally calculate the offset in pixel between the end of one row
     * and the begin of the next row. */
    dest = ( unsigned int* ) lock->Pixel1;
    ofs  = ( lock->Pitch1Y / 4 ) - image_width;

    /* Iterate through the pixel within the locked bitmap area.
     * Do this row-by-row and column-by-column.
     * After one row is finished adjust the 'dest' pointer to refer to the next row.
     * After one column is finished increment the 'dest' pointer only. */
    int rgb_idx = 0;
    for( y = 0; y < image_height; y++, dest += ofs )
        {
        for( x = 0; x < image_width; x++, dest++ )
            {
            *dest = ( ( rgb_buffer[rgb_idx] << EW_COLOR_CHANNEL_BIT_OFFSET_RED ) |
                      ( rgb_buffer[rgb_idx+1] << EW_COLOR_CHANNEL_BIT_OFFSET_GREEN ) |
                      ( rgb_buffer[rgb_idx+2] << EW_COLOR_CHANNEL_BIT_OFFSET_BLUE ) |
                      ( alpha << EW_COLOR_CHANNEL_BIT_OFFSET_ALPHA ) );
            rgb_idx += 3;
            }
        }

    EwUnlockBitmap( lock );
    JPEG_give_rgb();
    }
return bitmap;
}

/*********************************************************************
*
* @private
* load_external_qrcode
*
* Load QR code to XBitmap.
*
* @return XBitmap
*
*********************************************************************/
static XBitmap* load_external_qrcode
    (
    void
    )
{
XBitmap*      bitmap;
XPoint        frame_size;
XRect         bmp_lock_area;
XBitmapLock*  lock;
unsigned int* dest;
int           ofs;
qrcode_buf_handle_struct* buf_handle = QR_get_qrcode_buf();
uint8_t*      modules      = buf_handle->modules;
int           image_width  = buf_handle->module_num * QRCODE_PIXEL_PER_MODULE;
int           image_height = buf_handle->module_num * QRCODE_PIXEL_PER_MODULE;
unsigned int  alpha        = ALPHA_DEFAULT;

/* create a new bitmap with the previously determined size */
frame_size.X = image_width;
frame_size.Y = image_height;
bitmap       = EwCreateBitmap( EW_PIXEL_FORMAT_NATIVE, frame_size, 0, 1 );

/* check if enough memory to create the bitmap */
if( NULL == bitmap )
    {
    EwPrint( "%s: Err: create bitmap fail\r\n", __FUNCTION__ );
    return NULL;
    }

/* lock the entire bitmap for write operation */
bmp_lock_area.Point1.X = 0;
bmp_lock_area.Point1.Y = 0;
bmp_lock_area.Point2.X = image_width;
bmp_lock_area.Point2.Y = image_height;
lock = EwLockBitmap( bitmap, 0, bmp_lock_area, 0, 1 );

/* Get the pointer to the first pixel within the locked bitmap.
 * In the RGBA8888 format every pixel is a 32-bit value (unsigned int).
 * Additionally calculate the offset in pixel between the end of one row
 * and the begin of the next row. */
dest = ( unsigned int* ) lock->Pixel1;
ofs  = ( lock->Pitch1Y / 4 ) - image_width;

/* Iterate through the pixel within the locked bitmap area.
 * Do this row-by-row and column-by-column.
 * After one row is finished adjust the 'dest' pointer to refer to the next row.
 * After one column is finished increment the 'dest' pointer only. */
for( int y = 0; y < image_height; y++, dest += ofs )
    {
    for( int x = 0; x < image_width; x++, dest++ )
        {
        if( 0x00 == modules[( ( y / QRCODE_PIXEL_PER_MODULE ) * ( image_height / QRCODE_PIXEL_PER_MODULE ) + ( x / QRCODE_PIXEL_PER_MODULE ) )] )
            {
            *dest = 0x00 | ( alpha << EW_COLOR_CHANNEL_BIT_OFFSET_ALPHA );
            }
        else
            {
            *dest = ( ( 0xFF  << EW_COLOR_CHANNEL_BIT_OFFSET_RED ) |
                      ( 0xFF  << EW_COLOR_CHANNEL_BIT_OFFSET_GREEN ) |
                      ( 0xFF  << EW_COLOR_CHANNEL_BIT_OFFSET_BLUE )  |
                      ( alpha << EW_COLOR_CHANNEL_BIT_OFFSET_ALPHA ) );
            }
        }
    }

EwUnlockBitmap( lock );
return bitmap;
}

/*********************************************************************
*
* @private
* load_display_flicker
*
* Load display flicker pattern to XBitmap.
*
* @return XBitmap
*
*********************************************************************/
static XBitmap* load_display_flicker
    (
    void
    )
{
XBitmap*      bitmap;
XPoint        frame_size;
XRect         bmp_lock_area;
XBitmapLock*  lock;
unsigned int* dest;
int           ofs;
int           x;
int           y;
int           image_width  = EW_FRAME_BUFFER_WIDTH;
int           image_height = EW_FRAME_BUFFER_HEIGHT;

/* create a new bitmap with the previously determined size */
frame_size.X = image_width;
frame_size.Y = image_height;
bitmap       = EwCreateBitmap( EW_PIXEL_FORMAT_NATIVE, frame_size, 0, 1 );

/* check if enough memory to create the bitmap */
if( NULL == bitmap )
    {
    EwPrint( "%s: Err: create bitmap fail\r\n", __FUNCTION__ );
    return NULL;
    }

/* lock the entire bitmap for write operation */
bmp_lock_area.Point1.X = 0;
bmp_lock_area.Point1.Y = 0;
bmp_lock_area.Point2.X = image_width;
bmp_lock_area.Point2.Y = image_height;
lock = EwLockBitmap( bitmap, 0, bmp_lock_area, 0, 1 );

/* Get the pointer to the first pixel within the locked bitmap.
 * In the RGBA8888 format every pixel is a 32-bit value (unsigned int).
 * Additionally calculate the offset in pixel between the end of one row
 * and the begin of the next row. */
dest = ( unsigned int* ) lock->Pixel1;
ofs  = ( lock->Pitch1Y / 4 ) - image_width;

/* Iterate through the pixel within the locked bitmap area.
 * Do this row-by-row and column-by-column.
 * After one row is finished adjust the 'dest' pointer to refer to the next row.
 * After one column is finished increment the 'dest' pointer only. */
unsigned int argb;
for( y = 0; y < image_height; y++, dest += ofs )
    {
    for( x = 0; x < image_width; x++, dest++ )
        {
        int x_pattern = x % 4;
        if( 0 == ( y & 0x1 ) )
            {
            switch( x_pattern )
                {
                case 0:  argb = 0xFF000080; break;
                case 1:  argb = 0xFF008080; break;
                case 2:  argb = 0xFF808000; break;
                case 3:  argb = 0xFF800000; break;
                default: argb = 0x00000000; break;
                }
            }
        else
            {
            switch( x_pattern )
                {
                case 0:  argb = 0xFF808000; break;
                case 1:  argb = 0xFF800000; break;
                case 2:  argb = 0xFF000080; break;
                case 3:  argb = 0xFF008080; break;
                default: argb = 0x00000000; break;
                }
            }
        *dest = argb;
        }
    }

EwUnlockBitmap( lock );
return bitmap;
}

/*********************************************************************
*
* @private
* load_tacho_colorbase
*
* Load tacho visualizer color base to XBitmap
*
* @return XBitmap
*
*********************************************************************/
static XBitmap* load_tacho_colorbase
    (
    const tacho_colorbase_part_e colorbase_part
    )
{
XBitmap*      bitmap = NULL;
XPoint        frame_size;
XRect         bmp_lock_area;
XBitmapLock*  lock;
unsigned int* dest;
int           ofs;
int           x;
int           y;
int           image_width;
int           image_height;
uint8_t       alpha_hor = 0;
uint8_t       alpha_ver = 0;
int           alpha_hor_idx = 0;
int           rgb_idx   = 0;
uint8_t*      tacho_colorbase_rgb888;
tacho_display_param* display_param = ew_tacho_get_display_param();

boundary_s colorbase_boundary;
if( TACHO_COLORBASE_PART_UP == colorbase_part )
    {
    colorbase_boundary = display_param->up_colorbase_boundary;
    }
else
    {
    colorbase_boundary = display_param->down_colorbase_boundary;
    }

image_width  = colorbase_boundary.x2 - colorbase_boundary.x1;
image_height = colorbase_boundary.y2 - colorbase_boundary.y1;

if( ( 0 < image_width ) && ( TACHO_COLORBASE_WIDTH >= colorbase_boundary.x2 ) &&
    ( 0 < image_height ) && ( TACHO_COLORBASE_HEIGHT >= colorbase_boundary.y2 ) )
    {
    /* create a new bitmap with the previously determined size */
    frame_size.X = image_width;
    frame_size.Y = image_height;
    bitmap       = EwCreateBitmap( EW_PIXEL_FORMAT_NATIVE, frame_size, 0, 1 );

    /* check if enough memory to create the bitmap */
    if( NULL != bitmap )
        {
        /* lock the entire bitmap for write operation */
        bmp_lock_area.Point1.X = 0;
        bmp_lock_area.Point1.Y = 0;
        bmp_lock_area.Point2.X = image_width;
        bmp_lock_area.Point2.Y = image_height;
        lock = EwLockBitmap( bitmap, 0, bmp_lock_area, 0, 1 );

        /* Get the pointer to the first pixel within the locked bitmap.
         * In the RGBA8888 format every pixel is a 32-bit value (unsigned int).
         * Additionally calculate the offset in pixel between the end of one row
         * and the begin of the next row. */
        dest = (unsigned int*) lock->Pixel1;
        ofs  = ( lock->Pitch1Y / 4 ) - image_width;

        ew_tacho_get_colorbase( &tacho_colorbase_rgb888 );

        int up_mask_start_row   = display_param->up_mask_y1;
        int up_mask_end_row     = display_param->up_mask_y2;
        int down_mask_start_row = display_param->down_mask_y1;
        int down_mask_end_row   = display_param->down_mask_y2;
        int up_mask_offset      = TACHO_Y_MASK_HEIGHT - ( up_mask_end_row - up_mask_start_row );
        uint32_t alpha_dest = 0;

        /* Iterate through the pixel within the locked bitmap area.
         * Do this row-by-row and column-by-column.
         * After one row is finished adjust the 'dest' pointer to refer to the next row.
         * After one column is finished increment the 'dest' pointer only. */
        for( y = colorbase_boundary.y1; y < colorbase_boundary.y2; y++, dest += ofs )
            {
            alpha_hor_idx = TACHO_X_MASK_WIDTH * y ;
            rgb_idx       = ( TACHO_COLORBASE_WIDTH * y + colorbase_boundary.x1 ) * TACHO_COLORBASE_COLOR_DEPTH;

            /* get vertical alpha mask */
            if( ( y <= up_mask_start_row ) || ( y >= down_mask_end_row ) )
                {
                alpha_ver = 0;
                }
            else if( y >= up_mask_start_row && y < up_mask_end_row )
                {
                alpha_ver = TACHO_MASK_Y_UP[y - up_mask_start_row + up_mask_offset];
                }
            else if( y >= down_mask_start_row && y < down_mask_end_row )
                {
                alpha_ver = TACHO_MASK_Y_DOWN[y - down_mask_start_row];
                }
            else
                {
                alpha_ver = ALPHA_DEFAULT;
                }

            /* iterate horizontal direction */
            for( x = 0; x < image_width; x++, dest++, rgb_idx += TACHO_COLORBASE_COLOR_DEPTH )
                {
                alpha_hor = TACHO_MASK_X[alpha_hor_idx + TACHO_X_MASK_WIDTH - image_width + x];

                if( 0 == alpha_ver || 0 == alpha_hor )
                    {
                    alpha_dest = 0;
                    }
                else if( ALPHA_DEFAULT == alpha_ver )
                    {
                    alpha_dest = alpha_hor;
                    }
                else
                    {
                    alpha_dest = ( alpha_hor * alpha_ver ) >> 8;
                    }

                if( alpha_dest > 0 )
                    {
                    *dest = ( ( alpha_dest                          << EW_COLOR_CHANNEL_BIT_OFFSET_ALPHA ) |
                              ( tacho_colorbase_rgb888[rgb_idx]     << EW_COLOR_CHANNEL_BIT_OFFSET_RED )   |
                              ( tacho_colorbase_rgb888[rgb_idx + 1] << EW_COLOR_CHANNEL_BIT_OFFSET_GREEN ) |
                              ( tacho_colorbase_rgb888[rgb_idx + 2] << EW_COLOR_CHANNEL_BIT_OFFSET_BLUE ) );
                    }
                else
                    {
                    *dest = 0;
                    }
                }
            }

        EwUnlockBitmap( lock );
        }
    else
        {
        EwPrint( "%s: null bmp\r\n", __FUNCTION__ );
        }
    }
else
    {
    PRINTF( "invalid color bound %d %d %d %d\r\n",
            colorbase_boundary.x1, colorbase_boundary.y1,
            colorbase_boundary.x2, colorbase_boundary.y2 );
    }
return bitmap;
}

/*********************************************************************
*
* @private
* ew_load_external_bmp
*
* The callback function from Embedded Wizard to load external bmp.
*
* @param bmp_name The bitmap name to load.
* @return XBitmap
*
*********************************************************************/
XBitmap* ew_load_external_bmp
    (
    XString bmp_name
    )
{
char name[32];
XBitmap* bitmap = NULL;

/* convert the 16-bit wide character string in 8-bit ANSI string */
EwStringToAnsi( bmp_name, name, sizeof( name ), 0 );

if( !strncmp( name, "Map", 3 ) )
    {
    EwPrint( "%s %s\n", __FUNCTION__, name );
    bitmap = load_external_map();
    JPEG_notify_rgb_loaded();
    }
else if( !strncmp( name, "DisplayFlicker", 14 ) )
    {
    bitmap = load_display_flicker();
    }
else if( !strncmp( name, "QRCode", 6 ) )
    {
    bitmap = load_external_qrcode();
    }
else if( !strncmp( name, "TachoUp", 7 ) )
    {
    bitmap = load_tacho_colorbase( TACHO_COLORBASE_PART_UP );
    }
else if( !strncmp( name, "TachoDown", 9 ) )
    {
    bitmap = load_tacho_colorbase( TACHO_COLORBASE_PART_DOWN );
    }
else
    {
    /* empty */
    }

return bitmap;
}

