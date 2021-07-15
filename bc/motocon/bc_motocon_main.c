/*********************************************************************
* @file
* bc_motocon_main.c
*
* @brief
* MotoConSDK module - main
*
* Copyright 2020-2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <bc_motocon_priv.h>
#include <HCI_pub.h>
#include <hci_control_api.h>
#if( ENABLE_MOTOCON_HCI_LINK )
    #include <cycfg_gatt_db.h>
#endif
#include "timers.h"
#include "client_dcm_appl.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define MOTOCON_ALIVE_TIMEOUT_COUNT ( 3 )
#define MOTOCON_ALIVE_INTERVAL_TICKS ( pdMS_TO_TICKS( 3000 ) )

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
void BC_motocon_ble_connected_callback( void );
void BC_motocon_ble_disconnected_callback( void );
void BC_motocon_read_request_received_callback( const uint16_t handle );
void BC_motocon_write_request_received_callback( const uint16_t handle, const uint8_t* data, const uint16_t length );
static void send_alive_request( TimerHandle_t timer_handle );

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/
bc_motocon_callback_t* bc_motocon_callbacks[BC_MOTOCON_CALLBACK_MAX];
static bool bc_motocon_connected;
static uint8_t alive_count;
static uint8_t alive_id;
static TimerHandle_t alive_send_timer;

#if( ENABLE_MOTOCON_HCI_LINK )
    static ble_server_callback bc_motocon_ble_callback =
        {
        BC_motocon_ble_connected_callback,
        BC_motocon_ble_disconnected_callback,
        BC_motocon_read_request_received_callback,
        BC_motocon_write_request_received_callback
        };
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
* bc_motocon_init
*
* Initialize MotoConSDK module
*
*********************************************************************/
void bc_motocon_init
    (
    void
    )
{
bc_motocon_authentication_init();
bc_motocon_set_connected( false );
#if( ENABLE_MOTOCON_HCI_LINK )
    HCI_le_register_server_callback( BLE_SERVER_MOTOCONSDK, &bc_motocon_ble_callback );
#endif
bc_motocon_ddt_init();
alive_count = 0;
alive_id = 0;
alive_send_timer = xTimerCreate( "MotoconAliveTimer", MOTOCON_ALIVE_INTERVAL_TICKS, pdTRUE, ( void * ) 0, send_alive_request );
configASSERT( NULL != alive_send_timer );
}

/*********************************************************************
*
* @public
* BC_motocon_register_callback
*
* Register callback for motocon.
*
* @param callback Pointer of callback
*
* @return boolean
* Register successfully or not (true or false)
*
*********************************************************************/
bool BC_motocon_register_callback
    (
    bc_motocon_callback_t* callback
    )
{
for( int i = 0; i < BC_MOTOCON_CALLBACK_MAX; i++ )
    {
    if( NULL == bc_motocon_callbacks[i] )
        {
        bc_motocon_callbacks[i] = callback;
        return true;
        }
    }
return false;
}

/*********************************************************************
*
* @public
* BC_motocon_unregister_callback
*
* Unregister callback for motocon.
*
* @param callback Pointer of callback
*
* @return boolean
* Unregister successfully or not (true or false)
*
*********************************************************************/
bool BC_motocon_unregister_callback
    (
    bc_motocon_callback_t* callback
    )
{
for( int i = 0; i < BC_MOTOCON_CALLBACK_MAX; i++ )
    {
    if( callback == bc_motocon_callbacks[i] )
        {
        bc_motocon_callbacks[i] = NULL;
        return true;
        }
    }
return false;
}

/*********************************************************************
*
* @public
* BC_motocon_is_connected
*
* Check if phone app is connected.
*
* @return boolean
* Connected or not (true or false)
*
*********************************************************************/
bool BC_motocon_is_connected
    (
    void
    )
{
return bc_motocon_connected;
}

/*********************************************************************
*
* @private
* reset_alive_timer
*
* Reset/start alive timer and reset alive_count.
*
*********************************************************************/
static void reset_alive_timer
    (
    void
    )
{
if( bc_motocon_connected )
    {
    alive_count = 0;
    BaseType_t result = xTimerStart( alive_send_timer, MOTOCON_ALIVE_INTERVAL_TICKS );
    configASSERT( result == pdPASS );
    }
}

