//#DCM_NRC_GENERAL_REJECT
#ifndef _CLIENT_DCM_CFG_H_
#define _CLIENT_DCM_CFG_H_
#include "client_dcm_type.h"
#include "client_dcm.h"
#include "can_tp.h"
/*for appl*/
#define SUPPORT_SERVER_NUM                     ( TP_CAN0_NUM_CHANNELS - 1)/*22*/

#define CLIENT_RX_MAX_BUFFER_LEN               (0xFF)
#define CLIENT_TX_MAX_BUFFER_LEN               (0xFF)

#define SUPPORT_FUCNTION_NUMS                  (0x07)
#define REC_MAX_SNS                            (0x02)
#define RESEND_MAX_CONUNT                      (0x03)
#define SUPPORT_COMMON_COUNT                   (0x05)
#define SUPPORT_MARKET_COUNT                   (0x20)
#define MAX_FFD_COUNT                          (0x05)
#define no_server_connected                    (0xFF)

/*for dcm*/
#define P_CLIENT_TIME                          (2000)
#define P_CLIENT_STAER_TIME                    (2000)
#define S3_TIME                                (30000)


#define BYTE_NUM_0                             (0x00)
#define BYTE_NUM_1                             (0x01)
#define BYTE_NUM_2                             (0x02)
#define BYTE_NUM_3                             (0x03)
#define BYTE_NUM_4                             (0x04)
#define BYTE_NUM_5                             (0x05)
#define BYTE_NUM_6                             (0x06)
#define BYTE_NUM_7                             (0x07)

#define DCM_NRC_POSTIVE_RESPONSE               (0x00)
#define DCM_NRC_GENERAL_REJECT                 (0x10)
#define DCM_NRC_SERVICE_NOT_SUPPORT            (0x11)
#define DCM_NRC_SUB_FUNCTION_NOT_SUPPORT       (0x12)
#define DCM_NRC_BUSY_REPEAY_REQUEST            (0x21)
#define DCM_NRC_CONDITION_NOT_CORRECT          (0x22)
#define DCM_NRC_REQUEST_OUT_OF_RANGE           (0x31)
#define DCM_NRC_RESPONSE_PENDING               (0x78)
#define DCM_NEGATIVE_REPOSNE_SERVICE_ID        (0x7F)
#define NEGATIVE_RESPONSE_LENTH                (0x03)

#define SF_PCI_MASK                            (0x0F)


#define DCM_PADDING_DATA                       (0x55)


#define SERVER_ECU_LIST                        {\
                                                0x4E0, 0x4E1, 0x4E2, 0x4E3, 0x4E4 ,0x4E5,\
                                                0x4E6, 0x4E7, 0x4D1, 0x4D2, 0x4D3, 0x4D4,\
                                                0x4D5, 0x4D6, 0x4C0, 0x4C1, 0x4C2, 0x4C3,\
                                                0x4C4, 0x4C5, 0x4C6, 0x4C7\
                                               }


/*for 10h*/
#define DCM_DIAGNOSTC_SESSION_SERVICE_ID       (0x10)
#define DCM_10h_REQ_DATA_LEN                   (0x02)
#define DCM_10h_RESP_DATA_LEN                  (0x02)
#define DCM_10h_SUBFUNC_NUM                    (0x02)
#define DCM_10h_DEFAULT_ID                     (0x01)
#define DCM_10h_EXTEND_ID                      (0x03)

/*for 12h*/
#define DCM_READ_FREEZE_FRAME_DATA_SERVICE_ID  (0x12)
#define DCM_12h_REQ_DATA_LEN                   (0x04)
#define DCM_12h_RECMID                         (0x01)
#define DCM_12h_RECID_MAX                      (0x05)

/*for 18h*/
/*The parameter group of DTC is optional,So abandon it here */
#define DCM_READ_DTC_STATUS_SERVICE_ID         (0x18)
#define DCM_18h_REQ_DATA_LEN                   (0x02)
#define DCM_18h_STATDTC_20                     (0x20)
#define DCM_18h_STATDTC_24                     (0x24)
#define DCM_18h_STATDTC_A1                     (0xA1)
#define DCM_18h_STATDTC_FF                     (0xFF)
#define DCM_18h_INIT_STADTC                    DCM_18h_STATDTC_A1
/*for 21h*/
#define DCM_READ_LOCAL_INDENTIFIER             (0x21)
#define DMC_21h_REQ_DATA_LEN                   (0x02)

/*for 22h*/
#define DCM_READ_COMMON_INDENTIFIER            (0x22)
#define DCM_22h_REQ_DATA_LEN                   (0x03)

/*for 3Eh*/
#define DCM_TESTER_PERSNET_SERVICE_ID          (0x3E)
#define DCM_3Eh_REQ_DATA_LEN                   (0x02)
#define DCM_3Eh_NO_RESPONSE                    (0x02)
#endif
