/*!*******************************************************************
*
* @defgroup can_stack_mid middle Layer between CAN and other modules
* @ingroup can_stack
* @{
*
*********************************************************************/

/*--------------------------------------------------------------------
                            GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "can_defs.h"
#include "can_bcfg.h"
#include "CAN_app.h"
#include "can_dll_prv_par.h"

#include "can_il.h"
#include "can_il_prv.h"
#include "can_il_par.h"
#include "can_il_enum.h"
#include "can_il_prv_par.h"

#include "VI_pub.h"
#include "fsl_debug_console.h"
#include "FreeRTOS.h"
#include "task.h"
#include <string.h>

#include "can_mid.h"

/*--------------------------------------------------------------------
                            MACROS
--------------------------------------------------------------------*/
#define MID_MSG_RES_SHORT_TIMEOUT                       10   //!< 10  * 5ms = 50ms
#define MID_MSG_RES_SHORT_TIMEOUT_OFFSET                2    //!< 2  *  5ms = 10ms
#define MID_MSG_RES_MID_TIMEOUT                         30   //!< 30  * 5ms = 150ms

#define MID_MSG_RES_LONG_TIMEOUT                        1000 //!< 1000 * 5ms = 5000ms
#define MID_MSG_RE_SEND_TIME_LONG                       1    //!< 1 time,
#define MID_MSG_RE_SEND_TIME_SHORT                      3    //!< No response resending times

#define MID_MSG_CAN_ID_DEMO                             0xFFFFFFFF
#define MID_MSG_SVC_ID_DEMO                             0xFF

/*--------------------------------------------------------------------
                            TYPES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              VARIABLES
--------------------------------------------------------------------*/
/*------------------------------------------------------
Supported function list instances
------------------------------------------------------*/
mid_msg_supp_func_t supp_func_list      = { 0 };
boolean             supp_func_list_syc  = FALSE;

/*------------------------------------------------------
Message list pointer
------------------------------------------------------*/
mid_msg_lst msg_lst_head = NULL;

/*------------------------------------------------------
Request message instances
------------------------------------------------------*/
mid_msg_t mid_msg_inst[] =
{
    { TX0_REQ_MT_FUNC_CNT_CAN0_ID, RX4_RES_MT_FUNC_CNT_CAN0_ID, MID_MSG_SID_VC_INFO_RST        , MID_RES_SID_VC_INFO_RST    },
    { TX0_REQ_MT_FUNC_CNT_CAN0_ID, RX4_RES_MT_FUNC_CNT_CAN0_ID, MID_MSG_SID_VC_INFO_CHNG_MT_LCD, MID_RES_SID_VC_INFO_CHNG   },
    { TX0_REQ_MT_FUNC_CNT_CAN0_ID, RX4_RES_MT_FUNC_CNT_CAN0_ID, MID_MSG_SID_UNIT_CHNG,           MID_RES_SID_UNIT           },
    { TX0_REQ_MT_FUNC_CNT_CAN0_ID, RX4_RES_MT_FUNC_CNT_CAN0_ID, MID_MSG_SID_TCS_SWITCH,          MID_RES_SID_TCS            },
    { TX4_REQ_REPRGRM_INFO_CAN0_ID,RX9_RES_RPRGRM_INFO_CAN0_ID, MID_MSG_SID_REPROG,              MID_RES_SID_REPROG         },
    { TX2_REQ_SUPPORT_CAN0_ID,     RX2_RES_SUPPORT_CAN0_ID,     MID_MSG_SID_SUPP_FUNC_LIST,      MID_RES_SID_SUPP_FUNC_LIST },
};

/*------------------------------------------------------
Init the message list
------------------------------------------------------*/
static void mid_msg_list_init
    (
    void
    )
{
/*------------------------------------------------------
Get the head node memory space
------------------------------------------------------*/
msg_lst_head = pvPortMalloc( sizeof( mid_msg_node ) );

/*------------------------------------------------------
Init message para
------------------------------------------------------*/
msg_lst_head->next           = NULL;
msg_lst_head->req_msg_time   = 0;
msg_lst_head->req_msg_wait   = 0;
msg_lst_head->req_msg_status = MID_MSG_STAT_INITED;

/*------------------------------------------------------
Reset data field
------------------------------------------------------*/
memset( &msg_lst_head->req_msg,  0, sizeof(can_msg_t) );
memset( &msg_lst_head->pos_resp_msg,  0, sizeof(can_msg_t) );
memset( &msg_lst_head->neg_resp_msg,  0, sizeof(can_msg_t) );
}

