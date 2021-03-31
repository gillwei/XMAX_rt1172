/*********************************************************************
* @file
* ew_device_vehicle_info.c
*
* @brief
* EW module - vehicle related device interface implementation
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
#include "Enum.h"
#include "Application.h"
#include "VI_pub.h"
#include "semphr.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#ifdef _DeviceInterfaceVehicleDeviceClass_
    typedef int device_function( void );
#endif

#ifdef _DeviceInterfaceVehicleDeviceClass__NotifyDataReceived_
    static int ew_notify_vi_data_received( void );
#endif

#ifdef _DeviceInterfaceVehicleDeviceClass__NotifyDDModeStateChanged_
    static int ew_notify_vi_dd_mode_state_changed( void );
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
#define RX_TYPE_QUEUE_LENGTH    ( 16 )

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/
#ifdef _DeviceInterfaceVehicleDeviceClass_
    static DeviceInterfaceVehicleDeviceClass device_object = 0;

    device_function* const function_lookup_table[] =
    {
    #ifdef _DeviceInterfaceVehicleDeviceClass__NotifyDataReceived_
        ew_notify_vi_data_received,
    #endif
    #ifdef _DeviceInterfaceVehicleDeviceClass__NotifyDDModeStateChanged_
        ew_notify_vi_dd_mode_state_changed
    #endif
    };

    const int num_of_func = sizeof( function_lookup_table )/sizeof( device_function* );
    static QueueHandle_t rx_type_queue;
    static bool is_dd_mode_state_changed = false;
    static bool is_rx_type_queued = false;
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
* ew_device_vi_init
*
* Embedded Wizard vehicle info device interface initialization
*
*********************************************************************/
void ew_device_vi_init
    (
    void
    )
{
#ifdef _DeviceInterfaceVehicleDeviceClass_
     /*
       Get access to the counterpart of this device driver: get access to the
       device class that is created as autoobject within your Embedded Wizard
       project. For this purpose you can call the function EwGetAutoObject().
       This function contains two parameters: The pointer to the autoobject and
       the class of the autoobject.
       Assuming you have implemented the class 'DeviceClass' within the unit
       'Application' and you have an autoobject with the name 'Device', make
       the following call:
       EwGetAutoObject( &ApplicationDevice, ApplicationDeviceClass );
    */
    device_object = EwGetAutoObject( &DeviceInterfaceVehicleDevice, DeviceInterfaceVehicleDeviceClass );
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
* ew_device_vi_deinit
*
* Embedded Wizard vehicle info device interface de-initialization
*
*********************************************************************/
void ew_device_vi_deinit
    (
    void
    )
{
#ifdef _DeviceInterfaceVehicleDeviceClass_
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
* ew_device_vi_proc
*
* Select the function from function table and execute it.
*
*********************************************************************/
int ew_device_vi_proc
    (
    void
    )
{
int need_update = 0;

#ifdef _DeviceInterfaceVehicleDeviceClass_
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
* ew_notify_vi_dd_mode_state_changed
*
* Notify EW GUI the driver distraction mode state is changed
*
*********************************************************************/
#ifdef _DeviceInterfaceVehicleDeviceClass__NotifyDDModeStateChanged_
static int ew_notify_vi_dd_mode_state_changed
    (
    void
    )
{
int need_update = 0;

if( is_dd_mode_state_changed )
    {
    is_dd_mode_state_changed = 0;
    DeviceInterfaceVehicleDeviceClass__NotifyDDModeStateChanged( device_object );
    need_update = 1;
    }
return need_update;
}
#endif

/*********************************************************************
*
* @private
* ew_notify_vi_data_received
*
* Notify EW GUI the data received from vehicle info manager
*
*********************************************************************/
#ifdef _DeviceInterfaceVehicleDeviceClass__NotifyDataReceived_
static int ew_notify_vi_data_received
    (
    void
    )
{
int need_update = 0;

if( is_rx_type_queued )
    {
    EnumVehicleRxType rx_type;
    while( pdPASS == xQueueReceive( rx_type_queue, &rx_type, 0 ) )
        {
        DeviceInterfaceVehicleDeviceClass_NotifyDataReceived( device_object, rx_type );
        }

    is_rx_type_queued = 0;
    need_update = 1;
    }
return need_update;
}
#endif

/*********************************************************************
*
* @public
* EW_notify_dd_mode_state_changed
*
* Notify Embedded Wizard driver distraction mode state is changed
*
*********************************************************************/
void EW_notify_dd_mode_state_changed
    (
    void
    )
{
#ifdef _DeviceInterfaceVehicleDeviceClass_
    is_dd_mode_state_changed = true;
    EwBspEventTrigger();
#endif
}

/*********************************************************************
*
* @public
* EW_notify_vi_data_received
*
* Enqueue the vehicle rx type and notify Embedded Wizard
*
* @param rx_type Vehicle rx data type
*
*********************************************************************/
void EW_notify_vi_data_received
    (
    const EnumVehicleRxType rx_type
    )
{
if( NULL == rx_type_queue )
    {
    rx_type_queue = xQueueCreate( RX_TYPE_QUEUE_LENGTH, sizeof( EnumVehicleRxType ) );
    configASSERT( NULL != rx_type_queue );
    }

if( pdTRUE == xQueueSend( rx_type_queue, &rx_type, 0 ) )
    {
    is_rx_type_queued = true;
    EwBspEventTrigger();
    }
else
    {
    EwPrint( "%s err\r\n", __FUNCTION__ );
    }
}
