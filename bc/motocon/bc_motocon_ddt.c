/*********************************************************************
* @file
* bc_motocon_ddt.c
*
* @brief
* MotoConSDK module - ddt
*
* Copyright 2020-2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <bc_motocon_priv.h>
#include <string.h>

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/

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
static uint8_t  ddt_to_vehicle_status[BC_MOTOCON_DDT_STATUS_LENGTH]; // (active + session_id)
static uint32_t ddt_to_vehicle_data_size;
static uint8_t  ddt_to_vehicle_buffer[BC_MOTOCON_DDT_TO_VEHICLE_BUFFER_SIZE];

static uint8_t  ddt_to_phone_id;
/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
/*********************************************************************
*
* @private
* ddt_get_ddt_to_vehicle_status
*
* Get ddt to vehicle status.
*
* @return uint8_t* (non-null)
* Return status
*
*********************************************************************/
const uint8_t* ddt_get_ddt_to_vehicle_status
    (
    void
    )
{
return ddt_to_vehicle_status;
}

/*********************************************************************
*
* @private
* ddt_set_ddt_to_vehicle_status
*
* Handle ddt to vehicle control.
*
* @param bytes Pointer received data
*
* @return uint8_t* (non-null)
* Return status
*
*********************************************************************/
const uint8_t* ddt_set_ddt_to_vehicle_status
    (
    const uint8_t* bytes
    )
{
BC_MOTOCON_PRINTF( "%s, %x\r\n", __FUNCTION__, bytes );
ddt_to_vehicle_status[0] = bytes[0] == 0 ? 0 : 1;
ddt_to_vehicle_status[1] = bytes[0];
ddt_to_vehicle_data_size = THREE_BYTE_BIG( bytes, 1 );
if( ddt_to_vehicle_data_size > BC_MOTOCON_DDT_TO_VEHICLE_BUFFER_SIZE )
    {
    memset( ddt_to_vehicle_status, 0, 2 );
    BC_MOTOCON_PRINTF( "%s, data overflow: %d > %d(limit)\r\n", __FUNCTION__, ddt_to_vehicle_data_size, BC_MOTOCON_DDT_TO_VEHICLE_BUFFER_SIZE );
    }
return ddt_to_vehicle_status;
}

/*********************************************************************
*
* @private
* ddt_insert_ddt_to_vehicle_data
*
* Handle ddt to vehicle data.
*
* @param bytes Pointer received data
*
* @return uint8_t*
* Return status is changed or NULL
*
*********************************************************************/
const uint8_t* ddt_insert_ddt_to_vehicle_data
    (
    const uint8_t* bytes,
    const uint32_t length
    )
{
BC_MOTOCON_PRINTF( "%s, %x\r\n", __FUNCTION__, bytes );

const uint8_t  session_id = bytes[0];
const uint32_t data_position = THREE_BYTE_BIG( bytes, 1 );
const uint8_t* data = bytes + 4;
const uint32_t data_length = length - 4;

if( ddt_to_vehicle_status[0] == 0 )
    {
    BC_MOTOCON_PRINTF( "%s, session inactive\r\n", __FUNCTION__ );
    return NULL;
    }

if( ddt_to_vehicle_status[1] != session_id )
    {
    BC_MOTOCON_PRINTF( "%s, invalid session id, expect %d, received %d\r\n", __FUNCTION__, ddt_to_vehicle_status[1], session_id );
    return NULL;
    }

if( data_position + data_length > ddt_to_vehicle_data_size )
    {
    memset( ddt_to_vehicle_status, 0, 2 );
    BC_MOTOCON_PRINTF( "%s, data overflow: %d + %d > %d(expect)\r\n", __FUNCTION__, data_position, data_length, ddt_to_vehicle_data_size );
    return ddt_to_vehicle_status;
    }

memcpy( ddt_to_vehicle_buffer + data_position, data, data_length );
if( data_position + data_length == ddt_to_vehicle_data_size )
    {
    parser_ddt_to_vehicle_received( ddt_to_vehicle_buffer, ddt_to_vehicle_data_size );
    ddt_reset_ddt_to_vehicle();
    return ddt_to_vehicle_status;
    }
return NULL;
}

