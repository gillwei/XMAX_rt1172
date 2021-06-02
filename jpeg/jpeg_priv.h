/*********************************************************************
* @file
* jpeg_priv.h
*
* @brief
* JPEG - Private API of JPEG
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef JPEG_PRIV_H
#define JPEG_PRIV_H

#ifdef __cplusplus
extern "C"{
#endif

#define ENABLE_JPEG_DEBUG_LOG   ( 0 )

#if( ENABLE_JPEG_DEBUG_LOG )
    #define JPEG_PRINTF PRINTF
#else
    #define JPEG_PRINTF(fmt,...)
#endif

#ifdef __cplusplus
}
#endif

#endif /* JPEG_PRIV_H */
