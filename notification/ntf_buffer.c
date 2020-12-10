/*********************************************************************
* @file
* ntf_buffer.c
*
* @brief
* Notification - buffer
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "task.h"
#include "semphr.h"
#include "fsl_debug_console.h"
#include "error_code.h"
#include "ntf_priv.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define INVALID_BUFFER_IDX  ( -1 )

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
static notification_buffer_s notification_buffer[NOTIFICATION_MAX_NUM];

typedef struct
    {
    int num;
    int idx[NOTIFICATION_MAX_NUM];
    } buffer_lookup_table_s;

static buffer_lookup_table_s free_buffer_lookup_table;
static buffer_lookup_table_s used_buffer_lookup_table;

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @private
* get_free_buffer_idx
*
* Get free buffer index
*
*********************************************************************/
static int get_free_buffer_idx
    (
    void
    )
{
NTF_PRINTF( "%s %d/%d\r\n", __FUNCTION__, used_buffer_lookup_table.num, free_buffer_lookup_table.num );
int free_buffer_idx = INVALID_BUFFER_IDX;
if( free_buffer_lookup_table.num > 0 )
    {
    free_buffer_idx = free_buffer_lookup_table.idx[free_buffer_lookup_table.num - 1];
    free_buffer_lookup_table.num--;

    used_buffer_lookup_table.idx[used_buffer_lookup_table.num] = free_buffer_idx;
    used_buffer_lookup_table.num++;
    }
NTF_PRINTF( "%s: %d\r\n", __FUNCTION__, free_buffer_idx );
return free_buffer_idx;
}

/*********************************************************************
*
* @private
* find_same_caller_missed_call
*
* Find the missed call notification from the same caller
*
* @param title Pointer to the title buffer
*
* @return Used buffer lookup table index of the same caller
*
*********************************************************************/
static int find_same_caller_missed_call
    (
    const uint8_t* title
    )
{
uint32_t used_buffer_idx = 0;
int      i = 0;
uint32_t used_buffer_lookup_table_idx = INVALID_BUFFER_IDX;

for( i = 0; i < used_buffer_lookup_table.num; i++ )
    {
    used_buffer_idx = used_buffer_lookup_table.idx[i];
    if( EnumNotificationCategoryMISSED_CALL == notification_buffer[used_buffer_idx].category &&
        !memcmp( notification_buffer[used_buffer_idx].title, title, strlen( (const char*)title ) ) )
        {
        used_buffer_lookup_table_idx = i;
        break;
        }
    }

NTF_PRINTF( "%s %s %d\r\n", __FUNCTION__, title, used_buffer_idx );
return used_buffer_lookup_table_idx;
}

/*********************************************************************
*
* @private
* move_notification_last
*
* Move the notification to the last
*
* @param used_buffer_lookup_table_idx Index in the used buffer lookup table to move
*
* @return Result of moving buffer last
*
*********************************************************************/
static int move_notification_last
    (
    const int used_buffer_lookup_table_idx
    )
{
int result = ERR_NONE;
int      i = 0;
if( used_buffer_lookup_table_idx < used_buffer_lookup_table.num )
    {
	uint32_t notification_buffer_idx = used_buffer_lookup_table.idx[used_buffer_lookup_table_idx];
    for( i = used_buffer_lookup_table_idx ; i < used_buffer_lookup_table.num - 1; i++ )
        {
        used_buffer_lookup_table.idx[i] = used_buffer_lookup_table.idx[i+1];
        }
    used_buffer_lookup_table.idx[used_buffer_lookup_table.num-1] = notification_buffer_idx;
    }
else
    {
    result = ERR_BUF_OPERATION;
    }

return result;
}

/*********************************************************************
*
* @private
* delete_notification_at_used_buffer_idx
*
* Delete notification at the used buffer of idx
*
* @param idx Index of the used buffer
*
*********************************************************************/
static int delete_notification_at_used_buffer_idx
    (
    const int idx
    )
{
NTF_PRINTF( "%s %d\r\n", __FUNCTION__, idx );
int result = ERR_NONE;
int i = 0;
if( idx < used_buffer_lookup_table.num )
    {
    free_buffer_lookup_table.idx[free_buffer_lookup_table.num] = used_buffer_lookup_table.idx[idx];
    free_buffer_lookup_table.num++;
    for( i = idx + 1; i < used_buffer_lookup_table.num; i++ )
        {
        used_buffer_lookup_table.idx[i-1] = used_buffer_lookup_table.idx[i];
        }
    used_buffer_lookup_table.num--;
    }
else
    {
    result = ERR_BUF_OPERATION;
    }
return result;
}

