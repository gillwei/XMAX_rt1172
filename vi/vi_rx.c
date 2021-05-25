/*********************************************************************
* @file
* vi_rx.c
*
* @brief
* Vehicle information module - process received data
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
#include "EW_pub.h"
#include "PERIPHERAL_pub.h"
#include "EEPM_pub.h"
#include "CAN_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define VEHICLE_DRIVER_DISTRACTION_MODE_LIMIT       ( 3 )       /* km/h */
#define POSITIVE_RESPONSE   ( 0x0 )
#define NEGATIVE_RESPONSE   ( 0xFF )

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
static rx_ecu_info_struct           rx_ecu_info;
static rx_brightness_control_struct rx_brightness_control;
static rx_unit_setting_struct       rx_unit_setting;
static rx_fuel_rate_struct          rx_fuel_rate;
static rx_odo_trip_struct           rx_odo_trip;
static rx_vehicle_info_struct       rx_vehicle_info;
static rx_heater_status_struct      rx_grip_warmer_status;
static rx_heater_status_struct      rx_seat_heater_status;
static rx_maintenance_trip_struct   rx_maintenance_trip;
static rx_tacho_setting_struct      rx_tacho_setting;
static rx_tire_pressure_struct      rx_tire_pressure;

static uint32_t rx_vehicle_supported_functions = 0;
static bool     is_dd_mode_activated = false;
static SemaphoreHandle_t supported_function_semaphore_handle;
static supported_func_data_src_enum supported_func_data_source;
static const int32_t ticks_to_wait = pdMS_TO_TICKS( 500 );

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/
#define set_bit( data, offset )   ( ( data ) |=  ( 1 << ( offset ) ) )
#define clear_bit( data, offset ) ( ( data ) &= ~( 1 << ( offset ) ) )

