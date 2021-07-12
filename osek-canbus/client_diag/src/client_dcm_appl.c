/*--------------------------------------------------------------------
* @file client_dcm_appl.c
* @brief client diagnostic application management
*
* This file shall handle the service com_sequence flow, store and transmit
* data to upper layer.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
---------------------------------------------------------------------*/


/*--------------------------------------------------------------------
                            GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "client_dcm_appl.h"
#include "client_dcm_cfg.h"
#include "client_dcm.h"
#include "client_mem.h"
#include <string.h>
#include "BC_motocon_pub.h"
#include "EW_pub.h"
#include "client_ble_cmd.h"



/*Micro switch for DEBUG*/
#define APPL_DEBUG                                   (TRUE)
#define SIMULATE_INPUT_DEBUG                         (FALSE)

#ifdef APPL_DEBUG
#define CONSOLE_PRINT                                 (TRUE)
#define CLIENT_DEBUG(x)                              PRINTF("[%s-%s-%s]:%s\r\n",__FILE__,__TIME__,__func__, x)

#else
#define CONSOLE_PRINT                                 (FALSE)
#define CLIENT_DEBUG(x)
#endif



#define APPL_PENDING                                 (TRUE )


/*--------------------------------------------------------------------
                            VARIABLES
--------------------------------------------------------------------*/
/*define yamaha diagnostic tools connected state*/
/*define BLE connected state*/
static boolean ydt_timer_flag = FALSE;
static uint16 ydt_timer_count = 0x0000;
static boolean ydt_connected_state = FALSE;
static boolean ble_connected_state = FALSE;
static EnumOperationMode sys_operation_mode = EnumOperationModeTOTAL;
static boolean operation_mode_switch_flag = FALSE;
static uint32 delay_timer_count   =  0;
static client_process_flow_type client_process_flow_state = PROCESS_FLOW_IDLE;
static client_appl_cmd_rsp_state_type client_app_cmd_rsp_state = CMD_RSP_IDLE;

/*for server list detect*/
static uint8 current_connect_server_id   = 0xFF;
static uint8 default_server_list_detect_amount = 0x00;
static uint8 extend_server_list_detect_amount = 0x00;
static uint32 connected_server_list[SUPPORT_SERVER_NUM] = {0};
static const uint16 server_ecu_identifier[SUPPORT_SERVER_NUM] = SERVER_ECU_LIST;
static client_appl_server_detect_step_type server_detect_step = SERVER_DETECT_INIT;
static client_appl_server_list_detect_type server_list_detect_infos[SUPPORT_SERVER_NUM] = {0};
static client_appl_detect_connected_server_infos_type detect_connected_server_infos ={0};

/*for read DTC*/
static client_appl_read_dtc_infos_type read_dtc_infos = { 0 };

/*for common identifier data*/
static uint16 rx_comman_data_id_list[SUPPORT_COMMON_COUNT] = { 0 };
static client_appl_read_data_by_comon_id_type read_common_identifier_infos = {0};
static const uint16 support_common_data_id_list[SUPPORT_COMMON_COUNT] = SUPPORT_COMMON_IDS_LIST;

/*for local data*/
static uint8 rx_market_data_id_list[SUPPORT_MARKET_COUNT] = { 0 };
static const uint8 support_market_data_id_list[SUPPORT_MARKET_COUNT]= SUPPORT_MARKET_IDS_LIST;
static uint8 rx_monitor_data_id_list[SUPPORT_MONITOR_COUNT] = { 0 };
static boolean support_id_received_flag[SUPPORT_MONITOR_COUNT] = { FALSE };
/* SUPPORT_MONITOR_COUNT suuport id + 1 server code */
static uint8 response_support_monitor_data_id_list[SUPPORT_MONITOR_COUNT] = { 0 };
static const uint8 support_monitor_data_id_list[SUPPORT_MONITOR_COUNT] = SUPPORT_MONITOR_IDS_LIST;
static client_appl_read_data_by_local_id_type read_loacl_market_infos = {0};
static client_appl_read_data_by_local_id_type read_local_monitor_infos = {0};

/*for freeze frame data*/
static client_appl_read_freeze_frame_data_type read_freeze_frame_data_infos = {0};
static uint8 current_request_freeze_frame_id_list[20] = {0};

/*For protobuf repeated data*/
id_list_type vehicle_iden_list = {0};/*common data*/
id_list_type market_data_list = {0};/*market data*/
id_list_type vhicle_information_list = {0};/*monitor data*/
id_list_type* curr_id_list_ptr = NULL;


uint8 McServerListResponse_protobuf[3000];
uint8 McMalfunctionResponse_protobuf[3000];
uint8 McLocalRecordVehicleInformationSupportIdListResponse_protobuf[3000];
uint8 McVehicleIdentificationResponse_protobuf[3000];
uint8 McFfdResponse_protobuf[5000];
uint8 McCanResponse_protobuf[100];

IdDataList g_IdDataList;
IdDataList g_McCanResponse_dataList;
McFfdResponse_data_list_t g_McFfdResponse_data_list;
McServerListResponse_server_list_t g_McServerListResponse_server_list;
McMalfunctionResponse_list_t g_McMalfunctionResponse_list;
McLocalRecordVehicleInformationSupportIdListResponse_id_list_t g_McLocalRecordVehicleInformationSupportIdListResponse_id_list;

#if( APPL_DEBUG )
const char* print_header_0 = "Server connect detect flow(default session)";
const char* print_header_1 = "Server connected detect flow(extend session)";
const char* print_header_2 = "Read DTC status data flow";
const char* print_header_3 = "Read Common Identifier data flow";
const char* print_header_4 = "Read Local Market data flow";
const char* print_header_5 = "Read Local Monitor data flow";
const char* print_header_6 = "Read Freeze Frame data flow";
const char* print_header_7 = "IDLE flow";


const char* print_end_0 = " NO RESULT";
const char* print_end_1 = " process SUCCESS";
const char* print_end_2 = " process fail : TIMEOUT";
const char* print_end_3 = " process fail : RSEND OVER 3 TIMES";
const char* print_end_4 = " process fail : SERVICE NOT SUPPORT";
const char* print_end_5 = " Process fail : GENERAL REJECT";
const char* print_end_6 = " Process fail : INVALID DATA";
const char* print_end_7 = " Process END";

char* print_header[SUPPORT_FUCNTION_NUMS] = {0};
char* print_end[PROCESS_RESULT_MAX] = {0};
#endif

const client_appl_ble_server_code_mapping_type client_appl_ble_server_code_mapping[SUPPORT_SERVER_NUM] = BLE_SERVER_CODE_MAPPING;

/*------------------------------------------------------------------
*                          MACROS
-------------------------------------------------------------------*/
#define set_current_conncet_server_id( value )       ( current_connect_server_id = value )
#define get_current_connect_server_id()              ( current_connect_server_id )
#define decrease_delay_timer()                       ( delay_timer_count -- )
#define set_client_app_cmd_rsp_state( state )        client_app_cmd_rsp_state = state; PRINTF(" Current send state:%d\r\n",client_app_cmd_rsp_state)
#define get_client_app_cmd_rsp_state()               ( client_app_cmd_rsp_state )
#define is_client_app_cmd_rsp_state(state)           ( client_app_cmd_rsp_state == state? TRUE: FALSE )

/*-------------------------------------------------------------------
*                    function declaration
---------------------------------------------------------------------*/
/*for server list detect - request default session*/
static void  client_appl_detect_connected_server_handler_5ms
    (
    void
    );

static void client_appl_detect_connected_server_negative_response_handler
    (
    uint8 service_id,
    uint8 nrc,
    uint8 channel_id
    );

static void client_appl_detect_connected_server_positive_response_handler
    (
     uint8 * resp_data,
     uint16 resp_lenth,
     uint8 channel_id
    );

static void client_appl_detect_connected_server_response_timeout_notify
    (
    void
    );

/*for server list detect - request extend session*/
static void client_appl_server_detect_req_extend_session_5ms
    (
    void
    );

static void client_appl_server_detect_req_extend_session_positive_response_handler
    (
    uint8 * resp_data,
    uint16 resp_lenth,
    uint8 channel_id
    );

static void client_appl_server_detect_req_extend_session_negative_response_handler
    (
    uint8 service_id,
    uint8 nrc,
    uint8 channel_id
    );

static void client_appl_server_detect_req_extend_session_timeout_notify
    (
    void
    );


/*for Read DTC status info*/
static void client_appl_req_initial_dtc_status_handler_5ms
    (
    void
    );

static void client_appl_read_initial_dtc_status_positive_response_handler
    (
     uint8 * resp_data,
     uint16 resp_lenth,
     uint8 channel_id
    );

static void client_appl_read_initial_dtc_status_negative_response_handler
    (
    uint8 service_id,
    uint8 nrc,
    uint8 channel_id
    );

static void client_appl_read_initial_dtc_status_timeout_notify
    (
    void
    );



/*for common identifier data*/
static void client_appl_read_data_by_common_identifier_handler_5ms
    (
    void
    );

static void client_appl_read_data_by_common_identifier_positive_response_handler
    (
     uint8 * resp_data,
     uint16 resp_lenth,
     uint8 channel_id
    );

static void client_appl_read_data_by_common_identifier_negative_response_handler
    (
    uint8 service_id,
    uint8 nrc,
    uint8 channel_id
    );

static void client_appl_read_data_by_common_identifier_timeout_notify
    (
    void
    );



/*for local identifier data-market*/
static void client_appl_read_data_by_local_identifier_market_handler_5ms
    (
    void
    );

static void client_appl_read_data_by_local_identifier_market_positive_response_handler
    (
     uint8 * resp_data,
     uint16 resp_lenth,
     uint8 channel_id
    );

static void client_appl_read_data_by_local_identifier_market_negative_response_handler
    (
    uint8 service_id,
    uint8 nrc,
    uint8 channel_id
    );

static void client_appl_read_data_by_local_identifier_market_timeout_notify
    (
    void
    );


/*for local identifier data - monitor*/
static void client_appl_read_data_by_local_identifier_monitor_handler_5ms
    (
    void
    );

static void client_appl_read_data_by_local_identifier_monitor_positive_response_handler
    (
     uint8 * resp_data,
     uint16 resp_lenth,
     uint8 channel_id
    );

static void client_appl_read_data_by_local_identifier_monitor_negative_response_handler
    (
    uint8 service_id,
    uint8 nrc,
    uint8 channel_id
    );

static void client_appl_read_data_by_local_identifier_monitor_timeout_notify
    (
    void
    );

/*for read freeze frame data */
static void client_appl_read_freeze_frame_data_handler_5ms
    (
    void
    );

static void client_appl_read_freeze_frame_data_positive_response_handler
    (
     uint8 * resp_data,
     uint16 resp_lenth,
     uint8 channel_id
    );

static void client_appl_read_freeze_frame_data_negative_response_handler
    (
    uint8 service_id,
    uint8 nrc,
    uint8 channel_id
    );

static void client_appl_read_freeze_frame_data_timeout_notify
    (
    void
    );

static boolean client_appl_set_current_process_flow_step
    (
    client_process_flow_type next_process_flow
    );

void client_appl_cmd_rsp_result_notify
    (
    const uint8 vlaue
    );

boolean client_appl_get_storage_init_dtc_state
    (
    void
    );

void client_appl_check_ble_command
    (
    boolean diagnstic_is_enbale
    );

void client_appl_rsp_server_list_after_ble_connect
    (
    void
    );


static void client_appl_send_protobuf_data_success
    (
    void
    );



static client_process_flow_handler_type client_process_flow_handler[SUPPORT_FUCNTION_NUMS - 1] =
{
    { PROCESS_FLOW_DETECT_SERVER, &client_appl_detect_connected_server_handler_5ms, &client_appl_detect_connected_server_positive_response_handler, &client_appl_detect_connected_server_negative_response_handler, &client_appl_detect_connected_server_response_timeout_notify },
    { PROCESS_FLOW_EXTEND_SERVER, &client_appl_server_detect_req_extend_session_5ms, &client_appl_server_detect_req_extend_session_positive_response_handler, &client_appl_server_detect_req_extend_session_negative_response_handler, &client_appl_server_detect_req_extend_session_timeout_notify },
    { PROCESS_FLOW_INIT_RDTCBS, &client_appl_req_initial_dtc_status_handler_5ms, &client_appl_read_initial_dtc_status_positive_response_handler, &client_appl_read_initial_dtc_status_negative_response_handler, &client_appl_read_initial_dtc_status_timeout_notify },
    { PROCESS_FLOW_RDBCID, &client_appl_read_data_by_common_identifier_handler_5ms, &client_appl_read_data_by_common_identifier_positive_response_handler, &client_appl_read_data_by_common_identifier_negative_response_handler, &client_appl_read_data_by_common_identifier_timeout_notify },
    { PROCESS_FLOW_MARKET, &client_appl_read_data_by_local_identifier_market_handler_5ms, &client_appl_read_data_by_local_identifier_market_positive_response_handler, &client_appl_read_data_by_local_identifier_market_negative_response_handler, &client_appl_read_data_by_local_identifier_market_timeout_notify },
    { PROCESS_FLOW_MONITOR, &client_appl_read_data_by_local_identifier_monitor_handler_5ms, &client_appl_read_data_by_local_identifier_monitor_positive_response_handler, &client_appl_read_data_by_local_identifier_monitor_negative_response_handler, &client_appl_read_data_by_local_identifier_monitor_timeout_notify},
    { PROCESS_FLOW_RFFD, &client_appl_read_freeze_frame_data_handler_5ms, &client_appl_read_freeze_frame_data_positive_response_handler,&client_appl_read_freeze_frame_data_negative_response_handler, &client_appl_read_freeze_frame_data_timeout_notify}
};


/*!*******************************************************************
* @public
* Function name: client_appl_enter_ydt_handler
* Description:   this function will disconnect the diagnostic server
with all servers
*********************************************************************/
static void client_appl_enter_ydt_handler
    (
    void
    )
{
CLIENT_DEBUG("Detect Yamaha Detect tools online");
client_appl_set_current_process_flow_step( PROCESS_FLOW_IDLE );
client_mem_reset_data();
}

/*!*******************************************************************
* @public
* Function name: client_appl_set_ydt_connect_state
* Description:  Set current YAMAHA diagnostic tools connect state
* Usage:   Called by can driver
*********************************************************************/
void client_appl_set_ydt_connect_state
    (
    void
    )
{
if( FALSE == ydt_connected_state )
    {
    ydt_connected_state = TRUE;
    client_appl_enter_ydt_handler();
    }
ydt_timer_flag = TRUE;
ydt_timer_count = 1000;/*5s*/
}

/*!*******************************************************************
* @public
* Function name: client_appl_get_ydt_connect_state
* Description:  Get current YAMAH diagnostic tools connect state
* Usage: Called by client_appl_main_5ms_handler
*********************************************************************/
 boolean client_appl_get_ydt_connect_state
    (
    void
    )
{
return ydt_connected_state;
}

/*!*******************************************************************
* @public
* Function name: client_appl_set_ble_connected_state
* Description:  Set current BLE connect state
*********************************************************************/
void client_appl_set_ble_connected_state
    (
    boolean next_state
    )
{
if( next_state )
    {
    CLIENT_DEBUG("Authentication SUCCESS\r\n");
    client_appl_rsp_server_list_after_ble_connect();
    }
else
    {
    CLIENT_DEBUG("Authentication FAILED\r\n");
    }
ble_connected_state = next_state;
}

/*!*******************************************************************
* @public
* Function name: client_appl_get_ble_connected_state_ptr
* Description:  Get pointer to ble_connected_state
*********************************************************************/
static uint8* client_appl_get_ble_connected_state_ptr
    (
    void
    )
{
return &ble_connected_state;
}

/*!*******************************************************************
* @public
* Function name: client_appl_get_ble_connected_state
* Description:  Get BLE connected state
*********************************************************************/
static uint8 client_appl_get_ble_connected_state
    (
    void
    )
{
return ble_connected_state;
}

/*!*******************************************************************
* @public
* Function name: byte_merge_u16
* Description: combine two type uint8 data into type uint16
*********************************************************************/
static uint16 byte_merge_u16
    (
    const uint8* data
    )
{
uint16 return_data = ( data[0] << 8 ) | ( 0x00FF & data[1]);
return return_data;
}

#if 0
/*!*******************************************************************
* @public
* Function name: byte_merge_u24
* Description: combine three type uint8 data into type uint32
*********************************************************************/
static uint32 byte_merge_u24
    (
    const uint8* data
    )
{
uint32 return_value = ( 0x00 << 24 & 0xFF000000 )\
                    | ( data[0] << 16 & 0x00FF0000 )\
                    | ( data[1] << 8  & 0x0000FF00 )\
                    | ( data[2] & 0x000000FF);
return return_value;
}


/*!*******************************************************************
* @public
* Function name: byte_merge_u32
* Description: combine four type uint8 data into type uint32
*********************************************************************/
static uint32 byte_merge_u32
    (
    const uint8* data
    )
{
uint32 return_value = ( data[0] << 24 & 0xFF000000 )\
                    | ( data[1] << 16 & 0x00FF0000 )\
                    | ( data[2] << 8  & 0x0000FF00 )\
                    | ( data[3] & 0x000000FF);
return return_value;
}

/*!*******************************************************************
* @public
* Function name: clent_appl_data_swap_u16
* Description: big endian to little endian
*********************************************************************/
static uint16 clent_appl_data_swap_u16
    (
    uint16 data
    )
{
return ( ( data >> 8 ) |
         ( ( data << 8 ) & 0xFF00 ) );
}
#endif

/*!*******************************************************************
* @public
* Function name: clent_appl_data_swap_u32
* Description: big endian to little endian
*********************************************************************/
static uint32 client_app_data_swap_u32
    (
    uint32 data
    )
{
return ( ( ( data << 24 ) & 0xFF000000 ) |
       ( ( data << 8 ) & 0x00FF0000 )|
       ( ( data >> 8 ) & 0x0000FF00 )|
       ( ( data >> 24 ) & 0x000000FF ) );
}
/*!*******************************************************************
* @public
* Function name: client_appl_data_cpy
* Description:   this function implement memory data copy function
*********************************************************************/
static void client_appl_data_cpy
    (
    uint8* dest,
    uint8* src,
    uint16 cnt
    )
{
uint16 i;
for( i = 0; i < cnt; i++ )
    {
    *( dest + i ) = *( src + i );
    }
}

/*!*******************************************************************
* @public
* Function name: client_appl_set_delay_timer
* Description: this function shall set a delay timer value
*********************************************************************/
static void client_appl_set_delay_timer
    (
    uint16  delay_time
    )
{
delay_timer_count = delay_time;
}


static void client_appl_clear_delay_timer
    (
    void
    )
{
delay_timer_count = 0x00000;
}
/*!*******************************************************************
* @public
* Function name: client_appl_get_current_connected_server_id
* Description: this function shall get current connect server index
*********************************************************************/
uint8 client_appl_get_current_connected_server_id
    (
    void
    )
{
return current_connect_server_id;
}

/*!*******************************************************************
* @public
* Function name: client_client_appl_get_first_connected_server_id
* Description: this function shall get the first valid connect server
               index on server list
*********************************************************************/
static uint8 client_appl_get_first_connected_server_id
    (
    void
    )
{
uint8 index = 0;
uint8 return_value = NO_SERVER_CONNECT;

for( ; index < SUPPORT_SERVER_NUM; index++ )
    {
    if( SUPPORT_SERVER_NUM == index)
        {
        return NO_SERVER_CONNECT;
        }
    else if( server_list_detect_infos[index].server_connect_status_default == SERVER_CONNECT )
        {
        return index;
        }
    else
        {
        /*do nothing*/
        }
    }

return return_value;
}


/*!*******************************************************************
* @public
* Function name: appl_set_client_appl_get_first_connected_server_iddelay_timer
* Description: this function shall get the next valid connect server
               index on server list
*********************************************************************/
static uint8 client_appl_get_next_connected_server_id
    (
    void
    )
{
uint8 index = get_current_connect_server_id();
uint8 return_value = NO_SERVER_CONNECT;

for( index++ ; index < SUPPORT_SERVER_NUM; index++ )
    {
    if( SUPPORT_SERVER_NUM == index)
        {
        return NO_SERVER_CONNECT;
        }
    else if( server_list_detect_infos[index].server_connect_status_default == SERVER_CONNECT )
        {
        return index;
        }
    else
        {
        /*do nothing*/
        }
    }

return return_value;
}

/*!*******************************************************************
* @public
* Function name: client_appl_get_last_detected_server_index
* Description: this function shall get the last detected connected server
* index
*********************************************************************/
static uint8 client_appl_get_last_detected_server_index
    (
    void
    )
{
uint8 temp  = 0;
uint8 index = 0;
for( ; temp < SUPPORT_SERVER_NUM; temp++ )
    {
    if( server_list_detect_infos[temp].server_connect_status_default == SERVER_CONNECT )
        {
        index = temp;
        }
    }
return index;
}

/*!*******************************************************************
* @public
* Function name: client_get_current_process_flow
* Description: this function shall set next process flow
* index
*********************************************************************/
client_process_flow_type client_get_current_process_flow
    (
    void
    )
{
return client_process_flow_state;
}


