/*********************************************************************
* @file
* test_priv.h
*
* @brief
* Test module - private API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef TEST_PRIV_H
#define TEST_PRIV_H

#ifdef __cplusplus
extern "C"{
#endif

#define TEST_TICK_PERIOD_MS    ( 10 )

void test_production_int( void );
void test_production_proc( void );
void test_inspection_int( void );
void test_inspection_proc( void );
void test_burnin_int( void );
void test_burnin_proc( void );
void test_jpeg_int( void );
void test_jpeg_proc( void );
void test_adc_int( void );
void test_adc_proc( void );
void test_navi_int( void );
void test_navi_proc( void );
void test_eeprom_int( void );
void test_eeprom_proc( void );
void test_vi_int( void );
void test_vi_proc( void );
void test_notification_int( void );
void test_notification_proc( void );
void test_wea_int( void );
void test_wea_proc( void );

#ifdef __cplusplus
}
#endif

#endif /* TEST_PRIV_H */

