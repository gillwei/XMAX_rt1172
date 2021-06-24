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

#define IAP2_SPP_SEND_TRACE_ENABLE  0

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

BTM_get_connection_info( &bt_connection_status, &bt_connection_handle, BT_CONN_TYPE_BT_SPP );
#if IAP2_SPP_SEND_TRACE_ENABLE
    PRINTF( "%s handle:%04x connection status:%d\n\r", __FUNCTION__, bt_connection_handle, bt_connection_status );
#endif
if( ( data_length > ( HCI_MAX_DATA_SIZE - 2 ) ) || ( bt_connection_status != true ) )
    {
    PRINTF( "Send fail data length:%d bt_connection_status:%d\n\r", data_length, bt_connection_status );
    return false;
    }
transfer_spp_data[0] = (uint8_t)bt_connection_handle;
transfer_spp_data[1] = (uint8_t)( bt_connection_handle >> 8 );
memcpy( &(transfer_spp_data[2]), transfer_data, data_length );

if( pdPASS == HCI_wiced_send_command( HCI_CONTROL_SPP_COMMAND_DATA, transfer_spp_data, data_length + 2 ) )
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

BTM_get_connection_info( &bt_connection_status, &bt_connection_handle, BT_CONN_TYPE_BT_IAP2 );
#if IAP2_SPP_SEND_TRACE_ENABLE
PRINTF( "%s handle:%04x connection status:%d\n\r", __FUNCTION__, bt_connection_handle, bt_connection_status );
#endif
if( ( data_length > ( HCI_MAX_DATA_SIZE - 2 ) ) || ( bt_connection_status != true ) )
    {
    PRINTF( "Send fail data length:%d bt_connection_status:%d\n\r", data_length, bt_connection_status );
    return false;
    }
transfer_iap2_data[0] = (uint8_t)bt_connection_handle;
transfer_iap2_data[1] = (uint8_t)( bt_connection_handle >> 8 );
memcpy( &(transfer_iap2_data[2]), transfer_data, data_length );

if( pdPASS == HCI_wiced_send_command( HCI_CONTROL_IAP2_COMMAND_DATA, transfer_iap2_data, data_length + 2  ) )
    return true;
else
    return false;
}

/*********************************************************************
 *
 * @public
 * BT_SPP_IAP2_send_y_app
 *
 * Get BT SPP Y-connect APP connection handle and send data to APP
 *
 * @input data_length Send data length
 * @input transfer_data uint8 pointer of send data
********************************************************************/
bool BT_SPP_IAP2_send_y_app
    (
    uint8_t  data_length,
    uint8_t* transfer_data
    )
{
uint8_t   transfer_spp_data[HCI_MAX_DATA_SIZE];
bool      bt_connection_status;
uint16_t  bt_connection_handle;
bt_connection_path_type bt_connection_path;

BTM_get_connection_info( &bt_connection_status, &bt_connection_handle, BT_CONN_TYPE_BT_YAPP_SPP );
bt_connection_path = BTM_get_latest_connection_type();

#if IAP2_SPP_SEND_TRACE_ENABLE
PRINTF( "%s handle:%04x connection status:%d\n\r", __FUNCTION__, bt_connection_handle, bt_connection_status );
#endif
if( ( data_length > ( HCI_MAX_DATA_SIZE - 2 ) ) || ( bt_connection_status != true ) )
    {
    PRINTF( "Send fail data length:%d bt_connection_status:%d\n\r", data_length, bt_connection_status );
    return false;
    }
transfer_spp_data[0] = (uint8_t)bt_connection_handle;
transfer_spp_data[1] = (uint8_t)( bt_connection_handle >> 8 );
memcpy( &(transfer_spp_data[2]), transfer_data, data_length );

if( ( BT_CONN_TYPE_BT_SPP == bt_connection_path ) || ( BT_CONN_TYPE_BT_YAPP_SPP == bt_connection_path ) )
    {
    if( pdPASS == HCI_wiced_send_command( HCI_CONTROL_SPP_COMMAND_DATA, transfer_spp_data, data_length + 2  ) )
        return true;
    else
        return false;
    }
else if( ( BT_CONN_TYPE_BT_IAP2 == bt_connection_path ) || ( BT_CONN_TYPE_BT_YAPP_IAP2 == bt_connection_path ) )
    {
    if( pdPASS == HCI_wiced_send_command( HCI_CONTROL_IAP2_COMMAND_DATA, transfer_spp_data, data_length + 2  ) )
        return true;
    else
        return false;
    }
else
    {
    PRINTF( "ERROR: BT connection type unknown\r\n" );
    HCI_wiced_send_command( HCI_CONTROL_SPP_COMMAND_DATA, transfer_spp_data, data_length + 2  );
    HCI_wiced_send_command( HCI_CONTROL_IAP2_COMMAND_DATA, transfer_spp_data, data_length + 2  );
    }
return false;
}