/*********************************************************************
*
* @public
* bc_motocon_set_connected
*
* Check if phone app is connected.
*
* @param connected Is connected or not
*
*********************************************************************/
void bc_motocon_set_connected
    (
    bool connected
    )
{
BC_MOTOCON_PRINTF( "%s: %d\r\n", __FUNCTION__, connected );
if( bc_motocon_connected != connected )
    {
    bc_motocon_connected = connected;
    client_appl_set_ble_connected_state( connected );
    if( bc_motocon_connected )
        {
        reset_alive_timer();
        }
    else
        {
        BaseType_t result = xTimerStop( alive_send_timer, 0 );
        configASSERT( result == pdPASS );
        }
    for( int i = 0; i < BC_MOTOCON_CALLBACK_MAX; i++ )
        {
        if( NULL != bc_motocon_callbacks[i] &&
            NULL != bc_motocon_callbacks[i]->connected_status_changed_callback )
            {
            bc_motocon_callbacks[i]->connected_status_changed_callback( bc_motocon_connected );
            }
        }
    }
}

/*********************************************************************
*
* @private
* send_alive_request
*
* Send alive signal request via BLE.
* If alive_count is over MOTOCON_ALIVE_TIMEOUT_COUNT times, disconnect current ble connection,
* if not, send alive request and +1 alive_count.
*
* @param timer_handle Timer handle
*
*********************************************************************/
static void send_alive_request
    (
    TimerHandle_t timer_handle
    )
{
BC_MOTOCON_PRINTF( "%s, %d\r\n", __FUNCTION__, alive_id );
if( alive_count >= MOTOCON_ALIVE_TIMEOUT_COUNT )
    {
    BC_MOTOCON_PRINTF( "%s, disconnect ble. (sim)\r\n", __FUNCTION__ );
    // disable disconnect function for sv testing.
    //BC_MOTOCON_PRINTF( "%s, disconnect ble.\r\n", __FUNCTION__ );
    //HCI_le_disconnect_ble();
    }
else
    {
    uint8_t data[3];
    data[0] = BC_MOTOCON_COMMAND_CODE_ALIVE_CHECK_REQUEST >> 8;
    data[1] = BC_MOTOCON_COMMAND_CODE_ALIVE_CHECK_REQUEST & 0xFF;
    data[2] = alive_id++;
    bc_motocon_send_data( BC_MOTOCON_NOTIFY, data, 3 );
    alive_count++;
    }
}

/*********************************************************************
*
* @public
* BC_motocon_send_lib_version
*
* Send lib version via BLE.
*
* @param major Major version code
* @param minor Minor version code
* @param micro Micro version code
*
* @return bc_motocon_send_result_t
* Result of send command
*
*********************************************************************/
bc_motocon_send_result_t BC_motocon_send_lib_version
    (
    const uint8_t major,
    const uint8_t minor,
    const uint8_t micro
    )
{
BC_MOTOCON_PRINTF( "%s, %d %d %d\r\n", __FUNCTION__, major, minor, micro );
uint8_t data[5];
data[0] = BC_MOTOCON_COMMAND_CODE_LIB_VERSION >> 8;
data[1] = BC_MOTOCON_COMMAND_CODE_LIB_VERSION & 0xFF;
data[2] = major;
data[3] = minor;
data[4] = micro;
return bc_motocon_send_data( BC_MOTOCON_NOTIFY, data, 5 );
}

/*********************************************************************
*
* @public
* BC_motocon_send_weather_request
*
* Send weather request via BLE.
*
* @return bc_motocon_send_result_t
* Result of send command
*
*********************************************************************/
bc_motocon_send_result_t BC_motocon_send_weather_request
    (
    void
    )
{
BC_MOTOCON_PRINTF( "%s\r\n", __FUNCTION__ );
uint8_t data[3];
data[0] = BC_MOTOCON_COMMAND_CODE_WEATHER_REQUEST >> 8;
data[1] = BC_MOTOCON_COMMAND_CODE_WEATHER_REQUEST & 0xFF;
data[2] = 1;
bc_motocon_send_data( BC_MOTOCON_NOTIFY, data, 3 );
return BC_MOTOCON_SEND_RESULT_SUCCESS;
}

