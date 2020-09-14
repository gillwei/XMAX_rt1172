/*********************************************************************
* @file
* bt_spp_iap2.c
*
* @brief
* Bluetooth SPP profile and iAP2 profile send data API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#include "BTM_pub.h"
#include "hci_prv.h"
#include "HCI_pub.h"
#include "hci_control_api.h"
#include "fsl_debug_console.h"

/*********************************************************************
 *
 * @public
 * BT_SPP_send
 *
 * Get BT SPP connection handle and send to remote device
 *
 * @input data_length Send data length
 * @input transfer_data uint8 pointer of send data
********************************************************************/
bool BT_SPP_send
    (
    uint8_t  data_length,
    uint8_t* transfer_data
    )
{
uint8_t    transfer_spp_data[HCI_MAX_DATA_SIZE];
bool       bt_connection_status;
uint16_t   bt_connection_handle;

BTM_get_connection_info( &bt_connection_status, &bt_connection_handle );
PRINTF( "%s handle:%04x connection status:%d\n\r", __FUNCTION__, bt_connection_handle, bt_connection_status );
if( ( data_length > ( HCI_MAX_DATA_SIZE - 2 ) ) || ( bt_connection_status != true ) )
    {
    return false;
    }
transfer_spp_data[0] = (uint8_t)bt_connection_handle;
transfer_spp_data[1] = (uint8_t)( bt_connection_handle >> 8 );
memcpy( &(transfer_spp_data[2]), transfer_data, data_length );

if( HCI_wiced_send_command( HCI_CONTROL_SPP_COMMAND_DATA, transfer_spp_data, data_length + 2 ) )
    return true;
else
    return false;
}

/*********************************************************************
 *
 * @public
 * BT_IAP2_send
 *
 * Get BT iAP2 connection handle and send to remote device
 *
 * @input data_length Send data length
 * @input transfer_data uint8 pointer of send data
********************************************************************/
bool BT_IAP2_send
    (
    uint8_t  data_length,
    uint8_t* transfer_data
    )
{
uint8_t   transfer_iap2_data[HCI_MAX_DATA_SIZE];
bool      bt_connection_status;
uint16_t  bt_connection_handle;

BTM_get_connection_info( &bt_connection_status, &bt_connection_handle );
PRINTF( "%s handle:%04x connection status:%d\n\r", __FUNCTION__, bt_connection_handle, bt_connection_status );
if( ( data_length > ( HCI_MAX_DATA_SIZE - 2 ) ) || ( bt_connection_status != true ) )
    {
    return false;
    }
transfer_iap2_data[0] = (uint8_t)bt_connection_handle;
transfer_iap2_data[1] = (uint8_t)( bt_connection_handle >> 8 );
memcpy( &(transfer_iap2_data[2]), transfer_data, data_length );

if( HCI_wiced_send_command( HCI_CONTROL_IAP2_COMMAND_DATA, transfer_iap2_data, data_length + 2  ) )
    return true;
else
    return false;
}
