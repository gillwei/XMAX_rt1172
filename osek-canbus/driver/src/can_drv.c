/*!*******************************************************************
* @file can_drv.c
* @brief OSEK CAN Driver Layer
*
* The functions and data structures in this file provide the CAN
* Driver Layer API for CAN message frame transmission and reception.
* This module API supports additional CAN services, including
* initialization, configuration and status management and reporting.
* This driver also manages the software transmit and receive queues.
* This driver is dependent on a lower layer hardware driver that is
* specific to the underlying CAN controller hardware peripheral
* implementation.
*
* @defgroup can_drv CAN Driver Layer
* @ingroup bsp_comps
* @{
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*----------------------------------------------------------------
                            GENERAL INCLUDES
----------------------------------------------------------------*/
#include "can_defs.h"
#include "can_hw.h"
#include "can_cfg.h"
#include "can_bcfg.h"
#include "can_drv.h"

#include "fsl_debug_console.h"
#include "FreeRTOS.h"
#include "task.h"

/*--------------------------------------------------------------------
                            VARIABLES
--------------------------------------------------------------------*/

/*------------------------------------------------------
CAN2 Queue Variables
------------------------------------------------------*/

/*------------------------------------------------------
Transmit Queue and Status
------------------------------------------------------*/
static can_tmd_t const *
p_can0_txq[CAN0_TXQ_SIZE];

static can_qstatus_t
can0_txq_status;

static can_txq_info_t const
can0_txq_info =
    {
    &p_can0_txq[0],
    &can0_txq_status,
    CAN0_TXQ_SIZE
    };

/*------------------------------------------------------
TMD Queue and Status
------------------------------------------------------*/
static can_qtmd_t
can0_tmdq[CAN0_TMDQ_SIZE];

static can_qstatus_t
can0_tmdq_status;

static can_tmdq_info_t  const
can0_tmdq_info =
    {
    &can0_tmdq[0],
    &can0_tmdq_status,
    CAN0_TMDQ_SIZE
    };

/*------------------------------------------------------
Receive Queue and Status
------------------------------------------------------*/
can_rmd_t
can0_rxq[CAN0_RXQ_SIZE];

can_qstatus_t
can0_rxq_status;

static can_rxq_info_t   const
can0_rxq_info =
    {
    &can0_rxq[0],
    &can0_rxq_status,
    CAN0_RXQ_SIZE
    };

/*--------------------------------------------------------------------
CAN Instance Variables
--------------------------------------------------------------------*/

/*------------------------------------------------------
Can Queue Info Pointers
------------------------------------------------------*/
static can_qinfo_ptrs_t const
can_qinfo_ptrs[CAN_NUM_INSTANCES] =
    {
        { &can0_txq_info, &can0_tmdq_info, &can0_rxq_info }
    };

/*------------------------------------------------------
CAN Status
------------------------------------------------------*/
static volatile can_status_t
can_status[CAN_NUM_INSTANCES];

/*------------------------------------------------------
CAN Error Status
------------------------------------------------------*/
static volatile can_status_t
can_error_status[CAN_NUM_INSTANCES];

/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/
/*!*******************************************************************
*
* CAN driver transmit queue initialization
*
* This function initializes a software transmit queue and its status
* variables for a specific CAN hardware instance.
*
*********************************************************************/
static void
txq_init
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
Transmit Queue Info Pointer
------------------------------------------------------*/
can_qinfo_ptrs_t const * l_p_can_qinfo;

/*------------------------------------------------------
Transmit Queue Variables
------------------------------------------------------*/
can_tmd_t const * * l_p_can_txq;
can_qstatus_t     * l_p_can_txq_status;

/*------------------------------------------------------
Initialize Queue Info Pointer
------------------------------------------------------*/
l_p_can_qinfo = &( can_qinfo_ptrs[hw_inst] );

/*------------------------------------------------------
Initialize Transmit Queue Variables
------------------------------------------------------*/
l_p_can_txq        = l_p_can_qinfo->p_txq_info->pp_tmd;
l_p_can_txq_status = l_p_can_qinfo->p_txq_info->p_txq_status;

/*------------------------------------------------------
Check if Transmit Queue is Enabled
------------------------------------------------------*/
if( l_p_can_txq != NULL )
    {
    l_p_can_txq_status->next_in  = 0;
    l_p_can_txq_status->next_out = 0;
    l_p_can_txq_status->qnum     = 0;
    l_p_can_txq_status->qmax_num = 0;
    }
}

/*!*******************************************************************
*
* CAN driver transmit data queue initialization
*
* This function initializes a software transmit data queue and its
* status variables for a specific CAN hardware instance.
*
*********************************************************************/
static void
tmdq_init
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
Queue Info Pointer
------------------------------------------------------*/
can_qinfo_ptrs_t const * l_p_can_qinfo;

/*------------------------------------------------------
TMD Queue Variables
------------------------------------------------------*/
can_qtmd_t        * l_p_can_tmdq;
can_qstatus_t     * l_p_can_tmdq_status;

/*------------------------------------------------------
Initialize Queue Info Pointer
------------------------------------------------------*/
l_p_can_qinfo = &can_qinfo_ptrs[hw_inst];

/*------------------------------------------------------
Initialize TMD Queue Variables
------------------------------------------------------*/
l_p_can_tmdq        = l_p_can_qinfo->p_tmdq_info->p_tmd;
l_p_can_tmdq_status = l_p_can_qinfo->p_tmdq_info->p_tmdq_status;

/*------------------------------------------------------
Check if TMD Queue is Enabled
------------------------------------------------------*/
if( l_p_can_tmdq != NULL )
    {
    /*--------------------------------------------------
    Initialize Transmit Data Queue
    --------------------------------------------------*/
    l_p_can_tmdq_status->next_in  = 0;
    l_p_can_tmdq_status->next_out = 0;
    l_p_can_tmdq_status->qnum     = 0;
    l_p_can_tmdq_status->qmax_num = 0;
    }
}

