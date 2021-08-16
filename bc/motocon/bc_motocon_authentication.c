/*********************************************************************
* @file
* bc_motocon_authentication.c
*
* @brief
* MotoConSDK module - authentication
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <bc_motocon_priv.h>
#include <string.h>
#include "BT_pub.h"
#include "CM_pub.h"
#include "EW_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define BC_MOTOCON_AUTHENTICATION_HEADER_SIZE  ( 2 )
#define BC_MOTOCON_AUTHENTICATION_CCUID_SIZE   ( 14 )
#define BC_MOTOCON_AUTHENTICATION_PASSKEY_SIZE ( 6 )
#define BC_MOTOCON_AUTHENTICATION_DATA_SIZE    ( BC_MOTOCON_AUTHENTICATION_HEADER_SIZE + BC_MOTOCON_AUTHENTICATION_CCUID_SIZE + BC_MOTOCON_AUTHENTICATION_PASSKEY_SIZE )
#define BC_MOTOCON_BTC_HEADER_SIZE             ( 5 )
#define BC_MOTOCON_BTC_EOF_SIZE                ( 1 )
#define BC_MOTOCON_BTC_DATA_SIZE               ( BC_MOTOCON_BTC_HEADER_SIZE + BC_MOTOCON_AUTHENTICATION_DATA_SIZE + BC_MOTOCON_BTC_EOF_SIZE )

#define TEST_PASSKEY                           (const char []){ '9', '9', '9', '9', '9', '9' }

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
static void BC_motocon_authentication_received_btc_state( const bool connected, const uint8_t* bd_addr );
static void BC_motocon_authentication_received_btc_data( const uint8_t* data, const uint8_t length);

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/
static uint8_t authentication_string[BC_MOTOCON_BTC_DATA_SIZE];
static uint8_t* const ccuid_string = authentication_string + BC_MOTOCON_BTC_HEADER_SIZE + BC_MOTOCON_AUTHENTICATION_HEADER_SIZE;
static uint8_t* const passkey_string = ccuid_string + BC_MOTOCON_AUTHENTICATION_CCUID_SIZE;
static uint8_t btc_address[BT_DEVICE_ADDRESS_LEN];

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
/*********************************************************************
*
* @private
* bc_motocon_authentication_init
*
* Initial authentication
*
*********************************************************************/
void bc_motocon_authentication_init
    (
    void
    )
{
// -------------------------------------------------
// | Byte No | Length | Detail                     |
// -------------------------------------------------
// | 0       | 1      | SOH: 0x01                  |
// -------------------------------------------------
// | 1~4     | 4      | payload length: big endian |
// -------------------------------------------------
// | 5~5+n-1 | n      | payload                    |
// -------------------------------------------------
// | 5+n     | 1      | EOT: 0x04                  |
// -------------------------------------------------
authentication_string[0] = 1;
authentication_string[1] = 0;
authentication_string[2] = 0;
authentication_string[3] = 0;
authentication_string[4] = BC_MOTOCON_AUTHENTICATION_DATA_SIZE;
authentication_string[BC_MOTOCON_BTC_HEADER_SIZE] = BC_MOTOCON_COMMAND_CODE_CONNECT_INFORMATION_RESPONSE >> 8;
authentication_string[BC_MOTOCON_BTC_HEADER_SIZE +1] = BC_MOTOCON_COMMAND_CODE_CONNECT_INFORMATION_RESPONSE & 0xFF;
authentication_string[BC_MOTOCON_BTC_DATA_SIZE - 1] = 4;
BT_spp_add_connection_status_callback( BT_SPP_APP_MOTOCON, BC_motocon_authentication_received_btc_state );
BT_spp_add_data_received_callback( BT_SPP_APP_MOTOCON, BC_motocon_authentication_received_btc_data );
}

/*********************************************************************
*
* @private
* bc_motocon_authentication_set_data
*
* Reset authentication status
*
*********************************************************************/
void bc_motocon_authentication_set_data
    (
    const uint8_t* ccuid,
    const uint8_t* passkey
    )
{
memcpy( ccuid_string, ccuid, BC_MOTOCON_AUTHENTICATION_CCUID_SIZE);
memcpy( passkey_string, passkey, BC_MOTOCON_AUTHENTICATION_PASSKEY_SIZE);
BC_MOTOCON_PRINTF( "%s: ccuid+passkey: %s\r\n", __FUNCTION__, ccuid_string );
}

/*********************************************************************
*
* @private
* bc_motocon_authentication_verify_data
*
* Reset authentication status
*
*********************************************************************/
bool bc_motocon_authentication_verify_data
    (
    const uint8_t* ccuid,
    const uint8_t* passkey
    )
{
const bool is_ccuid_current = ( memcmp( ccuid_string, ccuid, BC_MOTOCON_AUTHENTICATION_CCUID_SIZE ) == 0 );
const bool is_passkey_current = ( memcmp( passkey_string, passkey, BC_MOTOCON_AUTHENTICATION_PASSKEY_SIZE ) == 0 );
return is_ccuid_current && is_passkey_current;
}

/*********************************************************************
*
* @private
* bc_motocon_authentication_update_data
*
* Update authentication data
*
*********************************************************************/
void bc_motocon_authentication_update_data
    (
    void
    )
{
static bool already_got = false;
if( already_got )
    {
    return;
    }
bool result_ccuid = false;
bool result_passkey = false;
uint8_t* real_ccuid = NULL;
uint8_t* real_passkey = NULL;
result_ccuid = EW_get_unit_id_ccuid( &real_ccuid );
BC_MOTOCON_PRINTF( "%s: ccuid %d\r\n", __FUNCTION__, result_ccuid );
result_passkey = EW_get_unit_id_passkey( &real_passkey );
BC_MOTOCON_PRINTF( "%s: passkey %d\r\n", __FUNCTION__, result_passkey );
bc_motocon_authentication_set_data( result_ccuid ? real_ccuid : (uint8_t*)TEST_CCUID, result_passkey ? real_passkey : (uint8_t*)TEST_PASSKEY );
already_got = true;
}

/*********************************************************************
*
* @public
* BC_motocon_authentication_received_btc_state
*
* Handle btc state.
*
*********************************************************************/
void BC_motocon_authentication_received_btc_state
    (
    const bool     connected,
    const uint8_t* bd_addr
    )
{
if( connected )
    {
    memcpy( btc_address, bd_addr, BT_DEVICE_ADDRESS_LEN );
    }
}

/*********************************************************************
*
* @public
* BC_motocon_authentication_received_btc_data
*
* Handle btc data.
*
*********************************************************************/
void BC_motocon_authentication_received_btc_data
    (
    const uint8_t* data,
    const uint8_t  length
    )
{
//TODO: check btc header is correct?
const bc_motocon_command_code_t command_code = TWO_BYTE_BIG( data, BC_MOTOCON_BTC_HEADER_SIZE );
switch( command_code )
    {
    case BC_MOTOCON_COMMAND_CODE_CONNECT_INFORMATION_REQUEST:
        bc_motocon_authentication_update_data();
        BT_spp_send_data( btc_address, BT_SPP_APP_MOTOCON, authentication_string, BC_MOTOCON_BTC_DATA_SIZE );
        break;
    default:
        bc_motocon_parse_error_handler( command_code, BC_MOTOCON_PARSE_INVALID_COMMAND_CODE, "" );
        break;
    }
}
