/*********************************************************************
* @file
* BC_ams_pub.h
*
* @brief
* Bluetooth Connectivity - Public API of AMS
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef BC_AMS_PUB_H
#define BC_AMS_PUB_H

#ifdef __cplusplus
extern "C"{
#endif
#include "fsl_debug_console.h"

void BC_ams_send_remote_control( const uint8_t re_ctrl_cmd );
bool BC_ams_is_ams_connected( void );

#ifdef __cplusplus
}
#endif

#endif /* BC_AMS_PUB_H */