/*------------------------------------------------------
Fill the node with the input request message
------------------------------------------------------*/
static can_ret_code_t
mid_msg_node_req_fill
    (
    can_msg_t   const *const req_msg_p,
    mid_msg_lst        const node_p
    )
{
can_ret_code_t  l_ret_code  = CAN_RC_NOT_AVAILABLE;
uint32 l_inst_can_id        = 0;
uint8  l_inst_svc_id        = 0;
uint32 l_req_can_id         = req_msg_p->id;
uint8  l_req_svc_id         = req_msg_p->data[MID_MSG_REQMFNC_IDX];
uint8  index = 0;

/*------------------------------------------------------
Find the para instance
------------------------------------------------------*/
for( index = 0; index < ( sizeof( mid_msg_inst ) / sizeof(mid_msg_t) ); index++ )
    {
    l_inst_can_id = mid_msg_inst[index].req_can_id;
    l_inst_svc_id = mid_msg_inst[index].req_svc_id;

    if( l_inst_can_id == l_req_can_id &&
        l_inst_svc_id == l_req_svc_id )
        {
        l_ret_code = CAN_RC_SUCCESS;
        break;
        }
    }

if( l_ret_code == CAN_RC_SUCCESS )
    {
    /*------------------------------------------------------
    Set these paras
    ------------------------------------------------------*/
    node_p->req_msg_wait   = 0;
    node_p->req_msg_time   = 0;
    node_p->req_msg_status = MID_MSG_STAT_WAIT_RES_SHORT;

    /*------------------------------------------------------
    Fill data field
    ------------------------------------------------------*/
    node_p->req_msg.id     = req_msg_p->id,
    node_p->req_msg.size   = req_msg_p->size;
    memcpy( node_p->req_msg.data, req_msg_p->data, req_msg_p->size );

    node_p->pos_resp_msg.id  = mid_msg_inst[index].resp_can_id;
    node_p->pos_resp_msg.data[MID_MSG_RESMFNC_IDX] = mid_msg_inst[index].pos_svc_id;

    node_p->neg_resp_msg.id  = mid_msg_inst[index].resp_can_id;
    node_p->neg_resp_msg.data[MID_MSG_NRES_NACK_IDX] = MID_MSG_NRES_NACK;
    node_p->neg_resp_msg.data[MID_MSG_NRES_SID_IDX]  = req_msg_p->data[MID_MSG_REQMFNC_IDX];
    }

return l_ret_code;
}

/*------------------------------------------------------
Search the message in the list by can id and service id
------------------------------------------------------*/
static mid_msg_lst
mid_msg_node_search
    (
    can_msg_t   const *const msg_p
    )
{
uint32 l_msg_can_id  = 0;
uint8  l_msg_svc_id  = 0;
uint32 l_can_id      = msg_p->id;
uint8  l_svc_id      = MID_MSG_SVC_ID_DEMO;
mid_msg_lst l_node_p = msg_lst_head;

/*------------------------------------------------------
Find the node whose element timer equals to the input
------------------------------------------------------*/
while( ( l_node_p != NULL ) &&
       ( l_msg_can_id != l_can_id || l_msg_svc_id != l_svc_id ) )
    {
    l_node_p = l_node_p->next;

    /*------------------------------------------------------
    Find the node by request CAN id and service id
    ------------------------------------------------------*/
    if( ( l_can_id == TX0_REQ_MT_FUNC_CNT_CAN0_ID  ) ||
        ( l_can_id == TX4_REQ_REPRGRM_INFO_CAN0_ID ) ||
        ( l_can_id == TX2_REQ_SUPPORT_CAN0_ID ) )
        {
        l_msg_can_id = l_node_p->req_msg.id;
        l_msg_svc_id = l_node_p->req_msg.data[MID_MSG_REQMFNC_IDX];
        }
    /*------------------------------------------------------
    Find the node by response CAN id and service id
    ------------------------------------------------------*/
    else if( ( l_can_id == RX4_RES_MT_FUNC_CNT_CAN0_ID ) ||
             ( l_can_id == RX9_RES_RPRGRM_INFO_CAN0_ID ) ||
             ( l_can_id == RX2_RES_SUPPORT_CAN0_ID ) )
        {
        if( msg_p->data[MID_MSG_RESMFNC_IDX] == MID_MSG_NRES_NACK )
            {
            l_svc_id     = msg_p->data[MID_MSG_NRES_SID_IDX];

            l_msg_can_id = l_node_p->neg_resp_msg.id;
            l_msg_svc_id = l_node_p->neg_resp_msg.data[MID_MSG_NRES_SID_IDX];
            }
        else
            {
            l_svc_id     = msg_p->data[MID_MSG_REQMFNC_IDX];

            l_msg_can_id = l_node_p->pos_resp_msg.id;
            l_msg_svc_id = l_node_p->pos_resp_msg.data[MID_MSG_RESMFNC_IDX];
            }
        }
    }

return l_node_p;
}

