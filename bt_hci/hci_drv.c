/*********************************************************************
* @file
* @brief Garmin HCI Serial Protocol Driver
*
* This file includes the functions that implement the Garmin HCI
* protocol driver.
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*********************************************************************
*
* @defgroup hci_drv Garmin HCI Protocol Driver
* @ingroup mw_comps
* @{
*
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
update_timer_count = 1;
init_update_state = INIT_STATE_REQUEST_VERSION;
xTimerStart( xUpdateTimer, 0 );
create_task();
}

/*********************************************************************
*
* MCU hardware reset 89820
*
* Use MCU reset pin reset 89820
*
*********************************************************************/
void HCI_reset_BT
    (
    void
    )
{
//gpio_pin_config_t rst_new_config = {kGPIO_DigitalOutput, 1, kGPIO_NoIntmode};

// Reset 89820
//GPIO_PinInit(GPIO9, 7U, &rst_new_config);
GPIO_PinWrite( GPIO9, 7, 0 );
vTaskDelay( pdMS_TO_TICKS( 2 ) ); // delay 2 ms
GPIO_PinWrite( GPIO9, 7, 1 );
vTaskDelay( pdMS_TO_TICKS( 50 ) );
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
uint8_t        update_status;

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
            update_status = getBTUpdateStatus();

            // Process data, check if now is BT download ongoing
            if ( update_status != true )
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
void BT_update_received
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
    BT_update_received();
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
* @}
*
*********************************************************************/
