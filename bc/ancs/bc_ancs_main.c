/*********************************************************************
* @file
* bc_ancs_main.c
*
* @brief
* Bluetooth Connectivity - ANCS parser
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "semphr.h"
#include "fsl_debug_console.h"
#include "error_code.h"
#include <stdlib.h>
#include <stdint.h>
#include "error_code.h"
#include "Enum.h"
#include "bc_priv.h"
#include "bc_ancs_priv.h"
#include "BC_ancs_pub.h"
#include "HCI_pub.h"
#include "NTF_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define ANCS_EVENT_ID_NOTIFICATION_ADDED                ( 0 )
#define ANCS_EVENT_ID_NOTIFICATION_MODIFIED             ( 1 )
#define ANCS_EVENT_ID_NOTIFICATION_REMOVED              ( 2 )

#define ANCS_EVENT_FLAG_SILENT                          ( 1 << 0 )
#define ANCS_EVENT_FLAG_IMPORTANT                       ( 1 << 1 )
#define ANCS_EVENT_FLAG_PREEXISTING                     ( 1 << 2 )
#define ANCS_EVENT_FLAG_POSITIVE_ACTION                 ( 1 << 3 )
#define ANCS_EVENT_FLAG_NEGATIVE_ACTION                 ( 1 << 4 )

#define ANCS_COMMAND_ID_GET_NOTIFICATION_ATTRIBUTES     ( 0 )
#define ANCS_COMMAND_ID_GET_APP_ATTRIBUTES              ( 1 )
#define ANCS_COMMAND_ID_PERFORM_NOTIFICATION_ACTION     ( 2 )

#define ANCS_CATEGORY_ID_OTHER                          ( 0 )
#define ANCS_CATEGORY_ID_INCOMING_CALL                  ( 1 )
#define ANCS_CATEGORY_ID_MISSED_CALL                    ( 2 )
#define ANCS_CATEGORY_ID_VOICE_MAIL                     ( 3 )
#define ANCS_CATEGORY_ID_SOCIAL                         ( 4 )
#define ANCS_CATEGORY_ID_SCHEDULE                       ( 5 )
#define ANCS_CATEGORY_ID_EMAIL                          ( 6 )
#define ANCS_CATEGORY_ID_NEWS                           ( 7 )
#define ANCS_CATEGORY_ID_HEALTH_AND_FITNESS             ( 8 )
#define ANCS_CATEGORY_ID_BUSINESS_AND_FINANCE           ( 9 )
#define ANCS_CATEGORY_ID_LOCATION                       ( 10 )
#define ANCS_CATEGORY_ID_ENTERTAINMENT                  ( 11 )

#define ANCS_NOTIFICATION_ATTR_ID_APP_IDENTIFIER        ( 0 )
#define ANCS_NOTIFICATION_ATTR_ID_TITLE                 ( 1 ) /* Needs to be followed by a 2-bytes max length parameter */
#define ANCS_NOTIFICATION_ATTR_ID_SUBTITLE              ( 2 ) /* Needs to be followed by a 2-bytes max length parameter */
#define ANCS_NOTIFICATION_ATTR_ID_MESSAGE               ( 3 ) /* Needs to be followed by a 2-bytes max length parameter */
#define ANCS_NOTIFICATION_ATTR_ID_MESSAGE_SIZE          ( 4 )
#define ANCS_NOTIFICATION_ATTR_ID_DATE                  ( 5 )
#define ANCS_NOTIFICATION_ATTR_ID_POSITIVE_ACTION_LABEL ( 6 )
#define ANCS_NOTIFICATION_ATTR_ID_NEGATIVE_ACTION_LABEL ( 7 )

#define ANCS_NOTIFICATION_GET_ATTR_NUM                  ( 7 ) /* number of attributes in get_notification_attributes() */

#define ANCS_NOTIFICATION_SOURCE_DATA_LENGTH            ( 8 )

#define ANCS_DATETIME_LEN                               ( 16 ) /* including ending null */
#define ANCS_LABEL_LEN                                  ( 32 )
#define ANCS_MESSAGE_SIZE_STRING_LEN                    ( 8 )

#define DICTIONARY_SIZE                                 ( 8 )
#define DICTIONARY_FLAG_FREE                            ( 0 )
#define DICTIONARY_FLAG_USED                            ( 1 )

#define ANCS_NOTIFICATION_ATTRIBUTES_BUFFER_SIZE        ( 1024 )

#define GATT_NOTIFICATION_DATA_QUEUE_SIZE               ( 16 )

#define ANCS_NOTIFICATION_ATTRIBUTE_RESPONSE_CMD_ID_SIZE            ( 1 )
#define ANCS_NOTIFICATION_ATTRIBUTE_RESPONSE_NOTIFICAION_UID_SIZE   ( 4 )
#define ANCS_NOTIFICATION_ATTRIBUTE_RESPONSE_ATTR_ID_SIZE           ( 1 )
#define ANCS_NOTIFICATION_ATTRIBUTE_RESPONSE_ATTR_LEN_SIZE          ( 2 )

#define IPHONE_CALL_VOLUME_CONTROLLABLE                 ( false )

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
typedef enum
    {
    ANCS_CHARACTERISTIC_CONTROL_POINT,
    ANCS_CHARACTERISTIC_NOTIFICATION_SOURCE,
    ANCS_CHARACTERISTIC_DATA_SOURCE,
    ANCS_CHARACTERISTIC_TOTAL
    } ancs_characteristic_enum;