/*------------------------------------------------------
Insert a request to the request message list
------------------------------------------------------*/
static can_ret_code_t
mid_msg_list_insert
    (
    can_msg_t   const *const req_msg_p
    )
{
can_ret_code_t  l_ret_code      = CAN_RC_NOT_AVAILABLE;
mid_msg_lst     l_node_pre_p    = msg_lst_head;
uint8           l_svc_staus     = 0;

/*------------------------------------------------------
Find if there is a same request message node
------------------------------------------------------*/
mid_msg_lst l_node_p = mid_msg_node_search( req_msg_p );

if( l_node_p != NULL )
    {
    /*------------------------------------------------------
    Client must not transmit next "Request A" message before
    "Response A" is received for previous "Request A".
    ------------------------------------------------------*/
    l_svc_staus = l_node_p->req_msg_status;
    if( l_svc_staus == MID_MSG_STAT_WAIT_RES_SHORT )
        {
        return l_ret_code;
        }
    else
        {
        l_ret_code = mid_msg_node_req_fill( req_msg_p, l_node_p );
        }
    }
else
    {
    /*------------------------------------------------------
    Get a node memory space
    ------------------------------------------------------*/
    l_node_p = pvPortMalloc( sizeof( mid_msg_node ) );
    if( l_node_p == NULL )
        {
        return l_ret_code;
        }

    /*------------------------------------------------------
    Find the message list tail
    ------------------------------------------------------*/
    while( l_node_pre_p->next != NULL )
        {
        l_node_pre_p = l_node_pre_p->next;
        }

    /*------------------------------------------------------
    Link new node to the tail node
    ------------------------------------------------------*/
    l_node_pre_p->next = l_node_p;

    /*------------------------------------------------------
    Set new node next pointer
    ------------------------------------------------------*/
    l_node_p->next = NULL;

    /*------------------------------------------------------
    Fill the node
    ------------------------------------------------------*/
    l_ret_code = mid_msg_node_req_fill( req_msg_p, l_node_p );
    }

return l_ret_code;
}

/*------------------------------------------------------
API for other module sending request
------------------------------------------------------*/
can_ret_code_t can_mid_req
    (
    uint32  can_id,
    uint8   msg_len,
    uint8   svc_id,
    uint8   svc_opt
    )
{
can_ret_code_t l_ret_code  = CAN_RC_NOT_AVAILABLE;
can_msg_t l_req_msg        = { 0 };

/*------------------------------------------------------
Set request message
------------------------------------------------------*/
l_req_msg.id   = can_id;
l_req_msg.size = msg_len;
l_req_msg.data[MID_MSG_REQMFNC_IDX]     = svc_id;
l_req_msg.data[MID_MSG_REQPROCDTL_IDX]  = svc_opt;
l_req_msg.data[MID_MSG_PADDING_IDX]     = MID_MSG_PADDING_DATA;

/*------------------------------------------------------
Add the message to message list for timing and response
waiting
------------------------------------------------------*/
l_ret_code = mid_msg_list_insert( &l_req_msg );

/*------------------------------------------------------
Add the message to message list for timing and response
waiting
------------------------------------------------------*/
if( l_ret_code == CAN_RC_SUCCESS )
    {
    l_ret_code = il_app_frm_put( &l_req_msg );
    }

return l_ret_code;
}

