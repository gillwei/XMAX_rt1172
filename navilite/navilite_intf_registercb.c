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
    * NAVILITE_register_update_callback_preconnected
    *
    * Register navilite session preconnected notify callback
    *
    * @param callback_func_connected callback function for session preconnected
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_preconnected
        (
        navilite_callback_func_preconnected callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_preconnected = callback_func;
    NAVILITE_PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

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
    NAVILITE_PRINTF( "%s callback register done\r\n", __FUNCTION__ );
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
    NAVILITE_PRINTF( "%s callback register done\r\n", __FUNCTION__ );
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
    NAVILITE_PRINTF( "%s callback register done\r\n", __FUNCTION__ );
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
    NAVILITE_PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_register_update_callback_bt_timeout
    *
    * register navilite bt timeout notify callback
    *
    * @param callback_func callback function for bt timeout update
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_bt_timeout
        (
        navilite_callback_func_bt_timeout callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_bt_timeout = callback_func;
    NAVILITE_PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_register_update_callback_content_mode_switch
    *
    * register navilite bt throughput notify callback
    *
    * @param callback_func callback function for content mode to switch and bt timeout update
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_content_mode_switch
        (
        navilite_callback_func_content_mode_switch callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_content_mode_switch = callback_func;
    NAVILITE_PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_register_update_callback_viapointcount
    *
    * register navilite via point content notify callback
    *
    * @param callback_func callback function for via point update
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_viapointcount
        (
        navilite_callback_func_viapointcount callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_viapointcount = callback_func;
    NAVILITE_PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_register_update_callback_speedlimit
    *
    * register navilite speed limit content notify callback
    *
    * @param callback_func callback function for speed limit update
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_speedlimit
        (
        navilite_callback_func_speedlimit callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_speedlimit = callback_func;
    NAVILITE_PRINTF( "%s callback register done\r\n", __FUNCTION__ );
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
    NAVILITE_PRINTF( "%s callback register done\r\n", __FUNCTION__ );
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
    navilite_content_update_callbacks.callback_func_nextturndistance = callback_func;
    NAVILITE_PRINTF( "%s callback register done\r\n", __FUNCTION__ );
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
    NAVILITE_PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_register_update_callback_favlist
    *
    * register navilite favorite list content notify callback
    *
    * @param callback_func callback function for favorite list update
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_favlist
        (
        navilite_callback_func_nexttpoilist callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_nextfavlist = callback_func;
    PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_register_update_callback_gaslist
    *
    * register navilite gas station list content notify callback
    *
    * @param callback_func callback function for gas station list update
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_gaslist
        (
        navilite_callback_func_nexttpoilist callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_nextgaslist = callback_func;
    PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_register_update_callback_activetbtlistitem
    *
    * register active navilite tbt list content notify callback
    *
    * @param callback_func callback function for getting active tbt list
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_activetbtlistitem
        (
        navilite_callback_func_activetbtitem callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_activetbtitem = callback_func;
    NAVILITE_PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

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
    NAVILITE_PRINTF( "%s callback register done\r\n", __FUNCTION__ );
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
    NAVILITE_PRINTF( "%s callback register done\r\n", __FUNCTION__ );
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
    NAVILITE_PRINTF( "%s callback register done\r\n", __FUNCTION__ );
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
    NAVILITE_PRINTF( "%s callback register done\r\n", __FUNCTION__ );
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
    NAVILITE_PRINTF( "%s callback register done\r\n", __FUNCTION__ );
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
    NAVILITE_PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_register_update_callback_esn_sent
    *
    * Register esn sent notify callback
    *
    * @param callback_func callback function when esn id is sent and acked
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_esn_sent
        (
        navilite_callback_func_esn_sent callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_esn_sent = callback_func;
    NAVILITE_PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_register_update_callback_navigationstatus
    *
    * Register navigation status notify callback
    *
    * @param callback_func callback function when navigation status is notified
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_navigationstatus
        (
        navilite_callback_func_navigationstatus callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_navigationstatus = callback_func;
    NAVILITE_PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_register_update_callback_dialogevent
    *
    * Register dialog event notify callback
    *
    * @param callback_func callback function when dialog event is received from app
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_dialogevent
        (
        navilite_callback_func_dialogevent callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_dialogevent = callback_func;
    NAVILITE_PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_register_update_callback_runloop
    *
    * Register runloop for running extra jobs periodically
    *
    * @param callback_func callback function for running extra jobs periodically
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_runloopevent
        (
        navilite_callback_func_runloopevent callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_runloopevent = callback_func;
    PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_register_update_callback_appsetting
    *
    * register app status setting notify callback
    *
    * @param callback_func callback function for app setting bit status
    * @return The result of the callback registering
    *
    *********************************************************************/
    bool NAVILITE_register_update_callback_appsetting
        (
        navilite_callback_func_appsetting callback_func
        )
    {
    bool ret = true;
    navilite_content_update_callbacks.callback_func_appsetting = callback_func;
    NAVILITE_PRINTF( "%s callback register done\r\n", __FUNCTION__ );
    return ret;
    }

#endif
