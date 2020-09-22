/*********************************************************************
* @file
* @brief Garmin HCI Serial Protocol Driver
*
* This file includes the functions that implement the Garmin HCI
* protocol driver.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                          GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <BT_UPDATE_pub.h>
#include <HCI_pub.h>
#include "hci_prv.h"
#include "JPEGPARSER_pub.h"
#include "fsl_debug_console.h"
#include "circular_buffer.h"
#include "event_groups.h"
#include "hci_control_api.h"
#include "PERIPHERAL_pub.h"
#include "fsl_gpio.h"
#include "BTM_pub.h"
#include "GRM_pub_prj.h"
#include "pin_mux.h"
#include "factory_test.h"

/*--------------------------------------------------------------------
                           LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define HCI_MAX_DATA_SIZE    240
#define HCI_TX_QUEUE_ENABLE  FALSE
#define HCI_HEADER_LENGTH    5
/*------------------------------------------------------
HCI Receive Error Flags
------------------------------------------------------*/
#define HCI_FLAG_LENGTH_ERROR       (0x1 << 2)
#define HCI_FLAG_OPCODE_ERROR       (0x1 << 1)
#define HCI_FLAG_INIT_ERROR         (0x1 << 0)

/*------------------------------------------------------
HCI Task Parameters
------------------------------------------------------*/
#define HCI_TASK_PRIORITY    ( TASK_PRIO_BT_HCI )
#define HCI_TASK_STACK_SIZE ( configMINIMAL_STACK_SIZE * 4 )
#define HCI_TASK_NAME       "hci_task"

#define EVENT_HCI_DATA_RECEIVED       ( 1 << 0 )
#if HCI_TX_QUEUE_ENABLE
    #define EVENT_HCI_DATA_TX             ( 1 << 1 )
#endif
#define EVENT_BT_UPDATE_RECEIVED      ( 1 << 2 )

#define HCI_RX_BUFFER_SIZE  ( 32 * 1024 )
AT_NONCACHEABLE_SECTION(uint8_t hci_rx_data[HCI_RX_BUFFER_SIZE]);

#if HCI_TX_QUEUE_ENABLE
#define HCI_TX_BUFFER_SIZE  ( 1024 )
AT_BOARDSDRAM_SECTION( uint8_t hci_tx_data[HCI_TX_BUFFER_SIZE] );
#endif

#define UPDATE_TIMER_PERIOD_MS       50
#define UPDATE_TICK_PERIOD_MS        pdMS_TO_TICKS( UPDATE_TIMER_PERIOD_MS )
#define UPDATE_TIMER_TWO_SECONDS     ( 2000 / UPDATE_TIMER_PERIOD_MS )
#define UPDATE_TIMER_THREE_SECONDS   ( 3000 / UPDATE_TIMER_PERIOD_MS )

#define RESPONSE_TIMER_PERIOD_MS     50
#define RESPONSE_TICK_PERIOD_MS      pdMS_TO_TICKS( RESPONSE_TIMER_PERIOD_MS )
#define RESPONSE_TIMER_TWO_SECONDS   ( 2000 / RESPONSE_TICK_PERIOD_MS )
#define AUTH_CHIP_RESULT_FAIL        0

/*--------------------------------------------------------------------
                                TYPES
--------------------------------------------------------------------*/
/*------------------------------------------------------
HCI Packet Reception Callback Function Pointers

This is the type definition for the HCI callback function
pointer that defines the callback issued when the IOP
driver successfully parses a valid HCI packet from the
received HCI byte stream.
------------------------------------------------------*/
typedef void (* p_hci_rx_pkt_hook_t )
    (
    uint8_t*   p_buffer,
    uint32_t   size
    ) ;

/**-----------------------------------------------------
 HCI States for Parsing Received Data
------------------------------------------------------*/
typedef enum tagHCI_STATE_TYPE                  //!< HCI receive state machine states
    {
    HCI_STATE_INIT,
    HCI_STATE_OPCODE_LAST_BYTE,
    HCI_STATE_OPCODE_FIRST_BYTE,
    HCI_STATE_LENGTH_LAST_BYTE,
    HCI_STATE_LENGTH_FIRST_BYTE,
    HCI_STATE_BUFFER
    } hci_state_t;