/*------------------------------------------------------
Response callback
------------------------------------------------------*/
void can_mid_resp_cb
    (
    can_msg_t const * const mid_msg_p
    )
{
uint8            l_rs        = 0;
uint8            l_svc_id    = 0;
uint32           l_can_id    = mid_msg_p->id;
uint32           l_msg_len   = mid_msg_p->size;
uint8            l_resp_type = mid_msg_p->data[MID_MSG_RESMFNC_IDX];

mid_msg_lst      l_node_p          = mid_msg_node_search( mid_msg_p );
uint8           *l_node_time_p     = &( l_node_p->req_msg_time );
uint16          *l_node_wait_p     = &( l_node_p->req_msg_wait );
mid_msg_stat_t  *l_node_status_p   = &( l_node_p->req_msg_status );
can_msg_t       *l_node_pos_resp_p = &( l_node_p->pos_resp_msg );

uint8            l_pos_resp_svc_id = mid_msg_p->data[MID_MSG_RESMFNC_IDX];
uint8            l_neg_resp_svc_id = mid_msg_p->data[MID_MSG_NRES_SID_IDX];

/*------------------------------------------------------
Can not find the response node in the message list
------------------------------------------------------*/
if( l_node_p == NULL )
    {
    return;
    }

/*------------------------------------------------------
Only when LC is in short wait(50ms) or long wait(5000ms),
response messages can be valid
------------------------------------------------------*/
if( ( ( *l_node_status_p ) != MID_MSG_STAT_WAIT_RES_SHORT ) &&
    ( ( *l_node_status_p ) != MID_MSG_STAT_WAIT_RES_LONG ) )
    {
    return;
    }

/*------------------------------------------------------
Handle resp date by different type(positive or negative)
------------------------------------------------------*/
if( l_resp_type == MID_MSG_NRES_NACK )
    {
    l_rs = mid_msg_p->data[MID_MSG_NRES_RS_IDX];
    if( l_rs == MID_MSG_NRES_RS_WAIT_REQ )
        {
        *l_node_wait_p   = 0;
        *l_node_time_p   = 0;
        *l_node_status_p = MID_MSG_STAT_WAIT_RES_LONG;
         l_svc_id        = l_neg_resp_svc_id;
        PRINTF("Neg resp %x %x!\r\n", l_can_id, l_svc_id );
        //TBD nodity upper layer (resending is in the mid_task)
        }
    else if( l_rs == MID_MSG_NRES_RS_NOT_SUPP )
        {
        /*------------------------------------------------------
        Handle the response message
        ------------------------------------------------------*/
        *l_node_wait_p   = 0;
        *l_node_time_p   = 0;
        *l_node_status_p = MID_MSG_STAT_WAIT_RES_SHORT;
         l_svc_id        = l_neg_resp_svc_id;

        PRINTF("Not supp %x %x!\r\n", l_can_id, l_svc_id );
        //TBD nodity upper layer to handle no supported service ID
        }
    }
else
    {
    /*------------------------------------------------------
    Handle the positive response message
    ------------------------------------------------------*/
    *l_node_wait_p   = 0;
    *l_node_time_p   = 0;
    *l_node_status_p = MID_MSG_STAT_INITED;
     l_svc_id        = l_pos_resp_svc_id;

    /*------------------------------------------------------
    Data modify
    ------------------------------------------------------*/
    memcpy( l_node_pos_resp_p->data, mid_msg_p->data, l_msg_len );

    /*------------------------------------------------------
    Set the function list
    ------------------------------------------------------*/
    if( ( l_can_id == RX2_RES_SUPPORT_CAN0_ID ) &&
        ( supp_func_list_syc == FALSE ) )
        {
        supp_func_list_syc = TRUE;
        memcpy( &supp_func_list, &( mid_msg_p->data[MID_MSG_TCFS_IDX] ), sizeof( supp_func_list ) );
        VI_rx_support_function_received( &supp_func_list );
        }

    PRINTF( "Pos resp %x %x!\r\n", l_can_id, l_svc_id );
    //TBD nodity upper layer to handle positive response.
    }
}

