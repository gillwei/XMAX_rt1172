/*********************************************************************
* @file
* error_code.h
*
* @brief
* Error code for the return value of functions
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef ERROR_CODE_H
#define ERROR_CODE_H

#ifdef __cplusplus
extern "C"{
#endif

#define ERR_NONE            ( 0 )
#define ERR_TYPE_BUF        ( 0x80000000 )
#define ERR_BUF_OVERFLOW    ( ERR_TYPE_BUF | 0x01)
#define ERR_BUF_OPERATION   ( ERR_TYPE_BUF | 0x02 )
#define ERR_TYPE_JPEG       ( 0x40000000 )
#define ERR_JPEG_DECODE     ( ERR_TYPE_JPEG | 0x01 )

#ifdef __cplusplus
}
#endif

#endif /* ERROR_CODE_H */

