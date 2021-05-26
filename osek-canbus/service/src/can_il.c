/*!*******************************************************************
* @file can_il.c
* @brief OSEK CAN Stack Interaction Layer
*
* This file implements the Garmin CAN Stack Interaction Layer.
* The Interaction Layer supports transmission and reception of
* the application signals and message frames. A signal abstraction
* is supported in that signals may be transmitted and received as
* independent objects, irrespective of the actual low level CAN
* message frame in which the signal resides. The Interaction Layer
* takes care of parsing signals from received frames using
* information derived from a CAN database as to the size of a signal
* (number of bits) and where the signal resides, i.e. which CAN frame
* as defined by its ID and which bits in the CAN frame.
* The Interaction Layer also manages the packing of transmitted
* signals into the appropriate CAN frames and in the correct bit
* position.
*
* The Interaction Layer also issues notifications to the application
* regarding signal reception, received signal change and successful
* frame transmission. These notifications must be enabled using a
* CAN configuration tool that generates input data structures that
* define these behaviors.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @defgroup can_stack_il Interaction Layer
* @ingroup can_stack
* @{
*
*********************************************************************/

/*--------------------------------------------------------------------
                            GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "can_defs.h"
#include "can_bcfg.h"
#include "can_cfg.h"
#include "can_util.h"

#include "can_drv.h"
#include "can_dll.h"
#include "can_dll_prv_par.h"
#include "can_il.h"
#include "can_il_prv.h"
#include "can_il_prv_par.h"

#include "fsl_debug_console.h"
#include "FreeRTOS.h"
#include "task.h"
#include <string.h>

/*--------------------------------------------------------------------
                            MACROS
--------------------------------------------------------------------*/
/*------------------------------------------------------
Macros used to compute the number of bytes in a given
number of bits
------------------------------------------------------*/
#define IL_MODULO8( _byte )     ( ( _byte ) & 0x07 )
#define IL_DIV_BY_8( _byte )    ( ( _byte ) >> 3 )

/*------------------------------------------------------
Transmit frame status bit definitions
------------------------------------------------------*/
#define IL_TX_STATUS_EVENT_PENDING          (0x1 << 0)
#define IL_TX_STATUS_PERIODIC_PENDING       (0x1 << 1)
#define IL_TX_STATUS_TX_IN_PROGRESS         (0x1 << 2)
#define IL_TX_STATUS_TXC_NOTIFY             (0x1 << 3)
#define IL_TX_STATUS_TX_TIMEOUT_NOTIFY      (0x1 << 4)
#define IL_TX_STATUS_MUTE_FAULT             (0x1 << 5)

/*------------------------------------------------------
Transmit Frame Maximum Mute Count
------------------------------------------------------*/
#define IL_TX_MAX_MUTE_COUNT                (0xFF)

/*------------------------------------------------------
At least one type of transmission is pending
------------------------------------------------------*/
#define IL_ANY_TX_PENDING                   ( IL_TX_STATUS_EVENT_PENDING        |   \
                                              IL_TX_STATUS_PERIODIC_PENDING )

/*------------------------------------------------------
Receive Frame timeout error 2 judge conditions number
------------------------------------------------------*/
#define IL_RX_TOE2_JUDGE_COND_NUM           (3)

/*------------------------------------------------------
Interaction layer status bits
------------------------------------------------------*/
#define IL_STATUS_DISABLE                   (0x1 << 0)
#define IL_STATUS_SUSPEND                   (0x1 << 1)
#define IL_STATUS_TX_SUSPEND                (0x1 << 2)
#define IL_STATUS_TX_TIMEOUT_DISABLE        (0x1 << 3)
#define IL_STATUS_RX_TIMEOUT_DISABLE        (0x1 << 4)

/*------------------------------------------------------
Disable any pending transmission type
------------------------------------------------------*/
#define IL_STATUS_ANY_TX_DISABLE            ( IL_STATUS_DISABLE )

/*--------------------------------------------------------------------
                            TYPES
--------------------------------------------------------------------*/
/*------------------------------------------------------
The il_sig_frm_coords_t data structure defines the
"coordinates" for a signal packed into a CAN frame. This
includes the "byte, bit coordinates" of the signal,
including the first byte in which the signal starts and
the specific bit within that byte. It also includes the
ending position defined by the end byte as well as the
end bit in that byte. A CAN frame has 8 bytes where the
first byte is considered byte 0 and the last byte is
considered byte 7. The bit order within a byte is MSBit
first which implies that the first data bit in the data
field of a CAN frame is bit 7 within byte 0.
------------------------------------------------------*/
typedef struct tagIL_SIG_FRM_COORDS_TYPE
    {
    uint8   start_byte;
    uint8   start_bit_pos;
    uint8   end_byte;
    uint8   end_bit_pos;

    } il_sig_frm_coords_t;

typedef struct tagIL_FRM_RX_NEW_STATUS_TYPE
    {
    dll_frm_handle_t  frm_handle;
    uint8             frm_rx_new ;

    }il_frm_rx_new_stat_t;

/*--------------------------------------------------------------------
                            VARIABLES
--------------------------------------------------------------------*/
/*------------------------------------------------------
Bit width masks used for unpacking bytes in a frame
------------------------------------------------------*/
static uint8   const
il_bit_width_masks[( CAN_MAX_DATA_LENGTH + 1 )] =
    { 0x00u, 0x01u, 0x03u, 0x07u, 0x0Fu, 0x1Fu, 0x3Fu, 0x7Fu, 0xFFu };

/*------------------------------------------------------
IL status for each CAN logical instance
------------------------------------------------------*/
static uint8   il_status[CAN_NUM_INSTANCES];

/*------------------------------------------------------
IL timeout error check start cnt
------------------------------------------------------*/
uint16  il_timeout_err_check_cnt = IL_RX_TIMEOUT_CHECK_START_TICK;

/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/
/*!*******************************************************************
*
* set transmit frame event pending
*
* This function supports an Interaction Layer implementation in which
* frames transmitted with the "Event" model (Event or Periodic +
* Event) must be transmitted in synchronization with the transmit task
* tick as opposed to asynchronously in between ticks.
*
*********************************************************************/
static void set_transmit_frame_event_pending
    (
    can_hw_inst_t   const hw_inst,  //!< [in] CAN hardware instance
    dll_frm_index_t const frm_index //!< [in] CAN frame index
    )
{
il_txfrm_info_t const * l_p_txfrm_info;
uint8                 * l_p_status;

/*------------------------------------------------------
Check if Interaction Layer transmission is disabled for
any reason before attempting to set the event flag.
------------------------------------------------------*/
if( 0 == ( il_status[hw_inst] & IL_STATUS_ANY_TX_DISABLE ) )
    {
    /*------------------------------------------------------
    Get the frame information.
    ------------------------------------------------------*/
    l_p_txfrm_info = il_get_txfrm_info_ptr( hw_inst );
    l_p_status     = &( l_p_txfrm_info->p_status[frm_index] );

    /*------------------------------------------------------
    Set the Event pending flag to transmit on the next tick.
    ------------------------------------------------------*/
    can_util_set_status_bits( l_p_status, IL_TX_STATUS_EVENT_PENDING );
    }
}

/*!*******************************************************************
*
* transmit an Interaction Layer CAN frame
*
* This function attempts to transmit an Interaction Layer CAN frame
* as soon as possible. This function assumes that all range checking
* for the frame index and the hardware instance have already been done
* and these parameters are valid. This function will attempt to
* transmit the frame immediately unless the frame has a minimum
* transmit delay requirement that has not yet been met. In this case
* the frame transmission isn't transmitted until the minimum delay
* for the frame has expired.
*
*********************************************************************/
void transmit_frame
    (
    can_hw_inst_t   const hw_inst,  //!< [in] CAN hardware instance
    dll_frm_index_t const frm_index //!< [in] CAN frame index
    )
{
il_txfrm_info_t const * l_p_txfrm_info;
il_txfrm_t      const * l_p_txfrm;
uint8                 * l_p_status;
can_tmd_t       const * l_p_tmd;
uint16                * l_p_delay_count;
boolean                 l_wait_tx;

/*------------------------------------------------------
Check if Interaction Layer transmission is disabled for
any reason before transmitting the frame
------------------------------------------------------*/
if( 0 == ( il_status[hw_inst] & IL_STATUS_ANY_TX_DISABLE ) )
    {
    /*------------------------------------------------------
    Get the frame information and initially assume the
    minimum wait delay is inactive
    ------------------------------------------------------*/
    l_p_txfrm_info = il_get_txfrm_info_ptr( hw_inst );
    l_p_txfrm      = &( l_p_txfrm_info->p_il_txfrm[frm_index] );
    l_p_status     = &( l_p_txfrm_info->p_status[frm_index] );
    l_wait_tx      = FALSE;

    /*------------------------------------------------------
    Check if minimum wait delay is enabled for this frame
    ------------------------------------------------------*/
    if( ( l_p_txfrm->attributes & IL_TX_FRM_ATTR_MIN_DELAY ) != 0 )
        {
        /*------------------------------------------------------
        Check the delay counter and see if this frame can be
        transmitted immediately
        ------------------------------------------------------*/
        l_p_delay_count = &( l_p_txfrm_info->p_delay_cnt[frm_index] );

        if( *( l_p_delay_count ) != 0 )
            {
            /*------------------------------------------------------
            Need to wait... set the event pending status bit so the
            frame is transmitted when the delay counter times out.
            ------------------------------------------------------*/
            l_wait_tx = TRUE;
            set_transmit_frame_event_pending( hw_inst, frm_index );
            }
        else
            {
            /*------------------------------------------------------
            The frame can be transmitted immediately. Reset the
            delay counter for the next transmission.
            ------------------------------------------------------*/
            *( l_p_delay_count ) = l_p_txfrm->min_delay;
            }
        }

    if( FALSE == l_wait_tx )
        {
        /*------------------------------------------------------
        Transmit the frame now and clear all of the transmit
        pending status bits
        ------------------------------------------------------*/
        l_p_tmd = &( l_p_txfrm_info->p_tmd[frm_index] );

        (void) can_transmit( hw_inst, l_p_tmd );
        can_util_clear_status_bits( l_p_status, IL_ANY_TX_PENDING );
        }
    }
}

/*!*******************************************************************
*
* disable transmit message timeouts
*
* This function disables transmit message timeouts.
*
*********************************************************************/
static void disable_tx_msg_timeouts
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
Set the "disable transmit timeout" status bit
------------------------------------------------------*/
can_util_set_status_bits( &il_status[hw_inst],
                          IL_STATUS_TX_TIMEOUT_DISABLE );
}

/*!*******************************************************************
*
* enable transmit message timeouts
*
* This function enables transmit message timeouts and also resets
* the transmit timeout counters to their initial values.
*
*********************************************************************/
static void enable_tx_msg_timeouts
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
il_txfrm_info_t     const * l_p_txfrm_info;
il_txfrm_t          const * l_p_txfrm;
dll_frm_index_t             l_i_frm_index;
dll_frm_index_t             l_num_frames;

/*------------------------------------------------------
Get the pointer to the transmit information and the
number of transmit frames.
------------------------------------------------------*/
l_p_txfrm_info = il_get_txfrm_info_ptr( hw_inst );
l_num_frames   = l_p_txfrm_info->num_frames;

for( l_i_frm_index = 0; l_i_frm_index < l_num_frames; l_i_frm_index++ )
    {
    /*------------------------------------------------------
    Get the pointer to the periodic transmit information
    for this frame. If it's valid, disable the transmit
    timeout counter (clear it to zero) to prevent false
    transmit timeout detection. The transmit timeout counter
    is enabled (set) at the next transmit timeout event.
    ------------------------------------------------------*/
    l_p_txfrm = &( l_p_txfrm_info->p_il_txfrm[l_i_frm_index] );

    if( l_p_txfrm->p_per_info != NULL )
        {
        *( l_p_txfrm->p_per_info->p_timeout_cnt ) = 0;
        }
    }

/*------------------------------------------------------
Clear the "disable transmit timeout" status bit
------------------------------------------------------*/
can_util_clear_status_bits( &( il_status[hw_inst] ),
                            IL_STATUS_TX_TIMEOUT_DISABLE );
}

/*!*******************************************************************
*
* disable receive message timeouts
*
* This function disables receive message timeouts.
*
*********************************************************************/
static void disable_rx_msg_timeouts
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
Set the "disable receive timeout" status bit
------------------------------------------------------*/
can_util_set_status_bits( &il_status[hw_inst],
                          IL_STATUS_RX_TIMEOUT_DISABLE );
}

/*!*******************************************************************
*
* get signal size in bytes
*
* This function determines the number of bytes needed to contain a
* signal based on the number of bits in the signal.
*
* @return uint8
* number of bytes
*
*********************************************************************/
static uint8 get_signal_size_in_bytes
    (
    uint8   const num_bits          //!< number of signal bits
    )
{
uint8   l_num_bytes;

/*------------------------------------------------------
Convert number of bits in a signal to the minimum number
of bytes needed to contain the signal
------------------------------------------------------*/
l_num_bytes = IL_DIV_BY_8( num_bits );

if( IL_MODULO8( num_bits ) != 0 )
    {
    l_num_bytes += 1;
    }

return l_num_bytes;
}

/*!*******************************************************************
*
* enable receive message timeouts
*
* This function enables receive message timeouts and also resets the
* receive timeout counters to their initial values.
*
*********************************************************************/
static void enable_rx_msg_timeouts
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
il_rxfrm_info_t     const * l_p_rxfrm_info;
il_rxfrm_t          const * l_p_rxfrm;
dll_frm_index_t             l_i_frm_index;
dll_frm_index_t             l_num_frames;

/*------------------------------------------------------
Get the pointer to the receive information and the
number of receive frames. Initialize the periodic
timeout count of all of the receive frames that have
valid periodic receive information.
------------------------------------------------------*/
l_p_rxfrm_info = il_get_rxfrm_info_ptr( hw_inst );
l_num_frames   = l_p_rxfrm_info->num_frames;

for( l_i_frm_index = 0; l_i_frm_index < l_num_frames; l_i_frm_index++ )
    {
    /*------------------------------------------------------
    Check for a periodic received frame
    ------------------------------------------------------*/
    l_p_rxfrm = &( l_p_rxfrm_info->p_il_rxfrm[l_i_frm_index] );

    if( l_p_rxfrm->p_per_info != NULL )
        {
        /*------------------------------------------------------
        Reset the timeout and the frame status bits related to
        frame gain and loss to allow for new notifications.
        ------------------------------------------------------*/
        *( l_p_rxfrm->p_per_info->p_timeout_cnt ) = 0;

        can_util_clear_status_bits( &( l_p_rxfrm_info->p_status[l_i_frm_index] ),
                                    ( IL_RX_STATUS_PENDING       |
                                      IL_RX_STATUS_TIMEOUT1      |
                                      IL_RX_STATUS_TIMEOUT2      |
                                      IL_RX_STATUS_LOSS_NOTIFIED |
                                      IL_RX_STATUS_TIMEOUT2_DIS ) );
        }
    }

