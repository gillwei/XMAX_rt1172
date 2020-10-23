/*********************************************************************
* @file
* navilite_intf_registercb.c
*
* @brief
* NAVILITE module - interface register APIs
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
extern navilite_content_update_callbacks_type navilite_content_update_callbacks;

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
    * NAVILITE_register_update_callback_connected
    *
    * Register navilite session connected notify callback
    *
    * @param callback_func_connected callback function for session connected
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_connected
        (
        navilite_callback_func_connected callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_connected = callback_func;
    PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_register_update_callback_disconnected
    *
    * Register navilite session disconnected notify callback
    *
    * @param callback_func_disconnected callback function for session disconnected
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_disconnected
        (
        navilite_callback_func_disconnected callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_disconnected = callback_func;
    PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_register_update_callback_imageframe
    *
    * Register navilite image frame content notify callback
    *
    * @param callback_func_imageframe callback function for image frame update
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_imageframe
        (
        navilite_callback_func_imageframe callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_imageframe = callback_func;
    PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_register_update_callback_eta
    *
    * register navilite eta content notify callback
    *
    * @param callback_func callback function for ETA update
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_eta
        (
        navilite_callback_func_eta callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_eta = callback_func;
    PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_register_update_callback_currentroadname
    *
    * register navilite current road name content notify callback
    *
    * @param callback_func callback function for current road name update
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_currentroadname
        (
        navilite_callback_func_currentroadname callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_currentroadname = callback_func;
    PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_register_update_callback_nextturndistance
    *
    * register navilite next turn distance content notify callback
    *
    * @param callback_func callback function for current road name update
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_nextturndistance
        (
        navilite_callback_func_nextturndistance callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_nextturndistance = *callback_func;
    PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_register_update_callback_tbtlist
    *
    * register navilite turn by turn list content notify callback
    *
    * @param callback_func callback function for turn by turn list update
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_tbtlist
        (
        navilite_callback_func_nexttbtlist callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_nexttbtist = callback_func;
    PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_register_update_callback_active_tbtlistitem
    *
    * register active navilite tbt list content notify callback
    *
    * @param callback_func callback function for getting active tbt list
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_active_tbtlistitem
        (
        navilite_callback_func_activetbtitem callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_activetbtitem = callback_func;
    PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

    /*
    @TODO: Those API are not confirmed yet. This should be decided for API v2
    bool NAVILITE_register_update_callback_FavPOITurnList(*);
    bool NAVILITE_register_update_callback_NearByGasStationList(*);
    */

    /*********************************************************************
    *
    * @public
    * NAVILITE_register_update_callback_navieventtext
    *
    * register navi event content notify callback
    *
    * @param callback_func callback function for getting navi
    *        event text
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_navieventtext
        (
        navilite_callback_func_navieventtext callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_navieventtext = callback_func;
    PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_register_update_callback_homelocationsetting
    *
    * register home setting notify callback
    *
    * @param callback_func callback function for getting
    *        if home setting is set or not
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_homelocationsetting
        (
        navilite_callback_func_homelocationsetting callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_homelocationsetting = callback_func;
    PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_register_update_callback_officelocationsetting
    *
    * register office setting notify callback
    *
    * @param callback_func callback function for getting
    *        if office setting is set or not
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_officelocationsetting
        (
        navilite_callback_func_officelocationsetting callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_officelocationsetting = callback_func;
    PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_register_update_callback_zoomlevel
    *
    * Register zoom level notify callback
    *
    * @param callback_func callback function for zoom level update
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_zoomlevel
        (
        navilite_callback_func_zoomlevel callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_zoomlevel = callback_func;
    PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_register_update_callback_routecalc_progress
    *
    * Register route progress notify callback
    *
    * @param callback_func callback function of route calc progress
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_routecalcprogress
        (
        navilite_callback_func_routecalcprogress callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_routecalcprogress = callback_func;
    PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_register_update_callback_daynight_mode
    *
    * Register day night mode notify callback
    *
    * @param callback_func callback function of daynight mode update
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_daynightmode
        (
        navilite_callback_func_daynightmode callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_daynightmode = callback_func;
    PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

#endif
