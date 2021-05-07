/*!*******************************************************************
* @file can_dll.c
* @brief IXWW22 CAN Stack Dispatch Lower Layer
*
* This file contains the CAN Dispatch Lower Layer functions needed to
* dispatch received frames and transmit complete notifications to the
* appropriate higher layers of the OSEK CAN Stack.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @defgroup can_stack_dll Dispatch Lower Layer
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
#include "can_hw.h"
#include "can_flexcan.h"
#include "can_drv.h"

#include "can_dll.h"
#include "can_dll_par.h"
#include "can_dll_prv_par.h"

#include "can_il.h"
#include "can_il_par.h"
#include "can_tp.h"
#include "can_nm.h"
#include "client_dcm_appl.h"
#include "fsl_debug_console.h"
#include "FreeRTOS.h"
#include "task.h"
#include "factory_test.h"
#include "VI_pub.h"

/*--------------------------------------------------------------------
                            MACROS
--------------------------------------------------------------------*/
#define RX_DAIG_SEG1_CAN0_ID_END         ( 0x4CF )
#define RX_DAIG_SEG2_CAN0_ID_END         ( 0x4EF )
#define RX_DAIG_SEG3_CAN0_ID_END         ( 0x4DE )


#define RX_DAIG_SEG5_YDT_CAN0_ID_END     ( 0x7EF )

/*------------------------------------------------------
Dispatch Layer Status Bit Definitions
------------------------------------------------------*/
#define DLL_STATUS_TXC_OVERFLOW          ( 0x01u )

/*--------------------------------------------------------------------
                            TYPES
--------------------------------------------------------------------*/

/*!-----------------------------------------------------

 dll_txc_queue_info_t is a data structure used to
 manage the transmit complete notifications that
 are issued to the higher layers of the OSEK CAN
 Stack when CAN frames are transmitted successfully.

------------------------------------------------------*/
typedef struct tagDLL_TXC_QUEUE_INFO_TYPE   //!< transmit queue management
    {
    can_tmh_t     * const p_txc_queue;  //!< pointer to transmit complete queue
    uint8         * const p_num;        //!< pointer to number in the queue
    uint8         * const p_max_num;    //!< pointer to queue high water mark
    uint8         * const p_next_in;    //!< pointer to "next in" index
    uint8         * const p_next_out;   //!< pointer to "next out" index
    uint8           const size;         //!< queue size

    } dll_txc_queue_info_t;

/*--------------------------------------------------------------------
                            VARIABLES
--------------------------------------------------------------------*/

/*------------------------------------------------------
CAN0 TX Complete Queue Variables
------------------------------------------------------*/
static can_tmh_t
dll_can0_txc_queue[DLL_CAN0_TXC_QUEUE_SIZE];

static uint8
dll_can0_txc_queue_num;

static uint8
dll_can0_txc_queue_max_num;

static uint8
dll_can0_txc_queue_next_in;

static uint8
dll_can0_txc_queue_next_out;

/*------------------------------------------------------
Transmit complete queue information
------------------------------------------------------*/
dll_txc_queue_info_t const
dll_txc_queue_info[CAN_NUM_INSTANCES] =
    {
        {
        &dll_can0_txc_queue[0],
        &dll_can0_txc_queue_num,
        &dll_can0_txc_queue_max_num,
        &dll_can0_txc_queue_next_in,
        &dll_can0_txc_queue_next_out,
        DLL_CAN0_TXC_QUEUE_SIZE
        }
    };

/*------------------------------------------------------
Dispatch Layer Status Variable
------------------------------------------------------*/
static uint8 dll_status[CAN_NUM_INSTANCES];

/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/