/*********************************************************************
*
* @private
* ntf_buffer_add_notification
*
* Add new notification into the buffer
*
* @param uid Unique notification id
* @param title Pointer to the title buffer
* @param mesaage Pointer to the message buffer
* @param category Notification category
* @param received_time Received time of the notification
*
* @return Resut of adding notification to buffer
*
*********************************************************************/
int ntf_buffer_add_notification
    (
    const uint32_t uid,
    const uint8_t* title,
    const uint8_t* subtitle,
    const uint8_t* message,
    const EnumNotificationCategory category,
    const notification_time_t      received_time
    )
{
NTF_PRINTF( "%s %d %s\r\n", __FUNCTION__, uid, title );
int result = ERR_NONE;
int same_caller_buf_idx = INVALID_BUFFER_IDX;
int string_length = 0;

// find if this missed call from the same caller
if( EnumNotificationCategoryMISSED_CALL == category )
    {
    same_caller_buf_idx = find_same_caller_missed_call( title );
    }

if( INVALID_BUFFER_IDX < same_caller_buf_idx )
    {
    notification_buffer[used_buffer_lookup_table.idx[same_caller_buf_idx]].call_repetition++;
    notification_buffer[used_buffer_lookup_table.idx[same_caller_buf_idx]].received_time = received_time;
    result = move_notification_last( same_caller_buf_idx );
    }
else
    {
    int free_buffer_idx = get_free_buffer_idx();
    if( INVALID_BUFFER_IDX == free_buffer_idx )
        {
        NTF_PRINTF( "%s hdl no free buf\r\n", __FUNCTION__ );
        delete_notification_at_used_buffer_idx( 0 );
        free_buffer_idx = get_free_buffer_idx();
        }

    if( INVALID_BUFFER_IDX < free_buffer_idx )
        {
        notification_buffer[free_buffer_idx].uid           = uid;
        notification_buffer[free_buffer_idx].received_time = received_time;
        notification_buffer[free_buffer_idx].category      = category;
        if( EnumNotificationCategoryMISSED_CALL == category )
            {
            notification_buffer[free_buffer_idx].call_repetition = 1;
            }
        else
            {
            notification_buffer[free_buffer_idx].call_repetition = 0;
            }

        string_length = strlen( (const char*)title );
        string_length = MIN( string_length, NOTIFICATION_TITLE_MAX_LEN - 1 );
        memcpy( notification_buffer[free_buffer_idx].title, title, string_length );
        notification_buffer[free_buffer_idx].title[string_length] = '\0';

        string_length = strlen( (const char*)subtitle );
        string_length = MIN( string_length, NOTIFICATION_SUBTITLE_MAX_LEN - 1 );
        memcpy( notification_buffer[free_buffer_idx].subtitle, subtitle, NOTIFICATION_SUBTITLE_MAX_LEN );
        notification_buffer[free_buffer_idx].subtitle[string_length] = '\0';

        string_length = strlen( (const char*)message );
        string_length = MIN( string_length, NOTIFICATION_MESSAGE_MAX_LEN - 1 );
        memcpy( notification_buffer[free_buffer_idx].message, message, NOTIFICATION_MESSAGE_MAX_LEN );
        notification_buffer[free_buffer_idx].message[string_length] = '\0';
        }
    else
        {
        result = ERR_BUF_OPERATION;
        }
    }
return result;
}

/*********************************************************************
*
* @private
* ntf_buffer_delete_notification_of_uid
*
* Delete notification of uid
*
* @param uid Unique notification id
*
*********************************************************************/
int ntf_buffer_delete_notification_of_uid
    (
    const uint32_t uid
    )
{
int result = ERR_NONE;
int i = 0;
int notification_buf_idx = 0;
int found_idx = INVALID_BUFFER_IDX;

NTF_PRINTF( "%s %u\r\n", __FUNCTION__, uid );

for( i = 0; i < used_buffer_lookup_table.num; i++ )
    {
    notification_buf_idx = used_buffer_lookup_table.idx[i];
    if( uid == notification_buffer[notification_buf_idx].uid )
        {
        found_idx = i;
        break;
        }
    }

if( found_idx >= 0 )
    {
    free_buffer_lookup_table.idx[free_buffer_lookup_table.num] = used_buffer_lookup_table.idx[found_idx];
    free_buffer_lookup_table.num++;
    for( i = found_idx + 1; i < used_buffer_lookup_table.num; i++ )
        {
        used_buffer_lookup_table.idx[i-1] = used_buffer_lookup_table.idx[i];
        }
    used_buffer_lookup_table.num--;
    }
else
    {
    result = ERR_BUF_OPERATION;
    }
return result;
}

