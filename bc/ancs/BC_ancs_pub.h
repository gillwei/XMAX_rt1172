/*********************************************************************
* @file
* BC_ansc_pub.h
*
* @brief
* Bluetooth Connectivity - Public API of ANCS
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef BC_ANCS_PUB_H
#define BC_ANCS_PUB_H

#ifdef __cplusplus
extern "C"{
#endif

bool BC_ancs_is_category_enabled( const uint8_t category_id );
void BC_ancs_set_notification_category_enabled( const uint8_t category_id, const uint8_t enabled );

#ifdef __cplusplus
}
#endif

#endif /* BC_ANCS_PUB_H */




