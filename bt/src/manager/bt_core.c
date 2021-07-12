/*********************************************************************
* @file  bt_core.c
* @brief Bluetooth Manager General Core interface definition.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <FreeRTOS.h>
#include <semphr.h>
#include <task.h>
#include <string.h>

#include "bt_core.h"
#include "bt_db.h"
#include "bt_device.h"
#include "bt_hw.h"
#include "bt_log.h"
#include "bt_spp_core.h"
#include "bt_tsk.h"
#include "bt_update.h"
#include "bt_utils.h"
#include "ble_client_core.h"
#include "ble_server_core.h"
#include "hci_cmd.h"

/*--------------------------------------------------------------------
                        Definitions
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define MUTEX_LOCK_MS            ( 5000 )
#define DEVICE_STARTED_MS        ( 3000 )
#define PAIRED_DEVICE_DELETED_MS ( 3000 )

/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/
typedef struct BT_power_setting
    {
    BT_power_status_e power_status;
    SemaphoreHandle_t mutex;
    } BT_power_setting_t;

typedef struct BT_pairing_request
    {
    BT_pairing_status_e pairing_status;
    uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN];
    SemaphoreHandle_t mutex;
    } BT_pairing_request_t;

typedef struct BT_core
    {
    bool initialized;
    bool discoverable_state;
    bool test_mode;
    BT_power_setting_t power_setting;
    BT_pairing_request_t pairing_request;
    } BT_core_t;

/*--------------------------------------------------------------------
                        PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        MEMORY CONSTANTS
--------------------------------------------------------------------*/
static const uint8_t s_tx_ch_freqs[] =
    {
    /* BT_TX_CH_LOW: 2402 MHz  */ 0x02,
    /* BT_TX_CH_MID: 2441 MHz  */ 0x29,
    /* BT_TX_CH_HIGH: 2480 MHz */ 0x50
    };

/*--------------------------------------------------------------------
                        VARIABLES
--------------------------------------------------------------------*/
static BT_core_t s_core = { 0 };

/*--------------------------------------------------------------------
                        PROTOTYPES
--------------------------------------------------------------------*/
static bool BT_core_disconnect_all
    (
    const uint8_t* bd_addr
    );

static bool BT_core_get_pairing_device_address
    (
    uint8_t* bd_addr
    );

static void BT_core_reset( void );

static void BT_core_reset_all( void );

static bool BT_core_set_pairing_status
    (
    const BT_pairing_status_e pairing_status,
    const uint8_t* bd_addr
    );

static bool BT_core_set_power_status
    (
    const BT_power_status_e power_status
    );

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
/*================================================================================================
@brief   Accept or reject current pairing request
@details Send the HCI command of accepting or rejecting current pairing request to Cypress module
@return  None
@retval  Whether or not the HCI command is sent to Cypress module successfully
================================================================================================*/
bool BT_core_accept_pairing
    (
    const bool accept
    )
{
bool ret = false;
uint8_t param[BT_DEVICE_ADDRESS_LEN + 1] = { 0 };
BT_pairing_status_e pairing_status = BT_core_get_pairing_status();

if( BT_PAIRING_USER_CONFIRMING != pairing_status )
    {
    BT_LOG_DEBUG( "Not allowed in pairing status: %s", BT_util_get_pairing_status_string( pairing_status ) );
    }
else
    {
    BT_core_get_pairing_device_address( param );
    param[6] = (uint8_t)accept;

    ret = HCI_send_wiced_command( HCI_CONTROL_COMMAND_USER_CONFIRMATION, param, sizeof( param ) );
    if( ret )
        {
        BT_core_set_pairing_status( BT_PAIRING_CONFIRMED_WAITING, NULL );
        }
    }
return ret;
}

