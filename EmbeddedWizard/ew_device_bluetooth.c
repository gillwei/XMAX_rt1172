/*********************************************************************
* @file
* ew_device_bluetooth.c
*
* @brief
* EW module - Bluetooth related device interface implementation
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
#include "fsl_debug_console.h"
#include "FreeRTOS.h"
#include "DeviceInterface.h"
#include "EW_pub.h"
#include <string.h>

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#ifdef _DeviceInterfaceBluetoothDeviceClass_
    typedef int bluetooth_device_function( void );
#endif
#ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyPasskeyGenerated_
    static int ew_bt_notify_passkey_generated( void );
#endif
#ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyConnectionResult_
    static int ew_bt_notify_connection_result( void );
#endif
#ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyBtFwStatus_
    static int ew_notify_bt_fw_status( void );
#endif

#define BT_FW_VERSION_MAX_LEN   ( 8 )

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
#ifdef _DeviceInterfaceBluetoothDeviceClass_
    static DeviceInterfaceBluetoothDeviceClass device_object = 0;
    bluetooth_device_function* const bluetooth_function_lookup_table[] =
        {
        #ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyPasskeyGenerated_
            ew_bt_notify_passkey_generated,
        #endif
        #ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyConnectionResult_
            ew_bt_notify_connection_result,
        #endif
        #ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyBtFwStatus_
            ew_notify_bt_fw_status
        #endif
        };

    const int num_of_bluetooth_func = sizeof( bluetooth_function_lookup_table )/sizeof( bluetooth_device_function* );

    static int  is_bt_passkey_received = 0;
    static int  is_bt_connection_result_updated = 0;
    static char bt_passkey[BT_PIN_CODE_LEN + 1] = "";
    static EnumBtResult bt_connection_result = 0;

    static int  is_notify_bt_fw_status = 0;
    static char bt_fw_version[BT_FW_VERSION_MAX_LEN];
    static EnumBtFwStatus bt_fw_update_status = 0;
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
* ew_device_bluetooth_init
*
* Embedded Wizard Bluetooth device interface initialization
*
*********************************************************************/
void ew_device_bluetooth_init
    (
    void
    )
{
#ifdef _DeviceInterfaceBluetoothDeviceClass_
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
    device_object = EwGetAutoObject( &DeviceInterfaceBluetoothDevice, DeviceInterfaceBluetoothDeviceClass );
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
* ew_device_bluetooth_deinit
*
* Embedded Wizard Bluetooth device interface de-initialization
*
*********************************************************************/
void ew_device_bluetooth_deinit
    (
    void
    )
{
#ifdef _DeviceInterfaceBluetoothDeviceClass_
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
* ew_device_bluetooth_proc
*
* Select the function from Bluetooth function table and execute it.
*
*********************************************************************/
int ew_device_bluetooth_proc
    (
    void
    )
{
int need_update = 0;

#ifdef _DeviceInterfaceBluetoothDeviceClass_
    if( device_object == 0 ||
        num_of_bluetooth_func == 0 )
        {
        return 0;
        }

    for( int i = 0; i < num_of_bluetooth_func; i++ )
        {
        if( bluetooth_function_lookup_table[i]() )
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
* ew_bt_notify_passkey_generated
*
* Notify the Bluetooth passkey to EW GUI.
*
*********************************************************************/
#ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyPasskeyGenerated_
    static int ew_bt_notify_passkey_generated
        (
        void
        )
    {
    int need_update = 0;
    if( is_bt_passkey_received )
        {
        is_bt_passkey_received = 0;
        XString passkey;
        passkey = EwNewStringAnsi( bt_passkey );
        DeviceInterfaceBluetoothDeviceClass__NotifyPasskeyGenerated( device_object, passkey );
        need_update = 1;
        }
    return need_update;
    }
#endif

/*********************************************************************
*
* @private
* ew_bt_notify_connection_result
*
* Notify the Bluetooth pairing result to EW GUI.
*
*********************************************************************/
#ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyConnectionResult_
    static int ew_bt_notify_connection_result
        (
        void
        )
    {
    int need_update = 0;
    if( is_bt_connection_result_updated )
        {
        is_bt_connection_result_updated = 0;
        DeviceInterfaceBluetoothDeviceClass_NotifyConnectionResult( device_object, bt_connection_result );
        need_update = 1;
        }
    return need_update;
    }
#endif

/*********************************************************************
*
* @private
* ew_notify_bt_fw_status
*
* Notify the status of BT firmware update to EW GUI.
*
*********************************************************************/
#ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyBtFwStatus_
    static int ew_notify_bt_fw_status
        (
        void
        )
    {
    int need_update = 0;
    if( is_notify_bt_fw_status )
        {
        is_notify_bt_fw_status = 0;
        XString version = EwNewStringAnsi( bt_fw_version );
        DeviceInterfaceBluetoothDeviceClass__NotifyBtFwStatus( device_object, bt_fw_update_status, version );
        need_update = 1;
        }
    return need_update;
    }
#endif

/*********************************************************************
*
* @private
* ew_bt_get_local_device_name
*
* @param device_name The pointer to the pointer to the device name.
*
*********************************************************************/
void ew_bt_get_local_device_name
    (
    uint8_t** device_name
    )
{
BTM_get_local_device_name( device_name );
}

/*********************************************************************
*
* @private
* ew_bt_get_local_device_address
*
* @param device_addr The pointer to the local device address.
*
*********************************************************************/
void ew_bt_get_local_device_address
    (
    uint8_t* device_address
    )
{
BTM_get_local_device_address( device_address );
}

/*********************************************************************
*
* @private
* ew_bt_is_max_paired_device_num
*
* Check if the paired device num reaches max or not
*
* @retval True if paired device num reaches max. False if not reaching max.
*
*********************************************************************/
bool ew_bt_is_max_paired_device_num
    (
    void
    )
{
return BTM_is_max_paired_device_num();
}

/*********************************************************************
*
* @private
* ew_bt_get_paired_device_num
*
* Get the paired device num.
*
* @retval The paired device num.
*
*********************************************************************/
int ew_bt_get_paired_device_num
    (
    void
    )
{
return BTM_get_paired_device_num();
}

/*********************************************************************
*
* @private
* ew_bt_get_paired_device_at_index
*
* Get the specific Bluetooth paired device information.
*
* @param index The index of the paired device.
* @param dev_name The pointer to the pointer of the device name.
* @param is_connected The pointer to the is_connected bool value.
*
*********************************************************************/
void ew_bt_get_paired_device_at_index
    (
    const int paired_device_idx,
    uint8_t** device_name,
    bool*     is_connected
    )
{
BTM_get_paired_device_info( paired_device_idx, device_name, is_connected );
}

/*********************************************************************
*
* @private
* ew_bt_is_ble_paired_device
*
* @param paired_device_idx The index of paired device.
* @retval True if BLE is paired to the device.
*
*********************************************************************/
bool ew_bt_is_ble_paired_device
    (
    const int paired_device_idx
    )
{
return true; //TODO: get the result from BT manager
}

/*********************************************************************
*
* @private
* ew_bt_connect_paired_device
*
* Device interface to connect the Bluetooth device
*
* @param paired_device_idx The index of paired device.
*
*********************************************************************/
void ew_bt_connect_paired_device
    (
    const int paired_device_idx
    )
{
BTM_connect_paired_device( paired_device_idx );
}

/*********************************************************************
*
* @private
* ew_bt_disconnect_paired_device
*
* Device interface to disconnect the Bluetooth device
*
* @param paired_device_idx The index of paired device.
*
*********************************************************************/
void ew_bt_disconnect_paired_device
    (
    const int paired_device_idx
    )
{
BTM_disconnect_paired_device( paired_device_idx );
}

/*********************************************************************
*
* @private
* ew_bt_unpair_paired_device
*
* Device interface to unpair the Bluetooth device
*
* @param paired_device_idx The index of paired device.
*
*********************************************************************/
void ew_bt_unpair_paired_device
    (
    const int paired_device_idx
    )
{
BTM_unpair_paired_device( paired_device_idx );
}

/*********************************************************************
*
* @private
* ew_bt_set_enable
*
* Device interface to enable/disable Bluetooth.
*
* @param state True: enable Bluetooth.
*              False: disable Bluetooth.
*
*********************************************************************/
void ew_bt_set_enable
    (
    bool state
    )
{
BTM_set_enable_state( state );
}

/*********************************************************************
*
* @private
* ew_bt_get_enable
*
* Device interface to get Bluetooth enable state.
*
* @retVal True if Bluetooth is enabled.
*         False if Bluetooth is disabled.
*
*********************************************************************/
bool ew_bt_get_enable
    (
    void
    )
{
bool result = false;
if( BTM_get_enable_state() > 0 )
    {
    result = true;
    }
return result;
}

/*********************************************************************
*
* @private
* ew_bt_set_discoverable
*
* Device interface used for making system discoverable to other
* Bluetooth device.
*
* @param state True if turning discoverable on.
*              False if turning discoverable off.
*
*********************************************************************/
void ew_bt_set_discoverable
    (
    bool state
    )
{
BTM_set_discoverable_state( ( int )state );
}

/*********************************************************************
*
* @private
* ew_bt_get_discoverable
*
* Device interface to get Bluetooth discoverable state.
*
* @retVal True if discoverable.
*         False if not discoverable.
*
*********************************************************************/
bool ew_bt_get_discoverable
    (
    void
    )
{
bool result = false;
if( BTM_get_discoverable_state() > 0 )
    {
    result = true;
    }
return result;
}

/*********************************************************************
*
* @private
* ew_bt_set_autoconnect
*
* Device interface to enable/disable auto connect to Bluetooth device.
*
* @param state True if turning auto connect on.
*              False if turning auto connect off.
*
*********************************************************************/
void ew_bt_set_autoconnect
    (
    bool state
    )
{
BTM_set_autoconnect_state( ( int )state );
}

/*********************************************************************
*
* @private
* ew_bt_get_autoconnect
*
* Device interface to get Bluetooth auto connect state.
*
* @retval True if auto connect.
*         False if not auto connect.
*
*********************************************************************/
bool ew_bt_get_autoconnect
    (
    void
    )
{
bool result = false;
if( BTM_get_autoconnect_state() > 0 )
    {
    result = true;
    }
return result;
}

/*********************************************************************
*
* @public
* EW_notify_bt_passkey_generated
*
* Notify EW GUI that the pass key is generated.
*
* @param passkey The pointer to the char array of passkey
*
*********************************************************************/
void EW_notify_bt_passkey_generated
    (
    const char* passkey
    )
{
#ifdef _DeviceInterfaceBluetoothDeviceClass_
    memcpy( bt_passkey, passkey, BT_PIN_CODE_LEN );
    bt_passkey[BT_PIN_CODE_LEN] = '\0';
    is_bt_passkey_received = 1;
    EwBspEventTrigger();
#endif
}

/*********************************************************************
*
* @public
* EW_notify_bt_connection_result
*
* Notify EW GUI the Bluetooth pairing result.
*
* @param result The BT connection result of bt_connection_result_type
*
*********************************************************************/
void EW_notify_bt_connection_result
    (
    const bt_connection_result_type result
    )
{
#ifdef _DeviceInterfaceBluetoothDeviceClass_
    switch( result )
        {
        case BT_CONNECTION_SUCCESS:
            bt_connection_result = EnumBtResultSUCCESS;
            break;
        case BT_CONNECTION_FAIL:
            bt_connection_result = EnumBtResultFAIL;
            break;
        case BT_CONNECTION_TIMEOUT:
            bt_connection_result = EnumBtResultTIMEOUT;
            break;
        default:
            bt_connection_result = EnumBtResultFAIL;
            break;
        }
    is_bt_connection_result_updated = 1;
    EwBspEventTrigger();
#endif
}

/*********************************************************************
*
* @public
* EW_notify_bt_fw_update_status
*
* Notify EW GUI the Bluetooth firmware update status.
*
* @param status 0: EnumBtFwStatusNO_UPDATE,    1: EnumBtFwStatusUPDATE_START,
*               2: EnumBtFwStatusUPDATE_ABORT, 3: EnumBtFwStatusUPDATE_FINISH
* @param version The pointer to the char array of BT firmware version.
*
*********************************************************************/
void EW_notify_bt_fw_update_status( EnumBtFwStatus status, char* version )
{
PRINTF( "%s, %d\r\n", __FUNCTION__, status );
is_notify_bt_fw_status = 1;
bt_fw_update_status = status;
memcpy( bt_fw_version, version, BT_FW_VERSION_MAX_LEN );
bt_fw_version[BT_FW_VERSION_MAX_LEN-1] = '\0';
EwBspEventTrigger();
}