/*!*******************************************************************
*
* flush CAN driver software and/or hardware pending transmissions
*
* This function flushes pending message transmissions. It can be used
* to flush all pending message transmissions, including any hardware
* pending message transmissions as well as any transmissions that are
* in the software transmit queue. It can also be used to flush a
* pending message transmission from a specific hardware transmit
* bufferor from all hardware Message Buffers that are configured
* for message transmission.
*
*********************************************************************/
static void
tx_flush
    (
    can_hw_inst_t   const hw_inst,    //!< [in] CAN hardware instance
    can_hmb_t       const tx_mb_index //!< [in] transmit Message Buffer instance
    )
{
/*------------------------------------------------------
Message Buffer index is from 0~CAN_HMB_ALL, tx_index is from
CAN_HMB_TX_START + CAN_HMB_TX_START
------------------------------------------------------*/
if( ( tx_mb_index > ( CAN_HMB_TX_ALL + CAN_HMB_TX_START ) ) ||
    ( tx_mb_index < CAN_HMB_TX_START ) )
    {
    return ;
    }
else
    {
    can_hw_tx_flush( hw_inst );
    }

/*------------------------------------------------------
Check for Initialization of the Transmit Queues
------------------------------------------------------*/
if( CAN_HMB_TX_MAX == tx_mb_index )
    {
    txq_init( hw_inst );
    tmdq_init( hw_inst );
    }
}

/*!*******************************************************************
*
* check CAN driver transmit queue for errors
*
* This function checks the transmit and transmit data queues to ensure
* the "next in" and "next out" indexes have not exceeded the allocated
* size of these queues. This function is normally called by the CAN
* driver periodic task as part of its normal monitoring activities.
*
*********************************************************************/
static void
txq_check
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
Queue Info Pointer
------------------------------------------------------*/
can_qinfo_ptrs_t const * l_p_can_qinfo;

/*------------------------------------------------------
Transmit Queue Variables
------------------------------------------------------*/
can_tmd_t     const * * l_pp_can_txq;
can_qstatus_t         * l_p_can_txq_status;
uint8                   l_can_txq_size;

/*------------------------------------------------------
TMD Queue Variables
------------------------------------------------------*/
can_qtmd_t            * l_p_can_tmdq;
can_qstatus_t         * l_p_can_tmdq_status;
uint8                   l_can_tmdq_size;

/*------------------------------------------------------
Initialize Queue Info Pointer
------------------------------------------------------*/
l_p_can_qinfo = &can_qinfo_ptrs[hw_inst];

/*------------------------------------------------------
Initialize Transmit Queue Variables
------------------------------------------------------*/
l_pp_can_txq        = l_p_can_qinfo->p_txq_info->pp_tmd;
l_p_can_txq_status  = l_p_can_qinfo->p_txq_info->p_txq_status;
l_can_txq_size      = l_p_can_qinfo->p_txq_info->txq_size;

/*------------------------------------------------------
Initialize TMD Queue Variables
------------------------------------------------------*/
l_p_can_tmdq        = l_p_can_qinfo->p_tmdq_info->p_tmd;
l_p_can_tmdq_status = l_p_can_qinfo->p_tmdq_info->p_tmdq_status;
l_can_tmdq_size     = l_p_can_qinfo->p_tmdq_info->tmdq_size;

/*------------------------------------------------------
Check if Transmit Queue is Enabled
------------------------------------------------------*/
if( l_pp_can_txq != NULL )
    {
    /*--------------------------------------------------
    Check the Transmit Queue
    --------------------------------------------------*/
    if( ( l_p_can_txq_status->next_in  >= l_can_txq_size )      ||
        ( l_p_can_txq_status->next_out >= l_can_txq_size ) )
        {
        /*----------------------------------------------
        Flag Transmit Queue Error
        ----------------------------------------------*/
        can_error_status[hw_inst] |= CAN_DRV_ERR_TXQ;

        /*----------------------------------------------
        Notify the Application
        ----------------------------------------------*/
        can_drv_hook_exception( hw_inst, CAN_EX_TXQ_ERROR );
        }
    }

/*------------------------------------------------------
Check if Transmit Data Queue is Enabled
------------------------------------------------------*/
if( l_p_can_tmdq != NULL )
    {
    /*--------------------------------------------------
    Check the Transmit Data Queue
    --------------------------------------------------*/
    if( ( l_p_can_tmdq_status->next_in  >= l_can_tmdq_size )    ||
        ( l_p_can_tmdq_status->next_out >= l_can_tmdq_size ) )
        {
        /*----------------------------------------------
        Flag TMD Queue Error
        ----------------------------------------------*/
        can_error_status[hw_inst] |= CAN_DRV_ERR_TMDQ;

        /*----------------------------------------------
        Notify the Application
        ----------------------------------------------*/
        can_drv_hook_exception( hw_inst, CAN_EX_TMDQ_ERROR );
        }
    }
}

/*!*******************************************************************
*
* check CAN driver for any pending message frame transmissions
*
* This function checks for pending message transmissions. It can be
* used to check all pending message transmissions, including any
* hardware pending message transmissions as well as any transmissions
* that are in the transmit queue. It can also be used to check for a
* pending message transmission in a specific hardware transmit buffer
* or from all hardware Message Object that are configured for message
* transmission.
*
* @return can_ret_code_t
* return code indicating CAN_RC_TRUE or CAN_RC_FALSE
*
*********************************************************************/
static can_ret_code_t
is_tx_pending
    (
    can_hw_inst_t   const hw_inst,    //!< [in] CAN hardware instance
    can_hmb_t       const tx_mb_index //!< [in] transmit Message Buffer instance
    )
{
uint8 l_index = 0;

/*------------------------------------------------------
Queue Info Pointer
------------------------------------------------------*/
can_qinfo_ptrs_t const   * l_p_can_qinfo;

/*------------------------------------------------------
Transmit Queue Variables
------------------------------------------------------*/
can_tmd_t        const * * l_pp_can_txq;
can_qstatus_t            * l_p_can_txq_status;

/*------------------------------------------------------
Return Code
------------------------------------------------------*/
can_ret_code_t             l_ret_code = CAN_RC_FALSE;

/*------------------------------------------------------
Initialize Queue Info Pointer
------------------------------------------------------*/
l_p_can_qinfo = &can_qinfo_ptrs[hw_inst];

/*------------------------------------------------------
Get Transmit Queue Variables
------------------------------------------------------*/
l_pp_can_txq       = l_p_can_qinfo->p_txq_info->pp_tmd;
l_p_can_txq_status = l_p_can_qinfo->p_txq_info->p_txq_status;

/*------------------------------------------------------
Check if Transmit Queue is Enabled
------------------------------------------------------*/
if( l_pp_can_txq != NULL )
    {
    /*----------------------------------------------
    Check for Entries in the Transmit Queue
    ----------------------------------------------*/
    if( l_p_can_txq_status->qnum > 0 )
        {
        /*------------------------------------------
        Transmit Messages are Pending
        ------------------------------------------*/
        l_ret_code = CAN_RC_TRUE;
        }

    /*--------------------------------------------------
    Check for software queue mode
    --------------------------------------------------*/
    if( CAN_HMB_TX_MAX == tx_mb_index )
        {
        /*----------------------------------------------
        Check All Hardware Buffers for Transmit Pending
        ----------------------------------------------*/
        for( l_index = CAN_HMB_TX_START; l_index < CAN_HMB_TX_MAX; l_index++ )
            {
            l_ret_code = can_hw_is_tx_pending( hw_inst, tx_mb_index  );
            if( l_ret_code == CAN_RC_TRUE )
                {
                break;
                }
            }
        }
    else
        {
        /*----------------------------------------------
        Check Specific Hardware Buffer for Tx Pending
        ----------------------------------------------*/
        l_ret_code = can_hw_is_tx_pending( hw_inst, CAN_HMB_TX_MAX );
        }
    }

return l_ret_code;
}

