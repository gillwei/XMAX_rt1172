/*********************************************************************
* @file
* bc_ams_priv.h
*
* @brief
* Bluetooth Connectivity - Private API of AMS
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef BC_AMS_PRIV_H
#define BC_AMS_PRIV_H

#ifdef __cplusplus
extern "C"{
#endif

#define ENABLE_BC_AMS_DEBUG_LOG   ( 1 )
#if( ENABLE_BC_AMS_DEBUG_LOG )
    #define BC_AMS_PRINTF PRINTF
#else
    #define BC_AMS_PRINTF(fmt,...)
#endif

void bc_ams_init( void );

#ifdef __cplusplus
}
#endif

#endif /* BC_AMS_PRIV_H */
