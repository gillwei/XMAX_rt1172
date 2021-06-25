/*********************************************************************
* @file  hci_cmd.c
* @brief Bluetooth Manager HCI command interface definition.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <string.h>

#include "fsl_debug_console.h"
#include "PERIPHERAL_pub.h"

#include "bt_log.h"
#include "bt_utils.h"
#include "hci_cmd.h"
#include "hci_tsk.h"

/*--------------------------------------------------------------------
                        Definitions
--------------------------------------------------------------------*/

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

/*--------------------------------------------------------------------
                        PROTOTYPES
--------------------------------------------------------------------*/
static bool HCI_send_command
    (
    const bool wiced_cmd,
    const uint16_t op_code,
    const uint8_t* payload,
    const uint16_t payload_len
    );

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
/*================================================================================================
@brief   Send the HCI command to Cypress module over UART
@details Send the HCI command to Cypress module over UART
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
static bool HCI_send_command
    (
    const bool wiced_cmd,
    const uint16_t op_code,
    const uint8_t* payload,
    const uint16_t payload_len
    )
{
uint8_t hci_cmd[HCI_COMMAND_MAX_SIZE] = { 0 };
uint8_t cmd_len = 0;

if( payload_len > HCI_PAYLOAD_MAX_SIZE )
    {
    BT_LOG_ERROR( "Maximum HCI payload size exceeded: %u (> %d)", payload_len, HCI_PAYLOAD_MAX_SIZE );
    return false;
    }

if( wiced_cmd )
    {
    hci_cmd[cmd_len++] = HCI_WICED_PKT;
    }
else
    {
    hci_cmd[cmd_len++] = HCI_STANDARD_COMMAND_PKT;
    }

INT16_TO_LITTLE_ENDIAN( op_code, &( hci_cmd[cmd_len] ) );
cmd_len += 2;

if( wiced_cmd )
    {
    INT16_TO_LITTLE_ENDIAN( payload_len, &( hci_cmd[cmd_len] ) );
    cmd_len += 2;
    }
else
    {
    hci_cmd[cmd_len++] = (uint8_t)payload_len;
    }

if( ( payload_len > 0 ) && ( NULL != payload ) )
    {
    memcpy( &( hci_cmd[cmd_len] ), payload, payload_len );
    cmd_len += payload_len;
    }

if( false == PERIPHERAL_uart_tx_data( cmd_len, hci_cmd ) )
    {
    BT_LOG_ERROR( "UART error" );
    return false;
    }

BT_LOG_DEBUG( "HCI command sent: op_code=0x%04x, cmd_len=%u, payload_len=%u", op_code, cmd_len, payload_len );
#if( HCI_DEBUG_ENABLED )
    {
    PRINTF( "[BT]HCI Tx[%u]: ", cmd_len );
    for( uint8_t i = 0; i < cmd_len; ++i )
        {
        PRINTF( "%02x ", hci_cmd[i] );
        }
    PRINTF( "\r\n" );
    }
#endif
return true;
}

/*================================================================================================
@brief   Send the Standard HCI command to Cypress module over UART
@details Send the Standard HCI command to Cypress module over UART. This should be used by Bluetooth
         Manager Main task only, do NOT use this in other tasks
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
bool HCI_send_standard_command
    (
    const uint16_t op_code,
    const uint8_t* payload,
    const uint8_t payload_len
    )
{
bool ret = HCI_send_command( false, op_code, payload, payload_len );
if( false == ret )
    {
    BT_LOG_ERROR( "HCI command sent failed: op_code=0x%04x", op_code );
    }
return ret;
}

/*================================================================================================
@brief   Send the Wiced HCI command to Cypress module over UART
@details Send the Wiced HCI command to Cypress module over UART. This should be used by Bluetooth
         Manager Main task only, do NOT use this in other tasks
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
bool HCI_send_wiced_command
    (
    const uint16_t op_code,
    const uint8_t* payload,
    const uint16_t payload_len
    )
{
bool ret = HCI_send_command( true, op_code, payload, payload_len );
if( false == ret )
    {
    BT_LOG_ERROR( "HCI command sent failed: op_code=0x%04x", op_code );
    }
return ret;
}

#ifdef __cplusplus
}
#endif
