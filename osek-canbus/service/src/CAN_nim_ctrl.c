/*!*******************************************************************
* @file CAN_nim_ctrl.c
* @brief CAN Stack Network Interface Control Manager
*
* This file includes the functions that implement the portion of the
* public API of the Garmin OSEK CAN Stack that deals with controlling
* the overall state of the CAN Stack. The functions in this file allow
* the application to initialize, start up Interface Manager. This file
* also includes the primary periodic task for the CAN Stack that in
* turn manages the periodic task calls for the invidiual layers of the
* CAN Stack, including the Network Management Layer, the Interaction Layer
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
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
#include "can_nm.h"

//#include "can_il.h"
//#include "can_il_par.h"
//#include "can_il_enum.h"

#include "can_tp.h"
#include "can_svcs.h"
//#include "can_nim_signals.h"
#include "can_nim_cfg.h"
#include "CAN_nim_ctrl.h"

#include "fsl_debug_console.h"
#include "FreeRTOS.h"
#include "task.h"
#include "CAN_nim_ctrl.h"
#include "GRM_pub_prj.h"

/*--------------------------------------------------------------------
                            MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                            TYPES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                            VARIABLES
--------------------------------------------------------------------*/
static uint8
can_nim_task_count[CAN_NUM_INSTANCES];

/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/
/*!*******************************************************************
*
* @public
* Network Interace Manager initialization
*
* Initialize the Network Management Layer which in turn initializes
* the Network Management Layer and theremaining layers of the Garmin
* OSEK CAN Stack implementation.
*
*********************************************************************/
void CAN_nim_init
    (
    void
    )
{
}

/*!*******************************************************************
*
* @public
* start up the Network Interace Manager
*
* This function performs start up initialization of the Network
* Interace Manager. Included in this function of the ancillary CAN
* services that are needed by the CAN controller and the low level
* driver as well as initialization of all layers of the Garmin OSEK
* CAN Stack.
*
*********************************************************************/
void CAN_nim_start_up
    (
    void
    )
{
can_hw_init( 0, CAN_INIT_MODE_COLD, NULL );
}

/*!*******************************************************************
*
* @public
* periodic Network Interace Manager task
*
* This function represents the periodic task that must be called at
* the specific rate by the OS or Task Manager needed to guarantee
* proper timing for all of the Garmin OSEK CAN Stack component
* behaviors, including timing of periodic message transmissions,
* receive message timeouts, Network Management message timeouts, etc.
*
*********************************************************************/
static void
CAN_nim_task
    (
    void
    )
{
can_hw_inst_t   l_i_hw_inst;
uint32_t        last_time = xTaskGetTickCount();

#if( DEBUG_TX_CAN_SUPPORT )
    uint32_t const  l_tx_id_table[] = { 0x584, 0x57A, 0x581, 0x5B1, 0x5B3, 0x5BF, 0x5CA, 0x690 };
    uint32_t const  l_tx_id_len[]   = { 3, 2, 1, 1, 2, 5, 2, 8 };
    uint8_t         l_tx_data[8]    = { 1, 2, 3, 4, 5, 6, 7, 8 };
    can_tmd_t       l_tmd_sample[8] = { 0 };
    uint8_t         l_tx_index      = 0;
    uint32_t        l_test_tick     = 0;
#endif

/*------------------------------------------------------
Starup the CAN hardware and services
------------------------------------------------------*/
CAN_nim_start_up();

while(1)
    {
    #if( DEBUG_TX_CAN_SUPPORT )
        if( ( ( l_test_tick++ ) % 100 ) == 0 )
            {
            /*------------------------------------------------------
            Test case
            ------------------------------------------------------*/
            for( l_tx_index = 0; l_tx_index < 8; l_tx_index++ )
                {
                l_tmd_sample[l_tx_index].dlc        = l_tx_id_len[l_tx_index];
                l_tmd_sample[l_tx_index].p_data     = l_tx_data;
                l_tmd_sample[l_tx_index].handle     = 0;
                l_tmd_sample[l_tx_index].options    = 0;
                l_tmd_sample[l_tx_index].identifier = l_tx_id_table[l_tx_index];
                can_transmit( 0, &l_tmd_sample[l_tx_index] );
                }
            }
    #endif

    /*------------------------------------------------------
    Service all the CAN stack layers for each hardware
    instance.
    ------------------------------------------------------*/
    for( l_i_hw_inst = 0; l_i_hw_inst < CAN_NUM_INSTANCES; l_i_hw_inst++ )
        {
        /*------------------------------------------------------
        Check if the container tasks are scheduled to run.
        ------------------------------------------------------*/
        if( can_nim_task_count[l_i_hw_inst] != 0 )
            {
            ( can_nim_task_count[l_i_hw_inst] )--;
            if( 0 == can_nim_task_count[l_i_hw_inst] )
                {
                /*------------------------------------------------------
                Dispatch Layer Periodic Receive and Transmit Tasks
                ------------------------------------------------------*/
                dll_rx_task( l_i_hw_inst );
                dll_tx_task( l_i_hw_inst );

                /*------------------------------------------------------
                Task interaction counter contains the Interaction Layer Periodic
                Receive and Transmit Tasks
                ------------------------------------------------------*/
                //il_rx_task( l_i_hw_inst );
                //il_tx_task( l_i_hw_inst );

                /*------------------------------------------------------
                TP Layer Periodic Task
                ------------------------------------------------------*/
                //tp_task( l_i_hw_inst );

                /*------------------------------------------------------
                Diagnostic Layer Periodic Task.
                ------------------------------------------------------*/
                //can_diag_task( l_i_hw_inst );

                /*------------------------------------------------------
                Network Management Layer Periodic Task
                ------------------------------------------------------*/
                //nm_task( l_i_hw_inst );

                /*------------------------------------------------------
                Re-initialize the task container counter
                ------------------------------------------------------*/
                can_nim_task_count[l_i_hw_inst] = CAN_NIM_TASK_COUNT_INIT;
                }
            }
        else
            {
            /*------------------------------------------------------
            Re-initialize the task container counter
            ------------------------------------------------------*/
            can_nim_task_count[l_i_hw_inst] = CAN_NIM_TASK_COUNT_INIT;
            }

        /*------------------------------------------------------
        Low Level CAN driver Periodic Task
        ------------------------------------------------------*/
        can_periodic( l_i_hw_inst );
        }

    vTaskDelayUntil( &last_time, 5 );
    }

vTaskDelete( NULL );
}

/*------------------------------------------------------
Create the CAN stack task NIM
------------------------------------------------------*/
void vCAN_nim_create_task
    (
    void
    )
{
if( pdPASS == xTaskCreate( (TaskFunction_t)CAN_nim_task, "CAN nim task", 256, NULL, TASK_PRIO_CAN, NULL ) )
    {
    PRINTF("Create LinkCard CAN Stack...                 [OK]\r\n" );
    }
else
    {
    PRINTF("Create LinkCard CAN Stack...                 [FAIL]\r\n" );
    }
}

