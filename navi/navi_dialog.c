/*********************************************************************
* @file
* navi_dialog.c
*
* @brief
* Navigation module - Handle dialog event
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "task.h"
#include "semphr.h"
#include "fsl_debug_console.h"
#include "EW_pub.h"
#include "NAVI_pub.h"
#include "navi_priv.h"
#include "NAVILITE_pub.h"
#include "error_code.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define DIALOG_TIME_DURATION_MS     ( 1000 )

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
static TimerHandle_t dialog_timer_handle;
static navi_dialog_type navi_dialog_obj;

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/
/*********************************************************************
*
* @public
* NAVI_get_navi_dialog_obj
*
* Get navi dialog object.
*
*********************************************************************/
navi_dialog_type* NAVI_get_navi_dialog_obj
    (
    void
    )
{
return &navi_dialog_obj;
}

/*********************************************************************
*
* @private
* navi_start_dialog_timer
*
* Start timer to update dialog time.
*
*********************************************************************/
static void navi_start_dialog_timer
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
BaseType_t result = xTimerStart( dialog_timer_handle, 0 );
configASSERT( result == pdPASS );
}

/*********************************************************************
*
* @private
* navi_stop_dialog_timer
*
* Stop timer to stop the update of dialog time.
*
*********************************************************************/
static void navi_stop_dialog_timer
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
BaseType_t result = xTimerStop( dialog_timer_handle, 0 );
configASSERT( result == pdPASS );
}

/*********************************************************************
*
* @private
* dialog_timer_callback
*
* A timer callback function which calls time update function.
*
* @param timer_handle The handle of dialog timer.
*
*********************************************************************/
static void dialog_timer_callback
    (
    TimerHandle_t timer_handle
    )
{
if( navi_dialog_obj.timeout > 0 )
    {
    navi_dialog_obj.timeout--;
    }
else
    {
    navi_stop_dialog_timer();
    }
}

/*********************************************************************
*
* @private
* navi_add_dialog
*
* Notify navigation module that the dialog event is updated.
*
* @param dialog_id      Dialog id.
* @param dialog_type    Type of dialog.
* @param message        Dialog message.
* @param message_size   Size of dialog message.
* @param timeout        Timeout.
* @param default_choice Default selected button.
*
*********************************************************************/
void navi_add_dialog
    (
    const uint8_t dialog_id,
    const navilite_dialog_type dialog_type,
    const char* message,
    const uint8_t message_size,
    const uint8_t timeout,
    const uint8_t default_choice
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );

navi_dialog_obj.dialog_id = dialog_id;
navi_dialog_obj.dialog_type = dialog_type;
strncpy( navi_dialog_obj.dialog_message, ( char* )message, MAX_DIALOG_DESCRIPTION_SIZE );
if( MAX_DIALOG_DESCRIPTION_SIZE > message_size )
    {
    navi_dialog_obj.dialog_message[message_size] = '\0';
    }
else
    {
    navi_dialog_obj.dialog_message[MAX_DIALOG_DESCRIPTION_SIZE-1] = '\0';
    }

navi_dialog_obj.timeout = timeout;
switch( default_choice )
    {
    case NAVILITE_BUTTON_OK:
        navi_dialog_obj.default_selected_button = EnumNaviButtonTypeOK;
        break;
    case NAVILITE_BUTTON_CANCEL:
        navi_dialog_obj.default_selected_button = EnumNaviButtonTypeCANCEL;
        break;
    case NAVILITE_BUTTON_YES:
        navi_dialog_obj.default_selected_button = EnumNaviButtonTypeYES;
        break;
    case NAVILITE_BUTTON_NO:
        navi_dialog_obj.default_selected_button = EnumNaviButtonTypeNO;
        break;
    default:
        PRINTF( "%s: Unknown button type\r\n", __FUNCTION__ );
        break;
    }
if( NAVILITE_DIALOGTYPE_YES_NO == dialog_type )
    {
    navi_start_dialog_timer();
    }
EW_notify_dialog_event_update();
}

