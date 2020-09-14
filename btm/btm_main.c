/*********************************************************************
* @file
* btm_main.c
*
* @brief
* Bluetooth module - main
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <stdio.h>
#include "FreeRTOS.h"
#include "event_groups.h"
#include "task.h"
#include "queue.h"
#include "fsl_common.h"
#include "fsl_debug_console.h"
#include "error_code.h"
#include "timers.h"
#include "EEPM_pub.h"
#include "EW_pub.h"
#include "BTM_pub.h"
#ifdef BTM_PRINT_TASK_STACK_USAGE
    #include "FRTOS_pub.h"
#endif
#include "hci_control_api.h"
#include "HCI_pub.h"
#include "BT_UPDATE_pub.h"
#include "fsl_gpio.h"
#include "GRM_pub_prj.h"
#include "factory_test.h"
#include "bt_spp_iap2.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define TASK_PRIORITY               ( TASK_PRIO_BT_MNGR )
#define TASK_STACK_SIZE             ( 256 )
#define TASK_NAME                   ( "bt_task" )
#define MSG_QUEUE_LENGTH            ( 10 )
#define BT_MAX_PAIRED_DEVICE_NUM    ( 1 )

#define EVENT_MSG_RECEIVED          ( 1 << 0 )

#define TIMEOUT_MS                  ( 5000 )

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
typedef struct
    {
    uint8_t   device_name[BT_DEVICE_NAME_LEN];        /**< the Bluetooth device name */
    uint8_t   device_address[BT_DEVICE_ADDRESS_LEN];  /**< the Bluetooth device address */
    bool      is_connected;                           /**< is connected flag */
    uint16_t  connection_handle;                      /**< connection handle */
    } bt_device_info;

typedef enum
    {
    MSG_ENABLE_BT,
    MSG_DISABLE_BT,
    MSG_ENABLE_DISCOVERABLE,
    MSG_DISABLE_DISCOVERABLE,
    MSG_ENABLE_AUTOCONNECT,
    MSG_DISABLE_AUTOCONNECT,
    MSG_CONNECT_DEVICE,
    MSG_DISCONNECT_DEVICE,
    MSG_PAIR_DEVICE,
    MSG_UNPAIR_DEVICE,
    MSG_GET_LOCAL_ADDRESS,
    } message_type;

typedef struct
    {
    message_type  type;
    uint8_t       device_address[BT_DEVICE_ADDRESS_LEN];
    uint16_t      connection_handle;
    } message_object;

/** BR/EDR Discoverable modes */
typedef enum
    {
    BT_NON_DISCOVERABLE,
    BT_DISCOVERABLE
    } wiced_bt_discoverability_t;

/** BR/EDR Connectable modes */
typedef enum
    {
    BT_NON_CONNECTABLE,
    BT_CONNECTABLE
    } wiced_bt_connectability_t;

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/
const uint8_t bd_addr_default[BT_DEVICE_ADDRESS_LEN] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/
static EventGroupHandle_t event_group   = NULL;
static QueueHandle_t      message_queue = NULL;

static bool is_bt_enable = false;          /* false: BT is disable.    true: BT is enable */
static bool is_bt_discoverable = false;    /* false: not discoverable, true: discoverable */
static bool is_bt_autoconnectable = false; /* false: not auto-connect, true: auto-connect */
static int  paired_device_num = 0;
static uint8_t local_device_name[BT_DEVICE_NAME_LEN];       /* local device name */
static uint8_t local_device_address[BT_DEVICE_ADDRESS_LEN]; /* local MAC address */

static bt_device_info paired_device_list[BT_MAX_PAIRED_DEVICE_NUM];
static uint8_t bt_sw_version[BT_SW_VERSION_LEN];            /* BT SW Major version and Minor version  */

typedef struct
    {
    uint8_t is_done;
    uint8_t is_success;
    } reset_result;

typedef struct
    {
    reset_result enable;
    reset_result autoconn;
    uint8_t      is_running_factory_reset;
    void         ( *factory_reset_callback_func_ptr )( int );
    } reset_status_type;

