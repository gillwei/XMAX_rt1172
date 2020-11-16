/*!*******************************************************************
* @file can_nm.h
* @brief IXWW22 CAN Stack Network Management Layer API
*
* This file contains public type definitions specific to the Network
* Management Layer implementation of the Garmin CAN Stack. Also
* included are public function definitions used to access Network
* Management functions.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @ingroup can_stack_nm
* @{
*
*********************************************************************/

#ifndef _CAN_NM_H
#define _CAN_NM_H

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                            MACROS
--------------------------------------------------------------------*/


/*--------------------------------------------------------------------
                            TYPES
--------------------------------------------------------------------*/
typedef enum tagNM_INIT_MODE_TYPE
    {
    NM_INIT_MODE_POWER_ON,
    NM_INIT_MODE_POWER_ON_SLEEP,
    NM_INIT_MODE_LOCAL_WAKEUP,
    NM_INIT_MODE_BUS_WAKEUP,
    NM_INIT_MODE_NUM

    } nm_init_mode_t;

/*------------------------------------------------------
Network Management State Definitions
------------------------------------------------------*/
typedef enum tagNM_STATE_TYPE
    {
    NM_STATE_SLEEP,
    NM_STATE_NORMAL,
    NM_STATE_GO_TO_SLEEP,
    NM_STATE_WAKEUP,
    NM_STATE_COM_OFF,
    NM_STATE_LIMP_HOME,
    NM_STATE_NUM

    } nm_state_t;

/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/
void nm_init
    (
    can_hw_inst_t       const hw_inst,
    nm_init_mode_t      const init_mode
    );

void nm_task
    (
    can_hw_inst_t       const hw_inst
    );

nm_state_t nm_get_current_state
    (
    can_hw_inst_t       const hw_inst
    );

void nm_app_notify_state_change
    (
    can_hw_inst_t       const hw_ins,
    nm_state_t          const nm_state
    );

void nm_app_notify_busoff_recovery
    (
    can_hw_inst_t       const hw_inst
    );

void nm_app_notify_busoff
    (
    can_hw_inst_t       const hw_inst
    );

void nm_app_notify_init_failed
    (
    can_hw_inst_t       const hw_inst
    );

void nm_app_notify_tx_hw_timeout
    (
    can_hw_inst_t hw_inst,
    can_tmh_t     tmh
    );

void nm_app_hook_process_receive
    (
    can_hw_inst_t       const hw_inst,
    can_rmd_t   const * const p_rmd
    );

void nm_hook_op_mode
    (
    can_hw_inst_t       const hw_inst,
    can_op_mode_t       const op_mode
    );

void nm_hook_bus_off
    (
    can_hw_inst_t       const hw_inst
    );

void nm_hook_transmit
    (
    can_hw_inst_t       const hw_inst,
    can_tmh_t           const tmh
    );

void nm_hook_transmit_timeout
    (
    can_hw_inst_t       const hw_inst,
    can_tmh_t           const tmh
    );

void nm_hook_receive
    (
    can_hw_inst_t       const hw_inst,
    can_rmd_t   const * const p_rmd
    );

void nm_hook_notify_any_can_frame_reception
    (
    can_hw_inst_t       const hw_inst
    );

void nm_hook_notify_any_can_frame_transmission
    (
    can_hw_inst_t       const hw_inst
    );

#ifdef __cplusplus
}
#endif

#endif /* _CAN_NM_H */

