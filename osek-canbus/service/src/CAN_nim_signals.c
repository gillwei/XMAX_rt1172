/*!*******************************************************************
* @file CAN_nim_signals.c
* @brief CAN Stack Network Interface Signal Manager
*
* This file includes the functions that implement the portion of the
* public API of the Garmin OSEK CAN Stack that deals with transmitted
* and received CAN signals. The functions in this file allow the
* application to transmit CAN signals and retrieve received CAN signals
* of any size and format. Additional ancillary functions provide the
* support for transmitting and receiving signals atomically in
* coherent groups. Functions are also provided for checking and/or
* clearing signal changed receive flags, either one signal at a time
* or in groups.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @defgroup can_stack_nim_signals Network Interface Signal Manager
* @ingroup can_stack_nim
* @{
*
*********************************************************************/
/*--------------------------------------------------------------------
                            GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "CAN_defs.h"
#include "can_cfg.h"
#include "can_dll.h"
#include "can_il.h"
#include "can_nm.h"
//#include "can_tp.h"
//#include "can_diag.h"
#include "CAN_nim_signals.h"

/*--------------------------------------------------------------------
                            TYPES
--------------------------------------------------------------------*/
/*------------------------------------------------------

 The nim_il_error_t structure is an enumerated
 type definition that defines the internal
 Network Interface Manager error types and
 is used to track  internal CAN signal errors

------------------------------------------------------*/
typedef enum tagIL_NIM_ERROR_TYPE       //!< Interaction Layer errors
    {
    IL_NIM_TX_PUT_SIGNAL_ERROR,
    IL_NIM_TX_PUT_SIGNAL_GROUP_ERROR,
    IL_NIM_RX_GET_SIGNAL_ERROR,
    IL_NIM_RX_GET_SIGNAL_CHANGED_FLAG_ERROR,
    IL_NIM_RX_CLEAR_SIGNAL_CHANGED_FLAG_ERROR,
    IL_NIM_RX_GET_SIGNAL_GROUP_ERROR,
    IL_NIM_RX_GET_SIGNAL_GROUP_CHANGE_FLAGS_ERROR,
    IL_NIM_RX_CLEAR_SIGNAL_GROUP_CHANGE_FLAGS_ERROR,

    IL_NIM_NUM_ERRORS

    } nim_il_error_t;

/*--------------------------------------------------------------------
                            VARIABLES
--------------------------------------------------------------------*/
static volatile uint16   nim_il_error_count[IL_NIM_NUM_ERRORS] = {0};

/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/
static void log_il_error
    (
    nim_il_error_t const nim_il_error
    );

/*!*******************************************************************
*
* @public
* transmit a CAN frame into byte(s) array
*
* This function transmits a CAN signal as an array of bytes.
*
*********************************************************************/
void CAN_nim_tx_put_frame_bytes
    (
    can_hw_inst_t const   hw_inst,  //!< CAN hardware instanc
    can_tmd_t     const * p_can_tmd //!< [in] frame CAN message
    )
{
boolean l_success;

l_success = il_tx_put_frame_bytes( hw_inst, p_can_tmd );

if( FALSE == l_success )
    {
    log_il_error( IL_NIM_TX_PUT_SIGNAL_ERROR );
    }
}

/*!*******************************************************************
*
* @public
* transmit a CAN signal byte array
*
* This function transmits a CAN signal as an array of bytes. The
* signal is specified in terms of the number of bytes in the signal.
*
*********************************************************************/
void CAN_nim_tx_put_signal_bytes
    (
    il_sig_handle_t     const sig_handle,   //!< [in] signal handle
    uint8       const * const p_sig_data,   //!< [in] pointer to signal data
    uint8               const num_bytes     //!< [in] number of bytes in the signal
    )
{
boolean l_success;

l_success = il_tx_put_signal_bytes( sig_handle, p_sig_data, num_bytes );

if( FALSE == l_success )
    {
    log_il_error( IL_NIM_TX_PUT_SIGNAL_ERROR );
    }
}

/*!*******************************************************************
*
* @public
* transmit a CAN uint8 signal
*
* This function transmits a CAN signal that is one byte in size.
*
*********************************************************************/
void CAN_nim_tx_put_uint8_signal
    (
    il_sig_handle_t const sig_handle,   //!< [in] signal handle
    uint8           const sig_value     //!< [in] signal value
    )
{
boolean l_success;

l_success = il_tx_put_uint8_signal( sig_handle, sig_value );

if( FALSE == l_success )
    {
    log_il_error( IL_NIM_TX_PUT_SIGNAL_ERROR );
    }
}

