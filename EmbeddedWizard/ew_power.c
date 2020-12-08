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
* @private
* ew_update_ignition_off_status
*
* Unregister callback to PM if all tasks are done
*
* @param task IGN_OFF_TASK_CLOSE_DISPLAY or IGN_OFF_TASK_WRITE_LAST_PAGE
*
*********************************************************************/
void ew_power_update_ignoff_task_status
    (
    uint32_t task
    )
{
ignition_off_task_status |= task;
if( IGN_OFF_TASK_ALL == ignition_off_task_status )
    {
    PM_unregister_callback( EW_MODULE_NAME );
    }
}

/*********************************************************************
*
* @public
* EW_power_write_last_page_callback
*
* The callback function of writing last page saved in EEPROM
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
    EwPrint( "EW set last page fail\r\n" );
    }
ew_power_update_ignoff_task_status( IGN_OFF_TASK_WRITE_LAST_PAGE );
}

/*********************************************************************
*
* @private
* ew_power_ignition_status
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
    ew_ignition_status = 1;

    // write last page to EEPROM
    // TODO: get last home index and meter index from UI
    uint8_t last_page = ( 0 << LAST_PAGE_METER_SHIFT ) |
                        ( 0 << LAST_PAGE_HOME_SHIFT );
    if( pdFALSE == EEPM_set_last_page( last_page, &EW_power_write_last_page_callback ) )
        {
        EwPrint( "reset page false\r\n" );
        }

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
