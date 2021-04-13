/*********************************************************************
* @file
* TEST_pub.h
*
* @brief
* Test module - public API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef TEST_PUB_H
#define TEST_PUB_H

#ifdef __cplusplus
extern "C"{
#endif

#define UNIT_TEST_FACTORY       ( 0 )
#define UNIT_TEST_BURNIN        ( 0 )
#define UNIT_TEST_INSPECTION    ( 0 )
#define UNIT_TEST_JPEG          ( 0 )
#define UNIT_TEST_ADC           ( 0 )
#define UNIT_TEST_NAVI          ( 0 )
#define UNIT_TEST_EEPROM        ( 0 )
#define UNIT_TEST_VI            ( 0 )
#define UNIT_TEST_NOTIFICATION  ( 0 )
#define UNIT_TEST_ENABLE        ( UNIT_TEST_INSPECTION | UNIT_TEST_FACTORY | UNIT_TEST_BURNIN | UNIT_TEST_JPEG | UNIT_TEST_ADC | UNIT_TEST_NAVI | UNIT_TEST_EEPROM | UNIT_TEST_VI | UNIT_TEST_NOTIFICATION )

#include "NAVI_pub.h"

void TEST_init( void );
void TEST_motocon_tx( const int test_item );

void TEST_navi_set_test_type( const int type );
navi_data_type* TEST_get_navi_obj( void );
bool TEST_navi_get_route_guidance_status( void );
void TEST_get_navi_tbt_data( const int active_tbt_index, uint32_t* list_index, uint32_t* icon_index, uint16_t* distance, char** dist_unit, char** description );

#ifdef __cplusplus
}
#endif

#endif /* TEST_PUB_H */


