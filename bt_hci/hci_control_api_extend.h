/*********************************************************************
* @file
* hci_control_api_extend.h
*
* @brief
* The WICED HCI Garmin customized commands and events, except for list
* hci_control_api.h
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifndef HCI_CONTROL_API_EXTEND_H
#define HCI_CONTROL_API_EXTEND_H

#ifdef __cplusplus
extern "C" {
#endif

/* Garmin add Miscellaneous commands */
#define HCI_CONTROL_MISC_COMMAND_SW_VERSION                 ( ( HCI_CONTROL_GROUP_MISC << 8 ) | 0x03 )    /* Request Garmin SW version */
#define HCI_CONTROL_MISC_COMMAND_READ_PAIR_INFO             ( ( HCI_CONTROL_GROUP_MISC << 8 ) | 0x04 )    /* Request BT send paired device name and address */
#define HCI_CONTROL_MISC_COMMAND_READ_PAIR_DEV_LIST         ( ( HCI_CONTROL_GROUP_MISC << 8 ) | 0x05 )    /* Request BT send paired device list */
#define HCI_CONTROL_MISC_COMMAND_READ_PAIR_DEV_NUM          ( ( HCI_CONTROL_GROUP_MISC << 8 ) | 0x06 )    /* Request BT send paired device number */
#define HCI_CONTROL_MISC_COMMAND_UNPAIR_ALL_DEV             ( ( HCI_CONTROL_GROUP_MISC << 8 ) | 0x07 )    /* Unpair all paired devices */
#define HCI_CONTROL_MISC_COMMAND_USER_CONFIRM_RESULT        ( ( HCI_CONTROL_GROUP_MISC << 8 ) | 0x08 )    /* Send the Host MCU User Confirm Result to BT module */

/* Garmin add Miscellaneous events */
#define HCI_CONTROL_MISC_EVENT_SW_VERSION                   ( ( HCI_CONTROL_GROUP_MISC << 8 ) | 0x03 )      /* Garmin SW version */
#define HCI_CONTROL_MISC_EVENT_READ_PAIR_INFO               ( ( HCI_CONTROL_GROUP_MISC << 8 ) | 0x04 )      /* Update paired device name and address */
#define HCI_CONTROL_MISC_EVENT_READ_PAIR_DEV_LIST           ( ( HCI_CONTROL_GROUP_MISC << 8 ) | 0x05 )      /* Update paired device list */
#define HCI_CONTROL_MISC_EVENT_READ_PAIR_DEV_NUM            ( ( HCI_CONTROL_GROUP_MISC << 8 ) | 0x06 )      /* Update paired device number */
#define HCI_CONTROL_MISC_EVENT_UNPAIR_ALL_DEV               ( ( HCI_CONTROL_GROUP_MISC << 8 ) | 0x07 )
#define HCI_CONTROL_MISC_EVENT_USER_CONFIRM_RESULT          ( ( HCI_CONTROL_GROUP_MISC << 8 ) | 0x08 )      /* Send the User Confirm Passkey and Device name to BT module */
#define HCI_CONTROL_MISC_EVENT_ADDR_PAIR_FAIL               ( ( HCI_CONTROL_GROUP_MISC << 8 ) | 0x09 )      /* SPP or iAP2 connect check the authentication error */

#ifdef __cplusplus
}
#endif

#endif /* HCI_CONTROL_API_EXTEND_H */
