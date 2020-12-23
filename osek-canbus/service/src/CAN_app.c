/*!*******************************************************************
* @file CAN_app.c
* @brief CAN Stack Application Client
*
* This file represents the application client for the Garmin OSEK CAN
* Stack implementation. This file includes all of the callback
* notifications that are issued by the CAN stack from the Network
* Management Layer, including notifications for event transitions on
* the CAN Bus such as BusOFF and BusOFF recovery,failures to initialize
* the CAN controller, etc. This file also includes the application CAN
* message frame notifications that are issued by the CAN stack from the
* Interaction Layer.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @defgroup can_app CAN Application (CAN Stack Client)
* @ingroup app_comps
* @{
*
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "can_defs.h"
#include "can_cfg.h"
#include "can_bcfg.h"

#include "can_hw.h"
#include "can_drv.h"
#include "can_dll.h"
#include "can_dll_par.h"
#include "can_dll_prv_par.h"
#include "can_il.h"
#include "can_il_prv.h"
#include "can_il_par.h"
#include "can_il_enum.h"
#include "can_il_prv_par.h"
#include "can_nm.h"
#include "can_tp.h"
#include "can_svcs.h"
#include "can_nim_signals.h"

#include "fsl_debug_console.h"
#include "FreeRTOS.h"
#include "task.h"

#include "VI_pub.h"
#include "CAN_app.h"

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/
#define LC_NACK                         0xEE
#define LC_SID                          0x20
#define LC_RS_NE                        0x10
#define LC_RS_WR                        0x20
#define LC_FILL                         0x55

/*--------------------------------------------------------------------
                                TYPES
--------------------------------------------------------------------*/
/*------------------------------------------------------
Negative response
------------------------------------------------------*/

/*--------------------------------------------------------------------
                              VARIABLES
--------------------------------------------------------------------*/
/*------------------------------------------------------
CAN application BusOFF Status.
------------------------------------------------------*/
static boolean
can_app_bus_off[CAN_NUM_INSTANCES];

/*------------------------------------------------------
CAN application BusOFF Status.
------------------------------------------------------*/
static boolean
can_app_timeout_error2[CAN_NUM_INSTANCES];

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
/*!*******************************************************************
*
* @private
* transmit CAN driver message frame
*
* Transmit a CAN network managment message that may be used  to check
* the CAN bus network status. A loopback message etc.
*
* @return can_ret_code
* return code indicating success or failure
*
*********************************************************************/
static can_ret_code_t
nm_app_tx_data
    (
    can_hw_inst_t     hw_inst,
    can_msg_t const * can_msg_tx_p
    )
{
can_ret_code_t  l_ret_code;
can_tmd_t       l_can_tmd;

/*--------------------------------------------------
fill the transmit structure "Just for NM Loop back frame"
--------------------------------------------------*/
l_can_tmd.identifier    = can_msg_tx_p->id;
l_can_tmd.dlc           = can_msg_tx_p->size;
l_can_tmd.p_data        = can_msg_tx_p->data;
l_can_tmd.handle        = IL_CAN0_RX_NM_AND_LP_BK_RXFRM_HANDLE;
l_can_tmd.options       = CAN_TXMSG_STANDARD;

/*--------------------------------------------------
transmit the NM layer frame
--------------------------------------------------*/
l_ret_code = can_transmit( hw_inst, &l_can_tmd );

return l_ret_code;
}

/*!*******************************************************************
*
* @private
* CAN OnLine notification
*
* This function is the callback function that is called by the CAN
* Stack Network Management Layer when the NM layer changes state.
*
*********************************************************************/
void
nm_app_notify_state_change
    (
    can_hw_inst_t       const hw_inst,
    nm_state_t          const nm_state
    )
{
PRINTF( "NM state changed,current state: %x \r\n",nm_state );
CAN_IGNORE_PARAMETER( hw_inst );
}

/*!*******************************************************************
*
* @private
* CAN BusOFF recovery notification
*
* This function is the callback function that is called by the CAN
* Stack Network Management layer when a CAN bus that was previously
* faulted (BusOFF) has recovered and resumed normal operation.
*
*********************************************************************/
void
nm_app_notify_busoff_recovery
    (
    can_hw_inst_t       const hw_inst
    )
{
PRINTF( "BusOFF recovery! \r\n" );
can_app_bus_off[hw_inst] = FALSE;
CAN_IGNORE_PARAMETER( hw_inst );
}

/*!*******************************************************************
*
* @private
* CAN BusOFF notification
*
* This function is the callback function that is called by the CAN
* Stack Network Management Layer when a CAN BusOFF event occurs.
*
*********************************************************************/
void
nm_app_notify_busoff
    (
    can_hw_inst_t       const hw_inst
    )
{
PRINTF( "BusOFF! \r\n" );
can_app_bus_off[hw_inst] = TRUE;
CAN_IGNORE_PARAMETER( hw_inst );
}

