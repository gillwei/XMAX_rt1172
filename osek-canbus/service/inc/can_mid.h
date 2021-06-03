/*!*******************************************************************
*
* @defgroup can_mid middle Layer between CAN and other modules
* @ingroup can_stack
* @{
*
*********************************************************************/
/*--------------------------------------------------------------------
                            GENERAL INCLUDES
--------------------------------------------------------------------*/
#ifndef _CAN_MID_H
#define _CAN_MID_H

#include "can_defs.h"

/*--------------------------------------------------------------------
                            MACROS
--------------------------------------------------------------------*/
/*------------------------------------------------------
Padding
------------------------------------------------------*/
#define MID_MSG_PADDING_DATA                      0x55

/*------------------------------------------------------
Request
------------------------------------------------------*/
#define MID_MSG_REQ_MT_FNC_LEN                    3
#define MID_MSG_REPROG_LEN                        3
#define MID_MSG_HANDSHAKE_LEN                     1

#define MID_MSG_REQMFNC_IDX                       0
#define MID_MSG_REQPROCDTL_IDX                    1
#define MID_MSG_PADDING_IDX                       2

/*------------------------------------------------------
Positive response
------------------------------------------------------*/
#define MID_MSG_RESMFNC_IDX                       0
#define MID_MSG_RESPROCDTL_IDX                    1
#define MID_MSG_PADDING_IDX                       2

#define MID_MSG_LBREPSTPR_IDX                     0
#define MID_MSG_PROGSTS_IDX                       1
#define MID_MSG_PADDING_IDX                       2

#define MID_MSG_RESSSFL_IDX                       0
#define MID_MSG_TCFS_IDX                          1
#define MID_MSG_BRZEGR_IDX                        2
#define MID_MSG_SFL_START_IDX                     3
#define MID_MSG_SFL_LEN                           5

/*------------------------------------------------------
Negative response
------------------------------------------------------*/
#define MID_MSG_NRES_NACK                         0xEE //!< Negative response ID
#define MID_MSG_NRES_RS_NOT_SUPP                  0x10 //!< Service ID is not supported.
#define MID_MSG_NRES_RS_WAIT_REQ                  0x20 //!< Wait request.

#define MID_MSG_NRES_NACK_IDX                     0
#define MID_MSG_NRES_SID_IDX                      1
#define MID_MSG_NRES_RS_IDX                       2

/*--------------------------------------------------------------------
                            TYPES
--------------------------------------------------------------------*/
/*------------------------------------------------------
Message service id in Middle layer CAN ID:0x584 Meter
func cont
------------------------------------------------------*/
typedef enum tagMID_MSG_MT_FUNC_CONT_SVC_ID_TYPE
    {
    MID_MSG_SID_VC_INFO_RST                     = 0x10, //!< Req Service ID for vehicle info reset
    MID_MSG_SID_VC_INFO_CHNG_MT_LCD             = 0x15, //!< For change vc info in meter LCD
    MID_MSG_SID_UNIT_CHNG                       = 0x20, //!< For changing units
    MID_MSG_SID_TCS_SWITCH                      = 0x30, //!< For TCS switching

    }mid_msg_mt_func_cont_sid_t;

/*------------------------------------------------------
Vehicle info reset and change
------------------------------------------------------*/
#define      MID_RES_SID_VC_INFO_RST              0x50
#define      MID_RES_SID_VC_INFO_CHNG             0x55

typedef enum tagMID_MSG_VC_INFO_TYPE
    {
    MID_MSG_PROCDTL_VC_INFO_CHNG_TO_ODO         = 0x10, //!< Change to ODO
    MID_MSG_PROCDTL_VC_INFO_RST_CHNG_TO_TRIP1   = 0x20, //!< Reset TRIP 1 or Change to TRIP 1
    MID_MSG_PROCDTL_VC_INFO_RST_CHNG_TO_TRIP2   = 0x30, //!< Reset TRIP 2 or Change to TRIP 2
    MID_MSG_PROCDTL_VC_INFO_RST_CHNG_TO_TRIPF   = 0x40, //!< Reset TRIP F or Change to TRIP F
    MID_MSG_PROCDTL_VC_INFO_RST_AVG_SPEED       = 0x50, //!< Reset AVG SPEED
    MID_MSG_PROCDTL_VC_INFO_RST_AVG_FUEL        = 0x60, //!< Reset AVG FUEL
    MID_MSG_PROCDTL_VC_INFO_RST_FUEL_CONS       = 0x70, //!< Reset FUEL CONS

    }mid_msg_vc_info_t;

