/*********************************************************************
* @file
* circular_buffer.c
*
* Implementation of circular buffer
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "fsl_debug_console.h"
#include "circular_buffer.h"
#include "error_code.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/
#define IS_POWER_OF_2(x)                ( ( ( x ) & ( x - 1 ) ) == 0 )
#define CIRCULAR_ADD(x,buffer_size)     ( ( x ) & ( buffer_size ) )

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @private
* get_free_size
*
* Get the free size of circular buffer
*
* @param handle The pointer to the handle of circular buffer
* @return The free size of the circular buffer.
*
*********************************************************************/
static int get_free_size
    (
    circular_buf_handle* handle
    )
{
return ( handle->buffer_size - CIRCULAR_ADD( handle->tail - handle->head, handle->buffer_size ) );
}

/*********************************************************************
*
* @private
* circular_buffer_init
*
* Initialize circular buffer
*
* @param buffer The pointer to the buffer allocated before calling this function.
* @param size allocated memory size for circular buffer.
*             Due to the design of circular buffer,
*             the size has to be 2^n.
* @return Returns the handle of circular buffer
*
*********************************************************************/
circular_buf_handle circular_buffer_init
    (
    char*    description,
    uint8_t* buffer,
    uint32_t size
    )
{
circular_buf_handle handle;

if( NULL != buffer && 0 != size && IS_POWER_OF_2( size ) )
    {
    strncpy( handle.description, description, CIRCULAR_BUF_DESCRIPTION_SIZE );
    handle.buffer_start = buffer;
    handle.buffer_size  = size - 1;
    handle.head = 0;
    handle.tail = 0;
    }
else
    {
    PRINTF( "%s %s err\r\n", __FUNCTION__, description );
    }

return handle;
}

/*********************************************************************
*
* @private
* circular_buffer_write
*
* Write data to circular buffer
*
* @param handle The pointer to the handle of circular buffer
* @param write_data The pointer to the write data buffer
* @param write_size The size to write to circular buffer
* @retval ERR_NONE when no overflow. ERR_BUF_OVERFLOW when overflow happens
*
*********************************************************************/
int circular_buffer_write
    (
    circular_buf_handle* handle,
    uint8_t* write_data,
    uint32_t write_size
    )
{
int result = ERR_NONE;
if( get_free_size( handle ) >= write_size )
    {
    if( 1 == write_size )
        {
        handle->buffer_start[handle->tail] = write_data[0];
        handle->tail = CIRCULAR_ADD( handle->tail + 1, handle->buffer_size );
        }
    else
        {
        int free_size_to_buffer_end = handle->buffer_size - handle->tail + 1;
        if( free_size_to_buffer_end >= write_size )
            {
            memcpy( &handle->buffer_start[handle->tail], write_data, write_size );
            handle->tail = CIRCULAR_ADD( handle->tail + write_size, handle->buffer_size );
            }
        else
            {
            memcpy( &handle->buffer_start[handle->tail], write_data, free_size_to_buffer_end );
            int remain_write_size = write_size - free_size_to_buffer_end;
            memcpy( handle->buffer_start, &write_data[free_size_to_buffer_end], remain_write_size );
            handle->tail = CIRCULAR_ADD( handle->tail + write_size, handle->buffer_size );
            }
        }
    }
else
    {
    PRINTF( "Err: %s write overflow\r\n", handle->description );
    result = ERR_BUF_OVERFLOW;
    }
return result;
}

/*********************************************************************
*
* @private
* circular_buffer_get_head
*
* Get the head of circular buffer
*
* @param handle The pointer to the handle of circular buffer
* @param buffer The pointer to the pointer of the head of data
* @param size The pointer to the size of data available.
* @retval ERR_NONE if no error. ERR_BUF_OPERATION if buffer is not initialized yet.
*
*********************************************************************/
int circular_buffer_get_head
    (
    circular_buf_handle* handle,
    uint8_t** buffer,
    uint32_t* size
    )
{
int result = ERR_NONE;
if( NULL != handle->buffer_start)
    {
    *buffer = &handle->buffer_start[handle->head];
    if( handle->tail >= handle->head )
        {
        *size = handle->tail - handle->head;
        }
    else
        {
        *size = handle->buffer_size - handle->head + 1;
        }
    }
else
    {
    result = ERR_BUF_OPERATION;
    *size = 0;
    }
return result;
}

/*********************************************************************
*
* @private
* circular_buffer_move_head
*
* Move the head of data after data is processed
*
* @param handle The pointer to the handle of circular buffer
* @param size The size to move head
* @retval ERR_NONE if moving head ok. ERR_BUF_OPERATION if move size is over data size.
*
*********************************************************************/
int circular_buffer_move_head
    (
    circular_buf_handle* handle,
    uint32_t size
    )
{
int result = ERR_NONE;
if( circular_buffer_get_data_size( handle ) >= size )
    {
    handle->head = CIRCULAR_ADD( handle->head + size, handle->buffer_size );
    }
else
    {
    PRINTF( "Err: %s invalid move head %d\r\n", handle->description, size );
    result = ERR_BUF_OPERATION;
    }
return result;
}

/*********************************************************************
*
* @private
* circular_buffer_get_data_size
*
* Get the data size in circular buffer
*
* @param handle The pointer to the handle of circular buffer
* @retval The data size in circular buffer
*
*********************************************************************/
int circular_buffer_get_data_size
    (
    circular_buf_handle* handle
    )
{
return CIRCULAR_ADD( handle->tail - handle->head, handle->buffer_size );
}