typedef struct
    {
    ancs_characteristic_enum characteristic;
    uint16_t value_handle;
    uint16_t cccd_handle;
    bool     is_discovered;
    } ancs_characteristic_type;

typedef enum
    {
    ANCS_ACTION_ID_POSITIVE = 0,
    ANCS_ACTION_ID_NEGATIVE = 1,
    ANCS_ACTION_ID_TOTAL
    } ancs_action_id;

typedef struct
    {
    uint32_t uid;
    uint8_t  category_id;
    uint8_t  flag;
    } uid_category_dictionary;

void BC_ancs_ble_connected_callback( void );
void BC_ancs_ble_disconnected_callback( void );
void BC_ancs_service_discovered_callback( const uint16_t start_handle, const uint16_t end_handle );
void BC_ancs_characteristic_discovered_callback( const uint8_t* uuid, const uint16_t value_handle );
void BC_ancs_descriptor_discovered_callback( const uint16_t descriptor_handle );
void BC_ancs_discovery_complete_callback( void );
void BC_ancs_notification_received_callback( const uint16_t handle, const uint8_t* data, const uint16_t length );

void BC_ancs_delete_notification_callback( const uint32_t uid );
void BC_ancs_answer_call_callback( const uint32_t uid );
void BC_ancs_decline_call_callback( const uint32_t uid );

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/
/* ANCS characteristic UUID in little endian */
static const char ANCS_CHARACTERISTIC_UUID[ANCS_CHARACTERISTIC_TOTAL][UUID_128BIT_LEN] =
    {
    {0xD9, 0xD9, 0xAA, 0xFD, 0xBD, 0x9B, 0x21, 0x98, 0xA8, 0x49, 0xE1, 0x45, 0xF3, 0xD8, 0xD1, 0x69}, // Control Point
    {0xBD, 0x1D, 0xA2, 0x99, 0xE6, 0x25, 0x58, 0x8C, 0xD9, 0x42, 0x01, 0x63, 0x0D, 0x12, 0xBF, 0x9F}, // Notification Source
    {0xFB, 0x7B, 0x7C, 0xCE, 0x6A, 0xB3, 0x44, 0xBE, 0xB5, 0x4B, 0xD6, 0x24, 0xE9, 0xC6, 0xEA, 0x22}  // Data Source
    };
static ancs_characteristic_type ancs_characteristics[ANCS_CHARACTERISTIC_TOTAL];
static uint16_t ancs_start_handle;
static uint16_t ancs_end_handle;
static bool     ancs_is_discovered;
static int      ancs_characteristic_discovered_count;
static uint8_t  ancs_index_table[ANCS_CHARACTERISTIC_TOTAL];

// callback functions from BLE
static const ble_client_callback ancs_client_callback =
    {
    BC_ancs_ble_connected_callback,
    BC_ancs_ble_disconnected_callback,
    BC_ancs_service_discovered_callback,
    BC_ancs_characteristic_discovered_callback,
    BC_ancs_descriptor_discovered_callback,
    BC_ancs_discovery_complete_callback,
    BC_ancs_notification_received_callback
    };

static notification_callback_t ancs_notification_callback =
    {
    BC_ancs_answer_call_callback,
    BC_ancs_decline_call_callback,
    NULL
    };

static uid_category_dictionary ancs_uid_category_dictionary[DICTIONARY_SIZE];

static uint8_t  ancs_notification_attributes_buffer[ANCS_NOTIFICATION_ATTRIBUTES_BUFFER_SIZE];
static uint32_t ancs_notification_attributes_received_size = 0;

typedef struct
    {
    uint16_t handle;
    uint8_t  data[HCI_MAX_DATA_SIZE];
    uint16_t data_len;
    } gatt_notification_struct;
static QueueHandle_t gatt_notification_queue_handle;

static uint8_t ancs_notification_messsage_buffer[NOTIFICATION_MESSAGE_MAX_LEN];

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @private
* put_uid_category_to_dictionary
*
* Add UID/category pairs into the lookup table
*
* @param uid The unique notification id
* @param category_id The category id
*
* @return The result of adding to lookup table
* @retVal ERR_NONE Success
* @retVal ERR_BUF_FULL Fail
*
*********************************************************************/
static int put_uid_category_to_dictionary
    (
    const uint32_t uid,
    const uint8_t  category_id
    )
{
int result = ERR_BUF_FULL;
for( int i = 0; i < DICTIONARY_SIZE; i++ )
    {
    if( DICTIONARY_FLAG_FREE == ancs_uid_category_dictionary[i].flag )
        {
        ancs_uid_category_dictionary[i].uid = uid;
        ancs_uid_category_dictionary[i].category_id = category_id;
        ancs_uid_category_dictionary[i].flag = DICTIONARY_FLAG_USED;
        result = ERR_NONE;
        break;
        }
    }
if( ERR_NONE != result )
    {
    BC_ANCS_PRINTF( "Err: ancs dict full\r\n" );
    }
return result;
}