/*================================================================================================
@brief   Delete the paired device
@details Send the HCI command of deleting the paired device to Cypress module
@return  None
@retval  Whether or not the HCI command is sent to Cypress module successfully
================================================================================================*/
bool BT_core_delete_paired_device
    (
    const uint8_t* bd_addr
    )
{
bool ret = false;
uint8_t param[BT_DEVICE_ADDRESS_LEN] = { 0 };
BT_sync_event_t sync_event = { BT_SYNC_EVENT_PAIRED_DEVICE_DELETED, { { 0 } } };

if( ( NULL == bd_addr ) || ( strlen( (const char*)bd_addr ) != BT_DEVICE_ADDRESS_LEN ) )
    {
    BT_LOG_DEBUG( "Invalid BD address" );
    }
else if( false == BT_device_is_existed( bd_addr ) )
    {
    BT_LOG_DEBUG( "Not paired device: %02x:%02x:%02x:%02x:%02x:%02x", BD_ADDR_PRINT( bd_addr ) );
    }
else
    {
    BT_core_disconnect_all( bd_addr );

    memcpy( param, bd_addr, BT_DEVICE_ADDRESS_LEN );
    ret = HCI_send_wiced_command( HCI_CONTROL_COMMAND_UNBOND, param, sizeof( param ) );
    if( ret )
        {
        ret = false;

        if( false == BT_tsk_sync_wait( &sync_event, PAIRED_DEVICE_DELETED_MS ) )
            {
            BT_LOG_ERROR( "Timeout on waiting paired device deleted event" );
            }
        else
            {
            ret = ( 0 == memcmp( bd_addr,
                                 sync_event.param_u.paired_device_deleted.bd_addr,
                                 BT_DEVICE_ADDRESS_LEN ) );
            }
        }
    }
return ret;
}

/*================================================================================================
@brief   Disconnect all the BR/EDR and LE connections from the remote device
@details Disconnect all the BR/EDR and LE connections from the remote device
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
static bool BT_core_disconnect_all
    (
    const uint8_t* bd_addr
    )
{
bool ret = false;
uint8_t cur_bd_addr[BT_DEVICE_ADDRESS_LEN] = { 0 };

if( ( NULL == bd_addr ) || ( strlen( (const char*)bd_addr ) != BT_DEVICE_ADDRESS_LEN ) )
    {
    BT_LOG_DEBUG( "Invalid BD address" );
    }
else
    {
    ret = true;

    for( BT_spp_app_type_e app_type = 0; app_type < BT_SPP_APP_TYPE_CNT; ++app_type )
        {
        if( ( BT_CONNECTION_CONNECTED == BT_core_spp_get_connection_status( app_type, cur_bd_addr ) &&
            ( 0 == memcmp( cur_bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN ) ) ) )
            {
            ret &= BT_core_spp_disconnect( bd_addr, app_type );
            }
        }

    // We expect that BLE will be disconnected by APP if the SPP connection is no longer existed
    }
return ret;
}

/*================================================================================================
@brief   Reset to factory default
@details Delete all the paired devices and set the Bluetooth enable state TRUE
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
bool BT_core_factory_reset( void )
{
bool ret = true;
uint8_t num_paired_devices = BT_core_get_num_paired_devices();

for( uint8_t i = 0; i < num_paired_devices; ++i )
    {
    const BT_device_info_t* device_info = BT_core_get_paired_device_info( 0 );
    if( NULL == device_info )
        {
        BT_LOG_WARNING( "NULL paired device" );
        ret = false;
        }
    else
        {
        ret &= BT_core_delete_paired_device( device_info->bd_addr );
        }
    }

ret &= BT_core_set_enable_state( true, true );
return ret;
}

/*================================================================================================
@brief   Get whether or not the discoverable mode is enabled
@details Get whether or not the discoverable mode is enabled
@return  None
@retval  Whether or not the discoverable mode is enabled
================================================================================================*/
bool BT_core_get_discoverable_state( void )
{
return s_core.discoverable_state;
}

/*================================================================================================
@brief   Get local Bluetooth device address
@details Get local Bluetooth device address
@return  None
@retval  Local Bluetooth device address
================================================================================================*/
const uint8_t* BT_core_get_local_device_address( void )
{
return BT_db_get_local_device_address();
}

