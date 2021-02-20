/*--------------------------------------------------------------------
* @file client_dcm.c
* @brief client diagnostic communication management
*
* This file transmit data between server_dcm,client_dcm and can_tp
* module, implement the 14229-2 session layer service
* including the periodic function to be called by the scheduler/thread
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
---------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                            GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "client_dcm.h"
#include "can_tp.h"
#include "client_dcm_appl.h"
#include "client_mem.h"
uint32 os_task_time = 0;

/*--------------------------------------------------------------------
                        VARIABLES
--------------------------------------------------------------------*/
static client_init_state_type g_client_init_state = CLIENT_UN_INITIALIZATION;
static client_diag_state_type g_client_diag_state = CLIENT_DIAG_STATE_IDLE;
static uint8 prev_connect_ecu_id  = 0xFF;

static client_msg_context_type client_diag_msg_context = { 0 };
static uint8 client_diag_rx_buffer[CLIENT_RX_MAX_BUFFER_LEN] = { 0 };
static uint8 client_diag_tx_buffer[CLIENT_TX_MAX_BUFFER_LEN] = { 0 };

static uint32 g_pclient_timer= 0;
static boolean g_pclient_timer_start_falg = FALSE;
static uint32 g_s3_timer = 0x0;

/*------------------------------------------------------------------
*                          MACROS
-------------------------------------------------------------------*/
//#define set_client_diag_state( new_state )               g_client_diag_state = new_state; PRINTF("diag state:%d \r\n", g_client_diag_state)
#define set_client_diag_state( new_state )              ( g_client_diag_state = new_state )
#define is_client_diag_state( state )                   ( g_client_diag_state == state ? TRUE:FALSE )
#define get_client_diag_state()                         ( g_client_diag_state )
#define set_pclient_timer_vlaue( value)                 ( g_pclient_timer = (uint32) value )
#define is_clr_client_timer()                           ( g_pclient_timer == (uint32)0?TRUE:FALSE )
#define decrease_p2client_timer()                       ( g_pclient_timer -- )
#define set_s3_timer(value)                             ( g_s3_timer = (uint32)value )
#define decrease_s3_timer()                             ( g_s3_timer -- )
#define is_clr_s3_timer()                               ( g_s3_timer == (uint32)0 ? TRUE:FALSE )


/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
void client_dcm_init
    (
    void
    );

void client_diag_main_funciton_5ms
    (
    void
    );

void client_diag_tx_complete
    (
    tp_n_result_t result,
    uint8 hw_inst,
    uint8 channel_id
    );

void
client_diag_rx_wrapper
    (
    tp_n_result_t result,
    uint8   const * const rx_buffer,
    uint16  const       mssg_length,
    tp_chan_index_t const  tp_channel
    );

client_ReturnType
client_dcm_req_tester_persent
    (
    uint8 channel_id
    );



/*!*******************************************************************
*
* @public
* Function name: client_diag_data_cpy
* Description:   this function implement memory data copy function
*
*********************************************************************/
void client_diag_data_cpy
    (
    uint8* dest,
    uint8* src,
    uint16 cnt
    )
{
uint16 i;
for( i = 0; i < cnt; i++ )
    {
    *(dest + i) = *(src + i);
    }
}

/*!*******************************************************************
*
* @public
* Function name: client_dcm_init
* Description:   this function initial client diagnostic communication management
*
*********************************************************************/
void client_dcm_init
    (
    void
    )
{
if( CLIENT_UN_INITIALIZATION == g_client_init_state )
    {
    set_client_diag_state( CLIENT_DIAG_STATE_IDLE );
    g_client_init_state = CLIENT_INITIALIZATION;

    client_diag_msg_context.req_data = client_diag_tx_buffer;
    client_diag_msg_context.resp_data = client_diag_rx_buffer;
    client_diag_msg_context.is_receive = FALSE;

    prev_connect_ecu_id = 0XFF;
    }
}

