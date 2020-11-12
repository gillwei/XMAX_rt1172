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
//#include "FreeRTOSConfig.h"
#include "fsl_common.h"
#include "PERIPHERAL_pub.h"
/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/

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

void HCI_reset_BT
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

#ifdef __cplusplus
}
#endif


#endif /*HCI_PUB_H */
