/*--------------------------------------------------------------------
* @file client_dcm_appl.c
* @brief client diagnostic application management
*
* This file shall handle the service comsequence flow, store and transmit
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

/*Micro switch for DEBUG*/
#define APPL_DEBUG                                   (TRUE)
#define APPL_PENDING                                 (TRUE)

/*--------------------------------------------------------------------
                            VARIABLES
--------------------------------------------------------------------*/
/*define yamaha diagnostic tools connected state*/
static boolean ydt_connected_state = FALSE;
/*define BLE conneted state*/
static boolean ble_connected_state = FALSE;
uint16 delay_timer_count   =  0x0000;
uint8 current_connect_server_id   = 0xFF;
client_process_flow_type client_process_flow_state = PROCESS_FLOW_IDLE;
static boolean is_read_init_dtc =  FALSE;

/*for server list detect*/
static uint8 default_server_list_detect_amount = 0x00;
static uint8 extend_server_list_detect_amount = 0x00;
static const uint16 server_ecu_identifier[SUPPORT_SERVER_NUM] = SERVER_ECU_LIST;

client_appl_server_detect_step_type server_detect_step = SERVER_DETECT_INIT;
client_appl_server_list_detect_type server_list_detect[SUPPORT_SERVER_NUM] = {0};



uint8 current_request_freeze_frame_id_list[20] = {0};
const uint16 common_data_id_list[SUPPORT_COMMON_COUNT] = { 0xF18A, 0xF18C, 0xF190, 0xF192, 0xF194 };
const uint8 local_data_id_list[SUPPORT_MARKET_COUNT]=
    { 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,
      0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
      0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77,
      0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F
    };

client_appl_read_dtc_infos_type read_dtc_infos = { 0 };
client_appl_detect_connected_server_infos_type detect_connected_server_infos ={0};
client_appl_read_data_by_comon_id_type read_common_identifier_infos = {0};
client_appl_read_data_by_local_id_type read_loacl_market_infos = {0};
client_appl_read_data_by_local_id_type read_local_monitor_infos = {0};
client_appl_read_freeze_frame_data_type read_freeze_frame_data_infos = {0};



#if( APPL_DEBUG )
const char* print_header_0 = "Server connect detect flow(default session)";
const char* print_header_1 = "Server connected detect flow(extend session)";
const char* print_header_2 = "Read DTC status data flow";
const char* print_header_3 = "Read Common Identifier data flow";
const char* print_header_4 = "Read Local Market data flow";
const char* print_header_5 = "Read Local Monitor data flow";
const char* print_header_6 = "Read Freeze Frame data flow";

const char* print_end_0 = " NO RESULT";
const char* print_end_1 = " process SUCCESS";
const char* print_end_2 = " process fail : TIMEOUT";
const char* print_end_3 = " process fail : RSEND OVER 3 TIMES";
const char* print_end_4 = " process fail : SERVICE NOT SUPPORT";
const char* print_end_5 = " Process fail : GENERAL REJECT";
const char* print_end_6 = " Process fail : INVALID DATA";
const char* print_end_7 = " Process END";

char** print_header[SUPPORT_FUCNTION_NUMS] = {0};
char** print_end[PROCESS_RESULT_MAX] = {0};
#endif

/*------------------------------------------------------------------
*                          MACROS
-------------------------------------------------------------------*/
#define set_current_conncet_server_id( value )       ( current_connect_server_id = value )
#define get_current_connect_server_id()              ( current_connect_server_id )
#define decrease_delay_timer()                       ( delay_timer_count -- )


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


/*for Read dtc status infos*/
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



/*for common indentifier data*/
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



/*for local indentifier data-market*/
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


/*for local indentifier data - monitor*/
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
* Description:  Set current yamaha diagnsotic tools connnect state
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
* Description:  Get current yamaha diagnsotic tools connnect state
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
* Function name: client_appl_set_ble_connected_state
* Description:  Set current ble connnect state
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
* Function name: client_appl_set_ble_connected_state
* Description:  Get current ble connnect state
*********************************************************************/
static boolean client_appl_get_ble_connected_state
    (
    void
    )
{
return ble_connected_state;
}

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
* Function name: client_appl_get_service_command
* Description:  Rarsing the receiving command an handle data
* Usage: Called upper lyer
*********************************************************************/
void client_appl_get_service_command
    (
    uint16 command_code,
    uint16 command_length,
    uint8* command_data
    )
{
/*Pending*/
#if (APPL_PENDING)
switch( command_code )
    {
    case 0x1000:
        break;

    case 0x1001:
        break;

    default:
        break;
    }
#endif
}