/*********************************************************************
*
* @public
* BC_motocon_send_vehicle_info
*
* Send vehicle info (speed & ignition) via BLE.
*
* @param command MotoConSDK's command code
*
* @return bc_motocon_send_result_t
* Result of send command
*
*********************************************************************/
bc_motocon_send_result_t BC_motocon_send_vehicle_info
    (
    const bc_motocon_vehicle_info_t* info
    )
{
BC_MOTOCON_PRINTF( "%s, %d %d %d %d %d\r\n", __FUNCTION__, info->front_speed, info->rear_speed, info->safe_mode_speed, info->ignition_on, info->speed_unit_miles );
uint8_t data[10];
data[0] = BC_MOTOCON_COMMAND_CODE_VEHICLE_INFORMATION >> 8;
data[1] = BC_MOTOCON_COMMAND_CODE_VEHICLE_INFORMATION & 0xFF;
data[2] = info->front_speed >> 8;
data[3] = info->front_speed & 0xFF;
data[4] = info->rear_speed >> 8;
data[5] = info->rear_speed & 0xFF;
data[6] = info->safe_mode_speed >> 8;
data[7] = info->safe_mode_speed & 0xFF;
data[8] = info->ignition_on;
data[9] = info->speed_unit_miles;
return bc_motocon_send_data( BC_MOTOCON_NOTIFY, data, 10 );
}

/*********************************************************************
*
* @public
* BC_motocon_send_vehicle_setting_request
*
* Send time request via BLE.
*
* @return bc_motocon_send_result_t
* Result of send command
*
*********************************************************************/
bc_motocon_send_result_t BC_motocon_send_vehicle_setting_request
    (
    void
    )
{
BC_MOTOCON_PRINTF( "%s\r\n", __FUNCTION__ );
uint8_t data[2];
data[0] = BC_MOTOCON_COMMAND_CODE_VEHICLE_SETTING_REQUEST >> 8;
data[1] = BC_MOTOCON_COMMAND_CODE_VEHICLE_SETTING_REQUEST & 0xFF;
return bc_motocon_send_data( BC_MOTOCON_NOTIFY, data, 2 );
}

/*********************************************************************
*
* @public
* BC_motocon_send_language_type_request
*
* Send language request via BLE.
*
* @return bc_motocon_send_result_t
* Result of send command
*
*********************************************************************/
bc_motocon_send_result_t BC_motocon_send_language_type_request
    (
    void
    )
{
BC_MOTOCON_PRINTF( "%s\r\n", __FUNCTION__ );
uint8_t data[2];
data[0] = BC_MOTOCON_COMMAND_CODE_LANGUAGE_TYPE_REQUEST >> 8;
data[1] = BC_MOTOCON_COMMAND_CODE_LANGUAGE_TYPE_REQUEST & 0xFF;
return bc_motocon_send_data( BC_MOTOCON_NOTIFY, data, 2 );
}

/*********************************************************************
*
* @public
* BC_motocon_send_authenticationv2_result
*
* Send authenticationv2 result.
*
* @param result Authentication result
*
* @return bc_motocon_send_result_t
* Result of send command
*
*********************************************************************/
bc_motocon_send_result_t BC_motocon_send_authenticationv2_result
    (
    bool result
    )
{
BC_MOTOCON_PRINTF( "%s\r\n", __FUNCTION__ );
uint8_t data[3];
data[0] = BC_MOTOCON_COMMAND_CODE_AUTHENTICATION_V2_RESPONSE >> 8;
data[1] = BC_MOTOCON_COMMAND_CODE_AUTHENTICATION_V2_RESPONSE & 0xFF;
data[2] = result;
return bc_motocon_send_data( BC_MOTOCON_NOTIFY, data, 3 );
}