reset_status_type reset_status;
static TimerHandle_t timeout_timer_handle;

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
static void disable_discoverable
    (
    void
    );

/*********************************************************************
*
* @private
* bd_addr_write_cb
*
* @brief callback function for BD address write operation.
*
*********************************************************************/
static void bd_addr_write_cb
    (
    bool    status,
    void*   data
    )
{
if( false == status )
    {
    PRINTF( "%s status false!\r\n", __FUNCTION__ );
    }
}

/*********************************************************************
*
* @public
* stop_timeout_timer
*
* Stop delay timer to delay sending time information.
*
*********************************************************************/
void stop_timeout_timer
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
BaseType_t result = xTimerStop( timeout_timer_handle, 0 );
configASSERT( result == pdPASS );
}

/*********************************************************************
*
* @private
* start_timeout_timer
*
* Start delay timer to delay sending time information.
*
*********************************************************************/
void start_timeout_timer
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
BaseType_t result = xTimerStart( timeout_timer_handle, 0 );
configASSERT( result == pdPASS );
}

/*********************************************************************
*
* @private
* timeout_timer_callback
*
* A timer callback function of timeout timer.
*
* @param timer_handle The handle of timeout timer.
*
*********************************************************************/
static void timeout_timer_callback
    (
    TimerHandle_t timer_handle
    )
{
stop_timeout_timer();
BTM_notify_EW_connection_status( BT_CONNECTION_FAIL );
}

/*********************************************************************
*
* @private
* create_timeout_timer
*
* Create the timeout timer.
*
*********************************************************************/
static void create_timeout_timer
    (
    void
    )
{
timeout_timer_handle = xTimerCreate( "btm_timeout_timer", pdMS_TO_TICKS( TIMEOUT_MS ), pdTRUE, ( void * ) 0, timeout_timer_callback );
configASSERT( NULL != timeout_timer_handle );
}

/*********************************************************************
*
* @private
* enable_bt
*
* Enable Bluetooth.
*
*********************************************************************/
static void enable_bt
    (
    void
    )
{
is_bt_enable = 1;
EEPM_set_BT_en( 1, NULL );
}

/*********************************************************************
*
* @private
* disable_bt
*
* Disable Bluetooth.
*
*********************************************************************/
static void disable_bt
    (
    void
    )
{
if( is_bt_enable != 0 )
    {
    is_bt_enable = 0;
    EEPM_set_BT_en( 0, NULL );
    }

disable_discoverable();
BTM_disconnect_paired_device( 0 );
}

/*********************************************************************
*
* @private
* enable_discoverable
*
* Make system discoverable to other Bluetooth device.
*
*********************************************************************/
static void enable_discoverable
    (
    void
    )
{
uint8_t data[2];
data[0] = BT_DISCOVERABLE;
data[1] = BT_CONNECTABLE;

is_bt_discoverable = true;
PRINTF("%s\n\r", __FUNCTION__ );
HCI_wiced_send_command( HCI_CONTROL_COMMAND_SET_VISIBILITY, &(data[0]), sizeof( data ) );
}

/*********************************************************************
*
* @private
* disable_discoverable
*
* Make system not discoverable to other Bluetooth device.
*
*********************************************************************/
static void disable_discoverable
    (
    void
    )
{
uint8_t data[2];
data[0] = BT_NON_DISCOVERABLE;
data[1] = BT_NON_CONNECTABLE;

is_bt_discoverable = 0;
PRINTF( "%s\n\r", __FUNCTION__ );
HCI_wiced_send_command( HCI_CONTROL_COMMAND_SET_VISIBILITY, &(data[0]), sizeof( data ) );
}

/*********************************************************************
*
* @private
* enable_autoconnect
*
* Turn on Bluetooth auto connection.
*
*********************************************************************/
static void enable_autoconnect
    (
    void
    )
{
is_bt_autoconnectable = 1;
EEPM_set_BT_autoconn( 1, NULL );
}

/*********************************************************************
*
* @private
* disable_autoconnect
*
* Turn off Bluetooth auto connection.
*
*********************************************************************/
static void disable_autoconnect
    (
    void
    )
{
is_bt_autoconnectable = 0;
EEPM_set_BT_autoconn( 0, NULL );
}

