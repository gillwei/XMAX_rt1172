/*********************************************************************
* @file
* btm_main.c
*
* @brief
* Bluetooth module - main
*
* Copyright 2020-2021 by Garmin Ltd. or its subsidiaries.
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
#include "hci_control_api_extend.h"
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
#define BT_MAX_PAIRED_DEVICE_NUM    ( 8 )
#define ENABLED                     ( 1 )

#define EVENT_MSG_RECEIVED          ( 1 << 0 )

#define AUTOCONNECT_TIMEOUT_MS      ( 15000 )
#define CONNECTION_HANDLE_LENGTH    sizeof( uint16_t )

#define BTM_TIMER_PERIOD_MS         1000
#define BTM_TICK_PERIOD_MS          pdMS_TO_TICKS( BTM_TIMER_PERIOD_MS )
#define BTM_TIMER_FIVE_SECONDS     ( 5000 / BTM_TICK_PERIOD_MS )
#define BTM_TIMER_THIRTY_SECONDS   ( 30000 / BTM_TICK_PERIOD_MS )
#define BTM_TIMER_SIXTY_SECONDS    ( 60000 / BTM_TICK_PERIOD_MS )
#define USER_CONFIRM_EVT_PIN_CODE_LENGTH  sizeof( uint32_t )
#define USER_CONFIRM_RESULT_DATA_LENGTH   ( USER_CONFIRM_EVT_PIN_CODE_LENGTH + BT_DEVICE_NAME_LEN )
#define HCI_ERR_PEER_USER                 0x13
#define HCI_ERR_CONN_CAUSE_LOCAL_HOST     0x16

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
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
    MSG_UNPAIR_ALL_DEVICE,
    MSG_SET_BLE_ADV,
    MSG_USER_CONFIRM_PASSKEY
    } message_type;

typedef struct
    {
    message_type  type;
    uint8_t       device_address[BT_DEVICE_ADDRESS_LEN];
    uint16_t      connection_handle;
    uint8_t       pair_dev_index;
    bool          ble_adv_enable;
    bool          user_confirm_result;
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

typedef struct
    {
    uint8_t   device_name[BT_DEVICE_NAME_LEN];        /**< the Bluetooth device name */
    uint8_t   device_address[BT_DEVICE_ADDRESS_LEN];  /**< the Bluetooth device address */
    bool      is_connected;                           /**< is connected flag */
    uint16_t  connection_handle;                      /**< connection handle */
    bt_connection_path_type  connection_path_type;    /**< connection profile type */
    } bt_device_info;

typedef struct BTM_BTC_CONNECTION_STATUS
    {
    uint16_t  current_connection_handle;              /**< BTC connection handle  */
    bool      BTC_is_connected;                       /**< BTC is connected flag */
    } btm_btc_connection_status_t;

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

typedef enum BTM_TIMEOUT_TYPE
    {
    BTM_TIMEOUT_IDLE,
    BTM_CONNECT_TIMEOUT,
    BTM_BLE_ADV_TIMEOUT,
    BTM_BLE_PHONE_USER_CONFIRM_TIMEOUT
    } btm_timeout_type_t;

typedef enum BTM_BLE_PAIRING_RESULT
    {
    BTM_BTC_BLE_PAIRING_SUCCESS
    } btm_ble_pairing_result_t;

typedef enum BTM_PAIRING_STATE
    {
    BTM_PAIRING_STATE_NON,
    BTM_PAIRING_STATE_BTC,
    BTM_PAIRING_STATE_BLE
    } btm_pairing_state_t;

typedef enum BTM_DISCOVERABLE_STATE
    {
    BTM_DISCOVERABLE_STATE_NON,
    BTM_DISCOVERABLE_STATE_BTC,
    BTM_DISCOVERABLE_STATE_BLE
    } btm_discoverable_state_t;

/** BR/EDR ACL connection status */
typedef enum
    {
    CONNECTION_STATUS_DISCONNECTED,
    CONNECTION_STATUS_CONNECTED
    } btm_acl_connection_status_t;

/* BT module WICED_BT_TRANSPORT_TYPE tra */
typedef enum
    {
    BT_TRANSPORT_BR_EDR = 1,
    BT_TRANSPORT_LE = 2
    } wiced_bt_transport_t;

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
static uint8_t bt_sw_version[BT_SW_VERSION_LEN];                /* BT SW Major version and Minor version  */
static uint8_t connect_request_bd_addrress_rev[BT_DEVICE_NAME_LEN]; /* connect command device address */
static uint8_t autoconnect_pair_device_index = 0;               /* Record current auto connect paired device index */

static bt_connection_info_update_cb bt_conn_info_cb_array[BT_INFO_CB_MAX_NUM]; /* bt connection info callback array */
static uint32_t                     ble_pairing_fail_count;
static btm_btc_connection_status_t  btm_btc_connection_status;
static TimerHandle_t                timeout_timer_handle;
static btm_timeout_type_t           btm_timeout_type;
static uint16_t                     btm_timeout_count;
static btm_pairing_state_t          btm_pairing_state = BTM_PAIRING_STATE_NON; /* BTC and BLE pairing event state  */
static btm_discoverable_state_t     btm_discoverable_state = BTM_DISCOVERABLE_STATE_NON; /* BTC and BLE pairing event state  */
static uint8_t                      connect_device_unpair_idx = 0; /* Used for the Authentication error return, the connect device is now unpaired */
static TimerHandle_t                autoconnect_timer_handle;

