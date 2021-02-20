/*--------------------------------------------------------------------
* @file client_mem.c
* @brief client memory management
*
* This file shall storage and package the received data
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
---------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                            GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "client_mem.h"
#include "client_dcm_appl.h"
#include "BC_motocon_pub.h"

/*--------------------------------------------------------------------
                                 MACROS
--------------------------------------------------------------------*/
#define INIT_DTC_DATA_MAX_CONUT           (238)
#define INDENTIFIER_DATA_MAX_COUNT        (10000)
#define CHANNELS_COUNT                    (SUPPORT_SERVER_NUM)
/*--------------------------------------------------------------------
                            VARIABLES
--------------------------------------------------------------------*/
uint8 client_mem_init_dtc_data_array[CHANNELS_COUNT][INIT_DTC_DATA_MAX_CONUT] = {0};
uint8 client_mem_indentifier_data_array[INDENTIFIER_DATA_MAX_COUNT] = {0};
client_mem_management_info_type client_mem_read_init_dtc_data[CHANNELS_COUNT] = {0};
client_mem_management_info_type client_mem_indentifier_data = {0};


/*-------------------------------------------------------------------
*                    function declaration
---------------------------------------------------------------------*/
/*!******************************************************************************
*
* @public
* Function name: client_mem_init
* Description  : initial the module
*********************************************************************************/
void client_mem_init
    (
    void
    )
{
uint8 index = 0;
for( ; index < CHANNELS_COUNT; index++)
    {
    client_mem_read_init_dtc_data[index].length = 0x0000;
    client_mem_read_init_dtc_data[index].empty_flag = TRUE;
    client_mem_read_init_dtc_data[index].overflow_flag = FALSE;
    client_mem_read_init_dtc_data[index].mem_data = client_mem_init_dtc_data_array[index];
    }

client_mem_indentifier_data.empty_flag = TRUE;
client_mem_indentifier_data.overflow_flag = FALSE;
client_mem_indentifier_data.length = 0x02;
client_mem_indentifier_data.mem_data = client_mem_indentifier_data_array;
}

/*!******************************************************************************
*
* @public
* Function name: client_mem_data_cpy
* Description  : data copy
*********************************************************************************/
void client_mem_data_cpy
    (
    uint8* dest,
    uint8* src,
    uint16 cnt
    )
{
uint16 i;
for( i = 0; i < cnt; i++ )
    {
    *(dest + i) = *(src + i);
    }
}


/*!******************************************************************************
*
* @public
* Function name: client_mem_storage_init_dtc_data
* Description  : storage the received initial data
*********************************************************************************/
client_ReturnType client_mem_storage_init_dtc_data
    (
    uint8 channel_id,
    uint16 data_lenth,
    uint8* storage_data
    )
{
uint16 empty_length = 0x0000;

if( 0x0000 == data_lenth )
    {
    return E_NOT_OK;
    }

if( TRUE == client_mem_read_init_dtc_data[channel_id].overflow_flag )
    {
    return E_NOT_OK;
    }
else if( INIT_DTC_DATA_MAX_CONUT <= data_lenth + client_mem_read_init_dtc_data[channel_id].length )
    {
    client_mem_read_init_dtc_data[channel_id].overflow_flag = TRUE;
    empty_length = INIT_DTC_DATA_MAX_CONUT - client_mem_read_init_dtc_data[channel_id].length;
    client_mem_data_cpy( &client_mem_read_init_dtc_data[channel_id].mem_data[client_mem_read_init_dtc_data[channel_id].length], storage_data, empty_length );
    client_mem_read_init_dtc_data[channel_id].length = INIT_DTC_DATA_MAX_CONUT;
    }
else
    {
    client_mem_data_cpy( &client_mem_read_init_dtc_data[channel_id].mem_data[client_mem_read_init_dtc_data[channel_id].length], storage_data, data_lenth );
    client_mem_read_init_dtc_data[channel_id].length += data_lenth;
    }

if( 0x0000 < client_mem_read_init_dtc_data[channel_id].length )
    {
    client_mem_read_init_dtc_data[channel_id].empty_flag = FALSE;
    }
//PRINTF("current storage initial length %d \r\n", client_mem_read_init_dtc_data[channel_id].length );

return E_OK;
}

