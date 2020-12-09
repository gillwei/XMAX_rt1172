/*!*******************************************************************
* @file can_cfg.h
* @brief RT1170 FlexCAN H/W Driver Application Configuration
*
* This file contains configuration macros that specify the basic
* configuration of the CAN driver and controller features. For most
* "Core" CAN controllers, this file fully specifies the driver
* configuration.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @defgroup can_hw_cfg FlexCAN H/W Driver Application Configuration
* @ingroup can_hw_drv
* @{
*
*********************************************************************/
#ifndef _CAN_CFG_H
#define _CAN_CFG_H

/*----------------------------------------------------------------
                            GENERAL INCLUDES
----------------------------------------------------------------*/
#include "can_defs.h"

/*--------------------------------------------------------------------

    Name:           CAN_NUM_INSTANCES

    Description:    Number of CAN Controller Instantiations

                    This parameter defines the number of CAN controller
                    instantiations supported by the driver. A range of 1
                    to 3 controller instantiations is presently supported
                    by the RT1170 FlexCAN Driver.

    Templates:      #define CAN_NUM_INSTANCES   1

    Assumptions:    All of the CAN controllers are of the same type and
                    have the same register interface.

--------------------------------------------------------------------*/
#define CAN_NUM_INSTANCES 1

/*--------------------------------------------------------------------
        CONTROLLER 2 SPECIFIC BIT TIMING CONFIGURATION MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------

    Names:          CAN2_SRC_CLK_HZ
                    CAN2_BIT_RATE_BPS
                    CAN2_PREDIVIDER_INIT
                    CAN2_PHASE_SEG1
                    CAN2_PHASE_SEG2
                    CAN2_PROP_SEG
                    CAN2_RJUMP_WIDTH

    Description:    CAN Bit Timing Parameters

--------------------------------------------------------------------*/
#define CAN2_SRC_CLK_HZ             (24000000)
#define CAN2_BIT_RATE_BPS           (500000)

#define CAN2_PREDIVIDER_INIT        (0) //!<will be re-calculated
#define CAN2_PHASE_SEG1             (3)
#define CAN2_PHASE_SEG2             (2)
#define CAN2_PROP_SEG               (1)
#define CAN2_RJUMP_WIDTH            (1)

/*--------------------------------------------------------------------

    Name:           CAN_HW_TASK_PERIOD_MS

    Description:    This parameter specifies the CAN hardware task
                    period in milliseconds that is used for monitoring
                    transmit timeout events. This CAN hardware
                    periodic task must be called at the correct rate
                    to guarantee the correct intervals for transmit
                    timeout detection.

--------------------------------------------------------------------*/
#define CAN_HW_TASK_PERIOD_MS               (5)

/*--------------------------------------------------------------------

    Name:           CAN_HW_N_AS_TRANSMIT_TIMEOUT_MS

    Description:    This parameter specifies the CAN hardware transmit
                    timeout period in milliseconds that is used for
                    monitoring transmit timeout events.

--------------------------------------------------------------------*/
#define CAN_HW_N_AS_TRANSMIT_TIMEOUT_MS     (1000)

/*--------------------------------------------------------------------

   Name:            CAN0_RXQ_SIZE

   Description:     This parameter specifies the size of the software
                    receive queue in terms of number of messages. The
                    minimum software receive queue size is 1 message.

   Template:        #define CAN_RXQ_SIZE  1

   Assumptions:     CAN software receive queue is enabled (see
                    "CAN_RXQ" definition.

--------------------------------------------------------------------*/
#define CAN0_RXQ_SIZE   20

/*--------------------------------------------------------------------

    Name:           CAN0_TXQ_SIZE

    Description:    This parameter specifies the size of the software
                    transmit queue in terms of number of messages.

    Template:       #define CAN0_TXQ_SIZE  1

    Assumptions:    Note the software transmit queue can be used in
                    polled the CAN periodic task pulls messages to be
                    transmitted from the software transmit queue.

--------------------------------------------------------------------*/
#define CAN0_TXQ_SIZE  20

/*--------------------------------------------------------------------
//
   Name:            CAN0_TMDQ_SIZE

   Description:     This parameter specifies the size in messages of
                    the software TMD queue, which queues complete
                    TMD's.

   Template:        #define CAN0_TMDQ_SIZE  8

   Assumptions:     The CAN software TMD queue is enabled (see
                    "CANx_TMDQ" parameter definition). Note the
                    software transmit data queue can be used in polled
                    or interrupt driven mode (i.e. CAN_TX_INTERRUPTS
                    do not have to be enabled). If CAN TX interrupts
                    are not enabled, the CAN periodic task pulls
                    messages to be transmitted from the software
                    Tx and TMD queues.

--------------------------------------------------------------------*/
#define CAN0_TMDQ_SIZE  2

/*--------------------------------------------------------------------

    Name:           CAN_HW_TRANSMIT_TIMEOUT_ENABLE

    Description:    This parameter specifies whether the CAN driver
                    transmit timeout feature is enabled or disabled.
                    For the IXWW22 CAN stack implementation, this feature
                    needs to be enabled.

--------------------------------------------------------------------*/
#define CAN_HW_TRANSMIT_TIMEOUT_ENABLE      TRUE

/*--------------------------------------------------------------------

    Name:           CAN_IL_DELAY_EVENT_TO_TICK

    Description:    This parameter is specific to the Interaction Layer
                    and provides an option to delay IL frame
                    transmission events to the next tick interval as
                    opposed to being transmitted immediately if the
                    time since the last frame transmission exceeds the
                    minimum frame transmit delay.

--------------------------------------------------------------------*/
#define CAN_IL_DELAY_EVENT_TO_TICK          FALSE

#endif/* _CAN_CFG_H */
