/*!*******************************************************************
* @file client_ble_cmd.h
* @brief client diagnostic ble command queque handle
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef _CLIENT_BLE_CMD_H_
#define _CLIENT_BLE_CMD_H_


/*--------------------------------------------------------------------
                            GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "can_defs.h"
/*--------------------------------------------------------------------
                            MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                            TYPES
--------------------------------------------------------------------*/
typedef struct
{
uint16 ble_command;
uint32 data_length;
uint8* command_data;
}ble_command_type;

/*--------------------------------------------------------------------
                            VARIABLES
--------------------------------------------------------------------*/


/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/
extern void client_ble_cmd_init
    (
    void
    );

ble_command_type* client_ble_cmd_pull_queue
    (
    void
    );

extern void client_ble_cmd_enter_queue
    (
    uint16 command,
    uint32 data_size,
    uint8* data
    );
#endif