/*********************************************************************
* @file  hci_bt_event_handler.c
* @brief Handles WICED HCI received events
*
* This file includes the functions that handle the received BT WICED
* HCI events
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <stdio.h>
#include "FreeRTOS.h"
#include "hci_control_api.h"
#include "hci_control_api_extend.h"
#include "fsl_debug_console.h"
#include "BTM_pub.h"
#include "hci_prv.h"
#include "HCI_pub.h"
#include "BT_UPDATE_pub.h"
#include "EW_pub.h"
#include "factory_test.h"
#include "task.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define AUTH_CHIP_VER_LENGTH  8
#define AUTH_CHIP_VER_ARRY (const uint8_t [])  { 0x07, 0x01, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00 }

#define PAIR_DEV_LIST_TOTAL_NUM_BYTE 0
#define PAIR_DEV_LIST_INDEX_BYTE     1

#define SPP_IAP2_DATA_CB_MAX_NUM     3

/*--------------------------------------------------------------------
                                TYPES
--------------------------------------------------------------------*/
/** MFI chip return result */
typedef enum
    {
    AUTH_CHIP_RETURN_FAIL,
    AUTH_CHIP_RETURN_SUCCESS
    } auth_chip_return_result_t;

/*--------------------------------------------------------------------
                            VARIABLES
--------------------------------------------------------------------*/
static bool pair_list_update_status = false;
static spp_iap2_data_callback spp_iap2_data_cb_array[BT_INFO_CB_MAX_NUM]; /* spp iap2 data callback array */

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @private
* hci_misc_event_handler
*
* Handle BT MISC and vendor specific events
*
* @param opcode    operation code
* @param p_data    uint8 data pointer
* @param data_len  data length
*
*********************************************************************/
void hci_misc_event_handler
    (
    const uint16_t opcode,
    const uint8_t* p_data,
    const uint32_t data_len
    )
{
uint8_t    Return_bt_sw_ver[2];
uint8_t    pair_dev_index[1] = { 0 };

uint8_t    Read_BT_version[2] = { 0 };

bt_update_get_BT_SW_ver( Read_BT_version );

switch( opcode )
    {
    case HCI_CONTROL_MISC_EVENT_SW_VERSION:
        if( INIT_STATE_REQUEST_VERSION == getBTInitUpdateState() )
            {
            setBTInitUpdateState( INIT_STATE_GET_VERSION );
            Return_bt_sw_ver[BT_SW_MAJOR_VER_BYTE] = p_data[0];
            Return_bt_sw_ver[BT_SW_MINOR_VER_BYTE] = p_data[1];
            BTM_update_sw_version( Return_bt_sw_ver );
            /* Read BT FW version on MCU flash is not correct */
            if( ( ( 0xff == Read_BT_version[BT_SW_MAJOR_VER_BYTE] ) && ( 0xff == Read_BT_version[BT_SW_MINOR_VER_BYTE] ) ) || ( ( 0 == Read_BT_version[BT_SW_MAJOR_VER_BYTE] ) && ( 0 == Read_BT_version[BT_SW_MINOR_VER_BYTE] ) ) )
                {
                PRINTF( "Read BT version ERROR: %02x.%02x\r\n", Read_BT_version[BT_SW_MAJOR_VER_BYTE], Read_BT_version[BT_SW_MINOR_VER_BYTE] );
                HCI_wiced_send_command( HCI_CONTROL_MISC_COMMAND_READ_PAIR_DEV_LIST, pair_dev_index, sizeof( pair_dev_index ) );
                }
            /* BT module return version is lower than BT FW version on MCU flash, do BT update */
            else if( ( Return_bt_sw_ver[BT_SW_MAJOR_VER_BYTE] < Read_BT_version[BT_SW_MAJOR_VER_BYTE] ) || ( ( Read_BT_version[BT_SW_MAJOR_VER_BYTE] == Return_bt_sw_ver[BT_SW_MAJOR_VER_BYTE] ) && ( Read_BT_version[BT_SW_MINOR_VER_BYTE] > Return_bt_sw_ver[BT_SW_MINOR_VER_BYTE] ) ) )
                {
                PRINTF( "Current BT FW is older than MCU BT version:%d.%d. BT update\n\r", Return_bt_sw_ver[BT_SW_MAJOR_VER_BYTE], Return_bt_sw_ver[BT_SW_MINOR_VER_BYTE] );
                BT_UPDATE_received();
                }
            /* BT module return version is equal or higher than BT FW version on MCU flash, not update */
            else
                {
                PRINTF( "BT FW version is equal or higher:%d.%d.\n\r", Return_bt_sw_ver[BT_SW_MAJOR_VER_BYTE], Return_bt_sw_ver[BT_SW_MINOR_VER_BYTE] );
                HCI_wiced_send_command( HCI_CONTROL_MISC_COMMAND_READ_PAIR_DEV_LIST, pair_dev_index, sizeof( pair_dev_index ) );
                }
            }
        break;

    case HCI_CONTROL_MISC_EVENT_READ_PAIR_INFO:
        if( false == pair_list_update_status )
            {
            BTM_pairing_info_update( p_data[0], &( p_data[1] ) );
            }
        break;

    case HCI_CONTROL_MISC_EVENT_READ_PAIR_DEV_LIST:
        if( 0 == p_data[PAIR_DEV_LIST_INDEX_BYTE] )
            {
            pair_list_update_status = true;
            }

        /* Sequentially send pair device information to BT manager update pair dev number when
         * every time receive one pair information until the pair device index is maximum.
         */
        if( p_data[PAIR_DEV_LIST_TOTAL_NUM_BYTE] > ( p_data[PAIR_DEV_LIST_INDEX_BYTE] + 1 ) )
            {
            BTM_pairing_info_update( p_data[PAIR_DEV_LIST_INDEX_BYTE], &( p_data[PAIR_DEV_LIST_INDEX_BYTE + 1] ) );
            pair_dev_index[0] = p_data[PAIR_DEV_LIST_INDEX_BYTE] + 1;
            HCI_wiced_send_command( HCI_CONTROL_MISC_COMMAND_READ_PAIR_DEV_LIST, pair_dev_index, sizeof( pair_dev_index ) );
            }
        /* Pair list information update finished */
        else if( p_data[PAIR_DEV_LIST_TOTAL_NUM_BYTE] == ( p_data[PAIR_DEV_LIST_INDEX_BYTE] + 1 ) )
            {
            BTM_pairing_info_update( p_data[PAIR_DEV_LIST_INDEX_BYTE], &( p_data[PAIR_DEV_LIST_INDEX_BYTE + 1] ) );
            /* pair list update finished */
            pair_list_update_status = false;
            BTM_init_autoconnect();
            }
        break;

    case HCI_CONTROL_MISC_EVENT_USER_CONFIRM_RESULT:
       BTM_receive_user_confirm_evt( p_data, data_len );
       break;

    case HCI_CONTROL_MISC_EVENT_ADDR_PAIR_FAIL:
        BTM_receive_btc_paired_fail( p_data, data_len );
       break;

    default:
        break;
    }
}

