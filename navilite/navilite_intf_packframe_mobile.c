/*********************************************************************
* @file
* navilite_intf_packframe_mobile.c
*
* @brief
* NaviLite protocol framing APIs for mobile
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/* NOTE: this is updated from MCU header to keep the protocol consistent from ECU and mobile apps, please do not change this file*/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "NAVILITE_pub.h"
#include "TEST_pub.h"
#include "fsl_debug_console.h"

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
#if( UNIT_TEST_NAVILITE )
    static uint8_t packet_buffer[ 250 ];
#endif

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

#if( NAVILITE_BUILD_ROLE == NAVILITE_TARGET_MOBILE || NAVILITE_LOCAL_HMI_TEST_MODE || UNIT_TEST_NAVILITE )
    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_update_imageframe
    *
    * Send image frame update request
    *
    * @param image image data to send
    * @param image_size image size
    * @param mode image mode
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_update_imageframe
        (
        uint8_t* image,
        uint32_t image_size,
        navilite_image_type mode
        )
    {
    navilite_message frame = { 0 };
    memcpy( (char*)frame.magic_code, (unsigned char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MCU_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_IMAGEFRAME_UPDATE;
    frame.payload_size = image_size;
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_POINTER;
    frame.data_pointer = image;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_update_eta
    *
    * Send eta update request
    *
    * @param value etc value to send
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_update_eta
        (
        uint32_t value
        )
    {
    navilite_message frame = { 0 };
    uint8_t* packValues = (uint8_t*)malloc( sizeof( uint32_t ) );

    memcpy( (uint8_t*)packValues, (uint8_t*)&value, sizeof( uint32_t ) );
    memcpy( (char*)frame.magic_code, (unsigned char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MCU_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_ETA_UPDATE;
    frame.payload_size = sizeof( uint32_t );
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_POINTER;
    frame.data_pointer = packValues;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_update_navigationstatus
    *
    * Send navigation status update request
    *
    * @param value navigation status value to send
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_update_navigationstatus
        (
        uint8_t value
        )
    {
    navilite_message frame = { 0 };
    memcpy( (char*)frame.magic_code, (unsigned char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MCU_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_NAVIGATION_STATUS_UPDATE;
    frame.payload_size = sizeof( uint16_t );
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE;
    frame.data_value = value;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_update_speedlimit
    *
    * Send speed limit update request
    *
    * @param value speed limit value to send
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_update_speedlimit
        (
        uint16_t value
        )
    {
    navilite_message frame = { 0 };
    memcpy( (char*)frame.magic_code, (unsigned char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MCU_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_SPEED_LIMIT_UPDATE;
    frame.payload_size = sizeof( uint16_t );
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE;
    frame.data_value = value;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_update_viapointcount
    *
    * Send via point count update request
    *
    * @param via_point_count via point count to send
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_update_viapointcount
        (
        uint16_t via_point_count
        )
    {
    navilite_message frame = { 0 };
    memcpy( (char*)frame.magic_code, (unsigned char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MCU_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_VIA_POINT_COUNT_UPDATE;
    frame.payload_size = sizeof( uint16_t );
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE;
    frame.data_value = (uint16_t)via_point_count;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_update_currentroadname
    *
    * Send current road update request
    *
    * @param via_point_count via point count to send
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_update_currentroadname
        (
        uint8_t* str,
        uint8_t str_size
        )
    {
    navilite_message frame = { 0 };
    memcpy( (char*)frame.magic_code, (unsigned char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MCU_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_CURROADNAME_UPDATE;
    frame.payload_size = str_size;
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_POINTER;
    frame.data_pointer = str;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_update_nextturndistance
    *
    * Send next turn distance update request
    *
    * @param icon_index icon index
    * @param str string data
    * @param str_size size of string data
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_update_nextturndistance
        (
        uint8_t icon_index,
        uint8_t* str,
        uint8_t str_size
        )
    {
    navilite_message frame = { 0 };
    uint32_t payload_size = sizeof( icon_index ) + sizeof( str_size ) + (uint32_t)strlen( (char*)str );
    // NOTE: this type of API will put the non-text data first, then text data.
    uint8_t* frame_data = (uint8_t*)malloc( payload_size );
    // append the icon index byte
    memcpy( frame_data, &icon_index, sizeof( icon_index ) );
    // append the data size byte
    memcpy( frame_data + sizeof( icon_index ), &str_size, sizeof( str_size ) );
    // append the rest string bytes
    memcpy( frame_data + sizeof( icon_index ) + sizeof( str_size ), str, str_size );
    // compose a navilite update frame
    memcpy( (char*)frame.magic_code, (unsigned char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MCU_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_NEXTTURNDIST_UPDATE;
    frame.payload_size = payload_size;
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_POINTER;
    frame.data_pointer = frame_data;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_update_nexttbtlist
    *
    * Send turn by turn list update request
    *
    * @param list_size tbt list size
    * @param has_more_data has more data on next request
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_update_nexttbtlist
        (
        uint16_t list_size,
        uint8_t has_more_data
        )
    {
    navilite_message frame = { 0 };
    uint8_t payload_size = sizeof( uint8_t ) * 3; // uint16_t + uint8_t
    uint8_t* packValues = (uint8_t*)malloc( payload_size );
    memcpy( (uint16_t*)packValues, (uint16_t*)&list_size, sizeof( uint16_t ) );
    memcpy( (uint8_t*)packValues + sizeof( uint16_t ), (uint8_t*)&has_more_data, sizeof( uint8_t ) );

    memcpy( (char*)frame.magic_code, (unsigned char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MCU_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_TBTLIST_UPDATE;
    frame.payload_size = payload_size;
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_POINTER;
    frame.data_pointer = packValues;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_update_nexttbtlist_itemdata
    *
    * Send next turn by turn list item data update request
    *
    * @param list pointer of tbt list
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_update_nexttbtlist_itemdata
        (
        navilite_tbt_list_type* list
        )
    {
    navilite_message frame = { 0 };

    uint32_t payload_size = sizeof( list->list_item_index ) +   // data size for storing uint32_t list index size
            sizeof( list->icon_index ) +                        // data size for storing uint8_t icon index size
            sizeof( list->desc_size ) +                         // data size for storing uint8_t desc size
            sizeof( list->dist_unit_size ) +                    // data size for storing uint8_t unit size
            sizeof( list->distance ) +                          // data size for storing uint16 distance
            list->dist_unit_size +                              // data size for storing distance unit string
            list->desc_size;                                    // data size for storing description

    // NOTE: this type of API will put the non-text data first, then text data.
    uint8_t* frame_data = (uint8_t*)packet_buffer;

    // fill the data into frame_data
    int offset = 0;
    memcpy( frame_data, &list->list_item_index, offset = sizeof( list->list_item_index ) );
    memcpy( frame_data + offset, &list->icon_index, sizeof( list->icon_index ) );
    offset += sizeof( list->icon_index );
    memcpy( frame_data + offset, &list->desc_size, sizeof( list->desc_size ) );
    offset += sizeof( list->desc_size );
    memcpy( frame_data + offset, &list->dist_unit_size, sizeof( list->dist_unit_size ) );
    offset += sizeof( list->dist_unit_size );
    memcpy( frame_data + offset, &list->distance, sizeof( list->distance ) );
    offset += sizeof( list->distance );
    memcpy( frame_data + offset, list->distance_unit, list->dist_unit_size );
    offset += list->dist_unit_size;
    memcpy( frame_data + offset, list->desc, list->desc_size );

    memcpy( (char*)frame.magic_code, (unsigned char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MCU_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_TBTLIST_DATA_UPDATE;

    // calculate how much payload it needs for list_size * each list payload
    frame.payload_size = payload_size;
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_POINTER;
    frame.data_pointer = frame_data;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_update_activetbtitem
    *
    * Send active tbt list item
    *
    * @param active_tbt_item_index active list index
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_update_activetbtitem
        (
        uint16_t active_tbt_item_index
        )
    {
    navilite_message frame = { 0 };
    memcpy( (char*)frame.magic_code, (unsigned char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MCU_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_ACTIVETURBLIST_UPDATE;
    frame.payload_size = sizeof( uint16_t );
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE;
    frame.data_value = active_tbt_item_index;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_update_nextfavlist
    *
    * Send next fav list item data update request
    *
    * @param list_size fav list size
    * @param has_more_data has more data on next request
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_update_nextfavlist
        (
        uint16_t list_size,
        uint8_t has_more_data
        )
    {
    navilite_message frame = { 0 };
    uint8_t payload_size = sizeof( uint8_t ) * 3; // uint16_t + uint8_t
    uint8_t* packValues = (uint8_t*)malloc( payload_size );
    memcpy( (uint16_t*)packValues, (uint16_t*)&list_size, sizeof( uint16_t ) );
    memcpy( (uint8_t*)packValues + sizeof( uint16_t ), (uint8_t*)&has_more_data, sizeof( uint8_t ) );

    memcpy( (char*)frame.magic_code, (unsigned char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MCU_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_FAVPOILIST_UPDATE;
    frame.payload_size = payload_size;
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_POINTER;
    frame.data_pointer = packValues;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_update_nextfavlist_itemdata
    *
    * Send next fav list item data update request
    *
    * @param list pointer of fav list
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_update_nextfavlist_itemdata
        (
        navilite_fav_list_type* list
        )
    {
    navilite_message frame = { 0 };

    uint32_t payload_size = sizeof( list->list_item_index ) +   // data size for storing uint32_t list index size
            sizeof( list->desc_size ) +                         // data size for storing uint8_t desc size
            sizeof( list->dist_unit_size ) +                    // data size for storing uint8_t unit size
            sizeof( list->distance ) +                          // data size for storing uint16 distance
            list->dist_unit_size +                              // data size for storing distance unit string
            list->desc_size;                                    // data size for storing description

    // NOTE: this type of API will put the non-text data first, then text data.
    uint8_t* frame_data = (uint8_t*)packet_buffer;

    // fill the data into frame_data
    int offset = 0;
    memcpy( frame_data, &list->list_item_index, offset = sizeof( list->list_item_index ) );
    memcpy( frame_data + offset, &list->desc_size, sizeof( list->desc_size ) );
    offset += sizeof( list->desc_size );
    memcpy( frame_data + offset, &list->dist_unit_size, sizeof( list->dist_unit_size ) );
    offset += sizeof( list->dist_unit_size );
    memcpy( frame_data + offset, &list->distance, sizeof( list->distance ) );
    offset += sizeof( list->distance );
    memcpy( frame_data + offset, list->distance_unit, list->dist_unit_size );
    offset += list->dist_unit_size;
    memcpy( frame_data + offset, list->desc, list->desc_size );

    memcpy( (char*)frame.magic_code, (unsigned char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MCU_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_FAVPOILIST_DATA_UPDATE;

    // calculate how much payload it needs for list_size * each list payload
    frame.payload_size = payload_size;
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_POINTER;
    frame.data_pointer = frame_data;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_update_nextgaslist
    *
    * Send next gas list item data update request
    *
    * @param list_size gas list size
    * @param has_more_data has more data on next request
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_update_nextgaslist
        (
        uint16_t list_size,
        uint8_t has_more_data
        )
    {
    navilite_message frame = { 0 };
    uint8_t payload_size = sizeof( uint8_t ) * 3; // uint16_t + uint8_t
    uint8_t* packValues = (uint8_t*)malloc( payload_size );
    memcpy( (uint16_t*)packValues, (uint16_t*)&list_size, sizeof( uint16_t ) );
    memcpy( (uint8_t*)packValues + sizeof( uint16_t ), (uint8_t*)&has_more_data, sizeof( uint8_t ) );

    memcpy( (char*)frame.magic_code, (unsigned char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MCU_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_GASPOILIST_UPDATE;
    frame.payload_size = payload_size;
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_POINTER;
    frame.data_pointer = packValues;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_update_nextgaslist_itemdata
    *
    * Send next gas list item data update request
    *
    * @param list pointer of gas list
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_update_nextgaslist_itemdata
        (
        navilite_fav_list_type* list
        )
    {
    navilite_message frame = { 0 };

    uint32_t payload_size = sizeof( list->list_item_index ) +  // data size for storing uint32_t list index size
            sizeof( list->desc_size ) +                       // data size for storing uint8_t desc size
            sizeof( list->dist_unit_size ) +                  // data size for storing uint8_t unit size
            sizeof( list->distance ) +                       // data size for storing uint16 distance
            list->dist_unit_size +                           // data size for storing distance unit string
            list->desc_size;                                 // data size for storing description

    // NOTE: this type of API will put the non-text data first, then text data.
    uint8_t* frame_data = (uint8_t*)packet_buffer;

    // fill the data into frame_data
    int offset = 0;
    memcpy( frame_data, &list->list_item_index, offset = sizeof( list->list_item_index ) );
    memcpy( frame_data + offset, &list->desc_size, sizeof( list->desc_size ) );
    offset += sizeof( list->desc_size );
    memcpy( frame_data + offset, &list->dist_unit_size, sizeof( list->dist_unit_size ) );
    offset += sizeof( list->dist_unit_size );
    memcpy( frame_data + offset, &list->distance, sizeof( list->distance ) );
    offset += sizeof( list->distance );
    memcpy( frame_data + offset, list->distance_unit, list->dist_unit_size );
    offset += list->dist_unit_size;
    memcpy( frame_data + offset, list->desc, list->desc_size );

    memcpy( (char*)frame.magic_code, (unsigned char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MCU_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_GASPOILIST_DATA_UPDATE;

    // calculate how much payload it needs for list_size * each list payload
    frame.payload_size = payload_size;
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_POINTER;
    frame.data_pointer = frame_data;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_update_navieventtext
    *
    * Send next event text
    *
    * @param str event data pointer
    * @param str_size size of string
    * @param navi_event_type type of navi event
    * @param event_extra_subtype extra subtype of the navi event
    * @param visibility visibility of the event
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_update_navieventtext
        (
        uint8_t* str,
        uint8_t str_size,
        navilite_navievent_type navi_event_type,
        navilite_navievent_extra_subtype event_extra_subtype,
        uint8_t visibility
        )
    {
    // NOTE: this type of API will put the non-text data first, then text data.
    navilite_message frame = { 0 };
    int frame_payload_size = sizeof( navi_event_type ) + sizeof( event_extra_subtype ) + sizeof( visibility ) + sizeof( str_size ) + str_size;
    uint8_t* frame_data = (uint8_t*)malloc( frame_payload_size );

    if( frame_data == NULL )
        {
        PRINTF("#ERROR: failed to allocate memory!\r\n");
        }

    // append the event type byte
    memcpy( frame_data,  &navi_event_type, sizeof( navi_event_type ) );
    // append the event-extra sub-type
    memcpy( frame_data + sizeof( navi_event_type ), &event_extra_subtype, sizeof( event_extra_subtype ));
    // append the visibility byte
    memcpy( frame_data + sizeof( navi_event_type ) + sizeof( event_extra_subtype ), &visibility, sizeof( visibility ) );
    // append the string size byte
    memcpy( frame_data + sizeof( navi_event_type ) + sizeof( event_extra_subtype ) + sizeof( visibility ), &str_size, sizeof( str_size ) );
    // append the rest strings
    memcpy( frame_data + sizeof( navi_event_type ) + sizeof( event_extra_subtype ) + sizeof( visibility ) + sizeof( str_size ), str, str_size );

    // compose a navilite update frame
    memcpy( (char*)frame.magic_code, (unsigned char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MCU_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_NAVIEVENTTEXTUPDATE;
    frame.payload_size = frame_payload_size;
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_POINTER;
    frame.data_pointer = frame_data;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_update_homelocationsetting
    *
    * home location setting
    *
    * @param is_home_loc_set home location setting
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_update_homelocationsetting
        (
        uint8_t is_home_loc_set
        )
    {
    navilite_message frame = { 0 };
    memcpy( (char*)frame.magic_code, (unsigned char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MCU_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_HOMESETTING_UPDATE;
    frame.payload_size = sizeof( uint16_t );
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE;
    frame.data_value = is_home_loc_set;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_update_officelocationsetting
    *
    * office location setting
    *
    * @param is_office_loc_set office location setting
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_update_officelocationsetting
        (
        uint8_t is_office_loc_set
        )
    {
    navilite_message frame = { 0 };
    memcpy( (char*)frame.magic_code, (unsigned char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MCU_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_OFFICESETTING_UPDATE;
    frame.payload_size = sizeof( uint16_t );
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE;
    frame.data_value = is_office_loc_set;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_update_appsetting
    *
    * app setting
    *
    * @param app_setting_status_bits app setting status bits to set
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_update_appsetting
        (
        uint16_t app_setting_status_bits
        )
    {
    navilite_message frame = { 0 };
    memcpy( (char*)frame.magic_code, (unsigned char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MCU_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_APPSETTING_UPDATE;
    frame.payload_size = sizeof( uint16_t );
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE;
    frame.data_value = app_setting_status_bits;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_update_zoomlevel
    *
    * zoom level update
    *
    * @param current_level current zoom level
    * @param max_level max zoom level
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_update_zoomlevel
        (
        uint8_t current_level,
        uint8_t max_level
        )
    {
    navilite_message frame = { 0 };
    uint8_t* packValues = (uint8_t*)malloc( sizeof( uint8_t ) * 2 );
    packValues[0] = current_level;
    packValues[1] = max_level;
    memcpy( (char*)frame.magic_code, (unsigned char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MCU_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_MAP_ZOOM_LEVEL_UPDATE;
    frame.payload_size = sizeof( uint8_t ) * 2;
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_POINTER;
    frame.data_pointer = packValues;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_update_routecalcprogress
    *
    * route calc progress update
    *
    * @param progress route progress
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_update_routecalcprogress
        (
        uint8_t progress
        )
    {
    navilite_message frame = { 0 };
    memcpy( (char*)frame.magic_code, (unsigned char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MCU_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_ROUTE_CALC_PROGRESS_UPDATE;
    frame.payload_size = sizeof( uint16_t );
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE;
    frame.data_value = progress;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_update_daynightmode
    *
    * day night mode update
    *
    * @param mode day night mode
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_update_daynightmode
        (
        navilite_daynight_mode_type mode
        )
    {
    navilite_message frame = { 0 };
    memcpy( (char*)frame.magic_code, (unsigned char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MCU_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_DAYNIGHT_MODE_UPDATE;
    frame.payload_size = sizeof( uint16_t );
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE;
    frame.data_value = (uint8_t)mode;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_update_bttimeout
    *
    * bt timeout update
    *
    * @param timeout bt connection timeout value
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_update_bttimeout
        (
        uint16_t timeout
        )
    {
    navilite_message frame = { 0 };
    memcpy( (char*)frame.magic_code, (unsigned char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MCU_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_BT_THROUGHPUT_TIMEOUT_UPDATE;
    frame.payload_size = sizeof( uint16_t );
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE;
    frame.data_value = (uint16_t)timeout;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_update_serviceack
    *
    * service ack type update
    *
    * @param ack_service_type service ack type
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_update_serviceack
        (
        navilite_service_type ack_service_type
        )
    {
    navilite_message frame = { 0 };
    memcpy( (char*)frame.magic_code, (unsigned char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MCU_UPDATE;
    frame.service_type = ack_service_type;
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_VALUE;
    frame.payload_size = 0;
    frame.data_value = 0;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_update_dialog_event
    *
    * dialog event update
    *
    * @param dialog_id dialog id
    * @param dialog_type dialog type
    * @param message pointer of message
    * @param message_size size of message
    * @param timeout dialog timeout
    * @param default_choice default choice if dialog timeout expires
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_update_dialog_event
        (
        uint8_t dialog_id,
        navilite_dialog_type dialog_type,
        uint8_t* message,
        uint8_t message_size,
        uint8_t timeout,
        uint8_t default_choice
        )
    {
    navilite_message frame = { 0 };
    int full_data_size = sizeof( uint8_t ) * 5 + strlen( (char*)message );
    uint8_t* packValues = (uint8_t*)malloc( full_data_size );
    packValues[0] = dialog_id;
    packValues[1] = dialog_type;
    packValues[2] = message_size;
    packValues[3] = timeout;
    packValues[4] = default_choice;
    memcpy( &packValues[5], message, message_size );
    memcpy( (char*)frame.magic_code, (unsigned char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MCU_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_DIALOG_EVENT_UPDATE;
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_POINTER;
    frame.payload_size = full_data_size;
    frame.data_pointer = packValues;
    return frame;
    }

    /*********************************************************************
    *
    * @public
    * NAVILITE_pack_frame_update_dialog_dismiss
    *
    * dialog dismiss update
    *
    * @param dialog_id dialog id to dismiss
    * @return navilite_message return navilite_message copy to caller
    *
    *********************************************************************/
    navilite_message NAVILITE_pack_frame_update_dialog_dismiss
        (
        uint8_t dialog_id
        )
    {
    navilite_message frame = { 0 };
    // full data size = dialog_id + dialog_type + message_size + message content
    int full_data_size = sizeof( uint8_t ) * 2;
    uint8_t* packValues = (uint8_t*)malloc( full_data_size );
    packValues[0] = dialog_id;
    packValues[1] = NAVILITE_DIALOGTYPE_DISMISS_DIALOG;
    memcpy( (char*)frame.magic_code, (unsigned char*)MAGIC_CODE, MAGIC_CODE_SIZE );
    frame.version = PROTOCOL_VERSION;
    frame.frame_type = NAVILITE_FRAMETYPE_MCU_UPDATE;
    frame.service_type = NAVILITE_SERVICETYPE_DIALOG_EVENT_UPDATE;
    frame.payload_data_type = NAVILITE_PAYLOAD_DATA_TYPE_AS_POINTER;
    frame.payload_size = full_data_size;
    frame.data_pointer = packValues;
    return frame;
    }
#endif