/*------------------------------------------------------
Maintenence info
------------------------------------------------------*/
#define      MID_RES_SID_MAINT_INFO               0x50 //!< Res SID for req SID:0x10

typedef enum tagMID_MSG_MAINT_INFO_TYPE
    {
    MID_MSG_PROCDTL_MAINT_INFO_RST_AT_TOP       = 0xA0, //!< Reset the value at the top
    MID_MSG_PROCDTL_MAINT_INFO_RST_AT_MID       = 0xB0, //!< Reset the value at the middle
    MID_MSG_PROCDTL_MAINT_INFO_RST_AT_BOT       = 0xC0, //!< Reset the value at the bottom

    }mid_msg_maint_info_t;

/*------------------------------------------------------
Traction Control System(TCS)
------------------------------------------------------*/
#define      MID_RES_SID_TCS                      0x70 //!< Res SID for TCS switching:0x30

typedef enum tagMID_MSG_TCS_TYPE
    {
    MID_MSG_PROCDTL_TCS_OFF_TO_ON               = 0x10, //!< Switch TCS from OFF to ON
    MID_MSG_PROCDTL_TCS_ON_TO_OFF               = 0x20, //!< Switch TCS from ON to OFF

    }mid_msg_tcs_t;

/*------------------------------------------------------
Unit
------------------------------------------------------*/
#define      MID_RES_SID_UNIT                     0x60 //!< Res SID for req SID:0x20

typedef enum tagMID_MSG_UNIT_TYPE
    {
    MID_MSG_PROCDTL_CHNG_DIST_UNIT_TO_KM        = 0x10, //!< Change distance unit to [km]
    MID_MSG_PROCDTL_CHNG_DIST_UNIT_TO_MILE      = 0x11, //!< Change distance unit to [mile]
    MID_MSG_PROCDTL_CHNG_FUEL_UNIT_TO_KML       = 0x20, //!< Change fuel unit to [km/L]
    MID_MSG_PROCDTL_CHNG_FUEL_UNIT_TO_MPG       = 0x21, //!< Change fuel unit to [MPG]
    MID_MSG_PROCDTL_CHNG_FUEL_UNIT_TO_L100KM    = 0x23, //!< Change fuel unit to [L/100km]
    MID_MSG_PROCDTL_CHNG_PRSS_UNIT_TO_KPA       = 0x30, //!< Change pressure unit to [kPa]
    MID_MSG_PROCDTL_CHNG_PRSS_UNIT_TO_PSI       = 0x31, //!< Change pressure unit to [psi]
    MID_MSG_PROCDTL_CHNG_PRSS_UNIT_TO_GKGFPSCM  = 0x32, //!< Change pressure unit to [kgf/cm2]
    MID_MSG_PROCDTL_CHNG_TEMP_UNIT_TO_DEGC      = 0x40, //!< Change temperature unit to [degC]
    MID_MSG_PROCDTL_CHNG_TEMP_UNIT_TO_DEGF      = 0x41, //!< Change temperature unit to [degF]

    }mid_msg_unit_t;

/*------------------------------------------------------
Reprogram CAN ID:0x5B3
------------------------------------------------------*/
#define    MID_MSG_SID_REPROG                     0x70 //!< For software update
#define    MID_RES_SID_REPROG                     0xB0 //!< Res SID for req SID:0x70

typedef enum tagMID_MSG_REPROG_TYPE
    {
    MID_MSG_PROGSTS_START_REQ                   = 0xC0, //!< Software flash start request.
    MID_MSG_PROGSTS_COMPLETE_REQ                = 0xD0, //!< Software flash complete(Reboot request)
    MID_MSG_PROGSTS_FAILED                      = 0xE0, //!< Software flash start request.

    }mid_msg_reprog_t;

