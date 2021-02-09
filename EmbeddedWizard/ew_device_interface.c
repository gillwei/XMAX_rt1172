/*********************************************************************
* @file
* ew_device_interface.c
*
* @brief
* EW module - device interface
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "ewrte.h"
#include "ew_bsp_inout.h"
#include "ew_bsp_clock.h"
#include "ew_bsp_event.h"
#include "ew_priv.h"
#include "Application.h"
#include <string.h>

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
typedef struct
{
    void    ( *init ) ( void );
    int     ( *proc ) ( void );
    void    ( *deinit ) ( void );
} device_interface_object;

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

device_interface_object const device_interface_lookup_table[] =
{
    {ew_device_test_init,      ew_device_test_proc,      ew_device_test_deinit},
    {ew_device_system_init,    ew_device_system_proc,    ew_device_system_deinit},
    {ew_device_navi_init,      ew_device_navi_proc,      ew_device_navi_deinit},
    {ew_device_mm_init,        ew_device_mm_proc,        ew_device_mm_deinit},
    {ew_device_bluetooth_init, ew_device_bluetooth_proc, ew_device_bluetooth_deinit},
    {ew_device_vi_init,        ew_device_vi_proc,        ew_device_vi_deinit},
    {ew_device_weather_init,   ew_device_weather_proc,   ew_device_weather_deinit}
};

const int device_interface_num = sizeof( device_interface_lookup_table )/sizeof( device_interface_object );

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @private
* ew_device_interface_init
*
* Embedded Wizard device interface initialization
*
*********************************************************************/
void ew_device_interface_init( void )
{
for( int i = 0; i < device_interface_num; i++ )
    {
    device_interface_lookup_table[i].init();
    }
}

/*********************************************************************
*
* @private
* ew_device_interface_deinit
*
* Embedded Wizard device interface de-initialization
*
*********************************************************************/
void ew_device_interface_deinit
    (
    void
    )
{
for( int i = 0; i < device_interface_num; i++ )
    {
    device_interface_lookup_table[i].deinit();
    }
}

/*********************************************************************
*
* @private
* ew_device_interface_process
*
* Call device interface function if need to update
*
*********************************************************************/
int ew_device_interface_process
    (
    void
    )
{
int need_update = 0;

for( int i = 0; i < device_interface_num; i++ )
    {
    if( device_interface_lookup_table[i].proc() )
        {
        need_update = 1;
        }
    }
/*
  Return a value != 0 if there is at least on property changed or if a
  system event was triggered. The return value is used by the main loop, to
  decide whether the GUI application has changed or not.
*/
return need_update;
}