/*!*******************************************************************
* @public
* Function name: client_appl_enter_ydt_handler
* Description:   this function will disconnect the diagnostic server
with all servers
*********************************************************************/
static boolean client_appl_enter_ydt_handler
    (
    void
    )
 {
/*Pending*/
#if(APPL_PENDING)
#endif
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
uint8 return_value = no_server_connected;

for( ; index < SUPPORT_SERVER_NUM; index++ )
    {
    if( SUPPORT_SERVER_NUM == index)
        {
        return no_server_connected;
        }
    else if( server_list_detect[index].server_connect_status_default == SERVER_CONNECT )
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
uint8 return_value = no_server_connected;

for( index++ ; index < SUPPORT_SERVER_NUM; index++ )
    {
    if( SUPPORT_SERVER_NUM == index)
        {
        return no_server_connected;
        }
    else if( server_list_detect[index].server_connect_status_default == SERVER_CONNECT )
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
* Note: In general, this fucntion shall be executed after call function client_appl_get_first_connected_server_id
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
        set_current_conncet_server_id( no_server_connected );
        /*init structure*/
        /*clear the read_dtc_infos except the read_dtc_infos.is_storge_init_dtc*/
        (void)memset( &read_dtc_infos, 0x00, sizeof( read_dtc_infos ) -1);
        (void)memset( &read_common_identifier_infos, 0x00, sizeof( read_common_identifier_infos ));
        (void)memset( &read_loacl_market_infos, 0x00, sizeof( read_loacl_market_infos ) );
        (void)memset( &read_local_monitor_infos, 0x00, sizeof( read_local_monitor_infos ));
        (void)memset( &read_freeze_frame_data_infos,0x00, sizeof( read_freeze_frame_data_infos ));
        break;

    case PROCESS_FLOW_DETECT_SERVER:
        client_appl_set_delay_timer( 500 );/*5ms*200 = 1s*/
        set_current_conncet_server_id( SUPPORT_SERVER_NUM );
        break;

    case PROCESS_FLOW_EXTEND_SERVER:
        set_current_conncet_server_id( client_appl_get_first_connected_server_id() );
        detect_connected_server_infos.connected_server_id = get_current_connect_server_id();
        detect_connected_server_infos.peocess_result = PROCESS_RESULT_INIT;
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
        read_dtc_infos.peocess_result = PROCESS_RESULT_INIT;
        break;

    case PROCESS_FLOW_RDBCID:
        read_common_identifier_infos.connected_server_id = get_current_connect_server_id();
        read_common_identifier_infos.common_id_list = common_data_id_list;
        read_common_identifier_infos.common_data_amount = SUPPORT_COMMON_COUNT;
        read_common_identifier_infos.current_common_data_index = 0x00;
        read_common_identifier_infos.peocess_result = PROCESS_RESULT_INIT;
        read_common_identifier_infos.curr_req_frame = REQ_NO_FRAME;
        read_common_identifier_infos.next_req_frame = REQ_ORIGINAL_FRAME;
        read_common_identifier_infos.receive_SNS_timer = 0x00;
        read_common_identifier_infos.resend_timer = 0x00;
        break;

    case PROCESS_FLOW_MARKET:
        read_loacl_market_infos.connected_server_id = get_current_connect_server_id();
        read_loacl_market_infos.local_id_list = local_data_id_list;
        read_loacl_market_infos.amount_local_data = SUPPORT_MARKET_COUNT;
        read_loacl_market_infos.current_local_data_index = 0x00;
        read_loacl_market_infos.peocess_result = PROCESS_RESULT_INIT;
        read_loacl_market_infos.curr_req_frame = REQ_NO_FRAME;
        read_loacl_market_infos.next_req_frame = REQ_ORIGINAL_FRAME;
        read_loacl_market_infos.receive_SNS_timer = 0x00;
        read_loacl_market_infos.resend_timer = 0x00;
        break;

    case PROCESS_FLOW_MONITOR:
        read_local_monitor_infos.connected_server_id = get_current_connect_server_id();
        read_local_monitor_infos.local_id_list = local_data_id_list;
        read_local_monitor_infos.amount_local_data = SUPPORT_MARKET_COUNT;
        read_local_monitor_infos.current_local_data_index = 0x00;
        read_local_monitor_infos.peocess_result = PROCESS_RESULT_INIT;
        read_local_monitor_infos.curr_req_frame = REQ_NO_FRAME;
        read_local_monitor_infos.next_req_frame = REQ_ORIGINAL_FRAME;
        read_local_monitor_infos.receive_SNS_timer = 0x00;
        read_local_monitor_infos.resend_timer = 0x00;
        break;

    case PROCESS_FLOW_RFFD:
        read_freeze_frame_data_infos.connected_server_id = get_current_connect_server_id();
        read_freeze_frame_data_infos.request_id_list = current_request_freeze_frame_id_list;
        read_freeze_frame_data_infos.requset_id_list_amount = 0x00;
        read_freeze_frame_data_infos.current_freeze_frame_number = 0x01;
        read_freeze_frame_data_infos.current_request_id = 0x00;
        read_freeze_frame_data_infos.curr_request_frame = REQ_NO_FRAME;
        read_freeze_frame_data_infos.prev_request_frame = REQ_NO_FRAME;
        read_freeze_frame_data_infos.next_request_frame = REQ_ORIGINAL_FRAME;
        read_freeze_frame_data_infos.receive_SNS_timer = 0x00;
        read_freeze_frame_data_infos.resend_timer = 0x00;
        read_freeze_frame_data_infos.peocess_result = PROCESS_RESULT_INIT;
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
* Description: this function shall intial moudle
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
    server_list_detect[index].server_id = index;
    server_list_detect[index].ecu_identifier = server_ecu_identifier[index];
    server_list_detect[index].server_connect_status_default = SERVER_UN_CONNECT;
    server_list_detect[index].server_connect_status_extend = SERVER_UN_CONNECT;
    }

server_detect_step = SERVER_DETECT_INIT;
default_server_list_detect_amount = 0x00;
extend_server_list_detect_amount = 0x00;

is_read_init_dtc = FALSE;

/*the ydt connect state is sync with atucal app state*/
/*we set ydt_connect_state to FALSE and */
ydt_connected_state = FALSE;
ble_connected_state = TRUE;

/*init structure infos*/
(void)memset( &read_dtc_infos, 0x00, sizeof( read_dtc_infos ));
(void)memset( &read_loacl_market_infos, 0x00, sizeof( read_loacl_market_infos ) );
(void)memset( &read_local_monitor_infos, 0x00, sizeof( read_local_monitor_infos ));
(void)memset( &read_freeze_frame_data_infos,0x00, sizeof( read_freeze_frame_data_infos ));
(void)memset( &read_common_identifier_infos, 0x00, sizeof( read_common_identifier_infos ));
(void)memset( &detect_connected_server_infos, 0x00, sizeof( detect_connected_server_infos ));


/*After IG-ON, Frist enter detect connected server process flow*/
client_appl_set_current_process_flow_step( PROCESS_FLOW_DETECT_SERVER );

/*for debug display*/
#if(APPL_DEBUG)
print_end[0] = print_end_0;
print_end[1] = print_end_1;
print_end[2] = print_end_2;
print_end[3] = print_end_3;
print_end[4] = print_end_4;
print_end[5] = print_end_5;
print_end[6] = print_end_6;
print_end[7] = print_end_7;
print_header[0] = print_header_0;
print_header[1] = print_header_1;
print_header[2] = print_header_2;
print_header[3] = print_header_3;
print_header[4] = print_header_4;
print_header[5] = print_header_5;
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
/*delay timer*/
if( TRUE == client_appl_get_ydt_connect_state() )
    {
    if( PROCESS_FLOW_IDLE != client_process_flow_state )
        {
        /*Reserved: Ther shall send connet ydt notify to upper layer*/
        client_appl_set_current_process_flow_step( PROCESS_FLOW_IDLE );
        client_appl_enter_ydt_handler();
        }
    return;
    }

if( 0x0000 != delay_timer_count )
    {
    decrease_delay_timer();
    }
else
    {
    if( client_process_flow_state < SUPPORT_FUCNTION_NUMS )
        {
        client_process_flow_handler[client_process_flow_state].appl_period_func();
        }
    }
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_positive_response_dispatch
* Description  : this function process the postive response data when handle hen handle process flow
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
uint16 ecu_id = 0x0000;

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
        /*get connect server amount and send data to app*/
        for( index = 0x00; index < SUPPORT_SERVER_NUM; index++ )
            {
            if( SERVER_CONNECT == server_list_detect[index].server_connect_status_default )
                {
                default_server_list_detect_amount++;
                ecu_id = clent_appl_data_swap_u16( server_list_detect[index].ecu_identifier );
                client_mem_storage_identifier_data( SUPPORT_SERVER_NUM, BYTE_NUM_2,&ecu_id );
                #if(APPL_DEBUG)
                PRINTF("Client detect channel %d servers-default session\r\n", index );
                #endif
                }
            }

        /*contiune to detect all server`s dtc when connected server*/
        if( 0x00 < default_server_list_detect_amount )
            {
            #if(APPL_DEBUG)
             PRINTF("Client detect %d connect servers-default session \r\n\r\n", default_server_list_detect_amount );
             #endif
             if( TRUE == client_appl_get_ble_connected_state() )
                {
                client_mem_send_can_data();
                }
             client_mem_reset_data();
             client_appl_set_current_process_flow_step( PROCESS_FLOW_EXTEND_SERVER );
            }
        else
            {
            client_appl_set_current_process_flow_step( PROCESS_FLOW_IDLE );
            #if(APPL_DEBUG)
            PRINTF(" Client detect No server connected-default session\r\n\r\n");
            #endif
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
* Description  : this function process the postive response data when handle hen handle process flow detect server list
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

if( SERVER_UN_CONNECT == server_list_detect[channel_id].server_connect_status_default )
    {
    server_list_detect[channel_id].server_connect_status_default = SERVER_CONNECT;
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

if( PROCESS_RESULT_INIT != detect_connected_server_infos.peocess_result )
    {
    if( no_server_connected == client_appl_get_next_connected_server_id() )
        {
        /*Have been read all detected server*/
        for( index = 0; index < SUPPORT_SERVER_NUM; index++ )
            {
            if( SERVER_CONNECT == server_list_detect[index].server_connect_status_extend )
                {
                extend_server_list_detect_amount++;
                ecu_id = clent_appl_data_swap_u16( server_list_detect[index].ecu_identifier );
                client_mem_storage_identifier_data( SUPPORT_SERVER_NUM, BYTE_NUM_2,&ecu_id );
                #if(APPL_DEBUG)
                PRINTF("Client detect channel %d servers-extend session\r\n", index );
                #endif
                }
            }

       /*analysic the result*/
        if( 0x00 < extend_server_list_detect_amount )
            {
            if( TRUE == client_appl_get_ble_connected_state() )
                {
                client_mem_send_can_data();
                }
            client_mem_reset_data();

            set_current_conncet_server_id( client_appl_get_first_connected_server_id() );
            client_appl_set_current_process_flow_step( PROCESS_FLOW_INIT_RDTCBS );
            #if(APPL_DEBUG)
            PRINTF("Client detect %d connect servers-extend session \r\n\r\n", extend_server_list_detect_amount );
            #endif
            }
        else
            {
            /*Handle all servers and all servers does send positive response*/
            /*client shall enter detect server process flow again and shall not notify to yamaha app*/
            for( index = 0; index < SUPPORT_SERVER_NUM; index++ )
                {
                server_list_detect[index].server_connect_status_default = SERVER_UN_CONNECT;
                server_list_detect[index].server_connect_status_extend = SERVER_UN_CONNECT;
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
        detect_connected_server_infos.peocess_result = PROCESS_RESULT_INIT;
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
* Description  : this function process the postive response data when handle hen handle process flow detect server list
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
    detect_connected_server_infos.peocess_result = PROCESS_RESULT_INVALID_DATA;
    return;
    }

switch( detect_connected_server_infos.curr_dtc_status_frame )
    {
    case REQ_ORIGINAL_FRAME:
    case REQ_RESEND_FRAME:
    case REQ_NRC_RSEND_FRAME:
        server_list_detect[channel_id].server_connect_status_extend = SERVER_CONNECT;
        detect_connected_server_infos.peocess_result = PROCESS_RESULT_SUCCESS;
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
            detect_connected_server_infos.peocess_result = PROCESS_RESULT_NRC_GR;
            }
        break;

    case REQ_RESEND_FRAME:
        detect_connected_server_infos.peocess_result = PROCESS_RESULT_NRC_GR;
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
                detect_connected_server_infos.peocess_result = RROCESS_RESULE_RESEND_OVERFLOW;
                }
            else
                {
                detect_connected_server_infos.next_req_dtc_status_frame = REQ_NRC_RSEND_FRAME;
                }
            }
         else
            {
            detect_connected_server_infos.peocess_result = PROCESS_RESULT_NRC_GR;
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
            detect_connected_server_infos.peocess_result = RROCESS_RESULE_RESEND_OVERFLOW;
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
* Description  : calculate the initial dtc data storage state according the mem state
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
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_get_storage_init_dtc_state
* Description  : get the current storage init dtc data state
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
            /*if inital DTC is not storage ,STADTC is set as A1*/
            read_dtc_infos.current_STADTC = DCM_18h_INIT_STADTC;
            client_dcm_req_read_dtc_status_code( read_dtc_infos.connected_server_id, read_dtc_infos.current_STADTC );
            }
        else
            {
            /*when received a STADTC from upper layer,STADTC is set as received value*/
            read_dtc_infos.current_STADTC = 0xA2;
            client_dcm_req_read_dtc_status_code( read_dtc_infos.connected_server_id, read_dtc_infos.current_STADTC );
            }
        client_appl_read_initial_dtc_frame_status_change();
        break;

    case REQ_DEFAULT_SESSION_FRAME:
        client_dcm_req_diagnostic_extend_session( read_dtc_infos.connected_server_id );
        client_appl_read_initial_dtc_frame_status_change();
        break;

    case REQ_RESEND_FRAME:
        if( FALSE == read_dtc_infos.is_storge_init_dtc )
            {
            /*if inital DTC is not storage ,STADTC is set as A1*/
            client_dcm_req_read_dtc_status_code( read_dtc_infos.connected_server_id, read_dtc_infos.current_STADTC );
            }
        else
            {
            /*when received a STADTC from upper layer,STADTC is set as defined value*/
            client_dcm_req_read_dtc_status_code( read_dtc_infos.connected_server_id, read_dtc_infos.current_STADTC );
            }
        client_appl_read_initial_dtc_frame_status_change();
        break;

        default:
            /* do nothing */
            break;
    }

/*shall send the process result to upper layer whehter process is success*/
/*shall re-init related status flags*/
/*shall set the next process flow*/
if( PROCESS_RESULT_INIT != read_dtc_infos.peocess_result )
    {
    #if (APPL_DEBUG )
    client_appl_debug_printf( read_dtc_infos.peocess_result );
    #endif
    /*send current server datas to yamaha app*/
    client_mem_send_can_data();
    client_mem_reset_data();

    /*Check anohter server is exist?*/
    if( no_server_connected == client_appl_get_next_connected_server_id() )
        {
        /*current flow is end and have been request all servers*/
        if( !read_dtc_infos.is_storge_init_dtc )
            {
             /*Check whether initial DTC data is read*/
            client_appl_calc_storage_init_dtc_state();
            }

        if( ( TRUE == read_dtc_infos.is_cycle_transmission ) && ( 0x00 < read_dtc_infos.cycle_tarns_interval_time ) )
            {
            /*enter period transmission mode*/
            client_appl_set_delay_timer( read_dtc_infos.cycle_tarns_interval_time );
            set_current_conncet_server_id( client_appl_get_first_connected_server_id() );
            client_appl_set_current_process_flow_step( PROCESS_FLOW_INIT_RDTCBS );
            }
        else
            {
            /*setting the next process flow to idle when read all server*/
            //client_appl_set_current_process_flow_step( PROCESS_FLOW_IDLE );

            /*for test cycle transmission---debug*/
            set_current_conncet_server_id( client_appl_get_first_connected_server_id() );
            client_appl_set_current_process_flow_step( PROCESS_FLOW_INIT_RDTCBS );

            read_dtc_infos.is_cycle_transmission = TRUE;
            read_dtc_infos.cycle_tarns_interval_time = 1000;
            }
        }
    else
        {
        /*Handle the next server*/
        set_current_conncet_server_id( client_appl_get_next_connected_server_id() );
        client_appl_set_current_process_flow_step( PROCESS_FLOW_INIT_RDTCBS );
        }
    }
}



/*!******************************************************************************
*
* @public
* Function name: client_appl_read_initial_dtc_status_positive_response_handler
* Description  : this function process the postive response data when handle hen handle process flow Read_DTC_infos
* usage        : called by client_diag_response_dispatch_handler_5ms
*********************************************************************************/
static void client_appl_read_initial_dtc_status_positive_response_handler
(
 uint8 * resp_data,
 uint16 resp_lenth,
 uint8 channel_id
)
{
switch( read_dtc_infos.curr_dtc_status_frame )
    {
    case REQ_ORIGINAL_FRAME:
    case REQ_RESEND_FRAME:
        /*When received a valid datas*/
        /*step1: stroge data here*/
        /**********func************/
        if( FALSE == read_dtc_infos.is_storge_init_dtc )
        {
        client_mem_storage_init_dtc_data( get_current_connect_server_id(), resp_lenth, resp_data );
        }
        else
        {
        client_mem_storage_identifier_data( get_current_connect_server_id(), resp_lenth, resp_data );
        }
        read_dtc_infos.peocess_result = PROCESS_RESULT_SUCCESS;
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
                read_dtc_infos.peocess_result = PROCESS_RESULT_NRC_SNS;
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
            read_dtc_infos.peocess_result = PROCESS_RESULT_NRC_GR;
            }
        else
            {
            read_dtc_infos.peocess_result = PROCESS_RESULT_NRC_GR;
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
        read_dtc_infos.peocess_result = PROCESS_RESULT_NRC_GR;
        break;

    case REQ_RESEND_FRAME:
        read_dtc_infos.resend_timer++;
        if( RESEND_MAX_CONUNT > read_dtc_infos.resend_timer )
            {
            read_dtc_infos.next_req_dtc_status_frame = REQ_RESEND_FRAME;
            }
        else
            {
            read_dtc_infos.peocess_result = RROCESS_RESULE_RESEND_OVERFLOW;
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
//read_common_identifier_infos.resend_timer = 0x00;
//read_common_identifier_infos.receive_SNS_timer = 0x00;
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

/*shall send the process result to upper layer whehter process is success*/
/*shall re-init related status flags*/
/*shall set the next process flow*/
if( PROCESS_RESULT_INIT != read_common_identifier_infos.peocess_result )
    {
    read_common_identifier_infos.receive_SNS_timer =0x00;
    read_common_identifier_infos.resend_timer = 0x00;
    #if (APPL_DEBUG )
         client_appl_debug_printf( read_common_identifier_infos.peocess_result );
   #endif
    if( read_common_identifier_infos.current_common_data_index == read_common_identifier_infos.common_data_amount - 1 )
        {
        /*have been alraedy all identifier data of current server*/
        client_mem_send_can_data();
        client_mem_reset_data();
        if( no_server_connected == client_appl_get_next_connected_server_id() )
            {
            /*set process state to Idle when request all servers*/
            client_appl_set_current_process_flow_step(PROCESS_FLOW_IDLE);
            }
        else
            {
            /*requset the next server*/
            set_current_conncet_server_id( client_appl_get_next_connected_server_id() );
            client_appl_set_current_process_flow_step( PROCESS_FLOW_RDBCID );
            }
        }
    else
        {
        /*go on request the next common indentifier data*/
        read_common_identifier_infos.current_common_data_index++;
        read_common_identifier_infos.peocess_result = PROCESS_RESULT_INIT;
        read_common_identifier_infos.next_req_frame = REQ_ORIGINAL_FRAME;
        read_common_identifier_infos.curr_req_frame = REQ_NO_FRAME;
        read_common_identifier_infos.receive_SNS_timer =0x00;
        read_common_identifier_infos.resend_timer = 0x00;
        }
    }
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_read_data_by_common_indentifier_postive_response_handler
* Description  : this function process the postive response data when handle hen handle process flow Read_Common
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
            client_mem_storage_identifier_data( read_common_identifier_infos.connected_server_id, resp_lenth, resp_data );
            read_common_identifier_infos.peocess_result = PROCESS_RESULT_SUCCESS;
            }
         else
            {
            read_common_identifier_infos.peocess_result = PROCESS_RESULT_INVALID_DATA;
            }
        break;

    case REQ_DEFAULT_SESSION_FRAME:
        if( DCM_10h_DEFAULT_ID == resp_data[BYTE_NUM_1] )
            {
            read_common_identifier_infos.next_req_frame = REQ_ORIGINAL_FRAME;
            }
        else
            {
            read_common_identifier_infos.peocess_result = PROCESS_RESULT_INVALID_DATA;
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
                read_common_identifier_infos.peocess_result = PROCESS_RESULT_NRC_SNS;
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
            read_common_identifier_infos.peocess_result = PROCESS_RESULT_NRC_GR;
            }
        else
            {
            read_common_identifier_infos.peocess_result = PROCESS_RESULT_INVALID_DATA;
            }
        break;

    case REQ_DEFAULT_SESSION_FRAME:
        read_common_identifier_infos.peocess_result = PROCESS_RESULT_NRC_GR;
        break;

    case REQ_RESEND_FRAME:
        read_common_identifier_infos.peocess_result = PROCESS_RESULT_NRC_GR;
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
        read_common_identifier_infos.peocess_result = PROCESS_RESULT_NRC_GR;
        break;

    case REQ_RESEND_FRAME:
       read_common_identifier_infos.resend_timer++;
       if( RESEND_MAX_CONUNT > read_common_identifier_infos.resend_timer )
             {
             read_common_identifier_infos.next_req_frame = REQ_RESEND_FRAME;
             }
        else
             {
             read_common_identifier_infos.peocess_result = RROCESS_RESULE_RESEND_OVERFLOW;
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

/*shall send the process result to upper layer whehter process is success*/
/*shall re-init related status flags*/
/*shall set the next process flow*/
if( PROCESS_RESULT_INIT != read_loacl_market_infos.peocess_result )
    {
    #if (APPL_DEBUG )
    client_appl_debug_printf( read_loacl_market_infos.peocess_result );
    #endif

    if( read_loacl_market_infos.current_local_data_index == read_loacl_market_infos.amount_local_data - 1 )
        {
        /*have been alraedy all identifier data of current server*/

        /*step 1:response data to upper layer and reset buff*/
        client_mem_send_can_data();
        client_mem_reset_data();

        if( no_server_connected == client_appl_get_next_connected_server_id() )
            {
            /*set process state to Idle when request all servers*/
            client_appl_set_current_process_flow_step(PROCESS_FLOW_IDLE);
            }
        else
            {
            /*requset the next server*/
            set_current_conncet_server_id( client_appl_get_next_connected_server_id() );
            client_appl_set_current_process_flow_step( PROCESS_FLOW_MARKET );
            }
        /*step3: setting the next process flow*/
        }
    else
        {
        /*go on request the next common indentifier data*/
        read_loacl_market_infos.current_local_data_index++;
        read_loacl_market_infos.peocess_result = PROCESS_RESULT_INIT;
        read_loacl_market_infos.next_req_frame = REQ_ORIGINAL_FRAME;
        read_loacl_market_infos.curr_req_frame = REQ_NO_FRAME;
        read_loacl_market_infos.receive_SNS_timer =0x00;
        read_loacl_market_infos.resend_timer = 0x00;
        }
    }

}

/*!******************************************************************************
*
* @public
* Function name: client_appl_read_data_by_local_indentifier_market_postive_response_handler
* Description  : this function process the postive response data when handle hen handle process flow Read_Market
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
      //  if(resp_identifier == read_loacl_market_infos.local_id_list[read_loacl_market_infos.current_local_data_index])
            {
            client_mem_storage_identifier_data( get_current_connect_server_id(), resp_lenth, resp_data );
            read_loacl_market_infos.peocess_result = PROCESS_RESULT_SUCCESS;
            }
      //  else
            {
          //  read_loacl_market_infos.peocess_result = PROCESS_RESULT_INVALID_DATA;
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
                read_loacl_market_infos.peocess_result = PROCESS_RESULT_NRC_SNS;
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
            read_loacl_market_infos.peocess_result = PROCESS_RESULT_NRC_GR;
            }
        else
            {
            read_loacl_market_infos.peocess_result = PROCESS_RESULT_NRC_GR;
            }
        break;

    case REQ_DEFAULT_SESSION_FRAME:
        read_loacl_market_infos.peocess_result = PROCESS_RESULT_NRC_GR;
        break;

    case REQ_RESEND_FRAME:
        read_loacl_market_infos.peocess_result = PROCESS_RESULT_NRC_GR;
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
        read_loacl_market_infos.peocess_result = PROCESS_RESULT_NRC_GR;
        break;

    case REQ_RESEND_FRAME:
       read_loacl_market_infos.resend_timer++;
        if( RESEND_MAX_CONUNT > read_loacl_market_infos.resend_timer )
            {
            read_loacl_market_infos.next_req_frame = REQ_RESEND_FRAME;
            }
        else
            {
            read_loacl_market_infos.peocess_result = RROCESS_RESULE_RESEND_OVERFLOW;
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

/*shall send the process result to upper layer whehter process is success*/
/*shall re-init related status flags*/
/*shall set the next process flow*/
if( PROCESS_RESULT_INIT != read_local_monitor_infos.peocess_result )
    {
    #if (APPL_DEBUG )
    client_appl_debug_printf( read_local_monitor_infos.peocess_result );
    #endif
    if( read_local_monitor_infos.current_local_data_index == read_local_monitor_infos.amount_local_data - 1 )
        {
        /*have been alraedy all identifier data of current server*/
        client_mem_send_can_data();
        client_mem_reset_data();
        /*step 1:response result to upper layer*/
        if( no_server_connected == client_appl_get_next_connected_server_id() )
            {
            client_appl_set_current_process_flow_step(PROCESS_FLOW_IDLE);
            }
        else
            {
            set_current_conncet_server_id( client_appl_get_next_connected_server_id() );
            client_appl_set_current_process_flow_step( PROCESS_FLOW_MONITOR );
            }
        /*step3: setting the next process flow*/
        }
    else
        {
        /*go on request the next common indentifier data*/
        read_local_monitor_infos.current_local_data_index++;
        read_local_monitor_infos.peocess_result = PROCESS_RESULT_INIT;
        read_local_monitor_infos.next_req_frame = REQ_ORIGINAL_FRAME;
        read_local_monitor_infos.curr_req_frame = REQ_NO_FRAME;
        read_local_monitor_infos.receive_SNS_timer =0x00;
        read_local_monitor_infos.resend_timer = 0x00;
        }
    }

}


/*!******************************************************************************
*
* @public
* Function name: client_appl_read_data_by_local_indentifier_monitor_postive_response_handler
* Description  : this function process the postive response data when handle hen handle process flow Read_Monitor
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
        /*When received a valid datas*/
        /*step1: stroge data here*/
        client_mem_storage_identifier_data( get_current_connect_server_id(), resp_lenth, resp_data );
        read_local_monitor_infos.peocess_result = PROCESS_RESULT_SUCCESS;
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
                read_local_monitor_infos.peocess_result = PROCESS_RESULT_NRC_SNS;
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
            read_local_monitor_infos.peocess_result = PROCESS_RESULT_NRC_GR;
            }
        else
            {
            read_local_monitor_infos.peocess_result = PROCESS_RESULT_NRC_GR;
            }
        break;

    case REQ_DEFAULT_SESSION_FRAME:
        read_local_monitor_infos.peocess_result = PROCESS_RESULT_NRC_GR;
        break;

    case REQ_RESEND_FRAME:
        read_local_monitor_infos.peocess_result = PROCESS_RESULT_NRC_GR;
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
        read_local_monitor_infos.peocess_result = PROCESS_RESULT_NRC_GR;
        break;

    case REQ_RESEND_FRAME:
       read_local_monitor_infos.resend_timer++;
        if( RESEND_MAX_CONUNT > read_local_monitor_infos.resend_timer )
            {
            read_local_monitor_infos.next_req_frame = REQ_RESEND_FRAME;
            }
        else
            {
            read_local_monitor_infos.peocess_result = RROCESS_RESULE_RESEND_OVERFLOW;
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

if( PROCESS_RESULT_INIT != read_freeze_frame_data_infos.peocess_result)
    {
#if (APPL_DEBUG )
    client_appl_debug_printf( read_freeze_frame_data_infos.peocess_result );
#endif
    /*have been alraedy all identifier data of current server*/
    client_mem_send_can_data();
    client_mem_reset_data();

    if( 0xFF != client_appl_get_next_connected_server_id() )
        {
        set_current_conncet_server_id( client_appl_get_next_connected_server_id() );
        (void)memset(read_freeze_frame_data_infos.request_id_list, 0x00, sizeof(current_request_freeze_frame_id_list));
        read_freeze_frame_data_infos.current_freeze_frame_number = 0x01;
        read_freeze_frame_data_infos.curr_request_frame = REQ_NO_FRAME;
        read_freeze_frame_data_infos.next_request_frame = REQ_ORIGINAL_FRAME;
        read_freeze_frame_data_infos.receive_SNS_timer = 0x00;
        read_freeze_frame_data_infos.resend_timer = 0x00;
        }
    else
        {
        client_appl_set_current_process_flow_step( PROCESS_FLOW_IDLE );
        }
    read_freeze_frame_data_infos.peocess_result = PROCESS_RESULT_INIT;
    }
}

/*!******************************************************************************
*
* @public
* Function name: client_appl_read_freeze_frame_data_positive_response_handler
* Description  : this function process the postive response data when handle hen handle process flow Read_FFD
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
        /*when rx a postive response for originl message, shall req FFD meesage consecutive*/
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
                /*The max valud of freeze frame number is 0xFF, (type unsiged char)*/
                if( 0xFF == read_freeze_frame_data_infos.current_freeze_frame_number )
                    {
                    read_freeze_frame_data_infos.peocess_result = PROCESS_RESULT_END;
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
        /*The max valud of freeze frame number is 0xFF, (type unsiged char)*/
        if( 0xFF == read_freeze_frame_data_infos.current_freeze_frame_number )
            {
            read_freeze_frame_data_infos.peocess_result = PROCESS_RESULT_END;
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
    break;

    default:
    break;
    }

/*we need init timer when received a postive message of data*/
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
                /*This process shall be end normaly by rx a NRC 12*/
                read_freeze_frame_data_infos.peocess_result = PROCESS_RESULT_END;
                }
            else
                {
                /*The server don`t have any DTC status data*/
                read_freeze_frame_data_infos.peocess_result = PROCESS_RESULT_INVALID_DATA;
                }
            }
        else if( DCM_NRC_SERVICE_NOT_SUPPORT == nrc )
            {
            read_freeze_frame_data_infos.receive_SNS_timer++;
            if( REC_MAX_SNS <= read_freeze_frame_data_infos.receive_SNS_timer )
                {
                read_freeze_frame_data_infos.peocess_result = PROCESS_RESULT_NRC_SNS;
                }
            else
                {
                client_appl_set_next_ffd_frame_frame( REQ_DEFAULT_SESSION_FRAME );
                }
            }
        else
            {
            read_freeze_frame_data_infos.peocess_result = PROCESS_RESULT_NRC_GR;
            }
        break;

    case REQ_DEFAULT_SESSION_FRAME:
        read_freeze_frame_data_infos.peocess_result = PROCESS_RESULT_NRC_GR;
        break;

    case REQ_RESEND_FRAME:
        if( REQ_ORIGINAL_FRAME == read_freeze_frame_data_infos.prev_request_frame )
            {
            if( DCM_NRC_SUB_FUNCTION_NOT_SUPPORT == nrc )
                {
                /*RX flow success end*/
                if( 0x01 < read_freeze_frame_data_infos.current_freeze_frame_number )
                    {
                    /*This process shall be end normaly by rx a NRC 12*/
                    read_freeze_frame_data_infos.peocess_result = PROCESS_RESULT_SUCCESS;
                    }
                else
                    {
                    /*The server don`t have any DTC status data*/
                    read_freeze_frame_data_infos.peocess_result = PROCESS_RESULT_INVALID_DATA;
                    }
                }
            else if( DCM_NRC_SERVICE_NOT_SUPPORT == nrc )
                    {
                    read_freeze_frame_data_infos.receive_SNS_timer++;
                    if( REC_MAX_SNS <= read_freeze_frame_data_infos.receive_SNS_timer )
                        {
                        read_freeze_frame_data_infos.peocess_result = PROCESS_RESULT_NRC_SNS;
                        }
                    else
                        {
                        client_appl_set_next_ffd_frame_frame( REQ_DEFAULT_SESSION_FRAME );
                        }
                    }
            else
                {
                read_freeze_frame_data_infos.peocess_result = PROCESS_RESULT_NRC_GR;
                }
            }
        else
            {
            if( DCM_NRC_SERVICE_NOT_SUPPORT == nrc )
            {
            read_freeze_frame_data_infos.receive_SNS_timer++;
            if( REC_MAX_SNS <= read_freeze_frame_data_infos.receive_SNS_timer )
                {
                read_freeze_frame_data_infos.peocess_result = PROCESS_RESULT_NRC_SNS;
                }
            else
                {
                client_appl_set_next_ffd_frame_frame( REQ_DEFAULT_SESSION_FRAME );
                }
            }
            else
                {
                read_freeze_frame_data_infos.peocess_result = PROCESS_RESULT_NRC_GR;
                }
            }
        break;

    case REQ_FFD_FRAME:
        if( DCM_NRC_SERVICE_NOT_SUPPORT == nrc )
            {
            read_freeze_frame_data_infos.receive_SNS_timer++;
            if( REC_MAX_SNS <= read_freeze_frame_data_infos.receive_SNS_timer )
                {
                read_freeze_frame_data_infos.peocess_result = PROCESS_RESULT_NRC_SNS;
                }
            else
                {
                client_appl_set_next_ffd_frame_frame( REQ_DEFAULT_SESSION_FRAME );
                }
            }
        else
            {
            read_freeze_frame_data_infos.peocess_result = PROCESS_RESULT_NRC_GR;
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
        read_freeze_frame_data_infos.peocess_result = PROCESS_RESULT_NRC_GR;
        break;

    case REQ_RESEND_FRAME:
        read_freeze_frame_data_infos.resend_timer++;
        if( RESEND_MAX_CONUNT > read_freeze_frame_data_infos.resend_timer )
            {
            read_freeze_frame_data_infos.next_request_frame = REQ_RESEND_FRAME;
            }
        else
            {
            read_freeze_frame_data_infos.peocess_result = RROCESS_RESULE_RESEND_OVERFLOW;
            }
        break;

    case REQ_FFD_FRAME:
        client_appl_set_next_ffd_frame_frame( REQ_RESEND_FRAME );
        break;

    default:
    break;
    }
}

