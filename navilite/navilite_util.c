/*********************************************************************
* @file
* navilite_util.c
*
* @brief
* NaviLight module - main
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "limits.h"
#include "task.h"
#include "semphr.h"
#include "ewrte.h"
#include "fsl_debug_console.h"
#include "EW_pub.h"
#include "NAVILITE_pub.h"

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
* @public
* NAVILITE_float_to_bytes
*
* convert float value to data bytes
* @param float_value float value
* @return the data bytes of float value
*
*********************************************************************/
uint32_t NAVILITE_float_to_bytes
    (
    float float_value
    )
{
    uint32_t bytes_value;
    memcpy( &bytes_value, &float_value, sizeof( bytes_value ) );
    return bytes_value;
}

/*********************************************************************
*
* @public
* NAVILITE_bytes_to_float
*
* convert bytes data to float
* @param bytes_value float value
* @return float value
*
*********************************************************************/
float NAVILITE_bytes_to_float
    (
    uint32_t bytes_value
    )
{
    float float_value = 0;
    memcpy( &float_value, &bytes_value, sizeof( float_value ) );
    return float_value;
}

/*********************************************************************
*
* @public
* NAVILITE_print_utf8
*
* print string to console  character by character
* @param str string pointer
* @param str_size string size
*
*********************************************************************/
void NAVILITE_print_utf8
    (
    uint8_t* str,
    uint16_t str_size
    )
{
int i = 0;
PRINTF("[");
for( i = 0; i < str_size; i++ )
    {
    PRINTF( "%c", (char)str[i] );
    }
PRINTF("]");
}