/*********************************************************************
*
* @public
* NAVI_get_dialog_type
*
* Obtain navi dialog type.
*
*********************************************************************/
EnumNaviDialogType NAVI_get_dialog_type
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
EnumNaviDialogType navi_dialog_type = EnumNaviDialogTypeDIALOG_TOTAL;
switch( navi_dialog_obj.dialog_type )
    {
    case NAVILITE_DIALOGTYPE_OK:
        navi_dialog_type = EnumNaviDialogTypeDIALOG_OK;
        break;
    case NAVILITE_DIALOGTYPE_OK_CANCEL:
        navi_dialog_type = EnumNaviDialogTypeDIALOG_OK_CANCEL;
        break;
    case NAVILITE_DIALOGTYPE_YES_NO:
        navi_dialog_type = EnumNaviDialogTypeDIALOG_YES_NO;
        break;
    case NAVILITE_DIALOGTYPE_YES_NO_CANCEL:
        navi_dialog_type = EnumNaviDialogTypeDIALOG_YES_NO_CANCEL;
        break;
    case NAVILITE_DIALOGTYPE_DISMISS_DIALOG:
        navi_dialog_type = EnumNaviDialogTypeDIALOG_DISMISS;
        break;
    default:
        PRINTF( "%s: Unknown dialog type\r\n", __FUNCTION__ );
        break;
    }
return navi_dialog_type;
}

/*********************************************************************
*
* @public
* NAVI_get_dialog_message
*
* Obtain the content of dialog
*
*********************************************************************/
void NAVI_get_dialog_message
    (
    char** dialog_message
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
*dialog_message = navi_dialog_obj.dialog_message;
}

/*********************************************************************
*
* @public
* NAVI_send_selected_dialog
*
* Send selected dialog id and its button type
*
* @param button_type Type of button on the selected dialog.
*
*********************************************************************/
void NAVI_send_selected_dialog
    (
    EnumNaviButtonType button_type
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
switch( button_type )
    {
    case EnumNaviButtonTypeOK:
        NAVILITE_report_app_dialog_select( navi_dialog_obj.dialog_id, NAVILITE_BUTTON_OK );
        break;
    case EnumNaviButtonTypeCANCEL:
        NAVILITE_report_app_dialog_select( navi_dialog_obj.dialog_id, NAVILITE_BUTTON_CANCEL );
        break;
    case EnumNaviButtonTypeYES:
        NAVILITE_report_app_dialog_select( navi_dialog_obj.dialog_id, NAVILITE_BUTTON_YES );
        break;
    case EnumNaviButtonTypeNO:
        NAVILITE_report_app_dialog_select( navi_dialog_obj.dialog_id, NAVILITE_BUTTON_NO );
        break;
    default:
        PRINTF( "%s: Unknown button type\r\n", __FUNCTION__ );
        break;
    }
}

/*********************************************************************
*
* @public
* NAVI_reset_dialog_object
*
* Reset dialog object
*
*********************************************************************/
void NAVI_reset_dialog_object
    (
    void
    )
{
PRINTF( "%s\r\n", __FUNCTION__ );
navi_dialog_obj.dialog_id = 0;
navi_dialog_obj.dialog_type = NAVILITE_DIALOGTYPE_DISMISS_DIALOG;
memset( navi_dialog_obj.dialog_message, 0, MAX_DIALOG_DESCRIPTION_SIZE );
navi_dialog_obj.timeout = 0;
navi_dialog_obj.default_selected_button = EnumNaviButtonTypeTOTAL;
}

/*********************************************************************
*
* @private
* navi_dialog_init
*
* Initialize navi dialog
*
*********************************************************************/
void navi_dialog_init
    (
    void
    )
{
dialog_timer_handle = xTimerCreate( "dialog_timer", pdMS_TO_TICKS( DIALOG_TIME_DURATION_MS ), pdTRUE, ( void * ) 0, dialog_timer_callback );
configASSERT( NULL != dialog_timer_handle );
}


