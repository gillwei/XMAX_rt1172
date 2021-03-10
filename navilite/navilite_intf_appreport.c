/*********************************************************************
* @file
* navilite_intf_apprequest.c
*
* @brief
* NAVILITE module - vehicle information report APIs
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
#include "NAVILITE_pub.h"
#include "navilite_prv_packframe.h"

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

#if( NAVILITE_BUILD_ROLE == NAVILITE_TARGET_MCU )
    /*********************************************************************
    *
    * @public
    * NAVILITE_report_app_esn
    *
    * Send ESN to app side
    *
    * @param esn ESN info of hardware
    * @return true when success
    *         false when failed
    *
    *********************************************************************/
    bool NAVILITE_report_app_esn
        (
        uint8_t* esn
        )
    {
    navilite_message frame = NAVILITE_pack_frame_app_report_esn( esn );
    bool ret = NAVILITE_send( (uint8_t*)&frame, sizeof( navilite_message ) );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_report_app_sysinfo
    *
    * Send system info to app side
    *
    * @param sysinfo system info of hardware
    * @return true when success
    *         false when failed
    *
    *********************************************************************/
    bool NAVILITE_report_app_sysinfo
        (
        uint8_t* sysinfo
        )
    {
    navilite_message frame = NAVILITE_pack_frame_app_report_sysinfo( sysinfo );
    bool ret = NAVILITE_send( (uint8_t*)&frame, sizeof( navilite_message ) );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_report_app_service_ack
    *
    * Send ack based on service type (ack-based) to app side for acknowledgment

    * @param  ack_service_type ack service type
    * @return true when success
    *         false when failed
    *
    *********************************************************************/
    bool NAVILITE_report_app_service_ack
        (
        navilite_service_type ack_service_type
        )
    {
    navilite_message frame = NAVILITE_pack_frame_app_report_service_ack( ack_service_type );
    #if NAVILITE_SESSION_ACK_SERIAL_SUPPORT
        static uint8_t frame_counter = 0;
        frame.data_value = frame_counter++ % 4096;
        frame.payload_size = sizeof( uint16_t );
    #endif
    bool ret = NAVILITE_send( (uint8_t*)&frame, sizeof( navilite_message ) );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_report_app_dialog_select
    *
    * Send dialog selection (dialog_id/button_type) to app side
    *
    * @param dialog_id dialog id to send
    * @param button_type button type to send
    * @return true when success
    *         false when failed
    *
    *********************************************************************/
    bool NAVILITE_report_app_dialog_select
        (
        uint8_t dialog_id,
        navilite_button_type button_type
        )
    {
    navilite_message frame = NAVILITE_pack_frame_app_report_dialog_select( dialog_id, button_type );
    bool ret = NAVILITE_send( (uint8_t*)&frame, sizeof( navilite_message ) );
    return ret;
    }

#endif