/*!*******************************************************************
*
* service the transmit queue
*
* This function checks for and services any pending message
* transmission in the software transmit queue by removing the next
* pending message frame and transmitting it.
*
*********************************************************************/
static void
txq_service
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
Queue Info Pointer
------------------------------------------------------*/
can_qinfo_ptrs_t const * l_p_can_qinfo;

/*------------------------------------------------------
Transmit Queue Variables
------------------------------------------------------*/
can_tmd_t const * * l_pp_can_txq;
can_qstatus_t     * l_p_can_txq_status;
uint8               l_can_txq_size;

/*------------------------------------------------------
TMD Queue Variables
------------------------------------------------------*/
can_qstatus_t     * l_p_can_tmdq_status;
uint8               l_p_can_tmdq_size;

/*------------------------------------------------------
Pointer to Transmit Data Structure
------------------------------------------------------*/
can_tmd_t   const * l_p_tmd;

/*------------------------------------------------------
Initialize Queue Info Pointer
------------------------------------------------------*/
l_p_can_qinfo  = &can_qinfo_ptrs[hw_inst];

/*------------------------------------------------------
Get Transmit Queue Size (Use it to Check for TxQ Enabled)
------------------------------------------------------*/
l_can_txq_size = l_p_can_qinfo->p_txq_info->txq_size;

if( l_can_txq_size > 0 )
    {
    /*--------------------------------------------------
    Initialize Transmit Queue Variables
    --------------------------------------------------*/
    l_pp_can_txq       = l_p_can_qinfo->p_txq_info->pp_tmd;
    l_p_can_txq_status = l_p_can_qinfo->p_txq_info->p_txq_status;

    /*--------------------------------------------------
    Check for Entries in the Transmit Queue and Transmit
    Operation Not Suspended
    --------------------------------------------------*/
    while( l_p_can_txq_status->qnum > 0 )
        {
        /*----------------------------------------------
        Get the Next TMD Pointer
        ----------------------------------------------*/
        l_p_tmd = l_pp_can_txq[l_p_can_txq_status->next_out];

        /*----------------------------------------------
        Attempt to Transmit the Message in Hardware
        ----------------------------------------------*/
        can_hw_transmit( hw_inst, l_p_tmd );

        /*------------------------------------------
        Sucessfully Transmitted...Take it Out of the Queue
        ------------------------------------------*/
        l_p_can_txq_status->qnum--;

        /*------------------------------------------
        Increment "Next Out" Index and Check for Wraparound
        ------------------------------------------*/
        l_p_can_txq_status->next_out++;

        if( l_p_can_txq_status->next_out >= l_can_txq_size )
            {
            l_p_can_txq_status->next_out = 0;
            }

        /*------------------------------------------
        Get TMDQ Size (Use it to Check for TmdQ
        Enabled)
        ------------------------------------------*/
        l_p_can_tmdq_size = l_p_can_qinfo->p_tmdq_info->tmdq_size;

        /*------------------------------------------
        Check for Queued TMD
        ------------------------------------------*/
        if( l_p_can_tmdq_size > 0 )
            {
            /*--------------------------------------
            Get Pointer to TMDQ Status
            --------------------------------------*/
            l_p_can_tmdq_status = l_p_can_qinfo->p_tmdq_info->p_tmdq_status;

            /*--------------------------------------
            Decrement Number in the Queued TMD Queue
            --------------------------------------*/
            l_p_can_tmdq_status->qnum--;

            /*--------------------------------------
            Increment "Next Out" Index, Check for
            Wraparound
            --------------------------------------*/
            l_p_can_tmdq_status->next_out++;

            if( l_p_can_tmdq_status->next_out >= l_p_can_tmdq_size )
                {
                l_p_can_tmdq_status->next_out = 0;
                }
            }
        };
    }
}

/*!*******************************************************************
*
* initialize the CAN driver software receive queue
*
* This function initializes the software receive queue and its status
* variables for a specific CAN hardware instance.
*
*********************************************************************/
static void
rxq_init
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
Queue Info Pointer
------------------------------------------------------*/
can_qinfo_ptrs_t    const * l_p_can_qinfo;

/*------------------------------------------------------
Receive Queue Variables
------------------------------------------------------*/
can_rmd_t           const * l_p_can_rxq;
can_qstatus_t             * l_p_can_rxqStatus;

/*------------------------------------------------------
Initialize Queue Info Pointer
------------------------------------------------------*/
l_p_can_qinfo = &can_qinfo_ptrs[hw_inst];

/*------------------------------------------------------
Initialize Receive Queue Variables
------------------------------------------------------*/
l_p_can_rxq       = l_p_can_qinfo->p_rxq_info->p_rxq;
l_p_can_rxqStatus = l_p_can_qinfo->p_rxq_info->p_rxq_status;

/*------------------------------------------------------
Check if Receive Queue is Enabled
------------------------------------------------------*/
if( l_p_can_rxq != NULL )
    {
    l_p_can_rxqStatus->next_in  = 0;
    l_p_can_rxqStatus->next_out = 0;
    l_p_can_rxqStatus->qnum     = 0;
    l_p_can_rxqStatus->qmax_num = 0;
    }
}

/*!*******************************************************************
*
* flush CAN driver receive buffers
*
* This function flushes pending message receptions. It can be used to
* flush all pending message receptions, including any hardware pending
* message receptions as well as any receptions that are in the
* software receive queue. It can also be used to flush a pending
* message reception from a specific hardware receive buffer or from
* all the hardware Message Buffers that are configured for
* message reception.
*
*********************************************************************/
static void
rx_flush
    (
    can_hw_inst_t   const hw_inst,    //!< [in] CAN hardware instance
    can_hmb_t       const rx_mb_index //!< [in] receive Message Buffer instance
    )
{
/*------------------------------------------------------
Flush a specific H/W Receive Buffer
------------------------------------------------------*/
can_hw_rx_flush( hw_inst );

/*------------------------------------------------------
Check for Initialization of the Software Receive Queue
------------------------------------------------------*/
if( CAN_HMB_RX_ALL == rx_mb_index )
    {
    rxq_init( hw_inst );
    }
}

