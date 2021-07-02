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
@brief   Convert the Bluetooth profile connection status to string
@details Convert the Bluetooth profile connection status to string
@return  None
@retval  String of the Bluetooth profile connection status
================================================================================================*/
const char* BT_util_get_connection_status_string
    (
    const BT_connection_status_e connection_status
    )
{
switch( connection_status )
    {
    case BT_CONNECTION_DISCONNECTED:   return "Disconnected";
    case BT_CONNECTION_CONNECTING:     return "Connecting";
    case BT_CONNECTION_CONNECTED:      return "Connected";
    case BT_CONNECTION_DISCONNECTING:  return "Disconnecting";
    case BT_CONNECTION_STATUS_INVALID:
    default:                           return "Unknown";
    }
}

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

/*================================================================================================
@brief   Convert the SPP app type to string
@details Convert the SPP app type to string
@return  None
@retval  String of the SPP app type
================================================================================================*/
const char* BT_util_get_spp_app_type_string
    (
    const BT_spp_app_type_e app_type
    )
{
switch( app_type )
    {
    case BT_SPP_APP_NAVILITE:     return "Navilite";
    case BT_SPP_APP_MOTOCON:      return "Motocon";
    case BT_SPP_APP_TYPE_INVALID:
    default:                      return "Unknown";
    }
}

/*================================================================================================
@brief   Convert the SPP connection type to string
@details Convert the SPP connection type to string
@return  None
@retval  String of the SPP connection type
================================================================================================*/
const char* BT_util_get_spp_connection_type_string
    (
    const BT_spp_connection_type_e connection_type
    )
{
switch( connection_type )
    {
    case BT_SPP_CONNECTION_SPP:          return "SPP";
    case BT_SPP_CONNECTION_IAP:          return "iAP";
    case BT_SPP_CONNECTION_TYPE_INVALID:
    default:                             return "Unknown";
    }
}

#ifdef __cplusplus
}
#endif
