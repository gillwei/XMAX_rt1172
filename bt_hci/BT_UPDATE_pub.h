/*********************************************************************
* @file
* BT_UPDATE_pub.h
*
* @brief
* BT HCI updater - public API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifndef BT_UPDATE_PUB_H
#define BT_UPDATE_PUB_H

#ifdef __cplusplus
extern "C" {
#endif

#include "FreeRTOS.h"
#include "HCI_pub.h"

/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/
BaseType_t BT_UPDATE_standard_send_command
    (
    const uint16_t command,
    const uint8_t* payload,
    const uint8_t  len
    );

void BT_UPDATE_received
    (
    void
    );

void BT_UPDATE_setParserStatus
    (
    bt_parser_t config_parser_status
    );

bool BT_UPDATE_get_BT_update_status
    (
    void
    );

#ifdef __cplusplus
}
#endif

#endif /* BT_UPDATE_PUB_H */