/*********************************************************************
*
* @public
* BC_motocon_send_can_related_data
*
* Send can related via BLE, data shall not be modified before result_callback called.
* 0x0101 ~ 0x0112
*
* @param command         MotoConSDK's command code
* @param size            Size of data or protobuf
* @param data            Bytes of data or protobuf
* @param result_callback Function pointer of result callback
*
* @return bc_motocon_send_result_t
* Result of send command
*
*********************************************************************/
bc_motocon_send_result_t BC_motocon_send_can_related_data
    (
    const bc_motocon_command_code_t command,
    const uint32_t                  size,
    const uint8_t*                  data,
    void ( *result_callback ) ( const bc_motocon_send_result_t )
    )
{
#ifndef BC_DEBUG
uint32_t index = 0;
BC_MOTOCON_PRINTF( "Response to APP-RSPCMD: %02x \r\n", command );
BC_MOTOCON_PRINTF( "Rseposne to APP-Datalen: %d \r\n", size );
BC_MOTOCON_PRINTF("Response to APP-data:");

for(; index < size; index++)
    {
    BC_MOTOCON_PRINTF( " %02x", data[index]);
    if( index % 30 == 0 )
        {
        BC_MOTOCON_PRINTF("\r\n");
        }
    }
    BC_MOTOCON_PRINTF( " \r\n");
#endif

if( command == BC_MOTOCON_COMMAND_CODE_AUTHENTICATION_V2_RESPONSE )
    {
    uint8_t data[3];
    data[0] = BC_MOTOCON_COMMAND_CODE_AUTHENTICATION_V2_RESPONSE >> 8;
    data[1] = BC_MOTOCON_COMMAND_CODE_AUTHENTICATION_V2_RESPONSE & 0xFF;
    data[2] = data[0];
    bc_motocon_send_result_t ret = bc_motocon_send_data( BC_MOTOCON_NOTIFY, data, 3 );
    if( result_callback != NULL )
        {
        result_callback( ret );
        }
    return ret;
    }
else
    {
    return bc_motocon_ddt_send_ddt_to_phone_data( command, data, size, result_callback );
    }
}

/*********************************************************************
*
* @public
* BC_motocon_send_can_response
*
* Send can response via BLE, data shall not be modified before result_callback called.
*
* @param size            Size of protobuf
* @param data            Bytes of protobuf
* @param result_callback Function pointer of result callback
*
* @return bc_motocon_send_result_t
* Result of send command
*
*********************************************************************/
bc_motocon_send_result_t BC_motocon_send_can_response
    (
    const uint32_t size,
    const uint8_t* data,
    void ( *result_callback ) ( const bc_motocon_send_result_t )
    )
{
if( !bc_motocon_connected )
    {
    return BC_MOTOCON_SEND_RESULT_BLE_ERROR;
    }
BC_MOTOCON_PRINTF( "%s, size: %d\r\n", __FUNCTION__, size );
return bc_motocon_ddt_send_ddt_to_phone_data( BC_MOTOCON_COMMAND_CODE_CAN_RESPONSE, data, size, result_callback );
}

/*********************************************************************
*
* @public
* BC_motocon_send_injection_quantity
*
* Send cumulative injection quantity via BLE, data shall be 4 bytes.
*
* @param injection_quantity Bytes of cumulative injection quantity
*
* @return bc_motocon_send_result_t
* Result of send command
*
*********************************************************************/
bc_motocon_send_result_t BC_motocon_send_injection_quantity
    (
    const uint8_t* injection_quantity
    )
{
BC_MOTOCON_PRINTF( "%s\r\n", __FUNCTION__ );
uint8_t data[6];
data[0] = BC_MOTOCON_COMMAND_CODE_CUMULATIVE_INJECTION_QUANTITY >> 8;
data[1] = BC_MOTOCON_COMMAND_CODE_CUMULATIVE_INJECTION_QUANTITY & 0xFF;
data[2] = injection_quantity[0];
data[3] = injection_quantity[1];
data[4] = injection_quantity[2];
data[5] = injection_quantity[3];
return bc_motocon_send_data( BC_MOTOCON_NOTIFY, data, 6 );
}

/*********************************************************************
*
* @public
* BC_motocon_send_bt_music_control
*
* Send music control via BLE.
*
* @param control Music control key
*
* @return bc_motocon_send_result_t
* Result of send command
*
*********************************************************************/
bc_motocon_send_result_t BC_motocon_send_bt_music_control
    (
    bc_motocon_bt_music_control_t control
    )
{
BC_MOTOCON_PRINTF( "%s, %d\r\n", __FUNCTION__, control );
uint8_t data[3];
data[0] = BC_MOTOCON_COMMAND_CODE_BLUETOOTH_MUSIC_CONTROL >> 8;
data[1] = BC_MOTOCON_COMMAND_CODE_BLUETOOTH_MUSIC_CONTROL & 0xFF;
data[2] = control;
return bc_motocon_send_data( BC_MOTOCON_NOTIFY, data, 3 );
}

