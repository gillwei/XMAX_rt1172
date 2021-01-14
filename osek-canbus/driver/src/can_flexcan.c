/*!*******************************************************************
* @file can_flexcan.c
* @brief RT1170 FlexCAN Controller Hardware Driver
*
* This file includes all of the functions necessary to support CAN
* communication using multiple instances of the RT1170 FlexCAN
* controller. These functions initialize the CAN controller including
* its configuration and filter/mask registers. These functions
* include those needed to transmit and receive messages on a CAN
* network, process interrupts, control interrupts, maintain and query
* the status of the CAN connection, allow sleep and wakeup, etc by
* means of direct management of the FlexCAN controller hardware
* registers. The functions in this file are private to the Garmin
* IXWW22 CAN Stack implementation.
*
*  Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @defgroup can_hw_drv RT1170 FlexCAN Controller Hardware Driver
* @ingroup can_drv
* @{
*
*********************************************************************/
/*----------------------------------------------------------------
                            GENERAL INCLUDES
----------------------------------------------------------------*/
#include <string.h>

#include "can_defs.h"
#include "can_cfg.h"
#include "can_bcfg.h"
#include "can_hw.h"
#include "can_flexcan.h"
#include "can_flexcan_fcfg.h"

#include "fsl_debug_console.h"
#include "FreeRTOS.h"
#include "task.h"

/*--------------------------------------------------------------------
                            MACROS
--------------------------------------------------------------------*/
#define IDEAL_SP_LOW            (750U)
#define IDEAL_SP_MID            (800U)
#define IDEAL_SP_HIGH           (875U)
#define IDEAL_SP_FACTOR         (1000U)

#define MAX_PROPSEG             (CAN_CTRL1_PROPSEG_MASK >> CAN_CTRL1_PROPSEG_SHIFT)
#define MAX_PSEG1               (CAN_CTRL1_PSEG1_MASK >> CAN_CTRL1_PSEG1_SHIFT)
#define MAX_PSEG2               (CAN_CTRL1_PSEG2_MASK >> CAN_CTRL1_PSEG2_SHIFT)
#define MAX_RJW                 (CAN_CTRL1_RJW_MASK >> CAN_CTRL1_RJW_SHIFT)
#define MAX_PRESDIV             (CAN_CTRL1_PRESDIV_MASK >> CAN_CTRL1_PRESDIV_SHIFT)
#define CTRL1_MAX_TIME_QUANTA   (1U + MAX_PROPSEG + 1U + MAX_PSEG1 + 1U + MAX_PSEG2 + 1U)
#define CTRL1_MIN_TIME_QUANTA   (8U)

#define FLEXCAN_CLOCK_SOURCE_SELECT       (1U)
#define FLEXCAN_CLOCK_SOURCE_DIVIDER      (1U)
#define FLEX_CAN_CLK_FREQ                 ( ( CLOCK_GetRootClockFreq( kCLOCK_Root_Can2 ) / 100000U ) * 100000U )

#define MAX_CAN_BAUDRATE (1000000U)

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
#ifndef CAN_CLOCK_CHECK_NO_AFFECTS
//!<If no define such MACRO, it mean that the CAN in current device have no clock affect issue.
#define CAN_CLOCK_CHECK_NO_AFFECTS (true)
#endif //!<CAN_CLOCK_CHECK_NO_AFFECTS
#endif //!<FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL

#define FLT_CONF_ERR_ACTIVE             0
#define FLT_CONF_ERR_PASSIVE            1
#define FLT_CONF_ERR_BUSOFF_MIN         2

/*------------------------------------------------------
Array of FlexCAN IRQ number.
------------------------------------------------------*/
#define CAN2_INSTANCE                   2
static const IRQn_Type s_flexcanRxWarningIRQ[] = CAN_Rx_Warning_IRQS;
static const IRQn_Type s_flexcanTxWarningIRQ[] = CAN_Tx_Warning_IRQS;
static const IRQn_Type s_flexcanWakeUpIRQ[]    = CAN_Wake_Up_IRQS;
static const IRQn_Type s_flexcanErrorIRQ[]     = CAN_Error_IRQS;
static const IRQn_Type s_flexcanBusOffIRQ[]    = CAN_Bus_Off_IRQS;
static const IRQn_Type s_flexcanMbIRQ[]        = CAN_ORed_Message_buffer_IRQS;

/*------------------------------------------------------
Array of FlexCAN clock name.
------------------------------------------------------*/
static const clock_ip_name_t s_flexcanClock[] = FLEXCAN_CLOCKS;

/*--------------------------------------------------------------------
                            TYPES
--------------------------------------------------------------------*/
/*------------------------------------------------------
FlexCAN Internal State.
------------------------------------------------------*/
typedef enum tagFLEXCAN_STATE_TYPE
    {
    FLEXCAN_STATE_IDLE     = 0x0, //!<MB/RxFIFO idle.
    FLEXCAN_STATE_RXDATA   = 0x1, //!<MB receiving.
    FLEXCAN_STATE_RXTEMOTE = 0x2, //!<MB receiving remote reply.
    FLEXCAN_STATE_TXDATA   = 0x3, //!<MB transmitting.
    FLEXCAN_STATE_TXREMOTE = 0x4, //!<MB transmitting remote request.
    FLEXCAN_STATE_RXFIFO   = 0x5, //!<RxFIFO receiving.

    } flexcan_state_t;

/*------------------------------------------------------
FlexCAN message buffer CODE FOR Rx buffers.
------------------------------------------------------*/
typedef enum tagFLEXCAN_MB_CODE_RX_TYPE
    {
    FLEXCAN_RXMB_INACTIVE = 0x0, //!<MB is not active.
    FLEXCAN_RXMB_FULL     = 0x2, //!<MB is full.
    FLEXCAN_RXMB_EMPTY    = 0x4, //!<MB is active and empty.
    FLEXCAN_RXMB_OVERRUN  = 0x6, //!<MB is overwritten into a full buffer.
    FLEXCAN_RXMB_BUSY     = 0x8, //!<FlexCAN is updating the contents of the MB.The CPU must not access the MB.
    FLEXCAN_RXMB_RANSWER  = 0xA, //!<A frame was configured to recognize a Remote Request Frame and transmit a Response Frame in return.
    FLEXCAN_RXMB_NOTUSED  = 0xF, //!<Not used.

    } flexcan_mb_code_rx_t;

/*------------------------------------------------------
FlexCAN message buffer CODE FOR Tx buffers.
------------------------------------------------------*/
typedef enum tagFLEXCAN_MB_CODE_TX_TYPE
    {
    FLEXCAN_TXMB_INACTIVE     = 0x8, //!<MB is not active.
    FLEXCAN_TXMB_ABORT        = 0x9, //!<MB is aborted.
    FLEXCAN_TXMB_DATAORREMOTE = 0xC, //!<MB is a TX Data Frame(when MB RTR = 0) or MB is a TX Remote Request Frame (when MB RTR = 1).
    FLEXCAN_TXMB_TANSWER      = 0xE, //!<MB is a TX Response Request Frame from an incoming Remote Request Frame.
    FLEXCAN_TXMB_NOTUSED      = 0xF, //!<Not used.

    } flexcan_mb_code_tx_t;

/*------------------------------------------------------
Transmit Timeout Type Definition
------------------------------------------------------*/
typedef struct tagCAN_HW_TX_TIMEOUT_TYPE        //!< tx timeout type definition
    {
    boolean     enable;                         //!< enable timeout function
    boolean     active[MAX_TX_OBJECTS];         //!< transmission is active (one per Message Buffer)
    uint16      timer[MAX_TX_OBJECTS];          //!< timeout timer value (one per Message Buffer)

    } can_hw_tx_timeout_t;

/*--------------------------------------------------------------------
                            VARIABLES
--------------------------------------------------------------------*/
/*------------------------------------------------------
Initial FlexCAN config
------------------------------------------------------*/
flexcan_hw_init_t const can2_hw_init_data =
{
    /*------------------------------------------------------
    FlexCAN TransmitMessage Buffer Initial config
    ------------------------------------------------------*/
    { CAN_HMB_TX_START, CAN_HMB_TX_ALL },
    /*------------------------------------------------------
    FlexCAN Receive Message Buffer Initial config
    ------------------------------------------------------*/
    {
        { CAN0_RX_DAIG_SEG1_STD,        RX_DAIG_SEG1_MSK, CAN_STANDARD_MSG_TYPE, CAN_DATA_MSG_TYPE },
        { CAN0_RX_DAIG_SEG2_STD,        RX_DAIG_SEG2_MSK, CAN_STANDARD_MSG_TYPE, CAN_DATA_MSG_TYPE },
        { CAN0_RX_DAIG_SEG3_STD,        RX_DAIG_SEG3_MSK, CAN_STANDARD_MSG_TYPE, CAN_DATA_MSG_TYPE },
        { CAN0_RX_DAIG_SEG4_STD,        RX_DAIG_SEG4_MSK, CAN_STANDARD_MSG_TYPE, CAN_DATA_MSG_TYPE },
        { CAN0_RX_DAIG_SEG5_YDT_STD,    RX_DAIG_SEG5_MSK, CAN_STANDARD_MSG_TYPE, CAN_DATA_MSG_TYPE },
        { CAN0_RX_DAIG_SEG6_YDT_STD,    RX_DAIG_SEG6_MSK, CAN_STANDARD_MSG_TYPE, CAN_DATA_MSG_TYPE },
        { CAN0_RX_DAIG_SEG7_YDT_STD,    RX_DAIG_SEG7_MSK, CAN_STANDARD_MSG_TYPE, CAN_DATA_MSG_TYPE },
        { CAN0_RX_NM_AND_LP_BK_STD,     RX_MB_DEF_MSK,    CAN_STANDARD_MSG_TYPE, CAN_DATA_MSG_TYPE },
        { CAN0_RX0_ECU_INDCT_STAT_STD,  RX_MB_DEF_MSK,    CAN_STANDARD_MSG_TYPE, CAN_DATA_MSG_TYPE },
        { CAN0_RX1_ECU_COM_DATA_STD,    RX_MB_DEF_MSK,    CAN_STANDARD_MSG_TYPE, CAN_DATA_MSG_TYPE },
        { CAN0_RX2_RES_SUPPORT_STD,     RX_MB_DEF_MSK,    CAN_STANDARD_MSG_TYPE, CAN_DATA_MSG_TYPE },
        { CAN0_RX3_BRGTHNSS_CTRL_STD,   RX_MB_DEF_MSK,    CAN_STANDARD_MSG_TYPE, CAN_DATA_MSG_TYPE },
        { CAN0_RX4_RES_MT_FUNC_CNT_STD, RX_MB_DEF_MSK,    CAN_STANDARD_MSG_TYPE, CAN_DATA_MSG_TYPE },
        { CAN0_RX5_VEHICLE_INFO_STD,    RX_MB_DEF_MSK,    CAN_STANDARD_MSG_TYPE, CAN_DATA_MSG_TYPE },
        { CAN0_RX6_FUNCSW_STAT_STD,     RX_MB_DEF_MSK,    CAN_STANDARD_MSG_TYPE, CAN_DATA_MSG_TYPE },
        { CAN0_RX7_FUEL_RATE_STD,       RX_MB_DEF_MSK,    CAN_STANDARD_MSG_TYPE, CAN_DATA_MSG_TYPE },
        { CAN0_RX8_ODO_TRIP_STD,        RX_MB_DEF_MSK,    CAN_STANDARD_MSG_TYPE, CAN_DATA_MSG_TYPE },
        { CAN0_RX9_RES_RPRGRM_INFO_STD, RX_MB_DEF_MSK,    CAN_STANDARD_MSG_TYPE, CAN_DATA_MSG_TYPE },
        { CAN0_RXA_VEHICLE_INFO_2_STD,  RX_MB_DEF_MSK,    CAN_STANDARD_MSG_TYPE, CAN_DATA_MSG_TYPE },
        { CAN0_RXB_VEHICLE_INFO_3_STD,  RX_MB_DEF_MSK,    CAN_STANDARD_MSG_TYPE, CAN_DATA_MSG_TYPE },
        { CAN0_RXC_VEHICLE_INFO_4_STD,  RX_MB_DEF_MSK,    CAN_STANDARD_MSG_TYPE, CAN_DATA_MSG_TYPE },
        { CAN0_RXD_MAINT_TRIP_STD,      RX_MB_DEF_MSK,    CAN_STANDARD_MSG_TYPE, CAN_DATA_MSG_TYPE },
        { CAN0_RXE_HEATER_STAT_STD,     RX_MB_DEF_MSK,    CAN_STANDARD_MSG_TYPE, CAN_DATA_MSG_TYPE },
        { CAN0_RXF_FACT_INSP_NS_STD,    RX_MB_DEF_MSK,    CAN_STANDARD_MSG_TYPE, CAN_DATA_MSG_TYPE },
        { CAN0_RXF_FACT_INSP2_GA_STD,   RX_MB_DEF_MSK,    CAN_STANDARD_MSG_TYPE, CAN_DATA_MSG_TYPE },
        { CAN0_RXG_ECU_INDCT_STAT1_STD, RX_MB_DEF_MSK,    CAN_STANDARD_MSG_TYPE, CAN_DATA_MSG_TYPE },
    },
};

/*------------------------------------------------------
Pointers to CAN Hardware Initialization Data Structures
------------------------------------------------------*/
static flexcan_hw_init_t  const * const
p_can_hw_init_data[CAN_NUM_INSTANCES] =
{
    &can2_hw_init_data
};

/*------------------------------------------------------
Pointers to CAN Hardware Registers
------------------------------------------------------*/
static flexcan_regs_t * const
p_flexcan_hw_regs[CAN_NUM_INSTANCES] =
{
    (flexcan_regs_t *) (CAN2_BASE)
};

/*------------------------------------------------------
Hardware Status
------------------------------------------------------*/
static volatile can_status_t
can_hw_status[CAN_NUM_INSTANCES];

/*------------------------------------------------------
Hardware Error Status
------------------------------------------------------*/
static volatile can_status_t
can_hw_error_status[CAN_NUM_INSTANCES];

/*------------------------------------------------------
BusOFF Init Pending
------------------------------------------------------*/
static boolean
can_hw_busoff_recovery_pndg[CAN_NUM_INSTANCES];

flexcan_hw_init_t  const *
p_can_hw_busoff_recovery_init_vector[CAN_NUM_INSTANCES];

/*------------------------------------------------------
Transmit Message Handles
------------------------------------------------------*/
static can_tmh_t
can_hw_tx_msg_handle[CAN_NUM_INSTANCES][MAX_TX_OBJECTS];

/*------------------------------------------------------
Transmit Timeout Data Structures
------------------------------------------------------*/
static can_hw_tx_timeout_t
can_hw_tx_timeout[CAN_NUM_INSTANCES];

/*------------------------------------------------------
Hardware Interrupt Configuration

This separate configuration variable is needed to be able to
support configuration of the CAN controller using initialization
data structures passed by the application to the CAN driver as
opposed to using the static default configurations.
------------------------------------------------------*/
static volatile can_status_t
can_hw_cfg_int_status[CAN_NUM_INSTANCES];