/*================================================================================================
@brief   Get local Bluetooth device name
@details Get local Bluetooth device name
@return  None
@retval  Local Bluetooth device name
================================================================================================*/
const uint8_t* BT_core_get_local_device_name( void )
{
return BT_db_get_local_device_name();
}

/*================================================================================================
@brief   Get the number of paired devices
@details Get the number of paired devices
@return  None
@retval  The number of paired devices
================================================================================================*/
uint8_t BT_core_get_num_paired_devices( void )
{
return BT_device_get_total_num();
}

/*================================================================================================
@brief   Get info of the paired device
@details Get info of the paired device
@return  None
@retval  Info of the paired device
================================================================================================*/
const BT_device_info_t* BT_core_get_paired_device_info
    (
    const uint8_t device_idx
    )
{
return BT_device_get_info( device_idx );
}

/*================================================================================================
@brief   Get current pairing device address
@details Get current pairing device address
@return  bd_addr: current pairing device address
@retval  Whether or not there is a pairing device existed
================================================================================================*/
static bool BT_core_get_pairing_device_address
    (
    uint8_t* bd_addr
    )
{
bool pairing = false;

if( NULL == bd_addr )
    {
    BT_LOG_DEBUG( "NULL BD address" );
    }
else
    {
    if( false == xSemaphoreTake( s_core.pairing_request.mutex, pdMS_TO_TICKS( MUTEX_LOCK_MS ) ) )
        {
        BT_LOG_ERROR( "Mutex lock timeout" );
        }
    else
        {
        if( BT_PAIRING_NONE != s_core.pairing_request.pairing_status )
            {
            pairing = true;
            memcpy( bd_addr, s_core.pairing_request.bd_addr, BT_DEVICE_ADDRESS_LEN );
            }
        xSemaphoreGive( s_core.pairing_request.mutex );
        }
    }
return pairing;
}

/*================================================================================================
@brief   Get current pairing status
@details Get current pairing status
@return  None
@retval  Current pairing status
================================================================================================*/
BT_pairing_status_e BT_core_get_pairing_status( void )
{
BT_pairing_status_e pairing_status = BT_PAIRING_NONE;

if( false == xSemaphoreTake( s_core.pairing_request.mutex, pdMS_TO_TICKS( MUTEX_LOCK_MS ) ) )
    {
    BT_LOG_ERROR( "Mutex lock timeout" );
    }
else
    {
    pairing_status = s_core.pairing_request.pairing_status;
    xSemaphoreGive( s_core.pairing_request.mutex );
    }
return pairing_status;
}

/*================================================================================================
@brief   Get current power status
@details Get current power status
@return  None
@retval  Current power status
================================================================================================*/
BT_power_status_e BT_core_get_power_status( void )
{
BT_power_status_e power_status = BT_POWER_OFF;

if( false == xSemaphoreTake( s_core.power_setting.mutex, pdMS_TO_TICKS( MUTEX_LOCK_MS ) ) )
    {
    BT_LOG_ERROR( "Mutex lock timeout" );
    }
else
    {
    power_status = s_core.power_setting.power_status;
    xSemaphoreGive( s_core.power_setting.mutex );
    }
return power_status;
}

/*================================================================================================
@brief   Get Bluetooth Manager's software version
@details Get Bluetooth Manager's software version
@return  major_version: The major version
         minor_version: The minor version
@retval  Whether or not the operation is successful
================================================================================================*/
bool BT_core_get_sw_version
    (
    uint8_t* major_version,
    uint8_t* minor_version
    )
{
bool ret = false;

if( ( NULL == major_version ) || ( NULL == minor_version ) )
    {
    BT_LOG_DEBUG( "NULL version" );
    }
else
    {
    ret = BT_update_get_sw_version( major_version, minor_version );
    }
return ret;
}

/*================================================================================================
@brief   Get whether or not Cypress module's test mode is enabled
@details Get whether or not Cypress module's test mode is enabled
@return  None
@retval  Whether or not Cypress module's test mode is enabled
================================================================================================*/
bool BT_core_get_test_mode( void )
{
return s_core.test_mode;
}