/*!*******************************************************************
*
* @public
* transmit a CAN uint16 signal
*
* This function transmits a uint16 CAN signal.
*
*********************************************************************/
void CAN_nim_tx_put_uint16_signal
    (
    il_sig_handle_t const sig_handle,   //!< [in] signal handle
    uint16          const sig_value     //!< [in] signal value
    )
{
boolean l_success;

l_success = il_tx_put_uint16_signal( sig_handle, sig_value );

if( FALSE == l_success )
    {
    log_il_error( IL_NIM_TX_PUT_SIGNAL_ERROR );
    }
}

/*!*******************************************************************
*
* @public
* transmit a CAN uint32 signal
*
* This function transmits a uint32 CAN signal.
*
*********************************************************************/
void CAN_nim_tx_put_uint32_signal
    (
    il_sig_handle_t const sig_handle,   //!< [in] signal handle
    uint32          const sig_value     //!< [in] signal value
    )
{
boolean l_success;

l_success = il_tx_put_uint32_signal( sig_handle, sig_value );

if( FALSE == l_success )
    {
    log_il_error( IL_NIM_TX_PUT_SIGNAL_ERROR );
    }
}

/*!*******************************************************************
*
* @public
* transmit a CAN uint64 signal
*
* This function transmits a uint64 CAN signal.
*
*********************************************************************/
void CAN_nim_tx_put_uint64_signal
    (
    il_sig_handle_t const sig_handle,   //!< [in] signal handle
    uint64          const sig_value     //!< [in] signal value
    )
{
boolean l_success;

l_success = il_tx_put_uint64_signal( sig_handle, sig_value );

if( FALSE == l_success )
    {
    log_il_error( IL_NIM_TX_PUT_SIGNAL_ERROR );
    }
}

/*!*******************************************************************
*
* @public
* transmit a CAN signal group
*
* This function transmits a group of CAN signals coherently. The
* signals that are transmitted must all be contained in the specified
* message frame.
*
*********************************************************************/
void CAN_nim_tx_put_signal_group
    (
    dll_frm_handle_t        const frm_handle,           //!< [in] CAN message frame handle
    il_txsig_put_t  const * const p_txsig_put_list,     //!< [in] pointer to array of signals to transmit
    uint8                   const num_signals           //!< [in] number of signals to transmit
    )
{
boolean l_success;

l_success = il_tx_put_signal_group( frm_handle, p_txsig_put_list, num_signals );

if( FALSE == l_success )
    {
    log_il_error( IL_NIM_TX_PUT_SIGNAL_GROUP_ERROR );
    }
}

/*!*******************************************************************
*
* @public
* get a CAN signal as an array of bytes
*
* This function gets a received CAN signal as an array of bytes.
*
*********************************************************************/
void CAN_nim_rx_get_signal_bytes
    (
    il_sig_handle_t const sig_handle,   //!< [in] signal handle
    uint8         * const p_sig_data,   //!< [out] pointer to received signal data
    uint8           const num_bytes     //!< [in] number of signal bytes to get
    )
{
boolean l_success;

l_success =  il_rx_get_signal_bytes( sig_handle, p_sig_data, num_bytes );

if( FALSE == l_success )
    {
    log_il_error( IL_NIM_RX_GET_SIGNAL_ERROR );
    }
}

/*!*******************************************************************
*
* @public
* receive a CAN uint8 signal
*
* This function gets a received uint8 CAN signal value.
*
*********************************************************************/
void CAN_nim_rx_get_uint8_signal
    (
    il_sig_handle_t const sig_handle,   //!< [in] signal handle
    uint8                *p_signal      //!< [out] pointer to signal value
    )
{
boolean l_success;

l_success = il_rx_get_uint8_signal( sig_handle, p_signal );

if( FALSE == l_success )
    {
    log_il_error( IL_NIM_RX_GET_SIGNAL_ERROR );
    }
}

/*!*******************************************************************
*
* @public
* receive a CAN uint16 signal
*
* This function gets a received uint16 CAN signal value.
*
*********************************************************************/
void CAN_nim_rx_get_uint16_signal
    (
    il_sig_handle_t const sig_handle,   //!< [in] signal handle
    uint16               *p_signal      //!< [out] pointer to signal value
    )
{
boolean l_success;

l_success = il_rx_get_uint16_signal( sig_handle, p_signal );

if( FALSE == l_success )
    {
    log_il_error( IL_NIM_RX_GET_SIGNAL_ERROR );
    }
}

/*!*******************************************************************
*
* @public
* receive a CAN uint32 signal
*
* This function gets a received uint32 CAN signal value.
*
*********************************************************************/
void CAN_nim_rx_get_uint32_signal
    (
    il_sig_handle_t const sig_handle,   //!< [in] signal handle
    uint32               *p_signal      //!< [out] pointer to signal value
    )
{
boolean l_success;

l_success = il_rx_get_uint32_signal( sig_handle, p_signal );

if( FALSE == l_success )
    {
    log_il_error( IL_NIM_RX_GET_SIGNAL_ERROR );
    }
}