/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/
/*!*******************************************************************
*
* get pointer to FlexCAN controller registers
*
* This function gets a pointer to the register space for the indicated
* CAN Controller hardware instance.
*
* return pointer to FlexCAN controller registers
*
*********************************************************************/
static flexcan_regs_t *
can_hw_get_regs
    (
    can_hw_inst_t           const hw_inst   //!< [in] CAN hardware instance
    )
{
flexcan_regs_t        *l_p_flexcan_regs = NULL;

/*------------------------------------------------------
Check that a valid hardware instance is specified
------------------------------------------------------*/
if( hw_inst < CAN_NUM_INSTANCES )
    {
    /*------------------------------------------------------
    Get the registers pointer
    ------------------------------------------------------*/
    l_p_flexcan_regs = p_flexcan_hw_regs[hw_inst];
    }

return l_p_flexcan_regs;
}

/*!*******************************************************************
*
* atomically set can_hw_status bit(s)
*
* This function atomically sets the CAN hardware status bits
* specified by the bit mask in a critical section.
*
*********************************************************************/
static void
can_hw_set_status_bit
    (
    can_hw_inst_t   const hw_inst,       //!< [in] CAN hardware instance
    can_status_t    const bit_mask       //!< [in] bit mask for set bit
    )
{
can_hw_status[hw_inst] |= bit_mask;
}

/*!*******************************************************************
*
* atomically clear can_hw_status bit(s)
*
* This function atomically clears the CAN hardware status bits
* specified by the bit mask in a critical section.
*
*********************************************************************/
static void
can_hw_clear_status_bit
    (
    can_hw_inst_t   const hw_inst,       //!< [in] CAN hardware instance
    can_status_t    const bit_mask       //!< [in] bit mask for set bits
    )
{
can_hw_status[hw_inst] &= SYS_MASK32_COMPLEMENT( bit_mask );
}

/*!*******************************************************************
*
* atomically set can_hw_error_status value
*
* This function atomically sets the specified CAN hardware error
* status value in a critical section.
*
*********************************************************************/
static void
can_hw_set_error_status
    (
    can_hw_inst_t   const hw_inst,     //!< [in] CAN hardware instance
    can_status_t    const value        //!< [in] value to set
    )
{
can_hw_error_status[hw_inst] = value;
}

/*!*******************************************************************
*
* @private
* get FlexCAN hardware driver status
*
* This function gets the specified hardware layer status information
* depending on the status mode indicated. For example the returned
* information can be the hardware status, the hardware error status or
* the interrupt configuration status. Error status bits may optionally
* be cleared after retrieval of the current status, depending on the
* specified status mode.
*
* @return can_status_t
* bit encoded driver status
*
*********************************************************************/
can_status_t
can_hw_get_status
    (
    can_hw_inst_t       const hw_inst,    //!< [in] CAN hardware instance
    can_get_stat_mode_t const status_mode //!< [in] status mod
    )
{
can_status_t    l_ret_status;

/*------------------------------------------------------
Initialize the Returned Status
------------------------------------------------------*/
l_ret_status = 0;

switch ( status_mode )
    {
    case CAN_GET_HW_STATUS:

        l_ret_status = can_hw_status[hw_inst];
        break;

    case CAN_GET_HW_ERROR_STATUS:
    case CAN_GET_CLEAR_HW_ERROR_STATUS:

        l_ret_status = can_hw_error_status[hw_inst];

        if( CAN_GET_CLEAR_HW_ERROR_STATUS == status_mode )
            {
            can_hw_set_error_status( hw_inst, 0 );
            }
        break;

    case CAN_GET_HW_INT_CFG_STATUS:
        l_ret_status = can_hw_cfg_int_status[hw_inst];
        break;

    default:
        break;
    }

return l_ret_status;
}

/*!*******************************************************************
*
* enter FlexCAN initialization mode
*
* This function puts the FlexCAN controller into initialization mode.
*
* return status code
*
*********************************************************************/
static can_ret_code_t
can_hw_enter_init_mode
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
can_ret_code_t   l_ret_code       = CAN_RC_FAIL;

/*------------------------------------------------------
Clear the Hardware ONLINE Status
------------------------------------------------------*/
can_hw_clear_status_bit( hw_inst, CAN_HW_ONLINE );

return (l_ret_code = CAN_RC_OK);
}

/*!*******************************************************************
*
* exit FlexCAN initialization mode
*
* This function exits the FlexCANcontroller initialization mode.
*
* return status code
*
*********************************************************************/
static can_ret_code_t
can_hw_exit_init_mode
    (
    can_hw_inst_t   const hw_inst       //!< [in] CAN hardware instance
    )
{
can_ret_code_t   l_ret_code       = CAN_RC_FAIL;

/*------------------------------------------------------
Set the Hardware ONLINE Status
------------------------------------------------------*/
can_hw_set_status_bit( hw_inst, CAN_HW_ONLINE );

return( l_ret_code = CAN_RC_OK );
}

/*!*******************************************************************
*
* @private
* check if CAN transmit message frame is pending
*
* This functions checks the indicated hardware Module for
* any pending message transmissions.
*
* @return can_ret_code_t
* return code indicating true or false
*
*********************************************************************/
can_ret_code_t
can_hw_is_tx_pending
    (
    can_hw_inst_t   const hw_inst,    //!< [in] CAN hardware instance
    can_hmb_t       const tx_mb_index //!< [in] transmit Message Buffer
    )
{
flexcan_regs_t   *l_p_flexcan_regs  = NULL;
can_ret_code_t    l_ret_code        = CAN_RC_FALSE;
uint32_t          l_cs_temp         = 0;

/*------------------------------------------------------
Message Buffer index is from 0~CAN_HMB_ALL, tx_index is from
CAN_HMB_TX_START + CAN_HMB_TX_START
------------------------------------------------------*/
if( ( tx_mb_index >= ( CAN_HMB_TX_ALL + CAN_HMB_TX_START ) ) ||
    ( tx_mb_index < CAN_HMB_TX_START ) )
    {
    return ( l_ret_code = CAN_RC_INVALID_PARAM );
    }

/*------------------------------------------------------
Get Pointer to Hardware Instance Registers
------------------------------------------------------*/
l_p_flexcan_regs = can_hw_get_regs( hw_inst );

/*------------------------------------------------------
Get the CS of the Message Buffer
------------------------------------------------------*/
l_cs_temp = l_p_flexcan_regs->MB[tx_mb_index].CS;

/*------------------------------------------------------
Check if the Message Buffer is in DATA transmitting
------------------------------------------------------*/
if( ( ( l_cs_temp & CAN_CS_CODE_MASK ) >> CAN_CS_CODE_SHIFT ) == FLEXCAN_TXMB_DATAORREMOTE )
    {
    l_ret_code = CAN_RC_TRUE;
    }

return l_ret_code;
}

/*!*******************************************************************
*
* @private
* check if the CAN bus is active
*
* This functions checks the hardware layer status to determine if
* there has been CAN bus activity (transmitted or received message)
* since the last check. This function also checks the Status
* Register to see if the CAN controller is currently transmitting or
* receiving a message.
*
* @return can_ret_code_t
* return code indicating true or false
*
*********************************************************************/
can_ret_code_t
can_hw_is_bus_active
    (
    can_hw_inst_t   const hw_inst       //!< [in] CAN hardware instance
    )
{
flexcan_regs_t   *l_p_flexcan_regs  = NULL;
can_ret_code_t    l_ret_code        = CAN_RC_FALSE;

/*------------------------------------------------------
Get Pointer to Hardware Instance Registers
------------------------------------------------------*/
l_p_flexcan_regs = can_hw_get_regs( hw_inst );

/*------------------------------------------------------
If Valid Frame Transmit or Receive in Progress, Bus is Active
------------------------------------------------------*/
if( ( ( can_hw_status[hw_inst] & CAN_HW_BUS_ACTIVE ) != 0 ) &&
    ( ( l_p_flexcan_regs->MCR & CAN_MCR_NOTRDY_MASK ) == 0 ) )
    {
    l_ret_code = CAN_RC_TRUE;
    }
else
    {
    l_ret_code = CAN_RC_FALSE;
    }

/*------------------------------------------------------
Clear Status Bit Atomically to Re-Arm the Flag
------------------------------------------------------*/
can_hw_clear_status_bit( hw_inst, CAN_HW_BUS_ACTIVE );

return l_ret_code;
}

/*!*******************************************************************
*
* @private
* check if the CAN bus is asleep
*
* This function is intended to support polled mode operation where
* wakeup interrupts are disabled and the wakeup status is polled to
* see if the CAN controller was awakened by bus activity.
*
* @return can_ret_code_t
* return code indicating true or false
*
*********************************************************************/
can_ret_code_t
can_hw_is_bus_sleep
    (
    can_hw_inst_t   const hw_inst       //!< [in] CAN hardware instance
    )
{
can_status_t    l_ret_status = 0;
can_ret_code_t  l_ret_code   = CAN_RC_FALSE;

/*------------------------------------------------------
Get the hardware status
------------------------------------------------------*/
l_ret_status = can_hw_get_status( hw_inst, CAN_GET_HW_STATUS );

/*------------------------------------------------------
Check if the hardware status is Wakeup
------------------------------------------------------*/
if( ( CAN_HW_WAKEUP & l_ret_status ) == 0 )
    {
    l_ret_code = CAN_RC_TRUE;
    }

return l_ret_code;
}

/*!*******************************************************************
*
* @private
* check if the FlexCAN controller bus connection is open
*
* This function checks the FlexCAN controller TX error count to infer if
* the CAN Bus is open. This is only a necessary but not sufficient
* condition check. In other words, if the CAN bus is open, the TX
* error count will be greater than or equal to the error passive count
* level (128). However the error count could be greater than the error
* passive count limit but not be open. Regardless, the CAN bus is
* severely faulted or there are no acknowledgers of transmitted CAN
* frames.
*
* @return can_ret_code_t
* return code indicating true or false
*
*********************************************************************/
can_ret_code_t
can_hw_is_bus_open
    (
    can_hw_inst_t   const hw_inst       //!< [in] CAN hardware instance
    )
{
flexcan_regs_t   *l_p_flexcan_regs = NULL;
can_ret_code_t    l_ret_code       = CAN_RC_FALSE;
uint32            l_esr_status     = 0;
uint8             l_flt_conf       = 0;

/*------------------------------------------------------
Get Pointer to Hardware Instance Registers and read the
Error Status Register to determine if Error Passive
error is set.
------------------------------------------------------*/
l_p_flexcan_regs = can_hw_get_regs( hw_inst );
l_esr_status     = l_p_flexcan_regs->ESR1;
l_flt_conf       = (uint8)( ( l_esr_status & CAN_ESR1_FLTCONF_MASK ) >> CAN_ESR1_FLTCONF_SHIFT );

/*------------------------------------------------------
Check if the FLT_CONF is Error Passive level
------------------------------------------------------*/
if( l_flt_conf == FLT_CONF_ERR_PASSIVE )
    {
    l_ret_code = CAN_RC_TRUE;
    }

return l_ret_code;
}

/*!*******************************************************************
*
* @private
* put the FlexCAN controller back online
*
* This function puts the FlexCAN controller online. An assumption for
* this function to work properly is that the CAN controller has
* already been successfully initialized and subsequently taken offline
* by setting the INRQ bit to put the controller into initialization
* mode where it is not able to communicate on the CAN bus.
*
* @return can_ret_code_t
* return code indicating success or failure
*
*********************************************************************/
can_ret_code_t
can_hw_on_line
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
can_ret_code_t l_ret_code;

/*------------------------------------------------------
Initialize the Return Code
------------------------------------------------------*/
l_ret_code = CAN_RC_NOT_AVAILABLE;

/*------------------------------------------------------
Put Controller Online... for the FlexCAN controller this
means taking it out of initialization mode after it
previously has been successfully initialized.
------------------------------------------------------*/
if( ( can_hw_status[hw_inst] & CAN_HW_INITOK ) )
    {
    l_ret_code = can_hw_exit_init_mode( hw_inst );
    }

return l_ret_code;
}

/*!*******************************************************************
*
* @private
* take the FlexCAN controller offline
*
* This function takes the FlexCAN controller offline. An assumption for
* this function to work properly is that the CAN controller has
* already been successfully initialized. It is taken offline by
* setting the INRQ bit to put the controller into the initialization
* mode where it is not able to communicate on the CAN bus.
*
* @return can_ret_code_t
* return code indicating success or failure
*
*********************************************************************/
can_ret_code_t
can_hw_off_line
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
can_ret_code_t l_ret_code;

/*------------------------------------------------------
Initialize the Return Code
------------------------------------------------------*/
l_ret_code = CAN_RC_NOT_AVAILABLE;

/*------------------------------------------------------
Put the CAN Controller Offline. For the FlexCAN controller
this implies putting it into initialization mode after it
previously has been successfully initialized.
------------------------------------------------------*/
if( ( can_hw_status[hw_inst] & CAN_HW_INITOK ) != 0 )
    {
    l_ret_code = can_hw_enter_init_mode( hw_inst );
    }

return l_ret_code;
}

/*!*******************************************************************
*
* @private
* power down the FlexCAN controller
*
* This function presently is not suppported but it may be possible to
* support this by turning off the peripheral clock to the FlexCAN
* controller.
*
* @return can_ret_code_t
* return code indicating success or failure
*
*********************************************************************/
can_ret_code_t
can_hw_power_down
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
Presently not supported
------------------------------------------------------*/
return CAN_RC_NOT_AVAILABLE;
}

/*!*******************************************************************
*
* @private
* put the FlexCAN controller into the sleep state
*
* This function puts the FlexCAN controller into the sleep mode. The
* assumption is that the CAN controller was previously initialized
* successfully on the CAN bus.
*
* @return can_ret_code_t
* return code indicating success or failure
*
*********************************************************************/
can_ret_code_t
can_hw_sleep
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
Presently not supported
------------------------------------------------------*/
return CAN_RC_NOT_AVAILABLE;
}

/*!*******************************************************************
*
* @private
* host wakeup of the FlexCAN controller
*
* This function takes the FlexCAN controller out of the sleep mode.
* This function is normally used to wake up a sleeping CAN controller
* in response to a "local" wakeup condition such as a switch input or
* some other non-Network related input activity.
*
* @return can_ret_code_t
* return code indicating success or failure
*
*********************************************************************/
can_ret_code_t
can_hw_wakeup
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
Presently not supported
------------------------------------------------------*/
return CAN_RC_NOT_AVAILABLE;
}

/*!*******************************************************************
*
* @private
* enable FlexCAN controller transmit buffer empty interrupt
*
* This function enables the transmit complete interrupt (actually the
* transmit xxxxxxxxxxxx empty interrupt). In order to support run time
* enabling and disabling of the transmit mailbox empty interrupt the
* transmit interrupt must be enabled in the CAN controller's saved
* interrupt configuration status that was set as part of CAN
* controller initialization.
*
* @return can_ret_code_t
* return code indicating success or failure
*
*********************************************************************/
can_ret_code_t
can_hw_enable_tx_interrupt
    (
    can_hw_inst_t   const hw_inst,    //!< [in] CAN hardware instance
    can_hmb_t       const tx_mb_index //!< [in] FlexCAN receive message buffer
    )
{
flexcan_regs_t  *l_p_flexcan_regs = NULL;
uint64_t         l_u64Msk         = 1;

/*------------------------------------------------------
Get Pointer to Hardware Instance Registers
------------------------------------------------------*/
l_p_flexcan_regs = can_hw_get_regs( hw_inst );

/*------------------------------------------------------
Clear interrupt of Message Buffer.
------------------------------------------------------*/
flexcan_EnableMbInterrupts( l_p_flexcan_regs, ( l_u64Msk << tx_mb_index ) );

return CAN_RC_OK;
}

