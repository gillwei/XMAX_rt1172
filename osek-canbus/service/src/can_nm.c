/*!*******************************************************************
* @file can_nm.c
* @brief Garmin OSEK CAN Stack Network Management Layer
*
* This file implements the Garmin OSEK CAN Stack Network Management
* Layer. The Network Management Layer is required to coordinate
* wakeup and sleep transitions with other ECU's on a shared CAN bus
* that supports IXWW22 CAN Network Management.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @defgroup can_nm IXWW22 Network Management Layer
* @ingroup can_stack
* @{
*
*********************************************************************/

/*----------------------------------------------------------------
                            GENERAL INCLUDES
----------------------------------------------------------------*/
#include "can_defs.h"
#include "can_cfg.h"
#include "can_util.h"
#include "can_drv.h"
#include "can_dll.h"
#include "can_dll_prv_par.h"
//#include "can_il.h"
//#include "can_tp.h"
#include "can_nm.h"
#include "can_nim_cfg.h"

#include "fsl_debug_console.h"
#include "FreeRTOS.h"
#include "task.h"

/*--------------------------------------------------------------------
                            MACROS
--------------------------------------------------------------------*/
/*------------------------------------------------------
STATUS Bit Flag Definitions
------------------------------------------------------*/
#define NM_STATUS_CONTROLLER_BUSOFF         (0x1u << 0)
#define NM_STATUS_NETWORK_BUSOFF            (0x1u << 1)
#define NM_STATUS_BUSOFF_REINIT_PNDG        (0x1u << 2)
#define NM_STATUS_ONLINE                    (0x1u << 3)

/*------------------------------------------------------
Network Management Frame Definitions
------------------------------------------------------*/
#define NM_LOOP_BACK_FRM_LMIN                   (1)

/*------------------------------------------------------
Fast BusOFF Recovery Retry Limit
------------------------------------------------------*/
#define NM_FAST_BUSOFF_RECOVERY_LIMIT           (0)

/*------------------------------------------------------
Time defined in terms of the periodic NM task call
------------------------------------------------------*/
#define NM_TIME_IN_TASK_TICS( _t_ms )        ( (uint16) ( ( ( _t_ms ) / NM_TASK_PERIOD_MS ) + 0.5 ) )

/*------------------------------------------------------
Network Management Time Intervals in Milliseconds
------------------------------------------------------*/
#define NM_BUSOFF_RECOVERY_INTERVAL_MS          (250)
#define NM_BUSOFF_RECOVERY_INTERVAL_CNT         NM_TIME_IN_TASK_TICS( NM_BUSOFF_RECOVERY_INTERVAL_MS )

/*--------------------------------------------------------------------
                            TYPES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                            VARIABLES
--------------------------------------------------------------------*/

/*------------------------------------------------------
Network Management State and Status
------------------------------------------------------*/
static nm_state_t
nm_state[CAN_NUM_INSTANCES];

static uint8
nm_status[CAN_NUM_INSTANCES];

/*------------------------------------------------------
BusOFF Management
------------------------------------------------------*/
static uint16
nm_busoff_retry_timer[CAN_NUM_INSTANCES];

static uint8
nm_busoff_retry_count[CAN_NUM_INSTANCES];

/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/
/*!*******************************************************************
*
* update timers
*
* This function updates all of the timeout timers associated with the
* Network Management implementation. It is assumed this function is
* called from the periodic Network Management task and the call of
* this task function represents one period of the NM period has
* elapsed.
*
*********************************************************************/
static void
update_timers
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
Update the BusOFF retry timer if the fast recovery
retry limit has been reached.
------------------------------------------------------*/
if( nm_busoff_retry_count[hw_inst] >= NM_FAST_BUSOFF_RECOVERY_LIMIT )
    {
    if( nm_busoff_retry_timer[hw_inst] > 0 )
        {
        ( nm_busoff_retry_timer[hw_inst] )--;
        }
    }
}

/*!*******************************************************************
*
* set the Network Management state
*
* This function is called to set the current Network Management state
* to the specified value. If the new state is different from the
* current state, a callback function to the application is called to
* notify the application of the state change. The assumption is this
* state change is thread safe as guaranteed by the calling function.
*
*********************************************************************/
static void
set_nm_state
    (
    can_hw_inst_t       const hw_inst,
    nm_state_t          const state
    )
{
nm_state_t  l_current_nm_state;

l_current_nm_state = nm_state[hw_inst];

/*------------------------------------------------------
Check if new state is different from current state.
------------------------------------------------------*/
if( state != l_current_nm_state )
    {
    nm_state[hw_inst] = state;

    /*------------------------------------------------------
    notify the application.
    ------------------------------------------------------*/
    //TBD nm_app_notify_state_change( hw_inst, state );
    }
}