/*********************************************************************
*
* @private
* get_category_from_dictionary
*
* Get corresponding category id from uid
* Note: When category id is returned, the data pair would be cleared
*
* @param uid The unique notification id
* @param category The pointer to the category id
*
* @return Result of looking up category from uid
* @retVal ERR_NONE Success
* @retVal ERR_BUF_OPERATION Fail
*
*********************************************************************/
static int get_category_from_dictionary
    (
    const uint32_t uid,
    uint8_t*       category_id
    )
{
int result = ERR_BUF_OPERATION;
for( int i = 0; i < DICTIONARY_SIZE; i++ )
    {
    if( DICTIONARY_FLAG_USED == ancs_uid_category_dictionary[i].flag &&
        uid == ancs_uid_category_dictionary[i].uid )
        {
        *category_id = ancs_uid_category_dictionary[i].category_id;
        ancs_uid_category_dictionary[i].flag = DICTIONARY_FLAG_FREE;
        result = ERR_NONE;
        break;
        }
    }
if( ERR_NONE != result )
    {
    BC_ANCS_PRINTF( "Err: %s fail\r\n", __FUNCTION__ );
    }
return result;
}

/*********************************************************************
*
* @private
* char_to_uint32
*
* Convert string to uint32 number
*
* @param number_string The pointer to the string
* @param len The length of the string
*
* @return The integer of the number string
*
*********************************************************************/
static uint32_t char_to_uint32
    (
    const uint8_t* number_string,
    const int      len
    )
{
int      digit  = 0;
uint32_t result = 0;
int      i = 0;

for( i = 0; i < len; i++ )
    {
    digit = number_string[i] - '0';

    if( digit < 0 || digit > 9 )
        {
        digit = 0;
        }
    result = result * 10 + digit;
    }
return result;
}

/*********************************************************************
*
* @private
* parse_ancs_date_string
*
* Parse the date time string of ANCS
*
* @param date_string The date time string from ANCS
*
* @return The time of notification_time_t type
*
*********************************************************************/
static notification_time_t parse_ancs_date_string
    (
    const uint8_t* date_string
    )
{
notification_time_t datetime;
datetime.year   = ( uint16_t )char_to_uint32( &date_string[0],  4 );
datetime.month  = ( uint8_t ) char_to_uint32( &date_string[4],  2 );
datetime.day    = ( uint8_t ) char_to_uint32( &date_string[6],  2 );
datetime.hour   = ( uint8_t ) char_to_uint32( &date_string[9],  2 );
datetime.minute = ( uint8_t ) char_to_uint32( &date_string[11], 2 );
datetime.second = ( uint8_t ) char_to_uint32( &date_string[13], 2 );
return datetime;
}

/*********************************************************************
*
* @private
* get_notification_attributes
*
* Get the notificaiton attributes
*
* @param notification_uid The unique notification id
* @return pass/fail result
*
*********************************************************************/
static int get_notification_attributes
    (
    const uint32_t notification_uid
    )
{
int     result = ERR_NONE;
uint8_t data[32];
int     control_point_idx = ancs_index_table[ANCS_CHARACTERISTIC_CONTROL_POINT];

data[0] = ANCS_COMMAND_ID_GET_NOTIFICATION_ATTRIBUTES;
data[1] = notification_uid & 0xff;
data[2] = ( notification_uid >> 8  ) & 0xff;
data[3] = ( notification_uid >> 16 ) & 0xff;
data[4] = ( notification_uid >> 24 ) & 0xff;

/* Note: Modify ANCS_NOTIFICATION_GET_ATTR_NUM if adding/removing attributes */

data[5] = ANCS_NOTIFICATION_ATTR_ID_TITLE;
data[6] = NOTIFICATION_TITLE_MAX_LEN & 0xff;
data[7] = ( NOTIFICATION_TITLE_MAX_LEN >> 8 ) & 0xff;

data[8]  = ANCS_NOTIFICATION_ATTR_ID_SUBTITLE;
data[9]  = NOTIFICATION_SUBTITLE_MAX_LEN & 0xff;
data[10] = ( NOTIFICATION_SUBTITLE_MAX_LEN >> 8 ) & 0xff;

data[11] = ANCS_NOTIFICATION_ATTR_ID_MESSAGE;
data[12] = NOTIFICATION_MESSAGE_MAX_LEN & 0xff;
data[13] = ( NOTIFICATION_MESSAGE_MAX_LEN >> 8 ) & 0xff;

data[14] = ANCS_NOTIFICATION_ATTR_ID_MESSAGE_SIZE;
data[15] = ANCS_NOTIFICATION_ATTR_ID_DATE;
data[16] = ANCS_NOTIFICATION_ATTR_ID_POSITIVE_ACTION_LABEL;
data[17] = ANCS_NOTIFICATION_ATTR_ID_NEGATIVE_ACTION_LABEL;

result = HCI_le_enqueue_gatt_write_request( ancs_characteristics[control_point_idx].value_handle, data, 18 );
if( ERR_NONE != result )
    {
    BC_ANCS_PRINTF( "%s fail\r\n", __FUNCTION__ );
    }
return result;
}