/*------------------------------------------------------
Clear the "disable receive timeout" status bit
------------------------------------------------------*/
can_util_clear_status_bits( &( il_status[hw_inst] ),
                            IL_STATUS_RX_TIMEOUT_DISABLE );
}

/*!*******************************************************************
*
* save received CAN frame for subsequent processing
*
* This function saves a received CAN frame for subsequent processing
* by the periodic receive task.
*
*********************************************************************/
static void save_receive_frame
    (
    can_hw_inst_t           const hw_inst,    //!< [in] CAN hardware instance
    can_rmd_t       const * const p_rmd,      //!< [in] pointer to received CAN frame
    dll_frm_index_t         const frame_index //!< [in] CAN frame index
    )
{
il_rxfrm_info_t     const * l_p_rxfrm_info;
il_rx_per_info_t    const * l_p_per_info;
il_rxfrm_t          const * l_p_rxfrm;
uint8                     * l_p_status;
dll_frm_index_t             l_num_frames;
uint8                       l_rmd_dlc;
uint8                       l_i_byte;
uint8                       l_temp_data[CAN_MAX_DATA_LENGTH];
boolean                     l_data_changed;

/*------------------------------------------------------
Get the pointer to the receive frame information and
the number of frames defined for this CAN hardware
instance. Check that the fame index is within a valid
range of index values for this instance. Also check
that the pointer to the RMD (Receive Message Data
structure) is not a NULL pointer.
------------------------------------------------------*/
l_p_rxfrm_info = il_get_rxfrm_info_ptr( hw_inst );
l_num_frames   = l_p_rxfrm_info->num_frames;

if( ( frame_index < l_num_frames ) && ( p_rmd != NULL ) )
    {
    /*------------------------------------------------------
    Get the frame information, status and length. Check the
    received frame length against the expected frame length.
    If the received frame is as long or longer than Lmin
    consider it valid and get the received data.
    ------------------------------------------------------*/
    l_p_rxfrm  = &( l_p_rxfrm_info->p_il_rxfrm[frame_index] );
    l_p_status = &( l_p_rxfrm_info->p_status[frame_index] );
    l_p_per_info = l_p_rxfrm->p_per_info;
    l_rmd_dlc    = p_rmd->dlc;
    if( l_rmd_dlc >= l_p_rxfrm->lmin )
        {
        /*------------------------------------------------------
        Copy the received data into the local buffer. Zero any
        bytes greater than the actual received length up to the
        expected length.
        ------------------------------------------------------*/
        for( l_i_byte = 0; l_i_byte < l_p_rxfrm->dlc; l_i_byte++ )
            {
            if( l_i_byte < l_rmd_dlc )
                {
                l_temp_data[l_i_byte] = p_rmd->data[l_i_byte];
                }
            else
                {
                l_temp_data[l_i_byte] = 0;
                }
            }

        /*------------------------------------------------------
        Compare the adjusted received frame data with the stored
        frame data to determine if any signal in the frame has
        changed in value. If no signal has changed then there's
        no need to parse the received frame data when the
        stored frame is subsequently processed.
        ------------------------------------------------------*/
        l_data_changed = FALSE;

        for(   l_i_byte = 0;
           ( ( l_i_byte < l_p_rxfrm->dlc ) && ( FALSE == l_data_changed ) );
               l_i_byte++ )
            {
            if( l_p_rxfrm->p_data[l_i_byte] != l_temp_data[l_i_byte] )
                {
                l_data_changed = TRUE;
                }
            }

        /*------------------------------------------------------
        If any one byte has changed then copy the entire frame
        into the frame data buffer and set the status flag that
        the frame data has changed. This implies the frame will
        need to be parsed when it is processed in the receive
        task.
        ------------------------------------------------------*/
        if( ( l_data_changed != FALSE ) || ( l_p_per_info == NULL ) )
            {
            can_util_set_status_bits( l_p_status, IL_RX_STATUS_DATA_CHANGED );
            can_util_copy_bytes( l_temp_data, l_p_rxfrm->p_data, l_p_rxfrm->dlc );
            }

        /*------------------------------------------------------
        Set the Receive Pending flag so this frame will be
        processed in the receive task
        ------------------------------------------------------*/
        can_util_set_status_bits( l_p_status, IL_RX_STATUS_PENDING );
        }
    }
}

/*!*******************************************************************
*
* get signal frame coordinates
*
* This function converts a signal "start_bit, num_bits" format (as is
* used in the Vector CAN database) for specifying the bit fields of a
* signal packed in a CAN frame to a format that specifies the
* starting byte and the start bit position in that byte, and the end
* byte and the end bit position in the end byte. A "plausiblity check"
* is performed on the passed in values such that if the resultant
* converted coordinates are out of range a "FALSE" indication is
* returned for the success value.
*
* @return boolean
* success (TRUE or FALSE)
*
*********************************************************************/
static boolean
get_sig_frm_coords
    (
    uint8                   const start_bit,            //!< [in] start bit position (from CAN database)
    uint8                   const num_bits,             //!< [in] number of bits in the signal
    il_sig_frm_coords_t   * const p_sig_frm_coords      //!< [out] pointer to returned signal coordinates
    )
{
uint8           l_end_byte;
uint8           l_end_bit_pos;
uint8           l_start_byte;
uint8           l_start_bit_pos;
boolean         l_success;

/*------------------------------------------------------
Initialize the returned success value
------------------------------------------------------*/
l_success = TRUE;

/*------------------------------------------------------
Divide the database start_bit (LSbit) by 8 to get the
end byte and database start_bit modulo 8 is the end bit
position
------------------------------------------------------*/
l_end_byte    = IL_DIV_BY_8( start_bit );
l_end_bit_pos = IL_MODULO8( start_bit );

/*------------------------------------------------------
Determine the start byte and the start bit position in
the start byte
------------------------------------------------------*/
l_start_bit_pos = l_end_bit_pos + num_bits - 1;
l_start_byte    = l_end_byte - ( IL_DIV_BY_8( l_start_bit_pos ) );
l_start_bit_pos = IL_MODULO8( l_start_bit_pos );

/*------------------------------------------------------
Check the plausibility of the computed coordinates
------------------------------------------------------*/
if( ( l_start_byte    <  CAN_MAX_DATA_LENGTH )      &&
    ( l_start_bit_pos <  IL_NUM_BITS_IN_BYTE )      &&
    ( l_end_byte      <  CAN_MAX_DATA_LENGTH )      &&
    ( l_end_bit_pos   <  IL_NUM_BITS_IN_BYTE )      &&
    ( l_end_byte      >= l_start_byte ) )
    {
    /*------------------------------------------------------
    Return the signal byte and bit position coordinates
    ------------------------------------------------------*/
    p_sig_frm_coords->start_byte    =  l_start_byte;
    p_sig_frm_coords->start_bit_pos =  l_start_bit_pos;
    p_sig_frm_coords->end_byte      =  l_end_byte;
    p_sig_frm_coords->end_bit_pos   =  l_end_bit_pos;
    }
else
    {
    l_success = FALSE;

    p_sig_frm_coords->start_byte    =  IL_FIRST_BYTE_IN_FRAME_DATA;
    p_sig_frm_coords->start_bit_pos =  IL_FIRST_BIT_IN_BYTE;
    p_sig_frm_coords->end_byte      =  IL_LAST_BYTE_IN_FRAME_DATA;
    p_sig_frm_coords->end_bit_pos   =  IL_LAST_BIT_IN_BYTE;
    }

return l_success;
}

/*!*******************************************************************
*
* parse a CAN signal from an Interaction Layer CAN frame
*
* This function parses a CAN signal from a CAN frame and stores it in
* the indicated signal buffer (p_sig_buffer).
*
* @return boolean
* success (TRUE or FALSE)
*
*********************************************************************/
static boolean
parse_frame_signal
    (
    uint8               const start_bit,        //!< [in] signal start bit in CAN frame
    can_hw_inst_t       const num_bits,         //!< [in] number of bits in the signal
    uint8       const * const p_frame_data,     //!< [in] pointer to CAN frame data
    uint8             * const p_sig_buffer,     //!< [out] pointer to parsed signal data
    uint8               const sig_size          //!< [in] signal size in bytes
    )
{
uint8                   l_working_buffer[CAN_MAX_DATA_LENGTH];
uint8                   l_num_sig_bytes;
il_sig_frm_coords_t     l_sig_frm_coords;
uint8                   l_i_byte;
uint8                   l_num_working_bytes;
uint8                   l_first_byte;
uint8                   l_num_left_shift;
uint8                   l_num_right_shift;
uint8                   l_bit_mask;
uint8                   l_temp_byte;
uint8                   l_num_bits_modulo8;
boolean                 l_success;

/*------------------------------------------------------
Initialize the return value, get the signal size in
bytes and check that the write buffer is the expected
size. If not then at a minimum the returned value will
not be correct. This check also prevents writes that
exceed the specified buffer size.
------------------------------------------------------*/
l_success       = FALSE;
l_num_sig_bytes = get_signal_size_in_bytes( num_bits );

if( l_num_sig_bytes == sig_size )
    {
    /*------------------------------------------------------
    Get the signal byte and bit coordinates within the CAN
    frame data field as a function of the start bit (LSBit
    location) in the frame and the number of bits in the signal
    ------------------------------------------------------*/
    l_success = get_sig_frm_coords( start_bit, num_bits, &l_sig_frm_coords );

    if( l_success != FALSE )
        {
        /*------------------------------------------------------
        Check if the signal is contained in one byte (this is
        the most typical case)
        ------------------------------------------------------*/
        if( l_sig_frm_coords.start_byte == l_sig_frm_coords.end_byte )
            {
            /*------------------------------------------------------
            Get the byte that contains the signal and check for a
            signal that's less than 8 bits
            ------------------------------------------------------*/
            l_temp_byte = p_frame_data[l_sig_frm_coords.start_byte];

            if( num_bits < IL_NUM_BITS_IN_BYTE )
                {
                /*------------------------------------------------------
                Shift and mask the signal
                ------------------------------------------------------*/
                l_temp_byte =  l_temp_byte >> l_sig_frm_coords.end_bit_pos;
                l_bit_mask  =  il_bit_width_masks[num_bits];
                l_temp_byte &= l_bit_mask;
                }

            /*------------------------------------------------------
            Store the extracted signal
            ------------------------------------------------------*/
            p_sig_buffer[0] = l_temp_byte;
            }
        /*------------------------------------------------------
        Check if the signal is more than one byte, an exact
        multiple of  8 bits and aligned on byte boundaries
        (MSbit is bit 7 and LSbit is bit 0)
        ------------------------------------------------------*/
        else if( ( IL_FIRST_BIT_IN_BYTE == l_sig_frm_coords.start_bit_pos )   &&
                 ( IL_LAST_BIT_IN_BYTE  == l_sig_frm_coords.end_bit_pos ) )
            {
            /*------------------------------------------------------
            The bytes can be copied directly with no shifting or masking
            ------------------------------------------------------*/
            can_util_copy_bytes( &( p_frame_data[l_sig_frm_coords.start_byte] ),
                                 &( p_sig_buffer[0] ),
                                 sig_size );
            }

        /*------------------------------------------------------
        Check if the end of the signal is aligned on a byte
        boundary
        ------------------------------------------------------*/
        else if( 0 == l_sig_frm_coords.end_bit_pos )
            {
            /*------------------------------------------------------
            In this case all of the bytes can be copied directly
            without shifting but the first byte will need to have
            non-signal bits masked off
            ------------------------------------------------------*/
            can_util_copy_bytes( &( p_frame_data[l_sig_frm_coords.start_byte] ),
                                 &( p_sig_buffer[0] ),
                                 sig_size );

            /*------------------------------------------------------
            Determine the first mask from the signal first bit position
            ------------------------------------------------------*/
            l_bit_mask =  il_bit_width_masks[( l_sig_frm_coords.start_bit_pos + 1 )];
            p_sig_buffer[0] &= l_bit_mask;
            }
        else
            {
            /*------------------------------------------------------
            The packed bytes will need to be shifted and masked...
            Copy all of the bytes that have any part of the signal
            to the working buffer.
            ------------------------------------------------------*/
            l_num_working_bytes = l_sig_frm_coords.end_byte - l_sig_frm_coords.start_byte + 1;

            can_util_copy_bytes( &( p_frame_data[l_sig_frm_coords.start_byte] ),
                                 &( l_working_buffer[0] ),
                                 l_num_working_bytes );

            l_num_right_shift = l_sig_frm_coords.end_bit_pos;
            l_num_left_shift  = ( IL_NUM_BITS_IN_BYTE - l_num_right_shift );
            l_bit_mask        = il_bit_width_masks[l_num_right_shift];

            /*------------------------------------------------------
            Shift right all but the first byte and add in the
            shifted out bits from the previous byte
            ------------------------------------------------------*/
            for( l_i_byte = l_num_working_bytes - 1; l_i_byte > 0; l_i_byte-- )
                {
                l_working_buffer[l_i_byte] = l_working_buffer[l_i_byte] >> l_num_right_shift;
                l_temp_byte = ( l_working_buffer[l_i_byte - 1] & l_bit_mask ) << l_num_left_shift;
                l_working_buffer[l_i_byte] |= l_temp_byte;
                }

            /*------------------------------------------------------
            Determine the first valid byte in the working buffer
            that has any signal bits
            ------------------------------------------------------*/
            if( l_num_working_bytes > sig_size )
                {
                l_first_byte = 1;
                }
            else
                {
                l_first_byte = 0;

                /*------------------------------------------------------
                The first byte needs to be right shifted
                ------------------------------------------------------*/
                l_working_buffer[0] =  l_working_buffer[0] >> l_num_right_shift;
                }

            /*------------------------------------------------------
            Determine the number of bits to keep in the first byte.
            This will be the modulo 8 result of the number of bits.
            If the number of bits is a multiple of 8 then the
            modulus is 0, but in this case all 8 bits are kept.
            ------------------------------------------------------*/
            l_num_bits_modulo8 = IL_MODULO8( num_bits );

            if( l_num_bits_modulo8 != 0 )
                {
                l_bit_mask = il_bit_width_masks[l_num_bits_modulo8];
                l_working_buffer[l_first_byte] &= l_bit_mask;
                }

            /*------------------------------------------------------
            Copy the working bytes to the return signal buffer
            ------------------------------------------------------*/
            can_util_copy_bytes( &( l_working_buffer[l_first_byte] ),
                                 &( p_sig_buffer[0] ),
                                 sig_size );
            }
        }
    }

return l_success;
}