/*********************************************************************
*
* @private
* connect_device
*
* Connect device.
*
* @param device_address The pointer to the device address to connect.
*
*********************************************************************/
static void connect_device
    (
    const uint8_t* device_address
    )
{
PRINTF( "%s: %s\r\n", __FUNCTION__, device_address );
uint8_t bd_addr_rev[BT_DEVICE_ADDRESS_LEN];
for( uint8_t i = 0; i < BT_DEVICE_ADDRESS_LEN; i++ )
    {
    bd_addr_rev[i] = device_address[BT_DEVICE_ADDRESS_LEN - 1 - i];
    }
HCI_wiced_send_command( HCI_CONTROL_SPP_COMMAND_CONNECT, bd_addr_rev, BT_DEVICE_ADDRESS_LEN );
start_timeout_timer();
}

/*********************************************************************
*
* @private
* disconnect_device
*
* Disconnect device.
*
* @param device_address The pointer to the device address to disconnect.
*
*********************************************************************/
static void disconnect_device
    (
    const uint16_t connection_handle
    )
{
uint8_t connection_handle_bytes[2];

PRINTF( "%s: connection handle:%04x\r\n", __FUNCTION__, connection_handle );
connection_handle_bytes[0] = 0xff & (uint8_t)(paired_device_list[0].connection_handle);
connection_handle_bytes[1] = (uint8_t)( paired_device_list[0].connection_handle >> 8 );

// Here assume the disconnect always success
paired_device_list[0].is_connected = false;
paired_device_list[0].connection_handle = 0;

// disconnect device through HCI command
HCI_wiced_send_command( HCI_CONTROL_SPP_COMMAND_DISCONNECT, &(connection_handle_bytes[0]), sizeof( uint16_t ) );
HCI_wiced_send_command( HCI_CONTROL_IAP2_COMMAND_DISCONNECT, &(connection_handle_bytes[0]), sizeof( uint16_t ) );
}

/*********************************************************************
*
* @private
* unpair_device
*
* Unpair device.
*
* @param device_address The pointer to the device address to unpair.
*
*********************************************************************/
static void unpair_device
    (
    const uint8_t* device_address
    )
{
// unpair device through HCI command
HCI_wiced_send_command( HCI_CONTROL_COMMAND_UNBOND, device_address, BT_DEVICE_ADDRESS_LEN );

// Since the unbond command only disconnect SPP connection, need to add disconnect iAP2
BTM_disconnect_paired_device( 0 );

paired_device_num = 0;
memset( &paired_device_list[0].device_address, 0, BT_DEVICE_ADDRESS_LEN );
memset( &paired_device_list[0].device_name, 0, BT_DEVICE_NAME_LEN );
}

/*********************************************************************
*
* @private
* send_message
*
* Send message to queue.
*
*********************************************************************/
static void send_message
    (
    const message_object msg_obj
    )
{
if( pdPASS == xQueueSend( message_queue, &msg_obj, 0 ) )
    {
    xEventGroupSetBits( event_group, EVENT_MSG_RECEIVED );
    }
else
    {
    EwPrint( "%s err\r\n", __FUNCTION__ );
    }
}

/*********************************************************************
*
* @private
* update_factory_reset_status
*
* Update factory reset status and callback if done
*
*********************************************************************/
static void update_factory_reset_status
    (
    void
    )
{
if( NULL != reset_status.factory_reset_callback_func_ptr &&
    reset_status.enable.is_done &&
    reset_status.autoconn.is_done )
    {
    int result = reset_status.enable.is_success & reset_status.autoconn.is_success;
    reset_status.factory_reset_callback_func_ptr( result );
    }
}

/*********************************************************************
*
* @private
* eeprom_read_BT_enable_callback
*
* EEPROM read callback
*
*********************************************************************/
static void eeprom_read_BT_enable_callback
    (
    bool  result,
    void* data
    )
{
if( result )
    {
    is_bt_enable = ( 1 == *( int* )data) ? 1 : 0;
    }
}

