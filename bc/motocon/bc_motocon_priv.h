/*********************************************************************
* @file
* bc_motocon_priv.h
*
* @brief
* MotoConSDK module - private api
*
* Copyright 2020-2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef BC_MOTOCON_PRIV_H
#define BC_MOTOCON_PRIV_H

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <stdint.h>
#include "fsl_debug_console.h"
#include <BC_motocon_pub.h>

/*--------------------------------------------------------------------
                          LITERAL CONSTANTS
--------------------------------------------------------------------*/
#if( ENABLE_MOTOCON_DEBUG_LOG )
    #define BC_MOTOCON_PRINTF PRINTF
#else
    #define BC_MOTOCON_PRINTF(fmt,...)
#endif

#define BC_MOTOCON_CALLBACK_MAX                     ( 5 )

#define BC_MOTOCON_DDT_INACTIVE_ID                  ( 0 )
#define BC_MOTOCON_DDT_STATUS_LENGTH                ( 2 )
#define BC_MOTOCON_DDT_TO_VEHICLE_BUFFER_SIZE       ( 1000 ) // This is an estimated value due to protobuf's length will change by its content.

#define BC_MOTOCON_DDT_HEADER_SIZE                  ( 4 )
#define BC_MOTOCON_DDT_TO_PHONE_CONTENT_SIZE        ( 24 ) /* this value shall more than 1 */
#define BC_MOTOCON_DDT_TO_PHONE_TOTAL_PACKAGE_SIZE  ( BC_MOTOCON_DDT_TO_PHONE_CONTENT_SIZE + BC_MOTOCON_DDT_HEADER_SIZE )
#define BC_MOTOCON_PROTOBUF_HEADER_SIZE             ( 5 )

/*--------------------------------------------------------------------
                                TYPES
--------------------------------------------------------------------*/
typedef enum
    {
    BC_MOTOCON_PARSE_SUCCESS,
    BC_MOTOCON_PARSE_INVALID_COMMAND_CODE,
    BC_MOTOCON_PARSE_INVALID_INPUT
    } bc_motocon_parse_result_t;

typedef enum
    {
    BC_MOTOCON_NOTIFY,
    BC_MOTOCON_DDT_TO_VEHICLE_STATUS_READ_RESPONSE,
    BC_MOTOCON_DDT_TO_VEHICLE_STATUS_NOTIFY,
    BC_MOTOCON_DDT_TO_PHONE_CONTROL_NOTIFY,
    BC_MOTOCON_DDT_TO_PHONE_DATA_NOTIFY,
    BC_MOTOCON_DDT_VEHICLE_INFORMATION_CONTROL_NOTIFY,
    BC_MOTOCON_DDT_VEHICLE_INFORMATION_DATA_NOTIFY,
    BC_MOTOCON_DDT_CAN_CONTROL_NOTIFY,
    BC_MOTOCON_DDT_CAN_DATA_NOTIFY
    } bc_motocon_send_type_t;


typedef enum
    {
    BC_MOTOCON_DDT_TO_VEHICLE,
    BC_MOTOCON_DDT_TO_PHONE,
    BC_MOTOCON_DDT_VEHICLE_INFORMATION,
    BC_MOTOCON_DDT_CAN
    } bc_motocon_ddt_type_t;
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
#define TWO_BYTE_BIG( bytes, position )        ( ( bytes[position] << 8 ) | bytes[position + 1] )
#define THREE_BYTE_BIG( bytes, position )      ( ( bytes[position] << 16 ) | ( bytes[position + 1] << 8 ) | bytes[position + 2] )
#define FOUR_BYTE_BIG( bytes, position )       ( ( bytes[position] << 24 ) | ( bytes[position + 1] << 16 ) | ( bytes[position + 2] << 8 ) | bytes[position + 3] )

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
void bc_motocon_ddt_init( void );
void bc_motocon_ddt_reset( void );
const uint8_t* bc_motocon_ddt_get_ddt_to_vehicle_status( void );
const uint8_t* bc_motocon_ddt_set_ddt_to_vehicle_status( const uint8_t* bytes );
const uint8_t* bc_motocon_ddt_insert_ddt_to_vehicle_data( const uint8_t* bytes, const uint32_t length );
bc_motocon_send_result_t bc_motocon_ddt_send_ddt_to_phone_data( const bc_motocon_command_code_t command, const uint8_t* bytes, const uint32_t length, void ( *result_callback ) ( const bc_motocon_send_result_t ) );
void bc_motocon_ddt_received_ddt_to_phone_ack( const bc_motocon_ddt_type_t type );

