/*********************************************************************
* @file
* ew_reset.c
*
* @brief
* EW module - handle reset
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
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "EEPM_pub.h"
#include "BTM_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define DEFAULT_HOME_INDEX          ( 1 )
#define DEFAULT_METER_INDEX         ( 0 )
#define DEFAULT_LANGUAGE            ( 0 )

#define FACTORY_RESET_BT_MANAGER    ( 1 << 0 )
#define FACTORY_RESET_LANGUAGE      ( 1 << 1 )
#define FACTORY_RESET_LAST_PAGE     ( 1 << 2 )
#define FACTORY_RESET_TOTAL         ( FACTORY_RESET_BT_MANAGER | FACTORY_RESET_LANGUAGE | FACTORY_RESET_LAST_PAGE )

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
static uint32_t factory_reset_status;

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/
/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @private
* update_factory_reset_status
*
* Count the number of items reset, and set is_factory_reset_complete to 1
* if all items are reset.
*
*********************************************************************/
static void update_factory_reset_status
    (
    uint32_t status
    )
{
factory_reset_status |= status;
if( FACTORY_RESET_TOTAL == factory_reset_status )
    {
    ew_done_factory_reset();
    }
}

/*********************************************************************
*
* @public
* EW_eeprom_set_last_page_callback
*
* The callback function of resetting last page saved in EEPROM
*
* @param result True if writing last page to EEPROM succeeded.
*               False if writing last page to EEPROM failed.
* @param data The pointer to the value of last page
*
*********************************************************************/
void EW_eeprom_set_last_page_callback
    (
    bool  result,
    void* data
    )
{
if( !result )
    {
    EwPrint( "EW reset last page fail\r\n" );
    }
update_factory_reset_status( FACTORY_RESET_LAST_PAGE );
}

/*********************************************************************
*
* @public
* EW_eeprom_set_language_callback
*
* The callback function of resetting language saved in EEPROM
*
* @param result True if writing last language to EEPROM succeeded.
*               False if writing last language to EEPROM failed.
* @param data The pointer to the value of language
*
*********************************************************************/
void EW_eeprom_set_language_callback
    (
    bool  result,
    void* data
    )
{
if( !result )
    {
    EwPrint( "EW reset lang fail\r\n" );
    }
update_factory_reset_status( FACTORY_RESET_LANGUAGE );
}

/*********************************************************************
*
* @public
* EW_btm_reset_callback
*
* The callback function of resetting BT manager
*
* @param result 1: The reset of BT manager successes.
*               0: The reset of BT manager fails.
*
*********************************************************************/
void EW_btm_reset_callback
    (
    int result
    )
{
if( !result )
    {
    EwPrint( "EW reset BTM fail\r\n" );
    }
update_factory_reset_status( FACTORY_RESET_BT_MANAGER );
}

/*********************************************************************
*
* @private
* ew_reset_to_factory_default
*
* Run factory reset
*
*********************************************************************/
void ew_reset_to_factory_default
    (
    void
    )
{
factory_reset_status = 0;
uint8_t last_page = ( DEFAULT_METER_INDEX ) |
                    ( DEFAULT_HOME_INDEX << LAST_PAGE_HOME_GROUP_SHIFT );
if( pdFALSE == EEPM_set_last_page( last_page, &EW_eeprom_set_last_page_callback ) )
    {
    EwPrint( "reset page false\r\n" );
    }

if( pdFALSE == EEPM_set_language( DEFAULT_LANGUAGE, &EW_eeprom_set_language_callback ) )
    {
    EwPrint( "reset lang false\r\n" );
    }

BTM_reset_factory_default( &EW_btm_reset_callback );
}

