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

int navi_add_event( uint8_t* str, uint8_t str_size, navilite_navievent_type navi_evnt_type, navilite_navievent_extra_subtype navi_evnt_extra_subtype, uint8_t visibility );
void navi_event_init( void );
void navi_send_event_to_queue( uint8_t* str, uint8_t str_size, navilite_navievent_type navi_evnt_type, navilite_navievent_extra_subtype navi_evnt_extra_subtype, uint8_t visibility );
void navi_tbt_init( void );
void navi_poi_init( void );
void navi_add_tbt_item( navilite_tbt_list_type* tbt_list_item );
void navi_update_active_tbt_item( const uint16_t recv_act_tbt_idx );
bool navi_set_tbt_item( const uint8_t icon_index, const uint32_t distance, const uint8_t* distance_unit, const uint8_t distance_unit_size );
void navi_notify_more_tbt_item( const bool has_next_tbt_request, const uint16_t tbt_list_size );
void navi_add_poi_item( navilite_poi_list_type* poi_list_item );
void navi_notify_more_poi_item( const uint16_t poi_list_size );
uint32_t navi_get_poi_list_index( uint32_t idx );

#ifdef __cplusplus
}
#endif

#endif /* NAVI_PRIV_H */
