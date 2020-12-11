/*********************************************************************
* @file
* qr_main.c
*
* @brief
* QR code module
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "task.h"
#include "ewrte.h"
#include <stdio.h>
#include <string.h>
#include "semphr.h"
#include "fsl_debug_console.h"
#include "EW_pub.h"
#include "ricmoo_qrcode/qrcode.h"
#include "QR_pub.h"
#include "EEPM_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define QRCODE_WIDTH_MODULE         ( 33 )
#define QRCODE_MARGIN               ( 4 )
#define QRCODE_BUF_SIZE_BYTE        ( 1120 ) // 32 bytes alignment
#define QRCODE_VERSION              ( 2 )    // version 2 stands for 25x25
#define ESN_STR_MAX_LEN             ( 10 )
#define INVALID_ESN                 ( 0xFFFFFFFF )
#define UNIT_ID_LEN                 ( 24 )
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
AT_BOARDSDRAM_SECTION( uint8_t qrcode_buf[QRCODE_BUF_SIZE_BYTE] );
static char qr_code_text[UNIT_ID_LEN + 1];
static qrcode_buf_handle_struct qrcode_buf_handle;
static const int rule_lookup_table[UNIT_ID_LEN] = {7,14,20,0,12,17,6,22,2,13,10,1,16,19,8,21,23,5,15,3,9,18,4,11};
static uint32_t qr_pixel_num;
/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @private
* qr_encrypt_unit_id
*
* Encrypt unit id by using rule_lookup_table.
*
* @param esn Electronic Serial Number.
*
*********************************************************************/
static void qr_encrypt_unit_id
    (
    char* esn
    )
{
char unit_id_text[UNIT_ID_LEN + 1];
strncpy( unit_id_text, "ABCD", sizeof( unit_id_text ) );
strncat( unit_id_text, esn, ESN_STR_MAX_LEN + 1 );
strncat( unit_id_text, "1234567890", 10 );
unit_id_text[UNIT_ID_LEN] = '\0';

for( int i = 0; i < UNIT_ID_LEN; i++ )
    {
    qr_code_text[rule_lookup_table[i]] = unit_id_text[i];
    }
PRINTF( "QR code text: %s \n\r", qr_code_text );
}

/*********************************************************************
*
* @public
* QR_init
*
* Init QR code module.
*
*********************************************************************/
void QR_init
    (
    void
    )
{
qrcode_buf_handle.addr = ( void* )qrcode_buf;
}

/*********************************************************************
*
* @public
* QR_generate_qrcode
*
* Write QR code to RGB buffer.
*
* @param esn Electronic Serial Number.
* @param pixel_per_mod Pixel per module.
*
*********************************************************************/
void QR_generate_qrcode
    (
    uint32_t esn,
    uint32_t pixel_per_mod
    )
{
uint32_t qrcode_width_pixel = pixel_per_mod * QRCODE_WIDTH_MODULE;
qrcode_buf_handle.image_width = qrcode_width_pixel;
qrcode_buf_handle.image_height = qrcode_width_pixel;
qr_pixel_num = pixel_per_mod;

unsigned char* bgra_buf = qrcode_buf_handle.addr;
QRCode qrcode;
uint8_t qrcodeData[qrcode_getBufferSize( QRCODE_VERSION )];
char esn_decimal[ESN_STR_MAX_LEN + 1];

if( INVALID_ESN != esn )
    {
    sprintf( esn_decimal, "%u", esn );
    qr_encrypt_unit_id( esn_decimal );
    }
PRINTF( "ESN: %s \n\r", esn_decimal );

qrcode_initText( &qrcode, qrcodeData, QRCODE_VERSION, ECC_QUARTILE, qr_code_text );

if( qrcode.size > 0 )
    {
    // set to full white
    memset( qrcode_buf_handle.addr, 0xFF, QRCODE_BUF_SIZE_BYTE );

    for( int y = 0; y < QRCODE_WIDTH_MODULE; y++ ) // vertical direction
        {
        for( int x = 0; x < QRCODE_WIDTH_MODULE; x++ ) // horizontal direction
            {
            if( qrcode_getModule( &qrcode, x - QRCODE_MARGIN, y - QRCODE_MARGIN ) )
                {
                bgra_buf[y * QRCODE_WIDTH_MODULE + x] = 0x00;
                }
            }
        }
    EW_notify_qrcode_ready();
    }
}

/*********************************************************************
*
* @public
* QR_get_qrcode_buf
*
* Get the QR code buffer handle.
*
* @return The pointer to RGB buffer contained QR code.
*
*********************************************************************/
qrcode_buf_handle_struct* QR_get_qrcode_buf
    (
    void
    )
{
return &qrcode_buf_handle;
}

/*********************************************************************
*
* @public
* QR_pixel_per_mod
*
* Get the current pixel per module of QR code.
*
* @return The current pixel per module of QR code.
*
*********************************************************************/
uint32_t QR_pixel_per_mod
    (
    void
    )
{
return qr_pixel_num;
}