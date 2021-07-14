/*********************************************************************
* @file
* ew_copyright.c
*
* @brief
* EW module - handle copyright content
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
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

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define NUM_OF_LICENSE          ( 10 )
#define LEN_OF_LICENSE_NAME     ( 32 )
#define LEN_OF_LICENSE_CONTENT  ( 192 )

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
static const char license_title[NUM_OF_LICENSE][LEN_OF_LICENSE_NAME] =
    {
    "FreeRTOS",
    "libjpeg",
    "ricmoo_qrcode",
    "nanopb",
    "NotoSansCJKjp-Medium.otf",
    "NotoSansCJKtc-Medium.otf",
    "NotoSansDevanagari-Medium.ttf",
    "NotoSans-Medium.ttf",
    "NotoSansThai-Medium.ttf",
    "NotoSans-Bold.ttf"
    };

static const char license_content[NUM_OF_LICENSE][LEN_OF_LICENSE_CONTENT] =
    {
    "Copyright © 2020 Amazon.com, Inc. or its affiliates.",
    "Copyright © 2020 JPEG Reference",
    "Copyright © 2017 Richard Moore\n(https://github.com/ricmoo/QRCode)\nCopyright © 2017 Project Nayuki\n(https://www.nayuki.io/page/qr-code-generator-library)",
    "Copyright © 2011 Petteri Aimonen <jpa at nanopb.mail.kapsi.fi>",
    "SIL OPEN FONT LICENSE Version 1.1 - 26 February 2007",
    "SIL OPEN FONT LICENSE Version 1.1 - 26 February 2007",
    "SIL OPEN FONT LICENSE Version 1.1 - 26 February 2007",
    "SIL OPEN FONT LICENSE Version 1.1 - 26 February 2007",
    "SIL OPEN FONT LICENSE Version 1.1 - 26 February 2007",
    "SIL OPEN FONT LICENSE Version 1.1 - 26 February 2007"
    };

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @private
* ew_get_copyright
*
* Get copyright content.
*
* @param index The index of copyright
* @param copyright_title The title of copyright
* @param copyright_content The content of copyright
*
*********************************************************************/
void ew_get_copyright
    (
    const int index,
    uint8_t** copyright_title,
    uint8_t** copyright_content
    )
{
if( index < NUM_OF_LICENSE )
    {
    *copyright_title = (uint8_t*)license_title[index];
    *copyright_content = (uint8_t*)license_content[index];
    }
}

/*********************************************************************
*
* @private
* ew_get_num_of_licenses
*
* Get number of licenses.
*
* @return The number of licenses.
*
*********************************************************************/
int ew_get_num_of_licenses
    (
    void
    )
{
return NUM_OF_LICENSE;
}