/*!*******************************************************************
*
* check the CAN driver software receive queue
*
* This function checks the software receive queue to ensure the
* "next in" and "next out" indexes have not exceeded the allocated
* size of the queue.  This function is normally called by the CAN
* driver periodic task as part of its normal monitoring activities.
*
*********************************************************************/
static void
rxq_check
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
Queue Info Pointer
------------------------------------------------------*/
can_qinfo_ptrs_t const * l_p_can_qinfo;

/*------------------------------------------------------
Receive Queue Variables
------------------------------------------------------*/
can_rmd_t     * l_p_can_rxq;
can_qstatus_t * l_p_can_rxq_status;
uint8           l_can_rxq_size;

/*------------------------------------------------------
Initialize Queue Info Pointer
------------------------------------------------------*/
l_p_can_qinfo = &can_qinfo_ptrs[hw_inst];

/*------------------------------------------------------
Initialize Receive Queue Variables
------------------------------------------------------*/
l_p_can_rxq        = l_p_can_qinfo->p_rxq_info->p_rxq;
l_p_can_rxq_status = l_p_can_qinfo->p_rxq_info->p_rxq_status;
l_can_rxq_size     = l_p_can_qinfo->p_rxq_info->rxq_size;

/*------------------------------------------------------
Check if Receive Queue is Enabled
------------------------------------------------------*/
if( l_p_can_rxq != NULL )
    {
    /*--------------------------------------------------
    Check the Receive Queue
    --------------------------------------------------*/
    if( ( l_p_can_rxq_status->next_in  >= l_can_rxq_size )      ||
        ( l_p_can_rxq_status->next_out >= l_can_rxq_size ) )
        {
        /*----------------------------------------------
        Flag Receive Queue Error
        ----------------------------------------------*/
        can_error_status[hw_inst] |= CAN_DRV_ERR_RXQ;

        can_drv_hook_exception( hw_inst, CAN_EX_RXQ_ERROR );
        }
    }
}

/*!*******************************************************************
*
* atomically set CAN driver status bit(s)
*
* This function is used to atomically (in a critical section) set CAN
* driver status bits using the specified bit mask value.
*
*********************************************************************/
static void
set_status_bit
    (
    can_hw_inst_t   const hw_inst, //!< [in] CAN hardware instance
    can_status_t    const bit_mask //!< [in] bit mask for which bits to set
    )
{
/*------------------------------------------------------
Disable Interrupts to Set Status Bits
------------------------------------------------------*/
can_status[hw_inst] |= bit_mask;
}

/*!*******************************************************************
*
* atomically clear CAN driver status bit(s)
*
* This function is used to atomically (in a critical section) clear
* CAN driver status bits using the specified bit mask value.
*
*********************************************************************/
static void
clear_status_bit
    (
    can_hw_inst_t   const hw_inst, //!< [in] CAN hardware instance
    can_status_t    const bit_mask //!< [in] bit mask for which bits to clear
    )
{
/*------------------------------------------------------
Disable Interrupts to Clear Status Bits
------------------------------------------------------*/
can_status[hw_inst] &= SYS_MASK8_COMPLEMENT( bit_mask );
}

/*!*******************************************************************
*
* @private
* CAN driver and controller initialization
*
* This function initializes and enablea a CAN instance including the
* low level CAN controller as well as all of instance specific
* software data in the Driver Layer. The CAN controller
* initialization data source depends on whether the initialization
* vector pointer is a NULL pointer or points to a valid user defined
* initialization data structure. Passing a NULL initialization
* pointer implies the default initialization data structure is to be
* used. The initialization mode determines whether all pending
* messages are flushed prior to initialization and all software
* variables and queues are initialized to zero (COLD INIT) or whether
* all existing data is left intact (WARM INIT).
*
* @return can_ret_code
* return code indicating success or failure
*
*********************************************************************/
can_ret_code_t
can_init
    (
    can_hw_inst_t           const hw_inst,      //!< [in] CAN hardware instance
    can_init_mode_t         const init_mode,    //!< [in] cold or warm initialization
    void            const * const p_init_vector //!< [in] pointer to initialization vector

    )
{
can_ret_code_t l_ret_code;

/*------------------------------------------------------
Perform Specified Initialization Task
------------------------------------------------------*/
switch( init_mode )
    {
    case CAN_INIT_MODE_COLD:
    case CAN_INIT_MODE_WARM:
        if( CAN_INIT_MODE_COLD == init_mode )
            {
            txq_init ( hw_inst );
            tmdq_init( hw_inst );
            rxq_init ( hw_inst );
            }

        /*--------------------------------------------------
        Clear Driver Layer Status and Error Status
        --------------------------------------------------*/
        can_status[hw_inst]       = 0;
        can_error_status[hw_inst] = 0;

        /*--------------------------------------------------
        Initialize CAN Controller Hardware
        --------------------------------------------------*/
        l_ret_code = can_hw_init( hw_inst, init_mode, p_init_vector );

        if( CAN_RC_OK == l_ret_code )
            {
            /*----------------------------------------------
            Notify the Application that CAN is On Line
            ----------------------------------------------*/
            can_drv_hook_op_mode( hw_inst, CAN_OP_MODE_ONLINE );
            }
        else if( CAN_RC_BUSOFF_INIT_PNDG == l_ret_code )
            {
            /*----------------------------------------------
            Notify the Application that a deferred CAN
            initialization is in progress.
            ----------------------------------------------*/
            can_drv_hook_op_mode( hw_inst, CAN_OP_MODE_DEFERRED_INIT_PNDG );
            }
        else
            {
            /*----------------------------------------------
            Do nothing.
            ----------------------------------------------*/
            ;
            }
        break;

    case CAN_INIT_MODE_VERIFY:
        break;

    default:
        l_ret_code = CAN_RC_INVALID_PARAM;
        break;

    } /* switch */

return l_ret_code;
}