/*********************************************************************
*
* @private
* ntf_buffer_get_category_of_uid
*
* Get the category of the notification
*
* @param uid Unique notification id
* @return Category of the notification
*
*********************************************************************/
EnumNotificationCategory ntf_buffer_get_category_of_uid
    (
    const uint32_t uid
    )
{
int i = 0;
int notification_buf_idx = 0;
EnumNotificationCategory category = EnumNotificationCategoryMESSAGE;

for( i = 0; i < used_buffer_lookup_table.num; i++ )
    {
    notification_buf_idx = used_buffer_lookup_table.idx[i];
    if( uid == notification_buffer[notification_buf_idx].uid )
        {
        category = notification_buffer[notification_buf_idx].category;
        break;
        }
    }

NTF_PRINTF( "%s %u %d\r\n", __FUNCTION__, uid, category );
return category;
}

/*********************************************************************
*
* @public
* NTF_get_notification_num
*
* Get notification num
*
*********************************************************************/
int NTF_get_notification_num
    (
    void
    )
{
return used_buffer_lookup_table.num;
}

/*********************************************************************
*
* @private
* ntf_buffer_get_notification_at_idx
*
* Get notification of brief information from the used buffer
*
* @param idx The index of the notification buffer
* @param uid The pointer to the notification uid
* @param title The pointer to the title string
* @param title_length The buffer size to keep title string
* @param message The pointer to message string
* @param message_length message buffer size
* @param category The pointer to the category
* @param received_time The pointer to the recevied time
*
*********************************************************************/
int ntf_buffer_get_notification_at_idx
    (
    const uint32_t idx,
    uint32_t*      uid,
    uint16_t*      call_repetition,
    uint8_t*       title,
    const uint32_t title_length,
    uint8_t*       message,
    const uint32_t message_length,
    EnumNotificationCategory* category,
    notification_time_t*      received_time
    )
{
NTF_PRINTF( "%s %d\r\n", __FUNCTION__, idx );
int      result = ERR_NONE;
uint32_t copy_length = 0;

if( idx < used_buffer_lookup_table.num )
    {
    int buffer_idx   = used_buffer_lookup_table.idx[idx];
    *uid             = notification_buffer[buffer_idx].uid;
    *call_repetition = notification_buffer[buffer_idx].call_repetition;
    *category        = notification_buffer[buffer_idx].category;
    *received_time   = notification_buffer[buffer_idx].received_time;

    copy_length = MIN( title_length, NOTIFICATION_TITLE_MAX_LEN );
    memcpy( title, notification_buffer[buffer_idx].title, copy_length );
    title[copy_length] = '\0';

    copy_length = MIN( message_length, NOTIFICATION_MESSAGE_MAX_LEN );
    memcpy( message, notification_buffer[buffer_idx].message, copy_length );
    message[copy_length] = '\0';
    }
else
    {
    result = ERR_BUF_OPERATION;
    }
return result;
}

/*********************************************************************
*
* @public
* NTF_get_idx_of_notification_uid
*
* Get index of the used buffer having the specific UID
*
* @param uid Unique notification id
*
* @return Index of the used buffer having the specific UID
*
*********************************************************************/
int NTF_get_idx_of_notification_uid
    (
    const uint32_t uid
    )
{
int used_buffer_idx = -1;
for( int i = 0; i < used_buffer_lookup_table.num; i++ )
    {
    if( notification_buffer[used_buffer_lookup_table.idx[i]].uid == uid )
        {
        used_buffer_idx = i;
        break;
        }
    }
NTF_PRINTF( "%s %u %d\r\n", __FUNCTION__, uid, used_buffer_idx );
return used_buffer_idx;
}


/*********************************************************************
*
* @private
* ntf_buffer_reset
*
* Reset notification buffer
*
*********************************************************************/
void ntf_buffer_reset
    (
    void
    )
{
NTF_PRINTF( "%s\r\n", __FUNCTION__ );
for( int i = 0; i < NOTIFICATION_MAX_NUM; i++ )
    {
    free_buffer_lookup_table.idx[i] = i;
    used_buffer_lookup_table.idx[i] = INVALID_BUFFER_IDX;
    }
free_buffer_lookup_table.num = NOTIFICATION_MAX_NUM;
used_buffer_lookup_table.num = 0;
}
