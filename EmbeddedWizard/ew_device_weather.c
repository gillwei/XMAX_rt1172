/*********************************************************************
* @file
* ew_device_weather.c
*
* @brief
* EW module - Weather related device interface implementation
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
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
#include "WEA_pub.h"
#include "BC_motocon_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#ifdef _DeviceInterfaceWeatherDeviceClass_
    typedef int device_function( void );
#endif

#ifdef _DeviceInterfaceWeatherDeviceClass__NotifyWeatherInfoUpdated_
    static int ew_notify_weather_info_update( void );
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
#ifdef _DeviceInterfaceWeatherDeviceClass_
    static DeviceInterfaceWeatherDeviceClass device_object = 0;
    device_function* const weather_function_lookup_table[] =
        {
        #ifdef _DeviceInterfaceWeatherDeviceClass__NotifyWeatherInfoUpdated_
            ew_notify_weather_info_update
        #endif
        };
    const int num_of_weather_func = sizeof( weather_function_lookup_table )/sizeof( device_function* );
    static int is_weather_info_update = 0;
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
* ew_device_weather_init
*
* Embedded Wizard weather device interface initialization
*
*********************************************************************/
void ew_device_weather_init
    (
    void
    )
{
#ifdef _DeviceInterfaceWeatherDeviceClass_
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
    device_object = EwGetAutoObject( &DeviceInterfaceWeatherDevice, DeviceInterfaceWeatherDeviceClass );
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
* ew_device_weather_deinit
*
* Embedded Wizard weather device interface de-initialization
*
*********************************************************************/
void ew_device_weather_deinit
    (
    void
    )
{
#ifdef _DeviceInterfaceWeatherDeviceClass_
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
* ew_device_weather_proc
*
* Select the function from weather function table and execute it.
*
*********************************************************************/
int ew_device_weather_proc
    (
    void
    )
{
int need_update = 0;

#ifdef _DeviceInterfaceWeatherDeviceClass_
    if( device_object == 0 ||
        num_of_weather_func == 0 )
        {
        return 0;
        }

    for( int i = 0; i < num_of_weather_func; i++ )
        {
        if( weather_function_lookup_table[i]() )
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
* ew_get_weather_info_obj
*
* Obtain weather info object.
*
* @param index the index of weather item.
* @return weather item.
*
*********************************************************************/
bc_motocon_weather_info_t* ew_get_weather_info_obj
    (
    const int index
    )
{
return WEA_get_weather_obj( index );
}

/*********************************************************************
*
* @private
* ew_get_weather_loc
*
* Obtain current weather location.
*
* @param location the double pointer to the stored weather location.
*
*********************************************************************/
void ew_get_weather_loc
    (
    char** location
    )
{
*location = WEA_get_weather_location();
}

/*********************************************************************
*
* @private
* ew_get_weather_week_day
*
* Get week day info.
*
*********************************************************************/
int ew_get_weather_week_day
    (
    void
    )
{
return WEA_get_weather_weekday();
}

/*********************************************************************
*
* @private
* ew_send_weather_info_req
*
* Send weather info request.
*
*********************************************************************/
void ew_send_weather_info_req
    (
    void
    )
{
WEA_reset_weather_info_threshold();
BC_motocon_send_weather_request();
}

/*********************************************************************
*
* @private
* ew_send_vehicle_setting_req
*
* Send vehicle setting request.
*
*********************************************************************/
void ew_send_vehicle_setting_req
    (
    void
    )
{
BC_motocon_send_vehicle_setting_request();
}

/*********************************************************************
*
* @private
* ew_notify_weather_info_update
*
* Notify EW GUI that weather info is updated.
*
*********************************************************************/
#ifdef _DeviceInterfaceWeatherDeviceClass__NotifyWeatherInfoUpdated_
    static int ew_notify_weather_info_update
        (
        void
        )
    {
    int need_update = 0;
    if( is_weather_info_update )
        {
        is_weather_info_update = 0;
        need_update = 1;
        DeviceInterfaceWeatherDeviceClass__NotifyWeatherInfoUpdated( device_object );
        }
    return need_update;
    }
#endif

/*********************************************************************
*
* @public
* EW_notify_weather_info_update
*
* Notify Embedded Wizard weather time is ready.
*
*********************************************************************/
void EW_notify_weather_info_update
    (
    void
    )
{
#ifdef _DeviceInterfaceWeatherDeviceClass_
    is_weather_info_update = 1;
    EwBspEventTrigger();
#endif
}