/*!*******************************************************************
*
* @private
* transmit CAN driver message frame
*
* Transmit a CAN message on a specific CAN controller using either the
* driver layer software transmit queue (the usual method) or bypassing
* the software transmit queue and using a specific CAN controller
* hardware transmit buffer (not the usual method).
*
* @return can_ret_code
* return code indicating success or failure
*
*********************************************************************/
can_ret_code_t
can_transmit
    (
    can_hw_inst_t       const hw_inst, //!< [in] CAN hardware instance
    can_tmd_t   const * const p_tmd    //!< [in] pointer to transmit message descriptor
    )
{
/*------------------------------------------------------
Queue Info Pointer
------------------------------------------------------*/
can_qinfo_ptrs_t const * l_p_can_qinfo;

/*------------------------------------------------------
Transmit Queue Variables
------------------------------------------------------*/
can_tmd_t const * * l_pp_can_txq;
can_qstatus_t     * l_p_can_txq_status;
uint8               l_can_txq_size;

/*------------------------------------------------------
Other Local Variables
------------------------------------------------------*/
can_ret_code_t      l_ret_code;

/*------------------------------------------------------
Initialize the Return Code
------------------------------------------------------*/
l_ret_code = CAN_RC_NOT_AVAILABLE;

/*------------------------------------------------------
Check for valid pointer to transmit data structure
------------------------------------------------------*/
if( NULL == p_tmd )
    {
    l_ret_code = CAN_RC_NULL_PTR;
    }
else
    {
    /*------------------------------------------------------
    Initialize Queue Info Pointer
    ------------------------------------------------------*/
    l_p_can_qinfo = &can_qinfo_ptrs[hw_inst];

    /*------------------------------------------------------
    Initialize Transmit Queue Variables
    ------------------------------------------------------*/
    l_pp_can_txq        = l_p_can_qinfo->p_txq_info->pp_tmd;
    l_p_can_txq_status  = l_p_can_qinfo->p_txq_info->p_txq_status;
    l_can_txq_size      = l_p_can_qinfo->p_txq_info->txq_size;

    /*--------------------------------------------------
    Start Process With No Errors
    --------------------------------------------------*/
    l_ret_code = CAN_RC_OK;

    /*--------------------------------------------------
    Check for Enough Room in the Transmit Queue
    --------------------------------------------------*/
    if( l_p_can_txq_status->qnum >= l_can_txq_size )
        {
        /*----------------------------------------------
        Flag Transmit Queue Overrun Error
        ----------------------------------------------*/
        can_error_status[hw_inst] |= CAN_DRV_ERR_TXQ_OVERRUN;
        l_ret_code = CAN_RC_TXQ_OVERRUN;
        }
    else
        {
        /*----------------------------------------------
        Initially Assume p_tmd Gets Stored in TMD Queue
        ----------------------------------------------*/
        l_pp_can_txq[l_p_can_txq_status->next_in] = p_tmd;

        if( CAN_RC_OK == l_ret_code )
            {
            /*------------------------------------------
            Increment "Next In" Index, Check for
            Wraparound
            ------------------------------------------*/
            l_p_can_txq_status->next_in++;

            if( l_can_txq_size <= l_p_can_txq_status->next_in )
                {
                l_p_can_txq_status->next_in = 0;
                }

            /*------------------------------------------
            Increment Number of Messages in the Queue
            ------------------------------------------*/
            l_p_can_txq_status->qnum++;

            /*--------------------------------------
            Save the largest Q size
            --------------------------------------*/
            if( l_p_can_txq_status->qnum > l_p_can_txq_status->qmax_num )
                {
                l_p_can_txq_status->qmax_num = l_p_can_txq_status->qnum;
                }
            }
        }
    }

return l_ret_code;
}

/*!*******************************************************************
*
* @private
* receive a CAN driver message frame
*
* Read a CAN message on a specific CAN controller from either the
* Driver Layer software receive queue (the usual method) or bypassing
* the software receive queue and reading a message from a specific
* CAN controller hardware receive buffer (not the usual method).
*
* @return can_ret_code
* return code indicating success or failure
*
*********************************************************************/
can_ret_code_t
can_receive
    (
    can_hw_inst_t   const hw_inst, //!< [in] CAN hardware instance
    can_rmd_t     * const p_rmd    //!< [out] pointer to receive message descriptor
    )
{
/*------------------------------------------------------
Queue Info Pointer
------------------------------------------------------*/
can_qinfo_ptrs_t const * l_p_can_qinfo;

/*------------------------------------------------------
Receive Queue Variables
------------------------------------------------------*/
can_rmd_t     * l_p_can_rxq;
can_qstatus_t * l_p_can_rxq_status;
uint8           l_can_rxq_size;

/*------------------------------------------------------
Return Code
------------------------------------------------------*/
can_ret_code_t   l_ret_code = CAN_RC_NOT_AVAILABLE;

/*------------------------------------------------------
Initialize Queue Info Pointer
------------------------------------------------------*/
l_p_can_qinfo = &can_qinfo_ptrs[hw_inst];

/*------------------------------------------------------
Initialize Receive Queue Variables
------------------------------------------------------*/
l_p_can_rxq        = l_p_can_qinfo->p_rxq_info->p_rxq;
l_p_can_rxq_status = l_p_can_qinfo->p_rxq_info->p_rxq_status;
l_can_rxq_size     = l_p_can_qinfo->p_rxq_info->rxq_size;

/*------------------------------------------------------
Check for Receive Messages in the Queue
------------------------------------------------------*/
if( ( l_p_can_rxq_status->qnum > 0 ) && ( p_rmd != NULL ) )
    {
    /*--------------------------------------------------
    Copy the Message into the Specified RMD Data
    Structure
    --------------------------------------------------*/
    *p_rmd = l_p_can_rxq[l_p_can_rxq_status->next_out];

    /*--------------------------------------------------
    Thread safe decrement of the number in the queue
    --------------------------------------------------*/
    taskENTER_CRITICAL();
    l_p_can_rxq_status->qnum--;
    taskEXIT_CRITICAL();

    /*--------------------------------------------------
    Increment "Next Out" index, check and adjust for
    FIFO queue wrap around
    --------------------------------------------------*/
    l_p_can_rxq_status->next_out++;

    if( l_can_rxq_size <= l_p_can_rxq_status->next_out )
        {
        l_p_can_rxq_status->next_out = 0;
        }

    l_ret_code = CAN_RC_OK;
    }

return l_ret_code;
}

/*!*******************************************************************
*
* @private
* CAN driver periodic task
*
* This function is optional for interrupt driven operation. The design
* of the driver in interrupt driven mode is such that the transmit
* queues are checked upon transmission completion for any pending
* messages. If checking of the state of the transmit and receive
* queues is required this function call performs those tasks.
*
*********************************************************************/
void can_periodic
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
can_status_t  l_can_hw_status;

/*------------------------------------------------------
Get the CAN Hardware Status
------------------------------------------------------*/
l_can_hw_status = can_hw_get_status( hw_inst, CAN_GET_HW_STATUS );

