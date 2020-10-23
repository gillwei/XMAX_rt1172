/*********************************************************************
* @file
* navilite_hmi_integration.c
*
* @brief
* NAVILITE module - hmi integration
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "limits.h"
#include "task.h"
#include "semphr.h"
#include "ewrte.h"
#include "fsl_debug_console.h"
#include "EW_pub.h"
#include "NAVILITE_pub.h"
#include "NAVI_pub.h"
/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/

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
* hmi_jpeg_decode_done
*
* Callback API for finishing JPEG decoding
*
* @param int result of JPEG decoding
*            return 1 when success, otherwise fail
*
*********************************************************************/
void hmi_jpeg_decode_done
    (
    int result
    )
{
if( 1 == result )
    {
    EW_notify_navi_map_update();
    }
else
    {
    PRINTF( "%s fail %d\r\n", __FUNCTION__, result );
    }
}

/*********************************************************************
*
* @private
* navilite_hmi_init_setup
*
* any setup procedure can be placed here, such as read ESN id
*
*********************************************************************/
void navilite_hmi_init_setup
    (
    void
    )
{
PRINTF( "[NAVILITE-HMI] hmi init setup code can be placed here if necessary !\r\n" );
}

/*********************************************************************
*
* @private
* hmi_update_callback_connected
*
* Callback API for navilite session is connected
*
* @param mode mode type for connection
*
*********************************************************************/
static void hmi_update_callback_connected
    (
    uint8_t mode
    )
{
PRINTF( "[NAVILITE-HMI] NAVILITE session connected!\r\n" );
}

/*********************************************************************
*
* @private
* hmi_update_callback_disconnected
*
* Callback API for navilite session is disconnected
*
* @param mode mode type for connection
*
*********************************************************************/
static void hmi_update_callback_disconnected
    (
    uint8_t mode
    )
{
PRINTF( "[NAVILITE-HMI] NAVILITE session disconnected!\r\n" );
}

/*********************************************************************
*
* @private
* hmi_update_callback_imageframe
*
* Callback API for image frame update
*
* @param image data pointer of image frame received
* @param image_size data size of image frame received
* @param mode mode type for the image frame
*
*********************************************************************/
static void hmi_update_callback_imageframe
    (
    uint8_t* image,
    uint16_t image_size,
    navilite_image_type mode
    )
{
PRINTF( "\r\n[ImageFrame] image size = %d, addr = 0x%x mode=%d, FB=%d,FB1=%d,FB256=%d,LB=%d\r\n", image_size, image, mode, image[ 0 ], image[ 1 ], image[ 256 ], image[ image_size - 1 ] );

if( image_size > 0 && JPEG_is_valid( image, image_size ) )
    {
    uint8_t* jpeg_buf = (uint8_t*)JPEG_get_jpeg_buffer();
    PRINTF( "DEBUG: JPEG_get_jpeg_buffer = 0x%x\r\n",jpeg_buf );
    if( NULL != jpeg_buf )
        {
        memcpy( jpeg_buf, image, image_size );
        JPEG_notify_received( image_size, jpeg_buf, &hmi_jpeg_decode_done );
        }
    else
        {
        PRINTF( "# ERROR: JPEG BUFFER NOT AVAIL\r\n" );
        }
    }
else
    {
    PRINTF( "# ERROR: INVALID JPEG DATA\r\n");
    }
}

/*********************************************************************
*
* @private
* hmi_update_callback_currentroadname
*
* Callback API for current road name update
*
* @param current_roadname data pointer of road name recieved
* @param str_size data size of road name string received
*
*********************************************************************/
static void hmi_update_callback_currentroadname
    (
    uint8_t* str,
    uint8_t str_size
    )
{
PRINTF( "\r\n[NAVILITE-CB] [RoadName：%d]:", str_size );
NAVILITE_print_utf8( str, str_size );
PRINTF( "\r\n" );
}

/*********************************************************************
*
* @private
* hmi_update_callback_eta
*
* Callback API for ETA update
*
* @param value value of ETA received
*
*********************************************************************/
static void  hmi_update_callback_eta
    (
    uint32_t value
    )
{
PRINTF( "\r\n[NAVILITE-CB] [ETA value]:%d\r\n", value );
}