/*!*******************************************************************
*
* parse and process a received Interaction Layer CAN frame
*
* This function parses a received CAN frame and updates all of the
* saved signals packed into that frame if parsing is enabled for the
* received frame. This function also issues frame reception,
* signal reception and signal change notifications if notifications
* are enabled.
*
*********************************************************************/
static void process_receive_frame
    (
    can_hw_inst_t   const hw_inst,       //!< [in] CAN hardware instance
    dll_frm_index_t const frm_index,     //!< [in] receive frame index
    boolean         const notify_enable, //!< [in] enable for notification callbacks
    boolean         const parse_enable   //!< [in] enable for parsing the received frame
    )
{
il_rxfrm_info_t     const * l_p_rxfrm_info;
il_rxsig_info_t     const * l_p_rxsig_info;
il_rxfrm_t          const * l_p_rxfrm;
il_sig_index_t      const * l_p_frm_sig_list;
il_rxsig_t          const * l_p_rxsig;
uint8                     * l_p_sig_status;
il_sig_index_t              l_num_signals;
il_sig_handle_t             l_sig_handle;
il_sig_index_t              l_sig_index;
uint8                       l_temp_sig_buf[CAN_MAX_DATA_LENGTH];
uint8                       l_num_frame_signals;
uint8                       l_sig_size;
uint8                       l_i_signal;
uint8                       l_i_byte;
boolean                     l_sig_value_changed;
boolean                     l_success;

/*------------------------------------------------------
Get the receive frame information including the frame
signal list and the number of signals in the frame and
process all of the signals in the frame
------------------------------------------------------*/
l_p_rxfrm_info      = il_get_rxfrm_info_ptr( hw_inst );
l_p_rxfrm           = &( l_p_rxfrm_info->p_il_rxfrm[frm_index] );
l_p_frm_sig_list    = l_p_rxfrm->p_signal_list;
l_num_frame_signals = l_p_rxfrm->num_signals;
l_p_rxsig_info      = il_get_rxsig_info_ptr( hw_inst );
l_num_signals       = l_p_rxsig_info->num_signals;

for( l_i_signal = 0; l_i_signal < l_num_frame_signals; l_i_signal++ )
    {
    /*------------------------------------------------------
    Get the signal index for this signal and formulate the
    signal handle. Check that the signal index is within
    the valid range for this CAN hardware instance.
    ------------------------------------------------------*/
    l_sig_index    = l_p_frm_sig_list[l_i_signal];
    l_sig_handle   = IL_FORM_SIGNAL_HANDLE( l_sig_index, hw_inst );
    l_p_sig_status = &( l_p_rxsig_info->p_status[l_sig_index] );

    if( l_sig_index < l_num_signals )
        {
        /*------------------------------------------------------
        Get the signal information for this signal including the
        number of bytes in the signal.
        ------------------------------------------------------*/
        l_p_rxsig  = &( l_p_rxsig_info->p_il_rxsig[l_sig_index] );
        l_sig_size = l_p_rxsig->size_p_data;

        /*------------------------------------------------------
        Check if the signals are to be parsed from this frame
        ------------------------------------------------------*/
        if( TRUE == parse_enable )
            {
            /*------------------------------------------------------
            Extract the signal from the received frame into a
            temporary buffer and check for successful parsing
            ------------------------------------------------------*/
            l_success = parse_frame_signal( l_p_rxsig->start_bit,
                                            l_p_rxsig->num_bits,
                                            l_p_rxfrm->p_data,
                                            &( l_temp_sig_buf[0] ),
                                            l_sig_size );
            if( l_success != FALSE )
                {
                /*------------------------------------------------------
                Check if the received signal value has changed...
                initially assume it hasn't. If it has changed then
                update the signal buffer, set the signal changed status
                bit and issue the signal change notification if enabled
                ------------------------------------------------------*/
                l_sig_value_changed = FALSE;

                for(   l_i_byte = 0;
                   ( ( l_i_byte < l_sig_size ) && ( FALSE == l_sig_value_changed ) );
                     l_i_byte++ )
                    {
                    if( l_temp_sig_buf[l_i_byte] != l_p_rxsig->p_data[l_i_byte] )
                        {
                        l_sig_value_changed = TRUE;
                        }
                    }

                if( l_sig_value_changed != FALSE )
                    {
                    can_util_copy_bytes( &( l_temp_sig_buf[0] ), &( l_p_rxsig->p_data[0] ), l_sig_size );
                    can_util_set_status_bits( l_p_sig_status, IL_SIG_STATUS_VALUE_CHNGD );
                    }
                }

            if( ( ( l_p_rxsig->attributes & IL_RX_SIG_ATTR_NOTIFY_CHANGE ) != 0 ) &&
                  ( notify_enable != FALSE ) &&
                  ( *l_p_sig_status & IL_SIG_STATUS_VALUE_CHNGD ) )
                {
                can_util_clear_status_bits( l_p_sig_status, IL_SIG_STATUS_VALUE_CHNGD );
                il_app_hook_sig_changed_handle( frm_index, l_sig_handle, l_sig_size );
                }
            }

        /*------------------------------------------------------
        Check for "on event" notification enabled. This is a
        notification issued that the signal has been received,
        event if it hasn't changed in value.
        ------------------------------------------------------*/
        if( ( ( l_p_rxsig->attributes & IL_RX_SIG_ATTR_NOTIFY ) != 0 ) &&
              ( notify_enable != FALSE ) )
            {
            il_app_notify_sig_received( l_sig_handle, l_sig_size );
            }
        }
    }
}

/*!*******************************************************************
*
* pack a CAN signal into an Interaction Layer CAN frame
*
* This function packs a CAN signal into a CAN frame using the signal
* data in the passed in data buffer.
*
* @return boolean
* success (TRUE or FALSE)
*
*********************************************************************/
boolean
pack_frame_signal
    (
    uint8               const start_bit,        //!< [in] Signal Start Bit (LSbit) in CAN Frame
    can_hw_inst_t       const num_bits,         //!< [in] Number of bits in the signal
    uint8       const * const p_sig_data,       //!< [in] Pointer to the signal data
    uint8             * const p_frame_buffer,   //!< [in] Pointer to the frame buffer
    uint8               const sig_size          //!< [in] Signal size in bytes
    )
{
il_sig_frm_coords_t     l_sig_frm_coords;
uint8                   l_working_buffer[CAN_MAX_DATA_LENGTH];
uint8                   l_num_sig_bytes;
uint8                   l_i_byte;
uint8                   l_num_working_bytes;
uint8                   l_first_byte;
uint8                   l_first_source_byte;
uint8                   l_num_left_shift;
uint8                   l_num_right_shift;
uint8                   l_bit_mask;
uint8                   l_temp_byte;
boolean                 l_success;

/*------------------------------------------------------
Initialize the return value, get the signal size in
bytes and check that the source buffer is at least as
big as the signal. If the source buffer is bigger than
the signal size then assume a Big Endian, right
adjusted format for the signal bytes
------------------------------------------------------*/
l_success       = FALSE;
l_num_sig_bytes = get_signal_size_in_bytes( num_bits );

if( sig_size >= l_num_sig_bytes )
    {
    /*------------------------------------------------------
    Start with the first non-zero byte value in the buffer.
    Get the signal byte and bit coordinates within the CAN
    frame data field as a function of the start bit (LSBit
    location) in the frame and the number of bits in the
    signal and check that the translated coordinates are
    valid.
    ------------------------------------------------------*/
    l_first_source_byte = sig_size - l_num_sig_bytes;

    l_success = get_sig_frm_coords( start_bit, num_bits, &l_sig_frm_coords );

    if( l_success != FALSE )
        {
        /*------------------------------------------------------
        Check if the signal is contained in one byte (this is
        the most typical case)
        ------------------------------------------------------*/
        if( l_sig_frm_coords.start_byte == l_sig_frm_coords.end_byte )
            {
            /*------------------------------------------------------
            Get the byte that contains the signal and check for a
            signal that is less than 8 bits
            ------------------------------------------------------*/
            l_temp_byte = p_sig_data[l_first_source_byte];

            if( num_bits < IL_NUM_BITS_IN_BYTE )
                {
                /*------------------------------------------------------
                Shift and mask the signal to make it the correct size
                and put the signal bits in the correct position within
                the byte. Also shift the bit mask to the correct
                position in the byte.
                ------------------------------------------------------*/
                l_bit_mask  =  il_bit_width_masks[num_bits];
                l_temp_byte &= l_bit_mask;
                l_temp_byte =  l_temp_byte << l_sig_frm_coords.end_bit_pos;
                l_bit_mask  =  l_bit_mask  << l_sig_frm_coords.end_bit_pos;

                /*------------------------------------------------------
                Get the target frame byte and OR in the non-signal bits
                from the frame byte with the signal bits for this signal
                ------------------------------------------------------*/
                l_temp_byte |= ( p_frame_buffer[l_sig_frm_coords.start_byte] &
                                 SYS_MASK8_COMPLEMENT( l_bit_mask ) ) ;
                }

            /*------------------------------------------------------
            Store the extracted signal
            ------------------------------------------------------*/
            p_frame_buffer[l_sig_frm_coords.start_byte] = l_temp_byte;
            }

        /*------------------------------------------------------
        Check if the signal is more than one byte, an exact
        multiple of  8 bits and aligned on byte boundaries
        (MSbit is bit 7 and LSbit is bit 0)
        ------------------------------------------------------*/
        else if( ( IL_FIRST_BIT_IN_BYTE == l_sig_frm_coords.start_bit_pos )   &&
                 ( IL_LAST_BIT_IN_BYTE  == l_sig_frm_coords.end_bit_pos ) )
            {
            /*------------------------------------------------------
            Copy the bytes directly with no shifting or masking
            ------------------------------------------------------*/
            can_util_copy_bytes( &( p_sig_data[l_first_source_byte] ),
                                 &( p_frame_buffer[l_sig_frm_coords.start_byte] ),
                                 sig_size );
            }
        /*------------------------------------------------------
        Check if the end of the signal is aligned on a byte
        boundary
        ------------------------------------------------------*/
        else if( 0 == l_sig_frm_coords.end_bit_pos )
            {
            /*------------------------------------------------------
            In this case all of the bytes can be copied directly
            without shifting but the first byte will need to have
            non-signal bits masked off
            ------------------------------------------------------*/
            can_util_copy_bytes( &( p_sig_data[l_first_source_byte + 1] ),
                                 &( p_frame_buffer[( l_sig_frm_coords.start_byte + 1 )] ),
                                 ( sig_size - 1 ) );

            /*------------------------------------------------------
            Determine the first byte mask from the signal start bit
            position and clear the signal bits in this byte
            ------------------------------------------------------*/
            l_bit_mask = il_bit_width_masks[( l_sig_frm_coords.start_bit_pos + 1 )];
            p_frame_buffer[l_sig_frm_coords.start_byte] &= SYS_MASK8_COMPLEMENT( l_bit_mask );

            /*------------------------------------------------------
            OR in the first byte signal bits into the frame buffer
            ------------------------------------------------------*/
            p_frame_buffer[l_sig_frm_coords.start_byte] |= ( p_sig_data[l_first_source_byte] & l_bit_mask );
            }
        else
            {
            /*------------------------------------------------------
            The packed signal bytes need to be shifted
            ------------------------------------------------------*/
            l_num_working_bytes = l_sig_frm_coords.end_byte - l_sig_frm_coords.start_byte + 1;
            l_num_left_shift    = l_sig_frm_coords.end_bit_pos;
            l_num_right_shift   = ( IL_NUM_BITS_IN_BYTE - l_num_left_shift );
            l_bit_mask          = il_bit_width_masks[l_num_right_shift];

            /*------------------------------------------------------
            Copy the signal bytes into a working buffer. The signal
            bytes will have to be shifted to align with the signal
            bit field within the CAN frame.
            ------------------------------------------------------*/
            for( l_i_byte = 0; l_i_byte < sig_size; l_i_byte++ )
                {
                l_working_buffer[l_i_byte + 1]  = p_sig_data[l_i_byte + l_first_source_byte] << l_num_left_shift;

                if( l_i_byte < ( sig_size - 1 ) )
                    {
                    l_working_buffer[l_i_byte + 1] |= p_sig_data[l_i_byte + l_first_source_byte + 1] >> l_num_right_shift;
                    }
                }

            /*------------------------------------------------------
            Determine the first valid byte in the working buffer
            that has signal bits and adjust the first byte if
            necessary
            ------------------------------------------------------*/
            if( l_num_working_bytes > sig_size )
                {
                l_first_byte = 0;
                l_working_buffer[0] = p_sig_data[l_first_source_byte] >> l_num_right_shift;
                }
            else
                {
                l_first_byte = 1;
                }

            /*------------------------------------------------------
            Copy the adjusted signal data bytes to the frame buffer,
            excluding the first and last bytes which require special
            handling to prevent corrupting adjacent signal bytes
            ------------------------------------------------------*/
            if( l_num_working_bytes > IL_FIRST_AND_LAST_NBYTES )
                {
                can_util_copy_bytes( &( l_working_buffer[l_first_byte + 1] ),
                                     &( p_frame_buffer[l_sig_frm_coords.start_byte + 1] ),
                                     ( l_num_working_bytes - IL_FIRST_AND_LAST_NBYTES ) );
                }

            /*------------------------------------------------------
            Process the start byte... clear the signal bits in the
            frame buffer and then OR in the desired signal bits
            from the working buffer
            ------------------------------------------------------*/
            l_bit_mask = il_bit_width_masks[l_sig_frm_coords.start_bit_pos + 1];
            p_frame_buffer[l_sig_frm_coords.start_byte] &= SYS_MASK8_COMPLEMENT( l_bit_mask );
            p_frame_buffer[l_sig_frm_coords.start_byte] |= ( l_working_buffer[l_first_byte] & l_bit_mask );

            /*------------------------------------------------------
            Do the same thing with the end byte
            ------------------------------------------------------*/
            l_bit_mask = il_bit_width_masks[l_sig_frm_coords.end_bit_pos];
            p_frame_buffer[l_sig_frm_coords.end_byte] &= l_bit_mask;
            p_frame_buffer[l_sig_frm_coords.end_byte] |= l_working_buffer[l_num_working_bytes];
            }
        }
    }

return l_success;
}