/*********************************************************************
*
* @private
* eeprom_read_BT_autoconn_callback
*
* EEPROM read callback
*
*********************************************************************/
static void eeprom_read_BT_autoconn_callback
    (
    bool  result,
    void* data
    )
{
if( result )
    {
    is_bt_autoconnectable = ( 1 == *( int* )data) ? 1 : 0;
    }
}

/*********************************************************************
*
* @private
* eeprom_read_bd_address_callback
*
* EEPROM read callback
*
*********************************************************************/
static void eeprom_read_bd_address_callback
    (
    bool  result,
    void* data
    )
{
if( result )
    {
    memcpy( local_device_address, (uint8_t *)data, BT_DEVICE_ADDRESS_LEN );
    }
}

/*********************************************************************
*
* @private
* eeprom_write_BT_enable_callback
*
* EEPROM write BT enable callback
*
*********************************************************************/
static void eeprom_write_BT_enable_callback
    (
    bool  result,
    void* data
    )
{
if( reset_status.is_running_factory_reset )
    {
    reset_status.enable.is_done = 1;
    reset_status.enable.is_success = ( uint8_t )result;
    update_factory_reset_status();
    }
}

/*********************************************************************
*
* @private
* eeprom_write_BT_autocon_callback
*
* EEPROM write BT auto connection callback
*
*********************************************************************/
static void eeprom_write_BT_autocon_callback
    (
    bool  result,
    void* data
    )
{
if( reset_status.is_running_factory_reset )
    {
    reset_status.autoconn.is_done = 1;
    reset_status.autoconn.is_success = ( uint8_t )result;
    update_factory_reset_status();
    }
}

/*********************************************************************
*
* @private
* get_settings_from_eeprom
*
* Get enable and auto connection settings from EEPROM
*
*********************************************************************/
static void get_settings_from_eeprom
    (
    void
    )
{
if( pdTRUE != EEPM_get_BT_en( &eeprom_read_BT_enable_callback ) )
    {
    PRINTF( "%s get_BT_en false\r\n", __FUNCTION__ );
    }

if( pdTRUE != EEPM_get_BT_autoconn( &eeprom_read_BT_autoconn_callback ) )
    {
    PRINTF( "%s get_BT_autoconn false\r\n", __FUNCTION__ );
    }

if( pdTRUE != EEPM_get_bd_address( &eeprom_read_bd_address_callback ) )
    {
    PRINTF( "EEPM_get_bd_address get_BT_en false\r\n");
    }
}

/*********************************************************************
*
* @public
* BTM_notify_EW_connection_status
*
* Call for notify EW connection status.
*
*********************************************************************/
void BTM_notify_EW_connection_status
    (
    bt_connection_result_type bt_connection_type
    )
{
stop_timeout_timer();
EW_notify_bt_connection_result( bt_connection_type );
}

/*********************************************************************
*
* @public
* BTM_connection_info_update
*
* Update BT manager connection status and connection handle
*
* @param connection_is_up  BTC connection status
* @param connection_info   BTC connection handle 2 bytes
*
*********************************************************************/
void BTM_connection_info_update
    (
    const bool     connection_is_up,
    const uint8_t* connection_info
    )
{
paired_device_list[0].is_connected = connection_is_up;
paired_device_list[0].connection_handle = connection_info[BT_DEVICE_ADDRESS_LEN];
paired_device_list[0].connection_handle += (uint16_t)( connection_info[BT_DEVICE_ADDRESS_LEN + 1] << 8 );
}

/*********************************************************************
*
* @public
* BTM_get_connection_info
*
* Get current connection status
*
* @param connection_is_up  BTC connection status
* @param connection_info   BTC connection handle 2 bytes
*
*********************************************************************/
void BTM_get_connection_info
    (
    bool*     current_connection_status,
    uint16_t* connection_handle
    )
{
memcpy( current_connection_status, &(paired_device_list[0].is_connected), sizeof( bool ) );
memcpy( connection_handle, &(paired_device_list[0].connection_handle), sizeof( uint16_t ) );
}

