/*!*******************************************************************
* @file ota.c
* @brief ota source file
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

#ifdef __cplusplus
extern "C"{
#endif

/*--------------------------------------------------------------------
                            GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "OTA_pub.h"

#include "FreeRTOS.h"
#include "task.h"
#include "fsl_debug_console.h"

#include "GRM_pub_prj.h"
#include "HCI_pub.h"
#include "fsl_lpuart.h"
#include "fsl_adc_etc.h"
#include "fsl_pit.h"
#include "fsl_xbara.h"
#include "fsl_lpi2c.h"
#include "fsl_flexio.h"
#include "display_support.h"
#include "fsl_dc_fb_lcdifv2.h"
/*--------------------------------------------------------------------
                            LITERAL CONSTANTS
--------------------------------------------------------------------*/
/*Stay in boot pattern related*/
#define BLD_STAY_IN_BOOT_PATTERN_LEN    16

#define OTA_UPDATE_INFO_PACKET_LEN    13

/*Bootloader starts at 0*/
#define MEM_BLD_START_ADDR          0x30000000

/*Software version data byte length*/
#define SW_VERSION_BYTE_LEN     2

/*Test SPP*/
#define OTA_TEST_SPP            0
/*--------------------------------------------------------------------
                            TYPES
--------------------------------------------------------------------*/
typedef __PACKED_STRUCT
    {
    uint8_t info_pattern[BLD_STAY_IN_BOOT_PATTERN_LEN];
    uint8_t ota_update_information_packet[OTA_UPDATE_INFO_PACKET_LEN];
    }ota_download_info_t;

