/*!*******************************************************************
* @file OTA_pub.h
* @brief ota header file
*
* This file represents the public interface for ota such as
* jumps to bootloader
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*!*******************************************************************
*
* @ingroup ota
* @{
*
*********************************************************************/
#ifndef OTA_PUB_H
#define OTA_PUB_H

#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                            GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "fsl_common.h"
/*--------------------------------------------------------------------
                            LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define OTA_ENTER_BOOTLOADER_BY_RESET 0
#define OTA_ENTER_BOOTLOADER_BY_JUMPING 1

#define OTA_ENTER_BOOTLOADER_METHOD OTA_ENTER_BOOTLOADER_BY_RESET

#define OTA_SYS_PARTITION_A           0x00
#define OTA_SYS_PARTITION_B           0x01
/*--------------------------------------------------------------------
                            TYPES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/
/*!*******************************************************************
*
* @public
* Jump to bootloader.
*
* Fill the software update request region and jump to bootloader
* with/without reset.
*
*********************************************************************/
void OTA_jump_to_bootloader
    (
    void
    );

/*!*******************************************************************
*
* @public
* Module init.
*
* Initilize the module variables and task.
*
*********************************************************************/
void OTA_init
    (
    void
    );

/*!*******************************************************************
*
* @public
* Set update packet.
*
* Store the update information before jumping to bootloader.
*
*********************************************************************/
void OTA_set_update_packet
    (
    const bool     enable,
    const uint16_t new_firmware_ver,
    const uint32_t total_size,
    const uint32_t number_of_packages
    );

/*!*******************************************************************
*
* @public
* Get current partition.
*
* Get the current partition that application is running.
* OTA_SYS_PARTITION_A:System runs in partition A
* OTA_SYS_PARTITION_B:System runs in partition B
*
*********************************************************************/
uint8_t OTA_get_sys_parition
    (
    void
    );
#endif /* OTA_PUB_H */

/*!*******************************************************************
*
* @}
*
*********************************************************************/