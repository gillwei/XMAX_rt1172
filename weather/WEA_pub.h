/*********************************************************************
* @file
* WEA_pub.h
*
* @brief
* Weather module - public API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef WEA_PUB_H
#define WEA_PUB_H

#ifdef __cplusplus
extern "C"{
#endif

#include "BC_motocon_pub_type.h"

#define MAX_LOC_LEN         ( 64 )

void WEA_init( void );
bc_motocon_weather_info_t* WEA_get_weather_obj( const int index );
char* WEA_get_weather_location( void );
int WEA_get_weather_weekday( void );
void WEA_reset_weather_info_threshold( void );

#ifdef __cplusplus
}
#endif

#endif /* WEA_PUB_H */
