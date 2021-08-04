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
typedef enum CM_log_severity
    {
    CM_LOG_FATAL = 0,
    CM_LOG_ERROR,
    CM_LOG_WARNING,
    CM_LOG_INFO,
    CM_LOG_DEBUG,
    CM_LOG_VERBOSE,

    CM_LOG_SEVERITY_CNT,
    CM_LOG_SEVERITY_INVALID = CM_LOG_SEVERITY_CNT
    } CM_log_severity_e;

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

// For CM to manage the navi spp connection status on core function
typedef enum CM_navi_app_connection_status
    {
    CM_NAVI_APP_CONNECTION_DISCONNECTED = 0,
    CM_NAVI_APP_CONNECTION_CONNECTING,
    CM_NAVI_APP_CONNECTION_CONNECTED,
    CM_NAVI_APP_CONNECTION_DISCONNECTING,
    CM_NAVI_APP_CONNECTION_AUTHENTICATED,

    CM_NAVI_APP_CONNECTION_STATUS_CNT,
    CM_NAVI_APP_CONNECTION_STATUS_INVALID = CM_NAVI_APP_CONNECTION_STATUS_CNT
    } CM_navi_app_connection_status_e;

// For CM to manage the Y-connect spp connection status on core function
typedef enum CM_yconnect_app_connection_status
    {
    CM_YCONNECT_APP_CONNECTION_DISCONNECTED = 0,
    CM_YCONNECT_APP_CONNECTION_CONNECTING,
    CM_YCONNECT_APP_CONNECTION_CONNECTED,
    CM_YCONNECT_APP_CONNECTION_DISCONNECTING,
    CM_YCONNECT_APP_CONNECTION_AUTHENTICATED,

    CM_YCONNECT_APP_CONNECTION_STATUS_CNT,
    CM_YCONNECT_APP_CONNECTION_STATUS_INVALID = CM_YCONNECT_APP_CONNECTION_STATUS_CNT
    } CM_yconnect_app_connection_status_e;

typedef enum CM_REQUEST_type
    {
    // SPP
    CM_REQUEST_SPP_CONNECT,
    CM_REQUEST_SPP_DISCONNECT,
    CM_REQUEST_PAIRING_RESULT,
    CM_REQUEST_CONNECTION_STATUS_CHANGE,
    CM_REQUEST_AUTHENTICATION_RESULT,

    CM_REQUEST_TYPE_CNT,
    CM_REQUEST_TYPE_INVALID = CM_REQUEST_TYPE_CNT
    } CM_REQUEST_type_e;

typedef enum CM_app_type
    {
    CM_APP_NAVILITE = 0,
    CM_APP_YCONNECT,

    CM_APP_TYPE_CNT,
    CM_APP_TYPE_INVALID = CM_APP_TYPE_CNT
    } CM_app_type_e;

typedef struct CM_connect_device_status
    {
    uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN];
    CM_navi_app_connection_status_e navi_app_connection_status;
    CM_yconnect_app_connection_status_e yconnect_app_connection_status;
    } CM_connect_device_status_t;

// SPP
typedef struct CM_spp_connect_request
    {
    uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN];
    } CM_spp_connect_request_t;

typedef struct CM_spp_disconnect_request
    {
    uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN];
    } CM_spp_disconnect_request_t;

typedef struct CM_btmgr_pairing_result
    {
    bool    pairing_result;
    uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN];
    } CM_btmgr_pairing_result_t;

typedef struct CM_connection_status_change
    {
    bool          connected;
    CM_app_type_e app_type;
    uint8_t       bd_addr[BT_DEVICE_ADDRESS_LEN];
    } CM_connection_status_change_t;

typedef struct CM_auth_result
    {
    CM_app_type_e app_type;
    bool          result;
    } CM_auth_result_t;

typedef struct CM_task_request
    {
    CM_REQUEST_type_e                CM_REQUEST_type;
    CM_spp_connect_request_t         CM_spp_connect_request;
    CM_spp_disconnect_request_t      CM_spp_disconnect_request;
    CM_btmgr_pairing_result_t        CM_btmgr_pairing_result;
    CM_connection_status_change_t    CM_connection_status_change;
    CM_auth_result_t                 CM_auth_result;
    } CM_task_request_t;

// Since HMI need to show both of Navi and Yconnect Connection result
// CM collect results and feedback to HMI
typedef struct CM_connect_result
    {
    bool  can_notify_UI;
    bool  navi_connect_result;
    bool  yconnect_connect_result;
    } CM_connect_result_t;

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
