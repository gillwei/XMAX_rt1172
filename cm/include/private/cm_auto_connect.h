/*********************************************************************
* @file  cm_auto_connect.h
* @brief Connection Manager Auto-Connect interface declaration.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifndef _CM_AUTO_CONNECT_H_
#define _CM_AUTO_CONNECT_H_

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/

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
bool CMA_factory_reset( void );

bool CMA_get_enable_state( void );

void CMA_handle_btmgr_acl_link_disconnected
    (
    const uint8_t* bd_addr,
    const bool user_requested
    );

void CMA_handle_btmgr_spp_connection_status_changed
    (
    const bool connected,
    const uint8_t* bd_addr
    );

void CMA_handle_btmgr_enable_state_changed
    (
    const bool enable_state
    );

void CMA_init( void );

bool CMA_set_enable_state
    (
    const bool enable
    );

#ifdef __cplusplus
}
#endif

#endif // _CM_AUTO_CONNECT_H_
