/*********************************************************************
* @file  bt_utils.c
* @brief Bluetooth Manager Utility interface definition.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "bt_utils.h"

/*--------------------------------------------------------------------
                        Definitions
--------------------------------------------------------------------*/

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
                        PROTOTYPES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
/*================================================================================================
@brief   Convert the device type to string
@details Convert the device type to string
@return  None
@retval  String of the device type
================================================================================================*/
const char* BT_util_get_device_type_string
    (
    const BT_device_type_e device_type
    )
{
switch( device_type )
    {
    case BT_DEVICE_BREDR:        return "BREDR";
    case BT_DEVICE_LE:           return "LE";
    case BT_DEVICE_BREDR_LE:     return "BREDR + LE";
    case BT_DEVICE_TYPE_INVALID:
    default:                     return "Unknown";
    }
}

/*================================================================================================
@brief   Convert the hardware mode to string
@details Convert the hardware mode to string
@return  None
@retval  String of the hardware mode
================================================================================================*/
const char* BT_util_get_hw_mode_string
    (
    const BT_hw_mode_e hw_mode
    )
{
switch( hw_mode )
    {
    case BT_HW_MODE_NORMAL:   return "Normal";
    case BT_HW_MODE_DOWNLOAD: return "Download";
    case BT_HW_MODE_INVALID:
    default:                  return "Unknown";
    }
}

/*================================================================================================
@brief   Convert the pairing status to string
@details Convert the pairing status to string
@return  None
@retval  String of the pairing status
================================================================================================*/
const char* BT_util_get_pairing_status_string
    (
    const BT_pairing_status_e pairing_status
    )
{
switch( pairing_status )
    {
    case BT_PAIRING_NONE:              return "None";
    case BT_PAIRING_USER_CONFIRMING:   return "User Confirming";
    case BT_PAIRING_CONFIRMED_WAITING: return "Confirmed Waiting";
    case BT_PAIRING_STATUS_INVALID:
    default:                           return "Unknown";
    }
}

/*================================================================================================
@brief   Convert the power status to string
@details Convert the power status to string
@return  None
@retval  String of the power status
================================================================================================*/
const char* BT_util_get_power_status_string
    (
    const BT_power_status_e power_status
    )
{
switch( power_status )
    {
    case BT_POWER_OFF:            return "Off";
    case BT_POWER_ON:             return "On";
    case BT_POWER_ON_UPDATING:    return "On Updating";
    case BT_POWER_ON_READY:       return "On Ready";
    case BT_POWER_STATUS_INVALID:
    default:                      return "Unknown";
    }
}

#ifdef __cplusplus
}
#endif