/*!*******************************************************************
*
* @public
* receive a CAN uint64 signal
*
* This function gets a received uint64 CAN signal value.
*
*********************************************************************/
void CAN_nim_rx_get_uint64_signal
    (
    il_sig_handle_t const sig_handle,   //!< [in] signal handle
    uint64        * const p_signal      //!< [out] pointer to signal value
    )
{
boolean l_success;

l_success = il_rx_get_uint64_signal( sig_handle, p_signal );

if( FALSE == l_success )
    {
    log_il_error( IL_NIM_RX_GET_SIGNAL_ERROR );
    }
}

/*!*******************************************************************
*
* @public
* get a CAN signal's change flag status
*
* This function gets a received CAN signal's change flag status which
* is used to determine if the received signal value has changed since
* the flag was last cleared.
*
*********************************************************************/
void CAN_nim_rx_get_signal_changed_flag
    (
    il_sig_handle_t const sig_handle,   //!< [in] signal handle
    boolean       * const p_flag        //!< [out] pointer to change flag result
    )
{
boolean l_success;

l_success = il_rx_get_signal_changed_flag( sig_handle, p_flag );

if( FALSE == l_success )
    {
    log_il_error( IL_NIM_RX_GET_SIGNAL_CHANGED_FLAG_ERROR );
    }
}

/*!*******************************************************************
*
* @public
* clear a CAN signal's change flag
*
* This function clears a received CAN signal's change flag.
*
*********************************************************************/
void CAN_nim_rx_clear_signal_changed_flag
    (
    il_sig_handle_t const sig_handle    //!< [in] signal handle
    )
{
boolean l_success;

l_success =  il_rx_clear_signal_changed_flag( sig_handle );

if( FALSE == l_success )
    {
    log_il_error( IL_NIM_RX_CLEAR_SIGNAL_CHANGED_FLAG_ERROR );
    }
}

/*!*******************************************************************
*
* @public
* get an array of CAN signals
*
* This function gets an array of signals and all of the bytes in each
* signal. The "il_rxsig_get_t" data structure includes information
* about each signal to retrieve along with a pointer to the data
* buffer where the received signal bytes are to be written. The
* signals to be retrieved may be contained in one or more separate
* CAN message frames and may even be on different networks.
*
*********************************************************************/
void CAN_nim_rx_get_signal_group
    (
    il_rxsig_get_t  const * const p_rxsig_get_list,     //!< [in, out] pointer to array of signal info
    uint8                   const num_signals           //!< [in] number of signals to get
    )
{
boolean l_success;

l_success =  il_rx_get_signal_group( p_rxsig_get_list, num_signals );

if( FALSE == l_success )
    {
    log_il_error( IL_NIM_RX_GET_SIGNAL_GROUP_ERROR );
    }
}

/*!*******************************************************************
*
* @public
* get the signal change status for a group of CAN signals
*
* This function retrieves a received CAN signal group's change status
* flags
*
*********************************************************************/
void CAN_nim_rx_get_signal_group_changed_flags
    (
    il_sig_handle_t const * const p_rx_sig_list,    //!< [in] pointer to array of signal handles
    boolean               * const p_flags,          //!< [out] pointer to returned flag values
    uint8                   const num_signals       //!< [in] number of signal flags to get
    )
{
boolean l_success;

l_success =  il_rx_get_signal_group_changed_flags( p_rx_sig_list, p_flags, num_signals );

if( FALSE == l_success )
    {
    log_il_error( IL_NIM_RX_GET_SIGNAL_GROUP_CHANGE_FLAGS_ERROR );
    }
}

/*!*******************************************************************
*
* @public
* clear the signal change status for a group of CAN signals
*
* This function clears a received CAN signal group's change status
* flags
*
*********************************************************************/
void CAN_nim_rx_clear_signal_group_changed_flags
    (
    il_sig_handle_t const * const p_rx_sig_list,    //!< [in] pointer to array of signal handles
    uint8                   const num_signals       //!< [in] number of signals to clear flags
    )
{
boolean     l_success;

l_success =  il_rx_clear_signal_group_changed_flags( p_rx_sig_list, num_signals );

if( FALSE == l_success )
    {
    log_il_error( IL_NIM_RX_CLEAR_SIGNAL_GROUP_CHANGE_FLAGS_ERROR );
    }
}

/*!*******************************************************************
*
* log a Network Interface Manager error event
*
* This function logs a Network Interface Manager error event.
*
*********************************************************************/
static void log_il_error
    (
    nim_il_error_t const nim_il_error   //!< [in] NIM Interaction Layer error type
    )
{
nim_il_error_count[nim_il_error]++;
}