reset_status_type reset_status;

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

static int BTM_unpair_all_dev
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
* stop_btm_timeout_timer
*
* Stop delay timer to delay sending time information.
*
*********************************************************************/
void stop_btm_timeout_timer
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
BaseType_t result = xTimerStop( timeout_timer_handle, 0 );
btm_timeout_count = 0;
btm_timeout_type = BTM_TIMEOUT_IDLE;
configASSERT( result == pdPASS );
}

/*********************************************************************
*
* @private
* start_btm_timeout_timer
*
* Start delay timer to delay sending time information.
*
*********************************************************************/
void start_btm_timeout_timer
    (
    btm_timeout_type_t  input_btm_timeout_type
    )
{
PRINTF( "%s timeout type %d\r\n", __FUNCTION__, input_btm_timeout_type );
btm_timeout_type = input_btm_timeout_type;
BaseType_t result = xTimerStart( timeout_timer_handle, 0 );
configASSERT( result == pdPASS );
}

/*********************************************************************
*
* @private
* btm_timeout_timer_callback
*
* A timer callback function of timeout timer.
*
* @param timer_handle The handle of timeout timer.
*
*********************************************************************/
static void btm_timeout_timer_callback
    (
    TimerHandle_t timer_handle
    )
{
switch( btm_timeout_type )
    {
    /* BTC initial connection timeout event  */
    case BTM_CONNECT_TIMEOUT:
        if( btm_timeout_count > BTM_TIMER_FIVE_SECONDS )
            {
            stop_btm_timeout_timer();
            btm_discoverable_state = BTM_DISCOVERABLE_STATE_NON;
            BTM_notify_EW_connection_status( BT_CONNECTION_FAIL );
            }
        break;

    /* BLE advertising not receive any user confirmation and timeout, send notify to EW  */
    case BTM_BLE_ADV_TIMEOUT:
        if( btm_timeout_count > BTM_TIMER_SIXTY_SECONDS )
            {
            stop_btm_timeout_timer();
            btm_pairing_state = BTM_PAIRING_STATE_NON;
            BTM_set_ble_advertisement( false );
            ble_pairing_fail_count += 1;
            PRINTF( "BTM_BLE_ADV_TIMEOUT Fail Count:%d\r\n", ble_pairing_fail_count );
            EW_notify_ble_pairing_state_changed( EnumBlePairingStateTIMEOUT, 0 );
            }
        break;

    /* BLE pairing Phone User Confirmation timeout, send notify to EW */
    case BTM_BLE_PHONE_USER_CONFIRM_TIMEOUT:
        if( btm_timeout_count > BTM_TIMER_THIRTY_SECONDS )
            {
            stop_btm_timeout_timer();
            ble_pairing_fail_count += 1;
            EW_notify_ble_pairing_state_changed( EnumBlePairingStateTIMEOUT, 0 );
            PRINTF( "BTM_BLE_PHONE_USER_CONFIRM_TIMEOUT Fail Count:%d\r\n", ble_pairing_fail_count );
            }
        break;

    default:
        break;
    }
btm_timeout_count ++;
}

/*********************************************************************
*
* @private
* create_btm_timeout_timer
*
* Create the timeout timer.
*
*********************************************************************/
static void create_btm_timeout_timer
    (
    void
    )
{
timeout_timer_handle = xTimerCreate( "btm_timeout_timer", BTM_TICK_PERIOD_MS, pdTRUE, ( void * ) 0, btm_timeout_timer_callback );
configASSERT( NULL != timeout_timer_handle );
}

/*********************************************************************
*
* @public
* stop_autoconnect_timer
*
* Stop autoconnect timer
*
*********************************************************************/
void stop_autoconnect_timer
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
BaseType_t result = xTimerStop( autoconnect_timer_handle, 0 );
autoconnect_pair_device_index = 0;
configASSERT( result == pdPASS );
}

/*********************************************************************
*
* @private
* start_autoconnect_timer
*
* Start sequentially auto connect to the pair devices
*
*********************************************************************/
void start_autoconnect_timer
    (
    void
    )
{
PRINTF( "%s and first autoconnect\r\n", __FUNCTION__ );

autoconnect_pair_device_index = 0;
BTM_connect_paired_device( autoconnect_pair_device_index );
autoconnect_pair_device_index += 1;

BaseType_t result = xTimerStart( autoconnect_timer_handle, 0 );
configASSERT( result == pdPASS );
}