/*!*******************************************************************
*
* @private
* transmit a CAN signal byte array
*
* This function transmits a CAN signal as an array of bytes. The
* signal is specified in terms of the number of bytes in the signal.
*
* @return boolean
* success flag (TRUE or FALSE)
*
*********************************************************************/
boolean
il_tx_put_signal_bytes
    (
    il_sig_handle_t     const sig_handle,   //!< [in] signal handle
    uint8       const * const p_sig_data,   //!< [in] pointer to signal data
    uint8               const num_bytes     //!< [in] number of bytes in the signal
    )
{
il_txsig_info_t     const * l_p_txsig_info;
il_txfrm_info_t     const * l_p_txfrm_info;
il_txsig_t          const * l_p_tx_sig;
il_txfrm_t          const * l_p_txfrm;
il_sig_index_t              l_sig_index;
il_sig_index_t              l_num_signals;
dll_frm_index_t             l_frm_index;
can_hw_inst_t               l_hw_inst;
boolean                     l_success;

/*------------------------------------------------------
Initialize the return value, then validate the signal
handle with respect to the range of CAN instances
------------------------------------------------------*/
l_success = FALSE;
l_hw_inst = IL_GET_HWINST_FROM_SIGNAL_HANDLE( sig_handle );

if( l_hw_inst < CAN_NUM_INSTANCES )
    {
    /*------------------------------------------------------
    Verify that the signal index is within a valid range and
    that the pointer to the data is not NULL
    ------------------------------------------------------*/
    l_p_txsig_info = il_get_txsig_info_ptr( l_hw_inst );
    l_num_signals  = l_p_txsig_info->num_signals;
    l_sig_index    = IL_GET_INDEX_FROM_SIGNAL_HANDLE( sig_handle );

    if( ( l_sig_index < l_num_signals ) && ( p_sig_data != NULL ) )
        {
        /*------------------------------------------------------
        Get the frame information for this signal index
        ------------------------------------------------------*/
        l_p_tx_sig     = &( l_p_txsig_info->p_il_txsig[l_sig_index] );
        l_frm_index    = l_p_tx_sig->frame_index;
        l_p_txfrm_info = il_get_txfrm_info_ptr( l_hw_inst );
        l_p_txfrm      = &( l_p_txfrm_info->p_il_txfrm[l_frm_index] );

        /*------------------------------------------------------
        Perform thread safe update of the frame signal data
        ------------------------------------------------------*/
        taskENTER_CRITICAL();

        l_success =  pack_frame_signal( l_p_tx_sig->start_bit,
                                        l_p_tx_sig->num_bits,
                                        p_sig_data,
                                        l_p_txfrm->p_data,
                                        num_bytes );
        taskEXIT_CRITICAL();

        if( ( l_success != FALSE )  &&
            ( ( l_p_txfrm->attributes & IL_TX_FRM_ATTR_EVENT ) != 0 ) )
            {
            #if( CAN_IL_DELAY_EVENT_TO_TICK == FALSE )
                /*------------------------------------------------------
                Attempt to transmit the frame immediately.
                ------------------------------------------------------*/
                transmit_frame( l_hw_inst, l_frm_index );
            #else
                /*------------------------------------------------------
                Defer frame transmission at least until the next tick.
                ------------------------------------------------------*/
                set_transmit_frame_event_pending( l_hw_inst, l_frm_index );
            #endif
            }
        }
    }

return l_success;
}

/*!*******************************************************************
*
* @private
* transmit a CAN uint8 signal
*
* This function transmits a CAN signal that is one byte in size.
*
* @return boolean
* success flag (TRUE or FALSE)
*
*********************************************************************/
boolean
il_tx_put_uint8_signal
    (
    il_sig_handle_t const sig_handle,   //!< [in] signal handle
    uint8           const sig_value     //!< [in] signal value
    )
{
boolean     l_success;

/*------------------------------------------------------
Transmit the byte using the byte array function
------------------------------------------------------*/
l_success = il_tx_put_signal_bytes( sig_handle, &sig_value, sizeof( uint8 ) );

return l_success;
}

/*!*******************************************************************
*
* @private
* transmit a CAN uint16 signal
*
* This function transmits a uint16 CAN signal.
*
* @return boolean
* success flag (TRUE or FALSE)
*
*********************************************************************/
boolean
il_tx_put_uint16_signal
    (
    il_sig_handle_t const sig_handle,   //!< [in] signal handle
    uint16          const sig_value     //!< [in] signal value
    )
{
uint8       l_bytes[sizeof( uint16 )];
boolean     l_success;

/*------------------------------------------------------
Convert the UINT16 value to a byte array and transmit it
using the byte array function
------------------------------------------------------*/
l_bytes[0] = (uint8) ( sig_value >> IL_NUM_BITS_IN_BYTE );
l_bytes[1] = (uint8) sig_value;

l_success = il_tx_put_signal_bytes( sig_handle, &( l_bytes[0] ), sizeof( uint16 ) );

return l_success;
}

/*!*******************************************************************
*
* @private
* transmit a CAN uint32 signal
*
* This function transmits a uint32 CAN signal.
*
* @return boolean
* success flag (TRUE or FALSE)
*
*********************************************************************/

boolean
il_tx_put_uint32_signal
    (
    il_sig_handle_t const sig_handle,   //!< [in] signal handle
    uint32          const sig_value     //!< [in] signal value
    )
{
uint8       l_bytes[sizeof( uint32 )];
uint32      l_temp32;
uint8       l_i_byte;
boolean     l_success;

/*------------------------------------------------------
Convert the UINT32 value to a byte array and transmit it
using the byte array function
------------------------------------------------------*/
l_temp32 = sig_value;

for( l_i_byte = sizeof( uint32 ); l_i_byte > 0; l_i_byte-- )
    {
    l_bytes[l_i_byte - 1] = (uint8) l_temp32;
    l_temp32 = l_temp32 >> IL_NUM_BITS_IN_BYTE;
    }

l_success = il_tx_put_signal_bytes( sig_handle, &( l_bytes[0] ), sizeof( uint32 ) );

return l_success;
}

/*!*******************************************************************
*
* @private
* transmit a CAN uint64 signal
*
* This function transmits a uint64 CAN signal.
*
* @return boolean
* success flag (TRUE or FALSE)
*
*********************************************************************/
boolean
il_tx_put_uint64_signal
    (
    il_sig_handle_t const sig_handle,   //!< [in] signal handle
    uint64          const sig_value     //!< [in] signal value
    )
{
uint8       l_bytes[sizeof( uint64 )];
uint64      l_temp64;
uint8       l_i_byte;
boolean     l_success;

/*------------------------------------------------------
Convert the UINT64 value to a byte array and transmit it
using the byte array function
------------------------------------------------------*/
l_temp64 = sig_value;

for( l_i_byte = sizeof( uint64 ); l_i_byte > 0; l_i_byte-- )
    {
    l_bytes[l_i_byte - 1] = (uint8) l_temp64;
    l_temp64 = l_temp64 >> IL_NUM_BITS_IN_BYTE;
    }

l_success = il_tx_put_signal_bytes( sig_handle, &( l_bytes[0] ), sizeof( uint64 ) );

return l_success;
}

/*!*******************************************************************
*
* @private
* transmit a CAN signal group
*
* This function transmits a group of CAN signals coherently. The
* signals that are transmitted must all be contained in the specified
* message frame.
*
* @return boolean
* success (TRUE or FALSE)
*
*********************************************************************/
boolean
il_tx_put_signal_group
    (
    dll_frm_handle_t        const frm_handle,           //!< [in] CAN message frame handle
    il_txsig_put_t  const * const p_txsig_put_list,     //!< [in] ptr to array of signals to transmit
    uint8                   const num_signals           //!< [in] number of signals to transmit
    )
{
il_txfrm_info_t const * l_p_txfrm_info;
il_txsig_info_t const * l_p_txsig_info;
il_txfrm_t      const * l_p_txfrm;
il_txsig_put_t  const * l_p_tx_put_sig;
il_txsig_t      const * l_p_txsig;
dll_frm_index_t         l_frm_index;
dll_frm_index_t         l_num_frames;
il_sig_index_t          l_sig_index;
il_sig_handle_t         l_sig_handle;
uint8                   l_num_frm_signals;
uint8                   l_num_sig_bytes;
uint8                   l_i_signal;
can_hw_inst_t           l_hw_inst;
can_hw_inst_t           l_chk_sig_hw_inst;
boolean                 l_success;

/*------------------------------------------------------
Initialize the return value, then validate the signal
handle with respect to the range of CAN instances
------------------------------------------------------*/
l_success = FALSE;

l_hw_inst = DLL_GET_HWINST_FROM_FRAME_HANDLE( frm_handle );

if( l_hw_inst < CAN_NUM_INSTANCES )
    {
    /*------------------------------------------------------
    Get the frame information for the specified CAN instance
    and check that the specified frame index is valid
    ------------------------------------------------------*/
    l_frm_index    = DLL_GET_INDEX_FROM_FRAME_HANDLE( frm_handle );
    l_p_txfrm_info = il_get_txfrm_info_ptr( l_hw_inst );
    l_num_frames   = l_p_txfrm_info->num_frames;

    if( l_frm_index < l_num_frames )
        {
        /*------------------------------------------------------
        Get the frame information for this frame index and the
        number of signals in the frame. Check that the specified
        number of signals is correct for this frame
        ------------------------------------------------------*/
        l_p_txfrm         = &( l_p_txfrm_info->p_il_txfrm[l_frm_index] );
        l_num_frm_signals = l_p_txfrm->num_signals;

        if( num_signals <= l_num_frm_signals )
            {
            /*------------------------------------------------------
            Set the return value and get the signal information for
            this CAN hardware instance and verify that all of the
            signals to be updated are defined to be in this frame
            and have the correct number of bytes for the signal.
            Also verify that the pointer to the signal data is not
            the NULL pointer.
            ------------------------------------------------------*/
            l_success      = TRUE;
            l_p_txsig_info = il_get_txsig_info_ptr( l_hw_inst );

            for(   l_i_signal = 0;
               ( ( l_i_signal < num_signals ) && ( TRUE == l_success ) );
                   l_i_signal++ )
                {
                l_p_tx_put_sig    = &( p_txsig_put_list[l_i_signal] );
                l_sig_handle      = l_p_tx_put_sig->sig_handle;
                l_sig_index       = IL_GET_INDEX_FROM_SIGNAL_HANDLE( l_sig_handle );
                l_chk_sig_hw_inst = IL_GET_HWINST_FROM_SIGNAL_HANDLE ( l_sig_handle );

                if( ( l_chk_sig_hw_inst != l_hw_inst )                  ||
                    ( NULL == l_p_tx_put_sig->p_data )                  ||
                    ( l_sig_index >= l_p_txsig_info->num_signals ) )
                    {
                    l_success = FALSE;
                    }
                else
                    {
                    /*------------------------------------------------------
                    Check this signal is in the specified frame
                    ------------------------------------------------------*/
                    l_p_txsig = &( l_p_txsig_info->p_il_txsig[l_sig_index] );

                    if( l_p_txsig->frame_index != l_frm_index )
                        {
                        l_success = FALSE;
                        }
                    else
                        {
                        /*------------------------------------------------------
                        Check there are enough data bytes for this signal size
                        ------------------------------------------------------*/
                        l_num_sig_bytes = get_signal_size_in_bytes( l_p_txsig->num_bits );

                        if( l_p_tx_put_sig->num_bytes < l_num_sig_bytes )
                            {
                            l_success = FALSE;
                            }
                        }
                    }
                }

            /*------------------------------------------------------
            Check if this update is still valid...
            ------------------------------------------------------*/
            if( l_success != FALSE )
                {
                for(   l_i_signal = 0;
                   ( ( l_i_signal < num_signals ) && ( l_success != FALSE ) );
                       l_i_signal++ )
                    {
                    l_p_tx_put_sig = &( p_txsig_put_list[l_i_signal] );
                    l_sig_index    = IL_GET_INDEX_FROM_SIGNAL_HANDLE( l_p_tx_put_sig->sig_handle );
                    l_p_txsig      = &( l_p_txsig_info->p_il_txsig[l_sig_index] );

                    /*------------------------------------------------------
                    Perform thread safe update of the signals in the frame
                    ------------------------------------------------------*/
                    taskENTER_CRITICAL();

                    l_success = pack_frame_signal( l_p_txsig->start_bit,
                                                   l_p_txsig->num_bits,
                                                   l_p_tx_put_sig->p_data,
                                                   l_p_txfrm->p_data,
                                                   l_p_tx_put_sig->num_bytes );
                    taskEXIT_CRITICAL();
                    }

                    /*------------------------------------------------------
                    Transmit the frame
                    ------------------------------------------------------*/
                    if( ( l_success != FALSE )  &&
                        ( ( l_p_txfrm->attributes & IL_TX_FRM_ATTR_EVENT ) != 0 ) )
                        {
                        #if( CAN_IL_DELAY_EVENT_TO_TICK == FALSE )
                            /*------------------------------------------------------
                            Attempt to transmit the frame immediately.
                            ------------------------------------------------------*/
                            transmit_frame( l_frm_index, l_hw_inst );
                        #else
                            /*------------------------------------------------------
                            Defer frame transmission at least until the next tick.
                            ------------------------------------------------------*/
                            set_transmit_frame_event_pending( l_frm_index, l_hw_inst );
                        #endif
                        }
                }
            }
        }
    }

return l_success;
}