/*--------------------------------------------------------------------
                            VARIABLES
--------------------------------------------------------------------*/
#if OTA_TEST_SPP
char ota_str[1000];
char hex2char[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
#endif

/*Stay in boot pattern*/
const uint8_t ota_stay_in_boot_pattern[BLD_STAY_IN_BOOT_PATTERN_LEN] =
    { 's', 't', 'a', 'y', 'i', 'n', 'b', 'o', 'o', 't', 'p', 'h', 'r', 'a', 's', 'e' };

uint32_t ota_task_counter;
uint32_t ota_test_task_counter;

__attribute__((section(".bss.$SRAM_OC2_NO_INIT"))) volatile ota_download_info_t ota_download_information;


bool ota_info_received = false;

#define DATA_STREAM_START_VAL 0x01
#define DATA_STREAM_ESC_VAL 0x55
#define DATA_STREAM_END_VAL 0x04

#define DATA_STREAM_HANDLE_STATE_WAIT_START 0x00
#define DATA_STREAM_HANDLE_STATE_WAIT_DATA 0x01
#define DATA_STREAM_HANDLE_STATE_WAIT_LEN 0x02
#define DATA_STREAM_HANDLE_STATE_WAIT_EOT 0x03

uint8_t data_stream_rcv_buf[5000];

bool data_stream_esc_received = false;
uint32_t data_stream_received_len;
uint8_t data_stream_state = DATA_STREAM_HANDLE_STATE_WAIT_START;

uint32_t data_stream_expected_len;
uint32_t data_stream_expected_len_byte_count;


/*--------------------------------------------------------------------
                            PROCEDURES
--------------------------------------------------------------------*/
/*!*******************************************************************
*
* @private
* ota task.
*
* ota task.
*
*********************************************************************/
void ota_task
    (
    void* arg
    )
{
while( 1 )
    {
    ota_task_counter++;
    vTaskDelay( pdMS_TO_TICKS( 10 ) );
    }
vTaskDelete( NULL );
}

void ota_stream_data_handle
    (
    uint8_t c
    )
{
#if 0
if( data_stream_state == DATA_STREAM_HANDLE_STATE_WAIT_START )
    {
    if( c == DATA_STREAM_START_VAL )
        {
        data_stream_state = DATA_STREAM_HANDLE_STATE_WAIT_DATA;
        data_stream_esc_received = false;
        data_stream_received_len = 0;
        }
    }
else if( data_stream_state == DATA_STREAM_HANDLE_STATE_WAIT_DATA )
    {
    if( c == DATA_STREAM_START_VAL )
        {
        if( data_stream_esc_received )
            {
            data_stream_rcv_buf[data_stream_received_len] = c;
            data_stream_received_len++;
            data_stream_esc_received = false;
            }
        else
            {
            data_stream_received_len = 0;
            }
        }
    else if( c == DATA_STREAM_ESC_VAL )
        {
        if( data_stream_esc_received )
            {
            data_stream_rcv_buf[data_stream_received_len] = c;
            data_stream_received_len++;
            data_stream_esc_received = false;
            }
        else
            {
            data_stream_esc_received = true;
            }
        }
    else if( c == DATA_STREAM_END_VAL )
        {
        if( data_stream_esc_received )
            {
            data_stream_rcv_buf[data_stream_received_len] = c;
            data_stream_received_len++;
            data_stream_esc_received = false;
            }
        else
            {
            if( data_stream_received_len!= 0 )
                {
                if( data_stream_received_len <= 512 )
                    {
                    if( data_stream_rcv_buf[0] == 0x01 && data_stream_rcv_buf[1] == 0x22 && data_stream_received_len >= 13 )
                        {
                        ota_set_update_packet(data_stream_rcv_buf);
                        }
                    }
                }
            data_stream_state = DATA_STREAM_HANDLE_STATE_WAIT_START;
            }
        }
    else
        {
        if( data_stream_esc_received )
            {
            data_stream_state = DATA_STREAM_HANDLE_STATE_WAIT_START;
            }
        else
            {
            data_stream_rcv_buf[data_stream_received_len] = c;
            data_stream_received_len++;
            }
        }
    }
else
    {
    data_stream_state = DATA_STREAM_HANDLE_STATE_WAIT_START;
    }
#endif

if( data_stream_state == DATA_STREAM_HANDLE_STATE_WAIT_START )
    {
    if( c == DATA_STREAM_START_VAL )
        {
        data_stream_state = DATA_STREAM_HANDLE_STATE_WAIT_LEN;
        data_stream_expected_len = 0;
        data_stream_expected_len_byte_count = 4;
        data_stream_received_len = 0;
        }
    }
else if( data_stream_state == DATA_STREAM_HANDLE_STATE_WAIT_LEN )
    {
    data_stream_expected_len = (data_stream_expected_len << 8) + c;
    data_stream_expected_len_byte_count -= 1;
    if( data_stream_expected_len_byte_count == 0 )
        {
        data_stream_state = DATA_STREAM_HANDLE_STATE_WAIT_DATA;
        }
    }
else if( data_stream_state == DATA_STREAM_HANDLE_STATE_WAIT_DATA )
    {
    data_stream_rcv_buf[data_stream_received_len] = c;
    data_stream_received_len += 1;
    if( data_stream_received_len >= data_stream_expected_len )
        {
        data_stream_state = DATA_STREAM_HANDLE_STATE_WAIT_EOT;
        }
    }
else if( data_stream_state == DATA_STREAM_HANDLE_STATE_WAIT_EOT )
    {
    if( c != DATA_STREAM_END_VAL )
        {
        PRINTF("MOTOCON EOT not received!");
        }
    data_stream_state = DATA_STREAM_HANDLE_STATE_WAIT_START;
    if( data_stream_received_len!= 0 )
        {
        if( data_stream_received_len <= 512 )
            {
            if( data_stream_rcv_buf[0] == 0x01 && data_stream_rcv_buf[1] == 0x22 && data_stream_received_len >= 13 )
                {
                OTA_set_update_packet(
                    data_stream_rcv_buf[2],
                    ( data_stream_rcv_buf[3] << 8 ) + data_stream_rcv_buf[4],
                    ( data_stream_rcv_buf[5] << 24 ) + ( data_stream_rcv_buf[6]  << 16 ) + ( data_stream_rcv_buf[7] << 8 ) + data_stream_rcv_buf[8],
                    ( data_stream_rcv_buf[9] << 24 ) + ( data_stream_rcv_buf[10]  << 16 ) + ( data_stream_rcv_buf[11] << 8 ) + data_stream_rcv_buf[12]
                    );
                }
            }
        }
    }
else
    {
    data_stream_state = DATA_STREAM_HANDLE_STATE_WAIT_START;
    }

}


/*!*******************************************************************
*
* @private
* SPP signal callback.
*
* SPP signal callback for test purpose.
*
*********************************************************************/
#if OTA_TEST_SPP
void ota_bt_cbk
    (
    const uint8_t* data,
    const uint16_t length
    )
{
uint32_t i;

for( i = 0; i < length; i++ )
    {
    ota_stream_data_handle( data[i] );
    ota_str[3*i] = hex2char[data[i]/16];
    ota_str[3*i+1] = hex2char[data[i]%16];
    ota_str[3*i+2] = ' ';
    }
ota_str[3*i] = '\0';

PRINTF( "SPP receive data:%s\r\n", ota_str );
}
#endif
void ota_create_task
    (
    void
    )
{
if( pdPASS == xTaskCreate( ota_task, "ota_task", ( 256 ), NULL, TASK_PRIO_IDLE, NULL ) )
    {
    PRINTF("%s ok\r\n", __FUNCTION__ );
    }
else
    {
    PRINTF("%s fail\r\n", __FUNCTION__ );
    }

#if OTA_TEST_SPP
    HCI_spp_iap2_add_data_callback( ota_bt_cbk );
#endif

}

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
    )
{
ota_create_task();
}

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
    )
{
ota_info_received = true;

/*Construct to the origin signal data OTA UPDATE INFORMATION (WRITE)
Byte No   Length  Detail
0~1       2       command code Fixed 0x0122
2         1       enable
3~4       2       new firmware version
5~8       4       total size
9~12      4       number of packages
*/

ota_download_information.ota_update_information_packet[0] = 0x01;
ota_download_information.ota_update_information_packet[1] = 0x22;
ota_download_information.ota_update_information_packet[2] = enable ? 0x01:0x00;
ota_download_information.ota_update_information_packet[3] = ( new_firmware_ver >> 8 ) & 0xFF;
ota_download_information.ota_update_information_packet[4] = ( new_firmware_ver >> 0 ) & 0xFF;
ota_download_information.ota_update_information_packet[5] = ( total_size >> 24 ) & 0xFF;
ota_download_information.ota_update_information_packet[6] = ( total_size >> 16 ) & 0xFF;
ota_download_information.ota_update_information_packet[7] = ( total_size >> 8 ) & 0xFF;
ota_download_information.ota_update_information_packet[8] = ( total_size >> 0 ) & 0xFF;
ota_download_information.ota_update_information_packet[9] = ( number_of_packages >> 24 ) & 0xFF;
ota_download_information.ota_update_information_packet[10] = ( number_of_packages >> 16 ) & 0xFF;
ota_download_information.ota_update_information_packet[11] = ( number_of_packages >> 8 ) & 0xFF;
ota_download_information.ota_update_information_packet[12] = ( number_of_packages >> 0 ) & 0xFF;

}

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
    )
{

/*Fill the pattern*/
DisableGlobalIRQ();

/*Shutdown app*/
LPUART_Deinit( LPUART7 );

ADC_ETC_Deinit( ADC_ETC );
PIT_Deinit( PIT1 );
XBARA_Deinit( XBARA1 );
LPI2C_MasterDeinit( LPI2C1 );
FLEXIO_Deinit( FLEXIO2 );
DC_FB_LCDIFV2_Deinit( &g_dc );

memcpy( ota_download_information.info_pattern, ota_stay_in_boot_pattern, BLD_STAY_IN_BOOT_PATTERN_LEN );
if( !ota_info_received )
    {
    memset( ota_download_information.ota_update_information_packet, 0, OTA_UPDATE_INFO_PACKET_LEN );
    }


#if ( OTA_ENTER_BOOTLOADER_METHOD == OTA_ENTER_BOOTLOADER_BY_RESET )
    __NVIC_SystemReset();
#elif ( OTA_ENTER_BOOTLOADER_METHOD == OTA_ENTER_BOOTLOADER_BY_JUMPING )
    __set_MSP( *(uint32_t*)( MEM_BLD_START_ADDR + 0x2000 ) );
    __set_CONTROL(0);
    ((void (*)(void))( *(uint32_t*)( MEM_BLD_START_ADDR + 0x2004 ) ))();
#else
    #error "Invalid enter bootloader mode is selected"
#endif

while( 1 );
}

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
    )
{
if( FLEXSPI1->HADDRSTART & FLEXSPI_HADDRSTART_REMAPEN_MASK )
    {
    return OTA_SYS_PARTITION_B;
    }

/*System will run in paritition A in default*/
return OTA_SYS_PARTITION_A;
}

#ifdef __cplusplus
}
#endif