/*!*******************************************************************
* @public
* Function name: client_appl_set_current_process_flow_step
* Description: this function shall set next handle process flow
* Note: In general, this function shall be executed after call function client_appl_get_first_connected_server_id
*********************************************************************/
static boolean client_appl_set_current_process_flow_step
    (
    client_process_flow_type next_process_flow
    )
{
client_process_flow_state = next_process_flow;
/*5ms*20 = 100ms*/
client_appl_set_delay_timer( 40 );

switch( client_process_flow_state )
    {
    case PROCESS_FLOW_IDLE:
        set_current_conncet_server_id( NO_SERVER_CONNECT );
        /*initial structure*/
        /*clear the read_dtc_infos except the read_dtc_infos.is_storge_init_dtc*/
        /*sizeof ( read_dtc_infos) = 12, Byte alignment */
        (void)memset( &read_dtc_infos, 0x00, sizeof( read_dtc_infos ) - 4 );
        (void)memset( &read_common_identifier_infos, 0x00, sizeof( read_common_identifier_infos ));
        (void)memset( &read_loacl_market_infos, 0x00, sizeof( read_loacl_market_infos ) );
        (void)memset( &read_local_monitor_infos, 0x00, sizeof( read_local_monitor_infos ));
        (void)memset( &read_freeze_frame_data_infos,0x00, sizeof( read_freeze_frame_data_infos ));
        set_client_app_cmd_rsp_state( CMD_RSP_IDLE );
        break;

    case PROCESS_FLOW_DETECT_SERVER:
        set_current_conncet_server_id( SUPPORT_SERVER_NUM );
        break;

    case PROCESS_FLOW_EXTEND_SERVER:
        set_current_conncet_server_id( client_appl_get_first_connected_server_id() );
        detect_connected_server_infos.connected_server_id = get_current_connect_server_id();
        detect_connected_server_infos.process_result = PROCESS_RESULT_INIT;
        detect_connected_server_infos.curr_dtc_status_frame = REQ_NO_FRAME;
        detect_connected_server_infos.next_req_dtc_status_frame = REQ_ORIGINAL_FRAME;
        detect_connected_server_infos.nrc_resend_timer = 0x00;
        detect_connected_server_infos.timeout_resend_timer = 0x00;
        break;

    case PROCESS_FLOW_INIT_RDTCBS:
        read_dtc_infos.connected_server_id = get_current_connect_server_id();
        read_dtc_infos.curr_dtc_status_frame = REQ_NO_FRAME;
        read_dtc_infos.next_req_dtc_status_frame = REQ_ORIGINAL_FRAME;
        read_dtc_infos.receive_SNS_timer = 0x00;
        read_dtc_infos.resend_timer = 0x00;
        read_dtc_infos.process_result = PROCESS_RESULT_INIT;
        break;

    case PROCESS_FLOW_RDBCID:
        read_common_identifier_infos.current_common_data_index = 0x00;
        read_common_identifier_infos.process_result = PROCESS_RESULT_INIT;
        read_common_identifier_infos.curr_req_frame = REQ_NO_FRAME;
        read_common_identifier_infos.next_req_frame = REQ_ORIGINAL_FRAME;
        read_common_identifier_infos.receive_SNS_timer = 0x00;
        read_common_identifier_infos.resend_timer = 0x00;
        break;

    case PROCESS_FLOW_MARKET:
        read_loacl_market_infos.current_local_data_index = 0x00;
        read_loacl_market_infos.process_result = PROCESS_RESULT_INIT;
        read_loacl_market_infos.curr_req_frame = REQ_NO_FRAME;
        read_loacl_market_infos.next_req_frame = REQ_ORIGINAL_FRAME;
        read_loacl_market_infos.receive_SNS_timer = 0x00;
        read_loacl_market_infos.resend_timer = 0x00;
        break;

    case PROCESS_FLOW_MONITOR:
        read_local_monitor_infos.current_local_data_index = 0x00;
        read_local_monitor_infos.process_result = PROCESS_RESULT_INIT;
        read_local_monitor_infos.curr_req_frame = REQ_NO_FRAME;
        read_local_monitor_infos.next_req_frame = REQ_ORIGINAL_FRAME;
        read_local_monitor_infos.receive_SNS_timer = 0x00;
        read_local_monitor_infos.resend_timer = 0x00;
        break;

    case PROCESS_FLOW_RFFD:
        read_freeze_frame_data_infos.request_id_list = (uint8*)current_request_freeze_frame_id_list;
        read_freeze_frame_data_infos.requset_id_list_amount = 0x00;
        read_freeze_frame_data_infos.current_freeze_frame_number = 0x01;
        read_freeze_frame_data_infos.curr_request_frame = REQ_NO_FRAME;
        read_freeze_frame_data_infos.prev_request_frame = REQ_NO_FRAME;
        read_freeze_frame_data_infos.next_request_frame = REQ_ORIGINAL_FRAME;
        read_freeze_frame_data_infos.receive_SNS_timer = 0x00;
        read_freeze_frame_data_infos.resend_timer = 0x00;
        read_freeze_frame_data_infos.process_result = PROCESS_RESULT_INIT;
        break;

    default:
    break;
    }
PRINTF("Enter new Process flow:%s\r\n",print_header[next_process_flow]);
return TRUE;
}

/*!*******************************************************************
* @public
* Function name: client_appl_init
* Description: this function shall initial module
*********************************************************************/
client_ReturnType client_appl_init
    (
    void
    )
{
uint8 index = 0;

/*for server list detect*/
for( ; index < SUPPORT_SERVER_NUM; index++ )
    {
    server_list_detect_infos[index].server_id = index;
    server_list_detect_infos[index].ecu_identifier = server_ecu_identifier[index];
    server_list_detect_infos[index].server_connect_status_default = SERVER_UN_CONNECT;
    server_list_detect_infos[index].server_connect_status_extend = SERVER_UN_CONNECT;
    }

server_detect_step = SERVER_DETECT_INIT;
default_server_list_detect_amount = 0x00;
extend_server_list_detect_amount = 0x00;

/*the YDT connect state is sync with actual APP state*/
/*we set ydt_connect_state to FALSE and */
ydt_connected_state = FALSE;
ble_connected_state = FALSE;
sys_operation_mode = EnumOperationModeNORMAL;
operation_mode_switch_flag = FALSE;


/*initial structure info*/
(void)memset( &read_dtc_infos, 0x00, sizeof( read_dtc_infos ));
(void)memset( &read_loacl_market_infos, 0x00, sizeof( read_loacl_market_infos ) );
(void)memset( &read_local_monitor_infos, 0x00, sizeof( read_local_monitor_infos ));
(void)memset( &read_freeze_frame_data_infos,0x00, sizeof( read_freeze_frame_data_infos ));
(void)memset( &read_common_identifier_infos, 0x00, sizeof( read_common_identifier_infos ));
(void)memset( &detect_connected_server_infos, 0x00, sizeof( detect_connected_server_infos ));

client_mem_reset_data();
/*After IG-ON, first enter detect connected server process flow*/
client_appl_set_current_process_flow_step( PROCESS_FLOW_DETECT_SERVER );

/*for debug display*/
#if(APPL_DEBUG)
print_end[0] = (char*)print_end_0;
print_end[1] = (char*)print_end_1;
print_end[2] = (char*)print_end_2;
print_end[3] = (char*)print_end_3;
print_end[4] = (char*)print_end_4;
print_end[5] = (char*)print_end_5;
print_end[6] = (char*)print_end_6;
print_end[7] = (char*)print_end_7;
print_header[0] = (char*)print_header_0;
print_header[1] = (char*)print_header_1;
print_header[2] = (char*)print_header_2;
print_header[3] = (char*)print_header_3;
print_header[4] = (char*)print_header_4;
print_header[5] = (char*)print_header_5;
print_header[6] = (char*)print_header_6;
print_header[7] = (char*)print_header_7;

#endif

return E_OK;
}


#if(APPL_DEBUG)
void client_appl_debug_printf
    (
    uint8 result_code
    )
{
PRINTF("%s + channel%d ", print_header[client_process_flow_state],get_current_connect_server_id() );
PRINTF("%s\r\n\n\n", print_end[result_code]);
}
#endif

