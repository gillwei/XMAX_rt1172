/*********************************************************************
* @file
* VI_pub.h
*
* @brief
* Vehicle information module - public API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef VI_PUB_H
#define VI_PUB_H

#ifdef __cplusplus
extern "C"{
#endif

#include <stdbool.h>
#include <stdint.h>
#include "vi_priv.h"
#include "CAN_pub.h"
#include "Enum.h"
#include "RTC_pub.h"

#define CAN_TIMEOUT_ERROR_1     ( 1 )
#define CAN_TIMEOUT_ERROR_2     ( 2 )

#define TCS_MODE_OFF            ( 0 )
#define TCS_MODE_ON             ( 1 )

#define INVALID_INSTANT_CONSUMPTION         ( 0x3FF )
#define INVALID_AVERAGE_CONSUMPTION         ( 0x3FF )
#define INVALID_RANGE_DISTANCE              ( 0x3FF )
#define INVALID_AVERAGE_SPEED               ( 0x3FF )

#define INVALID_ODO_VALUE                   ( 0xFFFFFF )
#define INVALID_TRIP1_VALUE                 ( 0xFFFFF )
#define INVALID_TRIP2_VALUE                 ( 0xFFFFF )

#define INVALID_FUEL_CONS                   ( 0x1FFF )
#define INVALID_AIR_TEMPERATURE             ( 0xFF )
#define INVALID_COOLANT_TEMPERATURE         ( 0xFF )
#define INVALID_BATTERY_VOLTAGE             ( 0xFF )
#define INVALID_CRUISE_SPEED                ( 0xFF )
#define INVALID_FUEL_TRIPMETER              ( 0x3FFF )

#define INVALID_MAINTENANCE_TRIP            ( 0x3FFFF )

#define INVALID_HEATER_VALUE                ( 0xF )

#define DEFAULT_GRIP_WARMER_LOW_VALUE       ( 0x1 )
#define DEFAULT_GRIP_WARMER_MIDDLE_VALUE    ( 0x5 )
#define DEFAULT_GRIP_WARMER_HIGH_VALUE      ( 0xA )

#define DEFAULT_SEAT_HEATER_LOW_VALUE       ( 0x1 )
#define DEFAULT_SEAT_HEATER_MIDDLE_VALUE    ( 0x5 )
#define DEFAULT_SEAT_HEATER_HIGH_VALUE      ( 0xA )

#define DEFALUT_LCD_BRIGHTNESS_LEVEL        ( 0x0 )
#define DEFALUT_TFT_BRIGHTNESS_LEVEL        ( 0x3 )
#define DEFALUT_TFT_DUTY                    ( 0x3FF )

#define DEFAULT_TACHO_FULLSCALE             ( 0xFF )
#define DEFAULT_TACHO_REDZONE               ( 0xFF )

void VI_init( void );
void VI_key_set_trigger_mode( const CoreKeyCode key_code, const EnumKeyTriggerMode trigger_mode );
void VI_key_set_magic_key_enabled( const bool enabled );
bool VI_is_key_state_valid( void );
void VI_notify_vehicle_cyc_frm_changed( const il_rx_frm_index_t msg_idx, const uint16_t sig_hnd, const uint32_t data );
void VI_notify_vehicle_event_frm_changed( const il_rx_frm_index_t msg_idx, const can_msg_t* msg_data_p );
bool VI_is_dd_mode_activated( void );
bool VI_is_function_supported( const EnumVehicleSupportedFunction feature );
void VI_set_supported_function( const EnumVehicleSupportedFunction feature, const bool supported );
void VI_set_tx_data( int tx_data_type, uint64_t data );
bool VI_get_rx_data_uint( const EnumVehicleRxType rx_type, uint32_t* data );
bool VI_get_rx_data_float( const EnumVehicleRxType rx_type, float* data );
void VI_rx_support_function_received( const mid_msg_supp_func_t* const support_functions );
void VI_rx_reprogram_info_response( const uint8_t  svc_type, const uint8 svc_id, const uint8 svc_data_size, const uint8* svc_data_p );
void VI_rx_mt_func_cont_info_response( const uint8 svc_id, const uint8 svc_data_size, const uint8* svc_data_p );
void VI_send_inspection_response( const EnumInspectionMode mode, const uint8_t fainsres );
void VI_notify_ydt_detected( void );
void VI_trip_time_count( void );
void VI_trip_time_save( void );
void VI_clock_notify_meter_time_updated( const snvs_lp_srtc_datetime_t datetime );
void VI_clock_send_rtc_time_to_meter( void );

#ifdef __cplusplus
}
#endif

#endif /* VI_PUB_H */