#define TFT_DUTY_FACTOR           100 / 1023.0
/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
/*********************************************************************
*
* @private
* process_ecu_indicate_status
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_ecu_indicate_status
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_ECU_INDCT_EG_SPD_RXSIG_HANDLE:
        rx_ecu_info.engine_speed = data;
        break;
    case IL_CAN0_ECU_INDCT_TC_MODE_RXSIG_HANDLE:
        rx_ecu_info.tc_mode = (uint8_t)data;
        EW_notify_vi_data_received( EnumVehicleRxTypeTC_MODE );
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_ecu_legacy_com_data
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_ecu_legacy_com_data
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_ECU_COM_DATA_RXSIG_HANDLE: /* VVA */
        rx_ecu_info.vva_indicator = ( vva_indicator_enum )data;
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_brightness_control_response
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_brightness_control_response
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_BRTNSS_CTRL_MT_TFT_DUTY_RXSIG_HANDLE:
        rx_brightness_control.tft_duty = (uint16_t)data;
        PERIPHERAL_pwm_set_display_dutycycle( (uint8_t)( data * TFT_DUTY_FACTOR ) );
        break;
    case IL_CAN0_BRTNSS_CTRL_LCD_LV_RXSIG_HANDLE:
        rx_brightness_control.lcd_brightness_level = (uint8_t)data;
        EW_notify_vi_data_received( EnumVehicleRxTypeMETER_BRIGHTNESS_LEVEL );
        break;
    case IL_CAN0_BRTNSS_CTRL_TFT_LV_RXSIG_HANDLE:
        rx_brightness_control.tft_brightness_level = (uint8_t)data;
        EW_notify_vi_data_received( EnumVehicleRxTypeTFT_BRIGHTNESS_LEVEL );
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_vehicle_info
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_vehicle_info
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_VEHICLE_INFO_MILE_UNIT_RXSIG_HANDLE:
        rx_unit_setting.mileage_unit = ( mileage_unit_enum )data;
        EW_notify_vi_data_received( EnumVehicleRxTypeMILEAGE_UNIT );
        break;
    case IL_CAN0_VEHICLE_INFO_PRESS_UNIT_RXSIG_HANDLE:
        rx_unit_setting.pressure_unit = ( pressure_unit_enum )data;
        EW_notify_vi_data_received( EnumVehicleRxTypePRESSURE_UNIT );
        break;
    case IL_CAN0_VEHICLE_INFO_TEMP_UNIT_RXSIG_HANDLE:
        rx_unit_setting.temperature_unit = ( temperature_unit_enum )data;
        EW_notify_vi_data_received( EnumVehicleRxTypeTEMPERATURE_UNIT );
        break;
    case IL_CAN0_VEHICLE_INFO_FUEL_CON_UNIT_RXSIG_HANDLE:
        rx_unit_setting.fuel_consumption_unit = ( fuel_consumption_unit_enum )data;
        EW_notify_vi_data_received( EnumVehicleRxTypeFUEL_CONSUMPTION_UNIT );
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_function_software_status
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_function_software_status
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_FUNC_SW_1_RXSIG_HANDLE:
        vi_key_status_changed( CoreKeyCodeUp, (int)data );
        break;
    case IL_CAN0_FUNC_SW_2_RXSIG_HANDLE:
        vi_key_status_changed( CoreKeyCodeDown, (int)data );
        break;
    case IL_CAN0_FUNC_SW_5_RXSIG_HANDLE:
        vi_key_status_changed( CoreKeyCodeOk, (int)data );
        break;
    case IL_CAN0_FUNC_SW_6_RXSIG_HANDLE:
        vi_key_status_changed( CoreKeyCodeHome, (int)data );
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_fuel_rate
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_fuel_rate
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_FUEL_RATE_AVE_RXSIG_HANDLE:
        rx_fuel_rate.average_consumption = (uint16_t)data;
        EW_notify_vi_data_received( EnumVehicleRxTypeFUEL_RATE_AVERAGE );
        break;
    case IL_CAN0_FUEL_RATE_AVG_SPD_RXSIG_HANDLE:
        rx_fuel_rate.average_speed_km = (uint16_t)data;
        EW_notify_vi_data_received( EnumVehicleRxTypeAVERAGE_SPEED );
        break;
    case IL_CAN0_FUEL_RATE_INST_RXSIG_HANDLE:
        rx_fuel_rate.instant_consumption = (uint16_t)data;
        EW_notify_vi_data_received( EnumVehicleRxTypeFUEL_RATE_INSTANT );
        break;
    case IL_CAN0_FUEL_RATE_RANGE_DIST_RXSIG_HANDLE:
        rx_fuel_rate.range_distance_km = (uint16_t)data;
        EW_notify_vi_data_received( EnumVehicleRxTypeRANGE_DISTANCE );
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_odo_trip_value
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_odo_trip_value
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_ODO_TRIP_ODOMETER_RXSIG_HANDLE:
        rx_odo_trip.odo_value_km = data;
        EW_notify_vi_data_received( EnumVehicleRxTypeODOMETER_VALUE );
        break;
    case IL_CAN0_ODO_TRIP1_METER_RXSIG_HANDLE:
        rx_odo_trip.trip1_value_km = data;
        EW_notify_vi_data_received( EnumVehicleRxTypeTRIP1_VALUE );
        break;
    case IL_CAN0_ODO_TRIP2_METER_RXSIG_HANDLE:
        rx_odo_trip.trip2_value_km = data;
        EW_notify_vi_data_received( EnumVehicleRxTypeTRIP2_VALUE );
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_vehicle_info_2
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_vehicle_info_2
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_VEHICLE_INFO_2_APS_ANG_TRAN_RXSIG_HANDLE:
        rx_vehicle_info.aps_angle_deg = (uint16_t)data;
        break;
    case IL_CAN0_VEHICLE_INFO_2_SPD_REAL_RXSIG_HANDLE:
        rx_vehicle_info.vehicle_speed_real = (uint16_t)data;
        if( is_dd_mode_activated && ( VEHICLE_DRIVER_DISTRACTION_MODE_LIMIT > rx_vehicle_info.vehicle_speed_real ) )
            {
            is_dd_mode_activated = false;
            EW_notify_dd_mode_state_changed();
            }
        else if( !is_dd_mode_activated && ( VEHICLE_DRIVER_DISTRACTION_MODE_LIMIT <= rx_vehicle_info.vehicle_speed_real ) )
            {
            is_dd_mode_activated = true;
            EW_notify_dd_mode_state_changed();
            }
        else
            {
            // empty
            }
        break;
    case IL_CAN0_VEHICLE_INFO_2_SPD_REAL_MT_RXSIG_HANDLE:
        rx_vehicle_info.vehicle_speed_meter = (uint16_t)data;
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_vehicle_info_3
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_vehicle_info_3
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_VEHICLE_INFO_3_FUEL_CON_RXSIG_HANDLE:
        rx_vehicle_info.fuel_cons = (uint16_t)data;
        EW_notify_vi_data_received( EnumVehicleRxTypeFUEL_CONSUMPTION );
        break;
    case IL_CAN0_VEHICLE_INFO_3_CLK_ADJST_RXSIG_HANDLE:
        rx_vehicle_info.clock_adj_status = (bool)data;
        vi_clock_notify_meter_clk_adj_status_changed( data );
        break;
    case IL_CAN0_VEHICLE_INFO_3_AIR_RXSIG_HANDLE:
        rx_vehicle_info.air_temperature = (uint8_t)data;
        EW_notify_vi_data_received( EnumVehicleRxTypeAIR_TEMPERATURE );
        break;
    case IL_CAN0_VEHICLE_INFO_3_COOLANT_RXSIG_HANDLE:
        rx_vehicle_info.coolant_temperature = (uint8_t)data;
        EW_notify_vi_data_received( EnumVehicleRxTypeCOOLANT_TEMPERATURE );
        break;
    case IL_CAN0_VEHICLE_INFO_3_BAT_RXSIG_HANDLE:
        rx_vehicle_info.battery_voltage = (uint8_t)data;
        EW_notify_vi_data_received( EnumVehicleRxTypeBATTERY_VOLTAGE );
        break;
    case IL_CAN0_VEHICLE_INFO_3_CRUISE_RXSIG_HANDLE:
        rx_vehicle_info.cruise_speed = (uint8_t)data;
        EW_notify_vi_data_received( EnumVehicleRxTypeCRUISE_SPEED );
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_vehicle_info_4
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_vehicle_info_4
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_VEHICLE_INFO_4_FTRIP_RXSIG_HANDLE:
        rx_vehicle_info.fuel_tripmeter_km = (uint16_t)data;
        EW_notify_vi_data_received( EnumVehicleRxTypeTRIP_F_VALUE );
        break;
    case IL_CAN0_VEHICLE_INFO_4_LOW_FUEL_WRN_RXSIG_HANDLE:
        rx_vehicle_info.low_fuel_warning = (bool)data;
        EW_notify_vi_data_received( EnumVehicleRxTypeLOW_FUEL_WARNING );
        break;
    case IL_CAN0_VEHICLE_INFO_4_FUEL_RSV_RXSIG_HANDLE:
        rx_vehicle_info.fuel_reserve = (bool)data;
        break;
    case IL_CAN0_VEHICLE_INFO_4_ODO_TRIP_DIS_RXSIG_HANDLE:
        rx_vehicle_info.odo_trip_display = (odo_trip_display_enum)data;
        EW_notify_vi_data_received( EnumVehicleRxTypeODO_TRIP_DISPLAY );
        break;
    case IL_CAN0_VEHICLE_INFO_4_FTRIP_HRD_RST_RXSIG_HANDLE:
        rx_vehicle_info.fuel_trip_hard_reset = (bool)data;
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_maintenance_trip
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_maintenance_trip
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_MAINT_TRIP_1_RXSIG_HANDLE:
        rx_maintenance_trip.trip1_km = data;
        EW_notify_vi_data_received( EnumVehicleRxTypeMAINTENANCE_TRIP1 );
        break;
    case IL_CAN0_MAINT_TRIP_2_RXSIG_HANDLE:
        rx_maintenance_trip.trip2_km = data;
        EW_notify_vi_data_received( EnumVehicleRxTypeMAINTENANCE_TRIP2 );
        break;
    case IL_CAN0_MAINT_TRIP_3_RXSIG_HANDLE:
        rx_maintenance_trip.trip3_km = data;
        EW_notify_vi_data_received( EnumVehicleRxTypeMAINTENANCE_TRIP3 );
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_heater_status
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_heater_status
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_HEATER_STAT_GRIP_WARM_LO_RXSIG_HANDLE:
        rx_grip_warmer_status.value_low = (uint8_t)data;
        EW_notify_vi_data_received( EnumVehicleRxTypeGRIP_WARMER_VALUE_LOW );
        break;
    case IL_CAN0_HEATER_STAT_GRIP_WARM_MID_RXSIG_HANDLE:
        rx_grip_warmer_status.value_middle = (uint8_t)data;
        EW_notify_vi_data_received( EnumVehicleRxTypeGRIP_WARMER_VALUE_MIDDLE );
        break;
    case IL_CAN0_HEATER_STAT_GRIP_WARM_HI_RXSIG_HANDLE:
        rx_grip_warmer_status.value_high = (uint8_t)data;
        EW_notify_vi_data_received( EnumVehicleRxTypeGRIP_WARMER_VALUE_HIGH );
        break;
    case IL_CAN0_HEATER_STAT_RIDER_SEAT_WARM_LO_RXSIG_HANDLE:
        rx_seat_heater_status.value_low = (uint8_t)data;
        EW_notify_vi_data_received( EnumVehicleRxTypeSEAT_HEATER_VALUE_LOW );
        break;
    case IL_CAN0_HEATER_STAT_RIDER_SEAT_WARM_MID_RXSIG_HANDLE:
        rx_seat_heater_status.value_middle = (uint8_t)data;
        EW_notify_vi_data_received( EnumVehicleRxTypeSEAT_HEATER_VALUE_MIDDLE );
        break;
    case IL_CAN0_HEATER_STAT_RIDER_SEAT_WARM_HI_RXSIG_HANDLE:
        rx_seat_heater_status.value_high = (uint8_t)data;
        EW_notify_vi_data_received( EnumVehicleRxTypeSEAT_HEATER_VALUE_HIGH );
        break;
    case IL_CAN0_HEATER_STAT_CRNT_GW_STAT_RXSIG_HANDLE:
        rx_grip_warmer_status.setting = ( heater_setting_enum )data;
        EW_notify_vi_data_received( EnumVehicleRxTypeGRIP_WARMER_STATUS );
        break;
    case IL_CAN0_HEATER_STAT_CRNT_SH_STAT_RXSIG_HANDLE:
        rx_seat_heater_status.setting = ( heater_setting_enum )data;
        EW_notify_vi_data_received( EnumVehicleRxTypeSEAT_HEATER_STATUS );
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* process_tpms_status
*
* @param signal_id CAN signal id
* @param data Received CAN data
*
*********************************************************************/
static void process_tpms_status
    (
    const uint16_t signal_id,
    const uint32_t data
    )
{
switch( signal_id )
    {
    case IL_CAN0_TPMS_SENSOR_EQUIP_FLG_RXSIG_HANDLE:
        rx_tire_pressure.sensor_equipped = (bool)data;
        EW_notify_vi_data_received( EnumVehicleRxTypeTIRE_SENSOR_EQUIPPED );
        break;
    case IL_CAN0_TPMS_STAT_TIRE_PRESS_FR_RXSIG_HANDLE:
        rx_tire_pressure.front = (uint8_t)data;
        EW_notify_vi_data_received( EnumVehicleRxTypeTIRE_FRONT );
        break;
    case IL_CAN0_TPMS_STAT_TIRE_PRESS_RR_RXSIG_HANDLE:
        rx_tire_pressure.rear = (uint8_t)data;
        EW_notify_vi_data_received( EnumVehicleRxTypeTIRE_REAR );
        break;
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, signal_id );
        break;
    }
}

