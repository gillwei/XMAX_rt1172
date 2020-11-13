/*********************************************************************
* @file
* vi_key.c
*
* @brief
* Vehicle information module - process key events
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "event_groups.h"
#include "task.h"

#include "semphr.h"
#include "ewrte.h"
#include "fsl_debug_console.h"
#include "EW_pub.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define VEHICLE_KEY_LONG_PRESS_TIME_MS      ( 1000 )
#define VEHICLE_KEY_VALID_PRESS_NUM         ( 1 )    /**< valid number of key pressed at the same time */

/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/
typedef enum
    {
    KEY_DETECTION_STATE_VALID,   /**< valid key detection state: no key or only one key is pressed */
    KEY_DETECTION_STATE_INVALID  /**< invalid key detection state: more than one key are pressed */
    } vi_key_detection_state;

/*--------------------------------------------------------------------
                           PROJECT INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                               VARIABLES
--------------------------------------------------------------------*/
static int num_key_pressed = 0; /**< number of keys pressed at the same time */
static CoreKeyCode current_key_code = CoreKeyCodeNoKey;
static vi_key_detection_state key_detection_state = KEY_DETECTION_STATE_VALID;

static int long_press_counter = 0;
static int long_press_state   = 0;
static CoreKeyCode press_key_code   = CoreKeyCodeNoKey;
static CoreKeyCode release_key_code = CoreKeyCodeNoKey;

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
* @private
* send_key_press
*
* Send key press event to embedded wizard
*
* @param key_code The key code of CoreKeyCode type
*
*********************************************************************/
static void send_key_press
    (
    const CoreKeyCode key_code
    )
{
press_key_code = key_code;
}

/*********************************************************************
*
* @private
* send_key_release
*
* Send key release event to embedded wizard
*
* @param key_code The key code of CoreKeyCode type
*
*********************************************************************/
static void send_key_release
    (
    const CoreKeyCode key_code
    )
{
release_key_code = key_code;
}

/*********************************************************************
*
* @private
* enable_long_press_detection_state
*
* Enable key long press detection state
*
*********************************************************************/
static void enable_long_press_detection_state
    (
    void
    )
{
long_press_counter = 0;
long_press_state   = 1;
}

/*********************************************************************
*
* @private
* disable_long_press_detection_state
*
* Disable key long press detection state
*
*********************************************************************/
static void disable_long_press_detection_state
    (
    void
    )
{
long_press_counter = 0;
long_press_state   = 0;
}

/*********************************************************************
*
* @private
* vi_key_proc
*
* Send key press and release events to Embedded Wizard
*
*********************************************************************/
void vi_key_proc
    (
    void
    )
{
if( CoreKeyCodeNoKey != press_key_code )
    {
    current_key_code = press_key_code;
    press_key_code   = CoreKeyCodeNoKey;
    //EW_send_key_event( current_key_code, KEY_STATE_PRESS );
    }

if( CoreKeyCodeNoKey != release_key_code )
    {
    //EW_send_key_event( current_key_code, KEY_STATE_RELEASE );
    current_key_code = CoreKeyCodeNoKey;
    release_key_code = CoreKeyCodeNoKey;
    }

if( long_press_state )
    {
    long_press_counter++;
    if( 20 == long_press_counter )
        {
        if( CoreKeyCodeNoKey != current_key_code )
            {
            send_key_press( current_key_code );
            }
        disable_long_press_detection_state();
        }
    }
}

/*********************************************************************
*
* @private
* vi_key_status_changed
*
* Process key events
*
*********************************************************************/
void vi_key_status_changed
    (
    const CoreKeyCode key_code,
    const int         key_status
    )
{
if( key_status )
    {
    num_key_pressed++;
    }
else
    {
    num_key_pressed--;
    }

switch( key_detection_state )
    {
    case KEY_DETECTION_STATE_VALID:
        if( VEHICLE_KEY_VALID_PRESS_NUM >= num_key_pressed )
            {
            if( key_status )
                {
                send_key_press( key_code );
                enable_long_press_detection_state();
                }
            else
                {
                send_key_release( key_code );
                disable_long_press_detection_state();
                }
            }
        else
            {
            PRINTF( "Err: invalid key state\r\n" );
            key_detection_state = KEY_DETECTION_STATE_INVALID;
            disable_long_press_detection_state();
            }
        break;

    case KEY_DETECTION_STATE_INVALID:
        if( 0 == num_key_pressed )
            {
            //TODO: to clear state state in Embedded Wizard
            //EW_clear_key_state();
            key_detection_state = KEY_DETECTION_STATE_VALID;
            PRINTF( "valid key state\r\n" );
            }
        break;

    default:
        break;
    }
}

/*********************************************************************
*
* @private
* vi_key_init
*
* Initialize vehicle key timer
*
*********************************************************************/
void vi_key_init
    (
    void
    )
{
// empty body
}

