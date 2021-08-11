/*********************************************************************
* @file  cm_prv.h
* @brief Defines the Connection Manager private procedures
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifndef _CM_PRV_H_
#define _CM_PRV_H_

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "fsl_debug_console.h"

#define CM_PRINT_ENABLE 1
#if CM_PRINT_ENABLE
    #define CM_PRINT PRINTF
#else
    #define CM_PRINT
#endif

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
void CM_core_init
    (
    void
    );

bool CM_core_spp_connect
    (
    const uint8_t* bd_addr
    );

bool CM_core_spp_disconnect
    (
    const uint8_t* bd_addr
    );

bool CM_core_get_spp_connection_status
    (
    const CM_app_type_e app_type
    );

bool CM_core_get_app_connection_status
    (
    const CM_app_type_e app_type,
    const uint8_t* bd_addr
    );

void CM_core_handle_btmgr_pairing_result
    (
    const CM_btmgr_pairing_result_t *CM_btmgr_pairing_result
    );

void CM_core_handle_btmgr_spp_connection_status_changed
    (
    const CM_connection_status_change_t *CM_connection_status_change
    );

void CM_core_handle_app_auth_result
    (
    const CM_auth_result_t *CM_auth_result
    );

void CM_core_handle_btmgr_acl_link_disconnected
    (
    const CM_acl_disconnected_t *CM_acl_disconnected
    );

void CM_core_set_auto_connect_state
    (
    const CM_set_auto_connect_state_t *CM_set_auto_connect_state
    );

void CM_core_handle_btmgr_enable_state_changed
    (
    const bool enable_state
    );

#ifdef __cplusplus
}
#endif

#endif // _CM_TYPES_H_
