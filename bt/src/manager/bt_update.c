/*********************************************************************
* @file  bt_update.h
* @brief Bluetooth Manager Firmware Update interface definition.
*
* Copyright 2021 by Garmin Ltd. or its subsidiaries.
*********************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                        GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <FreeRTOS.h>
#include <task.h>
#include <string.h>

#include "bt_hw.h"
#include "bt_log.h"
#include "bt_tsk.h"
#include "bt_update.h"
#include "bt_utils.h"
#include "hci_cmd.h"

extern uint32_t __base_BOARD_FLASH_BTFW;

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
#define MCU_FLASH_BT_FW_ADDR      ( (uint32_t)( &__base_BOARD_FLASH_BTFW ) )
#define MCU_FLASH_BT_VERSION_ADDR ( MCU_FLASH_BT_FW_ADDR )
#define MCU_FLASH_BT_MD_SIZE_ADDR ( MCU_FLASH_BT_VERSION_ADDR + 2 )
#define MCU_FLASH_BT_SS_SIZE_ADDR ( MCU_FLASH_BT_MD_SIZE_ADDR + 2 )
#define MCU_FLASH_BT_DS_SIZE_ADDR ( MCU_FLASH_BT_SS_SIZE_ADDR + 2 )
#define MCU_FLASH_BT_MD_DATA_ADDR ( MCU_FLASH_BT_FW_ADDR + 0x00000100 )
#define MCU_FLASH_BT_SS_DATA_ADDR ( MCU_FLASH_BT_FW_ADDR + 0x0000ec00 )
#define MCU_FLASH_BT_DS_DATA_ADDR ( MCU_FLASH_BT_FW_ADDR + 0x00010000 )

#define CYW_FLASH_BT_MD_DATA_ADDR ( 0x00270400 )
#define CYW_FLASH_BT_SS_DATA_ADDR ( 0x00500000 )
#define CYW_FLASH_BT_DS_DATA_ADDR ( 0x00501400 )

#define CYW_FLASH_CHIP_ERASE_MAGIC_ADDR ( 0xFCBEEEEF )
#define CYW_FLASH_LAUNCH_FW_MAGIC_ADDR  ( 0x00000000 )

#define COMMAND_COMPLETED_MS ( 3000 )

#define FIRMWARE_UPDATE_RETRY_MAX_TIMES ( 3 )

/*--------------------------------------------------------------------
                        VARIABLES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                        PROTOTYPES
--------------------------------------------------------------------*/
static bool BT_update_download
    (
    const char* data_name,
    uint32_t mcu_src_addr,
    uint32_t cyw_dest_addr,
    const uint32_t data_size
    );

static bool BT_update_download_data_section( void );

static bool BT_update_download_minidriver( void );

static bool BT_update_download_static_section( void );

static bool BT_update_enter_download_mode( void );

static bool BT_update_erase_chip( void );

static bool BT_update_launch
    (
    const uint32_t cyw_dest_addr
    );

static bool BT_update_launch_firmware( void );

static bool BT_update_launch_minidriver( void );

static bool BT_update_use_3m_uart_baudrate( void );

static bool BT_update_verify
    (
    const char* data_name,
    uint32_t mcu_src_addr,
    uint32_t cyw_dest_addr,
    const uint32_t data_size
    );

static bool BT_update_verify_data_section( void );

static bool BT_update_verify_static_section( void );