/*------------------------------------------------------
Supported function list.CAN ID:0x581
------------------------------------------------------*/
#define    MID_MSG_SID_SUPP_FUNC_LIST             0x10 //!< Req SID for supported function list.
#define    MID_RES_SID_SUPP_FUNC_LIST             0x50 //!< Res SID for req SID:0x10

/*--------------------------------------------------------------------
                            TYPES
--------------------------------------------------------------------*/
/*------------------------------------------------------
Request and response messages' struct
------------------------------------------------------*/
typedef struct tagMID_MSG_TYPE
    {
    uint32          req_can_id;  //!< Request CAN ID
    uint32          resp_can_id; //!< Response CAN ID
    uint8           req_svc_id;  //!< Request service ID
    uint8           pos_svc_id;  //!< Positive response service ID

    }mid_msg_t;

/*------------------------------------------------------
Message Status type
------------------------------------------------------*/
typedef enum tagMID_MSG_STAT_TYPE
    {
    MID_MSG_STAT_INITED,
    MID_MSG_STAT_WAIT_RES_SHORT,
    MID_MSG_STAT_WAIT_RES_MID,
    MID_MSG_STAT_WAIT_RES_LONG,
    MID_MSG_STAT_RES_SUCCESS,
    MID_MSG_STAT_COMM_ERR

    }mid_msg_stat_t;

/*------------------------------------------------------
Request messages list
------------------------------------------------------*/
typedef struct mid_msg_node
    {
    can_msg_t         req_msg;        //!< Request message
    can_msg_t         pos_resp_msg;   //!< Positive response
    can_msg_t         neg_resp_msg;   //!< Negative response

    uint16            req_msg_wait;   //!< Short wait is 50ms, long wait is 5000ms
    uint8             req_msg_time;   //!< Client can send the request message for 3 times.if no resp
    mid_msg_stat_t    req_msg_status; //!< Request message status

    struct mid_msg_node* next;

    }mid_msg_node;

typedef struct mid_msg_node   *mid_msg_lst;

/*------------------------------------------------------
Supported functions list sfl
------------------------------------------------------*/
typedef union
    {
    struct
        {
        /*------------------------------------------------------
        SFL Data0(message data3 )
        ------------------------------------------------------*/
        boolean seat_heater        : 1;
        boolean grip_warmer        : 1;
        boolean tcs                : 1;
        boolean clk                : 1;
        boolean mt_brgtnss_adj     : 1;
        boolean Ftrip              : 1;
        boolean trip2              : 1;
        boolean trip1              : 1;

        boolean avg_fuel           : 1;
        boolean crt_fuel           : 1;
        boolean avg_spd            : 1;
        boolean Free2              : 1;
        boolean Free1              : 1;
        boolean Vbelt_trip         : 1;
        boolean oil_trip           : 1;
        boolean wind_scrn          : 1;

        boolean tire_frnt_l        : 1;
        boolean tire_frnt_r        : 1;
        boolean tire_frnt          : 1;
        boolean rng                : 1;
        boolean coolant            : 1;
        boolean bat                : 1;
        boolean air                : 1;
        boolean fuel_cons          : 1;

        boolean rsv                : 5;
        boolean cruise             : 1;
        boolean tip_time           : 1;
        boolean tire_rear          : 1;

        uint8 unused               : 8;
        }bit;

    uint8 fsl_data[5];
    }mid_msg_supp_func_sfl_t;

/*------------------------------------------------------
Supported functions
------------------------------------------------------*/
typedef struct
    {
    uint8                   tcfs;
    uint8                   brzegr;
    mid_msg_supp_func_sfl_t sfl;

    }mid_msg_supp_func_t;

/*------------------------------------------------------
Middle layer Supplementcan bluetooth message type
------------------------------------------------------*/
typedef struct
    {
    can_msg_id_t      id;
    can_msg_data_t    *data;
    }can_supp_msg_t;

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
uint32 can_mid_fuel_cons_get
    (
    void
    );

void can_mid_init
    (
    void
    );

void can_mid_resp_cb
    (
    can_msg_t const * const mid_msg_p
    );

void can_mid_task
    (
    void
    );

void can_mid_supplement_task
    (
    void
    );

#endif /* _CAN_MID_H */