/*!*******************************************************************
*
* @private
* get a CAN signal as an array of bytes
*
* This function gets a received CAN signal as an array of bytes.
*
* @return boolean
* success flag (TRUE or FALSE)
*
*********************************************************************/
boolean
il_rx_get_signal_bytes
    (
    il_sig_handle_t const sig_handle,   //!< [in] signal handle
    uint8         * const p_sig_data,   //!< [out] ptr to received signal data
    uint8           const num_bytes     //!< [in] number of signal bytes to get
    )
{
il_rxsig_info_t const * l_p_rxsig_info;
il_rxsig_t      const * l_p_rxsig;
il_sig_index_t          l_sig_index;
il_sig_index_t          l_num_signals;
uint8                   l_hw_inst;
uint8                   l_i_byte;
uint8                   l_first_destination_byte;
boolean                 l_success;

/*------------------------------------------------------
Initialize the return value, then validate the signal
handle with respect to the range of CAN instances
------------------------------------------------------*/
l_success = FALSE;
l_hw_inst = IL_GET_HWINST_FROM_SIGNAL_HANDLE( sig_handle );

if( l_hw_inst < CAN_NUM_INSTANCES )
    {
    /*------------------------------------------------------
    Verify that the signal index is within a valid range
    and that the destination data pointer is not NULL
    ------------------------------------------------------*/
    l_sig_index    = IL_GET_INDEX_FROM_SIGNAL_HANDLE( sig_handle );
    l_p_rxsig_info = il_get_rxsig_info_ptr( l_hw_inst );
    l_num_signals  = l_p_rxsig_info->num_signals;

    if( ( l_sig_index < l_num_signals ) && ( p_sig_data != NULL ) )
        {
        /*------------------------------------------------------
        Get the signal definition and check that the data buffer
        is big enough to hold all of the signal data bytes. If
        the destination buffer is bigger than adjust the data
        bytes accordingly for the configured endianess
        ------------------------------------------------------*/
        l_p_rxsig = &( l_p_rxsig_info->p_il_rxsig[l_sig_index] );

        if( num_bytes >= l_p_rxsig->size_p_data )
            {
            l_success = TRUE;

            if( num_bytes == l_p_rxsig->size_p_data )
                {
                l_first_destination_byte = 0;
                }
            else
                {
                l_first_destination_byte = num_bytes - l_p_rxsig->size_p_data;

                for( l_i_byte = 0; l_i_byte < l_first_destination_byte; l_i_byte++ )
                    {
                    p_sig_data[l_i_byte] = 0;
                    }
                }

            /*------------------------------------------------------
            Copy the signal data bytes in a thread safe manner
            ------------------------------------------------------*/
            can_util_copy_bytes_atomic( &( l_p_rxsig->p_data[0] ),
                                        &( p_sig_data[l_first_destination_byte] ),
                                         ( num_bytes - l_first_destination_byte ) );
            }
        else
            {
            /*------------------------------------------------------
            There was a problem with the requested signal request so
            file the destination buffer with default characters to
            make the problem apparent
            ------------------------------------------------------*/
             for( l_i_byte = 0; l_i_byte < num_bytes; l_i_byte++ )
                {
                p_sig_data[l_i_byte] = CAN_HEX_FF;
                }
            }
        }
    }

return l_success;
}

/*!*******************************************************************
*
* @private
* receive a CAN uint8 signal
*
* This function gets a received uint8 CAN signal value.
*
* @return boolean
* success flag (TRUE or FALSE)
*
*********************************************************************/
boolean
il_rx_get_uint8_signal
    (
    il_sig_handle_t const sig_handle,   //!< [in] signal handle
    uint8                *p_signal      //!< [out] pointer to signal value
    )
{
boolean     l_success;

/*------------------------------------------------------
Retrieve the byte using the byte array function
------------------------------------------------------*/
l_success = il_rx_get_signal_bytes( sig_handle,
                                    p_signal,
                                    sizeof( uint8 ) );

return l_success;
}

/*!*******************************************************************
*
* @private
* receive a CAN uint16 signal
*
* This function gets a received uint16 CAN signal value.
*
* @return boolean
* success flag (TRUE or FALSE)
*
*********************************************************************/
boolean
il_rx_get_uint16_signal
    (
    il_sig_handle_t const sig_handle,   //!< [in] signal handle
    uint16               *p_signal      //!< [out] pointer to signal value
    )
{
uint8       l_bytes[sizeof( uint16 )];
boolean     l_success;

/*------------------------------------------------------
Get the bytes for this signal and formulate the UINT16
variable value
------------------------------------------------------*/
l_success = il_rx_get_signal_bytes( sig_handle,
                                    &( l_bytes[0] ),
                                    sizeof( uint16 ) );

*( p_signal ) = (uint16) ( ( l_bytes[0] << IL_NUM_BITS_IN_BYTE ) | l_bytes[1] );

return l_success;
}

/*!*******************************************************************
*
* @private
* receive a CAN uint32 signal
*
* This function gets a received uint32 CAN signal value.
*
* @return boolean
* success flag (TRUE or FALSE)
*
*********************************************************************/
boolean
il_rx_get_uint32_signal
    (
    il_sig_handle_t const sig_handle,   //!< [in] signal handle
    uint32               *p_signal      //!< [out] pointer to signal value
    )
{
uint8       l_bytes[sizeof( uint32 )];
uint32      l_temp32;
uint8       l_i_byte;
boolean     l_success;

/*------------------------------------------------------
Retrieve the signal bytes for the specified handle and
formulate the UINT32 signal value
------------------------------------------------------*/
l_success = il_rx_get_signal_bytes( sig_handle,
                                    &( l_bytes[0] ),
                                    sizeof( uint32 ) );

l_temp32 = 0;

for( l_i_byte = 0; l_i_byte < sizeof( uint32 ); l_i_byte++ )
    {
    l_temp32  = l_temp32 << IL_NUM_BITS_IN_BYTE;
    l_temp32 |= (uint32) l_bytes[l_i_byte];
    }

/*------------------------------------------------------
Set the return signal value
------------------------------------------------------*/
*( p_signal ) = l_temp32;

return l_success;
}

/*!*******************************************************************
*
* @private
* receive a CAN uint64 signal
*
* This function gets a received uint64 CAN signal value.
*
* @return boolean
* success flag (TRUE or FALSE)
*
*********************************************************************/
boolean
il_rx_get_uint64_signal
    (
    il_sig_handle_t const sig_handle,   //!< [in] signal handle
    uint64        * const p_signal      //!< [out] pointer to signal value
    )
{
uint8       l_bytes[sizeof( uint64 )];
uint64      l_temp64;
uint8       l_i_byte;
boolean     l_success;

/*------------------------------------------------------
Retrieve the signal bytes for the specified handle and
formulate the UINT64 signal value
------------------------------------------------------*/
l_success = il_rx_get_signal_bytes( sig_handle,
                                    &( l_bytes[0] ),
                                    sizeof( uint64 ) );

l_temp64 = 0;

for( l_i_byte = 0; l_i_byte < sizeof( uint64 ); l_i_byte++ )
    {
    l_temp64  = l_temp64 << IL_NUM_BITS_IN_BYTE;
    l_temp64 |= (uint64) l_bytes[l_i_byte];
    }

/*------------------------------------------------------
Set the return signal value
------------------------------------------------------*/
*( p_signal ) = l_temp64;

return l_success;
}

/*!*******************************************************************
*
* @private
* get a CAN signal's change flag status
*
* This function gets a received CAN signal's change flag status which
* is used to determine if the received signal value has changed since
* the flag was last cleared.
*
* @return boolean
* success flag (TRUE or FALSE)
*
*********************************************************************/
boolean
il_rx_get_signal_changed_flag
    (
    il_sig_handle_t const sig_handle,   //!< [in] signal handle
    boolean       * const p_flag        //!< [out] pointer to change flag result
    )
{
il_rxsig_info_t const * l_p_rxsig_info;
il_sig_index_t          l_sig_index;
il_sig_index_t          l_num_signals;
uint8                   l_hw_inst;
uint8                 * l_p_sig_status;
boolean                 l_success;

/*------------------------------------------------------
Initialize the return value, then validate the signal
handle with respect to the range of CAN instances
------------------------------------------------------*/
l_success = FALSE;
l_hw_inst = IL_GET_HWINST_FROM_SIGNAL_HANDLE( sig_handle );

if( l_hw_inst < CAN_NUM_INSTANCES )
    {
    /*------------------------------------------------------
    Verify that the signal index is within a valid range
    and that the destination flag pointer is not NULL
    ------------------------------------------------------*/
    l_sig_index    = IL_GET_INDEX_FROM_SIGNAL_HANDLE( sig_handle );
    l_p_rxsig_info = il_get_rxsig_info_ptr( l_hw_inst );
    l_num_signals  = l_p_rxsig_info->num_signals;

    if( ( l_sig_index < l_num_signals ) && ( p_flag != NULL ) )
        {
        /*------------------------------------------------------
        Set the return success flag and get the signal change
        flag status
        ------------------------------------------------------*/
        l_success = TRUE;
        l_p_sig_status = &( l_p_rxsig_info->p_status[l_sig_index] );

        if( ( *( l_p_sig_status ) & IL_SIG_STATUS_VALUE_CHNGD ) != 0 )
            {
            *( p_flag ) = TRUE;
            }
        else
            {
            *( p_flag ) = FALSE;
            }
        }
    }

return l_success;
}

/*!*******************************************************************
*
* @private
* clear a CAN signal's change flag
*
* This function clears a received CAN signal's change flag.
*
* @return boolean
* success flag (TRUE or FALSE)
*
*********************************************************************/
boolean
il_rx_clear_signal_changed_flag
    (
    il_sig_handle_t const sig_handle    //!< [in] signal handle
    )
{
il_rxsig_info_t const * l_p_rxsig_info;
il_sig_index_t          l_sig_index;
il_sig_index_t          l_num_signals;
uint8                   l_hw_inst;
boolean                 l_success;

/*------------------------------------------------------
Initialize the return value, then validate the signal
handle with respect to the range of CAN instances
------------------------------------------------------*/
l_success = FALSE;
l_hw_inst = IL_GET_HWINST_FROM_SIGNAL_HANDLE( sig_handle );

if( l_hw_inst < CAN_NUM_INSTANCES )
    {
    /*------------------------------------------------------
    Verify that the signal index is within a valid range
    ------------------------------------------------------*/
    l_sig_index    = IL_GET_INDEX_FROM_SIGNAL_HANDLE( sig_handle );
    l_p_rxsig_info = il_get_rxsig_info_ptr( l_hw_inst );
    l_num_signals  = l_p_rxsig_info->num_signals;

    if( l_sig_index < l_num_signals )
        {
        l_success = TRUE;
        can_util_clear_status_bits( &( l_p_rxsig_info->p_status[l_sig_index] ),
                                    IL_SIG_STATUS_VALUE_CHNGD );
        }
    }

return l_success;
}

/*!*******************************************************************
*
* @private
* get an array of CAN signals
*
* This function gets an array of signals and all of the bytes in each
* signal. The "il_rxsig_get_t" data structure includes information
* about each signal to retrieve along with a pointer to the data
* buffer where the received signal bytes are to be written. The
* signals to be retrieved may be contained in one or more separate
* CAN message frames and may even be on different networks.
*
* @return boolean
* success flag (TRUE or FALSE)
*
*********************************************************************/
boolean
il_rx_get_signal_group
    (
    il_rxsig_get_t  const * const p_rxsig_get_list,     //!< [in, out] pointer to array of signal info
    uint8                   const num_signals           //!< [in] number of signals to get
    )
{
il_rxsig_get_t  const * l_p_rx_get_sig;
il_rxsig_info_t const * l_p_rxsig_info;
il_rxsig_t      const * l_p_rxsig;
il_sig_handle_t         l_sig_handle;
il_sig_index_t          l_sig_index;
uint8                   l_i_signal;
uint8                   l_num_sig_bytes;
can_hw_inst_t           l_hw_inst;
boolean                 l_success;

/*------------------------------------------------------
Initialize the return value, then check the validity of
all of the signals in the signal group
------------------------------------------------------*/
l_success = TRUE;
l_hw_inst = 0;

for(   l_i_signal = 0;
   ( ( l_i_signal < num_signals ) && ( TRUE == l_success ) );
       l_i_signal++ )
    {
    /*------------------------------------------------------
    Get the H/W instance for the signal handle and verify
    that it's valid
    ------------------------------------------------------*/
    l_p_rx_get_sig = &( p_rxsig_get_list[l_i_signal] );
    l_sig_handle   = l_p_rx_get_sig->sig_handle;
    l_hw_inst      = IL_GET_HWINST_FROM_SIGNAL_HANDLE ( l_sig_handle );

    if( l_hw_inst < CAN_NUM_INSTANCES )
        {
        /*------------------------------------------------------
        Get the signal index from the handle and verify that
        it's CAN hardware instance is valid
        ------------------------------------------------------*/
        l_sig_index    = IL_GET_INDEX_FROM_SIGNAL_HANDLE( l_sig_handle );
        l_p_rxsig_info = il_get_rxsig_info_ptr( l_hw_inst );

        if( l_sig_index < l_p_rxsig_info->num_signals )
            {
            /*------------------------------------------------------
            Verify the number of bytes for this signal and check
            that the destinaton buffer pointer is not NULL
            ------------------------------------------------------*/
            l_p_rxsig       = &( l_p_rxsig_info->p_il_rxsig[l_sig_index] );
            l_num_sig_bytes = get_signal_size_in_bytes( l_p_rxsig->num_bits );

            if( ( NULL == l_p_rx_get_sig->p_data )                  ||
                ( l_num_sig_bytes != l_p_rx_get_sig->num_bytes ) )
                {
                l_success = FALSE;
                }
            }
        else
            {
            l_success = FALSE;
            }
        }
    else
        {
        l_success = FALSE;
        }
    }

/*------------------------------------------------------
If all the signals have passed all of the signal checks
at this point...
------------------------------------------------------*/
if( l_success != FALSE )
    {
    /*------------------------------------------------------
    ... then atomically copy the bytes to their buffers...
    ------------------------------------------------------*/
    for( l_i_signal = 0; ( l_i_signal < num_signals ); l_i_signal++ )
        {
        l_p_rx_get_sig = &( p_rxsig_get_list[l_i_signal] );
        l_sig_handle   = l_p_rx_get_sig->sig_handle;
        l_sig_index    = IL_GET_INDEX_FROM_SIGNAL_HANDLE( l_sig_handle );
        l_p_rxsig_info = il_get_rxsig_info_ptr( l_hw_inst );
        l_p_rxsig      = &( l_p_rxsig_info->p_il_rxsig[l_sig_index] );

        can_util_copy_bytes_atomic( l_p_rxsig->p_data,
                                    l_p_rx_get_sig->p_data,
                                    l_p_rx_get_sig->num_bytes );
        }
    }

return l_success;
}

/*!*******************************************************************
*
* @private
* get the signal change status for a group of CAN signals
*
* This function retrieves a received CAN signal group's change status
* flags
*
* @return boolean
* success flag (TRUE or FALSE)
*
*********************************************************************/
boolean
il_rx_get_signal_group_changed_flags
    (
    il_sig_handle_t const * const p_rx_sig_list,    //!< [in] pointer to array of signal handles
    boolean               * const p_flags,          //!< [out] pointer to returned flag values
    uint8                   const num_signals       //!< [in] number of signal flags to get
    )
{
il_rxsig_info_t const * l_p_rxsig_info;
il_sig_handle_t         l_sig_handle;
il_sig_index_t          l_sig_index;
can_hw_inst_t           l_hw_inst;
uint8                   l_i_signal;
boolean                 l_success;

/*------------------------------------------------------
Initialize the return value, then validate the input
signal list pointer and the return flags pointer
------------------------------------------------------*/
l_success = TRUE;

if( ( p_rx_sig_list != NULL ) && ( p_flags != NULL ) )
    {
    /*------------------------------------------------------
    Get the signal change flag value for all of the signals
    ------------------------------------------------------*/
    for(   l_i_signal = 0;
       ( ( l_i_signal < num_signals ) && ( TRUE == l_success ) );
           l_i_signal++ )
        {
        /*------------------------------------------------------
        Point to the next signal that will be retrieved. Extract
        its hardware instance from the signal handle and check
        that it's valid. If so then set the return flag status.
        ------------------------------------------------------*/
        l_sig_handle = p_rx_sig_list[l_i_signal];
        l_hw_inst    = IL_GET_HWINST_FROM_SIGNAL_HANDLE( l_sig_handle );

        if( l_hw_inst < CAN_NUM_INSTANCES )
            {
            l_sig_index    = IL_GET_INDEX_FROM_SIGNAL_HANDLE( l_sig_handle );
            l_p_rxsig_info = il_get_rxsig_info_ptr( l_hw_inst );

            if( l_sig_index < l_p_rxsig_info->num_signals )
                {
                p_flags[l_i_signal] = ( ( l_p_rxsig_info->p_status[l_sig_index] ) &
                                          IL_SIG_STATUS_VALUE_CHNGD );
                }
            }
        else
            {
            l_success = FALSE;
            }
        }
    }
else
    {
    l_success = FALSE;
    }

return l_success;
}