/*********************************************************************
*
* @private
* proc_notification_source_data
*
* Process notification source data
*
* @param data The pointer to the char array of source data
* @param length The length of source data
*
*********************************************************************/
static void proc_notification_source_data
    (
    const uint8_t* data,
    const uint16_t length
    )
{
uint16_t total_data       = WORD_LITTLE( data[0], data[1] );
uint16_t data_index       = WORD_LITTLE( data[2], data[3] );
uint8_t  event_id         = data[4];
uint8_t  event_flags      = data[5];
uint8_t  category_id      = data[6];
uint8_t  category_count   = data[7];
uint32_t notification_uid = DWORD_LITTLE( data[8], data[9], data[10], data[11] );

if( total_data == ANCS_NOTIFICATION_SOURCE_DATA_LENGTH &&
    0 == data_index )
    {
    switch( event_id )
        {
        case ANCS_EVENT_ID_NOTIFICATION_ADDED:
            BC_ANCS_PRINTF( "ancs event added\r\n" );
            if( ERR_NONE == get_notification_attributes( notification_uid ) )
                {
                put_uid_category_to_dictionary( notification_uid, category_id );
                }
            break;

        case ANCS_EVENT_ID_NOTIFICATION_MODIFIED:
            BC_ANCS_PRINTF( "ancs event modified\r\n" );
            if( ERR_NONE == get_notification_attributes( notification_uid ) )
                {
                put_uid_category_to_dictionary( notification_uid, category_id );
                }
            break;

        case ANCS_EVENT_ID_NOTIFICATION_REMOVED:
            BC_ANCS_PRINTF( "ancs event removed\r\n" );
            if( ANCS_CATEGORY_ID_INCOMING_CALL == category_id )
                {
                BC_ANCS_PRINTF( "ancs incoming call stopped %d\r\n", notification_uid );
                NTF_notify_incoming_call_stopped( notification_uid );
                }
            else
                {
                BC_ANCS_PRINTF( "ancs notification deleted %d\r\n", notification_uid );
                NTF_notify_notification_deleted( notification_uid );
                }
            break;

        default:
            BC_ANCS_PRINTF( "Err: ancs invalid event id, %d\r\n", event_id );
            break;
        }
    BC_ANCS_PRINTF( "ancs source data flag: 0x%x, catId: %d, catCount: %d, uid: %d\r\n", event_flags, category_id, category_count, notification_uid );
    }
else
    {
    PRINTF( "Err: %s invalid data len %d, %d\r\n", __FUNCTION__, total_data, data_index );
    }
}

/*********************************************************************
*
* @private
* check_data_source_notification_attributes_all_received
*
* Check if all the data source notification attributes are received
*
* @param data The pointer to the char array of the attribute
* @param length The length of the attribute
* @return The checked result
*
*********************************************************************/
static bool check_data_source_notification_attributes_all_received
    (
    const uint8_t* data,
    const uint16_t length
    )
{
bool     result        = false;
int      i             = ANCS_NOTIFICATION_ATTRIBUTE_RESPONSE_CMD_ID_SIZE + ANCS_NOTIFICATION_ATTRIBUTE_RESPONSE_NOTIFICAION_UID_SIZE;
uint32_t attribute_len = 0;
uint32_t attribute_num = 0;
uint32_t attribute_id  = 0;

/* command id: data[0]
 * notification uid: data[1] - data[4] */

if( ANCS_COMMAND_ID_GET_NOTIFICATION_ATTRIBUTES == data[0] )
    {
    while( i < length )
        {
        attribute_id  = data[i];
        attribute_len = WORD_LITTLE( data[i+1], data[i+2] );
        attribute_num++;
        i += ( ANCS_NOTIFICATION_ATTRIBUTE_RESPONSE_ATTR_ID_SIZE + ANCS_NOTIFICATION_ATTRIBUTE_RESPONSE_ATTR_LEN_SIZE + attribute_len );
        BC_ANCS_PRINTF( "ancs check attr id %d, len %d, total: %d\r\n", attribute_id, attribute_len, i );
        }

    if( ANCS_NOTIFICATION_GET_ATTR_NUM == attribute_num &&
        i == length )
        {
        result = true;
        }
    BC_ANCS_PRINTF( "%s %d %d %d %d\r\n ", __FUNCTION__, attribute_num, i, length, result );
    }
else
    {
    /* ANCS_COMMAND_ID_GET_APP_ATTRIBUTES and ANCS_COMMAND_ID_PERFORM_NOTIFICATION_ACTION are not used, so simply return true */
    result = true;
    PRINTF( "%s %d\r\n ", __FUNCTION__, result );
    }

return result;
}

