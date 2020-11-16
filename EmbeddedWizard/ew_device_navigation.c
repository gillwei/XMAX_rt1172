/*********************************************************************
* @file
* ew_device_navigation.c
*
* @brief
* EW module - Navigation related device interface implementation
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
#include "DeviceInterface.h"
#include <string.h>
#include <stdbool.h>

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#ifdef _DeviceInterfaceNavigationDeviceClass_
    typedef int device_function( void );
#endif

#ifdef _DeviceInterfaceNavigationDeviceClass__NotifyMapUpdate_
    static int ew_notify_navi_map_update( void );
#endif

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
#ifdef _DeviceInterfaceNavigationDeviceClass_
    static DeviceInterfaceNavigationDeviceClass device_object = 0;
    device_function* const navi_function_lookup_table[] =
        {
        #ifdef _DeviceInterfaceNavigationDeviceClass__NotifyMapUpdate_
            ew_notify_navi_map_update
        #endif
        };
    const int num_of_navi_func = sizeof( navi_function_lookup_table )/sizeof( device_function* );
    static int is_map_update = 0;
#endif
/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @private
* ew_device_navi_init
*
* Embedded Wizard navigation device interface initialization
*
*********************************************************************/
void ew_device_navi_init
    (
    void
    )
{
#ifdef _DeviceInterfaceNavigationDeviceClass_
     /*
       Get access to the counterpart of this device driver: get access to the
       device class that is created as autoobject within your Embedded Wizard
       project. For this purpose you can call the function EwGetAutoObject().
       This function contains two paramters: The pointer to the autoobject and
       the class of the autoobject.
       Assuming you have implemented the class 'DeviceClass' within the unit
       'Application' and you have an autoobject with the name 'Device', make
       the following call:
       EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass );
    */
    device_object = EwGetAutoObject( &DeviceInterfaceNavigationDevice, DeviceInterfaceNavigationDeviceClass );
    /*
       Once you have the access to the autoobject, lock it as long as you need
       the access (typically, until your device driver is closed). By locking
       the autoobject, you can ensure that the object of the device class will
       be kept within the memory and not freed by the Garbage Collector.
       Once the device class is locked, you can easily store it within a static
       variable to access the driver class during the runtime.
    */
    EwLockObject( device_object );
#endif
}

/*********************************************************************
*
* @private
* ew_device_navi_deinit
*
* Embedded Wizard navigation device interface de-initialization
*
*********************************************************************/
void ew_device_navi_deinit
    (
    void
    )
{
#ifdef _DeviceInterfaceNavigationDeviceClass_
    if( device_object )
        {
        EwUnlockObject( device_object );
        }
    device_object = 0;
#endif
}

/*********************************************************************
*
* @private
* ew_device_navi_proc
*
* Select the function from navi function table and execute it.
*
*********************************************************************/
int ew_device_navi_proc
    (
    void
    )
{
int need_update = 0;

#ifdef _DeviceInterfaceNavigationDeviceClass_
    if( device_object == 0 ||
        num_of_navi_func == 0 )
        {
        return 0;
        }

    for( int i = 0; i < num_of_navi_func; i++ )
        {
        if( navi_function_lookup_table[i]() )
            {
            need_update = 1;
            }
        }
#endif

return need_update;
}

/*********************************************************************
*
* @private
* ew_notify_navi_map_update
*
* Notify EW GUI that map has received.
*
*********************************************************************/
#ifdef _DeviceInterfaceNavigationDeviceClass__NotifyMapUpdate_
    static int ew_notify_navi_map_update
        (
        void
        )
    {
    int need_update = 0;
    if( is_map_update )
        {
        is_map_update = 0;
        need_update = 1;
        DeviceInterfaceNavigationDeviceClass__NotifyMapUpdate( device_object );
        }
    return need_update;
    }
#endif

/*********************************************************************
*
* @public
* EW_notify_navi_map_update
*
* Notify Embedded Wizard map frame of RGB format is ready.
*
*********************************************************************/
void EW_notify_navi_map_update
    (
    void
    )
{
#ifdef _DeviceInterfaceNavigationDeviceClass_
    is_map_update = 1;
    EwBspEventTrigger();
#endif
}

