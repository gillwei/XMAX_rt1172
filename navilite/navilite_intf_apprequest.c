/*********************************************************************
* @file
* navilite_intf_apprequest.c
*
* @brief
* NAVILITE module - navigation related request APIs
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
    * NAVILITE_request_app_startroute
    *
    * Send start route request to app side
    *
    * @param route_index route index to use
    * @param route_option route option to use
    * @return true when success
    *         false when failed
    *
    *********************************************************************/
    bool NAVILITE_request_app_startroute
        (
        uint32_t route_index,
        navilite_route_option_type route_option
        )
    {
    navilite_message frame = NAVILITE_pack_frame_app_startroute_request( route_index, route_option );
    bool ret = NAVILITE_send( (uint8_t*)&frame, sizeof( navilite_message ) );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_request_app_stoproute
    *
    * Send stop route request to app side
    *
    * @return true when success
    *         false when failed
    *
    *********************************************************************/
    bool NAVILITE_request_app_stoproute
        (
        void
        )
    {
    navilite_message frame = NAVILITE_pack_frame_app_stoproute_request();
    bool ret = NAVILITE_send( (uint8_t*)&frame, sizeof( navilite_message ) );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_request_app_skip_nextwaypoint
    *
    * send skip next way point request to app side
    *
    * @return true when success
    *         false when failed
    *
    *********************************************************************/
    bool NAVILITE_request_app_skip_nextwaypoint
        (
        void
        )
    {
    navilite_message frame = NAVILITE_pack_frame_app_skip_nextwaypoint();
    bool ret = NAVILITE_send( (uint8_t*)&frame, sizeof( navilite_message ) );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_request_app_zoomin
    *
    * send zoom in request to app side
    *
    * @return true when success
    *         false when failed
    *
    *********************************************************************/
    bool NAVILITE_request_app_zoomin
        (
        void
        )
    {
    navilite_message frame = NAVILITE_pack_frame_app_zoomin_request();
    bool ret = NAVILITE_send( (uint8_t*)&frame, sizeof( navilite_message ) );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_request_app_zoomout
    *
    * Send zoom out request to app side
    *
    * @return true when success
    *         false when failed
    *
    *********************************************************************/
    bool NAVILITE_request_app_zoomout
        (
        void
        )
    {
    navilite_message frame = NAVILITE_pack_frame_app_zoomout_request();
    bool ret = NAVILITE_send( (uint8_t*)&frame, sizeof( navilite_message ) );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_request_app_gohome
    *
    * Send go home request to app side
    *
    * @return true when success
    *         false when failed
    *
    *********************************************************************/
    bool NAVILITE_request_app_gohome
        (
        void
        )
    {
    navilite_message frame = NAVILITE_pack_frame_app_gohome_request();
    bool ret = NAVILITE_send( (uint8_t*)&frame, sizeof( navilite_message ) );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_request_app_gooffice
    *
    * Send go office request to app side
    *
    * @return true when success
    *         false when failed
    *
    *********************************************************************/
    bool NAVILITE_request_app_gooffice
        (
        void
        )
    {
    navilite_message frame = NAVILITE_pack_frame_app_gooffice_request();
    bool ret = NAVILITE_send( (uint8_t*)&frame, sizeof( navilite_message ) );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_request_app_get_favoritlist
    *
    * Send get favorite list request to app side
    *
    * @return true when success
    *         false when failed
    *
    *********************************************************************/
    bool NAVILITE_request_app_get_favoritlist
        (
        void
        )
    {
    navilite_message frame = NAVILITE_pack_frame_app_get_favoritlist_request();
    bool ret = NAVILITE_send( (uint8_t*)&frame, sizeof( navilite_message ) );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_request_app_get_stationlist
    *
    * Send get stationlist request to app side
    *
    * @return true when success
    *         false when failed
    *
    *********************************************************************/
    bool NAVILITE_request_app_get_stationlist
        (
        void
        )
    {
    navilite_message frame = NAVILITE_pack_frame_app_get_stationlist_request();
    bool ret = NAVILITE_send( (uint8_t*)&frame, sizeof( navilite_message ) );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_request_app_start_imageframe_update
    *
    * Start image frame update request to app
    *
    * @return true when success
    *         false when failed
    *
    *********************************************************************/
    bool NAVILITE_request_app_start_imageframe_update
        (
        void
        )
    {
    navilite_message frame = NAVILITE_pack_frame_app_enable_imageframe_update( NAVILITE_ENABLE_TYPE_ENABLE );
    bool ret = NAVILITE_send( (uint8_t*)&frame, sizeof( navilite_message ) );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_request_app_stop_imageframe_update
    *
    * Stop image frame update request to app
    *
    * @return true when success
    *         false when failed
    *
    *********************************************************************/
    bool NAVILITE_request_app_stop_imageframe_update
        (
        void
        )
    {
    navilite_message frame = NAVILITE_pack_frame_app_enable_imageframe_update( NAVILITE_ENABLE_TYPE_DISABLE );
    bool ret = NAVILITE_send( (uint8_t*)&frame, sizeof( navilite_message ) );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_request_app_enable_content_update
    *
    * Send content update request to app side
    * @param content_type for enable/disable the update request
    *        ex: NAVILITE_CONTENT_TYPE_TBT_LIST
    *            NAVILITE_CONTENT_TYPE_FAVORITE_LIST
    *            NAVILITE_CONTENT_TYPE_GASSTATION_LIST
    *
    * @param enable enable or disable the content update request
    * @return true when success
    *         false when failed
    *
    *********************************************************************/
    bool NAVILITE_request_app_enable_content_update
        (
        navilite_content_type content_type,
        navilite_switch_type enable
        )
    {
    // Back API compatibility for navigation image type
    if( NAVILITE_CONTENT_TYPE_NAVI_IMAGE == content_type )
        {
        navilite_message frame = NAVILITE_pack_frame_app_enable_imageframe_update( enable );
        bool ret = NAVILITE_send( (uint8_t*)&frame, sizeof( navilite_message ) );
        return ret;
        }
    else
        {
        navilite_message frame = NAVILITE_pack_frame_app_enable_content_update
            (
            content_type,
            enable
            );
        bool ret = NAVILITE_send( (uint8_t*)&frame, sizeof( navilite_message ) );
        return ret;
        }
    }
#endif
