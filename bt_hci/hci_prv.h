/*
 * hci_prv.h
 *
 *  Created on: Aug 14, 2020
 *      Author: WeiGill
 */

#ifndef HCI_PRV_H_
#define HCI_PRV_H_

#define GARMIN_SW_MAJOR_VER   0x01
#define GARMIN_SW_MINOR_VER   0x02

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

void BTM_pairing_info_update
    (
    const uint8_t *pairing_info
    );

void BTM_connection_info_update
    (
    const bool     connection_is_up,
    const uint8_t* connection_info
    );

#endif /* HCI_PRV_H_ */
