/*********************************************************************
* @file  bt_update.c
* @brief Garmin Update Cypress CYW89820 by HCI UART
*
* This file includes the functions that update CYW89820 by MCU through
* HCI UART
*
* Copyright 2020 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

/*--------------------------------------------------------------------
                          GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <BT_UPDATE_pub.h>
#include "projdefs.h"
#include "FreeRTOS.h"
#include "task.h"
#include "fsl_gpio.h"
#include "fsl_iomuxc.h"
#include "PERIPHERAL_pub.h"
#include "fsl_debug_console.h"
#include "hci_prv.h"
#include "HCI_pub.h"
#include "Enum.h"
#include "EW_pub.h"
#include "stdio.h"
#include "display_support.h"
#include "BTM_pub.h"

#define INIT_BYTE_1                0x04
#define INIT_BYTE_2                0x0E
#define MAX_UPDATE_DATA_LENGTH     240
#define READRAM_CMD_LENGTH         9
#define LAUNCH_CMD_LENGTH          8
#define OPCODE_READRAM             0x4D
#define OPCODE_LAUNCH              0x4E
#define OPCODE_RESET               0x03
#define OPCODE_ERASE               0xCE
#define BT_MINIDRIVER_ADDR         0x270400
#define BT_FLASH_ADDR              0x501400
extern uint32_t __base_BOARD_FLASH_BTFW;
#define FLASH_BT_FW_BASE_ADDR      ( ( uint32_t )( &__base_BOARD_FLASH_BTFW ) )
#define MCU_MINIDRIVER_ADDR        ( FLASH_BT_FW_BASE_ADDR + 0x00000100 )
#define MCU_BTFLASH_ADDR           ( FLASH_BT_FW_BASE_ADDR + 0x00010000 )
#define MCU_MINIDRIVER_END_ADDR    ( FLASH_BT_FW_BASE_ADDR + 0x00003ac0 )
#define MINIDRIVER_LAST_VAL        0x00273001

/*--------------------------------------------------------------------
                                TYPES
--------------------------------------------------------------------*/
/**-----------------------------------------------------
 HCI States for Parsing Received Data
------------------------------------------------------*/
typedef enum tagUPDATE_STATE_TYPE       //!< HCI receive state machine states
    {
    UPDATE_STATE_SUSPEND,
    UPDATE_STATE_INIT,
    UPDATE_STATE_DOWNLOAD_MINIDRIVER,
    UPDATE_STATE_VERIFY_MINIDRIVER,
    UPDATE_STATE_LAUNCH_MINIDRIVER,
    UPDATE_STATE_ERASE_BT_CHIP,
    UPDATE_STATE_DOWNLOAD_FLASH,
    UPDATE_STATE_VERIFY_FLASH,
    UPDATE_STATE_LAUNCH_FLASH,
    UPDATE_STATE_DOWNLOAD_FINISH,
    } update_state_t;

typedef struct
    {
    uint32_t flash_end_addr;      /**< buffer data  end address on MCU */
    uint32_t write_addr;          /**< prepare to write to BT address */
    uint32_t verify_addr;         /**< buffer verify address */
    uint32_t buffer_size;         /**< buffer allocation size */
    uint8_t* addr;                /**< pointer to buffer */
    } fw_buf_info;

typedef struct tagUPDATE_PKT_STORE_TYPE           //!< HCI receive packet data store
    {
    uint8_t       opcode;                         //!< HCI packet ID
    uint8_t       length;                         //!< data payload size
    uint8_t       count;                          //!< received byte count
    uint8_t       data[MAX_UPDATE_DATA_LENGTH];        //!< extracted payload data
    } update_pkt_store_t;

typedef enum tagPARSE_STATE_TYPE                  //!< HCI receive state machine states
    {
    PARSE_STATE_INIT_1,
    PARSE_STATE_INIT_2,
    PARSE_STATE_LENGTH,
    PARSE_STATE_VERIFY_1,
    PARSE_STATE_OPCODE,
    PARSE_STATE_VERIFY_3,
    PARSE_STATE_VERIFY_4,
    PARSE_STATE_BUFFER
    } parse_state_t;

