/*********************************************************************
*
* @file
* NAVILITE_pub_protocol.h - NAVILITE protocol header specific declarations
*
* @brief
* NAVILITE protocol header file
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/


#ifndef NAVILITE_PUB_PROTOCOL_H
#define NAVILITE_PUB_PROTOCOL_H

#if defined( __cplusplus )
extern "C"
{
#endif

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <stdint.h>  // for uint8_t etc
#include <stdbool.h> // for bool
#include <stddef.h>  // for NULL
#include <string.h>  // for memset()

/*--------------------------------------------------------------------
                          LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define MAGIC_CODE "nAl@"
#define MAGIC_CODE_SIZE 4
#define PROTOCOL_VERSION ( 1 )
#define HEADER_SIZE ( 255 )
#define MAX_PAYLOAD_SIZE ( 31 * 1024 * 1024 )

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/

//Types used for protocol encoding

typedef enum tagNAVILITE_MESSAGE_OFFSET_TYPE {
    FIELD_MAGICCODE_OFFSET = 0,
    FIELD_VERSION_OFFSET = 4,
    FIELD_FRAMETYPE_OFFSET = 5,
    FIELD_SERVICETYPE_OFFSET = 6,
    FIELD_PAYLOADSIZE_OFFSET = 7,
    FIELD_PAYLOADDATATYPE_OFFSET = 11,
    FIELD_PAYLOADVALUE_OFFSET = 12,
    FIELD_PAYLOADDATA_OFFSET = 12
} navilite_message_offset;

#pragma pack(push) /* push current alignment to stack */
#pragma pack(1) /* set alignment to 1 byte boundary */

typedef struct tagNAVILITE_MESSAGE_TYPE
    {
    uint8_t       magic_code[MAGIC_CODE_SIZE]; // 4
    uint8_t       version;                     // 1
    uint8_t       frame_type;                  // 1
    uint8_t       service_type;                // 1
    uint32_t      payload_size;                // 4, data size for data_value or data_pointer
    uint8_t       payload_data_type;           // 0 - value type (16bit), 1 - pointer
    uint16_t      data_value;
    uint8_t*      data_pointer;
    } navilite_message;

#pragma pack(pop)

typedef enum tagNAVILITE_CONNECTION_RESILT_TYPE
    {
    NAVILITE_CONNECTION_SUCCESS,
    NAVILITE_CONNECTION_FAIL,
    NAVILITE_CONNECTION_TIMEOUT,
    NAVILITE_CONNECTION_LOST,
    } navilite_connection_result_type;

typedef enum tagNAVILITE_PAYLOAD_DATA_TYPE
    {
    NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE = 0,
    NAVILITE_PAYLOAD_DATA_TYPE_AS_POINTER = 1
    } navilite_payload_data_type;

typedef enum tagNAVILITE_DAYNIGHT_MODE_TYPE
    {
    NAVILITE_DAYNIGHTMODE_AUTO = 0, // NOTE: let mcu to decide day or night itself
    NAVILITE_DAYNIGHTMODE_DAY = 1,
    NAVILITE_DAYNIGHTMODE_NIGHT = 2
    } navilite_daynight_mode_type;

typedef enum tagNAVILITE_FRAME_TYPE
    {
    NAVILITE_FRAMETYPE_MOBILE_REQUEST = 0x01,
    NAVILITE_FRAMETYPE_MOBILE_RESPONSE = 0x02,
    NAVILITE_FRAMETYPE_MOBILE_UPDATE = 0x03,
    NAVILITE_FRAMETYPE_MCU_REQUEST = 0x04,
    NAVILITE_FRAMETYPE_MCU_RESPONSE = 0x05,
    NAVILITE_FRAMETYPE_MCU_UPDATE = 0x06
    } navilite_frame_type;

