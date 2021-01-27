#ifndef _CLIENT_DCM_TYPE_H_
#define _CLIENT_DCM_TYPE_H_
#include "can_defs.h"


typedef enum
{
CLIENT_ADDRESS_PHYSICAL = 0x00,
CLIENT_ADDRESS_FUNCTIONAL,
CLIENT_ADDRESS_PHYSICAL_FUNCTIONAL
}client_address_type;

typedef enum
{
CLIENT_UN_INITIALIZATION = 0x00,
CLIENT_INITIALIZATION,
CLIENT_INIT_MAX
}client_init_state_type;

typedef enum
{
E_OK = 0x00,
E_NOT_OK,
E_BUSY,
E_RX_DATA_INVALID,
E_RX_FORMAT_ERROR,
E_RX_PENDING,
E_ERROR_MAX
}client_ReturnType;

typedef enum
{
CURRENT_REQ_SESSION_DEFAULT = 0x01,
CURRENT_REQ_SESSION_PROGRAMING,
CURRENT_REQ_SESSION_EXTEND,
CURRENT_REQ_SESSION_MAX
}req_current_session_type;

typedef enum
{
CLIENT_DIAG_STATE_IDLE = 0,
CLIENT_DIAG_STATE_REQUEST,
CLIENT_DIAG_STATE_CONFIRM,
CLIENT_DIAG_STATE_INDICATION_SOM,
CLIENT_DIAG_STATE_INDICATION,
CLIENT_DIAG_STATE_RX_PENDING,
CLIENT_DIAG_STATE_RX_PENDINF_DONE,
CLIENT_DIAG_STATE_MAX
}client_diag_state_type;

typedef struct
{
uint8* req_data;
uint16 req_data_len;
uint8* resp_data;
uint16 resp_data_len;
client_address_type  address_type;
uint8 resp_channel;
uint8 req_channel;
boolean is_receive;
}client_msg_context_type;
#endif