/*!*******************************************************************
*
* dispatch transmit complete notification
*
* This function dispatches message frame transmission complete
* notifications to the appropriate higher layer of the OSEK CAN Stack.
*
*********************************************************************/
static void
dispatch_txd_frm
    (
    can_hw_inst_t   const hw_inst, //!< [in] CAN hardware instance
    can_tmh_t       const tmh      //!< [in] transmit message handle
    )
{
/*------------------------------------------------------
Determine the Appropriate Layer to Process
the Transmit Complete Event
------------------------------------------------------*/
if( IL_CAN0_TX_NM_AND_LP_BK_TXFRM_HANDLE == tmh )
    {
    nm_hook_transmit( hw_inst, tmh );
    }
else
    {
    /*------------------------------------------------------
    Default to an Interaction Layer Message
    ------------------------------------------------------*/
    il_hook_transmit( hw_inst, tmh );
    }
}

/*!*******************************************************************
*
* dispatch CAN message frame reception
*
* This function dispatches received CAN message frames to the
* appropriate higher layer of the IXWW22 CAN Stack.
*
*********************************************************************/
static void
dispatch_rxd_frm
    (
    can_hw_inst_t       const hw_inst, //!< [in] CAN hardware instance
    can_rmd_t   const * const p_rmd    //!< [in] pointer to received message
    )
{
dll_rx_buf_dispatch_t   const * l_p_buf_dispatch;
dll_rx_filt_dispatch_t  const * l_p_filt_dispatch;
dll_rx_frm_dispatch_t   const * l_p_frm_dispatch;

uint8               l_num_filters;
dll_frm_handle_t    l_frm_handle;
uint8               l_filter_index;
uint8               l_num_filter_can_ids;
uint8               l_can_id_index;
uint8               l_can_id_match;
uint8               l_dispatch_layer;

boolean             l_can_defined_cantp_id_match = FALSE;/*for can transprot layer*/
boolean             l_can_defined_ydt_id_match = FALSE;/*for detecting yamaha diagnsotic tools*/
/*------------------------------------------------------
Initialize Variables
------------------------------------------------------*/
l_can_id_match = FALSE;

/*------------------------------------------------------
Check for NULL RMD Pointer
------------------------------------------------------*/
if( p_rmd != NULL )
    {
    /*------------------------------------------------------
    Get the filter index for this received frame
    ------------------------------------------------------*/
    l_filter_index = p_rmd->vector;

    /*------------------------------------------------------
    Get the Dispatch Table for this CAN Controller hardware
    instance. Also get the number of filters enabled for
    this specific hardware buffer.
    ------------------------------------------------------*/
    l_num_filters = dll_get_rx_buf_dispatch_table( hw_inst, &l_p_buf_dispatch );

    /*------------------------------------------------------
    Check for valid filters and a valid filter index
    ------------------------------------------------------*/
    if( ( l_num_filters    >  0 ) &&
        ( l_filter_index   <  l_num_filters ) &&
        ( l_p_buf_dispatch != NULL ) )
        {
        /*------------------------------------------------------
        Get the filter match CAN ID's for this filter index and
        the number of CAN ID's qualified by this filter
        ------------------------------------------------------*/
        l_p_filt_dispatch    = &( l_p_buf_dispatch->p_rx_filt_dispatch[l_filter_index] );
        l_p_frm_dispatch     = l_p_filt_dispatch->p_frame_dispatch;
        l_num_filter_can_ids = l_p_filt_dispatch->num_can_ids;

        /*------------------------------------------------------
        Search for a CAN ID Match for this filter. Note that NM
        messages don't require a specific CAN ID match beyond
        the filter match as there can be quite a large range of
        possible NM CAN ID's. Further checking of NM messages is
        done in the NM layer.
        ------------------------------------------------------*/
        for(   l_can_id_index = 0, l_can_id_match = FALSE, l_frm_handle = 0, l_dispatch_layer = 0;
           ( ( l_can_id_index < l_num_filter_can_ids ) && ( FALSE == l_can_id_match ) );
               l_can_id_index++ )
            {
            if( ( p_rmd->identifier == l_p_frm_dispatch[l_can_id_index].identifier )    ||
                ( DLL_RX_NM_FRAME   == l_p_frm_dispatch[l_can_id_index].frame_layer ) )
                {
                l_can_id_match   = TRUE;
                l_frm_handle     = l_p_frm_dispatch[l_can_id_index].frame_handle;
                l_dispatch_layer = l_p_frm_dispatch[l_can_id_index].frame_layer;
                }
            else
                {
                if( ( p_rmd->identifier >  RX_DAIG_SEG1_CAN0_ID && p_rmd->identifier <= RX_DAIG_SEG1_CAN0_ID_END )
                    || ( p_rmd->identifier >  RX_DAIG_SEG2_CAN0_ID && p_rmd->identifier <= RX_DAIG_SEG2_CAN0_ID_END )
                    || ( p_rmd->identifier >  RX_DAIG_SEG3_CAN0_ID && p_rmd->identifier <= RX_DAIG_SEG3_CAN0_ID_END )
                    )
                    {
                    l_can_defined_cantp_id_match = TRUE;
                    }
                else if( p_rmd->identifier >  RX_DAIG_SEG5_YDT_CAN0_ID && p_rmd->identifier <= RX_DAIG_SEG5_YDT_CAN0_ID_END )
                    {
                    l_can_defined_ydt_id_match = TRUE;
                    }
                else
                    {
                    /*do nothing*/
                    }
                }
           }

        /*------------------------------------------------------
        Check if Filter CAN ID match was found
        ------------------------------------------------------*/
        if( l_can_id_match != FALSE )
            {
            /*------------------------------------------------------
            Dispatch Received Frame to the Appropriate Layer
            ------------------------------------------------------*/
            switch( l_dispatch_layer )
                {
                case DLL_RX_IL_FRAME:
                    il_hook_receive( hw_inst, p_rmd, l_frm_handle );
                    break;

                case DLL_RX_NM_FRAME:
                    /*------------------------------------------------------
                    Dispatch to Network Management Layer
                    ------------------------------------------------------*/
                    nm_hook_receive( hw_inst, p_rmd );
                    break;

                case DLL_RX_TP_FRAME:
                    /*------------------------------------------------------
                    Dispatch to Transport Layer
                    ------------------------------------------------------*/
                    tp_hook_receive( p_rmd, hw_inst );
                    break;

                case DLL_RX_FT_FRAME:
                    /*------------------------------------------------------
                    Dispatch to Factory Test task
                    ------------------------------------------------------*/
                    ft_hook_receive( hw_inst, p_rmd );
                    break;

                default:
                    break;
                }
            }
        else if( ( l_can_id_match == FALSE ) && ( TRUE == l_can_defined_cantp_id_match ) )
            {
            /*------------------------------------------------------
            Dispatch to Transport Layer(the filters out of the DLL filter table)
            ------------------------------------------------------*/
            tp_hook_receive( p_rmd, hw_inst );
            }
        else if( TRUE == l_can_defined_ydt_id_match )
            {
            /* for detecting ydt online */
            VI_notify_ydt_detected();
            client_appl_set_ydt_connect_state();
            }
        else
            {
            /*do nothings*/
            }
        }
    }
}