void bc_motocon_parser_write_received( const uint8_t* bytes, const uint32_t length );
void bc_motocon_parser_ddt_to_vehicle_received( const uint8_t* bytes, const uint32_t length );
bc_motocon_parse_result_t bc_motocon_parser_weather_location( const uint8_t* bytes, const uint32_t length );
bc_motocon_parse_result_t bc_motocon_parser_weather_info( const uint8_t* bytes, const uint32_t length );
bc_motocon_parse_result_t bc_motocon_parser_vehicle_info_subscribe( const uint8_t* bytes, const uint32_t length );
bc_motocon_parse_result_t bc_motocon_parser_datetime_changed( const uint8_t* bytes, const uint32_t length );
bc_motocon_parse_result_t bc_motocon_parser_vehicle_datetime( const uint8_t* bytes, const uint32_t length );
bc_motocon_parse_result_t bc_motocon_parser_language_type( const uint8_t* bytes, const uint32_t length );
bc_motocon_parse_result_t bc_motocon_parser_short_data_to_can( const bc_motocon_command_code_t command_code, const uint8_t* bytes, const uint32_t length );
bc_motocon_parse_result_t bc_motocon_parser_protobuf_to_can( const bc_motocon_command_code_t command_code, const uint8_t* bytes, const uint32_t length );
bc_motocon_parse_result_t bc_motocon_parser_can_request( void );
bc_motocon_parse_result_t bc_motocon_parser_injection_request( void );
bc_motocon_parse_result_t bc_motocon_parser_battery( const uint8_t* bytes, const uint32_t length );
bc_motocon_parse_result_t bc_motocon_parser_bt_music_meta_data( const uint8_t* bytes, const uint32_t length );
bc_motocon_parse_result_t bc_motocon_parser_incoming_call_info( const uint8_t* bytes, const uint32_t length );
bc_motocon_parse_result_t bc_motocon_parser_thermal( const uint8_t* bytes, const uint32_t length );
bc_motocon_parse_result_t bc_motocon_parser_bt_headset_state( const uint8_t* bytes, const uint32_t length );
bc_motocon_parse_result_t bc_motocon_parser_volume_level( const uint8_t* bytes, const uint32_t length );
bc_motocon_parse_result_t bc_motocon_parser_notification_category( const uint8_t* bytes, const uint32_t length );
bc_motocon_parse_result_t bc_motocon_parser_volume_controllable( const uint8_t* bytes, const uint32_t length );
bc_motocon_parse_result_t bc_motocon_parser_ota_update_info( const uint8_t* bytes, const uint32_t length );
bc_motocon_parse_result_t bc_motocon_parser_notification_v2( const uint8_t* bytes, const uint32_t length );

void bc_motocon_init( void );
void bc_motocon_set_connected( bool connected );
bc_motocon_send_result_t bc_motocon_send_data( const bc_motocon_send_type_t type, const uint8_t* bytes, const uint32_t length );
void bc_motocon_parse_error_handler( const bc_motocon_command_code_t type, const bc_motocon_parse_result_t result, const char* message );

void bc_motocon_listener_init( void );

#ifdef __cplusplus
}
#endif

#endif  /* BC_MOTOCON_PRIV_H */