typedef struct tagUPDATE_STATUS_TYPE            //!< HCI channel status structure
    {
    parse_state_t           state;              //!< receive state machine state
    update_pkt_store_t      pkt_store;          //!< receive packet assembly data store
    } update_status_t;


/*--------------------------------------------------------------------
                            VARIABLES
--------------------------------------------------------------------*/
static uint8_t            download_status = false;
static update_state_t     update_state = UPDATE_STATE_SUSPEND;
static fw_buf_info        md_buf_info;
static fw_buf_info        flash_buf_info;
static uint16_t           md_write_count;
static uint16_t           flash_write_count;
static uint16_t           md_verify_count;
static uint16_t           flash_verify_count;
static update_status_t    update_status;
static uint8_t            static_section[93] = { 0x42, 0x52, 0x43, 0x4D, 0x63, 0x66, 0x67, 0x53, 0x00, 0x00, 0x00, 0x00, 0x4C, 0x00, 0x00, 0x00, 0x01, 0x01, 0x04,\
                                                 0xC0, 0x5D, 0x00, 0x00, 0x00, 0x03, 0x06, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x01, 0x1C, 0x00, 0x14, 0x50,\
                                                 0x00, 0x00, 0x0A, 0x52, 0x00, 0x00, 0x04, 0x50, 0x00, 0x00, 0x14, 0x50, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00,\
                                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x01, 0x10, 0x00, 0x04, 0x27, 0x00, 0x4F, 0xF4, 0xB0, 0x01, 0x03, 0x20,\
                                                 0x08, 0x60, 0x70, 0x47, 0x00, 0x00, 0x06, 0x01, 0x04, 0x01, 0x04, 0x27, 0x00, 0xFE, 0x00, 0x00, 0xEB };

/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/
static uint8_t parse_update_receive_packet
    (
    uint8_t    const**   const,    //!< [in] pointer to pointer to input HCI byte buffer
    uint32_t*            const     //!< [in] pointer to number of bytes in the HCI receive buffer
    );

static void download_finish
    (
    void
    );

static void verify_flash
    (
    uint8_t*,
    uint8_t
    );

static void download_flash
    (
    void
    );

static void verify_md
    (
    uint8_t*,
    uint8_t
    );

static uint32_t check_flash_end
    (
    void
    );

static void erase_flash
    (
    void
    );