/**-----------------------------------------------------
 HCI packet storage data structure used to assemble
 valid parsed HCI packets as encoded HCI message bytes
 are removed from the UART receive queue.
------------------------------------------------------*/
typedef struct tagHCI_PKT_STORE_TYPE            //!< HCI receive packet data store
    {
    uint16_t       opcode;                         //!< HCI packet ID
    uint16_t       length;                         //!< data payload size
    uint16_t       count;                          //!< received byte count
    uint8_t        data[HCI_MAX_DATA_SIZE];        //!< extracted payload data
    } hci_pkt_store_t;

/**-----------------------------------------------------
 HCI Status data structure used to keep track of the
 status of an HCI channel. This includes the receive
 state machine that parses incoming packets, packet
 storage as a received packet is being assembled,
 and error flags.
------------------------------------------------------*/
typedef struct tagHCI_STATUS_TYPE               //!< HCI channel status structure
    {
    hci_state_t             state;              //!< receive state machine state
    hci_pkt_store_t         pkt_store;          //!< receive packet assembly data store
    p_hci_rx_pkt_hook_t     p_rx_pkt_callback;  //!< client receive packet callback
    uint8_t                 flags;              //!< error flags
    } hci_status_t;

typedef enum
    {
    IOP_COMMAND_STATE_IDLE,
    IOP_COMMAND_STATE_WAIT_FOR_RESPONSE
    } IOP_command_state_struct;

typedef enum
    {
    LE_TRANSMIT_LOW_CH,
    LE_TRANSMIT_MID_CH,
    LE_TRANSMIT_HI_CH,
    LE_TRANSMIT_END
    } LE_transmit_channel;


/*--------------------------------------------------------------------
                            VARIABLES
--------------------------------------------------------------------*/
static hci_status_t           hci_status;
#if HCI_TX_QUEUE_ENABLE
static circular_buf_handle    tx_buffer_handle;
#endif
static circular_buf_handle    rx_buffer_handle;
static EventGroupHandle_t     event_group = NULL;
static uint16_t               tx_command_opcode;
static init_update_state_t    init_update_state;
static TimerHandle_t          xUpdateTimer = NULL;
static uint16_t               update_timer_count;
static bool                   LE_transmit_cmd_called = false;
static TimerHandle_t          xRespTimer = NULL;
static IOP_command_state_struct  iop_command_state;
static uint16_t               resp_timer_count;
static const uint8_t          allow_connection_const_data[3] = { 0x02, 0x00, 0x02 };
static const uint8_t          le_low_ch_cmd_data[3] = { 0x00, 0x37, 0x04 };
static const uint8_t          le_mid_ch_cmd_data[3] = { 0x13, 0x37, 0x04 };
static const uint8_t          le_hi_ch_cmd_data[3] = { 0x27, 0x37, 0x04 };

/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/
static bool parse_hci_receive_packet
    (
    uint8_t    const**   const pp_hci_buffer,
    uint32_t*            const p_nbytes
    );

static void task_main
    (
    void* arg
    );

static void create_task
    (
    void
    );

static void GetUartHciData
    (
    uint8_t* data,
    uint32_t data_size
    );

static void UpdateTimerCallback
    (
    TimerHandle_t xTimer
    );

static void RespTimerCallback
    (
    TimerHandle_t xTimer
    );

/*********************************************************************
*
* @public
* initialize HCI
*
* This function initializes all of the HCI variables
*
*********************************************************************/
void HCI_init
    (
    void
    )
{
rx_buffer_handle = circular_buffer_init( "HCI task_rx", hci_rx_data, HCI_RX_BUFFER_SIZE );
#if HCI_TX_QUEUE_ENABLE
    tx_buffer_handle = circular_buffer_init( "HCI task_tx", hci_tx_data, HCI_TX_BUFFER_SIZE );
#endif
tx_command_opcode = 0;

memset( &hci_status, 0, sizeof( hci_status_t ) );

xUpdateTimer = xTimerCreate( "UpdateTimer",           /* A text name, purely to help debugging. */
                             UPDATE_TICK_PERIOD_MS,   /* The timer period, in this case 5000ms (5s). */
                             pdTRUE,                  /* This is a one shot timer, so xAutoReload is set to pdFALSE. */
                             ( void * ) 0,            /* The ID is not used, so can be set to anything. */
                             UpdateTimerCallback      /* The callback function */
                           );

xRespTimer = xTimerCreate( "WaitResponseTimer",           /* A text name, purely to help debugging. */
                           RESPONSE_TICK_PERIOD_MS,   /* The timer period, in this case 5000ms (5s). */
                           pdTRUE,                  /* This is a one shot timer, so xAutoReload is set to pdFALSE. */
                           ( void * ) 0,            /* The ID is not used, so can be set to anything. */
                           RespTimerCallback      /* The callback function */
                         );

update_timer_count = 1;
resp_timer_count   = 0;
init_update_state = INIT_STATE_REQUEST_VERSION;
iop_command_state = IOP_COMMAND_STATE_IDLE;
xTimerStart( xUpdateTimer, 0 );
create_task();
}

