/*!*******************************************************************
* @file can_pub.h
* @brief OSEK CAN Stack public header file
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @ingroup can_stack
* @{
*
*********************************************************************/

#ifndef _CAN_PUB_H
#define _CAN_PUB_H

#ifdef __cplusplus
extern "C" {
#endif
#include "can_il_par.h"
#include "can_il.h"

void il_app_frm_timeout1_get
    (
    il_rx_frm_index_t  msg_index,
    boolean           *p_timeout_err1
    );

void il_app_frm_timeout2_get
    (
    boolean           *p_timeout_err2
    );

void nim_app_sig_put
    (
    il_sig_handle_t         const sig_handle,
    uint8_t                 const num_bytes,
    uint64_t                      sig_val
    );

void nim_app_sig_get
    (
    il_sig_handle_t         const sig_handle,
    uint8_t                 const num_bytes,
    uint32_t                     *p_sig_val
    );

can_ret_code_t
il_app_frm_put
    (
    can_msg_t const * const can_msg_tx_p
    );

can_ret_code_t
il_app_frm_get
    (
    il_rx_frm_index_t   frm_index,
    can_msg_t          *can_msg_rx_p
    );

#ifdef __cplusplus
}
#endif

#endif /* _CAN_PUB_H */