/*********************************************************************
*
* @public
* BC_motocon_send_incoming_call_control
*
* Send incoming call control via BLE.
*
* @param control Call control key
*
* @return bc_motocon_send_result_t
* Result of send command
*
*********************************************************************/
bc_motocon_send_result_t BC_motocon_send_incoming_call_control
    (
    bc_motocon_incoming_call_control_t control
    )
{
BC_MOTOCON_PRINTF( "%s, %d\r\n", __FUNCTION__, control );
uint8_t data[3];
data[0] = BC_MOTOCON_COMMAND_CODE_INCOMING_CALL_CONTROL >> 8;
data[1] = BC_MOTOCON_COMMAND_CODE_INCOMING_CALL_CONTROL & 0xFF;
data[2] = control;
return bc_motocon_send_data( BC_MOTOCON_NOTIFY, data, 3 );
}

/*********************************************************************
*
* @public
* BC_motocon_send_headset_state_request
*
* Send headset state request via BLE.
*
* @return bc_motocon_send_result_t
* Result of send command
*
*********************************************************************/
bc_motocon_send_result_t BC_motocon_send_headset_state_request
    (
    void
    )
{
BC_MOTOCON_PRINTF( "%s\r\n", __FUNCTION__ );
uint8_t data[2];
data[0] = BC_MOTOCON_COMMAND_CODE_BLUETOOTH_HEADSET_STATE_REQUEST >> 8;
data[1] = BC_MOTOCON_COMMAND_CODE_BLUETOOTH_HEADSET_STATE_REQUEST & 0xFF;
return bc_motocon_send_data( BC_MOTOCON_NOTIFY, data, 2 );
}

/*********************************************************************
*
* @public
* BC_motocon_send_volume_control
*
* Send volume control via BLE.
*
* @param control Volume control key
*
* @return bc_motocon_send_result_t
* Result of send command
*
*********************************************************************/
bc_motocon_send_result_t BC_motocon_send_volume_control
    (
    bc_motocon_volume_control_t control
    )
{
BC_MOTOCON_PRINTF( "%s, %d\r\n", __FUNCTION__, control );
uint8_t data[3];
data[0] = BC_MOTOCON_COMMAND_CODE_PHONE_VOLUME_CONTROL >> 8;
data[1] = BC_MOTOCON_COMMAND_CODE_PHONE_VOLUME_CONTROL & 0xFF;
data[2] = control;
return bc_motocon_send_data( BC_MOTOCON_NOTIFY, data, 3 );
}

/*********************************************************************
*
* @public
* BC_motocon_send_volume_controllable_request
*
* Send volume controllable request via BLE.
*
* @return bc_motocon_send_result_t
* Result of send command
*
*********************************************************************/
bc_motocon_send_result_t BC_motocon_send_volume_controllable_request
    (
    void
    )
{
BC_MOTOCON_PRINTF( "%s\r\n", __FUNCTION__ );
uint8_t data[2];
data[0] = BC_MOTOCON_COMMAND_CODE_PHONE_VOLUME_CONTROLLABLE_REQUEST >> 8;
data[1] = BC_MOTOCON_COMMAND_CODE_PHONE_VOLUME_CONTROLLABLE_REQUEST & 0xFF;
return bc_motocon_send_data( BC_MOTOCON_NOTIFY, data, 2 );
}

/*********************************************************************
*
* @public
* BC_motocon_send_create_ota_request
*
* Send create ota connection request via BLE.
*
* @return bc_motocon_send_result_t
* Result of send command
*
*********************************************************************/
bc_motocon_send_result_t BC_motocon_send_create_ota_request
    (
    void
    )
{
BC_MOTOCON_PRINTF( "%s\r\n", __FUNCTION__ );
uint8_t data[2];
data[0] = BC_MOTOCON_COMMAND_CODE_CREATE_OTA_CONNECTION_REQUEST >> 8;
data[1] = BC_MOTOCON_COMMAND_CODE_CREATE_OTA_CONNECTION_REQUEST & 0xFF;
return bc_motocon_send_data( BC_MOTOCON_NOTIFY, data, 2 );
}