/*!*******************************************************************
*
* @private
* clear the signal change status for a group of CAN signals
*
* This function clears a received CAN signal group's change status
* flags
*
* @return boolean
* success flag (TRUE or FALSE)
*
*********************************************************************/
boolean
il_rx_clear_signal_group_changed_flags
    (
    il_sig_handle_t const * const p_rx_sig_list,    //!< [in] pointer to array of signal handles
    uint8                   const num_signals       //!< [in] number of signals to clear flags
    )
{
il_rxsig_info_t const * l_p_rxsig_info;
il_sig_handle_t         l_sig_handle;
il_sig_index_t          l_sig_index;
uint8                   l_i_signal;
can_hw_inst_t           l_hw_inst;
boolean                 l_success;

/*------------------------------------------------------
Initialize the return value and check that the signal
list pointer is not a NULL pointer
------------------------------------------------------*/
l_success = TRUE;

if( p_rx_sig_list != NULL )
    {
    /*------------------------------------------------------
    Check the validity of all of the signals in the group
    ------------------------------------------------------*/
    for(   l_i_signal = 0;
       ( ( l_i_signal < num_signals ) && ( l_success != FALSE ) );
           l_i_signal++ )
        {
        /*------------------------------------------------------
        Get the signal index from the handle and verify that
        it's CAN hardware instance is valid
        ------------------------------------------------------*/
        l_sig_handle = p_rx_sig_list[l_i_signal];
        l_hw_inst    = IL_GET_HWINST_FROM_SIGNAL_HANDLE ( l_sig_handle );

        if( l_hw_inst < CAN_NUM_INSTANCES )
            {
            /*------------------------------------------------------
            Get the signal index from the handle and verify that
            it's valid for this CAN hardware instance. If it is then
            clear the signal changed flag
            ------------------------------------------------------*/
            l_sig_index    = IL_GET_INDEX_FROM_SIGNAL_HANDLE( l_sig_handle );
            l_p_rxsig_info = il_get_rxsig_info_ptr( l_hw_inst );

            if( l_sig_index < l_p_rxsig_info->num_signals )
                {
                can_util_clear_status_bits( &( l_p_rxsig_info->p_status[l_sig_index] ),
                                               IL_SIG_STATUS_VALUE_CHNGD );
                }
            }
        else
            {
            l_success = FALSE;
            }
        }
    }
else
    {
    l_success = FALSE;
    }

return l_success;
}

/*!*******************************************************************
*
* transmit initialization
*
* Initialize the Interaction Layer transmit variables. The
* "init_default" input specifies whether or not the transmitted signal
* values should be initialized with their default values (as defined
* in the CAN database). The default initialization is normally
* performed on a "cold boot" (i.e. initial System info) whereas
* the currently saved signal values are used on a network wakeup. In
* this latter case a default initialization would overwrite the
* currently saved signal values.
*
*********************************************************************/
static void init_tx
    (
    can_hw_inst_t   const hw_inst,     //!< CAN hardware instance
    boolean         const init_default //!< initialize signal values to defaults

    )
{
il_txfrm_info_t     const * l_p_txfrm_info;
il_txfrm_t          const * l_p_txfrm;
can_tmd_t           const * l_p_tmd;
il_tx_per_info_t    const * l_p_per_info;
dll_frm_index_t             l_num_frames;
dll_frm_index_t             l_i_frm_index;
uint8                       l_dlc;
uint8                       l_i_byte;

/*------------------------------------------------------
Get the transmit frame information and initialize all
of the frames for this CAN hardware instance
------------------------------------------------------*/
l_p_txfrm_info = il_get_txfrm_info_ptr( hw_inst );
l_num_frames   = l_p_txfrm_info->num_frames;

for( l_i_frm_index = 0; l_i_frm_index < l_num_frames; l_i_frm_index++ )
    {
    /*------------------------------------------------------
    Get the pointer to this frame, it's TMD (Transmit Message
    Data structure), periodic transmit information and the
    frame DLC (Data Length Code)
    ------------------------------------------------------*/
    l_p_txfrm    = &( l_p_txfrm_info->p_il_txfrm[l_i_frm_index] );
    l_p_tmd      = &( l_p_txfrm_info->p_tmd[l_i_frm_index] );
    l_p_per_info = l_p_txfrm->p_per_info;
    l_dlc        = l_p_tmd->dlc;

    /*------------------------------------------------------
    Initialize the frame status. If "default" initialization
    is specified then set the signal values to those
    specified in the CAN database
    ------------------------------------------------------*/
    l_p_txfrm_info->p_status[l_i_frm_index] = 0;

    if( init_default != FALSE )
        {
        for( l_i_byte = 0; l_i_byte < l_dlc; l_i_byte++ )
            {
            l_p_txfrm->p_data[l_i_byte] = l_p_txfrm->p_init_data[l_i_byte];
            }
        }

    /*------------------------------------------------------
    Clear the minimum delay count (minimum time between
    frames)
    ------------------------------------------------------*/
    l_p_txfrm_info->p_delay_cnt[l_i_frm_index] = 0;

    /*------------------------------------------------------
    If the frame is periodically transmitted then set the
    initial transmit delay to the value specified in the
    CAN database. Initially clear the Mute count and disable
    the periodic transmit timeout counter (set it to zero).
    If a Mute error was stored in nonvolatile memory at
    startup, then the Mute error is set and the Mute count
    is set to 255 separately after this intialization.
    ------------------------------------------------------*/
    if( l_p_per_info != NULL )
        {
        *( l_p_per_info->p_per_cnt     ) = l_p_per_info->start_delay + 1;
        *( l_p_per_info->p_timeout_cnt ) = 0;
        }
    }
}

/*!*******************************************************************
*
* receive initialization
*
* Initialize the Interaction Layer receive variables. The
* "init_default" input specifies whether or not the received signal
* values should be initialized with their default values (as defined
* in the CAN database). The default initialization is normally
* performed on a "cold boot" (i.e. initial Vehicle info) whereas
* the currently saved signal values are used on a network wakeup. In
* this latter case a default initialization would overwrite the
* currently saved signal values.
*
*********************************************************************/
static void init_rx
    (
    can_hw_inst_t   const hw_inst,     //!< CAN hardware instance
    boolean         const init_default //!< initialize signal values to defaults
    )
{
il_rxfrm_info_t     const * l_p_rxfrm_info;
il_rxfrm_t          const * l_p_rxfrm;
il_rx_per_info_t    const * l_p_per_info;
dll_frm_index_t             l_num_frames;
dll_frm_index_t             l_i_frm_index;
uint8                       l_dlc;
uint8                       l_i_byte;

/*------------------------------------------------------
Get the receive frame information, inlcuding number of
frames for this CAN hardware instance. Initialize all
of the received frames. The frame indexes start at
0x0000 and are numbered sequentially up to the the
number of frames
------------------------------------------------------*/
l_p_rxfrm_info = il_get_rxfrm_info_ptr( hw_inst );
l_num_frames   = l_p_rxfrm_info->num_frames;

for( l_i_frm_index = 0; l_i_frm_index < l_num_frames; l_i_frm_index++ )
    {
    /*------------------------------------------------------
    Get the frame information, periodic pointer and the
    frame length and then initialize the frame status.
    ------------------------------------------------------*/
    l_p_rxfrm    = &( l_p_rxfrm_info->p_il_rxfrm[l_i_frm_index] );
    l_p_per_info = l_p_rxfrm->p_per_info;
    l_dlc        = l_p_rxfrm->dlc;

    l_p_rxfrm_info->p_status[l_i_frm_index] = 0;

    /*------------------------------------------------------
    If a default initialization is specified then set all of
    the received frame signals to the values specified in
    the CAN database
    ------------------------------------------------------*/
    if( init_default != FALSE )
        {
        for( l_i_byte = 0; l_i_byte < l_dlc; l_i_byte++ )
            {
            l_p_rxfrm->p_data[l_i_byte] = l_p_rxfrm->p_init_data[l_i_byte];
            }
        }

    /*------------------------------------------------------
    Parse the receive frames to set the initial receive
    signal values but don't issue signal notifications for
    values set here.
    ------------------------------------------------------*/
    process_receive_frame( hw_inst, l_i_frm_index, FALSE, TRUE );

    /*------------------------------------------------------
    Check if the frame is periodic.
    ------------------------------------------------------*/
    if( l_p_per_info != NULL )
        {
        /*------------------------------------------------------
        Check if receive timeout or ABSENT fault notification is
        enabled.
        ------------------------------------------------------*/
        if( ( l_p_rxfrm->attributes & ( IL_RX_FRM_ATTR_TIMEOUT | IL_RX_FRM_ATTR_ABSENT_NOTIFY ) ) != 0 )
            {
            /*------------------------------------------------------
            Initialize the receive timeout counter.
            ------------------------------------------------------*/
            *( l_p_per_info->p_per_cnt)         = l_p_per_info->period;
            *( l_p_per_info->p_timeout_cnt )    = 0;
            *( l_p_per_info->p_terr_rcvry_cnt)  = 0;
            }
        }
    }
}

/*!*******************************************************************
*
* @private
* initialize the Interaction Layer
*
* This function initializes the OSEK CAN Stack Interaction Layer for
* the specified CAN instance. The init_default switch determines if
* the transmitted and received signals are initialized to their
* default values (as defined in the CAN database) or are left
* intact as currently defined in their volatile memory data stores.
*
*********************************************************************/
void il_init
    (
    can_hw_inst_t   const hw_inst,     //!< [in] CAN hardware instance
    boolean         const init_default //!< [in] Perform default initialization
    )
{
/*------------------------------------------------------
Check for a valid CAN instance
------------------------------------------------------*/
if( hw_inst < CAN_NUM_INSTANCES )
    {
    /*------------------------------------------------------
    Initialize TX and RX variables and conditionally
    initialize the transmitted and received signal values
    ------------------------------------------------------*/
    init_tx( hw_inst, init_default );
    init_rx( hw_inst, init_default );

    /*------------------------------------------------------
    Interaction Layer initializes to the suspended state
    ------------------------------------------------------*/
    il_status[hw_inst] = IL_STATUS_DISABLE;
    }
}

/*!*******************************************************************
*
* periodic transmit task service
*
* This function represents the periodic transmit task service that
* manages the transmission of periodic Interaction Layer CAN frames.
* It is assumed the CAN hardware instance has already been checked
* by any calling functions and is valid.
*
*********************************************************************/
static void tx_task_service
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
il_txfrm_info_t     const * l_p_txfrm_info;
il_txfrm_t          const * l_p_txfrm;
il_tx_per_info_t    const * l_p_per_info;
uint8                     * l_p_status;
uint16                    * l_p_delay_count;
dll_frm_index_t             l_num_frames;
dll_frm_index_t             l_i_frm_index;
dll_frm_handle_t            l_frm_handle;

/*------------------------------------------------------
Get the transmit frame information and service all of
the transmit frames for this CAN hardware instance
------------------------------------------------------*/
l_p_txfrm_info = il_get_txfrm_info_ptr( hw_inst );
l_num_frames   = l_p_txfrm_info->num_frames;

for( l_i_frm_index = 0; l_i_frm_index < l_num_frames; l_i_frm_index++ )
    {
    /*------------------------------------------------------
    Get the transmit frame information for this index and
    check if it's periodic.
    ------------------------------------------------------*/
    l_p_txfrm  = &( l_p_txfrm_info->p_il_txfrm[l_i_frm_index] );
    l_p_status = &( l_p_txfrm_info->p_status[l_i_frm_index] );

    if( ( ( l_p_txfrm->attributes & IL_TX_FRM_ATTR_PERIODIC ) != 0 ) &&
        ( 0 == ( il_status[hw_inst] & IL_STATUS_TX_SUSPEND ) ) )
        {
        /*------------------------------------------------------
        Get the pointer to the periodic frame information and
        check that it's not a NULL pointer.
        ------------------------------------------------------*/
        l_p_per_info = l_p_txfrm->p_per_info;

        if( l_p_per_info != NULL )
            {
            /*------------------------------------------------------
            Decrement the transmission counter
            ------------------------------------------------------*/
            if( *( l_p_per_info->p_per_cnt ) != 0 )
                {
                ( *( l_p_per_info->p_per_cnt ) )--;
                }

            /*------------------------------------------------------
            Check if the transmit timeout counter is enabled (non
            zero value).
            ------------------------------------------------------*/
            if( *( l_p_per_info->p_timeout_cnt ) != 0 )
                {
                ( *( l_p_per_info->p_timeout_cnt ) )--;
                }

            /*------------------------------------------------------
            Check the transmission periodic and timeout counter
            ------------------------------------------------------*/
            if( 0 == *( l_p_per_info->p_per_cnt ) )
                {
                /*------------------------------------------------------
                Flag the frame for transmission and reset the periodic
                transmission counter.
                ------------------------------------------------------*/
                if( 0 == *( l_p_per_info->p_timeout_cnt ) )
                    {
                    /*------------------------------------------------------
                    Check if transmit timeout detection is not disabled
                    ------------------------------------------------------*/
                    if( ( ( (*l_p_status ) & IL_TX_STATUS_PERIODIC_PENDING ) != 0 ) &&
                        ( ( il_status[hw_inst] & IL_STATUS_TX_TIMEOUT_DISABLE ) == 0 ) )
                        {
                        l_frm_handle = DLL_FORM_FRAME_HANDLE( l_i_frm_index, hw_inst );
                        il_app_notify_tx_timeout( l_frm_handle );
                        can_util_set_status_bits( l_p_status, IL_TX_STATUS_TX_TIMEOUT_NOTIFY );
                        }

                    *( l_p_per_info->p_timeout_cnt ) = l_p_per_info->timeout;
                    }

                /*------------------------------------------------------
                Flag the frame for transmission and reset the periodic
                transmission counter.
                ------------------------------------------------------*/
                can_util_set_status_bits( l_p_status, IL_TX_STATUS_PERIODIC_PENDING );
                *( l_p_per_info->p_per_cnt ) = l_p_per_info->period;
                }
            }
        }

    /*------------------------------------------------------
    Check for need for further processing of a transmit
    complete notification.
    ------------------------------------------------------*/
    if( ( *l_p_status & IL_TX_STATUS_TXC_NOTIFY ) != 0 )
        {
        can_util_clear_status_bits( l_p_status, IL_TX_STATUS_TXC_NOTIFY );

        if( ( l_p_txfrm->attributes & IL_TX_FRM_ATTR_NOTIFY ) != 0 )
            {
            l_frm_handle = DLL_FORM_FRAME_HANDLE( l_i_frm_index, hw_inst );
            il_app_notify_tx_complete( l_frm_handle );
            can_util_clear_status_bits( l_p_status, IL_TX_STATUS_TXC_NOTIFY );
            }
        }

    /*------------------------------------------------------
    Check for a required minimum delay between transmissions
    ------------------------------------------------------*/
    if( ( l_p_txfrm->attributes & IL_TX_FRM_ATTR_MIN_DELAY ) != 0 )
        {
        /*------------------------------------------------------
        Decrement the minimum delay count.
        ------------------------------------------------------*/
        l_p_delay_count = &( l_p_txfrm_info->p_delay_cnt[l_i_frm_index] );

        if( *( l_p_delay_count ) != 0 )
            {
            ( *( l_p_delay_count ) )--;
            }
        }

    /*------------------------------------------------------
    Transmit the frame if it's pending transmission for any
    reason.
    ------------------------------------------------------*/
    if( ( *l_p_status & IL_ANY_TX_PENDING ) != 0 )
        {
        transmit_frame( hw_inst, l_i_frm_index );
        }
    }
}