/*!*******************************************************************
*
* initialize transmit complete queue
*
* This function initializes the Dispatch Layer transmit complete queue.
*
*********************************************************************/
static void
init_txc_queue
    (
    can_hw_inst_t   const hw_inst       //!< [in] CAN hardware instance
    )
{
dll_txc_queue_info_t    const * l_p_txc_queue_info;

if( hw_inst < CAN_NUM_INSTANCES )
    {
    /*------------------------------------------------------
    Point to CAN instance queue information and initialize
    the queue
    ------------------------------------------------------*/
    l_p_txc_queue_info = &( dll_txc_queue_info[hw_inst] );

    *( l_p_txc_queue_info->p_num )      = 0;
    *( l_p_txc_queue_info->p_max_num )  = 0;
    *( l_p_txc_queue_info->p_next_in )  = 0;
    *( l_p_txc_queue_info->p_next_out ) = 0;
    }
}

/*!*******************************************************************
*
* add transmit complete event to the queue
*
* This function puts an entry in the Dispatch Layer transmit complete
* queue.
*
*********************************************************************/
static void
queue_tx_complete
    (
    can_hw_inst_t   const hw_inst, //!< [in] CAN hardware instance
    can_tmh_t       const tmh      //!< [in] transmit message handle
    )
{
dll_txc_queue_info_t    const * l_p_txc_queue_info;

/*------------------------------------------------------
Point to CAN instance queue information
------------------------------------------------------*/
l_p_txc_queue_info = &( dll_txc_queue_info[hw_inst] );

/*------------------------------------------------------
Check for room in the queue
------------------------------------------------------*/
if( *( l_p_txc_queue_info->p_num ) < l_p_txc_queue_info->size )
    {
    /*------------------------------------------------------
    Store the Transmit Complete Handle (tmh) in the queue.
    Increment the number in the queue, update the maximum
    number (high wather mark), advance the "next_in" index
    and check and adjust for FIFO queue wrap around of the
    next_in index.
    ------------------------------------------------------*/
    l_p_txc_queue_info->p_txc_queue[*( l_p_txc_queue_info->p_next_in )] = tmh;

    ( *( l_p_txc_queue_info->p_num ) )++;

    if( *( l_p_txc_queue_info->p_num ) > *( l_p_txc_queue_info->p_max_num ) )
        {
        *( l_p_txc_queue_info->p_max_num ) = *( l_p_txc_queue_info->p_num );
        }

    ( *( l_p_txc_queue_info->p_next_in ) )++;

    if( ( *( l_p_txc_queue_info->p_next_in ) ) >= l_p_txc_queue_info->size )
        {
        *( l_p_txc_queue_info->p_next_in ) = 0;
        }
    }
else
    {
    /*------------------------------------------------------
    Transmit Complete Queue Overflow
    ------------------------------------------------------*/
    dll_status[hw_inst] |= DLL_STATUS_TXC_OVERFLOW;
    }
}