/*********************************************************************
*
* MCU hardware reset 89820
*
* Pull MCU BT_RST_N pin low and high to reset 89820
*
*********************************************************************/
void HCI_reset_BT
    (
    void
    )
{
GPIO_PinWrite( BOARD_INITPINS_BT_RST_N_PERIPHERAL, BOARD_INITPINS_BT_RST_N_CHANNEL, 0 );
vTaskDelay( pdMS_TO_TICKS( BT_RESET_GPIO_DELAY ) );
GPIO_PinWrite( BOARD_INITPINS_BT_RST_N_PERIPHERAL, BOARD_INITPINS_BT_RST_N_CHANNEL, 1 );
vTaskDelay( pdMS_TO_TICKS( BT_RESET_RECONFIG_DELAY ) );
}

/*********************************************************************
*
* BT power off
*
* Pull MCU BT_RST_N pin low
*
*********************************************************************/
void HCI_BT_off
    (
    void
    )
{
GPIO_PinWrite( GPIO9, 7, 0 );
}

/*********************************************************************
*
* BT power on
*
* Pull MCU BT_RST_N pin high and send dummy message to UART for wake up
* 89820 chip
*
*********************************************************************/
void HCI_BT_on
    (
    void
    )
{
BaseType_t result;
uint8_t dummy_data_for_wakeup[2] = { 0, 0 };
GPIO_PinWrite( BOARD_INITPINS_BT_RST_N_PERIPHERAL, BOARD_INITPINS_BT_RST_N_CHANNEL, 1 );
vTaskDelay( pdMS_TO_TICKS( COMMON_CMD_WAIT_MS ) );
result = HCI_wiced_send_command( HCI_CONTROL_COMMAND_SET_VISIBILITY, &(dummy_data_for_wakeup[0]), sizeof( dummy_data_for_wakeup ) );
PRINTF( "%s:%d\n\r", __FUNCTION__, result );
}


/*********************************************************************
*
* Set BT chip into test mode
*
* Send three standard HCI commands and set BT chip into test mode
*
*********************************************************************/
void HCI_set_test_mode
    (
    void
    )
{
// Set parser to standard HCI for retreive DUT command response
BT_UPDATE_setParserStatus( PARSER_STANDARD_HCI );

BT_UPDATE_standard_send_command( OPCODE_RESET, NULL, 0 );
vTaskDelay( pdMS_TO_TICKS( COMMON_CMD_WAIT_MS ) );
BT_UPDATE_standard_send_command( OPCODE_ALLOW_CONNECTION, allow_connection_const_data, sizeof( allow_connection_const_data ) );
}

/*********************************************************************
*
* Get BT chip into test mode
*
* If Set DUT mode command receive correct response, return get DUT
* mode true
*
*********************************************************************/
bool HCI_get_test_mode_state
    (
    void
    )
{
bool test_mode_state = getBTDUTModeState();
return test_mode_state;
}

