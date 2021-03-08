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
    *        0 - default route
    *       >0 - route index on app side
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_app_startroute_request
        (
        uint16_t route_index
        )
    {
    navilite_message frame = { 0 };
    strncpy( (char*)frame.magic_code, (char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MOBILE_REQUEST;
    frame.service_type =  NAVILITE_SERVICETYPE_APP_START_ROUTE_REQUEST;
    frame.payload_size = sizeof( uint16_t );
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE;
    frame.data_value = route_index; /* 0 - default planned route */
                                   /* >0 - route Index for POI from Fav/Gas/etc.. */
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
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_app_gohome_request
        (
        void
        )
    {
    navilite_message frame = { 0 };
    strncpy( (char*)frame.magic_code, (char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MOBILE_REQUEST;
    frame.service_type =  NAVILITE_SERVICETYPE_APP_GO_HOME_REQUEST;
    frame.payload_size = 0;
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE;
    frame.data_value = 0;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_app_gooffice_request
    *
    * Send go to office request (route to office if available)
    *
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_app_gooffice_request
        (
        void
        )
    {
    navilite_message frame = { 0 };
    strncpy( (char*)frame.magic_code, (char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MOBILE_REQUEST;
    frame.service_type = NAVILITE_SERVICETYPE_APP_GO_OFFICE_REQUEST;
    frame.payload_size = 0;
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE;
    frame.data_value = 0;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_app_get_favoritlist_request
    *
    * Send get favorite list mode request
    *
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_app_get_favoritlist_request
        (
        void
        )
    {
    navilite_message frame = { 0 };
    strncpy( (char*)frame.magic_code, (char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MOBILE_REQUEST;
    frame.service_type = NAVILITE_SERVICETYPE_APP_GET_FAVORITE_LIST_REQUEST ;
    frame.payload_size = 0;
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE;
    frame.data_value = 0;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_app_get_stationlist_request
    *
    * Send get station list request
    *
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_app_get_stationlist_request
        (
        void
        )
    {
    navilite_message frame = { 0 };
    strncpy( (char*)frame.magic_code, (char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MOBILE_REQUEST;
    frame.service_type = NAVILITE_SERVICETYPE_APP_GET_STATION_LIST_REQUEST ;
    frame.payload_size = 0;
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE;
    frame.data_value = 0;
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
    strncpy( (char*)frame.magic_code, (char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MOBILE_REQUEST;
    if( enable == NAVILITE_ENABLE_TYPE_ENABLE )
        {
        frame.service_type = NAVILITE_SERVICETYPE_APP_START_IMAGE_FRAME_REQUEST ;
        }
    else
        {
        frame.service_type = NAVILITE_SERVICETYPE_APP_STOP_IMAGE_FRAME_REQUEST ;
        }
    frame.payload_size = 0;
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE;
    frame.data_value = enable;  // NOTE: navilite_switch_type enable/disable
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
#endif

