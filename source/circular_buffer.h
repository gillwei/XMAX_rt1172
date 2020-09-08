/*********************************************************************
* @file
* circular_buffer.h
*
* @brief
* Header file of circular buffer.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#ifdef __cplusplus
extern "C"{
#endif

#define CIRCULAR_BUF_DESCRIPTION_SIZE   ( 16 )

typedef struct
    {
    uint8_t* buffer_start; /**< start pointer of circular buffer */
    uint32_t buffer_size;  /**< size of circular buffer */
    uint32_t head;         /**< shift from buffer start to the head of data */
    uint32_t tail;         /**< shift from buffer start to the tail of data */
    char     description[CIRCULAR_BUF_DESCRIPTION_SIZE]; /**< description of circular buffer */
    } circular_buf_handle;

circular_buf_handle circular_buffer_init
    (
    char*    description,
    uint8_t* buffer,
    uint32_t size
    );

int circular_buffer_write
    (
    circular_buf_handle* handle,
    uint8_t* buffer,
    uint32_t size
    );

int circular_buffer_get_head
    (
    circular_buf_handle* handle,
    uint8_t** buffer,
    uint32_t* size
    );

int circular_buffer_move_head
    (
    circular_buf_handle* handle,
    uint32_t size
    );

int circular_buffer_get_data_size
    (
    circular_buf_handle* handle
    );

#ifdef __cplusplus
}
#endif

#endif /* CIRCULAR_BUFFER_H */