/*!*******************************************************************
*
* Check for recovery from BusOFF condition
*
* This function checks for recovery from a BusOFF condition. This
* function is called if the CAN controller went BusOFF, was
* re-initialized, and then was able to successfully transmit or
* receive a CAN frame. It is assumed this function is called with
* global interrupts disabled.
*
*********************************************************************/
static void
check_busoff_recovery
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
Check for Network BusOFF status set and CAN controller
currently online.
------------------------------------------------------*/
if( ( ( nm_status[hw_inst] & NM_STATUS_NETWORK_BUSOFF ) != 0 ) &&
    ( ( nm_status[hw_inst] & NM_STATUS_ONLINE ) != 0 ) )
    {
    /*------------------------------------------------------
    Clear the Network BusOFF flag, notify the application
    of recovery from the BusOFF condition, and enable CAN
    driver transmit timeout.
    ------------------------------------------------------*/
    nm_status[hw_inst] &= SYS_MASK8_COMPLEMENT( NM_STATUS_NETWORK_BUSOFF );
    //TBD nm_app_notify_busoff_recovery( hw_inst );
    can_service( hw_inst, 0, CAN_SVC_ENABLE_TX_TIMEOUT );

    /*------------------------------------------------------
    Start the BusOFF recovery timer and set the pending
    status flag for reinitializaton of the BusOFF recovery
    retry strategy.
    ------------------------------------------------------*/
    nm_busoff_retry_timer[hw_inst] = NM_BUSOFF_RECOVERY_INTERVAL_CNT;
    nm_status[hw_inst] |= NM_STATUS_BUSOFF_REINIT_PNDG;
    }
}

/*!*******************************************************************
*
* initialize CAN driver
*
* This function is called to submit a request to the low level BSP
* CAN driver to initialize the CAN controller. This function may be
* called as part of start up initialization or as part of the BusOFF
* fault recovery process wherein the Network Management component
* attempts periodically to reconnect with the CAN bus.
*
* @return boolean
* success flag (TRUE or FALSE)
*
*********************************************************************/
static boolean
init_can
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
can_ret_code_t  l_ret_code;
boolean         l_success;

/*------------------------------------------------------
Initialize the return value then initialize the CAN
controller
------------------------------------------------------*/
l_success = TRUE;

l_ret_code = can_init( hw_inst, CAN_INIT_MODE_COLD, NULL );

if( ( l_ret_code != CAN_RC_OK ) && ( l_ret_code != CAN_RC_BUSOFF_INIT_PNDG ) )
    {
    //TBD nm_app_notify_init_failed( hw_inst );
    l_success = FALSE;
    }

return l_success;
}

/*!*******************************************************************
*
* @private
* initialization
*
* This function initializes the OSEK CAN Network Management Layer.
*
*********************************************************************/
void
nm_init
    (
    can_hw_inst_t   const hw_inst,  //!< [in] CAN hardware instance
    nm_init_mode_t  const init_mode //!< [in] initialization mode
    )
{
boolean l_init_default_signals;

/*------------------------------------------------------
Initialize the NM state, status,
------------------------------------------------------*/
set_nm_state( hw_inst, NM_STATE_WAKEUP );
nm_status[hw_inst] = 0;

/*------------------------------------------------------
Check the Initialization Mode to determine if the
transmitted and received signal values need to be
initialized to their default values. Power ON
initializations require initialization of default
signal values whereas wakeups (Local or via the CAN bus)
do not.
------------------------------------------------------*/
if( ( NM_INIT_MODE_POWER_ON       == init_mode )     ||
    ( NM_INIT_MODE_POWER_ON_SLEEP == init_mode )     ||
    ( NM_INIT_MODE_LOCAL_WAKEUP   == init_mode )     ||
    ( NM_INIT_MODE_BUS_WAKEUP     == init_mode ) )
    {
    if( ( NM_INIT_MODE_POWER_ON       == init_mode )   ||
    ( NM_INIT_MODE_POWER_ON_SLEEP == init_mode ) )
        {
        l_init_default_signals = TRUE;
        }
    else
        {
        l_init_default_signals = FALSE;
        }

    /*------------------------------------------------------
    Initialize the CAN Stack Layers
    ------------------------------------------------------*/
    dll_init( hw_inst );
    //TBD il_init( hw_inst, l_init_default_signals );
    //TBD tp_init( hw_inst );
    }

/*------------------------------------------------------
Check if this initialization is due to a first power ON
or due to a wakeup. If it is due to a first power ON
then the CAN controller needs to be initialized.
------------------------------------------------------*/
if( ( NM_INIT_MODE_POWER_ON       == init_mode )    ||
    ( NM_INIT_MODE_POWER_ON_SLEEP == init_mode ) )
    {
    (void) init_can( hw_inst );
    }
}