/*********************************************************************
*
* @private
* autoconnect_timer_callback
*
* A timer callback function of autoconnect timeout
*
* @param timer_handle The handle of autoconnect timer.
*
*********************************************************************/
static void autoconnect_timer_callback
    (
    TimerHandle_t timer_handle
    )
{
// If there is no paired device or the BTC is already connected
if( ( 0 == paired_device_num ) || ( true == btm_btc_connection_status.BTC_is_connected ) )
    {
    stop_autoconnect_timer();
    return;
    }

/* autoconnect_pair_device_index start from 1 */
/* When the paired device num is 1 and already did first autoconnect */
if( autoconnect_pair_device_index == paired_device_num )
    {
    autoconnect_pair_device_index = 0;
    BTM_connect_paired_device( autoconnect_pair_device_index );
    }
/* When the autoconnect device is the last one, connect to the device and reset autoconnect device index */
else if( autoconnect_pair_device_index == ( paired_device_num - 1 ) )
    {
    BTM_connect_paired_device( autoconnect_pair_device_index );
    autoconnect_pair_device_index = 0;
    }
else if( autoconnect_pair_device_index < ( paired_device_num - 1 ) )
    {
    BTM_connect_paired_device( autoconnect_pair_device_index );
    autoconnect_pair_device_index += 1;
    }
else
    {
    PRINTF( "ERROR: autoconnect_pair_device_index:%d paired_device_num:%d\r\n", autoconnect_pair_device_index, paired_device_num );
    return;
    }
}

