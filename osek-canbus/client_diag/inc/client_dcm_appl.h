#ifndef _CLIENT_DCM_APPL_H_
#define _CLIENT_DCM_APPL_H_


#include "client_dcm_type.h"
#include "client_dcm_cfg.h"
#include "fsl_debug_console.h"/*for debug*/


typedef void (*appl_period_func_ptr)(void);
typedef void (*appl_postive_response_dispatch_ptr)(uint8 * resp_data,uint16 resp_lenth,uint8 channel_id);
typedef void (*appl_negative_response_dispatch_ptr)(uint8 service_id,uint8 nrc);
typedef void (*apppl_response_timeout_notify_ptr)(void);
typedef void (*appl_RCPP_notify_ptr)(void);



typedef enum
{
SERVER_INIT_STATE = 0,
SERVER_UN_CONNECT,
SERVER_CONNECT,
SERVER_CONNECT_STATE_MAX
}client_appl_server_connect_type;

typedef enum
{
SERVER_DETECT_INIT = 0,
SERVER_DETECT_REQ,
SERVER_DETECT_WAIT,
SERVER_DETECT_DEFAULT_DONE,
SERVER_DETECT_EXTEND_DONE,
SERVER_DETECT_MAX
}client_appl_server_detect_step_type;

typedef struct
{
uint8 server_id;
uint16 ecu_identifier;
client_appl_server_connect_type server_connect_status_default;
client_appl_server_connect_type server_connect_status_extend;
}client_appl_server_list_detect_type;

typedef enum
{
REQ_NO_FRAME = 0,
REQ_ORIGINAL_FRAME,
REQ_DEFAULT_SESSION_FRAME,
REQ_EXTEND_SESSION_FRAME,
REQ_RESEND_FRAME,
REQ_FFD_FRAME,
REQ_NRC_RSEND_FRAME,
REQ_FRAME_MAX
}client_appl_request_frame_type;

typedef enum
{
PROCESS_RESULT_INIT = 0,
PROCESS_RESULT_SUCCESS,
PROCESS_RESULT_TIMEOUT,
RROCESS_RESULE_RESEND_OVERFLOW,
PROCESS_RESULT_NRC_SNS,
PROCESS_RESULT_NRC_GR,
PROCESS_RESULT_INVALID_DATA,
PROCESS_RESULT_END,
PROCESS_RESULT_MAX
}process_flow_result_type;

typedef enum
{
PROCESS_FLOW_DETECT_SERVER = 0,
PROCESS_FLOW_EXTEND_SERVER,
PROCESS_FLOW_INIT_RDTCBS,
PROCESS_FLOW_RDBCID,
PROCESS_FLOW_MARKET,
PROCESS_FLOW_MONITOR,
PROCESS_FLOW_RFFD,
PROCESS_FLOW_IDLE,
PROCESS_FLOW_MAX
}client_process_flow_type;

typedef struct
{
uint8 connected_server_id;
client_appl_request_frame_type curr_dtc_status_frame;
client_appl_request_frame_type next_req_dtc_status_frame;
uint8 nrc_resend_timer;
uint8 timeout_resend_timer;
process_flow_result_type peocess_result;
}client_appl_detect_connected_server_infos_type;

typedef struct
{
uint8 connected_server_id;
uint8 current_STADTC;
client_appl_request_frame_type curr_dtc_status_frame;
client_appl_request_frame_type next_req_dtc_status_frame;
uint8 resend_timer;
uint8 receive_SNS_timer;
process_flow_result_type peocess_result;
boolean is_cycle_transmission;
uint16 cycle_tarns_interval_time;
boolean is_storge_init_dtc;/*This parameter shall be puted in the last*/
}client_appl_read_dtc_infos_type;


typedef struct
{
uint8 connected_server_id;
uint16* common_id_list;
uint8 common_data_amount;
uint8 current_common_data_index;
client_appl_request_frame_type curr_req_frame;
client_appl_request_frame_type next_req_frame;
uint8 resend_timer;
uint8 receive_SNS_timer;
process_flow_result_type peocess_result;
}client_appl_read_data_by_comon_id_type;

typedef struct
{
uint8 connected_server_id;
uint8* local_id_list;
uint8 amount_local_data;
uint8 current_local_data_index;
client_appl_request_frame_type curr_req_frame;
client_appl_request_frame_type next_req_frame;
uint8 resend_timer;
uint8 receive_SNS_timer;
process_flow_result_type peocess_result;
}client_appl_read_data_by_local_id_type;


typedef struct
{
uint8 connected_server_id;
uint8 current_freeze_frame_number;
uint8* request_id_list;
uint8 requset_id_list_amount;
uint8 current_request_id;
client_appl_request_frame_type prev_request_frame;
client_appl_request_frame_type curr_request_frame;
client_appl_request_frame_type next_request_frame;
uint8 resend_timer;
uint8 receive_SNS_timer;
process_flow_result_type peocess_result;
}client_appl_read_freeze_frame_data_type;





typedef struct
{
client_process_flow_type prosess_flow;
appl_period_func_ptr appl_period_func;
appl_postive_response_dispatch_ptr postive_response_dispatch;
appl_negative_response_dispatch_ptr negative_response_dispatch;
apppl_response_timeout_notify_ptr   response_timeout_notify;
}client_process_flow_handler_type;


extern client_ReturnType
client_appl_init

    (
    void
    );

extern void
client_appl_main_5ms_handler

    (
    void
    );

extern void
client_appl_negative_response_dispatch
    (
    uint8 service_id,
    uint8 nrc
    );

extern void
client_appl_positive_response_dispatch
     (
     uint8 * resp_data,
     uint16 resp_lenth,
     uint8 channel_id
     );

extern void client_appl_response_timeout_notify
    (
    void
    );

extern client_process_flow_type
client_get_current_process_flow
    (
    void
    );

extern void client_appl_set_ydt_connect_state
    (
    boolean connect_state
    );

extern boolean client_appl_get_storage_init_dtc_state
    (
    void
    );

extern uint8 client_appl_get_current_connected_server_id
    (
    void
    );
#endif



