/*--------------------------------------------------------------------
* @file client_ble_cmd.c
* @brief client diagnostic ble command queque handle
*
* This file rx command and handle the command in a queque
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
---------------------------------------------------------------------*/


/*--------------------------------------------------------------------
                            GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "client_dcm_appl.h"
#include "client_ble_cmd.h"
#include "BC_motocon_pub.h"

/*--------------------------------------------------------------------
                            MACROS
--------------------------------------------------------------------*/

#define BLE_CMD_QUEUE_COUNT       (6)
#define BLE_CMD_DATA_MAX_LEN      (100)


/*--------------------------------------------------------------------
                            VARIABLES
--------------------------------------------------------------------*/
uint8 queue_data_zone[BLE_CMD_QUEUE_COUNT][BLE_CMD_DATA_MAX_LEN] = {0};
ble_command_type ble_command_queue[BLE_CMD_QUEUE_COUNT] = {0};
uint8 queue_front = 0x00;
uint8 queue_rear = 0x00;


/*-------------------------------------------------------------------
                     function declaration
---------------------------------------------------------------------*/

/*!*******************************************************************
* @public
* Function name: client_ble_cmd_init
* Description: initial module
*********************************************************************/
client_ble_cmd_init
    (
    void
    )
{
uint8 index = 0x00;

for( ; index < BLE_CMD_QUEUE_COUNT; index++ )
    {
    ble_command_queue[index].ble_command = 0;
    ble_command_queue[index].data_length = 0;
    ble_command_queue[index].command_data = &queue_data_zone[index];
    }
queue_front = 0;
queue_rear = 0;
}

/*!*******************************************************************
* @public
* Function name: queue_is_empty
* Description: judge the queue whether is empty
*********************************************************************/
boolean queue_is_empty
    (
    void
    )
{
if( queue_front == queue_rear )
    {
    return TRUE;
    }
else
    {
    return FALSE;
    }
}

/*!*******************************************************************
* @public
* Function name: queue_is_full
* Description: judge the queue whether is full
*********************************************************************/
boolean queue_is_full
    (
    void
    )
{
if( queue_front == ( ( queue_rear + 1 ) % BLE_CMD_QUEUE_COUNT ) )
    {
    return TRUE;
    }
else
    {
    return FALSE;
    }
}

/*!*******************************************************************
* @public
* Function name: client_ble_cmd_data_cpy
* Description:   this function implement memory data copy function
*********************************************************************/
static void client_ble_cmd_data_cpy
    (
    uint8* dest,
    uint8* src,
    uint32 cnt
    )
{
uint32 i;
for( i = 0; i < cnt; i++ )
    {
    *( dest + i ) = *( src + i );
    }
}

/*!*******************************************************************
* @public
* Function name: client_ble_cmd_enter_queue
* Description:   this function enter a new coammand into queque
* Note: interface to upper layer
*********************************************************************/
void client_ble_cmd_enter_queue
    (
    uint16 command,
    uint32 data_size,
    uint8* data
    )
{
uint32 data_len = 0;

/*Discard new command when queue is full*/
if( queue_is_full() )
    {
    return;
    }

ble_command_queue[queue_rear].ble_command = command;
ble_command_queue[queue_rear].data_length = data_size;

if( data_size > BLE_CMD_DATA_MAX_LEN )
    {
    data_len = BLE_CMD_DATA_MAX_LEN;
    }
else
    {
    data_len = data_size;
    }
client_ble_cmd_data_cpy( ble_command_queue[queue_rear].command_data, data, data_len );

queue_rear++;
if( BLE_CMD_QUEUE_COUNT == queue_rear )
    {
    queue_rear = 0;
    }
}

/*!*******************************************************************
* @public
* Function name: client_ble_cmd_pull_queue
* Description:   this function get a new coammand from queque
* Note: periodly callback
*********************************************************************/
ble_command_type* client_ble_cmd_pull_queue
    (
    void
    )
{
ble_command_type* return_ptr = NULL;

if( queue_is_empty())
    {
    return NULL;
    }

return_ptr = &ble_command_queue[queue_front];

queue_front++;
if( BLE_CMD_QUEUE_COUNT == queue_front )
    {
    queue_front = 0;
    }

return return_ptr;
}