/*********************************************************************
*
* @private
* proc_data_source_notification_attributes
*
* Process notification attributes
*
* @param data The pointer to the char array of the attribute
* @param length The length of the attribute
*
*********************************************************************/
static void proc_data_source_notification_attributes
    (
    const uint8_t* data,
    const uint16_t length
    )
{
uint32_t attribute_num = 0;
uint32_t attribute_id  = 0;
uint32_t attribute_len = 0;
uint32_t attribute_id_flag = 0;
int      copy_length = 0;
uint32_t body_length = 0;
int      i           = ANCS_NOTIFICATION_ATTRIBUTE_RESPONSE_CMD_ID_SIZE + ANCS_NOTIFICATION_ATTRIBUTE_RESPONSE_NOTIFICAION_UID_SIZE;
uint8_t  category_id = 0;
uint8_t  title[NOTIFICATION_TITLE_MAX_LEN];
uint8_t  subtitle[NOTIFICATION_SUBTITLE_MAX_LEN];
uint8_t* body = ancs_notification_messsage_buffer;
uint8_t  datetime[ANCS_DATETIME_LEN];
uint8_t  positive_action_label[ANCS_LABEL_LEN];
uint8_t  negative_action_label[ANCS_LABEL_LEN];
uint8_t  message_size[ANCS_MESSAGE_SIZE_STRING_LEN];
uint32_t notification_uid = DWORD_LITTLE( data[1], data[2], data[3], data[4] ); // data[0] is CommandID

while( i < length )
    {
    attribute_id  = data[i];
    attribute_len = WORD_LITTLE( data[i+1], data[i+2] );
    attribute_id_flag |= ( 1 << attribute_id );
    attribute_num++;

    switch( attribute_id )
        {
        case ANCS_NOTIFICATION_ATTR_ID_TITLE:
            title[0] = '\0';
            if( attribute_len > 0 )
                {
                copy_length = MIN( attribute_len, NOTIFICATION_TITLE_MAX_LEN - 1 );
                memcpy( title, &data[i+3], copy_length );
                title[copy_length] = '\0';
                }
            BC_ANCS_PRINTF( "\tattr %d: len: %d, title: %s\r\n", attribute_id, attribute_len, title );
            break;

        case ANCS_NOTIFICATION_ATTR_ID_SUBTITLE:
            subtitle[0] = '\0';
            if( attribute_len > 0 )
                {
                copy_length = MIN( attribute_len, NOTIFICATION_SUBTITLE_MAX_LEN - 1 );
                memcpy( subtitle, &data[i+3], copy_length );
                subtitle[copy_length] = '\0';
                }
            BC_ANCS_PRINTF( "\tattr %d: len: %d, subtitle: %s\r\n", attribute_id, attribute_len, subtitle );
            break;

        case ANCS_NOTIFICATION_ATTR_ID_MESSAGE:
            body[0] = '\0';
            if( attribute_len > 0 )
                {
                copy_length = MIN( attribute_len, NOTIFICATION_MESSAGE_MAX_LEN - 1 );
                memcpy( body, &data[i+3], copy_length );
                body[copy_length] = '\0';
                body_length = copy_length;
                }
            BC_ANCS_PRINTF( "\tattr %d: len: %d, body: %s, %d\r\n", attribute_id, attribute_len, body, body_length );
            break;

        case ANCS_NOTIFICATION_ATTR_ID_MESSAGE_SIZE:
            message_size[0] = '\0';
            if( attribute_len > 0 )
                {
                copy_length = MIN( attribute_len, ANCS_MESSAGE_SIZE_STRING_LEN - 1);
                memcpy( message_size, &data[i+3], copy_length );
                message_size[copy_length] = '\0';
                }
            BC_ANCS_PRINTF( "\tattr %d: len: %d, message_size: %s\r\n", attribute_id, attribute_len, message_size );
            break;

        case ANCS_NOTIFICATION_ATTR_ID_DATE:
            datetime[0] = '\0';
            if( attribute_len > 0 )
                {
                copy_length = MIN( attribute_len, ANCS_DATETIME_LEN - 1 );
                memcpy( datetime, &data[i+3], copy_length );
                datetime[copy_length] = '\0';
                }
            BC_ANCS_PRINTF( "\tattr %d: len: %d, date: %s\r\n", attribute_id, attribute_len, datetime );
            break;

        case ANCS_NOTIFICATION_ATTR_ID_POSITIVE_ACTION_LABEL:
            positive_action_label[0] = '\0';
            if( attribute_len > 0 )
                {
                copy_length = MIN( attribute_len, ANCS_LABEL_LEN - 1 );
                memcpy( positive_action_label, &data[i+3], copy_length );
                positive_action_label[copy_length] = '\0';
                }
            BC_ANCS_PRINTF( "\tattr %d: len: %d, pos: %s\r\n", attribute_id, attribute_len, positive_action_label );
            break;

        case ANCS_NOTIFICATION_ATTR_ID_NEGATIVE_ACTION_LABEL:
            negative_action_label[0] = '\0';
            if( attribute_len > 0 )
                {
                copy_length = MIN( attribute_len, ANCS_LABEL_LEN - 1 );
                memcpy( negative_action_label, &data[i+3], copy_length );
                negative_action_label[copy_length] = '\0';
                }
            BC_ANCS_PRINTF( "\tattr %d: len: %d, neg: %s\r\n", attribute_id, attribute_len, negative_action_label );
            break;

        default:
            PRINTF( "Err: invalid ancs attr id: %d\r\n", attribute_id );
            break;
        }

    i += ( ANCS_NOTIFICATION_ATTRIBUTE_RESPONSE_ATTR_ID_SIZE + ANCS_NOTIFICATION_ATTRIBUTE_RESPONSE_ATTR_LEN_SIZE + attribute_len );
    }

if( ERR_NONE == get_category_from_dictionary( notification_uid, &category_id ) )
    {
    BC_ANCS_PRINTF( "%s uid: %d, category: %d\r\n", __FUNCTION__, notification_uid, category_id );
    if( ANCS_CATEGORY_ID_INCOMING_CALL == category_id )
        {
        NTF_notify_incoming_call_started( notification_uid, title, IPHONE_CALL_VOLUME_CONTROLLABLE );
        }
    else
        {
        if( !memcmp( negative_action_label, "End Call", 8 ) &&
            !memcmp( body, "Active Call", 11 ) )
            {
            NTF_notify_active_call_started( notification_uid, title, IPHONE_CALL_VOLUME_CONTROLLABLE );
            }
        else
            {
            EnumNotificationCategory category = EnumNotificationCategoryMESSAGE;
            if( ANCS_CATEGORY_ID_MISSED_CALL == category_id )
                {
                category = EnumNotificationCategoryMISSED_CALL;
                }
            notification_time_t received_time = parse_ancs_date_string( datetime );
            NTF_add_notification( notification_uid, title, subtitle, body, category, received_time );
            }
        }
    }
}

