/*********************************************************************
* @file
* display_support.h
*
* @brief
* display module - public API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef _DISPLAY_SUPPORT_H_
#define _DISPLAY_SUPPORT_H_

#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "fsl_dc_fb.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/

#define DEMO_PANEL_WIDTH        ( 480 )
#define DEMO_PANEL_HEIGHT       ( 272 )

typedef enum
    {
    TFT_CONNECTED,             //!< TFT is connected to the Board
    TFT_NOT_CONNECTED,         //!< TFT is not connected to the Board
    } TFT_CONNECT_STATUS;

/* There is not frame buffer aligned requirement, consider the 64-bit AXI data
 * bus width and 32-byte cache line size, the frame buffer alignment is set to
 * 32 byte.
 */
#define FRAME_BUFFER_ALIGN 32

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
extern const dc_fb_t g_dc;

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
status_t BOARD_PrepareDisplayController
    (
    void
    );

uint32_t BOARD_is_tft_connected
    (
    void
    );

void display_monitor_init
    (
    void
    );

void display_pre_handler
    (
    void
    );

bool display_is_tft_backlight_on
    (
    void
    );

#ifdef __cplusplus
}
#endif

#endif /* _DISPLAY_SUPPORT_H_ */