/*********************************************************************
*
* HCI LE transmit
*
* Send LE continuous transmit command
*
*********************************************************************/
void HCI_LE_transmit_cmd
    (
    uint8_t* data
    )
{

if( false == LE_transmit_cmd_called )
    {
    PRINTF( "%s cmd RECEIVED\n\r", __FUNCTION__ );
    LE_transmit_cmd_called = true;
    HCI_BT_off();
    HCI_BT_on();
    vTaskDelay( pdMS_TO_TICKS( RESET_WAIT_MS ) );
    BT_UPDATE_standard_send_command( OPCODE_RESET, NULL, 0 );
    vTaskDelay( pdMS_TO_TICKS( COMMON_CMD_WAIT_MS ) );
    }

if( LE_TRANSMIT_LOW_CH == *data )
    {
    BT_UPDATE_standard_send_command( OPCODE_LE_TX, le_low_ch_cmd_data, sizeof( le_low_ch_cmd_data ) );
    }
else if( LE_TRANSMIT_MID_CH == *data )
    {
    BT_UPDATE_standard_send_command( OPCODE_LE_TX, le_mid_ch_cmd_data, sizeof( le_mid_ch_cmd_data ) );
    }
else if( LE_TRANSMIT_HI_CH == *data )
    {
    BT_UPDATE_standard_send_command( OPCODE_LE_TX, le_hi_ch_cmd_data, sizeof( le_hi_ch_cmd_data ) );
    }
else if( LE_TRANSMIT_END == *data )
    {
    BT_UPDATE_standard_send_command( OPCODE_LE_END, NULL, 0 );
    vTaskDelay( pdMS_TO_TICKS( COMMON_CMD_WAIT_MS ) );
    HCI_BT_off();
    HCI_BT_on();
    vTaskDelay( pdMS_TO_TICKS( RESET_WAIT_MS ) );
    LE_transmit_cmd_called = false;
    PRINTF( "%s cmd TEST END\n\r", __FUNCTION__ );
    }

}

/*********************************************************************
*
* Get BT update status
*
* For outside function retrieve BT update status(true or false)
*
*********************************************************************/
init_update_state_t getBTInitUpdateState
    (
    void
    )
{
return init_update_state;
}

/*********************************************************************
*
* Set BT update status
*
* For outside function set BT update status(true or false)
*
*********************************************************************/
void setBTInitUpdateState
    (
    init_update_state_t newInitUpdateState
    )
{
init_update_state = newInitUpdateState;
}

/*********************************************************************
*
* @public
* transmit an HCI message
*
* This function formulates an HCI message based on the packet ID and
* data.
*
* @return boolean
* error flag (true or false)
*
*********************************************************************/
BaseType_t HCI_wiced_send_command
    (
    const uint16_t command,
    const uint8_t* payload,
    const uint16_t len
    )
{
uint8_t     data[HCI_HEADER_LENGTH + HCI_MAX_DATA_SIZE];
uint16_t    totalLength = 0;
uint16_t    header  = 0;

memset( data, 0, sizeof( data ) );

// If command header byte is not set, return
if( command )
    {
    data[header++] = HCI_WICED_PKT;
    data[header++] = command & 0xff;
    data[header++] = (command >> 8) & 0xff;
    data[header++] = len & 0xff;
    data[header++] = (len >> 8) & 0xff;
    }
else
    {
    return false;
    }

if( len > 0 && HCI_MAX_DATA_SIZE >= len  )
    {
    memcpy( &data[header], payload, len );
    totalLength = header + len;
    }
else if( 0 == len )
    {
    totalLength = header;
    }
else
    {
    memcpy( &data[header], payload, HCI_MAX_DATA_SIZE );
    totalLength = header + HCI_MAX_DATA_SIZE;
    }

if( 0 == totalLength )
    return false;

return PERIPHERAL_uart_tx_data( totalLength, data );
}