/*!*******************************************************************
*
* @public
* Function name: client_diag_pclient_timer_handler
* Description:   this function handler p_client timer
*
*********************************************************************/
static void client_diag_pclient_timer_handler
    (
    void
    )
{
if( ( TRUE == g_pclient_timer_start_falg ) && ( CLIENT_DIAG_STATE_RX_PENDING != get_client_diag_state() ) )
    {
    decrease_p2client_timer();
    if( is_clr_client_timer() )
        {
        set_client_diag_state( CLIENT_DIAG_STATE_IDLE );
        client_appl_response_timeout_notify();
        client_diag_msg_context.req_channel = 0xFF;
        g_pclient_timer_start_falg = FALSE;
        }
    }
}

/*!*******************************************************************
*
* @public
* Function name: client_diag_RCPP_handler
* Description:   this function handler p_client star timer
*
*********************************************************************/
static void client_diag_RCPP_handler
    (
    void
    )
{
if( ( TRUE == g_pclient_timer_start_falg ) && ( CLIENT_DIAG_STATE_RX_PENDING == get_client_diag_state() ) )
    {
    decrease_p2client_timer();
    if( is_clr_client_timer() )
        {
        set_client_diag_state( CLIENT_DIAG_STATE_IDLE );
        client_appl_response_timeout_notify();
        client_diag_msg_context.req_channel = 0xFF;
        g_pclient_timer_start_falg = FALSE;
        }
    }
}

/*!*******************************************************************
*
* @public
* Function name: client_diag_S3_timer_handler
* Description:   this function handler p_client star timer
*
*********************************************************************/
static void client_diag_S3_timer_handler
    (
    void
    )
{
uint8 curr_connnect_ecu_id = client_appl_get_current_connected_server_id();

if( ( SUPPORT_SERVER_NUM == curr_connnect_ecu_id ) \
    || ( 0xFF == curr_connnect_ecu_id ) )
    {
    /*when channel is idle or function address channel */
    prev_connect_ecu_id = curr_connnect_ecu_id;
    return;
    }
else if( prev_connect_ecu_id != curr_connnect_ecu_id )
    {
    client_dcm_req_tester_persent( curr_connnect_ecu_id );
    set_s3_timer( S3_TIME );
    prev_connect_ecu_id = curr_connnect_ecu_id;
    }
else
    {
    decrease_s3_timer();
    if( is_clr_s3_timer() )
        {
        client_dcm_req_tester_persent( curr_connnect_ecu_id );
        set_s3_timer( S3_TIME );
        }
    }
}


/*!******************************************************************************
*
* @public
* Function name: client_diag_timer_handler_5ms
* Description  : this function handler p_client timer
* usage        : called by function client_diag_main_funciton_5msDIAG_task
*********************************************************************************/
static void client_diag_timer_handler_5ms
    (
    void
    )
{
client_diag_pclient_timer_handler();
client_diag_RCPP_handler();
client_diag_S3_timer_handler();
}

