/*********************************************************************
* @file
* vi_priv.h
*
* @brief
* Vehicle information module - private API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef VI_PRIV_H
#define VI_PRIV_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Core.h"

#define RESET_VEHICLE_INFO_REQUEST_ID               ( 0x10 )
#define RESET_VEHICLE_INFO_RESPONSE_ID              ( 0x50 )

#define CHANGE_ODO_TRIP_REQUEST_ID                  ( 0x15 )
#define CHANGE_ODO_TRIP_RESPONSE_ID                 ( 0x55 )

#define VEHICLE_FEATURE_LIST_POSITIVE_RESPONSE_ID   ( 0x50 )
#define VEHICLE_NEGATIVE_RESPONSE_ID                ( 0xEE )

void vi_key_init( void );
void vi_key_status_changed( const CoreKeyCode key_code, const int key_status );
void vi_key_proc( void );
void vi_rx_init_data( void );

#ifdef __cplusplus
}
#endif

#endif /* VI_PRIV_H */

