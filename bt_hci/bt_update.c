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
#include "hci_control_api.h"
#include "pin_mux.h"

#define INIT_BYTE_1                0x04
#define INIT_BYTE_2                0x0E
#define MAX_UPDATE_DATA_LENGTH     240
#define MAX_COMMAND_DATA_LENGTH    244
#define READRAM_CMD_LENGTH         5
#define LAUNCH_CMD_LENGTH          4
#define ERASE_CMD_LENGTH           4
#define OPCODE_WRITERAM            0xFC4C
#define OPCODE_READRAM             0xFC4D
#define OPCODE_LAUNCH              0xFC4E
#define OPCODE_ERASE               0xFFCE
#define OPCODE_SCAN_ENABLE         0x0C1A
#define OPCODE_DUT_MODE            0x1803
#define BT_MINIDRIVER_ADDR         0x270400
#define BT_STATIC_SECTION_ADDR     0x500000
#define BT_FLASH_ADDR              0x501400
extern uint32_t __base_BOARD_FLASH_BTFW;
#define FLASH_BT_FW_BASE_ADDR      ( ( uint32_t )( &__base_BOARD_FLASH_BTFW ) )
#define MCU_MINIDRIVER_ADDR        ( FLASH_BT_FW_BASE_ADDR + 0x00000100 )
#define MCU_BTFLASH_ADDR           ( FLASH_BT_FW_BASE_ADDR + 0x00010000 )
#define MCU_MINIDRIVER_END_ADDR    ( FLASH_BT_FW_BASE_ADDR + 0x00003ac0 )
#define MINIDRIVER_LAST_VAL        0x00273001
#define HCI_STANDARD_PKT           0x01
#define HCI_STANDARD_HEADER_LENGTH 4
#define SW_VERSION_LENGTH          8
#define BT_SW_VER_LENGTH           2
#define ERASE_CONST_ADDR           0xFCBEEEEF
#define ORIGINAL_BAUD_RATE         3000000
#define UPDATE_BAUD_RATE           115200
#define SCAN_ENABLE_DATA           3

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
    uint16_t      opcode;                         //!< HCI packet ID
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
    PARSE_STATE_OPCODE_LO_BYTE,
    PARSE_STATE_OPCODE_HI_BYTE,
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
static bt_parser_t        parser_status = PARSER_WICED_HCI;
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
static uint32_t           download_flash_addr;
static bool               BT_DUT_mode_state = false;
static bool               BT_update_status = false;

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
                update_status.state     =  PARSE_STATE_OPCODE_LO_BYTE;
                }
            else
                {
                update_status.state     =  PARSE_STATE_INIT_1;
                }
            break;

        case PARSE_STATE_OPCODE_LO_BYTE:
            l_pkt_store->opcode  +=  (uint16_t)l_byte_value;
            update_status.state  =  PARSE_STATE_OPCODE_HI_BYTE;
            break;

        case PARSE_STATE_OPCODE_HI_BYTE:
            l_pkt_store->opcode  += ( (uint16_t)l_byte_value << 8 );
            update_status.state  =  PARSE_STATE_VERIFY_4;
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
uint8_t            write_scan_enable_data = SCAN_ENABLE_DATA;

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

        switch( update_state )
            {
            case UPDATE_STATE_SUSPEND:
                if( OPCODE_ALLOW_CONNECTION == l_p_pkt_store->opcode )
                    {
                    BT_UPDATE_standard_send_command( OPCODE_SCAN_ENABLE, &write_scan_enable_data, sizeof( uint8_t ) );
                    }
                else if( OPCODE_SCAN_ENABLE == l_p_pkt_store->opcode )
                    {
                    BT_UPDATE_standard_send_command( OPCODE_DUT_MODE, NULL, 0 );
                    }
                else if( OPCODE_DUT_MODE == l_p_pkt_store->opcode )
                    {
                    BT_DUT_mode_state = true;
                    BT_UPDATE_setParserStatus( PARSER_WICED_HCI );
                    }
                else if( OPCODE_COMMIT_ADDR == l_p_pkt_store->opcode )
                    {
                    BT_UPDATE_setParserStatus( PARSER_WICED_HCI );
                    HCI_normal_reset_BT();
                    }
                break;

            case UPDATE_STATE_INIT:
            case UPDATE_STATE_DOWNLOAD_MINIDRIVER:
                // Do nothing for debug
                break;

            case UPDATE_STATE_VERIFY_MINIDRIVER:
                if( OPCODE_READRAM == l_p_pkt_store->opcode )
                    {
                    verify_md( l_p_pkt_store->data, l_p_pkt_store->length );
                    }
                break;

            case UPDATE_STATE_LAUNCH_MINIDRIVER:
                if( OPCODE_LAUNCH == l_p_pkt_store->opcode )
                    {
                    PRINTF( "Minidriver launched. Erase BT flash\n\r" );
                    erase_flash();
                    }
                break;

            case UPDATE_STATE_ERASE_BT_CHIP:
                if( OPCODE_ERASE == l_p_pkt_store->opcode )
                    {
                    PRINTF( "Erase BT chip success. Start download BT flash\n\r" );
                    download_flash();
                    }
                break;

            case UPDATE_STATE_DOWNLOAD_FLASH:
                break;

            case UPDATE_STATE_VERIFY_FLASH:
                if( OPCODE_READRAM == l_p_pkt_store->opcode )
                    {
                    verify_flash( l_p_pkt_store->data, l_p_pkt_store->length );
                    }
                break;

            case UPDATE_STATE_LAUNCH_FLASH:
                if( OPCODE_LAUNCH == l_p_pkt_store->opcode )
                    {
                    PRINTF( "BT Flash launched and Download finished.\n\r" );
                    download_finish();
                    }
                break;

            case UPDATE_STATE_DOWNLOAD_FINISH:
                break;

            default:
                break;
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
char    sw_ver[SW_VERSION_LENGTH];
uint8_t bd_addr[BT_DEVICE_ADDRESS_LEN] = {0};
uint8_t bt_sw_ver[BT_SW_VER_LENGTH];
bool    bd_addr_set = false;

sprintf( sw_ver, "%c.%c", GARMIN_SW_MAJOR_VER, GARMIN_SW_MINOR_VER );

update_state = UPDATE_STATE_DOWNLOAD_FINISH;

parser_status = PARSER_WICED_HCI;

// Reset 89820
HCI_normal_reset_BT();

// Read BT chip address, if not all 0xFF(means already commit address), do factory commit BD address
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

// Notify BT update version to UI
bt_sw_ver[0] = GARMIN_SW_MAJOR_VER;
bt_sw_ver[1] = GARMIN_SW_MINOR_VER;
BTM_update_sw_version( bt_sw_ver );

if( BOARD_is_tft_connected() == TFT_CONNECTED )
    {
    EW_notify_bt_fw_update_status( EnumBtFwStatusUPDATE_FINISH, sw_ver );
    }
BT_update_status = false;
update_state = UPDATE_STATE_SUSPEND;
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
uint8_t          read_ram_cmd[READRAM_CMD_LENGTH] = { 0 };
uint8_t          launch_flash_cmd[LAUNCH_CMD_LENGTH] = { 0 };
uint8_t          cmp_result;

//Check the Read RAM data same as BT firmware
cmp_result = memcmp( &(p_buffer[0]), (uint32_t *)( MCU_BTFLASH_ADDR + flash_verify_count * MAX_UPDATE_DATA_LENGTH ), length );

flash_verify_count++;
flash_buf_info.verify_addr += length;
UINT32_to_UINT8_arry(  flash_buf_info.verify_addr, &( read_ram_cmd[0] ) );

if( ( flash_verify_count < ( flash_buf_info.buffer_size / MAX_UPDATE_DATA_LENGTH ) ) && ( 0 == cmp_result ) )
    {
    read_ram_cmd[4] = MAX_UPDATE_DATA_LENGTH;
    BT_UPDATE_standard_send_command( OPCODE_READRAM, read_ram_cmd, sizeof( read_ram_cmd ) );
    vTaskDelay( pdMS_TO_TICKS( COMMON_CMD_WAIT_MS ) );
    }
else if( 0 == cmp_result )
    {
    update_state = UPDATE_STATE_LAUNCH_FLASH;
    BT_UPDATE_standard_send_command( OPCODE_LAUNCH, launch_flash_cmd, sizeof( launch_flash_cmd ) );
    vTaskDelay( pdMS_TO_TICKS( COMMON_CMD_WAIT_MS ) );
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
uint8_t            write_flash_cmd[MAX_COMMAND_DATA_LENGTH] = { 0 };
uint8_t            read_ram_cmd[READRAM_CMD_LENGTH] = { 0 };
uint32_t           addr_val_uint32;
uint8_t            write_ss[ sizeof( uint32_t ) + sizeof( static_section ) ] = {0};

// Write static section
UINT32_to_UINT8_arry(  BT_STATIC_SECTION_ADDR, &( write_ss[0] ) );
memcpy( &(write_ss[4]), &(static_section[0]), sizeof( static_section ) );
BT_UPDATE_standard_send_command( OPCODE_WRITERAM, write_ss, sizeof( write_ss ) );
vTaskDelay( pdMS_TO_TICKS( COMMON_CMD_WAIT_MS ) );

flash_write_count = 0;

while( flash_write_count < ( flash_buf_info.buffer_size / MAX_UPDATE_DATA_LENGTH ) )
    {
    UINT32_to_UINT8_arry(  flash_buf_info.write_addr, &( write_flash_cmd[0] ) );

    for( uint8_t i = 0; i < MAX_UPDATE_DATA_LENGTH; i += 4 )
    {
    addr_val_uint32 = *( (volatile uint32_t *)( download_flash_addr  + i ) );
    UINT32_to_UINT8_arry( addr_val_uint32, &( write_flash_cmd[4 + i] ) );
    }
    download_flash_addr  += MAX_UPDATE_DATA_LENGTH;
    BT_UPDATE_standard_send_command( OPCODE_WRITERAM, write_flash_cmd, sizeof( write_flash_cmd ) );

    flash_write_count++;
    flash_buf_info.write_addr += MAX_UPDATE_DATA_LENGTH;
    vTaskDelay( pdMS_TO_TICKS( COMMON_CMD_WAIT_MS ) );
    }

// Send verify flash first command
flash_verify_count = 0;

UINT32_to_UINT8_arry( flash_buf_info.verify_addr, &( read_ram_cmd[0] ) );
read_ram_cmd[4] = MAX_UPDATE_DATA_LENGTH;

update_state = UPDATE_STATE_VERIFY_FLASH;
BT_UPDATE_standard_send_command( OPCODE_READRAM, read_ram_cmd, sizeof( read_ram_cmd ) );
vTaskDelay( pdMS_TO_TICKS( COMMON_CMD_WAIT_MS ) );
}

static void erase_flash
    (
    void
    )
{
uint8_t  erase_bt_cmd[ERASE_CMD_LENGTH] = { 0 };

UINT32_to_UINT8_arry( ERASE_CONST_ADDR, &( erase_bt_cmd[0] ) );

PRINTF("Start erase BT flash\n\r");
update_state = UPDATE_STATE_ERASE_BT_CHIP;
BT_UPDATE_standard_send_command( OPCODE_ERASE, erase_bt_cmd, sizeof( erase_bt_cmd ) );
vTaskDelay( pdMS_TO_TICKS( COMMON_CMD_WAIT_MS ) );
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
uint8_t      read_ram_cmd[READRAM_CMD_LENGTH] = { 0 };
uint8_t      launch_md_cmd[LAUNCH_CMD_LENGTH] = { 0 };
uint8_t      cmp_result;

cmp_result = memcmp( &(p_buffer[0]), (uint32_t *)( MCU_MINIDRIVER_ADDR + md_verify_count * MAX_UPDATE_DATA_LENGTH ), length );

md_verify_count++;
md_buf_info.verify_addr += length;
UINT32_to_UINT8_arry( md_buf_info.verify_addr, &( read_ram_cmd[0] ) );

if( ( md_verify_count < ( md_buf_info.buffer_size / MAX_UPDATE_DATA_LENGTH ) ) && ( 0 == cmp_result ) )
    {
    read_ram_cmd[4] = MAX_UPDATE_DATA_LENGTH;
    BT_UPDATE_standard_send_command( OPCODE_READRAM, read_ram_cmd, sizeof( read_ram_cmd ) );
    vTaskDelay( pdMS_TO_TICKS( COMMON_CMD_WAIT_MS ) );
    }
else if( ( ( md_buf_info.buffer_size / MAX_UPDATE_DATA_LENGTH ) == md_verify_count ) && ( 0 == cmp_result ) )
    {
    read_ram_cmd[4] = md_buf_info.buffer_size - ( ( md_buf_info.buffer_size / MAX_UPDATE_DATA_LENGTH ) * MAX_UPDATE_DATA_LENGTH );
    BT_UPDATE_standard_send_command( OPCODE_READRAM, read_ram_cmd, sizeof( read_ram_cmd ) );
    vTaskDelay( pdMS_TO_TICKS( COMMON_CMD_WAIT_MS ) );
    }
else if( 0 == cmp_result )
    {
    update_state = UPDATE_STATE_LAUNCH_MINIDRIVER;
    // Launch address is BT minidriver address
    UINT32_to_UINT8_arry( BT_MINIDRIVER_ADDR, &( launch_md_cmd[0] ) );
    BT_UPDATE_standard_send_command( OPCODE_LAUNCH, launch_md_cmd, sizeof( launch_md_cmd ) );
    vTaskDelay( pdMS_TO_TICKS( COMMON_CMD_WAIT_MS ) );
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
uint32_t  check_val_uint32;
uint8_t  section_nowrite = pdFALSE;

while( pdFALSE == section_nowrite )
    {
    for( uint8_t i = 0; i < MAX_UPDATE_DATA_LENGTH; i += 4 )
        {
        check_val_uint32 = *( (volatile uint32_t *)( bt_flash_addr + i ) );
        if( check_val_uint32 != 0xffffffff )
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
* Get BT parser status
*
* For outside function retrieve BT parser status
*
*********************************************************************/
bt_parser_t getBTParserStatus
    (
    void
    )
{
return parser_status;
}

/*********************************************************************
*
* Set BT parser status
*
* For outside function set BT parser status
*
*********************************************************************/
void BT_UPDATE_setParserStatus
    (
    bt_parser_t config_parser_status
    )
{
parser_status = config_parser_status;
}

/*********************************************************************
*
* Get BT DUT mode state
*
* For production test get BT DUT mode state
*
*********************************************************************/
bool getBTDUTModeState
    (
    void
    )
{
return BT_DUT_mode_state;
}

/*********************************************************************
*
* Get BT update status
*
* For production IOP get bd address test get BT update status
*
*********************************************************************/
bool BT_UPDATE_get_BT_update_status
    (
    void
    )
{
return BT_update_status;
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
uint8_t      write_md_cmd[sizeof( uint32_t ) + MAX_UPDATE_DATA_LENGTH] = {0};
uint8_t      read_ram_cmd[READRAM_CMD_LENGTH];
// For minidriver flash
uint32_t     bt_md_addr = MCU_MINIDRIVER_ADDR;
uint32_t     addr_val_uint32;
uint32_t     md_last_sec_size;
char         sw_ver[SW_VERSION_LENGTH] = { 0 };

BT_update_status = true;
sprintf( sw_ver, "%c.%c", GARMIN_SW_MAJOR_VER, GARMIN_SW_MINOR_VER );

EW_notify_bt_fw_update_status( EnumBtFwStatusUPDATE_START, sw_ver );

md_write_count = 0;
flash_write_count = 0;

update_state = UPDATE_STATE_INIT;
parser_status = PARSER_STANDARD_HCI;

if( *( (volatile uint32_t *)( MCU_MINIDRIVER_END_ADDR - 4 ) ) != MINIDRIVER_LAST_VAL )
    {
    PRINTF("ERROR: MINIDRIVER IS WRONG !\n\r");
    PRINTF("Last address:%08x, Data:%08x\n\r", *( (volatile uint32_t *)( MCU_MINIDRIVER_END_ADDR - 4 ) ));
    update_state = UPDATE_STATE_SUSPEND;
    parser_status = PARSER_WICED_HCI;
    EW_notify_bt_fw_update_status( EnumBtFwStatusUPDATE_ABORT, sw_ver );
    return;
    }
else
    {
    PRINTF( "MINIDRIVER VERIFY DONE\r\n" );
    }

hci_recovery_reset_BT();

// send reset cmd
BT_UPDATE_standard_send_command( OPCODE_RESET, NULL, 0 );
vTaskDelay( pdMS_TO_TICKS( COMMON_CMD_WAIT_MS ) );

update_state = UPDATE_STATE_DOWNLOAD_MINIDRIVER;

// Initiate flash buffer address
flash_buf_info.write_addr = BT_FLASH_ADDR;
flash_buf_info.verify_addr = BT_FLASH_ADDR;
flash_buf_info.flash_end_addr = check_flash_end();
flash_buf_info.buffer_size = flash_buf_info.flash_end_addr - MCU_BTFLASH_ADDR;
download_flash_addr = MCU_BTFLASH_ADDR;
PRINTF( "Flash buffer size:0x%08x\n\r", flash_buf_info.buffer_size );

// Write  minidriver
// Initiate minidriver buffer address
md_buf_info.flash_end_addr = MCU_MINIDRIVER_END_ADDR;
md_buf_info.verify_addr = BT_MINIDRIVER_ADDR;
md_buf_info.write_addr = BT_MINIDRIVER_ADDR;
md_buf_info.buffer_size = MCU_MINIDRIVER_END_ADDR - MCU_MINIDRIVER_ADDR;
md_write_count = 0;
md_last_sec_size = md_buf_info.buffer_size - ( ( md_buf_info.buffer_size / MAX_UPDATE_DATA_LENGTH ) * MAX_UPDATE_DATA_LENGTH );

while( md_write_count < ( md_buf_info.buffer_size / MAX_UPDATE_DATA_LENGTH ) )
    {
    UINT32_to_UINT8_arry( md_buf_info.write_addr, &( write_md_cmd[0] ) );

    for( uint8_t i = 0; i < MAX_UPDATE_DATA_LENGTH; i += 4 )
        {
        addr_val_uint32 = *( (volatile uint32_t *)( bt_md_addr + i ) );
        UINT32_to_UINT8_arry( addr_val_uint32, &( write_md_cmd[4 + i] ) );
        }
    bt_md_addr += MAX_UPDATE_DATA_LENGTH;
    BT_UPDATE_standard_send_command( OPCODE_WRITERAM, write_md_cmd, sizeof( write_md_cmd ) );
    md_write_count++;
    md_buf_info.write_addr += MAX_UPDATE_DATA_LENGTH;
    vTaskDelay( pdMS_TO_TICKS( COMMON_CMD_WAIT_MS ) );
    }
// Write last sector minidriver
UINT32_to_UINT8_arry( md_buf_info.write_addr, &( write_md_cmd[0] ) );

for( uint8_t i = 0; i < md_last_sec_size; i += 4 )
    {
    addr_val_uint32 = *( (volatile uint32_t *)( bt_md_addr + i ) );
    UINT32_to_UINT8_arry( addr_val_uint32, &( write_md_cmd[4 + i] ) );
    }

BT_UPDATE_standard_send_command( OPCODE_WRITERAM, write_md_cmd, md_last_sec_size + 4 );
vTaskDelay( pdMS_TO_TICKS( COMMON_CMD_WAIT_MS ) );

md_verify_count = 0;

// Read first sector minidriver
UINT32_to_UINT8_arry( md_buf_info.verify_addr, &( read_ram_cmd[0] ) );
read_ram_cmd[4] = MAX_UPDATE_DATA_LENGTH;

BT_UPDATE_standard_send_command( OPCODE_READRAM, read_ram_cmd, 5 );
update_state = UPDATE_STATE_VERIFY_MINIDRIVER;
}

/*********************************************************************
*
* @public
* transmit an Standard HCI message
*
* This function formulates an Standard HCI message based on the packet ID and
* data.
*
* @return boolean
* error flag (true or false)
*
*********************************************************************/
BaseType_t BT_UPDATE_standard_send_command
    (
    const uint16_t command,
    const uint8_t* payload,
    const uint8_t  len
    )
{
uint8_t     data[HCI_STANDARD_HEADER_LENGTH + MAX_COMMAND_DATA_LENGTH];
uint16_t    totalLength = 0;
uint16_t    header  = 0;

memset( data, 0, sizeof( data ) );

// If command header byte is not set, return
if( command )
    {
    data[header++] = HCI_STANDARD_PKT;
    data[header++] = command & 0xff;
    data[header++] = (command >> 8) & 0xff;
    data[header++] = len;
    }
else
    {
    return false;
    }

if( ( len > 0 ) && ( MAX_COMMAND_DATA_LENGTH >= len )  )
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
    memcpy( &data[header], payload, MAX_COMMAND_DATA_LENGTH );
    totalLength = header + MAX_COMMAND_DATA_LENGTH;
    }

if( 0 == totalLength )
    return false;

return PERIPHERAL_uart_tx_data( totalLength, data );
}

/*********************************************************************
*
* @private
* Transfer the uint32_t to uint8 array
*
* This function copy the value of uint32_t to the input uint8 address
* on first 4 bytes
*
*********************************************************************/
void UINT32_to_UINT8_arry
    (
    const uint32_t var_uint32,
    uint8_t * uint8_arry
    )
{
uint8_arry[0] = (uint8_t)( var_uint32 & 0xff );
uint8_arry[1] = (uint8_t)( ( var_uint32 & 0xff00 ) >> 8 );
uint8_arry[2] = (uint8_t)( ( var_uint32 & 0xff0000 ) >> 16 );
uint8_arry[3] = (uint8_t)( ( var_uint32 & 0xff000000 ) >> 24 );
}