/*!******************************************************************************
*
* @public
* Function name: client_mem_get_storage_init_dtc_state
* Description  : get the initial DTC data storage state
*********************************************************************************/
boolean client_mem_get_storage_init_dtc_state
    (
    uint8 channel_id
    )
{
return FALSE == client_mem_read_init_dtc_data[channel_id].empty_flag?TRUE:FALSE;
}



#if( MEM_DEBUG )
/*!******************************************************************************
*
* @public
* Function name: client_mem_print_init_dtc_data
* Description  : print the received data
*********************************************************************************/
client_ReturnType client_mem_print_init_dtc_data
    (
    void
    )
{
uint8 temp = 0;
uint16 index = 0;

for( ; temp < CHANNELS_COUNT; temp++ )
    {
    if( TRUE == client_mem_read_init_dtc_data[temp].empty_flag )
        {
        PRINTF( "Channel %d is empty for init dtc\r\n", temp );
        continue;
        }
    else if( TRUE == client_mem_read_init_dtc_data[temp].overflow_flag )
        {
        PRINTF( "Channel %d Received data over flow for init dtc\r\n", temp );
        }
    else
        {
        /*do nothing*/
        }

    PRINTF("Receive %d byte data for init dtc:", client_mem_read_init_dtc_data[temp].length );
    for( index = 0; index < client_mem_read_init_dtc_data[temp].length; index++ )
        {
        PRINTF( "%2x ",client_mem_init_dtc_data_array[temp][index] );
        }
        PRINTF( "\r\n" );
    }
return E_OK;
}
#endif



/*!******************************************************************************
*
* @public
* Function name: client_mem_get_init_dtc_data
* Description  : response initial DTC data
*********************************************************************************/
client_ReturnType client_mem_get_init_dtc_data
    (
    uint8 channel_id,
    client_mem_result_type* result,
    uint16* resp_length,
    uint8** resp_data
    )
{
if( TRUE == client_mem_read_init_dtc_data[channel_id].empty_flag)
    {
    *result = CLIENT_MEM_EMPTY;
    *resp_length = 0x0000;
    resp_data = 0;/*pointer*/
    return E_NOT_OK;
    }
else if( TRUE == client_mem_read_init_dtc_data[channel_id].overflow_flag )
    {
    *result = CLIENT_MEM_OVERFLOW;
    }
else
    {
    *result = CLIENT_MEM_NORMAL;
    }

*resp_length = client_mem_read_init_dtc_data[channel_id].length;
*resp_data =  client_mem_read_init_dtc_data[channel_id].mem_data;

return E_OK;
}

