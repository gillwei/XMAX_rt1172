/*********************************************************************
* @file
* NTF_pub.h
*
* @brief
* Notification - Public API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef NTF_PUB_H
#define NTF_PUB_H

#include "Enum.h"

#ifdef __cplusplus
extern "C"{
#endif

#define NOTIFICATION_MAX_NUM                        ( 100 )

#define NOTIFICATION_TITLE_MAX_LEN                  ( 64 )
#define NOTIFICATION_SUBTITLE_MAX_LEN               ( 64 )
#define NOTIFICATION_MESSAGE_MAX_LEN                ( 512 )
#define PHONE_CALLER_MAX_LEN                        ( 64 )

typedef enum
    {
    NOTIFICATION_PROTOCOL_NONE,
    NOTIFICATION_PROTOCOL_ANCS,
    NOTIFICATION_PROTOCOL_MOTOCON
    } notification_protocol_t;

typedef struct
    {
    uint16_t year;      /**< year */
    uint8_t  month;     /**< month from 1 to 12 */
    uint8_t  day;       /**< day from 1 to 31 */
    uint8_t  hour;      /**< hour from 0 to 23 */
    uint8_t  minute;    /**< minute from 0 to 59 */
    uint8_t  second;    /**< second from 0 to 59 */
    } notification_time_t;

typedef struct
    {
    void ( *notification_answer_call_callback )( const uint32_t uid );
    void ( *notification_decline_call_callback )( const uint32_t uid );
    void ( *notification_volume_control_callback )( const EnumVolumeControl control );
    } notification_callback_t;

void NTF_init( void );
void NTF_notify_connected( const notification_protocol_t protocol, notification_callback_t* callback );
void NTF_notify_disconnected( const notification_protocol_t protocol );
void NTF_notify_incoming_call_started( const uint32_t uid, const uint8_t* caller, const bool is_volume_adjustable );
void NTF_notify_incoming_call_stopped( const uint32_t uid );
void NTF_notify_active_call_started( const uint32_t uid, const uint8_t* caller, const bool is_volume_adjustable );
void NTF_notify_active_call_stopped( const uint32_t uid );

void NTF_answer_call( void );
void NTF_decline_call( void );
EnumPhoneCallState NTF_get_phonecall_state( void );

int  NTF_get_notification_num( void );
int  NTF_get_notification_num_of_category( EnumNotificationCategory category );
int  NTF_add_notification( const uint32_t uid, const uint8_t* title, const uint8_t* subtitle, const uint8_t* message, const EnumNotificationCategory category, const notification_time_t received_time );
int  NTF_get_notification_at_idx( const uint32_t idx, uint32_t* uid, uint16_t* call_repetition, uint8_t* title, const uint32_t title_length, uint8_t* subtitle, const uint32_t subtitle_length, uint8_t* message, const uint32_t message_length, EnumNotificationCategory* category, notification_time_t* received_time );
int  NTF_get_idx_of_notification_uid( const uint32_t uid );

void NTF_delete_notification( const uint32_t uid );
void NTF_notify_notification_deleted( const uint32_t uid );

void NTF_update_active_call_duration( void );
uint32_t NTF_get_active_call_duration( void );
void NTF_get_incoming_call_caller( uint8_t** phone_caller );
void NTF_get_active_call_caller( uint8_t** phone_caller );
bool NTF_is_phonecall_volume_controllable( void );
void NTF_phonecall_volume_control( const EnumVolumeControl control );

int32_t NTF_call_native( const EnumNotificationNativeCall native_call, const uint32_t data );

#ifdef __cplusplus
}
#endif

#endif /* NTF_PUB_H */
