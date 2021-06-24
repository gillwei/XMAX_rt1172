/*********************************************************************
* @file
* bt_spp_iap2.h
*
* @brief
* Bluetooth SPP profile and iAP2 profile send data API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifndef BT_SPP_IAP2_H
#define BT_SPP_IAP2_H

#ifdef __cplusplus
extern "C" {
#endif


bool BT_SPP_send
    (
    uint8_t  data_length,
    uint8_t* transfer_data
    );

bool BT_IAP2_send
    (
    uint8_t  data_length,
    uint8_t* transfer_data
    );

bool BT_SPP_IAP2_send_y_app
    (
    uint8_t  data_length,
    uint8_t* transfer_data
    );

#ifdef __cplusplus
}
#endif

#endif /* BT_SPP_IAP2_H */