/*********************************************************************
*
* @private
* ddt_reset_ddt_to_vehicle
*
* Reset ddt to vehicle status
*
*********************************************************************/
void ddt_reset_ddt_to_vehicle
    (
    void
    )
{
memset( ddt_to_vehicle_status, 0, 2 );
}

/*********************************************************************
*
* @private
* ddt_send_ddt_to_phone_data
*
* Send protobuf data by ddt to phone protocol. (include ddt vehicle information & ddt can)
* Input arguments are protobuf's parameters.
*
* @param command MotoConSDK's command code
* @param bytes   Bytes of protobuf
* @param length  Size of protobuf
*
* @return bc_motocon_send_result_t
* Result of send command
*
*********************************************************************/
bc_motocon_send_result_t ddt_send_ddt_to_phone_data
    (
    const bc_motocon_command_code_t command,
    const uint8_t* bytes,
    const uint32_t length
    )
{
uint32_t total_length = length + 5;
BC_MOTOCON_PRINTF( "%s, command_code: %d, length: %d\r\n", __FUNCTION__, command, total_length );
bc_motocon_send_type_t control_type = BC_MOTOCON_DDT_TO_PHONE_CONTROL_NOTIFY;
bc_motocon_send_type_t data_type = BC_MOTOCON_DDT_TO_PHONE_DATA_NOTIFY;
switch( command )
    {
    case BC_MOTOCON_COMMAND_CODE_VEHICLE_INFORMATION_RESPONSE:
        control_type = BC_MOTOCON_DDT_VEHICLE_INFORMATION_CONTROL_NOTIFY;
        data_type = BC_MOTOCON_DDT_VEHICLE_INFORMATION_DATA_NOTIFY;
        break;

    case BC_MOTOCON_COMMAND_CODE_CAN_RESPONSE:
        control_type = BC_MOTOCON_DDT_CAN_CONTROL_NOTIFY;
        data_type = BC_MOTOCON_DDT_CAN_DATA_NOTIFY;
        break;

    default:
        break;
    }
bc_motocon_send_result_t result = BC_MOTOCON_SEND_RESULT_SUCCESS;
uint8_t id = ddt_to_phone_id++;
// send control
uint8_t send_id[4];
send_id[0] = id;
send_id[1] = ( total_length >> 16 ) & 0xFF;
send_id[2] = ( total_length >> 8 ) & 0xFF;
send_id[3] = total_length & 0xFF;
result = bc_motocon_send_data( control_type, send_id, 4 );
// send data
uint32_t remain_length = total_length;
uint32_t send_point = 0;
uint32_t send_length = 0;
while( remain_length > 0 && result == BC_MOTOCON_SEND_RESULT_SUCCESS )
    {
    uint8_t send_data[BC_MOTOCON_DDT_TO_PHONE_TOTAL_PACKAGE_SIZE];
    send_data[0] = id;
    send_data[1] = ( send_point >> 16 ) & 0xFF;
    send_data[2] = ( send_point >> 8 ) & 0xFF;
    send_data[3] = send_point & 0xFF;
    if( send_point == 0 )
        {
        send_length = MIN( remain_length, BC_MOTOCON_DDT_TO_PHONE_CONTENT_SIZE - 5 );
        send_data[4] = command >> 8;
        send_data[5] = command & 0xFF;
        send_data[6] = ( length >> 16 ) & 0xFF;
        send_data[7] = ( length >> 8 ) & 0xFF;
        send_data[8] = length & 0xFF;
        memcpy( &send_data[9], bytes + send_point, send_length );
        }
    else
        {
        send_length = MIN( remain_length, BC_MOTOCON_DDT_TO_PHONE_CONTENT_SIZE );
        memcpy( &send_data[4], bytes + send_point, send_length );
        }
    result = bc_motocon_send_data( data_type, send_data, send_length );
    send_point += send_length;
    remain_length -= send_length;
    }
return result;
}
