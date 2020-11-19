/*********************************************************************
* @file
* NAVI_pub.h
*
* @brief
* Navigation module - public API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef NAVI_PUB_H
#define NAVI_PUB_H

#ifdef __cplusplus
extern "C"{
#endif

void NAVI_init( void );
void NAVI_jpeg_data_received( uint32_t jpeg_size, uint8_t* buffer_addr );

#ifdef __cplusplus
}
#endif

#endif /* NAVI_PUB_H */

