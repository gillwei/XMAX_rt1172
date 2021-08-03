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
#include <string.h>
#include "semphr.h"
#include "FreeRTOS.h"
#include "DeviceInterface.h"
#include "Enum.h"
#include "EW_pub.h"
#include "BT_pub.h"
#include "BC_motocon_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#ifdef _DeviceInterfaceBluetoothDeviceClass_
    typedef int bluetooth_device_function( void );
#endif
static int ew_notify_event_received( void );

#define MOTOCON_RX_EVENT_QUEUE_SIZE     ( 16 )
#define CONNECTION_STATUS_QUEUE_SIZE    ( 16 )
#define BTM_STATUS_QUEUE_SIZE           ( 8 )

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
        #ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyBtcConnectionResult_
            ew_bt_notify_btc_connection_result,
        #endif
        ew_notify_event_received
        };

    const int num_of_bluetooth_func = sizeof( bluetooth_function_lookup_table )/sizeof( bluetooth_device_function* );

    static uint32_t btc_passkey = 0;
    static uint8_t  btc_connecing_device_name[BT_DEVICE_NAME_LEN];
    static int      is_event_received = 0;
    static QueueHandle_t motocon_rx_event_queue_handle;
    static QueueHandle_t connection_status_queue_handle;
    static QueueHandle_t btm_status_queue_handle;
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
* ew_notify_event_received
*
* Notify event to EW GUI.
*
*********************************************************************/
static int ew_notify_event_received
    (
    void
    )
{
int need_update = 0;
if( is_event_received )
    {
    is_event_received = 0;

    #ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyMotoConEventReceived_
        EnumMotoConRxEvent motocon_event;
        while( pdTRUE == xQueueReceive( motocon_rx_event_queue_handle, &motocon_event, 0 ) )
            {
            DeviceInterfaceBluetoothDeviceClass__NotifyMotoConEventReceived( device_object, motocon_event );
            }
    #endif

    #ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyBtmStatus_
        EnumBtmStatus btm_status;
        while( pdTRUE == xQueueReceive( btm_status_queue_handle, &btm_status, 0 ) )
            {
            DeviceInterfaceBluetoothDeviceClass__NotifyBtmStatus( device_object, btm_status);
            }
    #endif

    #ifdef _DeviceInterfaceBluetoothDeviceClass__NotifyConnectionStatus_
        EnumConnectionStatus connection_status;
        while( pdTRUE == xQueueReceive( connection_status_queue_handle, &connection_status, 0 ) )
            {
            DeviceInterfaceBluetoothDeviceClass__NotifyConnectionStatus( device_object, connection_status );
            }
    #endif

    need_update = 1;
    }
return need_update;
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
* EW_notify_btc_passkey_generated
*
* Notify EW BTC passkey generated
*
* @param device_name Name of the Bluetooth device to pair
* @param passkey Passkey to confirm BTC pairing
*
*********************************************************************/
void EW_notify_btc_passkey_generated
    (
    const uint8_t* device_name,
    const uint32_t passkey
    )
{
EwPrint( "%s %s %u\r\n", __FUNCTION__, device_name, passkey );
memcpy( btc_connecing_device_name, device_name, BT_DEVICE_NAME_LEN );
btc_connecing_device_name[BT_DEVICE_NAME_LEN-1] = '\0';
btc_passkey = passkey;
EW_notify_connection_status( EnumConnectionStatusCONFIRM_PASSKEY );
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
* @public
* EW_notify_connection_status
*
* Notify EW GUI the bt/app connection status
*
* @param status BT/App connection status
* @param data Additional data for passkey
*
*********************************************************************/
void EW_notify_connection_status
    (
    const EnumConnectionStatus status
    )
{
PRINTF( "%s, %d\r\n", __FUNCTION__, status );
if( pdTRUE == xQueueSend( connection_status_queue_handle, &status, 0 ) )
    {
    is_event_received = 1;
    EwBspEventTrigger();
    }
else
    {
    PRINTF( "Err: %s queue\r\n", __FUNCTION__ );
    }
}

/*********************************************************************
* @public
* EW_notify_btm_status
*
* Notify EW GUI the BT manager status
*
* @param status BT manager status
*
*********************************************************************/
void EW_notify_btm_status
    (
    const EnumBtmStatus status
    )
{
PRINTF( "%s, %d\r\n", __FUNCTION__, status );
if( EnumBtmStatusFACTORY_RESET_COMPLETED == status )
    {
    ew_update_factory_reset_status( FACTORY_RESET_BT_MANAGER );
    }
else
    {
    if( pdTRUE == xQueueSend( btm_status_queue_handle, &status, 0 ) )
        {
        is_event_received = 1;
        EwBspEventTrigger();
        }
    else
        {
        PRINTF( "Err: %s queue\r\n", __FUNCTION__ );
        }
    }
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
    is_event_received = 1;
    EwBspEventTrigger();
    }
else
    {
    PRINTF( "Err: %s queue\r\n", __FUNCTION__ );
    }
}

/*********************************************************************
* @private
* ew_send_motocon_command
*
* Send MotoCon command
*
* @param command MotoCon command
*
*********************************************************************/
void ew_send_motocon_command
    (
    const EnumMotoConTx command
    )
{
PRINTF( "%s, %d\r\n", __FUNCTION__, command );
switch( command )
    {
    case EnumMotoConTxCREATE_OTA_CONNECTION:
        BC_motocon_send_create_ota_request();
        break;
    default:
        break;
    }
}

/*********************************************************************
* @private
* ew_device_bt_create_queue
*
* Create queue
*
*********************************************************************/
void ew_device_bt_create_queue
    (
    void
    )
{
motocon_rx_event_queue_handle = xQueueCreate( MOTOCON_RX_EVENT_QUEUE_SIZE, sizeof( EnumMotoConRxEvent ) );
configASSERT( NULL != motocon_rx_event_queue_handle );

btm_status_queue_handle = xQueueCreate( BTM_STATUS_QUEUE_SIZE, sizeof( EnumBtmStatus ) );
configASSERT( NULL != btm_status_queue_handle );

connection_status_queue_handle = xQueueCreate( CONNECTION_STATUS_QUEUE_SIZE, sizeof( EnumConnectionStatus ) );
configASSERT( NULL != connection_status_queue_handle );
}
