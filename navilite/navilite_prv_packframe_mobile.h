/*******************************************************************************
* @file
* navilite_prv_packframe_mobile.h
*
* @brief
* NAVILITE protocol pack frame public header file for mobile end
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
********************************************************************************/
#ifndef NAVILITE_PRV_PACKFRAME_MOBILE_H
#define NAVILITE_PRV_PACKFRAME_MOBILE_H

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
#include "TEST_pub.h"
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
#if( NAVILITE_BUILD_ROLE == NAVILITE_TARGET_MOBILE || NAVILITE_LOCAL_HMI_TEST_MODE || UNIT_TEST_NAVILITE )
/* NaviLite Protocol framing message API for mobile*/

navilite_message NAVILITE_pack_frame_update_imageframe            //! update image and type code to MCU
    (
    uint8_t* image,
    uint32_t image_size,
    navilite_image_type mode
    );

navilite_message NAVILITE_pack_frame_update_eta               //! update ETA to MCU
    (
    uint32_t value
    );

navilite_message NAVILITE_pack_frame_update_navigationstatus         //! update remain dist to MCU
    (
    uint8_t value
    );

navilite_message NAVILITE_pack_frame_update_speedlimit         //! update remain dist to MCU
    (
    uint16_t speed
    );

navilite_message NAVILITE_pack_frame_update_viapointcount
    (
    uint16_t count
    );

navilite_message NAVILITE_pack_frame_update_currentroadname    //! update ETA to MCU
    (
    uint8_t* str,
    uint8_t str_size
    );

navilite_message NAVILITE_pack_frame_update_nextturndistance  //! update next turn distance to MCU
    (
    uint8_t icon_index,
    uint8_t* str,
    uint8_t str_size
    );

navilite_message NAVILITE_pack_frame_update_nexttbtlist      //! update next turn list size to MCU
    (
    uint16_t list_size,
    uint8_t has_more_data
    );

navilite_message NAVILITE_pack_frame_update_nexttbtlist_itemdata    //! update next turn list item data to MCU
    (
    navilite_tbt_list_type *list
    );

navilite_message NAVILITE_pack_frame_update_nextfavlist      //! update next turn list size to MCU
    (
    uint16_t list_size,
    uint8_t has_more_data
    );

navilite_message NAVILITE_pack_frame_update_nextfavlist_itemdata    //! update next turn list item data to MCU
    (
    navilite_fav_list_type *list
    );

navilite_message NAVILITE_pack_frame_update_nextgaslist      //! update next turn list size to MCU
    (
    uint16_t list_size,
    uint8_t has_more_data
    );

navilite_message NAVILITE_pack_frame_update_nextgaslist_itemdata    //! update next turn list item data to MCU
    (
    navilite_gas_list_type *list
    );


navilite_message NAVILITE_pack_frame_update_activetbtitem    //! update active tbt item and inform MCU to show on HMI via peer's callback
    (
    uint16_t active_tbt_index
    );

navilite_message NAVILITE_pack_frame_update_navieventtext   //! update nZand inform MCU to show on HMI via peer's callback
    (
    uint8_t* event_text,
    uint8_t str_size,
    navilite_navievent_type navi_event_type,
    uint8_t visibility
    );

navilite_message NAVILITE_pack_frame_update_homelocationsetting
    (
    uint8_t is_home_location_setting
    );

navilite_message NAVILITE_pack_frame_update_officelocationsetting
    (
    uint8_t is_office_setting
    );

navilite_message NAVILITE_pack_frame_update_zoomlevel
    (
    uint8_t current_level,
    uint8_t max_level
    );

navilite_message NAVILITE_pack_frame_update_routecalcprogress  //timeout:10s and automatically callback to
    (
    uint8_t progress
    );

navilite_message NAVILITE_pack_frame_update_daynightmode
    (
    navilite_daynight_mode_type
    ); // daynight mode update

navilite_message NAVILITE_pack_frame_update_bttimeout
    (
    uint16_t timeout
    ); // bt timeout update

navilite_message NAVILITE_pack_frame_update_serviceack
    (
    navilite_service_type ack_service_type
    ); // used for ESN/Image Frame Update/ETC ACK

navilite_message NAVILITE_pack_frame_update_dialog_prompt
    (
    uint8_t dialog_id,
    navilite_dialog_type dialog_type,
    uint8_t* message,
    uint8_t message_size
    );

navilite_message NAVILITE_pack_frame_update_dialog_dismiss
    (
    uint8_t dialog_id
    );

#endif

#ifdef __cplusplus
}
#endif

#endif /* NAVILITE_PRV_PACKFRAME_MOBILE_H */
