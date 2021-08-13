/*********************************************************************
* @file  cm_tsk.c
* @brief Connection Manager Main Task interface definition.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <FreeRTOS.h>
#include <queue.h>
#include <semphr.h>
#include <task.h>
#include <string.h>

#include "GRM_pub_prj.h"

#include "cm_types.h"
#include "cm_tsk.h"
#include "cm_prv.h"
#include "cm_log.h"
#include "cm_auto_connect.h"

/*--------------------------------------------------------------------
                        Definitions
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define CM_TSK_NAME       ( "cm_task" )
#define CM_TSK_PRIORITY   ( TASK_PRIO_CM_MNGR )
#define CM_TSK_STACK_SIZE ( configMINIMAL_STACK_SIZE * 5 )

#define REQUEST_QUEUE_MAX_ITEMS    ( 10 )
#define SYNC_EVENT_QUEUE_MAX_ITEMS ( 1 )

/*--------------------------------------------------------------------
                        TYPES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        VARIABLES
--------------------------------------------------------------------*/
static QueueHandle_t s_request_queue = NULL;

/*--------------------------------------------------------------------
                        PROTOTYPES
--------------------------------------------------------------------*/
static void CM_tsk_main
    (
    void* data
    );

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
/*================================================================================================
@brief   Clear all the requests of Connection Manager Main task
@details Clear all the requests of Connection Manager Main task
@return  None
@retval  None
================================================================================================*/
void CM_tsk_clear_requests( void )
{
xQueueReset( s_request_queue );
}

/*================================================================================================
@brief   Connection Manager Main task initialization
@details Connection Manager Main task initialization
@return  None
@retval  None
================================================================================================*/
void CM_tsk_init( void )
{
// Init Main task
s_request_queue = xQueueCreate( REQUEST_QUEUE_MAX_ITEMS, sizeof( CM_task_request_t ) );
configASSERT( NULL != s_request_queue );

BaseType_t ret = xTaskCreate( CM_tsk_main, CM_TSK_NAME, CM_TSK_STACK_SIZE, NULL, CM_TSK_PRIORITY, NULL );
configASSERT( pdPASS == ret );
}

/*================================================================================================
@brief   Connection Manager Main task execution loop
@details Connection Manager Main task will wait on the request queue and be waked up to handle the
         received request.
@return  None
@retval  None
================================================================================================*/
static void CM_tsk_main
    (
    void* data
    )
{
CM_task_request_t task_request;

CMA_init();

while( 1 )
    {
    if( pdTRUE == xQueueReceive( s_request_queue, &task_request, portMAX_DELAY ) )
        {
        CM_LOG_VERBOSE( "Request received: %d\r\n", task_request.CM_REQUEST_type );
        switch( task_request.CM_REQUEST_type )
            {
            case CM_REQUEST_SPP_CONNECT:
                {
                CM_core_spp_connect( task_request.CM_spp_connect_request.bd_addr );
                } break;

            case CM_REQUEST_SPP_DISCONNECT:
                {
                CM_core_spp_disconnect( task_request.CM_spp_disconnect_request.bd_addr );
                } break;

            case CM_REQUEST_PAIRING_RESULT:
                {
                CM_core_handle_btmgr_pairing_result( &(task_request.CM_btmgr_pairing_result) );
                } break;

            case CM_REQUEST_CONNECTION_STATUS_CHANGE:
                {
                CM_core_handle_btmgr_spp_connection_status_changed( &(task_request.CM_connection_status_change) );
                } break;

            case CM_REQUEST_AUTHENTICATION_RESULT:
                {
                CM_core_handle_app_auth_result( &(task_request.CM_auth_result) );
                } break;

            case CM_REQUEST_ACL_DISCONNECT:
                {
                CM_core_handle_btmgr_acl_link_disconnected( &(task_request.CM_acl_disconnected) );
                } break;

            case CM_REQUEST_SET_AUTOCONNECT_STATE:
                {
                CM_core_set_auto_connect_state( &(task_request.CM_set_auto_connect_state) );
                } break;

            case CM_REQUEST_SET_ENABLE_STATE:
                {
                CM_core_handle_btmgr_enable_state_changed( task_request.CM_set_bt_enable_state.bt_enable_state );
                } break;

            case CM_REQUEST_STORE_CCUID:
                {
                CM_core_handle_hmi_ccuid_ready( task_request.CM_store_ccuid.ccuid );
                } break;


            default:
                {
                CM_LOG_DEBUG( "Invalid request type: %d\r\n", task_request );
                } break;
            }
        }
    }
}

/*================================================================================================
@brief   Send the request to Connection Manager Main task
@details Send the request to Connection Manager Main task
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
bool CM_tsk_send_request
    (
    const CM_task_request_t *request
    )
{
if( pdTRUE != xQueueSend( s_request_queue, request, 0 ) )
    {
    CM_LOG_DEBUG( "Request sent failed due to Queue Full: %d\r\n", request->CM_REQUEST_type );
    return false;
    }

CM_LOG_VERBOSE( "Request sent: %d\r\n", request->CM_REQUEST_type );
return true;
}

#ifdef __cplusplus
}
#endif
