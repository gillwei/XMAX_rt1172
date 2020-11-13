/*********************************************************************
* @file
* VI_pub.h
*
* @brief
* Vehicle information module - public API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef VI_PUB_H
#define VI_PUB_H

#ifdef __cplusplus
extern "C"{
#endif

#include "CAN_pub.h"

void VI_init( void );
void VI_notify_vehicle_data_changed( const il_rx_frm_index_t message_frame, const uint16_t signal_id, const uint16_t data );

#ifdef __cplusplus
}
#endif

#endif /* VI_PUB_H */