/*********************************************************************
*
* parse received HCI packet bytes
*
* This function parses the bytes retrieved from an HCI UART's
* software receive queue into valid HCI packets. A state machine
* sequences the received bytes in the expected order for a valid HCI
* message. If the sequence gets out of order the state machine reverts
* to waiting for the next HCI_WICED_PKT of a new message.
*
* @return bool
* valid packet flag (true or false)
*
*********************************************************************/
static bool parse_hci_receive_packet
    (
    uint8_t    const**   const pp_hci_buffer,    //!< [in] pointer to pointer to input HCI byte buffer
    uint32_t*            const p_nbytes         //!< [in] pointer to number of bytes in the HCI receive buffer
    )
{
bool                    l_valid_pkt;
uint8_t         const*  l_p_hci_buffer;
hci_pkt_store_t*        l_pkt_store;
uint8_t                 l_byte_value;

/*------------------------------------------------------
Initialize pointers and process the next received
character based on the current HCI receive state. Note
that l_p_hci_buffer is a local copy of a pointer to
the HCI data buffer and so the passed in pointer
contents need to be updated before returning.
------------------------------------------------------*/
l_valid_pkt    = false;
l_p_hci_buffer = *( pp_hci_buffer );
l_pkt_store    = &( hci_status.pkt_store );

while( ( false == l_valid_pkt ) && ( *( p_nbytes ) > 0) )
    {
    /*------------------------------------------------------
    Get the current byte value
    ------------------------------------------------------*/
    l_byte_value = *( l_p_hci_buffer );

    switch( hci_status.state )
        {
        case HCI_STATE_INIT:
            if( HCI_WICED_PKT == l_byte_value )
                {
                /*------------------------------------------------------
                Initial DLE received, reset the packet store, update the
                character pointer and wait for the ID byte next
                ------------------------------------------------------*/
                l_pkt_store->opcode  =  0;
                l_pkt_store->length  =  0;
                l_pkt_store->count   =  0;
                hci_status.state     =  HCI_STATE_OPCODE_LAST_BYTE;
                }
            else
                {
                /*------------------------------------------------------
                Flag an error and keep waiting for the starting DLE
                ------------------------------------------------------*/
                hci_status.flags |= HCI_FLAG_INIT_ERROR;
                }
            break;

        case HCI_STATE_OPCODE_LAST_BYTE:
            /*------------------------------------------------------
            Store the ID, initialize the checksum, update the
            character pointer and wait for the SIZE byte
            ------------------------------------------------------*/
            l_pkt_store->opcode  =  0;
            l_pkt_store->opcode  |= ( (uint16_t)l_byte_value & 0xff );
            hci_status.state      = HCI_STATE_OPCODE_FIRST_BYTE;
            break;

        case HCI_STATE_OPCODE_FIRST_BYTE:
            /*------------------------------------------------------
            Store the ID, initialize the checksum, update the
            character pointer and wait for the SIZE byte
            ------------------------------------------------------*/
            l_pkt_store->opcode  |= ( (uint16_t)l_byte_value << 8 );
            hci_status.state      = HCI_STATE_LENGTH_LAST_BYTE;
            break;

        case HCI_STATE_LENGTH_LAST_BYTE:
            /*------------------------------------------------------
            Valid SIZE so save it, update the checksum and the
            character pointer and wait for the next data byte
            ------------------------------------------------------*/
            l_pkt_store->length  = 0;
            l_pkt_store->length  |= ( (uint16_t)l_byte_value & 0xff );
            hci_status.state      = HCI_STATE_LENGTH_FIRST_BYTE;
            break;

        case HCI_STATE_LENGTH_FIRST_BYTE:
            /*------------------------------------------------------
            Valid SIZE so save it, update the checksum and the
            character pointer and wait for the next data byte
            ------------------------------------------------------*/
            l_pkt_store->length  |= ( (uint16_t)l_byte_value << 8 );
            if( ( l_pkt_store->length <= HCI_MAX_DATA_SIZE ) && ( l_pkt_store->length != 0 ) )
                {
                hci_status.state      = HCI_STATE_BUFFER;
                }
            else
                {
                hci_status.state      = HCI_STATE_INIT;
                }
            break;

        case HCI_STATE_BUFFER:
            /*------------------------------------------------------
            Store the data, update the data count, the checksum and
            the character pointer
            ------------------------------------------------------*/
            l_pkt_store->data[l_pkt_store->count] = l_byte_value;
            l_pkt_store->count  += 1;

            /*------------------------------------------------------
            Check the count against the size to determine if this is
            the last payload byte
            ------------------------------------------------------*/
            if( l_pkt_store->count >= l_pkt_store->length )
                {
                l_valid_pkt = true;
                hci_status.state = HCI_STATE_INIT;
                }
            break;

        default:
            break;
        }

    /*------------------------------------------------------
    Decrement the number of bytes processed and advance the
    buffer pointer
    ------------------------------------------------------*/
    if( *( p_nbytes ) > 0 )
        {
        *( p_nbytes )  -= 1;
        l_p_hci_buffer += 1;
        }
    }

/*------------------------------------------------------
Update the returned HCI buffer pointer
------------------------------------------------------*/
*( pp_hci_buffer ) = l_p_hci_buffer;
return l_valid_pkt;
}