/*!*******************************************************************
*
* @private
* disable FlexCAN controller transmit buffer empty interrupt
*
* This function allows the application to dynamically disable the
* transmit complete interrupt. Transmit interrupts must have been
* enabled as part of the original initialization configuration to
* enable dynamic (i.e. run time) configuration of the transmit
* complete interrupt.
*
* @return can_ret_code_t
* return code indicating success or failure
*
*********************************************************************/
can_ret_code_t
can_hw_disable_tx_interrupt
    (
    can_hw_inst_t   const hw_inst,    //!< [in] CAN hardware instance
    can_hmb_t       const tx_mb_index //!< [in] FlexCAN receive message buffer
    )
{
flexcan_regs_t  *l_p_flexcan_regs = NULL;
uint64_t         l_u64Msk         = 1;

/*------------------------------------------------------
Get Pointer to Hardware Instance Registers
------------------------------------------------------*/
l_p_flexcan_regs = can_hw_get_regs( hw_inst );

/*------------------------------------------------------
Clear interrupt of Message Buffer.
------------------------------------------------------*/
flexcan_DisableMbInterrupts( l_p_flexcan_regs, ( l_u64Msk << tx_mb_index ) );

return CAN_RC_OK;
}

/*!*******************************************************************
*
* @private
* enable FlexCAN controller receive buffer interrupt
*
* This function enables the message reception interrupt. In order to
* support run time enabling and disabling of the receive interrupt the
* receive interrupt must be enabled in the CAN controller's saved
* interrupt configuration status that was set as part of CAN
* controller initialization.
*
* @return can_ret_code_t
* return code indicating success or failure
*
*********************************************************************/
can_ret_code_t
can_hw_enable_rx_interrupt
    (
    can_hw_inst_t   const hw_inst,    //!< [in] CAN hardware instance
    can_hmb_t       const rx_mb_index //!< [in] FlexCAN receive message buffer
    )
{
flexcan_regs_t  *l_p_flexcan_regs = NULL;
uint64_t         l_u64Msk         = 1;

/*------------------------------------------------------
Get Pointer to Hardware Instance Registers
------------------------------------------------------*/
l_p_flexcan_regs = can_hw_get_regs( hw_inst );

/*------------------------------------------------------
Set interrupt of Message Buffer.
------------------------------------------------------*/
flexcan_EnableMbInterrupts( l_p_flexcan_regs, ( l_u64Msk << rx_mb_index ) );

return CAN_RC_OK;
}

/*!*******************************************************************
*
* @private
* disable FlexCAN controller receive buffer interrupt
*
* This function disables the message reception interrupt. In order to
* support run time enabling and disabling of the receive interrupt the
* receive interrupt must be enabled in the CAN controller's saved
* interrupt configuration status that was set as part of CAN
* controller initialization.
*
* @return can_ret_code_t
* return code indicating success or failure
*
*********************************************************************/
can_ret_code_t
can_hw_disable_rx_interrupt
    (
    can_hw_inst_t   const hw_inst,    //!< [in] CAN hardware instance
    can_hmb_t       const rx_mb_index //!< [in] FlexCAN receive message buffer
    )
{
flexcan_regs_t  *l_p_flexcan_regs = NULL;
uint64_t         l_u64Msk         = 1;

/*------------------------------------------------------
Get Pointer to Hardware Instance Registers
------------------------------------------------------*/
l_p_flexcan_regs = can_hw_get_regs( hw_inst );

/*------------------------------------------------------
Clear interrupt of Message Buffer.
------------------------------------------------------*/
flexcan_DisableMbInterrupts( l_p_flexcan_regs, ( l_u64Msk << rx_mb_index ) );

return CAN_RC_OK;
}

/*!*******************************************************************
*
* @private
* enable FlexCAN controller interrupts
*
* This function enables CAN interrupts according to the current
* interrupt configuration settings for this CAN controller. Since the
* CAN controller can be dynamically reconfigured at run time a status
* variable must be maintained that keeps track of the current
* interrupt configuration when CAN interrupts are enabled. Note that
* if Sleep and/or Wakeup interrupts are supported for a given
* configuration, these interrupts are only enabled when the CAN
* controller is put into the Sleep state.
*
* @return can_ret_code_t
* return code indicating success or failure
*
*********************************************************************/
can_ret_code_t
can_hw_enable_interrupts
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
flexcan_regs_t  *l_p_flexcan_regs = NULL;

/*------------------------------------------------------
Get Pointer to Hardware Instance Registers
------------------------------------------------------*/
l_p_flexcan_regs = can_hw_get_regs( hw_inst );

flexcan_EnableInterrupts( l_p_flexcan_regs,  (uint32_t)( FLEXCAN_TXWARNING_INT_EN   | FLEXCAN_RXWARNING_INT_EN |
                                                         FLEXCAN_BUSOFF_INT_EN      | FLEXCAN_ERROR_INT_EN ) );

/*------------------------------------------------------
Enable interrupts in NVIC.
------------------------------------------------------*/
(void)EnableIRQ((IRQn_Type)(s_flexcanRxWarningIRQ[CAN2_INSTANCE]));
(void)EnableIRQ((IRQn_Type)(s_flexcanTxWarningIRQ[CAN2_INSTANCE]));
(void)EnableIRQ((IRQn_Type)(s_flexcanWakeUpIRQ[CAN2_INSTANCE]));
(void)EnableIRQ((IRQn_Type)(s_flexcanErrorIRQ[CAN2_INSTANCE]));
(void)EnableIRQ((IRQn_Type)(s_flexcanBusOffIRQ[CAN2_INSTANCE]));
(void)EnableIRQ((IRQn_Type)(s_flexcanMbIRQ[CAN2_INSTANCE]));

return CAN_RC_OK;
}

/*!*******************************************************************
*
* @private
* disable FlexCAN controller interrupts
*
* This function disables all of the FlexCAN controller interrupts.
*
* @return can_ret_code_t
* return code indicating success or failure
*
*********************************************************************/
can_ret_code_t
can_hw_disable_interrupts
    (
    can_hw_inst_t   const hw_inst //!< [in] CAN hardware instance
    )
{
flexcan_regs_t  *l_p_flexcan_regs = NULL;

/*------------------------------------------------------
Get Pointer to Hardware Instance Registers
------------------------------------------------------*/
l_p_flexcan_regs = can_hw_get_regs( hw_inst );

flexcan_DisableInterrupts( l_p_flexcan_regs, (uint32_t)( FLEXCAN_TXWARNING_INT_EN | FLEXCAN_RXWARNING_INT_EN |
                                                         FLEXCAN_BUSOFF_INT_EN    | FLEXCAN_ERROR_INT_EN ) );

/*------------------------------------------------------
Disable interrupts in NVIC.
------------------------------------------------------*/
(void)DisableIRQ((IRQn_Type)(s_flexcanRxWarningIRQ[CAN2_INSTANCE]));
(void)DisableIRQ((IRQn_Type)(s_flexcanTxWarningIRQ[CAN2_INSTANCE]));
(void)DisableIRQ((IRQn_Type)(s_flexcanWakeUpIRQ[CAN2_INSTANCE]));
(void)DisableIRQ((IRQn_Type)(s_flexcanErrorIRQ[CAN2_INSTANCE]));
(void)DisableIRQ((IRQn_Type)(s_flexcanBusOffIRQ[CAN2_INSTANCE]));
(void)DisableIRQ((IRQn_Type)(s_flexcanMbIRQ[CAN2_INSTANCE]));

return CAN_RC_OK;
}

/*!*******************************************************************
*
*Enter freeze mode
*
*This function is used to make FlexCAN module into Freeze Mode
*
*********************************************************************/
static void flexcan_EnterFreezeMode
    (
    flexcan_regs_t    * const p_flexcan_hw_regs //!< [in] ptr to FlexCAN H/W registers
    )
{
/*------------------------------------------------------
Set Freeze, Halt bits.
------------------------------------------------------*/
p_flexcan_hw_regs->MCR |= CAN_MCR_FRZ_MASK;
p_flexcan_hw_regs->MCR |= CAN_MCR_HALT_MASK;
while( 0U == ( p_flexcan_hw_regs->MCR & CAN_MCR_FRZACK_MASK ) )
    {
    }

/*------------------------------------------------------
Set hardware status
------------------------------------------------------*/
can_hw_clear_status_bit( CAN_CONTROLLER_2, CAN_HW_WAKEUP );
can_hw_clear_status_bit( CAN_CONTROLLER_2, CAN_HW_NORMAL_MODE );
can_hw_set_status_bit( CAN_CONTROLLER_2, CAN_HW_FREEZE_MODE );
}

/*!*******************************************************************
*
*Exit freeze mode
*
*This function is used to make FlexCAN module exit Freeze Mode
*
*********************************************************************/
void flexcan_ExitFreezeMode
(
flexcan_regs_t    * const p_flexcan_hw_regs //!< [in] ptr to FlexCAN H/W registers
)
{
#if( defined(FSL_FEATURE_FLEXCAN_HAS_MEMORY_ERROR_CONTROL ) && FSL_FEATURE_FLEXCAN_HAS_MEMORY_ERROR_CONTROL )
    /*------------------------------------------------------
    Check MECR register and CTRL2 register
    ------------------------------------------------------*/
    uint32_t tempCTRL2 = p_flexcan_hw_regs->CTRL2;
    if( !( tempCTRL2 & CAN_CTRL2_ECRWRE_MASK ) )
        {
        tempCTRL2 |= CAN_CTRL2_ECRWRE_MASK;
        p_flexcan_hw_regs->CTRL2 = tempCTRL2;
        }

    uint32_t tempMECR = p_flexcan_hw_regs->MECR;
    if( tempMECR & CAN_MECR_NCEFAFRZ_MASK )
        {
        tempMECR &= ~CAN_MECR_NCEFAFRZ_MASK;
        p_flexcan_hw_regs->MECR = tempMECR;
        }
#endif

/*------------------------------------------------------
Clear Freeze, Halt bits.
------------------------------------------------------*/
p_flexcan_hw_regs->MCR &= ~CAN_MCR_HALT_MASK;
p_flexcan_hw_regs->MCR &= ~CAN_MCR_FRZ_MASK;

/*------------------------------------------------------
Wait until the FlexCAN Module exit freeze mode.
------------------------------------------------------*/
while( 0U != ( p_flexcan_hw_regs->MCR & CAN_MCR_FRZACK_MASK ) )
    {
    }
/*------------------------------------------------------
Set hardware status
------------------------------------------------------*/
can_hw_clear_status_bit( CAN_CONTROLLER_2, CAN_HW_FREEZE_MODE );
can_hw_set_status_bit( CAN_CONTROLLER_2, CAN_HW_NORMAL_MODE );
}

/*!*******************************************************************
* brief Sets the FlexCAN protocol timing characteristic.
*
* This function gives user settings to CAN bus timing characteristic.
* The function is for an experienced user. For less experienced users, call
* the flexcan_Init() and fill the baud rate field with a desired value.
* This provides the default timing characteristics to the module.
*
* Note that calling flexcan_SetTimingConfig() overrides the baud rate set
* in flexcan_Init().
*
* param base FlexCAN peripheral base address.
* param pConfig Pointer to the timing configuration structure.

*********************************************************************/
static void flexcan_SetTimingConfig
    (
    flexcan_regs_t         * const p_flexcan_hw_regs, //!< [in] ptr to FlexCAN H/W registers
    const flexcan_timing_config_t *p_timeConfig
    )
{
/*------------------------------------------------------
Enter Freeze Mode.
------------------------------------------------------*/
flexcan_EnterFreezeMode( p_flexcan_hw_regs );

/*------------------------------------------------------
Cleaning previous Timing Setting.
------------------------------------------------------*/
p_flexcan_hw_regs->CTRL1 &= ~( CAN_CTRL1_PRESDIV_MASK | CAN_CTRL1_RJW_MASK | CAN_CTRL1_PSEG1_MASK |
                            CAN_CTRL1_PSEG2_MASK | CAN_CTRL1_PROPSEG_MASK );

/*------------------------------------------------------
Updating Timing Setting according to configuration structure.
------------------------------------------------------*/
p_flexcan_hw_regs->CTRL1 |= (CAN_CTRL1_PRESDIV( p_timeConfig->preDivider  ) | CAN_CTRL1_RJW( p_timeConfig->rJumpwidth ) |
                             CAN_CTRL1_PSEG1( p_timeConfig->phaseSeg1 ) | CAN_CTRL1_PSEG2( p_timeConfig->phaseSeg2 ) |
                             CAN_CTRL1_PROPSEG( p_timeConfig->propSeg  ) );

/*------------------------------------------------------
Exit Freeze Mode.
------------------------------------------------------*/
flexcan_ExitFreezeMode( p_flexcan_hw_regs );
}

/*!*******************************************************************
*
Set Baudrate
*
*This function is used to set the baudrate of the FlexCAN module
*
*********************************************************************/
static void flexcan_SetBaudRate
    (
    flexcan_regs_t    *const  p_flexcan_hw_regs, //!< [in] ptr to FlexCAN H/W registers
    uint32_t                  sourceClock_Hz,
    uint32_t                  baudRate_Bps,
    flexcan_timing_config_t  *p_timingConfig
    )
{
/*------------------------------------------------------
FlexCAN timing setting formula:
quantum = 1 + (PSEG1 + 1) + (PSEG2 + 1) + (PROPSEG + 1)
------------------------------------------------------*/
uint32_t l_quantum = ( 1U + ( (uint32_t)p_timingConfig->phaseSeg1 + 1U ) + ( (uint32_t)p_timingConfig->phaseSeg2 + 1U ) + ( (uint32_t)p_timingConfig->propSeg + 1U ) );
uint32_t l_priDiv  = baudRate_Bps * l_quantum;

/*------------------------------------------------------
Calc and set the priDiv
------------------------------------------------------*/
if ( 0U == l_priDiv  )
    {
    l_priDiv = 1;
    }

l_priDiv = ( sourceClock_Hz / l_priDiv ) - 1U;

/*------------------------------------------------------
Desired baud rate is too low.
------------------------------------------------------*/
if ( l_priDiv > 0xFFU )
    {
    l_priDiv = 0xFF;
    }

p_timingConfig->preDivider = (uint16_t)l_priDiv;

/*------------------------------------------------------
Update actual timing characteristic.
------------------------------------------------------*/
flexcan_SetTimingConfig( p_flexcan_hw_regs, p_timingConfig );
}