/*------------------------------------------------------
Find the positive message node by response CAN ID and
service ID
------------------------------------------------------*/
mid_msg_lst
can_mid_resp_get
    (
    uint32  resp_can_id,
    uint8   resp_svc_id
    )
{
mid_msg_lst l_node_p      = msg_lst_head;
uint32      l_msg_can_id  = 0;
uint8       l_msg_svc_id  = 0;

/*------------------------------------------------------
Find the node whose element timer equals to the input
------------------------------------------------------*/
while( ( l_node_p != NULL ) &&
       ( l_msg_can_id != resp_can_id || l_msg_svc_id != resp_svc_id ) )
    {
    l_node_p = l_node_p->next;

    /*------------------------------------------------------
    Find the node by response CAN id and service id
    ------------------------------------------------------*/
    l_msg_can_id = l_node_p->pos_resp_msg.id;
    l_msg_svc_id = l_node_p->pos_resp_msg.data[MID_MSG_RESMFNC_IDX];
    }

return l_node_p;
}

/*------------------------------------------------------
Middle layer signal value set for event type messages
------------------------------------------------------*/
boolean can_mid_sig_set
    (
    dll_frm_index_t          *frm_index_p, //!< [in] Frame index
    il_sig_handle_t     const sig_handle,  //!< [in] signal handle
    uint8               const num_bytes,   //!< [in] number of bytes in the signal
    uint8       const * const p_sig_data   //!< [in] pointer to signal data
    )
{
il_txsig_info_t     const * l_p_txsig_info;
il_txfrm_info_t     const * l_p_txfrm_info;
il_txsig_t          const * l_p_tx_sig;
il_txfrm_t          const * l_p_txfrm;
il_sig_index_t              l_sig_index;
il_sig_index_t              l_num_signals;
can_hw_inst_t               l_hw_inst;
boolean                     l_success;

/*------------------------------------------------------
Initialize the return value, then validate the signal
handle with respect to the range of CAN instances
------------------------------------------------------*/
l_success = FALSE;
l_hw_inst = IL_GET_HWINST_FROM_SIGNAL_HANDLE( sig_handle );

if( l_hw_inst < CAN_NUM_INSTANCES )
    {
    /*------------------------------------------------------
    Verify that the signal index is within a valid range and
    that the pointer to the data is not NULL
    ------------------------------------------------------*/
    l_p_txsig_info = il_get_txsig_info_ptr( l_hw_inst );
    l_num_signals  = l_p_txsig_info->num_signals;
    l_sig_index    = IL_GET_INDEX_FROM_SIGNAL_HANDLE( sig_handle );

    if( ( l_sig_index < l_num_signals ) && ( p_sig_data != NULL ) )
        {
        /*------------------------------------------------------
        Get the frame information for this signal index
        ------------------------------------------------------*/
        l_p_tx_sig     = &( l_p_txsig_info->p_il_txsig[l_sig_index] );
        *frm_index_p   = l_p_tx_sig->frame_index;
        l_p_txfrm_info = il_get_txfrm_info_ptr( l_hw_inst );
        l_p_txfrm      = &( l_p_txfrm_info->p_il_txfrm[*frm_index_p] );

        /*------------------------------------------------------
        Perform thread safe update of the frame signal data
        ------------------------------------------------------*/
        taskENTER_CRITICAL();

        l_success =  pack_frame_signal( l_p_tx_sig->start_bit,
                                        l_p_tx_sig->num_bits,
                                        p_sig_data,
                                        l_p_txfrm->p_data,
                                        num_bytes );
        taskEXIT_CRITICAL();
        }
    }

return l_success;
}

/*------------------------------------------------------
Middle layer frame send
------------------------------------------------------*/
void can_mid_frm_send
    (
    dll_frm_index_t frm_index
    )
{
transmit_frame( CAN_CONTROLLER_2, frm_index );
}