/*================================================================================================
@brief   Check whether or not this is a paired device
@details Check whether or not this is a paired device
@return  None
@retval  Whether or not this is a paired device
================================================================================================*/
bool BT_core_is_paired_device
    (
    const uint8_t* bd_addr
    )
{
return BT_device_is_existed( bd_addr );
}

/*================================================================================================
@brief   Bluetooth Manager General Core initialization
@details Bluetooth Manager General Core initialization
@return  None
@retval  None
================================================================================================*/
void BT_core_init( void )
{
if( false == s_core.initialized )
    {
    s_core.power_setting.mutex = xSemaphoreCreateMutex();
    configASSERT( NULL != s_core.power_setting.mutex );

    s_core.pairing_request.mutex = xSemaphoreCreateMutex();
    configASSERT( NULL != s_core.pairing_request.mutex );

    BT_core_reset();

    s_core.initialized = true;
    }
}

/*================================================================================================
@brief   Initialize Cypess module
@details Send the HCI commands of initialization including local device address to Cypress module
@return  None
@retval  Whether or not these HCI commands are sent to Cypress module successfully
================================================================================================*/
bool BT_core_init_module( void )
{
bool ret = false;
uint8_t param[BT_DEVICE_ADDRESS_LEN] = { 0 };
const uint8_t* local_bd_addr = BT_core_get_local_device_address();

memcpy( param, local_bd_addr, BT_DEVICE_ADDRESS_LEN );

ret = HCI_send_wiced_command( HCI_CONTROL_COMMAND_SET_LOCAL_BDA, param, sizeof( param ) );
if( ret )
    {
    BT_core_set_power_status( BT_POWER_ON_READY );
    }
return ret;
}

/*================================================================================================
@brief   Check whether or not the paired device has lost its authentication data
@details Check whether or not the paired device has lost its authentication data
@return  None
@retval  Whether or not the paired device has lost its authentication data
================================================================================================*/
bool BT_core_is_paired_device_auth_lost
    (
    const uint8_t* bd_addr
    )
{
return BT_device_is_auth_lost( bd_addr );
}

/*================================================================================================
@brief   Check whether or not the number of paired devices reached the limit
@details Check whether or not the number of paired devices reached the limit
@return  None
@retval  Whether or not the number of paired devices reached the limit
================================================================================================*/
bool BT_core_is_paired_device_max_num_reached( void )
{
return BT_device_is_max_num_reached();
}

/*================================================================================================
@brief   Reset Bluetooth Manager General Core's data
@details Reset Bluetooth Manager General Core's data
@return  None
@retval  None
================================================================================================*/
static void BT_core_reset( void )
{
s_core.discoverable_state = true;
s_core.test_mode = false;

if( BT_PAIRING_NONE != BT_core_get_pairing_status() )
    {
    BT_core_set_pairing_status( BT_PAIRING_NONE, NULL );

    // TODO: Notify HMI the pairing result is failed
    }
}

/*================================================================================================
@brief   Reset Bluetooth Manager ALL Core's data
@details Reset Bluetooth Manager ALL Core's data
@return  None
@retval  None
================================================================================================*/
static void BT_core_reset_all( void )
{
BT_LOG_DEBUG( "Reset all data" );
BT_tsk_clear_requests();
BT_core_reset();
BT_core_spp_reset();
BLE_core_server_reset();
BLE_core_client_reset();
}

/*================================================================================================
@brief   Send the standard HCI command to Cypress module
@details Send the standard HCI command to Cypress module
@return  None
@retval  Whether or not the HCI command is sent to Cypress module successfully
================================================================================================*/
bool BT_core_send_standard_hci_command
    (
    const uint16_t op_code,
    const uint8_t* payload,
    const uint8_t payload_len
    )
{
return HCI_send_standard_command( op_code, payload, payload_len );
}