/*!*******************************************************************
* brief Reset the FlexCAN.
*
* This function is used to reset the FlexCAN module
*
* param base FlexCAN peripheral base address.
*
*********************************************************************/
static void flexcan_Reset
    (
    flexcan_regs_t    *const p_flexcan_hw_regs //!< [in] ptr to FlexCAN H/W registers
    )
{
uint8       index = 0;

/*------------------------------------------------------
The module must should be first exit from low power
mode, and then soft reset can be applied.
------------------------------------------------------*/
assert( 0U == ( p_flexcan_hw_regs->MCR & CAN_MCR_MDIS_MASK ) );

/*------------------------------------------------------
Wait until FlexCAN exit from any Low Power Mode.
------------------------------------------------------*/
while( 0U != ( p_flexcan_hw_regs->MCR & CAN_MCR_LPMACK_MASK ) )
    {
    }

/*------------------------------------------------------
Assert Soft Reset Signal.
------------------------------------------------------*/
p_flexcan_hw_regs->MCR |= CAN_MCR_SOFTRST_MASK;

/*------------------------------------------------------
Wait until FlexCAN reset completes.
------------------------------------------------------*/
while ( 0U != ( p_flexcan_hw_regs->MCR & CAN_MCR_SOFTRST_MASK ) )
    {
    }

/*------------------------------------------------------
Reset MCR register.
------------------------------------------------------*/
p_flexcan_hw_regs->MCR |= CAN_MCR_WRNEN_MASK | CAN_MCR_WAKSRC_MASK | CAN_MCR_MAXMB( (uint32_t)FSL_FEATURE_FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBERn(p_flexcan_regs) - 1U );

/*------------------------------------------------------
Reset CTRL1 and CTRL2 register.
------------------------------------------------------*/
p_flexcan_hw_regs->CTRL1 = CAN_CTRL1_SMP_MASK;
p_flexcan_hw_regs->CTRL2 = CAN_CTRL2_TASD(0x16) | CAN_CTRL2_RRS_MASK | CAN_CTRL2_EACEN_MASK;

/*------------------------------------------------------
Clean all individual Rx Mask of Message Buffers.
------------------------------------------------------*/
for( index = 0; index < (uint32_t)FSL_FEATURE_FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBERn(p_flexcan_regs); index++ )
    {
    p_flexcan_hw_regs->RXIMR[index] = 0x3FFFFFFF;
    }

/*------------------------------------------------------
Clean Global Mask of Message Buffers.
------------------------------------------------------*/
p_flexcan_hw_regs->RXMGMASK = 0x3FFFFFFF;
/*------------------------------------------------------
Clean Global Mask of Message Buffer 14.
------------------------------------------------------*/
p_flexcan_hw_regs->RX14MASK = 0x3FFFFFFF;
/*------------------------------------------------------
Clean Global Mask of Message Buffer 15.
------------------------------------------------------*/
p_flexcan_hw_regs->RX15MASK = 0x3FFFFFFF;
/*------------------------------------------------------
Clean Global Mask of Rx FIFO.
------------------------------------------------------*/
p_flexcan_hw_regs->RXFGMASK = 0x3FFFFFFF;

/*------------------------------------------------------
Clean all Message Buffer CS fields.
------------------------------------------------------*/
for( index = 0; index < (uint32_t)FSL_FEATURE_FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBERn(p_flexcan_regs); index++ )
    {
    p_flexcan_hw_regs->MB[index].CS = 0x0;
    }
}

/*!*******************************************************************
*
* brief Get the interrup of a message buffer.
*
* This function gets a Message Buffer's interrup status.
*
* param mbIdx The Message Buffer index.
*
*********************************************************************/
static bool flexcan_IsMbIntEnabled
    (
    flexcan_regs_t        * const p_flexcan_hw_regs, //!< [in] ptr to FlexCAN H/W registers
    can_hmb_t                     mb_index           //!< [in] Message Buffer to be checked
    )
{
uint32_t l_u32flag  = 1U;
bool     l_intflag  = FALSE;

/*------------------------------------------------------
Check if the MB's interrupt is enabled
------------------------------------------------------*/
if ( mb_index >= 32U )
    {
    l_intflag = ( 0U != ( p_flexcan_hw_regs->IMASK2 & ( l_u32flag << ( mb_index - 32U ) ) ) );
    }
else
    {
    l_intflag = ( 0U != ( p_flexcan_hw_regs->IMASK1 & ( l_u32flag << mb_index ) ) );
    }

return l_intflag;
}

/*!*******************************************************************
*
* brief Configures a FlexCAN transmit message buffer.
*
* This function aborts the previous transmission, cleans the Message
* Buffer, and configures it as a Transmit Message Buffer.
*
*********************************************************************/
static void flexcan_SetTxMbConfig
    (
    flexcan_regs_t        * const p_flexcan_hw_regs, //!< [in] ptr to FlexCAN H/W registers
    can_hmb_t                     tx_mb_index,       //!< [in] transmit Message Buffer
    bool                          enable             //!< [in] Enable/disable Tx Message Buffer.
    )
{
/*------------------------------------------------------
Message Buffer index is from 0~CAN_HMB_ALL, tx_index is from
CAN_HMB_TX_START to ( CAN_HMB_TX_START + CAN_HMB_TX_ALL )
------------------------------------------------------*/
if( ( tx_mb_index >= ( CAN_HMB_TX_ALL + CAN_HMB_TX_START ) ) ||
    ( tx_mb_index < CAN_HMB_TX_START ) )
    {
    return;
    }

/*------------------------------------------------------
Inactivate Message Buffer.
------------------------------------------------------*/
if( enable )
    {
    p_flexcan_hw_regs->MB[tx_mb_index].CS = CAN_CS_CODE( FLEXCAN_TXMB_INACTIVE );
    }
else
    {
    p_flexcan_hw_regs->MB[tx_mb_index].CS = 0;
    }

/*------------------------------------------------------
Clean Message Buffer content.
------------------------------------------------------*/
p_flexcan_hw_regs->MB[tx_mb_index].ID    = 0x0;
p_flexcan_hw_regs->MB[tx_mb_index].WORD0 = 0x0;
p_flexcan_hw_regs->MB[tx_mb_index].WORD1 = 0x0;
}

/*!*******************************************************************
*
* brief Get a FlexCAN transmit message buffer's code.
*
* This function is used to get a Message Buffer's CODE value
*
*********************************************************************/
static uint32 flexcan_getTxMbCode
    (
    flexcan_regs_t        * const p_flexcan_hw_regs, //!< [in] ptr to FlexCAN H/W registers
    can_hmb_t                     tx_mb_index        //!< [in] transmit Message Buffer
    )
{
uint32_t l_CS_temp = 0;
uint32_t l_Code    = 0;

/*------------------------------------------------------
Message Buffer index is from 0~CAN_HMB_ALL, tx_index is from
CAN_HMB_TX_START + CAN_HMB_TX_START
------------------------------------------------------*/
if( ( tx_mb_index >= ( CAN_HMB_TX_ALL + CAN_HMB_TX_START ) ) ||
    ( tx_mb_index < CAN_HMB_TX_START ) )
    {
    return l_Code = FLEXCAN_TXMB_NOTUSED;
    }

/*------------------------------------------------------
Get the CS vlaue of the Message Buffer.
------------------------------------------------------*/
l_CS_temp = p_flexcan_hw_regs->MB[tx_mb_index].CS;

/*------------------------------------------------------
Get the CODE in the CS register
------------------------------------------------------*/
l_Code = (uint32_t )( ( l_CS_temp & CAN_CS_CODE_MASK ) >> CAN_CS_CODE_SHIFT );

return l_Code;
}

/*!*******************************************************************
* brief Sets the FlexCAN receive individual mask.
*
* This function set a receive Message Buffer individual mask.
*
*********************************************************************/
void flexcan_SetRxIndividualMask
    (
    flexcan_regs_t   * const p_flexcan_hw_regs, //!< [in] ptr to FlexCAN H/W registers
    can_hmb_t                rx_mb_msk_index,   //!< [in] The Index of individual Mask.
    uint32_t                 maskRx             //!< [in] Individual Mask value.
    )
{
/*------------------------------------------------------
Enter Freeze Mode.
------------------------------------------------------*/
flexcan_EnterFreezeMode( p_flexcan_hw_regs );

/*------------------------------------------------------
Setting Rx Individual Mask value.
------------------------------------------------------*/
p_flexcan_hw_regs->RXIMR[rx_mb_msk_index] = maskRx;

/*------------------------------------------------------
Exit Freeze Mode.
------------------------------------------------------*/
flexcan_ExitFreezeMode( p_flexcan_hw_regs );
}

/*!*******************************************************************
* brief Configures a FlexCAN Receive Message Buffer.
*
* This function cleans a FlexCAN build-in Message Buffer and configures it
* as a Receive Message Buffer.
*
*********************************************************************/
static void flexcan_SetRxMbConfig
    (
    flexcan_regs_t        * const p_flexcan_hw_regs, //!< [in] ptr to FlexCAN H/W registers
    can_hmb_t                     rx_mb_index,       //!< [in] receive Message Buffer
    const flexcan_rx_mb_config_t *p_RxMbConfig,      //!< [in] Configuration consts
    bool                          enable             //!< [in] Enable/disable Rx Message Buffer
    )
{
uint32_t    l_cs_temp = 0;

/*------------------------------------------------------
Message Buffer index is from 0~CAN_HMB_RX_ALL
------------------------------------------------------*/
if( rx_mb_index >= CAN_HMB_RX_ALL )
    {
    return;
    }

/*------------------------------------------------------
Inactivate Message Buffer.
------------------------------------------------------*/
p_flexcan_hw_regs->MB[rx_mb_index].CS    = 0;

/*------------------------------------------------------
Clean Message Buffer content.
------------------------------------------------------*/
p_flexcan_hw_regs->MB[rx_mb_index].ID    = 0x0;
p_flexcan_hw_regs->MB[rx_mb_index].WORD0 = 0x0;
p_flexcan_hw_regs->MB[rx_mb_index].WORD1 = 0x0;

if( enable )
    {
    /*------------------------------------------------------
    Setup Message Buffer ID.
    ------------------------------------------------------*/
    p_flexcan_hw_regs->MB[rx_mb_index].ID = p_RxMbConfig->id;

    /*------------------------------------------------------
    Setup Message Buffer format.
    ------------------------------------------------------*/
    if( CAN_EXTENDED_MSG_TYPE == p_RxMbConfig->format )
    {
    l_cs_temp |= CAN_CS_IDE_MASK;
    }

    /*------------------------------------------------------
    Setup Message Buffer type.
    ------------------------------------------------------*/
    if( CAN_REMOTE_MSG_TYPE == p_RxMbConfig->type )
    {
    l_cs_temp |= CAN_CS_RTR_MASK;
    }

    /*------------------------------------------------------
    Activate Rx Message Buffer.
    ------------------------------------------------------*/
    l_cs_temp |= CAN_CS_CODE(FLEXCAN_RXMB_EMPTY);
    p_flexcan_hw_regs->MB[rx_mb_index].CS = l_cs_temp;
    }
}

/*!*******************************************************************
*
* write transmit data to transmit Message Buffer
*
* This function writes the transmit information and the transmit data
* to the specified FlexCAN transmit Message Buffer
*
*********************************************************************/
static can_ret_code_t
can_hw_write_tx_mb
    (
    can_hw_inst_t           const hw_inst,              //!< [in] CAN hardware instance
    flexcan_regs_t        * const p_flexcan_hw_regs,    //!< [in] ptr to FlexCAN H/W registers
    can_tmd_t       const * const p_tmd,                //!< [in] ptr to transmit data structure
    can_hmb_t               const tx_mb_index           //!< [in] transmit Message Buffer instance
    )
{
can_ret_code_t       l_ret_code        = CAN_RC_FAIL;
uint32               l_mcr             = 0;
uint32               l_cs_temp         = 0;
uint8                l_dlc_data        = 0;
uint8                l_index           = 0;
uint8                l_tmd_hdl_idx     = 0;

/*------------------------------------------------------
Message Buffer index is from 0~CAN_HMB_ALL, tx_index is from
CAN_HMB_TX_START + CAN_HMB_TX_START
------------------------------------------------------*/
if( ( tx_mb_index >= ( CAN_HMB_TX_ALL + CAN_HMB_TX_START ) ) ||
    ( tx_mb_index < CAN_HMB_TX_START ) )
    {
    return l_ret_code;
    }

/*------------------------------------------------------
Read MCR
------------------------------------------------------*/
l_mcr = p_flexcan_hw_regs->MCR;

/*------------------------------------------------------
Checking if CAN controller is in running / operational mode
------------------------------------------------------*/
if( ( l_mcr & CAN_MCR_NOTRDY_MASK ) != 0 )
    {
    return ( l_ret_code = CAN_RC_FAIL );
    }

/*------------------------------------------------------
Inactive Tx Message Buffer.
------------------------------------------------------*/
p_flexcan_hw_regs->MB[tx_mb_index].CS = ( p_flexcan_hw_regs->MB[tx_mb_index].CS & ( ~CAN_CS_CODE_MASK ) ) | CAN_CS_CODE( FLEXCAN_TXMB_INACTIVE );

/*------------------------------------------------------
Save the handle for transmit complete reporting
------------------------------------------------------*/
l_tmd_hdl_idx = tx_mb_index - CAN_HMB_TX_START;
can_hw_tx_msg_handle[hw_inst][l_tmd_hdl_idx] = p_tmd->handle;

/*------------------------------------------------------
Fill Message Format field.
------------------------------------------------------*/
if ( (uint32_t)CAN_EXTENDED_MSG_TYPE == p_tmd->options )
    {
    l_cs_temp |= CAN_CS_SRR_MASK | CAN_CS_IDE_MASK;

    /*------------------------------------------------------
    Fill Message ID field.
    ------------------------------------------------------*/
    p_flexcan_hw_regs->MB[tx_mb_index].ID = CAN_ID_EXT( p_tmd->identifier );
    }
else if( (uint32_t)CAN_STANDARD_MSG_TYPE == p_tmd->options )
    {
    /*------------------------------------------------------
    Fill Message ID field.
    ------------------------------------------------------*/
    p_flexcan_hw_regs->MB[tx_mb_index].ID = CAN_ID_STD( p_tmd->identifier );
    }

if ( (uint32_t)CAN_REMOTE_MSG_TYPE == p_tmd->options )
    {
    l_cs_temp |= CAN_CS_RTR_MASK;
    }

/*------------------------------------------------------
Get the message data length and limit it to 8 bytes
------------------------------------------------------*/
l_dlc_data = p_tmd->dlc;

if( l_dlc_data > CAN_MAX_DATA_LENGTH )
    {
    l_dlc_data = CAN_MAX_DATA_LENGTH;
    }

l_cs_temp |= CAN_CS_CODE( FLEXCAN_TXMB_DATAORREMOTE ) | CAN_CS_DLC( p_tmd->dlc );

/*------------------------------------------------------
Clear the Data buffer
------------------------------------------------------*/
p_flexcan_hw_regs->MB[tx_mb_index].WORD0 = 0;
p_flexcan_hw_regs->MB[tx_mb_index].WORD1 = 0;

/*------------------------------------------------------
Fill Message Data
------------------------------------------------------*/
l_index = l_dlc_data;
switch( l_dlc_data )
    {
    case 8: p_flexcan_hw_regs->MB[tx_mb_index].WORD1 |= p_tmd->p_data[--l_index];
    case 7: p_flexcan_hw_regs->MB[tx_mb_index].WORD1 |= p_tmd->p_data[--l_index] << SHIFT_ONE_BYTE;
    case 6: p_flexcan_hw_regs->MB[tx_mb_index].WORD1 |= p_tmd->p_data[--l_index] << SHIFT_TWO_BYTES;
    case 5: p_flexcan_hw_regs->MB[tx_mb_index].WORD1 |= p_tmd->p_data[--l_index] << SHIFT_THREE_BYTES;
    case 4: p_flexcan_hw_regs->MB[tx_mb_index].WORD0 |= p_tmd->p_data[--l_index];
    case 3: p_flexcan_hw_regs->MB[tx_mb_index].WORD0 |= p_tmd->p_data[--l_index] << SHIFT_ONE_BYTE;
    case 2: p_flexcan_hw_regs->MB[tx_mb_index].WORD0 |= p_tmd->p_data[--l_index] << SHIFT_TWO_BYTES;
    case 1: p_flexcan_hw_regs->MB[tx_mb_index].WORD0 |= p_tmd->p_data[--l_index] << SHIFT_THREE_BYTES;

    default:
        break;
    }

/*------------------------------------------------------
Activate Tx Message Buffer.
------------------------------------------------------*/
p_flexcan_hw_regs->MB[tx_mb_index].CS = l_cs_temp;

return ( l_ret_code = CAN_RC_SUCCESS );
}

