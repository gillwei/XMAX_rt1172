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

void vi_key_init( void );
void vi_key_status_changed( const CoreKeyCode key_code, const int key_status );
void vi_key_proc( void );

#ifdef __cplusplus
}
#endif

#endif /* VI_PRIV_H */