/*********************************************************************
*
* @private
* proc_data_source_data
*
* Process data source data
*
* @param data The pointer to the data source.
* @param length The length of the data buffer.
*
*********************************************************************/
static void proc_data_source_data
    (
    const uint8_t* data,
    const uint16_t length
    )
{
int command_id = data[0];

BC_ANCS_PRINTF( "%s cmd id: %d\r\n", __FUNCTION__, command_id );

switch( command_id )
    {
    case ANCS_COMMAND_ID_GET_NOTIFICATION_ATTRIBUTES:
        proc_data_source_notification_attributes( data, length );
        break;

    case ANCS_COMMAND_ID_GET_APP_ATTRIBUTES:
        /* empty */
        break;

    case ANCS_COMMAND_ID_PERFORM_NOTIFICATION_ACTION:
        /* empty */
        break;

    default:
        break;
    }
}

/*********************************************************************
*
* @private
* recompose_data_source_notification_attributes
*
* Recompose notification attributes in data source
*
* Note from ANCS spec:
*   If the response is larger than the negotiated GATT Maximum Transmission Unit (MTU),
*   it is split into multiple fragments by the NP.
*   The NC must recompose the response by splicing each fragment.
*   The response is complete when the complete tuples for each requested attribute has been received.
*
* @param data The pointer to the char array of the attribute
* @param length The length of the attribute
*
*********************************************************************/
static void recompose_data_source_notification_attributes
    (
    const uint8_t* data,
    const uint16_t length
    )
{
uint16_t attributes_data_length = length - 4; // 2 bytes of total data + 2 bytes of data index
uint32_t total_payload_size = WORD_LITTLE( data[0], data[1] );

BC_ANCS_PRINTF( "%s %d %d\r\n", __FUNCTION__, total_payload_size, attributes_data_length );

if( 0 == ancs_notification_attributes_received_size )
    {
    /* process data source data if all data is received */
    if( check_data_source_notification_attributes_all_received( &data[4], attributes_data_length ) )
        {
        proc_data_source_data( &data[4], attributes_data_length );
        }
    else /* keep in buffer */
        {
        memcpy( &ancs_notification_attributes_buffer[0], &data[4], attributes_data_length );
        ancs_notification_attributes_received_size += attributes_data_length;
        }
    }
else
    {
    if( ( ancs_notification_attributes_received_size + attributes_data_length ) <= ANCS_NOTIFICATION_ATTRIBUTES_BUFFER_SIZE )
        {
        /* append data in buffer */
        memcpy( &ancs_notification_attributes_buffer[ancs_notification_attributes_received_size], &data[4], attributes_data_length );
        ancs_notification_attributes_received_size += attributes_data_length;

        /* process data source data if all data is received */
        if( check_data_source_notification_attributes_all_received( ancs_notification_attributes_buffer, ancs_notification_attributes_received_size ) )
            {
            proc_data_source_data( ancs_notification_attributes_buffer, ancs_notification_attributes_received_size );
            ancs_notification_attributes_received_size = 0;
            }
        }
    else
        {
        PRINTF( "Err: ANCS data source %d+%d over %d\r\n", ancs_notification_attributes_received_size, attributes_data_length, ANCS_NOTIFICATION_ATTRIBUTES_BUFFER_SIZE );
        }
    }
}

/*********************************************************************
*
* @private
* register_notification
*
* Registser ANCS notification
*
*********************************************************************/
static void register_notification
    (
    void
    )
{
uint8_t data[2];
int     notification_source_idx = ancs_index_table[ANCS_CHARACTERISTIC_NOTIFICATION_SOURCE];
int     data_source_idx         = ancs_index_table[ANCS_CHARACTERISTIC_DATA_SOURCE];

if( ancs_characteristics[notification_source_idx].cccd_handle > 0 &&
    ancs_characteristics[data_source_idx].cccd_handle > 0 )
    {
    /* write notification source cccd */
    BC_ANCS_PRINTF( "write notification source cccd %x\r\n", ancs_characteristics[notification_source_idx].cccd_handle );
    data[0] = BLE_GATT_CLIENT_CONFIG_NOTIFICATION & 0xff;
    data[1] = ( BLE_GATT_CLIENT_CONFIG_NOTIFICATION >> 8 ) & 0xff;
    HCI_le_enqueue_gatt_write_request( ancs_characteristics[notification_source_idx].cccd_handle, data, 2 );

    /* write data source cccd */
    BC_ANCS_PRINTF( "write data source cccd %x\r\n", ancs_characteristics[data_source_idx].cccd_handle );
    data[0] = BLE_GATT_CLIENT_CONFIG_NOTIFICATION & 0xff;
    data[1] = ( BLE_GATT_CLIENT_CONFIG_NOTIFICATION >> 8 ) & 0xff;
    HCI_le_enqueue_gatt_write_request( ancs_characteristics[data_source_idx].cccd_handle, data, 2 );
    }
else
    {
    BC_ANCS_PRINTF( "ancs %s err, invalid cccd\r\n", __FUNCTION__ );
    }
}

/*********************************************************************
*
* @public
* BC_ancs_ble_connected_callback
*
* Callback function when BLE is disconnected
*
*********************************************************************/
void BC_ancs_ble_connected_callback
    (
    void
    )
{
BC_ANCS_PRINTF( "%s\r\n", __FUNCTION__ );
}