/*!*******************************************************************
*
* @private
* periodic task
*
* This function represents the OSEK CAN Stack Network Management Layer
* periodic task. This task primarily handles the various timeout
* events associated with the different Network Management states. The
* events are processed according to the current NM state.
*
*********************************************************************/
void nm_task
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
uint16  l_status;

/*------------------------------------------------------
Check that the CAN node is not in the sleep state.
------------------------------------------------------*/
if( nm_state[hw_inst] != NM_STATE_SLEEP )
    {
    /*------------------------------------------------------
    Update the BusOFF Retry Timers.
    ------------------------------------------------------*/
    update_timers( hw_inst );

    /*------------------------------------------------------
    Get the current NM status.
    ------------------------------------------------------*/
    l_status = nm_status[hw_inst];

    /*------------------------------------------------------
    Check for need to reinitialize CAN for BusOFF recovery.
    ------------------------------------------------------*/
    if( ( ( l_status & NM_STATUS_CONTROLLER_BUSOFF ) != 0 )                 &&
        ( nm_busoff_retry_count[hw_inst] >= NM_FAST_BUSOFF_RECOVERY_LIMIT ) &&
        ( 0 == nm_busoff_retry_timer[hw_inst] ) )
        {
        /*------------------------------------------------------
        Reset the timer for the recovery interval and initialize
        the CAN controller.
        ------------------------------------------------------*/
        nm_busoff_retry_timer[hw_inst] = NM_BUSOFF_RECOVERY_INTERVAL_CNT;
        (void) init_can( hw_inst );
        }

    /*------------------------------------------------------
    Check for reinitialization of the BusOFF recovery retry
    strategy. The timeout after successful recovery needs
    to have elapsed before reset of the retry strategy can
    be performed.
    ------------------------------------------------------*/
    if( ( NM_STATE_NORMAL == nm_state[hw_inst] )                &&
        ( ( l_status & NM_STATUS_BUSOFF_REINIT_PNDG ) != 0 )    &&
        ( 0 == nm_busoff_retry_timer[hw_inst] ) )
        {
        nm_busoff_retry_count[hw_inst] = 0;
        can_util_clear_status_bits( &( nm_status[hw_inst] ),
                                    NM_STATUS_BUSOFF_REINIT_PNDG );
        }

    l_status = nm_status[hw_inst];
    }
}

/*!*******************************************************************
*
* @private
* get the current Network Management state
*
*********************************************************************/
nm_state_t
nm_get_current_state
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
return nm_state[hw_inst];
}

/*!*******************************************************************
*
* @private
* operational mode callback notification
*
* This function represents the callback notification from the Dispatch
* Layer regarding CAN bus operational mode changes. The primary events
* of interest include BusOFF recovery events.
*
*********************************************************************/
void
nm_hook_op_mode
    (
    can_hw_inst_t   const hw_inst, //!< [in] CAN hardware instance
    can_op_mode_t   const op_mode  //!< [in] current operational mode
    )
{
/*------------------------------------------------------
Check for ONLINE notification.
------------------------------------------------------*/
if( CAN_OP_MODE_ONLINE == op_mode )
    {
    /*------------------------------------------------------
    CAN controller no longer BusOFF and back ONLINE.
    ------------------------------------------------------*/
    can_util_clear_status_bits( &( nm_status[hw_inst] ), NM_STATUS_CONTROLLER_BUSOFF );
    can_util_set_status_bits( &( nm_status[hw_inst] ), NM_STATUS_ONLINE );

    /*------------------------------------------------------
    Set the nm state and enable IL transmission.
    ------------------------------------------------------*/
    set_nm_state( hw_inst, NM_STATE_NORMAL );
    //TBD il_enable( hw_inst );
    //TBD il_resume( hw_inst );
    }
}

/*!*******************************************************************
*
* @private
* CAN BusOFF event callback notification
*
* This function represents the callback notification from the
* Dispatch Layer that the CAN bus has gone BusOFF (taken itself
* offline) due to faults on the CAN bus or synchronization problems
* related to an incorrect bit rate setting, clock source faults, etc.
* BusOFF causes the CAN controller to take itself offline and can
* only be recovered with a complete reinitialization of the FCAN
* controller hardware.
*
*********************************************************************/
void
nm_hook_bus_off
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
boolean l_success;