/*!******************************************************************************
*
* @public
* Function name: client_appl_operation_mode_switch
* Description  : this function will infrom that a requset of switching operation
*                mode is occured
* usage        : called by we_device_system
*********************************************************************************/
void client_appl_operation_mode_switch
    (
    void
    )
{
operation_mode_switch_flag = TRUE;
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_get_valid_operation_mode
* Description  : this function will get current operation mdoe whether is valid for
*                diagnostic fucntion and handler operation mode switch
* usage        : called periodly
*********************************************************************************/
static boolean client_appl_get_valid_operation_mode
    (
    void
    )
{
static boolean is_read_init_mode = FALSE;
EnumOperationMode mode = EnumOperationModeNORMAL;

if( FALSE == is_read_init_mode )
    {
    /*wait read data from eep after ign on*/
    is_read_init_mode = EW_get_operation_mode( &sys_operation_mode );
    if( TRUE == is_read_init_mode )
        {
        if( EnumOperationModeNORMAL == sys_operation_mode )
            {
            CLIENT_DEBUG("Init_EnterNormalOperationMode\r\n");
            client_appl_init();
            }
        else
            {
            CLIENT_DEBUG("Init_EnterFactoryOperationMode\r\n");
            client_appl_set_current_process_flow_step( PROCESS_FLOW_IDLE );
            client_appl_set_ble_connected_state( FALSE );
            }
        }
    else
        {
        return FALSE;
        }
    }

if( TRUE == operation_mode_switch_flag )
    {
    operation_mode_switch_flag = FALSE;
    (void)EW_get_operation_mode( &mode );
    if( mode != sys_operation_mode )
        {
        sys_operation_mode = mode;
        if( EnumOperationModeNORMAL == sys_operation_mode )
            {
            CLIENT_DEBUG("ModeSwitch_EnterNormalOperationMode\r\n");
            client_appl_init();
            }
        else
            {
            CLIENT_DEBUG("ModeSwitch_InitEnterFactoryOperationMode\r\n");
            client_appl_set_current_process_flow_step( PROCESS_FLOW_IDLE );
            client_appl_set_ble_connected_state( FALSE );
            }
        }
    }

if( EnumOperationModeNORMAL == sys_operation_mode )
    {
    return TRUE;
    }
else
    {
    return FALSE;
    }
}


/*!******************************************************************************
*
* @public
* Function name: client_appl_diagnostic_enable
* Description  : this function will get whether diagnostic function is enable
* usage        : called periodic
*********************************************************************************/
boolean client_appl_diagnostic_enable
    (
    void
    )
{
/*Check the Yamaha diagnostic tools connect state*/
if( TRUE == client_appl_get_ydt_connect_state() )
    {
    return FALSE;
    }

/*Check the system operation mode*/
if( FALSE  == client_appl_get_valid_operation_mode() )
    {
    return FALSE;
    }

return TRUE;
}


/*!******************************************************************************
*
* @public
* Function name: client_appl_is_in_delay
* Description  : this function will control delay function
* usage        : called periodic
*********************************************************************************/
boolean client_appl_is_in_delay
    (
    void
    )
{
if( 0 != delay_timer_count )
    {
    decrease_delay_timer();
    return TRUE;
    }
else
    {
    return FALSE;
    }
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_diagnostic_enable
* Description  : this function will get whether a next BLE command received is enable
* usage        : called periodic
*********************************************************************************/
boolean client_appl_enable_rx_next_command
    (
    void
    )
{
if( ( PROCESS_FLOW_IDLE == client_process_flow_state ) && ( CMD_RSP_PROCESSING != client_app_cmd_rsp_state ) )
    {
    return TRUE;
    }
else if( PROCESS_FLOW_INIT_RDTCBS == client_process_flow_state )
    {
    if( ( TRUE == read_dtc_infos.is_cycle_transmission ) && ( PROCESS_RESULT_INIT != read_dtc_infos.process_result ) && ( is_client_app_cmd_rsp_state( CMD_RSP_DONE) ) )
        {
        return TRUE;
        }
    }
else if( PROCESS_FLOW_MONITOR == client_process_flow_state )
    {
    if( ( PROCESS_RESULT_INIT != read_local_monitor_infos.process_result ) && ( TRUE == read_local_monitor_infos.is_cycle_transmission ) && ( is_client_app_cmd_rsp_state( CMD_RSP_DONE ) ) )
        {
        return TRUE;
        }
    }
else
    {
    /*do nothing*/
    }

return FALSE;
}


/*!******************************************************************************
*
* @public
* Function name: client_appl_delay_ydt_online
* Description  : this function will calculate the time of last ydt request
* usage        : called periodic
*********************************************************************************/
void client_appl_delay_ydt_online
    (
    void
    )
{
if( TRUE == ydt_timer_flag )
    {
    ydt_timer_count--;
    if( 0x0000 == ydt_timer_count )
        {
        CLIENT_DEBUG("Detect Yamaha Detect tools lost connect");
        ydt_timer_flag = FALSE;
        client_appl_init();
        }
    }
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_main_5ms_handler
* Description  : this function will send request message and send final result to
                upper layer when handle process flow
* usage        : called by upper layer period function
*********************************************************************************/

void McLocalRecordVehicleInformationSupportIdListResponse_list_add_id
    (
    McLocalRecordVehicleInformationSupportIdListResponse_id_list_t * list,
    int32_t id
    )
{
if ( list->count < MAX_MCLOCALRECORDVEHICLEINFORMATIONSUPPORTIDLISTRESPONSE_ID_LIST_COUNT )
    {
    list->id_list[list->count] = id;
    list->count++;
    }
}

bool Encode_McLocalRecordVehicleInformationSupportIdListResponse_id_list
    (
    pb_ostream_t *ostream,
    const pb_field_t *field,
    void * const *arg
    )
{
McLocalRecordVehicleInformationSupportIdListResponse_id_list_t * source = (McLocalRecordVehicleInformationSupportIdListResponse_id_list_t*)(*arg);

// encode all
for ( int i = 0; i < source->count; i++ )
    {
    if ( !pb_encode_tag_for_field( ostream, field ) )
        {
        const char * error = PB_GET_ERROR(ostream);
        PRINTF("Encode_McLocalRecordVehicleInformationSupportIdListResponse_id_list field error: %s", error);
        return false;
        }


    if ( !pb_encode_varint( ostream, source->id_list[i] ) )
        {
        const char * error = PB_GET_ERROR( ostream );
        PRINTF( "Encode_McLocalRecordVehicleInformationSupportIdListResponse_id_list submessage error: %s", error );
        return false;
        }
    }

return true;
}


void McMalfunctionResponse_list_add_data
    (
    McMalfunctionResponse_list_t * list,
    int32_t server,
    int32_t code,
    McMalfunctionStatus status
    )
{
if ( list->count < MAX_MCMALFUNCTIONRESPONSE_LIST_COUNT )
    {
    list->ServerCodeStatus_list[list->count].server = server;
    list->ServerCodeStatus_list[list->count].code = code;
    list->ServerCodeStatus_list[list->count].status = status;
    list->count++;
    }
}

bool Encode_McMalfunctionResponse_list
    (
    pb_ostream_t *ostream,
    const pb_field_t *field,
    void * const *arg
    )
{
McMalfunctionResponse_list_t * source = (McMalfunctionResponse_list_t*)(*arg);

// encode all
for ( int i = 0; i < source->count; i++ )
    {
    if ( !pb_encode_tag_for_field( ostream, field ) )
        {
        const char * error = PB_GET_ERROR( ostream );
        PRINTF( "Encode_McMalfunctionResponse_list field error: %s", error );
        return false;
        }

    McMalfunctionResponse_ServerCodeStatus subMessage_ServerCodeStatus = McMalfunctionResponse_ServerCodeStatus_init_default;
    subMessage_ServerCodeStatus.server = source->ServerCodeStatus_list[i].server;
    subMessage_ServerCodeStatus.code = source->ServerCodeStatus_list[i].code;
    subMessage_ServerCodeStatus.status = source->ServerCodeStatus_list[i].status;

    if ( !pb_encode_submessage( ostream, McMalfunctionResponse_ServerCodeStatus_fields, &subMessage_ServerCodeStatus ) )
        {
        const char * error = PB_GET_ERROR( ostream );
        PRINTF( "Encode_McMalfunctionResponse_list submessage error: %s", error );
        return false;
        }

    }

return true;
}


void McServerListResponse_server_list_add_server
    (
    McServerListResponse_server_list_t * list,
    int32_t server
    )
{
if ( list->count < MAX_MMCSERVERLISTRESPONSE_LIST_COUNT )
    {
    list->server_list[list->count] = server;
    list->count++;
    }
}

bool Encode_McServerListResponse_server_list
    (
    pb_ostream_t *ostream,
    const pb_field_t *field,
    void * const *arg
    )
{
McServerListResponse_server_list_t * source = (McServerListResponse_server_list_t*)(*arg);

// encode all
for ( int i = 0; i < source->count; i++ )
    {
    if ( !pb_encode_tag_for_field( ostream, field ) )
        {
        const char * error = PB_GET_ERROR(ostream);
        PRINTF( "Encode_McServerListResponse_server_list field error: %s", error );
        return false;
        }


    if ( !pb_encode_varint( ostream, source->server_list[i] ) )
        {
        const char * error = PB_GET_ERROR( ostream );
        PRINTF( "Encode_McServerListResponse_server_list submessage error: %s", error );
        return false;
        }
    }

return true;
}


void IdDataList_add_IdData
    (
    IdDataList * list,
    int32_t id,
    uint8_t* data,
    uint32_t len
    )
{
if ( list->count < MAX_IDDATA_COUNT )
    {
    list->IdData_array[list->count].id = id;
    memcpy (list->IdData_array[list->count].data, data, len );
    list->IdData_array[list->count].len = len;
    list->count++;
    }
}

bool Encode_IdData_data
    (
    pb_ostream_t *ostream,
    const pb_field_t *field,
    void * const *arg
    )
{
IdData * source = (IdData*)(*arg);

if ( !pb_encode_tag_for_field( ostream, field ) )
    {
    const char * error = PB_GET_ERROR(ostream);
    PRINTF( "Encode_IdData_data field error: %s", error );
    return false;
    }

if ( !pb_encode_string(ostream, source->data,source->len ) )
    {
    const char * error = PB_GET_ERROR( ostream );
    PRINTF( "Encode_IdDatas bytes error: %s", error );
    return false;
    }

return true;
}


bool Encode_IdData_list
    (
    pb_ostream_t *ostream,
    const pb_field_t *field,
    void * const *arg
    )
{
    IdDataList * source = (IdDataList*)(*arg);

    // encode all IdData
    for ( int i = 0; i < source->count; i++ )
        {
        if ( !pb_encode_tag_for_field( ostream, field ) )
            {
            const char * error = PB_GET_ERROR( ostream );
            PRINTF( "Encode_IdData_list field error: %s", error );
            return false;
            }

        /*All Id data sub message has the same structure, so use cVehicleIdentificationResponse*/
        McVehicleIdentificationResponse_IdData subMessage_IdData = McVehicleIdentificationResponse_IdData_init_default;
        subMessage_IdData.id = source->IdData_array[i].id;
        subMessage_IdData.data.arg = &source->IdData_array[i];
        subMessage_IdData.data.funcs.encode = Encode_IdData_data;

        if (!pb_encode_submessage( ostream, source->fields, &subMessage_IdData ) )
            {
            const char * error = PB_GET_ERROR(ostream);
            PRINTF("Encode_IdData_list submessage error: %s", error);
            return false;
            }
        }

    return true;
}

void McFfdResponse_data_list_add_data
    (
    McFfdResponse_data_list_t* list,
    uint8_t* data,
    uint32_t len
    )
{
if( list->count < MAX_MCFFDRESPONSE_DATA_LIST_COUNT )
    {
    memcpy( list->data_list_array[list->count].data, data, len );
    list->data_list_array[list->count].len = len;
    list->count++;
    }
}

bool Encode_McFfdResponse_data_list
    (
    pb_ostream_t *ostream,
    const pb_field_t *field,
    void * const *arg
    )
{
McFfdResponse_data_list_t * source = (McFfdResponse_data_list_t*)(*arg);

// encode all IdData
for ( int i = 0; i < source->count; i++ )
    {
    if ( !pb_encode_tag_for_field( ostream, field ) )
        {
        const char * error = PB_GET_ERROR( ostream );
        PRINTF( "Encode_McFfdResponse_data_list field error: %s", error );
        return false;
        }


    if ( !pb_encode_string( ostream, source->data_list_array[i].data, source->data_list_array[i].len ) )
        {
        const char * error = PB_GET_ERROR( ostream );
        PRINTF( "Encode_McFfdResponse_data_list submessage error: %s", error );
        return false;
        }
    }

return true;
}

size_t Gen_McServerListResponse
    (
    McServerListResponse_server_list_t* pList,
    uint8_t* out_buf,
    size_t out_buf_size
    )
{
McServerListResponse mc_server_list_resp_fb = McServerListResponse_init_default;

// prepare the nanopb ENCODING callback
mc_server_list_resp_fb.server_list.arg = pList;
mc_server_list_resp_fb.server_list.funcs.encode = Encode_McServerListResponse_server_list;

// call nanopb
pb_ostream_t ostream = pb_ostream_from_buffer( out_buf, out_buf_size );
if ( !pb_encode( &ostream, McServerListResponse_fields, &mc_server_list_resp_fb ) )
    {
    const char * error = PB_GET_ERROR( &ostream );
    PRINTF( "Gen_McServerListResponse pb_encode error: %s\r\n", error );
    return 0;
    }
else
    {
    PRINTF( "Gen_McServerListResponse pb_encode for: %d bytes\r\n", ostream.bytes_written );
    return ostream.bytes_written;
    }

}

size_t Gen_McMalfunctionResponse
    (
    McMalfunctionResponse_list_t* pList,
    uint8_t* out_buf,
    size_t out_buf_size
    )
{
McMalfunctionResponse mc_malfunction_resp_fb = McMalfunctionResponse_init_default;

// prepare the nanopb ENCODING callback
mc_malfunction_resp_fb.list.arg = pList;
mc_malfunction_resp_fb.list.funcs.encode = Encode_McMalfunctionResponse_list;

// call nanopb
pb_ostream_t ostream = pb_ostream_from_buffer( out_buf, out_buf_size );
if ( !pb_encode( &ostream, McMalfunctionResponse_fields, &mc_malfunction_resp_fb ) )
    {
    const char * error = PB_GET_ERROR( &ostream );
    PRINTF( "Gen_McMalfunctionResponse pb_encode error: %s\r\n", error );
    return 0;
    }
else
    {
    #if PB_MESSAGE_WHEN_SUCCESS
        PRINTF( "Gen_McMalfunctionResponse pb_encode for: %d bytes\r\n", ostream.bytes_written );
    #endif
    return ostream.bytes_written;
    }

}

size_t Gen_McLocalRecordVehicleInformationSupportIdListResponse
    (
    int32_t server,
    McLocalRecordVehicleInformationSupportIdListResponse_id_list_t* pList,
    uint8_t* out_buf,
    size_t out_buf_size
    )
{
McLocalRecordVehicleInformationSupportIdListResponse mc_support_server_list_resp_fb = McLocalRecordVehicleInformationSupportIdListResponse_init_zero;

// prepare the nanopb ENCODING callback
mc_support_server_list_resp_fb.server = server;
mc_support_server_list_resp_fb.id_list.arg = pList;
mc_support_server_list_resp_fb.id_list.funcs.encode = Encode_McLocalRecordVehicleInformationSupportIdListResponse_id_list;

// call nanopb
pb_ostream_t ostream = pb_ostream_from_buffer( out_buf, out_buf_size );
if ( !pb_encode(&ostream, McLocalRecordVehicleInformationSupportIdListResponse_fields, &mc_support_server_list_resp_fb ) )
    {
    const char * error = PB_GET_ERROR( &ostream );
    PRINTF( "Gen_McLocalRecordVehicleInformationSupportIdListResponse pb_encode error: %s\r\n", error );
    return 0;
    }
else
    {
    #if PB_MESSAGE_WHEN_SUCCESS
        PRINTF( "Gen_McLocalRecordVehicleInformationSupportIdListResponse pb_encode for: %d bytes\r\n", ostream.bytes_written );
    #endif
    return ostream.bytes_written;
    }

}


/*For McVehicleIdentificationResponse, McMarketDataResponse, McLocalRecordVehicleInformationResponse*/
size_t Gen_McVehicleIdentificationResponse
    (
    int32_t server,
    IdDataList* pList,
    uint8_t* out_buf,
    size_t out_buf_size
    )
{
McVehicleIdentificationResponse mc_vehicle_iden_resp_fb = McVehicleIdentificationResponse_init_zero;

// prepare the nanopb ENCODING callback
mc_vehicle_iden_resp_fb.server = server;
mc_vehicle_iden_resp_fb.data_list.arg = pList;
mc_vehicle_iden_resp_fb.data_list.funcs.encode = Encode_IdData_list;

// call nanopb
pb_ostream_t ostream = pb_ostream_from_buffer( out_buf, out_buf_size );
if (!pb_encode(&ostream, McVehicleIdentificationResponse_fields, &mc_vehicle_iden_resp_fb ) )
    {
    const char * error = PB_GET_ERROR( &ostream );
    PRINTF("Gen_McVehicleIdentificationResponse pb_encode error: %s\r\n", error);
    return 0;
    }
else
    {
    #if PB_MESSAGE_WHEN_SUCCESS
        PRINTF("Gen_McVehicleIdentificationResponse pb_encode for: %d bytes\r\n", ostream.bytes_written );
    #endif
    return ostream.bytes_written;
    }
}

size_t Gen_McCanResponse
    (
    IdDataList* pList,
    uint8_t* out_buf,
    size_t out_buf_size
    )
{
McCanResponse mc_can_resp_fb = McCanResponse_init_default;

// prepare the nanopb ENCODING callback
mc_can_resp_fb.data_list.arg = pList;
mc_can_resp_fb.data_list.funcs.encode = Encode_IdData_list;

// call nanopb
pb_ostream_t ostream = pb_ostream_from_buffer( out_buf, out_buf_size );
if ( !pb_encode( &ostream, McCanResponse_fields, &mc_can_resp_fb ) )
    {
    const char * error = PB_GET_ERROR( &ostream );
    PRINTF( "Gen_McCanResponse pb_encode error: %s\r\n", error );
    return 0;
    }
else
    {
    #if PB_MESSAGE_WHEN_SUCCESS
        PRINTF( "Gen_McCanResponse pb_encode for: %d bytes\r\n", ostream.bytes_written );
    #endif

    return ostream.bytes_written;
    }
}


size_t Gen_McFfdResponse
    (
    int32_t server,
    McFfdResponse_data_list_t* pList,
    uint8_t* out_buf,
    size_t out_buf_size
    )
{
McFfdResponse mc_ffd_resp_fb = McFfdResponse_init_zero;

// prepare the nanopb ENCODING callback
mc_ffd_resp_fb.server = server;
mc_ffd_resp_fb.data_list.arg = pList;
mc_ffd_resp_fb.data_list.funcs.encode = Encode_McFfdResponse_data_list;

// call nanopb
pb_ostream_t ostream = pb_ostream_from_buffer( out_buf, out_buf_size );
if (!pb_encode( &ostream, McFfdResponse_fields, &mc_ffd_resp_fb ) )
    {
    const char * error = PB_GET_ERROR( &ostream );
    PRINTF( "Gen_McFfdResponse pb_encode error: %s\r\n", error );
    return 0;
    }
else
    {
    #if PB_MESSAGE_WHEN_SUCCESS
        PRINTF("Gen_McFfdResponse pb_encode for: %d bytes\r\n", ostream.bytes_written );
    #endif
    return ostream.bytes_written;
    }

}


void client_appl_main_5ms_handler
    (
    void
    )
{

client_appl_delay_ydt_online();

if( FALSE == client_appl_diagnostic_enable() )
    {
    client_appl_check_ble_command( FALSE );
    return;
    }

if( TRUE == client_appl_is_in_delay() )
    {
    return;
    }

if( TRUE == client_appl_enable_rx_next_command() )
    {
    client_appl_check_ble_command( TRUE );
    }

if( client_process_flow_state < PROCESS_FLOW_IDLE )
    {
    client_process_flow_handler[client_process_flow_state].appl_period_func();
    }
else
    {
    /*idle state, do nothing*/
    }
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_positive_response_dispatch
* Description  : this function process the positive response data when handle hen handle process flow
* usage        : called by client_diag_response_dispatch_handler_5ms
*********************************************************************************/
void client_appl_positive_response_dispatch
     (
     uint8 * resp_data,
     uint16 resp_lenth,
     uint8 channel_id
     )
{
if( client_process_flow_state < PROCESS_FLOW_IDLE )
    {
    client_process_flow_handler[client_process_flow_state].postive_response_dispatch( resp_data, resp_lenth, channel_id );
    }
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_read_initial_dtc_status_negative_response_handler
* Description  : this function process the negative response data when handle hen handle process flow detect server list
* usage        : called by fclient_diag_response_dispatch_handler_5ms
*********************************************************************************/
void client_appl_negative_response_dispatch
    (
    uint8 service_id,
    uint8 nrc,
    uint8 channel_id
    )
{
if( client_process_flow_state < PROCESS_FLOW_IDLE )
    {
client_process_flow_handler[client_process_flow_state].negative_response_dispatch( service_id, nrc, channel_id );
    }
}


/*!******************************************************************************
*
* @public
* Function name: client_appl_detect_connected_server_response_timeout_notify
* Description  : this function process no data received  when handle hen handle process flow detect server list
* usage        : called by called by fclient_diag_response_dispatch_handler_5ms
*********************************************************************************/
void client_appl_response_timeout_notify
    (
    void
    )
{
if( client_process_flow_state < PROCESS_FLOW_IDLE )
    {
    client_process_flow_handler[client_process_flow_state].response_timeout_notify();
    }
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_data_compare
* Description  : Check whether the elements of the two arrays are exactly the same
*********************************************************************************/
boolean client_appl_data_compare
    (
    const uint8* src,
    const uint8* dst,
    uint8  length
    )
{
uint8 index = 0;
for( ; index < length; index++ )
    {
    if( *(src + index ) != *( dst + index ) )
        {
        return FALSE;
        }
    }
return TRUE;
}

/*!*******************************************************************
* @public
* Function name: client_appl_response_can_related_data
* Description: unifrom interface of response data to upper layer
*********************************************************************/
void client_appl_response_can_related_data
    (
    const uint16 command,
    const uint32                  size,
    const uint8*                  data,
    void ( *result_callback )( const boolean value )
    )
{
set_client_app_cmd_rsp_state( CMD_RSP_PROCESSING );
BC_motocon_send_can_related_data( command, size, data,result_callback );
}



/*!******************************************************************************
*
* @public
* Function name: client_appl_ble_req_authentication
* Description  : parsing the request connect server list command
*********************************************************************************/
boolean client_appl_ble_req_connect_server_list
    (
    void
    )
{
/*Check whether the data has been read  */
if( ( SERVER_DETECT_DEFAULT_DONE == server_detect_step ) && ( 0x00 < default_server_list_detect_amount ) )
    {
    return TRUE;
    }
else
    {
    return FALSE;
    }
}


/*!******************************************************************************
*
* @public
* Function name: client_appl_ble_rsp_connect_server_list
* Description  : this function will get support connect server list and response to motocon
*********************************************************************************/
void client_appl_ble_rsp_connect_server_list
    (
    boolean check_result
    )
{
uint8 index = 0x00;
uint32 server_code = 0;
uint32 resp_data_length = 0;

if( FALSE == check_result )
    {
    client_appl_response_can_related_data( BLE_RSP_CMD_SERVERLIST, (uint32)BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL, &client_appl_cmd_rsp_result_notify );
    }
else
    {
    /* Clear the list */
    g_McServerListResponse_server_list.count = 0;
    for( index = 0; index < SUPPORT_SERVER_NUM; index++ )
        {
        if( SERVER_CONNECT == server_list_detect_infos[index].server_connect_status_default )
            {
            McServerListResponse_server_list_add_server( &g_McServerListResponse_server_list, client_appl_ble_server_code_mapping[index].ble_server_code );
            }
        }
        resp_data_length = Gen_McServerListResponse( &g_McServerListResponse_server_list, McServerListResponse_protobuf, sizeof( McServerListResponse_protobuf ) );
        if( 0 == resp_data_length )
            {
            client_appl_response_can_related_data( BLE_RSP_CMD_SERVERLIST, (uint32)BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL, &client_appl_cmd_rsp_result_notify );
            }
        else
            {
            client_appl_response_can_related_data( BLE_RSP_CMD_SERVERLIST, resp_data_length, (uint8*)McServerListResponse_protobuf, &client_appl_cmd_rsp_result_notify );
            }
    }
}


/*!******************************************************************************
*
* @public
* Function name: client_appl_channel_mapping
* Description  : this function will find connect server channel index according the
* server code
*********************************************************************************/
uint8 client_appl_channel_mapping
    (
    uint32 server_code
    )
{
uint8 return_value = NO_SERVER_CONNECT;
uint8 index = 0x00;

for( ; index < SUPPORT_SERVER_NUM; index++ )
    {
    if( server_code == client_appl_ble_server_code_mapping[index].ble_server_code )
        {
        return_value = client_appl_ble_server_code_mapping[index].channel;
        break;
        }
    }

if( ( return_value != NO_SERVER_CONNECT ) && ( SERVER_CONNECT == server_list_detect_infos[return_value].server_connect_status_default ) )
    {
    /*do nothing*/
    }
else
    {
    return_value =  NO_SERVER_CONNECT;
    }

return return_value;
}


/*!******************************************************************************
*
* @public
* Function name: client_appl_get_curr_id_list_ptr
* Description  : this function will get the address that ponit current repeat data list
*********************************************************************************/
id_list_type* client_appl_get_curr_id_list_ptr
    (
    void
    )
{
return curr_id_list_ptr;
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_set_curr_id_list_ptr
* Description  : this function will set the address that ponit current repeat data list
*********************************************************************************/
void client_appl_set_curr_id_list_ptr
    (
    id_list_type* ptr
    )
{
curr_id_list_ptr = ptr;
}


/*!******************************************************************************
*
* @public
* Function name: add_data_to_id_list
* Description  : this function will fill the parse repeat type data into buff
*********************************************************************************/
boolean add_data_to_id_list
    (
    uint32 data
    )
{
id_list_type* list = client_appl_get_curr_id_list_ptr();

if( list == NULL )
    {
    return FALSE;
    }

if( list->id_list_num < MAX_ID_LIST_NUM )
    {
    list->id_list_array[list->id_list_num] = data;
    list->id_list_num++;
    }
return TRUE;
}

/*!******************************************************************************
*
* @public
* Function name: read_bytes
* Description  : this function will read and handle repeat type data
* NoteL: This is a callback function
*********************************************************************************/
boolean read_bytes
(
    pb_istream_t*     stream,
    const pb_field_t* field,
    void**            arg
)
{
uint64 number = 0;
while( stream->bytes_left )
    {
    pb_decode_varint( stream, &number );
    add_data_to_id_list( (uint32) number);
    }
return TRUE;
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_ble_req_malfunction
* Description  : this function will parsing the request malfunction command and execute command
*********************************************************************************/
boolean client_appl_ble_req_malfunction
    (
    boolean is_request_interval,
    uint32 data_size,
    const uint8* data
    )
{
uint8 channel_id = NO_SERVER_CONNECT;
uint8 status_code = 0;
uint32 server_code = 0;
uint32 interval_time = 0;

/*For Command: MALFUNCTION REQUEST */
/*Command type: 0x0105 */
if ( FALSE == is_request_interval )
    {
    uint8 sdata[5] = {0x18,0xE0,0x09,0x20,0x01};
    uint8 sdata_len = 5;
    McMalfunctionRequest mal_fucntion_requset_pb = McMalfunctionRequest_init_zero;

    #if ( TRUE == SIMULATE_INPUT_DEBUG )
    pb_istream_t stream = pb_istream_from_buffer( sdata, sdata_len );
    #else
    pb_istream_t stream = pb_istream_from_buffer( data, data_size );
    #endif


    if (pb_decode( &stream, McMalfunctionRequest_fields, &mal_fucntion_requset_pb ) )
        {
        server_code = mal_fucntion_requset_pb.server;
        status_code = mal_fucntion_requset_pb.status;
        }
    else
        {
        return E_PARSE_FAILED;
        }
    }
else
/*For Command: MALFUNCTION REQUEST INTERVAL*/
/*Command type: 0x0109 */
    {
    uint8 sdata[8] = {0x18,0xE0,0x09,0x20,0x01,0x28,0xE0,0x09};
    uint8 sdata_len = 8;
    McMalfunctionIntervalRequest mal_fucntion_interval_requset_pb = McMalfunctionIntervalRequest_init_zero;
    #if ( TRUE == SIMULATE_INPUT_DEBUG )
    pb_istream_t stream = pb_istream_from_buffer( sdata, sdata_len );
    #else
    pb_istream_t stream = pb_istream_from_buffer( data, data_size );
    #endif
    if ( pb_decode( &stream, McMalfunctionIntervalRequest_fields, &mal_fucntion_interval_requset_pb ) )
        {
        server_code = (uint32)mal_fucntion_interval_requset_pb.server;
        status_code = mal_fucntion_interval_requset_pb.status;
        interval_time = mal_fucntion_interval_requset_pb.interval;
        }
    else
        {
        return E_PARSE_FAILED;
        }
    }

/*check current server is connect*/
channel_id = client_appl_channel_mapping( server_code );
if( NO_SERVER_CONNECT == channel_id  )
    {
    return E_PARAMETER_ERROR;
    }

/*check status code*/
switch( status_code )
    {
    case BLE_CMD_MAL_STATUS_MARK:
        status_code = DCM_18h_STATDTC_A1;
        break;

    case BLE_CMD_MAL_STATUS_TRIANGLE:
        status_code = DCM_18h_STATDTC_20;
        break;

    case BLE_CMD_MAL_STATUS_FULL:
        status_code = DCM_18h_STATDTC_FF;
        break;

    case BLE_CMD_MAL_STATUS_TEMPORARY:
        status_code = DCM_18h_STATDTC_24;
        break;

    default:
        return E_PARAMETER_ERROR;
        break;
    }

if( FALSE == is_request_interval )
    {
    read_dtc_infos.is_cycle_transmission = FALSE;
    read_dtc_infos.cycle_tarns_interval_time = STOP_INTER_TIME;
    }
else
    {
    if( STOP_INTER_TIME == interval_time )
        {
        read_dtc_infos.is_cycle_transmission = FALSE;
        read_dtc_infos.cycle_tarns_interval_time = STOP_INTER_TIME;
        }
    else
        {
        read_dtc_infos.is_cycle_transmission = TRUE;
        read_dtc_infos.cycle_tarns_interval_time = interval_time;
        }
    }

read_dtc_infos.connected_server_id = channel_id;
read_dtc_infos.current_STADTC = status_code;
set_current_conncet_server_id( channel_id );
client_appl_set_current_process_flow_step( PROCESS_FLOW_INIT_RDTCBS );

g_McMalfunctionResponse_list.count = 0;


return E_SUCCESS;
}


/*!******************************************************************************
*
* @public
* Function name: client_appl_ble_req_vehicle_identification
* Description  : this function will parsing the request vehicle identification and execute command
*********************************************************************************/
boolean client_appl_ble_req_vehicle_identification
    (
    uint32 data_size,
    uint8* data
    )
{
uint8 index = 0;
uint8 channel_id = NO_SERVER_CONNECT;
uint32 server_code = 0;
boolean read_all_id = FALSE;

uint8 sdata[13] = { 0x18, 0xE0, 0x09, 0x22, 0x06, 0x03, 0x8E, 0x02 ,0x9E ,0xA7 ,0x05, 0x28, 0x01 };
uint16 sdata_len = 13;
McVehicleIdentificationRequest mc_vehicle_iden_req_fb = McVehicleIdentificationRequest_init_zero;

/*Shall reset current id number when received a new command*/
vehicle_iden_list.id_list_num = 0;
client_appl_set_curr_id_list_ptr( &vehicle_iden_list );

void* pointer = &vehicle_iden_list;
mc_vehicle_iden_req_fb.id_list.arg = &pointer;
mc_vehicle_iden_req_fb.id_list.funcs.decode = read_bytes;


#if ( TRUE == SIMULATE_INPUT_DEBUG )
    pb_istream_t stream = pb_istream_from_buffer( sdata, sdata_len );
#else
    pb_istream_t stream = pb_istream_from_buffer( data, data_size );
#endif

if( pb_decode( &stream, McVehicleIdentificationRequest_fields, &mc_vehicle_iden_req_fb ) )
    {
    server_code = mc_vehicle_iden_req_fb.server;
    read_all_id = mc_vehicle_iden_req_fb.all_id;
    }
else
    {
    return E_PARSE_FAILED;
    }

/*check server code */
channel_id = client_appl_channel_mapping( server_code );
if( NO_SERVER_CONNECT == channel_id )
    {
    return E_PARAMETER_ERROR;
    }

/*command data handle*/
if( TRUE == read_all_id )
    {
    client_appl_set_current_process_flow_step( PROCESS_FLOW_RDBCID );
    set_current_conncet_server_id( channel_id );
    read_common_identifier_infos.connected_server_id = channel_id;
    read_common_identifier_infos.common_id_list = (uint16*)support_common_data_id_list;
    read_common_identifier_infos.common_data_amount = SUPPORT_COMMON_COUNT;
    read_common_identifier_infos.current_common_data_index = 0x00;

    g_IdDataList.count = 0;
    g_IdDataList.fields = McVehicleIdentificationResponse_IdData_fields;
    return E_SUCCESS;
    }
else
    {
    for( index = 0; index < vehicle_iden_list.id_list_num; index++ )
        {
        rx_comman_data_id_list[index] = (uint16)vehicle_iden_list.id_list_array[index];
        }

    client_appl_set_current_process_flow_step( PROCESS_FLOW_RDBCID );
    set_current_conncet_server_id( channel_id );
    read_common_identifier_infos.connected_server_id = channel_id;
    read_common_identifier_infos.common_id_list = rx_comman_data_id_list;
    read_common_identifier_infos.common_data_amount = vehicle_iden_list.id_list_num;
    read_common_identifier_infos.current_common_data_index = 0x00;

    g_IdDataList.count = 0;
    g_IdDataList.fields = McVehicleIdentificationResponse_IdData_fields;
    return E_SUCCESS;
    }
}


/*!******************************************************************************
*
* @public
* Function name: client_appl_ble_req_market_data
* Description  : this function will parsing the request market data and execute command
*********************************************************************************/
boolean client_appl_ble_req_market_data
    (
    uint32 data_size,
    uint8* data
    )
{
uint8 index = 0;
uint8 channel_id = NO_SERVER_CONNECT;
uint32 server_code = 0;
boolean read_all_id = FALSE;

uint8 sdata[11] = { 0x18, 0xE0, 0x09, 0x22, 0x06, 0x03, 0x8E, 0x02 ,0x9E ,0xA7 ,0x05 };
uint16 sdata_len = 11;
McMarketDataRequest mc_market_data_req_fb = McMarketDataRequest_init_zero;


/*Shall reset current id number when received a new command*/
market_data_list.id_list_num = 0;
client_appl_set_curr_id_list_ptr( &market_data_list );
void* pointer = &market_data_list;
mc_market_data_req_fb.id_list.arg = &pointer;
mc_market_data_req_fb.id_list.funcs.decode = read_bytes;


#if ( TRUE == SIMULATE_INPUT_DEBUG )
    pb_istream_t stream = pb_istream_from_buffer( sdata, sdata_len );
#else
    pb_istream_t stream = pb_istream_from_buffer( data, data_size );
#endif

if( pb_decode( &stream, McMarketDataRequest_fields, &mc_market_data_req_fb ) )
    {
    server_code = mc_market_data_req_fb.server;
    read_all_id = mc_market_data_req_fb.all_id;
    }
else
    {
    return E_PARSE_FAILED;
    }

/*check server code */
channel_id = client_appl_channel_mapping( server_code );
if( NO_SERVER_CONNECT == channel_id )
    {
    return E_PARAMETER_ERROR;
    }

/*command data handle*/
if( TRUE == read_all_id )
    {
    client_appl_set_current_process_flow_step( PROCESS_FLOW_MARKET );
    set_current_conncet_server_id( channel_id );
    read_loacl_market_infos.connected_server_id = channel_id;
    read_loacl_market_infos.local_id_list = (uint8*)support_market_data_id_list;
    read_loacl_market_infos.amount_local_data = SUPPORT_MARKET_COUNT;
    read_loacl_market_infos.current_local_data_index = 0x00;

    g_IdDataList.count = 0;
    g_IdDataList.fields = McMarketDataResponse_IdData_fields;
    return E_SUCCESS;
    }
else
    {
    for( index = 0; index < market_data_list.id_list_num; index++ )
        {
        rx_market_data_id_list[index] = (uint8)market_data_list.id_list_array[index];
        }
    client_appl_set_current_process_flow_step( PROCESS_FLOW_MARKET );
    set_current_conncet_server_id( channel_id );
    read_loacl_market_infos.connected_server_id = channel_id;
    read_loacl_market_infos.local_id_list = rx_market_data_id_list;
    read_loacl_market_infos.amount_local_data = market_data_list.id_list_num;
    read_loacl_market_infos.current_local_data_index = 0x00;

    g_IdDataList.count = 0;
    g_IdDataList.fields = McMarketDataResponse_IdData_fields;
    return E_SUCCESS;
    }
}


/*!******************************************************************************
*
* @public
* Function name: client_appl_ble_req_vehicle_information_supproted_list
* Description  : this function will parsing the request vehicle supported list
*********************************************************************************/
boolean client_appl_ble_req_vehicle_information_supproted_list
    (
    uint32 data_size,
    uint8* data
    )
{

#if ( TRUE == SIMULATE_INPUT_DEBUG )
data[0]= 0x04;
data[1] = 0xE0;
data_size = 2;
#else
#endif

uint8 channel_id = NO_SERVER_CONNECT;
uint16 server_code_u16 = 0;
uint32 server_code = 0;

if( 0x02 != data_size )
    {
    return E_PARAMETER_ERROR;
    }

/*Check server code*/
server_code_u16 = byte_merge_u16( data );
server_code = (uint32)server_code_u16;
channel_id = client_appl_channel_mapping( server_code );
if( NO_SERVER_CONNECT == channel_id )
    {
    return E_PARAMETER_ERROR;
    }

client_appl_set_current_process_flow_step( PROCESS_FLOW_MONITOR );
set_current_conncet_server_id( channel_id );
read_local_monitor_infos.connected_server_id = channel_id;
read_local_monitor_infos.local_id_list = (uint8*)support_monitor_data_id_list;
read_local_monitor_infos.amount_local_data = SUPPORT_MONITOR_COUNT;
read_local_monitor_infos.current_local_data_index = 0x00;
read_local_monitor_infos.is_request_support_list_flow = TRUE;
read_local_monitor_infos.support_id_received_flag_array = (boolean*)support_id_received_flag;

g_McLocalRecordVehicleInformationSupportIdListResponse_id_list.count = 0;

return E_SUCCESS;
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_ble_req_vehicle_information
* Description  : this function will parsing the request vehicle information (interval) command and execute command
*********************************************************************************/
boolean client_appl_ble_req_vehicle_information
    (
    boolean is_request_interval,
    uint32 data_size,
    uint8* data
    )
{
uint8 index = 0;
uint8 channel_id = NO_SERVER_CONNECT;
uint32 interval_time= 0;
boolean read_all_id = FALSE;
uint32 server_code = 0;

/*For command VEHICLE INFORMATION REQUEST */
/*Command type: 0x010E*/
if( FALSE == is_request_interval )
    {
    /*--------------------------------command parse--------------------------------------------*/
    uint8 sdata[13] = { 0x18, 0xE0, 0x09, 0x22, 0x06, 0x03, 0x8E, 0x02 ,0x9E ,0xA7 ,0x05, 0x28, 0x00 };
    uint16 sdata_len = 13;
    McLocalRecordVehicleInformationRequest mc_vehicle_info_req_fb = McLocalRecordVehicleInformationRequest_init_zero;


    /*Shall reset current id number when received a new command*/
    vhicle_information_list.id_list_num = 0;
    client_appl_set_curr_id_list_ptr( &vhicle_information_list );
    void* pointer = &vhicle_information_list;
    mc_vehicle_info_req_fb.id_list.arg = &pointer;
    mc_vehicle_info_req_fb.id_list.funcs.decode = read_bytes;


#if ( TRUE == SIMULATE_INPUT_DEBUG )
    pb_istream_t stream = pb_istream_from_buffer( sdata, sdata_len );
#else
    pb_istream_t stream = pb_istream_from_buffer( data, data_size );
#endif
    if( pb_decode( &stream, McLocalRecordVehicleInformationRequest_fields, &mc_vehicle_info_req_fb ) )
        {
        server_code = mc_vehicle_info_req_fb.server;
        read_all_id = mc_vehicle_info_req_fb.all_id;
        }
    else
        {
        return E_PARSE_FAILED;
        }

    /*--------------------------------Process flow--------------------------------------------*/
    /*Check server code*/
    channel_id = client_appl_channel_mapping( server_code );
    if( NO_SERVER_CONNECT == channel_id )
        {
        return E_PARSE_FAILED;
        }

    if( TRUE == read_all_id )
        {
        read_local_monitor_infos.is_cycle_transmission = FALSE;
        read_local_monitor_infos.cycle_tarns_interval_time = STOP_INTER_TIME;
        read_local_monitor_infos.local_id_list = (uint8*)support_monitor_data_id_list;
        read_local_monitor_infos.amount_local_data = SUPPORT_MONITOR_COUNT;
        client_appl_set_current_process_flow_step( PROCESS_FLOW_MONITOR );
        read_local_monitor_infos.current_local_data_index = 0x00;
        read_local_monitor_infos.is_request_support_list_flow = FALSE;
        read_local_monitor_infos.connected_server_id = channel_id;
        set_current_conncet_server_id( channel_id );

        g_IdDataList.count = 0;
        g_IdDataList.fields = McLocalRecordVehicleInformationResponse_fields;
        return E_SUCCESS;
        }
    else if( FALSE == read_all_id )
        {
        for( index = 0; index < vhicle_information_list.id_list_num; index++ )
            {
            rx_monitor_data_id_list[index] = vhicle_information_list.id_list_array[index];
            }
        read_local_monitor_infos.is_cycle_transmission = FALSE;
        read_local_monitor_infos.cycle_tarns_interval_time = STOP_INTER_TIME;
        read_local_monitor_infos.local_id_list = (uint8*)rx_monitor_data_id_list;
        read_local_monitor_infos.amount_local_data =  vhicle_information_list.id_list_num;
        client_appl_set_current_process_flow_step( PROCESS_FLOW_MONITOR );
        read_local_monitor_infos.current_local_data_index = 0x00;
        read_local_monitor_infos.is_request_support_list_flow = FALSE;
        read_local_monitor_infos.connected_server_id = channel_id;

        g_IdDataList.count = 0;
        g_IdDataList.fields = McLocalRecordVehicleInformationResponse_fields;
        return E_SUCCESS;
        }
    else
        {
        return E_PARAMETER_ERROR;
        }
    }



/*For command VEHICLE INFORMATION INTERVAL REQUEST */
/*Command type: 0x0110*/
if( TRUE == is_request_interval )
    {
    /*--------------------------------command parse--------------------------------------------*/
    uint8 sdata[16] = { 0x18, 0xE0, 0x09, 0x22, 0x06, 0x03, 0x8E, 0x02 ,0x9E ,0xA7 ,0x05, 0x28, 0x01, 0x30, 0xE0, 0x09};
    uint16 sdata_len = 16;
    McLocalRecordVehicleInformationIntervalRequest mc_vehicle_info_inter_req_fb = McLocalRecordVehicleInformationIntervalRequest_init_zero;


    /*Shall reset current id number when received a new command*/
    vhicle_information_list.id_list_num = 0;
    client_appl_set_curr_id_list_ptr( &vhicle_information_list );
    void* pointer = &vhicle_information_list;
    mc_vehicle_info_inter_req_fb.id_list.arg = &pointer;
    mc_vehicle_info_inter_req_fb.id_list.funcs.decode = read_bytes;


#if ( TRUE == SIMULATE_INPUT_DEBUG )
    pb_istream_t stream = pb_istream_from_buffer( sdata, sdata_len );
#else
    pb_istream_t stream = pb_istream_from_buffer( data, data_size );
#endif
    if( pb_decode( &stream, McLocalRecordVehicleInformationIntervalRequest_fields, &mc_vehicle_info_inter_req_fb ) )
        {
        server_code = mc_vehicle_info_inter_req_fb.server;
        read_all_id = mc_vehicle_info_inter_req_fb.all_id;
        interval_time = mc_vehicle_info_inter_req_fb.interval;
        }
    else
        {
        return E_PARSE_FAILED;
        }

    /*--------------------------------Process flow--------------------------------------------*/
    /*Check server code*/
    channel_id = client_appl_channel_mapping( server_code );
    if( NO_SERVER_CONNECT == channel_id )
        {
        return E_PARSE_FAILED;
        }

    if( TRUE == read_all_id )
        {
        if( STOP_INTER_TIME == interval_time )
            {
            read_local_monitor_infos.is_cycle_transmission = FALSE;
            read_local_monitor_infos.cycle_tarns_interval_time = STOP_INTER_TIME;
            }
        else
            {
            read_local_monitor_infos.is_cycle_transmission = TRUE;
            read_local_monitor_infos.cycle_tarns_interval_time = read_all_id / 5;
            }

        read_local_monitor_infos.local_id_list = (uint8*)support_monitor_data_id_list;
        read_local_monitor_infos.amount_local_data = SUPPORT_MONITOR_COUNT;
        client_appl_set_current_process_flow_step( PROCESS_FLOW_MONITOR );
        read_local_monitor_infos.current_local_data_index = 0x00;
        read_local_monitor_infos.is_request_support_list_flow = FALSE;
        read_local_monitor_infos.connected_server_id = channel_id;
        set_current_conncet_server_id( channel_id );

        g_IdDataList.count = 0;
        g_IdDataList.fields = McLocalRecordVehicleInformationResponse_fields;
        return E_SUCCESS;
        }
    else if( FALSE == read_all_id )
        {
        for( index = 0; index < vhicle_information_list.id_list_num; index++ )
            {
            rx_monitor_data_id_list[index] = vhicle_information_list.id_list_array[index];
            }

        if( interval_time == 0 )
            {
            read_local_monitor_infos.is_cycle_transmission = FALSE;
            read_local_monitor_infos.cycle_tarns_interval_time = STOP_INTER_TIME;
            }
        else
            {
            read_local_monitor_infos.is_cycle_transmission = TRUE;
            read_local_monitor_infos.cycle_tarns_interval_time = read_all_id / 5;
            }
        read_local_monitor_infos.local_id_list = (uint8*)rx_monitor_data_id_list;
        read_local_monitor_infos.amount_local_data =  vhicle_information_list.id_list_num;
        client_appl_set_current_process_flow_step( PROCESS_FLOW_MONITOR );
        read_local_monitor_infos.current_local_data_index = 0x00;
        read_local_monitor_infos.is_request_support_list_flow = FALSE;
        read_local_monitor_infos.connected_server_id = channel_id;

        g_IdDataList.count = 0;
        g_IdDataList.fields = McLocalRecordVehicleInformationResponse_fields;
        return E_SUCCESS;
        }
    else
        {
        return E_PARAMETER_ERROR;
        }
    }
return E_SUCCESS;
}


/*!******************************************************************************
*
* @public
* Function name: client_app_ble_req_freeze_frame_data
* Description  : this function will parsing the request freeze frame data command and execute command
*********************************************************************************/
boolean client_app_ble_req_freeze_frame_data
    (
    uint32 data_size,
    uint8* data
    )
{
uint8 channel_id = NO_SERVER_CONNECT;
uint16 server_code_u16 = 0;
uint32 server_code = 0;

#if ( TRUE == SIMULATE_INPUT_DEBUG )
data[0]= 0x04;
data[1] = 0xE0;
data_size = 2;
#else
#endif

/*Check data length*/
if( 0x02 != data_size )
    {
    return E_PARAMETER_ERROR;
    }

/*Check server code*/
server_code_u16 = byte_merge_u16( data );
server_code = (uint32)server_code_u16;
channel_id = client_appl_channel_mapping( server_code );

if( NO_SERVER_CONNECT == channel_id )
    {
    return E_PARAMETER_ERROR;
    }

client_appl_set_current_process_flow_step( PROCESS_FLOW_RFFD );
set_current_conncet_server_id( channel_id );
read_freeze_frame_data_infos.connected_server_id = channel_id;
g_McFfdResponse_data_list.count = 0;

return E_SUCCESS;
}


typedef void (*rsp_result_func_notify)(uint8);

void client_appl_rsp_initial_dtc_after_ble_connect
    (
    boolean value
    )
{
uint8 index = 0;
uint8 dtc_number = 0;
uint8 result = 0x00;
uint8* data_ptr =  NULL;
uint16 data_length = 0;
uint32 resp_data_len = 0;
static uint8 current_send_channel_id = 0;
uint32 server_code = 0;
uint8* start_addr = NULL;
uint16 dtc_code = 0;
rsp_result_func_notify rsp_result_func_ptr = NULL;


for( ; current_send_channel_id < SUPPORT_SERVER_NUM; current_send_channel_id++ )
    {
    server_code = client_appl_ble_server_code_mapping[current_send_channel_id].ble_server_code ;

    if( SERVER_CONNECT == server_list_detect_infos[current_send_channel_id].server_connect_status_default )
        {
        client_mem_get_init_dtc_data( current_send_channel_id, &result, &data_length, &data_ptr );

        /*choose callback function*/
        if( current_send_channel_id == client_appl_get_last_detected_server_index() )
            {
            rsp_result_func_ptr = &client_appl_cmd_rsp_result_notify;
            current_send_channel_id = 0;
            }
        else
            {
            rsp_result_func_ptr = &client_appl_rsp_initial_dtc_after_ble_connect;
            current_send_channel_id++;
            }

        if( E_OK == result )
            {
            g_McMalfunctionResponse_list.count = 0;
            /*postive resposne data foramt */
            /*  1 bytes SID  + n #DTC     + n *(2 bytes DTC + 1 bytes status)*/
            dtc_number = data_ptr[BYTE_NUM_1];

            if( ( 0 == dtc_number ) && ( 0x02 == data_length ) )
                {
                /*1 fill data*/
                McMalfunctionResponse_list_add_data( &g_McMalfunctionResponse_list, server_code, 0x0000, read_dtc_infos.current_STADTC );

                /*2 generate protobuf data*/
                resp_data_len = Gen_McMalfunctionResponse( &g_McMalfunctionResponse_list, McMalfunctionResponse_protobuf, sizeof( McMalfunctionResponse_protobuf ) );

                /*3 send protobuf data*/
                if( 0 == resp_data_len )
                    {
                    client_appl_response_can_related_data( BLE_RSP_CMD_MALFUNCTION, 0x00, NULL, rsp_result_func_ptr );
                    }
                else
                    {
                    client_appl_response_can_related_data( BLE_RSP_CMD_MALFUNCTION,resp_data_len,McMalfunctionResponse_protobuf, rsp_result_func_ptr );
                    }
                }
            else if( data_length == 3* dtc_number + 2 )
                {
                /*1 fill data*/
                for( index = 0; index < dtc_number; index++ )
                    {
                    start_addr = data_ptr + 2 + (dtc_number - 1 )* 3;
                    if( read_dtc_infos.current_STADTC == start_addr[2] )
                        {
                        dtc_code = byte_merge_u16( start_addr );
                         McMalfunctionResponse_list_add_data( &g_McMalfunctionResponse_list, server_code, dtc_code, McMalfunctionStatus_TRIANGLE );
                        }
                    }

                /*2 generate protobuf data*/
                resp_data_len = Gen_McMalfunctionResponse( &g_McMalfunctionResponse_list, McMalfunctionResponse_protobuf, sizeof( McMalfunctionResponse_protobuf ) );

               /*3 send protobuf data*/
                if( 0 == resp_data_len )
                    {
                    client_appl_response_can_related_data( BLE_RSP_CMD_MALFUNCTION, 0x00, NULL, rsp_result_func_ptr );
                    }
                else
                    {
                    client_appl_response_can_related_data( BLE_RSP_CMD_MALFUNCTION,resp_data_len,McMalfunctionResponse_protobuf, rsp_result_func_ptr );
                    }
                }
           else
                {
                client_appl_response_can_related_data( BLE_RSP_CMD_MALFUNCTION, 0x00, NULL, rsp_result_func_ptr );
                return;
                }
            }
        /*current channel is valid,but no initial data*/
        else
            {
            client_appl_response_can_related_data( BLE_RSP_CMD_MALFUNCTION, 0x00, NULL, rsp_result_func_ptr );
            return;
            }
        }
    else
        {
        /*choose callback function*/
        if( current_send_channel_id == client_appl_get_last_detected_server_index() )
            {
            /*There shall not call a callback fucntion*/
            current_send_channel_id = 0;
            }
        else
            {
            current_send_channel_id++;
            /*There shall call a callback fucntion*/
            client_appl_rsp_initial_dtc_after_ble_connect( TRUE );
            }
        }
    }
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_rsp_server_list_after_ble_connect
* Description  : this function will response all detected server list to yamaha app
*********************************************************************************/
void client_appl_rsp_server_list_after_ble_connect
    (
    void
    )
{
uint8 index = 0x00;
uint8 resp_data_pos = 0x00;
uint32 resp_data_length = 0x00;


/*Clear the list*/
g_McServerListResponse_server_list.count = 0;

/*Get connect server list data*/
for( ; index < SUPPORT_SERVER_NUM; index++ )
    {
    if( SERVER_CONNECT == server_list_detect_infos[index].server_connect_status_default )
        {
        McServerListResponse_server_list_add_server( &g_McServerListResponse_server_list, client_appl_ble_server_code_mapping[index].ble_server_code );
        }
    }
/*Gernerate protobuf*/
resp_data_length = Gen_McServerListResponse( &g_McServerListResponse_server_list, McServerListResponse_protobuf, sizeof( McServerListResponse_protobuf ) );

/*No valid data*/
if( 0 == resp_data_length )
    {
    client_appl_response_can_related_data( BLE_RSP_CMD_SERVERLIST, resp_data_length, NULL, &client_appl_cmd_rsp_result_notify );
    }
/*LC will send init DTC data continuosly if have been storaged init DTC data*/
else if( TRUE == read_dtc_infos.is_storge_init_dtc )
    {
    //client_appl_response_can_related_data( BLE_RSP_CMD_SERVERLIST, resp_data_length, (uint8*)McServerListResponse_protobuf, &client_appl_rsp_initial_dtc_after_ble_connect );
     client_appl_response_can_related_data( BLE_RSP_CMD_SERVERLIST, resp_data_length, (uint8*)McServerListResponse_protobuf, &client_appl_cmd_rsp_result_notify );
    }
else
    {
    client_appl_response_can_related_data( BLE_RSP_CMD_SERVERLIST, resp_data_length, (uint8*)McServerListResponse_protobuf, &client_appl_cmd_rsp_result_notify );
    }
}


/*!******************************************************************************
*
* @public
* Function name: client_appl_ble_req_command_dispatch
* Description  : this function will parsing the request from MOTOCAN and execute command
*********************************************************************************/
void client_appl_ble_req_command_dispatch
    (
    uint16 req_command,
    uint32 data_size,
    uint8* data
    )
{
#if ( TRUE == CONSOLE_PRINT )
    uint32 temp = 0;
    PRINTF("RX-BleRequestcommand\r\n");
    PRINTF("RX-CMD:%2x, RX-LEN %d \r\n",req_command, data_size);
    PRINTF("RX-Data");

    for( temp = 0; temp < data_size; temp++ )
        {
        PRINTF("%2x ",data[temp]);
        }
    PRINTF("\r\n");
#endif
/*Linkcard only handle BLE command after passed Authentication*/
/*
if( FALSE == client_appl_get_ble_connected_state() )
    {
    CLIENT_DEBUG("Failed CMD with Pass Authentication\r\n");
    return;
    }
*/



switch( req_command )
    {
    /*This is only for DEBUG*/
#if ( TRUE == APPL_DEBUG )
    case BLE_REQ_CMD_AUTHENTICATION:
        client_appl_set_ble_connected_state( TRUE );
        break;
#endif

    case BLE_REQ_CMD_SERVERLIST:
        PRINTF("HandlerCMDResult-BleCmdReqServerList-SUCCESS\r\n");
        client_appl_ble_rsp_connect_server_list( client_appl_ble_req_connect_server_list());
        break;

    case BLE_REQ_CMD_MALFUNCTION:
        if( E_SUCCESS != client_appl_ble_req_malfunction( FALSE, data_size, data ) )
            {
            PRINTF("HandlerCMDResult-BleCmdMalFunction-FAILED\r\n");
            client_appl_response_can_related_data( BLE_RSP_CMD_MALFUNCTION, (uint32)BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL ,&client_appl_cmd_rsp_result_notify);
            }
        else
            {
            PRINTF("HandlerCMDResult-BleCmdMalFunction-SUCCESS\r\n");
            }
        break;

    case BLE_REQ_CMD_MALFUNCTION_INTERVAL:
         if( E_SUCCESS != client_appl_ble_req_malfunction( TRUE, data_size, data ) )
            {
            PRINTF("HandlerCMDResult-BleCmdMalFunctionInterval-FAILED\r\n");
            client_appl_response_can_related_data( BLE_RSP_CMD_MALFUNCTION, (uint32)BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL ,&client_appl_cmd_rsp_result_notify);
            }
         else
            {
            PRINTF("HandlerCMDResult-BleCmdMalFunctionInterval-SUCCESS\r\n");
            }
        break;

    case BLE_REQ_CMD_VEHICLE_IDENTIFICATION:
        if( E_SUCCESS != client_appl_ble_req_vehicle_identification( data_size, data ) )
            {
            PRINTF("HandlerCMDResult-BleCmdVehicleIdentification-FAILED\r\n");
            client_appl_response_can_related_data( BLE_RSP_CMD_VEHICLE_IDENTIFICATION, (uint32)BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL ,&client_appl_cmd_rsp_result_notify);
            }
        else
            {
            PRINTF("HandlerCMDResult-BleCmdVehicleIdentification-SUCCESS\r\n");
            }
        break;

    case BLE_REQ_CMD_MARKET_DATA:
        if( E_SUCCESS != client_appl_ble_req_market_data( data_size, data ) )
            {
            PRINTF("HandlerCMDResult-BleCmdMarketData-FAILED\r\n");
            client_appl_response_can_related_data( BLE_RSP_CMD_MARKET_DATA, (uint32)BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL ,&client_appl_cmd_rsp_result_notify);
            }
        else
            {
            PRINTF("HandlerCMDResult-BleCmdMarketData-SUCCESS\r\n");
            }
        break;

    case BLE_REQ_CMD_VEHICLE_INFORMATION:
        if( E_SUCCESS != client_appl_ble_req_vehicle_information( FALSE, data_size, data ) )
            {
            PRINTF("HandlerCMDResult-BleCmdVehicleInfos-FAILED\r\n");
            client_appl_response_can_related_data( BLE_RSP_CMD_VEHICLE_INFORMATION, (uint32)BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL, &client_appl_cmd_rsp_result_notify );
            }
        else
            {
            PRINTF("HandlerCMDResult-BleCmdVehicleInfos-SUCCESS\r\n");
            }
        break;

    case BLE_REQ_CMD_VEHIVLE_INFORMATION_SUPPORT_LIST:
        if( E_SUCCESS != client_appl_ble_req_vehicle_information_supproted_list( data_size, data ) )
            {
            PRINTF("HandlerCMDResult-BleCmdVehicleInfosSupportList-FAILED\r\n");
            client_appl_response_can_related_data( BLE_RSP_CMD_VEHIVLE_INFORMATION_SUPPORT_LIST, (uint32)BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL, &client_appl_cmd_rsp_result_notify );
            }
        else
            {
            PRINTF("HandlerCMDResult-BleCmdVehicleInfosSupportList-SUCCESS\r\n");
            }
        break;

    case BLE_REQ_CMD_VEHICLE_INFORMATION_INTERVAL:
        if( E_SUCCESS != client_appl_ble_req_vehicle_information( TRUE, data_size, data ) )
            {
            PRINTF("HandlerCMDResult-BleCmdVehicleInfosInterval-FAILED\r\n");
            client_appl_response_can_related_data( BLE_RSP_CMD_VEHICLE_INFORMATION, (uint32)BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL ,&client_appl_cmd_rsp_result_notify );
            }
        else
            {
            PRINTF("HandlerCMDResult-BleCmdVehicleInfosInterval-SUCCESS\r\n");
            }
        break;

    case BLE_REQ_CMD_FFD:
        if( E_SUCCESS != client_app_ble_req_freeze_frame_data( data_size, data ) )
            {
            PRINTF("HandlerCMDResult-BleCmdFFD-FAILED\r\n");
            client_appl_response_can_related_data( BLE_RSP_CMD_FFD, (uint32)BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL ,&client_appl_cmd_rsp_result_notify );
            }
        else
            {
            PRINTF("HandlerCMDResult-BleCmdFFD-SUCCESS\r\n");
            }
        break;

    default:
    break;
    }
}



/*!******************************************************************************
*
* @public
* Function name: client_appl_check_ble_command
* parameter: diagnstic_is_enbale
* Description  : this function will get a new command from command queue
* note: this function should callback periodly when diagnsostic function is disable or current
 diagnostic is idle
*********************************************************************************/
void client_appl_check_ble_command
    (
    boolean diagnstic_is_enbale
    )
{
ble_command_type* ble_command_ptr = NULL;
ble_command_ptr = client_ble_cmd_pull_queue();

if( FALSE == diagnstic_is_enbale )
    {
    return;
    }
else
    {
    if( NULL != ble_command_ptr )
        {
        set_client_app_cmd_rsp_state( CMD_RSP_IDLE );
        client_appl_ble_req_command_dispatch( ble_command_ptr->ble_command, ble_command_ptr->data_length, ble_command_ptr->command_data );
        }
    else
        {
        /*do nothing*/
        }
    }
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_ble_rsp_request_support_monitor_list
* Description  : this function get support monitor id list and transmit to upper layer
*********************************************************************************/
static void client_appl_ble_rsp_request_support_monitor_list
    (
    void
    )
{
uint8 index = 0x00;
uint16 server_code = 0x0000;
uint32* data_ptr = &response_support_monitor_data_id_list[BYTE_NUM_1];
uint8 data_length = 0x00;
uint8 server_id = 0;
uint8 monitor_id = 0;
uint32 resp_data_len = 0;

/*Clear the list*/
g_McServerListResponse_server_list.count = 0;

for( index = 0; index < SUPPORT_MONITOR_COUNT; index++ )
        {
        if( TRUE == read_local_monitor_infos.support_id_received_flag_array[index] )
            {
            monitor_id = support_monitor_data_id_list[index];
            McServerListResponse_server_list_add_server( &g_McServerListResponse_server_list, monitor_id );
            }
        }

if( 0 == g_McServerListResponse_server_list.count )
    {
    client_appl_response_can_related_data( BLE_RSP_CMD_VEHIVLE_INFORMATION_SUPPORT_LIST, BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL , &client_appl_cmd_rsp_result_notify );
    }
else
    {
    resp_data_len = Gen_McServerListResponse( &g_McServerListResponse_server_list, McServerListResponse_protobuf, sizeof( McServerListResponse_protobuf ) );
    if( 0 != resp_data_len )
        {
        client_appl_response_can_related_data( BLE_RSP_CMD_VEHIVLE_INFORMATION_SUPPORT_LIST, resp_data_len, McServerListResponse_protobuf , &client_appl_cmd_rsp_result_notify );
        }
    else
        {
        client_appl_response_can_related_data( BLE_RSP_CMD_VEHIVLE_INFORMATION_SUPPORT_LIST, BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL , &client_appl_cmd_rsp_result_notify );
        }
    }
}




/*!******************************************************************************
*
* @public
* Function name: client_appl_cmd_rsp_result_notify
* Description  : this function will reset data storage zone
* Usage: Callback function by upper layer when upper layer transmit data finished
*********************************************************************************/
void client_appl_cmd_rsp_result_notify
    (
    const uint8 vlaue
    )
{
client_process_flow_type process_flow = client_get_current_process_flow();


if( CMD_RSP_PROCESSING != get_client_app_cmd_rsp_state() )
    {
    return;
    }

set_client_app_cmd_rsp_state( CMD_RSP_DONE );


#if 0
switch( process_flow )
    {
    case PROCESS_FLOW_DETECT_SERVER:
        (void)memset( connected_server_list, 0x00, sizeof(connected_server_list) );
        set_client_app_cmd_rsp_state( CMD_RSP_DONE );
        break;

    case PROCESS_FLOW_INIT_RDTCBS:
        if( TRUE == read_dtc_infos.is_storge_init_dtc )
            {
            client_mem_reset_data();
            }
        set_client_app_cmd_rsp_state( CMD_RSP_DONE );
        break;

    case PROCESS_FLOW_RDBCID:
    case PROCESS_FLOW_MARKET:
    case PROCESS_FLOW_MONITOR:
    case PROCESS_FLOW_RFFD:
        client_mem_reset_data();

        break;

    default:
        set_client_app_cmd_rsp_state( CMD_RSP_IDLE );
        break;
    }
#endif
}


static void client_appl_send_protobuf_data_success
    (
    void
    )
{
uint8 connect_server_id = 0xFF;
uint16 resp_cmd = 0;
uint32 resp_data_len = 0;
client_process_flow_type current_flow = client_get_current_process_flow();
uint32 server_code = 0;

switch( current_flow )
    {
    case PROCESS_FLOW_INIT_RDTCBS:
        resp_cmd = BLE_RSP_CMD_MALFUNCTION;
        if( 0 == g_McMalfunctionResponse_list.count )
            {
            client_appl_response_can_related_data( resp_cmd, BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL , &client_appl_cmd_rsp_result_notify );
            }
        else
            {
            resp_data_len = Gen_McMalfunctionResponse( &g_McMalfunctionResponse_list, McMalfunctionResponse_protobuf, sizeof( McMalfunctionResponse_protobuf ) );
            if( 0 == resp_data_len )
                {
                client_appl_response_can_related_data( resp_cmd, BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL , &client_appl_cmd_rsp_result_notify );
                }
            else
                {
                client_appl_response_can_related_data( resp_cmd, resp_data_len, McMalfunctionResponse_protobuf , &client_appl_cmd_rsp_result_notify );
                }
             /*reset array*/
             g_McMalfunctionResponse_list.count = 0;
            }
        break;

    case PROCESS_FLOW_RDBCID:
        resp_cmd = BLE_RSP_CMD_VEHICLE_IDENTIFICATION;
    case PROCESS_FLOW_MARKET:
        resp_cmd = BLE_RSP_CMD_MARKET_DATA;
        if( 0 == g_IdDataList.count )
            {
            client_appl_response_can_related_data( resp_cmd, BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL , &client_appl_cmd_rsp_result_notify );
            }
        else
            {
            connect_server_id = get_current_connect_server_id();
            server_code = client_appl_ble_server_code_mapping[connect_server_id].ble_server_code ;

            resp_data_len = Gen_McVehicleIdentificationResponse( server_code, &g_IdDataList, McVehicleIdentificationResponse_protobuf,sizeof( McVehicleIdentificationResponse_protobuf ) );
            if( 0 == resp_data_len )
                {
                client_appl_response_can_related_data( resp_cmd, BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL , &client_appl_cmd_rsp_result_notify );
                }
            else
                {
                client_appl_response_can_related_data( resp_cmd, resp_data_len, McMalfunctionResponse_protobuf , &client_appl_cmd_rsp_result_notify );
                }
             /*reset array*/
             g_McMalfunctionResponse_list.count = 0;
            }
    break;

    case PROCESS_FLOW_MONITOR:
        if( TRUE == read_local_monitor_infos.is_request_support_list_flow )
            {
            resp_cmd = BLE_RSP_CMD_VEHIVLE_INFORMATION_SUPPORT_LIST;
            if( 0 == g_McLocalRecordVehicleInformationSupportIdListResponse_id_list.count )
                {
                client_appl_response_can_related_data( resp_cmd, BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL , &client_appl_cmd_rsp_result_notify );
                }
            else
                {
                connect_server_id = get_current_connect_server_id();
                server_code = client_appl_ble_server_code_mapping[connect_server_id].ble_server_code ;
                resp_data_len = Gen_McLocalRecordVehicleInformationSupportIdListResponse( server_code, &g_McLocalRecordVehicleInformationSupportIdListResponse_id_list, McLocalRecordVehicleInformationSupportIdListResponse_protobuf, sizeof( McLocalRecordVehicleInformationSupportIdListResponse_protobuf ) );
                if( 0 == resp_data_len )
                    {
                    client_appl_response_can_related_data( resp_cmd, BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL , &client_appl_cmd_rsp_result_notify );
                    }
                else
                    {
                    client_appl_response_can_related_data( resp_cmd, resp_data_len, McLocalRecordVehicleInformationSupportIdListResponse_protobuf , &client_appl_cmd_rsp_result_notify );
                    }
                }
            g_McLocalRecordVehicleInformationSupportIdListResponse_id_list.count = 0;
            }
        else
            {
            resp_cmd = BLE_RSP_CMD_VEHICLE_INFORMATION;
            if( 0 == g_IdDataList.count )
                {
                client_appl_response_can_related_data( resp_cmd, BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL , &client_appl_cmd_rsp_result_notify );
                }
            else
                {
                connect_server_id = get_current_connect_server_id();
                server_code = client_appl_ble_server_code_mapping[connect_server_id].ble_server_code ;

                resp_data_len = Gen_McVehicleIdentificationResponse( server_code, &g_IdDataList, McVehicleIdentificationResponse_protobuf,sizeof( McVehicleIdentificationResponse_protobuf ) );
                if( 0 == resp_data_len )
                    {
                    client_appl_response_can_related_data( resp_cmd, BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL , &client_appl_cmd_rsp_result_notify );
                    }
                else
                    {
                    client_appl_response_can_related_data( resp_cmd, resp_data_len, McMalfunctionResponse_protobuf , &client_appl_cmd_rsp_result_notify );
                    }
                 /*reset array*/
                 g_McMalfunctionResponse_list.count = 0;
                }
            }

    break;

    case PROCESS_FLOW_RFFD:
        resp_cmd = BLE_RSP_CMD_FFD;

        if( 0 == g_McFfdResponse_data_list.count )
            {
            client_appl_response_can_related_data( resp_cmd, BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL , &client_appl_cmd_rsp_result_notify );
            }
        else
            {
            connect_server_id = get_current_connect_server_id();
            server_code = client_appl_ble_server_code_mapping[connect_server_id].ble_server_code ;

            resp_data_len =  Gen_McFfdResponse( server_code, &g_McFfdResponse_data_list, McFfdResponse_protobuf, sizeof( McFfdResponse_protobuf ) );
            if( 0 == resp_data_len )
                {
                client_appl_response_can_related_data( resp_cmd, BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL , &client_appl_cmd_rsp_result_notify );
                }
            else
                {
                client_appl_response_can_related_data( resp_cmd, resp_data_len, McFfdResponse_protobuf , &client_appl_cmd_rsp_result_notify );
                }
            /*reset array*/
            g_McFfdResponse_data_list.count = 0;
            }
    break;
    }
}


/*!******************************************************************************
*
* @public
* Function name: client_appl_send_protobuf_failed_data
* Description  : this function send notify to upper layer when current process flow execute failed
*********************************************************************************/
static void client_appl_send_protobuf_failed_data
    (
    client_process_flow_type process_flow
    )
{
uint16 resp_command = 0;

switch( process_flow )
    {
    case PROCESS_FLOW_INIT_RDTCBS:
        resp_command = BLE_RSP_CMD_MALFUNCTION;
        break;

    case PROCESS_FLOW_RDBCID:
        resp_command = BLE_RSP_CMD_VEHICLE_IDENTIFICATION;
        break;

    case PROCESS_FLOW_MARKET:
        resp_command = BLE_RSP_CMD_MARKET_DATA;
        break;

    case PROCESS_FLOW_MONITOR:
        if( TRUE == read_local_monitor_infos.is_request_support_list_flow )
            {
            resp_command = BLE_RSP_CMD_VEHIVLE_INFORMATION_SUPPORT_LIST;
            }
        else
            {
            resp_command = BLE_RSP_CMD_VEHICLE_INFORMATION;
            }
        break;

    case PROCESS_FLOW_RFFD:
        resp_command = BLE_RSP_CMD_FFD;
        break;

    default:
        return;
        break;
    }
    client_appl_response_can_related_data( resp_command, BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL , &client_appl_cmd_rsp_result_notify );

}

/**************************Dividing line***************************/
/********************For server detect*****************************/
 /*!******************************************************************************
 *
 * @public
 * Function name: client_appl_detect_connected_server_handler_5ms
 * Description  : this function will send request message and send final result to
                 upper layer when handle process flow detect server list--default session
 * usage        : called by client_diag_main_funciton_5ms
 *********************************************************************************/
static void  client_appl_detect_connected_server_handler_5ms
    (
    void
    )
{
uint8 index = 0x00;

switch( server_detect_step )
    {
    case SERVER_DETECT_INIT:
        server_detect_step = SERVER_DETECT_REQ;
        break;

    case SERVER_DETECT_REQ:
        client_dcm_req_diagnostic_default_session_functional();
        server_detect_step = SERVER_DETECT_WAIT;
        break;

    case SERVER_DETECT_WAIT:
        /*wait server response*/
        break;

    case SERVER_DETECT_DEFAULT_DONE:
        /*get connect server amount and send data to APP*/
        for( index = 0x00; index < SUPPORT_SERVER_NUM; index++ )
            {
            if( SERVER_CONNECT == server_list_detect_infos[index].server_connect_status_default )
                {
                default_server_list_detect_amount++;
                #if(APPL_DEBUG)
                PRINTF("Client detect channel %d servers-default session\r\n", index );
                #endif
                }
            }

        /*continue to detect all server`s DTC when connected server*/
        if( 0x00 < default_server_list_detect_amount )
            {
            #if(APPL_DEBUG)
             PRINTF("Client detect %d connect servers-default session \r\n\r\n", default_server_list_detect_amount );
             #endif
             if( TRUE == client_appl_get_ble_connected_state() )
                {
                set_client_app_cmd_rsp_state(CMD_RSP_PROCESSING );
                client_appl_ble_rsp_connect_server_list( TRUE );
                server_detect_step = SERVER_DETECT_DEFAULT_TX;
                }
             else
                {
                server_detect_step = SERVER_DETECT_DEFAULT_DONE;
                client_appl_set_current_process_flow_step( PROCESS_FLOW_EXTEND_SERVER );
                }
            }
        else
            {
            if( TRUE == client_appl_get_ble_connected_state() )
                {
                client_appl_ble_rsp_connect_server_list( FALSE );
                }
            client_appl_set_current_process_flow_step( PROCESS_FLOW_IDLE );
            #if(APPL_DEBUG)
            PRINTF(" Client detect No server connected-default session\r\n\r\n");
            #endif
            }

        break;

        case SERVER_DETECT_DEFAULT_TX:
            /*wait data transmit done*/
            if( CMD_RSP_DONE  == get_client_app_cmd_rsp_state() )
                {
                set_client_app_cmd_rsp_state( CMD_RSP_IDLE );
                server_detect_step = SERVER_DETECT_DEFAULT_DONE;
                client_appl_set_current_process_flow_step( PROCESS_FLOW_EXTEND_SERVER );
                }
            break;

        default:
        break;
    }
}


/*!******************************************************************************
*
* @public
* Function name: client_appl_detect_connected_server_positive_response_handler
* Description  : this function process the positive response data when handle hen handle process flow detect server list
* usage        : called by client_diag_response_dispatch_handler_5ms
*********************************************************************************/
static void client_appl_detect_connected_server_positive_response_handler
    (
     uint8* resp_data,
     uint16 resp_lenth,
     uint8 channel_id
    )
{
/*client shall check the response data*/
if( DCM_10h_DEFAULT_ID != resp_data[BYTE_NUM_1] )
    {
    return;
    }

if( SERVER_UN_CONNECT == server_list_detect_infos[channel_id].server_connect_status_default )
    {
    server_list_detect_infos[channel_id].server_connect_status_default = SERVER_CONNECT;
    }
}


/*!******************************************************************************
*
* @public
* Function name: client_appl_detect_connected_server_negative_response_handler
* Description  : this function process the negative response data when handle hen handle process flow detect server list
* usage        : called by fclient_diag_response_dispatch_handler_5ms
*********************************************************************************/
static void client_appl_detect_connected_server_negative_response_handler
    (
    uint8 service_id,
    uint8 nrc,
    uint8 channel_id
    )
{
/*do nothing*/
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_detect_connected_server_response_timeout_notify
* Description  : this function process no data received  when handle hen handle process flow detect server list
* usage        : called by called by fclient_diag_response_dispatch_handler_5ms
*********************************************************************************/
static void client_appl_detect_connected_server_response_timeout_notify
    (
    void
    )
{
server_detect_step = SERVER_DETECT_DEFAULT_DONE;
}


/*!******************************************************************************
*
* @public
* Function name: client_appl_server_detect_req_extend_session_5ms
* Description  : this function will send request message and send final result to
                upper layer when handle process flow detect server list-extend session
* usage        : called by client_diag_main_funciton_5ms
*********************************************************************************/
static void client_appl_server_detect_req_extend_session_5ms
    (
    void
    )
{
uint8 index = 0x00;

switch( detect_connected_server_infos.next_req_dtc_status_frame )
    {
    case REQ_ORIGINAL_FRAME:
    case REQ_RESEND_FRAME:
    case REQ_NRC_RSEND_FRAME:
        client_dcm_req_diagnostic_extend_session( detect_connected_server_infos.connected_server_id );
        detect_connected_server_infos.curr_dtc_status_frame = detect_connected_server_infos.next_req_dtc_status_frame;
        detect_connected_server_infos.next_req_dtc_status_frame = REQ_NO_FRAME;
        break;

    default:
        break;
    }

if( PROCESS_RESULT_INIT != detect_connected_server_infos.process_result )
    {
    if( NO_SERVER_CONNECT == client_appl_get_next_connected_server_id() )
        {
        /*Have been read all detected server*/
        for( index = 0; index < SUPPORT_SERVER_NUM; index++ )
            {
            if( SERVER_CONNECT == server_list_detect_infos[index].server_connect_status_extend )
                {
                extend_server_list_detect_amount++;
                #if(APPL_DEBUG)
                PRINTF("Client detect channel %d servers-extend session\r\n", index );
                #endif
                }
            }

       /*analysis the result*/
        if( 0x00 < extend_server_list_detect_amount )
            {
                /*extend shall not send notify to MOTOCAN -----i think*/
          //  if( TRUE == client_appl_get_ble_connected_state() )
               // {
              //  client_mem_send_can_data();
              //  }
            //client_mem_reset_data();

            /*Enter next process flow*/
            set_current_conncet_server_id( client_appl_get_first_connected_server_id() );
            client_appl_set_current_process_flow_step( PROCESS_FLOW_INIT_RDTCBS );
            #if(APPL_DEBUG)
            PRINTF("Client detect %d connect servers-extend session \r\n\r\n", extend_server_list_detect_amount );
            #endif
            }
        else
            {
            /*Handle all servers and all servers does send positive response*/
            /*client shall enter detect server process flow again and shall not notify to YAMAHA APP*/
            for( index = 0; index < SUPPORT_SERVER_NUM; index++ )
                {
                server_list_detect_infos[index].server_connect_status_default = SERVER_UN_CONNECT;
                server_list_detect_infos[index].server_connect_status_extend = SERVER_UN_CONNECT;
                }
            server_detect_step = SERVER_DETECT_INIT;
            default_server_list_detect_amount = 0x00;
            extend_server_list_detect_amount = 0x00;
            client_appl_set_current_process_flow_step( PROCESS_FLOW_DETECT_SERVER );
            #if(APPL_DEBUG)
            PRINTF(" Client detect No server connected-extend session\r\n\r\n");
            #endif
            }
        }
    else
        {
        /*request the next detected servers*/
        set_current_conncet_server_id( client_appl_get_next_connected_server_id() );
        detect_connected_server_infos.connected_server_id = get_current_connect_server_id();
        detect_connected_server_infos.process_result = PROCESS_RESULT_INIT;
        detect_connected_server_infos.curr_dtc_status_frame = REQ_NO_FRAME;
        detect_connected_server_infos.next_req_dtc_status_frame = REQ_ORIGINAL_FRAME;
        detect_connected_server_infos.nrc_resend_timer = 0x00;
        detect_connected_server_infos.timeout_resend_timer = 0x00;
        }
    }
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_server_detect_req_extend_session_positive_response_handler
* Description  : this function process the positive response data when handle hen handle process flow detect server list
* usage        : called by client_diag_response_dispatch_handler_5ms
*********************************************************************************/
static void client_appl_server_detect_req_extend_session_positive_response_handler
    (
    uint8* resp_data,
    uint16 resp_lenth,
    uint8 channel_id
    )
{
/*client shall check the response data*/
if( DCM_10h_EXTEND_ID != resp_data[BYTE_NUM_1] )
    {
    detect_connected_server_infos.process_result = PROCESS_RESULT_INVALID_DATA;
    return;
    }

switch( detect_connected_server_infos.curr_dtc_status_frame )
    {
    case REQ_ORIGINAL_FRAME:
    case REQ_RESEND_FRAME:
    case REQ_NRC_RSEND_FRAME:
        server_list_detect_infos[channel_id].server_connect_status_extend = SERVER_CONNECT;
        detect_connected_server_infos.process_result = PROCESS_RESULT_SUCCESS;
        break;

    default:
        break;
    }
/*should reset timer when received a positive response*/
detect_connected_server_infos.nrc_resend_timer = 0x00;
detect_connected_server_infos.timeout_resend_timer = 0x00;
}


/*!******************************************************************************
*
* @public
* Function name: client_appl_server_detect_req_extend_session_negative_response_handler
* Description  : this function process the negative response data when handle hen handle process flow detect server list
* usage        : called by fclient_diag_response_dispatch_handler_5ms
*********************************************************************************/
static void client_appl_server_detect_req_extend_session_negative_response_handler
    (
    uint8 service_id,
    uint8 nrc,
    uint8 channel_id
    )
{
switch( detect_connected_server_infos.curr_dtc_status_frame )
    {
    case REQ_ORIGINAL_FRAME:
        if( ( DCM_NRC_GENERAL_REJECT == nrc ) \
            || ( DCM_NRC_SUB_FUNCTION_NOT_SUPPORT == nrc )\
            || ( DCM_NRC_BUSY_REPEAY_REQUEST == nrc )\
            || ( DCM_NRC_CONDITION_NOT_CORRECT == nrc) )
            {
            detect_connected_server_infos.next_req_dtc_status_frame = REQ_NRC_RSEND_FRAME;
            }
         else
            {
            detect_connected_server_infos.process_result = PROCESS_RESULT_NRC_GR;
            }
        break;

    case REQ_RESEND_FRAME:
        detect_connected_server_infos.process_result = PROCESS_RESULT_NRC_GR;
        break;

    case REQ_NRC_RSEND_FRAME:
        if( ( DCM_NRC_GENERAL_REJECT == nrc ) \
            || ( DCM_NRC_SUB_FUNCTION_NOT_SUPPORT == nrc )\
            || ( DCM_NRC_BUSY_REPEAY_REQUEST == nrc )\
            || ( DCM_NRC_CONDITION_NOT_CORRECT == nrc) )
            {
            detect_connected_server_infos.nrc_resend_timer++;
            if( RESEND_MAX_CONUNT <= detect_connected_server_infos.nrc_resend_timer )
                {
                detect_connected_server_infos.process_result = RROCESS_RESULE_RESEND_OVERFLOW;
                }
            else
                {
                detect_connected_server_infos.next_req_dtc_status_frame = REQ_NRC_RSEND_FRAME;
                }
            }
         else
            {
            detect_connected_server_infos.process_result = PROCESS_RESULT_NRC_GR;
            }
        break;

    default:
        break;
    }
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_server_detect_req_extend_session_timeout_notify
* Description  : this function process no data received  when handle hen handle process flow detect server list
* usage        : called by called by fclient_diag_response_dispatch_handler_5ms
*********************************************************************************/
static void client_appl_server_detect_req_extend_session_timeout_notify
    (
    void
    )
{
switch( detect_connected_server_infos.curr_dtc_status_frame )
    {
    case REQ_ORIGINAL_FRAME:
        detect_connected_server_infos.next_req_dtc_status_frame = REQ_RESEND_FRAME;
        break;

    case REQ_RESEND_FRAME:
        detect_connected_server_infos.timeout_resend_timer++;
        if( RESEND_MAX_CONUNT <= detect_connected_server_infos.timeout_resend_timer )
            {
            detect_connected_server_infos.process_result = RROCESS_RESULE_RESEND_OVERFLOW;
            }
        else
            {
            detect_connected_server_infos.next_req_dtc_status_frame = REQ_RESEND_FRAME;
            }
        break;

    case REQ_NRC_RSEND_FRAME:
        detect_connected_server_infos.next_req_dtc_status_frame = PROCESS_RESULT_TIMEOUT;
        break;

    default:
        break;
    }
}


/*for read dtc status*/

/*!******************************************************************************
*
* @public
* Function name: client_appl_read_initial_dtc_frame_status_change
* Description  : state switch
*********************************************************************************/
static void client_appl_read_initial_dtc_frame_status_change
    (
    void
    )
{
read_dtc_infos.curr_dtc_status_frame = read_dtc_infos.next_req_dtc_status_frame;
read_dtc_infos.next_req_dtc_status_frame = REQ_NO_FRAME;
}


/*!******************************************************************************
*
* @public
* Function name: client_appl_calc_storage_init_dtc_state
* Description  : calculate the initial DTC data storage state according the memory state
*********************************************************************************/
static void client_appl_calc_storage_init_dtc_state
    (
    void
    )
{
uint8 index = 0x00;

if( !read_dtc_infos.is_storge_init_dtc )
    {
    for( ; index < SUPPORT_SERVER_NUM; index++ )
        {
        read_dtc_infos.is_storge_init_dtc |= client_mem_get_storage_init_dtc_state( index );
        }
    }

/*LC think read initial data is finished when all request servers does response any data*/
read_dtc_infos.is_storge_init_dtc = TRUE;
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_get_storage_init_dtc_state
* Description  : get the current storage initial DTC data state
* Usage: This function will be used by client_mem to determine which memory area to choose
*********************************************************************************/
boolean client_appl_get_storage_init_dtc_state
    (
    void
    )
{
return read_dtc_infos.is_storge_init_dtc;
}





/*!******************************************************************************
*
* @public
* Function name: client_appl_req_initial_dtc_status_handler_5ms
* Description  : this function will send request message and send final result to
                 upper layer when handle process flow Read_DTC_infos
* usage        : period callback
*********************************************************************************/



static void client_appl_req_initial_dtc_status_handler_5ms
    (
    void
    )
{
uint32 server_code = 0;
uint32 resp_data_len = 0;

switch( read_dtc_infos.next_req_dtc_status_frame )
    {
    case REQ_NO_FRAME:
        /*do nothing*/
        break;

    case REQ_ORIGINAL_FRAME:
        if( FALSE == read_dtc_infos.is_storge_init_dtc )
            {
            /*if initial DTC is not storage ,STADTC is set as A1*/
            read_dtc_infos.current_STADTC = DCM_18h_INIT_STADTC;
            }
        client_dcm_req_read_dtc_status_code( read_dtc_infos.connected_server_id, read_dtc_infos.current_STADTC );
        client_appl_read_initial_dtc_frame_status_change();
        break;

    case REQ_DEFAULT_SESSION_FRAME:
        /*The received flow for a function address is end with timeout*/
        /*Wait fucntionl address request timeout*/
        client_appl_set_delay_timer( DCMM_APP_DELAY_100_MS );
        client_dcm_req_diagnostic_default_session_functional();
        client_appl_read_initial_dtc_frame_status_change();
        break;

    case REQ_EXTEND_SESSION_FRAME:
        client_dcm_req_diagnostic_extend_session( read_dtc_infos.connected_server_id );
        client_appl_read_initial_dtc_frame_status_change();
        break;

    case REQ_RESEND_FRAME:
        /*if initial DTC is not storage ,STADTC is set as A1*/
        /*when received a STADTC from upper layer,STADTC is set as defined value*/
        client_dcm_req_read_dtc_status_code( read_dtc_infos.connected_server_id, read_dtc_infos.current_STADTC );
        client_appl_read_initial_dtc_frame_status_change();
        break;

        default:
            /* do nothing */
            break;
    }


if( PROCESS_RESULT_INIT != read_dtc_infos.process_result )
    {
    if( FALSE == read_dtc_infos.is_storge_init_dtc )
        {
        /*Have been request all connected server initial diagnostic trouble code data*/
        if( NO_SERVER_CONNECT == client_appl_get_next_connected_server_id() )
            {
            /*Check if there is data storage*/
            client_appl_calc_storage_init_dtc_state();
            client_appl_set_current_process_flow_step( PROCESS_FLOW_IDLE );
            }
        else
            {
            client_appl_set_current_process_flow_step( PROCESS_FLOW_INIT_RDTCBS );
            set_current_conncet_server_id( client_appl_get_next_connected_server_id() );
            read_dtc_infos.connected_server_id = get_current_connect_server_id();
            }
        }
    else
        {
        /*shall send the process result and data to upper layer whether process is success*/
        if( is_client_app_cmd_rsp_state( CMD_RSP_IDLE ) )
            {
            #if (APPL_DEBUG )
            client_appl_debug_printf( read_dtc_infos.process_result );
            #endif

            if( PROCESS_RESULT_END == read_dtc_infos.process_result )
                {
                server_code =  client_appl_ble_server_code_mapping[read_dtc_infos.connected_server_id].ble_server_code ;
                if( 0 == g_McMalfunctionResponse_list.count )
                    {
                    client_appl_response_can_related_data( BLE_RSP_CMD_MALFUNCTION, BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL , &client_appl_cmd_rsp_result_notify );
                    }
                else
                    {
                    resp_data_len = Gen_McMalfunctionResponse( &g_McMalfunctionResponse_list, McMalfunctionResponse_protobuf, sizeof( McMalfunctionResponse_protobuf ) );
                    if( 0 == resp_data_len )
                        {
                        client_appl_response_can_related_data( BLE_RSP_CMD_MALFUNCTION, BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL , &client_appl_cmd_rsp_result_notify );
                        }
                    else
                        {
                        client_appl_response_can_related_data( BLE_RSP_CMD_MALFUNCTION, resp_data_len, McMalfunctionResponse_protobuf , &client_appl_cmd_rsp_result_notify );
                        }
                     /*reset array*/
                     g_McMalfunctionResponse_list.count = 0;
                    }
                }
            else
                {
                client_appl_send_protobuf_failed_data( PROCESS_FLOW_INIT_RDTCBS );
                client_appl_set_current_process_flow_step( PROCESS_FLOW_IDLE );
                }
            }
        else if( is_client_app_cmd_rsp_state( CMD_RSP_DONE ) )
            {
            set_client_app_cmd_rsp_state( CMD_RSP_IDLE );
            if( TRUE == read_dtc_infos.is_cycle_transmission )
                {
                g_McMalfunctionResponse_list.count = 0;
                client_appl_set_delay_timer( read_dtc_infos.cycle_tarns_interval_time );
                read_dtc_infos.curr_dtc_status_frame = REQ_NO_FRAME;
                read_dtc_infos.next_req_dtc_status_frame = REQ_ORIGINAL_FRAME;
                read_dtc_infos.receive_SNS_timer = 0x00;
                read_dtc_infos.resend_timer = 0x00;
                read_dtc_infos.process_result = PROCESS_RESULT_INIT;
                }
            else
                {
                client_appl_set_current_process_flow_step( PROCESS_FLOW_IDLE );
                }
            }
        else
            {
            /*do nothing*/
            }
        }
    }
}


/*!******************************************************************************
*
* @public
* Function name: client_appl_read_initial_dtc_status_positive_response_handler
* Description  : this function process the positive response data when handle hen handle process flow Read_DTC_infos
* usage        : called by client_diag_response_dispatch_handler_5ms
*********************************************************************************/
static void client_appl_read_initial_dtc_status_positive_response_handler
(
 uint8 * resp_data,
 uint16 resp_lenth,
 uint8 channel_id
)
{
uint8 index = 0;
uint8 dtc_number = 0;
uint8 connect_server_id = 0xFF;
uint32 server_code = 0;
uint8* start_addr = NULL;
uint8 dtc_code = 0;
if( channel_id != read_dtc_infos.connected_server_id )
    {
    return;
    }

if( 2 >= resp_lenth )
    {
    read_dtc_infos.process_result = PROCESS_RESULT_INVALID_DATA;
    }

switch( read_dtc_infos.curr_dtc_status_frame )
    {
    case REQ_ORIGINAL_FRAME:
    case REQ_RESEND_FRAME:
        if( FALSE == read_dtc_infos.is_storge_init_dtc )
            {
            client_mem_storage_init_dtc_data( connect_server_id, resp_lenth,  resp_data );
            }
        else
            {
            /*Clear the list*/
            g_McMalfunctionResponse_list.count = 0;
            /*postive resposne data foramt */
            /*  1 bytes SID  + n #DTC     + n *(2 bytes DTC + 1 bytes status)*/
            dtc_number = resp_data[BYTE_NUM_1];

            connect_server_id = get_current_connect_server_id();
            server_code = client_appl_ble_server_code_mapping[connect_server_id].ble_server_code ;

            if( ( 0 == dtc_number ) && ( 0x02 == resp_lenth ) )
                {
                McMalfunctionResponse_list_add_data( &g_McMalfunctionResponse_list, server_code, 0x0000, read_dtc_infos.current_STADTC );
                }
            else if( resp_lenth == 3* dtc_number + 2 )
                {
                for( index = 0; index < dtc_number; index++ )
                    {
                    start_addr = resp_data + 2 + (dtc_number -1 )* 3;
                    if( read_dtc_infos.current_STADTC == start_addr[2] )
                        {
                        dtc_code = byte_merge_u16( start_addr );
                         McMalfunctionResponse_list_add_data( &g_McMalfunctionResponse_list, server_code, dtc_code, read_dtc_infos.current_STADTC );
                        }
                    }
                }
            else
                {
                read_dtc_infos.process_result = PROCESS_RESULT_INVALID_DATA;
                }
            }
        read_dtc_infos.process_result = PROCESS_RESULT_END;
        break;

    case REQ_DEFAULT_SESSION_FRAME:
        if( DCM_10h_DEFAULT_ID == resp_data[BYTE_NUM_1] )
            {
            read_dtc_infos.next_req_dtc_status_frame = REQ_EXTEND_SESSION_FRAME;
            }
        else
            {
            read_dtc_infos.process_result = PROCESS_RESULT_INVALID_DATA;
            }
        break;

    case REQ_EXTEND_SESSION_FRAME:
        if( DCM_10h_EXTEND_ID == resp_data[BYTE_NUM_1] )
            {
            read_dtc_infos.next_req_dtc_status_frame = REQ_ORIGINAL_FRAME;
            }
        else
            {
            read_dtc_infos.process_result = PROCESS_RESULT_INVALID_DATA;
            }
        break;

    default:
        break;
    }
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_read_initial_dtc_status_negative_response_handler
* Description  : this function process the negative response data when handle hen handle process flow Read_DTC_infos
* usage        : called by fclient_diag_response_dispatch_handler_5ms
*********************************************************************************/
static void client_appl_read_initial_dtc_status_negative_response_handler
(
uint8 service_id,
uint8 nrc,
uint8 channel_id
)
{
if( channel_id != read_dtc_infos.connected_server_id )
    {
    return;
    }

switch( read_dtc_infos.curr_dtc_status_frame )
    {
    case REQ_ORIGINAL_FRAME:
        if( DCM_NRC_SERVICE_NOT_SUPPORT == nrc )/*0x11*/
            {
            read_dtc_infos.receive_SNS_timer++;
            if( REC_MAX_SNS <= read_dtc_infos.receive_SNS_timer )
                {
                read_dtc_infos.process_result = PROCESS_RESULT_NRC_SNS;
                }
            else
                {
                read_dtc_infos.next_req_dtc_status_frame = REQ_DEFAULT_SESSION_FRAME;
                }
            }
        else if( DCM_NRC_GENERAL_REJECT == nrc \
                || DCM_NRC_SUB_FUNCTION_NOT_SUPPORT == nrc
                || DCM_NRC_BUSY_REPEAY_REQUEST == nrc
                || DCM_NRC_CONDITION_NOT_CORRECT == nrc )
            {
            read_dtc_infos.process_result = PROCESS_RESULT_NRC_GR;
            }
        else
            {
            read_dtc_infos.process_result = PROCESS_RESULT_NRC_GR;
            }
        break;

    case REQ_DEFAULT_SESSION_FRAME:
    case REQ_EXTEND_SESSION_FRAME:
    case REQ_RESEND_FRAME:
        read_dtc_infos.process_result = PROCESS_RESULT_NRC_GR;
        break;

    default:
        break;
    }
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_read_initial_dtc_status_timeout_notify
* Description  : this function process no data received  when handle hen handle process flow Read_DTC_infos
* usage        : called by called by fclient_diag_response_dispatch_handler_5ms
*********************************************************************************/
static void client_appl_read_initial_dtc_status_timeout_notify
    (
    void
    )
{
switch( read_dtc_infos.curr_dtc_status_frame )
    {
    case REQ_ORIGINAL_FRAME:
        read_dtc_infos.next_req_dtc_status_frame = REQ_RESEND_FRAME;
        break;

    case REQ_DEFAULT_SESSION_FRAME:
        /*Request default sesson within function address*/
        /*The actual received end with timeout*/
        /*So the next req frame will be extend frame when have been received a positive resonse fot current channenl*/
        if( REQ_EXTEND_SESSION_FRAME != read_dtc_infos.next_req_dtc_status_frame )
            {
            read_dtc_infos.process_result = PROCESS_RESULT_NRC_GR;
            }
        else
            {
            /*do nothing*/
            }
        client_appl_clear_delay_timer();
        break;

    case REQ_EXTEND_SESSION_FRAME:
        read_dtc_infos.process_result = PROCESS_RESULT_NRC_GR;
        break;

    case REQ_RESEND_FRAME:
        read_dtc_infos.resend_timer++;
        if( RESEND_MAX_CONUNT > read_dtc_infos.resend_timer )
            {
            read_dtc_infos.next_req_dtc_status_frame = REQ_RESEND_FRAME;
            }
        else
            {
            read_dtc_infos.process_result = RROCESS_RESULE_RESEND_OVERFLOW;
            }
        break;

    default:
        break;
    }
}


static void client_appl_request_status_change
    (
    void
    )
{
read_common_identifier_infos.curr_req_frame = read_common_identifier_infos.next_req_frame;
read_common_identifier_infos.next_req_frame = REQ_NO_FRAME;;
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_read_data_by_common_identifier_handler_5ms
* Description  : this function will send request message and send final result to
                 upper layer when handle process flow Read_Common_Id
* usage        : period callback
*********************************************************************************/
static void client_appl_read_data_by_common_identifier_handler_5ms
    (
    void
    )
{
uint8 connect_channel_id  = 0xFF;
uint16 common_identifier = 0x0000;
uint32 server_code = 0;
uint32 resp_data_len = 0;

switch( read_common_identifier_infos.next_req_frame )
    {
    case REQ_ORIGINAL_FRAME:
        common_identifier = read_common_identifier_infos.common_id_list[read_common_identifier_infos.current_common_data_index];
        client_dcm_req_common_indentifier( read_common_identifier_infos.connected_server_id, common_identifier );
        client_appl_request_status_change();
        break;

    case REQ_DEFAULT_SESSION_FRAME:
        /*The received flow for a function address is end with timeout*/
        /*Wait fucntionl address request timeout*/
        client_appl_set_delay_timer( DCMM_APP_DELAY_100_MS );
        client_dcm_req_diagnostic_default_session_functional();
        client_appl_request_status_change();
        break;

    case REQ_EXTEND_SESSION_FRAME:
        client_dcm_req_diagnostic_extend_session( read_common_identifier_infos.connected_server_id );
        client_appl_request_status_change();
        break;
    case REQ_RESEND_FRAME:
        common_identifier = read_common_identifier_infos.common_id_list[read_common_identifier_infos.current_common_data_index];
        client_dcm_req_common_indentifier( read_common_identifier_infos.connected_server_id, common_identifier );
        client_appl_request_status_change();
        break;

    default:
        break;
    }

/*shall send the process result to upper layer whether process is success*/
/*shall re-initial related status flags*/
/*shall set the next process flow*/
if( PROCESS_RESULT_INIT != read_common_identifier_infos.process_result )
    {
    if( read_common_identifier_infos.current_common_data_index != ( read_common_identifier_infos.common_data_amount - 1 ) )
        {
        /*go on request the next common identifier data*/
        read_common_identifier_infos.current_common_data_index++;
        read_common_identifier_infos.process_result = PROCESS_RESULT_INIT;
        read_common_identifier_infos.next_req_frame = REQ_ORIGINAL_FRAME;
        read_common_identifier_infos.curr_req_frame = REQ_NO_FRAME;
        read_common_identifier_infos.receive_SNS_timer = 0x00;
        read_common_identifier_infos.resend_timer = 0x00;
        }
    else
        {
        if( is_client_app_cmd_rsp_state( CMD_RSP_IDLE ) )
            {
            if( 0 != g_IdDataList.count )
                {
                connect_channel_id = get_current_connect_server_id();
                server_code = client_appl_ble_server_code_mapping[connect_channel_id].ble_server_code ;
                resp_data_len = Gen_McVehicleIdentificationResponse( server_code, &g_IdDataList,McVehicleIdentificationResponse_protobuf,sizeof( McVehicleIdentificationResponse_protobuf ) );
                if( 0 == resp_data_len )
                    {
                    client_appl_send_protobuf_failed_data( PROCESS_FLOW_RDBCID );
                    }
                else
                    {
                    client_appl_response_can_related_data( BLE_RSP_CMD_VEHICLE_IDENTIFICATION, resp_data_len, McVehicleIdentificationResponse_protobuf , &client_appl_cmd_rsp_result_notify );
                    }
                }
            else
                {
                client_appl_send_protobuf_failed_data( PROCESS_FLOW_RDBCID );
                }
            }
        else if( is_client_app_cmd_rsp_state( CMD_RSP_DONE ) )
            {
            set_client_app_cmd_rsp_state( CMD_RSP_IDLE );
            client_appl_set_current_process_flow_step(PROCESS_FLOW_IDLE);
            }
        else
            {
            /*do nothing*/
            }
        }
    }
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_read_data_by_common_indentifier_postive_response_handler
* Description  : this function process the positive response data when handle hen handle process flow Read_Common
* usage        : called by client_diag_response_dispatch_handler_5ms
*********************************************************************************/
static void client_appl_read_data_by_common_identifier_positive_response_handler
(
 uint8 * resp_data,
 uint16 resp_lenth,
 uint8 channel_id
)
{
uint8 connect_server_id = 0;
uint16 resp_identifier = 0x0000;
uint32 resp_swap_id_u32 = 0;
uint32 server_code = 0;

if( channel_id != read_common_identifier_infos.connected_server_id )
    {
    return;
    }

if( 3 >= resp_lenth )
    {
    read_common_identifier_infos.process_result = PROCESS_RESULT_INVALID_DATA;
    return;
    };

switch( read_common_identifier_infos.curr_req_frame )
    {
    case REQ_ORIGINAL_FRAME:
    case REQ_RESEND_FRAME:
         resp_identifier = (uint16)( resp_data[BYTE_NUM_1] << 8 | resp_data[BYTE_NUM_2] );
         if( resp_identifier == read_common_identifier_infos.common_id_list[read_common_identifier_infos.current_common_data_index] )
            {
            IdDataList_add_IdData( &g_IdDataList, (uint32)resp_identifier, ( resp_data + 3 ), (uint32)(resp_lenth - 3 ) );
            read_common_identifier_infos.process_result = PROCESS_RESULT_SUCCESS;
            }
         else
            {
            read_common_identifier_infos.process_result = PROCESS_RESULT_INVALID_DATA;
            }
        break;

    case REQ_DEFAULT_SESSION_FRAME:
        if( DCM_10h_DEFAULT_ID == resp_data[BYTE_NUM_1] )
            {
            read_common_identifier_infos.next_req_frame = REQ_EXTEND_SESSION_FRAME;
            }
        else
            {
            read_common_identifier_infos.process_result = PROCESS_RESULT_INVALID_DATA;
            }
        break;

    case REQ_EXTEND_SESSION_FRAME:
        if( DCM_10h_EXTEND_ID == resp_data[BYTE_NUM_1] )
            {
            read_common_identifier_infos.next_req_frame = REQ_ORIGINAL_FRAME;
            }
        else
            {
            read_common_identifier_infos.process_result = PROCESS_RESULT_INVALID_DATA;
            }
        break;

    default:
        break;
    }
}


/*!******************************************************************************
*
* @public
* Function name: client_appl_read_data_by_common_indentifier_negative_response_handler
* Description  : this function process the negative response data when handle hen handle process flow Read_Comon_Id
* usage        : called by fclient_diag_response_dispatch_handler_5ms
*********************************************************************************/
static void client_appl_read_data_by_common_identifier_negative_response_handler
(
uint8 service_id,
uint8 nrc,
uint8 channel_id
)
{
if( channel_id != read_common_identifier_infos.connected_server_id )
    {
    return;
    }

switch( read_common_identifier_infos.curr_req_frame )
    {
    case REQ_ORIGINAL_FRAME:
        if( DCM_READ_COMMON_INDENTIFIER != service_id )
            {
            return;
            }

        if( DCM_NRC_SERVICE_NOT_SUPPORT == nrc )/*0x11*/
            {
            read_common_identifier_infos.receive_SNS_timer++;
            if( REC_MAX_SNS <= read_common_identifier_infos.receive_SNS_timer )
                {
                read_common_identifier_infos.process_result = PROCESS_RESULT_NRC_SNS;
                }
            else
                {
                read_common_identifier_infos.next_req_frame = REQ_DEFAULT_SESSION_FRAME;
                }
            }
        else if( DCM_NRC_GENERAL_REJECT == nrc \
                || DCM_NRC_SUB_FUNCTION_NOT_SUPPORT == nrc
                || DCM_NRC_BUSY_REPEAY_REQUEST == nrc
                || DCM_NRC_CONDITION_NOT_CORRECT == nrc )
            {
            read_common_identifier_infos.process_result = PROCESS_RESULT_NRC_GR;
            }
        else
            {
            read_common_identifier_infos.process_result = PROCESS_RESULT_INVALID_DATA;
            }
        break;

    case REQ_DEFAULT_SESSION_FRAME:
    case REQ_EXTEND_SESSION_FRAME:
    case REQ_RESEND_FRAME:
        read_common_identifier_infos.process_result = PROCESS_RESULT_NRC_GR;
        break;

    default:
        break;
    }
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_read_data_by_common_indentifier_timeout_notify
* Description  : this function process no data received  when handle hen handle process flow Read_Common_Id
* usage        : called by called by fclient_diag_response_dispatch_handler_5ms
*********************************************************************************/
static void client_appl_read_data_by_common_identifier_timeout_notify
    (
    void
    )
{
switch( read_common_identifier_infos.curr_req_frame )
    {
    case REQ_ORIGINAL_FRAME:
        read_common_identifier_infos.next_req_frame = REQ_RESEND_FRAME;
        break;

    case REQ_DEFAULT_SESSION_FRAME:
        /*Request default sesson within function address*/
        /*The actual received end with timeout*/
        /*So the next req frame will be extend frame when have been received a positive resonse fot current channenl*/
        if( REQ_EXTEND_SESSION_FRAME != read_common_identifier_infos.next_req_frame )
            {
            read_common_identifier_infos.process_result = PROCESS_RESULT_NRC_GR;
            }
        else
            {
            /*do nothing*/
            }
        client_appl_clear_delay_timer();
        break;

    case REQ_EXTEND_SESSION_FRAME:
        read_common_identifier_infos.process_result = PROCESS_RESULT_NRC_GR;
        break;

    case REQ_RESEND_FRAME:
       read_common_identifier_infos.resend_timer++;
       if( RESEND_MAX_CONUNT > read_common_identifier_infos.resend_timer )
             {
             read_common_identifier_infos.next_req_frame = REQ_RESEND_FRAME;
             }
        else
             {
             read_common_identifier_infos.process_result = RROCESS_RESULE_RESEND_OVERFLOW;
             }
        break;

    default:
        break;
    }
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_read_data_by_local_indentifier_market_handler_5ms
* Description  : this function will send request message and send final result to
                 upper layer when handle process flow Read_Local_Market_Id
* usage        : period callback
*********************************************************************************/
static void client_appl_read_data_by_local_identifier_market_handler_5ms
    (
    void
    )
{
uint8 connect_channel_id = 0;
uint8 market_id = 0x00;
uint32 server_code = 0;
uint32 resp_data_len = 0;

switch( read_loacl_market_infos.next_req_frame )
    {
    case REQ_ORIGINAL_FRAME:
        market_id = read_loacl_market_infos.local_id_list[read_loacl_market_infos.current_local_data_index];
        client_dcm_req_local_indentifier( read_loacl_market_infos.connected_server_id, market_id );
        read_loacl_market_infos.curr_req_frame = read_loacl_market_infos.next_req_frame;
        read_loacl_market_infos.next_req_frame = REQ_NO_FRAME;;
        break;

    case REQ_DEFAULT_SESSION_FRAME:
        /*The received flow for a function address is end with timeout*/
        /*Wait fucntionl address request timeout*/
        client_appl_set_delay_timer( DCMM_APP_DELAY_100_MS );
        client_dcm_req_diagnostic_default_session_functional();
        read_loacl_market_infos.curr_req_frame = read_loacl_market_infos.next_req_frame;
        read_loacl_market_infos.next_req_frame = REQ_NO_FRAME;
        break;

    case REQ_EXTEND_SESSION_FRAME:
        client_dcm_req_diagnostic_extend_session( read_loacl_market_infos.connected_server_id );
        read_loacl_market_infos.curr_req_frame = read_loacl_market_infos.next_req_frame;
        read_loacl_market_infos.next_req_frame = REQ_NO_FRAME;
        break;

    case REQ_RESEND_FRAME:
        market_id = read_loacl_market_infos.local_id_list[read_loacl_market_infos.current_local_data_index];
        client_dcm_req_local_indentifier( read_loacl_market_infos.connected_server_id, market_id );
        read_loacl_market_infos.curr_req_frame = read_loacl_market_infos.next_req_frame;
        read_loacl_market_infos.next_req_frame = REQ_NO_FRAME;;
        break;

    default:
        break;
    }

/*shall send the process result to upper layer whether process is success*/
/*shall re-init related status flags*/
/*shall set the next process flow*/
if( PROCESS_RESULT_INIT != read_loacl_market_infos.process_result )
    {
    if( read_loacl_market_infos.current_local_data_index != read_loacl_market_infos.amount_local_data - 1 )
        {
        /*go on request the next common identifier data*/
        read_loacl_market_infos.current_local_data_index++;
        read_loacl_market_infos.process_result = PROCESS_RESULT_INIT;
        read_loacl_market_infos.next_req_frame = REQ_ORIGINAL_FRAME;
        read_loacl_market_infos.curr_req_frame = REQ_NO_FRAME;
        read_loacl_market_infos.receive_SNS_timer =0x00;
        read_loacl_market_infos.resend_timer = 0x00;
        }
    else
        {
        /*shall send the process result and data to upper layer whether process is success*/
        if( is_client_app_cmd_rsp_state( CMD_RSP_IDLE ) )
            {
            if( 0 != g_IdDataList.count )
                {
                connect_channel_id = get_current_connect_server_id();
                server_code = client_appl_ble_server_code_mapping[connect_channel_id].ble_server_code ;
                resp_data_len = Gen_McVehicleIdentificationResponse( server_code, &g_IdDataList,McVehicleIdentificationResponse_protobuf,sizeof( McVehicleIdentificationResponse_protobuf ) );
                if( 0 == resp_data_len )
                    {
                    client_appl_send_protobuf_failed_data( PROCESS_FLOW_MARKET );
                    }
                else
                    {
                    client_appl_response_can_related_data( BLE_RSP_CMD_MARKET_DATA, resp_data_len, McVehicleIdentificationResponse_protobuf , &client_appl_cmd_rsp_result_notify );
                    }
                }
            else
                {
                client_appl_send_protobuf_failed_data( PROCESS_FLOW_MARKET );
                }
            }
        else if( is_client_app_cmd_rsp_state( CMD_RSP_DONE ) )
            {
            /*enter the next process flow*/
            client_appl_set_current_process_flow_step(PROCESS_FLOW_IDLE);
            }
        }
    }
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_read_data_by_local_indentifier_market_postive_response_handler
* Description  : this function process the positive response data when handle hen handle process flow Read_Market
* usage        : called by client_diag_response_dispatch_handler_5ms
*********************************************************************************/
static void client_appl_read_data_by_local_identifier_market_positive_response_handler
(
 uint8 * resp_data,
 uint16 resp_lenth,
 uint8 channel_id
)
{
uint8 resp_identifier = 0x00;
uint32 resp_id_swap_u32 = 0;

if( channel_id != read_loacl_market_infos.connected_server_id )
    {
    return;
    }

if( 2 >= resp_lenth )
    {
    read_loacl_market_infos.process_result = PROCESS_RESULT_INVALID_DATA;
    return;
    }

switch( read_loacl_market_infos.curr_req_frame )
    {
    case REQ_ORIGINAL_FRAME:
    case REQ_RESEND_FRAME:
        resp_identifier = resp_data[BYTE_NUM_1];

         if(  resp_identifier == read_loacl_market_infos.local_id_list[read_loacl_market_infos.current_local_data_index])
            {
            g_IdDataList.fields = McMarketDataResponse_IdData_fields;
            IdDataList_add_IdData( &g_IdDataList, (uint32)resp_identifier, ( resp_data + 2 ), (uint32)(resp_lenth - 2 ) );
            read_loacl_market_infos.process_result = PROCESS_RESULT_SUCCESS;
            }
         else
            {
            read_loacl_market_infos.process_result = PROCESS_RESULT_INVALID_DATA;
            }

        read_loacl_market_infos.receive_SNS_timer = 0x00;
        read_loacl_market_infos.resend_timer = 0x00;
        break;

    case REQ_DEFAULT_SESSION_FRAME:
         if( DCM_10h_DEFAULT_ID == resp_data[BYTE_NUM_1] )
            {
            read_loacl_market_infos.next_req_frame = REQ_EXTEND_SESSION_FRAME;
            }
         else
            {
            read_loacl_market_infos.process_result = PROCESS_RESULT_INVALID_DATA;
            }
        break;

    case REQ_EXTEND_SESSION_FRAME:
        if( DCM_10h_EXTEND_ID == resp_data[BYTE_NUM_1] )
            {
            read_loacl_market_infos.next_req_frame = REQ_ORIGINAL_FRAME;
            }
        else
            {
            read_loacl_market_infos.process_result = PROCESS_RESULT_INVALID_DATA;
            }
        break;

    default:
        break;
    }
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_read_data_by_local_indentifier_market_negative_response_handler
* Description  : this function process the negative response data when handle hen handle process flow Read_Market
* usage        : called by fclient_diag_response_dispatch_handler_5ms
*********************************************************************************/
static void client_appl_read_data_by_local_identifier_market_negative_response_handler
(
uint8 service_id,
uint8 nrc,
uint8 channel_id
)
{
if( channel_id != read_loacl_market_infos.connected_server_id )
    {
    return;
    }

switch( read_loacl_market_infos.curr_req_frame )
    {
    case REQ_ORIGINAL_FRAME:
        if( DCM_NRC_SERVICE_NOT_SUPPORT == nrc )/*0x11*/
            {
            read_loacl_market_infos.receive_SNS_timer++;
            if( REC_MAX_SNS <= read_loacl_market_infos.receive_SNS_timer )
                {
                read_loacl_market_infos.process_result = PROCESS_RESULT_NRC_SNS;
                }
            else
                {
                read_loacl_market_infos.next_req_frame = REQ_DEFAULT_SESSION_FRAME;
                }
            }
        else if( DCM_NRC_GENERAL_REJECT == nrc \
                || DCM_NRC_SUB_FUNCTION_NOT_SUPPORT == nrc
                || DCM_NRC_BUSY_REPEAY_REQUEST == nrc
                || DCM_NRC_CONDITION_NOT_CORRECT == nrc )
            {
            read_loacl_market_infos.process_result = PROCESS_RESULT_NRC_GR;
            }
        else
            {
            read_loacl_market_infos.process_result = PROCESS_RESULT_NRC_GR;
            }
        break;

    case REQ_DEFAULT_SESSION_FRAME:
    case REQ_EXTEND_SESSION_FRAME:
    case REQ_RESEND_FRAME:
        read_loacl_market_infos.process_result = PROCESS_RESULT_NRC_GR;
        break;

    default:
        break;
    }
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_read_data_by_local_indentifier_market_timeout_notify
* Description  : this function process no data received  when handle hen handle process flow Read_Market
* usage        : called by called by fclient_diag_response_dispatch_handler_5ms
*********************************************************************************/
static void client_appl_read_data_by_local_identifier_market_timeout_notify
    (
    void
    )
{
switch( read_loacl_market_infos.curr_req_frame )
    {
    case REQ_ORIGINAL_FRAME:
        read_loacl_market_infos.next_req_frame = REQ_RESEND_FRAME;
        break;

    case REQ_DEFAULT_SESSION_FRAME:
        /*Request default sesson within function address*/
        /*The actual received end with timeout*/
        /*So the next req frame will be extend frame when have been received a positive resonse fot current channenl*/
        if( REQ_EXTEND_SESSION_FRAME != read_loacl_market_infos.next_req_frame )
            {
            read_loacl_market_infos.process_result = PROCESS_RESULT_NRC_GR;
            }
        else
            {
            /*do nothing*/
            }
        client_appl_clear_delay_timer();
        break;

    case REQ_EXTEND_SESSION_FRAME:
        read_loacl_market_infos.process_result = PROCESS_RESULT_NRC_GR;
        break;

    case REQ_RESEND_FRAME:
       read_loacl_market_infos.resend_timer++;
        if( RESEND_MAX_CONUNT > read_loacl_market_infos.resend_timer )
            {
            read_loacl_market_infos.next_req_frame = REQ_RESEND_FRAME;
            }
        else
            {
            read_loacl_market_infos.process_result = RROCESS_RESULE_RESEND_OVERFLOW;
            }
        break;

    default:
        break;
    }
}


/*!******************************************************************************
*
* @public
* Function name: client_appl_read_data_by_local_indentifier_monitor_handler_5ms
* Description  : this function will send request message and send final result to
                 upper layer when handle process flow Read_Local_Monitor_Id
* usage        : period callback
*********************************************************************************/
static void client_appl_read_data_by_local_identifier_monitor_handler_5ms
    (
    void
    )
{
uint8 monitor_id = 0;
uint8 connect_channel_id = 0;
uint32 server_code = 0;
uint32 resp_data_len = 0;

switch( read_local_monitor_infos.next_req_frame )
    {
    case REQ_ORIGINAL_FRAME:
        monitor_id = read_local_monitor_infos.local_id_list[read_local_monitor_infos.current_local_data_index];
        client_dcm_req_local_indentifier( read_local_monitor_infos.connected_server_id, monitor_id );
        read_local_monitor_infos.curr_req_frame = read_local_monitor_infos.next_req_frame;
        read_local_monitor_infos.next_req_frame = REQ_NO_FRAME;;
        break;

    case REQ_DEFAULT_SESSION_FRAME:
        /*The received flow for a function address is end with timeout*/
        /*Wait fucntionl address request timeout*/
        client_appl_set_delay_timer( DCMM_APP_DELAY_100_MS );
        client_dcm_req_diagnostic_default_session_functional();
        read_local_monitor_infos.curr_req_frame = read_local_monitor_infos.next_req_frame;
        read_local_monitor_infos.next_req_frame = REQ_NO_FRAME;
        break;

    case REQ_EXTEND_SESSION_FRAME:
        client_dcm_req_diagnostic_extend_session( read_local_monitor_infos.connected_server_id );
        read_local_monitor_infos.curr_req_frame = read_local_monitor_infos.next_req_frame;
        read_local_monitor_infos.next_req_frame = REQ_NO_FRAME;
        break;

    case REQ_RESEND_FRAME:
        monitor_id = read_local_monitor_infos.local_id_list[read_local_monitor_infos.current_local_data_index];
        client_dcm_req_local_indentifier( read_local_monitor_infos.connected_server_id, monitor_id );
        read_local_monitor_infos.curr_req_frame = read_local_monitor_infos.next_req_frame;
        read_local_monitor_infos.next_req_frame = REQ_NO_FRAME;;
        break;

    default:
        break;
    }

/*shall send the process result to upper layer whether process is success*/
/*shall re-initial related status flags*/
/*shall set the next process flow*/
if( PROCESS_RESULT_INIT != read_local_monitor_infos.process_result )
    {
    if( read_local_monitor_infos.current_local_data_index != read_local_monitor_infos.amount_local_data - 1 )
        {
        /*go on request the next common identifier data*/
        read_local_monitor_infos.current_local_data_index++;
        read_local_monitor_infos.process_result = PROCESS_RESULT_INIT;
        read_local_monitor_infos.next_req_frame = REQ_ORIGINAL_FRAME;
        read_local_monitor_infos.curr_req_frame = REQ_NO_FRAME;
        read_local_monitor_infos.receive_SNS_timer =0x00;
        read_local_monitor_infos.resend_timer = 0x00;
        }
    else
        {
        if( is_client_app_cmd_rsp_state( CMD_RSP_IDLE ) )
            {
            if( TRUE == read_local_monitor_infos.is_request_support_list_flow )
                {
                client_appl_ble_rsp_request_support_monitor_list();
                }
            else if( 0 != g_IdDataList.count )
                {
                connect_channel_id = get_current_connect_server_id();
                server_code = client_appl_ble_server_code_mapping[connect_channel_id].ble_server_code ;
                resp_data_len = Gen_McVehicleIdentificationResponse( server_code, &g_IdDataList,McVehicleIdentificationResponse_protobuf,sizeof( McVehicleIdentificationResponse_protobuf ) );
                if( 0 == resp_data_len )
                    {
                    client_appl_send_protobuf_failed_data( PROCESS_FLOW_MONITOR );
                    }
                else
                    {
                    client_appl_response_can_related_data( BLE_RSP_CMD_VEHICLE_INFORMATION, resp_data_len, McVehicleIdentificationResponse_protobuf , &client_appl_cmd_rsp_result_notify );
                    }
                }
            else
                {
                client_appl_send_protobuf_failed_data( PROCESS_FLOW_MONITOR );
                }
            }
        else if( is_client_app_cmd_rsp_state( CMD_RSP_DONE ) )
            {
            set_client_app_cmd_rsp_state( CMD_RSP_IDLE );
            if( TRUE == read_local_monitor_infos.is_cycle_transmission )
                {
                g_IdDataList.count = 0;
                client_appl_set_delay_timer( read_local_monitor_infos.cycle_tarns_interval_time );
                read_local_monitor_infos.current_local_data_index = 0x00;
                read_local_monitor_infos.process_result = PROCESS_RESULT_INIT;
                read_local_monitor_infos.curr_req_frame = REQ_NO_FRAME;
                read_local_monitor_infos.next_req_frame = REQ_ORIGINAL_FRAME;
                read_local_monitor_infos.receive_SNS_timer = 0x00;
                read_local_monitor_infos.resend_timer = 0x00;
                }
            else
                {
                client_appl_set_current_process_flow_step( PROCESS_FLOW_IDLE );
                }
            }
        }
    }
}


/*!******************************************************************************
*
* @public
* Function name: client_appl_read_data_by_local_indentifier_monitor_postive_response_handler
* Description  : this function process the positive response data when handle hen handle process flow Read_Monitor
* usage        : called by client_diag_response_dispatch_handler_5ms
*********************************************************************************/
static void client_appl_read_data_by_local_identifier_monitor_positive_response_handler
(
 uint8 * resp_data,
 uint16 resp_lenth,
 uint8 channel_id
)
{
uint8 connect_channel_id = 0;
uint32 server_code = 0;

uint32 resp_id_swap_u32 = 0;

if( channel_id != read_local_monitor_infos.connected_server_id )
    {
    return;
    }

if( 2 >= resp_lenth )
    {
    read_local_monitor_infos.process_result = PROCESS_RESULT_INVALID_DATA;
    return;
    }

switch( read_local_monitor_infos.curr_req_frame )
    {
    case REQ_ORIGINAL_FRAME:
    case REQ_RESEND_FRAME:
        if( resp_data[BYTE_NUM_1] == read_local_monitor_infos.local_id_list[read_local_monitor_infos.current_local_data_index] )
            {
            read_local_monitor_infos.process_result = PROCESS_RESULT_SUCCESS;

            if( read_local_monitor_infos.current_local_data_index == read_local_monitor_infos.amount_local_data - 1 )
                {
                read_local_monitor_infos.process_result = PROCESS_RESULT_END;
                }

            if( TRUE == read_local_monitor_infos.is_request_support_list_flow )
                {
                read_local_monitor_infos.support_id_received_flag_array[read_local_monitor_infos.current_local_data_index] = TRUE;
                }
            else
                {
                connect_channel_id = get_current_connect_server_id();
                server_code = client_appl_ble_server_code_mapping[connect_channel_id].ble_server_code ;
                IdDataList_add_IdData( &g_IdDataList, (uint32)resp_data[BYTE_NUM_1], resp_data + 2 , (uint32)( resp_lenth  - 2 ) );
                }
            }
        else
            {
            read_local_monitor_infos.process_result = PROCESS_RESULT_INVALID_DATA;
            }
        break;

    case REQ_DEFAULT_SESSION_FRAME:
        if( DCM_10h_DEFAULT_ID == resp_data[BYTE_NUM_1] )
            {
            read_local_monitor_infos.next_req_frame = REQ_EXTEND_SESSION_FRAME;
            }
        else
            {
            read_local_monitor_infos.process_result = PROCESS_RESULT_INVALID_DATA;
            }
        break;

    case REQ_EXTEND_SESSION_FRAME:
       if( DCM_10h_EXTEND_ID == resp_data[BYTE_NUM_1] )
            {
            read_local_monitor_infos.next_req_frame = REQ_ORIGINAL_FRAME;
            }
        else
            {
            read_local_monitor_infos.process_result = PROCESS_RESULT_INVALID_DATA;
            }
        break;
        break;
    default:
        break;
    }
}


/*!******************************************************************************
*
* @public
* Function name: client_appl_read_data_by_local_indentifier_monitor_negative_response_handler
* Description  : this function process the negative response data when handle hen handle process flow Read_Monitor
* usage        : called by fclient_diag_response_dispatch_handler_5ms
*********************************************************************************/
static void client_appl_read_data_by_local_identifier_monitor_negative_response_handler
(
uint8 service_id,
uint8 nrc,
uint8 channel_id
)
{
if( channel_id != read_local_monitor_infos.connected_server_id )
    {
    return;
    }

switch( read_local_monitor_infos.curr_req_frame )
    {
    case REQ_ORIGINAL_FRAME:
        if( DCM_NRC_SERVICE_NOT_SUPPORT == nrc )/*0x11*/
            {
            read_local_monitor_infos.receive_SNS_timer++;
            if( REC_MAX_SNS <= read_local_monitor_infos.receive_SNS_timer )
                {
                read_local_monitor_infos.process_result = PROCESS_RESULT_NRC_SNS;
                }
            else
                {
                read_local_monitor_infos.next_req_frame = REQ_DEFAULT_SESSION_FRAME;
                }
            }
        else if( DCM_NRC_GENERAL_REJECT == nrc \
                || DCM_NRC_SUB_FUNCTION_NOT_SUPPORT == nrc
                || DCM_NRC_BUSY_REPEAY_REQUEST == nrc
                || DCM_NRC_CONDITION_NOT_CORRECT == nrc )
            {
            read_local_monitor_infos.process_result = PROCESS_RESULT_NRC_GR;
            }
        else
            {
            read_local_monitor_infos.process_result = PROCESS_RESULT_NRC_GR;
            }
        break;

    case REQ_DEFAULT_SESSION_FRAME:
    case REQ_EXTEND_SESSION_FRAME:
    case REQ_RESEND_FRAME:
        read_local_monitor_infos.process_result = PROCESS_RESULT_NRC_GR;
        break;

    default:
        break;
    }
}


/*!******************************************************************************
*
* @public
* Function name: client_appl_read_data_by_local_indentifier_monitor_timeout_notify
* Description  : this function process no data received  when handle hen handle process flow Read_Monitor
* usage        : called by called by fclient_diag_response_dispatch_handler_5ms
*********************************************************************************/
static void client_appl_read_data_by_local_identifier_monitor_timeout_notify
    (
    void
    )
{
switch( read_local_monitor_infos.curr_req_frame )
    {
    case REQ_ORIGINAL_FRAME:
        read_local_monitor_infos.next_req_frame = REQ_RESEND_FRAME;
        break;

    case REQ_EXTEND_SESSION_FRAME:
        /*Request default sesson within function address*/
        /*The actual received end with timeout*/
        /*So the next req frame will be extend frame when have been received a positive resonse fot current channenl*/
        if( REQ_EXTEND_SESSION_FRAME != read_local_monitor_infos.next_req_frame )
            {
            read_local_monitor_infos.process_result = PROCESS_RESULT_NRC_GR;
            }
        else
            {
            /*do nothing*/
            }
        client_appl_clear_delay_timer();
        break;

    case REQ_DEFAULT_SESSION_FRAME:
        read_local_monitor_infos.process_result = PROCESS_RESULT_NRC_GR;
        break;

    case REQ_RESEND_FRAME:
       read_local_monitor_infos.resend_timer++;
        if( RESEND_MAX_CONUNT > read_local_monitor_infos.resend_timer )
            {
            read_local_monitor_infos.next_req_frame = REQ_RESEND_FRAME;
            }
        else
            {
            read_local_monitor_infos.process_result = RROCESS_RESULE_RESEND_OVERFLOW;
            }
        break;

    default:
        break;
    }
}


static void client_appl_set_next_ffd_frame_frame
    (
    client_appl_request_frame_type next_frame_type
    )
{
read_freeze_frame_data_infos.next_request_frame = next_frame_type;
if( ( REQ_ORIGINAL_FRAME == read_freeze_frame_data_infos.curr_request_frame || REQ_FFD_FRAME == read_freeze_frame_data_infos.curr_request_frame )
    && (REQ_DEFAULT_SESSION_FRAME == read_freeze_frame_data_infos.next_request_frame || REQ_RESEND_FRAME == read_freeze_frame_data_infos.next_request_frame)
    )
    {
    read_freeze_frame_data_infos.prev_request_frame = read_freeze_frame_data_infos.curr_request_frame;
    }


}

static void client_appl_req_frame_status_switch
    (
    void
    )
{
read_freeze_frame_data_infos.curr_request_frame = read_freeze_frame_data_infos.next_request_frame;
read_freeze_frame_data_infos.next_request_frame = REQ_NO_FRAME;
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_read_frrze_frame_data_handler_5ms
* Description  : this function will send request message and send final result to
                 upper layer when handle process flow Read_FFD
* usage        : period callback
*********************************************************************************/
static void client_appl_read_freeze_frame_data_handler_5ms
    (
    void
    )
{
uint8 connect_channel_id = 0;
uint8 req_identifier = 0x00;
uint32 server_code = 0;
uint32 resp_data_len = 0;

switch( read_freeze_frame_data_infos.next_request_frame )
{
    case REQ_ORIGINAL_FRAME:
        client_dcm_req_freeze_frame_data( read_freeze_frame_data_infos.connected_server_id, read_freeze_frame_data_infos.current_freeze_frame_number, 0x00);
        client_appl_req_frame_status_switch();
        break;

    case REQ_DEFAULT_SESSION_FRAME:
        /*The received flow for a function address is end with timeout*/
        /*Wait fucntionl address request timeout*/
        client_appl_set_delay_timer( DCMM_APP_DELAY_100_MS );
        client_dcm_req_diagnostic_default_session_functional();
        client_appl_req_frame_status_switch();
        break;

    case REQ_EXTEND_SESSION_FRAME:
        client_dcm_req_diagnostic_extend_session( read_freeze_frame_data_infos.connected_server_id );
        client_appl_req_frame_status_switch();
        break;


    case REQ_RESEND_FRAME:
        if( REQ_FFD_FRAME == read_freeze_frame_data_infos.prev_request_frame )
            {
            req_identifier = read_freeze_frame_data_infos.request_id_list[read_freeze_frame_data_infos.current_request_id];
            }
        else
            {
            req_identifier = 0x00;
            }
        client_dcm_req_freeze_frame_data( read_freeze_frame_data_infos.connected_server_id, read_freeze_frame_data_infos.current_freeze_frame_number, req_identifier );
        client_appl_req_frame_status_switch();
        break;

    case REQ_FFD_FRAME:
        req_identifier = read_freeze_frame_data_infos.request_id_list[read_freeze_frame_data_infos.current_request_id];
        client_dcm_req_freeze_frame_data( read_freeze_frame_data_infos.connected_server_id, read_freeze_frame_data_infos.current_freeze_frame_number, req_identifier );
        client_appl_req_frame_status_switch();
        break;

    default:
    break;
}

if( PROCESS_RESULT_INIT != read_freeze_frame_data_infos.process_result )
    {
    if( is_client_app_cmd_rsp_state( CMD_RSP_IDLE ) )
        {
        if( PROCESS_RESULT_END  == read_freeze_frame_data_infos.process_result  )
            {
            #if (APPL_DEBUG )
            client_appl_debug_printf( read_freeze_frame_data_infos.process_result );
            #endif

            connect_channel_id = get_current_connect_server_id();
            server_code = client_appl_ble_server_code_mapping[connect_channel_id].ble_server_code ;
            resp_data_len = Gen_McFfdResponse( server_code, &g_McFfdResponse_data_list, McFfdResponse_protobuf, sizeof( McFfdResponse_protobuf ) );
            if( 0 == resp_data_len )
                {
                client_appl_send_protobuf_failed_data( PROCESS_FLOW_RFFD );
                }
            else
                {
                client_appl_response_can_related_data( BLE_RSP_CMD_FFD, resp_data_len, McFfdResponse_protobuf , &client_appl_cmd_rsp_result_notify );
                }
            }
         else
            {
            client_appl_send_protobuf_failed_data( PROCESS_FLOW_RFFD );
            }
        }
    else if( is_client_app_cmd_rsp_state( CMD_RSP_DONE ) )
        {
        set_client_app_cmd_rsp_state( CMD_RSP_IDLE );
        client_appl_set_current_process_flow_step( PROCESS_FLOW_IDLE );
        }
    }
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_read_freeze_frame_data_positive_response_handler
* Description  : this function process the positive response data when handle hen handle process flow Read_FFD
* usage        : called by client_diag_response_dispatch_handler_5ms
*********************************************************************************/
static void client_appl_read_freeze_frame_data_positive_response_handler
    (
     uint8 * resp_data,
     uint16 resp_lenth,
     uint8 channel_id
    )
{
uint8 amount_of_list = 0;
uint8 connect_channel_id = 0;
uint32 server_code = 0;
uint32 resp_len = 0;


if( channel_id != read_freeze_frame_data_infos.connected_server_id )
    {
    return;
    }

if( 2 >= resp_lenth  )
    {
    return;
    }

connect_channel_id = get_current_connect_server_id();
server_code = client_appl_ble_server_code_mapping[connect_channel_id].ble_server_code ;

switch( read_freeze_frame_data_infos.curr_request_frame )
    {
    case REQ_ORIGINAL_FRAME:
        /*for example:response message: 06 52 02 11 12 01 00, the get id is 0x11 and 0x12*/
        amount_of_list = (uint8)(resp_lenth - 0x04);
        read_freeze_frame_data_infos.requset_id_list_amount = amount_of_list;
        client_appl_data_cpy( read_freeze_frame_data_infos.request_id_list, ( resp_data + 2 ), amount_of_list );
        client_appl_set_next_ffd_frame_frame( REQ_FFD_FRAME );
        /*when receive a positive response for original message, shall request FFD message consecutive*/
        read_freeze_frame_data_infos.current_request_id = 0x00;
        break;

    case REQ_DEFAULT_SESSION_FRAME:
        if( DCM_10h_DEFAULT_ID == resp_data[BYTE_NUM_1] )
            {
            client_appl_set_next_ffd_frame_frame( REQ_EXTEND_SESSION_FRAME );
            }
        else
            {
             read_freeze_frame_data_infos.process_result = PROCESS_RESULT_INVALID_DATA;
            }
        break;

    case REQ_EXTEND_SESSION_FRAME:
        if( DCM_10h_EXTEND_ID == resp_data[BYTE_NUM_1] )
            {
            client_appl_set_next_ffd_frame_frame( read_freeze_frame_data_infos.prev_request_frame );
            }
        else
            {
             read_freeze_frame_data_infos.process_result = PROCESS_RESULT_INVALID_DATA;
            }
        break;

    case REQ_RESEND_FRAME:
        if( REQ_ORIGINAL_FRAME == read_freeze_frame_data_infos.prev_request_frame)
            {
            amount_of_list = (uint8)(resp_lenth - 0x04);
            read_freeze_frame_data_infos.requset_id_list_amount = amount_of_list;
            client_appl_data_cpy( read_freeze_frame_data_infos.request_id_list, ( resp_data + 2 ), amount_of_list);

            client_appl_set_next_ffd_frame_frame( REQ_FFD_FRAME );
            read_freeze_frame_data_infos.current_request_id = 0x00;
            }
        else
            {
            read_freeze_frame_data_infos.current_request_id++;

            McFfdResponse_data_list_add_data( &g_McFfdResponse_data_list, resp_data + 2, (uint32)(resp_lenth - 2 ) );
            if( read_freeze_frame_data_infos.current_request_id < read_freeze_frame_data_infos.requset_id_list_amount )
                {
                client_appl_set_next_ffd_frame_frame( REQ_FFD_FRAME );
                }
            else
                {
                /*The max valud of freeze frame number is 0xFF, (type unsigned char)*/
                if( 0xFF == read_freeze_frame_data_infos.current_freeze_frame_number )
                    {
                    read_freeze_frame_data_infos.process_result = PROCESS_RESULT_END;
                    }
                else
                    {
                    /*Requset the next freeze frame number data*/
                    client_appl_set_next_ffd_frame_frame( REQ_ORIGINAL_FRAME );
                    read_freeze_frame_data_infos.current_freeze_frame_number++;
                    read_freeze_frame_data_infos.current_request_id = 0x00;
                    read_freeze_frame_data_infos.requset_id_list_amount = 0x00;
                    (void)memset( read_freeze_frame_data_infos.request_id_list, 0x00 ,MAX_FFD_COUNT );
                    }
                }
            }
        break;

    case REQ_FFD_FRAME:
    read_freeze_frame_data_infos.current_request_id++;
    McFfdResponse_data_list_add_data( &g_McFfdResponse_data_list, resp_data + 2, (uint32)(resp_lenth - 2) );
    if( read_freeze_frame_data_infos.current_request_id < read_freeze_frame_data_infos.requset_id_list_amount )
        {
        client_appl_set_next_ffd_frame_frame( REQ_FFD_FRAME );
        }
    else
        {
        /*The max value of freeze frame number is 0xFF, (type unsigned char)*/
        if( 0xFF == read_freeze_frame_data_infos.current_freeze_frame_number )
            {
            read_freeze_frame_data_infos.process_result = PROCESS_RESULT_END;
            }
        else
            {
            /*Request the next freeze frame number data*/
            client_appl_set_next_ffd_frame_frame( REQ_ORIGINAL_FRAME );
            read_freeze_frame_data_infos.current_freeze_frame_number++;
            read_freeze_frame_data_infos.current_request_id = 0x00;
            read_freeze_frame_data_infos.requset_id_list_amount = 0x00;
            (void)memset( read_freeze_frame_data_infos.request_id_list, 0x00 ,MAX_FFD_COUNT );
            }
        }
    break;

    default:
    break;
    }

/*we need initial timer when received a positive message of data*/
if( REQ_ORIGINAL_FRAME == read_freeze_frame_data_infos.curr_request_frame
    || REQ_RESEND_FRAME == read_freeze_frame_data_infos.curr_request_frame
    || REQ_FFD_FRAME == read_freeze_frame_data_infos.curr_request_frame )
    {
    read_freeze_frame_data_infos.receive_SNS_timer = 0x00;
    read_freeze_frame_data_infos.resend_timer = 0x00;
    }
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_read_data_by_lclient_appl_read_freeze_frame_data_negative_response_handlerocal_indentifier_market_negative_response_handler
* Description  : this function process the negative response data when handle hen handle process flow Read_FFD
* usage        : called by fclient_diag_response_dispatch_handler_5ms
*********************************************************************************/
static void client_appl_read_freeze_frame_data_negative_response_handler
    (
    uint8 service_id,
    uint8 nrc,
    uint8 channel_id
    )
{
if( channel_id != read_freeze_frame_data_infos.connected_server_id )
    {
    return;
    }

switch( read_freeze_frame_data_infos.curr_request_frame )
    {
    case REQ_ORIGINAL_FRAME:
        if( DCM_NRC_SUB_FUNCTION_NOT_SUPPORT == nrc )
            {
            /*RX flow success end*/
            if( 0x01 < read_freeze_frame_data_infos.current_freeze_frame_number )
                {
                /*This process shall be end normally by receive a NRC 12*/
                read_freeze_frame_data_infos.process_result = PROCESS_RESULT_END;
                }
            else
                {
                /*The server don`t have any DTC status data*/
                read_freeze_frame_data_infos.process_result = PROCESS_RESULT_INVALID_DATA;
                }
            }
        else if( DCM_NRC_SERVICE_NOT_SUPPORT == nrc )
            {
            read_freeze_frame_data_infos.receive_SNS_timer++;
            if( REC_MAX_SNS <= read_freeze_frame_data_infos.receive_SNS_timer )
                {
                read_freeze_frame_data_infos.process_result = PROCESS_RESULT_NRC_SNS;
                }
            else
                {
                client_appl_set_next_ffd_frame_frame( REQ_DEFAULT_SESSION_FRAME );
                }
            }
        else
            {
            read_freeze_frame_data_infos.process_result = PROCESS_RESULT_NRC_GR;
            }
        break;

    case REQ_DEFAULT_SESSION_FRAME:
    case REQ_EXTEND_SESSION_FRAME:
        read_freeze_frame_data_infos.process_result = PROCESS_RESULT_NRC_GR;
        break;

    case REQ_RESEND_FRAME:
        if( REQ_ORIGINAL_FRAME == read_freeze_frame_data_infos.prev_request_frame )
            {
            if( DCM_NRC_SUB_FUNCTION_NOT_SUPPORT == nrc )
                {
                /*RX flow success end*/
                if( 0x01 < read_freeze_frame_data_infos.current_freeze_frame_number )
                    {
                    /*This process shall be end normally by received a NRC 12*/
                    read_freeze_frame_data_infos.process_result = PROCESS_RESULT_END;
                    }
                else
                    {
                    /*The server don`t have any DTC status data*/
                    read_freeze_frame_data_infos.process_result = PROCESS_RESULT_INVALID_DATA;
                    }
                }
            else if( DCM_NRC_SERVICE_NOT_SUPPORT == nrc )
                    {
                    read_freeze_frame_data_infos.receive_SNS_timer++;
                    if( REC_MAX_SNS <= read_freeze_frame_data_infos.receive_SNS_timer )
                        {
                        read_freeze_frame_data_infos.process_result = PROCESS_RESULT_NRC_SNS;
                        }
                    else
                        {
                        client_appl_set_next_ffd_frame_frame( REQ_DEFAULT_SESSION_FRAME );
                        }
                    }
            else
                {
                read_freeze_frame_data_infos.process_result = PROCESS_RESULT_NRC_GR;
                }
            }
        else
            {
            if( DCM_NRC_SERVICE_NOT_SUPPORT == nrc )
            {
            read_freeze_frame_data_infos.receive_SNS_timer++;
            if( REC_MAX_SNS <= read_freeze_frame_data_infos.receive_SNS_timer )
                {
                read_freeze_frame_data_infos.process_result = PROCESS_RESULT_NRC_SNS;
                }
            else
                {
                client_appl_set_next_ffd_frame_frame( REQ_DEFAULT_SESSION_FRAME );
                }
            }
            else
                {
                read_freeze_frame_data_infos.process_result = PROCESS_RESULT_NRC_GR;
                }
            }
        break;

    case REQ_FFD_FRAME:
        if( DCM_NRC_SERVICE_NOT_SUPPORT == nrc )
            {
            read_freeze_frame_data_infos.receive_SNS_timer++;
            if( REC_MAX_SNS <= read_freeze_frame_data_infos.receive_SNS_timer )
                {
                read_freeze_frame_data_infos.process_result = PROCESS_RESULT_NRC_SNS;
                }
            else
                {
                client_appl_set_next_ffd_frame_frame( REQ_DEFAULT_SESSION_FRAME );
                }
            }
        else
            {
            read_freeze_frame_data_infos.process_result = PROCESS_RESULT_NRC_GR;
            }
    break;

    default:
    break;
    }
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_read_freeze_frame_data_timeout_notify
* Description  : this function process no data received  when handle hen handle process flow Read_FFD
* usage        : called by called by fclient_diag_response_dispatch_handler_5ms
*********************************************************************************/
static void client_appl_read_freeze_frame_data_timeout_notify
    (
    void
    )
{
switch( read_freeze_frame_data_infos.curr_request_frame )
    {
    case REQ_ORIGINAL_FRAME:
        client_appl_set_next_ffd_frame_frame( REQ_RESEND_FRAME );
        break;

    case REQ_DEFAULT_SESSION_FRAME:
        /*Request default sesson within function address*/
        /*The actual received end with timeout*/
        /*So the next req frame will be extend frame when have been received a positive resonse fot current channenl*/
        if( REQ_EXTEND_SESSION_FRAME != read_freeze_frame_data_infos.next_request_frame )
            {
            read_freeze_frame_data_infos.process_result = PROCESS_RESULT_NRC_GR;
            }
        else
            {
            /*do nothing*/
            }
        client_appl_clear_delay_timer();
        break;

    case REQ_EXTEND_SESSION_FRAME:
        read_freeze_frame_data_infos.process_result = PROCESS_RESULT_NRC_GR;
        break;

    case REQ_RESEND_FRAME:
        read_freeze_frame_data_infos.resend_timer++;
        if( RESEND_MAX_CONUNT > read_freeze_frame_data_infos.resend_timer )
            {
            read_freeze_frame_data_infos.next_request_frame = REQ_RESEND_FRAME;
            }
        else
            {
            read_freeze_frame_data_infos.process_result = RROCESS_RESULE_RESEND_OVERFLOW;
            }
        break;

    case REQ_FFD_FRAME:
        client_appl_set_next_ffd_frame_frame( REQ_RESEND_FRAME );
        break;

    default:
    break;
    }
}
