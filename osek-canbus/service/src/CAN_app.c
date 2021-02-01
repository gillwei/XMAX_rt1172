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
#include "fsl_gpio.h"
#include "MIMXRT1176_cm7.h"

#include "FreeRTOS.h"
#include "task.h"

#include "VI_pub.h"
#include "CAN_pub.h"
#include "CAN_app.h"

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/
#define LC_NACK                         0xEE
#define LC_SID                          0x20
#define LC_RS_NE                        0x10
#define LC_RS_WR                        0x20
#define LC_FILL                         0x55

#define WAKEUP_GPIO                     GPIO13
#define WAKEUP_GPIO_PIN                 ( 0 )

#define PM_IGN_ON                       ( 0 )
#define PM_IGN_OFF                      ( 1 )

#if( (DEBUG_TX_CAN_SUPPORT)&&(DEBUG_RX_CAN_SUPPORT) )
    #define CAN_APP_SIG_DEBUG_TICK      200;//!< 200 * 5 = 1000ms
#endif

/*--------------------------------------------------------------------
                                TYPES
--------------------------------------------------------------------*/
/*------------------------------------------------------
CAN system status
------------------------------------------------------*/
typedef enum tagCAN_SYS_STAT_TYPE
    {
    CAN_SYS_STAT_INIT,
    CAN_SYS_STAT_NORMAL,
    CAN_SYS_STAT_COMM_ERR,
    CAN_SYS_STAT_PWR_OFF,

    CAN_SYS_STAT_INVALID
    } can_sys_stat_t;

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

/*------------------------------------------------------
CAN system status
------------------------------------------------------*/
static can_sys_stat_t
can_app_sys_stat[CAN_NUM_INSTANCES] = { CAN_SYS_STAT_INIT };

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
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
    //TBD
    }
}

/*!*******************************************************************
*
* @private
* receive timeout1 get
*
* This function is the Interaction Layer frame reception timeout error1
* status get
*
*********************************************************************/
void
il_app_frm_timeout1_get
    (
    il_rx_frm_index_t  msg_index,
    boolean           *p_timeout_err1
    )
{
il_rxfrm_info_t     const *l_p_rxfrm_info;
uint8                     *l_p_frm_status;

/*------------------------------------------------------
Get the receive frame information and service all of
the receive frames for this CAN hardware instance
------------------------------------------------------*/
l_p_rxfrm_info = il_get_rxfrm_info_ptr( CAN_CONTROLLER_2 );

/*------------------------------------------------------
Get the receive frame status
------------------------------------------------------*/
l_p_frm_status = &( l_p_rxfrm_info->p_status[msg_index] );

/*------------------------------------------------------
Get the receive frame timeout error1 status
------------------------------------------------------*/
( *p_timeout_err1 ) = ( ( *l_p_frm_status ) & IL_RX_STATUS_TIMEOUT1 );
}