/*********************************************************************
*
* @public
* BTM_pairing_info_update
*
* Update BT manager device address and device name
*
* @param pairing_info Updated pair device address and name
*
*
*********************************************************************/
void BTM_pairing_info_update
    (
    const uint8_t *pairing_info
    )
{
paired_device_num = 1;
memcpy( &paired_device_list[0].device_address, &(pairing_info[0]), BT_DEVICE_ADDRESS_LEN );
memcpy( &paired_device_list[0].device_name, &(pairing_info[BT_DEVICE_ADDRESS_LEN]), BT_DEVICE_NAME_LEN );
}

/*********************************************************************
*
* @public
* BTM_reset_factory_default
*
* Reset Bluetooth settings to factory default
*
* @param callback_func_ptr The function pointer to the callback function
*                          which will be called after factory reset is done.
*
*********************************************************************/
void BTM_reset_factory_default
    (
    void ( *callback_func_ptr )( int )
    )
{
reset_status.is_running_factory_reset = true;
reset_status.factory_reset_callback_func_ptr = callback_func_ptr;

BTM_unpair_paired_device( 0 );

if( pdTRUE != EEPM_set_BT_en( 0, &eeprom_write_BT_enable_callback ) )
    {
    PRINTF( "reset BT en fail\r\n" );
    }
if( pdTRUE != EEPM_set_BT_autoconn( 0, &eeprom_write_BT_autocon_callback ) )
    {
    PRINTF( "reset BT autoconn fail\r\n" );
    }
}

/*********************************************************************
*
* @public
* BTM_set_enable_state
*
* Set Bluetooth enable/disable
*
* @param state True: enable, false: disable
*
*********************************************************************/
int BTM_set_enable_state
    (
    bool state
    )
{
message_object msg_obj;
if( state )
    {
    msg_obj.type = MSG_ENABLE_BT;
    }
else
    {
    msg_obj.type = MSG_DISABLE_BT ;
    }
send_message( msg_obj );

return ERR_NONE;
}

/*********************************************************************
*
* @public
* BTM_get_enable_state
*
* Return the state of Bluetooth.
*
*********************************************************************/
bool BTM_get_enable_state
    (
    void
    )
{
return is_bt_enable;
}

/*********************************************************************
*
* @public
* BTM_set_discoverable_state
*
* Set the discoverable state.
*
*********************************************************************/
int BTM_set_discoverable_state
    (
    bool state
    )
{
message_object msg_obj;
is_bt_discoverable = state;
if( state )
    {
    msg_obj.type = MSG_ENABLE_DISCOVERABLE;
    }
else
    {
    msg_obj.type = MSG_DISABLE_DISCOVERABLE;
    }
send_message( msg_obj );
return ERR_NONE;
}

/*********************************************************************
*
* @public
* BTM_get_discoverable_state
*
* Return the discoverable state.
*
*********************************************************************/
bool BTM_get_discoverable_state
    (
    void
    )
{
return is_bt_discoverable;
}

/*********************************************************************
*
* @public
* BTM_set_autoconnect_state
*
* Set the state of Bluetooth auto connection.
*
*********************************************************************/
int BTM_set_autoconnect_state
    (
    bool state
    )
{
PRINTF( "%s %d\r\n", __FUNCTION__, state );
message_object msg_obj;
is_bt_autoconnectable = state;
if( is_bt_autoconnectable )
    {
    msg_obj.type = MSG_ENABLE_AUTOCONNECT;
    }
else
    {
    msg_obj.type = MSG_DISABLE_AUTOCONNECT;
    }
send_message( msg_obj );
return ERR_NONE;
}

/*********************************************************************
*
* @public
* BTM_get_autoconnect_state
*
* Get the state of Bluetooth auto connection.
*
*********************************************************************/
bool BTM_get_autoconnect_state
    (
    void
    )
{
return is_bt_autoconnectable;
}

/*********************************************************************
*
* @public
* BTM_is_max_paired_device_num
*
* Return if paired device num reaches max
*
*********************************************************************/
bool BTM_is_max_paired_device_num
    (
    void
    )
{
return ( paired_device_num >= BT_MAX_PAIRED_DEVICE_NUM );
}