/*================================================================================================
@brief   Enable or Disable the discoverable mode
@details Send the HCI command of enabling or disabling the discoverable mode to Cypress module
@return  None
@retval  Whether or not the HCI command is sent to Cypress module successfully
================================================================================================*/
bool BT_core_set_discoverable_state
    (
    const bool enable
    )
{
bool ret = false;
uint8_t param[2] = { 0 };

if( enable == s_core.discoverable_state )
    {
    BT_LOG_DEBUG( "Duplicate request: %d", enable );
    }
else
    {
    param[0] = true;   // Connectability
    param[1] = enable; // Discoverability

    ret = HCI_send_wiced_command( HCI_CONTROL_COMMAND_SET_VISIBILITY, param, sizeof( param ) );
    if( ret )
        {
        BT_LOG_DEBUG( "Discoverable state: %d -> %d", s_core.discoverable_state, enable );
        s_core.discoverable_state = enable;
        }
    }
return ret;
}

/*================================================================================================
@brief   Enable or Disable Bluetooth by powering on or off Cypress module
@details Enable or Disable Bluetooth by powering on or off Cypress module
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
bool BT_core_set_enable_state
    (
    const bool enable,
    const bool store
    )
{
bool ret = false;
BT_power_status_e power_status = BT_core_get_power_status();
BT_sync_event_t sync_event = { BT_SYNC_EVENT_DEVICE_STARTED, { { 0 } } };

if( enable && ( BT_POWER_OFF == power_status ) )
    {
    ret = true;
    }
else if( ( false == enable ) && ( ( BT_POWER_ON == power_status ) || ( BT_POWER_ON_READY == power_status ) ) )
    {
    ret = true;
    }
else
    {
    BT_LOG_DEBUG( "Not allowed: power_status=%s, enable=%d", BT_util_get_power_status_string( power_status ), enable );
    }

if( ret )
    {
    if( enable )
        {
        BT_core_set_power_status( BT_POWER_ON );
        if( store )
            {
            BT_db_set_enable_state( true );
            }

        ret = BT_hw_on( BT_HW_MODE_NORMAL );
        if( ret )
            {
            if( false == BT_tsk_sync_wait( &sync_event, DEVICE_STARTED_MS ) )
                {
                BT_LOG_ERROR( "Timeout on waiting device started event" );
                BT_core_set_power_status( BT_POWER_ON_UPDATING );
                BT_core_update_firmware();
                }
            }
        }
    else
        {
        BT_core_set_power_status( BT_POWER_OFF );
        if( store )
            {
            BT_db_set_enable_state( false );
            }

        // Cypress module is going to be powered off, reset all data
        BT_core_reset_all();

        ret = BT_hw_off();
        }
    }
return ret;
}

/*================================================================================================
@brief   Set local Bluetooth device address
@details Set local Bluetooth device address
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
bool BT_core_set_local_device_address
    (
    const uint8_t* bd_addr
    )
{
bool ret = false;
const uint8_t* cur_bd_addr = BT_core_get_local_device_address();

if( ( NULL == bd_addr ) || ( strlen( (const char*)bd_addr ) != BT_DEVICE_ADDRESS_LEN ) )
    {
    BT_LOG_DEBUG( "Invalid BD address" );
    }
else if( 0 == memcmp( cur_bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN ) )
    {
    BT_LOG_DEBUG( "Duplicate request" );
    }
else
    {
    ret = BT_db_set_local_device_address( bd_addr );
    if( ret )
        {
        if( BT_POWER_ON_READY == BT_core_get_power_status() )
            {
            ret &= BT_core_set_enable_state( false, false );
            ret &= BT_core_set_enable_state( true, false );
            }
        }
    }
return ret;
}

/*================================================================================================
@brief   Set Bluetooth Manager's log level
@details Set Bluetooth Manager's log level
@return  None
@retval  None
================================================================================================*/
void BT_core_set_log_level
    (
    const BT_log_severity_e severity
    )
{
if( ( severity < 0 ) || ( severity >= BT_LOG_SEVERITY_INVALID ) )
    {
    BT_LOG_DEBUG( "Invalid severity: %d", severity );
    }
else
    {
    BT_log_set_level( severity );
    }
}