/*------------------------------------------------------
Must be OnLine for periodic service
------------------------------------------------------*/
if( ( l_can_hw_status & CAN_HW_ONLINE ) != 0 )
    {
    /*--------------------------------------------------
    Check Receive and Transmit Queues
    --------------------------------------------------*/
    rxq_check( hw_inst );
    txq_check( hw_inst );

    /*--------------------------------------------------
    Service Queued Transmit Requests
    --------------------------------------------------*/
    txq_service( hw_inst );
    }

#if( CAN_HW_TRANSMIT_TIMEOUT_ENABLE != FALSE )
    can_hw_periodic( hw_inst );
#endif
}

/*!*******************************************************************
*
* @private
* CAN driver ancillary services
*
* This function provides general CAN driver services excluding message
* transmission and reception functionality. Supported services include
* taking the CAN driver offline or returning it online, putting the
* CAN controller to sleep, waking it up, suspending or enabling
* message transmission and reception, enabling and disabling
* interrupts, etc. This function also provides services that change
* the operation mode of the driver including the transmission mode
* (FIFO or Priority) or flushing pending transmit or receive messages
* from the queues.
*
* @return can_ret_code
* return code indicating success or failure
*
*********************************************************************/
can_ret_code_t
can_service
    (
    can_hw_inst_t   const hw_inst,        //!< [in] CAN hardware instance
    can_hmb_t       const mb_index,       //!< [in] Message Buffer instance
    can_svc_t       const service_request //!< [in] CAN service request type
    )
{
can_ret_code_t l_ret_code = CAN_RC_OK;

/*------------------------------------------------------
Process the Requested Service
------------------------------------------------------*/
switch( service_request )
{
    case CAN_SVC_ONLINE:
        /*----------------------------------------------
        Put CAN Controller OnLine
        ----------------------------------------------*/
        l_ret_code = can_hw_on_line( hw_inst );
        break;

    case CAN_SVC_OFFLINE:
        /*----------------------------------------------
        Take the CAN Controller Offline
        ----------------------------------------------*/
        l_ret_code = can_hw_off_line( hw_inst );
        break;

    case CAN_SVC_POWER_DOWN:
        /*----------------------------------------------
        Put CAN Controller in Low Power Mode
        ----------------------------------------------*/
        l_ret_code = can_hw_power_down( hw_inst );
        break;

    case CAN_SVC_SLEEP:
        /*----------------------------------------------
        Put CAN Controller in Sleep Mode
        ----------------------------------------------*/
        l_ret_code = can_hw_sleep( hw_inst );
        break;

    case CAN_SVC_WAKEUP:
        /*----------------------------------------------
        Host Wakeup of CAN Controller
        ----------------------------------------------*/
        l_ret_code = can_hw_wakeup( hw_inst );
        break;

    case CAN_SVC_BUS_IS_ACTIVE:
        /*----------------------------------------------
        Check for Bus Activity Since Last Check
        ----------------------------------------------*/
        l_ret_code = can_hw_is_bus_active( hw_inst );
        break;

    case CAN_SVC_BUS_IS_SLEEPING:
        /*----------------------------------------------
        Check for Sleeping Bus
        ----------------------------------------------*/
        l_ret_code = can_hw_is_bus_sleep( hw_inst );
        break;

    case CAN_SVC_HW_IS_SLEEPING:
        /*----------------------------------------------
        Check for Sleeping CAN Controller
        ----------------------------------------------*/
        break;

    case CAN_SVC_BUS_IS_OPEN:
        /*----------------------------------------------
        Check for Sleeping CAN Controller
        ----------------------------------------------*/
        l_ret_code = can_hw_is_bus_open( hw_inst );
        break;

    case CAN_SVC_TX_IS_PENDING:
        /*----------------------------------------------
        Check for Pending Transmissions
        ----------------------------------------------*/
        l_ret_code = is_tx_pending( hw_inst, mb_index );
        break;

    case CAN_SVC_TX_FLUSH:
        /*----------------------------------------------
        Flush Pending Transmit Requests
        ----------------------------------------------*/
        tx_flush( hw_inst, mb_index );
        break;

    case CAN_SVC_RX_FLUSH:
        /*----------------------------------------------
        Flush Pending Message Receptions
        ----------------------------------------------*/
        rx_flush( hw_inst, mb_index );
        break;

    case CAN_SVC_ENABLE_TX_TIMEOUT:
        /*----------------------------------------------
        Enable Transmit Timeouts
        ----------------------------------------------*/
        can_hw_enable_transmit_timeout( hw_inst );
        break;

    case CAN_SVC_DISABLE_TX_TIMEOUT:
        /*----------------------------------------------
        Disable Transmit Timeouts
        ----------------------------------------------*/
        can_hw_disable_transmit_timeout( hw_inst );
        break;

    case CAN_SVC_SUSPEND_ALL:
        /*----------------------------------------------
        Suspend Transmit and Receive Operations
        ----------------------------------------------*/
        set_status_bit(  hw_inst, ( CAN_DRV_TX_SUSPEND | CAN_DRV_RX_SUSPEND ) );
        break;

    case CAN_SVC_SUSPEND_TX:
        /*----------------------------------------------
        Suspend Transmit Operations
        ----------------------------------------------*/
        set_status_bit( hw_inst, CAN_DRV_TX_SUSPEND );
        break;

    case CAN_SVC_SUSPEND_RX:
        /*----------------------------------------------
        Suspend Receive Operations
        ----------------------------------------------*/
        set_status_bit( hw_inst, CAN_DRV_RX_SUSPEND );
        break;

    case CAN_SVC_RESUME_ALL:
        /*----------------------------------------------
        Resume Transmit and Receive Operations
        ----------------------------------------------*/
        clear_status_bit( hw_inst, ( CAN_DRV_TX_SUSPEND | CAN_DRV_RX_SUSPEND ) );
        break;

    case CAN_SVC_RESUME_TX:
        /*----------------------------------------------
        Resume Transmit Operations
        ----------------------------------------------*/
        clear_status_bit( hw_inst, CAN_DRV_TX_SUSPEND );
        break;

    case CAN_SVC_RESUME_RX:
        /*----------------------------------------------
        Resume Receive Operations
        ----------------------------------------------*/
        clear_status_bit( hw_inst, CAN_DRV_RX_SUSPEND );
        break;

    case CAN_SVC_ENABLE_RX_INT:
        /*----------------------------------------------
        Enable RX Interrupt
        ----------------------------------------------*/
        l_ret_code = can_hw_enable_rx_interrupt( hw_inst, mb_index );
        break;

    case CAN_SVC_DISABLE_RX_INT:
        /*----------------------------------------------
        Disable RX Interrupt
        ----------------------------------------------*/
        l_ret_code = can_hw_disable_rx_interrupt( hw_inst, mb_index );
        break;

    case CAN_SVC_ENABLE_INTS:
        /*----------------------------------------------
        Enable CAN Interrupts
        ----------------------------------------------*/
        l_ret_code = can_hw_enable_interrupts( hw_inst );
        break;

    case CAN_SVC_DISABLE_INTS:
        /*----------------------------------------------
        Disable CAN Interrupts
        ----------------------------------------------*/
        l_ret_code = can_hw_disable_interrupts( hw_inst );
        break;

    case CAN_SVC_ENABLE_TX_PRI_MODE:
        /*----------------------------------------------
        Enable CAN Interrupts
        ----------------------------------------------*/
        break;

    case CAN_SVC_DISABLE_TX_PRI_MODE:
        /*----------------------------------------------
        Disable CAN Interrupts
        ----------------------------------------------*/
        break;

#if( CAN_DEBUG == TRUE )

    case CAN_SVC_ENABLE_LOOPBACK:
        /*----------------------------------------------
        Enable Loopback Mode
        ----------------------------------------------*/
        break;

    case CAN_SVC_DISABLE_LOOPBACK:
        /*----------------------------------------------
        Disable Loopback Mode
        ----------------------------------------------*/
        break;

    case CAN_SVC_ENABLE_SILENTMODE:
        /*----------------------------------------------
        Enable Silent Mode
        ----------------------------------------------*/
        break;


    case CAN_SVC_DISABLE_SILENTMODE:
        /*----------------------------------------------
        Disable Silent Mode
        ----------------------------------------------*/
        break;
#else
    case CAN_SVC_ENABLE_LOOPBACK:
    case CAN_SVC_DISABLE_LOOPBACK:
    case CAN_SVC_ENABLE_SILENTMODE:
    case CAN_SVC_DISABLE_SILENTMODE:
        l_ret_code = CAN_RC_NOT_AVAILABLE;
        break;
#endif

    /*--------------------------------------------------
    AUTO TRANSMIT Feature Only Applies to Full CAN
    Controllers
    --------------------------------------------------*/
    case CAN_SVC_ENABLE_AUTOTX:
        /*----------------------------------------------
        Enable Auto Tx Remote Response
        ----------------------------------------------*/
        break;

    case CAN_SVC_DISABLE_AUTOTX:
        /*----------------------------------------------
        Disable Auto Tx Remote Response
        ----------------------------------------------*/
        break;

    case CAN_SVC_ENABLE_TX_INT:
        /*----------------------------------------------
        Enable TX Interrupt For Specified Tx. Buffer
        ----------------------------------------------*/
        l_ret_code = can_hw_enable_tx_interrupt( hw_inst, mb_index );
        break;

    case CAN_SVC_DISABLE_TX_INT:
        /*----------------------------------------------
        Disable TX Interrupt For Specified Tx. Buffer
        ----------------------------------------------*/
        l_ret_code = can_hw_disable_tx_interrupt( hw_inst, mb_index );
        break;

    default:

        l_ret_code = CAN_RC_INVALID_SERVICE;
        break;
    }

return l_ret_code;
}

