/*******************************************************************************
*@ File HCI_pub.h
*@ Brief HCI driver public header file
*
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
********************************************************************************/
#ifndef HCI_PUB_H
#define HCI_PUB_H

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "fsl_common.h"
#include "PERIPHERAL_pub.h"

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define OPCODE_RESET             0x0C03
#define OPCODE_COMMIT_ADDR       0xFC10
#define COMMON_CMD_WAIT_MS       30
#define BT_MIN_WAIT_DELAY        50
#define BT_RESET_RECONFIG_DELAY  100
#define BT_RESET_GPIO_DELAY      50
#define BT_AFTER_RESET_DELAY     1000

/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/
typedef enum tagBT_PARSER_TYPE                  //!< HCI receive state machine states
    {
    PARSER_WICED_HCI,
    PARSER_STANDARD_HCI
    } bt_parser_t;

typedef enum
    {
    BT_CONN_TYPE_BT_OTHERS,
    BT_CONN_TYPE_BT_IAP2,
    BT_CONN_TYPE_BT_SPP
    } bt_connection_path_type;

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
                        MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
void HCI_init
    (
    void
    );

void HCI_normal_reset_BT
    (
    void
    );

void HCI_notify_received
    (
    uint8_t* data,
    uint32_t size
    );

#if HCI_TX_QUEUE_ENABLE
void HCI_notify_transmit
    (
    uint16_t tx_command_type,
    uint8_t* data,
    uint32_t size
    );
#endif

BaseType_t HCI_wiced_send_command
    (
    const uint16_t command,
    const uint8_t* payload,
    const uint16_t len
    );

void HCI_avrc_play
    (
    void
    );

void HCI_avrc_pause
    (
    void
    );

void HCI_avrc_play_next_track
    (
    void
    );

void HCI_avrc_play_previous_track
    (
    void
    );

void hci_avrc_event_handler
    (
    const uint16_t opcode,
    const uint16_t length,
    const uint8_t* data
    );

void HCI_BT_off
    (
    void
    );

void HCI_BT_on
    (
    void
    );

void HCI_set_test_mode
    (
    void
    );

bool HCI_get_test_mode_state
    (
    void
    );

void HCI_LE_transmit_cmd
    (
    uint8_t* data
    );

void HCI_wait_for_resp_start
    (
    void
    );

#ifdef __cplusplus
}
#endif


#endif /*HCI_PUB_H */
