//#DCM_NRC_GENERAL_REJECT
#ifndef _CLIENT_DCM_CFG_H_
#define _CLIENT_DCM_CFG_H_
#include "client_dcm_type.h"
#include "client_dcm.h"
#include "can_tp.h"


#define APPL_CMD_DBUG                          (TRUE)


/*Genernal config*/
#define BYTE_NUM_0                             (0x00)
#define BYTE_NUM_1                             (0x01)
#define BYTE_NUM_2                             (0x02)
#define BYTE_NUM_3                             (0x03)
#define BYTE_NUM_4                             (0x04)
#define BYTE_NUM_5                             (0x05)
#define BYTE_NUM_6                             (0x06)
#define BYTE_NUM_7                             (0x07)


/*Config for Can transport layer*/


/*Config for Diagnostic Comunication module*/
#define P_CLIENT_TIME                          (2000)
#define P_CLIENT_STAER_TIME                    (2000)
#define S3_TIME                                (1000)




/*Config for Dignostic Application module*/
#define SUPPORT_FUCNTION_NUMS                  (0x08)

#define CLIENT_RX_MAX_BUFFER_LEN               (0xFF)
#define CLIENT_TX_MAX_BUFFER_LEN               (0xFF)

#define REC_MAX_SNS                            (0x02)
#define RESEND_MAX_CONUNT                      (0x03)
#define MAX_FFD_COUNT                          (0x05)

#define SUPPORT_SERVER_NUM                     ( TP_CAN0_NUM_CHANNELS - 1)/*22*/
#define NO_SERVER_CONNECT                     (0xFF)
#define SERVER_ECU_LIST                        {\
                                                0x4E0, 0x4E1, 0x4E2, 0x4E3, 0x4E4 ,0x4E5,\
                                                0x4E6, 0x4E7, 0x4D1, 0x4D2, 0x4D3, 0x4D4,\
                                                0x4D5, 0x4D6, 0x4C0, 0x4C1, 0x4C2, 0x4C3,\
                                                0x4C4, 0x4C5, 0x4C6, 0x4C7\
                                               }



                                                 /*for appl*/

#define SUPPORT_COMMON_COUNT                   (0x11)
#define SUPPORT_COMMON_IDS_LIST                { 0xF18A, 0xF18C, 0xF190, 0xF192, 0xF194,\
                                                 0xF195, 0xF197, 0xF198, 0xF199, 0xF1A0,\
                                                 0xF1A1, 0xF1A2, 0xF1EF, 0xF421, 0xF44D,\
                                                 0xf804, 0xF806 }

#define SUPPORT_MONITOR_COUNT                 ( 0x10 )
#define SUPPORT_MONITOR_IDS_LIST              { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06,\
                                                0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C,\
                                                0x0D, 0x0E, 0x0F, 0x48 }



#define SUPPORT_MARKET_COUNT                   (0x20)
#define SUPPORT_MARKET_IDS_LIST                { 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,\
                                                 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,\
                                                 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77,\
                                                 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F\
                                               }
/***********************for ble command***************************/
/*req_comand*/
#define BLE_REQ_CMD_AUTHENTICATION             (0x0101)
#define BLE_REQ_CMD_SERVERLIST                 (0x0103)
#define BLE_REQ_CMD_MALFUNCTION                (0x0105)
#define BLE_REQ_CMD_MALFUNCTION_INTERVAL       (0x0109)
#define BLE_REQ_CMD_VEHICLE_IDENTIFICATION     (0x010A)
#define BLE_REQ_CMD_MARKET_DATA                (0x010C)
#define BLE_REQ_CMD_VEHICLE_INFORMATION        (0x010E)
#define BLE_REQ_CMD_VEHIVLE_INFORMATION_SUPPORT_LIST    (0x0126)
#define BLE_REQ_CMD_VEHICLE_INFORMATION_INTERVAL        (0x0110)
#define BLE_REQ_CMD_FFD                        (0x0111)

/***********************response_comand**************************/
#define BLE_RSP_CMD_AUTHENTICATION             (0x0102)
#define BLE_RSP_CMD_SERVERLIST                 (0x0104)
#define BLE_RSP_CMD_MALFUNCTION                (0x0106)
#define BLE_RSP_CMD_VEHICLE_IDENTIFICATION     (0x010B)
#define BLE_RSP_CMD_MARKET_DATA                (0x010D)
#define BLE_RSP_CMD_VEHICLE_INFORMATION        (0x010F)
#define BLE_RSP_CMD_VEHIVLE_INFORMATION_SUPPORT_LIST    (0x0127)
#define BLE_RSP_CMD_FFD                        (0x0112)

#define BLE_RSP_CMD_NO_VALID_DATA_LENGTH       (0x00)
#define BLE_RSP_CMD_AUTHENTICATION_length      (0x01)

#define BLE_REQ_SERVER_CODE_LENGTH             (0x02)
#define BLE_REQ_COMMON_ID_LENTGH               (0x02)
#define BLE_REQ_LOCAL_ID_LENGTH                (0x02)
/***********************McMalfunctionStatus**********************/
#define BLE_CMD_MAL_STATUS_MARK                (0x01)
#define BLE_CMD_MAL_STATUS_TRIANGLE            (0x02)
#define BLE_CMD_MAL_STATUS_FULL                (0x03)
#define BLE_CMD_MAL_STATUS_TEMPORARY           (0x04)

/*for ble authentication*/
#define BLE_AUT_CCU_ID_OFFSET_ADDR             (0x00)
#define BLE_AUT_PASS_KEY_OFFSET_ADDR           (0x0E)
#define BLE_AUT_UUID_OFSET_ADDR                (0x14)

#define BLE_AUT_CCU_ID_LENGTH                  (0x0E)
#define BLE_AUT_PASS_KEY_LENGTH                (0x06)
#define BLE_AUT_UUID_KEY_LENGTH                (0x20)


/*****************For ISO-14230 protocol***************************/
/*NRC*/
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
