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
#include "Enum.h"
#include "EW_pub.h"
#include "BTM_pub.h"
#include <string.h>
#include "semphr.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#ifdef _DeviceInterfaceBluetoothDeviceClass_
    typedef int bluetooth_device_function( void );
#endif
#ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyPairedDeviceConnectionStatusUpdated_
    static int ew_bt_notify_paired_device_connection_status_updated( void );
#endif
#ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyBtcPasskeyGenerated_
    static int ew_bt_notify_btc_passkey_generated( void );
#endif
#ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyBtcConnectionResult_
    static int ew_bt_notify_btc_connection_result( void );
#endif
#ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyBtFwStatus_
    static int ew_notify_bt_fw_status( void );
#endif
#ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyBtcPairingStateChanged_
    static int ew_notify_btc_pairing_state_received( void );
#endif
#ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyBlePairingStateChanged_
    static int ew_notify_ble_pairing_state_changed( void );
#endif
#ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyMotoConEventReceived_
    static int ew_notify_motocon_event_received( void );
#endif

#define BT_FW_VERSION_MAX_LEN       ( 8 )
#define MOTOCON_RX_EVENT_QUEUE_SIZE ( 16 )

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
        #ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyPairedDeviceConnectionStatusUpdated_
            ew_bt_notify_paired_device_connection_status_updated,
        #endif
        #ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyBtcPasskeyGenerated_
            ew_bt_notify_btc_passkey_generated,
        #endif
        #ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyBtcConnectionResult_
            ew_bt_notify_btc_connection_result,
        #endif
        #ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyBtFwStatus_
            ew_notify_bt_fw_status,
        #endif
        #ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyBtcPairingStateChanged_
            ew_notify_btc_pairing_state_received,
        #endif
        #ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyBlePairingStateChanged_
            ew_notify_ble_pairing_state_changed,
        #endif
        #ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyMotoConEventReceived_
            ew_notify_motocon_event_received
        #endif
        };

    const int num_of_bluetooth_func = sizeof( bluetooth_function_lookup_table )/sizeof( bluetooth_device_function* );

    static int is_btc_passkey_received = 0;
    static int is_btc_paired_device_status_updated = 0;
    static int is_btc_connection_result_updated = 0;
    static uint32_t btc_passkey = 0;
    static uint8_t  btc_connecing_device_name[BT_DEVICE_NAME_LEN];
    static EnumBtDeviceConnectionResult btc_connection_result = 0;
    static EnumBtcPairingState btc_pairing_state;
    static int is_btc_pairing_state_changed = 0;

    static int  is_notify_bt_fw_status = 0;
    static char bt_fw_version[BT_FW_VERSION_MAX_LEN];
    static EnumBtFwStatus bt_fw_update_status = 0;
    static int  is_ble_pairing_state_changed;
    static EnumBlePairingState ble_pairing_state;
    static uint32_t ble_pincode = 0;

    static int  is_motocon_event_received = 0;
    static QueueHandle_t motocon_rx_event_queue_handle;
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

    motocon_rx_event_queue_handle = xQueueCreate( MOTOCON_RX_EVENT_QUEUE_SIZE, sizeof( EnumMotoConRxEvent ) );
    configASSERT( NULL != motocon_rx_event_queue_handle );
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
* ew_bt_notify_paired_device_connection_status_updated
*
* Notify the Bluetooth paired device connection status updated to EW GUI.
*
*********************************************************************/
#ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyPairedDeviceConnectionStatusUpdated_
    static int ew_bt_notify_paired_device_connection_status_updated
        (
        void
        )
    {
    int need_update = 0;
    if( is_btc_paired_device_status_updated )
        {
        is_btc_paired_device_status_updated = 0;
        DeviceInterfaceBluetoothDeviceClass__NotifyPairedDeviceConnectionStatusUpdated( device_object );
        need_update = 1;
        }
    return need_update;
    }
#endif

