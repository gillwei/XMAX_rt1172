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

typedef struct
    {
    uint32_t image_width;         /**< image width (pixel) */
    uint32_t image_height;        /**< image height (pixel) */
    uint8_t* addr;                /**< pointer to buffer */
    } qrcode_buf_handle_struct;

void QR_init
    (
    void
    );

void QR_generate_qrcode
    (
    uint32_t esn,
    uint32_t pixel_per_mod
    );

qrcode_buf_handle_struct* QR_get_qrcode_buf
    (
    void
    );

uint32_t QR_pixel_per_mod
    (
    void
    );

#ifdef __cplusplus
}
#endif

#endif /* QR_PUB_H */

