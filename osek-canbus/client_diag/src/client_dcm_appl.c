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
#define APPL_PENDING                                 (TRUE )
#define CLIENT_DEBUG(x)   PRINTF("[%s-%s-%s]:%s",__FILE__,__TIME__,__func__, x)


/*--------------------------------------------------------------------
                            VARIABLES
--------------------------------------------------------------------*/
/*define yamaha diagnostic tools connected state*/
/*define BLE connected state*/
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
static uint16 connected_server_list[SUPPORT_SERVER_NUM] = {0};
static const uint16 server_ecu_identifier[SUPPORT_SERVER_NUM] = SERVER_ECU_LIST;
static client_appl_server_detect_step_type server_detect_step = SERVER_DETECT_INIT;
static client_appl_server_list_detect_type server_list_detect_infos[SUPPORT_SERVER_NUM] = {0};
static client_appl_detect_connected_server_infos_type detect_connected_server_infos ={0};

/*for read DTC*/
static boolean is_read_init_dtc =  FALSE;
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
static boolean response_support_monitor_data_id_list[18] = { 0 };
static const uint8 support_monitor_data_id_list[SUPPORT_MONITOR_COUNT] = SUPPORT_MONITOR_IDS_LIST;
static client_appl_read_data_by_local_id_type read_loacl_market_infos = {0};
static client_appl_read_data_by_local_id_type read_local_monitor_infos = {0};

/*for freeze frame data*/
static client_appl_read_freeze_frame_data_type read_freeze_frame_data_infos = {0};
static uint8 current_request_freeze_frame_id_list[20] = {0};

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

/*------------------------------------------------------------------
*                          MACROS
-------------------------------------------------------------------*/
#define set_current_conncet_server_id( value )       ( current_connect_server_id = value )
#define get_current_connect_server_id()              ( current_connect_server_id )
#define decrease_delay_timer()                       ( delay_timer_count -- )
#define set_client_app_cmd_rsp_state( state )        ( client_app_cmd_rsp_state = state )
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
    uint8 nrc
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
    uint8 nrc
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
    uint8 nrc
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
    uint8 nrc
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
    uint8 nrc
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
    uint8 nrc
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
    uint8 nrc
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


static client_process_flow_handler_type client_process_flow_handler[SUPPORT_FUCNTION_NUMS] =
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
* Function name: client_appl_set_ydt_connect_state
* Description:  Set current YAMAHA diagnostic tools connect state
* Usage:   Called by can driver
*********************************************************************/
void client_appl_set_ydt_connect_state
    (
    boolean connect_state
    )
{
ydt_connected_state = connect_state;
}

/*!*******************************************************************
* @public
* Function name: client_appl_get_ydt_connect_state
* Description:  Get current YAMAH diagnostic tools connect state
* Usage: Called by client_appl_main_5ms_handler
*********************************************************************/
static boolean client_appl_get_ydt_connect_state
    (
    void
    )
{
return ydt_connected_state;
}

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
client_appl_set_current_process_flow_step( PROCESS_FLOW_IDLE );
}