void client_mem_storage_server_code
    (
    uint16 server_code
    )
{
client_mem_indentifier_data.mem_data[0] = (uint8)( server_code >> 8 );
client_mem_indentifier_data.mem_data[1] = (uint8)server_code;
}
/*!******************************************************************************
*
* @public
* Function name: client_mem_storage_identifier_data
* Description  : storage the received data
*********************************************************************************/
client_ReturnType client_mem_storage_identifier_data
    (
    uint8 channel_id,
    uint16 data_lenth,
    uint8* storage_data
    )
{
uint16 empty_length = 0x0000;

if( 0x0000 == data_lenth )
    {
    return E_NOT_OK;
    }

if( TRUE == client_mem_indentifier_data.overflow_flag )
    {
    return E_NOT_OK;
    }
else if( INDENTIFIER_DATA_MAX_COUNT <= data_lenth + client_mem_indentifier_data.length )
    {
    client_mem_indentifier_data.overflow_flag = TRUE;
    empty_length = INDENTIFIER_DATA_MAX_COUNT - client_mem_indentifier_data.length;
    client_mem_data_cpy( &client_mem_indentifier_data.mem_data[client_mem_indentifier_data.length], storage_data, empty_length );
    client_mem_indentifier_data.length = INDENTIFIER_DATA_MAX_COUNT;
    }
else
    {
    client_mem_data_cpy( &client_mem_indentifier_data.mem_data[client_mem_indentifier_data.length], storage_data, data_lenth );
    client_mem_indentifier_data.length += data_lenth;
    }

if( 0x0000 < client_mem_indentifier_data.length )
    {
    client_mem_indentifier_data.empty_flag = FALSE;
    }
PRINTF("current storage length %d \r\n", client_mem_indentifier_data.length );

return E_OK;
}
/*!******************************************************************************
*
* @public
* Function name: client_mem_get_identifier_data
* Description  : response storage data
*********************************************************************************/
client_mem_result_type client_mem_get_identifier_data
    (
    uint16* resp_length,
    uint8** resp_data
    )
{
client_mem_result_type result = CLIENT_MEM_INIT;

if( TRUE == client_mem_indentifier_data.empty_flag)
    {
    result = CLIENT_MEM_EMPTY;
    *resp_length = 0x0000;
    //*resp_data = 0;/*pointer*/
    return result;
    }
else if( TRUE == client_mem_indentifier_data.overflow_flag )
    {
    result = CLIENT_MEM_OVERFLOW;
    }
else
    {
    result = CLIENT_MEM_NORMAL;
    }

*resp_length = client_mem_indentifier_data.length;
*resp_data = client_mem_indentifier_data.mem_data;

return E_OK;
}

 /*!******************************************************************************
 *
 * @public
 * Function name:
 * Description  :
 *********************************************************************************/
 client_ReturnType client_mem_send_can_related_data
     (
     const uint16 command,
     const uint32 size,
     const uint8* data
     )
 {
 client_ReturnType return_value = 1;

 uint32 index = 0;
 switch( command )
     {
     case 0x010B:
     PRINTF("Read Comman data %d byte \r\n", size);
     }

 for(; index < size; )
     {
     PRINTF("%X ", data[index]);
     index++;
     if( 0 == (index % 30))
         {
         PRINTF("\r\n");
         }
     }
 PRINTF("\r\nsend data end \r\n");

 BC_motocon_send_can_related_data( command, size, data, &client_appl_cmd_rsp_result_notify );
 return return_value;
 }

 /*!******************************************************************************
 *
 * @public
 * Function name:client_mem_send_can_data
 * Description  : send the storage data to MOTOCAN
 *********************************************************************************/
 client_ReturnType client_mem_send_can_data
    (
    void
    )
{
client_ReturnType return_value = 0x00;
uint8 channel_id = 0x00;
uint16 resp_len = 0x0000;
uint8* resp_data = 0x00;
uint32 resp_cmd = 0;
client_process_flow_type current_flow = client_get_current_process_flow();

switch( current_flow )
    {
    case PROCESS_FLOW_RDBCID:
        resp_cmd = BLE_RSP_CMD_VEHICLE_IDENTIFICATION;
    case PROCESS_FLOW_MARKET:
        resp_cmd = BLE_RSP_CMD_MARKET_DATA;
    case PROCESS_FLOW_MONITOR:
        resp_cmd = BLE_RSP_CMD_VEHICLE_INFORMATION;
    case PROCESS_FLOW_RFFD:
        resp_cmd = BLE_RSP_CMD_FFD;
        (void)client_mem_get_identifier_data( &resp_len, &resp_data );
        return_value = client_mem_send_can_related_data( resp_cmd,(uint32)resp_len, resp_data );
        break;

    case PROCESS_FLOW_INIT_RDTCBS:
    if( client_appl_get_storage_init_dtc_state() )
        {
        (void)client_mem_get_identifier_data( &resp_len, &resp_data );
        }
    else
        {
        channel_id = client_appl_get_current_connected_server_id();
        resp_len = client_mem_read_init_dtc_data[channel_id].length;
        resp_data = client_mem_read_init_dtc_data[channel_id].mem_data;
        }
    return_value = client_mem_send_can_related_data( BLE_RSP_CMD_MALFUNCTION, (uint32)resp_len, resp_data );
    break;

    default:
    break;
    }
return return_value;
}

/*!******************************************************************************
*
* @public
* Function name: client_mem_reset_data
* Description  : clear the storage data and reset state
*********************************************************************************/
client_ReturnType client_mem_reset_data
    (
    void
    )
{
(void)memset( client_mem_indentifier_data.mem_data, 0x00, client_mem_indentifier_data.length );
client_mem_indentifier_data.empty_flag = TRUE;
client_mem_indentifier_data.length = 0x02;
client_mem_indentifier_data.overflow_flag = FALSE;
return E_OK;
}