/*********************************************************************
*
* @private
* create_autoconnect_timer
*
* Create the autoconnect timer.
*
*********************************************************************/
static void create_autoconnect_timer
    (
    void
    )
{
autoconnect_timer_handle = xTimerCreate( "btm_autoconnect_timer", pdMS_TO_TICKS( AUTOCONNECT_TIMEOUT_MS ), pdTRUE, ( void * ) 0, autoconnect_timer_callback );
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
is_bt_enable = true;
EEPM_set_BT_en( true, NULL );
BTM_init_autoconnect();
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
if( is_bt_enable != false )
    {
    is_bt_enable = false;
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
btm_discoverable_state = BTM_DISCOVERABLE_STATE_BTC;
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
data[1] = BT_CONNECTABLE;

is_bt_discoverable = false;
btm_discoverable_state = BTM_DISCOVERABLE_STATE_NON;
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
BTM_init_autoconnect();
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
stop_autoconnect_timer();
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
    const uint8_t paired_device_index
    )
{
PRINTF( "%s: %d Addr:", __FUNCTION__, paired_device_index );

uint8_t bd_addr_rev[BT_DEVICE_ADDRESS_LEN];
for( uint8_t i = 0; i < BT_DEVICE_ADDRESS_LEN; i++ )
    {
    bd_addr_rev[i] = paired_device_list[paired_device_index].device_address[BT_DEVICE_ADDRESS_LEN - 1 - i];
    PRINTF( " %02x", bd_addr_rev[i] );
    }
PRINTF( "\r\n" );

connect_device_unpair_idx = paired_device_index;
memcpy( connect_request_bd_addrress_rev, bd_addr_rev, BT_DEVICE_ADDRESS_LEN );
HCI_wiced_send_command( HCI_CONTROL_SPP_COMMAND_CONNECT, bd_addr_rev, BT_DEVICE_ADDRESS_LEN );

start_btm_timeout_timer( BTM_CONNECT_TIMEOUT );
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
    const uint8_t paired_device_index
    )
{
uint8_t connection_handle_bytes[2];

connection_handle_bytes[0] = 0xff & (uint8_t)(paired_device_list[paired_device_index].connection_handle);
connection_handle_bytes[1] = (uint8_t)( paired_device_list[paired_device_index].connection_handle >> 8 );
PRINTF( "%s: index:%d connect handle:%d connect type:%d\r\n", __FUNCTION__, paired_device_index, paired_device_list[paired_device_index].connection_handle, paired_device_list[paired_device_index].connection_path_type );

// disconnect device through HCI command
if( BT_CONN_TYPE_BT_IAP2 == paired_device_list[paired_device_index].connection_path_type )
    {
    /* Since we don't receive iAP2 disconnect callback after iAP2 disconnect command
     * Here we assume the disconnect always success
     */
    paired_device_list[paired_device_index].is_connected = false;
    paired_device_list[paired_device_index].connection_handle = 0;
    HCI_wiced_send_command( HCI_CONTROL_IAP2_COMMAND_DISCONNECT, connection_handle_bytes, sizeof( uint16_t ) );
    }
else if( BT_CONN_TYPE_BT_SPP == paired_device_list[paired_device_index].connection_path_type )
    {
    HCI_wiced_send_command( HCI_CONTROL_SPP_COMMAND_DISCONNECT, connection_handle_bytes, sizeof( uint16_t ) );
    }
else if( BT_CONN_TYPE_BT_OTHERS == paired_device_list[paired_device_index].connection_path_type )
    {
    HCI_wiced_send_command( HCI_CONTROL_SPP_COMMAND_DISCONNECT, connection_handle_bytes, sizeof( uint16_t ) );
    HCI_wiced_send_command( HCI_CONTROL_IAP2_COMMAND_DISCONNECT, connection_handle_bytes, sizeof( uint16_t ) );
    PRINTF( "ERROR: BT connection path type not exist\r\n" );
    }
}

/*********************************************************************
*
* @private
* unpair_device
*
* Unpair the specified index device, if the paired index is not the last,
* need to request BT module for pair device list update
*
* @param pair_dev_index The specified unpaired device index
*
*********************************************************************/
static void unpair_device
    (
    const uint8_t pair_dev_index
    )
{
uint8_t pair_dev_ind_arry[1] = {0};

pair_dev_ind_arry[0] = pair_dev_index;

// Check the unpaired device is the last one or not
if( pair_dev_index == ( paired_device_num - 1 ) )
    {
    HCI_wiced_send_command( HCI_CONTROL_COMMAND_UNBOND, pair_dev_ind_arry, sizeof( uint8_t ) );
    memset( &(paired_device_list[pair_dev_index]), 0, sizeof( bt_device_info ) );
    paired_device_num --;
    EW_notify_bt_paired_device_status_changed();
    }
else
    {
    // Reset pair device number until BT module update pair device list
    paired_device_num = 0;
    for( uint8_t i = 0; i < BT_MAX_PAIRED_DEVICE_NUM; i++ )
        {
        memset( &(paired_device_list[i]), 0, sizeof( bt_device_info ) );
        }
    // Unpair device through HCI command
    HCI_wiced_send_command( HCI_CONTROL_COMMAND_UNBOND, pair_dev_ind_arry, sizeof( uint8_t ) );
    }
}

/*********************************************************************
*
* @private
* unpair_all_device
*
* Unpair all paired devices, set MCU paired device list empty,
* BT module handle the delete linkkey operation
*
*********************************************************************/
static void unpair_all_device
    (
    void
    )
{
/* Clear MCU paired device list */
paired_device_num = 0;
for( uint8_t i = 0; i < BT_MAX_PAIRED_DEVICE_NUM; i++ )
    {
    memset( &(paired_device_list[i]), 0, sizeof( bt_device_info ) );
    }

/* BT module handle the delete linkkey operation */
HCI_wiced_send_command( HCI_CONTROL_MISC_COMMAND_UNPAIR_ALL_DEV, NULL, 0 );
}

/*********************************************************************
*
* @private
* set_ble_adv
*
* Start BLE advertising, refer to command HCI_CONTROL_LE_COMMAND_ADVERTISE
*
*********************************************************************/
static void set_ble_adv
    (
    bool enable_ble_adv
    )
{
uint8_t ble_adv_param[1];
ble_adv_param[0] = enable_ble_adv;
BaseType_t  send_cmd_result;

if( true == enable_ble_adv )
    {
    /* Request BT module start ble advertising */
    btm_discoverable_state = BTM_DISCOVERABLE_STATE_BLE;
    send_cmd_result = HCI_wiced_send_command( HCI_CONTROL_LE_COMMAND_ADVERTISE, ble_adv_param, sizeof( uint8_t ) );
    start_btm_timeout_timer( BTM_BLE_ADV_TIMEOUT );
    }
else
    {
    /* Request BT module stop ble advertising */
    stop_btm_timeout_timer();
    btm_discoverable_state = BTM_DISCOVERABLE_STATE_NON;
    send_cmd_result = HCI_wiced_send_command( HCI_CONTROL_LE_COMMAND_ADVERTISE, ble_adv_param, sizeof( uint8_t ) );
    }

PRINTF( "%s:%d send result:%d\r\n", __FUNCTION__, enable_ble_adv, send_cmd_result );
}

/*********************************************************************
*
* @private
* send_user_confirm_passkey_result
*
* Send user confirm passkey result to BT module,
* refer to command HCI_CONTROL_MISC_EVENT_USER_CONFIRM_REQUEST
*
*********************************************************************/
static void send_user_confirm_passkey_result
    (
    bool user_confirm_result
    )
{
uint8_t user_confirm_result_arry[1];
user_confirm_result_arry[0] = user_confirm_result;
BaseType_t  send_cmd_result;

if( true == user_confirm_result )
    {
    /* Send user confirm success to BT module */
    send_cmd_result = HCI_wiced_send_command( HCI_CONTROL_MISC_COMMAND_USER_CONFIRM_RESULT, user_confirm_result_arry, sizeof( uint8_t ) );
    }
else
    {
    /* Send user confirm fail to BT module */
    send_cmd_result = HCI_wiced_send_command( HCI_CONTROL_MISC_COMMAND_USER_CONFIRM_RESULT, user_confirm_result_arry, sizeof( uint8_t ) );
    }

PRINTF( "%s:%d send result:%d\r\n", __FUNCTION__, user_confirm_result, send_cmd_result );
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
    is_bt_enable = ( true == *( int* )data) ? true : false;
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
stop_btm_timeout_timer();
EW_notify_bt_connection_result( bt_connection_type );
}

/*********************************************************************
*
* @public
* BTM_BTC_spp_connected
*
* Update BT manager connection information, including connection status,
* remote device address, connection handle, and connection type for connected
* event, also update pair device information
*
* @param connection_is_up  BTC connection status
* @param connection_info_length  Indicate the connection information length
* @param connection_info   BTC connection handle 2 bytes or address/handle 8 bytes
* @param connection_path   bt spp or bt iap2 if connected
*********************************************************************/
void BTM_BTC_spp_connected
    (
    const bool                    connection_is_up,
    const uint32_t                connection_info_length,
    const uint8_t*                connection_info,
    const bt_connection_path_type connection_path
    )
{
PRINTF( "%s:", __FUNCTION__ );
for( uint32_t i = 0; i < connection_info_length; i++ )
    {
    PRINTF( " %02x",connection_info[i] );
    }
PRINTF( "\r\n" );

// Received BT connected event
if( ( ( BT_DEVICE_ADDRESS_LEN + CONNECTION_HANDLE_LENGTH ) == connection_info_length ) && ( true == connection_is_up ) )
    {
    uint8_t connect_bd_addr[BT_DEVICE_ADDRESS_LEN] = { 0 };

    // Change for big endian transfer
    stop_autoconnect_timer();

    for( uint8_t i = 0; i < BT_DEVICE_ADDRESS_LEN; i++ )
        {
        connect_bd_addr[i] = connection_info[BT_DEVICE_ADDRESS_LEN - 1 - i];
        }

    for( uint8_t i = 0; i < BT_MAX_PAIRED_DEVICE_NUM; i++ )
        {
        if( 0 == memcmp( connect_bd_addr, paired_device_list[i].device_address, BT_DEVICE_ADDRESS_LEN ) )
             {
             btm_btc_connection_status.BTC_is_connected = true;
             btm_btc_connection_status.current_connection_handle = connection_info[BT_DEVICE_ADDRESS_LEN];
             btm_btc_connection_status.current_connection_handle += (uint16_t)( connection_info[BT_DEVICE_ADDRESS_LEN + 1] << 8 );
             paired_device_list[i].is_connected = connection_is_up;
             paired_device_list[i].connection_handle = connection_info[BT_DEVICE_ADDRESS_LEN];
             paired_device_list[i].connection_handle += (uint16_t)( connection_info[BT_DEVICE_ADDRESS_LEN + 1] << 8 );
             paired_device_list[i].connection_path_type = connection_path;
             EW_notify_bt_paired_device_status_changed();
             break;
             }
        }
    }
// Received SPP disconnected event
else if( false == connection_is_up  )
    {
    // Action on ACL status disconnected,  BTM_receive_connection_status
    }

// fire callbacks defined by users
for( int i = 0; i < BT_INFO_CB_MAX_NUM; i++ )
    {
    if( bt_conn_info_cb_array[i] != NULL )
        {
        PRINTF( "BTM user-defined callback invoked!(%d)\r\n", i );
        ( bt_conn_info_cb_array[i] )( connection_is_up, connection_info, connection_path );
        }
    }

}

/*********************************************************************
*
* @public
* BTM_receive_connection_status
*
* Receive BT module connection status
*
** @param btc_ACL_status
** BTC ACL connect or disconnect status
** @param reason
** Connect or disconnect reason
**
*********************************************************************/
int BTM_receive_connection_status
    (
    const uint8_t *p_data,
    const uint32_t data_length
    )
{
uint8_t              is_connected = p_data[0];
uint8_t              reason = p_data[1];
wiced_bt_transport_t transport = p_data[2];
uint16_t             connection_handle = 0;
uint8_t              bd_address[BT_DEVICE_ADDRESS_LEN] = { 0 };

connection_handle = (uint16_t)p_data[3];
connection_handle += (uint16_t)( p_data[4] << 8 );
memcpy( bd_address, &(p_data[5]), BT_DEVICE_ADDRESS_LEN );


/* For previous connected device, set to disconnect and call UI */
if( ( CONNECTION_STATUS_DISCONNECTED == is_connected ) && ( BT_TRANSPORT_BR_EDR == transport ) )
    {
    for( uint8_t i = 0; i < BT_MAX_PAIRED_DEVICE_NUM; i++ )
        {
        if( 0 == memcmp( paired_device_list[i].device_address, bd_address, BT_DEVICE_ADDRESS_LEN ) )
            {
            /* Set BTC connect status false */
            btm_btc_connection_status.BTC_is_connected = false;
            btm_btc_connection_status.current_connection_handle = 0;
            /* Set paired device connect status false */
            paired_device_list[i].is_connected = false;
            paired_device_list[i].connection_handle = 0;
            EW_notify_bt_paired_device_status_changed();
            if( ( reason == HCI_ERR_CONN_CAUSE_LOCAL_HOST ) || ( reason == HCI_ERR_PEER_USER ) )
                {
                stop_autoconnect_timer();
                }
            else
                {
                BTM_init_autoconnect();
                }
            break;
            }
        }

    }

return ERR_NONE;
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
    bool*     btc_is_connected,
    uint16_t* connection_handle
    )
{
memcpy( btc_is_connected, &( btm_btc_connection_status.BTC_is_connected ), sizeof( bool ) );
memcpy( connection_handle, &( btm_btc_connection_status.current_connection_handle ), sizeof( uint16_t ) );
}

/*********************************************************************
*
* @public
* BTM_add_connection_info_callback
*
* add user-defined callback for listening the bt connection status update
*
* @param bt_connection_info_update_cb user callback pointer
*
*********************************************************************/
bool BTM_add_connection_info_callback
    (
    bt_connection_info_update_cb bt_info_cb
    )
{
int i = 0;

for( i = 0; i < BT_INFO_CB_MAX_NUM; i++ )
    {
    // check if there exists same callback, if yes, return false
    if( bt_conn_info_cb_array[i] == bt_info_cb )
        {
        PRINTF( "This callback already added! skip\r\n" );
        return false;
        }
    // if no, find a free slot to add this callback
    else if( bt_conn_info_cb_array[i] == NULL )
        {
        PRINTF( "This callback added successfuly!\r\n" );
        bt_conn_info_cb_array[i] = bt_info_cb;
        return true;
        }
    }

PRINTF( "not able to add this callback!" );
return false;
}

#if SW_MODULE_DISABLE_FUNCTION
    /*********************************************************************
    *
    * @public
    * BTM_remove_connection_info_callback
    *
    * remove user-defined callback for listening the bt connection status update
    *
    * @param bt_connection_info_update_cb user callback pointer
    *
    *********************************************************************/
    bool BTM_remove_connection_info_callback
        (
        bt_connection_info_update_cb bt_info_cb
        )
    {
    int i = 0;
    for( i = 0;i < BT_INFO_CB_MAX_NUM; i++ )
    {
        if( bt_conn_info_cb_array[i] == bt_info_cb )
        {
            PRINTF( "This callback removed successfully!\r\n" );
            bt_conn_info_cb_array[i] = NULL;
            return true;
        }
    }
    PRINTF( "this callback doesn't exists, skip removing" );
    return false;
    }
#endif

/*********************************************************************
*
* @public
* BTM_pairing_info_update
*
* Update BT manager device address and device name
*
* @param  pair_dev_index Updated paired device index
* @param  pairing_info Updated paired device address and name
*********************************************************************/
void BTM_pairing_info_update
    (
    const uint8_t pair_dev_index,
    const uint8_t *pairing_info
    )
{
if( ( BT_MAX_PAIRED_DEVICE_NUM > pair_dev_index ) & ( paired_device_num <= BT_MAX_PAIRED_DEVICE_NUM ) )
    {
    memcpy( &paired_device_list[pair_dev_index].device_address, &(pairing_info[0]), BT_DEVICE_ADDRESS_LEN );
    memcpy( &paired_device_list[pair_dev_index].device_name, &(pairing_info[BT_DEVICE_ADDRESS_LEN]), BT_DEVICE_NAME_LEN );
    paired_device_num ++;
    EW_notify_bt_paired_device_status_changed();
    }
else
    {
    PRINTF( "%s ERROR: pair device number:%d, Update pair device index:%d", __FUNCTION__, paired_device_num, pair_dev_index );
    }

PRINTF( "%s", __FUNCTION__ );
for( uint8_t i = 0; i < BT_DEVICE_ADDRESS_LEN; i++ )
    {
    PRINTF( " %02x", paired_device_list[pair_dev_index].device_address[i] );
    }
PRINTF( "\r\n" );
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

BTM_unpair_all_dev();

if( pdTRUE != EEPM_set_BT_en( ENABLED, &eeprom_write_BT_enable_callback ) )
    {
    PRINTF( "reset BT en fail\r\n" );
    }
if( pdTRUE != EEPM_set_BT_autoconn( ENABLED, &eeprom_write_BT_autocon_callback ) )
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
message_object msg_obj;
msg_obj.type = MSG_CONNECT_DEVICE;
msg_obj.pair_dev_index = paired_device_idx;
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
msg_obj.pair_dev_index = paired_device_idx;
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
PRINTF( "%s: index:%d\r\n", __FUNCTION__, paired_device_idx );

/* If the unpair device is connected, we need to assume the device will be successfully disconnected */
/* Or the connection information update may not find the correct paired device */
if( true == paired_device_list[paired_device_idx].is_connected )
    {
    btm_btc_connection_status.BTC_is_connected = false;
    btm_btc_connection_status.current_connection_handle = 0;
    }

// We need to disconnect the device before unpair it
BTM_disconnect_paired_device( paired_device_idx );

message_object msg_obj;
msg_obj.type = MSG_UNPAIR_DEVICE;
msg_obj.pair_dev_index = (uint8_t)paired_device_idx;
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
* @public
* BTM_unpair_all_dev
*
* Used for Factory reset to unpair all devices
*
*********************************************************************/
int BTM_unpair_all_dev
    (
    void
    )
{
message_object msg_obj;

msg_obj.type = MSG_UNPAIR_ALL_DEVICE;
send_message( msg_obj );
return ERR_NONE;
}

/*********************************************************************
*
* @public
* BTM_get_connect_request_bd_addrress_rev
*
* Called for when MCU receive SPP connection fail or Service not found,
* and need to try do iAP2 connect
*
** @param return_connect_bd_addr_rev
** Copy the current request connect device bd address value to output parameter
**
*********************************************************************/
int BTM_get_connect_request_bd_addrress_rev
    (
    uint8_t* return_connect_bd_addr_rev
    )
{
PRINTF( "%s", __FUNCTION__ );
for( uint8_t i = 0; i < BT_DEVICE_ADDRESS_LEN; i++ )
    {
    PRINTF( " %02x", connect_request_bd_addrress_rev[i]);
    }
PRINTF( "\r\n" );
memcpy( return_connect_bd_addr_rev, connect_request_bd_addrress_rev, BT_DEVICE_ADDRESS_LEN );
return ERR_NONE;
}


/*********************************************************************
*
* @public
* BTM_start_ble_advertisement
*
* When BTC is connected and user want to connect BLE with Phone,
* Start BLE advertising
**
**@param enable ble advertising
*********************************************************************/
int BTM_set_ble_advertisement
    (
    bool enable_ble_adv
    )
{
message_object msg_obj;

msg_obj.type = MSG_SET_BLE_ADV;
msg_obj.ble_adv_enable = enable_ble_adv;
send_message( msg_obj );
return ERR_NONE;
}

/*********************************************************************
*
* @public
* BTM_get_ble_pairing_fail_count
*
* Return BLE pairing fail count
**
*********************************************************************/
int BTM_get_ble_pairing_fail_count
    (
    void
    )
{
return ble_pairing_fail_count;
}

/*********************************************************************
*
* @public
* BTM_is_bt_connected
*
* Return boolean BTC is connected or not
**
*********************************************************************/
bool BTM_is_bt_connected
    (
    void
    )
{
PRINTF( "BTM_is_bt_connected:%d\r\n", btm_btc_connection_status.BTC_is_connected );
return btm_btc_connection_status.BTC_is_connected;
}

/*********************************************************************
*
* @public
* BTM_receive_user_confirm_evt
*
* MCU receive BT/BLE user confirmation event
**
**@param  p_data   Numeric code and Remote device address
**@param  data_len USER_CONFIRM_RESULT_DATA_LENGTH
*********************************************************************/
void BTM_receive_user_confirm_evt
    (
    const uint8_t* p_data,
    const uint32_t data_len
    )
{
uint32_t numeric_code = 0;
uint8_t  device_name_char[BT_DEVICE_NAME_LEN];
memcpy( &( device_name_char ), &( p_data[USER_CONFIRM_EVT_PIN_CODE_LENGTH] ), BT_DEVICE_NAME_LEN );

if( return_accept_next_pairing() )
    {
    PRINTF( "Accept Next Pairing Confirm and return confirm\r\n" );
    send_user_confirm_passkey_result( true );
    set_accept_next_pairing_false();
    }

/* BTC Pairing user confirmation request event */
if( BTM_DISCOVERABLE_STATE_BTC == btm_discoverable_state )
    {
    btm_pairing_state = BTM_PAIRING_STATE_BTC;
    numeric_code += (uint32_t)p_data[0];
    numeric_code += (uint32_t)( p_data[1] << 8 );
    numeric_code += (uint32_t)( p_data[2] << 16 );
    numeric_code += (uint32_t)( p_data[3] << 24 );
    PRINTF( "%s BTC_USR_CONFIRM numeric_code:%d\r\n", __FUNCTION__, numeric_code );
    EW_notify_bt_passkey_generated( device_name_char, numeric_code );
    }
/* BLE Pairing user confirmation request event */
else if( BTM_DISCOVERABLE_STATE_BLE == btm_discoverable_state )
    {
    stop_btm_timeout_timer();
    btm_pairing_state = BTM_PAIRING_STATE_BLE;
    numeric_code += (uint32_t)p_data[0];
    numeric_code += (uint32_t)( p_data[1] << 8 );
    numeric_code += (uint32_t)( p_data[2] << 16 );
    numeric_code += (uint32_t)( p_data[3] << 24 );
    PRINTF( "%s BLE_USR_CONFIRM numeric_code:%d\r\n", __FUNCTION__, numeric_code );
    EW_notify_ble_pairing_state_changed( EnumBlePairingStatePINCODE_GENERATED, numeric_code );
    start_btm_timeout_timer( BTM_BLE_PHONE_USER_CONFIRM_TIMEOUT );
    }
else
    {
    PRINTF( "ERROR: Receive User Confirm event when not on BT/BLE discoverable state\r\n" );
    }
}

/*********************************************************************
*
* @public
* BTM_receive_pairing_clt_evt
*
* Event refer to Cypress HCI protocol HCI_CONTROL_EVENT_PAIRING_COMPLETE
* After user press phone confirmation or confirmation, MCU will receive
* BT/BLE pairing complete event
**
**@param  p_data   ERROR code and remote device address
**@param  data_len 1 + BT_DEVICE_ADDRESS_LEN
*********************************************************************/
void BTM_receive_pairing_clt_evt
    (
    const uint8_t* p_data,
    const uint32_t data_len
    )
{
if( BTM_PAIRING_STATE_BTC == btm_pairing_state )
    {
    btm_pairing_state = BTM_PAIRING_STATE_NON;
    if( BTM_BTC_BLE_PAIRING_SUCCESS == p_data[0] )
        {
        PRINTF( "Receive BTC Pairing success\r\n" );
        EW_notify_btc_pairing_state_changed( EnumBtcPairingStateSUCCESSFUL );
        }
    else
        {
        PRINTF( "Receive BTC Pairing Fail Error code:%d remote address:", p_data[0] );
        for( uint8_t i = 0; i < BT_DEVICE_ADDRESS_LEN; i++ )
            {
            PRINTF( "%02x", p_data[1 + i] );
            }
        PRINTF( "\r\n" );
        EW_notify_btc_pairing_state_changed( EnumBtcPairingStateFAIL );
        }
    }
else if( BTM_PAIRING_STATE_BLE == btm_pairing_state )
    {
    btm_pairing_state = BTM_PAIRING_STATE_NON;
    if( BTM_BTC_BLE_PAIRING_SUCCESS == p_data[0] )
        {
        stop_btm_timeout_timer();
        ble_pairing_fail_count = 0;
        EW_notify_ble_pairing_state_changed( EnumBlePairingStateSUCCESSFUL, 0 );
        }
    else
        {
        stop_btm_timeout_timer();
        ble_pairing_fail_count += 1;
        PRINTF( "Receive BLE Pairing Fail Error code:%d Fail count:%d remote address:", p_data[0], ble_pairing_fail_count );
        for( uint8_t i = 0; i < BT_DEVICE_ADDRESS_LEN; i++ )
            {
            PRINTF( "%02x", p_data[1 + i] );
            }
        PRINTF( "\r\n" );
        EW_notify_ble_pairing_state_changed( EnumBlePairingStateFAIL, 0 );
        }
    }
}

/*********************************************************************
*
* @public
* BTM_get_ble_connected_device_name
*
* For EW get BLE connected device name, the BLE remote device should be
* the same with the BTC connected device
*
* @param p_data Return device name pointer value
* @return True if there is a BLE connected device.
*
*********************************************************************/
bool BTM_get_ble_connected_device_name
    (
    uint8_t** p_data
    )
{
// TODO memcpy BLE connected name to the pointer
return false;
}

/*********************************************************************
*
* @public
* BTM_btc_confirm_passkey
*
* From UI to confirm the passkey match the phone display pin code and
* user press yes or no button result in UI will call
* BTM_btc_confirm_passkey( true ) or BTM_btc_confirm_passkey( false )
*
** @param match_result
** user press result yes or no
**
*********************************************************************/
int BTM_btc_confirm_passkey
    (
    bool match_result
    )
{
message_object msg_obj;

msg_obj.type = MSG_USER_CONFIRM_PASSKEY;
msg_obj.user_confirm_result = match_result;
send_message( msg_obj );
return ERR_NONE;
}

/*********************************************************************
*
* @public
* BTM_is_ble_paired_device
*
* From UI to confirm the passkey match the phone display pin code and
* user press yes or no button result in UI will call
* BTM_btc_confirm_passkey( true ) or BTM_btc_confirm_passkey( false )
*
** @param match_result
** user press result yes or no
**
*********************************************************************/
bool BTM_is_ble_paired_device
    (
    const int paired_device_index
    )
{
// TODO need to judge the paired_device BLE is paired or not
return false;
}

/*********************************************************************
*
* @public
* BTM_receive_btc_paired_fail
*
* After MCU send SPP or iAP2 connect, receive this event if BT module
* check the BD address is not on paired device list
*
**@param p_data    SPP/iAP2 connect BD address ( no paired )
**@param data_len  Should be BT_DEVICE_ADDRESS_LEN
*********************************************************************/
void BTM_receive_btc_paired_fail
    (
    const uint8_t* p_data,
    const uint32_t data_len
    )
{
PRINTF( "ERROR %s:", __FUNCTION__ );
for( int i = 0; i < data_len; i++ )
    {
    PRINTF( " %02x", p_data[i] );
    }
PRINTF( "\n\r" );

BTM_unpair_paired_device( connect_device_unpair_idx );
BTM_notify_EW_connection_status( BT_CONNECTION_AUTHENTICATION_ERR );
}

/*********************************************************************
*
* @public
* BTM_start_autoconnect
*
* Called for when BT is ready and autoconnect button is on
*
*********************************************************************/
int BTM_init_autoconnect
    (
    void
    )
{
if( ( true == is_bt_autoconnectable ) && ( false == btm_btc_connection_status.BTC_is_connected ) && ( true == is_bt_enable ) )
    {
    start_autoconnect_timer();
    }
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
            connect_device( msg_obj.pair_dev_index );
            break;
        case MSG_DISCONNECT_DEVICE:
            disconnect_device( msg_obj.pair_dev_index );
            break;
        case MSG_UNPAIR_DEVICE:
            unpair_device( msg_obj.pair_dev_index );
            break;
        case MSG_UNPAIR_ALL_DEVICE:
            unpair_all_device();
            break;
        case MSG_SET_BLE_ADV:
            set_ble_adv( msg_obj.ble_adv_enable );
            break;
        case MSG_USER_CONFIRM_PASSKEY:
            send_user_confirm_passkey_result( msg_obj.user_confirm_result );
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

// Initialize static parameters
for( uint8_t i = 0; i < BT_MAX_PAIRED_DEVICE_NUM; i++ )
    {
    memset( &(paired_device_list[i]), 0, sizeof( bt_device_info ) );
    }
memset( connect_request_bd_addrress_rev, 0, BT_DEVICE_NAME_LEN );
memset( bt_sw_version, 0, BT_SW_VERSION_LEN );
memset( local_device_name, 0, BT_DEVICE_NAME_LEN );
btm_btc_connection_status.BTC_is_connected = false;
btm_btc_connection_status.current_connection_handle = 0;

ble_pairing_fail_count = 0;
create_btm_timeout_timer();

autoconnect_pair_device_index = 0;
create_autoconnect_timer();

create_task();
}