/*!******************************************************************************
*
* @public
* Function name: client_diag_response_dispatch_handler
* Description  : this function handler the response data
* usage        : called by function client_diag_main_funciton_5msDIAG_task
*********************************************************************************/
static client_ReturnType client_diag_response_dispatch_handler
    (
    void
    )
{
client_ReturnType return_value = E_OK;

if( TRUE == client_diag_msg_context.is_receive )
    {
    client_diag_msg_context.is_receive = FALSE;

    /*received a negative response*/
    if( DCM_NEGATIVE_REPOSNE_SERVICE_ID == client_diag_msg_context.resp_data[BYTE_NUM_0] )
        {
        /*Check whether the response service id is correct*/
        if( client_diag_msg_context.req_data[BYTE_NUM_0] != client_diag_msg_context.resp_data[BYTE_NUM_1])
            {
            return_value = E_RX_FORMAT_ERROR;
            }
        else if( NEGATIVE_RESPONSE_LENTH != client_diag_msg_context.resp_data_len )
            {
            /*Check whether the response data length is correct*/
            return_value = E_RX_FORMAT_ERROR;
            }
        else if( DCM_NRC_RESPONSE_PENDING == client_diag_msg_context.resp_data[BYTE_NUM_2] )
            {
            /*Check whether the RCPP is received*/
            if( CLIENT_ADDRESS_FUNCTIONAL == client_diag_msg_context.address_type )
                {
                /*response RCPP when request by functional address is not allowable*/
                return_value = E_RX_FORMAT_ERROR;
                }
            else
                {
                return_value = E_RX_PENDING;
                }
            }
        else
            {
            client_appl_negative_response_dispatch( client_diag_msg_context.resp_data[BYTE_NUM_1], client_diag_msg_context.resp_data[BYTE_NUM_2] );
            return_value =  E_OK;
            }
        }
    /*Received  a Positive response message*/
    else if( (client_diag_msg_context.req_data[BYTE_NUM_0] + 0x40 ) != client_diag_msg_context.resp_data[BYTE_NUM_0])
        {
        return_value = E_RX_FORMAT_ERROR;
        }
    else
        {
        client_appl_positive_response_dispatch( client_diag_msg_context.resp_data, client_diag_msg_context.resp_data_len, client_diag_msg_context.resp_channel );
        return_value =  E_OK;
        }

    /*client_diag_state shall be set to idle after the P2 timer timeout*/
    if( CLIENT_ADDRESS_FUNCTIONAL == client_diag_msg_context.address_type )
        {
        /*do nothing*/
        }
    else if( E_OK == return_value )
        {
        set_client_diag_state( CLIENT_DIAG_STATE_IDLE );
        }
    else if( E_RX_PENDING == return_value)
        {
        set_client_diag_state( CLIENT_DIAG_STATE_RX_PENDING );
        g_pclient_timer_start_falg = TRUE;
        set_pclient_timer_vlaue( P_CLIENT_STAER_TIME );
        }
    else if( E_RX_FORMAT_ERROR == return_value )
        {
        /*when received a error_format message,wait p2 timeout and set diagnostic state*/
        }
    else
        {
        }
    }
return return_value;
}

/*!******************************************************************************
*
* @public
* Function name: client_diag_main_funciton_5ms
* Description  :
* usage        : called by function DIAG_task
*********************************************************************************/
void client_diag_main_funciton_5ms
    (
    void
    )
{
os_task_time++;
client_diag_timer_handler_5ms();
//client_diag_response_dispatch_handler();
}


/*!******************************************************************************
*
* @public
* Function name: client_diag_tx_wrapper
* Description  : This function shall send a message to bus
* usage        : called by function client_dcm_req_common_indentifier..
*********************************************************************************/
client_ReturnType client_diag_tx_wrapper
    (
    uint8                ecu_id
    )
{
uint8 channel_id = 0;

if( CLIENT_ADDRESS_FUNCTIONAL == client_diag_msg_context.address_type )
    {
    channel_id = (TP_CAN0_NUM_CHANNELS - 1);
    }
else if( CLIENT_ADDRESS_PHYSICAL == client_diag_msg_context.address_type )
    {
    channel_id = ecu_id;
    }

if( channel_id >= TP_CAN0_NUM_CHANNELS )
    {
    return E_NOT_OK;
    }

if( 0x0000 != client_diag_msg_context.req_data_len ) /* network layer doesn't check for 0 byte message */
    {
    if( is_client_diag_state( CLIENT_DIAG_STATE_IDLE ))
        {
        set_client_diag_state( CLIENT_DIAG_STATE_REQUEST );
        client_diag_msg_context.req_channel = channel_id;
        tp_transmit(client_diag_msg_context.req_data, client_diag_msg_context.req_data_len, channel_id, CAN_CONTROLLER_2 );/*turan*/
        }
    else
        {
        /*a new request message when last message is processing,abandon the new request*/
        }
    }
return E_OK;
}

/*!******************************************************************************
*
* @public
* Function name: client_diag_tx_complete
* Description  : This function re-start p_client timer
* usage        : called when the request message send successful
*********************************************************************************/
void client_diag_tx_complete
    (
    tp_n_result_t result,
    uint8 hw_inst,
    uint8 channel_id
    )
{
//PRINTF("TX complete channel:%d-----time:%d\r\n",channel_id, os_task_time);
    /* TBD
if( TP_N_OK != result )
    {
    set_client_diag_state( CLIENT_DIAG_STATE_IDLE );
    return;
    }
    */
if( is_client_diag_state( CLIENT_DIAG_STATE_REQUEST ) )
    {
    set_client_diag_state( CLIENT_DIAG_STATE_CONFIRM );

    /*when the client success send request message,we start the p2_client timer*/
    g_pclient_timer_start_falg = TRUE;
    set_pclient_timer_vlaue( P_CLIENT_TIME );
    }
}

