/*********************************************************************
* @file
* mm_priv.h
*
* @brief
* Media manager module - Private API
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef MM_PRIV_H
#define MM_PRIV_H

#ifdef __cplusplus
extern "C"{
#endif

#include "MM_pub_ams_type.h"

bool mm_queue_cmd( ams_remote_command send_cmd );
void mm_start_elapsed_timer( void );
void mm_stop_elapsed_timer( void );
void mm_update_elapsed_time( void );
void mm_start_delay_timer( void );
void mm_ams_gatt_update_elapsed_time( void );
void mm_motocon_init( void );

#ifdef __cplusplus
}
#endif

#endif /* MM_PRIV_H */