/*********************************************************************
*
* @private
* notify_inspection_display_request
*
* Notify inspection display test pattern
*
* @param fainsreq FAINSREQ from CAN signal H'60A
*
*********************************************************************/
static void notify_inspection_display_request
    (
    const uint8_t fainsreq
    )
{
switch( fainsreq )
    {
    case 1: EW_notify_inspection_request( EnumInspectionModeDISPLAY, EnumInspectionDisplayCOLOR_GRADIENT );
        break;
    case 2: EW_notify_inspection_request( EnumInspectionModeDISPLAY, EnumInspectionDisplayFULL_BLACK );
        break;
    case 3: EW_notify_inspection_request( EnumInspectionModeDISPLAY, EnumInspectionDisplayFULL_WHITE );
        break;
    case 4: EW_notify_inspection_request( EnumInspectionModeDISPLAY, EnumInspectionDisplayFULL_RED );
        break;
    case 5: EW_notify_inspection_request( EnumInspectionModeDISPLAY, EnumInspectionDisplayFULL_GREEN );
        break;
    case 6: EW_notify_inspection_request( EnumInspectionModeDISPLAY, EnumInspectionDisplayFULL_BLUE );
        break;
    case 7: EW_notify_inspection_request( EnumInspectionModeDISPLAY, EnumInspectionDisplayFLICKER );
        break;
    case 8: EW_notify_inspection_request( EnumInspectionModeDISPLAY, EnumInspectionDisplayCROSSTALK );
        break;
    default:
        VI_send_inspection_response( EnumInspectionModeDISPLAY, fainsreq );
        break;
    }
}

/*********************************************************************
*
* @private
* process_factory_inspection_request
*
* Process factory inspection request
*
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
static void process_factory_inspection_request
    (
    void
    )
{
uint32_t  l_fact_req     = 0;
uint32_t  l_fact_reqCode = 0;

/*------------------------------------------------------
Get the signals' value
------------------------------------------------------*/
nim_app_sig_get( IL_CAN0_FACT_INSP_NS_REQ_RXSIG_HANDLE, IL_CAN0_FACT_INSP_NS_REQ_RXSIG_NBYTES, &l_fact_req );
nim_app_sig_get( IL_CAN0_FACT_INSP_NS_REQCODE_RXSIG_HANDLE, IL_CAN0_FACT_INSP_NS_REQCODE_RXSIG_NBYTES, &l_fact_reqCode );

/*------------------------------------------------------
Handle the factory request
------------------------------------------------------*/
switch( l_fact_req )
    {
    case EnumInspectionModeNONE:
        VI_send_inspection_response( (uint8_t)l_fact_req, POSITIVE_RESPONSE );
        break;
    case EnumInspectionModeDISPLAY:
        notify_inspection_display_request( (uint8_t)l_fact_reqCode );
        break;
    case EnumInspectionModeEND:
        EW_notify_inspection_request( EnumInspectionModeEND, EnumInspectionDisplayTOTAL );
        break;
    default:
        VI_send_inspection_response( (uint8_t)l_fact_req, NEGATIVE_RESPONSE );
        break;
    }
}

/*********************************************************************
*
* @public
* VI_notify_vehicle_cyc_frm_changed
*
* For cyclic CAN RX messages handling
*
* @param message_frame The received CAN message frame id
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
void VI_notify_vehicle_cyc_frm_changed
    (
    const il_rx_frm_index_t msg_idx,
    const uint16_t          sig_hnd,
    const uint32_t          data
    )
{
#if( DEBUG_RX_CAN_SUPPORT )
    PRINTF( "vi 0x%x 0x%x 0x%x\r\n", msg_idx, sig_hnd, data );
#endif

/*------------------------------------------------------
Fetch operation mode
------------------------------------------------------*/
EnumOperationMode operation_mode;
EW_get_operation_mode( &operation_mode );

