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

#define GARMIN_SW_MAJOR_VER   0x01
#define GARMIN_SW_MINOR_VER   0x02
#define BT_UPDATE_ON          false

typedef enum tagBT_PARSER_TYPE                  //!< HCI receive state machine states
    {
    PARSER_WICED_HCI,
    PARSER_STANDARD_HCI
    } bt_parser_t;

typedef enum tagINIT_UPDATE_STATE                //!< check the BT have newest FW or update
    {
    INIT_STATE_SUSPEND,
    INIT_STATE_REQUEST_VERSION,
    INIT_STATE_GET_VERSION,
    INIT_STATE_UPDATE
    } init_update_state_t;

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

#ifdef __cplusplus
}
#endif

#endif /* HCI_PRV_H */