/*!*******************************************************************
*
* @private
* CAN driver transmit complete callback
*
* This function is called by the hardware layer to signal successful
* transmission of a CAN message frame. This function is called in an
* ISR context.
*
*********************************************************************/
void
can_hook_transmit
    (
    can_hw_inst_t   const hw_inst,     //!< [in] CAN hardware instance
    can_tmh_t       const tmh,         //!< [in] transmit message handle
    can_hmb_t       const tx_mb_index, //!< [in] hardware transmit vector (buffer)
    boolean         const tx_ok        //!< [in] flag indicating transmit success
    )
{
/*--------------------------------------------------
Check if the message transmitted successfully. If so
then notify the application of successful transmit.
--------------------------------------------------*/
if( tx_ok != FALSE )
    {
    can_drv_hook_transmit( hw_inst, tx_mb_index, tmh );
    }
}

/*!*******************************************************************
*
* @private
* CAN driver transmit timeout callback
*
* This function is called by the hardware layer to notify the
* occurrence of a transmit timeout event.
*
*********************************************************************/
void can_hook_transmit_timeout
    (
    can_hw_inst_t   const hw_inst, //!< [in] CAN hardware instance
    can_tmh_t       const tmh      //!< [in] transmit message handle

    )
{
/*--------------------------------------------------
Notify the Application
--------------------------------------------------*/
can_drv_hook_transmit_timeout( hw_inst, tmh );
}

/*!*******************************************************************
*
* @private
* CAN driver message frame reception callback
*
* This function is called by the hardware layer to signal successful
* reception of a CAN message. This function is called in an ISR
* context. This function simply notifies the application that a CAN
* message has been received. The application is expected to only
* schedule deferred processing of the received message in a non-ISR
* context to keep the receive ISR duration as short as possible.
*
*********************************************************************/
void can_hook_receive
    (
    can_hw_inst_t           const hw_inst,     //!< [in] CAN hardware instance
    can_hmb_t               const rx_mb_index, //!< [in] hardware transmit vector (buffer)
    can_rmd_t       const * const p_rmd        //!< [in] ptr to received CAN frame data structure
    )
{
/*------------------------------------------------------
Check for Receive Suspended
------------------------------------------------------*/
if( 0 == ( can_status[hw_inst] & CAN_DRV_RX_SUSPEND ) )
    {
    /*--------------------------------------------------
    Notify the Application of received message
    --------------------------------------------------*/
    can_drv_hook_receive( hw_inst, rx_mb_index, p_rmd );
    }
}