/*--------------------------------------------------------------------
                        PROCEDURES
--------------------------------------------------------------------*/
/*================================================================================================
@brief   Download the data stored in MCU to Cypress module
@details Download the data stored in MCU to Cypress module using HCI Write RAM command
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
static bool BT_update_download
    (
    const char* data_name,
    uint32_t mcu_src_addr,
    uint32_t cyw_dest_addr,
    const uint32_t data_size
    )
{
bool ret = true;
uint32_t data_bytes_each_write = BT_WRITE_RAM_MAX_SIZE;
uint32_t num_writes = 0;
uint32_t written_bytes = 0;
uint32_t mcu_src_addr_val = 0;
uint8_t param[HCI_PAYLOAD_MAX_SIZE] = { 0 };
BT_sync_event_t sync_event = { BT_SYNC_EVENT_WRITE_RAM_COMPLETED, { { 0 } } };

num_writes = data_size / data_bytes_each_write;
if( ( data_size % data_bytes_each_write ) > 0 )
    {
    ++num_writes;
    }

for( uint32_t i = 0; i < num_writes; ++i )
    {
    BT_LOG_DEBUG( "Firmware update: Writing %s: %u of %u bytes...", data_name, written_bytes, data_size );

    // Handle last write
    if( i == ( num_writes - 1 ) )
        {
        if( ( data_size - written_bytes ) < data_bytes_each_write )
            {
            data_bytes_each_write = data_size - written_bytes;
            }
        }

    memset( param, 0, sizeof( param ) );
    INT32_TO_LITTLE_ENDIAN( cyw_dest_addr, &( param[0] ) );
    for( uint8_t j = 0; j < data_bytes_each_write; j += 4 )
        {
        mcu_src_addr_val = *( (volatile uint32_t*)( mcu_src_addr + j ) );
        INT32_TO_LITTLE_ENDIAN( mcu_src_addr_val, &( param[4 + j] ) );
        }

    if( ( false == HCI_send_standard_command( HCI_STANDARD_COMMAND_WRITE_RAM, param, ( data_bytes_each_write + 4 ) ) ) ||
        ( false == BT_tsk_sync_wait( &sync_event, COMMAND_COMPLETED_MS ) ) ||
        ( HCI_SUCCESS != sync_event.param_u.write_ram_completed.error_code ) )
        {
        ret = false;
        break;
        }

    mcu_src_addr += data_bytes_each_write;
    cyw_dest_addr += data_bytes_each_write;
    written_bytes += data_bytes_each_write;
    }
return ret;
}

/*================================================================================================
@brief   Download the data section of BT firmware stored in MCU to Cypress module
@details Download the data section of BT firmware stored in MCU to Cypress module
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
static bool BT_update_download_data_section( void )
{
bool ret = false;
uint32_t bt_ds_size = ( *(volatile uint8_t*)( MCU_FLASH_BT_DS_SIZE_ADDR + 0 ) << 24 ) +
                      ( *(volatile uint8_t*)( MCU_FLASH_BT_DS_SIZE_ADDR + 1 ) << 16 ) +
                      ( *(volatile uint8_t*)( MCU_FLASH_BT_DS_SIZE_ADDR + 2 ) <<  8 ) +
                      ( *(volatile uint8_t*)( MCU_FLASH_BT_DS_SIZE_ADDR + 3 ) <<  0 );

BT_LOG_INFO( "Firmware update: Download Data Section: MCU_addr=0x%08x, CYW_addr=0x%08x, data_size=%u bytes",
             MCU_FLASH_BT_DS_DATA_ADDR,
             CYW_FLASH_BT_DS_DATA_ADDR,
             bt_ds_size );

ret = BT_update_download( "Data Section", MCU_FLASH_BT_DS_DATA_ADDR, CYW_FLASH_BT_DS_DATA_ADDR, bt_ds_size );

if( ret )
    {
    BT_LOG_INFO( "Firmware update: Download Data Section: OK" );
    }
else
    {
    BT_LOG_ERROR( "Firmware update: Download Data Section: Failed" );
    }
return ret;
}

/*================================================================================================
@brief   Download the Minidriver stored in MCU to Cypress module
@details Download the Minidriver stored in MCU to Cypress module
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
static bool BT_update_download_minidriver( void )
{
bool ret = false;
uint16_t bt_md_size = ( *(volatile uint8_t*)( MCU_FLASH_BT_MD_SIZE_ADDR + 0 ) << 8 ) +
                      ( *(volatile uint8_t*)( MCU_FLASH_BT_MD_SIZE_ADDR + 1 ) << 0 );

BT_LOG_INFO( "Firmware update: Download Minidriver: MCU_addr=0x%08x, CYW_addr=0x%08x, data_size=%u bytes",
             MCU_FLASH_BT_MD_DATA_ADDR,
             CYW_FLASH_BT_MD_DATA_ADDR,
             bt_md_size );

ret = BT_update_download( "Minidriver", MCU_FLASH_BT_MD_DATA_ADDR, CYW_FLASH_BT_MD_DATA_ADDR, bt_md_size );

if( ret )
    {
    BT_LOG_INFO( "Firmware update: Download Minidriver: OK" );
    }
else
    {
    BT_LOG_ERROR( "Firmware update: Download Minidriver: Failed" );
    }
return ret;
}

/*================================================================================================
@brief   Download the static section of BT firmware stored in MCU to Cypress module
@details Download the static section of BT firmware stored in MCU to Cypress module
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
static bool BT_update_download_static_section( void )
{
bool ret = false;
uint16_t bt_ss_size = ( *(volatile uint8_t*)( MCU_FLASH_BT_SS_SIZE_ADDR + 0 ) << 8 ) +
                      ( *(volatile uint8_t*)( MCU_FLASH_BT_SS_SIZE_ADDR + 1 ) << 0 );

BT_LOG_INFO( "Firmware update: Download Static Station: MCU_addr=0x%08x, CYW_addr=0x%08x, data_size=%u bytes",
             MCU_FLASH_BT_SS_DATA_ADDR,
             CYW_FLASH_BT_SS_DATA_ADDR,
             bt_ss_size );

ret = BT_update_download( "Static Section", MCU_FLASH_BT_SS_DATA_ADDR, CYW_FLASH_BT_SS_DATA_ADDR, bt_ss_size );

if( ret )
    {
    BT_LOG_INFO( "Firmware update: Download Static Station: OK" );
    }
else
    {
    BT_LOG_ERROR( "Firmware update: Download Static Station: Failed" );
    }
return ret;
}

/*================================================================================================
@brief   Make Cypress module enter Download mode
@details Make Cypress module enter Download mode
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
static bool BT_update_enter_download_mode( void )
{
bool ret = false;
BT_sync_event_t sync_event = { BT_SYNC_EVENT_RESET_COMPLETED, { { 0 } } };

if( ( BT_hw_off() ) &&
    ( BT_hw_on( BT_HW_MODE_DOWNLOAD ) ) &&
    ( HCI_send_standard_command( HCI_STANDARD_COMMAND_RESET, NULL, 0 ) ) &&
    ( BT_tsk_sync_wait( &sync_event, COMMAND_COMPLETED_MS ) ) &&
    ( HCI_SUCCESS == sync_event.param_u.reset_completed.error_code ) )
    {
    ret = true;
    }

if( ret )
    {
    BT_LOG_INFO( "Firmware update: Enter download mode: OK" );
    }
else
    {
    BT_LOG_ERROR( "Firmware update: Enter download mode: Failed" );
    }
return ret;
}

/*================================================================================================
@brief   Erase the whole non-volatile memory of Cypress module
@details Use the special value of memory address to erase the whole non-volatile memory of Cypress
         module
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
static bool BT_update_erase_chip( void )
{
bool ret = false;
uint8_t param[4] = { 0 };
BT_sync_event_t sync_event = { BT_SYNC_EVENT_CHIP_ERASE_COMPLETED, { { 0 } } };

INT32_TO_LITTLE_ENDIAN( CYW_FLASH_CHIP_ERASE_MAGIC_ADDR, &( param[0] ) );

if( ( HCI_send_standard_command( HCI_STANDARD_COMMAND_CHIP_ERASE, param, sizeof( param ) ) ) &&
    ( BT_tsk_sync_wait( &sync_event, COMMAND_COMPLETED_MS ) ) &&
    ( HCI_SUCCESS == sync_event.param_u.chip_erase_completed.error_code ) )
    {
    ret = true;
    }

if( ret )
    {
    BT_LOG_INFO( "Firmware update: Chip erase: OK" );
    }
else
    {
    BT_LOG_ERROR( "Firmware update: Chip erase: Failed" );
    }
return ret;
}

/*================================================================================================
@brief   Get Bluetooth Manager's software version
@details Get Bluetooth Manager's software version
@return  major_version: The major version
         minor_version: The minor version
@retval  Whether or not the operation is successful
================================================================================================*/
bool BT_update_get_sw_version
    (
    uint8_t* major_version,
    uint8_t* minor_version
    )
{
bool ret = false;

if( ( NULL == major_version ) || ( NULL == minor_version ) )
    {
    BT_LOG_DEBUG( "NULL version" );
    }
else
    {
    *major_version = *( (volatile uint8_t*)( MCU_FLASH_BT_VERSION_ADDR + 0 ) );
    *minor_version = *( (volatile uint8_t*)( MCU_FLASH_BT_VERSION_ADDR + 1 ) );
    ret = true;
    }
return ret;
}

