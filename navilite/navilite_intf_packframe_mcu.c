/*********************************************************************
* @file
* navilite_intf_pack_frame_mcu.c
*
* @brief
* NAVILITE protocol framing APIs for mcu
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/* NOTE: this is updated from MCU header to keep the protocol consistent from ECU and mobile apps, please do not change this file*/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "NAVILITE_pub.h"
#include "navilite_prv_packframe_mcu.h"
#include <stdlib.h>

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
    * NAVILITE_pack_frame_app_startroute_request
    *
    * Send start route request
    *
    * @param route_index
    *       >0 - route index on app side
    * @param route_option
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_app_startroute_request
        (
        uint32_t route_index,
        navilite_route_option_type route_option
        )
    {
    int full_data_size = sizeof( uint8_t ) * 5;
    navilite_message frame = { 0 };
    strncpy( (char*)frame.magic_code, (char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MOBILE_REQUEST;
    frame.service_type =  NAVILITE_SERVICETYPE_APP_START_ROUTE_REQUEST;
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_POINTER;
    frame.data_value = 0;
    frame.payload_size = full_data_size;
    uint8_t* packValues = (uint8_t*)malloc( full_data_size );
    *( (uint32_t*)packValues + 0 ) = route_index;
    packValues[4] = route_option;
    frame.data_pointer = (uint8_t*)packValues;
    return (navilite_message)frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_app_stoproute_request
    *
    * Send stop current route request
    *
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_app_stoproute_request
        (
        void
        )
    {
    navilite_message frame = { 0 };
    strncpy( (char*)frame.magic_code, (char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MOBILE_REQUEST;
    frame.service_type =  NAVILITE_SERVICETYPE_APP_STOP_ROUTE_REQUEST;
    frame.payload_size = 0;
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE;
    frame.data_value = 0;
    return (navilite_message)frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_app_skip_nextwaypoint
    *
    * Send skip next way point request
    *
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_app_skip_nextwaypoint
        (
        void
        )
    {
    navilite_message frame = { 0 };
    strncpy( (char*)frame.magic_code, (char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MOBILE_REQUEST;
    frame.service_type =  NAVILITE_SERVICETYPE_APP_SKIP_NEXT_WAYPOINT_REQUEST;
    frame.payload_size = 0;
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE;
    frame.data_value = 0;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_app_zoomin_request
    *
    * Send map zoom in request
    *
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_app_zoomin_request
        (
        void
        )
    {
    navilite_message frame = { 0 };
    strncpy( (char*)frame.magic_code, (char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MOBILE_REQUEST;
    frame.service_type =  NAVILITE_SERVICETYPE_APP_MAP_ZOOM_IN_REQUEST;
    frame.payload_size = 0;
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE;
    frame.data_value = 0;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_app_zoomout_request
    *
    * Send map zoom out request
    *
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_app_zoomout_request
        (
        void
        )
    {
    navilite_message frame = { 0 };
    strncpy( (char*)frame.magic_code, (char*)MAGIC_CODE , MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MOBILE_REQUEST;
    frame.service_type =  NAVILITE_SERVICETYPE_APP_MAP_ZOOM_OUT_REQUEST;
    frame.payload_size = 0;
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE;
    frame.data_value = 0;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_app_gohome_request
    *
    * Send go home request (route home if available)
    *
    * @param route_option route option to use
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_app_gohome_request
        (
        navilite_route_option_type route_option
        )
    {
    navilite_message frame = { 0 };
    strncpy( (char*)frame.magic_code, (char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MOBILE_REQUEST;
    frame.service_type =  NAVILITE_SERVICETYPE_APP_GO_HOME_REQUEST;
    frame.payload_size = sizeof( uint16_t );
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE;
    frame.data_value = route_option;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_app_gooffice_request
    *
    * Send go to office request (route to office if available)
    *
    * @param route_option route option to use
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_app_gooffice_request
        (
        navilite_route_option_type route_option
        )
    {
    navilite_message frame = { 0 };
    strncpy( (char*)frame.magic_code, (char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MOBILE_REQUEST;
    frame.service_type = NAVILITE_SERVICETYPE_APP_GO_OFFICE_REQUEST;
    frame.payload_size = sizeof( uint16_t );
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE;
    frame.data_value = route_option;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_app_enable_imageframe_update
    *
    * Send enable/disable image frame update request
    *
    * @param  enable true/false to enable/disable the image frame update
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_app_enable_imageframe_update
        (
        navilite_switch_type enable
        )
    {
    navilite_message frame = { 0 };
    frame = NAVILITE_pack_frame_app_enable_content_update( NAVILITE_CONTENT_TYPE_NAVI_IMAGE, enable );
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_app_enable_content_update
    *
    * Send enable/disable content update request
    *
    * @param content_type what content to enable/disable updating from app
    * @param enable true/false to enable/disable the image frame update
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_app_enable_content_update
        (
        navilite_content_type content_type,
        navilite_switch_type enable
        )
    {
    navilite_message frame = { 0 };
    strncpy( (char*)frame.magic_code, (char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MOBILE_REQUEST;
    if( enable == NAVILITE_ENABLE_TYPE_ENABLE )
        {
        frame.service_type = NAVILITE_SERVICETYPE_APP_START_CONTENT_UPDATE_REQUEST ;
        }
    else
        {
        frame.service_type = NAVILITE_SERVICETYPE_APP_STOP_CONTENT_UPDATE_REQUEST ;
        }
    frame.payload_size = sizeof( uint16_t );
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE;
    frame.data_value = content_type;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_app_report_esn
    *
    * Send ESN data to app side
    *
    * @param  esn  device number
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_app_report_esn
        (
        uint8_t* esn
        )
    {
    navilite_message frame = { 0 };
    strncpy( (char*)frame.magic_code, (char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MOBILE_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_MCU_ESN_UPDATE;
    frame.payload_size = strlen( (char*)esn );
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_POINTER;
    frame.data_pointer = esn;
    return frame; // @TODO: need to release the memory from this pointer after use from caller!
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_AppReportSYSINFO
    *
    * Send system info to app side
    *
    * @param  sysinfo system information
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_app_report_sysinfo
        (
        uint8_t* sysinfo
        )
    {
    navilite_message frame = { 0 };
    strncpy( (char*)frame.magic_code, (char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MOBILE_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_MCU_SYSINFO_UPDATE;
    frame.payload_size = strlen( (char*)sysinfo );
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_POINTER;
    frame.data_pointer = sysinfo;
    return frame; // @TODO: need to release the memory from this pointer after use from caller!
    }

    /*********************************************************************
    * @public
    * NAVILITE_pack_frame_app_report_service_ack
    *
    * Send service ack to app side
    *
    * @param  ack_service_type  what service type to ack back
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_app_report_service_ack
        (
        navilite_service_type ack_service_type
        )
    {
    navilite_message frame = { 0 };
    strncpy( (char*)frame.magic_code, (char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MOBILE_UPDATE;
    frame.service_type = ack_service_type;
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE;
    frame.payload_size = 0;
    return frame; // @TODO: need to release the memory from this pointer after use from caller!
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_app_report_dialog_select
    *
    * Send dialog select to app side
    *
    * @param dialog_id  dialog identifier to report
    * @param button_type button type selected from HMI to send
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_app_report_dialog_select
        (
        uint8_t dialog_id,
        navilite_button_type button_type
        )
    {
    navilite_message frame = { 0 };
    // full data size = dialog_id + dialog_type
    int full_data_size = sizeof( uint8_t ) * 2;
    uint8_t* packValues = (uint8_t*)malloc( full_data_size );
    packValues[0] = dialog_id;
    packValues[1] = button_type;
    strncpy( (char*)frame.magic_code, (char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MOBILE_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_MCU_DIALOG_USER_SELECT_UPDATE;
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_POINTER;
    frame.payload_size = sizeof( uint8_t ) * 2;
    frame.data_pointer = packValues;
    return frame;
    }
#endif

