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
* send_meter_brightngess_operation
*
* Send meter brightness operation
*
* @param operation_code Brightness operation code of
*                       IL_VT_DEV_CTRL_LCD_BRGHTNSS_NT,
*                       IL_VT_DEV_CTRL_LCD_BRGHTNSS_DOWN,
*                       IL_VT_DEV_CTRL_LCD_BRGHTNSS_UP
*
*********************************************************************/
void send_meter_brightngess_operation
    (
    uint8_t operation_code
    )
{
dll_frm_index_t l_frm_index;
can_mid_sig_set( &l_frm_index, IL_CAN0_DEV_CTRL_LCD_BRGHTNSS_TXSIG_HANDLE, IL_CAN0_DEV_CTRL_LCD_BRGHTNSS_TXSIG_NBYTES, &operation_code );
can_mid_frm_send( l_frm_index );
PRINTF( "%s %d\r\n", __FUNCTION__, operation_code );
}

/*********************************************************************
*
* @private
* send_tft_brightngess_operation
*
* Send TFT brightness operation
*
* @param operation_code Brightness operation code of
*                       IL_VT_DEV_CTRL_TFT_BRGHTNSS_NT,
*                       IL_VT_DEV_CTRL_TFT_BRGHTNSS_DOWN,
*                       IL_VT_DEV_CTRL_TFT_BRGHTNSS_UP
*
*********************************************************************/
void send_tft_brightngess_operation
    (
    uint8_t operation_code
    )
{
dll_frm_index_t l_frm_index;
can_mid_sig_set( &l_frm_index, IL_CAN0_DEV_CTRL_TFT_BRGHTNSS_TXSIG_HANDLE, IL_CAN0_DEV_CTRL_TFT_BRGHTNSS_TXSIG_NBYTES, &operation_code );
can_mid_frm_send( l_frm_index );
PRINTF( "%s %d\r\n", __FUNCTION__, operation_code );
}

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
        send_meter_brightngess_operation( (uint8_t)data );
        break;
    case EnumVehicleTxTypeGRIP_WARMER_CHANGE_LEVEL:
        break;
    case EnumVehicleTxTypeHEAT_SEATER_CHANGE_LEVEL:
        break;
    case EnumVehicleTxTypeCHG_METER_INFO:
        break;
    case EnumVehicleTxTypeTFT_BRIGHTNESS_OPERATION:
        send_tft_brightngess_operation( (uint8_t)data );
        break;
    default:
        PRINTF( "Err: %s invalid tx type %d\r\n", __FUNCTION__, tx_type );
        break;
    }
}
