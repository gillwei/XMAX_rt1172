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
#include "can_mid.h"
#include "can_il_enum.h"
#include "can_dll_prv_par.h"
#include "can_bcfg.h"

void il_app_frm_timeout1_get
    (
    il_rx_frm_index_t  msg_index,
    boolean           *p_timeout_err1
    );

void il_app_frm_timeout2_get
    (
    boolean           *p_timeout_err2
    );

void il_app_frm_sig_set_status
    (
    il_rx_frm_index_t const frm_index,
    uint8             const frm_stat_bit_mask,
    il_sig_handle_t   const sig_handle,
    uint8             const sig_stat_bit_mask
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

can_ret_code_t can_mid_req
    (
    uint32  can_id,
    uint8   msg_len,
    uint8   svc_id,
    uint8   svc_opt
    );

mid_msg_lst can_mid_resp_get
    (
    uint32  can_id,
    uint8   svc_id
    );

mid_msg_supp_func_t*
can_mid_get_supp_func_list
    (
    void
    );

boolean can_mid_sig_set
    (
    dll_frm_index_t          *frm_index_p, //!< [in] Frame index
    il_sig_handle_t     const sig_handle,  //!< [in] signal handle
    uint8               const num_bytes,   //!< [in] number of bytes in the signal
    uint8       const * const p_sig_data   //!< [in] pointer to signal data
    );

void can_mid_frm_send
    (
    dll_frm_index_t frm_index
    );

void can_mid_fuel_cons_pm_cb
    (
    bool status
    );

#ifdef __cplusplus
}
#endif

#endif /* _CAN_PUB_H */