/*================================================================================================
@brief   Check whether or not MCU has newer firmware for Cypress module to update
@details Check the software version sent from Cypress module to know whether or not MCU has newer
         firmware for Cypress module to update
@return  None
@retval  Whether or not MCU has newer firmware for Cypress module to update
================================================================================================*/
bool BT_update_has_newer_firmware
    (
    const uint8_t cyw_major_version,
    const uint8_t cyw_minor_version
    )
{
uint8_t mcu_major_version = *( (volatile uint8_t*)( MCU_FLASH_BT_VERSION_ADDR + 0 ) );
uint8_t mcu_minor_version = *( (volatile uint8_t*)( MCU_FLASH_BT_VERSION_ADDR + 1 ) );
bool has_newer_version = ( ( mcu_major_version << 8 ) + mcu_minor_version ) > ( ( cyw_major_version << 8 ) + cyw_minor_version );

if( has_newer_version )
    {
    BT_LOG_INFO( "Firmware update required: MCU=v%u.%02u is newer than CYW=v%u.%02u",
                 mcu_major_version,
                 mcu_minor_version,
                 cyw_major_version,
                 cyw_minor_version );
    }
return has_newer_version;
}

/*================================================================================================
@brief   Launch the downloaded program to run on Cypress module
@details Launch the downloaded program to run on Cypress module using HCI Launch RAM command
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
static bool BT_update_launch
    (
    const uint32_t cyw_dest_addr
    )
{
bool ret = false;
uint8_t param[4] = { 0 };
BT_sync_event_t sync_event = { BT_SYNC_EVENT_LAUNCH_RAM_COMPLETED, { { 0 } } };

INT32_TO_LITTLE_ENDIAN( cyw_dest_addr, &( param[0] ) );

if( ( HCI_send_standard_command( HCI_STANDARD_COMMAND_LAUNCH_RAM, param, sizeof( param ) ) ) &&
    ( BT_tsk_sync_wait( &sync_event, COMMAND_COMPLETED_MS ) ) &&
    ( HCI_SUCCESS == sync_event.param_u.launch_ram_completed.error_code ) )
    {
    ret = true;
    }
return ret;
}

/*================================================================================================
@brief   Launch the downloaded Minidriver to run on Cypress module
@details Launch the downloaded Minidriver to run on Cypress module
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
static bool BT_update_launch_minidriver( void )
{
bool ret = BT_update_launch( CYW_FLASH_BT_MD_DATA_ADDR );

if( ret )
    {
    BT_LOG_INFO( "Firmware update: Launch Minidriver: OK" );
    }
else
    {
    BT_LOG_ERROR( "Firmware update: Launch Minidriver: Failed" );
    }
return ret;
}

/*================================================================================================
@brief   Launch the downloaded firmware to run on Cypress module
@details Launch the downloaded firmware to run on Cypress module
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
static bool BT_update_launch_firmware( void )
{
bool ret = BT_update_launch( CYW_FLASH_LAUNCH_FW_MAGIC_ADDR );

if( ret )
    {
    BT_LOG_INFO( "Firmware update: Launch Firmware: OK" );
    }
else
    {
    BT_LOG_ERROR( "Firmware update: Launch Firmware: Failed" );
    }
return ret;
}

/*================================================================================================
@brief   Change to use 3M UART baudrate to speed up the following firmware update process
@details Change to use 3M UART baudrate to speed up the following firmware update process
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
static bool BT_update_use_3m_uart_baudrate( void )
{
bool ret = false;
uint8_t param[2 + 4] = { 0 };
uint32_t baudrate = 3000000;
BT_sync_event_t sync_event = { BT_SYNC_EVENT_UPDATE_BAUDRATE_COMPLETED, { { 0 } } };

INT16_TO_LITTLE_ENDIAN( 0, &( param[0] ) );
INT32_TO_LITTLE_ENDIAN( baudrate, &( param[2] ) );

if( ( HCI_send_standard_command( HCI_STANDARD_COMMAND_UPDATE_BAUDRATE, param, sizeof( param ) ) ) &&
    ( BT_tsk_sync_wait( &sync_event, COMMAND_COMPLETED_MS ) ) &&
    ( HCI_SUCCESS == sync_event.param_u.update_baudrate_completed.error_code ) )
    {
    ret = true;
    }

if( ret )
    {
    ret = BT_hw_config_uart( true, BT_UART_BAUDRATE_3M );
    }

if( ret )
    {
    BT_LOG_INFO( "Firmware update: Use 3M UART baudrate: OK" );
    }
else
    {
    BT_LOG_ERROR( "Firmware update: Use 3M UART baudrate: Failed" );
    }
return ret;
}

/*================================================================================================
@brief   Verify whether or not the data downloaded to Cypress module is correct
@details Verify whether or not the data downloaded to Cypress module is correct using HCI Read RAM
         command
@return  None
@retval  Whether or not the data downloaded to Cypress module is correct
================================================================================================*/
static bool BT_update_verify
    (
    const char* data_name,
    uint32_t mcu_src_addr,
    uint32_t cyw_dest_addr,
    const uint32_t data_size
    )
{
bool ret = true;
uint32_t data_bytes_each_read = BT_READ_RAM_MAX_SIZE;
uint32_t num_reads = 0;
uint32_t read_bytes = 0;
uint8_t param[4 + 1] = { 0 };
BT_sync_event_t sync_event = { BT_SYNC_EVENT_READ_RAM_COMPLETED, { { 0 } } };

num_reads = data_size / data_bytes_each_read;
if( ( data_size % data_bytes_each_read ) > 0 )
    {
    ++num_reads;
    }

for( uint32_t i = 0; i < num_reads; ++i )
    {
    BT_LOG_DEBUG( "Firmware update: Verifying %s: %u of %u bytes...", data_name, read_bytes, data_size );

    // Handle last read
    if( i == ( num_reads - 1 ) )
        {
        if( ( data_size - read_bytes ) < data_bytes_each_read )
            {
            data_bytes_each_read = data_size - read_bytes;
            }
        }

    INT32_TO_LITTLE_ENDIAN( cyw_dest_addr, &( param[0] ) );
    param[4] = data_bytes_each_read;

    if( ( false == HCI_send_standard_command( HCI_STANDARD_COMMAND_READ_RAM, param, sizeof( param ) ) ) ||
        ( false == BT_tsk_sync_wait( &sync_event, COMMAND_COMPLETED_MS ) ) ||
        ( HCI_SUCCESS != sync_event.param_u.read_ram_completed.error_code ) ||
        ( data_bytes_each_read != sync_event.param_u.read_ram_completed.data_len ) ||
        ( 0 != memcmp( (uint32_t*)mcu_src_addr, sync_event.param_u.read_ram_completed.data, data_bytes_each_read ) ) )
        {
        ret = false;
        break;
        }

    mcu_src_addr += data_bytes_each_read;
    cyw_dest_addr += data_bytes_each_read;
    read_bytes += data_bytes_each_read;
    }
return ret;
}

