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
#include "Enum.h"
#include "EEPM_pub.h"
#include "BT_pub.h"
#include "CM_pub.h"
#include "VI_pub.h"
#include "RTC_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define DEFAULT_HOME_GROUP              ( 1 )
#define DEFAULT_NAVI_VIEW_SETTING       ( 0 )
#define DEFAULT_METER_DISPLAY_SETTING   ( 0 )
#define DEFAULT_LANGUAGE                ( EnumLanguageENGLISH ) //TODO: depends on SKU
#define DEFAULT_CLK_AUTO_ADJUSTMENT     ( 1 )

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
* ew_update_factory_reset_status
*
* Count the number of items reset, and set is_factory_reset_complete to 1
* if all items are reset.
*
* @param status Factory reset status
*
*********************************************************************/
void ew_update_factory_reset_status
    (
    const uint32_t status
    )
{
PRINTF( "%s 0x%02x\r\n", __FUNCTION__, status );
factory_reset_status |= status;
if( FACTORY_RESET_TOTAL == factory_reset_status )
    {
    EW_notify_system_event_received( EnumSystemRxEventFACTORY_RESET_COMPLETED );
    }
}

/*********************************************************************
*
* @public
* EW_eeprom_set_clk_auto_adj_callback
*
* The callback function of resetting clock auto adjustment in EEPROM
*
* @param result True if writing clk auto adj to EEPROM succeeded.
*               False if writing clk auto adj to EEPROM failed.
* @param data The pointer to the value of last page
*
*********************************************************************/
void EW_eeprom_set_clk_auto_adj_callback
    (
    bool  result,
    void* data
    )
{
if( !result )
    {
    EwPrint( "reset clk auto adj fail\r\n" );
    }
ew_update_factory_reset_status( FACTORY_RESET_CLK_AUTO_ADJ );
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
ew_update_factory_reset_status( FACTORY_RESET_LAST_PAGE );
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
ew_update_factory_reset_status( FACTORY_RESET_LANGUAGE );
}

/*********************************************************************
*
* @public
* EW_reset_to_factory_default
*
* Run factory reset
*
*********************************************************************/
void EW_reset_to_factory_default
    (
    void
    )
{
factory_reset_status = 0;

/* reset trip time to zero and save to EEPROM */
VI_trip_time_reset();
VI_trip_time_save();

/* reset clock auto adjustment to ON and save to EEPROM */
EEPM_set_clk_auto_adjustment( DEFAULT_CLK_AUTO_ADJUSTMENT, EW_eeprom_set_clk_auto_adj_callback );

/* reset RTC */
RTC_reset();

/* reset last page */
uint8_t last_page = ( DEFAULT_HOME_GROUP << LAST_PAGE_HOME_GROUP_SHIFT ) |
                    ( DEFAULT_NAVI_VIEW_SETTING << LAST_PAGE_NAVI_SETTING_SHIFT ) |
                    ( DEFAULT_METER_DISPLAY_SETTING );
if( pdFALSE == EEPM_set_last_page( last_page, &EW_eeprom_set_last_page_callback ) )
    {
    EwPrint( "reset page false\r\n" );
    }

/* reset language */
if( pdFALSE == EEPM_set_language( DEFAULT_LANGUAGE, &EW_eeprom_set_language_callback ) )
    {
    EwPrint( "reset lang false\r\n" );
    }

/* reset CM & BT */
CM_factory_reset();
BT_factory_reset();
}
