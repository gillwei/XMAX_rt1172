/*********************************************************************
* @file
* ew_power.c
*
* @brief
* EW module - handle power on/off task
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "ewrte.h"
#include "ew_bsp_inout.h"
#include "ew_bsp_event.h"
#include "ew_priv.h"
#include "DeviceInterface.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "EEPM_pub.h"
#include "PM_pub.h"
#include "VI_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define EW_MODULE_NAME          ( "ew" )

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
static int      ew_ignition_status = 0;
static uint32_t ignition_off_task_status = 0;

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @public
* EW_power_update_ignoff_task_status
*
* Unregister callback to PM if all tasks are done
*
* @param task Ignitition off task
*
*********************************************************************/
void EW_power_update_ignoff_task_status
    (
    uint32_t task
    )
{
if( PM_IGN_OFF == ew_ignition_status )
    {
    ignition_off_task_status |= task;
    if( IGN_OFF_TASK_ALL == ignition_off_task_status )
        {
        PM_unregister_callback( EW_MODULE_NAME );
        }
    }
}

/*********************************************************************
*
* @public
* EW_power_write_last_page_callback
*
* Callback function of writing last page in EEPROM
*
* @param result True if writing last page to EEPROM succeeded.
*               False if writing last page to EEPROM failed.
* @param data The pointer to the value of last page
*
*********************************************************************/
void EW_power_write_last_page_callback
    (
    bool  result,
    void* data
    )
{
if( !result )
    {
    EwPrint( "save last pg fail\r\n" );
    }
EW_power_update_ignoff_task_status( IGN_OFF_TASK_WRITE_LAST_PAGE );
}

/*********************************************************************
*
* @public
* EW_power_write_language_callback
*
* Callback function of writing language in EEPROM
*
* @param result True if writing language to EEPROM succeeded.
*               False if writing language to EEPROM failed.
* @param data Pointer to the value of last page
*
*********************************************************************/
void EW_power_write_language_callback
    (
    bool  result,
    void* data
    )
{
if( !result )
    {
    EwPrint( "save lang fail\r\n" );
    }
EW_power_update_ignoff_task_status( IGN_OFF_TASK_WRITE_LANGUAGE );
}

/*********************************************************************
*
* @private
* ew_power_ignition_status
*
* Return the ignition status
*
* @return Ignition status
*
*********************************************************************/
inline int ew_power_ignition_status
    (
    void
    )
{
return ew_ignition_status;
}

/*********************************************************************
*
* @private
* ew_save_last_status
*
* Save the last status including last page, language and trip time
*
*********************************************************************/
void ew_save_last_status
    (
    void
    )
{
// write last page to EEPROM
uint8_t last_page = ( ( ew_get_last_home_group() & LAST_PAGE_HOME_GROUP_MASK ) << LAST_PAGE_HOME_GROUP_SHIFT ) |
                    ( ( ew_get_navigation_view_setting() & LAST_PAGE_NAVIGATION_SETTING_MASK ) << LAST_PAGE_NAVI_SETTING_SHIFT ) |
                    ( ew_get_meter_display_setting() & LAST_PAGE_METER_DISP_SETTING_MASK );
if( pdFALSE == EEPM_set_last_page( last_page, &EW_power_write_last_page_callback ) )
    {
    EwPrint( "save last pg err\r\n" );
    }

uint8_t language = (uint8_t)ew_system_get_status( EnumSystemStatusLANGUAGE );
if( pdFALSE == EEPM_set_language( language, &EW_power_write_language_callback ) )
    {
    EwPrint( "save lang err\r\n" );
    }

EwPrint( "last pg 0x%x, lang %d\r\n", last_page, language );

// write trip time to EEPROM
VI_trip_time_save();
}

/*********************************************************************
*
* @public
* EW_ignition_off_callback
*
* The callback function from the power management to notify EW the ignition status
*
* @param ignition_status The status of ignition
*
*********************************************************************/
void EW_ignition_off_callback
    (
    bool ignition_status
    )
{
if( PM_IGN_OFF == ignition_status )
    {
    ew_ignition_status = PM_IGN_OFF;
    ew_save_last_status();

    // wake up EW task from Blocked state
    EwBspEventTrigger();
    }
}

/*********************************************************************
*
* @private
* ew_power_init
*
* Register callback to the power management
*
*********************************************************************/
void ew_power_init
    (
    void
    )
{
PM_register_callback( EW_MODULE_NAME, EW_ignition_off_callback );
}