/*********************************************************************
*
* @private
* hci_device_event_handler
*
* Handle BT device events
*
* @param opcode    operation code
* @param p_data    uint8 data pointer
* @param data_len  data length
*
*********************************************************************/
void hci_device_event_handler
    (
    const uint16_t cmd_opcode,
    const uint8_t* p_data,
    const uint32_t data_len
    )
{
switch( cmd_opcode )
    {
    case HCI_CONTROL_EVENT_READ_LOCAL_BDA:
        PRINTF( "BD addr: %02x:%02x:%02x:%02x:%02x:%02x\n\r",
                 (int)p_data[5], (int)p_data[4], (int)p_data[3], (int)p_data[2], (int)p_data[1], (int)p_data[0] );
        BTM_set_local_device_address( (uint8_t *)p_data );
        sent_iop_bd_address();
        break;

    case HCI_CONTROL_EVENT_DEVICE_STARTED:
        PRINTF( "Receive BT device start event\r\n" );
        break;

    case HCI_CONTROL_EVENT_PAIRING_COMPLETE:
       PRINTF( "Receive BT or BLE pairing complete event\r\n" );
       BTM_receive_pairing_clt_evt( p_data, data_len );
       break;

    case HCI_CONTROL_EVENT_CONNECTION_STATUS:
       BTM_receive_connection_status( p_data, data_len );
       break;

    default:
            break;

    }
}

