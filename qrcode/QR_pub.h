/*********************************************************************
* @file
* QR_pub.h
*
* @brief
* QR code module - public API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef QR_PUB_H
#define QR_PUB_H

#ifdef __cplusplus
extern "C"{
#endif

#include <stdbool.h>
#include <stdint.h>

#define QRCODE_PIXEL_PER_MODULE     ( 4 )

typedef struct
    {
    uint32_t module_num;          /**< number of modules in a row/column */
    uint8_t* modules;             /**< pointer to buffer */
    } qrcode_buf_handle_struct;

void QR_init
    (
    void
    );

void QR_generate
    (
    uint8_t* text,
    const uint32_t text_length
    );

qrcode_buf_handle_struct* QR_get_qrcode_buf
    (
    void
    );

#ifdef __cplusplus
}
#endif

#endif /* QR_PUB_H */