/*!*******************************************************************
*
* @private
* receive timeout2 get
*
* This function is the Interaction Layer frame reception timeout error2
* status get
*
*********************************************************************/
void
il_app_frm_timeout2_get
    (
    boolean  *p_timeout_err2
    )
{
( *p_timeout_err2 ) = can_app_timeout_error2[CAN_CONTROLLER_2];
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
//TBD
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
* for IXWW22 the largest signal is 24 bit, so we use the 32bit signal
* value
*
*********************************************************************/
void
il_app_notify_sig_changed
    (
    il_sig_handle_t         const sig_handle,
    uint8_t                 const num_bytes,
    uint32_t                     *p_sig_val
    )
{
//TBD
}

/*!*******************************************************************
*
* @private
* signal putting
*
* This function is the network interface manager Layer frame transmit
* signal that is called from the App Layer.
* for IXWW22 the largest signal is 40 bit, so we use the 64bit signal
* value
*
*********************************************************************/
void
nim_app_sig_put
    (
    il_sig_handle_t         const sig_handle,
    uint8_t                 const num_bytes,
    uint64_t                      sig_val
    )
{
/*------------------------------------------------------
Put the signal value
------------------------------------------------------*/
uint8       l_bytes[sizeof( uint64 )];
uint64      l_temp64;
uint8       l_i_byte;

/*------------------------------------------------------
Input number bytes is over the reserved memory(uint64)
------------------------------------------------------*/
if( num_bytes > 8 )
    {
    return;
    }

/*------------------------------------------------------
Convert the UINT32 value to a byte array and transmit it
using the byte array function
------------------------------------------------------*/
l_temp64 = sig_val;

for( l_i_byte = num_bytes; l_i_byte > 0; l_i_byte-- )
    {
    l_bytes[l_i_byte - 1] = (uint8) l_temp64;
    l_temp64 = l_temp64 >> IL_NUM_BITS_IN_BYTE;
    }

il_tx_put_signal_bytes( sig_handle, &( l_bytes[0] ), num_bytes );
}

/*!*******************************************************************
*
* @private
* signal getting
*
* This function is the network interface manager Layer frame transmit
* signal that is called from the App Layer.
* for IXWW22 the largest signal is 24 bit, so we use the 32bit signal
* value
*
*********************************************************************/
void
nim_app_sig_get
    (
    il_sig_handle_t         const sig_handle,
    uint8_t                 const num_bytes,
    uint32_t                     *p_sig_val
    )
{
/*------------------------------------------------------
Put the signal value
------------------------------------------------------*/
uint8       l_bytes[sizeof( uint32 )];
uint8       l_i_byte = 0;
uint32      l_temp32 = 0;

/*------------------------------------------------------
Input number bytes is over the reserved memory(uint32)
------------------------------------------------------*/
if( num_bytes > 4 )
    {
    return;
    }

/*------------------------------------------------------
Get the signal value from memory in bytes
------------------------------------------------------*/
il_rx_get_signal_bytes( sig_handle, l_bytes, num_bytes );

/*------------------------------------------------------
Convert the a byte array to UINT32 value
------------------------------------------------------*/
for( l_i_byte = num_bytes; l_i_byte > 0; l_i_byte-- )
    {
    l_temp32 |= l_bytes[l_i_byte - 1] << ( ( num_bytes  - l_i_byte ) * IL_NUM_BITS_IN_BYTE );
    }

(*p_sig_val) = l_temp32;
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
il_app_hook_sig_changed_handle
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
nim_app_sig_get( sig_handle, num_bytes,&l_sig_val );

/*------------------------------------------------------
Handle the changed signal value
------------------------------------------------------*/
VI_notify_vehicle_data_changed( msg_index, sig_handle, l_sig_val );

switch( msg_index )
    {
    case IL_CAN0_RX_NM_AND_LP_BK_IDX:
        /*--------------------------------------------------
        Network managment frame handle
        --------------------------------------------------*/
        break;

    //TBD other frames handler

    default:
        break;

    }
}

/*!*******************************************************************
*
* @private
* Interaction Layer CAN signal reception handler
*
* This function is the Interaction Layer CAN signal reception handler
* that is called by the CAN Stack when an Interaction Layer CAN signal
* is received on the CAN bus. This callback is called regardless of
* whether the CAN signal value has changed from the previously
* received value. This handler must be enabled as part of
* configuration of the Garmin OSEK CAN Stack.
*
*********************************************************************/
void
il_app_hook_sig_received_handle
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
nim_app_sig_get( sig_handle, num_bytes,&l_sig_val );

switch( msg_index )
    {
    //TBD unchanged signals handler

    default:
        break;
    }

}

/*!*******************************************************************
*
* @public
* CAN application initialization
*
* This function is called to init CAN app
*
*********************************************************************/
void app_init
    (
    can_hw_inst_t   const hw_inst       //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
CAN application BusOFF Status.
------------------------------------------------------*/
can_app_bus_off[CAN_CONTROLLER_2] = FALSE;

/*------------------------------------------------------
CAN application Timeout error2 Status.
------------------------------------------------------*/
can_app_timeout_error2[CAN_CONTROLLER_2] = FALSE;

/*------------------------------------------------------
CAN application Other paras init
------------------------------------------------------*/
//TBD

}

