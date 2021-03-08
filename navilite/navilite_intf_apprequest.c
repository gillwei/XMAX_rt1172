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
    * send start route request to app side
    *
    * @return true when success
    *         false when failed
    *
    *********************************************************************/
    bool NAVILITE_request_app_startroute
        (
        uint16_t routeIndex
        )
    {
    navilite_message frame = NAVILITE_pack_frame_app_startroute_request( routeIndex );
    bool ret = NAVILITE_send( (uint8_t*)&frame, sizeof( navilite_message ) );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_request_app_stoproute
    *
    * send stop route request to app side
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
    * send zoom out request to app side
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
    * send go home request to app side
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
    * send go office request to app side
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
    * stop image frame update request to app
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
    * stop image frame update request to app
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

#endif