/*********************************************************************
*
* @public
* BC_ancs_ble_disconnected_callback
*
* Callback function when BLE is disconnected
*
*********************************************************************/
void BC_ancs_ble_disconnected_callback
    (
    void
    )
{
BC_ANCS_PRINTF( "%s\r\n", __FUNCTION__ );

if( ancs_is_discovered )
    {
    NTF_notify_disconnected( NOTIFICATION_PROTOCOL_ANCS );
    ancs_is_discovered = false;
    }

ancs_start_handle = 0;
ancs_end_handle   = 0;
ancs_characteristic_discovered_count = 0;
memset( ancs_characteristics, 0, sizeof( ancs_characteristics ) );

for( int i = 0; i < DICTIONARY_SIZE; i++ )
    {
    ancs_uid_category_dictionary[i].flag = DICTIONARY_FLAG_FREE;
    }

ancs_notification_attributes_received_size = 0;
}

/*********************************************************************
*
* @public
* BC_ancs_service_discovered_callback
*
* Callback function when AMS is discovered
*
* @param start_handle The start handle of AMS service
* @param end_handle The end handle of AMS service
*
*********************************************************************/
void BC_ancs_service_discovered_callback
    (
    const uint16_t start_handle,
    const uint16_t end_handle
    )
{
BC_ANCS_PRINTF( "%s handle 0x%x - 0x%x\r\n", __FUNCTION__, start_handle, end_handle );
ancs_is_discovered = true;
ancs_start_handle  = start_handle;
ancs_end_handle    = end_handle;

NTF_notify_connected( NOTIFICATION_PROTOCOL_ANCS, &ancs_notification_callback );
}

/*********************************************************************
*
* @public
* BC_ancs_characteristic_discovered_callback
*
* Callback function from BLE when characteristic is discovered
*
* @param uuid UUID of the characteristic
* @param value_handle The handle of the charactertistic
*
*********************************************************************/
void BC_ancs_characteristic_discovered_callback
    (
    const uint8_t* uuid,
    const uint16_t value_handle
    )
{
BC_ANCS_PRINTF( "%s, handle: 0x%x\r\n", __FUNCTION__, value_handle );
for( int i = 0; i < ANCS_CHARACTERISTIC_TOTAL; i++ )
    {
    if( 0 == memcmp( uuid, ANCS_CHARACTERISTIC_UUID[i], UUID_128BIT_LEN ) )
        {
        ancs_characteristics[i].is_discovered = true;
        ancs_characteristics[i].value_handle  = value_handle;
        }
    }

/**
 * The characteristics are discovered in the order of ascending handle value.
 * The ancs_characteristics array has to maintain this nature
 * ( ancs_characteristics[x].value_handle < ancs_characteristics[x+1].value_handle )
 * to map the descriptor to the corresponding characteristic later in
 * the BC_ancs_descriptor_discovered_callback.
 *
 * For ANCS, it could be risky to assume that the characteristics are always discovered
 * in the sequence of CONTROL_POINT, NOTIFICATION_SOURCE and DATA_SOURCE.
 * So a lookup table, "ancs_index_table", is used for converting from the characteristic
 * to the index of "ancs_characteristics" array.
 *
 */
if( ANCS_CHARACTERISTIC_TOTAL > ancs_characteristic_discovered_count )
    {
    for( int i = 0; i < ANCS_CHARACTERISTIC_TOTAL; i++ )
        {
        if( 0 == memcmp( uuid, ANCS_CHARACTERISTIC_UUID[i], UUID_128BIT_LEN ) )
            {
            BC_ANCS_PRINTF( "%s, found: %d\r\n", __FUNCTION__, i );
            ancs_characteristics[ancs_characteristic_discovered_count].characteristic = i;
            ancs_characteristics[ancs_characteristic_discovered_count].is_discovered  = true;
            ancs_characteristics[ancs_characteristic_discovered_count].value_handle   = value_handle;
            ancs_index_table[i] = ancs_characteristic_discovered_count;
            ancs_characteristic_discovered_count++;
            break;
            }
        }
    }
else
    {
    BC_ANCS_PRINTF( "%s err\r\n", __FUNCTION__ );
    }
}

/*********************************************************************
*
* @public
* BC_ancs_descriptor_discovered_callback
*
* Callback function from BLE when descriptor is discovered
*
* @param descriptor_handle The handle of the discovered descriptor
*
*********************************************************************/
void BC_ancs_descriptor_discovered_callback
    (
    const uint16_t descriptor_handle
    )
{
uint16_t end_handle = 0;

BC_ANCS_PRINTF( "%s, handle: 0x%04x\r\n", __FUNCTION__, descriptor_handle );

for( int i = 0; i < ANCS_CHARACTERISTIC_TOTAL; i++ )
    {
    if( ANCS_CHARACTERISTIC_TOTAL == ( i + 1 ) )
        {
        end_handle = ancs_end_handle;
        }
    else
        {
        end_handle = ancs_characteristics[i+1].value_handle - 1;
        }

    if( descriptor_handle > ancs_characteristics[i].value_handle &&
        descriptor_handle <= end_handle )
        {
        ancs_characteristics[i].cccd_handle = descriptor_handle;
        BC_ANCS_PRINTF( "found cccd handle of ancs service %d\r\n", i );
        break;
        }
    }
}