typedef enum tagNAVILITE_SERVICE_TYPE
    {
    // Navi Content update types
    NAVILITE_SERVICETYPE_IMAGEFRAME_UPDATE = 0x00,               //! type: NAVI/JCV/FAV/GAS
    NAVILITE_SERVICETYPE_ETA_UPDATE = 0x01,
    NAVILITE_SERVICETYPE_REMAINDIST_UPDATE = 0x02,
    NAVILITE_SERVICETYPE_CURROADNAME_UPDATE = 0x03,
    NAVILITE_SERVICETYPE_NEXTTURNDIST_UPDATE = 0x04,
    NAVILITE_SERVICETYPE_TBTLIST_UPDATE = 0x05,
    NAVILITE_SERVICETYPE_ACTIVETURBLIST_UPDATE = 0x06,
    NAVILITE_SERVICETYPE_FAVPOITURNLIST_UPDATE = 0x07,           //! TBD
    NAVILITE_SERVICETYPE_NEARBYGASSTATIONLIST_UPDATE = 0x08,     //! TBD
    NAVILITE_SERVICETYPE_NAVIEVENTTEXTUPDATE = 0x09,
    NAVILITE_SERVICETYPE_HOMESETTING_UPDATE = 0x0a,
    NAVILITE_SERVICETYPE_OFFICESETTING_UPDATE = 0x0b,
    NAVILITE_SERVICETYPE_HARDKEY_ENABLE_UPDATE = 0x0c,
    NAVILITE_SERVICETYPE_HARDKEY_CODE_UPDATE = 0x0d,            //! REMOVE
    NAVILITE_SERVICETYPE_MAP_ZOOM_LEVEL_UPDATE = 0x0e,
    NAVILITE_SERVICETYPE_ROUTE_CALC_PROGRESS_UPDATE = 0x0f,
    NAVILITE_SERVICETYPE_DAYNIGHT_MODE_UPDATE = 0x1f,
    // Other info update
    NAVILITE_SERVICETYPE_BT_QUALITY_UPDATE = 0x10,
    // Speed Limit
    NAVILITE_SERVICETYPE_SPEED_LIMIT_UPDATE = 0x11,
    // Update Via Point Count
    NAVILITE_SERVICETYPE_VIA_POINT_COUNT_UPDATE = 0x12,
    // Recent List
    NAVILITE_SERVICETYPE_RECENTLIST_UPDATE = 0x13,
    // Dialog
    NAVILITE_SERVICETYPE_DIALOG_PROMPT_UPDATE = 0x20,
    // ACK types
    NAVILITE_SERVICETYPE_IMAGEFRAME_UPDATE_ACK = 0x50,
    NAVILITE_SERVICETYPE_MCU_ESN_UPDATE_ACK = 0x51,
    NAVILITE_SERVICETYPE_AUTH_REQUEST_ACK = 0x52,
    NAVILITE_SERVICETYPE_AUTH_REQUEST_NACK = 0x53,
    // Auth Request
    NAVILITE_SERVICETYPE_AUTH_REQUEST = 0x21,
    // App Request types
    NAVILITE_SERVICETYPE_APP_START_ROUTE_REQUEST = 0x30, // index = 0, default route, >=1 by index
    NAVILITE_SERVICETYPE_APP_STOP_ROUTE_REQUEST = 0x31,
    NAVILITE_SERVICETYPE_APP_SKIP_NEXT_WAYPOINT_REQUEST = 0x32,
    NAVILITE_SERVICETYPE_APP_MAP_ZOOM_IN_REQUEST = 0x33,
    NAVILITE_SERVICETYPE_APP_MAP_ZOOM_OUT_REQUEST = 0x34,
    NAVILITE_SERVICETYPE_APP_GO_HOME_REQUEST = 0x35,
    NAVILITE_SERVICETYPE_APP_GO_OFFICE_REQUEST = 0x36,
    NAVILITE_SERVICETYPE_APP_GET_FAVORITE_LIST_REQUEST = 0x37,
    NAVILITE_SERVICETYPE_APP_GET_STATION_LIST_REQUEST = 0x38,
    NAVILITE_SERVICETYPE_APP_START_IMAGE_FRAME_REQUEST = 0x39,
    NAVILITE_SERVICETYPE_APP_STOP_IMAGE_FRAME_REQUEST = 0x40,
    NAVILITE_SERVICETYPE_APP_GET_RECENT_LIST_REQUEST = 0x22,
    // Meter info notification/update
    NAVILITE_SERVICETYPE_MCU_METER_SPEED_UPDATE = 0x41,
    NAVILITE_SERVICETYPE_MCU_ESN_UPDATE         = 0x42,
    NAVILITE_SERVICETYPE_MCU_SYSINFO_UPDATE     = 0x45,
    NAVILITE_SERVICETYPE_MCU_VEHICLE_FUEL_UPDATE= 0x43,
    NAVILITE_SERVICETYPE_MCU_KEYCODE_UPDATE = 0x44,
    } navilite_service_type;

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

#if defined( __cplusplus )
}
#endif

#endif /* NAVILITE_PUB_PROTOCOL_H */