/*!*******************************************************************
*
* Interaction Layer periodic receive task hard key
*
* This function is used to handle hard key and ECU indicate status.
*
*********************************************************************/
static void
rx_hardkey_ECU_status_handle
    (
    boolean                     new_frame,
    uint8                     * p_sw_status,
    il_rx_per_info_t    const * p_per_info,
    il_rxfrm_t          const * p_rxfrm,
    dll_frm_handle_t            frm_handle
    )
{
/*------------------------------------------------------
Timeout error 2 check disable, for instance, ECU indicate
status and status1 can all be judge condition of timeout
error 2, but them can not be received in the same time
in one CAR type, so one condition should be disabled
------------------------------------------------------*/
if( ( *p_sw_status & IL_RX_STATUS_TIMEOUT2_DIS ) != 0 )
    {
    return;
    }

if( new_frame != FALSE )
    {
    can_util_clear_status_bits( p_sw_status, ( IL_RX_STATUS_PENDING | IL_RX_STATUS_DATA_CHANGED ) );

    /*------------------------------------------------------
    Reset the timeout counter and save the frame rx status
    ------------------------------------------------------*/
    *( p_per_info->p_timeout_cnt ) = 0;

    /*------------------------------------------------------
    From TOE2 to normal
    ------------------------------------------------------*/
    if( ( *p_sw_status & IL_RX_STATUS_TIMEOUT2 ) != 0 )
        {
        /*------------------------------------------------------
        Check the reception recovery timer timeout. If it hasn't timed
        out then decrement it and check for receive timeout2 recovery.
        ------------------------------------------------------*/
        if( *( p_per_info->p_terr_rcvry_cnt ) < p_per_info->terr2_rcvry )
            {
            ( *( p_per_info->p_terr_rcvry_cnt ) )++;
            }
        else
            {
            /*------------------------------------------------------
            Reset the timeout recovery conter
            ------------------------------------------------------*/
            ( *( p_per_info->p_terr_rcvry_cnt ) ) = 0;

            /*------------------------------------------------------
            clear status bit
            ------------------------------------------------------*/
            can_util_clear_status_bits( p_sw_status, IL_RX_STATUS_TIMEOUT2 );

            /*------------------------------------------------------
            Notify the CAN app that timeout error2 has recoveried
            ------------------------------------------------------*/
            il_app_notify_rx_timeout2( frm_handle, FALSE );
            }
        }
    /*------------------------------------------------------
    From TOE1 to normal
    ------------------------------------------------------*/
    else if( ( *p_sw_status & IL_RX_STATUS_TIMEOUT1 ) != 0 )
        {
        if(  *( p_per_info->p_terr_rcvry_cnt ) < p_per_info->terr1_rcvry )
            {
            ( *( p_per_info->p_terr_rcvry_cnt ) )++;
            }
        else
            {
            /*------------------------------------------------------
            Reset the timeout recovery conter
            ------------------------------------------------------*/
            ( *( p_per_info->p_terr_rcvry_cnt ) ) = 0;

            /*------------------------------------------------------
            clear status bit
            ------------------------------------------------------*/
            can_util_clear_status_bits( p_sw_status, IL_RX_STATUS_TIMEOUT1 );
            il_app_notify_rx_timeout1( frm_handle, FALSE );
            }
        }
    /*------------------------------------------------------
    In normal
    ------------------------------------------------------*/
    else if( ( ( *p_sw_status & IL_RX_STATUS_TIMEOUT1 ) == 0 ) &&
             ( ( *p_sw_status & IL_RX_STATUS_TIMEOUT2 ) == 0 ) )
        {
        /*------------------------------------------------------
        Reset the timeout recovery counter
        ------------------------------------------------------*/
        ( *( p_per_info->p_terr_rcvry_cnt ) ) = 0;
        }
    }
else
    {
    /*------------------------------------------------------
    Reset the timeout recovery conter
    ------------------------------------------------------*/
    ( *( p_per_info->p_terr_rcvry_cnt ) ) = 0;

    /*------------------------------------------------------
    From normal receiving status to TOE1
    ------------------------------------------------------*/
    if( ( ( *p_sw_status & IL_RX_STATUS_TIMEOUT1 ) == 0 ) &&
        ( ( *p_sw_status & IL_RX_STATUS_TIMEOUT2 ) == 0 ) )
        {
        if( *( p_per_info->p_timeout_cnt ) < p_per_info->timeout1 )
            {
            ( *( p_per_info->p_timeout_cnt ) )++;
            }
        else
            {
            /*------------------------------------------------------
            Reset the timeout counter to zero
            ------------------------------------------------------*/
            *( p_per_info->p_timeout_cnt ) = 0;

            /*------------------------------------------------------
            Set the TOE1 status and notify the can app
            ------------------------------------------------------*/
            can_util_set_status_bits( p_sw_status, IL_RX_STATUS_TIMEOUT1 );
            il_app_notify_rx_timeout1( frm_handle, TRUE );
            }
        }
    /*------------------------------------------------------
    From TOE1 to TOE2
    ------------------------------------------------------*/
    else if( ( *p_sw_status & IL_RX_STATUS_TIMEOUT1 ) != 0 )
        {
        if( *( p_per_info->p_timeout_cnt ) < p_per_info->timeout2 )
            {
            ( *( p_per_info->p_timeout_cnt ) )++;
            }
        else
            {
            /*------------------------------------------------------
            Reset the timeout counter to zero
            ------------------------------------------------------*/
            *( p_per_info->p_timeout_cnt ) = 0;

            /*------------------------------------------------------
            Set the TOE2 status clear TOE1
            ------------------------------------------------------*/
            can_util_set_status_bits( p_sw_status, IL_RX_STATUS_TIMEOUT2 );
            can_util_clear_status_bits( p_sw_status, IL_RX_STATUS_TIMEOUT1 );

            /*------------------------------------------------------
            Notify the can app
            ------------------------------------------------------*/
            il_app_notify_rx_timeout2( frm_handle, TRUE );
            }
        }
    /*------------------------------------------------------
    In TOE2
    ------------------------------------------------------*/
    else if( ( *p_sw_status & IL_RX_STATUS_TIMEOUT2 ) != 0 )
        {
        /*------------------------------------------------------
        Reset the timeout counter to zero
        ------------------------------------------------------*/
        *( p_per_info->p_timeout_cnt ) = 0;
        }
    }
}

/*!*******************************************************************
*
* Interaction Layer periodic receive task func status
*
* This function is used to handle func status.
*
*********************************************************************/
static void
rx_func_stat_handle
    (
    boolean                     new_frame,
    uint8                     * p_frm_status,
    il_rx_per_info_t    const * p_per_info,
    il_rxfrm_t          const * p_rxfrm,
    dll_frm_handle_t            frm_handle
    )
{
if( new_frame != FALSE )
    {
    can_util_clear_status_bits( p_frm_status, ( IL_RX_STATUS_PENDING | IL_RX_STATUS_DATA_CHANGED ) );

    /*------------------------------------------------------
    Reset the timeout counter to zero
    ------------------------------------------------------*/
    *( p_per_info->p_timeout_cnt ) = 0;

    if( ( *p_frm_status & IL_RX_STATUS_TIMEOUT1 ) != 0 )
        {
        if(  *( p_per_info->p_terr_rcvry_cnt ) < p_per_info->terr1_rcvry )
            {
            ( *( p_per_info->p_terr_rcvry_cnt ) )++;
            }
        else
            {
            /*------------------------------------------------------
            Reset the timeout recovery conter
            ------------------------------------------------------*/
            ( *( p_per_info->p_terr_rcvry_cnt ) ) = 0;

            /*------------------------------------------------------
            clear status bit
            ------------------------------------------------------*/
            can_util_clear_status_bits( p_frm_status, IL_RX_STATUS_TIMEOUT1 );
            il_app_notify_rx_timeout1( frm_handle, FALSE );
            }
        }
    else
        {
        /*------------------------------------------------------
        Reset the timeout recovery conter
        ------------------------------------------------------*/
        ( *( p_per_info->p_terr_rcvry_cnt ) ) = 0;
        }
    }
 else
    {
    /*------------------------------------------------------
    Reset the timeout recovery conter
    ------------------------------------------------------*/
    ( *( p_per_info->p_terr_rcvry_cnt ) ) = 0;

    /*------------------------------------------------------
    From normal receiving status to TOE1
    ------------------------------------------------------*/
    if( ( *p_frm_status & IL_RX_STATUS_TIMEOUT1 ) == 0 )
        {
        if( *( p_per_info->p_timeout_cnt ) < p_per_info->timeout1 )
            {
            ( *( p_per_info->p_timeout_cnt ) )++;
            }
        else
            {
            /*------------------------------------------------------
            Reset the timeout counter to zero
            ------------------------------------------------------*/
            *( p_per_info->p_timeout_cnt ) = 0;

            /*------------------------------------------------------
            Set the TOE1 status and notify the can app
            ------------------------------------------------------*/
            can_util_set_status_bits( p_frm_status, IL_RX_STATUS_TIMEOUT1 );
            il_app_notify_rx_timeout1( frm_handle, TRUE );
            }
        }
    }
}

/*!*******************************************************************
*
* Interaction Layer periodic receive task service
*
* This function represents the periodic receive task service that
* manages the reception of periodic Interaction Layer CAN frames.
* This function checks for newly received CAN frames as well as
* checking for received periodic frame timeouts. It is assumed the
* CAN hardware instance has already been checked by any calling
* functions and is valid.
*
*********************************************************************/
static void rx_task_service
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
il_rxfrm_info_t     const * l_p_rxfrm_info;
il_rxfrm_t          const * l_p_rxfrm;
il_rx_per_info_t    const * l_p_per_info;
uint8                     * l_p_frm_status;
dll_frm_index_t             l_num_frames;
dll_frm_index_t             l_i_frm_index;
dll_frm_handle_t            l_frm_handle;
boolean                     l_new_frame;
boolean                     l_frm_data_changed;

/*------------------------------------------------------
Get the receive frame information and service all of
the receive frames for this CAN hardware instance
------------------------------------------------------*/
l_p_rxfrm_info = il_get_rxfrm_info_ptr( hw_inst );
l_num_frames   = l_p_rxfrm_info->num_frames;

for( l_i_frm_index = 0; l_i_frm_index < l_num_frames; l_i_frm_index++ )
    {
    /*------------------------------------------------------
    Formulate a frame handle for notifications
    ------------------------------------------------------*/
    l_frm_handle = DLL_FORM_FRAME_HANDLE( l_i_frm_index, hw_inst );

    /*------------------------------------------------------
    Get pointers to the frame information and initially
    assume this frame is not newly received, then check for
    the frame received since the last task call
    ------------------------------------------------------*/
    l_p_rxfrm       = &( l_p_rxfrm_info->p_il_rxfrm[l_i_frm_index] );
    l_p_frm_status  = &( l_p_rxfrm_info->p_status[l_i_frm_index] );
    l_p_per_info    = l_p_rxfrm->p_per_info;
    l_new_frame     = FALSE;

    /*------------------------------------------------------
    Check if the frame is a new received one
    ------------------------------------------------------*/
    if( ( *l_p_frm_status & IL_RX_STATUS_PENDING ) != 0 )
        {
        l_new_frame = TRUE;

        if( ( *l_p_frm_status & IL_RX_STATUS_DATA_CHANGED ) != 0 )
            {
            l_frm_data_changed = TRUE;
            }
        else
            {
            l_frm_data_changed = FALSE;
            }

        /*------------------------------------------------------
        Process the received CAN frame to parse the signals and
        issue signal notifications... note there is no need to
        parse the frame signals if the received frame data has
        not changed. However any "on event" signal notifications
        that are enabled are issued. Clear the frame pending and
        data changed flags after processing the frame.
        ------------------------------------------------------*/
        process_receive_frame( hw_inst, l_i_frm_index, TRUE, l_frm_data_changed );

        /*------------------------------------------------------
        Only Event type messages can be notified to App layer
        periodic messages use signal-notifying
        ------------------------------------------------------*/
        if( ( ( l_p_rxfrm->attributes & IL_RX_FRM_ATTR_NOTIFY ) != 0 ) &&
            ( l_p_per_info == NULL ) )
            {
            can_util_clear_status_bits( l_p_frm_status, ( IL_RX_STATUS_PENDING | IL_RX_STATUS_DATA_CHANGED ) );
            il_app_notify_frame_received( l_i_frm_index );
            }
        }

    /*------------------------------------------------------
    Process reception of periodic frames. Check if receive
    timeout detection is enabled globally, that receive
    timeout is enabled for this frame, and that the periodic
    info pointer is valid.
    ------------------------------------------------------*/
    if( ( 0 == ( il_status[hw_inst]  & IL_STATUS_RX_TIMEOUT_DISABLE ) ) &&
        ( ( l_p_rxfrm->attributes   & IL_RX_FRM_ATTR_TIMEOUT ) != 0  ) &&
        ( l_p_per_info != NULL ) )
        {
        /*------------------------------------------------------
        timeout checking shall be started 500ms after the enter
        of normal communication
        ------------------------------------------------------*/
        if( il_timeout_err_check_cnt > 0 )
            {
            il_timeout_err_check_cnt--;
            return;
            }

        /*------------------------------------------------------
        Timeout error 2 is trggered by hardkey loss or ECU
        indicate loss which has different IDs in different vehicles
        ------------------------------------------------------*/
        if( ( l_i_frm_index == IL_CAN0_RX6_FUNCSW_STAT_RXFRM_INDEX )    ||
            ( l_i_frm_index == IL_CAN0_RX0_ECU_INDCT_STAT_RXFRM_INDEX ) ||
            ( l_i_frm_index == IL_CAN0_RXH_VH_EG_SPD_RXFRM_INDEX ) )
            {
            rx_hardkey_ECU_status_handle( l_new_frame, l_p_frm_status, l_p_per_info, l_p_rxfrm, l_frm_handle );
            }
        /*------------------------------------------------------
        Supplement CAN IDs's indexs are above IL_CAN0_RXJ_MT_SYS_MOD_RXFRM_INDEX
        not need to handle timeout error
        ------------------------------------------------------*/
        else if( l_i_frm_index <= IL_CAN0_RXJ_MT_SYS_MOD_RXFRM_INDEX )
            {
            /*------------------------------------------------------
            Handle the periodic frame
            ------------------------------------------------------*/
            if( *( l_p_per_info->p_per_cnt ) != 0 )
                {
                ( *( l_p_per_info->p_per_cnt ) )--;
                if( 0 == *( l_p_per_info->p_per_cnt ) )
                    {
                    /*------------------------------------------------------
                    Reset the period timer
                    ------------------------------------------------------*/
                    *( l_p_per_info->p_per_cnt ) = l_p_per_info->period;

                    /*------------------------------------------------------
                    Handle TOE1 of other messages except those can cause TOE2
                    ------------------------------------------------------*/
                    rx_func_stat_handle( l_new_frame, l_p_frm_status, l_p_per_info, l_p_rxfrm, l_frm_handle );
                    }
                }
            }
        }
    }
}