/*********************************************************************
*
* @public
* BC_ancs_discovery_complete_callback
*
* Callback function from BLE when the discovery of all the characteristics are completed
*
*********************************************************************/
void BC_ancs_discovery_complete_callback
    (
    void
    )
{
BC_ANCS_PRINTF( "%s\r\n", __FUNCTION__ );
register_notification();
}

/*********************************************************************
*
* @public
* BC_ancs_notification_received_callback
*
* Callback function from BLE when ANCS notification is received
*
* @param handle The handle of characteristic
* @param data The pointer to the data byte array
* @param length The length of the data byte array
*
*********************************************************************/
void BC_ancs_notification_received_callback
    (
    const uint16_t handle,
    const uint8_t* data,
    const uint16_t length
    )
{
BC_ANCS_PRINTF( "%s, handle: 0x%x, len: %d\r\n", __FUNCTION__, handle, length );

if( length <= HCI_MAX_DATA_SIZE )
    {
    gatt_notification_struct gatt_notification_data;
    gatt_notification_data.handle   = handle;
    gatt_notification_data.data_len = length;

    memcpy( gatt_notification_data.data, data, length );

    if( pdTRUE == xQueueSend( gatt_notification_queue_handle, &gatt_notification_data, 0 ) )
        {
        bc_notify_ancs_gatt_notification_received();
        }
    else
        {
        PRINTF( "Err: %s queue full\r\n", __FUNCTION__ );
        }
    }
else
    {
    PRINTF( "Err: %s %d > %d\r\n", __FUNCTION__, length, HCI_MAX_DATA_SIZE );
    }
}

/*********************************************************************
*
* @private
* bc_ancs_process_gatt_notification
*
* Process ANCS GATT notification in the Bluetooth Connectivity task
*
*********************************************************************/
void bc_ancs_process_gatt_notification
    (
    void
    )
{
const int notification_source_idx = ancs_index_table[ANCS_CHARACTERISTIC_NOTIFICATION_SOURCE];
const int data_source_idx         = ancs_index_table[ANCS_CHARACTERISTIC_DATA_SOURCE];
gatt_notification_struct gatt_notification;

while( pdTRUE == xQueueReceive( gatt_notification_queue_handle, &gatt_notification, 0 ) )
    {
    if( ancs_characteristics[notification_source_idx].value_handle == gatt_notification.handle )
        {
        proc_notification_source_data( gatt_notification.data, gatt_notification.data_len );
        }
    else if( ancs_characteristics[data_source_idx].value_handle == gatt_notification.handle )
        {
        recompose_data_source_notification_attributes( gatt_notification.data, gatt_notification.data_len );
        }
    else
        {
        PRINTF( "Err: invalid handle 0x%x\r\n", gatt_notification.handle );
        }
    }
}

/*********************************************************************
*
* @private
* send_action
*
* Send action from notification consumer (NC) to notification provider (NP)
*
* @param uid Unique notification id
* @param action_id ANCS_ACTION_ID_POSITIVE or ANCS_ACTION_ID_NEGATIVE
*
*********************************************************************/
static void send_action
    (
    const uint32_t       uid,
    const ancs_action_id action_id
    )
{
uint8_t data[8];
int     control_point_idx = ancs_index_table[ANCS_CHARACTERISTIC_CONTROL_POINT];

BC_ANCS_PRINTF( "%s %d %d\r\n", __FUNCTION__, uid, action_id );

if( control_point_idx < ANCS_CHARACTERISTIC_TOTAL &&
    action_id < ANCS_ACTION_ID_TOTAL )
    {
    data[0] = ANCS_COMMAND_ID_PERFORM_NOTIFICATION_ACTION;
    data[1] = uid & 0xff;
    data[2] = ( uid >>  8 ) & 0xff;
    data[3] = ( uid >> 16 ) & 0xff;
    data[4] = ( uid >> 24 ) & 0xff;
    data[5] = ( uint8_t )action_id;

    HCI_le_enqueue_gatt_write_request( ancs_characteristics[control_point_idx].value_handle, data, 6 );
    }
else
    {
    PRINTF( "Err: %s\r\n", __FUNCTION__ );
    }
}

/*********************************************************************
*
* @public
* BC_ancs_answer_call_callback
*
* Callback function from UI to answer the phone call
*
* @param uid Unique notification id
*
*********************************************************************/
void BC_ancs_answer_call_callback
    (
    const uint32_t uid
    )
{
send_action( uid, ANCS_ACTION_ID_POSITIVE );
}

/*********************************************************************
*
* @public
* BC_ancs_decline_call_callback
*
* Callback function from UI to decline the phone call
*
* @param uid Unique notification id
*
*********************************************************************/
void BC_ancs_decline_call_callback
    (
    const uint32_t uid
    )
{
send_action( uid, ANCS_ACTION_ID_NEGATIVE );
}

/*********************************************************************
*
* @public
* bc_ancs_init
*
* Init ANCS parser.
*
*********************************************************************/
void bc_ancs_init
    (
    void
    )
{
gatt_notification_queue_handle = xQueueCreate( GATT_NOTIFICATION_DATA_QUEUE_SIZE, sizeof( gatt_notification_struct ) );
configASSERT( NULL != gatt_notification_queue_handle );

HCI_le_register_client_callback( BLE_CLIENT_ANCS, &ancs_client_callback );
}