/*------------------------------------------------------
Set the BusOFF status bits, clear the ONLINE bit, and
notify the application of the BusOFF condition.
------------------------------------------------------*/
can_util_set_status_bits( &( nm_status[hw_inst] ),
                           ( NM_STATUS_CONTROLLER_BUSOFF |
                             NM_STATUS_NETWORK_BUSOFF ) );
can_util_clear_status_bits( &( nm_status[hw_inst] ), NM_STATUS_ONLINE );
//TBD nm_app_notify_busoff( hw_inst );

/*------------------------------------------------------
Disable the Interaction Layer and transmission of
application messages due to the BusOFF condition.
Disable the transmit timeout feature in the low level
CAN driver.
------------------------------------------------------*/
//TBD il_disable( hw_inst );
//can_service( hw_inst, 0, CAN_SVC_DISABLE_TX_TIMEOUT );

/*------------------------------------------------------
Check the BusOFF retry counter to determine if immediate
recovery should be attempted.
------------------------------------------------------*/
if( nm_busoff_retry_count[hw_inst] < NM_FAST_BUSOFF_RECOVERY_LIMIT )
    {
    l_success = init_can( hw_inst );

    if( l_success != FALSE )
        {
        nm_busoff_retry_count[hw_inst] += 1;
        }
    }
}

/*!*******************************************************************
*
* @private
* transmit NM message complete notification
*
* This function represents the callback notification from the
* Dispatch Layer with notification of successful completion of
* transmission of a Network Management frame.
*
*********************************************************************/
void
nm_hook_transmit
    (
    can_hw_inst_t       const hw_inst, //!< [in] CAN hardware instance
    can_tmh_t           const tmh      //!< [in] transmit message handle
    )
{
//TDB
}

/*!*******************************************************************
*
* @private
* transmit timeout notification
*
* This function represents the callback notification from the
* Dispatch Layer with notification of detection of a transmit timeout.
* This can be for any CAN frame transmission attempt, not just Network
* Management frames.
*
*********************************************************************/
void
nm_hook_transmit_timeout
    (
    can_hw_inst_t       const hw_inst, //!< [in] CAN hardware instance
    can_tmh_t           const tmh      //!< [in] transmit message handle
    )
{
/*------------------------------------------------------
Tell upper layer the NM CAN has not been transmitted
------------------------------------------------------*/
//TBD nm_app_notify_tx_hw_timeout( hw_inst, tmh );
}

/*!*******************************************************************
*
* @private
* receive NM Loopback message notification
*
* This function represents the callback notification from the
* Dispatch Layer with a valid received Network Management Loopback
* message.
*
*********************************************************************/
void
nm_hook_receive
    (
    can_hw_inst_t       const hw_inst, //!< [in] CAN hardware instance
    can_rmd_t   const * const p_rmd    //!< [in] pointer to received message
    )
{
/*------------------------------------------------------
Check that the Loopback frame has the correct frame
length.
------------------------------------------------------*/
if( p_rmd->dlc >= IL_CAN0_RX_NM_AND_LP_BK_RXFRM_MIN_LEN )
    {
    /*------------------------------------------------------
    Process the received Loopback frame
    ------------------------------------------------------*/
    //TBD nm_app_hook_process_receive( hw_inst, p_rmd );
    }
}

/*!*******************************************************************
*
* @private
* Callback notification of any CAN frame reception
*
* This function represents the callback notification from the
* Dispatch Layer that any CAN frame has been successfully received.
* This is needed to detect and issue notification of BusOFF recovery.
* This callback is called in interrupt context (with global interrupts
* disabled).
*
*********************************************************************/
void
nm_hook_notify_any_can_frame_reception
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
Check for recovery from the BusOFF condition.
------------------------------------------------------*/
check_busoff_recovery( hw_inst );
}

/*!*******************************************************************
*
* @private
* Callback notification of any successful CAN frame transmission
*
* This function represents the callback notification from the
* Dispatch Layer that any CAN frame has been successfully transmitted.
* This is needed to detect and issue notification of BusOFF recovery.
* This callback is called in interrupt context (with global interrupts
* disabled).
*
*********************************************************************/
void
nm_hook_notify_any_can_frame_transmission
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
Check for recovery from the BusOFF condition.
------------------------------------------------------*/
check_busoff_recovery( hw_inst );
}

