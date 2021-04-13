/*********************************************************************
* @file
* ntf_priv.h
*
* @brief
* Notification - Private API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef NTF_PRIV_H
#define NTF_PRIV_H

#ifdef __cplusplus
extern "C"{
#endif

#include "NTF_pub.h"

#define ENABLE_NTF_DEBUG_LOG   ( 1 )
#if( ENABLE_NTF_DEBUG_LOG )
    #define NTF_PRINTF PRINTF
#else
    #define NTF_PRINTF(fmt,...)
#endif

typedef struct
    {
    uint32_t uid;                                     /**< notification unique id */
    uint16_t call_repetition;                         /**< notification call repitition count */
    EnumNotificationCategory category;                /**< notification categoty */
    notification_time_t      received_time;           /**< notification received date time */
    uint8_t  title[NOTIFICATION_TITLE_MAX_LEN];       /**< notification title */
    uint8_t  subtitle[NOTIFICATION_SUBTITLE_MAX_LEN]; /**< notification subtitle */
    uint8_t  message[NOTIFICATION_MESSAGE_MAX_LEN];   /**< notification message */
    } notification_buffer_s;

void ntf_buffer_init( void );
int  ntf_buffer_add_notification( const uint32_t uid, const uint8_t* title, const uint8_t* subtitle, const uint8_t* message, const EnumNotificationCategory category, const notification_time_t received_time );
int  ntf_buffer_delete_notification_of_uid( const uint32_t uid );
int  ntf_buffer_get_notification_at_idx( const uint32_t idx, uint32_t* uid, uint16_t* call_repetition, uint8_t* title, const uint32_t title_length, uint8_t* subtitle, const uint32_t subtitle_length, uint8_t* message, const uint32_t message_length, EnumNotificationCategory* category, notification_time_t* received_time );
void ntf_buffer_reset( void );
EnumNotificationCategory ntf_buffer_get_category_of_uid( const uint32_t uid );

#ifdef __cplusplus
}
#endif

#endif /* NTF_PRIV_H */