/*------------------------------------------------------
Middle layer request  and response message task
------------------------------------------------------*/
void can_mid_task
    (
    void
    )
{
can_ret_code_t   l_ret_code       = CAN_RC_NOT_AVAILABLE;
uint8           *l_node_time_p    = NULL;
uint16          *l_node_wait_p    = NULL;
mid_msg_stat_t  *l_node_status_p  = NULL;
can_msg_t       *l_node_req_p     = NULL;
mid_msg_lst      l_node_p         = msg_lst_head;

/*------------------------------------------------------
There is no request message in the list
------------------------------------------------------*/
if( l_node_p == NULL )
    {
    return;
    }

/*------------------------------------------------------
Handle all the nodes in the list
------------------------------------------------------*/
while( l_node_p->next != NULL )
    {
    l_node_p = l_node_p->next;

    /*------------------------------------------------------
    Get the message node status and request message
    ------------------------------------------------------*/
    l_node_wait_p    = &( l_node_p->req_msg_wait );
    l_node_time_p    = &( l_node_p->req_msg_time );
    l_node_status_p  = &( l_node_p->req_msg_status );
    l_node_req_p     = &( l_node_p->req_msg );

    /*------------------------------------------------------
    Handle message node with different status
    ------------------------------------------------------*/
    switch( *l_node_status_p )
        {
        case MID_MSG_STAT_INITED :

            break;

        case MID_MSG_STAT_WAIT_RES_SHORT :
            /*------------------------------------------------------
            Ticker increases
            ------------------------------------------------------*/
            ( *l_node_wait_p )++;
            if( ( *l_node_wait_p ) > MID_MSG_RES_SHORT_TIMEOUT )
                {
                ( *l_node_wait_p ) = 0;
                ( *l_node_time_p )++;
                if( ( *l_node_time_p ) >= MID_MSG_RE_SEND_TIME_SHORT )
                    {
                    ( *l_node_status_p ) = MID_MSG_STAT_COMM_ERR;

                    /*------------------------------------------------------
                    Notify the communication error
                    ------------------------------------------------------*/
                    PRINTF( "Comm error %x!\r\n", l_node_req_p->id );
                    }
                else
                    {
                    ( *l_node_status_p ) = MID_MSG_STAT_WAIT_RES_MID;
                    }
                }
            break;

        case MID_MSG_STAT_WAIT_RES_MID :
            /*------------------------------------------------------
            Ticker increases
            ------------------------------------------------------*/
            ( *l_node_wait_p )++;
            if( ( *l_node_wait_p ) > MID_MSG_RES_MID_TIMEOUT )
                {
                ( *l_node_wait_p ) = 0;
                ( *l_node_status_p ) = MID_MSG_STAT_WAIT_RES_SHORT;

                /*------------------------------------------------------
                Re-send the request message 50ms after the first sending
                without response
                ------------------------------------------------------*/
                l_ret_code = il_app_frm_put( l_node_req_p );
                }
            break;

        case MID_MSG_STAT_WAIT_RES_LONG :
            /*------------------------------------------------------
            Ticker increases
            ------------------------------------------------------*/
            ( *l_node_wait_p )++;
            if( ( *l_node_wait_p ) > MID_MSG_RES_LONG_TIMEOUT )
                {
                ( *l_node_wait_p ) = 0;
                ( *l_node_time_p )++;

                /*------------------------------------------------------
                Client judge as communication error if there is no response
                even though Client send the request message for 3 times.
                ------------------------------------------------------*/
                if( ( *l_node_time_p ) > MID_MSG_RE_SEND_TIME_LONG )
                    {
                    ( *l_node_status_p ) = MID_MSG_STAT_COMM_ERR;

                    /*------------------------------------------------------
                    Notify the communication error
                    ------------------------------------------------------*/
                    PRINTF( "Comm error %x!\r\n", l_node_req_p->id );
                    }
                }
            break;

        case MID_MSG_STAT_RES_SUCCESS :

            break;


        case MID_MSG_STAT_COMM_ERR :
            //TBD communication error handle.
            break;
        }
    }
}

