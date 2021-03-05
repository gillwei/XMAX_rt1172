/*********************************************************************
* @file
* test_motocon.c
*
* @brief
* Test module - MotoCon
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "fsl_debug_console.h"
#include "Enum.h"
#include "BTM_pub.h"
#include "BC_motocon_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/

void ddt_can_result( const bc_motocon_send_result_t result )
{
EwPrint( "ddt_can_result %d\r\n", result );
}

void ddt_can_related_result( const bc_motocon_send_result_t result )
{
EwPrint( "ddt_can_related_result %d\r\n", result );
}
/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/
static uint8_t data[50];

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @public
* TEST_motocon_tx
*
* Test MotoCon send command
*
* @param test_item Test item of EnumMotoConTest type
*
*********************************************************************/
void TEST_motocon_tx
    (
    const int test_item
    )
{
PRINTF( "%s %d\r\n", __FUNCTION__, test_item );
switch( test_item )
    {
    case EnumMotoConTestSTART_BLE_ADVERTISING:
        BTM_set_ble_advertisement( true );
        break;
    case EnumMotoConTestSTOP_BLE_ADVERTISING:
        BTM_set_ble_advertisement( false );
        break;
    case EnumMotoConTestLIBRATY_VERSION:
        BC_motocon_send_lib_version( 1, 2, 3 );
        break;
    case EnumMotoConTestWEATHER_REQ:
        BC_motocon_send_weather_request();
        break;
    case EnumMotoConTestVEHICLE_INFO:
        {
        bc_motocon_vehicle_info_t info;
        BC_motocon_send_vehicle_info( &info );
        }
        break;
    case EnumMotoConTestVEHICLE_SETTING_REQ:
        BC_motocon_send_vehicle_setting_request();
        break;
    case EnumMotoConTestLANG_TYPE_REQ:
        BC_motocon_send_language_type_request();
        break;
    case EnumMotoConTestCAN_RELATED_DATA:
        {
        BC_motocon_send_can_related_data( BC_MOTOCON_COMMAND_CODE_FFD_RESPONSE, 50, data, &ddt_can_related_result );
        BC_motocon_send_can_related_data( BC_MOTOCON_COMMAND_CODE_VEHICLE_INFORMATION_RESPONSE, 50, data, &ddt_can_related_result );
        BC_motocon_send_can_related_data( BC_MOTOCON_COMMAND_CODE_AUTHENTICATION_V2_RESPONSE, 1, data, &ddt_can_related_result );
        }
        break;
    case EnumMotoConTestCAN_RESPONSE:
        {
        BC_motocon_send_can_response( 50, data, &ddt_can_result );
        }
        break;
    case EnumMotoConTestINJECTION_QUALITY:
        {
        uint8_t quantity[4];
        BC_motocon_send_injection_quantity( quantity );
        }
        break;
    case EnumMotoConTestMUSIC_CONTROL_PLAY:
        BC_motocon_send_bt_music_control( BC_MOTOCON_MUSIC_PLAY );
        break;
    case EnumMotoConTestMUSIC_CONTROL_PAUSE:
        BC_motocon_send_bt_music_control( BC_MOTOCON_MUSIC_PAUSE );
        break;
    case EnumMotoConTestMUSIC_CONTROL_PREVIOUS:
        BC_motocon_send_bt_music_control( BC_MOTOCON_MUSIC_PREVIOUS_TRACK );
        break;
    case EnumMotoConTestMUSIC_CONTROL_NEXT:
        BC_motocon_send_bt_music_control( BC_MOTOCON_MUSIC_NEXT_TRACK );
        break;
    case EnumMotoConTestINCOMING_CALL_ANSWER:
        BC_motocon_send_incoming_call_control( BC_MOTOCON_CALL_ANSWER );
        break;
    case EnumMotoConTestINCOMING_CALL_DECLINE:
        BC_motocon_send_incoming_call_control( BC_MOTOCON_CALL_REJECT );
        break;
    case EnumMotoConTestHEADSET_STATE_REQ:
        BC_motocon_send_headset_state_request();
        break;
    case EnumMotoConTestVOLUME_CONTROL_UP:
        BC_motocon_send_volume_control( BC_MOTOCON_VOLUME_UP );
        break;
    case EnumMotoConTestVOLUME_CONTROL_DOWN:
        BC_motocon_send_volume_control( BC_MOTOCON_VOLUME_DOWN );
        break;
    case EnumMotoConTestVOLUME_CONTROLLABLE_REQ:
        BC_motocon_send_volume_controllable_request();
        break;
    case EnumMotoConTestCREATE_OTA_REQ:
        BC_motocon_send_create_ota_request();
        break;
    default:
        PRINTF( "Err: invalid motocon test type %d\r\n", test_item );
        break;
    }
}