/*********************************************************************
*
* process UART receive bytes
*
* This function retrieves received bytes from the UART software
* receive queue and processes them to continue parsing valid HCI
* messages.
*
*********************************************************************/
static void GetUartHciData
    (
    uint8_t* l_hci_buffer,
    uint32_t length
    )
{
uint32_t           l_num_bytes = length;
uint8_t*           l_p_hci_buffer;
bool               l_valid_pkt = false;
uint8_t  const**   l_pp_hci_buffer;
hci_pkt_store_t*   l_p_pkt_store;

l_p_hci_buffer  = &( l_hci_buffer[0] );
l_pp_hci_buffer = (uint8_t const**) &( l_p_hci_buffer );

while( l_num_bytes > 0 )
    {
    l_valid_pkt = parse_hci_receive_packet( l_pp_hci_buffer, &( l_num_bytes ) );
    /*-------------------------------------------------------
    Pass the valid HCI packet back for processing
    -------------------------------------------------------*/
    if( true == l_valid_pkt )
        {
        l_p_pkt_store = &( hci_status.pkt_store );

        switch( ( l_p_pkt_store->opcode >> 8 ) & 0xff )
            {
            case HCI_CONTROL_GROUP_DEVICE:
                hci_device_event_handler( l_p_pkt_store->opcode,
                                          &( l_p_pkt_store->data[0] ),
                                          (uint32_t)l_p_pkt_store->length
                                          );
                break;

            case HCI_CONTROL_GROUP_LE:
                break;

            case HCI_CONTROL_GROUP_IAP2:
                hci_iap2_event_handler( l_p_pkt_store->opcode,
                                       &( l_p_pkt_store->data[0] ),
                                       (uint32_t)l_p_pkt_store->length
                                       );
                break;

            case HCI_CONTROL_GROUP_SPP:
                hci_spp_event_handler( l_p_pkt_store->opcode,
                                       &( l_p_pkt_store->data[0] ),
                                       (uint32_t)l_p_pkt_store->length
                                       );
                break;

            case HCI_CONTROL_GROUP_MISC:
                hci_misc_event_handler( l_p_pkt_store->opcode, &( l_p_pkt_store->data[0] ), length );
                break;

            case HCI_CONTROL_GROUP_AVRC_CONTROLLER:
                hci_avrc_event_handler( l_p_pkt_store->opcode, l_p_pkt_store->length, &l_p_pkt_store->data[0] );
                break;

            default:
                PRINTF( "hci_iap2_spp_proc_rx_cmd:unknown code:%04x len:%d\n\r", l_p_pkt_store->opcode, length );
                break;
            }

        l_valid_pkt = false;
        }
    }
}

/*********************************************************************
*
* HCI Task main
*
* Process HCI Task event, including the HCI packet parsing and BT
* update parsing, HCI Tx queue reserved for future.
*
*********************************************************************/

static void task_main
    (
    void* arg
    )
{
EventBits_t    event_bits;
bt_parser_t    task_parser_status;

while( true )
    {
    event_bits = xEventGroupWaitBits
                    (
                    event_group,    /* The event group handle. */
#if HCI_TX_QUEUE_ENABLE
                    EVENT_HCI_DATA_RECEIVED | EVENT_HCI_DATA_TX,
#else
                    EVENT_HCI_DATA_RECEIVED | EVENT_BT_UPDATE_RECEIVED,
#endif
                    pdTRUE,         /* clear on exit */
                    pdFALSE,        /* Don't wait for both bits, either bit unblock task. */
                    portMAX_DELAY   /* Block indefinitely to wait for the condition to be met. */
                    );

    if( EVENT_HCI_DATA_RECEIVED == ( event_bits & EVENT_HCI_DATA_RECEIVED ) )
        {
        while( circular_buffer_get_data_size( &rx_buffer_handle ) > 0 )
            {
            uint8_t*  data = NULL;
            uint32_t  size = 0;
            // Get data from circular buffer
            circular_buffer_get_head( &rx_buffer_handle, &data, &size );
            task_parser_status = getBTParserStatus();

            // Process data, check if now is HCI standard packet mode
            if( task_parser_status != PARSER_STANDARD_HCI )
                {
                GetUartHciData( data, size );
                }
            else
                {
                parseUpdatePkt( data, size );
                }
            // Move the data head after process
            circular_buffer_move_head( &rx_buffer_handle, size );
            }
        }

    #if HCI_TX_QUEUE_ENABLE
        if( EVENT_HCI_DATA_TX == ( event_bits & EVENT_HCI_DATA_TX ) )
            {
            while( circular_buffer_get_data_size( &tx_buffer_handle ) > 0 )
                {
                uint8_t*  data = NULL;
                uint32_t  size = 0;
                // Get data from circular buffer
                circular_buffer_get_head( &tx_buffer_handle, &data, &size );

                // Process data
                HCI_wiced_send_command( tx_command_opcode, data, size );

                // Move the data head after process
                circular_buffer_move_head( &tx_buffer_handle, size );
                }
            }
    #endif


    if( EVENT_BT_UPDATE_RECEIVED == ( event_bits & EVENT_BT_UPDATE_RECEIVED ) )
        {
        #if BT_UPDATE_ON
            bt_update_init();
        #else
            PRINTF("No BT update since flag off\n\r");
        #endif
        }
    }

vTaskDelete( NULL );
}