/*********************************************************************
*
* @public
* NAVILITE_print_frame
*
* print navilite frame info
* @param msg frame message pointer to print
*
*********************************************************************/
void NAVILITE_print_frame
    (
    navilite_message* msg
    )
{
PRINTF("\r\n --- NAVILITE FRAME INFO ---\r\n");
PRINTF("Frame Type:");
switch( msg->frame_type )
    {
    case NAVILITE_FRAMETYPE_MOBILE_REQUEST:
        PRINTF("FRAMETYPE_MOBILE_REQUEST");
        break;
    case NAVILITE_FRAMETYPE_MOBILE_RESPONSE:
        PRINTF("FRAMETYPE_MOBILE_RESPONSE");
        break;
    case NAVILITE_FRAMETYPE_MOBILE_UPDATE:
        PRINTF("FRAMETYPE_MOBILE_UPDATE");
        break;
    case NAVILITE_FRAMETYPE_MCU_REQUEST:
        PRINTF("FRAMETYPE_MCU_REQUEST");
        break;
    case NAVILITE_FRAMETYPE_MCU_RESPONSE:
        PRINTF("FRAMETYPE_MCU_RESPONSE");
        break;
    case NAVILITE_FRAMETYPE_MCU_UPDATE:
        PRINTF("FRAMETYPE_MCU_UPDATE");
        break;
    default:
        PRINTF( "OTHER FRAMETYPE CODE UNDEFINED:0x%x",  msg->frame_type );
        break;
    }

PRINTF("\r\nService Type:");
switch( msg->service_type )
    {
    case NAVILITE_SERVICETYPE_IMAGEFRAME_UPDATE:
        PRINTF( "IMAGEFRAME_UPDATE" );
        break;
    case NAVILITE_SERVICETYPE_ETA_UPDATE:
        PRINTF( "ETA_UPDATE" );
        break;
    case NAVILITE_SERVICETYPE_NAVIGATION_STATUS_UPDATE:
        PRINTF( "NAVIGATION_STATUS_UPDATE" );
        break;
    case NAVILITE_SERVICETYPE_CURROADNAME_UPDATE:
        PRINTF( "CURROADNAME_UPDATE" );
        break;
    case NAVILITE_SERVICETYPE_NEXTTURNDIST_UPDATE:
        PRINTF( "NEXTTURNDIST_UPDATE" );
        break;
    case NAVILITE_SERVICETYPE_TBTLIST_UPDATE:
        PRINTF( "TBTLIST_UPDATE" );
        break;
    case NAVILITE_SERVICETYPE_ACTIVETURBLIST_UPDATE:
        PRINTF( "ACTIVETURBLIST_UPDATE" );
        break;
    case NAVILITE_SERVICETYPE_FAVPOITURNLIST_UPDATE:
        PRINTF( "FAVPOITURNLIST_UPDATE" );
        break;
    case NAVILITE_SERVICETYPE_NEARBYGASSTATIONLIST_UPDATE:
        PRINTF( "NEARBYGASSTATIONLIST_UPDATE" );
        break;
    case NAVILITE_SERVICETYPE_NAVIEVENTTEXTUPDATE:
        PRINTF( "NAVIEVENTTEXTUPDATE" );
        break;
    case NAVILITE_SERVICETYPE_HOMESETTING_UPDATE:
        PRINTF( "HOMESETTING_UPDATE" );
        break;
    case NAVILITE_SERVICETYPE_OFFICESETTING_UPDATE:
        PRINTF( "OFFICESETTING_UPDATE" );
        break;
    case NAVILITE_SERVICETYPE_MAP_ZOOM_LEVEL_UPDATE:
        PRINTF( "MAP_ZOOM_LEVEL_UPDATE" );
        break;
    case NAVILITE_SERVICETYPE_ROUTE_CALC_PROGRESS_UPDATE:
        PRINTF( "ROUTE_CALC_PROGRESS_UPDATE" );
        break;
    case NAVILITE_SERVICETYPE_DAYNIGHT_MODE_UPDATE:
        PRINTF( "DAYNIGHT_MODE_UPDATE" );
        break;
    case NAVILITE_SERVICETYPE_BT_THROUGHPUT_TIMEOUT_UPDATE:
        PRINTF( "BT_THROUGHPUT_TIMEOUT_UPDATE" );
        break;
    case NAVILITE_SERVICETYPE_SPEED_LIMIT_UPDATE:
        PRINTF( "SPEED_LIMIT_UPDATE" );
        break;
    case NAVILITE_SERVICETYPE_VIA_POINT_COUNT_UPDATE:
        PRINTF( "VIA_POINT_COUNT_UPDATE" );
        break;
    case NAVILITE_SERVICETYPE_DIALOG_EVENT_UPDATE:
        PRINTF( "DIALOG_EVENT_UPDATE" );
        break;
    case NAVILITE_SERVICETYPE_IMAGEFRAME_UPDATE_ACK:
        PRINTF( "IMAGEFRAME_UPDATE_ACK" );
        break;
    case NAVILITE_SERVICETYPE_MCU_ESN_UPDATE_ACK:
        PRINTF( "MCU_ESN_UPDATE_ACK" );
        break;
    case NAVILITE_SERVICETYPE_AUTH_REQUEST_ACK:
        PRINTF( "AUTH_REQUEST_ACK" );
        break;
    case NAVILITE_SERVICETYPE_AUTH_REQUEST_NACK:
        PRINTF( "AUTH_REQUEST_NACK" );
        break;
    case NAVILITE_SERVICETYPE_AUTH_REQUEST:
        PRINTF( "AUTH_REQUEST" );
        break;
    // Note: Mobile request types
    case NAVILITE_SERVICETYPE_APP_START_ROUTE_REQUEST:
        PRINTF( "APP_START_ROUTE_REQUEST" );
        break;
    case NAVILITE_SERVICETYPE_APP_STOP_ROUTE_REQUEST:
        PRINTF( "APP_STOP_ROUTE_REQUEST" );
        break;
    case NAVILITE_SERVICETYPE_APP_SKIP_NEXT_WAYPOINT_REQUEST:
        PRINTF( "APP_SKIP_NEXT_WAYPOINT_REQUEST" );
        break;
    case NAVILITE_SERVICETYPE_APP_MAP_ZOOM_IN_REQUEST:
        PRINTF( "APP_MAP_ZOOM_IN_REQUEST" );
        break;
    case NAVILITE_SERVICETYPE_APP_MAP_ZOOM_OUT_REQUEST:
        PRINTF( "APP_MAP_ZOOM_OUT_REQUEST" );
        break;
    case NAVILITE_SERVICETYPE_APP_GO_HOME_REQUEST:
        PRINTF( "APP_GO_HOME_REQUEST" );
        break;
    case NAVILITE_SERVICETYPE_APP_GO_OFFICE_REQUEST:
        PRINTF( "APP_GO_OFFICE_REQUEST" );
        break;
    case NAVILITE_SERVICETYPE_APP_START_CONTENT_UPDATE_REQUEST:
        PRINTF( "APP_START_CONTENT_UPDATE_REQUEST" );
        break;
    case NAVILITE_SERVICETYPE_APP_STOP_CONTENT_UPDATE_REQUEST:
        PRINTF( "APP_STOP_CONTENT_UPDATE_REQUEST" );
        break;
    case NAVILITE_SERVICETYPE_APP_START_IMAGE_FRAME_REQUEST:
        PRINTF( "START_IMAGE_FRAME_REQUEST(Obsolete)" );
        break;
    case NAVILITE_SERVICETYPE_APP_STOP_IMAGE_FRAME_REQUEST:
        PRINTF( "APP_STOP_IMAGE_FRAME_REQUEST(Obsolete)" );
        break;
    // Note: MCU report types
    case NAVILITE_SERVICETYPE_MCU_METER_SPEED_UPDATE:
        PRINTF( "MCU_METER_SPEED_UPDATE" );
        break;
    case NAVILITE_SERVICETYPE_MCU_ESN_UPDATE:
        PRINTF( "MCU_ESN_UPDATE" );
        break;
    case NAVILITE_SERVICETYPE_MCU_SYSINFO_UPDATE:
        PRINTF( "MCU_SYSINFO_UPDATE" );
        break;
    case NAVILITE_SERVICETYPE_MCU_DIALOG_USER_SELECT_UPDATE:
        PRINTF( "MCU_DIALOG_USER_SELECT_UPDATE" );
        break;
    // Note: Appendix
    case NAVILITE_SERVICETYPE_TBTLIST_DATA_UPDATE:
        PRINTF( "TBTLIST_DATA_UPDATE" );
        break;
    default:
        PRINTF( "OTHER SERVICE CODE UNDEFINED:0x%x",  msg->service_type );
        break;
    }
PRINTF( "\r\nPayLoad Type:%d", msg->payload_data_type );
PRINTF( "\r\nPayload Size:%d", msg->payload_size );
PRINTF( "\r\nPayload value:%d\r\n", msg->data_value );
}

/*********************************************************************
*
* @public
* NAVILITE_print_raw_data
*
* print the raw data bytes
* @param data data pointer to print
* @param data_len byte length of data pointer
*
*********************************************************************/
void NAVILITE_print_raw_data
    (
    uint8_t* data,
    uint8_t data_len
    )
{
PRINTF( "== HEX DATA DUMP ===\r\n" );
for( int i = 0; i < data_len; i++ )
    {
    PRINTF( "%x ,", data[i] );
    }
PRINTF( "\r\n" );
}
