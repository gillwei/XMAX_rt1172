#include "client_dcm_type.h"
#include "fsl_debug_console.h"/*for debug*/
#define MEM_DEBUG       TRUE


typedef enum
{
CLIENT_MEM_INIT = 0,
CLIENT_MEM_NORMAL,
CLIENT_MEM_OVERFLOW,
CLIENT_MEM_EMPTY,
CLIENT_MEM_MAX
}client_mem_result_type;

typedef struct
{
boolean overflow_flag;
boolean empty_flag;
uint16 length;
uint8* mem_data;
}client_mem_management_info_type;


extern void client_mem_init
    (
    void
    );

extern client_ReturnType client_mem_storage_init_dtc_data
    (
    uint8 channel_id,
    uint16 data_lenth,
    uint8* storage_data
    );

extern client_ReturnType client_mem_get_init_dtc_data
    (
    uint8 channel_id,
    client_mem_result_type* result,
    uint16* resp_length,
    uint8** resp_data
    );

extern client_ReturnType client_mem_storage_identifier_data
    (
    uint8 channel_id,
    uint16 data_lenth,
    uint8* storage_data
    );

extern void client_mem_storage_server_code
    (
    uint16 server_code
    );

boolean client_mem_get_storage_init_dtc_state
    (
    uint8 channel_id
    );

typedef struct
{
uint8 channel_id;
client_mem_result_type result;
uint16* resp_length;
uint8* resp_data;
}client_mem_resposne_type;

extern void client_mem_get_current_command
    (
    void
    );

extern client_ReturnType client_mem_transport_result_notify
    (
    boolean result
    );

#if(MEM_DEBUG)
extern client_ReturnType client_mem_print_init_dtc_data
    (
    void
    );

extern client_ReturnType client_mem_print_indentifier_data
    (
    void
    );

extern client_mem_result_type client_mem_get_identifier_data
    (
    uint16* resp_length,
    uint8** resp_data
    );

extern client_ReturnType client_mem_send_can_data
   (
   void
   );

extern client_ReturnType client_mem_reset_data
    (
    void
    );

#endif