/*!*******************************************************************
*
* get message from FlexCAN receive Message Buffer
*
* This function gets a received message from the specified  receive
* Message Buffer, formats it, and loads it into the RMD data structure
* accessed.
*
*********************************************************************/
static can_ret_code_t
can_hw_receive_rx_mb
    (
    flexcan_regs_t        * const p_flexcan_hw_regs, //!< [in] ptr to FlexCAN H/W registers
    can_rmd_t             * const p_rmd,             //!< [in, out] ptr to receive message write buffer
    can_hmb_t               const rx_mb_index        //!< [in] Index of FlexCAN receive Message Buffer
    )
{
can_ret_code_t       l_ret_code       = CAN_RC_EMPTY;
uint32               cs_temp          = 0;
uint32               rx_code          = 0;
uint8                l_dlc_data       = 0;
uint8                l_index          = 0;

/*------------------------------------------------------
Read CS field of Rx Message Buffer to lock Message Buffer.
------------------------------------------------------*/
cs_temp = p_flexcan_hw_regs->MB[rx_mb_index].CS;

/*------------------------------------------------------
Get Rx Message Buffer Code field.
------------------------------------------------------*/
rx_code = ( cs_temp & CAN_CS_CODE_MASK ) >> CAN_CS_CODE_SHIFT;

/*------------------------------------------------------
Check to see if Rx Message Buffer is full.
------------------------------------------------------*/
if( ( (uint32)FLEXCAN_RXMB_FULL == rx_code ) || ( (uint32)FLEXCAN_RXMB_OVERRUN == rx_code ) )
    {
    /*------------------------------------------------------
    Store Message ID.
    ------------------------------------------------------*/
    p_rmd->identifier   = p_flexcan_hw_regs->MB[rx_mb_index].ID & ( CAN_ID_EXT_MASK | CAN_ID_STD_MASK );
    p_rmd->identifier   = (( p_rmd->identifier ) >> CAN_ID_STD_SHIFT );

    /*------------------------------------------------------
    Get the message ID format
    ------------------------------------------------------*/
    p_rmd->format       = ( cs_temp & CAN_CS_IDE_MASK ) != 0U ? (uint8)CAN_EXTENDED_MSG_TYPE : (uint8)CAN_STANDARD_MSG_TYPE;

    /*------------------------------------------------------
    Get the message type.
    ------------------------------------------------------*/
    p_rmd->type         = ( cs_temp & CAN_CS_RTR_MASK ) != 0U ? (uint8)CAN_REMOTE_MSG_TYPE : (uint8)CAN_DATA_MSG_TYPE;

    /*------------------------------------------------------
    Get the message length.
    ------------------------------------------------------*/
    p_rmd->dlc          = (uint8)( ( cs_temp & CAN_CS_DLC_MASK ) >> CAN_CS_DLC_SHIFT );

    /*------------------------------------------------------
    Get the time stamp.
    ------------------------------------------------------*/
    p_rmd->timestamp    = (uint16)( ( cs_temp & CAN_CS_TIME_STAMP_MASK ) >> CAN_CS_TIME_STAMP_SHIFT );

    /*------------------------------------------------------
    Store Message Buffer Number
    ------------------------------------------------------*/
    p_rmd->vector       = rx_mb_index;

    /*------------------------------------------------------
    Store Message Payload.
    ------------------------------------------------------*/
    l_dlc_data = p_rmd->dlc;
    l_index    = l_dlc_data;
    switch( l_dlc_data )
        {
        case 8: p_rmd->data[--l_index] = (uint8)( p_flexcan_hw_regs->MB[rx_mb_index].WORD1 );
        case 7: p_rmd->data[--l_index] = (uint8)( p_flexcan_hw_regs->MB[rx_mb_index].WORD1 >> SHIFT_ONE_BYTE    );
        case 6: p_rmd->data[--l_index] = (uint8)( p_flexcan_hw_regs->MB[rx_mb_index].WORD1 >> SHIFT_TWO_BYTES   );
        case 5: p_rmd->data[--l_index] = (uint8)( p_flexcan_hw_regs->MB[rx_mb_index].WORD1 >> SHIFT_THREE_BYTES );
        case 4: p_rmd->data[--l_index] = (uint8)( p_flexcan_hw_regs->MB[rx_mb_index].WORD0 );
        case 3: p_rmd->data[--l_index] = (uint8)( p_flexcan_hw_regs->MB[rx_mb_index].WORD0 >> SHIFT_ONE_BYTE    );
        case 2: p_rmd->data[--l_index] = (uint8)( p_flexcan_hw_regs->MB[rx_mb_index].WORD0 >> SHIFT_TWO_BYTES   );
        case 1: p_rmd->data[--l_index] = (uint8)( p_flexcan_hw_regs->MB[rx_mb_index].WORD0 >> SHIFT_THREE_BYTES );

        default:
            break;
        }

    /*------------------------------------------------------
    Read free-running timer to unlock Rx Message Buffer.
    ------------------------------------------------------*/
    (void)p_flexcan_hw_regs->TIMER;

    l_ret_code = CAN_RC_SUCCESS;
    }
else
    {
    (void)p_flexcan_hw_regs->TIMER;

    l_ret_code = CAN_RC_FAIL;
    }

return l_ret_code ;
}

/*!*******************************************************************
*
* abort a message transmission in progress
*
* This function is called to abort a message transmission in progress.
*
*********************************************************************/
static void
can_hw_abort_tx_mb
    (
    flexcan_regs_t    * const p_flexcan_hw_regs, //!< [in] ptr to FlexCAN H/W registers
    can_hmb_t           const tx_mb_index        //!< [in] transmit Message Buffer
    )
{
can_hmb_mask_t l_u64mask = 1;

/*------------------------------------------------------
Message Buffer index is from 0~CAN_HMB_ALL, tx_index is from
CAN_HMB_TX_START + CAN_HMB_TX_START
------------------------------------------------------*/
if( ( tx_mb_index >= ( CAN_HMB_TX_ALL + CAN_HMB_TX_START ) ) ||
    ( tx_mb_index < CAN_HMB_TX_START ) )
    {
    return;
    }

/*------------------------------------------------------
Disable Message Buffer Interrupt.
------------------------------------------------------*/
flexcan_DisableMbInterrupts( p_flexcan_hw_regs, l_u64mask << tx_mb_index );

/*------------------------------------------------------
Clean Message Buffer.
------------------------------------------------------*/
flexcan_SetTxMbConfig( p_flexcan_hw_regs, tx_mb_index, TRUE );
}

/*!*******************************************************************
*
* @private
* FlexCAN controller frame transmission function
*
* This function transmits a message frame on the CAN bus using the
* message format and data defined by the CAN transmit data structure
* referenced by the input p_tmd pointer. The function looks for the
* next available transmit hardware Message Object and loads it with the
* message configuration and data.
*
* @return can_ret_code_t
* return code indicating success or failure
*
*********************************************************************/
can_ret_code_t
can_hw_transmit
    (
    can_hw_inst_t       const hw_inst,   //!< [in] CAN hardware instanc
    can_tmd_t   const * const p_tmd      //!< [in] pointer to transmit data structure
    )
{
flexcan_regs_t      *l_p_flexcan_regs   = NULL;
can_ret_code_t       l_ret_code         = CAN_RC_NOT_AVAILABLE;
uint32               l_tx_mb_code       = 0;
uint8                l_tx_mb_index      = 0;
uint8                l_tx_mb_timout_idx = 0;

/*------------------------------------------------------
Get Pointer to Hardware Instance Registers
------------------------------------------------------*/
l_p_flexcan_regs = can_hw_get_regs( hw_inst );

/*------------------------------------------------------
Check first if CAN is on line
------------------------------------------------------*/
if( ( can_hw_status[hw_inst] & CAN_HW_ONLINE ) != 0 )
    {
    /*------------------------------------------------------
    Find out a Message Buffer can be used for Transmission
    ------------------------------------------------------*/
    for( l_tx_mb_index = CAN_HMB_TX_START; l_tx_mb_index < CAN_HMB_ALL; l_tx_mb_index++ )
        {
        /*------------------------------------------------------
        Get the CODE of a Message Buffer
        ------------------------------------------------------*/
        l_tx_mb_code = flexcan_getTxMbCode( l_p_flexcan_regs, l_tx_mb_index );
        if( FLEXCAN_TXMB_INACTIVE == l_tx_mb_code )
            {
            break;
            }
        }

    /*------------------------------------------------------
    If there is no Tx Message Buffer to be used
    ------------------------------------------------------*/
    if( l_tx_mb_index == CAN_HMB_ALL )
        {
        return ( l_ret_code = CAN_RC_FAIL );
        }

    /*--------------------------------------------------
    Set the transmit timeout active for the indicated
    transmit Message Buffer and intialize the timer.
    --------------------------------------------------*/
    l_tx_mb_timout_idx = l_tx_mb_index - CAN_HMB_TX_START;
    can_hw_tx_timeout[hw_inst].active[l_tx_mb_timout_idx] = TRUE;
    can_hw_tx_timeout[hw_inst].timer[l_tx_mb_timout_idx]  = CAN_HW_N_AS_TIMEOUT_TICS;

    /*--------------------------------------------------
    Write the transmit the message,Tx Message Buffer number
    is started from CAN_HMB_TX_START,
    --------------------------------------------------*/
    l_ret_code = can_hw_write_tx_mb( hw_inst, l_p_flexcan_regs, p_tmd, l_tx_mb_index );
    }

return l_ret_code;
}

/*!*******************************************************************
*
* @private
* get received FlexCAN message
*
* This function is used to retrieve a received message from the
* specified receive message buffer.
*
* @return can_ret_code_t
* return code indicating success (CAN_RC_OK) or failure
*
*********************************************************************/
can_ret_code_t
can_hw_receive
    (
    can_hw_inst_t   const hw_inst,      //!< [in] CAN hardware instance
    can_rmd_t     * const p_rmd,        //!< [out] pointer to receive message buffer
    can_hmb_t       const rx_mb_index   //!< [in] Receive Message Buffer
    )
{
can_ret_code_t l_ret_code = CAN_RC_FAIL;

//TBD
return ( l_ret_code = CAN_RC_SUCCESS );
}

/*!*******************************************************************
*
* @private
* flush pending FlexCAN message transmissions
*
* This function aborts any pending message transmissions in the
* indicated hardware transmit Message Buffer and in the specified CAN
* controller instance.
*
*********************************************************************/
void can_hw_tx_flush
    (
    can_hw_inst_t     const hw_inst           //!< [in] CAN hardware instance
    )
{
flexcan_regs_t *l_p_flexcan_regs   = NULL;
uint8           l_tx_mb_index      = 0;
uint8           l_tx_mb_timout_idx = 0;

/*------------------------------------------------------
Get Pointer to Hardware Instance Registers
------------------------------------------------------*/
l_p_flexcan_regs = can_hw_get_regs( hw_inst );

for( l_tx_mb_index = CAN_HMB_TX_START; l_tx_mb_index < CAN_HMB_ALL; l_tx_mb_index++ )
    {
    /*------------------------------------------------------
    Abort any transmit requests in progress.
    ------------------------------------------------------*/
    flexcan_SetTxMbConfig( l_p_flexcan_regs, l_tx_mb_index, TRUE );

    /*------------------------------------------------------
    Clear all transmit timeout active Message Object
    ------------------------------------------------------*/
    l_tx_mb_timout_idx = l_tx_mb_index - CAN_HMB_TX_START;
    can_hw_tx_timeout[hw_inst].active[l_tx_mb_timout_idx] = FALSE;

    /*------------------------------------------------------
    Zero the TMD Message Handles
    ------------------------------------------------------*/
    can_hw_tx_msg_handle[hw_inst][l_tx_mb_timout_idx]     = 0;
    }
}

/*!*******************************************************************
*
* @private
* flush received FlexCAN message(s)
*
* This function flushes pending message receptions from the
* specified receive FlexCAN Message Buffers and CAN controller instance.
*
*********************************************************************/
void
can_hw_rx_flush
    (
    can_hw_inst_t     const hw_inst           //!< [in] CAN hardware instance
    )
{
//TBD
}

/*!*******************************************************************
*
* Init Tx Message buffers
*
* This function is used to initialize all of the Message Buffers that
* will be used for transmission
*
*********************************************************************/
static void
can_hw_init_tx_mbs
    (
    flexcan_regs_t        * const p_flexcan_hw_regs, //!< [in] ptr to FlexCAN H/W registers
    flexcan_tx_mb_config_t const* P_tx_mb_init_config
    )
{
uint8_t  l_index             = 0;
uint8_t  l_tx_mb_start_idx   = 0;
uint8_t  l_tx_mb_num         = 0;
uint64_t l_u64Msk            = 1;

/*------------------------------------------------------
Get Message Buffer configuration data
------------------------------------------------------*/
l_tx_mb_start_idx = P_tx_mb_init_config->can_tx_mb_start_idx;
l_tx_mb_num       = P_tx_mb_init_config->can_tx_mb_num;

/*------------------------------------------------------
Set all the Message Buffers.
------------------------------------------------------*/
for( l_index = l_tx_mb_start_idx; l_index < ( l_tx_mb_num + l_tx_mb_start_idx ); l_index++ )
    {
    /*------------------------------------------------------
    Clean Message Buffers.
    ------------------------------------------------------*/
    flexcan_SetTxMbConfig( p_flexcan_hw_regs, l_index, TRUE );

    /*------------------------------------------------------
    Set interrupts of Message Buffers.
    ------------------------------------------------------*/
    flexcan_EnableMbInterrupts( p_flexcan_hw_regs, ( l_u64Msk << l_index ) );
    }
}

/*!*******************************************************************
*
* Init Rx Message buffer
*
* This function is used to initialize all of the Message Buffers that
* will be used for receiving
*
*********************************************************************/
static void
can_hw_init_rx_mbs
    (
    flexcan_regs_t         * const p_flexcan_hw_regs, //!< [in] ptr to FlexCAN H/W registers
    flexcan_rx_mb_config_t  const *p_rx_mb_init_config
    )
{
uint8_t  l_index             = 0;
uint64_t l_u64Msk            = 1;
uint32_t l_idmsk             = 0;

/*------------------------------------------------------
Set all the APP Message Buffers.
------------------------------------------------------*/
for( l_index = 0; l_index < CAN_HMB_RX_ALL; l_index++ )
    {
    /*------------------------------------------------------
    Init Rx Message Buffers.
    ------------------------------------------------------*/
    flexcan_SetRxMbConfig( p_flexcan_hw_regs, l_index, &p_rx_mb_init_config[l_index], TRUE );

    /*------------------------------------------------------
    Set interrupts of Message Buffer.
    ------------------------------------------------------*/
    flexcan_EnableMbInterrupts( p_flexcan_hw_regs, ( l_u64Msk << l_index ) );
    }

/*------------------------------------------------------
Set all the Diag Message Buffers.
------------------------------------------------------*/
for( l_index = CAN_HMB_RX_DIAG_START; l_index < ( CAN_HMB_RX_DIAG_ALL ); l_index++ )
    {
    /*------------------------------------------------------
    Init Rx Message Buffers Individual Masks.
    ------------------------------------------------------*/
    l_idmsk = p_rx_mb_init_config[l_index].idmsk;
    flexcan_SetRxIndividualMask( p_flexcan_hw_regs, l_index, l_idmsk );
    }
}

