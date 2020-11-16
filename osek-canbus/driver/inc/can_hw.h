/*!*******************************************************************
* @file can_hw.h
* @brief RT1170 FlexCAN H/W Driver API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @ingroup can_hw_drv
* @{
*
*********************************************************************/

#ifndef _CAN_HW_H
#define _CAN_HW_H

#ifdef __cplusplus

extern "C" {
#endif

/*--------------------------------------------------------------------
                            GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "MIMXRT1052.h"

/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/
can_ret_code_t
can_hw_transmit
    (
    can_hw_inst_t       const hw_inst,   //!< [in] CAN hardware instanc
    can_tmd_t   const * const p_tmd      //!< [in] pointer to transmit data structure
    );

void
can_hw_tx_flush
    (
    can_hw_inst_t     const hw_inst      //!< [in] CAN hardware instance
    );

can_ret_code_t
can_hw_receive
    (
    can_hw_inst_t   const hw_inst,       //!< [in] CAN hardware instance
    can_rmd_t     * const p_rmd,         //!< [out] pointer to receive message buffer
    can_hmb_t       const rx_mb_index    //!< [in] Receive Message Buffer
    );

void
can_hw_rx_flush
    (
    can_hw_inst_t     const hw_inst      //!< [in] CAN hardware instance
    );

can_ret_code_t
can_hw_init
    (
    can_hw_inst_t       const hw_inst,        //!< [in] CAN hardware instance
    can_init_mode_t     const init_mode,      //!< [in] initialization mode (cold or warm init)
    void        const * const p_init_vector   //!< [in] pointer to initialization data structure
    );

can_status_t
can_hw_get_status
    (
    can_hw_inst_t           const hw_inst,
    can_get_stat_mode_t     const status_mode
    );

can_ret_code_t
can_hw_is_tx_pending
    (
    can_hw_inst_t           const hw_inst,
    can_hmb_t               const tx_mb_index
    );

can_ret_code_t
can_hw_is_bus_active
    (
    can_hw_inst_t           const hw_inst
    );

can_ret_code_t
can_hw_is_bus_sleep
    (
    can_hw_inst_t           const hw_inst
    );

can_ret_code_t
can_is_hw_sleeping
    (
    can_hw_inst_t           const hw_inst
    );

can_ret_code_t
can_hw_is_bus_open
    (
    can_hw_inst_t           const hw_inst
    );

can_ret_code_t
can_hw_on_line
    (
    can_hw_inst_t           const hw_inst
    );

can_ret_code_t
can_hw_off_line
    (
    can_hw_inst_t           const hw_inst
    );

can_ret_code_t
can_hw_power_down
    (
    can_hw_inst_t           const hw_inst
    );

can_ret_code_t
can_hw_sleep
    (
    can_hw_inst_t           const hw_inst
    );

can_ret_code_t
can_hw_wakeup
    (
    can_hw_inst_t           const hw_inst
    );

can_ret_code_t
can_hw_enable_tx_interrupt
    (
    can_hw_inst_t           const hw_inst,
    can_hmb_t               const tx_mb_index
    );

can_ret_code_t
can_hw_disable_tx_interrupt
    (
    can_hw_inst_t           const hw_inst,
    can_hmb_t               const tx_mb_index
    );

can_ret_code_t
can_hw_enable_rx_interrupt
    (
    can_hw_inst_t           const hw_inst,
    can_hmb_t               const tx_mb_index
    );

can_ret_code_t
can_hw_disable_rx_interrupt
    (
    can_hw_inst_t           const hw_inst,
    can_hmb_t               const rx_mb_index
    );

can_ret_code_t
can_hw_enable_interrupts
    (
    can_hw_inst_t           const hw_inst
    );

can_ret_code_t
can_hw_disable_interrupts
    (
    can_hw_inst_t           const hw_inst
    );

void
can_hw_enable_transmit_timeout
    (
    can_hw_inst_t           const hw_inst
    );

void
can_hw_disable_transmit_timeout
    (
    can_hw_inst_t           const hw_inst
    );

void
can_hw_periodic
    (
    can_hw_inst_t           const hw_inst
    );

void CAN2_DriverIRQHandler
    (
    void
    );

can_rmd_t *
can_hook_get_rmd_ptr
    (
    can_hw_inst_t           const hw_inst
    );

void
can_hook_transmit
    (
    can_hw_inst_t           const hw_inst,
    can_tmh_t               const tmh,
    can_hmb_t               const tx_mb_index,
    boolean                 const tx_ok
    );

void
can_hook_transmit_timeout
    (
    can_hw_inst_t           const hw_inst,
    can_tmh_t               const tmh
    );

void
can_hook_receive
    (
    can_hw_inst_t           const hw_inst,
    can_hmb_t               const rx_mb_index,
    can_rmd_t       const * const p_rmd
    );

void
can_hook_exception
    (
    can_hw_inst_t           const hw_inst,
    can_exception_t         const exception
    );

void
can_hook_init_busoff_recovery
    (
    can_hw_inst_t           const hw_inst
    );

#ifdef __cplusplus
}

#endif

#endif

