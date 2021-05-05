/*********************************************************************
* @file
* navilite_intf_vim_runloop.c
*
* @brief
* NAVILITE module - vim runloop jobs
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "NAVILITE_pub.h"

#if( NAVILITE_BUILD_ROLE == NAVILITE_TARGET_MCU )
#include "FreeRTOS.h"
#include "event_groups.h"
#include "limits.h"
#include "task.h"
#include "semphr.h"
#include "ewrte.h"
#include "fsl_debug_console.h"

#include "CAN_pub.h"

#define NAVILITE_DEBUG true
#define NAVILITE_DEBUG_DETAIL false
#define NAVILITE_TEST_VIM_SPEED false
#define NAVILITE_TEST_IOP_SPEED false
#endif

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @private
* navilite_vim_runloop
*
* Report vehicle speed to navilite app
*
* @return  true if vehicle job executed successfully
*          false otherwise
*
*********************************************************************/
bool navilite_vim_runloop
    (
    void
    )
{
uint32_t speed_value = 0;
uint32_t speed_unit = 0;
#if( NAVILITE_TEST_VIM_SPEED )
    static uint32_t test_speed = 0;
#endif

nim_app_sig_get( IL_CAN0_MT_SET_INFO_SPD_UNIT_RXSIG_HANDLE, IL_CAN0_MT_SET_INFO_SPD_UNIT_RXSIG_NBYTES, &speed_unit );
nim_app_sig_get( IL_CAN0_VEHICLE_INFO_2_SPD_REAL_RXSIG_HANDLE, IL_CAN0_VEHICLE_INFO_2_SPD_REAL_RXSIG_NBYTES, &speed_value );

#if( NAVILITE_TEST_VIM_SPEED )
    test_speed += 2;
    if( speed_value == 0 )
        {
        speed_value = test_speed % 100;
        }
    if( test_speed > 20000 )
        {
        test_speed = 0;
        }
#endif

#if( NAVILITE_DEBUG )
    PRINTF( "[NAVILITE-runloop] VIM-CAN speed unit: %s, value : %d\r\n", ( speed_unit == 0 ) ? "kph" : "mph", speed_value );
#endif
NAVILITE_report_app_vehicle_speed( (navilite_speed_unit_type)speed_unit, (uint16_t)speed_value );
return true;
}
