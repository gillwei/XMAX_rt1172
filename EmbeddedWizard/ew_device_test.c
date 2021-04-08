/*********************************************************************
* @file
* ew_device_test.c
*
* @brief
* EW module - Test related device interface implementation
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
#ifdef _ApplicationDeviceClass_
    typedef int device_function( void );
#endif

#ifdef _ApplicationDeviceClass__NotifyMapReceived_
    static int ew_test_map_received( void );
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
#ifdef _ApplicationDeviceClass_
    static ApplicationDeviceClass device_object = 0;

    device_function* const function_lookup_table[] =
    {
        #ifdef _ApplicationDeviceClass__NotifyMapReceived_
            ew_test_map_received,
        #endif
    };

    const int num_of_func = sizeof( function_lookup_table )/sizeof( device_function* );

    static int is_map_frame_ready = 0;
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
* ew_device_test_init
*
* Embedded Wizard test device interface initialization
*
*********************************************************************/
void ew_device_test_init
    (
    void
    )
{
#ifdef _ApplicationDeviceClass_
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
    device_object = EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass );
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
* ew_device_test_deinit
*
* Embedded Wizard test device interface de-initialization
*
*********************************************************************/
void ew_device_test_deinit
    (
    void
    )
{
#ifdef _ApplicationDeviceClass_
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
* ew_device_test_proc
*
* Select the function from function table and execute it.
*
*********************************************************************/
int ew_device_test_proc
    (
    void
    )
{
int need_update = 0;

#ifdef _ApplicationDeviceClass_
    if( device_object == 0 ||
        num_of_func == 0 )
        {
        return 0;
        }

    for( int i = 0; i < num_of_func; i++ )
        {
        if( function_lookup_table[i]() )
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
* ew_test_map_received
*
* Test EW GUI that map has received.
*
*********************************************************************/
#ifdef _ApplicationDeviceClass__NotifyMapReceived_
static int ew_test_map_received
    (
    void
    )
{
int need_update = 0;

if( is_map_frame_ready )
    {
    is_map_frame_ready = 0;
    ApplicationDeviceClass__NotifyMapReceived( device_object );
    need_update = 1;
    }
return need_update;
}
#endif
