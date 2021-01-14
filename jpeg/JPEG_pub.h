/*********************************************************************
* @file
* JPEG_pub.h
*
* @brief
* JPEG module - public API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef JPEG_PUB_H
#define JPEG_PUB_H

#ifdef __cplusplus
extern "C"{
#endif

#include <stdbool.h>
#include <stdint.h>

#define RESULT_ERR                       0
#define RESULT_SUCCESS                   1
#define RESULT_ERR_BUFFER_NOT_AVAILABLE  2

typedef struct
    {
    uint32_t image_width;         /**< image width (pixel) */
    uint32_t image_height;        /**< image height (pixel) */
    uint32_t buffer_size;         /**< buffer allocation size */
    uint8_t* addr;                /**< pointer to buffer */
    bool     is_buffer_available; /**< flag of buffer availability */
    } buffer_info;

void JPEG_init( void );
uint8_t* JPEG_get_jpeg_buffer( void );
uint32_t JPEG_get_jpeg_buffer_size( void );
void JPEG_notify_received( uint32_t jpeg_size, uint8_t* buffer_addr, void ( *callback_func_ptr ) ( int ) );
void JPEG_notify_rgb_loaded( void );
buffer_info* JPEG_take_rgb( void );
void JPEG_give_rgb( void );
bool JPEG_is_rgb_ready( void );

#ifdef __cplusplus
}
#endif

#endif /* JPEG_PUB_H */