/*------------------------------------------------------
Handshake with Meter to get supported functions list
------------------------------------------------------*/
static can_ret_code_t
can_mid_hand_shake
    (
    void
    )
{
can_ret_code_t  l_ret_code  = CAN_RC_NOT_AVAILABLE;

/*------------------------------------------------------
Only one byte for function list request
------------------------------------------------------*/
l_ret_code = can_mid_req( TX2_REQ_SUPPORT_CAN0_ID,    IL_CAN0_TX2_REQ_SUPPORT_TXFRM_LEN,
                          MID_MSG_SID_SUPP_FUNC_LIST, MID_MSG_PADDING_DATA );
return l_ret_code;
}

#if( DEBUG_TX_CAN_SUPPORT )
/*------------------------------------------------------
Positive and negative test
------------------------------------------------------*/
static can_ret_code_t
can_mid_pos_neg_test
    (
    void
    )
{
can_ret_code_t  l_ret_code  = CAN_RC_NOT_AVAILABLE;

/*------------------------------------------------------
Positive test
------------------------------------------------------*/
l_ret_code = can_mid_req( TX0_REQ_MT_FUNC_CNT_CAN0_ID, IL_CAN0_TX0_REQ_MT_FUNC_CNT_TXFRM_LEN,
                          MID_MSG_SID_UNIT_CHNG, MID_MSG_PROCDTL_CHNG_DIST_UNIT_TO_MILE );

/*------------------------------------------------------
Negative test
------------------------------------------------------*/
l_ret_code = can_mid_req( TX4_REQ_REPRGRM_INFO_CAN0_ID, IL_CAN0_TX4_REQ_REPRGRM_INFO_TXFRM_LEN,
                          MID_MSG_SID_REPROG, MID_MSG_PROGSTS_START_REQ );

return l_ret_code;
}

/*------------------------------------------------------
No response test
------------------------------------------------------*/
static can_ret_code_t
can_mid_no_resp_test
    (
    void
    )
{
dll_frm_index_t  l_frm_index;

uint8  bnt_status = IL_VT_HEATER_LVL_BTN_STAT_AUD_UP;
uint8  lvl_lv     = IL_VT_HEATER_LVL_LV_MID;
uint8  lvl_select = IL_VT_HEATER_LVL_SLECT_RIDER_SEAT_HEATER;

/*------------------------------------------------------
Fill the frame with different signals' values
------------------------------------------------------*/
can_mid_sig_set(
                &l_frm_index,
                 IL_CAN0_HEATER_LVL_BTN_STAT_AUD_TXSIG_HANDLE,
                 IL_CAN0_HEATER_LVL_BTN_STAT_AUD_TXSIG_NBYTES,
                &bnt_status
                );

can_mid_sig_set(
                &l_frm_index,
                IL_CAN0_HEATER_LVL_LV_TXSIG_HANDLE,
                IL_CAN0_HEATER_LVL_LV_TXSIG_NBYTES,
                &lvl_lv
                );

can_mid_sig_set(
                &l_frm_index,
                IL_CAN0_HEATER_LVL_SLECT_TXSIG_HANDLE,
                IL_CAN0_HEATER_LVL_SLECT_TXSIG_NBYTES,
                &lvl_select
                );

/*------------------------------------------------------
Send frame
------------------------------------------------------*/
can_mid_frm_send( l_frm_index );
}
#endif

/*------------------------------------------------------
Init CAN middle layer module
------------------------------------------------------*/
void can_mid_init
    (
    void
    )
{
/*------------------------------------------------------
Init message list
------------------------------------------------------*/
mid_msg_list_init();

/*------------------------------------------------------
Handshake with Meter to check out those functions
it supports
------------------------------------------------------*/
can_mid_hand_shake();

#if( DEBUG_TX_CAN_SUPPORT )
/*------------------------------------------------------
No response test case
------------------------------------------------------*/
can_mid_no_resp_test();

/*------------------------------------------------------
Positive and negative test case
------------------------------------------------------*/
can_mid_pos_neg_test();
#endif

}

/*------------------------------------------------------
Get supported functions
------------------------------------------------------*/
mid_msg_supp_func_t*
can_mid_get_supp_func_list
    (
    void
    )
{
return ( &supp_func_list );
}

