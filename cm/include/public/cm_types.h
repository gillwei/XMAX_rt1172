/*********************************************************************
* @file  cm_types.h
* @brief Defines the Connection Manager specific types used for public
*        interface.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifndef _CM_TYPES_H_
#define _CM_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "bt_types.h"

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/


/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/
typedef enum CM_status
    {
    CM_STATUS_OK = 0,
    CM_STATUS_BUSY,              // The same request is still under processing
    CM_STATUS_INVALID_PARAMETER, // Invalid parameter input
    CM_STATUS_NO_CONNECTION,     // No device is connected yet
    CM_STATUS_NOT_READY,         // Connection Manager is not initialized yet
    CM_STATUS_NOT_ALLOWED,       // Operation is not allowed
    CM_STATUS_QUEUE_FULL,        // Connection Manager's request queue is full

    CM_STATUS_CNT,
    CM_STATUS_INVALID = CM_STATUS_CNT
    } CM_status_e;

typedef enum CM_REQUEST_type
    {
    // SPP
    CM_REQUEST_SPP_CONNECT,
    CM_REQUEST_SPP_DISCONNECT,

    CM_REQUEST_TYPE_CNT,
    CM_REQUEST_TYPE_INVALID = CM_REQUEST_TYPE_CNT
    } CM_REQUEST_type_e;

typedef enum CM_spp_app_type
    {
    CM_SPP_APP_NAVILITE = 0,
    CM_SPP_APP_YCONNECT,

    CM_SPP_APP_TYPE_CNT,
    CM_SPP_APP_TYPE_INVALID = CM_SPP_APP_TYPE_CNT
    } CM_spp_app_type_e;

typedef enum CM_app_type
    {
    CM_APP_NAVILITE = 0,
    CM_APP_YCONNECT,

    CM_APP_TYPE_CNT,
    CM_APP_TYPE_INVALID = CM_APP_TYPE_CNT
    } CM_app_type_e;

// SPP
typedef struct CM_spp_connect_request
    {
    uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN];
    CM_spp_app_type_e app_type;
    } CM_spp_connect_request_t;

typedef struct CM_spp_disconnect_request
    {
    uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN];
    CM_spp_app_type_e app_type;
    } CM_spp_disconnect_request_t;

typedef struct CM_spp_send_data_request
    {
    uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN];
    CM_spp_app_type_e app_type;
    uint8_t data[SPP_DATA_MAX_SIZE];
    uint8_t data_len;
    } CM_spp_send_data_request_t;

/*--------------------------------------------------------------------
                        PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        VARIABLES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif // _CM_TYPES_H_
