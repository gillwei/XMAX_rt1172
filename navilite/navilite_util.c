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
int i = 0;

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
    case NAVILITE_SERVICETYPE_IMAGEFRAME_UPDATE_ACK:
        PRINTF( "IMAGEFRAME_UPDATE_ACK" );
        break;
    case NAVILITE_SERVICETYPE_ETA_UPDATE:
        PRINTF( "ETA_UPDATE:" );
        char tmp[255];
        strncpy( tmp, (char*)msg->data_pointer, msg->payload_size );
        tmp[msg->payload_size] = 0;
        for( i = 0; i < msg->payload_size; i++ )
            {
            PRINTF( "%c", msg->data_pointer[i] );
            }
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
        PRINTF( "ZOOMLEVEL_UPDATE" );
        break;
    case NAVILITE_SERVICETYPE_ROUTE_CALC_PROGRESS_UPDATE:
        PRINTF( "ROUTE_CALC_PROGRESS_UPDATE" );
        break;
    case NAVILITE_SERVICETYPE_BT_QUALITY_UPDATE:
        PRINTF( "NAVILITE_SERVICETYPE_BT_QUALITY_UPDATE" );
        break;
    case NAVILITE_SERVICETYPE_VIA_POINT_COUNT_UPDATE:
        PRINTF( "VIA_POINT_COUNT_UPDATE" );
        break;
    default:
        PRINTF( "OTHER SERVICE CODE UNDEFINED:0x%x",  msg->service_type );
        break;
    }
PRINTF( "\r\nPayLoad Type:%d",msg->payload_data_type);
PRINTF( "\r\nPayload Size:%d\r\n", msg->payload_size );
PRINTF( "\r\nPayload value:%d\r\n", msg->data_value );
}