/*!*******************************************************************
* @public
* Function name: client_appl_set_ble_connected_state
* Description:  Set current BLE connect state
*********************************************************************/
static void client_appl_set_ble_connected_state
    (
   boolean next_state
    )
{
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

for( ; index <= SUPPORT_SERVER_NUM; index++ )
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

for( index++ ; index <= SUPPORT_SERVER_NUM; index++ )
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
for( ; temp <= SUPPORT_SERVER_NUM; temp++ )
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
switch( client_process_flow_state )
    {
    case PROCESS_FLOW_IDLE:
        set_current_conncet_server_id( NO_SERVER_CONNECT );
        /*initial structure*/
        /*clear the read_dtc_infos except the read_dtc_infos.is_storge_init_dtc*/
        /*sizof( read_dtc_infos) = 12, Byte alignment */
        (void)memset( &read_dtc_infos, 0x00, sizeof( read_dtc_infos ) - 2 );
        (void)memset( &read_common_identifier_infos, 0x00, sizeof( read_common_identifier_infos ));
        (void)memset( &read_loacl_market_infos, 0x00, sizeof( read_loacl_market_infos ) );
        (void)memset( &read_local_monitor_infos, 0x00, sizeof( read_local_monitor_infos ));
        (void)memset( &read_freeze_frame_data_infos,0x00, sizeof( read_freeze_frame_data_infos ));
        set_client_app_cmd_rsp_state( CMD_RSP_IDLE );
        break;

    case PROCESS_FLOW_DETECT_SERVER:
        client_appl_set_delay_timer( 2000 );/*5ms*2000 = 10s*/
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
PRINTF("Client Start new flow:%s\r\n",print_header[next_process_flow]);
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
for( ; index <= SUPPORT_SERVER_NUM; index++ )
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
* usage        : called periodly
*********************************************************************************/
boolean client_appl_diagnostic_enable
    (
    void
    )
{
/*Check the Yamaha diagnostic tools connect state*/
if( TRUE == client_appl_get_ydt_connect_state() )
    {
    if( PROCESS_FLOW_IDLE != client_process_flow_state )
        {
        client_appl_enter_ydt_handler();
        }
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
* usage        : called periodly
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
* Description  : this function will get whether a next ble command received is enable
* usage        : called periodly
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
    if( ( TRUE == read_dtc_infos.is_cycle_transmission ) && ( PROCESS_RESULT_END == read_dtc_infos.process_result ) && ( is_client_app_cmd_rsp_state( CMD_RSP_DONE) ) )
        {
        return TRUE;
        }
    }
else if( PROCESS_FLOW_MONITOR == client_process_flow_state )
    {
    if( (PROCESS_RESULT_SUCCESS == read_local_monitor_infos.process_result ) && ( TRUE == read_local_monitor_infos.is_cycle_transmission ) && ( CMD_RSP_PROCESSING != client_app_cmd_rsp_state ) )
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
* Function name: client_appl_main_5ms_handler
* Description  : this function will send request message and send final result to
                upper layer when handle process flow
* usage        : called by upper layer period function
*********************************************************************************/
void client_appl_main_5ms_handler
    (
    void
    )
{
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
client_process_flow_handler[client_process_flow_state].postive_response_dispatch( resp_data, resp_lenth, channel_id );
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
    uint8 nrc
    )
{
client_process_flow_handler[client_process_flow_state].negative_response_dispatch( service_id, nrc );
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
client_process_flow_handler[client_process_flow_state].response_timeout_notify();
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
* Description  : authentication
*********************************************************************************/
boolean client_appl_ble_req_authentication
    (
    uint32 data_size,
    const uint8* data
    )
{
uint8 return_value = TRUE;
const uint8* p_uuid = data + BLE_AUT_UUID_OFSET_ADDR;
const uint8* p_ccu_id = data + BLE_AUT_CCU_ID_OFFSET_ADDR;
const uint8* P_pass_key = data + BLE_AUT_PASS_KEY_OFFSET_ADDR;


/*temporary,this data is read from EEP*/
const uint8 tmep_ccu_id[BLE_AUT_CCU_ID_LENGTH] = {0};
const uint8 temp_pass_key[BLE_AUT_PASS_KEY_LENGTH] = {0};
const uint8 temp_uuid[BLE_AUT_UUID_KEY_LENGTH] = {0};

uint8 data_total_length = BLE_AUT_CCU_ID_LENGTH + BLE_AUT_PASS_KEY_LENGTH + BLE_AUT_UUID_KEY_LENGTH;
/*check CCU, pass_key, UUID*/
if( (uint32)data_total_length != data_size )
    {
    return_value = FALSE;
    }
else
    {
    if( ( TRUE == client_appl_data_compare( p_ccu_id, tmep_ccu_id, BLE_AUT_CCU_ID_LENGTH ) )\
        && ( TRUE == client_appl_data_compare( P_pass_key, temp_pass_key, BLE_AUT_PASS_KEY_LENGTH ) )\
        && ( TRUE == client_appl_data_compare( p_uuid, temp_uuid, BLE_AUT_UUID_KEY_LENGTH ) ) )
        {
        return_value = TRUE;
        }
    else
        {
        return_value = FALSE;
        }
    }
/*feedback check result to MOTOCAN*/

return return_value;
}


/*!******************************************************************************
*
* @public
* Function name: client_appl_ble_req_authentication
* Description  : parsing the request connect server list command
*********************************************************************************/
boolean client_appl_ble_req_connect_server_list
    (
    uint32 data_size,
    uint8* data
    )
{
/*check command*/
if( 0 != data_size )
    {
    return FALSE;
    }

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
uint32 resp_data_length = 0;
uint16* data_ptr = &connected_server_list[0];

if( FALSE == check_result )
    {
    client_appl_response_can_related_data( BLE_RSP_CMD_SERVERLIST, (uint32)BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL, &client_appl_cmd_rsp_result_notify );
    }
else
    {
    for( ; index <= SUPPORT_SERVER_NUM; index++ )
        {
        if( SERVER_CONNECT == server_list_detect_infos[index].server_connect_status_default )
            {
            resp_data_length += 0x02; /*ECU code length: 2 bytes*/
            *data_ptr = clent_appl_data_swap_u16( server_list_detect_infos[index].ecu_identifier );
            data_ptr++;/*pointer movement*/
            }
        }
        client_appl_response_can_related_data( BLE_RSP_CMD_SERVERLIST, resp_data_length, (uint8*)connected_server_list, &client_appl_cmd_rsp_result_notify );
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
    uint16 server_code
    )
{
uint8 return_value = NO_SERVER_CONNECT;
uint8 index = 0x00;

for( ; index <= SUPPORT_SERVER_NUM; index++ )
    {
     if( server_list_detect_infos[index].ecu_identifier == server_code \
        && SERVER_CONNECT == server_list_detect_infos[index].server_connect_status_default )
        {
        return_value = index;
        break;
        }
    }

return return_value;
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
uint8 channel_id = 0xFF;
uint8 status_code = 0x00;
uint16 server_code = 0x0000;
uint32 interval_time = 0x00000000;

/*check data length*/
if( FALSE == is_request_interval )
    {
    /*2 bytes server + 1byte status*/
    if( 0x03 != data_size )
        {
        return FALSE;
        }
    }
else
    {
    /*2 bytes server + 1byte status + 4 bytes interval_time*/
    if( 0x07 != data_size )
        {
        return FALSE;
        }
    }

/*Check server code and status code*/
server_code = byte_merge_u16( data ) ;
status_code = *( data + 2 );
channel_id = client_appl_channel_mapping( server_code );
if( NO_SERVER_CONNECT == channel_id  )
    {
    return FALSE;
    }
#ifdef APPL_PENDING
/*the status code need confirm*/
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
        return FALSE;
        break;
    }
#endif

/*Check interval time*/
if( TRUE == is_request_interval )
    {
    interval_time = byte_merge_u32( data + 3 );
    if( 0x00000000 == interval_time )
        {
        read_dtc_infos.is_cycle_transmission = FALSE;
        read_dtc_infos.cycle_tarns_interval_time = 0x00000000;
        }
    else
        {
        /*received data uint: MS*/
        /*The minimum interval time shall be 100ms*/
        if( interval_time <= 100 )
            {
            interval_time = 100;
            }
        read_dtc_infos.is_cycle_transmission = TRUE;
        read_dtc_infos.cycle_tarns_interval_time = interval_time / 5 ;
        }
    }
else
    {
    read_dtc_infos.is_cycle_transmission = FALSE;
    read_dtc_infos.cycle_tarns_interval_time = 0x00000000;
    }
read_dtc_infos.connected_server_id = channel_id;
read_dtc_infos.current_STADTC = status_code;
set_current_conncet_server_id( channel_id );
client_appl_set_current_process_flow_step( PROCESS_FLOW_INIT_RDTCBS );

return TRUE;
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
boolean read_all_id = FALSE;
uint8 received_id_amount = 0x00;
uint8 channel_id = NO_SERVER_CONNECT;
uint16 server_code = byte_merge_u16( data );

channel_id = client_appl_channel_mapping( server_code );
if( NO_SERVER_CONNECT == channel_id )
    {
    return FALSE;
    }

if( 0x03 == data_size )
    {
    read_all_id = *( data + BLE_REQ_SERVER_CODE_LENGTH );
    if( TRUE == read_all_id )
        {
        client_appl_set_current_process_flow_step( PROCESS_FLOW_RDBCID );
        set_current_conncet_server_id( channel_id );
        read_common_identifier_infos.connected_server_id = channel_id;
        read_common_identifier_infos.common_id_list = (uint16*)support_common_data_id_list;
        read_common_identifier_infos.common_data_amount = SUPPORT_COMMON_COUNT;
        read_common_identifier_infos.current_common_data_index = 0x00;
        return TRUE;
        }
    else
        {
        return FALSE;
        }
    }
else if( 0x04 <= data_size )/*server_code + 1 id*/
    {
    received_id_amount = (uint8)( data_size - 2 ) / 2;
    client_appl_data_cpy( (uint8*)rx_comman_data_id_list, data + 2, data_size - 2 );
    client_appl_set_current_process_flow_step( PROCESS_FLOW_RDBCID );
    set_current_conncet_server_id( channel_id );
    read_common_identifier_infos.connected_server_id = channel_id;
    read_common_identifier_infos.common_id_list = rx_comman_data_id_list;
    for( index = 0; index < received_id_amount; index++ )
        {
        rx_comman_data_id_list[index] = clent_appl_data_swap_u16( rx_comman_data_id_list[index] );
        }
    read_common_identifier_infos.common_data_amount = received_id_amount;
    read_common_identifier_infos.current_common_data_index = 0x00;
    return TRUE;
    }

return FALSE;
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
boolean read_all_id = FALSE;
uint8 received_id_amount = 0x00;
uint8 channel_id = NO_SERVER_CONNECT;
uint16 server_code = byte_merge_u16( data );

channel_id = client_appl_channel_mapping( server_code );
if( NO_SERVER_CONNECT == channel_id )
    {
    return FALSE;
    }

if( 0x02 >= data_size)
{
return FALSE;
}

if( 0x03 == data_size )
    {
    read_all_id = *( data + BLE_REQ_SERVER_CODE_LENGTH );
    if( TRUE == read_all_id )
        {
        client_appl_set_current_process_flow_step( PROCESS_FLOW_MARKET );
        set_current_conncet_server_id( channel_id );
        read_loacl_market_infos.connected_server_id = channel_id;
        read_loacl_market_infos.local_id_list = (uint8*)support_market_data_id_list;
        read_loacl_market_infos.amount_local_data = SUPPORT_MARKET_COUNT;
        read_loacl_market_infos.current_local_data_index = 0x00;
        return TRUE;
        }
    else
        {
        return FALSE;
        }
    }
else
    {
    received_id_amount = (uint8)( data_size - 2 );
    client_appl_data_cpy( (uint8*)rx_market_data_id_list, data + 2, data_size - 2 );
    client_appl_set_current_process_flow_step( PROCESS_FLOW_MARKET );
    set_current_conncet_server_id( channel_id );
    read_loacl_market_infos.connected_server_id = channel_id;
    read_loacl_market_infos.local_id_list = rx_market_data_id_list;
    read_loacl_market_infos.amount_local_data = received_id_amount;
    read_loacl_market_infos.current_local_data_index = 0x00;
    return TRUE;
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
uint8 channel_id = NO_SERVER_CONNECT;
uint16 server_code = byte_merge_u16( data );
channel_id = client_appl_channel_mapping( server_code );

if( NO_SERVER_CONNECT == channel_id )
    {
    return FALSE;
    }

if( data_size !=  0x02 )/*server_code*/
    {
    return FALSE;
    }

client_appl_set_current_process_flow_step( PROCESS_FLOW_MONITOR );
set_current_conncet_server_id( channel_id );
read_loacl_market_infos.connected_server_id = channel_id;
read_local_monitor_infos.local_id_list = (uint8*)support_monitor_data_id_list;
read_local_monitor_infos.amount_local_data = SUPPORT_MONITOR_COUNT;
read_local_monitor_infos.current_local_data_index = 0x00;
read_local_monitor_infos.is_request_support_list_flow = TRUE;
read_local_monitor_infos.support_id_received_flag_array = (boolean*)support_id_received_flag;
return TRUE;
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
uint8 channel_id = NO_SERVER_CONNECT;
uint32 interval_time = 0;
uint8 received_id_amount = 0x00;

uint16 server_code = byte_merge_u16( data );
channel_id = client_appl_channel_mapping( server_code );

if( (  data_size < 0x03 ) || ( data_size > ( 0x02 + SUPPORT_MONITOR_COUNT ) ) )
    {
    return FALSE;
    }


if( NO_SERVER_CONNECT == channel_id )
    {
    return FALSE;
    }



if( TRUE != is_request_interval )
    {
    received_id_amount = (uint8)( data_size - 2 );
    read_local_monitor_infos.is_cycle_transmission = FALSE;
    read_local_monitor_infos.cycle_tarns_interval_time = 0x00000000;
    }
else
    {
    /*Inter_time_length_ 0x04 */
    /*server_code_length_0x02 */
    received_id_amount = (uint8)( data_size - 4 - 2 );
    interval_time = byte_merge_u32( data + data_size - 4 );
    if( 0x00000000 == interval_time )
        {
        read_local_monitor_infos.is_cycle_transmission = FALSE;
        read_local_monitor_infos.cycle_tarns_interval_time = 0x00000000;
        }
    else
        {
        /*received data uint: MS*/
        /*The minimum time shall be 5ms*/
        if( interval_time < 5 )
            {
            interval_time = 5;
            }
        read_local_monitor_infos.is_cycle_transmission = TRUE;
        read_local_monitor_infos.cycle_tarns_interval_time = interval_time / 5;
        }
    }

if( 0x00 < received_id_amount )
    {
    client_appl_data_cpy( (uint8*)rx_monitor_data_id_list, data + 2, received_id_amount );
    client_appl_set_current_process_flow_step( PROCESS_FLOW_MONITOR );
    set_current_conncet_server_id( channel_id );
    read_local_monitor_infos.connected_server_id = channel_id;
    set_current_conncet_server_id( channel_id );
    read_local_monitor_infos.local_id_list = rx_monitor_data_id_list;
    read_local_monitor_infos.amount_local_data = received_id_amount;
    read_local_monitor_infos.current_local_data_index = 0x00;
    read_local_monitor_infos.is_request_support_list_flow = FALSE;
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
uint16 server_code = 0x0000;

if( 0x02 != (uint8)data_size )
    {
    return FALSE;
    }

server_code = byte_merge_u16( data );
channel_id = client_appl_channel_mapping( server_code );
if( NO_SERVER_CONNECT == channel_id )
    {
    return FALSE;
    }

client_appl_set_current_process_flow_step( PROCESS_FLOW_RFFD );
set_current_conncet_server_id( channel_id );
read_freeze_frame_data_infos.connected_server_id = channel_id;
CLIENT_DEBUG("BleCmdFFD  SUCCESS");

return TRUE;
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
        set_client_app_cmd_rsp_state( CMD_RSP_DONE );
        break;

    default:
        set_client_app_cmd_rsp_state( CMD_RSP_IDLE );
        break;
    }
}



void client_appl_rsp_initial_dtc_after_ble_connect
    (
    boolean value
    )
{
static uint8 current_send_channel_id = 0;
uint8 result = 0x00;
/*const*/ uint8* data_ptr =  NULL;
uint16 data_length = 0;

for( ; current_send_channel_id <= SUPPORT_SERVER_NUM; current_send_channel_id++ )
    {
    if( SERVER_CONNECT == server_list_detect_infos[current_send_channel_id].server_connect_status_default )
        {
        client_mem_get_init_dtc_data( current_send_channel_id, &result, &data_length, &data_ptr );
        if( 0 == result )
            {
            if( current_send_channel_id == client_appl_get_last_detected_server_index() )
                {
                client_appl_response_can_related_data( BLE_RSP_CMD_MALFUNCTION, data_length, (uint8*)data_ptr, &client_appl_cmd_rsp_result_notify );
                current_send_channel_id = 0;
                return;
                }
            else
                {
                current_send_channel_id++;
                client_appl_response_can_related_data( BLE_RSP_CMD_MALFUNCTION, data_length, (uint8*)data_ptr, &client_appl_rsp_initial_dtc_after_ble_connect );
                return;
                }
            }
        else
            {
            /*current channel is valid,but no initial data*/
            if( current_send_channel_id == client_appl_get_last_detected_server_index() )
                {
                current_send_channel_id = 0;
                client_appl_response_can_related_data( BLE_RSP_CMD_MALFUNCTION, 0x00, NULL, &client_appl_cmd_rsp_result_notify );
                return;
                }
            else
                {
                current_send_channel_id++;
                client_appl_response_can_related_data( BLE_RSP_CMD_MALFUNCTION, 0x00, NULL, &client_appl_rsp_initial_dtc_after_ble_connect );
                return;
                }
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
    boolean result
    )
{
uint8 index = 0x00;
uint32 resp_data_length = 0;
uint16* data_ptr = &connected_server_list[0];

for( ; index < SUPPORT_SERVER_NUM; index++ )
    {
    if( SERVER_CONNECT == server_list_detect_infos[index].server_connect_status_default )
        {
        resp_data_length += 0x02; /*ECU code length: 2 bytes*/
        *data_ptr = clent_appl_data_swap_u16( server_list_detect_infos[index].ecu_identifier );
        data_ptr++;/*pointer movement*/
        }
    }

if( TRUE == read_dtc_infos.is_storge_init_dtc )
    {
    client_appl_response_can_related_data( BLE_RSP_CMD_SERVERLIST, resp_data_length, (uint8*)connected_server_list, &client_appl_rsp_initial_dtc_after_ble_connect );
    }
else
    {
    client_appl_response_can_related_data( BLE_RSP_CMD_SERVERLIST, resp_data_length, (uint8*)connected_server_list, &client_appl_cmd_rsp_result_notify );
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
CLIENT_DEBUG("RX-BleRequestcommand\r\n");

if( FALSE == client_appl_get_storage_init_dtc_state() )
    {
    return;
    }

if( FALSE == client_appl_get_ble_connected_state() )
    {
    if( req_command == BLE_REQ_CMD_AUTHENTICATION )
        {
        if( TRUE == client_appl_ble_req_authentication( data_size, data ) )
            {
            CLIENT_DEBUG("Authentication SUCCESS\r\n");
            client_appl_set_ble_connected_state( TRUE );
            client_appl_response_can_related_data( BLE_RSP_CMD_AUTHENTICATION, BLE_RSP_CMD_AUTHENTICATION_length, client_appl_get_ble_connected_state_ptr(), &client_appl_rsp_server_list_after_ble_connect );
            }
        else
            {
            CLIENT_DEBUG("Authentication FAILED\r\n");
            client_appl_set_ble_connected_state( FALSE );
            }
        }
    else
        {
        CLIENT_DEBUG("Failed CMD with Pass Authentication\r\n");
        }
    return;
    }

switch( req_command )
    {
    case BLE_REQ_CMD_AUTHENTICATION:
        if( TRUE == client_appl_ble_req_authentication( data_size, data ) )
            {
            client_appl_set_ble_connected_state( TRUE );
            CLIENT_DEBUG("BleCmdAuthentication SUCCESS\r\n");
            }
        else
            {
            client_appl_set_ble_connected_state( FALSE );
            CLIENT_DEBUG("Authentication FAILED\r\n");
            }
        client_appl_response_can_related_data( BLE_RSP_CMD_AUTHENTICATION, BLE_RSP_CMD_AUTHENTICATION_length, client_appl_get_ble_connected_state_ptr(), &client_appl_cmd_rsp_result_notify );
        break;

    case BLE_REQ_CMD_SERVERLIST:
        CLIENT_DEBUG("BleCmdReqServerList SUCCESS\r\n");
        client_appl_ble_rsp_connect_server_list( client_appl_ble_req_connect_server_list( data_size, data ) );
        break;

    case BLE_REQ_CMD_MALFUNCTION:
        if( FALSE == client_appl_ble_req_malfunction( FALSE, data_size, data ) )
            {
            CLIENT_DEBUG("BleCmdMalFunction FAILED\r\n");
            client_appl_response_can_related_data( BLE_RSP_CMD_MALFUNCTION, (uint32)BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL ,&client_appl_cmd_rsp_result_notify);
            }
        else
            {
            CLIENT_DEBUG("BleCmdMalFunction SUCCESS\r\n");
            }
        break;

    case BLE_REQ_CMD_MALFUNCTION_INTERVAL:
         if( FALSE == client_appl_ble_req_malfunction( TRUE, data_size, data ) )
            {
            CLIENT_DEBUG("BleCmdMalFunctionInterval FAILED\r\n");
            client_appl_response_can_related_data( BLE_RSP_CMD_MALFUNCTION, (uint32)BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL ,&client_appl_cmd_rsp_result_notify);
            }
         else
            {
            CLIENT_DEBUG("BleCmdMalFunctionInterval SUCCESS\r\n");
            }
        break;

    case BLE_REQ_CMD_VEHICLE_IDENTIFICATION:
        if( FALSE == client_appl_ble_req_vehicle_identification( data_size, data ) )
            {
            CLIENT_DEBUG("BleCmdVehicleFucntion FAILED\r\n");
            client_appl_response_can_related_data( BLE_RSP_CMD_VEHICLE_IDENTIFICATION, (uint32)BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL ,&client_appl_cmd_rsp_result_notify);
            }
        break;

    case BLE_REQ_CMD_MARKET_DATA:
        if( FALSE == client_appl_ble_req_market_data( data_size, data ) )
            {
            CLIENT_DEBUG("BleCmdMarketData FAILED\r\n");
            client_appl_response_can_related_data( BLE_RSP_CMD_MARKET_DATA, (uint32)BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL ,&client_appl_cmd_rsp_result_notify);
            }
        else
            {
            CLIENT_DEBUG("BleCmdMarketData SUCCESS\r\n");
            }
        break;

    case BLE_REQ_CMD_VEHICLE_INFORMATION:
        if( FALSE == client_appl_ble_req_vehicle_information( FALSE, data_size, data ) )
            {
            CLIENT_DEBUG("BleCmdVehicleInformation FAILED\r\n");
            client_appl_response_can_related_data( BLE_RSP_CMD_VEHICLE_INFORMATION, (uint32)BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL, &client_appl_cmd_rsp_result_notify );
            }
        else
            {
            CLIENT_DEBUG("BleCmdVehicleInformation SUCCESS\r\n");
            }
        break;

    case BLE_REQ_CMD_VEHIVLE_INFORMATION_SUPPORT_LIST:
        if( FALSE == client_appl_ble_req_vehicle_information_supproted_list( data_size, data ) )
            {
            CLIENT_DEBUG("BleCmdVehicleFucntionSupportList FAILED\r\n");
            client_appl_response_can_related_data( BLE_RSP_CMD_VEHIVLE_INFORMATION_SUPPORT_LIST, (uint32)BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL, &client_appl_cmd_rsp_result_notify );
            }
        else
            {
            CLIENT_DEBUG("BleCmdVehicleFucntionSupportList SUCCESS\r\n");
            }
        break;

    case BLE_REQ_CMD_VEHICLE_INFORMATION_INTERVAL:
        if( FALSE == client_appl_ble_req_vehicle_information( TRUE, data_size, data ) )
            {
            CLIENT_DEBUG("BleCmdVehicleInterval  FAILED\r\n");
            client_appl_response_can_related_data( BLE_RSP_CMD_VEHICLE_INFORMATION, (uint32)BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL ,&client_appl_cmd_rsp_result_notify );
            }
        else
            {
            CLIENT_DEBUG("BleCmdVehicleInterval  SUCCESS\r\n");
            }
        break;

    case BLE_REQ_CMD_FFD:
        if( FALSE == client_app_ble_req_freeze_frame_data( data_size, data ) )
            {
            CLIENT_DEBUG("BleCmdFFD  FAILED\r\n");
            client_appl_response_can_related_data( BLE_RSP_CMD_FFD, (uint32)BLE_RSP_CMD_NO_VALID_DATA_LENGTH, NULL ,&client_appl_cmd_rsp_result_notify );
            }
        else
            {
            CLIENT_DEBUG("BleCmdFFD  SUCCESS\r\n");
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
uint8* data_ptr = &response_support_monitor_data_id_list[2];
uint8 data_length = 0x00;

if( TRUE == read_local_monitor_infos.is_request_support_list_flow )
    {
    server_code = server_list_detect_infos[read_local_monitor_infos.connected_server_id].ecu_identifier;
    response_support_monitor_data_id_list[0] = (uint8)(server_code >> 8 );
    response_support_monitor_data_id_list[1] = (uint8)server_code;
    for( index = 0; index < SUPPORT_MONITOR_COUNT; index++ )
        {
        if( TRUE == read_local_monitor_infos.support_id_received_flag_array[index] )
            {
            data_length++;
            *data_ptr = read_local_monitor_infos.local_id_list[index];
            data_ptr++;
            }
        }
    }
    client_appl_response_can_related_data( BLE_RSP_CMD_VEHIVLE_INFORMATION_SUPPORT_LIST, (uint32)( data_length + 2 ), response_support_monitor_data_id_list, &client_appl_cmd_rsp_result_notify );
}


/*!******************************************************************************
*
* @public
* Function name: client_appl_send_faild_to_motocon
* Description  : this function send notify to upper layer when current process flow execute failed
*********************************************************************************/
static void client_appl_send_faild_to_motocon
    (
    client_process_flow_type process_flow
    )
{
uint32 resp_length = 0;
uint16 resp_command = 0;
uint16 current_ecu_number = 0x0000;

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
        resp_command = BLE_RSP_CMD_VEHICLE_INFORMATION;
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
    uint8 nrc
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
uint16 ecu_id = 0x0000;

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
                ecu_id = clent_appl_data_swap_u16( server_list_detect_infos[index].ecu_identifier );
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
/*shoudld reset timer when received a positive response*/
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
    uint8 nrc
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
    for( ; index <= SUPPORT_SERVER_NUM; index++ )
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
            client_mem_storage_server_code( server_list_detect_infos[read_dtc_infos.connected_server_id].ecu_identifier );
            if( PROCESS_RESULT_END == read_dtc_infos.process_result )
                {
                client_mem_send_can_data();
                }
            else
                {
                client_appl_send_faild_to_motocon( PROCESS_FLOW_INIT_RDTCBS );
                client_appl_set_current_process_flow_step( PROCESS_FLOW_IDLE );
                }
            }
        else if( is_client_app_cmd_rsp_state( CMD_RSP_DONE ) )
            {
            set_client_app_cmd_rsp_state( CMD_RSP_IDLE );
            if( TRUE == read_dtc_infos.is_cycle_transmission )
                {
                client_appl_set_delay_timer( read_dtc_infos.cycle_tarns_interval_time );
                client_appl_set_current_process_flow_step( PROCESS_FLOW_INIT_RDTCBS );
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
uint8 connect_server_id = 0xFF;
uint16 swap_server_code_u16 = 0x0000;

switch( read_dtc_infos.curr_dtc_status_frame )
    {
    case REQ_ORIGINAL_FRAME:
    case REQ_RESEND_FRAME:
        /*storage example :04 DE 23 4E A1 E0 24 A1*/
        /*04 DE: server code*/
        /*23 4E:  diagnostic trouble code*/
        /*A1: status code */
        connect_server_id = get_current_connect_server_id();
        swap_server_code_u16 = clent_appl_data_swap_u16( server_list_detect_infos[connect_server_id].ecu_identifier );
        if( FALSE == read_dtc_infos.is_storge_init_dtc )
        {
        client_mem_storage_init_dtc_data( connect_server_id, (uint16)0X02, (uint8*)&swap_server_code_u16 );
        client_mem_storage_init_dtc_data( connect_server_id, resp_lenth, ( resp_data + 1 ));
        }
        else
        {
        client_mem_storage_init_dtc_data( connect_server_id, (uint16)0X02, (uint8*)&swap_server_code_u16 );
        client_mem_storage_identifier_data( get_current_connect_server_id(), resp_lenth, ( resp_data + 1 ) );
        }
        read_dtc_infos.process_result = PROCESS_RESULT_END;
        break;

    case REQ_DEFAULT_SESSION_FRAME:
        read_dtc_infos.next_req_dtc_status_frame = REQ_ORIGINAL_FRAME;
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
uint8 nrc
)
{
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
        read_dtc_infos.next_req_dtc_status_frame = PROCESS_RESULT_NRC_GR;
        break;

    case REQ_RESEND_FRAME:
        read_dtc_infos.next_req_dtc_status_frame = PROCESS_RESULT_NRC_GR;
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
uint16 common_identifier = 0x0000;

switch( read_common_identifier_infos.next_req_frame )
    {
    case REQ_ORIGINAL_FRAME:
        common_identifier = read_common_identifier_infos.common_id_list[read_common_identifier_infos.current_common_data_index];
        client_dcm_req_common_indentifier( read_common_identifier_infos.connected_server_id, common_identifier );
        client_appl_request_status_change();
        break;

    case REQ_DEFAULT_SESSION_FRAME:
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
            if( 0x02 < client_mem_get_iden_data_storage_length() )
                {
                #if (APPL_DEBUG )
                client_appl_debug_printf( read_common_identifier_infos.process_result );
                #endif

                /*have been already all identifier data of current server*/
                client_mem_storage_server_code( server_list_detect_infos[read_common_identifier_infos.connected_server_id].ecu_identifier );
                client_mem_send_can_data();
                }
            else
                {
                client_appl_send_faild_to_motocon( PROCESS_FLOW_RDBCID );
                client_appl_set_current_process_flow_step( PROCESS_FLOW_IDLE );
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
uint16 resp_identifier = 0x0000;

switch( read_common_identifier_infos.curr_req_frame )
    {
    case REQ_ORIGINAL_FRAME:
    case REQ_RESEND_FRAME:
         resp_identifier = (uint16)( resp_data[BYTE_NUM_1] << 8 | resp_data[BYTE_NUM_2] );
         if( resp_identifier == read_common_identifier_infos.common_id_list[read_common_identifier_infos.current_common_data_index] )
            {
            client_mem_storage_identifier_data( read_common_identifier_infos.connected_server_id, resp_lenth - 1, resp_data + 1 );
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
uint8 nrc
)
{
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
        read_common_identifier_infos.process_result = PROCESS_RESULT_NRC_GR;
        break;

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
uint8 market_id = 0x00;

switch( read_loacl_market_infos.next_req_frame )
    {
    case REQ_ORIGINAL_FRAME:
        market_id = read_loacl_market_infos.local_id_list[read_loacl_market_infos.current_local_data_index];
        client_dcm_req_local_indentifier( read_loacl_market_infos.connected_server_id, market_id );
        read_loacl_market_infos.curr_req_frame = read_loacl_market_infos.next_req_frame;
        read_loacl_market_infos.next_req_frame = REQ_NO_FRAME;;
        break;

    case REQ_DEFAULT_SESSION_FRAME:
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
            if( 0x02 < client_mem_get_iden_data_storage_length() )
                {
                #if (APPL_DEBUG )
                client_appl_debug_printf( read_loacl_market_infos.process_result );
                #endif
                /*step 1:response data to upper layer and reset buff*/
                client_mem_storage_server_code( server_list_detect_infos[read_loacl_market_infos.connected_server_id].ecu_identifier );
                client_mem_send_can_data();
                }
            else
                {
                client_appl_send_faild_to_motocon( PROCESS_FLOW_MARKET );
                client_appl_set_current_process_flow_step( PROCESS_FLOW_IDLE );
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
switch( read_loacl_market_infos.curr_req_frame )
    {
    case REQ_ORIGINAL_FRAME:
    case REQ_RESEND_FRAME:
        resp_identifier = resp_data[BYTE_NUM_1];
        if(resp_identifier == read_loacl_market_infos.local_id_list[read_loacl_market_infos.current_local_data_index])
            {
            client_mem_storage_identifier_data( get_current_connect_server_id(), resp_lenth - 1, resp_data + 1 );
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
        read_loacl_market_infos.next_req_frame = REQ_ORIGINAL_FRAME;
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
uint8 nrc
)
{
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
        read_loacl_market_infos.process_result = PROCESS_RESULT_NRC_GR;
        break;

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
uint8 monitor_id = 0x0000;

switch( read_local_monitor_infos.next_req_frame )
    {
    case REQ_ORIGINAL_FRAME:
        monitor_id = read_local_monitor_infos.local_id_list[read_local_monitor_infos.current_local_data_index];
        client_dcm_req_local_indentifier( read_local_monitor_infos.connected_server_id, monitor_id );
        read_local_monitor_infos.curr_req_frame = read_local_monitor_infos.next_req_frame;
        read_local_monitor_infos.next_req_frame = REQ_NO_FRAME;;
        break;

    case REQ_DEFAULT_SESSION_FRAME:
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
            else if( 0x02 < client_mem_get_iden_data_storage_length() )
                {
                client_mem_storage_server_code( server_list_detect_infos[read_local_monitor_infos.connected_server_id].ecu_identifier );
                client_mem_send_can_data();
                }
           else
                {
                client_appl_send_faild_to_motocon( PROCESS_FLOW_MONITOR );
                }
            }
        else if( is_client_app_cmd_rsp_state( CMD_RSP_DONE ) )
            {
            set_client_app_cmd_rsp_state( CMD_RSP_IDLE );
            if( TRUE == read_local_monitor_infos.is_cycle_transmission )
                {

                client_appl_set_delay_timer( read_local_monitor_infos.cycle_tarns_interval_time );
                client_appl_set_current_process_flow_step( PROCESS_FLOW_MONITOR );
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
switch( read_local_monitor_infos.curr_req_frame )
    {
    case REQ_ORIGINAL_FRAME:
    case REQ_RESEND_FRAME:
        if( resp_data[1] == read_local_monitor_infos.local_id_list[read_local_monitor_infos.current_local_data_index] )
            {
            client_mem_storage_identifier_data( get_current_connect_server_id(), resp_lenth - 1 , resp_data  +1 );
            read_local_monitor_infos.process_result = PROCESS_RESULT_SUCCESS;
            if( read_local_monitor_infos.current_local_data_index == read_local_monitor_infos.amount_local_data - 1 )
                {
                read_local_monitor_infos.process_result = PROCESS_RESULT_END;
                }
            if( TRUE == read_local_monitor_infos.is_request_support_list_flow )
                {
                read_local_monitor_infos.support_id_received_flag_array[read_local_monitor_infos.current_local_data_index] = TRUE;
                }
            }
        else
            {
            read_local_monitor_infos.process_result = PROCESS_RESULT_INVALID_DATA;
            }
        break;

    case REQ_DEFAULT_SESSION_FRAME:
        read_local_monitor_infos.next_req_frame = REQ_ORIGINAL_FRAME;
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
uint8 nrc
)
{
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
        read_local_monitor_infos.process_result = PROCESS_RESULT_NRC_GR;
        break;

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
uint8 req_identifier = 0x00;

switch( read_freeze_frame_data_infos.next_request_frame )
{
    case REQ_ORIGINAL_FRAME:
        client_dcm_req_freeze_frame_data( read_freeze_frame_data_infos.connected_server_id, read_freeze_frame_data_infos.current_freeze_frame_number, 0x00);
        client_appl_req_frame_status_switch();
        break;

    case REQ_DEFAULT_SESSION_FRAME:
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
            /*have been already all identifier data of current server*/
            client_mem_storage_server_code( server_list_detect_infos[read_loacl_market_infos.connected_server_id].ecu_identifier );
            client_mem_send_can_data();
            }
         else
            {
            client_appl_send_faild_to_motocon( PROCESS_FLOW_RFFD );
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
        client_appl_set_next_ffd_frame_frame( read_freeze_frame_data_infos.prev_request_frame );
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
            client_mem_storage_identifier_data( read_freeze_frame_data_infos.connected_server_id, resp_lenth, resp_data );
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
    client_mem_storage_identifier_data( read_freeze_frame_data_infos.connected_server_id, resp_lenth, resp_data );
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
    uint8 nrc
    )
{
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