/*!*******************************************************************
*
* @private
* CAN controller initialization failure notification
*
* This function is the callback function that is called by the CAN
* Stack Network Management layer if the process of initializing the
* CAN controller hardware in the low level BSP CAN Driver fails.
*
*********************************************************************/
void
nm_app_notify_init_failed
    (
    can_hw_inst_t       const hw_inst
    )
{
PRINTF( "NM init failed \r\n" );
CAN_IGNORE_PARAMETER( hw_inst );
}

/*!*******************************************************************
*
* @private
* CAN controller transmission hardware failed notification
*
* This function is the callback function that is called by the CAN
* Stack Network Management layer if the process of CAN frame transmission
* fail in CAN controller hardware driver(the low level BSP CAN Driver fails).
*
*********************************************************************/
void
nm_app_notify_tx_hw_timeout
    (
    can_hw_inst_t hw_inst,
    can_tmh_t     tmh
    )
{
PRINTF( "NM Tx HW timeout,Tx message handle: %x\r\n", tmh );
CAN_IGNORE_PARAMETER( hw_inst );
}

/*!*******************************************************************
*
* @private
* Network Management layer CAN bus processing
*
* This function is the callback function that is called by the CAN
* Stack Network Management layer when a CAN bus frame has been received.
*
*********************************************************************/
void
nm_app_hook_process_receive
    (
    can_hw_inst_t       const hw_inst,
    can_rmd_t   const * const p_rmd
    )
{
/*------------------------------------------------------
CAN frame from can stack lower layer
------------------------------------------------------*/
can_msg_t   l_can_msg_rx;

/*--------------------------------------------------
process received data from CAN lower layer
--------------------------------------------------*/
l_can_msg_rx.id     = p_rmd->identifier;
l_can_msg_rx.size   = p_rmd->dlc;
memcpy( l_can_msg_rx.data, p_rmd->data, p_rmd->dlc );

/*--------------------------------------------------
Handling data
--------------------------------------------------*/
//TBD
}

/*!*******************************************************************
*
* @private
* interaction layer frame handle
*
* Put a CAN message which is from app or other component into interation
* layer frame data structures
*
* @return can_ret_code
* return code indicating success or failure
*
*********************************************************************/
static can_ret_code_t
il_app_tx_data
    (
    can_msg_t const * can_msg_tx_p
    )
{
can_ret_code_t  l_ret_code;
can_tmd_t       l_can_tmd;

/*--------------------------------------------------
fill the transmit structure "Just for NM Loop back frame"
--------------------------------------------------*/
l_can_tmd.identifier    = can_msg_tx_p->id;
l_can_tmd.dlc           = can_msg_tx_p->size;
l_can_tmd.p_data        = can_msg_tx_p->data;

/*--------------------------------------------------
put the interaction layer frame into the specific
data structures for this CAN hardware instance
--------------------------------------------------*/
l_ret_code = il_tx_put_frame_bytes ( CAN_CONTROLLER_2, &l_can_tmd );

return l_ret_code;
}

/*!*******************************************************************
*
* @private
* interaction layer frame transmission complete notify
*
* Notify interactiom layer transmission complete
* and the frame status is IL_TX_STATUS_TXC_NOTIFY
*
* @return can_ret_code
* return code indicating success or failure
*
*********************************************************************/
void
il_app_notify_tx_complete
    (
    dll_frm_handle_t        const frm_handle
    )
{
CAN_IGNORE_PARAMETER( frm_handle );
}

/*!*******************************************************************
*
* @private
* interaction layer transmission timeout
*
* Notify interactiom layer timeout when il frame transmission has a
* timeout satuation and the frame status is
* IL_TX_STATUS_TX_TIMEOUT_NOTIFY
*
* @return can_ret_code
* return code indicating success or failure
*
*********************************************************************/
void
il_app_notify_tx_timeout
    (
    dll_frm_handle_t        const frm_handle
    )
{
CAN_IGNORE_PARAMETER( frm_handle );
}

/*!*******************************************************************
*
* @private
* transmit timeout callback notification
*
* This function is the Interaction Layer frame transmit timeout
* callback notification that is called from the interaction Layer.
*
*********************************************************************/
void
il_app_notify_tx_hw_timeout
    (
    can_hw_inst_t hw_inst,
    can_tmh_t     tmh
    )
{
CAN_IGNORE_PARAMETER( tmh );
CAN_IGNORE_PARAMETER( hw_inst );
}

/*!*******************************************************************
*
* @private
* receive timeout1 callback notification
*
* This function is the Interaction Layer frame reception timeout
* callback notification that is called from the interaction Layer.
*
*********************************************************************/
void
il_app_notify_rx_timeout1
    (
    can_hw_inst_t    hw_inst,
    dll_frm_handle_t rmh
    )
{
CAN_IGNORE_PARAMETER( rmh );
CAN_IGNORE_PARAMETER( hw_inst );
}

