/*********************************************************************
* @file
* navi_priv.h
*
* @brief
* Navigation - Private API
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifndef NAVI_PRIV_H
#define NAVI_PRIV_H

#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>
#include <stdbool.h>
#include "NAVILITE_pub.h"

int navi_add_event( uint8_t* str, uint8_t str_size, navilite_navievent_type navi_evnt_type, navilite_navievent_camera_extra_subtype navi_evnt_extra_subtype, uint8_t visibility );
void navi_event_init( void );
void navi_send_event_to_queue( uint8_t* str, uint8_t str_size, navilite_navievent_type navi_evnt_type, navilite_navievent_camera_extra_subtype navi_evnt_extra_subtype, uint8_t visibility );

#ifdef __cplusplus
}
#endif

#endif /* NAVI_PRIV_H */