/*!*******************************************************************
*
* get pointer to FlexCAN initialization data
*
* This function checks the pointer to initialization data that is
* passed to it. If the passed pointer is NULL then the pointer to the
* default initialization data is returned. If p_init_data pointer
* passed into this function is not NULL this function assumes the
* pointer points to a valid initializaton data structure and returns
* the same pointer back as the returned pointer value. In this case
* the burden is on the calling function to point to a valid
* initializaton data structure.
*
* return pointer to FlexCAN initialization data
*
*********************************************************************/
static flexcan_hw_init_t const *
can_hw_get_init_data
    (
    can_hw_inst_t                    hw_inst,    //!< [in] CAN hardware instance
    flexcan_hw_init_t  const * const p_init_data //!< [in, out] ptr to FlexCAN init data
    )
{
flexcan_hw_init_t const * l_p_init = NULL;

/*------------------------------------------------------
Check for a NULL init data pointer
------------------------------------------------------*/
if( NULL == p_init_data )
    {
    /*------------------------------------------------------
    Check that a valid hardware instance is specified
    ------------------------------------------------------*/
    if( hw_inst < CAN_NUM_INSTANCES )
        {
        /*--------------------------------------------------
        Point to the default Initialization Data
        --------------------------------------------------*/
        l_p_init = p_can_hw_init_data[hw_inst];
        }
    }
else
    {
    /*------------------------------------------------------
    Assume the passed in pointer points to valid init data
    structure and return the passed in value
    ------------------------------------------------------*/
    l_p_init = p_init_data;
    }

return l_p_init;
}

/*!*******************************************************************
*
* Set CAN root clock
*
*********************************************************************/
static void
can_hw_set_root_clk
    (
    void
    )
{
clock_root_config_t rootCfg = {0};
rootCfg.mux                 = FLEXCAN_CLOCK_SOURCE_SELECT;
rootCfg.div                 = FLEXCAN_CLOCK_SOURCE_DIVIDER;
CLOCK_SetRootClock(kCLOCK_Root_Can2, &rootCfg);
}

/*!*******************************************************************
* brief Gets the default configuration structure.
*
* This function initializes the FlexCAN configuration structure to default
* values. The default
* values are as follows.
*   flexcanConfig->clkSrc                  = FLEXCAN_CLKSRC_OSC;
*   flexcanConfig->baudRate                = 1000000U;
*   flexcanConfig->maxMbNum                = 64;
*   flexcanConfig->enableLoopBack          = false;
*   flexcanConfig->enableSelfWakeup        = false;
*   flexcanConfig->enableIndividMask       = false;
*   flexcanConfig->disableSelfReception    = false;
*   flexcanConfig->enableListenOnlyMode    = false;
*   flexcanConfig->enableDoze              = false;
*   flexcanConfig.timingConfig             = timingConfig;
*
* param pConfig Pointer to the FlexCAN configuration structure.
*
*********************************************************************/
static void
can_hw_get_def_config
    (
    flexcan_config_t *p_config
    )
{
/*------------------------------------------------------
Assertion.
------------------------------------------------------*/
assert( NULL != p_config );

/*------------------------------------------------------
Initializes the configure structure to zero.
------------------------------------------------------*/
(void)memset( p_config, 0, sizeof( *p_config ) );

/*------------------------------------------------------
Initialize FlexCAN Module config struct with default value.
------------------------------------------------------*/
p_config->clkSrc               = FLEXCAN_CLKSRC_OSC;
p_config->baudRate             = 500000U;
p_config->maxMbNum             = CAN_HMB_ALL;
p_config->enableLoopBack       = false;
p_config->enableTimerSync      = true;
p_config->enableSelfWakeup     = false;
p_config->wakeupSrc            = FLEXCAN_WAKEUP_SRC_UNFILTERED;
p_config->enableIndividMask    = true;
p_config->disableSelfReception = false;
p_config->enableListenOnlyMode = false;
p_config->enableDoze           = false;

/*------------------------------------------------------
Default protocol timing configuration, time quantum is 10
------------------------------------------------------*/
p_config->timingConfig.phaseSeg1  = 3;
p_config->timingConfig.phaseSeg2  = 2;
p_config->timingConfig.propSeg    = 1;
p_config->timingConfig.rJumpwidth = 1;
}

/*!*******************************************************************
* @brief Calculates the segment values for a single bit time for classical CAN
*
* @param baudRate The data speed in bps
* @param tqNum Number of time quantas per bit
* @param pTimingConfig Pointer to the FlexCAN timing configuration structure.
*
* @return TRUE if Calculates the segment success, FALSE if Calculates the
* segment success
*
*********************************************************************/
static bool
can_hw_flexcan_GetSegments
    (
    uint32_t                 baudRate,
    uint32_t                 tqNum,
    flexcan_timing_config_t *pTimingConfig
    )
{
uint32_t p1;
uint32_t ideal_sp;
bool     fgRet = false;

/*------------------------------------------------------
Get ideal sample point. For the Bit field in CTRL1 register
can't calculate higher ideal SP, we set it as the lowest one(75%).
------------------------------------------------------*/
ideal_sp = IDEAL_SP_LOW;

/*------------------------------------------------------
Distribute time quanta.
------------------------------------------------------*/
p1 = tqNum * (uint32_t)ideal_sp;
pTimingConfig->propSeg = (uint8_t)( p1 / (uint32_t)IDEAL_SP_FACTOR - 2U );
if( pTimingConfig->propSeg <= ( MAX_PSEG1 + MAX_PROPSEG ) )
    {
    if( pTimingConfig->propSeg > MAX_PROPSEG )
        {
        pTimingConfig->phaseSeg1 = pTimingConfig->propSeg - MAX_PROPSEG;
        pTimingConfig->propSeg   = MAX_PROPSEG;
        }
    else
        {
        pTimingConfig->phaseSeg1 = 0;
        }

    /*------------------------------------------------------
    The value of prog Seg should be not larger than tqNum -4U.
    ------------------------------------------------------*/
    if( ( pTimingConfig->propSeg + pTimingConfig->phaseSeg1 ) < ( (uint8_t)tqNum - 4U ) )
        {
        pTimingConfig->phaseSeg2 = (uint8_t)tqNum - ( pTimingConfig->phaseSeg1 + pTimingConfig->propSeg + 4U );
        if( pTimingConfig->phaseSeg2 <= MAX_PSEG1 )
            {
            if( ( pTimingConfig->phaseSeg1 < pTimingConfig->phaseSeg2 ) &&
                ( pTimingConfig->propSeg > ( pTimingConfig->phaseSeg2 - pTimingConfig->phaseSeg1 ) ) )
                {
                pTimingConfig->propSeg -= ( pTimingConfig->phaseSeg2 - pTimingConfig->phaseSeg1 );
                pTimingConfig->phaseSeg1 = pTimingConfig->phaseSeg2;
                }

            /*------------------------------------------------------
            Subtract one TQ for sync seg.sjw is 20% of total TQ,
            rounded to nearest int.
            ------------------------------------------------------*/
            pTimingConfig->rJumpwidth = ( (uint8_t)tqNum + 4U ) / 5U - 1U;
            /*------------------------------------------------------
            The max tqNum for CBT will reach to 129, ERJW would not
            be larger than 26.Considering that max ERJW is 31,
            rJumpwidth will always be smaller than MAX_ERJW.
            ------------------------------------------------------*/
            if( pTimingConfig->rJumpwidth > MAX_RJW )
                {
                pTimingConfig->rJumpwidth = MAX_RJW;
                }

            fgRet = true;
            }
        }
    }

return fgRet;
}

/*!*******************************************************************
* @brief Calculates the improved timing values by specific baudrates
* for classical CAN
*
* @param baudRate  The classical CAN speed in bps defined by user
* @param sourceClock_Hz The Source clock data speed in bps. Zero to
* disable baudrate switching
* @param pTimingConfig Pointer to the FlexCAN timing configuration
* structure.
*
* @return TRUE if timing configuration found, FALSE if failed to find
* configuration
*
*********************************************************************/
static bool
can_hw_flexcan_calc_Improved_TimingValues
    (
    uint32_t                 baudRate,
    uint32_t                 sourceClock_Hz,
    flexcan_timing_config_t *pTimingConfig
    )
{
/*------------------------------------------------------
observe baud rate maximums.
------------------------------------------------------*/
assert( baudRate <= MAX_CAN_BAUDRATE  );

/*------------------------------------------------------
the clock is tqNumb x baudRateFD,and Numbers of TQ.
------------------------------------------------------*/
uint32_t clk;
uint32_t tqNum;
bool     fgRet = false;

/*------------------------------------------------------
Auto Improved Protocal timing for CTRL1.
------------------------------------------------------*/
tqNum = CTRL1_MAX_TIME_QUANTA;
do
    {
    clk = baudRate * tqNum;
    if( clk > sourceClock_Hz )
        {
        /*------------------------------------------------------
        tqNum too large, clk has been exceed sourceClock_Hz.
        ------------------------------------------------------*/
        continue;
        }

    if( ( sourceClock_Hz / clk * clk ) != sourceClock_Hz )
        {
        /*------------------------------------------------------
        Non-supporting: the frequency of clock source is not
        divisible by target baud rate, the user should change a
        divisible baud rate.
        ------------------------------------------------------*/
        continue;
        }

    pTimingConfig->preDivider = (uint16_t)( sourceClock_Hz / clk ) - 1U;
    if( pTimingConfig->preDivider > MAX_PRESDIV )
        {
        /*------------------------------------------------------
        The frequency of source clock is too large or the baud
        rate is too small, the pre-divider could not handle it.
        ------------------------------------------------------*/
        break;
        }

        /*------------------------------------------------------
        Try to get the best timing configuration.
        ------------------------------------------------------*/
    if( can_hw_flexcan_GetSegments( baudRate, tqNum, pTimingConfig ) )
        {
        fgRet = true;
        break;
        }
    }while ( --tqNum >= CTRL1_MIN_TIME_QUANTA );

return fgRet;
}

/*!*******************************************************************
* brief Initializes a FlexCAN instance.
*
* This function initializes the FlexCAN module with user-defined settings.
* This example shows how to set up the flexcan_config_t parameters and how
* to call the FLEXCAN_Init function by passing in these parameters.
*  code
*   flexcan_config_t flexcanConfig;
*   flexcanConfig.clkSrc               = kFLEXCAN_ClkSrc0;
*   flexcanConfig.baudRate             = 1000000U;
*   flexcanConfig.maxMbNum             = 16;
*   flexcanConfig.enableLoopBack       = false;
*   flexcanConfig.enableSelfWakeup     = false;
*   flexcanConfig.enableIndividMask    = false;
*   flexcanConfig.disableSelfReception = false;
*   flexcanConfig.enableListenOnlyMode = false;
*   flexcanConfig.enableDoze           = false;
*   flexcanConfig.timingConfig         = timingConfig;
*   FLEXCAN_Init(CAN0, &flexcanConfig, 8000000UL);
*   endcode
*
* param base FlexCAN peripheral base address.
* param pConfig Pointer to the user-defined configuration structure.
* param sourceClock_Hz FlexCAN Protocol Engine clock source frequency in Hz.

*
*********************************************************************/
static void
can_hw_init_module
        (
        can_hw_inst_t           hw_inst,           //!< [in] CAN hardware instance
        flexcan_regs_t  *const  p_flexcan_hw_regs, //!< [in] ptr to FlexCAN H/W registers
        flexcan_config_t       *pConfig,
        uint32_t                sourceClock_Hz
        )
{
assert( NULL != pConfig );
assert( ( pConfig->maxMbNum > 0U ) &&
        ( pConfig->maxMbNum <= (uint8_t)FSL_FEATURE_FLEXCAN_HAS_MESSAGE_BUFFER_MAX_NUMBERn( p_flexcan_hw_regs ) ) );

uint32_t mcrTemp;
uint32_t ctrl1Temp;

/*------------------------------------------------------
Enable FlexCAN clock.
------------------------------------------------------*/
(void)CLOCK_EnableClock( s_flexcanClock[hw_inst] );

/*------------------------------------------------------
* Check the CAN clock in this device whether affected by
* Other clock gate.If it affected, we'd better to change
* other clock source,If user insist on using that clock
* source, user need open these gate at same time,In this
* scene, User need to care the power consumption.
------------------------------------------------------*/
assert( CAN_CLOCK_CHECK_NO_AFFECTS );

#if defined( CAN_CTRL1_CLKSRC_MASK )
#if( defined( FSL_FEATURE_FLEXCAN_SUPPORT_ENGINE_CLK_SEL_REMOVE ) && FSL_FEATURE_FLEXCAN_SUPPORT_ENGINE_CLK_SEL_REMOVE )
    if(0 == FSL_FEATURE_FLEXCAN_INSTANCE_SUPPORT_ENGINE_CLK_SEL_REMOVEn( p_flexcan_hw_regs ) )
#endif
        {
        /*------------------------------------------------------
        Disable FlexCAN Module.
        ------------------------------------------------------*/
        flexcan_Enable( p_flexcan_hw_regs, false );

        /*------------------------------------------------------
        Protocol-Engine clock source selection, This bit must be
        set when FlexCAN Module in Disable Mode.
        ------------------------------------------------------*/
        p_flexcan_hw_regs->CTRL1 = ( FLEXCAN_CLKSRC0 == pConfig->clkSrc ) ? ( p_flexcan_hw_regs->CTRL1 & ~CAN_CTRL1_CLKSRC_MASK ) :
                                                                            ( p_flexcan_hw_regs->CTRL1 | CAN_CTRL1_CLKSRC_MASK  );
        }
#endif

/*------------------------------------------------------
Enable FlexCAN Module for configuration.
------------------------------------------------------*/
flexcan_Enable( p_flexcan_hw_regs, true );

/*------------------------------------------------------
Reset to known status.
------------------------------------------------------*/
flexcan_Reset( p_flexcan_hw_regs );

/*------------------------------------------------------
Save current CTRL1 value and enable to enter Freeze mode
(enabled by default).
------------------------------------------------------*/
ctrl1Temp = p_flexcan_hw_regs->CTRL1;

/*------------------------------------------------------
Save current MCR value and enable to enter Freeze mode
(enabled by default).
------------------------------------------------------*/
mcrTemp   = p_flexcan_hw_regs->MCR;

/*------------------------------------------------------
Enable Loop Back Mode?
------------------------------------------------------*/
ctrl1Temp = ( pConfig->enableLoopBack ) ? ( ctrl1Temp | CAN_CTRL1_LPB_MASK ) : ( ctrl1Temp & ~CAN_CTRL1_LPB_MASK );

/*------------------------------------------------------
Enable Timer Sync?
------------------------------------------------------*/
ctrl1Temp = ( pConfig->enableTimerSync ) ? ( ctrl1Temp | CAN_CTRL1_TSYN_MASK ) : (  ctrl1Temp & ~CAN_CTRL1_TSYN_MASK );

/*------------------------------------------------------
Enable Listen Only Mode?
------------------------------------------------------*/
ctrl1Temp = ( pConfig->enableListenOnlyMode ) ? ctrl1Temp | CAN_CTRL1_LOM_MASK : ctrl1Temp & ~CAN_CTRL1_LOM_MASK;

/*------------------------------------------------------
Set the maximum number of Message Buffers
------------------------------------------------------*/
mcrTemp   = ( mcrTemp & ~CAN_MCR_MAXMB_MASK ) | CAN_MCR_MAXMB( (uint32_t)pConfig->maxMbNum - 1U );

/*------------------------------------------------------
Enable Self Wake Up Mode and configure the wake up source.
------------------------------------------------------*/
mcrTemp   = ( pConfig->enableSelfWakeup ) ? ( mcrTemp | CAN_MCR_SLFWAK_MASK ) : ( mcrTemp & ~CAN_MCR_SLFWAK_MASK );
mcrTemp   = ( FLEXCAN_WAKEUP_SRC_FILTERED == pConfig->wakeupSrc ) ? ( mcrTemp | CAN_MCR_WAKSRC_MASK ) : ( mcrTemp & ~CAN_MCR_WAKSRC_MASK );

/*------------------------------------------------------
Enable Individual Rx Masking?
------------------------------------------------------*/
mcrTemp   = ( pConfig->enableIndividMask ) ? ( mcrTemp | CAN_MCR_IRMQ_MASK ) : ( mcrTemp & ~CAN_MCR_IRMQ_MASK );

/*------------------------------------------------------
Disable Self Reception?
------------------------------------------------------*/
mcrTemp   = ( pConfig->disableSelfReception ) ? mcrTemp | CAN_MCR_SRXDIS_MASK : mcrTemp & ~CAN_MCR_SRXDIS_MASK;

#if( defined( FSL_FEATURE_FLEXCAN_HAS_DOZE_MODE_SUPPORT ) && FSL_FEATURE_FLEXCAN_HAS_DOZE_MODE_SUPPORT )
    if( 0 != FSL_FEATURE_FLEXCAN_INSTANCE_HAS_DOZE_MODE_SUPPORTn( p_flexcan_hw_regs ) )
    {
    /*------------------------------------------------------
    Enable Doze Mode?
    ------------------------------------------------------*/
    mcrTemp = ( pConfig->enableDoze ) ? ( mcrTemp | CAN_MCR_DOZE_MASK ) : ( mcrTemp & ~CAN_MCR_DOZE_MASK );
    }
#endif

/*------------------------------------------------------
Write back CTRL1 Configuration to register.
------------------------------------------------------*/
p_flexcan_hw_regs->CTRL1 = ctrl1Temp;

#if( defined( FSL_FEATURE_FLEXCAN_HAS_MEMORY_ERROR_CONTROL ) && FSL_FEATURE_FLEXCAN_HAS_MEMORY_ERROR_CONTROL )
    /*------------------------------------------------------
    Enable to update in MCER.
    ------------------------------------------------------*/
    p_flexcan_hw_regs->CTRL2 |= CAN_CTRL2_ECRWRE_MASK;
    p_flexcan_hw_regs->MECR  &= ~CAN_MECR_ECRWRDIS_MASK;
#endif

/*------------------------------------------------------
Write back MCR Configuration to register.
------------------------------------------------------*/
p_flexcan_hw_regs->MCR = mcrTemp;

/*------------------------------------------------------
Baud Rate Configuration.
------------------------------------------------------*/
flexcan_SetBaudRate( p_flexcan_hw_regs, sourceClock_Hz, pConfig->baudRate, &( pConfig->timingConfig ) );
}