/*!*******************************************************************
*
* @private
* receive timeout2 callback notification
*
* This function is the Interaction Layer frame reception timeout
* callback notification that is called from the interaction Layer.
*
*********************************************************************/
void
il_app_notify_rx_timeout2
    (
    boolean  timeout_trig
    )
{
can_app_timeout_error2[CAN_CONTROLLER_2] = timeout_trig;

/*------------------------------------------------------
Notify Timeout error2 data
------------------------------------------------------*/
if( timeout_trig == TRUE )
    {
    PRINTF( "Timeout error 2!\r\n" );
    }
}

/*!*******************************************************************
*
* @private
* Interaction Layer CAN message frame reception notification
*
* This function is the Interaction Layer CAN frame reception callback
* that is called by the CAN Stack when an Interaction Layer CAN
* message frame is received on the CAN bus. This notification must be
* enabled as part of configuration of the Garmin OSEK CAN Stack.
*
*********************************************************************/
void
il_app_notify_frame_received
    (
    dll_frm_handle_t        const frm_handle
    )
{
CAN_IGNORE_PARAMETER( frm_handle );
}

/*!*******************************************************************
*
* @private
* Interaction Layer CAN signal reception notification
*
* This function is the Interaction Layer CAN signal reception callback
* that is called by the CAN Stack when an Interaction Layer CAN signal
* is received on the CAN bus. This callback is called regardless of
* whether the CAN signal value has changed from the previously
* received value. This notification must be enabled as part of
* configuration of the Garmin OSEK CAN Stack.
*
*********************************************************************/
void
il_app_notify_sig_received
    (
    il_sig_handle_t const sig_handle,   //!< [in] signal handle
    uint8           const num_bytes     //!< [in] signal size in bytes
    )
{
//TBD
}

/*!*******************************************************************
*
* @private
* signal changed callback notification
*
* This function is the Interaction Layer frame reception signal changed
* callback notification that is called from the interaction Layer.
*
*********************************************************************/
static void
il_app_notify_sig_changed
    (
    il_sig_handle_t         const sig_handle,
    uint8_t                 const num_bytes,
    uint32_t                     *p_sig_val
    )
{
uint8_t  l_sig_val_8  = 0;
uint16_t l_sig_val_16 = 0;
uint32_t l_sig_val_32 = 0;

/*------------------------------------------------------
Get the changed signal value
------------------------------------------------------*/
if( sizeof( uint8 ) == num_bytes )
    {
    CAN_nim_rx_get_uint8_signal( sig_handle, &l_sig_val_8 );
    (*p_sig_val) = (uint32)l_sig_val_8;
    }
else if( sizeof( uint16 ) == num_bytes )
    {
    CAN_nim_rx_get_uint16_signal( sig_handle, &l_sig_val_16 );
    (*p_sig_val) = (uint32)l_sig_val_16;
    }
else if( sizeof( uint32 ) == num_bytes )
    {
    CAN_nim_rx_get_uint32_signal( sig_handle, &l_sig_val_32 );
    (*p_sig_val) = l_sig_val_32;
    }
else
    {
    //TBD
    }
}

/*!*******************************************************************
*
* @private
* Interaction layer received CAN frame CAN sending
*
* This function is called by the CAN app layer to handle CAN signals
*
*********************************************************************/
void
il_app_hook_rx_sig_chngd_handle
    (
    il_rx_frm_index_t             msg_index,
    il_sig_handle_t         const sig_handle,
    uint8_t                 const num_bytes
    )
{
uint32_t l_sig_val;


/*------------------------------------------------------
Get the changed signal value
------------------------------------------------------*/
il_app_notify_sig_changed( sig_handle, num_bytes,&l_sig_val );

switch( msg_index )
    {
    case IL_CAN0_RX5_VEHICLE_INFO_IDX:
        /*--------------------------------------------------
        Vehicle info handler
        --------------------------------------------------*/
        break;

    case IL_CAN0_RX6_FUNCSW_STAT_IDX:
        /*--------------------------------------------------
        Handle hard keys changed
        --------------------------------------------------*/
        VI_notify_vehicle_data_changed( msg_index, sig_handle, l_sig_val );
        break;

    //TBD other signals handler

    default:
        break;

    }
}






/*!*******************************************************************
*
* @public
* CAN application periodic task
*
* This function is called periodically by the Task Manager during
* normal application execution. This task is needed to schedule and
* send the Signal Service "on change" synchronization signal values
*
*********************************************************************/
void app_task
    (
    can_hw_inst_t   const hw_inst       //!< [in] CAN hardware instance
    )
{
//TBD
}

