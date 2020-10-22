/*********************************************************************
* @file
* RTC_pub.h
*
* @brief
* real time clock module - public API
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/
#ifndef RTC_PUB_H
#define RTC_PUB_H

#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "fsl_snvs_lp.h"

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
void RTC_init
    (
    void
    );

status_t RTC_set_DateTime
    (
    snvs_lp_srtc_datetime_t * datetime
    );

void RTC_get_DateTime
    (
    snvs_lp_srtc_datetime_t * datetime
    );

#ifdef __cplusplus
}
#endif

#endif /* RTC_PUB_H */

