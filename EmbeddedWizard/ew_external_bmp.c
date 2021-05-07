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
int           image_width  = FRAME_BUFFER_WIDTH;
int           image_height = FRAME_BUFFER_HEIGHT;

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
EwPrint( "%s %s\n", __FUNCTION__, name );

if( !strncmp( name, "Map", 3 ) )
    {
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
else
    {
    EwPrint( "%s invalid %s\n", __FUNCTION__, name );
    }

return bitmap;
}

