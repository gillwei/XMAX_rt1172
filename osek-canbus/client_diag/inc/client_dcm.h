
#ifndef _CLIENT_DCM_H_
#define _CLIENT_DCM_H_
#include "can_tp.h"
#include "can_defs.h"
#include "client_dcm_type.h"
#include "client_dcm_cfg.h"
#include "fsl_debug_console.h"/*for debug*/

extern void
client_dcm_init
    (
    void
    );

void client_dcm_authencation_state
    (
    boolean value
    );

extern void
client_diag_main_funciton_5ms
    (
    void
    );

extern void
client_dcm_SOM_indication
    (
    tp_n_result_t       const result,       //!< [in] TP receive result
    uint8       const * const p_frame_data, //!< [in] ptr to First Frame data
    boolean             const func_addr,    //!< [in] Functionally addressed TP message
    can_hw_inst_t       const hw_inst,       //!< [in] CAN hardware instance
    tp_chan_index_t const  tp_channel
    );

extern void
client_diag_rx_wrapper
    (
    tp_n_result_t result,
    uint8   const * const rx_buffer,
    uint16  const       mssg_length,
    tp_chan_index_t const  tp_channel
    );

extern void
client_diag_tx_complete
    (
    tp_n_result_t result,
    uint8 hw_inst,
    uint8 channel_id
    );


extern client_ReturnType
client_dcm_req_diagnostic_default_session_functional
    (
    void
    );
extern client_ReturnType
client_dcm_req_diagnostic_default_session_physical
    (
    uint8 channel_id
    );

extern client_ReturnType
client_dcm_req_read_dtc_status_code
    (
    uint8 channel_id,
    uint8 status_code
    );




void client_diag_task
    (
    can_hw_inst_t   const hw_inst           //!< [in] CAN hardware instance
    );

void client_diag_init
    (
    can_hw_inst_t   const hw_inst           //!< [in] CAN hardware instance
    );
#endif