/*********************************************************************
*
* @public
* BTM_get_paired_device_addr
*
* Get paired device address
*
* @param paired_device_idx The index of paired_device_list.
* @param device_addr       Use memcpy to copy the pair device address
*                          data to the pointed address
*
*********************************************************************/
int BTM_get_paired_device_addr
    (
    const int paired_device_idx,
    uint8_t*  device_addr
    )
{
int result = 0;
if( paired_device_idx <= paired_device_num )
    {
    memcpy( device_addr, paired_device_list[paired_device_idx].device_address, BT_DEVICE_ADDRESS_LEN );
    result = 1;
    }
PRINTF( "%s\r\n", __FUNCTION__);
return result;
}

/*********************************************************************
*
* @public
* BTM_get_paired_device_num
*
* Get the paired device num
*
*********************************************************************/
int BTM_get_paired_device_num
    (
    void
    )
{
PRINTF( "%s, %d\r\n", __FUNCTION__, paired_device_num );
return paired_device_num;
}

/*********************************************************************
*
* @public
* BTM_get_paired_device_info
*
* Get paired device info
*
* @param paired_device_idx The index of paired_device_list.
* @param device_name The pointer to the pointer of the device name char array.
* @param is_connected The pointer to the is_connected bool value.
*
*********************************************************************/
int BTM_get_paired_device_info
    (
    const int paired_device_idx,
    uint8_t** device_name,
    bool*     is_connected
    )
{
int result = 0;
if( paired_device_idx <= paired_device_num )
    {
    *device_name  = paired_device_list[paired_device_idx].device_name;
    *is_connected = paired_device_list[paired_device_idx].is_connected,
    result = 1;
    }
PRINTF( "%s, %d, %s, %d\r\n", __FUNCTION__, paired_device_idx, *device_name, *is_connected );
return result;
}

/*********************************************************************
*
* @public
* BTM_connect_paired_device
*
* Connect paired device.
*
* @param paired_device_idx The index of paired_device_list.
*
*********************************************************************/
int BTM_connect_paired_device
    (
    const int paired_device_idx
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
for( uint8_t i=0; i < BT_DEVICE_ADDRESS_LEN; i++ )
    {
    PRINTF( " %02x", paired_device_list[0].device_address[i] );
    }
PRINTF("\r\n");
message_object msg_obj;
msg_obj.type = MSG_CONNECT_DEVICE;
memcpy( msg_obj.device_address, paired_device_list[0].device_address, BT_DEVICE_ADDRESS_LEN );
send_message( msg_obj );
return ERR_NONE;
}

/*********************************************************************
*
* @public
* BTM_disconnect_paired_device
*
* Disconnect device.
*
* @param paired_device_idx The index of paired_device_list.
*
*********************************************************************/
int BTM_disconnect_paired_device
    (
    const int paired_device_idx
    )
{
message_object msg_obj;
msg_obj.type = MSG_DISCONNECT_DEVICE;
msg_obj.connection_handle = paired_device_list[paired_device_idx].connection_handle;
send_message( msg_obj );
return ERR_NONE;
}

/*********************************************************************
*
* @public
* BTM_unpair_paired_device
*
* Unpair paired device.
*
* @param paired_device_idx The index of paired_device_list.
*
*********************************************************************/
int BTM_unpair_paired_device
    (
    const int paired_device_idx
    )
{
int result = ERR_NONE;

message_object msg_obj;
msg_obj.type = MSG_UNPAIR_DEVICE;
memcpy( msg_obj.device_address, paired_device_list[paired_device_idx].device_address, BT_DEVICE_ADDRESS_LEN );
send_message( msg_obj );

return result;
}

/*********************************************************************
*
* @public
* BTM_get_local_device_name
*
* Get the local device name
*
* @param device_name The pointer to the pointer to the device name.
*
*********************************************************************/
int BTM_get_local_device_name
    (
    uint8_t** device_name
    )
{
*device_name = local_device_name;
return ERR_NONE;
}

