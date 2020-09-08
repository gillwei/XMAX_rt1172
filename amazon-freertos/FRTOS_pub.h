/*********************************************************************
* @file
* FRTOS_pub.h
*
* @brief
* FreeRTOS public API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef FRTOS_PUB_H
#define FRTOS_PUB_H

#ifdef __cplusplus
extern "C"{
#endif

#include "FreeRTOS.h"
#include "task.h"

void FRTOS_stat_init( void );
void FRTOS_print_task_status( TaskHandle_t task_handle );

#ifdef __cplusplus
}
#endif

#endif /* FRTOS_PUB_H */

