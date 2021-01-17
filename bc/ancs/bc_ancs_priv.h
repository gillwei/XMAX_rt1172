/*********************************************************************
* @file
* bc_ansc_priv.h
*
* @brief
* Bluetooth Connectivity - Private API of ANCS
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef BC_ANCS_PRIV_H
#define BC_ANCS_PRIV_H

#ifdef __cplusplus
extern "C"{
#endif

#define ENABLE_BC_ANCS_DEBUG_LOG   ( 1 )
#if( ENABLE_BC_ANCS_DEBUG_LOG )
    #define BC_ANCS_PRINTF PRINTF
#else
    #define BC_ANCS_PRINTF(fmt,...)
#endif

void bc_ancs_init( void );
void bc_ancs_process_gatt_notification( void );

#ifdef __cplusplus
}
#endif

#endif /* BC_ANCS_PRIV_H */



