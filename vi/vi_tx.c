/*********************************************************************
* @file
* vi_tx.c
*
* @brief
* Vehicle information module - process tx data
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "task.h"
#include "semphr.h"
#include "ewrte.h"
#include "fsl_debug_console.h"
#include "vi_priv.h"
#include "VI_pub.h"
#include "CAN_pub.h"

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
* VI_set_tx_data
*
* Send data from UI to CAN stack
*
* @param tx_type Tx data of EnumVehicleTxType type
* @param data Tx data
*
*********************************************************************/
void VI_set_tx_data
    (
    int      tx_type,
    uint64_t data
    )
{
PRINTF( "%s 0x%x, 0x%x\r\n", __FUNCTION__, tx_type, data );

switch( tx_type )
    {
    case EnumVehicleTxTypeLANGUAGE:
        break;
    case EnumVehicleTxTypeMILEAGE_UNIT:
        break;
    case EnumVehicleTxTypeVEHICLE_SPEED_UNIT:
        break;
    case EnumVehicleTxTypePRESSURE_UNIT:
        break;
    case EnumVehicleTxTypeTEMPERATURE_UNIT:
        break;
    case EnumVehicleTxTypeFUEL_CONSUMPTION_UNIT:
        break;
    case EnumVehicleTxTypeFUEL_UNIT:
        break;
    case EnumVehicleTxTypeHEATER_SELECT:
        break;
    case EnumVehicleTxTypeHEATER_LEVEL:
        break;
    case EnumVehicleTxTypeBUTTON_STATUS_AUDIO:
        break;
    case EnumVehicleTxTypeWIND_SCREEN_OPERATION:
        break;
    case EnumVehicleTxTypeMETER_BRIGHTNESS_OPERATION:
        break;
    case EnumVehicleTxTypeGRIP_WARMER_CHANGE_LEVEL:
        break;
    case EnumVehicleTxTypeHEAT_SEATER_CHANGE_LEVEL:
        break;
    case EnumVehicleTxTypeCHG_METER_INFO:
        break;
    case EnumVehicleTxTypeTFT_BRIGHTNESS_OPERATION:
        break;
    default:
        PRINTF( "Err: %s invalid tx type %d\r\n", __FUNCTION__, tx_type );
        break;
    }
}