/*!*******************************************************************
*
* @private
* Diagnostic Layer CAN Start Of Message(First Frame )reception notification
*
* This function is the callback from the Transport Protocol Layer of
* the CAN Stack that passes received Diagnostic TP First Frames for
* processing.
*
*********************************************************************/
void
client_dcm_SOM_indication
    (
    tp_n_result_t       const result,       //!< [in] TP receive result
    uint8       const * const p_frame_data, //!< [in] ptr to First Frame data
    boolean             const func_addr,    //!< [in] Functionally addressed TP message
    can_hw_inst_t       const hw_inst,       //!< [in] CAN hardware instance
    tp_chan_index_t const  tp_channel
    )
{
/*response of functional address request*/
if( CLIENT_ADDRESS_FUNCTIONAL == client_diag_msg_context.address_type )
    {
    /* do nothing*/
    }
else if( CLIENT_ADDRESS_PHYSICAL == client_diag_msg_context.address_type )
    {
    if( TP_N_OK != result )
        {
        return;
        }
    else if( tp_channel != client_diag_msg_context.req_channel )
        {
        return;
        }
    else if( is_client_diag_state( CLIENT_DIAG_STATE_CONFIRM )
        || is_client_diag_state( CLIENT_DIAG_STATE_RX_PENDING ) )
        {
        set_client_diag_state( CLIENT_DIAG_STATE_INDICATION_SOM );
        g_pclient_timer_start_falg = FALSE;
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
* Function name: client_diag_rx_wrapper
* Description  : This function handle the received message
* usage        : called when the response message is received
*********************************************************************************/
void
client_diag_rx_wrapper
    (
    tp_n_result_t result,
    uint8   const * const rx_buffer,
    uint16  const       mssg_length,
    tp_chan_index_t const  tp_channel
    )
{

//PRINTF("Received channel--%d    time:%d    \r\n",tp_channel, os_task_time);
//PRINTF("data: %d, %d\r\n",rx_buffer[0],rx_buffer[1] );
/*response of functional address request*/
if( CLIENT_ADDRESS_FUNCTIONAL == client_diag_msg_context.address_type )
    {
    if( TP_N_OK != result )
        {
        return;
        }
    else
        {
        /*do nothing*/
        }
    }
else if( CLIENT_ADDRESS_PHYSICAL == client_diag_msg_context.address_type )
    {
    /*PENDING*/
    if( TP_N_OK != result )
        {
        set_client_diag_state( CLIENT_DIAG_STATE_IDLE );
        return;
        }
    else if( tp_channel != client_diag_msg_context.req_channel )
        {
        return;
        }
    else if( is_client_diag_state( CLIENT_DIAG_STATE_CONFIRM )
        || is_client_diag_state( CLIENT_DIAG_STATE_INDICATION_SOM )
        || is_client_diag_state( CLIENT_DIAG_STATE_RX_PENDING ) )
        {
        set_client_diag_state( CLIENT_DIAG_STATE_INDICATION );
        g_pclient_timer_start_falg = FALSE;
        }
    else
        {
        return;
        }
    }

client_diag_data_cpy( client_diag_rx_buffer, (uint8*)rx_buffer, mssg_length );
client_diag_msg_context.resp_data = client_diag_rx_buffer;
client_diag_msg_context.resp_data_len = mssg_length;
client_diag_msg_context.resp_channel = tp_channel;
client_diag_msg_context.is_receive = TRUE;

client_diag_response_dispatch_handler();
}

/***********************************************************************
Function: client_dcm_req_diagnostic_default_session_functional
Description: This function will send a request diagnostic default session message to can_tp
Input: void
Return: Send Status
***********************************************************************/
client_ReturnType client_dcm_req_diagnostic_default_session_functional
    (
    void
    )
{
client_ReturnType return_value;

if( is_client_diag_state( CLIENT_DIAG_STATE_IDLE ) )
    {
    client_diag_msg_context.req_data[BYTE_NUM_0] = DCM_DIAGNOSTC_SESSION_SERVICE_ID;
    client_diag_msg_context.req_data[BYTE_NUM_1] = DCM_10h_DEFAULT_ID;
    client_diag_msg_context.req_data_len = 0x02;
    client_diag_msg_context.address_type = CLIENT_ADDRESS_FUNCTIONAL;
    return_value = client_diag_tx_wrapper( 5 );
    }
else
    {
    return_value = E_BUSY;
    }

return return_value;
}


/***********************************************************************
Function: client_dcm_req_diagnostic_default_session_physical
Description: This function will send a request diagnostic default session message to can_tp
Input: void
Return: Send Status
***********************************************************************/
client_ReturnType client_dcm_req_diagnostic_default_session_physical
    (
    uint8 channel_id
    )
{
client_ReturnType return_value;

if( is_client_diag_state( CLIENT_DIAG_STATE_IDLE ) )
    {
    client_diag_msg_context.req_data[BYTE_NUM_0] = DCM_DIAGNOSTC_SESSION_SERVICE_ID;
    client_diag_msg_context.req_data[BYTE_NUM_1] = DCM_10h_DEFAULT_ID;
    client_diag_msg_context.req_data_len = 0x02;
    client_diag_msg_context.address_type = CLIENT_ADDRESS_PHYSICAL;
    return_value = client_diag_tx_wrapper( channel_id );
    }
else
    {
    return_value = E_BUSY;
    }

return return_value;
}


/***********************************************************************
Function:    client_dcm_req_diagnostic_extend_session
Description: This function will send a request diagnostic extend session message to speical ECU
Input: channel_id
Return: Send Status
***********************************************************************/
client_ReturnType client_dcm_req_diagnostic_extend_session
    (
    uint8 channel_id
    )
{
client_ReturnType return_value;

if( is_client_diag_state( CLIENT_DIAG_STATE_IDLE ) )
    {
    client_diag_msg_context.req_data[BYTE_NUM_0] = DCM_DIAGNOSTC_SESSION_SERVICE_ID;
    client_diag_msg_context.req_data[BYTE_NUM_1] = DCM_10h_EXTEND_ID;
    client_diag_msg_context.req_data_len = 0x02;
    client_diag_msg_context.address_type = CLIENT_ADDRESS_PHYSICAL;
    return_value = client_diag_tx_wrapper( channel_id );
    }
else
    {
    return_value = E_BUSY;
    }

return return_value;
}


/***********************************************************************
Function:    client_dcm_req_diagnostic_extend_session
Description: This function will send a request tester present message to special ECU
Input: channel_id
Return: Send Status
***********************************************************************/
client_ReturnType client_dcm_req_tester_persent
    (
    uint8 channel_id
    )
{
uint8 tester_persent_req_message[DCM_3Eh_REQ_DATA_LEN] = {0};
tester_persent_req_message[BYTE_NUM_0] = DCM_TESTER_PERSNET_SERVICE_ID;
tester_persent_req_message[BYTE_NUM_1] = DCM_3Eh_NO_RESPONSE;
tp_transmit_direct( tester_persent_req_message, DCM_3Eh_REQ_DATA_LEN, channel_id, CAN_CONTROLLER_2 );
return E_OK;
}

/***********************************************************************
Function:    client_dcm_req_read_dtc_status_code
Description: This function will send a request DTC status code to special ECU
Input: channel_id, status_code
Return: Send Status
***********************************************************************/
client_ReturnType client_dcm_req_read_dtc_status_code
    (
    uint8 channel_id,
    uint8 status_code
    )
{
client_ReturnType return_value;

if( is_client_diag_state( CLIENT_DIAG_STATE_IDLE ) )
    {
    client_diag_msg_context.req_data[BYTE_NUM_0] = DCM_READ_DTC_STATUS_SERVICE_ID;
    client_diag_msg_context.req_data[BYTE_NUM_1] = status_code;
    client_diag_msg_context.req_data_len = 0x02;
    client_diag_msg_context.address_type = CLIENT_ADDRESS_PHYSICAL;
    return_value = client_diag_tx_wrapper( channel_id );
    }
else
    {
    return_value = E_BUSY;
    }

return return_value;
}


/***********************************************************************
Function:    client_dcm_req_common_indentifier
Description: This function will send a request common id data to special ECU
Input: channel_id, common_id
Return: Send Status
***********************************************************************/
client_ReturnType client_dcm_req_common_indentifier
    (
    uint8 channel_id,
    uint16 common_id
    )
{
client_ReturnType return_value;

if( is_client_diag_state( CLIENT_DIAG_STATE_IDLE ) )
    {
    client_diag_msg_context.req_data[BYTE_NUM_0] = DCM_READ_COMMON_INDENTIFIER;
    client_diag_msg_context.req_data[BYTE_NUM_1] = (uint8)(common_id >> 8);
    client_diag_msg_context.req_data[BYTE_NUM_2] = (uint8)common_id;
    client_diag_msg_context.req_data_len = DCM_22h_REQ_DATA_LEN;
    client_diag_msg_context.address_type = CLIENT_ADDRESS_PHYSICAL;
    return_value = client_diag_tx_wrapper( channel_id );
    }
else
    {
    return_value = E_BUSY;
    }

return return_value;
}

/***********************************************************************
Function:    client_dcm_req_local_indentifier
Description: This function will send a request local id data to special ECU
Input: channel_id, common_id
Return: Send Status
***********************************************************************/
client_ReturnType client_dcm_req_local_indentifier
    (
    uint8 channel_id,
    uint8 local_id
    )
{
client_ReturnType return_value;

if( is_client_diag_state( CLIENT_DIAG_STATE_IDLE ) )
    {
    client_diag_msg_context.req_data[BYTE_NUM_0] = DCM_READ_LOCAL_INDENTIFIER;
    client_diag_msg_context.req_data[BYTE_NUM_1] = local_id;
    client_diag_msg_context.req_data_len = DMC_21h_REQ_DATA_LEN;
    client_diag_msg_context.address_type = CLIENT_ADDRESS_PHYSICAL;
    return_value = client_diag_tx_wrapper( channel_id );
    }
else
    {
    return_value = E_BUSY;
    }

return return_value;
}



/***********************************************************************
Function:    client_dcm_req_freeze_frame_data
Description: This function will send a request freeze frame data data to special ECU
Input: channel_id, freeze_frame_numberm, record_local_id
Return: Send Status
***********************************************************************/
client_ReturnType client_dcm_req_freeze_frame_data
    (
    uint8 channel_id,
    uint8 freeze_frame_number,
    uint8 record_local_id
    )
{
client_ReturnType return_value;

if( is_client_diag_state( CLIENT_DIAG_STATE_IDLE ) )
    {
    client_diag_msg_context.req_data[BYTE_NUM_0] = DCM_READ_FREEZE_FRAME_DATA_SERVICE_ID;
    client_diag_msg_context.req_data[BYTE_NUM_1] = freeze_frame_number;
    client_diag_msg_context.req_data[BYTE_NUM_2] = DCM_12h_RECMID;
    client_diag_msg_context.req_data[BYTE_NUM_3] = record_local_id;
    client_diag_msg_context.req_data_len = DCM_12h_REQ_DATA_LEN;
    client_diag_msg_context.address_type = CLIENT_ADDRESS_PHYSICAL;
    return_value = client_diag_tx_wrapper( channel_id );
    }
else
    {
    return_value = E_BUSY;
    }

return return_value;
}


/*!*******************************************************************
*
* @private
* Diagnostic function Periodic Task
*
* This function processes all Diagnostic Layer periodic tasks.
*
*********************************************************************/
void
client_diag_task
    (
    can_hw_inst_t   const hw_inst           //!< [in] CAN hardware instance
    )
{
if( CAN_CONTROLLER_2 == hw_inst )/*turan*/
    {
    client_diag_main_funciton_5ms();
    client_appl_main_5ms_handler();
    }
}


/*!*******************************************************************
*
* @public
* diagnostics initialization routine
*
* This function is called from an OS startup hook
*
*********************************************************************/
void client_diag_init
    (
    can_hw_inst_t   const hw_inst           //!< [in] CAN hardware instance
    )
{
if( CAN_CONTROLLER_2 == hw_inst )
    {
    client_dcm_init();
    client_appl_init();
    client_mem_init();
    }
}