switch( msg_idx )
    {
    case IL_CAN0_RX0_ECU_INDCT_STAT_IDX:
        process_ecu_indicate_status( sig_hnd, data );
        break;
    case IL_CAN0_RX1_ECU_COM_DATA_IDX:
        process_ecu_legacy_com_data( sig_hnd, data );
        break;
    case IL_CAN0_RX3_BRGTHNSS_CTRL_IDX:
        if( EnumOperationModeNORMAL == operation_mode )
            {
            process_brightness_control_response( sig_hnd, data );
            }
        break;
    case IL_CAN0_RX5_VEHICLE_INFO_IDX:
        process_vehicle_info( sig_hnd, data );
        break;
    case IL_CAN0_RX6_FUNCSW_STAT_IDX:
        process_function_software_status( sig_hnd, data );
        break;
    case IL_CAN0_RX7_FUEL_RATE_IDX:
        process_fuel_rate( sig_hnd, data );
        break;
    case IL_CAN0_RX8_ODO_TRIP_IDX:
        process_odo_trip_value( sig_hnd, data );
        break;
    case IL_CAN0_RXA_VEHICLE_INFO_2_IDX:
        process_vehicle_info_2( sig_hnd, data );
        break;
    case IL_CAN0_RXB_VEHICLE_INFO_3_IDX:
        process_vehicle_info_3( sig_hnd, data );
        break;
    case IL_CAN0_RXC_VEHICLE_INFO_4_IDX:
        process_vehicle_info_4( sig_hnd, data );
        break;
    case IL_CAN0_RXD_MAINT_TRIP_IDX:
        process_maintenance_trip( sig_hnd, data );
        break;
    case IL_CAN0_RXE_HEATER_STAT_IDX:
        process_heater_status( sig_hnd, data );
        break;
    case IL_CAN0_RXI_TPMS_STAT_IDX:
        process_tpms_status( sig_hnd, data );
        break;
    default:
#if( DEBUG_RX_CAN_SUPPORT )
        PRINTF( "%s drop message frame id: 0x%x\r\n", __FUNCTION__, msg_idx );
#endif
        break;
    }
}

/*********************************************************************
*
* @public
* VI_notify_vehicle_event_frm_changed
*
* For event CAN RX messages handling
*
* @param message_frame The received CAN message frame id
* @param signal_id The CAN signal id
* @param data The received CAN data
*
*********************************************************************/
void VI_notify_vehicle_event_frm_changed
    (
    const il_rx_frm_index_t msg_idx,
    const can_msg_t*        msg_data_p
    )
{
#if( DEBUG_RX_CAN_SUPPORT )
    PRINTF( "vi 0x%x 0x%x 0x%x\r\n", msg_idx);
#endif

/*------------------------------------------------------
Fetch operation mode
------------------------------------------------------*/
EnumOperationMode operation_mode;
EW_get_operation_mode( &operation_mode );

/*------------------------------------------------------
Handle meter request or event messages
------------------------------------------------------*/
switch( msg_idx )
    {
    case IL_CAN0_RXF_FACT_INSP_NS_REQ_IDX:
        if( EnumOperationModeFACTORY == operation_mode ||
            EnumOperationModeINSPECTION == operation_mode )
            {
            process_factory_inspection_request();
            }
        break;

    default:

#if( DEBUG_RX_CAN_SUPPORT )
        PRINTF( "%s drop message frame id: 0x%x\r\n", __FUNCTION__, msg_idx );
#endif
        break;
    }
}

/*********************************************************************
*
* @public
* VI_is_dd_mode_activated
*
* Return if the driver distraction mode is activated
*
* @return The driver distraction mode activated status
*
*********************************************************************/
bool VI_is_dd_mode_activated
    (
    void
    )
{
bool is_activated = false;
if( VEHICLE_DRIVER_DISTRACTION_MODE_LIMIT <= rx_vehicle_info.vehicle_speed_real )
    {
    is_activated = true;
    }
return is_activated;
}

/*********************************************************************
*
* @public
* VI_is_function_supported
*
* Return if the vehicle function is supported
*
* @return The vehicle function supported or not
*
*********************************************************************/
bool VI_is_function_supported
    (
    const EnumVehicleSupportedFunction function
    )
{
return ( ( rx_vehicle_supported_functions >> function ) & 0x1 );
}

/*********************************************************************
*
* @public
* VI_notify_ydt_detected
*
* Notify if the YDT is detected
*
*********************************************************************/
void VI_notify_ydt_detected
    (
    void
    )
{
EW_notify_vi_data_received( EnumVehicleRxTypeYDT_DETECTED );
}