/*!*******************************************************************
*
* @private
*
* CAN APP system status check
*
* This function is called by the CAN app layer to check if the system
* status enters IGN OFF.
*
*********************************************************************/
void
can_app_sys_stat_check
    (
    void
    )
{
volatile bool ign_status;

ign_status = GPIO_ReadPinInput( WAKEUP_GPIO, WAKEUP_GPIO_PIN );

/*------------------------------------------------------
Switch the CAN status according to thw IGN status
------------------------------------------------------*/
#if( (DEBUG_TX_CAN_SUPPORT)&&(DEBUG_RX_CAN_SUPPORT) )
    PRINTF( "sys status:%x IGN:%x\r\n", can_app_sys_stat[CAN_CONTROLLER_2], ign_status );
#endif

switch( can_app_sys_stat[CAN_CONTROLLER_2] )
    {
    case CAN_SYS_STAT_INIT:
        if( PM_IGN_ON == ign_status )
            {
            can_app_sys_stat[CAN_CONTROLLER_2] = CAN_SYS_STAT_NORMAL;
            il_resume( CAN_CONTROLLER_2 );
            }
        else
            {
            il_suspend( CAN_CONTROLLER_2 );
            }
        break;

    case CAN_SYS_STAT_NORMAL:
        if( PM_IGN_OFF == ign_status )
            {
            can_app_sys_stat[CAN_CONTROLLER_2] = CAN_SYS_STAT_PWR_OFF;
            }
        break;

    case CAN_SYS_STAT_COMM_ERR:

        break;

    case CAN_SYS_STAT_PWR_OFF:
        can_app_sys_stat[CAN_CONTROLLER_2] = CAN_SYS_STAT_INIT;
        break;

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
can_app_sys_stat_check();

#if( (DEBUG_TX_CAN_SUPPORT)&&(DEBUG_RX_CAN_SUPPORT) )
static uint8   app_tx_tick = CAN_APP_SIG_DEBUG_TICK;//!< 200 * 5 = 1000ms
static uint32  app_rx_data = 0;
static boolean timeout_err = FALSE;

if( app_tx_tick > 0 )
    {
    app_tx_tick--;
    if( app_tx_tick == 0 )
        {
        app_tx_tick = CAN_APP_SIG_DEBUG_TICK;
        nim_app_sig_put( IL_CAN0_HEATER_LVL_SLECT_TXSIG_HANDLE,
                         IL_CAN0_HEATER_LVL_SLECT_TXSIG_NBYTES,
                         IL_VT_HEATER_LVL_SLECT_PASSENGER_SEAT_HEATER );

        nim_app_sig_put( IL_CAN0_SYS_INFO_VH_SPEED_UNIT_TXSIG_HANDLE,
                         IL_CAN0_SYS_INFO_VH_SPEED_UNIT_TXSIG_NBYTES,
                         IL_VT_SYS_INFO_VH_SPEED_UNIT_MPH );

        nim_app_sig_put( IL_CAN0_CLK_DATE_RESP_DATA_TXSIG_HANDLE,
                         IL_CAN0_CLK_DATE_RESP_DATA_TXSIG_NBYTES,
                         app_tx_tick-1 );

        nim_app_sig_put( IL_CAN0_REQ_MT_FUNC_CNT_SVC_ID_TXSIG_HANDLE,
                         IL_CAN0_REQ_MT_FUNC_CNT_SVC_ID_TXSIG_NBYTES,
                         0x88 );

        nim_app_sig_get( IL_CAN0_FUNC_SW_6_RXSIG_HANDLE, sizeof(uint8), &app_rx_data );
        PRINTF( "Hardkey value:%x\r\n\r\n",app_rx_data );

        il_app_frm_timeout1_get( IL_CAN0_RX3_BRGTHNSS_CTRL_IDX, &timeout_err );
        PRINTF( "BRGTHNSS_CTRL  timeout_err1:%x\r\n", timeout_err );

        il_app_frm_timeout1_get( IL_CAN0_RX5_VEHICLE_INFO_IDX, &timeout_err );
        PRINTF( "VEHICLE_INFO   timeout_err1:%x\r\n", timeout_err );

        il_app_frm_timeout1_get( IL_CAN0_RXA_VEHICLE_INFO_2_IDX, &timeout_err );
        PRINTF( "VEHICLE_INFO_2 timeout_err1:%x\r\n", timeout_err );

        il_app_frm_timeout1_get( IL_CAN0_RXD_MAINT_TRIP_IDX, &timeout_err );
        PRINTF( "MAINT_TRIP     timeout_err1:%x\r\n", timeout_err );

        il_app_frm_timeout1_get( IL_CAN0_RX8_ODO_TRIP_IDX, &timeout_err );
        PRINTF( "ODO_TRIP       timeout_err1:%x\r\n", timeout_err );

        il_app_frm_timeout1_get( IL_CAN0_RX7_FUEL_RATE_IDX, &timeout_err );
        PRINTF( "FUEL_RATE      timeout_err1:%x\r\n", timeout_err );

        il_app_frm_timeout1_get( IL_CAN0_RX6_FUNCSW_STAT_IDX, &timeout_err );
        PRINTF( "FUNCSW_STAT    timeout_err1:%x\r\n", timeout_err );

        il_app_frm_timeout2_get( &timeout_err );
        PRINTF( "FUNCSW_STAT    timeout_err2:%x\r\n", timeout_err );
        }
    }
else
    {
    app_tx_tick = CAN_APP_SIG_DEBUG_TICK;
    }

#endif
}