/*********************************************************************
*
* Notify HCI task have receive event
*
* Write UART data to circular buffer
*
*********************************************************************/
void HCI_notify_received
    (
    uint8_t* data,
    uint32_t size
    )
{
circular_buffer_write( &rx_buffer_handle, data, size );
xEventGroupSetBits( event_group, EVENT_HCI_DATA_RECEIVED );
}

/*********************************************************************
*
* Notify BT Update have receive event
*
* Initialize BT update work
*
*********************************************************************/
void BT_UPDATE_received
    (
    void
    )
{
xEventGroupSetBits( event_group, EVENT_BT_UPDATE_RECEIVED );
}

#if HCI_TX_QUEUE_ENABLE
/*********************************************************************
*
* Notify HCI task have receive event
*
* Write UART data to circular buffer
*
*********************************************************************/
void HCI_notify_transmit
    (
    uint16_t tx_command_type,
    uint8_t* data,
    uint32_t size
    )
{
tx_command_opcode = tx_command_type;
circular_buffer_write( &tx_buffer_handle, data, size );
xEventGroupSetBits( event_group, EVENT_HCI_DATA_TX );
}
#endif

/*********************************************************************
*
* Update timer callback
*
* This timer use to wait for the SW version request response
*
*********************************************************************/
static void UpdateTimerCallback
    (
    TimerHandle_t xTimerHandle
    )
{
uint8_t    sw_version[6] = { 0x19, 0x03, 0xFF, 0x01, 0x00, 0x01 };

// After boot 2 seconds, request SW version
if( ( UPDATE_TIMER_TWO_SECONDS == update_timer_count ) && ( INIT_STATE_REQUEST_VERSION == init_update_state ) )
    {
    // send request garmin sw version command
    PRINTF( "Request BT SW version...\n\r" );
    PERIPHERAL_uart_tx_data( sizeof( sw_version ), sw_version );
    }

// After boot 3 seconds, check whether SW version is received or not
if( ( UPDATE_TIMER_THREE_SECONDS == update_timer_count ) && ( INIT_STATE_REQUEST_VERSION == init_update_state ) )
    {
    PRINTF( "No version feedback. Do BT update.\n\r" );
    BT_UPDATE_received();
    xTimerStop( xTimerHandle, 0 );
    }
else if( ( UPDATE_TIMER_THREE_SECONDS == update_timer_count ) && ( INIT_STATE_GET_VERSION == init_update_state ) )
    {
    xTimerStop( xTimerHandle, 0 );
    }

if( update_timer_count >= 1 )
    {
    update_timer_count++;
    }
}

/*********************************************************************
*
* Response timer callback
*
* This timer use to wait for response of BT chip
*
*********************************************************************/
static void RespTimerCallback
    (
    TimerHandle_t xTimerHandle
    )
{
// Wait for response timeout, means no receive chip version and timer not stop, return fail
if( resp_timer_count >= RESPONSE_TIMER_TWO_SECONDS )
    {
    hci_wait_for_resp_stop();
    receive_auth_chip_ver( AUTH_CHIP_RESULT_FAIL );
    }

resp_timer_count++;
}

/*********************************************************************
*
* Create HCI task and event group
*
*********************************************************************/
static void create_task
    (
    void
    )
{
event_group = xEventGroupCreate();
BaseType_t result = xTaskCreate( task_main, HCI_TASK_NAME, HCI_TASK_STACK_SIZE, NULL, HCI_TASK_PRIORITY, NULL );

configASSERT( pdPASS == result );
}

/*********************************************************************
*
* @public
* HCI_wait_for_resp_start
*
*
*********************************************************************/
void HCI_wait_for_resp_start
    (
    void
    )
{
xTimerStart( xRespTimer, 0 );
}

/*********************************************************************
*
* @private
* hci_wait_for_resp_stop
*
*
*********************************************************************/
void hci_wait_for_resp_stop
    (
    void
    )
{
xTimerStop( xRespTimer, 0 );
resp_timer_count = 0;
}


/*********************************************************************
*
* @}
*
*********************************************************************/