/*!*******************************************************************
*
* @private
* Dispatch Layer initialization
*
* This function initializes the OSEK CAN Stack Dispatch Layer
*
*********************************************************************/
void
dll_init
    (
    can_hw_inst_t   const hw_inst       //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
Initialize the Dispatch Layer status
------------------------------------------------------*/
dll_status[hw_inst] = 0;

/*------------------------------------------------------
Initialize the Transmit Complete Queue
------------------------------------------------------*/
init_txc_queue( hw_inst );
}

/*!*******************************************************************
*
* @private
* Dispatch Layer periodic transmit task
*
* This function represents the OSEK CAN Stack Dispatch Layer periodic
* task that processes CAN transmit complete notifications and
* dispatches them to the appropriate higher layers of the CAN Stack.
*
*********************************************************************/
void
dll_tx_task
    (
    can_hw_inst_t   const hw_inst       //!< [in] CAN hardware instance
    )
{
dll_txc_queue_info_t    const * l_p_txc_queue_info;
can_tmh_t                       l_tmh;
uint8                           l_txc_q_num;

if( hw_inst < CAN_NUM_INSTANCES )
    {
    /*------------------------------------------------------
    Point to CAN Instance queue info and process all TX
    complete notifications to completion
    ------------------------------------------------------*/
    l_p_txc_queue_info = &( dll_txc_queue_info[hw_inst] );

    do
        {
        /*------------------------------------------------------
        Thread safe read of current number in the queue
        ------------------------------------------------------*/
        l_txc_q_num =  *( l_p_txc_queue_info->p_num );

        /*------------------------------------------------------
        Check for entries in the queue
        ------------------------------------------------------*/
        if( l_txc_q_num > 0 )
            {
            /*------------------------------------------------------
            Get the "next_out" transmit and process the transmit
            complete notification event
            ------------------------------------------------------*/
            l_tmh = l_p_txc_queue_info->p_txc_queue[*( l_p_txc_queue_info->p_next_out )];
            dispatch_txd_frm( hw_inst, l_tmh );

            /*------------------------------------------------------
            Thread safe decrement the number in the queue
            ------------------------------------------------------*/
            taskENTER_CRITICAL( );
            ( *( l_p_txc_queue_info->p_num ) )--;
            taskEXIT_CRITICAL( );

            /*------------------------------------------------------
            Advance the "next_out" index and check and adjust for
            FIFO queue wrap around
            ------------------------------------------------------*/
            ( *( l_p_txc_queue_info->p_next_out ) )++;

            if( ( *( l_p_txc_queue_info->p_next_out ) ) >= l_p_txc_queue_info->size )
                {
                *( l_p_txc_queue_info->p_next_out ) = 0;
                }
            }
        } while( l_txc_q_num > 0 );
    }
}

