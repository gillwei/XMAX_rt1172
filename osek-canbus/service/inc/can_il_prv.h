/*!*******************************************************************
* @file can_il_prv.h
* @brief Interaction Layer Type Definitions and Data Access Functions
*
* This file contains the Interaction Layer type definitions used to
* manage the Interaction Layer transmitted and received frames and
* signals.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @ingroup can_stack_il_cfg
* @{
*
*********************************************************************/

#ifndef _CAN_IL_PRV_H
#define _CAN_IL_PRV_H

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/

typedef il_sig_handle_t         il_sig_index_t;


typedef struct tagIL_TXSIG_TYPE                         //!< transmit signal object
    {
    dll_frm_index_t             const frame_index;      //!< index of frame containing the signal
    uint8                       const start_bit;        //!< LSBit location in the frame
    uint8                       const num_bits;         //!< signal size in bits

    } il_txsig_t;


typedef struct tagIL_TX_PER_INFO_TYPE                   //!< periodic transmit frame info
    {
    uint16                      const period;           //!< transmission period in task tics
    uint16                      const start_delay;      //!< initial start delay in task tics
    uint16                      const timeout;          //!< transmit timeout in task tics
    uint16                    * const p_per_cnt;        //!< pointer to the transmit time counter
    uint16                    * const p_timeout_cnt;    //!< pointer to the transmit timeout counter

    } il_tx_per_info_t;


typedef struct tagIL_TXFRM_TYPE                         //!< transmit frame type
    {
    uint8                       const attributes;       //!< frame attributes (periodic, event triggered, etc)
    uint8                     * const p_data;           //!< pointer to transmit data
    uint8               const * const p_init_data;      //!< pointer to nitialization data
    il_sig_handle_t     const * const p_signal_list;    //!< pointer to list of signals packed in the frame
    uint8                       const num_signals;      //!< number of signals in the frame
    uint8                       const num_sig_bytes;    //!< total number of signal bytes needed to pack the frame
    uint16                      const min_delay;        //!< minimum delay between frame transmissions
    il_tx_per_info_t    const * const p_per_info;       //!< pointer to periodic information

    } il_txfrm_t;


typedef struct tagIL_TXSIG_INFO_TYPE                    //!< transmit signal information
    {
    il_txsig_t          const * const p_il_txsig;       //!< pointer to start of signal table
    il_sig_index_t              const num_signals;      //!< number of signals in the table

    } il_txsig_info_t;


typedef struct tagIL_TXFRM_INFO_TYPE                    //!< transmit frame information
    {
    il_txfrm_t          const * const p_il_txfrm;       //!< pointer to start of transmit frame table
    uint8                     * const p_status;         //!< pointer to start of transmit status byte array
    uint16                    * const p_delay_cnt;      //!< pointer to start of delay count array
    can_tmd_t           const * const p_tmd;            //!< pointer transmit data structure
    dll_frm_index_t             const num_frames;       //!< number of frames defined in the table

    } il_txfrm_info_t;


typedef struct tagIL_RXSIG_TYPE                         //!< receive signal object
    {
    uint8                       const attributes;       //!< options for signal reception handling
    uint8                       const start_bit;        //!< LSBit in the frame containing the signal
    uint8                       const num_bits;         //!< signal size in bits
    uint8                     * const p_data;           //!< pointer to receive data buffer
    uint8                       const size_p_data;      //!< size of receive data buffer (in bytes)

    } il_rxsig_t;


typedef struct tagIL_RX_PER_INFO_TYPE                   //!< periodic receive frame information
    {
    uint16                      const period;           //!< reception period in task tics
    uint16                      const timeout1;         //!< reception timeout1 in task tics
    uint16                      const timeout2;         //!< reception timeout2 in task tics
    uint16                      const terr1_rcvry;      //!< reception timeout error1 recovery in task tics
    uint16                      const terr2_rcvry;      //!< reception timeout error2 recovery in task tics
    uint16                    * const p_per_cnt;        //!< pointer to the reception periodic counter
    uint16                    * const p_timeout_cnt;    //!< pointer to the reception timeout counter
    uint16                    * const p_terr_rcvry_cnt; //!< pointer to the reception time out recovery counter

    } il_rx_per_info_t;


typedef struct tagIL_RXFRM_TYPE                         //!< receive frame type
    {
    uint8                       const attributes;       //!< frame attributes (periodic, timeout enabled, etc)
    uint8                       const dlc;              //!< Data Length Code
    uint8                       const lmin;             //!< Minimum Data Length Code that can be received
    uint8               const * const p_init_data;      //!< pointer to initialization data
    il_sig_index_t      const * const p_signal_list;    //!< pointer to list of signals in the frame
    uint8                       const num_signals;      //!< number of signals in the frame
    uint8                       const num_sig_bytes;    //!< total number of signal bytes parsed from frame
    uint8                     * const p_data;           //!< pointer to raw frame data
    il_rx_per_info_t    const * const p_per_info;       //!< pointer to periodic information

    } il_rxfrm_t;


