/*!*******************************************************************
* @file can_tp.h
* @brief Garmin CAN Stack Transport Protocol Layer API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @ingroup can_stack_tp
* @{
*
*********************************************************************/
#ifndef _CAN_TP_H
#define _CAN_TP_H
#include "can_defs.h"
#include "can_tp_cfg.h"
#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                            GENERAL INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                            MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                            TYPES
--------------------------------------------------------------------*/
/*------------------------------------------------------
TP Channel Index
------------------------------------------------------*/
typedef uint8 tp_chan_index_t;
#define TP_CHN_FUNC_INDEX           (TP_CAN0_NUM_CHANNELS - 1)

#define TP_CHN0_INDEX               (0)
#define TP_CHN1_INDEX               (1)
#define TP_CHN2_INDEX               (2)
#define TP_CHN3_INDEX               (3)
#define TP_CHN4_INDEX               (4)
#define TP_CHN5_INDEX               (5)
#define TP_CHN6_INDEX               (6)
#define TP_CHN7_INDEX               (7)
#define TP_CHN8_INDEX               (8)
#define TP_CHN9_INDEX               (9)
#define TP_CHN10_INDEX              (10)
#define TP_CHN11_INDEX              (11)
#define TP_CHN12_INDEX              (12)
#define TP_CHN13_INDEX              (13)
#define TP_CHN14_INDEX              (14)
#define TP_CHN15_INDEX              (15)
#define TP_CHN16_INDEX              (16)
#define TP_CHN17_INDEX              (17)
#define TP_CHN18_INDEX              (18)
#define TP_CHN19_INDEX              (19)
#define TP_CHN20_INDEX              (20)
#define TP_CHN21_INDEX              (21)
#define TP_CHN22_INDEX              (TP_CHN_FUNC_INDEX)

/*------------------------------------------------------
TP Parameter Enumerated Type Definition
------------------------------------------------------*/
typedef enum tagTP_N_PARAM_TYPE
    {
    TP_NP_STMIN,
    TP_NP_BLOCKSIZE,
    TP_NP_RCV_SUSPEND,
    TP_NP_RCV_RESUME,
    TP_NP_NUM_PARAMS
    } tp_n_param_t;

/*------------------------------------------------------
TP Transfer Result Definitions
------------------------------------------------------*/
typedef uint8 tp_n_result_t;

#define TP_N_OK                     (0x00u)
#define TP_N_TIMEOUT_A              (0x01u)
#define TP_N_TIMEOUT_Bs             (0x02u)
#define TP_N_TIMEOUT_Cr             (0x03u)
#define TP_N_WRONG_SN               (0x04u)
#define TP_N_INVALID_FS             (0x05u)
#define TP_N_INVALID_STMIN          (0x06u)
#define TP_N_UNEXP_PDU              (0x07u)
#define TP_N_WFT_OVRN               (0x08u)
#define TP_N_BUFFER_OVFLW           (0x09u)
#define TP_N_ERROR                  (0x0Au)

/*------------------------------------------------------
TP Parameter Change Request Return Value Definitions
------------------------------------------------------*/
typedef uint8 tp_n_chng_result_t;

#define TP_NC_OK                    (0x00u)
#define TP_NC_RX_ON                 (0x01u)
#define TP_NC_WRONG_PARAMETER       (0x02u)
#define TP_NC_WRONG_VALUE           (0x03u)

typedef int TP_RC;

#define TP_RC_OK                    (1)
#define TP_RC_SUCCESS               (1)
#define TP_RC_TRUE                  (1)
#define TP_RC_FALSE                 (0)
#define TP_RC_NULL                  (0)
#define TP_RC_FAIL                  (0)
#define TP_RC_EMPTY                 (0)
#define TP_RC_ERROR                 (-1)
#define TP_RC_INVALID_PARM          (-2)
#define TP_RC_INVALID_HANDLE        (-3)
#define TP_RC_NULL_PTR              (-4)
#define TP_RC_INVALID_SERVICE       (-5)
#define TP_RC_NOT_AVAILABLE         (-6)
#define TP_RC_RX_OVERRUN            (-7)
#define TP_RC_TXQ_OVERRUN           (-8)
#define TP_RC_TMDQ_OVERRUN          (-9)

/*--------------------------------------------------------------------
                            VARIABLES
--------------------------------------------------------------------*/


/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/
void tp_init
    (
    can_hw_inst_t           const hw_inst
    );

void tp_task
    (
    can_hw_inst_t           const hw_inst
    );

void tp_transmit
    (
    uint8           const * const p_tp_data,
    uint16                  const num_tp_bytes,
    tp_chan_index_t         const ch_index,
    can_hw_inst_t           const hw_inst
    );

void tp_transmit_direct
(
   uint8       const * const p_tp_data,        //!< [in] ptr to TP data to send
   uint16              const num_tp_bytes,     //!< [in] number of bytes to send
   tp_chan_index_t     const ch_index,         //!< [in] TP channel index
   can_hw_inst_t       const hw_inst           //!< [in] CAN hardware instance
   );

void tp_cf_send_timer_event
    (
    uint8                   const tp_send_cf_index
    );

tp_n_chng_result_t
tp_change_parameter
    (
    tp_n_param_t            const param,
    uint16                  const param_value,
    tp_chan_index_t         const ch_index,
    can_hw_inst_t           const hw_inst
    );

void tp_hook_transmit
    (
    can_tmh_t               const tmh,
    can_hw_inst_t           const hw_inst
    );

void tp_hook_transmit_timeout
    (
    can_tmh_t               const tmh,
    can_hw_inst_t           const hw_inst
    );

void tp_hook_receive
    (
    can_rmd_t       const * const p_rmd,
    can_hw_inst_t           const hw_inst
    );

void tp_app_hook_transmit_complete
    (
    tp_n_result_t           const result,
    tp_chan_index_t         const ch_index,
    can_hw_inst_t           const hw_inst
    );

void tp_app_hook_receive_first_frame
    (
    tp_n_result_t           const result,
    tp_chan_index_t         const ch_index,
    can_hw_inst_t           const hw_inst
    );

void tp_app_hook_receive_complete
    (
    uint8           const * const p_data,
    uint16                  const num_bytes,
    tp_n_result_t           const result,
    tp_chan_index_t         const ch_index,
    can_hw_inst_t           const hw_inst
    );

#ifdef __cplusplus
}
#endif

#endif /* _CAN_TP_H */