/*********************************************************************
*
* @public
* VI_get_rx_data_uint
*
* Get vehicle rx data of uint32 type
*
* @param rx_type Rx data type
* @param data    The pointer to the rx data
* @return        The validity of vehicle rx data
*
*********************************************************************/
bool VI_get_rx_data_uint
    (
    const EnumVehicleRxType rx_type,
    uint32_t* data
    )
{
bool is_valid = true;

switch( rx_type )
    {
    case EnumVehicleRxTypeENGINE_SPEED:
        *data = rx_ecu_info.engine_speed;
        break;
    case EnumVehicleRxTypeTC_MODE:
        *data = rx_ecu_info.tc_mode;
        break;
    case EnumVehicleRxTypeVVA_INDICATOR:
        *data = rx_ecu_info.vva_indicator;
        break;
    case EnumVehicleRxTypeTFT_BRIGHTNESS_LEVEL:
        *data = rx_brightness_control.tft_brightness_level;
        break;
    case EnumVehicleRxTypeMETER_BRIGHTNESS_LEVEL:
        *data = rx_brightness_control.lcd_brightness_level;
        break;
    case EnumVehicleRxTypeMILEAGE_UNIT:
        *data = rx_unit_setting.mileage_unit;
        break;
    case EnumVehicleRxTypePRESSURE_UNIT:
        *data = rx_unit_setting.pressure_unit;
        break;
    case EnumVehicleRxTypeTEMPERATURE_UNIT:
        *data = rx_unit_setting.temperature_unit;
        break;
    case EnumVehicleRxTypeFUEL_CONSUMPTION_UNIT:
        *data = rx_unit_setting.fuel_consumption_unit;
        break;
    case EnumVehicleRxTypeRANGE_DISTANCE:
        if( INVALID_RANGE_DISTANCE != rx_fuel_rate.range_distance_km )
            {
            *data = rx_fuel_rate.range_distance_km;
            }
        else
            {
            is_valid = false;
            }
        break;
    case EnumVehicleRxTypeAVERAGE_SPEED:
        if( INVALID_AVERAGE_SPEED != rx_fuel_rate.average_speed_km )
            {
            *data = rx_fuel_rate.average_speed_km;
            }
        else
            {
            is_valid = false;
            }
        break;
    case EnumVehicleRxTypeAPS_ANGLE:
        *data = ( rx_vehicle_info.aps_angle_deg * 125 ) >> 10;
        break;
    case EnumVehicleRxTypeVEHICLE_SPEED_REAL:
        *data = rx_vehicle_info.vehicle_speed_real;
        break;
    case EnumVehicleRxTypeVEHICLE_SPEED_METER:
        *data = rx_vehicle_info.vehicle_speed_meter;
        break;
    case EnumVehicleRxTypeCLOCK_ADJUSTMENT_STATUS:
        *data = rx_vehicle_info.clock_adj_status;
        break;
    case EnumVehicleRxTypeCRUISE_SPEED:
        if( INVALID_CRUISE_SPEED != rx_vehicle_info.cruise_speed )
            {
            *data = rx_vehicle_info.cruise_speed;
            }
        else
            {
            is_valid = false;
            }
        break;
    case EnumVehicleRxTypeLOW_FUEL_WARNING:
        *data = rx_vehicle_info.low_fuel_warning;
        break;
    case EnumVehicleRxTypeFUEL_RESERVE:
        *data = rx_vehicle_info.fuel_reserve;
        break;
    case EnumVehicleRxTypeODO_TRIP_DISPLAY:
        *data = rx_vehicle_info.odo_trip_display;
        break;
    case EnumVehicleRxTypeF_TRIP_HARD_RESET:
        *data = rx_vehicle_info.fuel_trip_hard_reset;
        break;
    case EnumVehicleRxTypeMAINTENANCE_TRIP1:
        if( INVALID_MAINTENANCE_TRIP != rx_maintenance_trip.trip1_km )
            {
            *data = rx_maintenance_trip.trip1_km;
            }
        else
            {
            is_valid = false;
            }
        break;
    case EnumVehicleRxTypeMAINTENANCE_TRIP2:
        if( INVALID_MAINTENANCE_TRIP != rx_maintenance_trip.trip2_km )
            {
            *data = rx_maintenance_trip.trip2_km;
            }
        else
            {
            is_valid = false;
            }
        break;
    case EnumVehicleRxTypeMAINTENANCE_TRIP3:
        if( INVALID_MAINTENANCE_TRIP != rx_maintenance_trip.trip3_km )
            {
            *data = rx_maintenance_trip.trip3_km;
            }
        else
            {
            is_valid = false;
            }
        break;
    case EnumVehicleRxTypeGRIP_WARMER_VALUE_LOW:
        if( INVALID_HEATER_VALUE != rx_grip_warmer_status.value_low )
            {
            *data = rx_grip_warmer_status.value_low;
            }
        else
            {
            is_valid = false;
            }
        break;
    case EnumVehicleRxTypeGRIP_WARMER_VALUE_MIDDLE:
        if( INVALID_HEATER_VALUE != rx_grip_warmer_status.value_middle )
            {
            *data = rx_grip_warmer_status.value_middle;
            }
        else
            {
            is_valid = false;
            }
        break;
    case EnumVehicleRxTypeGRIP_WARMER_VALUE_HIGH:
        if( INVALID_HEATER_VALUE != rx_grip_warmer_status.value_high )
            {
            *data = rx_grip_warmer_status.value_high;
            }
        else
            {
            is_valid = false;
            }
        break;
    case EnumVehicleRxTypeSEAT_HEATER_VALUE_LOW:
        if( INVALID_HEATER_VALUE != rx_seat_heater_status.value_low )
            {
            *data = rx_seat_heater_status.value_low;
            }
        else
            {
            is_valid = false;
            }
        break;
    case EnumVehicleRxTypeSEAT_HEATER_VALUE_MIDDLE:
        if( INVALID_HEATER_VALUE != rx_seat_heater_status.value_middle )
            {
            *data = rx_seat_heater_status.value_middle;
            }
        else
            {
            is_valid = false;
            }
        break;
    case EnumVehicleRxTypeSEAT_HEATER_VALUE_HIGH:
        if( INVALID_HEATER_VALUE != rx_seat_heater_status.value_high )
            {
            *data = rx_seat_heater_status.value_high;
            }
        else
            {
            is_valid = false;
            }
        break;
    case EnumVehicleRxTypeGRIP_WARMER_STATUS:
        *data = rx_grip_warmer_status.setting;
        break;
    case EnumVehicleRxTypeSEAT_HEATER_STATUS:
        *data = rx_seat_heater_status.setting;
        break;
    case EnumVehicleRxTypeTRIP_TIME:
        is_valid = vi_trip_time_get_current( data );
        break;
    case EnumVehicleRxTypeTIRE_SENSOR_EQUIPPED:
        *data = (uint32_t)rx_tire_pressure.sensor_equipped;
        break;
    default:
        PRINTF( "Err: %s invalid rx type %d\r\n", __FUNCTION__, rx_type );
        is_valid = false;
        break;
    }
return is_valid;
}

/*********************************************************************
*
* @public
* VI_get_rx_data_float
*
* Get vehicle rx data of float type
*
* @param rx_type Rx data type
* @param data    The pointer to the rx data
* @return        The validity of vehicle rx data
*
*********************************************************************/
bool VI_get_rx_data_float
    (
    const EnumVehicleRxType rx_type,
    float* data
    )
{
bool is_valid = true;

switch( rx_type )
    {
    case EnumVehicleRxTypeFUEL_RATE_INSTANT:
        if( INVALID_INSTANT_CONSUMPTION != rx_fuel_rate.instant_consumption )
            {
            *data = rx_fuel_rate.instant_consumption * 0.1;
            }
        else
            {
            is_valid = false;
            }
        break;
    case EnumVehicleRxTypeFUEL_RATE_AVERAGE:
        if( INVALID_AVERAGE_CONSUMPTION != rx_fuel_rate.average_consumption )
            {
            *data = rx_fuel_rate.average_consumption * 0.1;
            }
        else
            {
            is_valid = false;
            }
        break;
    case EnumVehicleRxTypeODOMETER_VALUE:
        if( INVALID_ODO_VALUE != rx_odo_trip.odo_value_km )
            {
            *data = rx_odo_trip.odo_value_km * 0.1;
            }
        else
            {
            is_valid = false;
            }
        break;
    case EnumVehicleRxTypeTRIP1_VALUE:
        if( INVALID_TRIP1_VALUE != rx_odo_trip.trip1_value_km )
            {
            *data = rx_odo_trip.trip1_value_km * 0.1;
            }
        else
            {
            is_valid = false;
            }
        break;
    case EnumVehicleRxTypeTRIP2_VALUE:
        if( INVALID_TRIP2_VALUE != rx_odo_trip.trip2_value_km )
            {
            *data = rx_odo_trip.trip2_value_km * 0.1;
            }
        else
            {
            is_valid = false;
            }
        break;
    case EnumVehicleRxTypeFUEL_CONSUMPTION:
        if( INVALID_FUEL_CONS != rx_vehicle_info.fuel_cons )
            {
            *data = rx_vehicle_info.fuel_cons * 0.1;
            }
        else
            {
            is_valid = false;
            }
        break;
    case EnumVehicleRxTypeAIR_TEMPERATURE:
        if( INVALID_AIR_TEMPERATURE != rx_vehicle_info.air_temperature )
            {
            *data = rx_vehicle_info.air_temperature * 160 / 256.0 - 30;
            }
        else
            {
            is_valid = false;
            }
        break;
    case EnumVehicleRxTypeCOOLANT_TEMPERATURE:
        if( INVALID_COOLANT_TEMPERATURE != rx_vehicle_info.coolant_temperature )
            {
            *data = rx_vehicle_info.coolant_temperature * 160 / 256.0 - 30;
            }
        else
            {
            is_valid = false;
            }
        break;
    case EnumVehicleRxTypeBATTERY_VOLTAGE:
        if( INVALID_BATTERY_VOLTAGE != rx_vehicle_info.battery_voltage )
            {
            *data = rx_vehicle_info.battery_voltage * 18.75 / 256.0;
            }
        else
            {
            is_valid = false;
            }
        break;
    case EnumVehicleRxTypeTRIP_F_VALUE:
        if( INVALID_FUEL_TRIPMETER != rx_vehicle_info.fuel_tripmeter_km )
            {
            *data = rx_vehicle_info.fuel_tripmeter_km * 0.1;
            }
        else
            {
            is_valid = false;
            }
        break;
    case EnumVehicleRxTypeTIRE_FRONT:
        *data = rx_tire_pressure.front * 0.2;
        break;
    case EnumVehicleRxTypeTIRE_REAR:
        *data = rx_tire_pressure.rear * 0.2;
        break;
    default:
        PRINTF( "Err: %s invalid rx type %d\r\n", __FUNCTION__, rx_type );
        is_valid = false;
        break;
    }
return is_valid;
}

