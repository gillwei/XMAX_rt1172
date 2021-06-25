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
#include "HCI_pub.h"
#include "bt_spp_iap2.h"

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

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
static void BC_motocon_authentication_received_btc_data( const uint8_t* data, const uint16_t length);

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
HCI_spp_iap2_add_data_callback_y_app( BC_motocon_authentication_received_btc_data );
// set temp key
uint8_t passkey[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };
bc_motocon_authentication_set_data( (uint8_t*)TEST_CCUID, passkey );
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
* @public
* BC_motocon_authentication_received_btc_data
*
* Handle btc data.
*
*********************************************************************/
void BC_motocon_authentication_received_btc_data
    (
    const uint8_t* data,
    const uint16_t length
    )
{
//TODO: check btc header is correct?
const bc_motocon_command_code_t command_code = TWO_BYTE_BIG( data, BC_MOTOCON_BTC_HEADER_SIZE );
switch( command_code )
    {
    case BC_MOTOCON_COMMAND_CODE_CONNECT_INFORMATION_REQUEST:
        BT_SPP_IAP2_send_y_app( BC_MOTOCON_BTC_DATA_SIZE, authentication_string );
        break;
    default:
        bc_motocon_parse_error_handler( command_code, BC_MOTOCON_PARSE_INVALID_COMMAND_CODE, "" );
        break;
    }
}