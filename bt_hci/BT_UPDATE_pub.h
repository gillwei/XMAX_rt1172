/*******************************************************************************
*@ File BT_UPDATE_pub.h
*@ Brief BT update public header file
*
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
********************************************************************************/
#ifndef BT_UPDATE_PUB_H
#define BT_UPDATE_PUB_H

#include "fsl_common.h"

#define BT_UPDATE_ON false
/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/
bool getBTUpdateStatus
    (
    void
    );

void parseUpdatePkt
    (
    uint8_t* l_hci_buffer,
    uint32_t length
    );

void bt_update_init
    (
    void
    );

#endif /* BT_UPDATE_pub.H_ */