/*********************************************************************
*
* @private
* set_sfl
*
* Set SFL bit
*
* @param sfl Pointer to SFL
* @param function vehicle function
* @param supported True or false
*
*********************************************************************/
static void set_sfl
    (
    uint32_t* sfl,
    const EnumVehicleSupportedFunction function,
    const bool supported
    )
{
if( supported )
    {
    set_bit( *sfl, function );
    }
}

/*********************************************************************
*
* @public
* VI_write_supported_function_callback
*
* Callback of writing supported function from EEPROM
*
* @param result True if write success. False if read fail.
* @param value Pointer to the supported function of uint8_t* type
*
*********************************************************************/
void VI_write_supported_function_callback
    (
    bool  result,
    void* value
    )
{
if( !result )
    {
    uint8_t* supported_functions = (uint8_t*)value;
    PRINTF( "%s false, 0x%02x %02x %02x %02x %02x\r\n", __FUNCTION__, supported_functions[0], supported_functions[1], supported_functions[2],
                                                                      supported_functions[3], supported_functions[4], supported_functions[5] );
    }
}

/*********************************************************************
*
* @private
* set_supported_function
*
* Set supported function
*
* @param supported_functions Supported functions of uint8 data array
* @param data_source Data source of supported functions
*
*********************************************************************/
static void set_supported_function
    (
    uint8_t* supported_functions,
    const supported_func_data_src_enum data_source
    )
{
uint32_t last_supported_functions = 0;
uint32_t sfl_diff = 0;
bool     is_tacho_setting_changed = false;

if( pdTRUE == xSemaphoreTake( supported_function_semaphore_handle, ticks_to_wait ) )
    {
    PRINTF( "%s %d\r\n", __FUNCTION__, data_source );
    if( SUPPORTED_FUNCTION_DATA_SOURCE_CAN == supported_func_data_source &&
        SUPPORTED_FUNCTION_DATA_SOURCE_EEPROM == data_source )
        {
        // data from CAN has higher priority than data from EEPROM, so ignore
        PRINTF( "%s ignore eep data\r\n", __FUNCTION__ );
        }
    else
        {
        supported_func_data_source = data_source;
        last_supported_functions = rx_vehicle_supported_functions;

        if( rx_tacho_setting.fullscale != supported_functions[0] )
            {
            rx_tacho_setting.fullscale = supported_functions[0];
            is_tacho_setting_changed = true;
            }
        if( rx_tacho_setting.redzone != supported_functions[1] )
            {
            rx_tacho_setting.redzone = supported_functions[1];
            is_tacho_setting_changed = true;
            }
        rx_vehicle_supported_functions = ( supported_functions[5] << 24 ) | ( supported_functions[4] << 16 ) |
                                         ( supported_functions[3] << 8 ) | supported_functions[2];

        // Notify UI if the supported functions are changed
        sfl_diff = last_supported_functions ^ rx_vehicle_supported_functions;
        if( ( sfl_diff >> EnumVehicleSupportedFunctionCLOCK ) & 0x1 )
            {
            EW_notify_vi_data_received( EnumVehicleRxTypeSUPPORT_FUNC_CLOCK );
            }
        if( ( sfl_diff >> EnumVehicleSupportedFunctionGRIP_WARMER ) & 0x1 )
            {
            EW_notify_vi_data_received( EnumVehicleRxTypeSUPPORT_FUNC_GRIP_WARMER );
            }
        if( ( sfl_diff >> EnumVehicleSupportedFunctionSEAT_HEATER ) & 0x1 )
            {
            EW_notify_vi_data_received( EnumVehicleRxTypeSUPPORT_FUNC_SEAT_HEATER );
            }
        if( ( sfl_diff >> EnumVehicleSupportedFunctionWIND_SCREEN ) & 0x1 )
            {
            EW_notify_vi_data_received( EnumVehicleRxTypeSUPPORT_FUNC_WIND_SCREEN );
            }
        if( ( sfl_diff >> EnumVehicleSupportedFunctionAIR_TEMPERATURE ) & 0x1 )
            {
            EW_notify_vi_data_received( EnumVehicleRxTypeSUPPORT_FUNC_AIR_TEMPERATURE );
            }

        // write to EEPROM when the data from CAN is different
        if( SUPPORTED_FUNCTION_DATA_SOURCE_CAN == data_source &&
            ( is_tacho_setting_changed || ( 0 != sfl_diff ) ) )
            {
            PRINTF( "%s w\r\n", __FUNCTION__ );
            // MSB of byte 5 is used for checking if data is valid. (0: valid. 1: invalid)
            clear_bit( supported_functions[5], 7 );
            EEPM_set_supported_function( supported_functions, &VI_write_supported_function_callback );
            }
        }

    xSemaphoreGive( supported_function_semaphore_handle );
    }
}

