/*!*******************************************************************
* @file can_dll.h
* @brief OSEK CAN Stack Dispatch Lower Layer API
*
* This file contains type definitions needed for the Dispatch Lower
* Layer to dispatch received CAN frames to the higher layers of the
* Garmin OSEK CAN Stack implementation.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @ingroup can_stack_dll
* @{
*
*********************************************************************/

#ifndef _CAN_DLL_H
#define _CAN_DLL_H

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                            MACROS
--------------------------------------------------------------------*/
/*------------------------------------------------------
Macros to Support Rx Qualification and Dispatch and
Transmit Complete Dispatch and Notification
------------------------------------------------------*/
#define DLL_RX_IL_FRAME                 (0)
#define DLL_RX_NM_FRAME                 (1)
#define DLL_RX_TP_FRAME                 (2)
#define DLL_RX_FT_FRAME                 (3)

/*--------------------------------------------------------------------
                            TYPES
--------------------------------------------------------------------*/
typedef uint16              dll_frm_handle_t;
typedef dll_frm_handle_t    dll_frm_index_t;

typedef struct tagDLL_RX_FRM_DISPATCH_TYPE                          //!< receive frame dispatch object
    {
    uint32                          const   identifier;             //!< CAN Identifier
    dll_frm_handle_t                const   frame_handle;           //!< frame handle
    uint8                           const   frame_layer;            //!< frame layer (e.g. Interanction Layer,
                                                                    //!< Network Managmement, etc)
    } dll_rx_frm_dispatch_t;

typedef struct tagDLL_RX_FILT_DISPATCH_TYPE                         //!< receive filter dispatch object
    {
    uint8                           const   num_can_ids;            //!< number of CAN ID's in the filter
    dll_rx_frm_dispatch_t   const * const   p_frame_dispatch;       //!< pointer to receive frame object

    } dll_rx_filt_dispatch_t;

typedef struct tagDLL_RX_BUF_DISPATCH_TYPE                          //!< receive dispatch object
    {
    uint8                           const   num_filters;            //!< number of filters for reception
    dll_rx_filt_dispatch_t  const * const   p_rx_filt_dispatch;     //!< pointer to receive filter dispatch object

    } dll_rx_buf_dispatch_t;

/*--------------------------------------------------------------------
                            MACROS
--------------------------------------------------------------------*/
#define DLL_FRAME_HANDLE_HWINST_MASK                        (0xF000u)
#define DLL_FRAME_HANDLE_INDEX_MASK                         (0x0FFFu)

#define DLL_GET_HWINST_FROM_FRAME_HANDLE( _frm_handle )     ( (can_hw_inst_t)    ( ( ( _frm_handle ) & DLL_FRAME_HANDLE_HWINST_MASK ) >> 12 ) )
#define DLL_GET_INDEX_FROM_FRAME_HANDLE( _frm_handle )      ( (dll_frm_index_t)  ( ( _frm_handle ) & DLL_FRAME_HANDLE_INDEX_MASK ) )
#define DLL_FORM_FRAME_HANDLE( _frm_index, _hw_inst )       ( (dll_frm_handle_t) ( ( _frm_index ) | ( ( _hw_inst ) << 12 ) ) )

/*--------------------------------------------------------------------
                            VARIABLES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/
void
dll_init
    (
    can_hw_inst_t   const   hw_inst
    );

void
dll_tx_task
    (
    can_hw_inst_t   const   hw_inst
    );

void
dll_rx_task
    (
    can_hw_inst_t   const   hw_inst
    );

uint8
dll_get_rx_buf_dispatch_table
    (
    can_hw_inst_t                     const hw_inst,
    dll_rx_buf_dispatch_t   const * * const pp_buf_dispatch_table
    );

#ifdef __cplusplus
}
#endif

#endif /* _CAN_DLL_H */