typedef struct tagIL_RXSIG_INFO_TYPE                    //!< receive signal information
    {
    il_rxsig_t          const * const p_il_rxsig;       //!< pointer to start of received signal table
    uint8                     * const p_status;         //!< pointer to start of received signal status array
    il_sig_index_t              const num_signals;      //!< number of defined receive signals

    } il_rxsig_info_t;


typedef struct tagIL_RXFRM_INFO_TYPE                    //!< receive frame information
    {
    il_rxfrm_t          const * const p_il_rxfrm;       //!< pointer to start of receive frame table
    uint8                     * const p_status;         //!< pointer to start of receive frame status array
    dll_frm_index_t             const num_frames;       //!< number of frames in the table

    } il_rxfrm_info_t;


/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*------------------------------------------------------
Signal Reception Attributes
------------------------------------------------------*/
#define IL_RX_SIG_ATTR_DEFAULT              (0x0 << 0)
#define IL_RX_SIG_ATTR_NOTIFY               (0x1 << 0)
#define IL_RX_SIG_ATTR_NOTIFY_CHANGE        (0x1 << 1)

/*------------------------------------------------------
Conversion from Time in Milliseconds to Interaction
Layer Task Tics
------------------------------------------------------*/
#define IL_TIME_IN_TASK_TICS( msec )                        ( (uint16) ( ( ( (float) ( msec ) ) / IL_TASK_PERIOD_MS ) + 0.5 ) )

/*------------------------------------------------------
Compute MUTE/ABSENT Increment and Decrement Values
------------------------------------------------------*/
#define IL_MUTE_ABSENT_INC_DEC( _flt_int_ms, _evt_int_ms )  ( (uint8) ( ( 255.0 / ( ( (float) ( _flt_int_ms ) ) / ( (float) ( _evt_int_ms ) ) ) ) + 0.5 ) )

/*------------------------------------------------------
Transmit Frame Attributes
------------------------------------------------------*/
#define IL_TX_FRM_ATTR_DEFAULT              (0x0 << 0)
#define IL_TX_FRM_ATTR_EVENT                (0x1 << 0)
#define IL_TX_FRM_ATTR_PERIODIC             (0x1 << 1)
#define IL_TX_FRM_ATTR_MIN_DELAY            (0x1 << 2)
#define IL_TX_FRM_ATTR_NOTIFY               (0x1 << 3)
#define IL_TX_FRM_ATTR_INIT                 (0x1 << 4)
#define IL_TX_FRM_ATTR_TIMOUT_NOTIFY        (0x1 << 5)
#define IL_TX_FRM_ATTR_MUTE_NOTIFY          (0x1 << 6)

/*------------------------------------------------------
Receive Frame Attributes
------------------------------------------------------*/
#define IL_RX_FRM_ATTR_DEFAULT              (0x0 << 0)
#define IL_RX_FRM_ATTR_TIMEOUT              (0x1 << 0)
#define IL_RX_FRM_ATTR_NOTIFY               (0x1 << 1)
#define IL_RX_FRM_ATTR_ABSENT_NOTIFY        (0x1 << 2)

/*------------------------------------------------------
Signal Handle and Index Macros
------------------------------------------------------*/
#define IL_SIG_HANDLE_HWINST_MASK           (0xF000u)
#define IL_SIG_HANDLE_INDEX_MASK            (0x0FFFu)

#define IL_GET_HWINST_FROM_SIGNAL_HANDLE( _sig_handle )     ( (can_hw_inst_t)   ( ( ( _sig_handle ) & IL_SIG_HANDLE_HWINST_MASK ) >> 12 ) )
#define IL_GET_INDEX_FROM_SIGNAL_HANDLE( _sig_handle)       ( (il_sig_index_t)  ( ( _sig_handle ) & IL_SIG_HANDLE_INDEX_MASK ) )
#define IL_FORM_SIGNAL_HANDLE( _sig_index, _hw_inst )       ( (il_sig_handle_t) ( ( _sig_index ) | ( ( _hw_inst ) << 12 ) ) )


/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

il_txsig_info_t const *
il_get_txsig_info_ptr
    (
    can_hw_inst_t   const   hw_inst
    );

il_txfrm_info_t const *
il_get_txfrm_info_ptr
    (
    can_hw_inst_t   const   hw_inst
    );

il_rxsig_info_t const *
il_get_rxsig_info_ptr
    (
    can_hw_inst_t   const   hw_inst
    );

il_rxfrm_info_t const *
il_get_rxfrm_info_ptr
    (
    can_hw_inst_t   const   hw_inst
    );

#ifdef __cplusplus
}
#endif

#endif /* _CAN_IL_PRV_H */

