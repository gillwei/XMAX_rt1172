/*!*******************************************************************
* @file can_drv.h
* @brief CAN Driver Layer API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @ingroup can_drv
* @{
*
*********************************************************************/

#ifndef _CAN_DRV_H
#define _CAN_DRV_H

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/
can_ret_code_t
can_init
    (
    can_hw_inst_t           const hw_inst,
    can_init_mode_t         const init_mode,
    void            const * const p_init_vector
    );

can_ret_code_t
can_transmit
    (
    can_hw_inst_t           const hw_inst,
    can_tmd_t       const * const p_tmd
    );

can_ret_code_t
can_receive
    (
    can_hw_inst_t           const hw_inst,
    can_rmd_t             * const p_rmd
    );

void
can_periodic
    (
    can_hw_inst_t           const hw_inst
    );

can_ret_code_t
can_service
    (
    can_hw_inst_t           const hw_inst,
    can_hmb_t               const mb_index,
    can_svc_t               const service_request
    );

void
can_drv_hook_transmit
    (
    can_hw_inst_t           const hw_inst,
    can_hmb_t               const tx_mb_index,
    can_tmh_t               const tmh
    );

void
can_drv_hook_transmit_timeout
    (
    can_hw_inst_t           const hw_inst,
    can_tmh_t               const tmh
    );

void
can_drv_hook_receive
    (
    can_hw_inst_t           const hw_inst,
    can_hmb_t               const rx_mb_index,
    can_rmd_t       const * const p_rmd
    );

void
can_drv_hook_op_mode
    (
    can_hw_inst_t           const hw_inst,
    can_op_mode_t           const op_mode
    );

void
can_drv_hook_exception
    (
    can_hw_inst_t           const hw_inst,
    can_exception_t         const exception
    );

#ifdef __cplusplus
}
#endif

#endif /* CAN_DRV_H */