/*********************************************************************
*
* @public
* BTM_get_local_device_address
*
* Get the local device address
*
* @param device_name The pointer to the device address.
*
*********************************************************************/
int BTM_get_local_device_address
    (
    uint8_t* device_address
    )
{
PRINTF( "%s", __FUNCTION__  );
for( uint8_t i = 0; i < BT_DEVICE_ADDRESS_LEN; i++ )
{
    PRINTF( " %02x", local_device_address[i]  );
}
PRINTF("\r\n");

memcpy( device_address, local_device_address, BT_DEVICE_ADDRESS_LEN );
return ERR_NONE;
}

/*********************************************************************
*
* @public
* BTM_set_local_device_address
*
* When receive 89820 return local device address, update local address also
*
* @param device_name The pointer to the pointer to the device address.
*
*********************************************************************/
int BTM_set_local_device_address
    (
    uint8_t* device_address
    )
{
memcpy( local_device_address, device_address, BT_DEVICE_ADDRESS_LEN );
return ERR_NONE;
}

/*********************************************************************
*
* @public
* BTM_IOP_read_local_device_address
*
* Read BT module device address
*
*
*********************************************************************/
int BTM_IOP_read_local_device_address
    (
    void
    )
{
PRINTF( "%s\n\r", __FUNCTION__ );
// If the last set bd address are all 0xff, then don't ask BT chip bd address
// Send local bd address for IOP
if( 0 == memcmp( local_device_address, bd_addr_default, BT_DEVICE_ADDRESS_LEN ) )
    {
    sent_iop_bd_address();
    }
else
    {
    HCI_wiced_send_command( HCI_CONTROL_COMMAND_READ_LOCAL_BDA, NULL, 0 );
    }

return ERR_NONE;
}

/*********************************************************************
*
* @public
* BTM_IOP_set_local_device_address
*
* For production IOP, send command set 89820 BD address and EEPROM BD
* address.
*
* @param device_name The pointer to the pointer to the device address.
*
*********************************************************************/
int BTM_IOP_set_local_device_address
    (
    uint8_t* bd_addr
    )
{
uint8_t factory_commit_addr_cmd[BT_DEVICE_ADDRESS_LEN + 1] = { 0 };
uint8_t bd_addr_rev[BT_DEVICE_ADDRESS_LEN];

for( uint8_t i = 0; i < BT_DEVICE_ADDRESS_LEN; i++ )
    {
    bd_addr_rev[i] = bd_addr[BT_DEVICE_ADDRESS_LEN - 1 - i];
    }

PRINTF( "%s ", __FUNCTION__  );
for( uint8_t i = 0; i < BT_DEVICE_ADDRESS_LEN; i++ )
    {
    PRINTF( " %02x", bd_addr_rev[i]  );
    }
PRINTF("\r\n");

/* If BD address set to ALL 0xFF, then update BT firmware and return */
if( 0 == memcmp( bd_addr_rev, bd_addr_default, BT_DEVICE_ADDRESS_LEN ) )
    {
    if( pdTRUE == EEPM_set_bd_address( bd_addr_rev, bd_addr_write_cb ) )
        {
        BTM_set_local_device_address( bd_addr_rev );
        BT_UPDATE_received();
        }
    else
        {
        PRINTF("EEPM_set_bd_address fail\n\r");
        }
    }
else
    {
    memcpy( &factory_commit_addr_cmd[0], &bd_addr[0], BT_DEVICE_ADDRESS_LEN );

    if( pdTRUE == EEPM_set_bd_address( bd_addr_rev, bd_addr_write_cb ) )
        {
        BTM_set_local_device_address( bd_addr_rev );
        BT_UPDATE_standard_send_command( OPCODE_RESET, NULL, 0 );
        BT_UPDATE_setParserStatus( PARSER_STANDARD_HCI );
        vTaskDelay( pdMS_TO_TICKS( COMMON_CMD_WAIT_MS ) );
        BT_UPDATE_standard_send_command( OPCODE_COMMIT_ADDR, factory_commit_addr_cmd, sizeof( factory_commit_addr_cmd ) );
        }
    else
        {
        PRINTF("EEPM_set_bd_address fail\n\r");
        }
    }
return ERR_NONE;
}

