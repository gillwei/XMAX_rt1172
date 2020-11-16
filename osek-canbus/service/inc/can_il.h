/*!*******************************************************************
* @file can_il.h
* @brief OSEK CAN Stack Interaction Layer API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @ingroup can_stack_il
* @{
*
*********************************************************************/

#ifndef _CAN_IL_H
#define _CAN_IL_H

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                            GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "can_defs.h"
#include "can_dll.h"


/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
typedef enum tagIL_RX_FRM_INDEX_TYPE //!< Interaction Layer receive frames index
    {
    IL_RX_FRM_INDEX_FUNC_SW_STATUS,
    IL_RX_FRM_INDEX_VEHICLE_INFO,
    IL_RX_FRM_INDEX_FUNC_CNTRL,
    IL_RX_FRM_INDEX_CLK_DATE_REQ,
    IL_RX_FRM_INDEX_UNIT_INFO,
    IL_RX_FRM_INDEX_REQ_SCREEN_TRANS,
    IL_RX_FRM_INDEX_RES_REPROGRAM_INFO,
    IL_RX_FRM_INDEX_REQ_SCREEN_TRANS2,

    IL_RX_FRM_INDEX_ERRORS
    }il_rx_frm_index_t;

/*------------------------------------------------------
Signal Handle Type

The handle includes the hardware instance in the Most
Significant Nibble and the index of the signal together
------------------------------------------------------*/
typedef uint16      il_sig_handle_t;

/*------------------------------------------------------
Transmit Signal Put Type

This data structure facilitates group signal
transmissions for coherency.
------------------------------------------------------*/
typedef struct  tagIL_TXSIG_PUT_TYPE
    {
    il_sig_handle_t         const sig_handle;
    uint8           const * const p_data;
    uint8                   const num_bytes;

    } il_txsig_put_t;

/*------------------------------------------------------
Receive Signal Get Type

This data structure facilitates group signal
receptions for coherency.
------------------------------------------------------*/
typedef struct  tagIL_RXSIG_GET_TYPE
    {
    il_sig_handle_t         const sig_handle;
    uint8                 * const p_data;
    uint8                   const num_bytes;

    } il_rxsig_get_t;


/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
void il_init
    (
    can_hw_inst_t           const hw_inst,
    boolean                 const init_default
    );

void il_tx_task
    (
    can_hw_inst_t           const hw_inst
    );

void il_rx_task
    (
    can_hw_inst_t           const hw_inst
    );

void il_hook_transmit
    (
    can_hw_inst_t           const hw_inst,
    can_tmh_t               const tmh
    );

void il_hook_transmit_timeout
    (
    can_hw_inst_t           const hw_inst,
    can_tmh_t               const tmh
    );

void il_hook_receive
    (
    can_hw_inst_t           const hw_inst,
    can_rmd_t       const * const p_rmd,
    dll_frm_handle_t        const frm_handle
    );

void il_enable
    (
    can_hw_inst_t           const hw_inst
    );

void il_disable
    (
    can_hw_inst_t           const hw_inst
    );

void il_suspend
    (
    can_hw_inst_t           const hw_inst
    );

void il_resume
    (
    can_hw_inst_t           const hw_inst
    );

boolean il_tx_put_signal_bytes
    (
    il_sig_handle_t         const sig_handle,
    uint8           const * const p_sig_data,
    uint8                   const num_bytes
    );

boolean il_tx_put_uint8_signal
    (
    il_sig_handle_t         const sig_handle,
    uint8                   const sig_value
    );

boolean il_tx_put_uint16_signal
    (
    il_sig_handle_t         const sig_handle,
    uint16                  const sig_value
    );

boolean il_tx_put_uint32_signal
    (
    il_sig_handle_t         const sig_handle,
    uint32                  const sig_value
    );

boolean il_tx_put_uint64_signal
    (
    il_sig_handle_t         const sig_handle,
    uint64                  const sig_value
    );

boolean il_tx_put_signal_group
    (
    dll_frm_handle_t        const frm_handle,
    il_txsig_put_t  const * const p_txsig_put_list,
    uint8                   const num_signals
    );

boolean il_rx_get_signal_bytes
    (
    il_sig_handle_t         const sig_handle,
    uint8                 * const p_sig_data,
    uint8                   const num_bytes
    );

boolean il_rx_get_uint8_signal
    (
    il_sig_handle_t         const sig_handle,
    uint8                 * const p_signal
    );

boolean il_rx_get_uint16_signal
    (
    il_sig_handle_t         const sig_handle,
    uint16                * const p_signal
    );

boolean il_rx_get_uint32_signal
    (
    il_sig_handle_t         const sig_handle,
    uint32                * const p_signal
    );

boolean il_rx_get_uint64_signal
    (
    il_sig_handle_t         const sig_handle,
    uint64                * const p_signal
    );

boolean il_rx_get_signal_changed_flag
    (
    il_sig_handle_t         const sig_handle,
    boolean               * const p_flag
    );

boolean il_rx_clear_signal_changed_flag
    (
    il_sig_handle_t         const sig_handle
    );

boolean il_rx_get_signal_group
    (
    il_rxsig_get_t  const * const p_rxsig_get_list,
    uint8                   const num_signals
    );

boolean il_rx_get_signal_group_changed_flags
    (
    il_sig_handle_t const * const p_rx_sig_list,
    boolean               * const p_flags,
    uint8                   const num_signals
    );

boolean il_rx_clear_signal_group_changed_flags
    (
    il_sig_handle_t const * const p_rx_sig_list,
    uint8                   const num_signals
    );

void il_app_notify_tx_complete
    (
    dll_frm_handle_t        const frm_handle
    );

void il_app_notify_tx_timeout
    (
    dll_frm_handle_t        const frm_handle
    );

void il_app_notify_frame_received
    (
    dll_frm_handle_t        const frm_handle
    );

void il_can_app_notify_sig_changed
    (
    il_sig_handle_t         const sig_handle,
    uint8_t                 const num_bytes,
    uint16_t                     *p_sig_val
    );

void il_app_notify_rx_timeout1
    (
    can_hw_inst_t    hw_inst,
    dll_frm_handle_t rmh
    );

void il_app_notify_rx_timeout2
    (
    boolean timeout_trig
    );

#ifdef __cplusplus
}
#endif

#endif /* _CAN_IL_H */

/*!*******************************************************************
*
* @}
*
*********************************************************************/
