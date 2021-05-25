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
                                MACROS
--------------------------------------------------------------------*/
/*------------------------------------------------------
Receive Frame timeout error start tick(50*10ms)
------------------------------------------------------*/
#define IL_RX_TIMEOUT_CHECK_START_TICK      (50)

/*------------------------------------------------------
Receive frame status bits
------------------------------------------------------*/
#define IL_RX_STATUS_PENDING                (0x1 << 0)
#define IL_RX_STATUS_DATA_CHANGED           (0x1 << 1)
#define IL_RX_STATUS_TIMEOUT1               (0x1 << 2)
#define IL_RX_STATUS_TIMEOUT2               (0x1 << 3)
#define IL_RX_STATUS_LOSS_NOTIFIED          (0x1 << 4)
#define IL_RX_STATUS_TIMEOUT2_DIS           (0x1 << 5)

/*------------------------------------------------------
Signal changed status bit definitions
------------------------------------------------------*/
#define IL_SIG_STATUS_VALUE_CHNGD           (0x1 << 0)

/*------------------------------------------------------
General usage literals for bit and byte manipulation
------------------------------------------------------*/
#define IL_NUM_BITS_IN_BYTE                 (8)
#define IL_FIRST_BYTE_IN_FRAME_DATA         (0)
#define IL_LAST_BYTE_IN_FRAME_DATA          (7)
#define IL_FIRST_BIT_IN_BYTE                (7)
#define IL_LAST_BIT_IN_BYTE                 (0)
#define IL_FIRST_AND_LAST_NBYTES            (2)

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
typedef enum tagIL_RX_FRM_INDEX_TYPE //!< Interaction Layer receive frames index
    {
    IL_CAN0_RX_DAIG_SEG1_IDX,
    IL_CAN0_RX_DAIG_SEG2_IDX,
    IL_CAN0_RX_DAIG_SEG3_IDX,
    IL_CAN0_RX_DAIG_SEG4_IDX,
    IL_CAN0_RX_DAIG_SEG5_YDT_IDX,
    IL_CAN0_RX_DAIG_SEG6_YDT_IDX,
    IL_CAN0_RX_DAIG_SEG7_YDT_IDX,
    IL_CAN0_RX_NM_AND_LP_BK_IDX,
    IL_CAN0_RX0_ECU_INDCT_STAT_IDX,
    IL_CAN0_RX1_ECU_COM_DATA_IDX,
    IL_CAN0_RX2_RES_SUPPORT_IDX,
    IL_CAN0_RX3_BRGTHNSS_CTRL_IDX,
    IL_CAN0_RX4_RES_MT_FUNC_CNT_IDX,
    IL_CAN0_RX5_VEHICLE_INFO_IDX,
    IL_CAN0_RX6_FUNCSW_STAT_IDX,
    IL_CAN0_RX7_FUEL_RATE_IDX,
    IL_CAN0_RX8_ODO_TRIP_IDX,
    IL_CAN0_RX9_RES_RPRGRM_INFO_IDX,
    IL_CAN0_RXA_VEHICLE_INFO_2_IDX,
    IL_CAN0_RXB_VEHICLE_INFO_3_IDX,
    IL_CAN0_RXC_VEHICLE_INFO_4_IDX,
    IL_CAN0_RXD_MAINT_TRIP_IDX,
    IL_CAN0_RXE_HEATER_STAT_IDX,
    IL_CAN0_RXF_FACT_INSP_NS_REQ_IDX,
    IL_CAN0_RXG_FACT_INSP2_GA_IDX,
    IL_CAN0_RXH_VH_EG_SPD_IDX,
    IL_CAN0_RXI_TPMS_STAT_IDX,

    /*------------------------------------------------------
    Supplement CAN frames
    ------------------------------------------------------*/
    IL_CAN0_RXJ_MT_SYS_MOD_IDX,
    IL_CAN0_RXK_GRIP_W_BTN_STAT_IDX,
    IL_CAN0_RXL_MT_GEAR_POS_IDX,
    IL_CAN0_RXM_ODO_TRIP_VAL_IDX,
    IL_CAN0_RXN_MT_SET_INFO_IDX,
    IL_CAN0_RXO_ECU_SYS_MOD_IDX,
    IL_CAN0_RXP_APS_ETV_IDX,
    IL_CAN0_RXQ_DIAG_EGMOD_IDX,
    IL_CAN0_RXR_EG_STAT_IDX,
    IL_CAN0_RXS_ECU_GEAR_POS_IDX,
    IL_CAN0_RXT_ECU_STAT_TCU_IDX,
    IL_CAN0_RXU_ECVT_STAT_TCU_IDX,
    IL_CAN0_RXV_ABS_PRESS_IDX,
    IL_CAN0_RXW_ABS_STAT_IDX,
    IL_CAN0_RXX_SMT_STAT_IDX,
    IL_CAN0_RXY_TLCU_COM_DATA_IDX,
    IL_CAN0_RXZ0_TLCU_SIG_IDX,
    IL_CAN0_RXZ1_TCU_STAT_ECU_IDX,

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

boolean il_tx_put_frame_bytes
    (
    can_hw_inst_t const         hw_inst,
    can_msg_t     const * const p_can_msg
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

void il_app_notify_tx_hw_timeout
    (
    can_hw_inst_t hw_inst,
    can_tmh_t     tmh
    );

void il_app_notify_frame_received
    (
    il_rx_frm_index_t             msg_index
    );

void il_app_notify_sig_received
    (
    il_sig_handle_t const sig_handle,   //!< [in] signal handle
    uint8           const num_bytes     //!< [in] signal size in bytes
    );

void il_app_notify_sig_changed
    (
    il_sig_handle_t         const sig_handle,
    uint8_t                 const num_bytes,
    uint32_t                     *p_sig_val
    );

void il_app_hook_sig_changed_handle
    (
    il_rx_frm_index_t             msg_index,
    il_sig_handle_t         const sig_handle,
    uint8_t                 const num_bytes
    );

void il_app_hook_sig_received_handle
    (
    il_rx_frm_index_t             msg_index,
    il_sig_handle_t         const sig_handle,
    uint8_t                 const num_bytes
    );

void il_app_notify_rx_timeout1
    (
    dll_frm_handle_t rmh,
    boolean          timeout_trig
    );

void il_app_notify_rx_timeout2
    (
    dll_frm_handle_t rmh,
    boolean          timeout_trig
    );

boolean
pack_frame_signal
    (
    uint8               const start_bit,        //!< [in] Signal Start Bit (LSbit) in CAN Frame
    can_hw_inst_t       const num_bits,         //!< [in] Number of bits in the signal
    uint8       const * const p_sig_data,       //!< [in] Pointer to the signal data
    uint8             * const p_frame_buffer,   //!< [in] Pointer to the frame buffer
    uint8               const sig_size          //!< [in] Signal size in bytes
    );

void transmit_frame
    (
    can_hw_inst_t   const hw_inst,  //!< [in] CAN hardware instance
    dll_frm_index_t const frm_index //!< [in] CAN frame index
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