/*********************************************************************
*
* @public
* BTM_update_sw_version
*
* After BT update check, update BTM BT SW version
*
* @param update_bt_sw_version
*
*********************************************************************/
int BTM_update_sw_version
    (
    uint8_t* update_bt_sw_version
    )
{
memcpy( bt_sw_version, update_bt_sw_version, BT_SW_VERSION_LEN );
return ERR_NONE;
}

/*********************************************************************
*
* @public
* BTM_get_sw_version
*
* Used for EW to get BT SW version
*
* @param return_bt_sw_version
*
*********************************************************************/
int BTM_get_sw_version
    (
    uint8_t* return_bt_sw_version
    )
{
memcpy( return_bt_sw_version, bt_sw_version, BT_SW_VERSION_LEN );
return ERR_NONE;
}

/*********************************************************************
*
* @private
* process_message
*
* Process the message in the Bluetooth manager
*
*********************************************************************/
static void process_message
    (
    void
    )
{
message_object msg_obj;
while( pdPASS == xQueueReceive( message_queue, &msg_obj, 0 ) )
    {
    switch( msg_obj.type )
        {
        case MSG_ENABLE_BT:
            enable_bt();
            break;
        case MSG_DISABLE_BT:
            disable_bt();
            break;
        case MSG_ENABLE_DISCOVERABLE:
            enable_discoverable();
            break;
        case MSG_DISABLE_DISCOVERABLE:
            disable_discoverable();
            break;
        case MSG_ENABLE_AUTOCONNECT:
            enable_autoconnect();
            break;
        case MSG_DISABLE_AUTOCONNECT:
            disable_autoconnect();
            break;
        case MSG_CONNECT_DEVICE:
            connect_device( msg_obj.device_address );
            break;
        case MSG_DISCONNECT_DEVICE:
            disconnect_device( msg_obj.connection_handle );
            break;
        case MSG_UNPAIR_DEVICE:
            unpair_device( msg_obj.device_address );
            break;
        default:
            break;
        }
    }
}

/*********************************************************************
*
* @private
* bt_task_main
*
* Main loop of the Bluetooth manager task
*
*********************************************************************/
static void bt_task_main
    (
    void* arg
    )
{
EventBits_t event_bits;

vTaskDelay( pdMS_TO_TICKS( 50 ) );
get_settings_from_eeprom();
sprintf( (char *)local_device_name, "LINKCARD" );
memset( bt_sw_version, 0, BT_SW_VERSION_LEN );

while( true )
    {
    event_bits = xEventGroupWaitBits
                    (
                    event_group,    /* The event group handle. */
                    EVENT_MSG_RECEIVED,
                    pdTRUE,         /* clear on exit */
                    pdFALSE,        /* Don't wait for both bits, either bit unblock task. */
                    portMAX_DELAY   /* Block indefinitely to wait for the condition to be met. */
                    );

    if( EVENT_MSG_RECEIVED == ( event_bits & EVENT_MSG_RECEIVED ) )
        {
        process_message();
        }

    #ifdef BTM_PRINT_TASK_STACK_USAGE
        FRTOS_print_task_status( xTaskGetCurrentTaskHandle() );
    #endif
    }

vTaskDelete( NULL );
}

/*********************************************************************
*
* @private
* create_task
*
* Create the Bluetooth manager task
*
*********************************************************************/
static void create_task
    (
    void
    )
{
BaseType_t result = xTaskCreate( bt_task_main, TASK_NAME, TASK_STACK_SIZE, NULL, TASK_PRIORITY, NULL );
configASSERT( pdPASS == result );
}

/*********************************************************************
*
* @public
* BTM_init
*
* Initialize Bluetooth manager module
*
*********************************************************************/
void BTM_init
    (
    void
    )
{
message_queue = xQueueCreate( MSG_QUEUE_LENGTH, sizeof( message_object ) );
configASSERT( NULL != message_queue );

event_group = xEventGroupCreate();
configASSERT( NULL != event_group );

create_timeout_timer();
create_task();
}