/*================================================================================================
@brief   Just set the pairing status to target value
@details Just set the pairing status to target value
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
static bool BT_core_set_pairing_status
    (
    const BT_pairing_status_e pairing_status,
    const uint8_t* bd_addr
    )
{
bool ret = false;

if( ( pairing_status < 0 ) || ( pairing_status >= BT_PAIRING_STATUS_INVALID ) )
    {
    BT_LOG_DEBUG( "Invalid pairing status: %d", pairing_status );
    }
else
    {
    if( false == xSemaphoreTake( s_core.pairing_request.mutex, pdMS_TO_TICKS( MUTEX_LOCK_MS ) ) )
        {
        BT_LOG_ERROR( "Mutex lock timeout" );
        }
    else
        {
        BT_LOG_INFO( "Pairing status: %s -> %s",
                     BT_util_get_pairing_status_string( s_core.pairing_request.pairing_status ),
                     BT_util_get_pairing_status_string( pairing_status ) );

        s_core.pairing_request.pairing_status = pairing_status;
        if( BT_PAIRING_NONE == pairing_status )
            {
            memset( s_core.pairing_request.bd_addr, 0, BT_DEVICE_ADDRESS_LEN );
            }
        else if( BT_PAIRING_USER_CONFIRMING == pairing_status )
            {
            memcpy( s_core.pairing_request.bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN );
            }

        ret = true;
        xSemaphoreGive( s_core.pairing_request.mutex );
        }
    }
return ret;
}

/*================================================================================================
@brief   Just set the power status to target value
@details Just set the power status to target value
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
static bool BT_core_set_power_status
    (
    const BT_power_status_e power_status
    )
{
bool ret = false;

if( ( power_status < 0 ) || ( power_status >= BT_POWER_STATUS_INVALID ) )
    {
    BT_LOG_DEBUG( "Invalid power status: %d", power_status );
    }
else
    {
    if( false == xSemaphoreTake( s_core.power_setting.mutex, pdMS_TO_TICKS( MUTEX_LOCK_MS ) ) )
        {
        BT_LOG_ERROR( "Mutex lock timeout" );
        }
    else
        {
        BT_LOG_INFO( "Power status: %s -> %s",
                     BT_util_get_power_status_string( s_core.power_setting.power_status ),
                     BT_util_get_power_status_string( power_status ) );

        s_core.power_setting.power_status = power_status;

        ret = true;
        xSemaphoreGive( s_core.power_setting.mutex );
        }
    }
return ret;
}

/*================================================================================================
@brief   Enable or disable Cypress module's test mode
@details Send the HCI command of enabling or disabling test mode to Cypress module
@return  None
@retval  Whether or not the HCI command is sent to Cypress module successfully
================================================================================================*/
bool BT_core_set_test_mode
    (
    const bool enable
    )
{
bool ret = false;

if( enable == s_core.test_mode )
    {
    BT_LOG_DEBUG( "Duplicate request: %d", enable );
    }
else
    {
    if( enable )
        {
        ret = HCI_send_standard_command( HCI_STANDARD_COMMAND_DUT_MODE, NULL, 0 );
        }
    else
        {
        ret = BT_core_set_enable_state( false, false );
        ret &= BT_core_set_enable_state( true, false );
        }

    if( ret )
        {
        BT_LOG_DEBUG( "Test mode: %d -> %d", s_core.test_mode, enable );
        s_core.test_mode = enable;
        }
    }
return ret;
}