/*!*******************************************************************
*
* @private
* Dispatch Layer periodic receive task
*
* This function represents the OSEK CAN Stack Dispatch Layer periodic
* task that processes received CAN message frames in the software
* receive queue and dispatches them to the appropriate higher layers
* of the CAN Stack. The Dispatch Layer processing includes performing
* software filtering of any unwanted received messages that could not
* be filtered by the CAN controller due to filter configuration
* limitations.
*
*********************************************************************/
void
dll_rx_task
    (
    can_hw_inst_t   const hw_inst       //!< [in] CAN hardware instance
    )
{
can_rmd_t       l_rmd;
can_ret_code_t  l_ret_code;

/*------------------------------------------------------
Check the Hardware Instance
------------------------------------------------------*/
if( hw_inst < CAN_NUM_INSTANCES )
    {
    /*------------------------------------------------------
    Process the CAN Receive Queue to completion
    ------------------------------------------------------*/
    do
        {
        /*------------------------------------------------------
        Get the next received frame, process it and dispatch it
        to the appropriate upper layer
        ------------------------------------------------------*/
        l_ret_code = can_receive( hw_inst, &l_rmd );

        /*------------------------------------------------------
        Check for valid received frame
        ------------------------------------------------------*/
        if( CAN_RC_OK == l_ret_code )
            {
            /*------------------------------------------------------
            Dispatch it
            ------------------------------------------------------*/
            dispatch_rxd_frm( hw_inst, &l_rmd );
            }
        } while( CAN_RC_OK == l_ret_code );
    }
}

/*!*******************************************************************
*
* @private
* CAN driver frame reception notification
*
* This function is the callback function from the CAN Driver layer
* for that informs the Dispatch Layer that a CAN message frame has
* been received. This callback can be used to generate a callback into
* the application that allows for processing any received CAN frame in
* the receive interrupt context for expedited processing. This should
* only be used if absolutely necessary as this callback is issued by
* the CAN driver in the receive interrupt context.
*
*********************************************************************/
void
can_drv_hook_receive
    (
    can_hw_inst_t   const   hw_inst,     //!< [in] CAN hardware instance
    can_hmb_t       const   rx_mb_index, //!< [in] handle to hardware message vector
    can_rmd_t const * const p_rmd        //!< [in] ptr to received CAN frame data structure

    )
{
/*------------------------------------------------------
Notify the NM layer of any frame reception for BusOFF
recovery detection.
------------------------------------------------------*/
nm_hook_notify_any_can_frame_reception( hw_inst );
}

