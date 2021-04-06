/*********************************************************************
* @file
* ew_device_notification.c
*
* @brief
* EW module - Notification related device interface implementation
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
#include "NTF_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/

#ifdef _DeviceInterfaceNotificationDeviceClass_
    typedef int notification_device_function( void );
#endif

#ifdef _DeviceInterfaceNotificationDeviceClass__NotifyListUpdated_
    static int ew_notification_notify_list_updated( void );
#endif

#ifdef _DeviceInterfaceNotificationDeviceClass__NotifyPhoneCallStateChanged_
    static int ew_notification_notify_phone_call_state_changed( void );
#endif

#ifdef _DeviceInterfaceNotificationDeviceClass__NotifyPhoneCallVolumeChanged_
    static int ew_notification_notify_phone_call_volume_changed( void );
#endif

#define DEVICE_NOTIFICATION_EVENT_LIST_UPDATED          ( 1 << 0 )

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
#ifdef _DeviceInterfaceNotificationDeviceClass_
    static DeviceInterfaceNotificationDeviceClass device_object = 0;
    static bool     is_phone_call_stated_changed = false;
    static bool     is_phone_call_volume_changed = false;
    static uint32_t device_notification_event = 0;

    notification_device_function* const nm_function_lookup_table[] =
        {
        #ifdef _DeviceInterfaceNotificationDeviceClass__NotifyListUpdated_
            ew_notification_notify_list_updated,
        #endif
        #ifdef _DeviceInterfaceNotificationDeviceClass__NotifyPhoneCallStateChanged_
            ew_notification_notify_phone_call_state_changed,
        #endif
        #ifdef _DeviceInterfaceNotificationDeviceClass__NotifyPhoneCallVolumeChanged_
            ew_notification_notify_phone_call_volume_changed
        #endif
        };

    const int num_of_nm_func = sizeof( nm_function_lookup_table )/sizeof( notification_device_function* );
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
* ew_device_notification_init
*
* Embedded Wizard notification device interface initialization
*
*********************************************************************/
void ew_device_notification_init
    (
    void
    )
{
#ifdef _DeviceInterfaceNotificationDeviceClass_
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
    device_object = EwGetAutoObject( &DeviceInterfaceNotificationDevice, DeviceInterfaceNotificationDeviceClass );
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
* ew_device_notification_deinit
*
* Embedded Wizard notifiation device interface de-initialization
*
*********************************************************************/
void ew_device_notification_deinit
    (
    void
    )
{
#ifdef _DeviceInterfaceNotificationDeviceClass_
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
* ew_device_notification_proc
*
* Select the function from notification function table and execute it.
*
*********************************************************************/
int ew_device_notification_proc
    (
    void
    )
{
int need_update = 0;

#ifdef _DeviceInterfaceNotificationDeviceClass_
    if( device_object == 0 ||
        num_of_nm_func == 0 )
        {
        return 0;
        }

    for( int i = 0; i < num_of_nm_func; i++ )
        {
        if( nm_function_lookup_table[i]() )
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
* ew_notification_notify_list_updated
*
* Notify title of track to EW GUI.
*
*********************************************************************/
#ifdef _DeviceInterfaceNotificationDeviceClass__NotifyListUpdated_
static int ew_notification_notify_list_updated
    (
    void
    )
{
int need_update = 0;
if( device_notification_event & DEVICE_NOTIFICATION_EVENT_LIST_UPDATED )
    {
    device_notification_event &= ~DEVICE_NOTIFICATION_EVENT_LIST_UPDATED;
    DeviceInterfaceNotificationDeviceClass__NotifyListUpdated( device_object );
    need_update = 1;
    }
return need_update;
}
#endif

/*********************************************************************
*
* @private
* ew_notification_notify_phone_call_state_changed
*
* Notify EW GUI the phone call state changed
*
*********************************************************************/
#ifdef _DeviceInterfaceNotificationDeviceClass__NotifyPhoneCallStateChanged_
static int ew_notification_notify_phone_call_state_changed
    (
    void
    )
{
int need_update = 0;
if( is_phone_call_stated_changed )
    {
    is_phone_call_stated_changed = false;
    DeviceInterfaceNotificationDeviceClass__NotifyPhoneCallStateChanged( device_object );
    need_update = 1;
    }
return need_update;
}
#endif

/*********************************************************************
*
* @private
* ew_notification_notify_phone_call_volume_changed
*
* Notify EW GUI the phone call state changed
*
*********************************************************************/
#ifdef _DeviceInterfaceNotificationDeviceClass__NotifyPhoneCallVolumeChanged_
static int ew_notification_notify_phone_call_volume_changed
    (
    void
    )
{
int need_update = 0;
if( is_phone_call_volume_changed )
    {
    is_phone_call_volume_changed = false;
    DeviceInterfaceNotificationDeviceClass__NotifyPhoneCallVolumeChanged( device_object );
    need_update = 1;
    }
return need_update;
}
#endif

/*********************************************************************
*
* @public
* EW_notify_notification_list_updated
*
* Notify EW GUI the notification list is updated
*
*********************************************************************/
void EW_notify_notification_list_updated
    (
    void
    )
{
#ifdef _DeviceInterfaceNotificationDeviceClass_
    device_notification_event |= DEVICE_NOTIFICATION_EVENT_LIST_UPDATED;
    EwBspEventTrigger();
#endif
}

/*********************************************************************
*
* @public
* EW_notify_phone_call_state_changed
*
* Notify EW GUI the phone call state changed
*
*********************************************************************/
void EW_notify_phone_call_state_changed
    (
    void
    )
{
#ifdef _DeviceInterfaceNotificationDeviceClass_
    is_phone_call_stated_changed = true;
    EwBspEventTrigger();
#endif
}

/*********************************************************************
*
* @public
* EW_notify_phone_call_volume_changed
*
* Notify EW GUI the phone call volume changed
*
*********************************************************************/
void EW_notify_phone_call_volume_changed
    (
    void
    )
{
#ifdef _DeviceInterfaceNotificationDeviceClass_
    is_phone_call_volume_changed = true;
    EwBspEventTrigger();
#endif
}