/*********************************************************************
*
* @private
* hci_spp_event_handler
*
* Handle BT serial port protocol events
*
* @param opcode    operation code
* @param p_data    uint8 data pointer
* @param data_len  data length
*
*********************************************************************/
void hci_spp_event_handler
    (
    const uint16_t cmd_opcode,
    const uint8_t* p_data,
    const uint32_t data_len
    )
{
bool    connection_is_up = false;
uint8_t bd_addr_rev[BT_DEVICE_ADDRESS_LEN] = { 0 };

switch( cmd_opcode )
    {
    case HCI_CONTROL_SPP_EVENT_RX_DATA:
        // fire callbacks defined by users
        for( int i = 0; i < SPP_IAP2_DATA_CB_MAX_NUM; i++ )
            {
            if( spp_iap2_data_cb_array[i] != NULL )
                {
                ( spp_iap2_data_cb_array[i] )( (uint8_t *)p_data, (uint32_t)data_len );
                }
            }
        break;

    case HCI_CONTROL_SPP_EVENT_CONNECTED:
        connection_is_up = true;
        BTM_notify_EW_connection_status( BT_CONNECTION_SUCCESS );
        BTM_BTC_spp_connected( connection_is_up, data_len, &( p_data[0] ), BT_CONN_TYPE_BT_SPP );
        break;

    case HCI_CONTROL_SPP_EVENT_DISCONNECTED:
        connection_is_up = false;
        BTM_BTC_spp_connected( connection_is_up, data_len, &( p_data[0] ), BT_CONN_TYPE_BT_SPP );
        break;

    case HCI_CONTROL_SPP_EVENT_CONNECTION_FAILED:
        BTM_get_connect_request_bd_addrress_rev( bd_addr_rev );
        HCI_wiced_send_command( HCI_CONTROL_IAP2_COMMAND_CONNECT, bd_addr_rev, BT_DEVICE_ADDRESS_LEN );
        break;

    case HCI_CONTROL_SPP_EVENT_SERVICE_NOT_FOUND:
        BTM_get_connect_request_bd_addrress_rev( bd_addr_rev );
        HCI_wiced_send_command( HCI_CONTROL_IAP2_COMMAND_CONNECT, bd_addr_rev, BT_DEVICE_ADDRESS_LEN );
        break;

    default:
        break;
    }
}

/*********************************************************************
*
* @private
* hci_iap2_event_handler
*
* Handle BT iAP2 events
*
* @param opcode    operation code
* @param p_data    uint8 data pointer
* @param data_len  data length
*
*********************************************************************/
void hci_iap2_event_handler
    (
    const uint16_t cmd_opcode,
    const uint8_t* p_data,
    const uint32_t data_len
    )
{
bool connection_is_up = false;
auth_chip_return_result_t auth_ver_result = AUTH_CHIP_RETURN_FAIL;

switch( cmd_opcode )
    {
    case HCI_CONTROL_IAP2_EVENT_RX_DATA:
        // fire callbacks defined by users
        for( int i = 0; i < SPP_IAP2_DATA_CB_MAX_NUM; i++ )
            {
            if( spp_iap2_data_cb_array[i] != NULL )
                {
                ( spp_iap2_data_cb_array[i] )( (uint8_t *)p_data, (uint32_t)data_len );
                }
            }
        break;

    case HCI_CONTROL_IAP2_EVENT_CONNECTED:
        connection_is_up = true;
        BTM_notify_EW_connection_status( BT_CONNECTION_SUCCESS );
        BTM_BTC_spp_connected( connection_is_up, data_len, &( p_data[0] ), BT_CONN_TYPE_BT_IAP2 );
        break;

    case HCI_CONTROL_IAP2_EVENT_DISCONNECTED:
        connection_is_up = false;
        BTM_BTC_spp_connected( connection_is_up, data_len, &( p_data[0] ), BT_CONN_TYPE_BT_IAP2 );
        break;

    case HCI_CONTROL_IAP2_EVENT_CONNECTION_FAILED:
        BTM_notify_EW_connection_status( BT_CONNECTION_FAIL );
        break;

    case HCI_CONTROL_IAP2_EVENT_SERVICE_NOT_FOUND:
        BTM_notify_EW_connection_status( BT_CONNECTION_FAIL );
        break;

    case HCI_CONTROL_IAP2_EVENT_AUTH_CHIP_INFO:
        if( 0 == memcmp( AUTH_CHIP_VER_ARRY, p_data, AUTH_CHIP_VER_LENGTH ) )
            {
            auth_ver_result = AUTH_CHIP_RETURN_SUCCESS;
            }
        else
            {
            auth_ver_result = AUTH_CHIP_RETURN_FAIL;
            PRINTF( "ERROR: chip version compare fail\r\n" );
            }
        hci_wait_for_resp_stop();
        receive_auth_chip_ver( auth_ver_result );
        break;
    default:
        break;
    }
}

/*********************************************************************
*
* @public
* HCI_spp_iap2_add_data_callback
*
* Register the spp or iap2 receive data callback function
*
* @param callback The pointer of the callback struct of spp_iap2_data_callback
*
*********************************************************************/
bool HCI_spp_iap2_add_data_callback
    (
    spp_iap2_data_callback data_callback
    )
{
int i = 0;

for( i = 0; i < SPP_IAP2_DATA_CB_MAX_NUM; i++ )
    {
    // check if there exists same callback, if yes, return false
    if( spp_iap2_data_cb_array[i] == data_callback )
        {
        PRINTF( "This spp iap2 data callback already added! skip\r\n" );
        return false;
        }
    // if no, find a free slot to add this callback
    else if( spp_iap2_data_cb_array[i] == NULL )
        {
        PRINTF( "This spp iap2 data callback added successfuly!\r\n" );
        spp_iap2_data_cb_array[i] = data_callback;
        return true;
        }
    }

PRINTF( "not able to add spp iap2 data callback!" );
return false;
}