/*********************************************************************
*
* Parse bytes on update state
*
* Parsing bt update packet on different update state, and return valid
* packet.
*
*********************************************************************/
static uint8_t parse_update_receive_packet
    (
    uint8_t    const**   const pp_hci_buffer,    //!< [in] pointer to pointer to input HCI byte buffer
    uint32_t*            const p_nbytes         //!< [in] pointer to number of bytes in the HCI receive buffer
    )
{
uint8_t                 l_valid_pkt;
uint8_t         const*  l_p_hci_buffer;
update_pkt_store_t*     l_pkt_store;
uint8_t                 l_byte_value;

l_valid_pkt    = false;
l_p_hci_buffer = *( pp_hci_buffer );
l_pkt_store    = &( update_status.pkt_store );

while( ( false == l_valid_pkt ) && ( *( p_nbytes ) > 0) )
    {
    l_byte_value = *( l_p_hci_buffer );

    switch( update_status.state )
        {
        case PARSE_STATE_INIT_1:
            if( INIT_BYTE_1 == l_byte_value )
                {
                l_pkt_store->opcode  =  0;
                l_pkt_store->length  =  0;
                l_pkt_store->count   =  0;
                update_status.state     =  PARSE_STATE_INIT_2;
                }
            else
                {
                update_status.state     =  PARSE_STATE_INIT_1;
                }
            break;

        case PARSE_STATE_INIT_2:
            if( INIT_BYTE_2 == l_byte_value )
                {
                update_status.state     =  PARSE_STATE_LENGTH;
                }
            else
                {
                update_status.state     =  PARSE_STATE_INIT_1;
                }
            break;

        case PARSE_STATE_LENGTH:
            if( ( l_byte_value > 3 ) && ( l_byte_value <= ( MAX_UPDATE_DATA_LENGTH + 4 ) ) )
                {
                l_pkt_store->length  =  l_byte_value - 4;
                update_status.state     =  PARSE_STATE_VERIFY_1;
                }
            else
                {
                update_status.state     =  PARSE_STATE_INIT_1;
                }
            break;

        case PARSE_STATE_VERIFY_1:
            if( 0x01 == l_byte_value )
                {
                update_status.state     =  PARSE_STATE_OPCODE;
                }
            else
                {
                update_status.state     =  PARSE_STATE_INIT_1;
                }
            break;

        case PARSE_STATE_OPCODE:
            update_status.state     =  PARSE_STATE_VERIFY_3;
            l_pkt_store->opcode  =  l_byte_value;
            break;

        case PARSE_STATE_VERIFY_3:
            update_status.state     =  PARSE_STATE_VERIFY_4;
            break;

        case PARSE_STATE_VERIFY_4:
            if( 0x0 == l_byte_value )
                {
                update_status.state     =  PARSE_STATE_BUFFER;
                if( ( OPCODE_LAUNCH == l_pkt_store->opcode ) || ( 0 == l_pkt_store->length ) )
                    {
                    l_valid_pkt = true;
                    update_status.state = PARSE_STATE_INIT_1;
                    }
                }
            else
                {
                update_status.state     =  PARSE_STATE_INIT_1;
                }
            break;

        case PARSE_STATE_BUFFER:
            l_pkt_store->data[l_pkt_store->count] = l_byte_value;
            l_pkt_store->count  += 1;

            if( l_pkt_store->count >= l_pkt_store->length )
                {
                l_valid_pkt = true;
                update_status.state = PARSE_STATE_INIT_1;
                }
            break;

        default:
            break;
        }

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
* This function retrieves BT update response bytes from the HCI receive
* event
*
*********************************************************************/
void parseUpdatePkt
    (
    uint8_t* l_hci_buffer,
    uint32_t length
    )
{
uint32_t           l_num_bytes = length;
uint8_t*           l_p_hci_buffer;
uint8_t            l_valid_pkt = false;
uint8_t  const**   l_pp_hci_buffer;
update_pkt_store_t*   l_p_pkt_store;

l_p_hci_buffer  = &( l_hci_buffer[0] );
l_pp_hci_buffer = (uint8_t const**) &( l_p_hci_buffer );

while( l_num_bytes > 0 )
    {
    l_valid_pkt = parse_update_receive_packet( l_pp_hci_buffer, &( l_num_bytes ) );

    /*-------------------------------------------------------
    Pass the valid HCI packet back for processing
    -------------------------------------------------------*/
    if( true == l_valid_pkt )
        {
        l_p_pkt_store = &( update_status.pkt_store );
        if( ( OPCODE_READRAM == l_p_pkt_store->opcode ) && ( UPDATE_STATE_VERIFY_MINIDRIVER == update_state )  )
            {
            verify_md( l_p_pkt_store->data, l_p_pkt_store->length );
            }
        else if( ( OPCODE_LAUNCH == l_p_pkt_store->opcode ) && ( UPDATE_STATE_LAUNCH_MINIDRIVER == update_state )  )
            {
            PRINTF( "Minidriver launched. Erase BT flash\n\r" );
            erase_flash();
            }

        else if( ( OPCODE_ERASE == l_p_pkt_store->opcode ) && ( UPDATE_STATE_ERASE_BT_CHIP == update_state )  )
            {
            PRINTF( "Erase BT chip success. Start download BT flash\n\r" );
            download_flash();
            }

        else if( ( OPCODE_READRAM == l_p_pkt_store->opcode ) && ( UPDATE_STATE_VERIFY_FLASH == update_state )  )
            {
            verify_flash( l_p_pkt_store->data, l_p_pkt_store->length );
            }
        else if( ( OPCODE_LAUNCH == l_p_pkt_store->opcode ) && ( UPDATE_STATE_LAUNCH_FLASH == update_state )  )
            {
            PRINTF( "BT Flash launched and Download finished.\n\r" );
            download_finish();
            }
        l_valid_pkt = false;
        }
    }
}

/*********************************************************************
*
* Download finish
*
* Change download status, reset 89820 and reconfigure UART to default
* state
*
*********************************************************************/
static void download_finish
    (
    void
    )
{
char  sw_ver[8];
uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN] = {0};
bool  bd_addr_set = false;

sprintf( sw_ver, "%c.%c", GARMIN_SW_MAJOR_VER, GARMIN_SW_MINOR_VER );

update_state = UPDATE_STATE_DOWNLOAD_FINISH;

// Set LPUART3_CTS back
GPIO_PinWrite( GPIO9, 2, 1 );
vTaskDelay( pdMS_TO_TICKS( 20 ) ); // delay 20 ms

download_status = false;

// Reset 89820
HCI_reset_BT();

// Reconfigure GPIO1_IO21 to BT UART RTS
IOMUXC_SetPinMux( IOMUXC_GPIO_AD_03_LPUART7_RTS_B, /* GPIO_AD_B1_05 is configured as GPIO1_IO21 */
                  0U);                                /* Software Input On Field: Input Path is determined by functionality */

PERIPHERAL_uart_port_reconfig( true, true, 3000000 );

vTaskDelay( pdMS_TO_TICKS( 2000 ) ); // delay 2000 ms

BTM_IOP_read_local_device_address();
BTM_get_local_device_address( &(bd_addr[0]) );
for( uint8_t i = 0; i < BT_DEVICE_ADDRESS_LEN; i++ )
    {
    if( 0xff != bd_addr[i] )
        {
        bd_addr_set = true;
        break;
        }
    }
if( bd_addr_set )
    {
    BTM_IOP_set_local_device_address( bd_addr );
    }

if( BOARD_is_tft_connected() == TFT_CONNECTED )
    {
    EW_notify_bt_fw_update_status( EnumBtFwStatusUPDATE_FINISH, sw_ver );
    }
}

/*********************************************************************
*
* Verify BT flash is correct
*
* Use read ram command, check the data on MCU BT flash address are
* the same as BT flash address
*
*********************************************************************/
static void verify_flash
    (
    uint8_t* p_buffer,
    uint8_t length
    )
{
uint8_t          read_ram_cmd[9] = { 0x01, 0x4D, 0xFC, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00 };
uint8_t          launch_flash_cmd[8] = { 0x1, 0x4E, 0xFC, 0x4, 0xFF, 0xFF, 0xFF, 0xFF };
uint8_t          cmp_result;
static uint32_t  bt_verify_addr = MCU_BTFLASH_ADDR;

//Check the Read RAM data same as BT firmware
cmp_result = memcmp( &(p_buffer[0]), (uint32_t *)( bt_verify_addr + flash_verify_count * MAX_UPDATE_DATA_LENGTH ), length );

flash_verify_count++;
flash_buf_info.verify_addr += length;

read_ram_cmd[4] = (uint8_t)( flash_buf_info.verify_addr & 0xff );
read_ram_cmd[5] = (uint8_t)( ( flash_buf_info.verify_addr & 0xff00 ) >> 8 );
read_ram_cmd[6] = (uint8_t)( ( flash_buf_info.verify_addr & 0xff0000 ) >> 16 );
read_ram_cmd[7] = (uint8_t)( ( flash_buf_info.verify_addr & 0xff000000 ) >> 24 );

if( ( flash_verify_count < ( flash_buf_info.buffer_size / MAX_UPDATE_DATA_LENGTH ) ) && ( 0 == cmp_result ) )
    {
    read_ram_cmd[8] = MAX_UPDATE_DATA_LENGTH;
    PERIPHERAL_uart_tx_data( READRAM_CMD_LENGTH , read_ram_cmd );
    vTaskDelay( pdMS_TO_TICKS( 30 ) ); // delay 30 ms
    }
else if( 0 == cmp_result )
    {
    update_state = UPDATE_STATE_LAUNCH_FLASH;
    PERIPHERAL_uart_tx_data( LAUNCH_CMD_LENGTH , launch_flash_cmd );
    vTaskDelay( pdMS_TO_TICKS( 30 ) ); // delay 30 ms
    }
}

/*********************************************************************
*
* Download BT flash
*
* Use write ram command, download flash on BT, use 240-byte block
*
*********************************************************************/
static void download_flash
    (
    void
    )
{
uint8_t            write_flash_cmd[248] = {0};
uint8_t            read_ram_cmd[READRAM_CMD_LENGTH];
static uint32_t    bt_flash_addr = MCU_BTFLASH_ADDR;
uint32_t           val;
uint8_t            write_ss[93 + 8] = {0};

// Write static section
write_ss[0] = 0x01;
write_ss[1] = 0x4C;
write_ss[2] = 0xFC;
write_ss[3] = 0x61;
write_ss[4] = 0x00;
write_ss[5] = 0x00;
write_ss[6] = 0x50;
write_ss[7] = 0x00;
memcpy( &(write_ss[8]), &(static_section[0]), 93 );
PERIPHERAL_uart_tx_data( sizeof( write_ss ) , write_ss );
vTaskDelay( pdMS_TO_TICKS( 50 ) ); // delay 50 ms

flash_write_count = 0;

write_flash_cmd[0] = 0x01;
write_flash_cmd[1] = 0x4C;
write_flash_cmd[2] = 0xFC;

while( flash_write_count < ( flash_buf_info.buffer_size / MAX_UPDATE_DATA_LENGTH ) )
    {
    write_flash_cmd[3] = MAX_UPDATE_DATA_LENGTH + 4;
    write_flash_cmd[4] = (uint8_t)( flash_buf_info.write_addr & 0xff );
    write_flash_cmd[5] = (uint8_t)( ( flash_buf_info.write_addr & 0xff00 ) >> 8 );
    write_flash_cmd[6] = (uint8_t)( ( flash_buf_info.write_addr & 0xff0000 ) >> 16 );
    write_flash_cmd[7] = (uint8_t)( ( flash_buf_info.write_addr & 0xff000000 ) >> 24 );

    for( uint8_t i = 0; i < MAX_UPDATE_DATA_LENGTH; i += 4 )
    {
    val = *( (volatile uint32_t *)( bt_flash_addr + i ) );
    write_flash_cmd[8 + i] = (uint8_t)( val & 0xff );
    write_flash_cmd[9 + i] = (uint8_t)( ( val & 0xff00 ) >> 8 );
    write_flash_cmd[10 + i] = (uint8_t)( ( val & 0xff0000 ) >> 16 );
    write_flash_cmd[11 + i] = (uint8_t)( ( val & 0xff000000 ) >> 24 );
    }
    bt_flash_addr += MAX_UPDATE_DATA_LENGTH;
    PERIPHERAL_uart_tx_data( sizeof( write_flash_cmd ), write_flash_cmd );

    flash_write_count++;
    flash_buf_info.write_addr += MAX_UPDATE_DATA_LENGTH;
    vTaskDelay( pdMS_TO_TICKS( 30 ) ); // delay 30 ms
    }

// Send verify flash first command
flash_verify_count = 0;

read_ram_cmd[0] = 0x01;
read_ram_cmd[1] = 0x4D;
read_ram_cmd[2] = 0xFC;
read_ram_cmd[3] = 0x05;
read_ram_cmd[4] = (uint8_t)( flash_buf_info.verify_addr & 0xff );
read_ram_cmd[5] = (uint8_t)( ( flash_buf_info.verify_addr & 0xff00 ) >> 8 );
read_ram_cmd[6] = (uint8_t)( ( flash_buf_info.verify_addr & 0xff0000 ) >> 16 );
read_ram_cmd[7] = (uint8_t)( ( flash_buf_info.verify_addr & 0xff000000 ) >> 24 );
read_ram_cmd[8] = MAX_UPDATE_DATA_LENGTH;

update_state = UPDATE_STATE_VERIFY_FLASH;
PERIPHERAL_uart_tx_data( READRAM_CMD_LENGTH , read_ram_cmd );
vTaskDelay( pdMS_TO_TICKS( 30 ) ); // delay 30 ms
}

static void erase_flash
    (
    void
    )
{
uint8_t      erase_bt_cmd[8] = { 0x1, 0xCE, 0xFF, 0x04, 0xef, 0xee, 0xbe, 0xfc };
PRINTF("Start erase BT flash\n\r");
update_state = UPDATE_STATE_ERASE_BT_CHIP;
PERIPHERAL_uart_tx_data( sizeof( erase_bt_cmd ), erase_bt_cmd );
vTaskDelay( pdMS_TO_TICKS( 50 ) ); // delay 50 ms
}


/*********************************************************************
*
* Verify minidriver is correct
*
* Use read ram command, check the data on MCU minidriver address are
* the same as BT minidriver address
*
*********************************************************************/
static void verify_md
    (
    uint8_t* p_buffer,
    uint8_t length
    )
{
uint8_t      read_ram_cmd[9] = { 0x01, 0x4D, 0xFC, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00 };
uint8_t      launch_md_cmd[8] = { 0x1, 0x4E, 0xFC, 0x4, 0x0, 0x04, 0x27, 0x0 };
uint8_t      cmp_result;
static uint32_t     md_verify_addr = MCU_MINIDRIVER_ADDR;

cmp_result = memcmp( &(p_buffer[0]), (uint32_t *)( md_verify_addr + md_verify_count * MAX_UPDATE_DATA_LENGTH ), length );

md_verify_count++;
md_buf_info.verify_addr += length;

read_ram_cmd[4] = (uint8_t)( md_buf_info.verify_addr & 0xff );
read_ram_cmd[5] = (uint8_t)( ( md_buf_info.verify_addr & 0xff00 ) >> 8 );
read_ram_cmd[6] = (uint8_t)( ( md_buf_info.verify_addr & 0xff0000 ) >> 16 );
read_ram_cmd[7] = (uint8_t)( ( md_buf_info.verify_addr & 0xff000000 ) >> 24 );

if( ( md_verify_count < ( md_buf_info.buffer_size / MAX_UPDATE_DATA_LENGTH ) ) && ( 0 == cmp_result ) )
    {
    read_ram_cmd[8] = MAX_UPDATE_DATA_LENGTH;
    PERIPHERAL_uart_tx_data( READRAM_CMD_LENGTH , read_ram_cmd );
    vTaskDelay( pdMS_TO_TICKS( 30 ) ); // delay 30 ms
    }
else if( ( ( md_buf_info.buffer_size / MAX_UPDATE_DATA_LENGTH ) == md_verify_count ) && ( 0 == cmp_result ) )
    {
    read_ram_cmd[8] = md_buf_info.buffer_size - ( ( md_buf_info.buffer_size / MAX_UPDATE_DATA_LENGTH ) * MAX_UPDATE_DATA_LENGTH );
    PERIPHERAL_uart_tx_data( READRAM_CMD_LENGTH , read_ram_cmd );
    vTaskDelay( pdMS_TO_TICKS( 30 ) ); // delay 30 ms
    }
else if( 0 == cmp_result )
    {
    update_state = UPDATE_STATE_LAUNCH_MINIDRIVER;
    PERIPHERAL_uart_tx_data( LAUNCH_CMD_LENGTH , launch_md_cmd );
    vTaskDelay( pdMS_TO_TICKS( 30 ) ); // delay 30 ms
    }
}

/*********************************************************************
*
* Check BT Flash end address on MCU
*
* Check where is the end of 240-byte section, all 0xff
*
*********************************************************************/
static uint32_t check_flash_end
    (
    void
    )
{
uint32_t bt_flash_addr = MCU_BTFLASH_ADDR;
uint32_t  val;
uint8_t  section_nowrite = pdFALSE;

while( pdFALSE == section_nowrite )
    {
    for( uint8_t i = 0; i < MAX_UPDATE_DATA_LENGTH; i += 4 )
        {
        val = *( (volatile uint32_t *)( bt_flash_addr + i ) );
        if( val != 0xffffffff )
            {
            section_nowrite = pdFALSE;
            break;
            }
        else
            {
            section_nowrite = pdTRUE;
            }
        }
    bt_flash_addr += MAX_UPDATE_DATA_LENGTH;
    }
bt_flash_addr -= MAX_UPDATE_DATA_LENGTH;

PRINTF("Check BT_flash_mcu_end_addr:%08x\n\r", bt_flash_addr);
return bt_flash_addr;
}

/*********************************************************************
*
* Get BT update status
*
* For outside function retrieve BT update status(true or false)
*
*********************************************************************/
bool getBTUpdateStatus
    (
    void
    )
{
return download_status;
}

/*********************************************************************
*
* BT update initialization
*
* Initiate BT update, make cyw989820 into download mode
*
*********************************************************************/
void bt_update_init
    (
    void
    )
{
uint8_t      reset_cmd[4] = { 0x1, 0x03, 0x0C, 0x0 };
uint8_t      write_md_cmd[248] = {0};
uint8_t      read_ram_cmd[READRAM_CMD_LENGTH];
// For minidriver flash
uint32_t     bt_md_addr = MCU_MINIDRIVER_ADDR;
uint32_t     val;
uint32_t     md_last_sec_size;
char         sw_ver[8] = { 0 };

sprintf( sw_ver, "%c.%c", GARMIN_SW_MAJOR_VER, GARMIN_SW_MINOR_VER );
if( BOARD_is_tft_connected() == TFT_CONNECTED )
    {
    EW_notify_bt_fw_update_status( EnumBtFwStatusUPDATE_START, sw_ver );
    }

md_write_count = 0;
flash_write_count = 0;

gpio_pin_config_t uart_cts_config = {kGPIO_DigitalOutput, 0, kGPIO_NoIntmode};

update_state = UPDATE_STATE_INIT;
download_status = true;

// Reconfigure UART & reset cyw989820
PERIPHERAL_uart_port_reconfig( false, false, 115200 );

// Reconfigure BT UART RTS to GPIO1_IO21
IOMUXC_SetPinMux( IOMUXC_GPIO_AD_03_GPIO9_IO02,    /* GPIO_AD_B1_05 is configured as GPIO1_IO21 */
                  0U);                                /* Software Input On Field: Input Path is determined by functionality */

GPIO_PinInit( GPIO9, 2U, &uart_cts_config );
GPIO_PinWrite( GPIO9, 2, 0 );

// Reset 89820
HCI_reset_BT();

// send reset cmd
PERIPHERAL_uart_tx_data( sizeof( reset_cmd ), reset_cmd );
vTaskDelay( pdMS_TO_TICKS( 20 ) ); // delay 20 ms

update_state = UPDATE_STATE_DOWNLOAD_MINIDRIVER;

// Initiate flash buffer address
flash_buf_info.write_addr = BT_FLASH_ADDR;
flash_buf_info.verify_addr = BT_FLASH_ADDR;
flash_buf_info.flash_end_addr = check_flash_end();
flash_buf_info.buffer_size = flash_buf_info.flash_end_addr - MCU_BTFLASH_ADDR;
PRINTF( "Flash buffer size:0x%08x\n\r", flash_buf_info.buffer_size );

// Write  minidriver
memset( write_md_cmd, 0, sizeof( write_md_cmd ) );
write_md_cmd[0] = 0x1;
write_md_cmd[1] = 0x4C;
write_md_cmd[2] = 0xFC;
write_md_cmd[3] = 0xF4;

// Initiate minidriver buffer address
md_buf_info.flash_end_addr = MCU_MINIDRIVER_END_ADDR;
md_buf_info.verify_addr = BT_MINIDRIVER_ADDR;
md_buf_info.write_addr = BT_MINIDRIVER_ADDR;
md_buf_info.buffer_size = MCU_MINIDRIVER_END_ADDR - MCU_MINIDRIVER_ADDR;
md_write_count = 0;
md_last_sec_size = md_buf_info.buffer_size - ( ( md_buf_info.buffer_size / MAX_UPDATE_DATA_LENGTH ) * MAX_UPDATE_DATA_LENGTH );

if( *( (volatile uint32_t *)( MCU_MINIDRIVER_END_ADDR - 4 ) ) != MINIDRIVER_LAST_VAL )
    {
    PRINTF("ERROR: MINIDRIVER IS WRONG !\n\r");
    PRINTF("Last address:%08x, Data:%08x\n\r", *( (volatile uint32_t *)( MCU_MINIDRIVER_END_ADDR - 4 ) ));
    download_status = false;
    if( BOARD_is_tft_connected() == TFT_CONNECTED )
        {
        EW_notify_bt_fw_update_status( EnumBtFwStatusUPDATE_ABORT, sw_ver );
        }
    return;
    }

while( md_write_count < ( md_buf_info.buffer_size / MAX_UPDATE_DATA_LENGTH ) )
    {
    write_md_cmd[3] = MAX_UPDATE_DATA_LENGTH + 4;
    write_md_cmd[4] = (uint8_t)( md_buf_info.write_addr & 0xff );
    write_md_cmd[5] = (uint8_t)( ( md_buf_info.write_addr & 0xff00 ) >> 8 );
    write_md_cmd[6] = (uint8_t)( ( md_buf_info.write_addr & 0xff0000 ) >> 16 );
    write_md_cmd[7] = (uint8_t)( ( md_buf_info.write_addr & 0xff000000 ) >> 24 );

    for( uint8_t i = 0; i < MAX_UPDATE_DATA_LENGTH; i += 4 )
        {
        val = *( (volatile uint32_t *)( bt_md_addr + i ) );
        write_md_cmd[8 + i] = (uint8_t)( val & 0xff );
        write_md_cmd[9 + i] = (uint8_t)( ( val & 0xff00 ) >> 8 );
        write_md_cmd[10 + i] = (uint8_t)( ( val & 0xff0000 ) >> 16 );
        write_md_cmd[11 + i] = (uint8_t)( ( val & 0xff000000 ) >> 24 );
        }
    bt_md_addr += MAX_UPDATE_DATA_LENGTH;
    PERIPHERAL_uart_tx_data( sizeof( write_md_cmd ), write_md_cmd );
    md_write_count++;
    md_buf_info.write_addr += MAX_UPDATE_DATA_LENGTH;
    vTaskDelay( pdMS_TO_TICKS( 20 ) ); // delay 20 ms
    }

write_md_cmd[3] = md_last_sec_size + 4;
write_md_cmd[4] = (uint8_t)( md_buf_info.write_addr & 0xff );
write_md_cmd[5] = (uint8_t)( ( md_buf_info.write_addr & 0xff00 ) >> 8 );
write_md_cmd[6] = (uint8_t)( ( md_buf_info.write_addr & 0xff0000 ) >> 16 );
write_md_cmd[7] = (uint8_t)( ( md_buf_info.write_addr & 0xff000000 ) >> 24 );

for( uint8_t i = 0; i < md_last_sec_size; i += 4 )
    {
    val = *( (volatile uint32_t *)( bt_md_addr + i ) );
    write_md_cmd[8 + i] = (uint8_t)( val & 0xff );
    write_md_cmd[9 + i] = (uint8_t)( ( val & 0xff00 ) >> 8 );
    write_md_cmd[10 + i] = (uint8_t)( ( val & 0xff0000 ) >> 16 );
    write_md_cmd[11 + i] = (uint8_t)( ( val & 0xff000000 ) >> 24 );
    }

PERIPHERAL_uart_tx_data( ( md_last_sec_size + 8 ) , write_md_cmd );
vTaskDelay( pdMS_TO_TICKS( 50 ) ); // delay 50 ms

md_write_count++;
md_buf_info.write_addr += 0x8F;

md_verify_count = 0;

read_ram_cmd[0] = 0x01;
read_ram_cmd[1] = 0x4D;
read_ram_cmd[2] = 0xFC;
read_ram_cmd[3] = 0x05;
read_ram_cmd[4] = (uint8_t)( md_buf_info.verify_addr & 0xff );
read_ram_cmd[5] = (uint8_t)( ( md_buf_info.verify_addr & 0xff00 ) >> 8 );
read_ram_cmd[6] = (uint8_t)( ( md_buf_info.verify_addr & 0xff0000 ) >> 16 );
read_ram_cmd[7] = (uint8_t)( ( md_buf_info.verify_addr & 0xff000000 ) >> 24 );
read_ram_cmd[8] = MAX_UPDATE_DATA_LENGTH;

PERIPHERAL_uart_tx_data( READRAM_CMD_LENGTH , read_ram_cmd );
update_state = UPDATE_STATE_VERIFY_MINIDRIVER;
}