/*!*******************************************************************
*
* @private
* periodic transmit task
*
*********************************************************************/
void il_tx_task
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
Check for a valid CAN instance
------------------------------------------------------*/
if( hw_inst < CAN_NUM_INSTANCES )
    {
    /*------------------------------------------------------
    Check that Interaction Layer transmission is enabled
    ------------------------------------------------------*/
    if( 0 == ( il_status[hw_inst] & IL_STATUS_DISABLE ) )
        {
        /*------------------------------------------------------
        Service the Interaction Layer transmit task
        ------------------------------------------------------*/
        tx_task_service( hw_inst );
        }
    }
}

/*!*******************************************************************
*
* @private
* periodic receive task
*
*********************************************************************/
void il_rx_task
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
Check for a valid CAN instance
------------------------------------------------------*/
if( hw_inst < CAN_NUM_INSTANCES )
    {
    /*------------------------------------------------------
    Check that Interaction Layer is enabled
    ------------------------------------------------------*/
    if( 0 == ( il_status[hw_inst] & IL_STATUS_DISABLE ) )
        {
        /*------------------------------------------------------
        Process All Receive Frames for this instance
        ------------------------------------------------------*/
         rx_task_service( hw_inst );
        }
    }
}

/*!*******************************************************************
*
* @private
* transmit complete callback notification
*
* This function is the Interaction Layer frame transmit complete
* callback notification that is called from the Dispatch Layer.
*
*********************************************************************/
void il_hook_transmit
    (
    can_hw_inst_t   const hw_inst, //!< [in] CAN hardware instance
    can_tmh_t       const tmh      //!< [in] transmit message handle
    )
{
il_txfrm_info_t     const * l_p_txfrm_info;
dll_frm_index_t             l_frm_index;
can_hw_inst_t               l_hw_inst;

/*------------------------------------------------------
Extract the H/W instance from the reported frame handle
and check it against the reported CAN H/W instance
------------------------------------------------------*/
l_hw_inst = DLL_GET_HWINST_FROM_FRAME_HANDLE( tmh );

if( l_hw_inst == hw_inst )
    {
    /*------------------------------------------------------
    Extract the frame index from the handle and check that
    it is valid (within range)
    ------------------------------------------------------*/
    l_frm_index    = DLL_GET_INDEX_FROM_FRAME_HANDLE( tmh );
    l_p_txfrm_info = il_get_txfrm_info_ptr( hw_inst );

    if( l_frm_index < l_p_txfrm_info->num_frames )
        {
        /*------------------------------------------------------
        Update frame status for pending TX complete notification
        ------------------------------------------------------*/
        can_util_set_status_bits( &( l_p_txfrm_info->p_status[l_frm_index] ),
                                  IL_TX_STATUS_TXC_NOTIFY );
        }
    }
}

/*!*******************************************************************
*
* @private
* transmit timeout callback notification
*
* This function is the Interaction Layer frame transmit timeout
* callback notification that is called from the Dispatch Layer.
*
*********************************************************************/
void il_hook_transmit_timeout
    (
    can_hw_inst_t   const hw_inst, //!< [in] CAN hardware instance
    can_tmh_t       const tmh     //!< [in] transmit message handle
    )
{
/*------------------------------------------------------
Tell upper layer the IL CAN has not been transmitted
------------------------------------------------------*/
il_app_notify_tx_hw_timeout( hw_inst, tmh );
}

/*!*******************************************************************
*
* @private
* frame reception callback notification
*
* This function is the Interaction Layer CAN frame reception callback
* notification that is called from the Dispatch Layer. This is called
* from the Dispatch Layer periodic task context (it is not called
* from an interrupt context).
*
*********************************************************************/
void il_hook_receive
    (
    can_hw_inst_t           const hw_inst,   //!< [in] CAN hardware instance
    can_rmd_t       const * const p_rmd,     //!< [in] pointer to received CAN frame
    dll_frm_handle_t        const frm_handle //!< [in] message frame handle
    )
{
il_rxfrm_info_t     const * l_p_rxfrm_info;
uint8                       l_hw_inst;
dll_frm_index_t             l_frm_index;
uint8                     * l_p_frm_status;
dll_frm_index_t             l_ecu_status_frm_index;

/*------------------------------------------------------
Extract the H/W instance from the reported frame handle
and check it against the reported CAN H/W instance
------------------------------------------------------*/
l_hw_inst = DLL_GET_HWINST_FROM_FRAME_HANDLE( frm_handle );

if( l_hw_inst == hw_inst )
    {
    /*------------------------------------------------------
    Extract the frame index from the handle and check that
    it is valid (within range)
    ------------------------------------------------------*/
    l_p_rxfrm_info = il_get_rxfrm_info_ptr( hw_inst );
    l_frm_index    = DLL_GET_INDEX_FROM_FRAME_HANDLE( frm_handle );

    if( l_frm_index < l_p_rxfrm_info->num_frames )
        {
        /*------------------------------------------------------
        Disable the timeout error 2 by ECU indicate
        status or status1
        ------------------------------------------------------*/
        if( p_rmd->identifier == RX0_ECU_INDCT_STAT_CAN0_ID )
            {
            l_ecu_status_frm_index = DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RXH_VH_EG_SPD_RXFRM_HANDLE );
            l_p_frm_status         = &( l_p_rxfrm_info->p_status[l_ecu_status_frm_index] );
            ( *l_p_frm_status )   |= IL_RX_STATUS_TIMEOUT2_DIS;
            }
        else if( p_rmd->identifier == RXH_VH_EG_SPD_CAN0_ID )
            {
            l_ecu_status_frm_index = DLL_GET_INDEX_FROM_FRAME_HANDLE( IL_CAN0_RX0_ECU_INDCT_STAT_RXFRM_HANDLE );
            l_p_frm_status         = &( l_p_rxfrm_info->p_status[l_ecu_status_frm_index] );
            ( *l_p_frm_status )   |= IL_RX_STATUS_TIMEOUT2_DIS;
            }

        /*------------------------------------------------------
        Save the received frame for subsequent processing
        ------------------------------------------------------*/
        save_receive_frame( hw_inst, p_rmd, l_frm_index );
        }
    }
}

/*!*******************************************************************
*
* @private
* enable operation
*
* This function supports enabling the Interaction Layer when the
* Network Management Layer transitions from the Offline to the Online
* state or starts in the Offline state after network initialization.
* It is intended to be called from the Network Management Layer
* component directly.
*
*********************************************************************/
void il_enable
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
Check for a valid CAN instance
------------------------------------------------------*/
if( hw_inst < CAN_NUM_INSTANCES )
    {
    il_timeout_err_check_cnt = IL_RX_TIMEOUT_CHECK_START_TICK;

    /*------------------------------------------------------
    Enable Interaction Layer operation
    ------------------------------------------------------*/
    can_util_clear_status_bits( &( il_status[hw_inst] ), IL_STATUS_DISABLE );
    }
}

/*!*******************************************************************
*
* @private
* disable operation
*
* This function supports disabling the Interaction Layer when the
* Network Management Layer transitions to the Offline state from the
* Online state. It is intended to be called from the Network
* Management Layer component directly.
*
*********************************************************************/
void il_disable
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
Check for a valid CAN instance
------------------------------------------------------*/
if( hw_inst < CAN_NUM_INSTANCES )
    {
    /*------------------------------------------------------
    Disable Interaction Layer operation
    ------------------------------------------------------*/
    can_util_set_status_bits( &( il_status[hw_inst] ), IL_STATUS_DISABLE );
    }
}

/*!*******************************************************************
*
* @private
* suspend operation
*
* This function suspends Interaction Layer operation. It is intended
* to support "quiet mode" operation that is typically invoked by an
* external programming tool when it is programming an ECU on a shared
* CAN bus. This mode of operation suspends normal application message
* transmissions and also disables receive message timeouts. Note that
* the transmit task stops running but the receive task continues to
* run to process any received messages.
*
*********************************************************************/
void il_suspend
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
Check for a valid CAN instance
------------------------------------------------------*/
if( hw_inst < CAN_NUM_INSTANCES )
    {
    /*------------------------------------------------------
    Suspend transmit operation and disable receive message
    and transmit message timeout detection
    ------------------------------------------------------*/
    can_util_set_status_bits( &( il_status[hw_inst] ), IL_STATUS_TX_SUSPEND );
    disable_rx_msg_timeouts( hw_inst );
    disable_tx_msg_timeouts( hw_inst );
    }
}

/*!*******************************************************************
*
* @private
* resume operation
*
* This function supports resumption of Interaction Layer operation
* after it has been suspended for quiet mode operation. This function
* causes all transmit periodic messages to reset their timing.
* Periodic transmit data is left unchanged from what it was before the
* Interaction Layer was suspended. Timeout detection of received
* messages is enabled and all of the timeout counts are reinitialized
* to their specified maximum count values (i.e. nominal timeout
* value).
*
*********************************************************************/
void il_resume
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
Check for a valid CAN instance
------------------------------------------------------*/
if( hw_inst < CAN_NUM_INSTANCES )
    {
    il_timeout_err_check_cnt = IL_RX_TIMEOUT_CHECK_START_TICK;

    /*------------------------------------------------------
    Enable transmit operation and enable receive message
    and transmit message timeout detection.
    ------------------------------------------------------*/
    can_util_clear_status_bits( &( il_status[hw_inst] ), IL_STATUS_TX_SUSPEND );
    enable_rx_msg_timeouts( hw_inst );
    enable_tx_msg_timeouts( hw_inst );
    }
}

/*!*******************************************************************
*
* @private
* transmit a CAN frame group
*
* This function put a CAN frame into interaction layer memory that are
* transmitted must all be contained in the specified message frame.
*
* @return boolean
* success (TRUE or FALSE)
*
*********************************************************************/
boolean
il_tx_put_frame_bytes
    (
    can_hw_inst_t const         hw_inst,  //!< CAN hardware instanc
    can_msg_t     const * const p_can_msg //!< [in] frame CAN message
    )
{
il_txfrm_info_t     const * l_p_txfrm_info;
il_txfrm_t          const * l_p_txfrm;
can_tmd_t           const * l_p_tmd;
dll_frm_index_t             l_num_frames;
dll_frm_index_t             l_i_frm_index;
uint8                       l_dlc;
boolean                     l_success;

/*------------------------------------------------------
Initialize the return value
------------------------------------------------------*/
l_success = FALSE;

/*------------------------------------------------------
Get the transmit frame information and initialize all
of the frames for this CAN hardware instance
------------------------------------------------------*/
l_p_txfrm_info = il_get_txfrm_info_ptr( hw_inst );
l_num_frames   = l_p_txfrm_info->num_frames;

for( l_i_frm_index = 0; l_i_frm_index < l_num_frames; l_i_frm_index++ )
    {
    /*------------------------------------------------------
    Get the pointer to this frame, it's TMD (Transmit Message
    Data structure)and the frame DLC (Data Length Code)
    ------------------------------------------------------*/
    l_p_txfrm    = &( l_p_txfrm_info->p_il_txfrm[l_i_frm_index] );
    l_p_tmd      = &( l_p_txfrm_info->p_tmd[l_i_frm_index] );
    l_dlc        = l_p_tmd->dlc;

    if( ( p_can_msg->id   == l_p_tmd->identifier ) &&
        ( p_can_msg->size == l_p_tmd->dlc ) )
        {
        /*------------------------------------------------------
        put the frame data to  transmission array.
        ------------------------------------------------------*/
        memcpy( (void*)l_p_tmd->p_data, p_can_msg->data, l_dlc );

        #if( CAN_IL_DELAY_EVENT_TO_TICK == FALSE )
            /*------------------------------------------------------
            Attempt to transmit the frame immediately. on event frame
            ------------------------------------------------------*/
            if( ( l_p_txfrm->attributes & IL_TX_FRM_ATTR_EVENT ) != 0 )
                {
                transmit_frame( hw_inst, l_i_frm_index );
                }
        #else
            /*------------------------------------------------------
            Defer frame transmission at least until the next tick.
            ------------------------------------------------------*/
            set_transmit_frame_event_pending(  hw_inst, l_i_frm_index );
        #endif

        /*------------------------------------------------------
        stop getting the pointer to this frame(has been found)
        ------------------------------------------------------*/
        l_success = TRUE;
        break;
        }
    }

return l_success;
}