/*================================================================================================
@brief   Start or stop Cypress module's Tx carrier test
@details Send the HCI command of starting or stopping Tx carrier test to Cypress module
@return  None
@retval  Whether or not the HCI command is sent to Cypress module successfully
================================================================================================*/
bool BT_core_set_tx_carrier_mode
    (
    const bool enable,
    const BT_tx_channel_type_e channel_type
    )
{
bool ret = false;
uint8_t param[7] = { 0 };

if( ( channel_type < 0 ) || ( channel_type >= BT_TX_CH_TYPE_INVALID ) )
    {
    BT_LOG_DEBUG( "Invalid channel type" );
    }
else
    {
    param[0] = ( enable ? 0x00 : 0x01 );    // Carrier Enable
    param[1] = s_tx_ch_freqs[channel_type]; // Carrier Frequency: n + 2400
    param[2] = 0;                           // Mode. 0 = Unmodulated
    param[3] = 0;                           // Modulation Type (ignored if Mode is Unmodulated)
    param[4] = 9;                           // Transmit Power. 9 = Specify Power Table Index
    param[5] = 0;                           // Power dBm
    param[6] = 0;                           // Power Table Index

    ret = HCI_send_standard_command( HCI_STANDARD_COMMAND_TX_CARRIER, param, sizeof( param ) );
    }
return ret;
}

/*================================================================================================
@brief   Update the firmware stored in MCU to Cypress module
@details Send the HCI commands to download the firmware stored in MCU to Cypress module
@return  None
@retval  Whether or not the firmware update of Cypress module is successful
================================================================================================*/
bool BT_core_update_firmware( void )
{
bool ret = BT_update_start();

if( ret )
    {
    if( BT_POWER_ON_UPDATING == BT_core_get_power_status() )
        {
        BT_core_set_power_status( BT_POWER_ON );
        }

    BT_core_set_enable_state( false, false );
    BT_core_set_enable_state( true, false );
    }
return ret;
}

// HCI event handler

/*================================================================================================
@brief   Handle the device event that the ACL link's connection status is changed
@details Handle the device event that the ACL link's connection status is changed
@return  None
@retval  None
================================================================================================*/
void BT_core_handle_device_event_connection_status
    (
    const uint8_t* bd_addr,
    const BT_transport_type_e transport_type,
    const bool connected,
    const uint8_t reason
    )
{
// TODO: Notify CM that the BR/EDR ACL link is disconnected with reason including Auth Lost
}

/*================================================================================================
@brief   Handle the device event that Cypress module is started
@details Handle the device event that Cypress module is started
@return  None
@retval  None
================================================================================================*/
void BT_core_handle_device_event_device_started
    (
    const uint8_t major_version,
    const uint8_t minor_version
    )
{
BT_request_t request = { 0 };
BT_sync_event_t sync_event = { BT_SYNC_EVENT_DEVICE_STARTED, { { 0 } } };

// Cypress module started, reset all data
BT_core_reset_all();

BT_tsk_sync_signal( &sync_event );

if( BT_update_has_newer_firmware( major_version, minor_version ) )
    {
    BT_core_set_power_status( BT_POWER_ON_UPDATING );
    request.type = BT_REQUEST_UPDATE_FIRMWARE;
    }
else
    {
    request.type = BT_REQUEST_INIT_MODULE;
    }
BT_tsk_send_request( &request );
}

/*================================================================================================
@brief   Handle the device event that the paired device is deleted
@details Handle the device event that the paired device is deleted
@return  None
@retval  None
================================================================================================*/
void BT_core_handle_device_event_paired_device_deleted
    (
    const uint8_t* bd_addr
    )
{
BT_sync_event_t sync_event = { BT_SYNC_EVENT_PAIRED_DEVICE_DELETED, { { 0 } } };

memcpy( sync_event.param_u.paired_device_deleted.bd_addr, bd_addr, BT_DEVICE_ADDRESS_LEN );
BT_tsk_sync_signal( &sync_event );

// TODO: Notify HMI and CM that the paired device is deleted
}

/*================================================================================================
@brief   Handle the device event that the latest paired device list is received
@details Handle the device event that the latest paired device list is received
@return  None
@retval  None
================================================================================================*/
void BT_core_handle_device_event_paired_device_list
    (
    const uint8_t* raw_device_list
    )
{
BT_device_update( raw_device_list );
}

/*================================================================================================
@brief   Handle the device event that the pairing is completed
@details Handle the device event that the pairing is completed
@return  None
@retval  None
================================================================================================*/
void BT_core_handle_device_event_pairing_complete
    (
    const uint8_t result
    )
{
BT_core_set_pairing_status( BT_PAIRING_NONE, NULL );

// TODO: Notify HMI and CM the pairing result
}

