/*******************************************************************************
* @file
* NAVILITE_config.h
*
* @brief
* NAVILITE public config file
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
********************************************************************************/
#ifndef NAVILITE_CONFIG_H

// BUILD OS SUPPORT DEFINE
#define NAVLITE_BUILD_OS_MCU 1
#define NAVLITE_BUILD_OS_LINUX 2
#define NAVLITE_BUILD_OS_ANDROID 3
#define NAVLITE_BUILD_OS_IOS 4

// BUILD TARGET DEFINE
#define NAVILITE_TARGET_MCU 1
#define NAVILITE_TARGET_MOBILE 2

// BUILD SETTINGS (Modifiable)
// buiild target role
#define NAVILITE_BUILD_ROLE NAVILITE_TARGET_MCU

// build target platform choice
#define NAVILITE_PLATFORM_SUPPORT NAVLITE_BUILD_OS_MCU

// message queue size for default
#define NAVILITE_MESSAGE_QUEUE_SIZE 300

// enable ack for image or ESN data transfer
#define NAVILITE_SESSION_ACK_SUPPORT 1

// enable ack serial data sending
#define NAVILITE_SESSION_ACK_SERIAL_SUPPORT 0

// support the ESN report to app if function is ready
#define NAVILITE_ESN_REPORT_SUPPORT 1

// support the serial send if function is ready
#define NAVILITE_SERIAL_SEND_SUPPORT 1

// enable nanopb support if available
#define NAVILITE_NANOPB_SUPPORT      0

// set this 1 if you want to do local test mode during HMI integration
#define NAVILITE_LOCAL_HMI_TEST_MODE 0

// simulation tick speed for hmi test local mode
#define NAVILITE_LOOP_TICK_DEFAULT 5000

// runloop tick threadhold
#define NAVILITE_RUNLOOP_TICK_DEFAULT 1000

// disable function not ready
#define NAVILITE_FUNC_DISABLED 0

// buffer size for hold data stream from HCI buffer in navilite task
#define NAVILITE_QUEUE_BUFFER_SIZE 240

// jpeg max buffer size
#define NAVILITE_JPEG_BUFFER_MAX_SIZE ( 65 * 1024 )

// buffer queue max timeout
#define NAVILITE_QUEUE_BUFFER_TIMEOUT 900

// buffer size for unit test which contains image data (at max 35K payload data)
#define NAVILITE_PROTOCOL_BUFFER_SIZE_FOR_UNIT_TEST 1024

#endif /*NAVILITE_CONFIG_H */