/*!*******************************************************************
*
* @private
* initialize the FlexCAN controller
*
* This function initializes and enables a FlexCAN controller instance.
* The CAN controller iniitialization data source depends on whether
* the initialization vector pointer is a NULL pointer or points to a
* valid user defined initialization data structure. Passing a NULL
* initialization pointer implies the default initialization data
* structure is to be used.
*
* The initialization mode determines whether all pending messages
* are flushed prior to initialization and all software variables and
* queues are initialized to zero (COLD INIT) or whether all existing
* data is left intact (WARM INIT).
*
* @return can_ret_code_t
* return code indicating success or failure
*
*********************************************************************/
can_ret_code_t
can_hw_init
    (
    can_hw_inst_t       const hw_inst,          //!< [in] CAN hardware instance
    can_init_mode_t     const init_mode,        //!< [in] initialization mode (cold or warm init)
    void        const * const p_init_vector     //!< [in] pointer to initialization data structure
    )
{
can_ret_code_t                l_ret_code          = CAN_RC_FAIL;
flexcan_regs_t               *l_p_flexcan_regs    = NULL;
flexcan_hw_init_t      const *l_p_init_vector     = NULL;
flexcan_tx_mb_config_t const *l_p_mbs_tx_config   = NULL;
flexcan_rx_mb_config_t const *l_p_mbs_rx_config   = NULL;
boolean                       l_esr_bus_off       = FALSE;
flexcan_config_t              l_def_config        = { 0 };
flexcan_timing_config_t       l_timing_config     = { 0 };

/*------------------------------------------------------
Get Pointer to Hardware Instance Registers
------------------------------------------------------*/
l_p_flexcan_regs = can_hw_get_regs( hw_inst );

/*------------------------------------------------------
Get Pointer to Initialization Data
------------------------------------------------------*/
l_p_init_vector = can_hw_get_init_data( hw_inst, NULL );

l_p_mbs_tx_config   = &( l_p_init_vector->mb_tx_config    );
l_p_mbs_rx_config   = &( l_p_init_vector->mb_rx_config[0] );

/*------------------------------------------------------
Initialize CAN Controller Instance Variables
------------------------------------------------------*/
can_hw_status[hw_inst]       = 0;
can_hw_error_status[hw_inst] = 0;

/*------------------------------------------------------
Initialize CAN Initialization Bus OFF Recovery Variables
------------------------------------------------------*/
can_hw_busoff_recovery_pndg[hw_inst]          = FALSE;
p_can_hw_busoff_recovery_init_vector[hw_inst] = NULL;

/*------------------------------------------------------
Default the Transmit Timeout feature to disabled.
------------------------------------------------------*/
can_hw_tx_timeout[hw_inst].enable = TRUE;

/*------------------------------------------------------
Make CAN hardware enter Initialization mode
------------------------------------------------------*/
can_hw_enter_init_mode( hw_inst );

/*------------------------------------------------------
Enter freezemode before initialization
------------------------------------------------------*/
flexcan_EnterFreezeMode( l_p_flexcan_regs );

/*------------------------------------------------------
Disable All CAN Interrupts
------------------------------------------------------*/
can_hw_disable_interrupts( hw_inst );

/*------------------------------------------------------
Set CAN root clock
------------------------------------------------------*/
can_hw_set_root_clk();

/*------------------------------------------------------
Get CAN default config
------------------------------------------------------*/
can_hw_get_def_config( &l_def_config );
memset( &l_timing_config, 0, sizeof(flexcan_timing_config_t) );
if ( can_hw_flexcan_calc_Improved_TimingValues( l_def_config.baudRate, FLEX_CAN_CLK_FREQ, &l_timing_config ) )
    {
    /*------------------------------------------------------
    Update the improved timing configuration
    ------------------------------------------------------*/
    memcpy( &( l_def_config.timingConfig ), &l_timing_config , sizeof(flexcan_timing_config_t) );
    }
else
    {
    PRINTF("No found Improved Timing Configuration.\r\n");
    }

/*------------------------------------------------------
Init CAN module including CTRL1 MCR and Baudrate
------------------------------------------------------*/
can_hw_init_module( hw_inst, l_p_flexcan_regs, &l_def_config, FLEX_CAN_CLK_FREQ );

/*------------------------------------------------------
A cold init flushes all pending messages (tx and rx)
------------------------------------------------------*/
if( CAN_INIT_MODE_COLD == init_mode )
    {
    can_hw_init_tx_mbs( l_p_flexcan_regs, l_p_mbs_tx_config );
    can_hw_init_rx_mbs( l_p_flexcan_regs, l_p_mbs_rx_config );
    }

/*------------------------------------------------------
Make CAN hardware exit Initialization mode
------------------------------------------------------*/
can_hw_exit_init_mode( hw_inst );
l_ret_code = CAN_RC_OK;

/*----------------------------------------------
Wait for the FlexCAN controller to synchronize to
the CAN bus before enabling interrupts. If the
FlexCAN controller is not allowed to synchronize
after a Bus OFF event, a spurious Bus OFF
interrupt is generated. CAN bus synchronization
after a Bus OFF event requires waiting for 128
consecutive inter-frame idle periods, which are
11 bit periods long. This can take 10's of
milliseconds to complete, depending on the CAN
bit rate.
----------------------------------------------*/
l_esr_bus_off = ( ( l_p_flexcan_regs->ESR1 & CAN_ESR1_BOFFINT_MASK ) != 0 );
if( l_esr_bus_off != FALSE )
    {
    /*----------------------------------------------
    Save flag for initialization Bus OFF recovery
    pending. Save the initialization vector for
    subsequent processing in the periodic task.
    ----------------------------------------------*/
    can_hw_busoff_recovery_pndg[hw_inst]          = TRUE;
    p_can_hw_busoff_recovery_init_vector[hw_inst] = l_p_init_vector;
    l_ret_code = CAN_RC_BUSOFF_INIT_PNDG;
    }

/*------------------------------------------------------
Enable All CAN Interrupts
------------------------------------------------------*/
can_hw_enable_interrupts( hw_inst );

/*------------------------------------------------------
Exit freezemode before initialization
------------------------------------------------------*/
flexcan_ExitFreezeMode( l_p_flexcan_regs );

/*------------------------------------------
Set Hardware Status INIT OK Bit
------------------------------------------*/
can_hw_set_status_bit( hw_inst, CAN_HW_INITOK );

return l_ret_code;
}

/*!*******************************************************************
*
* @private
* enable transmit timeout
*
* This function is called to enable the CAN transmit timeout feature.
*
*********************************************************************/
void
can_hw_enable_transmit_timeout
    (
    can_hw_inst_t   const hw_inst       //!< [in] CAN hardware instance
    )
{
can_hw_tx_timeout[hw_inst].enable = TRUE;
}

/*!*******************************************************************
*
* @private
* disable transmit timeout
*
* This function is called to disable the CAN transmit timeout feature.
*
*********************************************************************/
void
can_hw_disable_transmit_timeout
    (
    can_hw_inst_t   const hw_inst       //!< [in] CAN hardware instance
    )
{
can_hw_tx_timeout[hw_inst].enable = FALSE;
}

/*!*******************************************************************
*
* @private
* enable transmit timeout
*
* This function is called periodicallly to manage the transmit timeout
* feature.
*
*********************************************************************/
void can_hw_periodic
    (
    can_hw_inst_t   const hw_inst       //!< [in] CAN hardware instance
    )
{
flexcan_regs_t   *l_p_flexcan_regs  = NULL;
boolean           l_esr_bus_off     = 0;
uint8             l_i_tx_index      = 0;
boolean           l_tx_active       = FALSE;
can_tmh_t         l_tmh             = 0;

/*------------------------------------------------------
If the timeout feature is enabled, check all of the
Message Buffer timers for a timeout event.
------------------------------------------------------*/
if( can_hw_tx_timeout[hw_inst].enable != FALSE )
    {
    /*------------------------------------------------------
    Get Pointer to Hardware Instance Registers
    ------------------------------------------------------*/
    l_p_flexcan_regs = can_hw_get_regs( hw_inst );

    /*------------------------------------------------------
    Check all Tx Message Buffers
    ------------------------------------------------------*/
    for( l_i_tx_index = 0; l_i_tx_index < MAX_TX_OBJECTS; l_i_tx_index++ )
        {
        l_tx_active = can_hw_tx_timeout[hw_inst].active[l_i_tx_index];
        l_tmh       = can_hw_tx_msg_handle[hw_inst][l_i_tx_index];

        if( l_tx_active != FALSE )
            {
            if( can_hw_tx_timeout[hw_inst].timer[l_i_tx_index] != 0 )
                {
                ( can_hw_tx_timeout[hw_inst].timer[l_i_tx_index] )--;

                /*------------------------------------------------------
                If a timeout is detected, abort the pending transmission
                and notify the timeout event.
                ------------------------------------------------------*/
                if( 0 == can_hw_tx_timeout[hw_inst].timer[l_i_tx_index] )
                    {
                    l_i_tx_index += CAN_HMB_TX_START;
                    can_hw_abort_tx_mb( l_p_flexcan_regs, l_i_tx_index );
                    can_hook_transmit_timeout( hw_inst, l_tmh );
                    }
                }
            }
        }
    }

/*------------------------------------------------------
Check for Init BusOFF Recovery Pending
------------------------------------------------------*/
if( can_hw_busoff_recovery_pndg[hw_inst] != FALSE )
    {
    /*------------------------------------------------------
    Get Pointer to Hardware Instance Registers
    ------------------------------------------------------*/
    l_esr_bus_off = ( ( l_p_flexcan_regs->ESR1 & FLEXCAN_BUSOFF_INT_FLAG ) != 0 );

    if( FALSE == l_esr_bus_off )
        {
        can_hw_busoff_recovery_pndg[hw_inst] = FALSE;

        /*------------------------------------------
        Set Hardware Status INIT OK Bit
        ------------------------------------------*/
        can_hw_set_status_bit( hw_inst, CAN_HW_INITOK );

        /*------------------------------------------
        Notify the driver of successful recovery
        ------------------------------------------*/
        can_hook_init_busoff_recovery( hw_inst );
        }
    }
}

