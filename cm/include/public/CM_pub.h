/*********************************************************************
* @file  CM_pub.h
* @brief Connection Manager Public interface declaration.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifndef _CM_PUB_H_
#define _CM_PUB_H_

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "cm_types.h"

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
CM_status_e CM_init
    (
    void
    );

CM_status_e CM_connect
    (
    const uint8_t* bd_addr
    );

CM_status_e CM_disconnect
    (
    const uint8_t* bd_addr
    );

bool CM_get_auto_connect_state
    (
    void
    );

CM_status_e CM_set_auto_connect_state
    (
    const bool state
    );

CM_status_e CM_handle_hmi_ccuid_ready
    (
    const uint8_t* ccuid
    );

bool CM_get_spp_connection_status
    (
    const CM_spp_app_type_e app_type
    );

bool CM_get_app_connection_status
    (
    const CM_app_type_e app_type,
    const uint8_t* bd_addr
    );

CM_status_e CM_handle_btmgr_enable_state_changed
    (
    const bool enable_state
    );

CM_status_e CM_handle_btmgr_pairing_result
    (
    const bool pairing_result,
    const uint8_t* bd_addr
    );

CM_status_e CM_handle_btmgr_paired_device_deleted
    (
    const uint8_t* bd_addr
    );

CM_status_e CM_handle_btmgr_spp_connection_status_changed
    (
    const bool connected,
    const uint8_t* bd_addr
    );

CM_status_e CM_handle_btmgr_acl_link_disconnected
    (
    const bool user_requested
    );

#ifdef __cplusplus
}
#endif

#endif // _BT_PUB_H_
