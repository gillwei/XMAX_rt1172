/*********************************************************************
* @file
* hci_prv.h
*
* @brief
* BT HCI driver - private API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifndef HCI_PRV_H
#define HCI_PRV_H

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "HCI_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define BT_UPDATE_ON             true

#define OPCODE_ALLOW_CONNECTION  0x0C05
#define OPCODE_LE_TX             0x201E
#define OPCODE_LE_END            0x201F

#define RESET_WAIT_MS            1000

#define HCI_MAX_DATA_SIZE        240

extern uint32_t __base_BOARD_FLASH_BTFW;
#define FLASH_BT_FW_BASE_ADDR    ( ( uint32_t )( &__base_BOARD_FLASH_BTFW ) )
#define BT_SW_MAJOR_VER_BYTE     0
#define BT_SW_MINOR_VER_BYTE     1

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
typedef enum tagINIT_UPDATE_STATE                //!< check the BT have newest FW or update
    {
    INIT_STATE_SUSPEND,
    INIT_STATE_REQUEST_VERSION,
    INIT_STATE_GET_VERSION,
    INIT_STATE_UPDATE
    } init_update_state_t;

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
init_update_state_t getBTInitUpdateState
    (
    void
    );

void setBTInitUpdateState
    (
    init_update_state_t newInitUpdateState
    );

void hci_misc_event_handler
    (
    const uint16_t opcode,
    const uint8_t* p_data,
    const uint32_t data_len
    );

void hci_device_event_handler
    (
    const uint16_t cmd_opcode,
    const uint8_t* p_data,
    const uint32_t data_len
    );

void hci_spp_event_handler
    (
    const uint16_t cmd_opcode,
    const uint8_t* p_data,
    const uint32_t data_len
    );

void hci_iap2_event_handler
    (
    const uint16_t cmd_opcode,
    const uint8_t* p_data,
    const uint32_t data_len
    );

void initBTUpdateCheck
    (
    void
    );

bt_parser_t getBTParserStatus
    (
    void
    );

void parseUpdatePkt
    (
    uint8_t* l_hci_buffer,
    uint32_t length
    );

void bt_update_init
    (
    void
    );

void UINT32_to_UINT8_arry
    (
    const uint32_t var_uint32,
    uint8_t * uint8_arry
    );

void hci_wait_for_resp_stop
    (
    void
    );

bool getBTDUTModeState
    (
    void
    );

void hci_recovery_reset_BT
    (
    void
    );

void bt_update_get_BT_SW_ver
    (
    uint8_t * read_bt_sw_ver
    );

#ifdef __cplusplus
}
#endif

#endif /* HCI_PRV_H */
