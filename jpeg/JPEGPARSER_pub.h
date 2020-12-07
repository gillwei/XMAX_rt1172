/*******************************************************************************
*@ File JPEGPARSER_pub.h
*@ Brief Jpeg Parser public header file
*
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
********************************************************************************/
#ifndef JPEGPARSER_PUB_H
#define JPEGPARSER_PUB_H

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "projdefs.h"
//#include "FreeRTOSConfig.h"
#include "fsl_common.h"

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

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/

void getUartJpegData
    (
    uint8_t* data,
    uint32_t data_size
    );

#ifdef __cplusplus
}
#endif


#endif /*JPEGPARSER_PUB_H */