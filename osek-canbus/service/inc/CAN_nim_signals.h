/*!*******************************************************************
* @file CAN_nim_signals.h
* @brief CAN Stack Network Interface Signal Manager API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @ingroup can_stack_nim_signals
* @{
*
*********************************************************************/

#ifndef _CAN_NIM_SIGNALS_H
#define _CAN_NIM_SIGNALS_H

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/
void CAN_nim_tx_put_signal_bytes
    (
    il_sig_handle_t         const sig_handle,
    uint8           const * const p_sig_data,
    uint8                   const num_bytes
    );

void CAN_nim_tx_put_uint8_signal
    (
    il_sig_handle_t         const sig_handle,
    uint8                   const sig_value
    );

void CAN_nim_tx_put_uint16_signal
    (
    il_sig_handle_t         const sig_handle,
    uint16                  const sig_value
    );

void CAN_nim_tx_put_uint32_signal
    (
    il_sig_handle_t         const sig_handle,
    uint32                  const sig_value
    );

void CAN_nim_tx_put_uint64_signal
    (
    il_sig_handle_t         const sig_handle,
    uint64                  const sig_value
    );

void CAN_nim_tx_put_signal_group
    (
    dll_frm_handle_t        const frm_handle,
    il_txsig_put_t  const * const p_txsig_put_list,
    uint8                   const num_signals
    );

void CAN_nim_rx_get_signal_bytes
    (
    il_sig_handle_t         const sig_handle,
    uint8                 * const p_sig_data,
    uint8                   const num_bytes
    );

void CAN_nim_rx_get_uint8_signal
    (
    il_sig_handle_t         const sig_handle,
    uint8                 * const p_signal
    );

void CAN_nim_rx_get_uint16_signal
    (
    il_sig_handle_t         const sig_handle,
    uint16                * const p_signal
    );

void CAN_nim_rx_get_uint32_signal
    (
    il_sig_handle_t         const sig_handle,
    uint32                * const p_signal
    );

void CAN_nim_rx_get_uint64_signal
    (
    il_sig_handle_t         const sig_handle,
    uint64                * const p_signal
    );

void CAN_nim_rx_get_signal_changed_flag
    (
    il_sig_handle_t         const sig_handle,
    boolean               * const p_flag
    );

void CAN_nim_rx_clear_signal_changed_flag
    (
    il_sig_handle_t         const sig_handle
    );

void CAN_nim_rx_get_signal_group
    (
    il_rxsig_get_t  const * const p_rxsig_get_list,
    uint8                   const num_signals
    );

void CAN_nim_rx_get_signal_group_changed_flags
    (
    il_sig_handle_t const * const p_rx_sig_list,
    boolean               * const p_flags,
    uint8                   const num_signals
    );

void CAN_nim_rx_clear_signal_group_changed_flags
    (
    il_sig_handle_t  const * const p_rx_sig_list,
    uint8                    const num_signals
    );

#ifdef __cplusplus
}
#endif

#endif /* _CAN_NIM_SIGNALS_H */