// remove the _DISABLE when command is supported both on app and mcu
#if( NAVILITE_FUNC_DISABLED )
    static void hmi_update_callback_activetbtlistitem
        (
        uint8_t tbt_index
        )

    {
    PRINTF( "\r\n[ActiveTBTListItem:%d]:", tbt_index );
    }

    static void hmi_update_callback_navieventtext
        (
        uint8_t* navi_event_text,
        uint8_t str_size,
        navilite_navievent_type navi_event_type,
        uint8_t visibility
        )
    {
    PRINTF( "\r\n[NaviEventText:%s, visibilty:%d]:", strlen( (char*)navi_event_text ), visibility );
    NAVILITE_print_utf8( navi_event_text, str_size );
    }

    static void hmi_update_callback_homelocationsetting
        (
        uint8_t is_home_location
        )
    {
    PRINTF( "\r\nhome location setting:%d", is_home_location );
    }

    static void hmi_update_callback_officelocationsetting
        (
        uint8_t is_office_location
        )
    {
    PRINTF( "\r\noffice location setting:%d", is_office_location );
    }

    static void hmi_update_callback_hardkeyreportrequest
        (
        uint8_t enable
        )
    {
    PRINTF( "\r\n got hardkey report request: %d ", enable );
    }

    static void hmi_update_callback_zoomlevel
        (
        uint8_t current_level,
        uint8_t max_level
        )
    {
    PRINTF( "\r\n zoom level: current:%d, max(%d) ", current_level, max_level );
    }

    static void hmi_update_callback_routecalcprogress  //timeout:10s and automatically callback to
        (
        uint8_t progress
        )
    {
    PRINTF( "\r\n Route Calc Progress: %d ", progress );
    }

    static void hmi_update_callback_daynightmode
        (
        navilite_daynight_type mode
        )
    {
    PRINTF( "\r\n DayNight Mode: %d", mode );
    }

    static void hmi_update_callback_btsignalquality
        (
        navilite_btsignal_quality_type signal_status
        )
    {
    PRINTF( "\r\n BT signal quality: %d", signal_status );
    }
#endif

/*********************************************************************
*
* @public
* NAVILITE_hmi_integration_setup
*
* HMI integration setup entry for callback register using the navilite callbacks
*
*********************************************************************/
void NAVILITE_hmi_integration_setup
    (
    void
    )
{
// HMI integration example to setup user-defined callbacks.
// when data is received, the user-defined callback will be triggered.
// @TODO: add more APIs, initially the RoadName API is added for HMI integration test purpose
PRINTF("\r\n[HMI integration setup by registering the navi content API's callbacks for image mode, roadname update, and etc]\r\n");
#if( !UNIT_TEST_NAVILITE )
    NAVILITE_register_update_callback_connected( hmi_update_callback_connected );
    NAVILITE_register_update_callback_disconnected( hmi_update_callback_disconnected );
#endif

NAVILITE_register_update_callback_imageframe( hmi_update_callback_imageframe );
NAVILITE_register_update_callback_currentroadname( hmi_update_callback_currentroadname );
NAVILITE_register_update_callback_eta( hmi_update_callback_eta );

// remove the _DISABLE  when command is supported both on app and mcu
#if( NAVILITE_FUNC_DISABLED )
    NAVILITE_register_update_callback_remaindist( hmi_update_callback_RemainDist );
    NAVILITE_register_update_callback_active_tbtlistitem( hmi_update_callback_ActiveTBTListItem );
    NAVILITE_register_update_callback_navieventtext( hmi_update_callback_NaviEventText );
    NAVILITE_register_update_callback_homelocationsetting( hmi_update_callback_HomeLocationSetting );
    NAVILITE_register_update_callback_officelocationsetting( hmi_update_callback_OfficeLocationSetting );
    NAVILITE_register_update_callback_hardkey_report_request( hmi_update_callback_HardKeyReportRequest );
    NAVILITE_register_update_callback_zoomlevel( hmi_update_callback_ZoomLevel );
    NAVILITE_register_update_callback_routecalc_progress( hmi_update_callback_RouteCalcProgress );
    NAVILITE_register_update_callback_daynight_mode( hmi_update_callback_DayNightMode );
    NAVILITE_register_update_callback_btsignal_quality( hmi_update_callback_BTSignalQuality );
#endif
}