/*********************************************************************
*
* @public
* VI_set_supported_function
*
* Set vehicle supported function
*
* @param function vehicle supported function
* @param supported Supported status
*
*********************************************************************/
void VI_set_supported_function
    (
    const EnumVehicleSupportedFunction function,
    const bool supported
    )
{
static uint8_t supported_functions[SUPPORTED_FUNCTION_LENGTH];
uint32_t sfl = rx_vehicle_supported_functions;

if( supported )
    {
    set_bit( sfl, function );
    }
else
    {
    clear_bit( sfl, function );
    }

supported_functions[0] = rx_tacho_setting.fullscale;
supported_functions[1] = rx_tacho_setting.redzone;
supported_functions[2] = sfl & 0xFF;
supported_functions[3] = ( sfl >> 8 ) & 0xFF;
supported_functions[4] = ( sfl >> 16 ) & 0xFF;
supported_functions[5] = ( sfl >> 24 ) & 0xFF;

set_supported_function( supported_functions, SUPPORTED_FUNCTION_DATA_SOURCE_UI );
}

/*********************************************************************
*
* @public
* VI_rx_support_function_received
*
* Notify from CAN stack that vehicle support functions received
*
* @param support_functions
*
*********************************************************************/
void VI_rx_support_function_received
    (
    const mid_msg_supp_func_t* const support_functions
    )
{
uint8_t  supported_functions[SUPPORTED_FUNCTION_LENGTH];
uint32_t sfl = 0;

PRINTF( "%s, grip warmer: %d\r\n", __FUNCTION__, support_functions->sfl.bit.grip_warmer );
PRINTF( "%s, seat heater: %d\r\n", __FUNCTION__, support_functions->sfl.bit.seat_heater );

set_sfl( &sfl, EnumVehicleSupportedFunctionTRIP1, support_functions->sfl.bit.trip1 );
set_sfl( &sfl, EnumVehicleSupportedFunctionTRIP2, support_functions->sfl.bit.trip2 );
set_sfl( &sfl, EnumVehicleSupportedFunctionF_TRIP, support_functions->sfl.bit.Ftrip );
set_sfl( &sfl, EnumVehicleSupportedFunctionMETER_BRIGHTNESS_ADJ, support_functions->sfl.bit.mt_brgtnss_adj );
set_sfl( &sfl, EnumVehicleSupportedFunctionCLOCK, support_functions->sfl.bit.clk );
set_sfl( &sfl, EnumVehicleSupportedFunctionTCS, support_functions->sfl.bit.tcs );
set_sfl( &sfl, EnumVehicleSupportedFunctionGRIP_WARMER, support_functions->sfl.bit.grip_warmer );
set_sfl( &sfl, EnumVehicleSupportedFunctionSEAT_HEATER, support_functions->sfl.bit.seat_heater );
set_sfl( &sfl, EnumVehicleSupportedFunctionWIND_SCREEN, support_functions->sfl.bit.wind_scrn );
set_sfl( &sfl, EnumVehicleSupportedFunctionOIL_TRIP, support_functions->sfl.bit.oil_trip );
set_sfl( &sfl, EnumVehicleSupportedFunctionV_BELT_TRIP, support_functions->sfl.bit.Vbelt_trip );
set_sfl( &sfl, EnumVehicleSupportedFunctionFREE_1, support_functions->sfl.bit.Free1 );
set_sfl( &sfl, EnumVehicleSupportedFunctionFREE_2, support_functions->sfl.bit.Free2 );
set_sfl( &sfl, EnumVehicleSupportedFunctionAVG_SPEED, support_functions->sfl.bit.avg_spd );
set_sfl( &sfl, EnumVehicleSupportedFunctionCURRENT_FUEL, support_functions->sfl.bit.crt_fuel );
set_sfl( &sfl, EnumVehicleSupportedFunctionAVG_FUEL, support_functions->sfl.bit.avg_fuel );
set_sfl( &sfl, EnumVehicleSupportedFunctionFUEL_CONSUMPTION, support_functions->sfl.bit.fuel_cons );
set_sfl( &sfl, EnumVehicleSupportedFunctionAIR_TEMPERATURE, support_functions->sfl.bit.air );
set_sfl( &sfl, EnumVehicleSupportedFunctionBATTERY_VOLTAGE, support_functions->sfl.bit.bat );
set_sfl( &sfl, EnumVehicleSupportedFunctionCOOLANT, support_functions->sfl.bit.coolant );
set_sfl( &sfl, EnumVehicleSupportedFunctionRANGE_DISTANCE, support_functions->sfl.bit.rng );
set_sfl( &sfl, EnumVehicleSupportedFunctionTIRE_FRONT, support_functions->sfl.bit.tire_frnt );
set_sfl( &sfl, EnumVehicleSupportedFunctionTIRE_FRONT_RIGHT, support_functions->sfl.bit.tire_frnt_r );
set_sfl( &sfl, EnumVehicleSupportedFunctionTIRE_FRONT_LEFT, support_functions->sfl.bit.tire_frnt_l );
set_sfl( &sfl, EnumVehicleSupportedFunctionTIRE_REAR, support_functions->sfl.bit.tire_rear );
set_sfl( &sfl, EnumVehicleSupportedFunctionTRIP_TIME, support_functions->sfl.bit.tip_time );
set_sfl( &sfl, EnumVehicleSupportedFunctionCRUISE, support_functions->sfl.bit.cruise );

supported_functions[0] = support_functions->tcfs;
supported_functions[1] = support_functions->brzegr;
supported_functions[2] = sfl & 0xFF;
supported_functions[3] = ( sfl >> 8 ) & 0xFF;
supported_functions[4] = ( sfl >> 16 ) & 0xFF;
supported_functions[5] = ( sfl >> 24 ) & 0xFF;

set_supported_function( supported_functions, SUPPORTED_FUNCTION_DATA_SOURCE_CAN );
}

/*********************************************************************
*
* @private
* VI_rx_reprogram_info_response
*
* Callback function of reprogram info response (CAN message H'5AF)
*
* @param svc_id Signal id
* @param svc_data_size Response data size
* @param svc_data_p Pointer to the response data
*
*********************************************************************/
void VI_rx_reprogram_info_response
    (
    const uint8_t  svc_type,
    const uint8_t  svc_id,
    const uint8_t  svc_data_size,
    const uint8_t* svc_data_p
    )
{
if( svc_type == MID_MSG_NRES_NACK )
    {
    switch( svc_id )
        {
        case MID_MSG_NRES_RS_NOT_SUPP:

            break;

        case MID_MSG_NRES_RS_WAIT_REQ:
            //Nothing to do ( Middle layer handles it )
            break;

        default:
            PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, svc_id);
            break;
        }
    }
else
    {
    switch( svc_id )
        {
        default:
            PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, svc_id);
            break;
        }
    }
}