/*********************************************************************
*
* @public
* BC_motocon_send_ota_linkcard_info
*
* Send ota linkcard info via BLE.
*
* @return bc_motocon_send_result_t
* Result of send command
*
*********************************************************************/
bc_motocon_send_result_t BC_motocon_send_ota_linkcard_info
    (
    const bc_motocon_ota_linkcard_info_t* info
    )
{
BC_MOTOCON_PRINTF( "%s\r\n", __FUNCTION__ );
uint8_t data[16];
data[0] = BC_MOTOCON_COMMAND_CODE_OTA_LINKCARD_INFORMATION >> 8;
data[1] = BC_MOTOCON_COMMAND_CODE_OTA_LINKCARD_INFORMATION & 0xFF;
data[2] = info->current_firmware_ver >> 8;
data[3] = info->current_firmware_ver & 0xFF;
data[4] = info->linkcard_model;
memcpy( data + 5, info->serial_number, 10 );
data[15] = info->new_program_position;
return bc_motocon_send_data( BC_MOTOCON_NOTIFY, data, 16 );
}

/*********************************************************************
*
* @public
* BC_motocon_send_ccuid_response
*
* Send ccuid via BLE.
*
* @param ccuid Ccu id, the size of data must be 14 byte.
*
* @return bc_motocon_send_result_t
* Result of send command
*
*********************************************************************/
bc_motocon_send_result_t BC_motocon_send_ccuid_response
    (
    const uint8_t* ccuid
    )
{
BC_MOTOCON_PRINTF( "%s\r\n", __FUNCTION__ );
uint8_t data[16];
data[0] = BC_MOTOCON_COMMAND_CODE_CCUID_RESPONSE >> 8;
data[1] = BC_MOTOCON_COMMAND_CODE_CCUID_RESPONSE & 0xFF;
memcpy( data + 2, ccuid, 14 );
return bc_motocon_send_data( BC_MOTOCON_NOTIFY, data, 16 );
}

/*********************************************************************
*
* @public
* BC_motocon_send_cell_signal_request
*
* Send cell signal request via BLE.
*
* @return bc_motocon_send_result_t
* Result of send command
*
*********************************************************************/
bc_motocon_send_result_t BC_motocon_send_cell_signal_request
    (
    void
    )
{
BC_MOTOCON_PRINTF( "%s\r\n", __FUNCTION__ );
uint8_t data[2];
data[0] = BC_MOTOCON_COMMAND_CODE_PHONE_CELL_SIGNAL_LEVEL_REQUEST >> 8;
data[1] = BC_MOTOCON_COMMAND_CODE_PHONE_CELL_SIGNAL_LEVEL_REQUEST & 0xFF;
return bc_motocon_send_data( BC_MOTOCON_NOTIFY, data, 2 );
}

/*********************************************************************
*
* @public
* BC_motocon_send_ignition_state_response
*
* Send ignition state via BLE.
*
* @return bc_motocon_send_result_t
* Result of send command
*
*********************************************************************/
bc_motocon_send_result_t BC_motocon_send_ignition_state_response
    (
    const bc_motocon_ignition_state_t state
    )
{
BC_MOTOCON_PRINTF( "%s\r\n", __FUNCTION__ );
uint8_t data[3];
data[0] = BC_MOTOCON_COMMAND_CODE_IGNITION_STATE_RESPONSE >> 8;
data[1] = BC_MOTOCON_COMMAND_CODE_IGNITION_STATE_RESPONSE & 0xFF;
data[2] = state;
return bc_motocon_send_data( BC_MOTOCON_NOTIFY, data, 3 );
}