/*================================================================================================
@brief   Handle the device event that the pairing request of user confirmation is received
@details Handle the device event that the pairing request of user confirmation is received
@return  None
@retval  None
================================================================================================*/
void BT_core_handle_device_event_user_confirmation
    (
    const uint8_t* bd_addr,
    const uint32_t passkey
    )
{
BT_core_set_pairing_status( BT_PAIRING_USER_CONFIRMING, bd_addr );

// TODO: Notify HMI the pairing request
}

/*================================================================================================
@brief   Handle the standard event that the chip erase command is completed
@details Handle the standard event that the chip erase command is completed
@return  None
@retval  None
================================================================================================*/
void BT_core_handle_standard_event_chip_erase_complete
    (
    const uint8_t error_code
    )
{
BT_sync_event_t sync_event =
    {
    .type = BT_SYNC_EVENT_CHIP_ERASE_COMPLETED,
    .param_u.chip_erase_completed.error_code = error_code
    };

BT_tsk_sync_signal( &sync_event );
}

/*================================================================================================
@brief   Handle the standard event that the launch RAM command is completed
@details Handle the standard event that the launch RAM command is completed
@return  None
@retval  None
================================================================================================*/
void BT_core_handle_standard_event_launch_ram_complete
    (
    const uint8_t error_code
    )
{
BT_sync_event_t sync_event =
    {
    .type = BT_SYNC_EVENT_LAUNCH_RAM_COMPLETED,
    .param_u.launch_ram_completed.error_code = error_code
    };

BT_tsk_sync_signal( &sync_event );
}

/*================================================================================================
@brief   Handle the standard event that the read RAM command is completed
@details Handle the standard event that the read RAM command is completed
@return  None
@retval  None
================================================================================================*/
void BT_core_handle_standard_event_read_ram_complete
    (
    const uint8_t error_code,
    const uint8_t* data,
    const uint8_t data_len
    )
{
BT_sync_event_t sync_event =
    {
    .type = BT_SYNC_EVENT_READ_RAM_COMPLETED,
    .param_u.read_ram_completed.error_code = error_code,
    .param_u.read_ram_completed.data = { 0 },
    .param_u.read_ram_completed.data_len = data_len
    };

memcpy( sync_event.param_u.read_ram_completed.data, data, data_len );
BT_tsk_sync_signal( &sync_event );
}

/*================================================================================================
@brief   Handle the standard event that the reset command is completed
@details Handle the standard event that the reset command is completed
@return  None
@retval  None
================================================================================================*/
void BT_core_handle_standard_event_reset_complete
    (
    const uint8_t error_code
    )
{
BT_sync_event_t sync_event =
    {
    .type = BT_SYNC_EVENT_RESET_COMPLETED,
    .param_u.reset_completed.error_code = error_code
    };

BT_tsk_sync_signal( &sync_event );
}

/*================================================================================================
@brief   Handle the standard event that the update baudrate command is completed
@details Handle the standard event that the update baudrate command is completed
@return  None
@retval  None
================================================================================================*/
void BT_core_handle_standard_event_update_baudrate_complete
    (
    const uint8_t error_code
    )
{
BT_sync_event_t sync_event =
    {
    .type = BT_SYNC_EVENT_UPDATE_BAUDRATE_COMPLETED,
    .param_u.update_baudrate_completed.error_code = error_code
    };

BT_tsk_sync_signal( &sync_event );
}

/*================================================================================================
@brief   Handle the standard event that the write RAM command is completed
@details Handle the standard event that the write RAM command is completed
@return  None
@retval  None
================================================================================================*/
void BT_core_handle_standard_event_write_ram_complete
    (
    const uint8_t error_code
    )
{
BT_sync_event_t sync_event =
    {
    .type = BT_SYNC_EVENT_WRITE_RAM_COMPLETED,
    .param_u.write_ram_completed.error_code = error_code
    };

BT_tsk_sync_signal( &sync_event );
}

#ifdef __cplusplus
}
#endif