/*********************************************************************
*
* @private
* VI_rx_mt_func_cont_info_response
*
* Callback function of reset meter info response (CAN message H'585)
*
* @param svc_id Signal id
* @param svc_data_size Response data size
* @param svc_data_p Pointer to the response data
*
*********************************************************************/
void VI_rx_mt_func_cont_info_response
    (
    const uint8_t  svc_id,
    const uint8_t  svc_data_size,
    const uint8_t* svc_data_p
    )
{
switch( svc_id )
    {
    default:
        PRINTF( "%s unknown signal id: 0x%x\r\n", __FUNCTION__, svc_id);
        break;
    }
}

/*********************************************************************
*
* @private
* init_supported_function
*
* Init supported functions
*
*********************************************************************/
static void init_supported_function
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
uint8_t  init_value[SUPPORTED_FUNCTION_LENGTH];
uint32_t sfl = 0;

set_sfl( &sfl, EnumVehicleSupportedFunctionOIL_TRIP, true );
set_sfl( &sfl, EnumVehicleSupportedFunctionCURRENT_FUEL, true );
set_sfl( &sfl, EnumVehicleSupportedFunctionAVG_FUEL, true );
set_sfl( &sfl, EnumVehicleSupportedFunctionTRIP_TIME, true );

init_value[0] = DEFAULT_TACHO_FULLSCALE;
init_value[1] = DEFAULT_TACHO_REDZONE;
init_value[2] = sfl & 0xFF;
init_value[3] = ( sfl >> 8 ) & 0xFF;
init_value[4] = ( sfl >> 16 ) & 0xFF;
init_value[5] = ( sfl >> 24 ) & 0xFF;

set_supported_function( init_value, SUPPORTED_FUNCTION_DATA_SOURCE_EEPROM );
}

/*********************************************************************
*
* @private
* init_rx_data
*
* Set initial value of rx data defined in CAN requirement spec
*
*********************************************************************/
static void init_rx_data
    (
    void
    )
{
rx_unit_setting.mileage_unit     = MILEAGE_UNIT_KM;
rx_unit_setting.pressure_unit    = PRESSURE_UNIT_PSI;
rx_unit_setting.temperature_unit = TEMPERATURE_UNIT_DEG_C;
rx_unit_setting.fuel_consumption_unit = FUEL_CONSUMPTION_UNIT_L_100KM;

rx_fuel_rate.instant_consumption = INVALID_INSTANT_CONSUMPTION;
rx_fuel_rate.average_consumption = INVALID_AVERAGE_CONSUMPTION;
rx_fuel_rate.range_distance_km   = INVALID_RANGE_DISTANCE;
rx_fuel_rate.average_speed_km    = INVALID_AVERAGE_SPEED;

rx_odo_trip.odo_value_km   = INVALID_ODO_VALUE;
rx_odo_trip.trip1_value_km = INVALID_TRIP1_VALUE;
rx_odo_trip.trip2_value_km = INVALID_TRIP2_VALUE;

rx_vehicle_info.fuel_cons           = INVALID_FUEL_CONS;
rx_vehicle_info.air_temperature     = INVALID_AIR_TEMPERATURE;
rx_vehicle_info.coolant_temperature = INVALID_COOLANT_TEMPERATURE;
rx_vehicle_info.battery_voltage     = INVALID_BATTERY_VOLTAGE;
rx_vehicle_info.cruise_speed        = INVALID_CRUISE_SPEED;
rx_vehicle_info.fuel_tripmeter_km   = INVALID_FUEL_TRIPMETER;
rx_vehicle_info.odo_trip_display    = ODO_TRIP_DISPLAY_ODO;

rx_maintenance_trip.trip1_km = INVALID_MAINTENANCE_TRIP;
rx_maintenance_trip.trip2_km = INVALID_MAINTENANCE_TRIP;
rx_maintenance_trip.trip3_km = INVALID_MAINTENANCE_TRIP;

rx_ecu_info.tc_mode = TCS_MODE_ON;

rx_grip_warmer_status.value_low    = DEFAULT_GRIP_WARMER_LOW_VALUE;
rx_grip_warmer_status.value_middle = DEFAULT_GRIP_WARMER_MIDDLE_VALUE;
rx_grip_warmer_status.value_high   = DEFAULT_GRIP_WARMER_HIGH_VALUE;
rx_grip_warmer_status.setting      = HEATER_SETTING_OFF;

rx_seat_heater_status.value_low    = DEFAULT_SEAT_HEATER_LOW_VALUE;
rx_seat_heater_status.value_middle = DEFAULT_SEAT_HEATER_MIDDLE_VALUE;
rx_seat_heater_status.value_high   = DEFAULT_SEAT_HEATER_HIGH_VALUE;
rx_seat_heater_status.setting      = HEATER_SETTING_OFF;

rx_vehicle_info.clock_adj_status   = false;

rx_brightness_control.lcd_brightness_level = DEFALUT_LCD_BRIGHTNESS_LEVEL;
rx_brightness_control.tft_brightness_level = DEFALUT_TFT_BRIGHTNESS_LEVEL;
rx_brightness_control.tft_duty             = DEFALUT_TFT_DUTY;
}

/*********************************************************************
*
* @public
* VI_read_supported_function_callback
*
* Callback of reading supported function from EEPROM
*
* @param result True if read success. False if read fail.
* @param value Pointer to the supported function of uint8_t* type
*
*********************************************************************/
void VI_read_supported_function_callback
    (
    bool  result,
    void* value
    )
{
bool     is_valid = false;
uint8_t* supported_functions = (uint8_t*)value;

if( result )
    {
    PRINTF( "rd sf %02x%02x%02x%02x%02x%02x\r\n", supported_functions[0], supported_functions[1], supported_functions[2],
                                                  supported_functions[3], supported_functions[4], supported_functions[5] );
    // The initial data from EEPROM is all 0xFF.
    // MSB of byte 5 is used for checking if the supported function from EEPROM is valid.
    // (0: valid. 1: invalid)
    if( 0 == ( supported_functions[5] & 0x80 ) )
        {
        is_valid = true;
        }
    }
else
    {
    PRINTF( "rd supported func fail\r\n" );
    }

if( is_valid )
    {
    set_supported_function( supported_functions, SUPPORTED_FUNCTION_DATA_SOURCE_EEPROM );
    }
else
    {
    // used initial value when fail to get supported function from EEPROM
    init_supported_function();
    }
}

/*********************************************************************
*
* @private
* vi_rx_init
*
* Init vi rx
*
*********************************************************************/
void vi_rx_init
    (
    void
    )
{
supported_function_semaphore_handle = xSemaphoreCreateBinary();
configASSERT( NULL != supported_function_semaphore_handle );
xSemaphoreGive( supported_function_semaphore_handle );

if( pdFALSE == EEPM_get_supported_function( &VI_read_supported_function_callback ) )
    {
    PRINTF( "get supported func fail\r\n" );
    }

init_rx_data();
}
