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
#define UNIT_TEST_ENABLE        ( UNIT_TEST_FACTORY )

void TEST_init( void );

#ifdef __cplusplus
}
#endif

#endif /* TEST_PUB_H */