/*********************************************************************
*
* @public
* bc_motocon_send_data
*
* Send data via BLE.
*
* @param type   Type of sending way
* @param bytes  Encoded data
* @param length Length of bytes
*
* @return bc_motocon_send_result_t
* Result of send command
*
*********************************************************************/
bc_motocon_send_result_t bc_motocon_send_data
    (
    const bc_motocon_send_type_t type,
    const uint8_t*               bytes,
    const uint32_t               length
    )
{
BC_MOTOCON_PRINTF( "%s, type: %d, length: %d, content:", __FUNCTION__, type, length );
for( int i = 0; i < length; i++ )
    {
    BC_MOTOCON_PRINTF( " %2X", bytes[i] );
    }
BC_MOTOCON_PRINTF( "\r\n" );


if( ! bc_motocon_connected )
    {
    return BC_MOTOCON_SEND_RESULT_BLE_ERROR;
    }

#if( ENABLE_MOTOCON_HCI_LINK )
    switch( type )
        {
        case BC_MOTOCON_NOTIFY:
            HCI_le_send_gatt_server_data( HCI_CONTROL_GATT_COMMAND_NOTIFY, HDLC_MOTOCONSDK_NOTIFY_VALUE, bytes, length );
            break;

        case BC_MOTOCON_DDT_TO_VEHICLE_STATUS_READ_RESPONSE:
            HCI_le_send_gatt_server_data( HCI_CONTROL_GATT_COMMAND_READ_RESPONSE, HDLC_MOTOCONSDK_DDT_TO_VEHICLE_STATUS_VALUE, bytes, length );
            break;

        case BC_MOTOCON_DDT_TO_VEHICLE_STATUS_NOTIFY:
            HCI_le_send_gatt_server_data( HCI_CONTROL_GATT_COMMAND_NOTIFY, HDLC_MOTOCONSDK_DDT_TO_VEHICLE_STATUS_VALUE, bytes, length );
            break;

        case BC_MOTOCON_DDT_TO_PHONE_CONTROL_NOTIFY:
            HCI_le_send_gatt_server_data( HCI_CONTROL_GATT_COMMAND_NOTIFY, HDLC_MOTOCONSDK_DDT_TO_PHONE_CONTROL_VALUE, bytes, length );
            break;

        case BC_MOTOCON_DDT_TO_PHONE_DATA_NOTIFY:
            HCI_le_send_gatt_server_data( HCI_CONTROL_GATT_COMMAND_NOTIFY, HDLC_MOTOCONSDK_DDT_TO_PHONE_DATA_VALUE, bytes, length );
            break;

        case BC_MOTOCON_DDT_VEHICLE_INFORMATION_CONTROL_NOTIFY:
            HCI_le_send_gatt_server_data( HCI_CONTROL_GATT_COMMAND_NOTIFY, HDLC_MOTOCONSDK_DDT_VEHICLE_INFORMATION_CONTROL_VALUE, bytes, length );
            break;

        case BC_MOTOCON_DDT_VEHICLE_INFORMATION_DATA_NOTIFY:
            HCI_le_send_gatt_server_data( HCI_CONTROL_GATT_COMMAND_NOTIFY, HDLC_MOTOCONSDK_DDT_VEHICLE_INFORMATION_DATA_VALUE, bytes, length );
            break;

        case BC_MOTOCON_DDT_CAN_CONTROL_NOTIFY:
            HCI_le_send_gatt_server_data( HCI_CONTROL_GATT_COMMAND_NOTIFY, HDLC_MOTOCONSDK_DDT_CAN_CONTROL_VALUE, bytes, length );
            break;

        case BC_MOTOCON_DDT_CAN_DATA_NOTIFY:
            HCI_le_send_gatt_server_data( HCI_CONTROL_GATT_COMMAND_NOTIFY, HDLC_MOTOCONSDK_DDT_CAN_DATA_VALUE, bytes, length );
            break;

        default:
            return BC_MOTOCON_SEND_RESULT_INVALID_TYPE;
            break;
        }
    return BC_MOTOCON_SEND_RESULT_SUCCESS;
#else
    return BC_MOTOCON_SEND_RESULT_BLE_ERROR;
#endif
}

/*********************************************************************
*
* @private
* bc_motocon_parse_error_handler
*
* Handle parser error.
*
* @param type    Parse data type
* @param result  Parse result
* @param message Error note
*
*********************************************************************/
void bc_motocon_parse_error_handler
    (
    const bc_motocon_command_code_t type,
    const bc_motocon_parse_result_t result,
    const char*                     message
    )
{
BC_MOTOCON_PRINTF( "%s, %d, result: %d, message: %s\r\n", __FUNCTION__, type, result, message );
}

/*********************************************************************
*
* @public
* BC_motocon_ble_connected_callback
*
* Handle bc_motocon_connected callback.
*
*********************************************************************/
void BC_motocon_ble_connected_callback
    (
    void
    )
{
BC_MOTOCON_PRINTF( "%s\r\n", __FUNCTION__ );
}