/*!*******************************************************************
*
* @private
* CAN driver transmit complete notification callback
*
* This function is the callback function from the CAN Driver layer
* for processing CAN message frame transmit complete notifications.
* This callback is issued by the CAN driver in the transmit complete
* interrupt context so processing in this callback needs to be as
* short and efficient as possible (i.e. just put the notification in
* a queue and defer subsequent processing to the DLL layer transmit
* task context if possible).
*
*********************************************************************/
void
can_drv_hook_transmit
    (
    can_hw_inst_t   const hw_inst,     //!< [in] CAN hardware instance
    can_hmb_t       const tx_mb_index, //!< [in] handle to hardware message vector
    can_tmh_t       const tmh          //!< [in] transmit message handle
    )
{
if( ( tmh >= TP_MIN_FRAME_HANDLE ) &&
    ( tmh <= TP_MAX_FRAME_HANDLE ) )
    {
    tp_hook_transmit( tmh, hw_inst );
    }
else
    {
    /*------------------------------------------------------
    Queue the Transmit Complete notification
    ------------------------------------------------------*/
    queue_tx_complete( hw_inst, tmh );
    }

/*------------------------------------------------------
Notify the NM layer of any frame transmission for BusOFF
recovery detection.
------------------------------------------------------*/
nm_hook_notify_any_can_frame_transmission( hw_inst );

CAN_IGNORE_PARAMETER( tx_mb_index );
}

/*!*******************************************************************
*
* @private
* CAN driver transmit timeout notification
*
* This function is the callback function from the CAN Driver layer
* for processing CAN message frame transmit timeout notifications.
*
*********************************************************************/
void
can_drv_hook_transmit_timeout
    (
    can_hw_inst_t   const hw_inst, //!< [in] CAN hardware instance
    can_tmh_t       const tmh      //!< [in] transmit message handle
    )
{
if( ( tmh >= TP_MIN_FRAME_HANDLE ) &&
    ( tmh <= TP_MAX_FRAME_HANDLE ) )
    {
    tp_hook_transmit_timeout( tmh, hw_inst );
    }
else if( tmh == IL_CAN0_TX_NM_AND_LP_BK_TXFRM_HANDLE )
    {
    /*------------------------------------------------------
    Notify the Network Management Layer of the timeout for
    handling of the SUPERVISION flags and counts.
    ------------------------------------------------------*/
    nm_hook_transmit_timeout( hw_inst, tmh );
    }
else
    {
    /*------------------------------------------------------
    Notify the Interaction Layer of the transmit timeout.
    Because of TX Mute functionality this cannot be treated
    the same as a transmit completion.
    ------------------------------------------------------*/
    il_hook_transmit_timeout( hw_inst, tmh );
    }
}

/*!*******************************************************************
*
* @private
* CAN driver operational mode change callback
*
* This function is the callback function from the CAN Driver layer
* for processing CAN operational mode change event notifications.
* These mode changes include sleep, wakeup, online, offline, etc.
*
*********************************************************************/
void
can_drv_hook_op_mode
    (
    can_hw_inst_t   const hw_inst, //!< [in] CAN hardware instance
    can_op_mode_t   const op_mode  //!< [in] operational mode change
    )
{
/*------------------------------------------------------
Call back to the Network Management Layer to process
operational mode transitions
------------------------------------------------------*/
nm_hook_op_mode( hw_inst, op_mode );
}

/*!*******************************************************************
*
* @private
* can_drv_hook_exception
*
* This function is the callback function from the CAN Driver layer
* for processing BSP CAN Driver layer exceptions such as BusOFF
* events.
*
*********************************************************************/
void
can_drv_hook_exception
    (
    can_hw_inst_t   const hw_inst,       //!< [in] CAN hardware instance
    can_exception_t const exception    //!< [in] CAN driver exception
    )
{
/*------------------------------------------------------
Check for BusOFF condition as that is a special bus
faulted condition that must be handled in the Network
Management layer
------------------------------------------------------*/
if( CAN_EX_BUSOFF == exception )
    {
    nm_hook_bus_off( hw_inst );
    }
}

