/*********************************************************************
* @file
* frtos_priv.h
*
* @brief
* FreeRTOS private API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef FRTOS_PRIV_H
#define FRTOS_PRIV_H

#ifdef __cplusplus
extern "C"{
#endif

void frtos_stat_timer_config( void );
int  frtos_stat_timer_count( void );

#ifdef __cplusplus
}
#endif

#endif /* FRTOS_PRIV_H */