/*!*******************************************************************
*
* test for and process CAN bus errors
*
* This function tests for CAN bus errors and processes the identified
* errors.
*
*********************************************************************/
static void
can_hw_bus_errors_isr_hndlr
    (
    can_hw_inst_t   const hw_inst       //!< [in] CAN hardware instance
    )
{
flexcan_regs_t   *l_p_flexcan_regs = NULL;
uint32            l_esr_status     = 0;
uint32            l_mcr            = 0;
uint8             l_tx_err_cnt     = 0;
uint8             l_rx_err_cnt     = 0;
uint8             l_flt_conf       = 0;

/*------------------------------------------------------
Get Pointer to Hardware Instance Registers
------------------------------------------------------*/
l_p_flexcan_regs = can_hw_get_regs( hw_inst );

/*------------------------------------------------------
Read ESR1 (Error and Status Register) and ECR
(Error Counter) for error condition handling
------------------------------------------------------*/
l_esr_status    = l_p_flexcan_regs->ESR1;
l_mcr           = l_p_flexcan_regs->MCR;

/*------------------------------------------------------
Get the values of Tx and Rx error counters
------------------------------------------------------*/
flexcan_GetBusErrCount( l_p_flexcan_regs, &l_tx_err_cnt, &l_rx_err_cnt );

l_flt_conf = (uint8)( ( l_esr_status & CAN_ESR1_FLTCONF_MASK ) >> CAN_ESR1_FLTCONF_SHIFT );

/*------------------------------------------------------
Check for Error Warning Level
------------------------------------------------------*/
if( 0U != ( l_esr_status & (uint32_t)FLEXCAN_TXWARNING_INT_FLAG ) )
    {
    can_hw_error_status[hw_inst] |= CAN_HW_ERR_TX_WARNING;

    /*------------------------------------------------------
    Check for Error Warning interrupt enabled
    ------------------------------------------------------*/
    if( ( l_mcr & CAN_MCR_WRNEN_MASK ) != 0 )
        {
        if( l_tx_err_cnt >= CAN_ERROR_WARNING_COUNT )
            {
            can_hook_exception( hw_inst, CAN_EX_TX_ERROR_WARNING );
            }
        }
    }

if ( 0U != ( l_esr_status & (uint32_t)FLEXCAN_RXWARNING_INT_FLAG ) )
    {
    can_hw_error_status[hw_inst] |= CAN_HW_ERR_RX_WARNING;

    /*------------------------------------------------------
    Check for Error Warning interrupt enabled
    ------------------------------------------------------*/
    if( ( l_mcr & CAN_MCR_WRNEN_MASK ) != 0 )
        {
        if( l_rx_err_cnt >= CAN_ERROR_WARNING_COUNT )
            {
            can_hook_exception( hw_inst, CAN_EX_RX_ERROR_WARNING );
            }
        }
    }

/*------------------------------------------------------
Check for Error Active Level
------------------------------------------------------*/
if( 0 != ( can_hw_error_status[hw_inst] & CAN_HW_ERR_TX_PASSIVE ) )
    {
    /*------------------------------------------------------
    Check for Error interrupt enabled
    ------------------------------------------------------*/
    if( ( l_esr_status & CAN_ESR1_ERRINT_MASK ) != 0 )
        {
        if( l_tx_err_cnt < CAN_ERROR_ACTIVE_COUNT )
            {
            /*------------------------------------------------------
            Clear TX Error Passive
            ------------------------------------------------------*/
            can_hw_error_status[hw_inst] &= ( ~CAN_HW_ERR_TX_PASSIVE );

            /*------------------------------------------------------
            Set TX Error Active
            ------------------------------------------------------*/
            can_hw_error_status[hw_inst] |= ( ~CAN_HW_ERR_TX_ACTIVE );

            can_hook_exception( hw_inst, CAN_EX_TX_ERROR_ACTIVE );
            }
        }
    }

if( 0 != ( can_hw_error_status[hw_inst] & CAN_HW_ERR_RX_PASSIVE ) )
    {
    /*------------------------------------------------------
    Check for Error interrupt enabled
    ------------------------------------------------------*/
    if( ( l_esr_status & CAN_ESR1_ERRINT_MASK ) != 0 )
        {
        if( l_rx_err_cnt < CAN_ERROR_ACTIVE_COUNT )
            {
            /*------------------------------------------------------
            Clear RX Error Passive
            ------------------------------------------------------*/
            can_hw_error_status[hw_inst] &= ( ~CAN_HW_ERR_RX_PASSIVE );

            /*------------------------------------------------------
            Set RX Error Active
            ------------------------------------------------------*/
            can_hw_error_status[hw_inst] |= ( ~CAN_HW_ERR_RX_ACTIVE );

            can_hook_exception( hw_inst, CAN_EX_RX_ERROR_ACTIVE );
            }
        }
    }

/*------------------------------------------------------
Check for Error Passive Level
------------------------------------------------------*/
if( l_flt_conf == FLT_CONF_ERR_PASSIVE )
    {
    /*------------------------------------------------------
    Check for Error interrupt enabled
    ------------------------------------------------------*/
    if( ( l_esr_status & CAN_ESR1_ERRINT_MASK ) != 0 )
        {
        if( l_tx_err_cnt >= CAN_ERROR_PASSIVE_COUNT )
            {
            can_hw_error_status[hw_inst] |= CAN_HW_ERR_TX_PASSIVE;

            can_hook_exception( hw_inst, CAN_EX_TX_ERROR_PASSIVE );
            }
        if( l_rx_err_cnt >= CAN_ERROR_PASSIVE_COUNT )
            {
            can_hw_error_status[hw_inst] |= CAN_HW_ERR_RX_PASSIVE;

            can_hook_exception( hw_inst, CAN_EX_RX_ERROR_PASSIVE );
            }
        }
    }

/*------------------------------------------------------
Check for CAN BussOFF
------------------------------------------------------*/
if( ( l_esr_status & FLEXCAN_BUSOFF_INT_FLAG ) != 0 )
    {
    /*------------------------------------------------------
    Update the hardware status to indicate Offline and
    uninitialized
    ------------------------------------------------------*/
    can_hw_status[hw_inst] &= SYS_MASK32_COMPLEMENT( CAN_HW_ONLINE | CAN_HW_INITOK );

    /*------------------------------------------------------
    Update hardware error status to indicate BusOFF condition
    ------------------------------------------------------*/
    can_hw_error_status[hw_inst] |= CAN_HW_ERR_BUSOFF;

    /*------------------------------------------------------
    Check for BussOFF interrupt enabled
    ------------------------------------------------------*/
    if( l_flt_conf >= FLT_CONF_ERR_BUSOFF_MIN )
        {
        /*------------------------------------------------------
        Notify the application
        ------------------------------------------------------*/
        can_hook_exception( hw_inst, CAN_EX_BUSOFF );
        }
    }
}

/*!*******************************************************************
*
* for and process CAN module wakeup
*
* This function is used for CAN bus wakeup processes
*
*********************************************************************/
static void
can_hw_bus_wakeup_isr_hndlr
    (
    can_hw_inst_t   const hw_inst       //!< [in] CAN hardware instance
    )
{
/*------------------------------------------------------
Set hardware status Wakeup
------------------------------------------------------*/
can_hw_set_status_bit( hw_inst, CAN_HW_WAKEUP );
}

/*!*******************************************************************
*
* @private
* FlexCAN controller transmit complete interrupt handler
*
* This function is the handler for transmit complete (transmit buffer
* empty) interrupts. Note that a transmit buffer empty even can either
* be due to a normal transmit message completion or a result of a
* transmit abort request. This handler must distinguish between these
* two events and only report successful message transmit completions
* via the callback to the CAN driver layer.
*
*********************************************************************/
static void
can_hw_tx_mb_isr_hndlr
    (
    can_hw_inst_t    const hw_inst,           //!< [in] CAN hardware instance
    flexcan_regs_t * const p_flexcan_hw_regs, //!< [in] ptr to FlexCAN H/W registers
    can_hmb_t        const tx_mb_index        //!< [in] receive Message Buffer
    )
{
can_tmh_t         l_tx_handle        = 0;
uint8             l_tx_mb_timout_idx = 0;
boolean           l_tx_ok            = FALSE;
uint64_t          l_u64Msk           = 1;

/*------------------------------------------------------
Clear transmit Interrupt
------------------------------------------------------*/
flexcan_ClearMbStatusFlags( p_flexcan_hw_regs, ( l_u64Msk << tx_mb_index ) );

/*------------------------------------------------------
Reset the Message Buffer for another transmission
------------------------------------------------------*/
flexcan_SetTxMbConfig( p_flexcan_hw_regs, tx_mb_index, TRUE );

/*--------------------------------------------------
The message transmitted successfully. Set TX OK to
TURE and set the Bus Activity Status bit.
--------------------------------------------------*/
l_tx_ok = TRUE;
can_hw_set_status_bit( hw_inst, CAN_HW_BUS_ACTIVE );

/*------------------------------------------------------
Transmit is no longer pending, either due to transmit
complete or due to aborting the transmission due to a
transmit timeout. In either case the transmit is no
longer pending. Get the transmit message handle for the
completed message and reset the handle for this transmit
buffer. Notify the driver layer of transmit transaction
completion (successful or otherwise).
------------------------------------------------------*/
l_tx_mb_timout_idx  = tx_mb_index - CAN_HMB_TX_START;
l_tx_handle         = can_hw_tx_msg_handle[hw_inst][l_tx_mb_timout_idx];
can_hw_tx_msg_handle[hw_inst][l_tx_mb_timout_idx]     = 0;
can_hw_tx_timeout[hw_inst].active[l_tx_mb_timout_idx] = FALSE;
can_hook_transmit( hw_inst, l_tx_handle, tx_mb_index, l_tx_ok );
}

/*!*******************************************************************
*
* @private
* FlexCAN receive Message Buffer Interrupt Handler
*
* This function is the handler for MB reception events. Note that a
* FlexCAN controller has upto 64 separate Message Buffer and
* each MB generates its own events. Also note that MB events
* include successful message receptions as as well as any other MB
* event interrupts that have been enabled.
*
*********************************************************************/
static void
can_hw_rx_mb_isr_hndlr
    (
    can_hw_inst_t    const hw_inst,           //!< [in] CAN hardware instance
    flexcan_regs_t * const p_flexcan_hw_regs, //!< [in] ptr to FlexCAN H/W registers
    can_hmb_t        const rx_mb_index        //!< [in] receive Message Buffer
    )
{
can_ret_code_t      l_ret_code   = CAN_RC_FALSE;
can_rmd_t          *l_p_rmd      = NULL;
can_hmb_mask_t      l_u64flag    = 1;

/*------------------------------------------------------
Get Pointer to Next Entry in the Receive Queue
------------------------------------------------------*/
l_p_rmd = can_hook_get_rmd_ptr( hw_inst );

/*------------------------------------------------------
Check for Available Space in the Receive Queue
(NULL Returned Pointer indicates none available)
------------------------------------------------------*/
if( l_p_rmd != NULL )
    {
    /*------------------------------------------------------
    Find Message to deal with.
    ------------------------------------------------------*/
    l_ret_code = can_hw_receive_rx_mb( p_flexcan_hw_regs, l_p_rmd, rx_mb_index );

    /*------------------------------------------------------
    Check for Message Successfully Received
    ------------------------------------------------------*/
    if( CAN_RC_SUCCESS == l_ret_code )
        {
        /*--------------------------------------------------
        Set the Bus Activity Status bit.
        --------------------------------------------------*/
        can_hw_set_status_bit( hw_inst, CAN_HW_BUS_ACTIVE );

        /*--------------------------------------------------
        Notify the Driver layer of a message reception
        --------------------------------------------------*/
        can_hook_receive( hw_inst, rx_mb_index, l_p_rmd );
        }
    }
else
    {
    /*------------------------------------------------------
    The Driver Layer is unable to accept the received
    message so just flush it. (The Driver layer sets the
    software receive queue overrun error status bit).
    ------------------------------------------------------*/
    can_hw_rx_flush( hw_inst );
    }

flexcan_ClearMbStatusFlags( p_flexcan_hw_regs, l_u64flag << rx_mb_index );
}

/*!*******************************************************************
*
* @private
* FlexCAN status change interrupt handler
*
* This function is the handler for CAN controller status change
* events. CAN controller events that can be included in these status
* change events are, if enabled, CAN go to sleep and CAN wakeup
* events. Also included in these events are CAN error events including
* the Error Warning, Error Passive and BusOFF events. This handler
* must differentiate between these various events and process these
* events and issue notifications to the driver layer accordingly.
*
*********************************************************************/
static void
can_hw_status_change_isr_hndlr
    (
    can_hw_inst_t   const hw_inst       //!< [in] CAN hardware instance
    )
{
flexcan_regs_t   *l_p_flexcan_regs = NULL;
uint32            l_esr_status     = 0;
can_hmb_mask_t    l_u64flag        = 1;
can_hmb_t         l_mb_index       = 0;

/*------------------------------------------------------
Get Pointer to Hardware Instance Registers
------------------------------------------------------*/
l_p_flexcan_regs = can_hw_get_regs( hw_inst );

/*------------------------------------------------------
Read ESR1 (Error and Status Register)
------------------------------------------------------*/
l_esr_status     = flexcan_GetStatusFlags( l_p_flexcan_regs );

/*------------------------------------------------------
To handle FlexCAN Error and Status Interrupt first.
------------------------------------------------------*/
if( 0U != ( l_esr_status & ( (uint32_t)FLEXCAN_TXWARNING_INT_FLAG | (uint32_t)FLEXCAN_RXWARNING_INT_FLAG |
                             (uint32_t)FLEXCAN_BUSOFF_INT_FLAG    | (uint32_t)FLEXCAN_ERROR_INT_FLAG ) ) )
    {
    /*------------------------------------------------------
    Disable CAN interrupts
    ------------------------------------------------------*/
    flexcan_DisableInterrupts( l_p_flexcan_regs, (uint32_t)( FLEXCAN_TXWARNING_INT_EN | FLEXCAN_RXWARNING_INT_EN |
                                                             FLEXCAN_BUSOFF_INT_EN    | FLEXCAN_ERROR_INT_EN ) );

    /*------------------------------------------------------
    Process any Bus Errors
    ------------------------------------------------------*/
    can_hw_bus_errors_isr_hndlr( hw_inst );

    /*------------------------------------------------------
    Clear FlexCAN Error and Enable Status Interrupt.
    ------------------------------------------------------*/
    flexcan_ClearStatusFlags( l_p_flexcan_regs,  (uint32_t)( FLEXCAN_TXWARNING_INT_FLAG | FLEXCAN_RXWARNING_INT_FLAG |
                                                             FLEXCAN_BUSOFF_INT_FLAG    | FLEXCAN_ERROR_INT_FLAG ) );
    flexcan_EnableInterrupts( l_p_flexcan_regs,  (uint32_t)( FLEXCAN_TXWARNING_INT_EN   | FLEXCAN_RXWARNING_INT_EN |
                                                             FLEXCAN_BUSOFF_INT_EN      | FLEXCAN_ERROR_INT_EN ) );
    }

/*------------------------------------------------------
Handle FlexCAN Wakeup Interrupt.
------------------------------------------------------*/
if( 0U != ( l_esr_status & (uint32_t)FLEXCAN_WAKEUP_INT_FLAG ) )
    {
    /*------------------------------------------------------
    Disable CAN wakeup interrupts
    ------------------------------------------------------*/
    flexcan_DisableInterrupts( l_p_flexcan_regs, (uint32_t)FLEXCAN_WAKEUP_INT_EN );

    /*------------------------------------------------------
    Handle CAN wakeup
    ------------------------------------------------------*/
    can_hw_bus_wakeup_isr_hndlr( hw_inst );

    /*------------------------------------------------------
    Clear FlexCAN Error and Enable wakeup Interrupt.
    ------------------------------------------------------*/
    flexcan_ClearStatusFlags( l_p_flexcan_regs, (uint32_t)FLEXCAN_WAKEUP_INT_FLAG );
    flexcan_EnableInterrupts( l_p_flexcan_regs, (uint32_t)FLEXCAN_WAKEUP_INT_EN   );
    }

/*------------------------------------------------------
Handle FlexCAN Message buffer receive and transmit Interrupt.
------------------------------------------------------*/
for( l_mb_index = 0; l_mb_index < ( CAN_HMB_TX_START + CAN_HMB_TX_ALL ); l_mb_index++ )
    {
    if( 0U != ( flexcan_GetMbStatus( l_p_flexcan_regs ) & ( l_u64flag << l_mb_index ) ) )
        {
        /*------------------------------------------------------
        Check if the Message Buffer interrupt is enabled
        ------------------------------------------------------*/
        if( flexcan_IsMbIntEnabled( l_p_flexcan_regs, l_mb_index ) )
            {
            if( l_mb_index < CAN_HMB_RX_ALL )
                {
                /*------------------------------------------------------
                Handle receive interrupt
                ------------------------------------------------------*/
                can_hw_rx_mb_isr_hndlr( hw_inst, l_p_flexcan_regs, l_mb_index );
                }

            /*------------------------------------------------------
            Handle FlexCAN Message buffer Transmit Interrupt.
            ------------------------------------------------------*/
            if( ( l_mb_index >= CAN_HMB_TX_START ) && ( l_mb_index < ( CAN_HMB_TX_START + CAN_HMB_TX_ALL ) ) )
                {
                /*------------------------------------------------------
                Handle transmit interrupt
                ------------------------------------------------------*/
                can_hw_tx_mb_isr_hndlr( hw_inst, l_p_flexcan_regs, l_mb_index );
                }
            }
        }
    }
}

/*********************************************************************
*
*   PROCEDURE NAME:
*       CAN2_DriverIRQHandler - CAN2 interrupt service routine
*
*   DESCRIPTION:
*       This function handles CAN2 interrupt request
*
*********************************************************************/
void CAN2_DriverIRQHandler(void)
{
#if( SYC_CAN_SUPPORT == TRUE )
    can_hw_status_change_isr_hndlr( CAN_CONTROLLER_2 );
#endif

/*------------------------------------------------------
Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F
Store immediate overlapping exception return operation
might vector to incorrect interrupt.
------------------------------------------------------*/
#if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
#endif
}

