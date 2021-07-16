#ifndef _CLIENT_DCM_APPL_H_
#define _CLIENT_DCM_APPL_H_


#include "client_dcm_type.h"
#include "client_dcm_cfg.h"
#include "fsl_debug_console.h"/*foE_SUCCESSr debug*/
#include "BleServiceStructure.pb.h"
#include "pb_decode.h"
#include "pb_encode.h"

#define PB_ENCODE_DEBUG                                                             ( 1 )
#define PB_MESSAGE_WHEN_SUCCESS                                                     ( 0 )
#define MAX_MMCSERVERLISTRESPONSE_LIST_COUNT                                        ( 25 )
#define MAX_MCMALFUNCTIONRESPONSE_LIST_COUNT                                        ( 25 )
#define MAX_MCLOCALRECORDVEHICLEINFORMATIONSUPPORTIDLISTRESPONSE_ID_LIST_COUNT      ( 25 )
#define MAX_MCFFDRESPONSE_DATA_LIST_BYTES_NUMBER                                    ( 100 )
#define MAX_MCFFDRESPONSE_DATA_LIST_COUNT                                           ( 50 )
#define MAX_IDDATA_BYTES_NUMBER                                                     ( 100 )
#define MAX_IDDATA_COUNT                                                            ( 150 )
#define MAX_ID_LIST_NUM                                                             ( 50 )


typedef void (*appl_period_func_ptr)(void);
typedef void (*appl_postive_response_dispatch_ptr)(uint8 * resp_data,uint16 resp_lenth,uint8 channel_id);
typedef void (*appl_negative_response_dispatch_ptr)(uint8 service_id,uint8 nrc, uint8 channel_id);
typedef void (*apppl_response_timeout_notify_ptr)(void);
typedef void (*appl_RCPP_notify_ptr)(void);




typedef struct
{
    int32_t id_list[MAX_MCLOCALRECORDVEHICLEINFORMATIONSUPPORTIDLISTRESPONSE_ID_LIST_COUNT];
    int32_t count;
}McLocalRecordVehicleInformationSupportIdListResponse_id_list_t;

typedef struct
{
    int32_t server_list[MAX_MMCSERVERLISTRESPONSE_LIST_COUNT];
    int32_t count;
}McServerListResponse_server_list_t;


typedef struct
{
    McMalfunctionResponse_ServerCodeStatus ServerCodeStatus_list[MAX_MCMALFUNCTIONRESPONSE_LIST_COUNT];
    int32_t count;
}McMalfunctionResponse_list_t;


typedef struct
{
    uint8_t data[MAX_MCFFDRESPONSE_DATA_LIST_BYTES_NUMBER];
    int32_t len;
}McFfdResponse_data_list_item_t;

typedef struct
{
    McFfdResponse_data_list_item_t data_list_array[MAX_MCFFDRESPONSE_DATA_LIST_COUNT];
    int32_t count;
}McFfdResponse_data_list_t;


typedef struct
{
    int32_t id;
    uint8_t data[MAX_IDDATA_BYTES_NUMBER];
    int32_t len;
}IdData;

typedef struct
{
    IdData IdData_array[MAX_IDDATA_COUNT];
    int32_t count;
    const pb_msgdesc_t *fields;
} IdDataList;


typedef struct
{
uint32 id_list_array[MAX_ID_LIST_NUM];
uint32 id_list_num;
}id_list_type;


typedef enum
{
E_PARSE_FAILED = 0,
E_SUCCESS,
E_PARAMETER_ERROR
}E_reuset_type;

typedef enum
{
SERVER_INIT_STATE = 0,
SERVER_UN_CONNECT,
SERVER_CONNECT,
SERVER_CONNECT_STATE_MAX
}client_appl_server_connect_type;


typedef enum
{
CMD_RSP_IDLE = 0,
CMD_RSP_PROCESSING,
CMD_RSP_TIMEOUT,
CMD_RSP_DONE,
CMD_RSP_MAX
}client_appl_cmd_rsp_state_type;

typedef enum
{
SERVER_DETECT_INIT = 0,
SERVER_DETECT_REQ,
SERVER_DETECT_WAIT,
SERVER_DETECT_DEFAULT_DONE,
SERVER_DETECT_EXTEND_DONE,
SERVER_DETECT_DEFAULT_TX,
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
process_flow_result_type process_result;
}client_appl_detect_connected_server_infos_type;

typedef struct
{
uint8 connected_server_id;
uint8 current_STADTC;
client_appl_request_frame_type curr_dtc_status_frame;
client_appl_request_frame_type next_req_dtc_status_frame;
uint8 resend_timer;
uint8 receive_SNS_timer;
process_flow_result_type process_result;
boolean is_cycle_transmission;
uint32 cycle_tarns_interval_time;
boolean is_storge_init_dtc;/*This parameter shall be puted in the last*/
}client_appl_read_dtc_infos_type;
/*Note: if you want to modify the struct of  client_appl_read_dtc_infos_type
you have to modify (void)memset( &read_dtc_infos, 0x00, sizeof( read_dtc_infos ) - 4 );*/



typedef struct
{
uint32 ble_server_code;
uint8 channel;
}client_appl_ble_server_code_mapping_type;

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
process_flow_result_type process_result;
}client_appl_read_data_by_comon_id_type;

typedef struct
{
boolean is_request_support_list_flow;
uint8 connected_server_id;
uint8* local_id_list;
boolean* support_id_received_flag_array;
uint8 amount_local_data;
uint8 current_local_data_index;
client_appl_request_frame_type curr_req_frame;
client_appl_request_frame_type next_req_frame;
uint8 resend_timer;
uint8 receive_SNS_timer;
process_flow_result_type process_result;
boolean is_cycle_transmission;
uint32 cycle_tarns_interval_time;
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
process_flow_result_type process_result;
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
    uint8 nrc,
    uint8 channel_id
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
    void
    );

extern boolean client_appl_get_ydt_connect_state
    (
    void
    );

extern void client_appl_set_ble_connected_state
    (
    boolean next_state
    );

extern void client_appl_operation_mode_switch
    (
    void
    );

extern boolean client_appl_get_storage_init_dtc_state
    (
    void
    );

extern uint8 client_appl_get_current_connected_server_id
    (
    void
    );

extern void client_appl_ble_req_command_dispatch
    (
    uint16 req_command,
    uint32 data_size,
    uint8* data
    );

extern void client_appl_cmd_rsp_result_notify
    (
    uint8 vlaue
    );

extern void client_appl_response_can_related_data
   (
   const uint16 command,
   const uint32_t                  size,
   const uint8_t*                  data,
   void ( *result_callback )( const uint8 )
   );

extern size_t Gen_McCanResponse
    (
    IdDataList* pList,
    uint8_t* out_buf,
    size_t out_buf_size
    );

#endif