/*================================================================================================
@brief   Verify whether or not the data section downloaded to Cypress module is correct
@details Verify whether or not the data section downloaded to Cypress module is correct
@return  None
@retval  Whether or not the data section downloaded to Cypress module is correct
================================================================================================*/
static bool BT_update_verify_data_section( void )
{
bool ret = false;
uint32_t bt_ds_size = ( *(volatile uint8_t*)( MCU_FLASH_BT_DS_SIZE_ADDR + 0 ) << 24 ) +
                      ( *(volatile uint8_t*)( MCU_FLASH_BT_DS_SIZE_ADDR + 1 ) << 16 ) +
                      ( *(volatile uint8_t*)( MCU_FLASH_BT_DS_SIZE_ADDR + 2 ) <<  8 ) +
                      ( *(volatile uint8_t*)( MCU_FLASH_BT_DS_SIZE_ADDR + 3 ) <<  0 );

ret = BT_update_verify( "Data Section", MCU_FLASH_BT_DS_DATA_ADDR, CYW_FLASH_BT_DS_DATA_ADDR, bt_ds_size );

if( ret )
    {
    BT_LOG_INFO( "Firmware update: Verify Data Section: OK" );
    }
else
    {
    BT_LOG_ERROR( "Firmware update: Verify Data Section: Failed" );
    }
return ret;
}