/*********************************************************************
*
* @public
* BC_motocon_ble_disconnected_callback
*
* Handle disconnected callback.
*
*********************************************************************/
void BC_motocon_ble_disconnected_callback
    (
    void
    )
{
BC_MOTOCON_PRINTF( "%s\r\n", __FUNCTION__ );
bc_motocon_set_connected( false );
bc_motocon_ddt_reset();
}

/*********************************************************************
*
* @public
* BC_motocon_read_request_received_callback
*
* Handle read request callback.
*
*********************************************************************/
void BC_motocon_read_request_received_callback
    (
    const uint16_t handle
    )
{
BC_MOTOCON_PRINTF( "%s\r\n", __FUNCTION__ );
#if( ENABLE_MOTOCON_HCI_LINK )
    reset_alive_timer();
    if( handle == HDLC_MOTOCONSDK_DDT_TO_VEHICLE_STATUS_VALUE )
        {
        bc_motocon_send_data( BC_MOTOCON_DDT_TO_VEHICLE_STATUS_READ_RESPONSE, bc_motocon_ddt_get_ddt_to_vehicle_status(), BC_MOTOCON_DDT_STATUS_LENGTH );
        }
#endif
}

/*********************************************************************
*
* @public
* BC_motocon_write_request_received_callback
*
* Handle write request callback.
*
*********************************************************************/
void BC_motocon_write_request_received_callback
    (
    const uint16_t handle,
    const uint8_t* data,
    const uint16_t length
    )
{
BC_MOTOCON_PRINTF( "%s\r\n", __FUNCTION__ );
#if( ENABLE_MOTOCON_HCI_LINK )
    reset_alive_timer();
    switch( handle )
        {
        case HDLC_MOTOCONSDK_WRITE_VALUE:
            bc_motocon_parser_write_received( data, length );
            break;

        case HDLC_MOTOCONSDK_DDT_TO_VEHICLE_CONTROL_VALUE:
            {
            const uint8_t* bytes = bc_motocon_ddt_set_ddt_to_vehicle_status( data );
            bc_motocon_send_data( BC_MOTOCON_DDT_TO_VEHICLE_STATUS_NOTIFY, bytes, BC_MOTOCON_DDT_STATUS_LENGTH );
            }
            break;

        case HDLC_MOTOCONSDK_DDT_TO_VEHICLE_DATA_VALUE:
            {
            const uint8_t* bytes = bc_motocon_ddt_insert_ddt_to_vehicle_data( data, length );
            if( bytes != NULL )
                {
                bc_motocon_send_data( BC_MOTOCON_DDT_TO_VEHICLE_STATUS_NOTIFY, bytes, BC_MOTOCON_DDT_STATUS_LENGTH );
                }
            }
            break;

        case HDLC_MOTOCONSDK_DDT_TO_PHONE_STATUS_VALUE:
        case HDLC_MOTOCONSDK_DDT_TO_PHONE_DATA_VALUE:
            BC_MOTOCON_PRINTF( "%s, DDT_TO_PHONE ack\r\n", __FUNCTION__ );
            bc_motocon_ddt_received_ddt_to_phone_ack( BC_MOTOCON_DDT_TO_PHONE );
            break;

        case HDLC_MOTOCONSDK_DDT_VEHICLE_INFORMATION_STATUS_VALUE:
        case HDLC_MOTOCONSDK_DDT_VEHICLE_INFORMATION_DATA_VALUE:
            BC_MOTOCON_PRINTF( "%s, DDT_VEHICLE_INFORMATION ack\r\n", __FUNCTION__ );
            bc_motocon_ddt_received_ddt_to_phone_ack( BC_MOTOCON_DDT_VEHICLE_INFORMATION );
            break;

        case HDLC_MOTOCONSDK_DDT_CAN_STATUS_VALUE:
        case HDLC_MOTOCONSDK_DDT_CAN_DATA_VALUE:
            BC_MOTOCON_PRINTF( "%s, DDT_CAN ack\r\n", __FUNCTION__ );
            bc_motocon_ddt_received_ddt_to_phone_ack( BC_MOTOCON_DDT_CAN );
            break;

        default:
            break;
        }
#endif
}
