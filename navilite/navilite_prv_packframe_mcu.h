/*******************************************************************************
* @file
* navilite_prv_pack_frame_mcu.h
*
* @brief
* NAVILITE private pack frame header file
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
********************************************************************************/
#ifndef NAVILITE_PRV_pack_frame_MCU_H
#define NAVILITE_PRV_pack_frame_MCU_H

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <stdint.h>  // for uint8_t etc
#include <stdbool.h> // for bool
#include <stddef.h>  // for NULL
#include <string.h>  // for memset()

#include "NAVILITE_pub.h"

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
    navilite_message NAVILITE_pack_frame_app_startroute_request
        (
        uint16_t route_index
        );

    navilite_message NAVILITE_pack_frame_app_stoproute_request
        (
        void
        );

    navilite_message NAVILITE_pack_frame_app_skip_nextwaypoint
        (
        void
        );

    navilite_message NAVILITE_pack_frame_app_zoomin_request
        (
        void
        );

    navilite_message NAVILITE_pack_frame_app_zoomout_request
        (
        void
        );

    navilite_message NAVILITE_pack_frame_app_gohome_request
        (
        void
        );

    navilite_message NAVILITE_pack_frame_app_gooffice_request
        (
        void
        );

    navilite_message NAVILITE_pack_frame_app_get_favoritlist_request
        (
        void
        );

    navilite_message NAVILITE_pack_frame_app_get_stationlist_request
        (
        void
        );

    navilite_message NAVILITE_pack_frame_app_get_recentlist_request
        (
        void
        );

    navilite_message NAVILITE_pack_frame_app_enable_imageframe_update
        (
        navilite_switch_type enable
        );

    navilite_message NAVILITE_pack_frame_app_report_esn
        (
        uint8_t* esn
        );

    navilite_message NAVILITE_pack_frame_app_report_sysinfo
        (
        uint8_t* sysinfo
        );

    /* ACK back to mobile side */
    navilite_message NAVILITE_pack_frame_app_report_service_ack
        (
        navilite_service_type ack_service_type
        );

    navilite_message NAVILITE_pack_frame_app_report_dialog_select
        (
        uint8_t dialog_id,
        navilite_button_type button_type
        );
#endif

#ifdef __cplusplus
}
#endif

#endif /*NAVILITE_PUB_H */