/*********************************************************************
*
* @private
* ew_bt_notify_btc_connection_result
*
* Notify the Bluetooth pairing result to EW GUI.
*
*********************************************************************/
#ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyBtcConnectionResult_
    static int ew_bt_notify_btc_connection_result
        (
        void
        )
    {
    int need_update = 0;
    if( is_btc_connection_result_updated )
        {
        is_btc_connection_result_updated = 0;
        DeviceInterfaceBluetoothDeviceClass__NotifyBtcConnectionResult( device_object, btc_connection_result );
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
* ew_notify_btc_pairing_state_received
*
* Notify EW the BTC pairing state changed
*
*********************************************************************/
#ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyBtcPairingStateChanged_
    static int ew_notify_btc_pairing_state_received
        (
        void
        )
    {
    int need_update = 0;
    if( is_btc_pairing_state_changed )
        {
        is_btc_pairing_state_changed = 0;
        DeviceInterfaceBluetoothDeviceClass__NotifyBtcPairingStateChanged( device_object, btc_pairing_state );
        need_update = 1;
        }
    return need_update;
    }
#endif

/*********************************************************************
*
* @private
* ew_notify_ble_pairing_state_changed
*
* Notify EW the BLE pairing state changed
*
*********************************************************************/
#ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyBlePairingStateChanged_
    static int ew_notify_ble_pairing_state_changed
        (
        void
        )
    {
    int need_update = 0;
    if( is_ble_pairing_state_changed )
        {
        is_ble_pairing_state_changed = 0;
        DeviceInterfaceBluetoothDeviceClass__NotifyBlePairingStateChanged( device_object );
        need_update = 1;
        }
    return need_update;
    }
#endif

/*********************************************************************
*
* @private
* ew_notify_motocon_event_received
*
* Notify MotoCon event to EW GUI.
*
*********************************************************************/
#ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyMotoConEventReceived_
    static int ew_notify_motocon_event_received
        (
        void
        )
    {
    int need_update = 0;
    if( is_motocon_event_received )
        {
        is_motocon_event_received = 0;
        EnumMotoConRxEvent event;
        while( pdTRUE == xQueueReceive( motocon_rx_event_queue_handle, &event, 0 ) )
            {
            DeviceInterfaceBluetoothDeviceClass__NotifyMotoConEventReceived( device_object, event );
            }
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
* @param device_name The pointer to the pointer of the device name.
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
return BTM_is_ble_paired_device( paired_device_idx );
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
return BTM_get_enable_state();
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
return BTM_get_discoverable_state();
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
return BTM_get_autoconnect_state();
}

/*********************************************************************
*
* @public
* EW_notify_btc_passkey_generated
*
* Notify EW GUI that the BTC pairing passkey is generated.
*
* @param device_name Pointer to the BTC connecting device name
* @param passkey Passkey to pair BTC
*
*********************************************************************/
void EW_notify_btc_passkey_generated
    (
    const uint8_t* device_name,
    const uint32_t passkey
    )
{
#ifdef _DeviceInterfaceBluetoothDeviceClass_
    memcpy( btc_connecing_device_name, device_name, BT_DEVICE_NAME_LEN );
    btc_connecing_device_name[BT_DEVICE_NAME_LEN-1] = '\0';
    btc_passkey = passkey;
    is_btc_passkey_received = 1;
    EwBspEventTrigger();
#endif
}

/*********************************************************************
*
* @private
* ew_bt_get_btc_connecting_device_name
*
* @param device_name The pointer to the pointer to the device name.
*
*********************************************************************/
void ew_bt_get_btc_connecting_device_name
    (
    uint8_t** device_name
    )
{
*device_name = btc_connecing_device_name;
}

/*********************************************************************
*
* @public
* EW_notify_bt_refresh_paired_device_list
*
* Notify EW GUI the status of the Bluetooth paired device is changed
*
*********************************************************************/
void EW_notify_bt_paired_device_status_changed
    (
    void
    )
{
#ifdef _DeviceInterfaceBluetoothDeviceClass_
    is_btc_paired_device_status_updated = 1;
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
PRINTF( "%s, %d\r\n", __FUNCTION__, result );

#ifdef _DeviceInterfaceBluetoothDeviceClass_
    switch( result )
        {
        case BT_CONNECTION_SUCCESS:
            btc_connection_result = EnumBtDeviceConnectionResultSUCCESS;
            break;
        case BT_CONNECTION_FAIL:
            btc_connection_result = EnumBtDeviceConnectionResultFAIL;
            break;
        case BT_CONNECTION_AUTHENTICATION_ERR:
            btc_connection_result = EnumBtDeviceConnectionResultAUTHENTICATION_ERR;
            break;
        default:
            btc_connection_result = EnumBtDeviceConnectionResultFAIL;
            break;
        }
    is_btc_connection_result_updated = 1;
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

/*********************************************************************
*
* @private
* ew_set_ble_advertisement
*
* Enable/disable BLE advertisement
*
* @param enable True: Enable BLE advertisement, False: Disable BLE advertisement
*
*********************************************************************/
void ew_set_ble_advertisement
    (
    const bool enable
    )
{
if( enable )
    {
    ble_pairing_state = EnumBlePairingStateADVERTISING;
    }
else
    {
    ble_pairing_state = EnumBlePairingStateIDLE;
    }
BTM_set_ble_advertisement( enable );
}

/*********************************************************************
*
* @private
* ew_get_ble_pincode
*
* Get BLE pairing PIN code
*
* @return PIN code for BLE pairing
*
*********************************************************************/
uint32_t ew_get_ble_pincode
    (
    void
    )
{
return ble_pincode;
}

/*********************************************************************
*
* @public
* EW_notify_bt_passkey_generated
*
* Notify EW BTC passkey generated
*
* @param device_name Name of the Bluetooth device to pari
* @param passkey Passkey to pair BTC
*
*********************************************************************/
void EW_notify_bt_passkey_generated
    (
    const uint8_t* device_name,
    const uint32_t passkey
    )
{
EwPrint( "%s %s %d\r\n", __FUNCTION__, device_name, passkey );
memcpy( btc_connecing_device_name, device_name, BT_DEVICE_NAME_LEN );
btc_connecing_device_name[BT_DEVICE_NAME_LEN -1] = '\0';
btc_passkey = passkey;
btc_pairing_state = EnumBtcPairingStatePASSKEY_GENERATED;
is_btc_pairing_state_changed = true;
EwBspEventTrigger();
}

/*********************************************************************
*
* @public
* EW_notify_btc_pairing_state_changed
*
* Notify EW BTC pairing state changed
*
* @param state BTC pairing state
*
*********************************************************************/
void EW_notify_btc_pairing_state_changed
    (
    const EnumBtcPairingState state
    )
{
EwPrint( "%s %d\r\n", __FUNCTION__, state );
btc_pairing_state = state;
is_btc_pairing_state_changed = true;
EwBspEventTrigger();
}

/*********************************************************************
*
* @private
* ew_get_blc_pairing_state
*
* Get BTC pairing state
*
* @return BTC pairing state
*
*********************************************************************/
EnumBtcPairingState ew_get_blc_pairing_state
    (
    void
    )
{
EwPrint( "%s %d\r\n", __FUNCTION__, btc_pairing_state );
return btc_pairing_state;
}

/*********************************************************************
*
* @private
* ew_get_btc_passkey
*
* Get BTC pairing passkey
*
* @return Passkey for BTC pairing
*
*********************************************************************/
uint32_t ew_get_btc_passkey
    (
    void
    )
{
return btc_passkey;
}

/*********************************************************************
*
* @private
* ew_get_ble_pairing_state
*
* Get BLE pairing state
*
* @return BLE pairing state
*
*********************************************************************/
EnumBlePairingState ew_get_ble_pairing_state
    (
    void
    )
{
EwPrint( "%s %d\r\n", __FUNCTION__, ble_pairing_state );
return ble_pairing_state;
}

/*********************************************************************
*
* @public
* EW_notify_ble_pairing_state_changed
*
* Notify EW BLE pairing state changed
*
* @param state BLE pairing state
* @param param ble_pincode for EnumBlePairingEventPINCODE_GENERATED
*
*********************************************************************/
void EW_notify_ble_pairing_state_changed
    (
    const EnumBlePairingState state,
    const uint32_t            param
    )
{
EwPrint( "%s %d\r\n", __FUNCTION__, state );
ble_pairing_state = state;
if( EnumBlePairingStatePINCODE_GENERATED == state )
    {
    ble_pincode = param;
    }
is_ble_pairing_state_changed = true;
EwBspEventTrigger();
}

/*********************************************************************
* @public
* EW_notify_motocon_event_received
*
* Notify EW GUI the MotoCon event
*
* @param event MotoCon Rx Event
*
*********************************************************************/
void EW_notify_motocon_event_received
    (
    const EnumMotoConRxEvent event
    )
{
PRINTF( "%s, %d\r\n", __FUNCTION__, event );
if( pdTRUE == xQueueSend( motocon_rx_event_queue_handle, &event, 0 ) )
    {
    is_motocon_event_received = 1;
    EwBspEventTrigger();
    }
else
    {
    PRINTF( "Err: %s queue\r\n", __FUNCTION__ );
    }
}