/*================================================================================================
@brief   Verify whether or not the static section downloaded to Cypress module is correct
@details Verify whether or not the static section downloaded to Cypress module is correct
@return  None
@retval  Whether or not the static section downloaded to Cypress module is correct
================================================================================================*/
static bool BT_update_verify_static_section( void )
{
bool ret = false;
uint16_t bt_ss_size = ( *(volatile uint8_t*)( MCU_FLASH_BT_SS_SIZE_ADDR + 0 ) << 8 ) +
                      ( *(volatile uint8_t*)( MCU_FLASH_BT_SS_SIZE_ADDR + 1 ) << 0 );

ret = BT_update_verify( "Static Section", MCU_FLASH_BT_SS_DATA_ADDR, CYW_FLASH_BT_SS_DATA_ADDR, bt_ss_size );

if( ret )
    {
    BT_LOG_INFO( "Firmware update: Verify Static Section: OK" );
    }
else
    {
    BT_LOG_ERROR( "Firmware update: Verify Static Section: Failed" );
    }
return ret;
}

/*================================================================================================
@brief   Start downloading the firmware stored in MCU to Cypress module to update
@details This is the process of firmware update of Cypress module that step by step downloads the
         firmware stored in MCU to Cypress module
@return  None
@retval  Whether or not the operation is successful
================================================================================================*/
bool BT_update_start( void )
{
bool ret = false;
uint8_t retry_times = 0;

// TODO: Notify HMI the update progress and result

while( ( false == ret ) && ( retry_times < FIRMWARE_UPDATE_RETRY_MAX_TIMES ) )
    {
    BT_LOG_INFO( "Firmware update: Start: retry_times=%u", retry_times );
    ++retry_times;

    if( ( BT_update_enter_download_mode() ) &&
        ( BT_update_download_minidriver() ) &&
        ( BT_update_launch_minidriver() ) &&
        ( BT_update_use_3m_uart_baudrate() ) &&
        ( BT_update_erase_chip() ) &&
        ( BT_update_download_static_section() ) &&
        ( BT_update_verify_static_section() ) &&
        ( BT_update_download_data_section() ) &&
        ( BT_update_verify_data_section() ) &&
        ( BT_update_launch_firmware() ) )
        {
        BT_LOG_INFO( "Firmware update: Completed successfully!" );
        ret = true;
        }
    }
return ret;
}

#ifdef __cplusplus
}
#endif