/*!*******************************************************************
*
* @private
* get pointer to next entry in the software receive queue
*
* This function is called by the hardware layer to get a pointer to
* the next entry in the driver software receive queue. If the software
* receive queue is full this function returns the NULL pointer to
* indicate there is no entry available.
*
* @return can_rmd_t *
* pointer to next entry in the software receive queue, may return NULL
*
*********************************************************************/
can_rmd_t *
can_hook_get_rmd_ptr
    (
    can_hw_inst_t   const hw_inst       //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
Queue Info Pointer
------------------------------------------------------*/
can_qinfo_ptrs_t const * l_p_can_qinfo;

/*------------------------------------------------------
Receive Queue Variables
------------------------------------------------------*/
can_rmd_t     * l_p_rxq;
can_qstatus_t * l_p_can_rxq_status;
can_rmd_t     * l_p_next_rx_in;
uint8           l_can_rxq_size;

/*------------------------------------------------------
Critical interrupt status
------------------------------------------------------*/
UBaseType_t uxSavedInterruptStatus;

/*------------------------------------------------------
Initialize the returned RMD pointer
------------------------------------------------------*/
l_p_next_rx_in = NULL;

/*------------------------------------------------------
Initialize Queue Info Pointer
------------------------------------------------------*/
l_p_can_qinfo = &can_qinfo_ptrs[hw_inst];

/*------------------------------------------------------
Initialize Receive Queue Variables
------------------------------------------------------*/
l_p_rxq            = l_p_can_qinfo->p_rxq_info->p_rxq;
l_p_can_rxq_status = l_p_can_qinfo->p_rxq_info->p_rxq_status;
l_can_rxq_size     = l_p_can_qinfo->p_rxq_info->rxq_size;

if( 0 == ( can_status[hw_inst] & CAN_DRV_RX_SUSPEND ) )
    {
    /*--------------------------------------------------
    Check for Available Received Message Slot in the
    Queue
    --------------------------------------------------*/
    if( l_p_can_rxq_status->qnum < l_can_rxq_size )
        {
        /*----------------------------------------------
        Point to the Next Available Receive Queue Slot
        ----------------------------------------------*/
        l_p_next_rx_in = &( l_p_rxq[l_p_can_rxq_status->next_in] );

        /*----------------------------------------------
        Increment Number in the Receive Queue
        ----------------------------------------------*/
        uxSavedInterruptStatus = taskENTER_CRITICAL_FROM_ISR();
        l_p_can_rxq_status->qnum++;
        taskEXIT_CRITICAL_FROM_ISR( uxSavedInterruptStatus );

        /*--------------------------------------
        Save the largest Q size
        --------------------------------------*/
        if( l_p_can_rxq_status->qnum > l_p_can_rxq_status->qmax_num )
            {
            l_p_can_rxq_status->qmax_num = l_p_can_rxq_status->qnum;
            }

        /*----------------------------------------------
        Update the receive queue "next_in" index for the
        next entry and check and adjust for FIFO queue
        wrap around
        ----------------------------------------------*/
        l_p_can_rxq_status->next_in++;

        if( l_p_can_rxq_status->next_in >=  l_can_rxq_size )
            {
            l_p_can_rxq_status->next_in = 0;
            }
        }
    else
        {
        /*----------------------------------------------
        Flag Receive Queue Overrun Error
        ----------------------------------------------*/
        can_error_status[hw_inst] |= CAN_DRV_ERR_RXQ_OVERRUN;

        /*----------------------------------------------
        Notify the Application
        ----------------------------------------------*/
//        can_drv_hook_exception( hw_inst, CAN_EX_RXQ_OVERRUN );
        }
    }

return l_p_next_rx_in;
}

/*!*******************************************************************
*
* @private
* CAN driver hardware wakeup callback notification
*
* This function is called by the hardware layer when a wakeup
* interrupt is generated due to wakeup of a sleeping CAN controller
* due to activity on the CAN bus. This function notifies the
* application of the wakeup event and also coordinates control of the
* CAN transceiver, putting it into the proper mode for normal
* operation.
*
*********************************************************************/
void
can_hook_wake
    (
    can_hw_inst_t   const hw_inst       //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
Notify the application layer
------------------------------------------------------*/
can_drv_hook_op_mode( hw_inst, CAN_OP_MODE_WAKEUP );
}

/*!*******************************************************************
*
* @private
* can_hook_sleep
*
* CAN driver hardware sleep callback
*
* This function is called by the hardware layer when a sleep interrupt
* is generated due to a successful transition of a CAN controller to
* the sleep state in response to a sleep request. This function
* notifies the application of the sleep transition event and also
* coordinates control of the CAN transceiver, putting it into the
* proper mode for sleep operation.
*
*********************************************************************/
void
can_hook_sleep
    (
    can_hw_inst_t   const hw_inst       //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
Notify the application layer
------------------------------------------------------*/
can_drv_hook_op_mode( hw_inst, CAN_OP_MODE_SLEEP );
}

/*!*******************************************************************
*
* @private
* CAN driver hardware exception callback
*
* This function is called by the hardware layer when a defined CAN
* hardware exception occurs. This function notifies the application of
* the exception event. This function also looks specifically for a
* BusOFF exception and notifies the application that the CAN
* controller has gone "offline" due to a bus fault.
*
*********************************************************************/
void
can_hook_exception
    (
    can_hw_inst_t   const hw_inst,  //!< [in] CAN hardware instance
    can_exception_t const exception //!< [in] CAN controller exception
    )
{
/*------------------------------------------------------
Check for BusOFF Condition
------------------------------------------------------*/
if( CAN_EX_BUSOFF == exception )
    {
    /*--------------------------------------------------
    Notify the application of change in operational mode
    --------------------------------------------------*/
    can_drv_hook_op_mode( hw_inst, CAN_OP_MODE_OFFLINE );
    }

/*------------------------------------------------------
Notify the application of the exception
------------------------------------------------------*/
can_drv_hook_exception( hw_inst, exception );
}

/*!*******************************************************************
*
* @private
* CAN driver initialization busoff recovery callback
*
* This function is called by the hardware layer when a the CAN
* controller is being intialized after a BusOFF event. The CAN
* controller requires 128 x 11 idle bit periods before it can recover
* from BusOFF. This callback is from the hardware driver periodic
* task that polls for when the BusOFF recovery has completed.
*
*********************************************************************/

void
can_hook_deferred_init_busoff_recovery_pndg
    (
    can_hw_inst_t           const hw_inst
    )
{
/*--------------------------------------------------
Notify the application of change in operational mode
--------------------------------------------------*/
can_drv_hook_op_mode( hw_inst, CAN_OP_MODE_DEFERRED_INIT_PNDG );
}

/*!*******************************************************************
*
* @private
* CAN driver initialization busoff recovery callback
*
* This function is called by the hardware layer when a the CAN
* controller is being intialized after a BusOFF event. The CAN
* controller requires 128 x 11 idle bit periods before it can recover
* from BusOFF. This callback is from the hardware driver periodic
* task that polls for when the BusOFF recovery has completed.
*
*********************************************************************/
void
can_hook_init_busoff_recovery
    (
    can_hw_inst_t           const hw_inst
    )
{
/*--------------------------------------------------
Notify the application of change in operational mode
--------------------------------------------------*/
can_drv_hook_op_mode( hw_inst, CAN_OP_MODE_ONLINE );
}

