/*********************************************************************
*
*   HEADER NAME:
*       IOP_pub_inst.h - Input/Output Processing Public Declarations
*
* Copyright 2001-2020 by Garmin Ltd. or its subsidiaries.
*
*********************************************************************/

#ifndef IOP_PUB_INST_H
#define IOP_PUB_INST_H

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------
                          LITERAL CONSTANTS
--------------------------------------------------------------------*/
typedef uint16_t IOP_inst_id_type; enum
    {
    IOP_EXTENDED_ID             =   0,

    /*------------------------------------------------------
    the following address symbols are used as indexes and
    must be equal to their indicated values
    ------------------------------------------------------*/

    IOP_ADDR0_DATA              =   0,
    IOP_ADDR1_DATA              =   1,
    IOP_ADDR2_DATA              =   2,

    /*------------------------------------------------------
    the following symbols are used to meet input/output
    protocol requirements and must be equal to their
    indicated values
    ------------------------------------------------------*/

    IOP_STX_BYTE                =   2,
    IOP_ETX_BYTE                =   3,
    IOP_ACK_BYTE                =   6,
    IOP_DLE_BYTE                =  16,
    IOP_NAK_BYTE                =  21,

    /*------------------------------------------------------
    the following symbol values need only be unique
    ------------------------------------------------------*/

    IOP_ADDR_DATA               =   4,
    IOP_ASIC_STAT_DATA          =   5,

    IOP_BBP_DATA                =   7,
    IOP_BREAK_DATA              =   8,
    IOP_SYC_UNITS_DATA          =   9,
    IOP_CMND_DATA               =  10,
    IOP_CNTRST_DATA             =  11,
    IOP_DL_CMPLT                =  12,
    IOP_EVNT_DATA               =  13,
    IOP_HWM_TIME_DATA           =  14,
    IOP_LIGHT_DATA              =  15,

    IOP_POSN_DATA               =  17,
    IOP_PREP_DATA               =  18,
    IOP_PRX_WPT_DATA            =  19,
    IOP_PVT_DATA                =  20,

    IOP_PVT_SV_DATA             =  22,
    IOP_PVT_UNCRT_DATA          =  23,
    IOP_DATA_LOST_DATA          =  24,
    IOP_RCV_DATA                =  25,
    IOP_RCV_MNTR_DATA           =  26,
    IOP_RECORDS                 =  27,
    IOP_RQST_DATA               =  28,
    IOP_RTE_IDX                 =  29,
    IOP_RTE_WPT_DATA            =  30,
    IOP_SPC_ALM_DATA            =  31,
    IOP_SW_VRSN_DATA            =  32,
    IOP_TONE_DATA               =  33,
    IOP_TRK_DATA                =  34,
    IOP_WPT_DATA                =  35,

    /*------------------------------------------------------
    the following symbols were added after initial
    production and are not in alphabetical order
    ------------------------------------------------------*/

    IOP_RGN_DATA                    =  36,
    IOP_FLASH_SMRY_DATA             =  37,
    IOP_UNIT_ID_DATA                =  38,
    IOP_TEMP_DATA                   =  39,
    IOP_VOLT_DATA                   =  40,
    IOP_RCV_SAT_DATA                =  41,
    IOP_RCV_INDX_DATA               =  42,

    IOP_PGM_START                   =  43,  /********************************/
    IOP_PGM_DATA                    =  44,  /* old program upload,          */
    IOP_PGM_DONE                    =  45,  /* don't use anymore            */
    IOP_PGM_ERROR                   =  46,  /********************************/

    IOP_RGN_CMPLT                   =  45,  /* same as IOP_pgm_done         */

    IOP_SYC_MODE_DATA               =  47,
    IOP_BAUD_RQST_DATA              =  48,
    IOP_BAUD_ACPT_DATA              =  49,
    IOP_ROM_FAIL_DATA               =  50,  /* don't use, use ram_test event*/
    IOP_CPO_PVT_DATA                =  51,
    IOP_CPO_RCV_DATA                =  52,
    IOP_SPC_EPH_DATA                =  53,
    IOP_RCV_NAV_DATA                =  54,
    IOP_RCV_PREP_DATA               =  55,
    IOP_RCV_MEAS_DATA               =  56,
    IOP_RCV_TOI_DATA                =  57,
    IOP_KEY_SCAN_DATA               =  58,
    IOP_SONR_DATA                   =  59,
    IOP_EEPRM_FAIL_DATA             =  60,
    IOP_COM_FREQ_DATA               =  61,
    IOP_COM_POLE_DATA               =  62,
    IOP_COM_XMTR_DATA               =  63,
    IOP_COM_VOL_DATA                =  64,
    IOP_NVOL_DATA                   =  65,  /* nonvol data              */
    IOP_FNVOL_DATA                  =  66,  /* far nonvol data          */
    IOP_STR_DATA                    =  67,
    IOP_COM_SQLCH_DATA              =  68,
    IOP_BMP_DATA                    =  69,
    IOP_CHNL_DATA                   =  70,
    IOP_PVT_CDP_DATA                =  71,
    IOP_TEST_RSLT_DATA              =  72,
    IOP_SET_DAC_DATA                =  73,

    IOP_RGN_STATUS                  =  74,  /* status return                */
    IOP_RGN_STRT_RX                 =  75,  /* includes DBM region specifier*/

    IOP_READ_FLASH                  =  76,
    IOP_GRP_IDX                     =  77,
    IOP_GRP_CHN_DATA                =  78,
    IOP_TUNE_CHN                    =  79,
    IOP_ALM_ID_DATA                 =  80,
    IOP_RTC_STAT_DATA               =  81,
    IOP_RGN_TEST                    =  82,  /* data is DBM_data_rgn_type    */
    IOP_RGN_MEM_CMP_RSLT            =  83,  /* memory compare results       */
    IOP_CEL_DATA                    =  84,  /* cellular unit data           */
    IOP_CLONE_DATA                  =  85,
    IOP_RTCM_DATA                   =  86,

    IOP_SONR_PRODUCT                =  87,
    IOP_SONR_CMND_DATA              =  88,

    IOP_GFTP_RQST                   =  89,
    IOP_GFTP_DATA                   =  90,
    IOP_GFTP_ACCEPT                 =  91,
    IOP_GFTP_ERROR                  =  92,

    IOP_CEL_RQST_DATA               =  93,
    IOP_CEL_INST_DATA               =  94,

    IOP_GMAP_RGN_INFO               =  95,
    IOP_RGN_STRT_TX                 =  96,

    IOP_CONSOLE_DATA                =  97,

    IOP_RTE_LINK_DATA               =  98,
    IOP_TRK_HDR                     =  99,

    IOP_LCD_TEMP_DATA               = 100,

    IOP_BARO_CAL_DATA               = 101,
    IOP_BARO_DATA                   = 102,
    IOP_CMPS_CAL_DATA               = 103,
    IOP_CMPS_DATA                   = 104,
    IOP_DTMGRD_DATA                 = 105,
    IOP_FLASH_ID                    = 106,

    IOP_AUDIO_CMND_DATA             = 107,

    IOP_UNLOCK_CODE_DATA            = 108,
    IOP_ENUM_DATA                   = 109,      /* data field contains IOP_enum_data_type   */

    IOP_GOLFLOGIX_DATA              = 110,

    IOP_STUFF_KEY_DATA              = 111,      /* data field contains HWM_key_buf_type     */
    IOP_COM_BREAK_DATA              = 112,

    IOP_HOLD_IN_BB                  = 113,
    IOP_SAT_DATA                    = 114,      /* Satellite data   */
    IOP_PPS_DATA                    = 115,
    IOP_PRODUCT_ID                  = 116,

    IOP_PDA_CONFIG                  = 117,      /* Used for syncing */
    IOP_PDA_SYNC_SEC                = 118,
    IOP_PDA_REC_ID_STATUS_LIST      = 119,
    IOP_PDA_REC_OP                  = 120,
    IOP_PDA_REC                     = 121,
    IOP_PDA_STS                     = 122,

    IOP_INIT_T001                   = 123,     /* Used for transport protocol T001 */
    IOP_CONT_T001                   = 124,
    IOP_TRANS_ACCEPT                = 125,
    IOP_TRANS_REJECT                = 126,


    IOP_IP_DATA                     = 127,      /* Internet IP data */

    /*------------------------------------------------------
    PDA Instrumention IDs
    ------------------------------------------------------*/
    IOP_PDA_RECORDS                 = 128,

    IOP_DR_GYRO_INST_DATA           = 129,      /* Gyro Dead Rckn Data   */
    IOP_NAV_MNTR_DATA               = 130,      /* NAV monitor data */
    IOP_BAUD_SET_DATA               = 131,
    IOP_TEST_CMND_DATA              = 132,
    IOP_RGN_SUPPORT_INFO            = 133,

    IOP_FLIGHT_LOG_DATA             = 134,      /* Flight log data    */

    IOP_NEW_DEST_DATA               = 135,      /* new destination to route to */
    IOP_TEXT_MSG_DATA               = 136,      /* text message to display */
    IOP_DSPL_BIAS_DATA              = 137,      /* display bias */

    IOP_HONDA_MSG_DATA              = 138,      /* Honda Motor Company Message  */
    IOP_DR_ODOM_INST_DATA           = 139,      /* Odometer Dead Rckn Data   */

    IOP_TIS_TRAFFIC_DATA            = 140,      /* TIS Air Traffic Data */

    IOP_OEM_DATA                    = 141,      /* Special Packets for OEM use  */

    IOP_PROJ_DATA                   = 142,      /* MIL range finder projection data */

    /*------------------------------------------------------
    RFASIC params instrumentation ID
    ------------------------------------------------------*/
    IOP_RFASIC_DATA                 = 143,

    /*------------------------------------------------------
    WAAS status instrumentation ID
    ------------------------------------------------------*/
    IOP_WAAS_STAT_DATA              = 144,

    /*------------------------------------------------------
    Cradle ID Data
    ------------------------------------------------------*/
    IOP_CRADLE_ID_DATA              = 145,
    IOP_CRADLE_ID_VOLT_DATA         = 146,

    /*------------------------------------------------------
    Antenna Status Data
    ------------------------------------------------------*/
    IOP_GPS_ANT_STATUS_DATA         = 147,      /* GPS antenna status */

    /*------------------------------------------------------
    Compass Factory Calibration
    ------------------------------------------------------*/
    IOP_CMPS_FCTRY_CAL_DATA         = 148,

    /*------------------------------------------------------
    Lap Data (Forerunner)
    ------------------------------------------------------*/
    IOP_LAP_DATA                    = 149,

    IOP_SIGNAL_DATA                 = 150,

    /*------------------------------------------------------
    Bad block table instrumentation
    ------------------------------------------------------*/
    IOP_NAND_BBTBL_INST             = 151,

    /*------------------------------------------------------
    Waypoint category data
    ------------------------------------------------------*/
    IOP_WPT_CAT_DATA                = 152,

    /*------------------------------------------------------
    Remote PVT Instrumentation IDs
    ------------------------------------------------------*/
    IOP_PVT_INST_START              = 153,

    IOP_PVT_REMOTE_STATE            = 153,
    IOP_PVT_REMOTE_SAT              = 154,
    IOP_PVT_REMOTE_STATUS           = 155,
    IOP_PVT_RQST_REMOTE_STATUS      = 156,
    IOP_PVT_REMOTE_SAT_NMEA         = 157,
    IOP_PVT_REMOTE_SAT_NMEA2K       = 158,
    IOP_PVT_REDUCED_REMOTE_STATE    = 159,

    IOP_PVT_INST_END                = 160,

    IOP_FMI_MSG                     = 161,
    IOP_ENTERPRISE_TRACKING_MSG     = IOP_FMI_MSG,
    IOP_REMOTE_APP_NOTIFICATION     = 162,

    IOP_SESSION_SEQ_PACKET          = 163,
    IOP_BT_SYNC_PACKET              = 164,

    /*------------------------------------------------------
    Gyro Bias Data ID
    ------------------------------------------------------*/
    IOP_GYRO_BIAS_DATA              = 165,

    /*------------------------------------------------------
    SBAS Service Volume ID
    ------------------------------------------------------*/
    IOP_WDM_SRVC_ID                 = 166,

    /*------------------------------------------------------
    Battery status ID
    ------------------------------------------------------*/
    IOP_BATT_DATA                   = 167,

    /*------------------------------------------------------
    Status of adaptive transmit and automatic shutoff.
    ------------------------------------------------------*/
    IOP_ADAPTIVE_TX_STAT_DATA       = 168,
    IOP_AUTO_SHUTOFF_STAT_DATA      = 169,

    /*------------------------------------------------------
    GTM Traffic Messages
    ------------------------------------------------------*/
    IOP_GTM_TRAFFIC_MSG             = 170,

    /*------------------------------------------------------
    Status of external power-up feature
    ------------------------------------------------------*/
    IOP_EXT_PWR_UP_DATA             = 171,

    /*------------------------------------------------------
    PPS Auto Off Mode ID
    ------------------------------------------------------*/
    IOP_PPS_AUTO_OFF_MODE           = 172,

    /*------------------------------------------------------
    Program the temperature sensor offset value.
    ------------------------------------------------------*/
    IOP_TEMP_OFFSET_DATA            = 173,

    /*------------------------------------------------------
    SiRF binary data.
    ------------------------------------------------------*/
    IOP_SIRF_BINARY_DATA            = 174,

    /*------------------------------------------------------
    Extended OEM Specific Data
    ------------------------------------------------------*/
    IOP_OEM_DATA_EX                 = 175,

    /*------------------------------------------------------
    NAND bad block remap and related information
    ------------------------------------------------------*/
    IOP_NAND_BLOCK_MAP_INFO         = 176,
    IOP_NAND_BLOCK_MAP_ENTRY_RQST   = 177,
    IOP_NAND_BLOCK_MAP_ENTRY        = 178,

    IOP_RF_DATA                     = 179,

    /*------------------------------------------------------
    NMEA packaged in a Garmin packet (primarily for NMEA
    over USB)
    ------------------------------------------------------*/
    IOP_NMEA_DATA                   = 180,
    IOP_NMEA_DATA_CONTROL           = 181,

    IOP_RDR_MTR_DATA                = 182,

    IOP_REMOTE_GPS_DATA             = 183,

    IOP_PACKED_EPH_DATA             = 184,

    IOP_RDP_DATA                    = 185,

    /*------------------------------------------------------
    Remote GPS Test Mode Diagnostics Data
    ------------------------------------------------------*/
    IOP_RMT_GPS_TEST_DIAG           = 186,

    IOP_GPS_VEL_FLTR_STAT           = 187, /* velocity filter time constant data */
    IOP_GPS_VEL_FLTR_DATA           = 188, /* set velocity filter time constant data */

    IOP_OBD_MSG                     = 189, /* OBD accessory message */

    /*------------------------------------------------------
    New region transfer protocol
    ------------------------------------------------------*/
    IOP_RGN_STRT_EXT                = 190,
    IOP_RGN_DATA_RCPT               = 191,

    /*------------------------------------------------------
    CD player control
    ------------------------------------------------------*/
    IOP_CD_PLAYER_DATA              = 192,

    IOP_ILIMIT_DATA                 = 193, /* Accesory's current limit value( mA ) */

    /*------------------------------------------------------
    Streaming JSON Data over IOP
    ------------------------------------------------------*/
    IOP_JSON_WRAPPER                = 194,

    /*------------------------------------------------------
    Application Data Tunnel (ADT) for Android Fleet devices
    ------------------------------------------------------*/
    IOP_ADT_MSG                     = 217,

    /*------------------------------------------------------
    Electronic Logging Device (001-00408-XX)
    ------------------------------------------------------*/
    IOP_ELD_MSG                     = 218,

    /*------------------------------------------------------
    Utility to override the real-time clock
    ------------------------------------------------------*/
    IOP_OVERRIDE_CLOCK_MSG          = 219,

    /*------------------------------------------------------
    New commands for configuration over serial through
    CAN processor.
    ------------------------------------------------------*/
    IOP_TUNER_READ_MEM_BY_ADDR_SIF          = 220,  // read tuner memory at address
    IOP_TUNER_READ_MEM_RSLT_SIF             = 221,  // returns the requested data
    IOP_TUNER_WRITE_MEM_BY_ADDR_SIF         = 222,  // write tuner memory at address
    IOP_TUNER_START_PROFILE_DNLD_SIF        = 223,
    IOP_TUNER_END_PROFILE_DNLD_SIF          = 224,
    IOP_TUNER_WRITE_DATA_SIF                = 225,  // for writing rom images to a file
    IOP_TUNER_ABORT_PROFILE_DNLD_SIF        = 226,
    IOP_TUNER_CONFIG_RESPONSE_SIF           = 227,  // used by some commands as an ack/nak
    IOP_TUNER_PRGM_PROFILE_SECTOR_SIF       = 228,
    IOP_TUNER_GET_VERSION_SIF               = 229,  // returns the version number from the requested area
    IOP_TUNER_CONFIG_DIAGS_SIF              = 230,
    IOP_TUNER_CONFIG_DIAGS_RSLT_SIF         = 231,
    IOP_TUNER_IPL_SIF                       = 232,  // command to program the whole tuner serial flash

    /*----------------------------------------------------------
    Report region of execution.  This ID allows the device to
    report the region from where it is executing (i.e. BB, LDR,
    or SYS).  An 8-bit value of HWM_data_rgn_type is returned.
    ----------------------------------------------------------*/
    IOP_RGN_OF_EXEC                 = 233,

    /*------------------------------------------------------
    ANT Dongle
    ------------------------------------------------------*/
    IOP_ANT_DONGLE_CMD_DATA         = 240,
    IOP_ANT_DONGLE_RX_DATA          = 241,

    /*------------------------------------------------------
    ------------------------------------------------------*/

    IOP_RDP_UNIT_TEST_ID            = 242,
    IOP_RSTR_FACT_DFLTS_DONE        = 243, /* (new) Response to IOP_OEM_RSTR_FACT_DFLTS */

    /*------------------------------------------------------
    ------------------------------------------------------*/

    IOP_UNIT_TYPE                   = 244, /* SYC_unit_type_t8 data (device sub-category identifier) */
    IOP_PRODUCT_INFO_SUMMARY        = 245, /* GRM_product_info_summary_type data */
    IOP_PRODUCT_INFO                = 246, /* GRM_product_info_type data */
    IOP_PRODUCT_INVENTORY           = 247,

    /*------------------------------------------------------
    This product request should only request the product
    data.  A unit should assume no other actions to take
    in responding to a product request.  Only send the
    product data.
    ------------------------------------------------------*/
    IOP_EXT_PRODUCT_DATA            = 248,
    IOP_PRODUCT_RQST                = 249,

    IOP_APP_SUCCESS                 = 250,
    IOP_APP_FAILURE                 = 251,

    /*------------------------------------------------------
    The following symbols are used to identify products
    and their protocol capabilities
    ------------------------------------------------------*/
    IOP_BAUD_CAPS_DATA              = 252,
    IOP_PROTOCOL_DATA               = 253,

    /*------------------------------------------------------
    This product request has other assumed actions that the
    receiving unit should take.  For example, Updater assumes
    that the receiving unit will stop sending synchronous
    data after receiving an IOP_PRODUCT_RQST_EXTEND packet.
    Also, all request bits are set turned off after receiving
    this product request.
    ------------------------------------------------------*/
    IOP_PRODUCT_RQST_EXTEND         = 254,

    IOP_PRODUCT_DATA                = 255,


    IOP_START_OF_EX_IDS             = 256,

    /*------------------------------------------------------
    Set Fuel Gauge's Capacity (in percent)
    ------------------------------------------------------*/
    IOP_SET_FUEL_GAUGE_CAP          = 257,
    IOP_TAIWAN_DATA                 = 258,

    /*------------------------------------------------------
    This constant was initially misspelled and has remained
    mispelled for some time. To avoid breaking existing
    code, the correct spelling as been added (rather than
    correcting the misspelled constant)
    ------------------------------------------------------*/
    IOP_ANT_ALWAYSON_SET_MODE       = 259,
    IOP_ANT_ALWYASON_SET_MODE       = 259,

    /*------------------------------------------------------
    ANT Test Mode
    ------------------------------------------------------*/
    IOP_ANT_SET_TEST_MODE           = 260,
    IOP_ANT_START_SENSOR_SEARCH     = 261,
    IOP_ANT_SET_TEST_MODE_DUTY_CYCLE= 262,

    /*------------------------------------------------------
    ANT Page Data
    ------------------------------------------------------*/
    IOP_ANT_PAGE_DATA               = 265,

    /*------------------------------------------------------
    Set Unit Type

    Payload is an 8-bit unsigned integer value
    specifying a sub-category of device within a single
    product number.  It is meant to be permanent.

    Expected response:
    1. Attempt setting unit type.
    2. Reply with IOP_UNIT_TYPE message containing
    resulting unit type.
    ------------------------------------------------------*/
    IOP_UNIT_TYPE_SET               = 266,

    /*------------------------------------------------------
    Serial Pass-Thru IDs
    ------------------------------------------------------*/
    IOP_SERIAL_PASSTHRU_START       = 270,
    IOP_SERIAL_PASSTHRU_1           = 270,
    IOP_SERIAL_PASSTHRU_2           = 271,
    IOP_SERIAL_PASSTHRU_PORT        = 272,

    IOP_SERIAL_PASSTHRU_CLOSE       = 279,
    IOP_SERIAL_PASSTHRU_END         = 279,

    /*------------------------------------------------------
    GSM Related Tests
    ------------------------------------------------------*/
    IOP_GSM_START                   = 280,
    IOP_GSM_START_TESTS             = 280,
    IOP_GSM_SELF_TEST_RESULT        = 281,
    IOP_GSM_SELF_TEST_START         = 281,
    IOP_GSM_IO_TEST__RESET          = 282,
    IOP_GSM_IO_TEST_ON__OFF         = 283,
    IOP_GSM_SIM_CARD_TEST           = 284,
    IOP_GSM_REGISTRATION_TEST       = 285,
    IOP_GSM_IO_CONTROL              = 286,
    IOP_GSM_OPERATING_MODE          = 287,
    IOP_GSM_END_TESTS               = 289,
    IOP_GSM_FIRMWARE_UPDATE         = 290,
    IOP_GSM_FIRMWARE_UPDATE_STATUS  = 291,
    IOP_GSM_END                     = 299,

    /*------------------------------------------------------
    Diagnostic Instrumention IDs
    ------------------------------------------------------*/
    IOP_DIAG_START                  = 300,

    IOP_DIAG_TEST_DATA              = 300,
    IOP_DIAG_ACK_TEST_DATA          = 301,
    IOP_DIAG_STACK_DATA             = 302,
    IOP_DIAG_SHUTDOWN_DATA          = 303,
    IOP_DIAG_COMM_STATS_DATA        = 304,
    IOP_DIAG_SYC_MODE               = 305,
    IOP_DIAG_EXT_STACK_DATA         = 306,
    IOP_DIAG_MSN_DIRECT_REG_KEY     = 307,
    IOP_DIAG_AVR_ASSERT_DATA        = 308,
    IOP_DIAG_AVR_STACK_DATA         = 309,
    IOP_DOWN_LOAD_SHUTDOWN_INFO_REQ = 310,

    IOP_DIAG_SNSHUB_ASSERT          = 311,
    IOP_DIAG_SNSHUB_ASSERT_CONTINUE = 312,

    IOP_DIAG_TVL                    = 313,          /* Tag Value Logging */

    IOP_DIAG_END                    = 349,

    /*------------------------------------------------------
    Bluetooth Instrumention IDs
    ------------------------------------------------------*/
    IOP_BT_START                        = 350,
    IOP_BT_SET_BDADDR                   = 350,      /* Get the Bluetooth device address          */
    IOP_BT_ADDR_DATA                    = 351,      /* Data used to return the bluetooth address */
    IOP_BT_SET_TEST_DEVICE_ADDR_TEST    = 352,
    IOP_BT_VERSION_DATA                 = 353,      /* Bluetooth version data                    */
    IOP_BT_TX_CARRIER_FREQ              = 354,      /* Transmit Carrier Frequency of BT          */
    IOP_BT_GET_PWR_TBL                  = 355,      /* Get the Bluetooth power table             */
    IOP_BT_SET_PWR_TBL                  = 356,      /* Set the Bluetooth power table             */
    IOP_BT_LE_SET_RX_TEST               = 357,
    IOP_BT_LE_SET_TX_TEST               = 358,
    IOP_BT_LE_STOP_TEST                 = 359,
    IOP_BT_LE_RX_TEST_RESULT_DATA       = 360,
    IOP_BT_LE_SET_HRS_DATA              = 361,
    IOP_BT_LE_HRS_ENABLE                = 362,
    IOP_BT_SET_DISCOVERY_MODE           = 363,
    IOP_BT_STOP_TX_CARRIER_FREQ         = 364,      /* Stop Transmit of BT Carrier Frequency     */
    IOP_BT_CONN_DATA                    = 365,
    IOP_BT_GET_PAIR_KEY                 = 366,
    IOP_BT_SET_PAIR_KEY                 = 367,
    IOP_BT_CHIP_SELECT                  = 368,      /* Selects which bluetooth chip to use       */
    IOP_BT_WHITELIST_DATA               = 369,      /* Add/response with white list device data  */

    IOP_BT_END                          = 369,

    /*------------------------------------------------------
    WirelessUSB Instrumentation IDs
    ------------------------------------------------------*/
    IOP_WUSB_START                      = 370,
    IOP_WUSB_CHNL                       = 370,
    IOP_WUSB_POWER                      = 371,
    IOP_WUSB_SLAVE_LINK_INFO            = 372,
    IOP_WUSB_LINK_MODE                  = 373,
    IOP_WUSB_LNA_MODE                   = 374,
    IOP_WUSB_TX_TEST_DATA               = 375,
    IOP_WUSB_TX_STATUS                  = 376,
    IOP_WUSB_RX_DATA                    = 377,
    IOP_WUSB_RX_STATUS                  = 378,
    IOP_WUSB_RSSI_DATA                  = 380,
    IOP_WUSB_PASSTHROUGH_MODE           = 382,
    IOP_WUSB_MASTER_LINK_INFO           = 383,
    IOP_WUSB_INST_RQST                  = 384,
    IOP_WUSB_END                        = 390,

    /*------------------------------------------------------
    Sonar Instrumentation IDs
    ------------------------------------------------------*/
    IOP_SONAR_INST_START               = 400,

    IOP_SONAR_DEPTH_US                 = 400,
    IOP_SONAR_WATER_TEMPERATURE        = 401,
    IOP_SONAR_WATER_SPEED              = 402,      /* Water speed in meters per second                */
    IOP_SONAR_PROFILE_COLUMN           = 403,
    IOP_REMOTE_SONAR_STATUS_RQST_VER   = 404,      /* Request a remote status version                 */
    IOP_REMOTE_SONAR_STATUS            = 405,

    /*------------------------------------------------------
    Deprecated Sonar Inst ID, left in for old products
    ------------------------------------------------------*/
    IOP_SONAR_RCVR_PARMS               = 406,
    IOP_SONAR_ENV_DATA_REQ             = IOP_SONAR_RCVR_PARMS,    /* Request envelope data output     */

    IOP_SONAR_DEBUG_DATA               = 407,                     /* Array of data used for debugging */

    /*------------------------------------------------------
    Deprecated Sonar Inst ID, left in for old products
    ------------------------------------------------------*/
    IOP_SONAR_START_DRIVER             = 408,                     /* Begin sonar driver control       */
    IOP_SONAR_DRIVER_CNFG              = IOP_SONAR_START_DRIVER,  /* Sonar driver configuration       */

    IOP_SONAR_TEST_TRANSMITTER_START   = 409,      /* Begin transmitter test                          */
    IOP_SONAR_TEST_RECEIVER_START      = 410,      /* Begin receiver test                             */
    IOP_SONAR_TEST_RECEIVER_DATA       = 411,      /* Receive test data                               */
    IOP_SONAR_XDCR_ID_TEST_DATA        = 412,      /* Transducer ID test data                         */
    IOP_SONAR_WATER_SPEED_ID           = 413,      /* Water speed sensor present                      */
    IOP_SONAR_XDCR_ID_BUS_LVL_DATA     = 414,      /* Transducer ID bus level data                    */
    IOP_SONAR_WATER_SPEED_HZ           = 415,      /* Water speed in Hertz                            */
    IOP_SONAR_WATER_TEMPERATURE_VOLTS  = 416,      /* Water temperature in millivolts                 */
    IOP_SONAR_HARDWARE_DRIVER_HEALTHY  = 417,      /* True if sonar hardware can be used              */
    IOP_SONAR_TEST_DYNAMIC_RANGE_START = 418,      /* Begin dynamic range test                        */
    IOP_SONAR_SAMPLE_INJECT_CNFG       = 419,      /* Sonar sample injection configuration            */
    IOP_SONAR_XDCR_ID_DATA             = 420,      /* Transducer ID read data                         */
    IOP_REMOTE_SONAR_STATUS_V2         = 421,      /* Sonar status version 2                          */
    IOP_SONAR_PROFILE_COLUMN_V2        = 422,      /* Profile column version 2                        */
    IOP_SONAR_TX_ONLY_HALF             = 423,      /* only transmit half the sonar waveform           */
    IOP_SONAR_SET_FILTER_COEFFICIENTS  = 424,      /* update the filter coefficients                  */
    IOP_SONAR_SET_PRIMARY_TX_FREQ      = 425,      /* set the primary transmit frequency              */
    IOP_SONAR_TEST_FOM                 = 426,      /* Figure Of Merit test                            */
    IOP_SONAR_ADC_DATA                 = 427,      /* ADC data output                                 */
    IOP_SONAR_ADC_DATA_REQ             = 428,      /* Request ADC data output                         */
    IOP_SONAR_ADC_CNFG                 = 429,      /* ADC data configuration                          */
    IOP_SONAR_XDCR_ID_REQ              = 430,      /* Request transducer ID info                      */
    IOP_SONAR_TEST_DATA                = 431,      /* Flexibly formatted test mode output             */
    IOP_SONAR_TEST_START               = 432,      /* Flexibly formatted test mode start              */
    IOP_SONAR_SET_TEST_CNFG            = 433,      /* Set test mode configuration                     */
    IOP_SONAR_GARMIN_ID_VOLTS          = 434,      /* Garmin ID in millivolts                         */
    IOP_SONAR_ENF_SEARCH               = 435,      /* Search for the electrical noise floor           */
    IOP_SONAR_XDCR_DATA_REQ            = 436,      /* Request transducer data                         */
    IOP_SONAR_XDCR_DATA                = 437,      /* Transducer data                                 */
    IOP_SONAR_XDCR_BAY_LID_STATE       = 438,      /* Lid state of the sonar bay                      */
    IOP_SONAR_XDCR_STATE               = 439,      /* Sonar transducer state                          */
    IOP_SONAR_DYNAMICS                 = 440,      /* Sonar dynamic conditions & measurements         */
    IOP_SONAR_SET_XDCR_MODEL           = 441,      /* Set transducer model                            */
    IOP_SONAR_XMIT_STATE               = 442,      /* Transmit duration, power, and rate data         */
    IOP_SONAR_MOTOR_STATUS             = 443,      /* Sonar beam patterm testing motor status         */
    IOP_SONAR_MOTOR_GUIDANCE           = 444,      /* Sonar beam pattern testing motor guidance       */
    IOP_SONAR_PACKET_DELIMITER         = 445,      /* Mark the beginning and end of interrogation data */
    IOP_SONAR_DATASET_AVAIL_REQ        = 446,      /* Request available sonar datasets                */
    IOP_SONAR_DATASET_AVAIL            = 447,      /* Available sonar datasets                        */
    IOP_SONAR_MISC_DATA                = 448,      /* Optional data varying with product capabilities */
    IOP_SONAR_CNFG_OVERRIDE            = 449,      /* Override sonar interrogation configuration parameters */

    /*------------------------------------------------------
    Sonar Recording Inst IDs
    ------------------------------------------------------*/
    IOP_SONAR_RECORDING_DATA           = 450,      /* Sonar recording data                            */
    IOP_SONAR_RECORDING_RQST           = 451,      /* Sonar recording request                         */

    IOP_SONAR_INST_END                 = 499,


    /*------------------------------------------------------
    RFC Instrumentation IDs
    ------------------------------------------------------*/
    IOP_COM_INST_DATA               = 500,      /* COM mode for radio or sim products   */
    IOP_COM_VOX_DATA                = 501,      /* VOX threshold setting                */

    IOP_COM_CONFIG_DATA             = 502,      /* RF COM configuration data            */
    IOP_COM_MODEM_TX_DATA           = 503,      /* Set data for RF modem to transmit    */
    IOP_COM_AUDMON_DATA             = 504,      /* Enable/disable audio monitor         */
    IOP_COM_MODEM_RX_PAGE           = 505,      /* Modem raw data waveform samples      */
    IOP_COM_POSSEND                 = 506,      /* Enable/disable auto position sending */
    IOP_COM_MODEM_COR_PAGE          = 507,      /* Modem correlation samples            */
    IOP_COM_FRS_GEO_RGN             = 508,      /* Set geographical region              */
    IOP_COM_MODEM_RX_CHECK          = 509,      /* Packet of status of last modem rx    */
    IOP_COM_MODEM_WPT_DATA          = 510,      /* Set tx'ed or get rx'ed waypoint data */
    IOP_COM_MODEM_WAVE_CONFIG       = 511,      /* Set modem waveform                   */
    IOP_COM_VIBRA_DATA              = 512,      /* Turn on/off vibrator                 */
    IOP_COM_SCRMB_DATA              = 513,      /* Turn on/off scrambler                */
    IOP_COM_ENBL_GMRS               = 514,      /* Enable/disable GMRS channels         */
    IOP_COM_INST_RQST               = 515,      /* Enable/disable RF comm data fm unit  */
    IOP_COM_SYNTH_LOCK              = 516,      /* Synth lock status                    */
    IOP_COM_MIC_GAIN                = 517,      /* Set mic gain                         */
    IOP_COM_ENBL_WX_ALERT_CHK       = 518,      /* Enable Weather Radio Alert Checking  */
    IOP_COM_TUNE_REF_FREQ           = 519,      /* Set tuning of reference clock        */
    IOP_COM_RXSQUELCH_CAL           = 520,      /* Set stored calibration rx squelch    */
    IOP_COM_RXSQUELCH_USR           = 521,      /* Set user rx squelch level            */
    IOP_COM_USER_PWRLVL             = 522,      /* User power selection                 */
    IOP_COM_TRACKED_ASSET           = 523,      /* Add a tracked asset to the list of tracked items */
    IOP_COM_TX_INTERVAL             = 524,      /* Interval TX for 5 seconds            */

    /*------------------------------------------------------
    Device Data Reporting
    ------------------------------------------------------*/
    IOP_UNIT_ALIAS_DATA             = 525,      /* User defined device name data    */
    IOP_UNIT_ALIAS_RQST             = 526,      /* Rqst for user defined device name*/

    /*------------------------------------------------------
    Dead Reckoning (DR) instrumentation IDs
    ------------------------------------------------------*/
    IOP_DR_GYRO_ADC_DATA            = 540,
    IOP_DR_REVERSE_DATA             = 541,
    IOP_DR_ODOM_PULSE_DATA          = 542,
    IOP_DR_ODOM_SINE_DATA           = 543,
    IOP_DR_GYRO_BIAS_CHECK_DATA     = 544,

    /*------------------------------------------------------
    General Test Mode Reporting
    ------------------------------------------------------*/
    IOP_IRDA_TEST_BYTE              = 550,
    IOP_PHOTOCELL_LEVEL_DATA        = 551,
    IOP_PEN_SCAN_DATA               = 552,
    IOP_RTC_DRIFT_DATA              = 553,
    IOP_AMBIENT_LUX_DATA            = 554,
    IOP_CORE_TEMP_DATA              = 555,
    IOP_CORE2_TEMP_DATA             = 556,
    IOP_SENSOR_TEMP_DATA            = 557,
    IOP_PEN_MTOUCH_SCAN_DATA        = 558,

    /*------------------------------------------------------
    Unlock Codes and map listing
    ------------------------------------------------------*/
    IOP_MAP_UNLOCK_DATA             = 560,
    IOP_MAP_LIST_INFO               = 561,
    IOP_GPI_UNLOCK_DATA             = 562,
    IOP_SW_UNLOCK_DATA              = 563,
    IOP_MAP_RENAME_DATA             = 564,

    /* New unlock protocols may be added using this protocol. See IOP_pub_unlock_ex_types.h. */
    IOP_UNLOCK_EX_DATA              = 565,      /* Extensible Unlock Protocol */

    /*------------------------------------------------------
    Garmin Ethernet
    ------------------------------------------------------*/
    IOP_NET_ADDR_BYTE               = 570,      /* Set the network address to a fixed value (no negotiation) */
    IOP_NET_CLR_ADDR_BYTE           = 571,      /* Clear the fixed network address (resume negotiation) */
    IOP_NET_SET_MFD_PWR_ON          = 572,      /* Command to assert the MFD Power On Line */
    IOP_NET_SET_SENSOR_PWR_ON       = 573,      /* Command to assert the Sensor Power On Line */
    IOP_NET_REMOTE_PWR_ON           = 574,      /* Current asserted state of the Pemote Power On line */
    IOP_NET_RESTORE_DEFAULTS        = 575,      /* Restore factory settings (but don't clear user data) */
    IOP_NET_UPDATE_BEGIN            = 576,      /* Begin the Passive Updater */
    IOP_NET_UPDATE_DONE             = 577,      /* End the Passive Updater */

    /*------------------------------------------------------
    Vibration Motor
    ------------------------------------------------------*/
    IOP_SET_VIB_MOTOR_ID            = 580,
    IOP_SET_VIB_MOTOR_FREQ_SCALE    = 581,

    /*------------------------------------------------------
    RDS Diagnostic Instrumentation IDs
    ------------------------------------------------------*/
    IOP_RDS_INST_START              = 600,

    IOP_RDS_INST_LOG_EVENT          = 600,
    IOP_RDS_INST_CONTACT_MADE_RSP   = 601,

    IOP_RDS_INST_GTM_ESN            = 619,
    IOP_RDS_INST_END                = 619,

    /*------------------------------------------------------
    XM Radio Instrumentation IDs
    ------------------------------------------------------*/
    IOP_XM_INST_START                       = 620,

    IOP_XM_INST_DATA_YODA_DIAG_INFO         = 620,
    IOP_XM_INST_DATA_STATE_INFO             = 621,
    IOP_XM_INST_SGNL_QLTY_V2                = 622,

    IOP_XM_INST_AUDIO_CH_LABEL              = 630,
    IOP_XM_INST_AUDIO_YODA_DIAG_INFO        = 631,
    IOP_XM_INST_AUDIO_STATE_INFO            = 632,
    IOP_XM_INST_AUDIO_CAT_LABEL             = 633,
    IOP_XM_INST_AUDIO_ART_LABEL             = 634,
    IOP_XM_INST_AUDIO_CH_LABEL_EXT          = 635,


    IOP_XM_INST_AUDIO_CAT_LABEL_EXT         = 638,
    IOP_XM_INST_AUDIO_ART_LABEL_EXT         = 639,
    IOP_XM_INST_AUDIO_REQ_CH_BY_SID         = 640,
    IOP_XM_INST_AUDIO_REQ_LBL_BY_CH         = 641,
    IOP_XM_INST_AUDIO_FAVORITE_INFO         = 642,
    IOP_XM_INST_AUDIO_ADD_FAVORITE          = 643,
    IOP_XM_INST_AUDIO_DEL_FAVORITE          = 644,
    IOP_XM_INST_AUDIO_REQ_CH_BY_CH          = 645,
    IOP_XM_INST_AUDIO_SET_VOLUME            = 646,
    IOP_XM_INST_AUDIO_SET_SRCH_MODE         = 647,

    IOP_XM_INST_DUAL_STATE_INFO             = 650,
    IOP_XM_INST_DUAL_YODA_DIAG_INFO         = 651,
    IOP_XM_INST_DUAL_RADIO_ID               = 652,
    IOP_XM_INST_DUAL_STATE_PRDC_INFO        = 653,
    IOP_XM_INST_DUAL_STATE_STATIC_INFO      = 654,
    IOP_XM_INST_AUDIO_REQ_CH_BY_SID_EXT     = 655,
    IOP_XM_INST_AUDIO_REQ_LBL_BY_CH_EXT     = 656,

    IOP_XM_INST_AUDIO_ADD_FAVORITE_EXT      = 658,
    IOP_XM_INST_AUDIO_DEL_FAVORITE_EXT      = 659,
    IOP_XM_INST_AUDIO_REQ_CH_BY_CH_EXT      = 660,

    IOP_XM_INST_RCVR_FCTRY_DFLTS_RSTRD      = 663,
    IOP_XM_INST_MODULE_CONFIG_CHECK         = 664,
    IOP_XM_INST_DUAL_STATE_STATIC_INFO_EXT  = 665,
    IOP_XM_INST_VERSION_CHECK               = 666,
    IOP_XM_INST_EXTERNAL_ID_ADC             = 667,
    IOP_XM_INST_ANTENNA_STATUS              = 668,
    IOP_XM_INST_SGNL_QLTY                   = 669,
    IOP_XM_INST_CBM_SEQ_LOG                 = 670,
    IOP_XM_INST_CONTACT_MODE                = 671,
    IOP_XM_INST_FAVORITE_BANDS              = 672,
    IOP_XM_INST_FAVORITE_BANDS_ACK          = 673,

    IOP_XM_INST_END                         = 674,

    /*------------------------------------------------------
    Marine Radar
    ------------------------------------------------------*/
    IOP_MR_INST_START               = 675,

    /* data from the radar              */
    IOP_MR_TARGET_DATA              = 675,
    IOP_MR_AFC_DATA                 = 676,
    IOP_MR_STATUS                   = 677,
    IOP_MR_USER_DATA                = 678,
    IOP_MR_MSTR_CNFG                = 679,
    IOP_MR_RESIDUAL_TX_PULSE        = 680,
    IOP_MR_PRESETS                  = 681,
    IOP_MR_MAG_TIME                 = 682,
    IOP_MR_DC_MOTOR_RPM             = 683,
    IOP_MR_TEMP_DATA                = 684,
    IOP_MR_UNIT_TYPE                = 685,
    IOP_MR_CAPABILITIES             = 686,
    IOP_MR_AFC_CAL_OFST             = 687,
    IOP_MR_RAW_DATA                 = 688,

    /* commands to control the radar    */
    IOP_MR_TX_STATE                 = 690,
    IOP_MR_RANGE                    = 691,
    IOP_MR_GAIN_OFFSET              = 692,
    IOP_MR_SEA_CLUTTER_OFFSET       = 693,
    IOP_MR_RAIN_CLUTTER_OFFSET      = 694,
    IOP_MR_FOB_OFFSET               = 695,
    IOP_MR_SET_FTC                  = 696,
    IOP_MR_PULSE_DITHER             = 697,
    IOP_MR_SET_TRGT_EXPANSION       = 698,
    IOP_MR_SET_WATCHMAN             = 699,
    IOP_MR_RQST_PRESETS             = 700,
    IOP_MR_RQST_MAG_TIME            = 701,
    IOP_MR_SET_ANT_ROT_RPM          = 702,
    IOP_MR_SET_HW_ID                = 703,
    IOP_MR_SET_AFC_CAL_OFST         = 704,
    IOP_MR_CP_OFFSET                = 705,

    /* test commands                    */
    IOP_MR_RQST_AFC_INFO            = 710,
    IOP_MR_SET_AFC                  = 711,
    IOP_MR_SET_IF_BW                = 712,
    IOP_MR_SET_VIDEO_BW             = 713,
    IOP_MR_SET_TX_PULSE_MASK        = 714,
    IOP_MR_SET_STC                  = 715,
    IOP_MR_ZERO_TX_PULSE_MASK       = 716,
    IOP_MR_RQST_RESIDUAL_TX_PULSE   = 717,
    IOP_MR_SET_LMTR                 = 718,
    IOP_MR_TWN_TEST_TX              = 719,

    /* user data commands */
    IOP_MR_RQST_USER_DATA           = 720,
    IOP_MR_CLR_USER_DATA            = 721,
    IOP_MR_RQST_MSTR_CNFG           = 722,
    IOP_MR_RQST_UNIT_TYPE           = 723,
    IOP_MR_RQST_UNIT_ID             = 724,

    /* echo cursor commands             */
    IOP_MR_ECHO_CRSR_DATA           = 725,

    /* more test commands               */
    IOP_MR_SET_AUTO_GAINS           = 728,
    IOP_MR_COARSE_AFC_TUNE          = 729,
    IOP_MR_RQST_RAW_DATA            = 730,
    IOP_MR_SET_COARSE_AFC           = 731,

    /* more user data commands  */
    IOP_MR_RQST_CAPABILITIES        = 735,
    IOP_MR_RQST_AFC_CAL_OFST        = 736,

    /* test data                        */
    IOP_MR_DC_MOTOR_STATUS          = 740,
    IOP_MR_COARSE_AFC_DATA          = 741,
    IOP_MR_OPTO_SENSOR_STATUS       = 742,
    IOP_MR_INST_TEST                = 743,
    IOP_MR_COARSE_AFC_TUNE_STATUS   = 744,

    /* advanced commands */
    IOP_MR_FTC_OFFSET                 = 745,
    IOP_MR_TX_ZONE                    = 746,
    IOP_MR_SCAN_AVG                   = 747,
    IOP_MR_AUTO_GAIN_PRESET           = 748,

    IOP_MR_ADVANCED_CNFG              = 749,
    IOP_MR_RQST_ADVANCED_CNFG         = 750,

    IOP_MR_RANGE_MODE                 = 751,
    IOP_MR_SHORT_RANGE                = 752,
    IOP_MR_LONG_RANGE                 = 753,
    IOP_MR_SPOKE_NUM                  = 754,

    IOP_MR_SR_TGT_DATA                = 755,
    IOP_MR_SR_GAIN_OFFSET             = 756,
    IOP_MR_SR_SEA_OFFSET              = 757,
    IOP_MR_SR_RAIN_OFFSET             = 758,
    IOP_MR_SR_FTC_OFFSET              = 759,
    IOP_MR_LR_TGT_DATA                = 760,
    IOP_MR_LR_GAIN_OFFSET             = 761,
    IOP_MR_LR_SEA_OFFSET              = 762,
    IOP_MR_LR_RAIN_OFFSET             = 763,
    IOP_MR_LR_FTC_OFFSET              = 764,
    IOP_MR_SAP                        = 765,
    IOP_MR_CLUTTER_SWITCH             = 766,
    IOP_MR_BITS_PER_SAMPLE            = 767,
    IOP_MR_SR_BEAM_SHARPENING         = 768,
    IOP_MR_LR_BEAM_SHARPENING         = 769,

    IOP_MR_INST_END                 = 774,

    /*------------------------------------------------------
    XM/Wx Weather Instrumentation IDs
    ------------------------------------------------------*/
    IOP_WX_INST_START               = 775,

    IOP_WX_INST_LOG                 = 775,
    IOP_WX_INST_STATS               = 776,
    IOP_WX_INST_STATE_INFO          = 777,
    IOP_WX_INST_RAW_DATA            = 778,

    IOP_WX_INST_OLD_START_QUERY     = 785,
    IOP_WX_INST_OLD_CONT_QUERY      = 786,
    IOP_WX_INST_OLD_QUERY_DATA      = 787,
    IOP_WX_INST_OLD_END_QUERY       = 788,
    IOP_WX_INST_OLD_QUERY_ACK       = 789,
    IOP_WX_INST_OLD_QUERY_DATA_START= 790,

    IOP_WX_INST_REQ_CURRENT_COND    = 800,
    IOP_WX_INST_REQ_FORECAST        = 801,
    IOP_WX_INST_REQ_EXT_FORECAST    = 802,
    IOP_WX_INST_REQ_WATER_COND      = 803,
    IOP_WX_INST_REQ_WARNING_DATA    = 804,

    IOP_WX_INST_NEW_START_QUERY     = 805,
    IOP_WX_INST_NEW_CONT_QUERY      = 806,
    IOP_WX_INST_NEW_QUERY_DATA      = 807,
    IOP_WX_INST_NEW_END_QUERY       = 808,
    IOP_WX_INST_NEW_QUERY_ACK       = 809,
    IOP_WX_INST_NEW_QUERY_DATA_START= 810,

    IOP_WX_INST_REQ_MARINE_BULLETIN = 815,

    IOP_WX_INST_G4_PRDCT_LIST       = 818,
    IOP_WX_INST_PRDCT_LIST          = 819,
    IOP_WX_INST_PRDCT_RCVD          = 820,
    IOP_WX_INST_REQ_RAW_DATA        = 821,

    IOP_WX_INST_G4_PRDCT_RCVD       = 822,
    IOP_WX_INST_G4_REQ_RAW_DATA     = 823,

    IOP_WX_INST_FILE_HDR            = 825,
    IOP_WX_INST_FILE_REQ            = 826,
    IOP_WX_INST_FILE_INV            = 827,
    IOP_WX_INST_FILE_DATA           = 828,

    IOP_WX_INST_END                 = 859,

    /*------------------------------------------------------
    MTP Packets
    ------------------------------------------------------*/
    IOP_MTP_INST_START              = 860,

    IOP_MTP_INST_DATA               = 860,
    IOP_MTP_INST_ACK                = 861,

    IOP_MTP_INST_END                = 874,

    /*------------------------------------------------------
    Bitmap I/O Packets
    ------------------------------------------------------*/
    IOP_BIO_START                   = 875,

    IOP_BIO_READ_NAME               = 875,  /* Read File Name           */
    IOP_BIO_NAME                    = 876,  /* File Name                */
    IOP_BIO_READ_TOC                = 877,  /* Read Image Table of Cont.*/
    IOP_BIO_TOC                     = 878,  /* Image Table of Contents  */
    IOP_BIO_READ_IMG_DEF            = 879,  /* Read Image Definition    */
    IOP_BIO_IMG_DEF                 = 880,  /* Image Definition Data    */
    IOP_BIO_OPEN_IMG                = 881,  /* Open a Bitmap Image      */
    IOP_BIO_CONV_HNDL               = 882,  /* Conversation Handle      */
    IOP_BIO_CLOSE_IMG               = 883,  /* Close a Bitmap Image     */
    IOP_BIO_READ_IMG                = 884,  /* Read Bitmap Image        */
    IOP_BIO_IMG_DATA                = 885,  /* Bitmap Image Data        */
    IOP_BIO_READ_RGB                = 886,  /* Read Bitmap Image        */
    IOP_BIO_RGB_DATA                = 887,  /* Bitmap Image Data        */
    IOP_BIO_READ_CAT_LIST           = 888,  /* Read Category List       */
    IOP_BIO_CAT_LIST                = 889,  /* Category List            */
    IOP_BIO_READ_CAT_NAME           = 890,  /* Read Category Name       */
    IOP_BIO_CAT_NAME                = 891,  /* Category Name            */
    IOP_BIO_START_CAPTURE           = 892,  /* Start Sequence Capture   */
    IOP_BIO_END_CAPTURE             = 893,  /* End Sequence Capture     */
    IOP_BIO_IMG_DIRTY               = 894,  /* Image Dirty              */

    IOP_BIO_END                     = 899,

    /*------------------------------------------------------
    Battery Monitor Instrumentation
    ------------------------------------------------------*/
    IOP_BATT_MON_START              = 900,
    IOP_BATT_MON_DATA               = 901,  /* Battery Monitor Basic Data Inst.     */
    IOP_BATT_CHRG_START_STOP        = 902,  /* Start/Stop charging battery          */
    IOP_BATT_TEMP_CAL_DATA          = 903,  /* Battery Temperature Calibration      */
    IOP_BATT_MEM_DATA               = 904,  /* Battery memory contents              */
    IOP_BATT_FAST_CHRG_START_STOP   = 905,  /* Start/Stop fast charging battery     */
    IOP_BATT_CHRG_DATA              = 906,  /* Battery charge information           */
    IOP_BATT_VERIFY_DATA            = 907,  /* Battery programmed data verification */
    IOP_BATT_INST_RESPONSE          = 908,  /* Battery INST success/fail response   */
    IOP_BATT_MON_END                = 909,

    /*------------------------------------------------------
    Connection Control Service Packets
    ------------------------------------------------------*/
    IOP_NET_CCS_HEARTBEAT       = 910,  /* Periodically transmitted heartbeat   */
    IOP_NET_CCS_SET_SYS_MODE    = 911,  /* Set the system mode                  */
    IOP_NET_CCS_SET_SLEEP_LVL   = 912,  /* Set the sleep level ( Deprecated )   */
    IOP_NET_CCS_PROD_INFO_RQST  = 913,  /* Product information request          */
    IOP_NET_CCS_PROD_INFO_DATA  = 914,  /* Product information data             */
    IOP_NET_CCS_SET_ALIAS_NAME  = 915,  /* Set the alias name                   */
    IOP_NET_CCS_BLD_DESC_DATA   = 916,  /* Build Description Data               */
    IOP_NET_CCS_HEAT            = 917,  /* Hardware Exercise Application Test   */
    IOP_NET_CCS_UNIT_ID_RQST    = 918,  /* Unit ID request                      */
    IOP_NET_CCS_UNIT_ID_DATA    = 919,  /* Unit ID data                         */
    IOP_NET_CCS_NMEA_DEV_RQST   = 920,  /* NMEA 0183 device request             */
    IOP_NET_CCS_NMEA_DEV_DATA   = 921,  /* NMEA 0183 device data                */
    IOP_NET_CCS_SET_PWR_LVL     = 922,  /* Set the power level (replaces IOP_NET_CCS_SET_SLEEP_LVL) */
    IOP_NET_CCS_PROD_DATA       = 923,  /* Product Data                         */

    IOP_NET_CCS_END             = 924,

    /*------------------------------------------------------
    Deprecated SYC Net CCS IDs left in for old products
    ------------------------------------------------------*/
    IOP_SYC_NET_CCS_HEARTBEAT           = IOP_NET_CCS_HEARTBEAT,      /* Periodically transmitted heartbeat   */
    IOP_SYC_NET_CCS_SET_SYS_MODE        = IOP_NET_CCS_SET_SYS_MODE,   /* Set the system mode                  */
    IOP_SYC_NET_CCS_SET_SLEEP_LVL       = IOP_NET_CCS_SET_SLEEP_LVL,  /* Set the sleep level                  */
    IOP_SYC_NET_CCS_PROD_INFO_RQST      = IOP_NET_CCS_PROD_INFO_RQST, /* Product information request          */
    IOP_SYC_NET_CCS_PROD_INFO_DATA      = IOP_NET_CCS_PROD_INFO_DATA, /* Product information data             */
    IOP_SYC_NET_CCS_SET_ALIAS_NAME      = IOP_NET_CCS_SET_ALIAS_NAME, /* Set the alias name                   */
    IOP_SYC_NET_CCS_BLD_DESC_DATA       = IOP_NET_CCS_BLD_DESC_DATA,  /* Build Description Data               */
    IOP_SYC_NET_CCS_HEAT                = IOP_NET_CCS_HEAT,           /* Hardware Exercise Application Test   */
    IOP_SYC_NET_CCS_UNIT_ID_RQST        = IOP_NET_CCS_UNIT_ID_RQST,   /* Unit ID request                      */
    IOP_SYC_NET_CCS_UNIT_ID_DATA        = IOP_NET_CCS_UNIT_ID_DATA,   /* Unit ID data                         */
    IOP_SYC_NET_CCS_NMEA_DEV_RQST       = IOP_NET_CCS_NMEA_DEV_RQST,  /* NMEA 0183 device request             */
    IOP_SYC_NET_CCS_NMEA_DEV_DATA       = IOP_NET_CCS_NMEA_DEV_DATA,  /* NMEA 0183 device data                */

    IOP_SYC_NET_CCS_END                 = IOP_NET_CCS_END,

    /*------------------------------------------------------
    ATA Data Packets
    ------------------------------------------------------*/
    IOP_ATA_REQUEST                 = 925,  /* request an ATA command be executed   */
    IOP_ATA_DATA                    = 926,  /* response to an ATA request           */
    IOP_ATA_ERROR                   = 927,  /* error execuiting an ATA request      */

    /*------------------------------------------------------
    Test Commands that have associated Data
    ------------------------------------------------------*/
    IOP_STORED_RAM_TEST             = 928,  /* command to retrieve stored RAM test      */
    IOP_STORED_RAM_TEST_RSLT        = 929,  /* result of stored RAM test                */
    IOP_MEDIA_RW_TEST               = 930,  /* perform a read/write test on media       */
    IOP_MEDIA_RW_TEST_RSLT          = 931,  /* media read/write test result             */
    IOP_RGN_CHECKSUM                = 932,  /* command to checksum a region             */
    IOP_RGN_CHECKSUM_RSLT           = 933,  /* result of region checksum test           */
    IOP_RGN_CHECKSUM_COMPARE        = 934,  /* compare checksums                        */
    IOP_RGN_CHECKSUM_COMPARE_RSLT   = 935,  /* result of checksum comparison            */
    IOP_SET_POWER_ON_PIN            = 936,  /* command to assert the power on pin       */
    IOP_RGN_PROGRESS                = 937,  /* report region manipulation progress      */
    IOP_MULTIPLE_RGN_CHKSUM         = 938,  /* command to checksum multiple hwm regions */
    IOP_PUSH_PAGE_REQUEST           = 939,  /* command request to Push Page             */

    /*------------------------------------------------------
    Video
    ------------------------------------------------------*/
    IOP_SET_VIDEO_INPUT_SRC         = 940,  /* Video input source selection command                    */
    IOP_SET_VIDEO_INPUT_STANDARD    = 941,  /* Video input standard (NTSC, PAL, etc) selection command */

    /*------------------------------------------------------
    Additional Test Commands that have Associated Data
    ------------------------------------------------------*/
    IOP_STORED_GPU_RAM_TEST         = 942,
    IOP_STORED_GPU_RAM_TEST_RSLT    = 943,

    /*------------------------------------------------------
    GCD PASS THRU MODE SUPPORT
    ------------------------------------------------------*/
    IOP_START_PASS_THRU_MODE        = 945,
    IOP_STOP_PASS_THRU_MODE         = 946,
    IOP_REQUEST_VIRTUAL_DEVICE      = 947,
    IOP_NEGOTIATE_TRANSFER_RATE     = 948,
    IOP_PASS_THRU_MODE_RESULT       = 949,

    /*------------------------------------------------------
    On-board part qualification test
    ------------------------------------------------------*/
    IOP_QUALIFY_TEST_DATA           = 954,

    /*-----------------------------------------------------------
    Added to support multiple region trsnfer within the loader
    -----------------------------------------------------------*/
    IOP_RGN_FLUSH_WRITE_CACHE       = 955,

    /*------------------------------------------------------
    Instrumentation dependent on type of power source
    ------------------------------------------------------*/
    IOP_PSRC_START                  = 960,
    IOP_PSRC_INTBAT_MON_DATA        = 960,
    IOP_PSRC_EXTFXD_MON_DATA        = 961,
    IOP_PSRC_MRNBAT_MON_DATA        = 962,
    IOP_PSRC_USBFXD_MON_DATA        = 963,
    IOP_PSRC_TYPE_INFO              = 964,
    IOP_PSRC_END                    = 979,

    /*------------------------------------------------------
    Region Information
    ------------------------------------------------------*/
    IOP_RQST_RGN_SIZE               = 980,
    IOP_RGN_SIZE                    = 981,
    IOP_REMOTE_RGN_RQST             = 982,
    IOP_TX_RGN_SIZE                 = 983,
    IOP_RGN_FAILURE_INFO            = 984,

    /*------------------------------------------------------
    Fitness Product Data
    ------------------------------------------------------*/
    IOP_RUN_DATA                    = 990,
    IOP_WRKT_DATA                   = 991,
    IOP_WRKT_DATE_DATA              = 992,
    IOP_PRFL_DATA                   = 993,
    IOP_WRKT_LMT_DATA               = 994,

    /*------------------------------------------------------
    Remote Sensor Instrumentation
    ------------------------------------------------------*/
    IOP_RQST_AUTO_SRCH              = 995,  /* Request AutoSearch on next power on of remote sensor */

    /*------------------------------------------------------
    Heart rate Data
    ------------------------------------------------------*/
    IOP_HEART_RATE_DATA             = 1005,
    IOP_HEART_RATE_START_STOP       = 1006,
    IOP_HEART_RATE_TEST_DATA        = 1007,
    IOP_HEART_RATE_INST_ID_END      = 1009,

    /*------------------------------------------------------
    ADC Voltage data
    ------------------------------------------------------*/
    IOP_ADC_DATA                    = 1010,
    IOP_ADC_START_STOP              = 1011,
    IOP_ADC_CHANNEL_READ            = 1012,
    IOP_ADC_CHANNEL_READ_DATA       = 1013,
    IOP_ADC_SET_CONV_RATE           = 1014,

    /*------------------------------------------------------
    Registration Code Data
    ------------------------------------------------------*/
    IOP_REG_CODE_DATA               = 1015, /* map registration code data                           */

    /*------------------------------------------------------
    ActiveSync
    ------------------------------------------------------*/
    IOP_START_OF_ACTIVESYNC         = 1016,

    IOP_ACTIVESYNC_UMSG_DATA        = 1016,

    IOP_AS_DEVICE_INFO              = 1020,
    IOP_AS_USER_CNFG_START          = 1021,
    IOP_AS_USER_CNFG_PACKET         = 1022,

    IOP_END_OF_ACTIVE_SYNC          = 1049,

    /*------------------------------------------------------
    Hard drive temperature sensor reading
    ------------------------------------------------------*/
    IOP_HD_TEMP                     = 1050,

    /*------------------------------------------------------
    Audio volume level
    ------------------------------------------------------*/
    IOP_AUDIO_VOL_LEVEL             = 1051,
    IOP_AUDIO_AMP_MUTE              = 1052,
    IOP_AUDIO_EXT_MUTE              = 1053,

    /*------------------------------------------------------
    GFS File Mapping
    ------------------------------------------------------*/
    IOP_GFS_RGN_MAP                 = 1055,
    IOP_GFS_RGN_UNMAP               = 1056,
    IOP_GFS_RGN_MAP_RSLT            = 1057,

    /*------------------------------------------------------
    Bravo 2.0 Die ID
    ------------------------------------------------------*/
    IOP_DIE_ID                      = 1060,

    /*------------------------------------------------------
    Course Data for Fitness Products
    ------------------------------------------------------*/
    IOP_COURSE_DATA                 = 1061,
    IOP_COURSE_LAP_DATA             = 1062,
    IOP_COURSE_PNT_DATA             = 1063,
    IOP_COURSE_TRK_HDR              = 1064,
    IOP_COURSE_TRK_DATA             = 1065,
    IOP_COURSE_LMT_DATA             = 1066,

    /*------------------------------------------------------
    USB inst id's
    ------------------------------------------------------*/
    IOP_TO_MASS_STRG_PRVT           = 1070,         /* Don't publish this.  Some units only support mass storage for Taiwan */
    IOP_TO_MASS_STRG_PUBLIC         = 1071,

    /*------------------------------------------------------
    FM Modulator ID
    ------------------------------------------------------*/
    IOP_FM_SET_FREQ                 = 1073,
    IOP_FM_SET_CHNL                 = 1074,
    IOP_FM_SET_OUTPUT               = 1075,
    IOP_FM_SET_HIPWR                = 1076,
    IOP_FM_SET_PWR_LVL              = 1077,

    /*------------------------------------------------------
    Localization Data
    ------------------------------------------------------*/
    IOP_LOCALE_SET                  = 1080,
    IOP_LOCALE_RQST                 = 1081,
    IOP_LOCALE_DATA                 = 1082,

    /*------------------------------------------------------
    External Interface ID
    ------------------------------------------------------*/
    IOP_COMPOSITE_SET_AUDIO_OUT     = 1085,
    IOP_COMPOSITE_SET_VIDEO_OUT     = 1086,

    /*------------------------------------------------------
    Park Brake ID
    ------------------------------------------------------*/
    IOP_PARK_BRAKE_DATA             = 1088,
    IOP_PARK_BRAKE_STS_RQST         = 1089,

    /*------------------------------------------------------
    Unit id verification data
    ------------------------------------------------------*/
    IOP_RQST_UNIT_ID_VRF_DATA       = 1090,
    IOP_UNIT_ID_VRF_DATA            = 1091,

    /*------------------------------------------------------
    RF Remote control data
    ------------------------------------------------------*/
    IOP_RF_REMOTE_ID_DATA           = 1092,

    /*------------------------------------------------------
    More unit id verification data
    ------------------------------------------------------*/
    IOP_STORE_UNIT_ID_VRF_DATA      = 1093,

    /*------------------------------------------------------
    Video switch data for ntsc/pal selection on GVN
    ------------------------------------------------------*/
    IOP_VIDEO_SWITCH_DATA           = 1100,

    /*------------------------------------------------------
    Sensor capability data
    ------------------------------------------------------*/
    IOP_SNSR_CAPABILITY_DATA        = 1101,

    /*------------------------------------------------------
    Calorie Burn Rate Data
    ------------------------------------------------------*/
    IOP_CAL_TBL                     = 1102,

    /*------------------------------------------------------
    Microphone detection data
    ------------------------------------------------------*/
    IOP_MIC_DETECT_DATA             = 1103,

    /*------------------------------------------------------
    Communication Port IDs
    ------------------------------------------------------*/
    IOP_SERIAL_DIAG_PORT_ENABLE     = 1104,
    IOP_SERIAL_SELF_TEST            = 1105,

    /*------------------------------------------------------
    Display Adjust IDs
    ------------------------------------------------------*/
    IOP_DSPL_PARAM_RQST             = 1111,
    IOP_DSPL_PARAM                  = 1112,

    /*------------------------------------------------------
    SiRF extended ephemeris data
    ------------------------------------------------------*/
    IOP_SIRF_EFIX_DATA              = 1116,
    IOP_SIRF_EFIX_IONO_DATA         = 1117,
    IOP_SIRF_EFIX_RQST              = 1118,

    /*------------------------------------------------------
    DC series data
    ------------------------------------------------------*/
    IOP_DC_MURS_POWER_DATA          = 1124,
    IOP_DC_WUSB_DATA                = 1125,
    IOP_DC_MURS_DATA                = 1126,
    IOP_DC_FLASH_READ               = 1127,
    IOP_DC_FLASH_WRITE              = 1128,
    IOP_DC_FLASH_ERASE              = 1129,
    IOP_DC_FLASH_DATA               = 1130,
    IOP_DC_FLASH_WRITE_VERIFY       = 1131,
    IOP_DC_FLASH_ERASE_VERIFY       = 1132,
    IOP_DC_BATT_DATA                = 1133,
    IOP_DC_ACCEL_DATA               = 1134,
    IOP_DC_MURS_MODE_DATA           = 1135,
    IOP_DC_MURS_FREQ_ADJ_DATA       = 1136,
    IOP_DC_EEPROM_READ              = 1137,
    IOP_DC_EEPROM_WRITE             = 1138,
    IOP_DC_EEPROM_DATA              = 1139,
    IOP_DC_EEPROM_WRITE_VERIFY      = 1140,
    IOP_DC_BATT_READ                = 1141,
    IOP_DC_FLASH_DATA_TRK_HEADER    = 1142,
    IOP_DC_SEND_ACCEL_DATA          = 1143,
    IOP_DC_LED_CTRL                 = 1144,
    IOP_DC_HOLD_IN_RESET            = 1145,
    IOP_DC_SW_UPGRD_CMLPT           = 1146,
    IOP_DC_BATT_WRITE               = 1147,
    IOP_DC_BATT_WRITE_VERIFY        = 1148,
    IOP_DC_MODEL_INFO               = 1149,

    /*------------------------------------------------------
    Instrumentation ID for gyro bias data to COM monitor.
    ------------------------------------------------------*/
    IOP_GYRO_UPDATE_DATA            = 1150,

    /*------------------------------------------------------
    VLRP-protocol data
    ------------------------------------------------------*/
    IOP_VLRP_HWM_CFG_DATA           = 1151,
    IOP_VLRP_CFG_DATA               = 1152,
    IOP_VLRP_PROTECTED_CFG_DATA     = 1153,

    /*------------------------------------------------------
    Mount Detection data
    ------------------------------------------------------*/
    IOP_MOUNT_DETECT_DATA           = 1155,
    IOP_SMNT_DETECT_DATA            = 1156,

    /*------------------------------------------------------
    TouchScreen Linearization Data
    ------------------------------------------------------*/
    IOP_TS_LIN_DATA                 = 1160,
    IOP_TS_FIRMWARE_VER_STR         = 1161,

    /*------------------------------------------------------
    Distributed System Messaging
    ------------------------------------------------------*/
    IOP_DSM_DATA                    = 1165,

    /*------------------------------------------------------
    More ADC ids
    ------------------------------------------------------*/
    IOP_ADC_CAL_DATA                = 1180,

    /*------------------------------------------------------
    Marine Network Data Server
    ------------------------------------------------------*/
    IOP_DS_INST_START               = 1185,

    /* data from the data server         */
    IOP_DS_TEMP_DATA                = 1185,
    IOP_DS_VOLT_DATA                = 1186,
    IOP_DS_EVNT_DATA                = 1187,
    IOP_DS_VER_STR                  = 1188,
    IOP_DS_SW_STR                   = 1189,
    IOP_DS_INFO_RQST                = 1190,
    IOP_DS_INST_ID                  = 1191,
    IOP_DS_INST_DATA                = 1192,
    IOP_DS_INST_END                 = 1195,

    /*------------------------------------------------------
    Remote GPS debug information.
    ------------------------------------------------------*/
    IOP_REMOTE_GPS_DEBUG            = 1196,
    IOP_REMOTE_GPS_DEBUG_NMEA       = 1197,
    IOP_REMOTE_GPS_DEBUG_MTG        = 1198,
    IOP_REMOTE_GPS_DEBUG_MTS        = 1199,

    /*------------------------------------------------------
    PCB information and IDs
    ------------------------------------------------------*/
    IOP_PCB_GPN                     = 1200,
    IOP_PCB_VERSION                 = 1201,
    IOP_PCB_DISPLAY_TYPE            = 1202,
    IOP_PCB_INVENTORY_DATA          = 1203,


    /*------------------------------------------------------
    Command to assert/de-assert ACC_ON line
    ------------------------------------------------------*/
    IOP_ACC_ON_DATA                 = 1210,

    /*------------------------------------------------------
    Current back light level
    ------------------------------------------------------*/
    IOP_BACK_LIGHT_LEVEL_DATA       = 1211,

    /*------------------------------------------------------
    Variable capacitor information
    ------------------------------------------------------*/
    IOP_RQST_VAR_CAP                = 1212,
    IOP_SET_VAR_CAP                 = 1213,
    IOP_VAR_CAP_DATA                = 1214,

    /*------------------------------------------------------
    Product number data
    ------------------------------------------------------*/
    IOP_PRD_NUM_SET                  = 1215,
    IOP_PRD_NUM_DATA                 = 1216,

    /*------------------------------------------------------
    Product number data
    ------------------------------------------------------*/
    IOP_BRD_REV_SET                  = 1217,
    IOP_BRD_REV_DATA                 = 1218,

    /*------------------------------------------------------
    Software Information
    ------------------------------------------------------*/
    IOP_SW_INFO_RQST                 = 1219,
    IOP_SW_INFO_DATA                 = 1220,

    /*------------------------------------------------------
    Marine Sensor Instrumentation IDs
    ------------------------------------------------------*/
    IOP_MRN_SNSR_INST_START                 = 1221,  /* Marker only */

    /*------------------------------------------------------
    Garmin Fuel and Fluid Level Sensors
    ------------------------------------------------------*/
    IOP_MNR_SNSR_FUEL_SNSR_START            = 1221,  /* Marker only */

    IOP_MRN_SNSR_FUEL_SNSR_HEARTBEAT        = 1221,  /* Heartbeat from GFS */
    IOP_MRN_SNSR_FUEL_LVL_SET_REGION        = 1222,  /* Sets the region of the fuel level */
    IOP_MRN_SNSR_FUEL_FLOW_SET_PLACEMENT    = 1223,  /* Sensor placement (flow direction) (to GFS) */

    IOP_MRN_SNSR_FUEL_LVL_CAL_INIT          = 1224,  /* Initialize for calibration */
    IOP_MRN_SNSR_FUEL_LVL_CAL_DATA          = 1225,  /* Calibrate the GFS level sender */

    IOP_MRN_SNSR_FUEL_LVL_TEST_START        = 1227,  /* Configure hardware for Test Mode */
    IOP_MRN_SNSR_FUEL_LVL_TEST_DATA         = 1228,  /* Raw level data output during Test Mode */

    IOP_MRN_SNSR_FUEL_FLOW_TEST_DATA        = 1229,  /* Fuel flow expressed in Hz */
    IOP_MRN_SNSR_FUEL_FLOW_xCU_M_PER_HR     = 1230,  /* Fuel flow in 10^-4 cubic meters per hour */
    IOP_MRN_SNSR_FUEL_FLOW_CNTR_TALLY       = 1231,  /* Total number of fuel flow ticks */
    IOP_MRN_SNSR_FUEL_FLOW_RESET_TALLY      = 1232,  /* Reset the tally */

    IOP_MRN_SNSR_FUEL_FLOW_SET_MULT         = 1233,  /* Set the fuel flow multiplier */
    IOP_MRN_SNSR_FUEL_SNSR_GAUGE_TYPE_SET   = 1234,  /* Set the gauge type */
    IOP_MRN_SNSR_FUEL_LVL_MULTI_CAL         = 1235,  /* set multiple level calibration points */

    IOP_MRN_SNSR_FUEL_FLOW_FACTORY_CAL      = 1236,  /* set the factory flow cal table */

    IOP_MRN_SNSR_FUEL_SNSR_END              = 1239,  /* Marker only */
    /*------------------------------------------------------
    Garmin Fuel Sensor End
    ------------------------------------------------------*/

    /*------------------------------------------------------
    Garmin Marine Autopilot 1

        NOTE: This is the first set of Inst IDs for the Autopilot.

              Set 1 starts at 1240.
              Set 2 starts at 1300.
              Set 3 starts at 1683.
              Set 4 starts at 1881
              Set 5 starts at 5903
    ------------------------------------------------------*/
    IOP_MRN_SNSR_AUP_SNSR_BEGIN             = 1240,  /* Marker only */

    IOP_MRN_SNSR_AUP_HEARTBEAT              = 1240,
    IOP_MRN_SNSR_AUP_EVENT                  = 1241,
    IOP_MRN_SNSR_AUP_CNFG                   = 1242,

    IOP_MRN_SNSR_AUP_MTR_VOLT               = 1243,
    IOP_MRN_SNSR_AUP_MTR_CRNT               = 1244,
    IOP_MRN_SNSR_AUP_PUMP_ID                = 1245,
    IOP_MRN_SNSR_AUP_PUMP_ENBL              = 1246,
    IOP_MRN_SNSR_AUP_PUMP_DIR               = 1247,
    IOP_MRN_SNSR_AUP_PUMP_PWM               = 1248,

    IOP_MRN_SNSR_AUP_FLOW_SWITCH            = 1249,
    IOP_MRN_SNSR_AUP_CMPS_INFO              = 1250,

    IOP_MRN_SNSR_AUP_CMPS_PWM               = 1251,
    IOP_MRN_SNSR_AUP_CMPS_POT               = 1252,

    IOP_MRN_SNSR_AUP_GYRO_OUT               = 1253,
    IOP_MRN_SNSR_AUP_CMPS_OUT               = 1254,

    IOP_MRN_SNSR_AUP_CALIB_STATUS           = 1255,

    IOP_MRN_SNSR_AUP_TACH_OUT               = 1256,
    IOP_MRN_SNSR_AUP_HORN                   = 1257,

    IOP_MRN_SNSR_AUP_DECK_LED               = 1258,
    IOP_MRN_SNSR_AUP_RUDDER_RATE            = 1259,

    IOP_MRN_SNSR_AUP_SNSR_END               = 1259,  /* Marker only */
    /*-----------------------------------------------------*/


    /*------------------------------------------------------
    Generic Garmin Sensor
    ------------------------------------------------------*/
    IOP_MRN_SNSR_GNRC_BEGIN                 = 1260,  /* Marker only */

    IOP_MRN_SNSR_GNRC_CNFG                  = 1260,  /* Sensor configuration string */
    IOP_MRN_SNSR_RQST_CAPABILITIES          = 1261,  /* Capabilities Request */
    IOP_MRN_SNSR_CAPABILITIES               = 1262,  /* Capabilities Response */
    IOP_MRN_SNSR_DATA_BROADCAST_ENABLE      = 1263,  /* Enable/disable data broadcast */
    IOP_MRN_SNSR_EXTENDED_CNFG              = 1264,  /* Extended Configuration Response */

    IOP_MRN_SNSR_GNRC_END                   = 1273,  /* Marker only */

    /*------------------------------------------------------
    Garmin NMEA2000 Adapter
    ------------------------------------------------------*/
    IOP_MRN_SNSR_ADAPTER_START              = 1274,  /* Marker only */

    IOP_MRN_SNSR_ADAPTER_TEST_DATA          = 1274,  /* Raw level data output during Test Mode */
    IOP_MRN_SNSR_ADAPTER_CMD_TEST           = 1275,  /* Command data during Test Mode */
    IOP_MRN_SNSR_ADAPTER_HEARTBEAT          = 1276,  /* Heartbeat from GNA */

    IOP_MRN_SNSR_ADAPTER_END                = 1279,  /* Marker only */

    /*------------------------------------------------------
    Garmin Wind Sensor
    ------------------------------------------------------*/
    IOP_MNR_SNSR_WIND_SNSR_START            = 1280,  /* Marker only */

    IOP_MRN_SNSR_WIND_SPEED_TEST_DATA       = 1280,  /* Wind Speed expressed in Hz */
    /*-----------------------------------------------------------------------
    no longer used
    IOP_MRN_SNSR_WIND_SPEED_CNTR_TALLY      = 1281,     Total number of wind speed ticks
    -----------------------------------------------------------------------*/

    IOP_MRN_SNSR_WIND_SPD_FACTORY_CAL       = 1282,  /* Factory calibration of wind speed */

    IOP_MRN_SNSR_WIND_DIR_TEST_DATA         = 1283,  /* Raw direction ADC */

    IOP_MRN_SNSR_WIND_SNSR_HEARTBEAT        = 1284,  /* Heartbeat from GWS */

    IOP_MRN_SNSR_WIND_SNSR_APP_WIND_RAW     = 1285,  /* Unfiltered Apparent Wind Data (internal structure N2k PGN 130306) */

    IOP_MRN_SNSR_WIND_SNSR_RSSI_DATA        = 1286,  /* Received Signal Strength Indicator Data (gWind Wireless) */

    IOP_MRN_SNSR_WIND_SNSR_END              = 1299,  /* Marker only */
    /*------------------------------------------------------
    Garmin Wind Sensor End
    ------------------------------------------------------*/

    /*------------------------------------------------------
    Garmin Marine Autopilot 2

        NOTE: This is the Second set of Inst IDs for the Autopilot.

              Set 1 starts at 1240.
              Set 2 starts at 1300.
              Set 3 starts at 1683.
              Set 4 starts at 1881
              Set 5 starts at 5903
    ------------------------------------------------------*/
    IOP_MRN_SNSR_AUP_SNSR_2_BEGIN                    = 1300,  /* Marker only */

    IOP_MRN_SNSR_AUP_PRDC_INFO                       = 1300,  /* Perodic Info packet */
    IOP_MRN_SNSR_AUP_ERROR                           = 1301,  /* autopilot error     */
    IOP_MRN_SNSR_AUP_WARNING                         = 1302,  /* autopilot warning   */
    IOP_MRN_SNSR_AUP_GHC_HEARTBEAT                   = 1303,  /* Heartbeat sent from a Garmin Helm Controller */
    IOP_MRN_SNSR_AUP_PUMP_DSPLCMNT                   = 1304,  /* Pump Displacement   */
    IOP_MRN_SNSR_AUP_GYRO_SCALE                      = 1305,  /* Gyro Scale          */
    IOP_MRN_SNSR_AUP_GYRO_CAL                        = 1306,  /* Gyro Calibration    */
    IOP_MRN_SNSR_AUP_COMPASS_CAL                     = 1307,  /* Compass Calibration data */
    IOP_MRN_SNSR_AUP_ERROR_LOG                       = 1308,  /* Error Log           */
    IOP_MRN_SNSR_AUP_SHUTDOWN                        = 1309,  /* Shutdown message specific to Autopilot Helm Controllers */
    IOP_MRN_SNSR_AUP_ADVANCE_PUMP                    = 1310,  /* Advance pump value used for sloppy liknage comp         */
    IOP_MRN_SNSR_AUP_COMPASS_CAL_DIAG_THRESHOLD_CNTS = 1311,  /* Debugging messages used to output exceeding COS and SIN amplituded thresholds */
    IOP_MRN_SNSR_AUP_TEST_WVFM                       = 1312,  /* Test waveform to determine boat dynamics */
    IOP_MRN_SNSR_AUP_DESIRED_RUDDER_ANGLE_TEST       = 1313,  /* Desired rudder angle used for testing  */
    IOP_MRN_SNSR_AUP_CLUTCH_CURRENT                  = 1314,  /* Current clutch current */
    IOP_MRN_SNSR_AUP_TUNING_MODE_SET                 = 1315,  /* Set the Autopilot Tuning Mode */
    IOP_MRN_SNSR_AUP_RUDDER_POSITION                 = 1316,  /* Rudder Position Feedback */
    IOP_MRN_SNSR_AUP_TACK_GYBE_DELAY                 = 1317,  /* Tack/Gybe Delay Time Remaining */
    IOP_MRN_SNSR_AUP_GYBE_INHIBIT_OVERRIDE_SET       = 1318,  /* Set the Gybe Inhibit Override flag */

    IOP_MRN_SNSR_AUP_SNSR_2_END                      = 1319,  /* Marker only */
    /*------------------------------------------------------*/

    IOP_MRN_SNSR_USER_CAL                   = 1320,  /* User calibration settings */

    /* GMI, GHC, and Intelligent Transducer */


    /*------------------------------------------------------
    GXM - Garmin XM receiver
    ------------------------------------------------------*/
    IOP_MRN_SNSR_XM_DATA_TEST               = 1321,  /* test mode data received?      */

    /*------------------------------------------------------
    NMEA2000 Adapters - Rudder Angle Adapter
    ------------------------------------------------------*/
    IOP_MRN_SNSR_RUDDER_ANGLE_BEGIN         = 1322, /* Marker only */

    IOP_MRN_SNSR_RUDDER_ANGLE_HEARTBEAT     = 1322, /* Heartbeat from Rudder Adapter                    */

    IOP_MRN_SNSR_RUDDER_MULTI_CAL           = 1323, /* Multiple Point Calibration Table                 */

    IOP_MRN_SNSR_RUDDER_ANGLE_GAUGE_TYPE_SET= 1324, /* Set the gauge type                               */

    IOP_MRN_SNSR_RUDDER_ANGLE_TEST_START    = 1325, /* Configure hardware for Test Mode                 */
    IOP_MRN_SNSR_RUDDER_RESISTIVE_TEST_DATA = 1326, /* Raw level data output during Test Mode           */
    IOP_MRN_SNSR_RUDDER_MAGNETIC_TEST_DATA  = 1327, /* Raw level data output during Test Mode           */

    IOP_MRN_SNSR_RUDDER_ANGLE_SENSOR_TYPE_SET=1328, /* Set the sensor type                              */

    IOP_MRN_SNSR_RUDDER_ANGLE_END           = 1332, /* Marker only */

    /*------------------------------------------------------
    NMEA2000 Adapters - Engine Tilt Adapter
    ------------------------------------------------------*/
    IOP_MRN_SNSR_ENGINE_TILT_BEGIN          = 1333, /* Marker only                                      */

    IOP_MRN_SNSR_ENGINE_TILT_HEARTBEAT      = 1333, /* Heartbeat from Engine Tilt Adapter               */

    IOP_MNR_SNSR_ENGINE_TILT_MULTI_CAL      = 1334, /* Set Calibration points for engine tilt sensor    */

    IOP_MRN_SNSR_ENGINE_TILT_GAUGE_TYPE_SET = 1335, /* Set the gauge type                               */

    IOP_MRN_SNSR_ENGINE_TILT_TEST_START     = 1336, /* Configure hardware for Test Mode                 */
    IOP_MRN_SNSR_ENGINE_RESISTIVE_TEST_DATA = 1337, /* Raw level data output during Test Mode           */
    IOP_MRN_SNSR_ENGINE_GENERIC_TEST_DATA   = 1338, /* Raw level data output during Test Mode           */

    IOP_MRN_SNSR_ENGINE_TILT_SENSOR_TYPE_SET= 1339, /* Set the sensor type                              */

    IOP_MRN_SNSR_ENGINE_TILT_END            = 1343, /* Marker only                                      */

    /*------------------------------------------------------
    NMEA2000 Adapters - Fluid Level Adapter

    Re-useing several instances from the Garmin Fuel Sensor
    (see 1221).
    ------------------------------------------------------*/
    IOP_MRN_SNSR_FLUID_LEVEL_BEGIN          = 1344, /* Marker only                                      */

    IOP_MRN_SNSR_FLUID_LEVEL_HEARTBEAT      = 1344, /* Heartbeat from Fluid Level Adapter               */

    IOP_MRN_SNSR_FLUID_LEVEL_SENSOR_TYPE_SET= 1345, /* Set the sensor type                              */

    IOP_MRN_SNSR_FLUID_LEVEL_END            = 1354, /* Marker only                                      */

    /*------------------------------------------------------
    NMEA2000 Adapters - Bennett Trim Tab Adapter
    ------------------------------------------------------*/
    IOP_MNR_SNSR_TRIM_TAB_SNSR_START        = 1355, /* Marker only                                      */

    IOP_MRN_SNSR_TRIM_TAB_HEARTBEAT         = 1355, /* Heartbeat from Bennett Trim Tab Adapter          */

    IOP_MRN_SNSR_TRIM_TAB_CAL_INIT          = 1356, /* Start Calibarting Trim Tab                       */
    IOP_MRN_SNSR_TRIM_TAB_MULTI_CAL         = 1357, /* Send calibration points to trim tab sensor       */
    IOP_MRN_SNSR_TRIM_TAB_CAL_PNT_TBL       = 1358, /* Calibration point table from Trim Tab Sensor     */

    IOP_MRN_SNSR_TRIM_TAB_PORT_TEST_DATA    = 1359, /* Raw level data output during Test Mode           */
    IOP_MRN_SNSR_TRIM_TAB_STBD_TEST_DATA    = 1360, /* Raw level data output during Test Mode           */

    IOP_MRN_SNSR_SET_TRIM_TAB_OSCILLATION   = 1361, /* Set oscillation circuit TRUE=ON, FALSE=OFF       */

    IOP_MRN_SNSR_TRIM_TAB_SNSR_END          = 1365, /* Marker only                                      */

    /*------------------------------------------------------
    NMEA2000 Adapters - Water Speed & Temperature Adapter
    ------------------------------------------------------*/
    IOP_MRN_SNSR_WTRSPD_AND_TEMP_BEGIN      = 1366, /* Marker only                                      */

    IOP_MRN_SNSR_WTRSPD_AND_TEMP_HEARTBEAT  = 1366, /* Heartbeat from Water Speed & Temperature Adapter */

    IOP_MRN_SNSR_WTRSPD_CAL_START           = 1367, /* Water Speed Sensor Start Calibration             */
    IOP_MRN_SNSR_WTRSPD_CAL_PNT             = 1368, /* Water Speed Sensor set calibration point         */

    IOP_MRN_SNSR_WTRSPD_CAL_TBL_REQ         = 1369, /* Water Speed Sensor Request cal table             */
    IOP_MRN_SNSR_WTRSPD_CAL_TBL_RESP        = 1370, /* Water Speed Sensor Responce with cal table       */
    IOP_MRN_SNSR_WTRSPD_CAL_TBL_SET         = 1371, /* Water Speed Sensor Set cal table                 */

    IOP_MRN_SNSR_WTRSPD_AND_TEMP_END        = 1376, /* Marker only                                      */

    /*------------------------------------------------------
    NMEA2000 Adapters - GSM/GDL IDs
    ------------------------------------------------------*/
    IOP_MRN_SNSR_GSM_START                  = 1377, /* Marker only                                      */

    IOP_MRN_SNSR_GSM_EXT_ANT_ENBL           = 1377, /* Enable/disable external antenna                  */
    IOP_MRN_SNSR_GSM_STATUS                 = 1378, /* Heartbeat                                        */
    IOP_MRN_SNSR_GSM_WX_RQST                = 1379, /* weather request                                  */
    IOP_MRN_SNSR_GSM_WX_DATA                = 1380, /* weather data                                     */
    IOP_MRN_SNSR_GSM_WX_PURCHASE            = 1381, /* purchase weather                                 */
    IOP_MRN_SNSR_GSM_SET_LOG_MODE           = 1382, /* set log mode                                     */
    IOP_MRN_SNSR_GSM_ERROR                  = 1383, /* report an error                                  */
    IOP_MRN_SNSR_GSM_ZONE_RQST              = 1384, /* zone cartography request                         */
    IOP_MRN_SNSR_GSM_DIAG                   = 1385, /* Diagnostic data and request                      */
    IOP_MRN_SNSR_GSM_DATA_TEST_RQST         = 1386, /* Request data download test through GCS           */
    IOP_MRN_SNSR_GSM_TEST_DATA              = 1387, /* Test data from GCS                               */

    IOP_MRN_SNSR_GSM_END                    = 1400, /* Marker only                                      */

    /*------------------------------------------------------
    Garmin Network Cameras
    ------------------------------------------------------*/
    IOP_MRN_CAM_START                       = 1401, /* Marker only                                      */
    IOP_MRN_CAM_DATA_SET                    = 1401, /* Marine Camera Setting Set                        */
    IOP_MRN_CAM_DATA_RQST                   = 1402, /* Marine Camera Setting Request                    */
    IOP_MRN_CAM_DATA_RESP                   = 1403, /* Marine Camera Setting Data                       */
    IOP_MRN_CAM_HEARTBEAT                   = 1404, /* Marine Camera Heartbeat                          */
    IOP_MRN_CAM_CONTROL_SET                 = 1405, /* Marine Camera Control Set                        */
    IOP_MRN_CAM_CONTROL_RESP                = 1406, /* Marine Camera Control Response                   */
    IOP_MRN_CAM_PRESET_CMND                 = 1407, /* Marine Camera Preset Command                     */
    IOP_MRN_CAM_PRESET_CMND_RESP            = 1408, /* Marine Camera Preset Command Response            */
    IOP_MRN_CAM_STANDBY_CTRL                = 1409, /* Marine Camera Standby Control                    */

    IOP_MRN_CAM_END                         = 1420, /* Marker only                                      */
    /*------------------------------------------------------
    Garmin Network Cameras End
    ------------------------------------------------------*/

    /*------------------------------------------------------
    Alarm Network Synchronization Instrumentation IDs
    ------------------------------------------------------*/
    IOP_MRN_NET_ALARM_SYNC                  = 1421,

    /*------------------------------------------------------
    WiFi Router Instrumentation IDs
    ------------------------------------------------------*/
    IOP_MRN_WIFI_ROUTER_INST_BEGIN              = 1422, /* Marker Only                                  */
    IOP_MRN_WIFI_ROUTER_RQST_CNFG_DATA          = 1423, /* Request router configurations                */
    IOP_MRN_WIFI_ROUTER_LAN_CNFG_DATA           = 1424, /* Set/Get router LAN configurations            */
    IOP_MRN_WIFI_ROUTER_AP_CNFG_DATA            = 1425, /* Set/Get router AP configurations             */
    IOP_MRN_WIFI_ROUTER_REPEATER_CNFG_DATA      = 1426, /* Set/Get router REPEATER configurations       */
    IOP_MRN_WIFI_ROUTER_AUTOJOIN_CNFG_DATA      = 1427, /* Set/Get router AUTOJOIN configurations       */
    IOP_MRN_WIFI_ROUTER_DFLT_GATEWAY_CNFG_DATA  = 1428, /* Inform MFDs of what default gateway to use   */
    IOP_MRN_WIFI_ROUTER_WAN_CNFG_DATA           = 1429, /* Set/Get router WAN configurations            */
    IOP_MRN_WIFI_ROUTER_WAN_DHCP_CNFG_DATA      = 1430, /* Set/Get router WAN DHCP configurations       */
    IOP_MRN_WIFI_ROUTER_WAN_PPPOE_CNFG_DATA     = 1431, /* Set/Get router WAN PPPOE configurations      */
    IOP_MRN_WIFI_ROUTER_WAN_STATIC_IP_CNFG_DATA = 1432, /* Set/Get router WAN Static IP configurations  */
    IOP_MRN_WIFI_ROUTER_WAN_USB_CNFG_DATA       = 1433, /* Set/Get router WAN USB configurations        */
    IOP_MRN_WIFI_ROUTER_WAN_WIFI_CNFG_DATA      = 1434, /* Set/Get router WAN WiFi configurations       */
    IOP_MRN_WIFI_ROUTER_CAPTIVE_PORTAL_NOTIFY   = 1435, /* Notify MFDs there's captive portal           */
    IOP_MRN_WIFI_ROUTER_WAN_STATUS_DATA         = 1436, /* Notify MFDs of WAN status                    */
    IOP_MRN_WIFI_ROUTER_STATUS_DATA             = 1437, /* Notify MFDs of router's status               */
    IOP_MRN_WIFI_ROUTER_HEARTBEAT_DATA          = 1438, /* Router heartbeat                             */
    IOP_MRN_WIFI_ROUTER_NO_UPDATE               = 1439, /* Notify MFDs no update is needed              */
    IOP_MRN_WIFI_ROUTER_NEED_UPDATE_DL          = 1440, /* Notify MFDs update with download             */
    IOP_MRN_WIFI_ROUTER_NEED_UPDATE             = 1441, /* Notify MFDs update without download          */
    IOP_MRN_WIFI_ROUTER_UPDATE_DL_PROGRESS      = 1442, /* Report the download progress                 */
    IOP_MRN_WIFI_ROUTER_UPDATE_DL_DONE          = 1443, /* Notify MFDs download is complete             */
    IOP_MRN_WIFI_ROUTER_UPDATE_START            = 1444, /* Start SW update process                      */
    IOP_MRN_WIFI_ROUTER_INST_END                = 1460, /* Marker Only                                  */

    /*------------------------------------------------------
    Reserved for Media Black Box Instrumentation IDs
    ------------------------------------------------------*/
    IOP_MRN_MBB_INST_BEGIN                  = 1461, /* Marker only                                      */
    IOP_MRN_MBB_RQST                        = 1461, /* Media Black Box Request                          */
    IOP_MRN_MBB_RESP                        = 1462, /* Media Black Box Response                         */
    IOP_MRN_MBB_HEARTBEAT                   = 1463, /* Media Black Box Heartbeat                        */
    IOP_MRN_MBB_WAKEUP                      = 1464, /* Media Black Box Wake-Up                          */
    IOP_MRN_MBB_SLEEP                       = 1465, /* Media Black Box Sleep                            */
    IOP_MRN_MBB_INST_END                    = 1476, /* Marker only                                      */

    /*------------------------------------------------------
    Reserved for Bridge Sensor Datastream module
    ------------------------------------------------------*/
    IOP_MRN_BRIDGE_DATASTREAM               = 1477, /* DDF message that may contain various sensor data */

    /*------------------------------------------------------
    J1939 Bridge Data
    ------------------------------------------------------*/
    IOP_MRN_J1939_BRIDGE_DATA               = 1478, /* Bridged J1939 CAN data                           */

    /*------------------------------------------------------
    End of Marine Sensor Instrumentation IDs
    ------------------------------------------------------*/
    IOP_MARINE_SENSOR_INST_END              = 1499,  /* Marker only */

    /*------------------------------------------------------
    Jump to System code
    ------------------------------------------------------*/
    IOP_JUMP_SYS                    = 1500,

    /*------------------------------------------------------
    Initial fix date data
    ------------------------------------------------------*/
    IOP_IFIX_DATE_DATA              = 1501,

    /*------------------------------------------------------
    Shared settings.
    ------------------------------------------------------*/
    IOP_SHARE_SETTING_ID            = 1502,

    /*------------------------------------------------------
    User File Transfer
    ------------------------------------------------------*/
    IOP_FILE_XFER_HDR               = 1503,
    IOP_FILE_XFER_DATA              = 1504,
    IOP_FILE_XFER_RSLT              = 1505,

    /*------------------------------------------------------
    Task reporting
    ------------------------------------------------------*/
    IOP_TSK_INFO                    = 1506,

    /*------------------------------------------------------
    TMC antenna data passed through a GPS unit
    ------------------------------------------------------*/
    IOP_TMC_PSS_THRGH_ID            = 1507,

    /*------------------------------------------------------
    Map Update Nag Date
    ------------------------------------------------------*/
    IOP_MAPUP_DATE                  = 1508,

    /*------------------------------------------------------
    New fitness goal data
    ------------------------------------------------------*/
    IOP_GOAL_DATA                   = 1509,

    /*------------------------------------------------------
    New track data with multiple points per message
    ------------------------------------------------------*/
    IOP_TRK_DATA_MULTI              = 1510,
    IOP_COURSE_TRK_DATA_MULTI       = 1511,

    /*------------------------------------------------------
    Dummy packet ID for Forerunner 50 data.
    ------------------------------------------------------*/
    IOP_FR50_DATA                   = 1515,

    /*------------------------------------------------------
    IOP records packet with cmnd ID added.
    ------------------------------------------------------*/
    IOP_RECORDS_WITH_CMND           = 1516,

    /*------------------------------------------------------
    Flash serial number
    ------------------------------------------------------*/
    IOP_FLASH_SNUM                  = 1517,

    /*------------------------------------------------------
    Flash info stored in SD/MMC CID register
    ------------------------------------------------------*/
    IOP_FLASH_MID                   = 1518,     /* Flash Manufacturer ID        */
    IOP_FLASH_OID                   = 1519,     /* Flash OEM/Application ID     */
    IOP_FLASH_PNM                   = 1520,     /* Flash Product Name           */
    IOP_FLASH_PRV                   = 1521,     /* Flash Product Revision       */
    IOP_FLASH_MDT                   = 1522,     /* Flash Manufacturing Date     */

    /*------------------------------------------------------
    ANTLink timeout data
    ------------------------------------------------------*/
    IOP_ALINK_TIMEOUT_DATA          = 1523,

    /*------------------------------------------------------
    Signed data matching an ESN to a die ID
    ------------------------------------------------------*/
    IOP_SIGNED_ESN_DATA             = 1524,

    /*------------------------------------------------------
    Bravo4 GPS IDs.
    ------------------------------------------------------*/
    IOP_RMT_GPS_SAT_BRDCST_ENBL     = 1525,
    IOP_RMT_GPS_SAT_BRDCST_DSBL     = 1526,
    IOP_RMT_GPS_SAT_EPH_CLR         = 1527,
    IOP_RMT_GPS_WALKING_MODE        = 1528,
    IOP_B4_GPS_RSVD5                = 1529,
    IOP_B4_GPS_RSVD6                = 1530,
    IOP_B4_GPS_RSVD7                = 1531,
    IOP_B4_GPS_RSVD8                = 1532,
    IOP_B4_GPS_JAM_TEST_OFF         = 1533,
    IOP_B4_GPS_JAM_TEST             = 1534,

    /*------------------------------------------------------
    Start of next instrumentation ID group.
    ------------------------------------------------------*/
    IOP_RTC_ACC_DATA                = 1535,

    /*------------------------------------------------------
    Minimum GPS data needed for factory testing.
    ------------------------------------------------------*/
    IOP_GPS_MIN_TEST_DATA           = 1536,

    /*------------------------------------------------------
    Efield test data.
    ------------------------------------------------------*/
    IOP_EFIELD_TEST_DATA            = 1537,

    /*------------------------------------------------------
    Select mic input source
    ------------------------------------------------------*/
    IOP_MIC_SOURCE_SELECT           = 1538,

    /*------------------------------------------------------
    MTK BEE ID group
    -----------------------------------------------------*/
    IOP_MTK_BEE_BCAST_RX_ACK        = 1539,
    IOP_MTK_BEE_PRED_DATA           = 1540,
    IOP_MTK_BEE_AVBL_MASK           = 1541,
    IOP_MTK_BEE_RQST_HSHAKE         = 1542,
    IOP_MTK_BEE_RQST_BEE_UPLD       = 1543,
    IOP_MTK_BEE_BCAST_DATA          = 1544,

    /*------------------------------------------------------
    Touch Screen Calibration
    ------------------------------------------------------*/
    IOP_TCHSCRN_CAL_COMPLETE        = 1545,

    /*------------------------------------------------------
    Accelerometer/Magnetometer
    ------------------------------------------------------*/
    IOP_ACCEL_CMND_DATA             = 1548,
    IOP_MAG_CMND_DATA               = 1549,
    IOP_ACCEL_DATA                  = 1550,
    IOP_MAG_DATA                    = 1551,

    /*------------------------------------------------------
    Local pressure calibration data
    ------------------------------------------------------*/
    IOP_LOCAL_PRESS_DATA            = 1552,

    /*------------------------------------------------------
    Navigation data - DEPRECATED

    This inst ID was created as a proprietary means for
    passing Navigation data on the Marine N2K bus. This
    functionality has fallen apart and this ID should no
    longer be used.  Use IOP_NAV_PROP_DATA instead
    ------------------------------------------------------*/
    IOP_NAV_DATA_DEPRECATED         = 1553,

    /*------------------------------------------------------
    Marine System-wide MOB
    ------------------------------------------------------*/
    IOP_MRN_SYS_WIDE_MOB_CAPTURE    = 1554,
    IOP_MRN_SYS_WIDE_MOB_ACTIVATE   = 1555,
    IOP_MRN_SYS_WIDE_MOB_CNCL_GLBL  = 1556,
    IOP_MRN_SYS_WIDE_MOB_DLG_OPEN   = 1557,
    IOP_MRN_SYS_WIDE_MOB_CNCL_CAT   = 1558,

    IOP_MRN_SYS_WIDE_MOB_LAST       = 1559,

    /*------------------------------------------------------
    Sensor Calibration
    ------------------------------------------------------*/
    IOP_ACCEL_CAL_DATA              = 1560,
    IOP_MAG_CAL_DATA                = 1561,


    /*------------------------------------------------------
    Accustic Tech Rapid audio tunning tool
    -----------------------------------------------------*/
    IOP_ATI_RAPID_CMD               = 1562,
    IOP_ATI_RAPID_LOG               = 1563,

    /*------------------------------------------------------
    Set the touch panel/screen pressure threshold.
    -----------------------------------------------------*/
    IOP_SET_TCH_PNL_PRSSR_THRSHLD   = 1564,

    /*----------------------------------------------------
    Garmin Online
    ------------------------------------------------------*/
    IOP_GRMN_ONLINE_REQUEST         = 1565,
    IOP_GRMN_ONLINE_RESPONSE        = 1566,

    /*----------------------------------------------------
    Marine OEM IDs
    ------------------------------------------------------*/
    IOP_MARINE_OEM_ID               = 1567,

    /*------------------------------------------------------
    Send sytem information data
    ------------------------------------------------------*/
    IOP_SYS_INFO_DATA               = 1568,

    /*------------------------------------------------------
    Command a device to send a DSC call
    ------------------------------------------------------*/
    IOP_MRN_DSC_CALL_SEND           = 1569,

    /*------------------------------------------------------
    ANT Remote Test Mode Data
    ------------------------------------------------------*/
    IOP_ANT_RMT_ID                  = 1575,
    IOP_ANT_RMT_ADC                 = 1576,
    IOP_ANT_RMT_PHOTOCELL           = 1577,

    /*------------------------------------------------------
    Compass Calibration parameters
    ------------------------------------------------------*/
    IOP_CMPS_CAL_CAE_SCL_DATA           = 1578,
    IOP_CMPS_CAL_CAE_GEW_DATA           = 1579,
    IOP_CMPS_CAL_CAE_GNS_DATA           = 1580,
    IOP_CMPS_CAL_USER_XOFF_DATA         = 1581,
    IOP_CMPS_CAL_USER_YOFF_DATA         = 1582,
    IOP_CMPS_CAL_USER_MEAS_TO_GS_DATA   = 1583,
    IOP_CMPS_CAL_USER_FINISH            = 1584,
    IOP_CMPS_CAL_USER_CLR_OFF_REG       = 1585,
    IOP_CMPS_CAL_OFF_SET                = 1586,

    IOP_CMPS_CAL_END                    = 1589,

    /*------------------------------------------------------
    Aviation Portable Ids.
    ------------------------------------------------------*/
    IOP_EXT_ID_VOLTS                = 1590,
    IOP_EXT_LIGHT_BUS_VOLTS         = 1591,
    IOP_EXT_ID_VOLTS2               = 1592,
    IOP_EXT_GPS_ANT_STATE_CHNG      = 1593,

    /*------------------------------------------------------
    Phone IDs
    ------------------------------------------------------*/
    IOP_IMEI_DATA                   = 1600,
    IOP_WIFI_ADDR                   = 1601,

    /*------------------------------------------------------
    Master Clear Acknowledgement
    ------------------------------------------------------*/
    IOP_FLSH_MSTR_CLR_ACK           = 1602, /* device acknowledging the tool for master clear request */
    IOP_FLSH_MSTR_CLR_STATUS_ACK    = 1603,
    IOP_WHOAMI_ACK                  = 1604,

    /*------------------------------------------------------
    BTB connector test commands
    ------------------------------------------------------*/
    IOP_LCD_DATA_LINE_TEST          = 1605,

    /*------------------------------------------------------
    GPS RF control
    ------------------------------------------------------*/
    IOP_GPS_NOISE_CANCEL            = 1606,



    IOP_GPS_CONTROL_END             = 1620,

    /*------------------------------------------------------
    Camera control (continued at 1835)
    ------------------------------------------------------*/
    IOP_CAMERA_STATE_DATA           = 1621,
    IOP_CAMERA_DATA_ENABLE          = 1622,
    IOP_CAMERA_OP                   = 1623, /* Set Camera operation state */
    IOP_CAMERA_PIC_DATA_HDR         = 1624,
    IOP_CAMERA_PIC_DATA             = 1625,
    IOP_CAMERA_CABLE_STATUS         = 1626,
    IOP_CAMERA_RGB565_DATA          = 1627,
    IOP_CAMERA_FRAME_SIZE           = 1628,
    IOP_CAMERA_OP_DATA              = 1629, /* Provide Camera operation state */

    /*------------------------------------------------------
    UTF8 Console data (versus ASCII for IOP_CONSOLE_DATA)
    ------------------------------------------------------*/
    IOP_UNI_CONSOLE_DATA            = 1630,

    /*------------------------------------------------------
    Raw Accelerometer/Magnetometer Measurements
    ------------------------------------------------------*/
    IOP_ACCEL_RAW_DATA              = 1631,
    IOP_MAG_RAW_DATA                = 1632,

    /*------------------------------------------------------
    Proprietary Navigation Data
    ------------------------------------------------------*/
    IOP_NAV_PROP_DATA               = 1633,

    /*------------------------------------------------------
    User message acknowledgement data
    ------------------------------------------------------*/
    IOP_ACK_USER_MSG_DATA           = 1634,

    /*------------------------------------------------------
    Network page synchronization data
    ------------------------------------------------------*/
    IOP_PAGE_SYNC_DATA              = 1635,

    /*------------------------------------------------------
    Set the usage mode
    ------------------------------------------------------*/
    IOP_SET_USAGE_MODE              = 1636,

    /*------------------------------------------------------
    Battery Door Open Data
    -----------------------------------------------------*/
    IOP_BATT_DOOR_OPEN_DATA         = 1637,

    /*------------------------------------------------------
    WiFi Controls (continued at 1670)
    ------------------------------------------------------*/
    IOP_WIFI_RXTEST_START           = 1638,
    IOP_WIFI_RXTEST_DATA            = 1639,
    IOP_WIFI_TEST_SET_CHNL          = 1640,
    IOP_WIFI_TEST_SET_MOD           = 1641,
    IOP_WIFI_TEST_SET_PWR           = 1642,
    IOP_WIFI_TESTMODE_CHNG          = 1643,
    IOP_WIFI_TESTMODE_DATA          = 1644,
    IOP_WIFI_STATUS                 = 1645,
    IOP_WIFI_TXFR_DATA              = 1646,
    IOP_WIFI_CONNECT_NETWORK        = 1647,    /* See also ID 6370 for variable length string support */
    IOP_WIFI_DOWNLOAD_FILE          = 1648,

    /*------------------------------------------------------
    IIC Error Data
    ------------------------------------------------------*/
    IOP_IIC_ERROR_DATA              = 1649,

    /*------------------------------------------------------
    Mount SW Version Data
    ------------------------------------------------------*/
    IOP_MOUNT_BB_VER_DATA           = 1650,
    IOP_MOUNT_SYS_VER_DATA          = 1651,

    /*------------------------------------------------------
    Engine Max RPM data
    ------------------------------------------------------*/
    IOP_ENGN_MAX_RPM_DATA           = 1652,

    /*------------------------------------------------------
    Zero MBR of internal NAND
    -----------------------------------------------------*/
    IOP_CLR_MBR                     = 1661,
    IOP_CLR_MBR_DATA                = 1662,

    /*------------------------------------------------------
    MTK GPS testing
    ------------------------------------------------------*/
    IOP_MTK_PARAM_TEST_MODE         = 1664,
    IOP_MTK_LAST_RESERVED           = 1669,

    /*------------------------------------------------------
    WiFi Controls (continued from 1638)
    ------------------------------------------------------*/
    IOP_WIFI_UPLOAD_FILE            = 1670,
    IOP_WIFI_ENDPOINT_TEST          = 1671,
    IOP_WIFI_SET_MAC_ADDR           = 1672,
    IOP_WIFI_ADDR_DATA              = 1673,
    IOP_WIFI_SET_IP_ADDR            = 1674,
    IOP_WIFI_CONNECTION_INFO        = 1675,

    /*------------------------------------------------------
    Set Wi-Fi passphrase
    Warning: Only consider adding support for this ID to a
    product if a sufficient use case is justified and
    adequate protection from malicious use is in place.
    ------------------------------------------------------*/
    IOP_WIFI_SET_PSK                = 1676,

    /*------------------------------------------------------
    Show Test Results - ATE commands
    ------------------------------------------------------*/
    IOP_SHOWTESTRESULTS_PASS        = 1677,
    IOP_SHOWTESTRESULTS_FAIL        = 1678,

    /*------------------------------------------------------
    Play Audio Tone instruction
    ------------------------------------------------------*/
    IOP_AUDIO_PLAY_TONE             = 1679,

    /*------------------------------------------------------
    Phone command
    ------------------------------------------------------*/
    IOP_OPEN_MARKET_SET             = 1680,

    /*------------------------------------------------------
    PimSync packet data
    ------------------------------------------------------*/
    IOP_PIM_SYNC                    = 1681,

    /*-----------------------------------------------------
    IOP for Map info
    ------------------------------------------------------*/
    IOP_GET_MAP_PART_NUM_ACK        = 1682,



    /*------------------------------------------------------
    Garmin Marine Autopilot 3

        NOTE: This is the third set of Inst IDs for the Autopilot.

              Set 1 starts at 1240.
              Set 2 starts at 1300.
              Set 3 starts at 1683.
              Set 4 starts at 1881
              Set 5 starts at 5903
    ------------------------------------------------------*/
    IOP_MRN_SNSR_AUP_3_BEGIN                                    = 1683,  /* Marker only                                   */

    IOP_MRN_SNSR_AUP_DRIVE_UNIT_FULL_CNFG                       = 1683,  /* Drive Unit Full Configuration                 */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_FULL_CNFG_ACK                   = 1684,  /* Drive Unit ID Number                          */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_TUNING_CNFG                     = 1685,  /* Drive Unit Tuning Configuration Data          */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_TUNING_CNFG_ACK                 = 1686,  /* Drive Unit Tuning Configuration Acknowledgement */
    IOP_MRN_SNSR_AUP_CLUTCH_PWM_SET                             = 1687,  /* Directly sets the PWM of the clutch circuity (used in Test mode) */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_CLUTCH_INITIAL_PCNT_SET         = 1688,  /* Sets the Drive Unit Clutch Initial PWM Percentage */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_CLUTCH_INIT_TIME_SET            = 1689,  /* Sets the Drive Unit Clutch Init Time */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_CLUTCH_STDY_STATE_PCNT_SET      = 1690,  /* Sets the Drive Unit Clutch Steady State PWM Percentage */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_DETECTED                        = 1691,  /* Drive Unit Detected                           */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_RUDDER_RAIL_STAR_VOLT_SET_ACK   = 1692,  /* Drive Unit Rudder Rail Starboard Voltage Set Acknowledgement     */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_RUDDER_RAIL_PORT_VOLT_SET_ACK   = 1693,  /* Drive Unit Rudder Rail Port Voltage Set Acknowledgement          */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_RUDDER_DIR_CAL_BEGIN_ACK        = 1694,  /* Drive Unit Rudder Direction Calibration Begin Acknowledgement    */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_RUDDER_DIR_CAL_CMPLT_ACK        = 1695,  /* Drive Unit Rudder Direction Calibration Completed Acknowledgement */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_RUDDER_DIR_CAL_CANCEL_ACK       = 1696,  /* Drive Unit Rudder Direction Calibration Canceled Acknowledgement  */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_TEST_MODE_LED                   = 1697,  /* Drive Unit Test Mode LED                (ECU Rx) */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_TEST_MODE_FLOW_SWITCH           = 1698,  /* Drive Unit Test Mode Flow Switch        (ECU Tx) */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_TEST_MODE_MOTOR_ENABLE          = 1699,  /* Drive Unit Test Mode Motor Enable       (ECU Rx) */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_TEST_MODE_MOTOR_PWM             = 1700,  /* Drive Unit Test Mode Motor PWM          (ECU Rx) */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_TEST_MODE_MOTOR_DIR             = 1701,  /* Drive Unit Test Mode Motor Direction    (ECU Rx) */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_TEST_MODE_MOTOR_CURRENT         = 1702,  /* Drive Unit Test Mode Motor Current      (ECU Tx) */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_TEST_MODE_CLUTCH_PWM            = 1703,  /* Drive Unit Test Mode Clutch PWM         (ECU Rx) */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_TEST_MODE_CLUTCH_CURRENT        = 1704,  /* Drive Unit Test Mode Clutch Current     (ECU Tx) */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_TEST_MODE_CLUTCH_FAULT          = 1705,  /* Drive Unit Test Mode Clutch Fault       (ECU Tx) */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_TEST_MODE_RUDDER_FDBK           = 1706,  /* Drive Unit Test Mode Rudder Feedback    (ECU Tx) */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_TEST_MODE_ENCODER_SERIAL        = 1707,  /* Drive Unit Test Mode Encoder Serial     (ECU Tx) */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_TEST_MODE_PUMP_ID               = 1708,  /* Drive Unit Test Mode Pump ID            (ECU Tx) */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_LOCKUP_TEST                     = 1709,  /* Drive Unit Software Lockup Test                  */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_TEST_MODE_CLUTCH_RESET          = 1710,  /* Drive Unit Test Mode Clutch Fault Reset (ECU Rx) */

    IOP_MRN_SNSR_AUP_3_END                                      = 1710,  /* Marker only */
    /*----------------------------------------------------*/

    /*------------------------------------------------------
    Send a Request Group Function across the network
    ------------------------------------------------------*/
    IOP_SEND_REQUEST_PGN            = 1711,

    /*------------------------------------------------------
    Send Lua script output
    ------------------------------------------------------*/
    IOP_LUA_OUTPUT                  = 1712,

    /*------------------------------------------------------
    IOP instruction for TV module
    -----------------------------------------------------*/
    IOP_TV_INST                     = 1713,

    /*------------------------------------------------------
    Tire pressure data
    -----------------------------------------------------*/
    IOP_TIRE_PRSSR_DATA             = 1714,

    /*------------------------------------------------------
    IOP for the MNAND refresh status
    ------------------------------------------------------*/
    IOP_MNAND_REFRESH_STATUS        = 1715,


    /*------------------------------------------------------
    AIS600 Transceiver
    ------------------------------------------------------*/
    IOP_MRN_SNSR_AIS_SET_TXT        = 1716, /* Set AIS Mayday text                              */
    IOP_MRN_SNSR_AIS_MAYDAY         = 1717, /* Broadcast an AIS Mayday message                  */
    IOP_MRN_SNSR_AIS_HEARTBEAT      = 1718, /* AIS Heartbeat packet                             */

    /*------------------------------------------------------
    IOP IIC operation
    -----------------------------------------------------*/
    IOP_IIC_READ                    = 1719,
    IOP_IIC_WRITE                   = 1720,
    IOP_IIC_DUMP_ALL                = 1721,

    /*------------------------------------------------------
    Engine page gauge synchronization data
    ------------------------------------------------------*/
    IOP_ENGN_GAUGE_SYNC_DATA        = 1722,

    /*------------------------------------------------------
    IOP RAM operation
    ------------------------------------------------------*/
    IOP_RAM_READ                    = 1723,
    IOP_RAM_WRITE                   = 1724,

    /*------------------------------------------------------
    IOP RAM operation
    ------------------------------------------------------*/
    IOP_MANIFEST_STORAGE            = 1729,
    IOP_RQST_MANIFEST               = 1730,
    IOP_MANIFEST_DATA               = 1731,

    /*------------------------------------------------------
    DRC/Filter related instructions
    ------------------------------------------------------*/
    IOP_COM_DRC_LVL_SET             = 1732,
    IOP_COM_DRC_STATUS              = 1733,
    IOP_COM_DRC_RSV_LAST_ID         = 1735,

    /*------------------------------------------------------------------------
    GPS Position, TOW, and Speed logging only
    ------------------------------------------------------------------------*/
    IOP_PVT_LOG_POSN_DATA           = 1736,

    /*------------------------------------------------------
    Manufacturer specific data (Currently engines but not limited to)
    ------------------------------------------------------*/
    IOP_ACK_MANUF_SPECIFIC_MSG_DATA = 1737,

    /*------------------------------------------------------
    ANT Sensor Pre-pair Commands.
    -----------------------------------------------------*/
    IOP_ANT_PREPAIR_HR              = 1738, /* Heart Rate               */
    IOP_ANT_PREPAIR_CAD             = 1739, /* Cadence Sensor           */
    IOP_ANT_PREPAIR_SPD             = 1740, /* Speed Sensor             */
    IOP_ANT_PREPAIR_SPDCAD          = 1741, /* Speed and Cadence Sensor */
    IOP_ANT_PREPAIR_PWR             = 1742, /* Power Meter              */
    IOP_ANT_PREPAIR_POD             = 1743, /* Foot Pod                 */
    IOP_ANT_PREPAIR_LEV             = 1744, /* Light Electric Vehicle   */
    IOP_ANT_PREPAIR_BR              = 1745, /* Bike Radar               */
    IOP_ANT_PREPAIR_SENSOR          = 1746, /* Any ANT Sensor           */
    IOP_ANT_PAIRED_ID_LIST          = 1747, /* download list response   */
    IOP_ANT_PREPAIR_BLC             = 1748, /* Bike Light Controller    */

    /*------------------------------------------------------
    Managed nand field refresh commands
    -----------------------------------------------------*/
    IOP_MNAND_FLD_RFRSH_STATUS      = 1750,

    /*------------------------------------------------------
    Orientation data for fixed accelerometer calibration
    ------------------------------------------------------*/
    IOP_ACCEL_FIXED_CAL_DATA        = 1753,

    /*------------------------------------------------------
    IOP set CSM ClientTypeID operation
    -----------------------------------------------------*/
    IOP_CSM_SET_CLIENT_TYPE_ID      = 1755,
    IOP_CSM_CLIENT_TYPE_ID          = 1756,

    /*------------------------------------------------------
    Has IFIX date ever been set on unit for NOH to
        determine if unit is new.
    -----------------------------------------------------*/
    IOP_NOH_IFIX_FLAG_DATA          = 1757,

    /*------------------------------------------------------
    flash file op status data
    ------------------------------------------------------*/
    IOP_RGN_OP_STATUS_DATA          = 1758,

    /*------------------------------------------------------
    Touchscreen Controller instructions
    -----------------------------------------------------*/
    IOP_TSC_SENSOR_DATA             = 1759,
    IOP_TSC_RAWDIFF_DATA            = 1760,
    IOP_TSC_RAW_DATA_MODE           = 1761,
    IOP_TSC_DIFF_DATA_MODE          = 1762,
    IOP_TSC_TEST_SCAN_RATE_CHG      = 1763,
    IOP_TSC_BL_DATA                 = 1764,

    /*------------------------------------------------------
    GUI string registration
    ------------------------------------------------------*/
    IOP_STRING_REGISTRATION_DATA    = 1765,

    /*------------------------------------------------------
    Touchscreen unit input stuffing IDs
    ------------------------------------------------------*/
    IOP_STUFF_TOUCH_DATA            = 1766,
    IOP_QUERY_CONTROL_TEXT          = 1767,

    /*------------------------------------------------------
    Read PRNP checksum.
    -----------------------------------------------------*/
    IOP_PRNP_CHECKSUM              = 1768,

    /*------------------------------------------------------
    Tuner data
    1769 - 1799 are reserved for tuner communications
    -----------------------------------------------------*/
    IOP_TUNER_READ_MEM_BY_ID       = 1769,
    IOP_TUNER_READ_MEM_BY_ADDR     = 1770,
    IOP_TUNER_READ_MEM_RSLT        = 1771,
    IOP_TUNER_WRITE_MEM_BY_ID      = 1772,
    IOP_TUNER_WRITE_MEM_BY_ADDR    = 1773,
    IOP_TUNER_WRITE_MEM_RSLT       = 1774,
    IOP_TUNER_GET_USER_DATA        = 1775,
    IOP_TUNER_GET_USER_DATA_RSLT   = 1776,
    IOP_TUNER_SET_USER_DATA        = 1777,
    IOP_TUNER_SET_USER_DATA_RSLT   = 1778,
    IOP_TUNER_CMND_DATA            = 1779,
    IOP_TUNER_SET_ALIGN_DATA       = 1780,
    IOP_TUNER_CMND_RSLT_DATA       = 1781,
    IOP_TUNER_LOG                  = 1782,

    IOP_TUNER_RESERVED             = 1799,

    /*------------------------------------------------------
    Overwriting system code(beginning and end sections) and
    non-volatile memory (a.k.a NVM / nonvol) sections to test MMU.
    ------------------------------------------------------*/
    IOP_TEST_MMU                    = 1800,

    /*------------------------------------------------------
    Remote antenna power MPS test
    ------------------------------------------------------*/
    IOP_TEST_REMOTE_ANTENNA         = 1801,

    /*------------------------------------------------------
    Microphone logging
    ------------------------------------------------------*/
    IOP_MIC_LOG_DATA                = 1802,

    /*------------------------------------------------------
    Touchscreen Controller instructions (cont.)
    -----------------------------------------------------*/
    IOP_TSC_TEST_LINEARITY          = 1803,
    IOP_TSC_TEST_DATA               = 1804,
    IOP_TSC_TEST_ACCURACY           = 1805,
    IOP_TSC_TEST_GET_RESULTS        = 1806,

    /*------------------------------------------------------
    IOP Command Line Interface
    ------------------------------------------------------*/
    IOP_CLI_ID                      = 1807,

    /*------------------------------------------------------
    Instruction to read CID struct from MMC/SD
    ------------------------------------------------------*/
    IOP_GET_MMC_CID_DATA            = 1808,
    IOP_MMC_CID_DATA                = 1809,

    /*------------------------------------------------------
    Route destination data for marine products
    ------------------------------------------------------*/
    IOP_MRN_ROUTE_DEST_DATA         = 1810,

    /*------------------------------------------------------
    IOP commands for GMA
    ------------------------------------------------------*/
    IOP_UPLOAD_GMA                  = 1811,
    IOP_UPLOAD_GMA_STRT             = 1812,
    IOP_UPLOAD_GMA_CMPLT            = 1813,

    /*------------------------------------------------------
    Query screen contents for data retrieval to enable
    automatic testing.
    ------------------------------------------------------*/
    IOP_QUERY_RESERVED_1            = 1814, /* Reserved for future marine testing */
    IOP_QUERY_RESERVED_2            = 1815, /* Reserved for future marine testing */
    IOP_QUERY_FOCUS_TEXT            = 1816, /* Query text for screen element with focus */
    IOP_QUERY_SCREEN_TEXT           = 1817, /* Query all screen text by mask */

    /*------------------------------------------------------
    Toggle touch record
    ------------------------------------------------------*/
    IOP_TOGGLE_TOUCH_RECORD         = 1818,

    /*------------------------------------------------------
    Efield calibration data.
    ------------------------------------------------------*/
    IOP_EFIELD_SET_THRESHOLDS       = 1821,
    IOP_EFIELD_RPT_CAL_STATE        = 1822,
    IOP_EFIELD_RPT_CAL_VALS         = 1823,

    /*------------------------------------------------------
    IOP command for GUI Script Remote (GREMLIN) commands
    -----------------------------------------------------*/
    IOP_LUA_CONTROL                 = 1826,

    /*------------------------------------------------------
    GSM Tracker IDs
    ------------------------------------------------------*/
    IOP_GSM_TRKR_START              = 1828, /* Marker only                                      */
    IOP_GSM_TRKR_RQST_SETTINGS      = 1828,
    IOP_GSM_TRKR_SETTINGS_DATA      = 1829,
    IOP_GSM_TRKR_RQST_GEOFENCE      = 1830,
    IOP_GSM_TRKR_GEOFENCE_DATA      = 1831,
    IOP_GSM_TRKR_FORCE_TXN          = 1832,
    IOP_GSM_TRKR_SET_GSM_INST       = 1833,
    IOP_GSM_TRKR_GSM_DATA           = 1834,
    IOP_GSM_TRKR_SET_CSM_INST       = 1835,
    IOP_GSM_TRKR_CSM_DATA           = 1836,
    IOP_GSM_TRKR_RQST_SESSIONS      = 1837,
    IOP_GSM_TRKR_SESSION_DATA       = 1838,
    IOP_GSM_TRKR_RQST_CHECKINS      = 1839,
    IOP_GSM_TRKR_CHECKIN_DATA       = 1840,

    IOP_GSM_TRKR_END                = 1849, /* Marker only                                      */

    /*------------------------------------------------------
    Test Diagnostics Utility
    -----------------------------------------------------*/
    IOP_MRN_TEST_DIAG               = 1850,

    /*------------------------------------------------------
    PRNP Image Programming speed
    -----------------------------------------------------*/
    IOP_IMAGE_PROGRAMMING_SPEED    = 1851,

    /*------------------------------------------------------
    Tire-pressure monitoring system (TPMS)
    ------------------------------------------------------*/
    IOP_TPMS_RESERVED_1             = 1852,
    IOP_TPMS_RESERVED_2             = 1853,
    IOP_TPMS_RESERVED_3             = 1854,
    IOP_SET_TPMS_SENSOR_ID          = 1855,

    /*------------------------------------------------------
    MAX9526 video decoder settings
    ------------------------------------------------------*/
    IOP_VIDEC_BRIGHTNESS            = 1856,
    IOP_VIDEC_CONTRAST              = 1857,
    IOP_VIDEC_HUE                   = 1858,
    IOP_VIDEC_SATURATION            = 1859,

    /*------------------------------------------------------
    Touchscreen Controller instructions (cont.)
    ------------------------------------------------------*/
    IOP_TSC_DEBUG_ENABLE            = 1860,
    IOP_TSC_OP_SUCCESS_DATA         = 1861,
    IOP_TSC_VERSION_DATA            = 1862,
    IOP_TSC_RUN_BIST                = 1863, /* Run TSC basic in-system test with passed in test number (HWM_tsc_bist_t8) */
    IOP_TSC_BIST_RSLT               = 1864, /* Result of TSC basic in-system test as defined in HWM_tsc_bist_rslt        */

    /*------------------------------------------------------
    Delete individual NVM tag.
    -----------------------------------------------------*/
    IOP_NVM_TAG_DEL                 = 1865,

    /*------------------------------------------------------
    006-J Garmin part number.
    -----------------------------------------------------*/
    IOP_IMAGE_BOM_GPN               = 1867,

    /*------------------------------------------------------
    File system data.
    -----------------------------------------------------*/
    IOP_FS_DATA_CHKDSK_RSLT         = 1870,
    IOP_FS_DATA_CHKDSK_EVL_RSLT     = 1871,
    IOP_FS_ERASE_PARTITION          = 1872,
    IOP_FS_ERASE_PARTITION_RSLT     = 1873,

    /*------------------------------------------------------
    Switch audio source
    -----------------------------------------------------*/
    IOP_SWITCH_AUDIO_SRC            = 1880,

    /*------------------------------------------------------
    Garmin Marine Autopilot 4

        NOTE: This is the fourth set of Inst IDs for the Autopilot.

              Set 1 starts at 1240.
              Set 2 starts at 1300.
              Set 3 starts at 1683.
              Set 4 starts at 1881
              Set 5 starts at 5903
    ------------------------------------------------------*/
    IOP_MRN_SNSR_AUP_4_BEGIN                                        = 1881,  /* Marker only                                                     */

    IOP_MRN_SNSR_AUP_DRIVE_UNIT_RUDDER_ANGULAR_RATE_CALC_PROGRESS   = 1881,  /* Progess of the rudder angular rate calculation                  */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_RUDDER_ANGULAR_RATE                 = 1882,  /* Value of the rudder angular rate                                */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_VALID                               = 1883,  /* Is the detected drive unit still valid?                         */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_RUDDER_FDBK_DVC_IS_LINEAR           = 1884,  /* Is the output of the connected rudder feedback device linear?   */
    IOP_MRN_SNSR_AUP_HW_INFO_RQST                                   = 1885,  /* Request ECU to send info on it's hardware                       */
    IOP_MRN_SNSR_AUP_HW_INFO_DATA                                   = 1886,  /* Response from ECU with info about its hardware                  */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_INITIAL_SYS_VOLTAGE                 = 1887,  /* Voltage of drive unit at power up.                              */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_INITIAL_SYS_VOLTAGE_ACK             = 1888,  /* Acknowledgement that the drive unit initial voltage was Rx'd    */
    IOP_MRN_SNSR_AUP_GEAR_RATIO_TEST_RESULT                         = 1889,  /* CCU->ECU, contains config param resulting from GRT.             */
    IOP_MRN_SNSR_AUP_MIN_LOCK_TO_LOCK_TIME                          = 1890,  /* CCU->ECU, commands ECU to set up a given min lock to lock time in seconds */
    IOP_MRN_SNSR_AUP_RUDDER_RATE_LIMITER_INFO                       = 1891,  /* Rudder Rate Limiter information                                 */
    IOP_MRN_SNSR_AUP_MOTOR_INFO_SEND_PERIOD                         = 1892,  /* Sets the period for the ECU's periodic output of motor info     */
    IOP_MRN_SNSR_AUP_RUDDER_POSITION_SET                            = 1893,  /* Rudder position command to ECU                                  */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_RUDDER_CENTER_VOLT_SET_ACK          = 1894,  /* Acknowledgement that the rudder center point has been set       */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_SETTINGS_CLEAR_ACK                  = 1895,  /* Ack that the ECU has received the settings clear command        */
    IOP_MRN_SNSR_AUP_VOLVO_PRDC_INFO                                = 1896,  /* Temporary packet to bridge Volvo Data.                          */
    IOP_MRN_SNSR_CTL_CMD_MSG                                        = 1897,  /* Wrapper message for actuator tuning data                        */
    IOP_MRN_SNSR_AUP_ECU_BOARD_TEMP                                 = 1898,  /* ECU Board (MOSFET) temperature (degrees Celsius)                */
    IOP_MRN_SNSR_AUP_DRIVE_UNIT_TEST_MODE_TEMP_SHUTDOWN             = 1899,  /* ECU test mode shutdown and restart temperatures (degrees Celsius)  */
    IOP_MRN_SNSR_ATTITUDE                                           = 1900,  /* Vessel attitude. Also includes associated values and messages.  */

    IOP_MRN_SNSR_AUP_4_END                                          = 1900,  /* Marker only                                                     */

    /*------------------------------------------------------
    SD Card Info
    ------------------------------------------------------*/
    IOP_SD_VOL_STATUS_RQST          = 1901,

    /*------------------------------------------------------
    Display and keypad light levels
    ------------------------------------------------------*/
    IOP_LIGHT_LEVEL_CONFIG          = 1902,

    /*------------------------------------------------------
    Marine Configuration Cloning ID group

    NOTE: This is the first set of Inst IDs for CLN.

              Set 1 starts at 1903.
              Set 2 starts at 2134.
    ------------------------------------------------------*/
    IOP_MRN_CNFG_CLONE_BEGIN                                        = 1903,  /* Marker only                                                     */

    IOP_MRN_CNFG_CLONE_DISCOVER_CLONE_DEVICES                       = 1904,  /* Message that asks for a response from clone-supporting devices  */
    IOP_MRN_CNFG_CLONE_DISCOVER_CLONE_DEVICES_RESPONSE              = 1905,  /* Response from a clone-supporting device                         */
    IOP_MRN_CNFG_CLONE_STORAGE_CLONE_TO_DEVICE_READY_REQUEST        = 1906,  /* Request asking whether Storage Clone To device is ready         */
    IOP_MRN_CNFG_CLONE_STORAGE_CLONE_TO_DEVICE_READY_RESPONSE       = 1907,  /* Response from the Storage Clone To device                       */
    IOP_MRN_CNFG_CLONE_TO_DEVICE_READY_REQUEST                      = 1908,  /* Request asking whether the Clone To device is ready             */
    IOP_MRN_CNFG_CLONE_TO_DEVICE_READY_RESPONSE                     = 1909,  /* Response from the Clone To device                               */
    IOP_MRN_CNFG_CLONE_STORAGE_CLONE_DEVICE_FINISHED                = 1910,  /* Message indicating the Storage device is finished               */
    IOP_MRN_CNFG_CLONE_FROM_DEVICE_READY_REQUEST                    = 1911,  /* Request asking whether the Clone From device is ready           */
    IOP_MRN_CNFG_CLONE_FROM_DEVICE_READY_RESPONSE                   = 1912,  /* Response from the Clone From device                             */
    IOP_MRN_CNFG_CLONE_STORAGE_DEVICE_READY_REQUEST                 = 1913,  /* Request asking whether the Clone Storage device is ready        */
    IOP_MRN_CNFG_CLONE_STORAGE_DEVICE_READY_RESPONSE                = 1914,  /* Response from the Clone Storage device                          */
    IOP_MRN_CNFG_CLONE_FROM_DEVICE_FINISHED                         = 1915,  /* Message indicating the Clone From device is finished            */
    IOP_MRN_CNFG_CLONE_PROGRESS_MSG                                 = 1916,  /* We are sending a Configuration Cloning Progress message         */
    IOP_MRN_CNFG_CLONE_OPERATION_IN_PROGRESS                        = 1917,  /* A clone operation is now in progress                            */
    IOP_MRN_CNFG_CLONE_OPERATION_COMPLETED                          = 1918,  /* A clone operation that was in progress is now complete          */
    IOP_MRN_CNFG_CLONE_DBG_REPORT                                   = 1919,  /* Tell all physical devices (that support CLN) to report dbg info */

    IOP_MRN_CNFG_CLONE_END                                          = 1920,  /* Marker only                                                     */

    /*------------------------------------------------------
    Ipod authentication test result.
    -----------------------------------------------------*/
    IOP_IPOD_AUTH_RSLT              = 1921,

    IOP_BATT_AUTH_RSLT              = 1922,    /* Battery pack authentication test result */

    /*------------------------------------------------------
    Sonar Instrumentation IDs
    ------------------------------------------------------*/
    IOP_DPS_INST_START                  = 2000,

    IOP_DPS_HEARTBEAT                   = 2001,     /* Client heatbeat packet               */
    IOP_DPS_SETTINGS                    = 2002,     /* Sonar Settings                       */
    IOP_DPS_STATUS_RQST                 = 2003,     /* Sonar Status request                 */
    IOP_DPS_STATUS                      = 2004,     /* Sonar Status information             */
    IOP_DPS_COLUMN_DEPRECATED_1         = 2005,     /* Sonar Column information deprecated  */
    IOP_DPS_TRANSDUCER_RQST             = 2006,     /* Request Transducer information       */
    IOP_DPS_TRANSDUCER_INFO             = 2007,     /* Transducer information               */
    IOP_DPS_SENSOR_DATA                 = 2008,     /* Sensor information                   */

    IOP_DPS_DEBUG_DATA                  = 2009,     /* Array of data used for debugging     */
    IOP_DPS_START_DRIVER                = 2010,     /* Begin sonar driver control           */
    IOP_DPS_RCVR_PARMS                  = 2011,     /* Send envelope data                   */
    IOP_DPS_TEST_TRANSMITTER_START      = 2012,     /* Begin transmitter test               */
    IOP_DPS_TEST_RECEIVER_START         = 2013,     /* Begin receiver test                  */
    IOP_DPS_TEST_RECEIVER_DATA          = 2014,     /* Receiver test data                   */
    IOP_DPS_TEST_DYNAMIC_RANGE_START    = 2015,     /* Begin dynamic range test             */
    IOP_DPS_SAMPLE_INJECT_CNFG          = 2016,     /* Sonar sample injection configuration */
    IOP_DPS_XDCR_ID_REQ                 = 2017,     /* Request transducer ID info           */
    IOP_DPS_SYNCH_DATA                  = 2018,     /* Sonar synchronous data               */

    IOP_DPS_XDCR_ID_TEST_DATA           = 2019,     /* Transducer ID test data              */
    IOP_DPS_XDCR_ID_DATA                = 2020,     /* Transducer ID read data              */
    IOP_DPS_XDCR_ID_BUS_LVL_DATA        = 2021,     /* Transducer ID bus level data         */
    IOP_DPS_WATER_SPEED_ID              = 2022,     /* Water speed sensor preset            */
    IOP_DPS_WATER_SPEED_HZ              = 2023,     /* Water speed in Hertz                 */
    IOP_DPS_WATER_TEMPERATURE_VOLTS     = 2024,     /* Water temperature in millivolts      */
    IOP_DPS_HARDWARE_DRIVER_HEALTHY     = 2025,     /* True if sonar hardware can be used   */

    IOP_DPS_COLUMN_DEPRECATED_2         = 2026,     /* Deprecated column information        */
    IOP_DPS_COLUMN                      = 2027,     /* Column packet                        */

    IOP_DPS_GEN_NTFCTN                  = 2028,     /* General DPS notification             */
    IOP_DPS_COLUMN_V2                   = 2029,     /* Improved column packet               */

    IOP_DPS_INST_END                    = 2099,

    /*------------------------------------------------------
    Battery Capacity Limiting Enable/Disable
    -----------------------------------------------------*/
    IOP_BATT_CAP_LMT_ENBL               = 2100,
    IOP_BATT_CAP_BURNOFF_ENBL           = 2101,

    /*------------------------------------------------------
    Mass Production State Set/Clear
    -----------------------------------------------------*/
    IOP_MP_STATE_SET                    = 2102,

    /*------------------------------------------------------
    PMIC TPS65023 register access
    -----------------------------------------------------*/
    IOP_PMIC_WRITE_REG                  = 2103,
    IOP_PMIC_READ_REG                   = 2104,
    IOP_PMIC_REG_STATUS                 = 2105,
    IOP_PMIC_ILIM_OVERRIDE_DATA         = 2106,

    /*------------------------------------------------------
    Inst ID's for Garmin TCP
    ------------------------------------------------------*/
    IOP_GRMN_TCP_INST_START             = 2110,
    IOP_GRMN_TCP_TAP_PORT_INFO          = 2111,
    IOP_GRMN_TCP_PROBE                  = 2112,
    IOP_GRMN_TCP_PROBE_ACK              = 2113,

    IOP_GRMN_TCP_INST_END               = 2119,

    /*------------------------------------------------------
    joinction view map ID data
    -----------------------------------------------------*/
    IOP_JCV_ID_DATA                     = 2120,

    /*------------------------------------------------------
    Gauge layout selection data
    -----------------------------------------------------*/
    IOP_GAUGE_LAYOUT_IDX                = 2121,

    /*------------------------------------------------------
    Theme selection data
    -----------------------------------------------------*/
    IOP_THEME_IDX                       = 2122,

    /*------------------------------------------------------
    GUI application selection data
    -----------------------------------------------------*/
    IOP_GUI_APP_DATA                    = 2123,

    /*------------------------------------------------------
    Intelligent Driving Video Recorder
    -----------------------------------------------------*/
    IOP_IDVR_DATA                       = 2124,

    /*------------------------------------------------------
    Driving recorder id.
    -----------------------------------------------------*/
    IOP_DRIVING_RECORDER                = 2125,

    /*------------------------------------------------------
    GDP Interface
    ------------------------------------------------------*/
    IOP_GDP_ENUMERATE                   = 2126,
    IOP_GDP_REQUEST                     = 2127,
    IOP_GDP_REPLY                       = 2128,
    IOP_GDP_RSVD0                       = 2129,
    IOP_GDP_RSVD1                       = 2130,
    IOP_GDP_RSVD2                       = 2131,
    IOP_GDP_RSVD3                       = 2132,

    /*------------------------------------------------------
    Return whether an SD card is present inside unit
    -----------------------------------------------------*/
    IOP_SD_CARD_PRESENT_DATA            = 2133,

    /*------------------------------------------------------
    Marine Configuration Cloning ID group

    NOTE: This is the second set of Inst IDs for CLN.

              Set 1 starts at 1903.
              Set 2 starts at 2134.
    ------------------------------------------------------*/
    IOP_MRN_CNFG_CLONE_2_BEGIN                                        = 2134,  /* Marker only                                                     */

    IOP_MRN_CNFG_CLONE_STORAGE_DEVICE_STORE_COMPLETE                  = 2135,  /* Message indicating the Clone Storage device's write is finished */
    IOP_MRN_CNFG_CLONE_TO_DEVICE_STORE_COMPLETE                       = 2136,  /* Message indicating the Clone To device's write is finished      */

    IOP_MRN_CNFG_CLONE_2_END                                          = 2160,  /* Marker only                                                     */

    IOP_SHUTDOWN_DATA                                                 = 2161,  /* Retrieve the shutdown.log file */
    IOP_RQST_SHUTDOWN_RPT                                             = 2162,  /* Discover if there is anything to shut down */

    /*------------------------------------------------------
    Acknowledge legal message.
    ------------------------------------------------------*/
    IOP_ACK_LEGAL_MSG                                                 = 2164,

    /*------------------------------------------------------
    Set Audio Sample Rate
    ------------------------------------------------------*/
    IOP_AUDIO_SET_RATE                  = 2165,

    /*------------------------------------------------------
    Production cmd to used to identify the production
    process step in progress.  The argument is passed as
    data for an EVL log
    -----------------------------------------------------*/
    IOP_EVL_LOG_STEP                    = 2166,

    /*------------------------------------------------------
    Accelerometer self-test result.
    -----------------------------------------------------*/
    IOP_ACCEL_DATA_SELF_TEST_RESULT     = 2168,

    /*------------------------------------------------------
    Command to modify non-vol flag to start the PRNP process
    ------------------------------------------------------*/
    IOP_PRNP_NV_FLAG                    = 2169,

    /*------------------------------------------------------
    SHELL Data Packets: IDs reserved for use by Shell
    ------------------------------------------------------*/
    IOP_SHELL_CONNECT_REQUEST           = 2170,
    IOP_SHELL_CONNECT_RESPONSE          = 2171,
    IOP_SHELL_DISCONNECT_REQUEST        = 2172,
    IOP_SHELL_DISCONNECT_RESPONSE       = 2173,
    IOP_SHELL_DATA                      = 2174, /* Primary SHELL transport ID */
    IOP_SHELL_ERROR                     = 2175,

    /*------------------------------------------------------
    Automatic Volume Control (AVC)
    ------------------------------------------------------*/
    IOP_AVC_SET_MAX_GAIN_RANGE          = 2176,

    /*------------------------------------------------------
    Flag to get the amplifier faults stored in non-vol
    -----------------------------------------------------*/
    IOP_NV_AMP_FLT_FLAG                 = 2177,

    /*------------------------------------------------------
    Flag to get the USB overcurrent faults stored in non-vol
    -----------------------------------------------------*/
    IOP_NV_USB_FLT_FLAG                 = 2178,

    /*------------------------------------------------------
    VCOM (digital potentiometer) data
    -----------------------------------------------------*/
    IOP_VCOM_DATA                       = 2179,

    /*------------------------------------------------------
    Networked assert continue
    ------------------------------------------------------*/
    IOP_ASSERT_CONTINUE                 = 2180,

    /*------------------------------------------------------
    DDF tests
    ------------------------------------------------------*/
    IOP_DDF_TEST_SUITE                  = 2181,

    /*------------------------------------------------------
     Current Display Orientation (portrait, landscape, etc)
    ------------------------------------------------------*/
    IOP_CURR_DSPL_ORNTN_DATA            = 2182,

    /*------------------------------------------------------
    Reserved Marine-Specific Instrumentation IDs
    ------------------------------------------------------*/
    IOP_FIRST_RESERVED_MARINE_ID        = 2183,

    IOP_DATABASE_CMND                   = 2184,

    /*------------------------------------------------------
    Inst IDs for GMM communication protocol
    ------------------------------------------------------*/
    IOP_MONITOR_IDS_START               = 2185,
    IOP_MONITOR_HEARTBEAT               = 2186,
    IOP_MONITOR_HEARTBEAT_ACK           = 2187,
    IOP_MONITOR_PAIR_REQUEST            = 2188,
    IOP_MONITOR_PAIR_RESPONSE           = 2189,
    IOP_MONITOR_TOUCH_INPUT             = 2190,
    IOP_MONITOR_LIGHT_SENSOR            = 2191,
    IOP_MONITOR_SETTINGS                = 2192,
    IOP_MONITOR_OSD_COMMAND             = 2193,
    IOP_MONITOR_BEEPER                  = 2194,
    IOP_MONITOR_POWER_MESSAGE           = 2195,
    IOP_MONITOR_PAIR_ERROR              = 2196,
    IOP_MONITOR_IDS_END                 = 2199,

    /*-------------------------------------------------------------
    Bavaria OEM Docking System IDs
    ---------------------------------------------------------------*/
    IOP_OEM_BAVARIA_START                                    = 2200,
    IOP_OEM_BAVARIA_THRUSTER_STATUS                          = 2201,
    IOP_OEM_BAVARIA_SNSR_THRUSTER_HEARTBEAT                  = 2202,
    IOP_OEM_BAVARIA_SNSR_BATTERY_HEARTBEAT                   = 2203,
    IOP_OEM_BAVARIA_SNSR_RPM_HEARTBEAT                       = 2204,
    IOP_OEM_BAVARIA_SNSR_TRANSMISSION_HEARTBEAT              = 2205,
    IOP_OEM_BAVARIA_RAW_VOLTAGE                              = 2206,
    IOP_OEM_BAVARIA_RPM_PERCENTAGE                           = 2207,
    IOP_OEM_BAVARIA_THRUSTER_SYSTEM_OFF_ADAPTER_ENGINE_SPEED = 2208,
    IOP_OEM_BAVARIA_THRUSTER_SYSTEM_OFF_ADAPTER_TRANS_PARAM  = 2209,
    IOP_OEM_BAVARIA_END                                      = 2210,

    /*------------------------------------------------------
    Collision Alarm Settings Sharing ID
    -------------------------------------------------------*/
    IOP_COLL_ALRM_SETTING_SHARE_ID              = 2211,

    /*------------------------------------------------------
    AIS Data/Command Sharing IDs
    -------------------------------------------------------*/
    IOP_AIS_CLEAR_LOST_TARGET_ID                = 2212,

    /*------------------------------------------------------
    ESM remote volume inst IDs
    ------------------------------------------------------*/
    IOP_ESM_VOL_INFO                    = 2214,
    IOP_ESM_VOL_UNREG                   = 2215,
    IOP_ESM_VOL_LIST_REQ                = 2216,
    IOP_ESM_VOL_NOTIFY_REG              = 2217,
    IOP_ESM_VOL_RPC_REQ                 = 2218,
    IOP_ESM_VOL_RPC_RESP                = 2219,

    /*------------------------------------------------------
    Deprecated ESM Inst ID name kept for now to ease
    transition
    ------------------------------------------------------*/
    IOP_ESM_VOL_RPC                     = IOP_ESM_VOL_RPC_REQ,

    /*------------------------------------------------------
    Inst ID's for RID communication protocol
    ------------------------------------------------------*/
    IOP_RID_HEARTBEAT       = 2220,
    IOP_RID_HEARTBEAT_ACK   = 2221,
    IOP_RID_NET_CMND        = 2222,
    IOP_RID_STATE           = 2223,
    IOP_RID_INPUT           = 2224,
    IOP_RID_PAIR_MODE_START = 2225,
    IOP_RID_LAST            = 2230,

    /*------------------------------------------------------
    BlueChart Mobile Inst IDs
    ------------------------------------------------------*/
    IOP_BCM_PAIR_REQUEST                = 2231,
    IOP_BCM_PAIR_REPLY                  = 2232,
    IOP_BCM_TRANSFER_DATA               = 2233,
    IOP_BCM_TRANSFER_DATA_REQUEST       = 2234,
    IOP_BCM_TRANSFER_ACK                = 2235,
    IOP_BCM_TRANSFER_ERROR              = 2236,
    IOP_BCM_END                         = 2240,

    /*------------------------------------------------------
    Inst ID's for UPDT communication protocol
    ------------------------------------------------------*/
    IOP_CNS_UPDT_NET_START          = 2241, /* Start network update packet  */
    IOP_CNS_UPDT_NET_END            = 2242, /* End network update packet    */
    IOP_CNS_UPDT_DEV_START          = 2243, /* Start device update          */
    IOP_CNS_UPDT_DEV_END            = 2244, /* End device update            */
    IOP_CNS_UPDT_RQST_INVENTORY     = 2245, /* Request inventory            */
    IOP_CNS_UPDT_INVENTORY          = 2246, /* Inventory list               */
    IOP_CNS_UPDT_LOADER             = 2247, /* Transmit loader              */
    IOP_CNS_UPDT_ITEM               = 2248, /* Transmit deliverable item    */
    IOP_CNS_UPDT_INSTALL_CMPLT      = 2249, /* Install complete             */
    IOP_CNS_UPDT_INSTALL_CONT       = 2250, /* Install in progress          */
    IOP_CNS_UPDT_READY              = 2251, /* Update is ready              */
    IOP_CNS_UPDT_COORD_HEARTBEAT    = 2252, /* Update heartbeat             */
    IOP_CNS_UPDT_LOADER_CONT        = 2253, /* Wait for loader              */
    IOP_CNS_UPDT_INSTALL_CANCEL     = 2254, /* Install cancel               */

    IOP_CNS_UPDT_INST_END       = 2259,

    /*------------------------------------------------------
    Backlight Calibration Inst IDs
    ------------------------------------------------------*/
    IOP_BACK_LIGHT_CAL_GET              = 2260,
    IOP_BACK_LIGHT_CAL_SET              = 2261,
    IOP_BACK_LIGHT_CAL_DATA             = 2262,

    /*------------------------------------------------------
    EDID inst IDs
    ------------------------------------------------------*/
    IOP_EDID_PORT_TEST                  = 2263,
    IOP_EDID_WRITE                      = 2264,

    /*------------------------------------------------------
    Test Mode page navigation
    ------------------------------------------------------*/
    IOP_TEST_GOTO_PAGE                  = 2265,

    /*------------------------------------------------------
    EDID inst IDs, continued
    ------------------------------------------------------*/
    IOP_EDID_PORT_TEST_RSLT             = 2266,
    IOP_EDID_WRITE_RSLT                 = 2267,

    /*------------------------------------------------------
    Station Instruction IDs (Deprecated)
    ------------------------------------------------------*/
    IOP_STA_INST                        = 2268,

    /*------------------------------------------------------
    CFG Synchronization (Deprecated)
    ------------------------------------------------------*/
    IOP_MRN_CFG_SYNC                    = 2269, /* DEPRECATED! */

    /*------------------------------------------------------
    NMEA 0183 Bridging Data
    ------------------------------------------------------*/
    IOP_NMEA0183_DATA                   = 2270,

    /*------------------------------------------------------
    Ethernet Test 'noise' ID
    ------------------------------------------------------*/
    IOP_TEST_DATA_ETHERNET_NOISE        = 2271,

    /*------------------------------------------------------
    NMEA 2000 Bridging Synchronization
    ------------------------------------------------------*/
    IOP_N2K_BRIDGE_CTRL                 = 2272,

    /*------------------------------------------------------
    TCP Test IDs for CNS
    ------------------------------------------------------*/
    IOP_CNS_GRMN_TCP_TEST_START                 = 2273,
    IOP_CNS_GRMN_TCP_TEST_RQST                  = 2274,
    IOP_CNS_GRMN_TCP_TEST_DEADBEEF              = 2275,

    /*------------------------------------------------------
    Station Event
    ------------------------------------------------------*/
    IOP_STATION_EVENT                   = 2276,

    /*---------------------------------------------------------
    CFG settings sync packets
    ---------------------------------------------------------*/
    IOP_SETTING_SYNC_ITEM_VALUE         = 2277,
    IOP_SETTING_SYNC_NETWORK_COMMAND    = 2278,
    IOP_SETTING_SYNC_NETWORK_STATE      = 2279,
    IOP_SETTING_SYNC_REQ_TX             = 2280,

    IOP_SETTING_SYNC_LAST_RESERVED      = 2286,

    IOP_PROGRAM_BUILT_IN_MAP_START      = 2287,
    IOP_PROGRAM_BUILT_IN_MAP_DONE       = 2288,

    /*------------------------------------------------------
    GNT10 data
    ------------------------------------------------------*/
    IOP_MRN_GATEWAY_DATA                = 2289,

    /*------------------------------------------------------
    MultiBeam Sonar Instrumentation IDs
    ------------------------------------------------------*/
    IOP_MBS_COLUMN_2D                   = 2290,     /* Multibeam sonar swath                */
    IOP_MBS_COLUMN_3D                   = 2291,     /* Multibeam sonar column (DEPRECATED, don't use) */
    IOP_MBS_SETTINGS                    = 2292,     /* Multibeam sonar settings             */
    IOP_MBS_SINGLE_SETTING              = 2293,     /* Multibeam sonar single setting value */
    IOP_MBS_HEARTBEAT                   = 2294,     /* Multibeam sonar heartbeat            */
    IOP_MBS_STATUS_RQST                 = 2295,     /* Multibeam sonar status request       */

    IOP_MBS_DEBUG_SETTINGS_DATA         = 2296,     /* Multibeam sonar diagnostic data      */
    IOP_MBS_DEBUG_SNAPSHOT_DATA         = 2297,     /* Multibeam sonar diagnostic data      */
    IOP_MBS_DEBUG_SINGLE_CHANNEL_DATA   = 2298,     /* Multibeam sonar diagnostic data      */

    IOP_MBS_TRANSDUCER_PING_SETUP       = 2299,     /* Multibeam sonar transducer network only */
    IOP_MBS_TRANSDUCER_HEARTBEAT        = 2300,     /* Multibeam sonar transducer network only */
    IOP_MBS_TRANSDUCER_SAMPLES          = 2301,     /* Multibeam sonar transducer network only */

    IOP_MBS_TEST_MESSAGE                = 2302,     /* Multibeam sonar run test commanad    */
    IOP_MBS_TEST_RESULTS                = 2303,     /* Multibeam sonar test results         */

    IOP_MBS_SWATH_2                     = 2304,     /* Multibeam sonar swath                */
    IOP_MBS_SETTINGS_2                  = 2305,     /* Multibeam sonar settings             */
    IOP_MBS_SINGLE_SETTING_2            = 2306,     /* Multibeam sonar single setting value */
    IOP_MBS_BOTTOM_POINTS               = 2307,     /* Multibeam sonar bottom point data    */
    IOP_MBS_GENERIC_DATA                = 2308,     /* Multibeam sonar generic data         */

    IOP_MBS_INST_END                    = 2320,

    /*------------------------------------------------------
    Marine Radar Instrumentation IDs
    These Inst IDs are reserved to support the enhanced radar
    protocol.  They are divided in to two (2) sub-groups based
    on their specific usage.

    Commands - Generally the command Inst IDs are used to send
    instruction and setting information to the radar.  The radar
    will acknowledge the command with the same Inst ID and any
    appropriate information.

    Data - Generally the data Inst IDs are used to send the
    operational information generated by the radar scanner.
    This would include things like spoke data, operating times,
    monitored system values (such as voltages, currents, and
    temperatures), error information and other related items.
    ------------------------------------------------------*/
    /*------------------------------------------------------
    Radar Enhanced Command Inst IDs
    ------------------------------------------------------*/
    IOP_MR_FRONT_END_FILTER             = 2321,             /* Front End Filter Mode - sets front end processing mode       */
    IOP_MR_FRONT_END_TEST               = 2322,             /* Front End Test Mode -sets front end test mode                */
    IOP_MR_ZERO_NOISE_FLOOR_MODE        = 2323,             /* Zero Noise Floor - enable noise floor removal                */
    IOP_MR_PULSE_AVERAGE_RANGE_A        = 2324,             /* Pulse Average Range A - number of pulse data sets to average */
    IOP_MR_PULSE_AVERAGE_RANGE_B        = 2325,             /* Pulse Average Range B - number of pulse data sets to average */
    IOP_MR_SPEED_MODE                   = 2326,             /* Speed mode (normal, high, auto, etc.)                        */
    IOP_MR_SPEED_SELECT                 = 2327,             /* Speed selection (1/100 RPM)                                  */
    IOP_MR_MOTOR_MODE                   = 2328,             /* Motor control mode (off, on, brake)                          */
    IOP_MR_TRANSMIT_MODE                = 2329,             /* Transmit mode (on or off)                                    */
    IOP_MR_TARGET_DATA_SEND             = 2330,             /* Target data send mode (on or off)                            */
    IOP_MR_DITHER_MODE                  = 2331,             /* Dither mode (on or off)                                      */
    IOP_MR_RANGES_MODE                  = 2332,             /* Ranges mode (single or dual)                                 */
    IOP_MR_RADAR_MODE_RANGE_A           = 2333,             /* Range A Radar mode (harbor, offshore, bird)                  */
    IOP_MR_RANGE_A                      = 2334,             /* Range A distance (meters)                                    */
    IOP_MR_RANGE_B                      = 2335,             /* Range B distance (meters)                                    */
    IOP_MR_AFC_MODE                     = 2336,             /* AFC mode (manual, auto, periodic)                            */
    IOP_MR_AFC_FINE                     = 2337,             /* AFC fine adjustment (1/100 percent)                          */
    IOP_MR_AFC_COARSE                   = 2338,             /* AFC coarse adjustment (1/100 percent)                        */
    IOP_MR_AFC_DATA_SEND                = 2339,             /* AFC data send mode (on or off)                               */
    IOP_MR_GAIN_MODE_RANGE_A            = 2340,             /* Range A gain mode (manual, linked, auto)                     */
    IOP_MR_GAIN_RANGE_A                 = 2341,             /* Range A gain (1/100 percent)                                 */
    IOP_MR_GAIN_MODE_RANGE_B            = 2342,             /* Range B gain mode  (manual, linked, auto)                    */
    IOP_MR_GAIN_RANGE_B                 = 2343,             /* Range B gain (1/100 percent)                                 */
    IOP_MR_GAIN_WINDOW_SIZE             = 2344,             /* Gain window size (1/100 percent)                             */
    IOP_MR_INTENSITY_LIMIT              = 2345,             /* Intensity limit (1/100 percent)                              */
    IOP_MR_AGC_THRESHOLD_RANGE_A        = 2346,             /* Range A AGC threshold (1/100 percent)                        */
    IOP_MR_AGC_SENSITIVITY_RANGE_A      = 2347,             /* Range A AGC sensitivity (1/100 percent)                      */
    IOP_MR_SPOKE_DATA_SEND              = 2348,             /* Spoke data send mode (on or off)                             */
    IOP_MR_LEGACY_SEND_MODE             = 2349,             /* Legacy protocol send mode (on or off)                        */
    IOP_MR_FACTORY_DEFAULTS             = 2350,             /* Factory defaults reset                                       */
    IOP_MR_AFC_FACTORY_TUNE             = 2351,             /* AFC factory tune function control                            */
    IOP_MR_FOB_ADJUST                   = 2352,             /* Front Of Boat (FOB) adjustment (1/32 degree)                 */
    IOP_MR_PARK_ADJUST                  = 2353,             /* Park position adjustment (1/32 degree)                       */
    IOP_MR_NOISE_BLANKER_MODE           = 2354,             /* Noise blanker mode (on or off)                               */
    IOP_MR_RAIN_MODE_RANGE_A            = 2355,             /* Range A rain filter mode (on or off)                         */
    IOP_MR_RAIN_GAIN_RANGE_A            = 2356,             /* Range A rain gain (1/100 percent)                            */
    IOP_MR_RAIN_FILTER_RANGE_A          = 2357,             /* Range A rain filter (none, narrow, medium, wide)             */
    IOP_MR_RAIN_MODE_RANGE_B            = 2358,             /* Range B rain filter mode (on or off)                         */
    IOP_MR_RAIN_GAIN_RANGE_B            = 2359,             /* Range B rain gain (1/100 percent)                            */
    IOP_MR_RAIN_FILTER_RANGE_B          = 2360,             /* Range B rain filter (none, narrow, medium, wide)             */
    IOP_MR_SEA_CLUTTER_MODE_RANGE_A     = 2361,             /* Range A sea clutter mode (off, manual, auto)                 */
    IOP_MR_SEA_CLUTTER_GAIN_RANGE_A     = 2362,             /* Range A sea clutter gain (1/100 percent)                     */
    IOP_MR_SEA_STATE_RANGE_A            = 2363,             /* Range A sea state (calm, moderate, rough)                    */
    IOP_MR_SEA_CLUTTER_MODE_RANGE_B     = 2364,             /* Range B sea clutter mode (off, manual, auto)                 */
    IOP_MR_SEA_CLUTTER_GAIN_RANGE_B     = 2365,             /* Range B sea clutter gain (1/100 percent)                     */
    IOP_MR_SEA_STATE_RANGE_B            = 2366,             /* Range B sea state (calm, moderate, rough)                    */
    IOP_MR_NO_TX_ZONE_MODE              = 2367,             /* No transmit zone mode (on or off)                            */
    IOP_MR_NO_TX_ZONE_BEGIN             = 2368,             /* No transmit zone Begin (1/32 degree)                         */
    IOP_MR_NO_TX_ZONE_END               = 2369,             /* No transmit zone end (1/32 degree)                           */
    IOP_MR_SENTRY_MODE                  = 2370,             /* Sentry mode (off, nominal, low power)                        */
    IOP_MR_SENTRY_TIME_INACTIVE         = 2371,             /* Sentry time inactive (standby or low power) (minutes)        */
    IOP_MR_SENTRY_TIME_ACTIVE           = 2372,             /* Sentry time active (transmitting) (minutes)                  */
    IOP_MR_STC_DATASET_REQUEST          = 2373,             /* Request STC dataset (current dataset)                        */
    IOP_MR_STC_DATASET_STORE            = 2374,             /* Store STC dataset (current dataset)                          */
    IOP_MR_STC_DATASET_DEFAULTS         = 2375,             /* Restore STC dataset defaults                                 */
    IOP_MR_HIGH_VOLTAGE_ADJUST          = 2376,             /* High Voltage Adjust                                          */
    IOP_MR_ERROR_CODE_REQUEST           = 2377,             /* Error code request ( error code )                            */
    IOP_MR_ERROR_LOG_REQUEST            = 2378,             /* Error log request                                            */
    IOP_MR_ERROR_FLAG_REQUEST           = 2379,             /* Error flag request                                           */
    IOP_MR_ERROR_CLEAR_REQUEST          = 2380,             /* Error clear request - clear error log and flags              */
    IOP_MR_OPERATION_TIME_CLEAR         = 2381,             /* Operation time clear                                         */
    IOP_MR_MODULATOR_TIME_CLEAR         = 2382,             /* Modulator time clear                                         */
    IOP_MR_TRANSMIT_TIME_CLEAR          = 2383,             /* Transmit time clear                                          */
    IOP_MR_ANTENNA_SIZE                 = 2384,             /* Antenna size (cm)                                            */
    IOP_MR_SPOKE_AVERAGE                = 2385,             /* Spoke sample average (samples to average)                    */
    IOP_MR_SPOKE_DETECT_MODE            = 2386,             /* Spoke detect mode                                            */
    IOP_MR_ERROR_LEVEL                  = 2387,             /* Error level - sets error reporting level                     */
    IOP_MR_LIMITER_OVERRIDE             = 2388,             /* Limiter override - limiter signal control                    */
    IOP_MR_LOW_COLOR_MODE               = 2389,             /* Low color mode - enable low color spokes                     */
    IOP_MR_RADAR_MODE_RANGE_B           = 2390,             /* Range B Radar mode (harbor, offshore, bird)                  */
    IOP_MR_AGC_THRESHOLD_RANGE_B        = 2391,             /* Range B AGC threshold (1/100 percent)                        */
    IOP_MR_AGC_SENSITIVITY_RANGE_B      = 2392,             /* Range B AGC sensitivity (1/100 percent)                      */
    IOP_MR_SEA_CLUTTER_SENSITIVITY_A    = 2393,             /* Range A sea clutter sensitivity (1/100 percnt)               */
    IOP_MR_SEA_CLUTTER_SENSITIVITY_B    = 2394,             /* Range B sea clutter sensitivity (1/100 percnt)               */
    IOP_MR_SPOKE_TOTAL                  = 2395,             /* Spoke total (per rotation)                                   */
    IOP_MR_ECHO_TRAIL_MODE_RANGE_A      = 2396,             /* Range A echo trail mode                                      */
    IOP_MR_ECHO_TRAIL_TIME_RANGE_A      = 2397,             /* Range A echo trail time                                      */
    IOP_MR_ECHO_TRAIL_MODE_RANGE_B      = 2398,             /* Range B echo trail mode                                      */
    IOP_MR_ECHO_TRAIL_TIME_RANGE_B      = 2399,             /* Range B echo trail time                                      */
    IOP_MR_SCAN_MODE_RANGE_A            = 2400,             /* Range A scanning mode (classic, doppler)                     */
    IOP_MR_SCAN_MODE_RANGE_B            = 2401,             /* Range B scanning mode (classic, doppler)                     */
    IOP_MR_PULSE_EXPAND_MODE_RANGE_A    = 2402,             /* Range A pulse expansion mode (on or off)                     */
    IOP_MR_PULSE_EXPAND_MODE_RANGE_B    = 2403,             /* Range B pulse expansion mode (on or off)                     */
    IOP_MR_ROF_FILTER_MODE_RANGE_A      = 2404,             /* Range A ROF filter mode (off, static, dynamic, normalize)    */
    IOP_MR_ROF_FILTER_MODE_RANGE_B      = 2405,             /* Range B ROF filter mode (off, static, dynamic, normalize)    */
    IOP_MR_TRANSMIT_CHANNEL_MODE        = 2406,             /* Transmit channel select mode (manual, auto)                  */
    IOP_MR_TRANSMIT_CHANNEL_SELECT      = 2407,             /* Transmit channel select (0 - max)                            */
    IOP_MR_TARGET_SIZE_MODE_RANGE_A     = 2408,             /* Range A target size mode (normal, larger, smaller )          */
    IOP_MR_TARGET_SIZE_MODE_RANGE_B     = 2409,             /* Range B target size mode (normal, larger, smaller )          */
    IOP_MR_NO_TX_ZONE_2_MODE            = 2410,             /* No transmit zone 2 mode (on or off)                          */
    IOP_MR_NO_TX_ZONE_2_BEGIN           = 2411,             /* No transmit zone 2 Begin (1/32 degree)                       */
    IOP_MR_NO_TX_ZONE_2_END             = 2412,             /* No transmit zone 2 end (1/32 degree)                         */
    IOP_MR_DOPPLER_SENSITIVITY_RANGE_A  = 2413,             /* Range A Doppler sensitivity (1/100 percent)                  */
    IOP_MR_DOPPLER_SENSITIVITY_RANGE_B  = 2414,             /* Range B Doppler sensitivity (1/100 percent)                  */
    IOP_MR_CROSSTALK_LEVEL              = 2415,             /* Crosstalk level (Off, Low, Medium, High)                     */
    IOP_MR_SSA_FILTER_MODE_RANGE_A      = 2416,             /* Range A SSA filter mode (Off, Fixed, Relative)               */
    IOP_MR_SSA_FILTER_MODE_RANGE_B      = 2417,             /* Range B SSA filter mode (Off, Fixed, Relative)               */
    IOP_MR_SSA_SENSITIVITY_RANGE_A      = 2418,             /* Range A SSA filter sensitivity (1/100 percent)               */
    IOP_MR_SSA_SENSITIVITY_RANGE_B      = 2419,             /* Range B SSA filter sensitivity (1/100 percent)               */

    /*------------------------------------------------------
    Add new radar command Inst IDs go here as required.
    ------------------------------------------------------*/
    IOP_MR_COMMAND_INST_LAST            = 2449,             /* Last radar command ID                                        */

    /*------------------------------------------------------
    Radar Enhanced Data Inst IDs
    ------------------------------------------------------*/
    IOP_MR_SM_STATE                     = 2450,             /* Current state machine state (operating mode)                 */
    IOP_MR_EXPIRE_TIME                  = 2451,             /* State expiration Time (msec)                                 */
    IOP_MR_ROTATION_SPEED               = 2452,             /* Current rotation speed (1/100 RPM)                           */
    IOP_MR_ROTATION_POSITION            = 2453,             /* Current rotation position (1/32 degree)                      */
    IOP_MR_TARGET_POSITION              = 2454,             /* Last reported target dataset position (1/32 degree)          */
    IOP_MR_TARGET_DATA_PACKET           = 2455,             /* One packet of a target dataset (RDR_send_target_data_type)   */
    IOP_MR_SPOKE_DATASET                = 2456,             /* Spoke dataset (8 bit intensity)                              */
    IOP_MR_AFC_DATASET                  = 2457,             /* AFC dataset (RDR_afc_dataset_type)                           */
    IOP_MR_AFC_FACTORY_TUNE_PROGRESS    = 2458,             /* AFC factory tune function progress                           */
    IOP_MR_ERROR_DATASET                = 2459,             /* Error dataset reporting                                      */
    IOP_MR_MODULATOR_CONTROL            = 2460,             /* Modulator control (on/off)                                   */
    IOP_MR_TRANSMITTER_CONTROL          = 2461,             /* Transmitter control (on/off)                                 */
    IOP_MR_SUSPEND_CONTROL              = 2462,             /* Suspend control (on/off)                                     */
    IOP_MR_RANGE_MAX                    = 2463,             /* Range maximum (meters)                                       */
    IOP_MR_SPEED_MAX                    = 2464,             /* Speed maximum (1/100 RPM)                                    */
    IOP_MR_SPOKES_MAX                   = 2465,             /* Spokes maximum per rotation                                  */
    IOP_MR_TRANSMIT_POWER_MODE          = 2466,             /* Transmit power mode                                          */
    IOP_MR_INPUT_VOLTAGE                = 2467,             /* Input voltage (dvolts)                                       */
    IOP_MR_HEATER_VOLTAGE               = 2468,             /* Heater voltage (dvolts)                                      */
    IOP_MR_HEATER_STATUS                = 2469,             /* Heater status (on or off)                                    */
    IOP_MR_HIGH_VOLTAGE                 = 2470,             /* High voltage supply (dvolts)                                 */
    IOP_MR_TRANSMIT_CURRENT             = 2471,             /* Transmit Current (mamp)                                      */
    IOP_MR_SYSTEM_TEMP                  = 2472,             /* System temperature (1/100 degree c)                          */
    IOP_MR_MODULATOR_TEMP               = 2473,             /* Modulator temperature (1/100 degree c)                       */
    IOP_MR_OPERATION_TIME               = 2474,             /* Operation time (minutes)                                     */
    IOP_MR_MODULATOR_TIME               = 2475,             /* Modulator time (minutes)                                     */
    IOP_MR_TRANSMIT_TIME                = 2476,             /* Transmit time (minutes)                                      */
    IOP_MR_ERROR_LOG_DATA               = 2477,             /* Error log data (multiple records)                            */
    IOP_MR_ERROR_FLAG_DATA              = 2478,             /* Error flag data (multiple entries)                           */
    IOP_MR_GAIN_FLOOR_VALUE             = 2479,             /* Gain floor calculated (32 bit sample value)                  */
    IOP_MR_GAIN_WINDOW_VALUE            = 2480,             /* Gain window value calculated (32 bit sample value)           */
    IOP_MR_CAPABILITY_FLAGS             = 2481,             /* Capability flags (support features and mode flags)           */
    IOP_MR_CAPABILITY_RANGES            = 2482,             /* Capability ranges (list of valid ranges)                     */
    IOP_MR_SPOKE_LOW_COLOR_DATASET      = 2483,             /* Spoke low color dataset (packed 2 bit intensity)             */
    IOP_MR_BOAT_SENSOR_DATA             = 2484,             /* Boat sensor data (BSD) packet                                */
    IOP_MR_RANGE_SELECT_MAX             = 2485,             /* Range selection maximum (meters)                             */
    IOP_MR_TRANSMIT_CHANNEL_MAX         = 2486,             /* Transmit channel selection max                               */
    IOP_MR_DOPPLER_SENSITIVITY_DEFAULT  = 2487,             /* Doppler sensitivity default value (1/100 percent)            */

    /*------------------------------------------------------
    Add new radar data Inst IDs here as required.
    ------------------------------------------------------*/

    /*------------------------------------------------------
    System level radar IDs will be created from the end
    of the last Marine Radar ID.
    ------------------------------------------------------*/
    IOP_MR_CALIB_MANAGEMENT             = 2518,             /* Radar calibration management                                 */
    IOP_MR_TARGET_TRACK_SYNC            = 2519,             /* Target Track Synchronization, Device Management, and Control */
    IOP_MR_DATA_INST_LAST               = 2520,             /* Last radar data ID                                           */

    /*------------------------------------------------------
    Inst ID's for GMM
    ------------------------------------------------------*/
    IOP_GMM_FIRST                       = 2521,
    IOP_GMM_LAST                        = 2550,

    /*------------------------------------------------------
    Joystick Test Mode Data
    ------------------------------------------------------*/
    IOP_JOYSTICK_TEST_COORDINATES       = 2551,

    /*------------------------------------------------------
    Request the Basemap Checksum
    ------------------------------------------------------*/
    IOP_BMAP_CHECKSUM                   = 2552,

    /*------------------------------------------------------
    Base map Checksum Result
    ------------------------------------------------------*/
    IOP_BMAP_CHECKSUM_RSLT              = 2553,

    /*------------------------------------------------------
    Power down cancel message.
    ------------------------------------------------------*/
    IOP_PWRDN_CANCEL_MSG                = 2554,             /* Used to cancel the power down timer                          */
    IOP_PWRDN_SHOW_MSG                  = 2555,             /* Used to show the power down timer                            */

    /*------------------------------------------------------
    J1939 Connection Status
    ------------------------------------------------------*/
    IOP_J1939_STATUS                    = 2556,

    /*---------------------------------------------------------
    Sync framework
    ---------------------------------------------------------*/
    IOP_SYNC_MASTER_ADVERTISE           = 2557,
    IOP_SYNC_N2K_MSG                    = 2558,
    IOP_SYNC_RS232_MSG                  = 2559,
    IOP_SYNC_MASTER_ADVERTISE_V2        = 2560,
    IOP_SYNC_LAST_ID                    = 2564, /* Placeholder  */

    /*------------------------------------------------------
    Ethernet Bridging Synchronization
    ------------------------------------------------------*/
    IOP_NET_BRIDGE_CTRL                 = 2565,

    /*------------------------------------------------------
    Close sd card review page
    ------------------------------------------------------*/
    IOP_SD_VOL_CLOSE_REVIEW             = 2566,

    /*------------------------------------------------------
    Test mode boot configuration
    ------------------------------------------------------*/
    IOP_TEST_MODE_BOOT_CFG_DATA         = 2567,

    /*------------------------------------------------------
    Aspect Ratio Inst ID's
    ------------------------------------------------------*/
    IOP_SET_ASPECT_RATIO                = 2568,
    IOP_GET_ASPECT_RATIO                = 2569,
    IOP_ASPECT_RATIO_DATA               = 2570,

    /*------------------------------------------------------
    Network event
    ------------------------------------------------------*/
    IOP_CNS_NETWORK_EVENT_ID            = 2571,

    /*------------------------------------------------------
    Layout Event
    ------------------------------------------------------*/
    IOP_LAYOUT_EVENT                    = 2572,

    /*------------------------------------------------------
    CAP data capture module IDs
    ------------------------------------------------------*/
    IOP_CAP_DATA_MODE                   = 2573,      /* Capture mode control    */
    IOP_CAP_PAYLOAD_CTRL                = 2574,      /* Capture payload control */
    IOP_CAP_DATA_SEND                   = 2575,      /* Capture capture packet  */
    IOP_CAP_DATA_REPLAY                 = 2576,      /* Capture replay packet   */

    /*------------------------------------------------------
    Touchscreel Self Test Results
    ------------------------------------------------------*/
    IOP_TS_SELF_TEST_RESULT             = 2577,

    /*------------------------------------------------------
    IOP Inst to run extended RGB Video In Tests
    ------------------------------------------------------*/
    IOP_VID_IN_RGB_EXTND_TEST           = 2578,

    /*----------------------------------------------------------
    Touch Screen false touch count
    ----------------------------------------------------------*/
    IOP_TS_FALSE_TOUCH_CNT              = 2579,

    /*------------------------------------------------------
    Profile IDs
    ------------------------------------------------------*/
    IOP_PROFILE_FIRST                   = 2580,
    IOP_PROFILE_CREATE                  = IOP_PROFILE_FIRST,
    IOP_PROFILE_DESTROY                 = 2581,
    IOP_PROFILE_RENAME                  = 2582,
    IOP_PROFILE_SAVE                    = 2583,
    IOP_PROFILE_LOAD_DISPLAY            = 2584,
    IOP_PROFILE_LOAD_STATION            = 2585,
    IOP_PROFILE_EXPORT                  = 2586,
    IOP_PROFILE_IMPORT                  = 2587,
    IOP_PROFILE_STATUS                  = 2588,
    IOP_PROFILE_ACK                     = 2589,
    IOP_PROFILE_CREATE_EXTERNAL         = 2590,
    IOP_PROFILE_LOAD_FILES              = 2591,
    IOP_PROFILE_LOAD_DONE               = 2592,
    IOP_PROFILE_LAST                    = 2599,

    /*------------------------------------------------------
    Digital Switching Load Image
    ------------------------------------------------------*/
    IOP_DSW_LOAD_IMAGE                  = 2600,

    /*------------------------------------------------------
    Radar Test Configure
    ------------------------------------------------------*/
    IOP_MR_TEST_CONFIG                  = 2601,

    /*------------------------------------------------------
    Sets the default transducer
    ------------------------------------------------------*/
    IOP_DFLT_XDCR_DATA                  = 2602,

    /*------------------------------------------------------
    Yamaha J1939 Bridging Synchronization
    ------------------------------------------------------*/
    IOP_YAMAHA_J1939_BRIDGE_CTRL        = 2603,

    /*------------------------------------------------------
    WOL support
    ------------------------------------------------------*/
    IOP_MARINE_WOL_WAKE                 = 2604,
    IOP_MARINE_REC_WAKE                 = 2605,

    /*------------------------------------------------------
    DCI weather ID group
    ------------------------------------------------------*/
    IOP_DCI_WX_START                    = 2606,
    IOP_DCI_WX_OFFLINE                  = 2607,
    IOP_DCI_WX_ON_DEMAND_RQST           = 2608,
    IOP_DCI_WX_ON_DEMAND                = 2609,
    IOP_DCI_SUBSCRIPTION_INFO           = 2610,
    IOP_DCI_WX_END                      = 2615,

    /*------------------------------------------------------
    Yamaha NMEA 2000 Bridging Synchronization
    ------------------------------------------------------*/
    IOP_YAMAHA_N2K_BRIDGE_CTRL          = 2616,

    /*------------------------------------------------------
    Communication interface to send messages between sonar
    blackbox and transducer.
    ------------------------------------------------------*/
    IOP_MRN_XDCR_COMM_INTF_MSG          = 2617,

    /*------------------------------------------------------
    Yamaha NMEA 2000 Secondary Bridging Synchronization
    ------------------------------------------------------*/
    IOP_YAMAHA_N2K_SECONDARY_BRIDGE_CTRL = 2618,

    /*------------------------------------------------------
    Query Test IDs
    ------------------------------------------------------*/
    IOP_QUERY_CONTROL_TEST_ID           = 2619,
    IOP_QUERY_FOCUS_TEST_ID             = 2620,  /* Query test ID for screen element with focus */
    IOP_QUERY_SCREEN_TEST_IDS           = 2621,  /* Query all screen test IDs by mask */
    IOP_QUERY_TEST_IDS_END              = 2622,  /* Unused, available ID */

    /*------------------------------------------------------
    Share Garmin SCM settings (locales, units, ...)
    to non Garmin devices on N2K bus.
    ------------------------------------------------------*/
    IOP_MRN_SHARE_SETTINGS_DATA         = 2623,
    IOP_MRN_SHARE_SETTINGS_RQST         = 2624,

    /*------------------------------------------------------
    Trolling Motor IDs
    ------------------------------------------------------*/
    IOP_TM_START                        = 2625,  /* Marker only */

    IOP_TM_TEST                         = 2625,  /* Test Commands */
    IOP_TM_TEST_RSP                     = 2626,  /* Test Responses */
    IOP_TM_ANGLE                        = 2627,  /* Servo Angle Data */
    IOP_TM_INTERNAL_MSG                 = 2628,  /* Transport IOP for internal TMI messages */
    IOP_TM_STATUS                       = 2629,  /* Status Data */
    IOP_TM_RPM_DATA                     = 2630,  /* Motor RPM Data */

    IOP_TM_END                          = 2644,  /* Marker only */

    /*------------------------------------------------------
    Trolling Motor Pedal IDs
    ------------------------------------------------------*/
    IOP_TM_PEDAL_START                  = 2645,  /* Marker only */

    IOP_TM_PEDAL_CAL_RESP               = 2645,
    IOP_TM_PEDAL_PIVOT_ANGLE            = 2646,
    IOP_TM_PEDAL_SPEED_ANGLE            = 2647,
    IOP_TM_PEDAL_TEST_LED               = 2648,
    IOP_TM_PEDAL_SPEED_ADJ              = 2649,

    IOP_TM_PEDAL_END                    = 2654,  /* Marker only */

    /*------------------------------------------------------
    Security Sensor Status
    ------------------------------------------------------*/
    IOP_MRN_SECURITY_SNSR_STATUS        = 2655,

    /*------------------------------------------------------
    Shore Power Status
    ------------------------------------------------------*/
    IOP_MRN_SHORE_POWER_STATUS          = 2656,

    /*------------------------------------------------------
    Bilge Pump Data
    ------------------------------------------------------*/
    IOP_MRN_BILGE_PUMP_DATA             = 2657,

    /*------------------------------------------------------
    MiniGRID Group
    ------------------------------------------------------*/
    IOP_MGRID_GMN_HEARTBEAT             = 2658,
    IOP_MGRID_GMN_HEARTBEAT_ACK         = 2659,
    IOP_MGRID_JOYSTICK_XY_DATA          = 2660,
    IOP_MGRID_GMN_KEY_DATA              = 2661,
    IOP_MGRID_N2K_HEARTBEAT             = 2662,
    IOP_MGRID_N2K_PAIRING               = 2663,
    IOP_MGRID_N2K_SETTINGS              = 2664,
    IOP_MGRID_SHUTDOWN                  = 2665,
    IOP_MGRID_TIMEOUT                   = 2666,
    IOP_MGRID_GMN_ANT_DISCONNECT_ALL    = 2667,
    IOP_MGRID_WHEEL_ROTATION_DATA       = 2668,
    IOP_MGRID_N2K_KEY_DATA              = 2669,
    IOP_MGRID_SOS_MODE                  = 2670,
    IOP_MGRID_END                       = 2672,

    /*----------------------------------------------------------
    External GPIO Test ID groupd
    ----------------------------------------------------------*/
    IOP_EXT_GPIO_GROUP_START            = 2673,
    IOP_EXT_BATT_VOLT_DATA              = 2673,
    IOP_EXT_TEMP_VOLT_DATA              = 2674,
    IOP_EXT_GPIO_SET                    = 2675,
    IOP_EXT_GPIO_STATUS                 = 2676,
    IOP_EXT_GPIO_GROUP_END              = 2680,

    /*----------------------------------------------------------
    RV Vehicle Integration Service (VIS) message
    ----------------------------------------------------------*/
    IOP_RV_VIS_MSG                      = 2681,

    /*------------------------------------------------------
    Digital Switching Server
    ------------------------------------------------------*/
    IOP_DSW_SERVER_STATE                = 2682,
    IOP_DSW_SERVER_STATE_SET            = 2683,
    IOP_DSW_SERVER_CONFIG               = 2684,
    IOP_DSW_SERVER_CONFIG_REQUEST       = 2685,
    IOP_DSW_SERVER_CONFIG_SET           = 2686,

    /*----------------------------------------------------------
    Internally Sourced Data Test ID Group
    ----------------------------------------------------------*/
    IOP_INT_DATA_GROUP_START            = 2687,
    IOP_INT_VOLT_DATA                   = 2687,
    IOP_INT_TEMP_DATA                   = 2688,
    IOP_INT_DATA_GROUP_END              = 2692,

    /*----------------------------------------------------------
    Factory Burn in Thermal Data
    ----------------------------------------------------------*/
    IOP_FACTORY_BURN_IN_THERMAL_DATA    = 2693,

    /*------------------------------------------------------
    Last Marine Reserved ID
    ------------------------------------------------------*/
    IOP_LAST_RESERVED_MARINE_ID         = 2999,

    /*------------------------------------------------------
    Sets the default backlight setting on battery power
    ------------------------------------------------------*/
    IOP_SET_DFLT_BATT_BL                = 3000,

    /*------------------------------------------------------
    Requests the acceleration in gs for all three axes
    ------------------------------------------------------*/
    IOP_RQST_ACCEL_3_AXIS               = 3001,

    /*------------------------------------------------------
    The response message with acceleration in gs for all three axes
    ------------------------------------------------------*/
    IOP_RSPNS_ACCEL_3_AXIS              = 3002,

    /*------------------------------------------------------
    GNSS Satellite Data Requests/Reponses
    ------------------------------------------------------*/
    IOP_GNSS_SAT_DATA                   = 3003, /* Output GNSS satellite data */
    IOP_GNSS_DATA_SRC_RESPONSE          = 3004, /* Response to request data src command */
    IOP_GNSS_SELECT_DATA_SRC            = 3005, /* Set GNSS data source(s) */

    /*------------------------------------------------------
    IOP command to tune acoustic parameters inside car
    -----------------------------------------------------*/
    IOP_AUDIO_ACOUSTIC_TUNING            = 3006,

    /*------------------------------------------------------
    Top level IOP inst IDs reserved for GPS IOP extensions
    -----------------------------------------------------*/
    IOP_GPS_GENERIC_START                = 3007,
    IOP_GPS_GENERIC                      = 3007,
    IOP_GPS_SNSR_RQST_FIX_RATE_HZ        = 3008,
    IOP_GPS_SNSR_RESP_FIX_RATE_HZ        = 3009,
    IOP_GPS_POWER_MODE_CFG               = 3010,
    IOP_GPS_GENERIC_RSRVD_3              = 3011,
    IOP_GPS_GENERIC_RSRVD_4              = 3012,
    IOP_GPS_GENERIC_RSRVD_5              = 3013,
    IOP_GPS_GENERIC_RSRVD_6              = 3014,
    IOP_GPS_GENERIC_RSRVD_7              = 3015,
    IOP_GPS_GENERIC_END                  = 3015,

    /*------------------------------------------------------
    IOP command to set sleep level
    ------------------------------------------------------*/
    IOP_SET_SLEEP_LVL                    = 3016,

    /*------------------------------------------------------
    GPS Pulse Per Second (PPS) configuration
    ------------------------------------------------------*/
    IOP_GPS_PPS_CONFIG                   = 3017,

    /*------------------------------------------------------
    AMX device factory test instructions
    ------------------------------------------------------*/
    IOP_AMX_PROGRAM_PARTNER_INFO_DATA    = 3018,
    IOP_AMX_RSRVD_0                      = 3019,
    IOP_AMX_RSRVD_1                      = 3020,
    IOP_AMX_RSRVD_2                      = 3021,
    IOP_AMX_RSRVD_3                      = 3022,
    IOP_AMX_RSRVD_4                      = 3023,
    IOP_AMX_END                          = 3023,

    /*------------------------------------------------------
    ID's for FDA logging
    -----------------------------------------------------*/
    IOP_PVT_REMOTE_FDA_INST_START        = 3024,
    IOP_PVT_REMOTE_FDA_STATE_DATA        = 3024,
    IOP_PVT_REMOTE_FDA_SAT               = 3025,
    IOP_PVT_REMOTE_FDA_RESERVED1         = 3026,
    IOP_PVT_REMOTE_FDA_RESERVED2         = 3027,
    IOP_PVT_REMOTE_FDA_RESERVED3         = 3028,
    IOP_PVT_REMOTE_FDA_INST_END          = 3028,

    /*------------------------------------------------------
    Generic Inst ID for all GPS instrumentation data.
    -----------------------------------------------------*/
    IOP_GENERIC_GPS_INST_DATA            = 3029,

    /*------------------------------------------------------
    Watchdog Timer Log data request/reply IDs
    ------------------------------------------------------*/
    IOP_WDT_LOG_RQST                     = 3030,    /* Request for WDT Log data             */
    IOP_WDT_LOG_DATA                     = 3031,    /* Reply with all WDT Log data          */
    IOP_WDT_LOG_DATA_ABBREV              = 3032,    /* Reply with abbreviated WDT Log data  */
    IOP_WDT_TEST                         = 3033,    /* INST ID for WDT Testing Data         */
    IOP_WDT_DUMMY                        = 3034,    /* Unused, but reserved for WDT         */

    /*------------------------------------------------------
    Alpha specific instrument IDs
    ------------------------------------------------------*/
    IOP_ALPHA_INST_BEGIN                 = 3035,
    IOP_ALPHA_STIM_START                 = 3035,
    IOP_ALPHA_STIM_STOP                  = 3036,

    IOP_ALPHA_MAIN_STATE                 = 3037,
    IOP_ALPHA_TRACKING_SETTINGS          = 3038,

    IOP_ALPHA_PAIR_REPLY                 = 3039,

    IOP_ALPHA_PASS_THRU                  = 3040,
    IOP_ALPHA_USER_LEVEL_STIM            = 3041,

    /*------------------------------------------------------
    LFCOMM ATE testing IOP
    ------------------------------------------------------*/
    IOP_ALPHA_LFCOMM_TEST                = 3042,

    /*------------------------------------------------------
    Microphone ATE testing IOP
    ------------------------------------------------------*/
    IOP_ALPHA_MICROPHONE_TEST            = 3043,
    IOP_ALPHA_SET_RFC_MODE               = 3044,

    IOP_ALPHA_RF_MODE                    = 3045,
    IOP_ALPHA_RF_PWR                     = 3046,
    IOP_ALPHA_RF_PROP                    = 3047,
    IOP_ALPHA_RF_CHNL                    = 3048,
    IOP_ALPHA_ANT_MASTER_ON_OFF          = 3049,
    IOP_ALPHA_INST_END                   = 3049,

    /*------------------------------------------------------
    Bounding Box Restriction IDs
    ------------------------------------------------------*/
    IOP_RESTRICT_BBOX_SEND              = 3050,
    IOP_RESTRICT_BBOX_SEND_RESPONCE     = 3051,
    IOP_RESTRICT_BBOX_GET               = 3052,
    IOP_RESTRICT_BBOX_GET_RESPONCE      = 3053,
    IOP_RESTRICT_BBOX_CLEAR             = 3054,
    IOP_RESTRICT_BBOX_CLEAR_RESPONCE    = 3055,

    /*------------------------------------------------------
    Barometer internal values manipulation
    ------------------------------------------------------*/
    IOP_BARO_CONST_PROM_VALS_GET        = 3056,
    IOP_BARO_CONST_PROM_VALS_RESPONSE   = 3057,
    IOP_BARO_CONST_STORED_VALS_GET      = 3058,
    IOP_BARO_CONST_STORED_VALS_RESPONSE = 3059,
    IOP_BARO_CONST_STORED_VAL_PROGRAM   = 3060,
    IOP_BARO_D_VALS_GET                 = 3061,
    IOP_BARO_D_VALS_RESPONSE            = 3062,

    /*------------------------------------------------------
    Sound test result ID
    ------------------------------------------------------*/
    IOP_SOUND_TEST_RSLT                 = 3063,

    /*------------------------------------------------------
    I/O expander input state
    ------------------------------------------------------*/
    IOP_IO_EXP_STATE                    = 3064,

    /*------------------------------------------------------
    Steering wheel key state
    ------------------------------------------------------*/
    IOP_VIM_KEY_STATE                   = 3065,

    /*------------------------------------------------------
    Steering wheel key state
    ------------------------------------------------------*/
    IOP_VIM_BT_STW_KEY_STATE            = 3066,

    /*------------------------------------------------------
    Speed of the vehicle
    ------------------------------------------------------*/
    IOP_SPEED_DATA                      = 3067,

    /*------------------------------------------------------
    Camera detection status
    ------------------------------------------------------*/
    IOP_CAMERA_STATUS                   = 3068,

    /*------------------------------------------------------
    Steer wheel data
    ------------------------------------------------------*/
    IOP_STEER_WHEEL_DATA                = 3069,

    /*------------------------------------------------------
    Amplifier tests
    ------------------------------------------------------*/
    IOP_AMP_TEST                        = 3071,
    IOP_AMP_TEST_DONE                   = 3072,
    IOP_AMP_TEST_RESULTS                = 3073,

    /*------------------------------------------------------
    Fan configuration
    ------------------------------------------------------*/
    IOP_SET_FAN_DATA                    = 3076,

    /*------------------------------------------------------
    DVD Player Data
    ------------------------------------------------------*/
    IOP_DVD_PLAYER_DATA                 = 3077,

    /*------------------------------------------------------
    Tracked Asset Point Info
    ------------------------------------------------------*/
    IOP_DTRK_PT_DATA                    = 3078,

    /*------------------------------------------------------
    GPIO Command/Response
    ------------------------------------------------------*/
    IOP_GPIO_CMD                        = 3079,
    IOP_GPIO_DATA                       = 3080,

    /*------------------------------------------------------
    Button Backlighting/Illumination Data
    ------------------------------------------------------*/
    IOP_ILLUM_DATA                      = 3081,

    /*------------------------------------------------------
    ADC counts obtained from VIM for steering wheel keys
    ------------------------------------------------------*/
    IOP_VIM_AUD_ADC_STATE               = 3082,
    IOP_VIM_BT_ADC_STATE                = 3083,

    /*------------------------------------------------------
    Enable/Disable Clock Source Output
        must specify clock source output to enable/disable
    ------------------------------------------------------*/
    IOP_ENABLE_CLK_SRC_OUTPUT           = 3084,
    IOP_DISABLE_CLK_SRC_OUTPUT          = 3085,

    /*------------------------------------------------------
    Reserved for MFI(made for ipod) Specific Instrumentation
    IDs
    ------------------------------------------------------*/
    IOP_MFI_START_COPROCESSOR_TEST      = 3086, /* Start MFI Coprocessor Self-Test */
    IOP_MFI_INST_RESPONSE               = 3087, /* MFI INST success/fail response  */

    IOP_LAST_MFI_ID                     = 3089,

    /*------------------------------------------------------
    IOP power cycle test mode
    ------------------------------------------------------*/
    IOP_PWR_CYCLE_TEST_MODE             = 3090,

    /*------------------------------------------------------
    Reserved for Aviation Specific Instrumentation IDs
    ------------------------------------------------------*/
    IOP_FIRST_AVTN_ID                   = 4000,
    IOP_AVTN_SET_DATA                   = 4001,
    IOP_AVTN_GET_DATA                   = 4002,
    IOP_AVTN_SET_GPS_PASSTHROUGH        = 4003,
    IOP_AVTN_BTN_PRESS_EVNT             = 4004,

    IOP_LAST_AVTN_ID                    = 4999,

    /*------------------------------------------------------
    Reserved for Fitness Device Interface IDs
    ------------------------------------------------------*/
    IOP_FIRST_FDI_ID                        = 5000,
    IOP_FDI_MESSAGE_ACKNOWLEDGEMENT         = 5000,
    IOP_FDI_REQUEST_DATA                    = 5001,
    IOP_FDI_DOWNLOAD_REQUEST                = 5002,
    IOP_FDI_UPLOAD_REQUEST                  = 5003,
    IOP_FDI_FILE_TRANSFER_DATA              = 5004,
    IOP_FDI_CREATE_FILE_REQUEST             = 5005,
    IOP_FDI_DELETE_FILE_REQUEST             = 5006,
    IOP_FDI_DIRECTORY_FILE_FILTER_REQUEST   = 5007,
    IOP_FDI_SET_FILE_FLAGS                  = 5008,
    IOP_FDI_FILE_READY                      = 5009,
    IOP_FDI_LOCATION                        = 5010,
    IOP_FDI_FIT_DEFINITION                  = 5011,
    IOP_FDI_FIT_DATA                        = 5012,
    IOP_FDI_FIT_RECORD_REQUEST              = 5013,
    IOP_FDI_WEATHER_REQUEST                 = 5014,
    IOP_FDI_WEATHER_ALERT                   = 5015,
    IOP_FDI_TRACKING_REQUEST                = 5016,
    IOP_FDI_WEATHER_DATA                    = 5017,
    IOP_FDI_TRACKING_DATA                   = 5018,
    IOP_FDI_GPS_EPHEMERIS_DATA_REQUEST      = 5019,
    IOP_FDI_GPS_EPHEMERIS_DATA              = 5020,
    IOP_FDI_REQUEST_TIMEOUT                 = 5021,
    IOP_FDI_FILE_TRANSFER_CANCEL            = 5022,
    IOP_FDI_BATTERY_STATUS                  = 5023,
    IOP_FDI_GARMIN_DEVICE_INFO              = 5024,
    IOP_FDI_STOP_TRACKING                   = 5025,
    IOP_FDI_DEVICE_SETTINGS                 = 5026,
    IOP_FDI_QUEUED_DOWNLOAD_REQUEST         = 5027,
    IOP_FDI_GPS_EPHEMERIS_EPO_DATA_REQUEST  = 5028,
    IOP_FDI_GPS_EPHEMERIS_EPO_DATA          = 5029,
    IOP_FDI_SYSTEM_EVENT                    = 5030,
    IOP_FDI_SUPPORTED_FILE_TYPES_REQUEST    = 5031,
    IOP_FDI_FILE_LISTING_REQUEST            = 5032,
    IOP_FDI_GNCS_NOTIFICATION_SOURCE        = 5033,
    IOP_FDI_GNCS_CONTROL_POINT              = 5034,
    IOP_FDI_GNCS_DATA_SOURCE                = 5035,
    IOP_FDI_GNCS_SERVICE_SUBSCRIPTION       = 5036,
    IOP_FDI_MANUAL_SYNC_REQUEST             = 5037,
    IOP_FDI_PROTOCOL_BUFFER_DATA            = 5038,
    IOP_FDI_FIND_MY_PHONE_REQUEST           = 5039,
    IOP_FDI_FIND_MY_PHONE_CANCEL            = 5040,
    IOP_FDI_MUSIC_CONTROL_COMMAND           = 5041,
    IOP_FDI_MUSIC_CONTROL_CAPABILITIES      = 5042,
    IOP_FDI_PROTOBUF_REQUEST                = 5043,
    IOP_FDI_PROTOBUF_RESPONSE               = 5044,
    IOP_FDI_PROTOBUF_CANCEL_REQUEST         = 5045,
    IOP_FDI_AUTO_START_TRACKING             = 5046,
    IOP_FDI_CANCEL_AUTO_START_TRACKING      = 5047,
    IOP_FDI_AUTO_START_TRACKING_FAILURE     = 5048,
    IOP_FDI_MUSIC_CONTROL_ENTITY_UPDATE     = 5049,
    IOP_FDI_DEVICE_CONFIGURATION            = 5050,
    IOP_FDI_DUAL_PAIRING_STATUS             = 5051,
    IOP_FDI_CURRENT_TIME_REQUEST            = 5052,

    IOP_FDI_COMPRESSED_FILE_TRANSFER_DATA   = 5054,
    IOP_FDI_PAIRING_INFO                    = 5055,
    IOP_FDI_PAIRING_REQUEST                 = 5056,

    IOP_NUM_USED_FDI_ID                     = 5057 - IOP_FIRST_FDI_ID,

    /*-------------------------------
    Block 5060-5079 reserved for
    vivokid product related Fit
    Device Interface IDs.
    --------------------------------*/
    IOP_FIRST_KID_FDI_ID                    = 5060,
    IOP_FDI_KID_SET_COIN_TOTAL              = 5060,
    IOP_FDI_KID_SET_CHORES_TOTAL            = 5061,
    IOP_FDI_KID_TIMER_NOTIFICATION          = 5062,
    IOP_FDI_KID_ACTIVE_TIME_STEP_DATA       = 5063,
    IOP_FDI_KID_SET_GRAPHIC_USAGE           = 5064,
    IOP_FDI_KID_QUERY_GRAPHIC_USAGE         = 5065,
    IOP_FDI_KID_SET_GAME_LEVEL              = 5066,

    /*---------------------------
    Block 5080-5099 reserved for
    dog product related GFDI IDs.
    ---------------------------*/
    IOP_FIRST_DOG_FDI_ID                    = 5080,
    IOP_FDI_DOG_BARK_MSG                    = 5085,
    IOP_FDI_DOG_FRIENDLY_NAME_COMMAND       = 5086,
    IOP_FDI_DOG_KEY_FOB_SETUP_COMMAND       = 5087,
    IOP_FDI_DOG_CIRC_PROV_COMMAND           = 5088,
    IOP_FDI_DOG_SET_ADVERT_COMMAND          = 5089,
    IOP_FDI_DOG_TRAINING_COMMAND            = 5090,
    IOP_FDI_DOG_SET_MODE_COMMAND            = 5091,
    IOP_FDI_DOG_NOTIFICATION_COMMAND        = 5092,
    IOP_FDI_DOG_SINGLE_KAT_PROV_COMMAND     = 5093,
    IOP_FDI_DOG_KAT_PROV_COMMAND            = 5094,
    IOP_FDI_DOG_BL_PROV_COMMAND             = 5095,
    IOP_FDI_DOG_CAPABILITY_MSG              = 5096,
    IOP_FDI_DOG_SYNC_TIME_MS_COMMAND        = 5097,
    IOP_FDI_DOG_INFO_MSG                    = 5098,
    IOP_FDI_DOG_HANDSHAKE_MSG               = 5099,

    /*---------------------------
    GFDI Authentication IDs
    ---------------------------*/
    IOP_FDI_AUTH_NEGOTIATION_BEGIN          = 5101,
    IOP_FDI_AUTH_LTK_RECONNECT              = 5102,
    IOP_FDI_AUTH_STK_BEGIN_GENERATION       = 5103,
    IOP_FDI_AUTH_STK_CONFIRM                = 5104,
    IOP_FDI_AUTH_STK_RAND                   = 5105,
    IOP_FDI_AUTH_STK_GENERATION_STATUS      = 5106,
    IOP_FDI_AUTH_LTK_KEY_DISTRIBUTION       = 5107,
    IOP_FDI_AUTH_SESSION_KEY_SKD_DISTRIBUTION = 5108,
    IOP_FDI_AUTH_SESSION_KEY_VERIFICATION   = 5109,
    IOP_FDI_AUTH_PASSKEY_REDISPLAY_REQUEST  = 5110,
    IOP_FDI_AUTH_SESSION_SECURITY_FLAGS     = 5111,
    IOP_FDI_AUTH_OOB_PASSKEY_DATA           = 5112,

    /*---------------------------
    Block 5113-5121 reserved for
    task management related Fit
    Device Interface IDs.
    ---------------------------*/
    IOP_FDI_TASK_START                      = 5113,
    IOP_FDI_TASK_CONFIGURE                  = 5113,
    IOP_FDI_TASK_MARK                       = 5114,
    IOP_FDI_TASK_READ                       = 5115,
    IOP_FDI_TASK_INST_READ                  = 5116,
    IOP_FDI_TASK_INST_WRITE                 = 5117,
    IOP_FDI_TASK_END                        = 5121,

    IOP_LAST_FDI_ID                         = 5299,

    IOP_OEM_MODEL_RSLT                  = 5300,
    IOP_OEM_MARKET_RSLT                 = 5301,

    IOP_CHECK_FOR_BB_RSLT               = 5302,

    /*------------------------------------------------------
    Sensor logging
    ------------------------------------------------------*/
    IOP_SENSOR_LOG_START                = 5303,
    IOP_SENSOR_LOG_STOP                 = 5304,

    /*------------------------------------------------------
    Mass Storage RWFS Volume Enable/Disable
    ------------------------------------------------------*/
    IOP_UMS_RWFS_ENABLE                 = 5305,

    /*------------------------------------------------------
    Sliding control data
    ------------------------------------------------------*/
    IOP_SLIDING_CONTROL_DATA            = 5306,
    IOP_MOTOT_ENABLE_CMD                = 5307,

    /*------------------------------------------------------
    Reserved for Android platform Instrumentation IDs
    ------------------------------------------------------*/
    IOP_FIRST_ANDROID_ID                = 5308,

    IOP_ANDROID_FACTORY_BACKUP          = 5309,
    IOP_ANDROID_FACTORY_RESTORE         = 5310,

    IOP_GAS_GAUGE_FW_VER                = 5311,
    IOP_GAS_GAUGE_ENABLE                = 5312,

    IOP_VIDEOIN_COMPARE                 = 5313,

    IOP_GAS_GAUGE_LOG_CTRL              = 5314,
    IOP_GAS_GAUGE_LOG_DATA              = 5315,

    IOP_DUALTOUCH_RTP_TEST              = 5316,
    IOP_DUALTOUCH_RTP_TEST_SINGLE       = 5317,
    IOP_DUALTOUCH_RTP_TEST_DIST         = 5318,

    IOP_FLASHLIGHT_TEST                 = 5319,

    IOP_UV_TEST_START                   = 5320,
    IOP_UV_TEST_DATA                    = 5321,

    IOP_WAKELOCK_CTRL                   = 5322,

    IOP_GYRO_DATA                       = 5323,
    IOP_GYRO_RAW_DATA                   = 5324,
    IOP_GYRO_BIAS_STATUS                = 5325,
    IOP_GYRO_START_SCALE_FACTOR_CAL     = 5326,
    IOP_GYRO_STOP_SCALE_FACTOR_CAL      = 5327,
    IOP_GYRO_TURNTABLE_SPEED            = 5328,
    IOP_GYRO_SCALE_FACTOR_STATUS        = 5329,

    IOP_POWER_KEY_EVENT                 = 5330,

    IOP_NFC_TEST_PAGE                   = 5340,
    IOP_NFC_FUNC_CHECK                  = 5341,
    IOP_NFC_TAG_TECH                    = 5342,
    IOP_NFC_RF_DETECT                   = 5343,

    IOP_MOUNT_UART_TEST                 = 5345,

    IOP_GYRO_LOG_DATA_HDR               = 5346,
    IOP_GYRO_LOG_DATA                   = 5347,

    IOP_KEYPAD_LED_TEST                 = 5348,

    IOP_LAST_ANDROID_ID                 = 5349,

    /*------------------------------------------------------
    WiFi extended Instrumentation IDs
    ------------------------------------------------------*/
    IOP_WIFI_EXT_START                  = 5350,

    IOP_WIFI_EXT_CAL                    = 5351,
    IOP_WIFI_EXT_ON                     = 5352,
    IOP_WIFI_EXT_CHNG                   = 5353,
    IOP_WIFI_EXT_LINKSPEED              = 5354,
    IOP_WIFI_EXT_TST_MD_STAT            = 5355,
    IOP_WIFI_EXT_SET_DOWNLOAD_IP_ADDR   = 5356,
    IOP_WIFI_EXT_SET_COUNTRY_CODE       = 5357,
    IOP_WIFI_EXT_COUNTRY_CODE_DATA      = 5358,
    IOP_WIFI_EXT_CREATE_AP              = 5359,
    IOP_WIFI_EXT_GET_CNCTN_CNT          = 5360,
    IOP_WIFI_EXT_CNCTN_CNT_DATA         = 5361,
    IOP_WIFI_EXT_GET_IP_ADDR            = 5362,
    IOP_WIFI_EXT_IP_ADDR_DATA           = 5363,
    IOP_WIFI_EXT_WOWLAN                 = 5364,
    IOP_WIFI_EXT_OFF                    = 5365,
    IOP_WIFI_EXT_TEST_SET_MOD32         = 5366,
    IOP_WIFI_EXT_TEST_GET_MOD32         = 5367,
    IOP_WIFI_EXT_TEST_MOD32_DATA        = 5368,
    IOP_WIFI_EXT_CONNMGR_ON             = 5369,

    IOP_WIFI_EXT_GET_CONNECTION_INFO_EXT  = 5370,
    IOP_WIFI_EXT_CONNECTION_INFO_EXT_DATA = 5371,
    IOP_WIFI_EXT_SOC_TEST_CMD           = 5372,

    IOP_WIFI_EXT_END                    = 5399,

    /*------------------------------------------------------
    Nordic Rino650 specific instrument IDs
    ------------------------------------------------------*/
    IOP_NORDIC_INST_BEGIN               = 5400,

    IOP_BT_SHOW_INQ_CONN_INFO           = 5400,
    IOP_BT_SHOW_PAIR_CONN_INFO          = 5401,
    IOP_BT_SEL_INQ_PAIR                 = 5402,
    IOP_BT_SEL_INQ_CONN                 = 5403,
    IOP_BT_SEL_INQ_DISCONN              = 5404,
    IOP_BT_SEL_INQ_STR_SCO              = 5405,
    IOP_BT_SEL_PAIR_CONN                = 5406,
    IOP_BT_SEL_PAIR_DISCONN             = 5407,
    IOP_BT_SEL_STR_SCO                  = 5408,
    IOP_BT_SEL_STP_SCO                  = 5409,
    IOP_RFC_SET_BATT_TYPE               = 5410,
    IOP_BT_SHOW_DEV_NAME                = 5411,
    IOP_RFC_BT_SET_AUD_TEST             = 5412,
    IOP_BT_SWITCH                       = 5413,
    IOP_BT_AUDIO_PATH_SWITCH            = 5414,
    IOP_BT_RFC_AUD_SET_TEST             = 5415,
    IOP_BT_SET_DUT_ADDR                 = 5416,
    IOP_BT_SET_INQURY_MODE              = 5417,
    IOP_NORDIC_INST_END                 = 5429,

    /*------------------------------------------------------
    Demo mode check
    ------------------------------------------------------*/
    IOP_DEMO_MODE_DATA                  = 5430,

    /*------------------------------------------------------
    Reserved for AOEM extended Instrumentation IDs
    ------------------------------------------------------*/
    IOP_AOEN_EXT_NOTIFICATION_DATA      = 5431,
    IOP_AOEM_EXT_FACTORY_TEST_CMND      = 5432,
    IOP_AOEM_EXT_FACTORY_TEST_DATA      = 5433,

    IOP_GET_TW8816_REG                  = 5434,
    IOP_SET_TW8816_REG_ADDR             = 5435,
    IOP_SET_TW8816_REG_VALUE            = 5436,

    IOP_VIDEO_SWITCH_MAP0_CMD           = 5437,
    IOP_VIDEO_SWITCH_MAP1_CMD           = 5438,

    IOP_VIDEO_ENCODER_CH7026_CMD        = 5439,

    IOP_VIM_BY_PASS_CMD                 = 5440,
    IOP_VIM_BY_PASS_DATA                = 5441,
    IOP_REQUEST_CMD                     = 5442,
    IOP_REQUEST_DATA                    = 5443,
    IOP_SWITCH_TO_TEST_MODE_PAGE        = 5444,
    IOP_SWITCH_TO_FRAGMENT              = 5445,
    IOP_VIDEO_PATH_TEST_CMD             = 5446,
    IOP_USER_EVENT                      = 5447,
    IOP_DISABLE_AUTO_PATH_CORRECTION    = 5448,

    IOP_LAST_AOEM_EXT_ID                = 5460,

    /*------------------------------------------------------
    Reserved for HUD (Head-Up Display) Instrumentation IDs
    ------------------------------------------------------*/
    IOP_FIRST_HUD_ID                    = 5461,

    IOP_LAST_HUD_ID                     = 5470,

    /*------------------------------------------------------
    Manufacturing self-test IDs
    ------------------------------------------------------*/
    IOP_TAIWAN_SELF_TEST                = 5471,
    IOP_HW_SELF_TEST_FAILURE            = 5472,
    IOP_HW_SELF_TEST_PASS               = 5473,
    IOP_HW_SELF_TEST_COMPLETE           = 5474,

    /*------------------------------------------------------
    Memory Statistics Logging IDs
    ------------------------------------------------------*/
    IOP_MEM_STATS_LOG_CMND              = 5475,

    /*------------------------------------------------------
    Hardware configuration handling ID
    ------------------------------------------------------*/
    IOP_READ_HW_CONFIG_DATA             = 5476,

    /*------------------------------------------------------
    video camaera Instrumentation IDs (action camera / virb )
    ------------------------------------------------------*/
    IOP_VIDEO_STATE_ID                  = 5477,             /* control video camera state machine   */
    IOP_VIDEO_SET_VIDEO_CONFIG          = 5478,             /* set video recording configuration    */
    IOP_VIDEO_SET_STILL_CONFIG          = 5479,             /* set still capture configuration      */
    IOP_VIDEO_ACCESS_OTHER_UNIT_ID_DATA = 5480,             /* Access including SB/ICB unit id from NV/BIOS */
    IOP_VIDEO_DIVE_CASE_DETECT_DATA     = 5481,             /* Report diving case status            */
    IOP_VIDEO_HDMI_CABLE_DETECT_DATA    = 5482,             /* Report HDMI cable detect status      */
    IOP_VIDEO_SET_EXT_RTC_ALARM         = 5483,             /* Set Ext RTC Alarm                    */
    IOP_VIDEO_BIOS_OPERATION            = 5484,             /* Handle some BIOS operation           */
    IOP_VIDEO_TV_OUT_OPERATION          = 5485,             /* set TV out format                    */
    IOP_VIDEO_GPS_SNR_LOG_OPERATION     = 5486,             /* GPS SNR logging operation            */
    IOP_VIDEO_GPS_SNR_LOG_STATUS        = 5487,             /* Report state of GPS SNR logging      */
    IOP_VIDEO_GPS_SNR_LOG_DATA          = 5488,             /* Report GPS SNR logging result        */
    IOP_VIDEO_SET_ICB_HW_VER            = 5489,             /* Set ICB HW version to EEPROM         */
    IOP_VIDEO_SET_IOB_HW_VER            = 5490,             /* Set IOB HW version to EEPROM         */
    IOP_VIDEO_FORCE_FLUSH               = 5491,             /* flush data back to disk              */
    IOP_VIDEO_LENS_DETECT_DATA          = 5492,             /* Report lens status                   */

    IOP_VIDEO_LAST_ID                   = 5549,

    /*------------------------------------------------------
     WiFi Alliance Certification tests
    ------------------------------------------------------*/
    IOP_WIFI_ALLIANCE_SERIAL_PRINT_INIT = 5550,
    IOP_WIFI_ALLIANCE_SERIAL_PRINT_DATA = 5551,
    IOP_WIFI_ALLIANCE_MSG               = 5560,
    IOP_WIFI_ALLIANCE_REQ               = 5561,
    IOP_WIFI_ALLIANCE_RSP               = 5562,
    IOP_WIFI_ALLIANCE_LAST_ID           = 5569,

    /*------------------------------------------------------
    Erase contents of an SD/MMC
    ------------------------------------------------------*/
    IOP_ERASE_SDMMC                     = 5570,

    /*------------------------------------------------------
    Camera flash control ID
    ------------------------------------------------------*/
    IOP_CAMERA_FLASH_CONFIG             = 5571,

    /*------------------------------------------------------
    Set VIM factory standby time
    ------------------------------------------------------*/
    IOP_SET_VIM_FACTORY_STANDBY_TIME_MS = 5572,

    /*------------------------------------------------------
    Bluetooth file xfer support
    ------------------------------------------------------*/
    IOP_BT_FILE_XFER_SUPPORT            = 5573,

    /*------------------------------------------------------
    Dog status support
    ------------------------------------------------------*/
    IOP_DOG_STATUS_START                = 5574,
    IOP_DOG_BARK_SAMPLE_DATA            = 5574,
    IOP_DOG_BARK_PROCESSED_DATA         = 5575,
    IOP_DOG_BARK_STATUS                 = 5576,
    IOP_DOG_TILT_SAMPLE_DATA            = 5577,
    IOP_DOG_TILT_STATUS                 = 5578,
    IOP_DOG_TYPE                        = 5579,
    IOP_DOG_BARK_SIGNAL_SOURCE          = 5580,            /* enables acc or mic base bark signal (US VS EU) */
    IOP_DOG_BARK_DETECT_ENABLE          = 5581,            /* enables/disables* bark detection independent of tracking mode */
    IOP_DOG_BARK_PARAMETER              = 5582,            /* set, get or return specific bark related data (Bark count, Bark profile,...) */
    IOP_DOG_DEVICE_PREPAIR              = 5583,
    IOP_DOG_STATUS_LAST_ID              = 5584,

    /*------------------------------------------------------
    Locked block tests
    ------------------------------------------------------*/
    IOP_LOCK_BLK_TST_START              = 5585,
    IOP_LOCK_BLK_TST_INFO               = 5586,
    IOP_LOCK_BLK_TST_PRGRSS             = 5587,
    IOP_LOCK_BLK_TST_END                = 5588,
    IOP_LOCK_BLK_TST_FAILED             = 5589,

    /*------------------------------------------------------
    Named Function
    ------------------------------------------------------*/
    IOP_NAMED_FUNC_ID                   = 5590,

    /*------------------------------------------------------
    Auto test mode status
    ------------------------------------------------------*/
    IOP_AUTO_TEST_MODE_STAT_DATA        = 5591,

    /*------------------------------------------------------
    Enable/Disable HWM IOP debugging for various items
    ------------------------------------------------------*/
    IOP_HWM_DEBUG_ENABLE                = 5592,

    /*------------------------------------------------------
    Clear EVL Logs
    ------------------------------------------------------*/
    IOP_EVL_LOG_CLEAR                   = 5593,             /* Clear all EVL logs including archives    */
    IOP_EVL_CLEAR                       = 5594,             /* Clear a single owner's EVL log and it's archives */

    /*------------------------------------------------------
    Extended Android platform Instrumentation IDs (AOEM)
    ------------------------------------------------------*/
    IOP_FIRST_ANDROID_EXT_ID            = 5595,

    IOP_BOOT_COMPLETE_CHECK             = 5596,
    IOP_UV_CALI_DATA                    = 5597,
    IOP_QUICKBOOT_PWROFF_TIME           = 5598,
    IOP_PB_IN                           = 5599,
    IOP_CAN_UC_RESET                    = 5600,
    IOP_CAMERA_FOCUS_AREA               = 5601,    /* Control Android Camera for focusing area config */
    IOP_ALL_CHIPS_TEMP                  = 5602,
    IOP_VIDEO_HDMI_READ_EDID            = 5603,
    IOP_VIDEO_HDMI_WRITE_EDID           = 5604,
    IOP_TONE_TTS_DATA                   = 5605,
    IOP_DUAL_DISPLAY_ENABLE             = 5606,
    IOP_USBOTG_PWR_ENABLE               = 5607,
    IOP_ANA_DIGITAL_MIC_SWITCH          = 5608,
    IOP_CTP_I2C_SWITCH                  = 5609,
    IOP_VIM_UART_TEST                   = 5610,
    IOP_VIM_INTERRUPT_V33               = 5611,
    IOP_MHL_DATA                        = 5612,
    IOP_USBOTG_OVERCURRENT              = 5613,
    IOP_REBOOT_INT                      = 5614,
    IOP_SERDES_LINK_TEST                = 5615,
    IOP_TW8836_VIDEO_SWITCH             = 5616,
    IOP_CAM_WIFI_SSID                   = 5617,    /* Send WiFi CAM SSID                              */
    IOP_CAM_WIFI_PWD                    = 5618,    /* Send WiFi CAM PWD                               */
    IOP_CAM_WIFI_GET_PIC                = 5619,    /* Ask PND to get screen of WiFi CAM               */
    IOP_CAM_WIFI_PIC_DATA               = 5620,    /* Send the screen captured of WiFi CAM to Host    */
    IOP_SERDES_PWR_EN                   = 5621,
    IOP_IR_OUTPUT_EN                    = 5622,
    IOP_LAUNCH_HDMIAPP                  = 5623,
    IOP_TW8836_ADC_VAL                  = 5624,
    IOP_TW8836_OSD_CHECKSUM             = 5625,
    IOP_AUDIO_I2S_SWITCH                = 5626,
    IOP_AUDIO_RSE_SWITCH                = 5627,
    IOP_UART_DA_EN                      = 5628,
    IOP_UART_ACC_EN                     = 5629,
    IOP_DVD_UART_TEST                   = 5630,
    IOP_HUD_UART_TEST                   = 5631,
    IOP_DTV_DETECT                      = 5632,
    IOP_I2S_LX_EN                       = 5633,
    IOP_AUTO_BURN_IN                    = 5634,
    IOP_TPMS_DETECT                     = 5635,
    IOP_AUDIO_ANA_SWITCH                = 5636,    /* Analog audio output switch */
    IOP_BOARD_REV_DATA                  = 5637,
    IOP_BOARD_TYPE_DATA                 = 5638,
    IOP_ADC_CHANNEL_DATA                = 5639,
    IOP_EXT_DVD_MUTE                    = 5640,
    IOP_GYRO_PWR_EN                     = 5641,
    IOP_SPEED_REVERSE_LINE_STATUS       = 5642,
    IOP_ANDROID_CAM_SET_SHUTTER         = 5643,
    IOP_ANDROID_CAM_GET_TEMP            = 5644,
    IOP_ANDROID_BT_RF_TEST              = 5645,
    IOP_ANDROID_BLE_RF_TEST             = 5646,
    IOP_ANDROID_WIFI_MCS                = 5647,
    IOP_ANDROID_WIFI_CW                 = 5648,
    IOP_ANDROID_BLE_SEARCH              = 5649,
    IOP_GYRO_UPLOAD_CAL                 = 5650,
    IOP_ANDROID_CAM_PWR                 = 5651,
    IOP_ANDROID_BT_RX_TEST              = 5652,
    IOP_CARPLAY_SUPPORT                 = 5653,
    IOP_ANDROID_DASHCAM_TEST            = 5654,
    IOP_HDTVI_OUT_PWREN                 = 5655,
    IOP_MUX_ADC                         = 5656,
    IOP_USB_REDRIVER_RST                = 5657,
    IOP_2ND_USB_TEST                    = 5658,
    IOP_HUB_RST                         = 5659,
    IOP_CHIP_TST                        = 5660,
    IOP_HDCP_DOWNLOAD_REQUEST           = 5661,    /* Ask host to send the HDCP key to device                */
    IOP_HDCP_DOWNLOAD_REPLY             = 5662,    /* Return the result code of HDCP key installation        */
    IOP_NETWORK_STATUS                  = 5663,    /* Check the network is connected                         */
    IOP_CONTROL_MOBILE_DATA_SWITCH      = 5664,    /* Turn on/off mobile data                                */
    IOP_WIFI_PAIRED_SSID_NAME           = 5665,    /* Return current connected Wi-Fi SSID name               */
    IOP_BT_PAIRED_DEVICE_NAME           = 5666,    /* Return current paired BT device name                   */
    IOP_DISABLE_PRE_CACHE               = 5667,    /* Turn on/off pre-cache pages loading while booting      */
    IOP_ANDROID_AUTOMATION_TST          = 5668,    /* Simulate users’ touch event for automation testing     */
    IOP_IOP_ACC_UPLOAD_CAL              = 5669,    /* Upload the acc calibration data                        */
    IOP_MOBILE_COMMUNICATION_TEST       = 5670,    /* Mobile device communication test                       */

    IOP_TEST_MODE_SWITCH_PAGE           = 5683,
    IOP_TEST_MODE_BLACK_PATTERN         = 5684,
    IOP_ANDROID_FDR_DEL_FILE            = 5685,
    IOP_ANDROID_FDR_CHK_FILE            = 5686,
    IOP_AUIDO_SW_MIXER_SET_VOLUME       = 5687,
    IOP_TEST_MODE_COLOR_PATTERN         = 5688,
    IOP_MTKLOGGER_CTRL                  = 5689,

    IOP_LAST_ANDROID_EXT_ID             = 5690,

    /*------------------------------------------------------
    Garmin Helm Inst IDs
    ------------------------------------------------------*/
    IOP_HLM_CONNECT_REQUEST             = 5700,
    IOP_HLM_CONNECT_REPLY               = 5701,
    IOP_HLM_DISCONNECT_REQUEST          = 5702,
    IOP_HLM_DISCONNECT_REPLY            = 5703,
    IOP_HLM_TRANSFER_DATA_REQUEST       = 5704,
    IOP_HLM_TRANSFER_DATA               = 5705,
    IOP_HLM_TRANSFER_ACK                = 5706,
    IOP_HLM_TRANSFER_ERROR              = 5707,
    IOP_HLM_TOUCH_INPUT                 = 5708,
    IOP_HLM_KEY_INPUT                   = 5709,
    IOP_HLM_END                         = 5749,

    /*------------------------------------------------------
    Camera status feedback
    ------------------------------------------------------*/
    IOP_CAMERA2_START                   = 5750,
    IOP_CAMERA2_FOCUS_POSITION          = 5750,
    IOP_CAMERA2_FOCUS_FAULT_STATUS      = 5751,
    IOP_CAMERA2_END                     = 5799,

    /*------------------------------------------------------
    Product name data
    ------------------------------------------------------*/
    IOP_PRD_NAME_SET                    = 5800,

    /*------------------------------------------------------
    RTC Enable Square Wave Output
    ------------------------------------------------------*/
    IOP_RTC_SQUARE_WAVE_ENABLE          = 5801,
    IOP_RTC_SQUARE_WAVE_DISABLE         = 5802,

    /*------------------------------------------------------
    Sample ambient light data (in lux). The lower 2 bits of
    the payload data configure the mode (0: Off, 1: Single Shot,
    2: Continuous, 3: Reserved), and the other 30 bits are used
    for the sample data, depending on the mode selected.

    If Single Shot mode, the 30 bits are the number of samples
    to make for an average. If Continuous mode, the 30 bits
    are used to configure the sample rate (in milliseconds).
    ------------------------------------------------------*/
    IOP_SAMPLE_AMBIENT_LUX_DATA         = 5805,

    /*------------------------------------------------------
    Barometer local pressure offest
    ------------------------------------------------------*/
    IOP_BARO_LOCAL_PRESSURE_DATA        = 5806,

    /*------------------------------------------------------
    Wireless Sensor Connection Manager Connectivity Testing
    ------------------------------------------------------*/
    IOP_WSCM_CONN_TEST                  = 5809,

    /*------------------------------------------------------
    Start of processed ANT data
    ------------------------------------------------------*/
    IOP_ANT_START                       = 5810,

    /*------------------------------------------------------
    ANT host to client
    ------------------------------------------------------*/
    IOP_ANT_SNSR_CONFIG                 = 5810,
    IOP_ANT_SNSR_ENABLE                 = 5811,
    IOP_ANT_SNSR_DISABLE                = 5812,
    IOP_ANT_SNSR_SEARCH                 = 5813,
    IOP_ANT_SNSR_SEARCH_STOP            = 5814,

    /*------------------------------------------------------
    ANT client to host
    ------------------------------------------------------*/
    IOP_ANT_SNSR_FOUND                  = 5830,
    IOP_ANT_SNSR_DATA                   = 5831,

    /*------------------------------------------------------
    Used for Transmission of data for an ant-network-service
    ------------------------------------------------------*/
    IOP_ANS_IN                          = 5832,
    IOP_ANS_OUT                         = 5833,
    IOP_ANS_SYSTEM_READY                = 5834,

    /*------------------------------------------------------
    ANT Hot Zone Factory Test
    ------------------------------------------------------*/
    IOP_ANT_HOT_ZONE_TEST_REQUEST       = 5835,
    IOP_ANT_HOT_ZONE_TEST_RESPONSE      = 5836,

    /*------------------------------------------------------
    Enable/Disable overwrite of HR broadcast data
    ------------------------------------------------------*/
    IOP_ANT_HR_BROADCAST_OVERWRITE_CONTROL = 5837,

    IOP_ANT_END                         = 5849,

    /*------------------------------------------------------
    Touchscreen window index
    ------------------------------------------------------*/
    IOP_TSC_WDW_INDEX                   = 5850,

    /*------------------------------------------------------
    Passthrough protocol used to forward IOP data from other
    IOP pipes. (See AOEM Test Manager docs)
    ------------------------------------------------------*/
    IOP_BRIDGE_ID                       = 5851,

    /*------------------------------------------------------
    MAC module testing IDs
    ------------------------------------------------------*/
    IOP_MAC_TEST_START                  = 5852,
    IOP_MAC_TEST_RESULT                 = 5853,

    /*------------------------------------------------------
    SPI read/write/exchange protocol.
    ------------------------------------------------------*/
    IOP_SPI_CMD                         = 5854,

    /*------------------------------------------------------
    Used to adjust the ambient light sensor gain factor to
    an expected ambient light lux value (passed in as a uint16)
    ------------------------------------------------------*/
    IOP_ADJ_AMB_LGHT_GAIN_FACTOR        = 5855,
    IOP_ADJ_AMB_LGHT_GAIN_FACTOR_STATUS = 5856,

    /*------------------------------------------------------
    EVL log data requesting
    Most IDs should receive the EVL log # as a parameter
    ------------------------------------------------------*/
    IOP_EVL_LOG_CONTAINS_ERRORS         = 5857,
    IOP_EVL_LOG_ERROR_DATA              = 5858,
    IOP_EVL_END                         = 5866,

    /*------------------------------------------------------
    RGB Video test results
    ------------------------------------------------------*/
    IOP_RGB_VIDEO_TEST_DATA             = 5867,

    /*----------------------------------------------------------
    Vibration Motor IDs
    ----------------------------------------------------------*/
    IOP_VIB_MOTOR_CALIBRATION_RESULT    = 5868,
    IOP_VIB_MOTOR_RESONANT_FREQ         = 5869,

    /*------------------------------------------------------
    Nordic nrfF51 specific IOP
    ------------------------------------------------------*/
    IOP_NRF51_START                     = 5870,

    IOP_NRF51_ERROR_DATA                = 5870,

    IOP_NRF51_END                       = 5879,

    /*------------------------------------------------------
    activity-monitoring submodule
    ------------------------------------------------------*/
    IOP_ACT_MON_START                   = 5880,

    IOP_ACT_MON_RMT_WRIST_DATA          = 5880,
    IOP_ACT_MON_RMT_ACCEL_DATA          = 5881,
    IOP_ACT_MON_RMT_HR_DATA             = 5882,
    IOP_ACT_MON_RMT_HR_MIN_DATA         = 5883,
    IOP_ACT_MON_RMT_USER_STATE_DATA     = 5884,
    IOP_ACT_MON_HOST_TIME_DATA          = 5885,
    IOP_ACT_MON_RMT_FLOOR_DATA          = 5886,
    IOP_ACT_MON_RMT_HUMAN_AAD_DATA      = 5887,
    IOP_ACT_MON_HOST_IM_THRESHOLD_DATA  = 5888,
    IOP_ACT_MON_RMT_AAD_ACTIVITY_CHANGE = 5889,
    IOP_ACT_MON_RMT_AAD_FEATURE_DATA    = 5890,
    IOP_ACT_MON_HOST_FLOOR_DATA         = 5891,
    IOP_ACT_MON_RMT_AAD_SWIMRUN_DATA    = 5892,
    IOP_ACT_MON_RMT_FALL_RESULT_DATA    = 5893,
    IOP_ACT_MON_HOST_FALL_DTCT_ENABLE   = 5894,
    IOP_ACT_MON_HOST_FALL_SENS_DATA     = 5895,
    IOP_ACT_MON_HOST_FALL_LOG_ENABLE    = 5896,
    IOP_ACT_MON_RMT_FALL_RAW_DATA       = 5897,
    IOP_ACT_MON_RMT_FALL_INTERNAL_DATA  = 5898,

    IOP_ACT_MON_END                     = 5899,

    /*------------------------------------------------------
    Start/stop Line-in stream
    ------------------------------------------------------*/
    IOP_LINE_IN_ENABLE                  = 5900,

    /*------------------------------------------------------
    Request and result of basemap checksums for each map
    ------------------------------------------------------*/
    IOP_EACH_BMAP_CHECKSUM              = 5901,
    IOP_EACH_BMAP_CHECKSUM_RSLT         = 5902,

    /*------------------------------------------------------
    Garmin Marine Autopilot 5

        NOTE: This is the fifth set of Inst IDs for the Autopilot.

              Set 1 starts at 1240.
              Set 2 starts at 1300.
              Set 3 starts at 1683.
              Set 4 starts at 1881
              Set 5 starts at 5903
    ------------------------------------------------------*/
    IOP_MRN_SNSR_AUP_5_BEGIN            = 5903,  /* Marker only                                                                         */

    IOP_MRN_SNSR_AUP_CAPABILITY_FLAGS   = 5903,  /* Capability flags (support features and mode flags)                                  */
    IOP_MRN_SNSR_AUP_COMM_INTF_2_MSG    = 5904,  /* Message being sent using the Autopilot's second-generation communication interface  */
    IOP_MRN_SNSR_ATTITUDE_2             = 5905,  /* INST for sending large attitude messages */
    IOP_MRN_SNSR_AUP_COMM_INTF_3_MSG    = 5906,  /* Simplified autopilot protocol, based on IOP_MRN_SNSR_AUP_COMM_INTF_2_MSG */
    IOP_MRN_SNSR_AUP_THROTTLE_CMD       = 5907,  /* Throttle command messages                                                           */
    IOP_MRN_SNSR_ENGINE_RPM             = 5908,  /* Engine RPM data */

    IOP_MRN_SNSR_AUP_5_END              = 5923,  /* Marker only                                                                         */

    /*------------------------------------------------------
    In-circuit programming status
    ------------------------------------------------------*/
    IOP_ICP_STATUS                      = 5924,

    /*------------------------------------------------------
    Turn-signal Lever Sensor(TLS) support
    ------------------------------------------------------*/
    IOP_TLS_START                       = 5925,

    IOP_TLS_GET_DEVICE_STATUS           = 5926,
    IOP_TLS_DEVICE_STAUTS_RETURN        = 5927,
    IOP_TLS_SET_DEVICE_ID               = 5928,
    IOP_TLS_SET_PRIOR_DEVICE_ID         = 5929,
    IOP_TLS_POWER_MANGEMENT             = 5930,
    IOP_TLS_LR_CONTROL                  = 5931,
    IOP_TLS_ANT_EXISTENCE               = 5932,
    IOP_TLS_BATTERY_STATUS              = 5933,
    IOP_TLS_GDR_STATUS                  = 5934,

    IOP_TLS_END                         = 5939,

    /*------------------------------------------------------
    Microphone logging (stereo data format)
    ------------------------------------------------------*/
    IOP_MIC_LOG_STEREO_DATA             = 5940,

    /*------------------------------------------------------
    Garmin Marine Weather Service ID group.
    ------------------------------------------------------*/
    IOP_GMW_WX_PRDCT_LIST               = 5941,
    IOP_GMW_WX_PARAM_RQST               = 5942,
    IOP_GMW_WX_PARAM_DATA               = 5943,
    IOP_GMW_WX_RAW_DATA                 = 5944,
    IOP_GMW_WX_TRANSFER_ACK             = 5945,
    IOP_GMW_CONNECT_RQST                = 5946,
    IOP_GMW_CONNECT_REPLY               = 5947,
    IOP_GMW_DISCONNECT_RQST             = 5948,
    IOP_GMW_DISCONNECT_REPLY            = 5949,
    IOP_GMW_CONNECT_STATUS              = 5950,

    /*------------------------------------------------------
    Setup the vibrator PWM duty cycle
    ------------------------------------------------------*/
    IOP_SET_VIBE_DUTY                   = 5951,

    /*------------------------------------------------------
    Translate IOP command to Dbus command
    ------------------------------------------------------*/
    IOP_DBUS_ID                         = 5952,

    /*------------------------------------------------------
    Reply to IOP_QUERY_CONTROL_TEXT or IOP_QUERY_SCREEN_TEXT
    requests for Automatic Testing. 3993
    ------------------------------------------------------*/
    IOP_QUERY_TEXT_REPLY                = 5953,

    /*------------------------------------------------------
    Return byte status indicating a test file exists 1,
    or doesn't exist 0.
    ------------------------------------------------------*/
    IOP_TEST_MODE_FILE_STATUS           = 5954,

    /*------------------------------------------------------
    Marine GNX Display Communication IDs
    ------------------------------------------------------*/
    IOP_MRN_GNX_DISCOVER_MODE           = 5955,
    IOP_MRN_GNX_DICOVERY_FINISHED       = 5956,
    IOP_MRN_GNX_SELECTED_ORDER          = 5957,
    IOP_MRN_GNX_SELECTION_FINISHED      = 5958,
    IOP_MRN_GNX_SELECTION_ABORT         = 5959,
    IOP_MRN_GNX_DISPLAY_SELECT_ACK      = 5960,
    IOP_MRN_GNX_CHANGE_PAGE             = 5961,
    IOP_MRN_GNX_CAP_TOUCH_CONFIG        = 5962,

    /*------------------------------------------------------
    GPS Remote Chipset Power Mode
    ------------------------------------------------------*/
    IOP_GPS_RMT_PWR_MODE                = 5963,

    /*------------------------------------------------------
    Extended Connection Control Service Packets
    ------------------------------------------------------*/
    IOP_NET_CCS_EXT_CHILDREN_INFO_RQST  = 5964,     /* Children information request */
    IOP_NET_CCS_EXT_CHILDREN_INFO       = 5965,     /* Children information         */

    IOP_NET_CCS_EXT_END                 = 5990,

    /*------------------------------------------------------
    Remote Ambarella A7L Processor IDs
    ------------------------------------------------------*/
    IOP_A7L_REMOTE_FW_UPDATE            = 5991,
    IOP_A7L_REMOTE_FW_UPDATE_RSLT       = 5992,
    IOP_A7L_REMOTE_GET_POWER_STATE      = 5993,
    IOP_A7L_REMOTE_GET_POWER_STATE_RSLT = 5994,
    IOP_A7L_REMOTE_SET_POWER_STATE      = 5995,
    IOP_A7L_REMOTE_GET_VERSION          = 5996,
    IOP_A7L_REMOTE_GET_VERSION_RSLT     = 5997,
    IOP_A7L_REMOTE_SELF_TEST            = 5998,
    IOP_A7L_REMOTE_SELF_TEST_RSLT       = 5999,
    IOP_A7L_REMOTE_AUDIO_INTF           = 6000,
    IOP_A7L_REMOTE_AUDIO_INTF_RSLT      = 6001,
    IOP_A7L_REMOTE_LAST_PHOTO_DATA      = 6002,
    IOP_A7L_REMOTE_LAST_PHOTO_DATA_END  = 6003,
    IOP_A7L_REMOTE_CAUSE_CRASH          = 6004,
    IOP_A7L_REMOTE_FORMAT_CARD          = 6005,
    IOP_A7L_REMOTE_FORMAT_CARD_RSLT     = 6006,
    IOP_A7L_REMOTE_ENABLE_NAND          = 6007,

    IOP_A7L_REMOTE_LAST_ID              = 6019,

    /*------------------------------------------------------
    Marine GNX Display Preset Comm. IDs
    ------------------------------------------------------*/
    IOP_MRN_GNX_PRESET_SELECT           = 6020,
    IOP_MRN_GNX_PRESET_CHANGE           = 6021,

    /*------------------------------------------------------
    Fusion (Marine) Test IDs
    ------------------------------------------------------*/
    IOP_FUSION_TEST_REQUEST             = 6022,
    IOP_FUSION_TEST_REPLY               = 6023,

    IOP_FUSION_LAST_ID                  = 6031,

    /*------------------------------------------------------
    Sensor Quality Test IDs
    ------------------------------------------------------*/
    IOP_SENSOR_START_QUAL_TEST          = 6032,
    IOP_SENSOR_QUAL_TEST_RSLT           = 6033,

    /*------------------------------------------------------
    3-axis Gyro Cal IDs
    ------------------------------------------------------*/
    IOP_3AXIS_GYRO_CAL_DATA             = 6034,
    IOP_3AXIS_GYRO_CLEAR_CAL_PT         = 6035,
    IOP_3AXIS_GYRO_ADD_CAL_OFST         = 6036,

    /*------------------------------------------------------
    USB Mux test IDs
    ------------------------------------------------------*/
    IOP_USB_MUX_STATUS                  = 6037,

    /*------------------------------------------------------
    TT series specific instrument IDs
    ------------------------------------------------------*/
    IOP_TT_INST_BEGIN                   = 6038,             /* Marker only */
    IOP_TT_CHECK_PPS_WORKING            = 6038,             /* factory test to verify PPS is outputing*/
    IOP_TT_MURS_XTAL_OUTPUT             = 6039,             /* output the clock of Si4461 */
    IOP_TT_ALLOW_MASS_STORAGE_MODE      = 6040,             /* factory test to indicate the unit is allow to enter mass storage or not */
    IOP_TT_USER_STIM                    = 6041,             /* IOP to perfom user case stimulation */
    IOP_TT_INST_END                     = 6041,             /* Marker only */

    /*------------------------------------------------------
    LED Test IDs
    ------------------------------------------------------*/
    IOP_LED_TEST_CTRL                   = 6042,
    IOP_LED_TEST_STATUS                 = 6043,

    /*------------------------------------------------------
    PC Instrumentation Data Marine
    ------------------------------------------------------*/
    IOP_MRN_PC_DATA                     = 6044,

    /*------------------------------------------------------
    Get/Set image sensor board ID
    ------------------------------------------------------*/
    IOP_SET_IMG_SENSOR_ID               = 6045,
    IOP_GET_IMG_SENSOR_ID               = 6046,
    IOP_IMG_SENSOR_ID_DATA              = 6047,

    IOP_PANEL_SORTING_RESULT            = 6048,

    /*------------------------------------------------------
    General Audio IDs
    ------------------------------------------------------*/
    IOP_AUDIO_LINEIN_LOG                = 6049,
    IOP_MIC_TEST_START                  = 6050,
    IOP_MIC_TEST_STOP                   = 6051,
    IOP_MIC_TEST_FILE_START             = 6052,

    IOP_AUDIO_GENERAL_LAST_ID           = 6060,

    /*------------------------------------------------------
    Optical Heart Rate Module Instrumentation IDs - Block 1
    (Block 2 starts at INST ID 6335)
    ------------------------------------------------------*/
    IOP_OHR_INST_START                  = 6061,

    IOP_OHR_HR                          = 6061,
    IOP_OHR_VER                         = 6062,
    IOP_OHR_MODE                        = 6063,
    IOP_OHR_SET_RESTRICTION             = 6064,
    IOP_OHR_RESTRICTION_DATA            = 6065,
    IOP_OHR_REQUEST_PPG_DATA            = 6066,
    IOP_OHR_PPG_DATA                    = 6067,
    IOP_OHR_SET_LED_CURRENT             = 6068,
    IOP_OHR_SET_LED_CURRENT_CC_MODE     = 6069,
    IOP_OHR_BIST_RESULT                 = 6070, /* Result from "IOP_OHR_BIST" command. Type is defined as "HWM_whr_bist_result_t8" */

    IOP_OHR_INST_END                    = 6070,

    /*------------------------------------------------------
    Data is uint32 of millisecond delay. Device powers
    off after that much time after receiving this ID.
    ------------------------------------------------------*/
    IOP_DELAYED_POWER_OFF               = 6071,

    /*------------------------------------------------------
    Garmin Marine Weather Service ID group 2
    ------------------------------------------------------*/
    IOP_GMW_START                       = 6072,
    IOP_GMW_WX_PRDCT_LIST_ACK           = 6072,
    IOP_GMW_END                         = 6082,

    /*------------------------------------------------------
    Force a unit to remain in a specific power mode
    ------------------------------------------------------*/
    IOP_SET_PWR_MODE                    = 6083,

    /*------------------------------------------------------
    Partner/Feature commands
    ------------------------------------------------------*/
    IOP_PARTNER_START                   = 6090,
    IOP_PARTNER_SET_ID                  = 6091,
    IOP_PARTNER_SET_FEATURE_MASK        = 6092,
    IOP_PARTNER_GET_DETAILS             = 6093,
    IOP_PARTNER_END                     = 6099,

    /*------------------------------------------------------
    FITSDK MESG/DATA commands
    ------------------------------------------------------*/
    IOP_FITSDK_MESG_DATA                = 6100,

    /*------------------------------------------------------
    Automated Testing System (robots) commands
    ------------------------------------------------------*/
    IOP_ATS_START                       = 6110,
    IOP_ATS_PROPERTY_DATA               = 6111,
    IOP_ATS_PROPERTY_SET                = 6112,
    IOP_ATS_PROPERTY_GET                = 6113,
    IOP_ATS_ACTION_USER                 = 6114,
    IOP_ATS_ACTION_SYSTEM               = 6115,
    IOP_ATS_END                         = 6119,

    /*------------------------------------------------------
    Set Capacitive Touch Panel Sensitivity
    ------------------------------------------------------*/
    IOP_SET_CTP_SENSITIVITY             = 6120,

    /*------------------------------------------------------
    Accelerometer temperature calibration
    ------------------------------------------------------*/
    IOP_ACCEL_TEMP_CAL_DATA             = 6121,

    /*------------------------------------------------------
    Magnetometer cross axis correction check
    ------------------------------------------------------*/
    IOP_MAG_CROSS_AXIS_COEFF_CHECK      = 6122,

    /*------------------------------------------------------
    Heart rate monitor(ECG/EKG) analog front end verification
    ------------------------------------------------------*/
    IOP_HRM_AFE_INST_START              = 6123,

    IOP_HRM_AFE_PART_NUM                = 6123,

    /*------------------------------------------------------
    IOP_HRM_AFE_DATA packet format. Receivers must ignore
    fields following these for future compatibility. Older
    senders may send a shorter packet. All fields are
    stored in little-endian.

    struct
        {
        uint16  dc_bias;    //Average of ADC samples
        uint16  pk_to_pk;   //Maximum sample - minimum sample
        uint16  freq;       //Heartbeat frequency if detected, 0 otherwise
        uint16  min;        //Maximum ADC sample
        uint16  max;        //Minimum ADC sample
        } IOP_hrm_afe_data_type

    ------------------------------------------------------*/
    IOP_HRM_AFE_DATA                    = 6124,

    /*------------------------------------------------------
    IOP_HRM_DISCRETE_AFE_DATA packet format. Receivers must ignore
    fields following these for future compatibility. Older
    senders may send a shorter packet.

    struct
        {
        uint16  event_time;     //Event time of last beat
        uint8   beat_count;     //Beat count
        uint8   current_hr;     //Heartbeat frequency if detected, 0 otherwise
        } IOP_hrm_discrete_afe_data_type;

    ------------------------------------------------------*/
    IOP_HRM_DISCRETE_AFE_DATA           = 6125,

    IOP_HRM_AFE_INST_END                = 6129,

    /*------------------------------------------------------
    Temperature Bias Data
    ------------------------------------------------------*/
    IOP_SET_TEMP_BIAS                   = 6130,
    IOP_TEMP_BIAS_DATA                  = 6131,

    /*------------------------------------------------------
    Bike Lights INST IDs
    ------------------------------------------------------*/
    IOP_BL_INST_START                   = 6132,

    IOP_BL_SET_LED_MODE                 = 6132,     /* Sets the LED UI mode on the unit. The data, LED_MODE, is an enumeration. */
    IOP_BL_LED_MODE_DATA                = 6133,     /* The unit's response to report on the LED mode. */
    IOP_BL_SET_LED_LVL                  = 6134,     /* Set the brightness level of the LEDs. The data consists of the LED reference ID and brightness level (expressed in percentage). */
    IOP_BL_LED_LVL_DATA                 = 6135,     /* The unit's response to report on the current LED brightness level value. */
    IOP_BL_GET_CONFIG_INFO              = 6136,     /* Get the config info specified by an enumeration value. */
    IOP_BL_CONFIG_DATA                  = 6137,     /* Response to a request for config info specified by an enumeration value. */

    IOP_BL_LED_DRIVE_CAL_RUN            = 6138,     /*Run the LED Drive calibration at the given point */
    IOP_BL_LED_DRIVE_CAL_DATA           = 6139,     /*The LED Drive calibration data at the given point */

    IOP_BL_SET_LED_STATE                = 6140,     /* Sets the LED system state on the unit. */
    IOP_BL_LED_STATE_DATA               = 6141,     /* The unit's response to report on the system state. */

    IOP_BL_IAQ_DATA                     = 6142,     /* Accel sample from IAQ */

    IOP_BL_SET_SYS_STATE                = 6143,     /* Sets the system state on the unit. */
    IOP_BL_SYS_STATE_DATA               = 6144,     /* The unit's response to report on the system state. */

    IOP_BL_SET_SYS_FAULT                = 6145,     /* Sets the system fault state on the unit. */
    IOP_BL_SYS_FAULT_DATA               = 6146,     /* The unit's response to report on the system faults. */

    IOP_BL_SET_USER_CONFIG_FIELD        = 6147,
    IOP_BL_USER_CONFIG_DATA             = 6148,
    IOP_BL_GET_USER_CONFIG_FIELD        = 6149,

    IOP_BL_LED_INTENSITY_SCALE_FACTOR_DATA = 6150,

    IOP_BL_INST_END                     = 6231,

    /*------------------------------------------------------
    Dynastream INST IDs
    ------------------------------------------------------*/
    IOP_DYNASTREAM_INST_START           = 6232,

    IOP_CONFIG_BLOCK_DATA               = 6232,
    IOP_BIST_DATA                       = 6233,
    IOP_FIELD_DATA                      = 6234,
    IOP_RSSI_DATA                       = 6235,
    IOP_UNIT_ANT_ID_DATA                = 6236,

    IOP_DYNASTREAM_INST_END             = 6241,

    /*------------------------------------------------------
    3-axis Accel Cal IDs
    ------------------------------------------------------*/
    IOP_3AXIS_ACCEL_CAL_DATA            = 6242,
    IOP_3AXIS_ACCEL_CLEAR_CAL_PT        = 6243,
    IOP_3AXIS_ACCEL_ADD_CAL_OFST        = 6244,

    /*------------------------------------------------------
    Video Device Test Page IDs
    ------------------------------------------------------*/
    IOP_VIDEO_DEVICE_TEST_PAGE_SHOW     = 6245,
    IOP_VIDEO_DEVICE_TEST_PAGE_HIDE     = 6246,

    /*------------------------------------------------------
    Get current page that is in focus from CDP
    ------------------------------------------------------*/
    IOP_GET_CDP_FOCUS_PAGE              = 6247,
    IOP_CDP_FOCUS_PAGE_RETURN           = 6248,

    /*------------------------------------------------------
    Self Test Commands
    ------------------------------------------------------*/
    IOP_SELF_TEST_START                 = 6249,
    IOP_SELF_TEST_DONE                  = 6250,

    /*------------------------------------------------------
    J1939 Auto Turn On Status
    ------------------------------------------------------*/
    IOP_AUTO_ENABLE_J1939_STAT_DATA     = 6251,

    /*------------------------------------------------------
    Remote Processor Comms Inst IDs
    ------------------------------------------------------*/
    IOP_RMT_MCU_COMM_INST_START         = 6252,
    IOP_RMT_MCU_VRSN_INFO               = 6252,
    IOP_RMT_MCU_FULL_DSPL_UPDATE        = 6253,
    IOP_RMT_MCU_SET_DSPL_MODE           = 6254,
    IOP_RMT_MCU_SET_DSPL_PARAMS         = 6255,
    IOP_RMT_MCU_SENSOR_HUB_RQST         = 6256,
    IOP_RMT_MCU_SENSOR_HUB_DATA         = 6257,
    IOP_RMT_MCU_FULL_DSPL_UPDATE_PACKED = 6258,
    IOP_RMT_MCU_SET_COLOR_TABLE         = 6259,
    IOP_RMT_MCU_SHUTDOWN_INFO           = 6260,
    IOP_RMT_MCU_SET_REFRESH_RATE        = 6261,
    IOP_RMT_MCU_VRSN_COMMIT_INFO        = 6262,
    IOP_RMT_MCU_DSPL_BKGD_BUF           = 6263,
    IOP_RMT_MCU_PRTL_DSPL_UPDATE        = 6264,
    IOP_RMT_MCU_PRTL_DSPL_UPDATE_PACKED = 6265,
    IOP_RMT_MCU_MODE_INFO               = 6266,
    IOP_RMT_MCU_DEBUG_RQST              = 6267,
    IOP_RMT_MCU_DEBUG_DATA              = 6268,
    IOP_RMT_MCU_INIT_COMPONENT          = 6269,
    IOP_RMT_MCU_INIT_COMPONENT_ACK      = 6270,
    IOP_RMT_MCU_DIRTY_BUILD             = 6271,
    IOP_RMT_MCU_GPN                     = 6272,

    IOP_RMT_MCU_COMM_INST_END           = 6283,

    /*----------------------------------------------------------
    NOH ( Newly Overhauled ) Support
    ----------------------------------------------------------*/
    IOP_USED_UNIT_FLAG_DATA             = 6284,

    /*------------------------------------------------------
    Remote accelerometer
    ------------------------------------------------------*/
    IOP_REMOTE_ACCEL_START              = 6285,

    IOP_REMOTE_ACCEL_CONFIG             = 6285,
    IOP_REMOTE_ACCEL_ENABLE             = 6286,
    IOP_REMOTE_ACCEL_ALLOW_SLEEP_ENABLE = 6287,
    IOP_REMOTE_ACCEL_DATA               = 6288,
    IOP_REMOTE_ACCEL_SLEEPING           = 6289,
    IOP_REMOTE_ACCEL_STATIONARY         = 6290,
    IOP_REMOTE_ACCEL_MOVE_DETECT_ENABLE = 6291,
    IOP_REMOTE_ACCEL_SINGLE_TAP         = 6292,
    IOP_REMOTE_ACCEL_DOUBLE_TAP         = 6293,
    IOP_REMOTE_ACCEL_TAP_ENABLE         = 6294,
    IOP_REMOTE_ACCEL_TAP_THRESHOLD_SET  = 6295,
    IOP_REMOTE_ACCEL_DATA_MULTI         = 6296, /* Many sequentially placed IOP_REMOTE_ACCEL_DATA packets */

    IOP_REMOTE_ACCEL_END                = 6299,

    /*----------------------------------------------------------
    More Battery Related INST ID's - cont. from ID 900.
    ----------------------------------------------------------*/
    IOP_BATT_START                      = 6300,

    IOP_BATT_VOLTAGE_THRESHOLD          = 6300,  /* Battery voltage regulation threshold */

    IOP_BATT_SENSE_CAL_RUN              = 6301,  /* Run the battery sense circuit calibration process for the given point */
    IOP_BATT_SENSE_CAL_DATA             = 6302,  /* The battery sense circuit calibration data at the given point */

    IOP_BATT_END                        = 6319,

    /*------------------------------------------------------
    Remote magnetometer
    ------------------------------------------------------*/
    IOP_REMOTE_MAG_START                = 6320, /* Marker */

    IOP_REMOTE_MAG_CONFIG               = 6320,
    IOP_REMOTE_MAG_ENABLE               = 6321,
    IOP_REMOTE_MAG_DATA                 = 6322,
    IOP_REMOTE_MAG_RESTORE              = 6323,
    IOP_REMOTE_MAG_DATA_MULTI           = 6324, /* Many sequentially placed IOP_REMOTE_MAG_DATA packets */

    IOP_REMOTE_MAG_END                  = 6324, /* Marker */

    /*------------------------------------------------------
    TT mini specific instrument IDs
    ------------------------------------------------------*/
    IOP_MINI_INST_BEGIN                 = 6325,             /* Marker only */
    IOP_MINI_STOP_LED_INDICATION        = 6325,             /* Stop/Start LED indication for factory test */
    IOP_ASTRO_FT_RX_TEST                = 6326,             /* Turn on/off FT RX test, currently for Astro425 */
    IOP_MINI_INST_END                   = 6329,             /* Marker only */

    /*------------------------------------------------------
    Barometer Instructions
    ------------------------------------------------------*/
    IOP_BARO_INST_BEGIN                 = 6330,
    IOP_BARO_RUN_BIST                   = 6330, /* Run barometer basic in-system test on passed in number of samples (uint8) */
    IOP_BARO_BIST_RSLT                  = 6331, /* Result of barometer basic in-system test as defined in HWM_baro_bist_rslt */
    IOP_BARO_RQST_SAMPLE                = 6332, /* Request barometer sample(s) as defined in HWM_baro_rqst_t16               */
    IOP_BARO_INST_END                   = 6334,

    /*------------------------------------------------------
    Optical Heart Rate Module Instrumentation IDs - Block 2
    ------------------------------------------------------*/
    IOP_OHR_INST2_START                 = 6335,

    IOP_OHR_SET_AFE_GAIN                = 6335, /* Sets the gain for the AFE (expected value is an 8bit index of gains supported by AFE) */

    IOP_OHR_INST2_END                   = 6355,

    /*------------------------------------------------------
    Remote gesture processing
    ------------------------------------------------------*/
    IOP_REMOTE_GESTURE_SETTINGS         = 6356,
    IOP_REMOTE_GESTURE_STATE            = 6357,

    /*------------------------------------------------------
    Head Mounted Display INST IDs
    ------------------------------------------------------*/
    IOP_HMD_INST_START                  = 6360,

    IOP_HMD_ENABLE_TP_TEST              = 6360,
    IOP_HMD_TP_INTENSITY_DATA           = 6361,
    IOP_HMD_SET_BACKLIGHT_PWM           = 6362,
    IOP_HMD_PROBE_DISPLAY_CHIP          = 6363,
    IOP_HMD_PROBE_DISPLAY_RETURN        = 6364,
    IOP_HMD_PROBE_TP_FW_VERSION         = 6365,
    IOP_HMD_TP_FW_VERSION_RETURN        = 6366,
    IOP_HMD_GET_TP_TEST_COUNT           = 6367,
    IOP_HMD_TP_TEST_COUNT               = 6368,

    IOP_HMD_INST_END                    = 6369,

    /*-----------------------------------------------------
    WiFi Controls (continued)
    -----------------------------------------------------*/
    IOP_WIFI_CONNECT_NETWORK_VARLEN     = 6370,    /*Same as IOP_WIFI_CONNECT_NETWORK (1647), but using null term strings*/

    /*------------------------------------------------------
    Dog Training Instrumentation IDs
    ------------------------------------------------------*/
    IOP_DOG_TRAIN_START                 = 6371,

    IOP_DOG_TRAIN_RELEASE               = 6371,
    IOP_DOG_TRAIN_TUNE                  = 6372,

    IOP_DOG_TRAIN_END                   = 6384,

    /*------------------------------------------------------
    Marine Survey Instrumentation IDs
    ------------------------------------------------------*/
    IOP_MRN_SURVEY_START                = 6385,

    IOP_MRN_SURVEY_SYNC                 = 6385,
    IOP_MRN_SURVEY_IMPORT               = 6386,

    IOP_MRN_SURVEY_END                  = 6389,

    /*----------------------------------------------------------
    Ambient Light Sensor (ALS)
    ----------------------------------------------------------*/
    IOP_ALS_RAW_DATA                    = 6390,
    IOP_ALS_UV_DATA                     = 6391,

    /*----------------------------------------------------------
    Magnetometer Self-Test
    ----------------------------------------------------------*/
    IOP_MAG_DATA_SELF_TEST_RESULT       = 6392,

    /*------------------------------------------------------
    Sound Test Control
    ------------------------------------------------------*/
    IOP_SOUND_TEST_CTRL                 = 6393,

    /*------------------------------------------------------
    QIC1832 Group
    ------------------------------------------------------*/
    IOP_QIC1832_REMOTE_FW_UPDATE        = 6394,
    IOP_QIC1832_REMOTE_FW_VERSION       = 6395,
    IOP_QIC1832_RESET                   = 6396,

    IOP_QIC1832_REMOTE_LAST_ID          = 6397,

    /*----------------------------------------------------------
    Generic Touchscreen Controller Packet Piping
    ----------------------------------------------------------*/
    IOP_TSC_COMMAND                     = 6398,
    IOP_TSC_RESPONSE                    = 6399,

    /*------------------------------------------------------
    Radio BTF/ANT group
    ------------------------------------------------------*/
    IOP_RADIO_SET_BTF_ENABLE            = 6400,  //same functionality as IOP inst 363?
    IOP_RADIO_SET_ANT_ENABLE            = 6401,
    IOP_RADIO_BTF_STATE_CHG_CMPLT       = 6402,
    IOP_RADIO_ANT_STATE_CHG_CMPLT       = 6403,

    /*----------------------------------------------------------
    NOH ( Newly Overhauled ) Reply
    ----------------------------------------------------------*/
    IOP_USED_UNIT_FLAG_REPLY            = 6404,

    /*----------------------------------------------------------
    Ambient Light Sensor (ALS) (continued)
    ----------------------------------------------------------*/
    IOP_ALS_CAL_DATA                    = 6405,

    /*------------------------------------------------------
    GDR
    ------------------------------------------------------*/
    IOP_GDR_INST_START                  = 6406, /* marker */

    IOP_GDR_FORMAT_CARD                 = 6406,

    IOP_GDR_INST_END                    = 6410, /* marker */

    /*------------------------------------------------------
    NFC ESE ( Embedded Security Element )
    ------------------------------------------------------*/
    IOP_NFC_ESE_CMND                    = 6411,
    IOP_NFC_ESE_RESPONSE                = 6412,

    /*------------------------------------------------------
    GCD Software Update group
    ------------------------------------------------------*/
    IOP_GCD_UPDATE_START                = 6413,

    IOP_GCD_UPDATE_START_CMND           = 6414,
    IOP_GCD_UPDATE_GET_STATUS           = 6415,
    IOP_GCD_UPDATE_STATUS_DATA          = 6416,

    IOP_GCD_UPDATE_END                  = 6418,

    /*----------------------------------------------------------
    Micro Radar Instrumentation IDs
    ----------------------------------------------------------*/
    IOP_RADAR_INST_START                = 6419, /* marker */

    IOP_RADAR_GET_DAC_STRUCT            = 6419,
    IOP_RADAR_DAC_STRUCT                = 6420,
    IOP_RADAR_MODE_DATA                 = 6421,
    IOP_RADAR_POWER_DATA                = 6422,
    IOP_RADAR_CHANNEL_DATA              = 6423,
    IOP_RADAR_GET_WAVEFORM              = 6424,
    IOP_RADAR_WAVEFORM_DATA             = 6425,
    IOP_RADAR_RX_GAIN_DATA              = 6426,
    IOP_RADAR_OPAMP_GAIN_DATA           = 6427,
    IOP_RADAR_CALIB_STATUS_DATA         = 6428,
    IOP_RADAR_TARGET_DATA               = 6429,
    IOP_RADAR_TARGETS_SNR_DATA          = 6430,
    IOP_RADAR_SELF_TEST_RESULT          = 6431,
    IOP_RADAR_NUM_WAVEFORMS_DATA        = 6432,
    IOP_RADAR_INTRLV_CH_SET_DATA        = 6433,
    IOP_RADAR_TEMPERATURE_DATA          = 6434,
    IOP_RADAR_DUMP_MAP_REQ              = 6435,
    IOP_RADAR_DUMP_MAP_DATA             = 6436,
    IOP_RADAR_DAC_TEST_STRUCT           = 6437,
    IOP_RADAR_SET_MON_DBG_CH_VALUE      = 6438,

    IOP_RADAR_INST_END                  = 6439, /* marker */

    /*------------------------------------------------------
    IOP to Serial (GSP) Bridge IDs
    ------------------------------------------------------*/
    IOP_GSP_BRIDGE_START                = 6440,

    IOP_GSP_BRIDGE_MODE                 = 6440,
    IOP_GSP_BRIDGE_RSVD1                = 6441,
    IOP_GSP_BRIDGE_RSVD2                = 6442,
    IOP_GSP_BRIDGE_RSVD3                = 6443,
    IOP_GSP_BRIDGE_RSVD4                = 6444,
    IOP_GSP_BRIDGE_RSVD5                = 6445,
    IOP_GSP_BRIDGE_RSVD6                = 6446,
    IOP_GSP_BRIDGE_RSVD7                = 6447,
    IOP_GSP_BRIDGE_RSVD8                = 6448,
    IOP_GSP_BRIDGE_RSVD9                = 6449,

    IOP_GSP_BRIDGE_END                  = 6449,

    /*------------------------------------------------------
    Delta Contain and new dog products Instrumentation IDs
    ------------------------------------------------------*/
    IOP_CANINE_PRODUCTS_START           = 6450,

    IOP_PERFORM_FACTORY_RESET           = 6450,
    IOP_RETURN_PRODUCT_USAGE_HOURS      = 6451,
    IOP_MFG_QA_TEST_STATE               = 6452,

    IOP_CANINE_PRODUCTS_END             = 6469,

    /*------------------------------------------------------
    Cryptographically secure RNG seed.
    ------------------------------------------------------*/
    IOP_ENTROPY_SEED                    = 6470,

    /*------------------------------------------------------
    Marine System Wide Preferred Sources IDs
    ------------------------------------------------------*/
    IOP_MRN_SWPS_START                  = 6471,

    IOP_MRN_SWPS_ADVERT                 = 6471,
    IOP_MRN_SWPS_LEADER_NIDI            = 6472,
    IOP_MRN_SWPS_RESYNC                 = 6473,
    IOP_MRN_SWPS_NEXT_DEVICE_SYNC       = 6474,
    IOP_MRN_SWPS_PREF_SRC_REQUEST       = 6475,
    IOP_MRN_SWPS_PREF_SRC_RESPONSE      = 6476,
    IOP_MRN_SWPS_PREF_SRC_SET           = 6477,
    IOP_MRN_SWPS_ALIAS_REQUEST          = 6478,
    IOP_MRN_SWPS_ALIAS_RESPONSE         = 6479,
    IOP_MRN_SWPS_ALIAS_SET              = 6480,
    IOP_MRN_SWPS_BRIDGE_ADVERT          = 6481,
    IOP_MRN_SWPS_NIDI_RESOLUTION        = 6482,
    IOP_MRN_SWPS_PREF_SRC_ACK           = 6483,
    IOP_MRN_SWPS_ALIAS_ACK              = 6484,

    IOP_MRN_SWPS_END                    = 6489,

    /*------------------------------------------------------
    WHR Data (Optical Wrist Heart Rate)
    ------------------------------------------------------*/
    IOP_WHR_START                       = 6490, /* marker */

    IOP_WHR_IN_ID                       = 6491,
    IOP_WHR_OUT_ID                      = 6492,
    IOP_WHR_WRIST_DETECT_ENABLE_DISABLE = 6493,

    IOP_WHR_END                         = 6499, /* marker */

    /*------------------------------------------------------
    IAQ Data (Input Acquisition)
    ------------------------------------------------------*/
    IOP_IAQ_START                       = 6500, /* marker */

    IOP_IAQ_SENSOR_ID                   = 6500, /* All sensor data */
    IOP_IAQ_IN_ID                       = 6501,
    IOP_IAQ_OUT_ID                      = 6502,
    IOP_IAQ_COMPRESSED_ID               = 6503,
    IOP_IAQ_EVENT_ID                    = 6504,
    IOP_IAQ_ACCEL_ID                    = 6505, /* Accelerometer sensor, obsoleted by IOP_IAQ_SENSOR_ID */
    IOP_IAQ_MAG_ID                      = 6506, /* Magnetometer sensor, obsoleted by IOP_IAQ_SENSOR_ID */
    IOP_IAQ_GYRO_ID                     = 6507, /* Gyroscope sensor, obsoleted by IOP_IAQ_SENSOR_ID */
    IOP_IAQ_BARO_ID                     = 6508, /* Barometer sensor, obsoleted by IOP_IAQ_SENSOR_ID */
    IOP_IAQ_PPG_ID                      = 6509, /* Photoplethysmogram optical sensor, obsoleted by IOP_IAQ_SENSOR_ID */
    IOP_IAQ_STRAIN_ID                   = 6510, /* Strain gauge sensor, obsoleted by IOP_IAQ_SENSOR_ID  */
    IOP_IAQ_EXCITATION_ID               = 6511, /* Strain gauge excitation voltage, obsoleted by IOP_IAQ_SENSOR_ID */
    IOP_IAQ_TEMP_ID                     = 6512, /* Temperature, obsoleted by IOP_IAQ_SENSOR_ID */

    IOP_IAQ_END                         = 6519, /* marker */

    /*----------------------------------------------------------
    Radar Calibration Helper App Command IDs
    ----------------------------------------------------------*/
    IOP_RDR_CALIB_HELPER_INST_START     = 6520, /* Marker only */

    IOP_RDR_CALIB_HELPER_INIT           = 6520,
    IOP_RDR_CALIB_HELPER_STATUS         = 6521,
    IOP_RDR_CALIB_UPDATE                = 6522,
    IOP_RDR_CALIB_RESPONSE              = 6523,
    IOP_RDR_CALIB_CONF_UPDATE           = 6524,
    IOP_RDR_CALIB_CONF_RESPONSE         = 6525,
    IOP_RDR_CALIB_HELPER_ERR            = 6526,
    IOP_RDR_CALIB_HELPER_FREQ_DIV       = 6527,

    IOP_RDR_CALIB_HELPER_INST_END       = 6529, /* Marker only */

    /*------------------------------------------------------
    BNS Data (Bluetooth Low Energy Network Service)
    ------------------------------------------------------*/
    IOP_BNS_START                       = 6530, /* marker */

    IOP_BNS_CMD                         = 6530,
    IOP_BNS_CMD_RESP                    = 6531,
    IOP_BNS_EVT_GENERIC                 = 6532,
    IOP_BNS_EVT_SERVER                  = 6533,
    IOP_BNS_EVT_CLIENT                  = 6534,
    IOP_BNS_DEBUG_LOG                   = 6535,

    IOP_BNS_END                         = 6539, /* marker */

    /*----------------------------------------------------------
    Micro Radar Operational Messages
    ----------------------------------------------------------*/
    IOP_RADAR_OPER_INST_START           = 6540, /* marker */

    IOP_RADAR_ENABLED_DATA              = 6540,
    IOP_RADAR_CONFIG_DATA               = 6541,
    IOP_RADAR_HEALTH_DATA               = 6542,
    IOP_RADAR_TRACK_LIST                = 6543,
    IOP_RADAR_TRACK_LIST_TX_RATE        = 6544,
    IOP_RADAR_SHUTDOWN_RET              = 6545,
    IOP_RADAR_PLATFORM_SPEED            = 6546,
    IOP_RADAR_ENABLE_TELEMETRY          = 6547,
    IOP_RADAR_LOG                       = 6548,
    IOP_RADAR_LOG_LVL                   = 6549,
    IOP_RADAR_CAN_IOP_KEY               = 6550,
    IOP_RADAR_HW_ID                     = 6551,

    IOP_RADAR_OPER_INST_END             = 6559, /* marker */

    /*------------------------------------------------------
    Arduino Based Test Fixture Command ID group.
    ------------------------------------------------------*/
    IOP_ARDUINO_TEST_FIXTURE_START            = 6560,
    IOP_ARDUINO_TEST_FIXTURE_FOR_LIDAR_TX     = 6560,
    IOP_ARDUINO_TEST_FIXTURE_FOR_LIDAR_TR     = 6561,
    IOP_ARDUINO_TEST_FIXTURE_FOR_LIDAR_INFO   = 6562,
    IOP_ARDUINO_TEST_FIXTURE_END              = 6579,

    /*------------------------------------------------------
    Ant Common Battery Status
    ------------------------------------------------------*/
    IOP_ANT_COMMON_BATTERY_STATUS       = 6580,

    /*------------------------------------------------------
    Yamaha Software Update Information
    ------------------------------------------------------*/
    IOP_YAMAHA_SW_UPDATE_INFO           = 6581,

    /*------------------------------------------------------
    Extended ID
    ------------------------------------------------------*/
    IOP_EXTENDED_UNIT_ID_DATA           = 6582, /* Unit extended ID data. Use IOP_SET_EXTENDED_UNIT_ID for setting the extended ID */

    /*------------------------------------------------------
    Bootloader Setting ID's
    ------------------------------------------------------*/
    IOP_BOOTLOADER_MASTER_SEED          = 6583,
    IOP_BOOTLOADER_RESERVED_PAGES       = 6584,

    /*------------------------------------------------------
    Info Manager Settings ID's
    ------------------------------------------------------*/
    IOP_INFO_MANAGER_SET_LOCK_STATUS    = 6585, /* Set arbitrary locks (can't unlock, returns lock status) */
    IOP_INFO_MANAGER_LOCK_STATUS        = 6586, /* Return the status of the locks */

    /*------------------------------------------------------
    NET MAC ADDR ID's
    ------------------------------------------------------*/
    IOP_NET_SET_MAC_ADDR                = 6587,
    IOP_NET_MAC_ADDR_DATA               = 6588,

    /*------------------------------------------------------
    LNA gain config of RF chip
    ------------------------------------------------------*/
    IOP_RF_SET_LNA_CFG                  = 6589,
    IOP_RF_GET_LNA_CFG                  = 6590,

    /*---------------------------------------------------------------
    Photoplethysmogram (PPG) automatic gain control (AGC) state debug
    -----------------------------------------------------------------*/
    IOP_PPG_AGC_DRIVER_START            = 6591,
    IOP_PPG_AGC_DRIVER_CHANGE           = 6592,
    IOP_PPG_AGC_DRIVER_CHANGE_PPG_DC    = 6593,
    IOP_PPG_AGC_STATE_LOG_DEBUG         = 6594,
    IOP_PPG_AGC_DRIVER_END              = 6601,

    /*------------------------------------------------------
    UTC Time (Coordinated Universal Time)
    ------------------------------------------------------*/
    IOP_UTC_TIME_DATA                   = 6602, /* At time of message generation */

    /*------------------------------------------------------
    IOP Fit Logging
    ------------------------------------------------------*/
    IOP_IFL_INST_START                  = 6603, /* marker */

    IOP_IFL_START_FILE                  = 6603, /* Request to start specified file */
    IOP_IFL_END_FILE                    = 6604, /* Request to end specified file */
    IOP_IFL_FILE_OPENED                 = 6605, /* Notification of file being opened */
    IOP_IFL_DEBUG                       = 6606, /* Debug output of IFL */
    IOP_IFL_PAUSE_FILE                  = 6607, /* Request to pause logging to specified file */
    IOP_IFL_RESUME_FILE                 = 6608, /* Request to resume specified paused logging file */
    IOP_IFL_MARK_LAP                    = 6609, /* Request to mark a lap in the specified file */
    IOP_IFL_CLEAR_FILES                 = 6610, /* Request to clear out all of the log files */
    IOP_IFL_RESYNC                      = 6611, /* Request an IFL_resync() call */

    IOP_IFL_INST_END                    = 6613, /* marker */

    /*------------------------------------------------------
    Product data with a longer string (up to 120 char including NULL)
    ------------------------------------------------------*/
    IOP_EXTENDED_PRODUCT_DATA           = 6614,

    /*------------------------------------------------------
    General PMIC Data
    ------------------------------------------------------*/
    IOP_PMIC_INST_START                 = 6615, /* marker */
    IOP_PMIC_CHRG_STATE_DATA            = 6615, /* Charger state data from the PMIC */
    IOP_PMIC_OTP_CHECK_RESULT           = 6616, /* Result of PMIC's One-Time Programmable Settings Check */
    IOP_PMIC_THERMISTOR_FAULT_STATE     = 6617, /* Reports PMIC thermistor fault state (i.e. none, cold, hot, etc.) */
    IOP_PMIC_REPROGRAM_RESULT           = 6618, /* Status result of IOP PMIC Reprogram function */
    IOP_PMIC_THRM_STATUS_DATA           = 6619, /* Thermal status from the PMIC */
    IOP_PMIC_INST_END                   = 6630, /* marker */

    /*------------------------------------------------------
    Photoplethysmogram (PPG) Phase Stepper Markers
    ------------------------------------------------------*/
    IOP_PPG_PHASE_STEPPER_MARKER        = 6631,

    /*----------------------------------------------------------
    Vector Operational Messages
    ----------------------------------------------------------*/
    IOP_VECTOR_OPER_INST_START          = 6632, /* marker */

    IOP_VECTOR_IAQ_SAMPLE_OUT           = 6632, /* Force, Accel, Vex, Temperature & UTC sample */
    IOP_VECTOR_START_SPIN_CAL           = 6633, /* Start Vector Spin Cal */
    IOP_VECTOR_PEDAL_SIDE_DATA          = 6634, /* Get Vector Pedal Side Info */
    IOP_VECTOR_START_BRIDGE_CAL         = 6635, /* Vector MFG Start Bridge Cal */
    IOP_VECTOR_START_FINAL_CAL          = 6636, /* Vector MFG Start Final Cal */
    IOP_VECTOR_CAL_STATUS_DATA          = 6637, /* Get Calibration State/Status */
    IOP_VECTOR_ALGORITHM_SAMPLE_DATA    = 6638, /* Algorithm sample data output */
    IOP_VECTOR_ALGORITHM_CYCLE_DATA     = 6639, /* Algorithm cycle data output */
    IOP_VECTOR_DATA_REFERENCE_FRAME     = 6640, /* Data reference frame */
    IOP_VECTOR_START_ZERO_OFFSET        = 6641, /* Start zero offset process */
    IOP_VECTOR_SAMPLING_TEST_DATA       = 6642, /* Sampling Test results */
    IOP_VECTOR_SET_PEDAL_SIDE           = 6643, /* Set Pedal Side */
    IOP_VECTOR_TEMP_CAL_RESULT          = 6644, /* Get result from temperature calibration, should be 0 */
    IOP_VECTOR_SPIN_CAL_RESULT          = 6645, /* Get result from spin calibration, should be 0 */
    IOP_VECTOR_FORCE_ERROR_FRACTION_DATA    = 6646, /* Binned force error fraction results */
    IOP_VECTOR_PCO_ERROR_FRACTION_DATA      = 6647, /* Binned pco error fraction results */
    IOP_VECTOR_GET_FORCE_ERROR_FRACTION = 6648, /* Request for force error fraction results */
    IOP_VECTOR_GET_PCO_ERROR_FRACTION   = 6649, /* Request for PCO error fraction results */
    IOP_VECTOR_GET_ACCEL_CONV           = 6650, /* Request to get accel convergence data */
    IOP_VECTOR_ACCEL_CONV_DATA          = 6651, /* Accel convergence data */
    IOP_VECTOR_GET_STRAIN_CONV          = 6652, /* Request to get strain convergence data */
    IOP_VECTOR_STRAIN_CONV_DATA         = 6653, /* Strain convergence data */
    IOP_VECTOR_STRAIN_RANGE_DATA        = 6654, /* Strain range data*/
    IOP_VECTOR_VEX_RANGE_DATA           = 6655, /* Vex range data */
    IOP_VECTOR_ACCEL_RANGE_DATA         = 6656, /* Accel range data */
    IOP_VECTOR_TEMPERATURE_RANGE_DATA   = 6657, /* Temperature range data */
    IOP_VECTOR_TEMPERATURE_COMPENSATION_DATA    = 6658, /* Temperature compensation data */
    IOP_VECTOR_BATTERY_DATA             = 6659, /* Battery data */
    IOP_VECTOR_RAW_OFFSET_DATA          = 6660, /* Raw offsets */
    IOP_VECTOR_OPERATIONAL_OFFSET_DATA  = 6661, /* Operational offsets */
    IOP_VECTOR_INSTALL_ANGLES_DATA      = 6662, /* Install angles */
    IOP_VECTOR_COMPACT_SAMPLE_OUT       = 6663, /* Force and Accel sample */
    IOP_VECTOR_TEMPCAL_NOISE_STATS_DATA = 6664,

    IOP_VECTOR_OPER_INST_END            = 6671, /* marker */

    /*------------------------------------------------------
    General Temperature Data
    ------------------------------------------------------*/
    IOP_TEMPERATURE_INST_START          = 6672, /* marker */

    IOP_TEMPERATURE_GET_TEMP            = 6672, /* get temperature */
    IOP_TEMPERATURE_Kx32_DATA           = 6673, /* temperature data in Kelvin x 32 */
    IOP_TEMPERATURE_LOW_THRESHOLD       = 6674, /* Low temperature event threshold */
    IOP_TEMPERATURE_HIGH_THRESHOLD      = 6675, /* High temperature event threshold */
    IOP_TEMPERATURE_CHANGE_ALERT        = 6676, /* Temperature change alert        */

    IOP_TEMPERATURE_INST_END            = 6680, /* marker */

    /*------------------------------------------------------
    Photoplethysmogram (PPG) Analog Front End (AFE) sensor
    test data
    ------------------------------------------------------*/
    IOP_PPG_AFE_DATA_START                      = 6681, /* Marker */

    IOP_PPG_AFE_SELF_TEST_DATA                  = 6681,
    IOP_PPG_AFE_MFG_CURRENT_MEAS_STATE_DATA     = 6682,
    IOP_PPG_AFE_MFG_FSP_DATA                    = 6683,
    IOP_PPG_AFE_LED_BRIGHTNESS_STATE_DATA       = 6684,
    IOP_PPG_AFE_IMPEDANCE_DARK_LVL_DATA         = 6685,
    IOP_PPG_AFE_PD_DISCONNECT_DATA              = 6686,
    IOP_PPG_AFE_MFG_NOISE_STATE_DATA            = 6687,
    IOP_PPG_AFE_MFG_LIGHT_OUTPUT_STATE_DATA     = 6688,
    IOP_PPG_AFE_MFG_LIGHT_POLLUTION_DATA        = 6689,
    IOP_PPG_AFE_MFG_RECEIVER_SENSITIVITY_DATA   = 6690,
    IOP_PPG_AFE_MFG_CLK_VAR_TEST_DATA           = 6691,

    IOP_PPG_AFE_DATA_END                        = 6691, /* Marker */

    /*------------------------------------------------------
    Bootloader
    ------------------------------------------------------*/
    IOP_BOOTLOADER_INST_START               = 6692, /* marker */

    IOP_BOOTLOADER_SET_MASTER_SEED          = 6693, /* Set bootloader master seed. */
    IOP_BOOTLOADER_MASTER_SEED_DATA         = 6694, /* Bootloader master seed data. */
    IOP_BOOTLOADER_SET_APP_RESERVED_PAGES   = 6695, /* Set application reserved data pages. */
    IOP_BOOTLOADER_APP_RESERVED_PAGES_DATA  = 6696, /* Application reserved pages data. */
    IOP_BOOTLOADER_SET_START_ADDRESS        = 6697, /* Set bootloader start address. */
    IOP_BOOTLOADER_START_ADDRESS_DATA       = 6698, /* Bootloader start address data. */
    IOP_BOOTLOADER_SET_MBR_PARAMS_ADDRESS   = 6699, /* Set MBR parameters start address. */
    IOP_BOOTLOADER_MBR_PARAMS_ADDRESS_DATA  = 6700, /* MBR parameters start address data. */

    IOP_BOOTLOADER_FILE_INFO_DATA           = 6701, /* Provides the file information for upgrade */
    IOP_BOOTLOADER_FILE_PACKET_DATA         = 6702, /* File packet data transfer */
    IOP_BOOTLOADER_FILE_PACKET_ACK          = 6703, /* File packet data received ack */
    IOP_BOOTLOADER_DEVICE_INFO_DATA         = 6704, /* Provides the device info */
    IOP_BOOTLOADER_SET_DEVICE_MODE          = 6705, /* Set the device mode : APP, BL, etc. */
    IOP_BOOTLOADER_DEVICE_MODE_DATA         = 6706, /* Provides the current device mode */
    IOP_BOOTLOADER_STATUS_DATA              = 6707, /* Provides the DFU status (verification/write passed or failed) */
    IOP_BOOTLOADER_CONTINUE_UPDATE          = 6708, /* Sent by host to start the next update stage if status is IOP_BOOTLOADER_STATUS_COMPLETE_SEND_AGAIN (refer to IOP_pub_bootloader_types.h) */
    IOP_BOOTLOADER_READY                    = 6709, /* Transmitted by bootloader on startup to indicate that the bootloader is ready for an update, or to continue an update. Can be used to detect spurious reset conditions. */

    IOP_BOOTLOADER_INST_END                 = 6720, /* marker */

    /*------------------------------------------------------
    Extended ID (continued)
    ------------------------------------------------------*/
    IOP_SET_EXTENDED_UNIT_ID            = 6721, /* Set unit extended ID. Use IOP_EXTENDED_UNIT_ID_DATA for passing the extended ID */

    /*------------------------------------------------------
    Return byte status indicating a "CPYRIGHT.txt" exists 1,
    or doesn't exist 0.
    ------------------------------------------------------*/
    IOP_COPYRIGHT_FILE_STATUS           = 6722,

    /*------------------------------------------------------
    User selected FIT Sport data id
    ------------------------------------------------------*/
    IOP_USER_FIT_SPORT                  = 6723,

    /*-------------------------------------------------------
    Time data from an external source, UTC, local offset, DST
    -------------------------------------------------------*/
    IOP_EXTERNAL_TIME_SYNC_DATA         = 6724,

    /*------------------------------------------------------
    Humidity sensor
    ------------------------------------------------------*/
    IOP_HUMIDITY_INST_BEGIN             = 6725, /* Marker */

    IOP_HUMIDITY_DATA                   = 6725, /* Humidity sensor data */
    IOP_HUMIDITY_RQST_SAMPLE            = 6726, /* Request a humidity sample */
    IOP_HUMIDITY_SAVED_DATA             = 6727, /* Saved humidity data */

    IOP_HUMIDITY_INST_END               = 6734, /* Marker */

    /*------------------------------------------------------
    802.15.4 Radio
    ------------------------------------------------------*/
    IOP_802_15_4_INST_BEGIN             = 6735, /* Marker */
    IOP_802_15_4_SET_TEST_MODE          = 6735, /* set the radio into various test modes */
    IOP_802_15_4_RX_DATA                = 6736, /* data reception information and indication */
    IOP_802_15_4_TX_DATA                = 6737, /* data transmission information and indication */
    IOP_802_15_4_INST_END               = 6744, /* Marker */

    /*------------------------------------------------------
    Remote Gyroscope
    ------------------------------------------------------*/
    IOP_REMOTE_GYRO_INST_START          = 6745, /* Marker */
    IOP_REMOTE_GYRO_CONFIG              = 6745,
    IOP_REMOTE_GYRO_DATA                = 6746,
    IOP_REMOTE_GYRO_DATA_MULTI          = 6747, /* Many sequentially placed IOP_REMOTE_GYRO_DATA packets */

    IOP_REMOTE_GYRO_INST_END            = 6754, /* Marker */

    /*------------------------------------------------------
    Information about the user
    ------------------------------------------------------*/
    IOP_USER_INFO_DATA                  = 6755,
    IOP_USER_SPEED_DATA                 = 6756,
    IOP_USER_CADENCE_DATA               = 6757,
    IOP_USER_POWER_DATA                 = 6758,

    /*------------------------------------------------------
    Iridium Modem
    ------------------------------------------------------*/
    IOP_IRIDIUM_INST_BEGIN              = 6759, /* Marker */

    IOP_IRIDIUM_MODEM_INFO              = 6759, /* Iridium modem information */
    IOP_IRIDIUM_EOL_TEST_START_STOP     = 6760, /* Start/Stop the Iridium end of line RX/TX test */
    IOP_IRIDIUM_EOL_TEST_DATA           = 6761, /* Iridium end of line RX/TX test data */
    IOP_IRIDIUM_TX_TEST_START_STOP      = 6762, /* Start/Stop the Iridium TX test */
    IOP_IRIDIUM_TX_TEST_DATA            = 6763, /* Iridium TX test data */
    IOP_IRIDIUM_MODE                    = 6764, /* Set Iridium mode */
    IOP_IRIDIUM_SIGNAL_QUALITY          = 6765, /* Iridium signal quality data */
    IOP_IRIDIUM_SERIAL_NUMBER           = 6766, /* Iridium serial number data */
    IOP_IRIDIUM_TX_POWER_TEST           = 6767, /* Control Iridium TX power test */
    IOP_IRIDIUM_RSSI_TEST_START_STOP    = 6768, /* Start/Stop Iridium RSSI test */
    IOP_IRIDIUM_RSSI_TEST_DATA          = 6769, /* Iridium RSSI test data */

    IOP_IRIDIUM_INST_END                = 6769, /* Marker */

    /*------------------------------------------------------
    Run multiple basic in-system tests. Payload data is
    a bitmask identifying which test(s) to run. Result
    payload data is a bitmask representing the result
    of each requested test where 0 = test failed and
    1 = test passed.
    ------------------------------------------------------*/
    IOP_MULTIPLE_BIST                   = 6770,
    IOP_MULTIPLE_BIST_RESULT            = 6771,

    /*------------------------------------------------------
    Wakeup Tests
    ------------------------------------------------------*/
    IOP_WAKE_TEST_RTC                   = 6772, /* Test device wakeup via RTC */
    IOP_WAKE_TEST_ACCEL                 = 6773, /* Test device wakeup via accelerometer  */

    /*------------------------------------------------------
    Display runtime data
    ------------------------------------------------------*/
    IOP_DSPL_RUNTIME                    = 6774,

    /*------------------------------------------------------
    Finite State Machine
    ------------------------------------------------------*/
    IOP_FSM_INST_START                  = 6775, /* Marker */
    IOP_FSM_ACTION                      = 6775, /* State machine action */
    IOP_FSM_TRANSITION                  = 6776, /* State machine transition */
    IOP_FSM_EVENT                       = 6777, /* State machine event */

    IOP_FSM_INST_END                    = 6784, /* Marker */

    /*------------------------------------------------------
    XCP Operational Messages
    ------------------------------------------------------*/
    IOP_XCP_OPER_INST_START             = 6785, /* marker */

    IOP_XCP_IAQ_SAMPLE_OUT              = 6785,

    IOP_XCP_OPER_INST_END               = 6794, /* marker */

    /*------------------------------------------------------
    3axis Gyro Cal
    ------------------------------------------------------*/
    IOP_3AXIS_GYRO_INST_BEGIN           = 6795, /* Marker */
    IOP_3AXIS_GYRO_SET_STD_DEV_SCALE    = 6795,
    IOP_3AXIS_GYRO_SET_ACCEL_ERR_SCALE  = 6796,

    IOP_3AXIS_GYRO_INST_END             = 6800, /* Marker */

    /*------------------------------------------------------
    Reboot into specified Test Mode
    ------------------------------------------------------*/
    IOP_REBOOT_IN_TESTMODE              = 6801,

    /*------------------------------------------------------
    Photoplethysmogram (PPG) Analog Front End (AFE) sensor
    test data - Second format of noise state data
    ------------------------------------------------------*/
    IOP_PPG_AFE_MFG_NOISE_STATE_DATA_V2 = 6802,

    /*------------------------------------------------------
    Bluetooth Certified Profiles (BCP)
    ------------------------------------------------------*/
    IOP_BCP_START                       = 6803, /* marker */
    IOP_BCP_PTS_CMD                     = 6803,

    IOP_BCP_END                         = 6807, /* marker */

    /*------------------------------------------------------
    Data about what the current test mode is
    ------------------------------------------------------*/
    IOP_TESTMODE_DATA                   = 6808,

    /*------------------------------------------------------
    LRF (Laser Range Finder) Data
    ... See also LRF EXT inst block starting at 7033
    ------------------------------------------------------*/
    IOP_LRF_INST_START                  = 6809, /* Marker */
    IOP_LRF_INST_FPGA_READ              = 6809,
    IOP_LRF_INST_FPGA_WRITE             = 6810,
    IOP_LRF_INST_HAPTIC_READ            = 6811,
    IOP_LRF_INST_HAPTIC_WRITE           = 6812,
    IOP_LRF_INST_ENABLE                 = 6813,
    IOP_LRF_INST_RANGE                  = 6814,
    IOP_LRF_INST_BIST_RESULT            = 6815,
    IOP_LRF_INST_APD_CAL_RESULT         = 6816,
    IOP_LRF_INST_APD_ADC_MEAS           = 6817,
    IOP_LRF_INST_FILTERED_RANGE         = 6818,
    IOP_LRF_INST_TEST_APD_BIAS          = 6819,
    IOP_LRF_INST_END                    = 6819, /* Marker */

    /*------------------------------------------------------
    NOH ( Newly Overhauled ) Support
    ------------------------------------------------------*/
    IOP_SET_USED_UNIT_FLAG              = 6820,

    /*------------------------------------------------------
    FLASH (Flash memory tests)
    ------------------------------------------------------*/
    IOP_FLASH_START                     = 6821, /* Marker */

    IOP_FLASH_TEST                      = 6821,

    IOP_FLASH_TEST_DATA                 = 6822,

    IOP_FLASH_END                       = 6822, /* Marker */

    /*------------------------------------------------------
    Photoplethysmogram (PPG) Analog Front End (AFE) sensor
    Disable AGC and manually set settings command
    (specific settings for ADPD10x part)
    ------------------------------------------------------*/
    IOP_PPG_ADPD_AFE_CONFIGURATION_DATA  = 6823,

    /*------------------------------------------------------
    Photoplethysmogram (PPG) Analog Front End (AFE) sensor
    Provide host with status of the driver.
    ------------------------------------------------------*/
    IOP_PPG_ADPD_AFE_STATUS              = 6824,

    /*------------------------------------------------------
    Dive Data
    ------------------------------------------------------*/
    IOP_DIVE_INST_START                 = 6825, /* Marker */

    IOP_DIVE_TEST_DATA                  = 6825,
    IOP_DIVE_BUTTON_DATA                = 6826,
    IOP_DIVE_TEST_DELETE_STATUS         = 6827,
    IOP_DIVE_BUTTON_TEST_DELETE_STATUS  = 6828,
    IOP_DIVE_TEST_STATUS_DATA           = 6829,
    IOP_DIVE_BUTTON_TEST_STATUS_DATA    = 6830,
    IOP_DIVE_REMOTE_AUTO_DIVE_NTFCTN    = 6831,

    IOP_DIVE_INST_END                   = 6834, /* Marker */

    /*------------------------------------------------------
    HW GPN
    ------------------------------------------------------*/
    IOP_HW_GPN                          = 6835,

    /*------------------------------------------------------
    Camera commands (continued from 1629)
    ------------------------------------------------------*/

    IOP_CAMERA_SET_CONFIG               = 6836,
    IOP_CAMERA_CONFIG_DATA              = 6837,
    IOP_CAMERA_TTFVF_DATA               = 6838,
    IOP_CAMERA_PAIR_BT                  = 6839,
    IOP_CAMERA_UNPAIR_BT                = 6840,
    IOP_CAMERA_GET_PAIRED_STATE         = 6841,

    IOP_CAMERA_END                      = 6860,

    /*------------------------------------------------------
    Region transfers over 4GB.
    ------------------------------------------------------*/
    IOP_RGN_64BIT_INST_START            = 6861, /* Marker */

    IOP_RGN_DATA_64BIT                  = 6861,
    IOP_RGN_STRT_RX_64BIT               = 6862,

    IOP_RGN_64BIT_INST_END              = 6870, /* Marker */

    /*------------------------------------------------------
    IOP request data extended
    ------------------------------------------------------*/
    IOP_RQST_DATA_EXTND                 = 6871,

    /*------------------------------------------------------
    Response packet for IOP_RQST_DATA_EXTND_SUPPORT_CHK
    command id.

    If a product supports IOP request data extended, then
    the payload for IOP_RQST_DATA_EXTND_SUPPORT_INFO will
    be a unit8 with a value of 0x01.
    ------------------------------------------------------*/
    IOP_RQST_DATA_EXTND_SUPPORT_INFO    = 6872,

    /*------------------------------------------------------
    ID's for Instrumenting data from GPS multi
    -----------------------------------------------------*/
    IOP_GPS_MULTI_INST_DATA_START       = 6873,

    /*------------------------------------------------------
    New format satellite data. For more information, please
    see the JIRA GPSTECH-755
    -----------------------------------------------------*/
    IOP_GPS_MULTI_INST_GNSS_SAT_DATA    = 6873,

    IOP_GPS_MULTI_INST_DATA_RSRVD_0     = 6874,
    IOP_GPS_MULTI_INST_DATA_RSRVD_1     = 6875,
    IOP_GPS_MULTI_INST_DATA_RSRVD_2     = 6876,
    IOP_GPS_MULTI_INST_DATA_RSRVD_3     = 6877,
    IOP_GPS_MULTI_INST_DATA_RSRVD_4     = 6878,

    IOP_GPS_MULTI_INST_DATA_END         = 6878,

    /*------------------------------------------------------
    ID's for Instrumenting data from ECG
    -----------------------------------------------------*/
    IOP_ECG_INST_DATA_START             = 6879, /* marker */
    IOP_ECG_INST_MODE                   = 6879, /* Size=1, data=HWM_ecg_mode_t8*/
    IOP_ECG_INST_CONV                   = 6880, /* Size=4, data=float, (sample*conv) is in volts */
    IOP_ECG_INST_WAVEFORM               = 6881, /* HWM_ecg_packet */
    IOP_ECG_BACKEND_CTRL                = 6882, /* Encapsulates backend-specific commands */
    IOP_ECG_INST_DATA_END               = 6885, /* marker */

    /*------------------------------------------------------
    Non-volatile memory lock state.
    ------------------------------------------------------*/
    IOP_NVM_MEMORY_LOCK_DATA            = 6886,

    /*------------------------------------------------------
    GPS Chipset ON/OFF
    ------------------------------------------------------*/
    IOP_GPS_ONOFF                       = 6887,

    /*------------------------------------------------------
    Set of IOP instrumentation IDs for Near Field
    Communication (NFC)
    ------------------------------------------------------*/
    IOP_NFC_INST_START                  = 6888, /* Marker */
    IOP_NFC_INST_END                    = 6897, /* Marker */

    /*----------------------------------------------------------
    Biometrics module data
    Used internally by BMX to communicate with BMX on other
    processors within the same system.
    ----------------------------------------------------------*/
    IOP_BMX_DATA                        = 6898,

    /*------------------------------------------------------
    Bluetooth classic network service IDs
    ------------------------------------------------------*/
    IOP_BTNS_START                      = 6899,

    IOP_BTNS_CMD                        = 6899,
    IOP_BTNS_AUDIO_REQ                  = 6900,

    IOP_BTNS_END                        = 6903,

    /*------------------------------------------------------
    Applied Ballistics IDs
    ------------------------------------------------------*/
    IOP_APPLIED_BALLISTICS_LICENSE_DATA   = 6904,
    IOP_APPLIED_BALLISTICS_LIBRARY_STATUS = 6905,

    /*------------------------------------------------------
    Depth Sensor Barometer ID
    ------------------------------------------------------*/
    IOP_BARO_DEPTH_SENSOR_DATA          = 6906,

    /*------------------------------------------------------
    ID's for controlling gearbox and hand
    ------------------------------------------------------*/
    IOP_GEARBOX_START                   = 6907,

    /*------------------------------------------------------
    SLG IC state
    ------------------------------------------------------*/
    IOP_GEARBOX_GET_CRNT_STATE          = 6908,
    IOP_GEARBOX_SET_SLG_MODE_REG        = 6909,
    IOP_GEARBOX_GET_SETUP               = 6910,

    /*------------------------------------------------------
    Gearbox control without setting frequency
    ------------------------------------------------------*/
    IOP_GEARBOX_MOVE_SNGL_HAND          = 6911,
    IOP_GEARBOX_MOVE_SEC_CW             = 6912,
    IOP_GEARBOX_MOVE_SEC_CCW            = 6913,
    IOP_GEARBOX_MOVE_MIN_CW             = 6914,
    IOP_GEARBOX_MOVE_MIN_CCW            = 6915,
    IOP_GEARBOX_MOVE_HOUR_CW            = 6916,
    IOP_GEARBOX_MOVE_HOUR_CCW           = 6917,
    IOP_GEARBOX_SEND_ALL_SETTING        = 6918,

    /*------------------------------------------------------
    Hnd control
    ------------------------------------------------------*/
    IOP_HND_SET_MODE                    = 6919,
    IOP_HND_SEC_CALIBRATION             = 6920,
    IOP_HND_MIN_CALIBRATION             = 6921,
    IOP_HND_HOUR_CALIBRATION            = 6922,
    IOP_HND_DONE_CALIBRATION            = 6923,

    /*------------------------------------------------------
    Gearbox control with setting frequency
    ------------------------------------------------------*/
    IOP_GEARBOX_SET_MIN_FREQ            = 6924,
    IOP_GEARBOX_SET_HOUR_FREQ           = 6925,
    IOP_GEARBOX_SET_MIN_DIR             = 6926,
    IOP_GEARBOX_SET_HOUR_DIR            = 6927,
    IOP_GEARBOX_SET_MIN_STEP            = 6928,
    IOP_GEARBOX_SET_HOUR_STEP           = 6929,
    IOP_GEARBOX_MOVE_HANDS              = 6930,
    IOP_GEARBOX_HANDS_TEST              = 6931,
    IOP_GEARBOX_SET_CNT0_LIMIT          = 6932,

    IOP_GEARBOX_END                     = 6937,

    /*------------------------------------------------------
    Remote storage instrumentation IDs
    For details see:
    https://confluence.consumer.garmin.com/display/OlatheFit/Micro+Radar+-+USB+Module+-+UMS-IOP+Translation
    ------------------------------------------------------*/
    IOP_STOR_INST_START                 = 6938, /* Marker */

    IOP_STOR_INITIALIZE                 = 6938,
    IOP_STOR_INITIALIZED_DATA           = 6939,
    IOP_STOR_GET_CAPACITY               = 6940,
    IOP_STOR_CAPACITY_DATA              = 6941,
    IOP_STOR_CHECK_IF_READY             = 6942,
    IOP_STOR_IS_READY_DATA              = 6943,
    IOP_STOR_CHK_WRITE_PROTECTION       = 6944,
    IOP_STOR_IS_WRITE_PROTECTED         = 6945,
    IOP_STOR_READ_BLOCKS                = 6946,
    IOP_STOR_BLOCK_DATA                 = 6947,
    IOP_STOR_WRITE_BLOCKS               = 6948,
    IOP_STOR_WRITE_RETURN               = 6949,
    IOP_STOR_MAX_LUN_DATA               = 6950,

    IOP_STOR_INST_END                   = 6954, /* Marker */

    /*------------------------------------------------------
    ID to get USB ID line data
    ------------------------------------------------------*/
    IOP_USB_ID_LINE_DATA                = 6955,

    IOP_VECTOR_AIR_IAQ_SAMPLE_OUT       = 6956, /* Vector Air sensor sample message */

    /*------------------------------------------------------
    Audio settings group
    ------------------------------------------------------*/
    IOP_AUDIO_INST_START                = 6957,

    IOP_AUDIO_INPUT_GAIN_SET            = 6957,
    IOP_AUDIO_OUTPUT_GAIN_SET           = 6958,
    IOP_AUDIO_GAIN_RANGE_RET            = 6959,
    IOP_AUDIO_GAIN_VALUE_RET            = 6960,
    IOP_AUDIO_STATUS_RET                = 6961,
    IOP_AUDIO_INPUT_ENABLE_AUTO_GAIN    = 6962,

    IOP_AUDIO_INST_END                  = 6964,

    /*------------------------------------------------------
    IDs to get USB module info
    ------------------------------------------------------*/
    IOP_USB_STATE_DATA                  = 6965,
    IOP_USB_MODE_DATA                   = 6966,

    /*------------------------------------------------------
    Display Tests
    ------------------------------------------------------*/
    IOP_DSPL_TEST                       = 6967,

    /*------------------------------------------------------
    Get the device's screen size
    ------------------------------------------------------*/
    IOP_SCREEN_SIZE                     = 6968,

    /*------------------------------------------------------
    Enable/Disable pen logging over IOP
    ------------------------------------------------------*/
    IOP_ENABLE_PEN_LOGGING              = 6969,

    /*------------------------------------------------------
    IDs for storing and verifying DiSa information
    ------------------------------------------------------*/
    IOP_DSA_INST_START                  = 6970,
    IOP_DSA_DISA_ID_STORE               = 6970,
    IOP_DSA_FIRST_ACTIV_HASH_STORE      = 6971,
    IOP_DSA_SECOND_ACTIV_HASH_STORE     = 6972,
    IOP_DSA_DISA_ID_VERIFY              = 6973,
    IOP_DSA_FIRST_ACTIV_HASH_VERIFY     = 6974,
    IOP_DSA_SECOND_ACTIV_HASH_VERIFY    = 6975,
    IOP_DSA_CLEAR_DATA                  = 6976,
    IOP_DSA_DISA_ID_DATA                = 6977,
    IOP_DSA_FIRST_ACTIV_HASH_DATA       = 6978,
    IOP_DSA_SECOND_ACTIV_HASH_DATA      = 6979,
    IOP_DSA_INST_END                    = 6980,

    /*------------------------------------------------------
    External Mount. Allow the unit to power up normally
    when the external mount is detected at boot for factory
    testing.
    ------------------------------------------------------*/
    IOP_EXTMNT_SKIP_COLDDETECT          = 6981,

    /*------------------------------------------------------
    Request VIB status/reply
    The expected reply is one 32 bit platform specific value.
    ------------------------------------------------------*/
    IOP_VIBE_STATUS                     = 6982,

    /*------------------------------------------------------
    ID's for tracking IFL sensor data
    ------------------------------------------------------*/
    IOP_SENSOR_DATA_CALIBRATED_ACCEL    = 6983,
    IOP_SENSOR_DATA_CALIBRATED_GYRO     = 6984,
    IOP_SENSOR_DATA_CALIBRATED_MAG      = 6985,

    /*------------------------------------------------------
    ID's for WICED based cypress chips
    ------------------------------------------------------*/
    IOP_WICED_INST_START                = 6986,

    IOP_WICED_SW_VER                    = 6986,
    IOP_WICED_REQ_HW_RESET              = 6987,

    IOP_WICED_INST_END                  = 6990,

    /*------------------------------------------------------
    ID's for SD Card Update
    ------------------------------------------------------*/
    IOP_CARD_UPDATE_STATUS              = 6991,

    /*------------------------------------------------------
    Modem inst IDs
    ------------------------------------------------------*/
    IOP_MODEM_AT_CMD_DATA               = 6992,
    IOP_MODEM_AT_CMD_RESPONSE           = 6993,
    IOP_MODEM_LOG                       = 6994,
    IOP_MODEM_STATUS                    = 6995,
    IOP_MODEM_SOCKET_CMND               = 6996,
    IOP_MODEM_CTRL                      = 6997,
    IOP_MODEM_TEST                      = 6998,
    IOP_MODEM_END                       = 6999,

    /*------------------------------------------------------
    ID's for China Unionpay ID
    ------------------------------------------------------*/
    IOP_CHINA_UNIONPAY_ID_SET           = 7000,
    IOP_CHINA_UNIONPAY_ID_GET           = 7001,
    IOP_CHINA_UNIONPAY_ID_DATA          = 7002,

    /*------------------------------------------------------
    Indicate that sub dac changed, data is 32kHz timestamp
    ------------------------------------------------------*/
    IOP_MAX8614X_SUB_DAC_CHANGE         = 7003,

    /*------------------------------------------------------
    DGNSS data instrumentation IDs,
    Differential Global Navigation Satellite System,
    Reserving a block of 14 IDs for future
    constellation support.
    ------------------------------------------------------*/
    IOP_PVT_DGNSS_PVT_DATA              = 7004,
    IOP_PVT_DGNSS_SAT_DATA              = 7005,
    IOP_PVT_DGNSS_GPS_MEAS_DATA         = IOP_PVT_DGNSS_SAT_DATA,
    IOP_PVT_DGNSS_SAT_DATA_EXT          = 7006,
    IOP_PVT_DGNSS_GLO_MEAS_DATA         = IOP_PVT_DGNSS_SAT_DATA_EXT,
    IOP_PACKED_GLO_EPH_DATA             = 7007,
    IOP_PACKED_GALILEO_INAV_EPH_DATA    = 7008,
    IOP_PACKED_BEIDOU_CNAV1_EPH_DATA    = 7009,
    IOP_PACKED_QZSS_LNAV_EPH_DATA       = 7010,
    IOP_SBAS_RAW_MSG                    = 7011,

    IOP_DGNSS_LAST                      = 7017,

    /*------------------------------------------------------
    Manufacturing commands for maxim 8614x AFEs
    ------------------------------------------------------*/
    IOP_MAX_8614X_MANUF_START              = 7018,

    IOP_MAX_8614X_MANUF_BIST_RESP          = 7018,
    IOP_MAX_8614X_MANUF_CURRENT_RESP       = 7019,
    IOP_MAX_8614X_MANUF_LED_RESP           = 7020,
    IOP_MAX_8614X_MANUF_PD_RESP            = 7021,
    IOP_MAX_8614X_MANUF_REFLECTED_RESP     = 7022,
    IOP_MAX_8614X_MANUF_SET_LED_UA         = 7023,
    IOP_MAX_8614X_MANUF_SET_LED_UA_RESP    = 7024,
    IOP_MAX_8614X_ILP_RESP                 = 7025,
    IOP_MAX_8614X_MANUF_SET_FSP2           = 7026,
    IOP_MAX_8614X_MANUF_SET_LED_CW         = 7027,
    IOP_MAX_8614X_MANUF_SET_LED_CW_RESP    = 7028,
    IOP_MAX_8614X_MANUF_REFLECTED_RESP_STD = 7029,
    IOP_MAX_8614X_MANUF_REFLECTED_ME_TEST  = 7030,

    IOP_MAX_8614X_MANUF_END                = 7030,


    IOP_HWM_KEY_DRIVER_DATA                = 7031, /* Key driver data (HWM_key_evnt_type) */

    /*------------------------------------------------------
    IOP command to push a GPS testing page that stresses
    the system.
    ------------------------------------------------------*/
    IOP_PUSH_GPS_STRESS_TEST_PAGE       = 7032,

    /*------------------------------------------------------
    LRF EXT (Laser Range Finder Extended) Data
    ... See also 'original' LRF inst block starting at 6809
    ------------------------------------------------------*/
    IOP_LRF_EXT_INST_START              = 7033, /* Marker */
    IOP_LRF_EXT_LASER_POWER             = 7033,
    IOP_LRF_EXT_LASER_TEST              = 7034,
    IOP_LRF_EXT_ENABLE_LASER_TESTMODE   = 7035,
    IOP_LRF_EXT_CALIBRATE_APD           = 7036,
    IOP_LRF_EXT_CLEAR_APD_CAL           = 7037,
    IOP_LRF_EXT_APD_CAL_DATA            = 7038,
    IOP_LRF_EXT_ENABLE_LOGGING          = 7039,
    IOP_LRF_EXT_CORR_MEAS_RQST          = 7040,
    IOP_LRF_EXT_CORR_REC_RESP           = 7041, /* Send a series of packets until coorelation record transfered.  Transfers marked complete by sending a zero-sized payload IOP_LRF_EXT_CORR_REC_RESP packet */
    IOP_LRF_EXT_APD_BIAS_OVERRIDE       = 7042,

    IOP_LRF_EXT_INST_END                = 7043, /* Marker */

    /*------------------------------------------------------
    ID's for generic GNSS sensor configuration.
    ------------------------------------------------------*/
    IOP_GNSS_SENSOR_SET                 = 7044,
    IOP_GNSS_SENSOR_REQUEST             = 7045,
    IOP_GNSS_SENSOR_REPLY               = 7046,
    IOP_GNSS_SENSOR_END                 = 7050,

    /*------------------------------------------------------
    Baro Monitor
    ------------------------------------------------------*/
    IOP_BARO_MONITOR_EXPIRED            = 7051,

    /*------------------------------------------------------
    ID's for eBike communication
    ------------------------------------------------------*/
    IOP_EBIKE_START                     = 7052,

    IOP_EBIKE_SYSTEM_DATA               = 7052,
    IOP_EBIKE_SYSTEM_CTRL               = 7053,
    IOP_EBIKE_RADAR_TARGET              = 7054,
    IOP_EBIKE_LIGHT_STATE               = 7055,
    IOP_EBIKE_LIGHT_CONTROL             = 7056,
    IOP_EBIKE_SYSTEM_EXT_DATA           = 7057,

    IOP_EBIKE_END                       = 7251,

    /* IAQ OFE Event Instance IDs */
    IOP_IAQ_OFE_VRSN_EVENT_AGC_CHANGE   = 7252, /* Specify upcoming AGC change data format - good till next */
    IOP_IAQ_OFE_EVENT_AGC_CHANGE        = 7253, /* Signal AGC change */
    IOP_IAQ_OFE_VRSN_EVENT_SIGNAL_SHIFT = 7254, /* Specify upcoming shift data format - good till next */
    IOP_IAQ_OFE_EVENT_SIGNAL_SHIFT      = 7255, /* Signal that the optical signal is shifting */

    /*------------------------------------------------------
    Golf Radar instrumentation IDs
    ------------------------------------------------------*/
    IOP_GRDR_INST_START                 = 7256, /* Marker */
    IOP_GRDR_INST_ENABLE                = 7256,
    IOP_GRDR_INST_SET_CHANNEL           = 7257,

    IOP_GRDR_INST_END                   = 7266, /* Marker */

    /*------------------------------------------------------
    Start of next instrumentation ID group.
    ------------------------------------------------------*/
    IOP_BSCM_SENSOR_START               = 7267, /* Marker */

    IOP_BSCM_ACCEL_DATA                 = 7267, /* Accelerometer sample data */
    IOP_BSCM_MAG_DATA                   = 7268, /* Magnetometer sample data */
    IOP_BSCM_SPD_SAMPLE_DATA            = 7269, /* Speed sensor resampled data */
    IOP_BSCM_CAD_SAMPLE_DATA            = 7270, /* Cadence sensor resampled data */
    IOP_BSCM_SENSOR_EVENT               = 7271, /* eg. cycle with period information */
    IOP_BSCM_SENSOR_PARAMETER           = 7272, /* pollable information such as odometer reading */
    IOP_BSCM_SENSOR_REQUEST             = 7273, /* config info like tire circumference */
    IOP_BSCM_MANUFACTURING_DATA         = 7274, /* data about if the device is a cannondale variant */
    IOP_BSCM_LOCK_GEAR                  = 7275, /* Lock the current gear to the gear id included in the command */
    IOP_BSCM_GEAR_DATA                  = 7276, /* Data about what gear the device is in */
    IOP_BSCM_BLE_TEST_DATA              = 7277, /* Inject event data for BLE test */

    IOP_BSCM_SENSOR_END                 = 7277, /* Marker */

    /*------------------------------------------------------
    ID for mount peripheral power enable/disable
    ------------------------------------------------------*/
    IOP_MOUNT_PERIPHERAL_POWER_ENABLE   = 7278,

    /*------------------------------------------------------
    ID for Xero Shotgun Radar
    For details see:
    https://confluence.consumer.garmin.com/display/OUTDOOR/Xero+S1+IPC+Detailed+Design
    ------------------------------------------------------*/
    IOP_XERO_SHOTGUN_RADAR              = 7279, /* All Xero Shotgun Radar messages */

    IOP_HWM_REMOTE_UART                 = 7280,

    /*------------------------------------------------------
    Tone test automation commands
    Triggers a periodic tone test
    ------------------------------------------------------*/
    IOP_TONE_TEST_PERIODIC              = 7281, /* Period (mS) between tone invocations */

    /*------------------------------------------------------
    IOP messages for communicating with the CTR fixture.
    ------------------------------------------------------*/
    IOP_PHASE_STEPPER_CTR_FIXTURE_DATA  = 7282,

    /*------------------------------------------------------
    Wrist Detect Module
    ------------------------------------------------------*/
    IOP_WD_INST_START                   = 7283, /* Marker */
    IOP_WD_OUT_ID                       = 7283, /* Module Output */
    IOP_WD_IN_ID                        = 7284, /* Module Input */

    IOP_WD_INST_END                     = 7289, /* Marker */

    /*------------------------------------------------------
    Remote Optical AFE
    ------------------------------------------------------*/
    IOP_REMOTE_OFE_INST_START           = 7290, /* Marker */
    IOP_REMOTE_OFE_DATA                 = 7290,
    IOP_REMOTE_OFE_DATA_SHIFT           = 7291,
    IOP_REMOTE_OFE_PHASE_STEPPER_INFO   = 7292,
    IOP_REMOTE_OFE_REGISTER_DUMP        = 7293,
    IOP_REMOTE_OFE_PHASE_STEPPER_END    = 7294, /* IOP to inform host that all phases have been stepped */
    /*------------------------------------------------------
    AFE manufacturing calibration data
    ------------------------------------------------------*/
    IOP_REMOTE_OFE_CAL_DATA             = 7295,
    IOP_REMOTE_OFE_CAL_DATA_ACK         = 7296,
    IOP_REMOTE_OFE_CAL_DATA_NACK        = 7297,

    IOP_REMOTE_OFE_INST_END             = 7299, /* Marker */

    IOP_HOST_PROCESSOR_STATE            = 7300, /* IOP_host_processor_state_type */

    /*------------------------------------------------------
    TIM (Test Interface Module) Data
    ------------------------------------------------------*/
    IOP_TIM_DATA                        = 7301,

    /*------------------------------------------------------
    IOP messages for remote ALS
    ------------------------------------------------------*/
    IOP_REMOTE_ALS_CMD                  = 7302,
    IOP_REMOTE_ALS_RESPONSE             = 7303,

    /*------------------------------------------------------
    IOP messages for reset count and hard fault information
    ------------------------------------------------------*/
    IOP_RESET_COUNT_DATA                = 7304,
    IOP_HW_RESET_COUNT_DATA             = 7305,
    IOP_SW_RESET_COUNT_DATA             = 7306,
    IOP_WATCHDOG_RESET_COUNT_DATA       = 7307,
    IOP_HARD_FAULT_INFO_DATA            = 7308,

    /*------------------------------------------------------
    Response for IOP_CHARGER_RESET_START_TEST (boolean indicating pass/fail)
    ------------------------------------------------------*/
    IOP_CHARGER_RESET_TEST_STATUS       = 7309,

    /*------------------------------------------------------
    ID for accessing TCXO drift in NONVOL
    ------------------------------------------------------*/
    IOP_RF_DRFT_CAL                     = 7310, /* RF Calibration */
    IOP_RF_STR_TCXO_DRFT                = 7311, /* Storing TCXO drift to NONVOL */
    IOP_RF_GET_TCXO_DRFT                = 7312, /* Get TCXO drift from NONVOL */
    IOP_RF_TCXO_DRFT_DATA               = 7313, /* TCXO drift data */

    /*------------------------------------------------------
    NRF52 Temperature Sensor
    ------------------------------------------------------*/
    IOP_NRF52_TEMPERATURE_DATA          = 7314,

    /*------------------------------------------------------
     IOPs for BIOS information
    ------------------------------------------------------*/
    IOP_BIOS_INST_START                 = 7315,
    IOP_BIOS_RESPONSE                   = 7315,

    IOP_BIOS_INST_END                   = 7320,

    /*------------------------------------------------------
    All IOPs to handle IPC for the Diablo radar product.
    ------------------------------------------------------*/
    IOP_DIABLO_BASEBALL_RADAR           = 7321,

    /*------------------------------------------------------
    Authenticated IOP per GRFC-0024
    ------------------------------------------------------*/
    IOP_AUTH_INST_START                 = 7322, /* Marker */

    IOP_AUTH_START                      = 7322, /* Host->Device, request to start */
    IOP_AUTH_CHALLENGE                  = 7323, /* Device->Host, data to sign     */
    IOP_AUTH_RESPONSE                   = 7324, /* Host->Device, signature        */
    IOP_AUTH_RESULT                     = 7325, /* Device->Host, success/failure  */

    IOP_AUTH_INST_END                   = 7330, /* Marker */

    /*------------------------------------------------------
    ID for transferring RTC data to/from a remote source
    ------------------------------------------------------*/
    IOP_REMOTE_RTC_DATA                 = 7331,

    /*------------------------------------------------------
    UART over external mount
    ------------------------------------------------------*/
    IOP_UART_OV_MNT_INST                = 7332, /* For factory test instruction commands */

    /*------------------------------------------------------
    Send/Recieve Remote commands to MFI chip
    ------------------------------------------------------*/
    IOP_REMOTE_MFI_WRITE_DATA           = 7333,
    IOP_REMOTE_MFI_READ_DATA            = 7334,

    /*------------------------------------------------------
    HRM5 - HRM Dual Basic/Advanced
    ------------------------------------------------------*/
    IOP_HRM_START                       = 7335, /* Marker */

    IOP_HRM_EVENT_TIME                  = 7335, /* HRM captured event time for heart beat */

    IOP_HRM_SENSOR_DATA                 = 7336,
    IOP_HRM_ADC_DATA                    = 7337,
    IOP_HRM_COMP_ADC_DATA               = 7338,
    IOP_HRM_LEADS_DETECT_STATUS         = 7339,
    IOP_HRM_BODY_RESISTANCE_MEASUREMENT = 7340,
    IOP_HRM_ACCEL_DATA                  = 7341,

    IOP_HRM_END                         = 7345, /* Marker */

    /*------------------------------------------------------
    IOP to set the GLONASS svid ID in test mode
    ------------------------------------------------------*/
    IOP_GPS_TEST_SET_GLONASS_SVID       = 7346,

    /*------------------------------------------------------
    Sensor Hub Memory Tests
    ------------------------------------------------------*/
    IOP_SENSOR_HUB_ROM_TEST_RESULT      = 7347,
    IOP_SENSOR_HUB_RAM_TEST_RESULT      = 7348,

    /*------------------------------------------------------
    IOP to allow IOP communication via BLE
    ------------------------------------------------------*/
    IOP_COMM_OVER_BLE_ENABLE             = 7349,

    /*------------------------------------------------------
    IOP for Alpha/Astro Dog tracking series products
    ------------------------------------------------------*/
    IOP_ALPHA_PACKING_START             = 7350,
    IOP_ALPHA_PACKING_GEN_RFC_SETTINGS  = 7350,
    IOP_ALPHA_PACKING_ADD_DD_SETTINGS   = 7351,

    /*------------------------------------------------------
    IOP for Alpha/Astro RFC RED/Factory tests
    ------------------------------------------------------*/
    IOP_RFC_TEST_RESET_FAILED_PKT_CNT   = 7352,
    IOP_RFC_TEST_ENBL_RAND_PAYLOAD      = 7353,
    IOP_RFC_TEST_PRINT_RSSI             = 7354,
    IOP_RFC_TEST_ENBL_LNA               = 7355,
    IOP_RFC_TEST_SETUP_CHIP_MODEM       = 7356,
    IOP_RFC_TEST_SWITCH_CHIP_MODEM      = 7357,
    IOP_RFC_TEST_SET_CHIP_SYNC_BITS     = 7358,
    IOP_RFC_TEST_GET_CHIP_SYNC_BITS     = 7359,
    IOP_RFC_TEST_CHIP_SETTINGS_START    = 7360,
    IOP_RFC_TEST_CHIP_SETTINGS_LOAD     = 7361,
    IOP_RFC_TEST_CHIP_SETTINGS_EXECUTE  = 7362,
    IOP_RFC_TEST_CHIP_SETTINGS_GET      = 7363,

    /*------------------------------------------------------
    IOP for Alpha/Astro Asset handling
    ------------------------------------------------------*/
    IOP_ALPHA_ASSET_STATUS_UPDATE       = 7364,
    IOP_ALPHA_REMOVE_ASSET              = 7365,
    IOP_ALPHA_REMOVE_ALL_ASSETS         = 7366,
    IOP_ALPHA_MESSAGE                   = 7367,
    IOP_ALPHA_ADD_ASSET                 = 7368,
    IOP_ALPHA_CONFIGURE_ASSET           = 7369,

    IOP_ALPHA_PACKING_END               = 7369,

    /*------------------------------------------------------
    Enable / Disable / Read internal power regulators
    ------------------------------------------------------*/
    IOP_PWR_REG_ENABLE                  = 7370,
    IOP_PWR_REG_DISABLE                 = 7371,
    IOP_PWR_REG_STATUS                  = 7372,

    /*------------------------------------------------------
    Same as IOP_LIGHT_DATA, but scaled by 10 to allow
    higher resolution near zero. Ex:
        100 = 10.%
        10  = 1.0%
        1   = 0.1%
        0   = 0.0%
    ------------------------------------------------------*/
    IOP_LIGHT_TENTHS_DATA               = 7373,

    /*------------------------------------------------------
    IOP for retrieving GPS firmware crc
    ------------------------------------------------------*/
    IOP_RMT_GPS_FLASH_CRC               = 7374,

    /*------------------------------------------------------
    RTC Test Support
    ------------------------------------------------------*/
    IOP_RTC_TEST_INST_START             = 7375,
    IOP_RTC_SET_ALARM                   = 7375, /*replies with IOP_RTC_ALARM_DATA of GRMN time alarm was set*/
    IOP_RTC_ALARM_TRIGGERED_TIME        = 7376, /*returns GRMN time of triggered alarm                      */
    IOP_RTC_ALARM_DATA                  = 7377, /*returns date_time_t32                                     */

    IOP_RTC_TEST_INST_END               = 7380,

    /*------------------------------------------------------
    Binary log playback
    ------------------------------------------------------*/
    IOP_BIN_LOG_PLAYBACK_START          = 7381,
    IOP_BIN_LOG_PLAYBACK_STATUS         = 7382,
    IOP_BIN_LOG_SET_SPORT               = 7385,

    /*------------------------------------------------------
    Hopper status (Response for IOP_HOPPER_STATUS)
    ------------------------------------------------------*/
    IOP_HOPPER_STATUS_RSLT              = 7386,

    /*------------------------------------------------------
    For Edge Reman Procedure
    ------------------------------------------------------*/
    IOP_HOLD_IN_LDR                     = 7387,

    /*------------------------------------------------------
    IOPs for build date/times of different stations stored
    in BIOS
    ------------------------------------------------------*/
    IOP_MANUF_SET_BUILD_DATE_TIME       = 7388, /* IOP_build_date_time_type */
    IOP_MANUF_GET_BUILD_DATE_TIME       = 7389, /* data: uint8 of station, response with IOP_build_date_time_type */

    /*------------------------------------------------------
    IOPs for swim library host-remote communication if swim library is built on remote
    ------------------------------------------------------*/
    IOP_SWM_START                               = 7390,
    IOP_SWM_HOST_TO_REMOTE_SWIM_INIT_ID         = 7390,
    IOP_SWM_HOST_TO_REMOTE_EVENT_ID             = 7391,
    IOP_SWM_HOST_TO_REMOTE_SWIM_DEINIT_ID       = 7392,
    IOP_SWM_REMOTE_TO_HOST_SWIM_UPDATE_ID       = 7393,
    IOP_SWM_REMOTE_TO_HOST_OWS_STROKE_RATE_ID   = 7394,
    IOP_SWM_HOST_TO_REMOTE_SWIM_RECOVERY_DATA1_ID= 7395,
    IOP_SWM_HOST_TO_REMOTE_SWIM_RECOVERY_DATA2_ID= 7396,
    IOP_SWM_REMOTE_TO_HOST_SWIM_RECOVERY_DATA1_ID= 7397,
    IOP_SWM_REMOTE_TO_HOST_SWIM_RECOVERY_DATA2_ID= 7398,

    IOP_SWM_END                                 = 7400,

    /*------------------------------------------------------
    Sensor hub error
    ------------------------------------------------------*/
    IOP_SENSOR_HUB_ERROR                = 7401,

    /*------------------------------------------------------
    Remote barometer
    ------------------------------------------------------*/
    IOP_REMOTE_BARO_START               = 7402, /* Marker */

    IOP_REMOTE_BARO_CONFIG              = 7402,
    IOP_REMOTE_BARO_ENABLE              = 7403,
    IOP_REMOTE_BARO_DATA                = 7404,
    IOP_REMOTE_BARO_ID_DATA             = 7405, /* HWM_baro_id_type */

    IOP_REMOTE_BARO_END                 = 7411, /* Marker */

    /*----------------------------------------------------------
    Health Sensing and Analytics Module
    ----------------------------------------------------------*/
    IOP_HSA_DATA_START                  = 7412, /* Marker */

    IOP_HSA_DATA_SENSOR_HUB             = 7412,
    IOP_HSA_DATA_USB                    = 7413,

    IOP_HSA_DATA_END                    = 7416, /* Marker */

    /*------------------------------------------------------
    Currently displayed passkey for pairing
    ------------------------------------------------------*/
    IOP_PAIRING_PASSKEY                 = 7417,

    /*------------------------------------------------------
    FIT LOG Start / Stop
    ------------------------------------------------------*/
    IOP_FIT_LOG_BEGIN                   = 7418,

    IOP_FIT_LOG_START                   = 7418, /* byte 0: FIT_debug_type_t8, bytes 1-16: fit_data */
    IOP_FIT_LOG_STOP                    = 7419, /* byte 0: FIT_debug_type_t8 */

    IOP_FIT_LOG_END                     = 7421,

    /*----------------------------------------------------------
    Vector Air Messages
    ----------------------------------------------------------*/
    IOP_VECTOR_AIR_INST_START           = 7422, /* marker */

    IOP_VECTOR_AIR_4HZ_SAMPLE           = 7422, /* Sensor sample - Legacy / equiv to 6956 */
    IOP_VECTOR_AIR_16HZ_SAMPLE          = 7423, /* Sensor sample - medium rate */
    IOP_VECTOR_AIR_64HZ_SAMPLE          = 7424, /* Sensor sample - high rate */
    IOP_VECTOR_AIR_EXTERN_SAMPLE        = 7425, /* External sample data */
    IOP_VECTOR_AIR_AERO_DATA            = 7426, /* Algorithm aero mode data output */
    IOP_VECTOR_AIR_PWR_DATA             = 7427, /* Algorithm power mode data output */
    IOP_VECTOR_AIR_PAIRING_DATA         = 7428, /* Vector Air sensor pairing data */
    IOP_VECTOR_AIR_CAL_DATA             = 7429, /* Vector Air MFG Cal data */
    IOP_VECTOR_AIR_CONFIG_DATA          = 7430, /* Vector Air configuration data */
    IOP_VECTOR_AIR_BATTERY_DATA         = 7431, /* Battery data */
    IOP_VECTOR_AIR_STATE_DATA           = 7432, /* Internal state data */
    IOP_VECTOR_AIR_64Hz_ACCUM_SAMPLE    = 7433, /* Accumulated 64Hz sample data: logging only */
    IOP_VECTOR_AIR_INST_END             = 7441, /* marker */

    /*----------------------------------------------------------
    Solar panel messages
    ----------------------------------------------------------*/
    IOP_SOLAR_PANEL_INST_START          = 7442,

    IOP_SOLAR_PANEL_CALIBRATION         = 7442,
    IOP_SOLAR_PANEL_CALIBRATION_SETUP   = 7443,

    IOP_SOLAR_PANEL_INST_END            = 7446,

    /*----------------------------------------------------------
    Bluetooth I2S loopback self-test result
    ----------------------------------------------------------*/
    IOP_BT_LOOPBACK_SELFTEST_RESULT     = 7447,

    /*------------------------------------------------------
    Layout for the current page
    ------------------------------------------------------*/
    IOP_PAGE_LAYOUT                     = 7448,

    /*------------------------------------------------------
    Inductive Keys
    ------------------------------------------------------*/
    IOP_INDUCTIVE_KEY_INST_START        = 7449,

    IOP_INDUCTIVE_KEY_RAW_VALUES        = 7449,
    IOP_INDUCTIVE_KEY_MAX_VALUES        = 7450,
    IOP_INDUCTIVE_KEY_PRESSES           = 7451,

    IOP_INDUCTIVE_KEY_INST_END          = 7453,

    /*------------------------------------------------------
    IOP for IAQ sensor error
    ------------------------------------------------------*/
    IOP_IAQ_SENSOR_ERROR                = 7454, /* IAQ forwarding a sensor error */

    /*------------------------------------------------------
    CSD and extended CSD register access (register definitions available
    in JEDEC eMMC and SD card standards)
    The format for these should be:
    PC: IOP_MMC_READ_(EXT_)CSD <device-specifier> <start-slice> <end-slice>
    DUT: IOP_MMC_READ_(EXT_)CSD <device-specifier> <data>
    @param device-specifier (uint16_t) which SD/eMMC device to select
    @param start-slice (uint16_t) the offset to start reading from
    @param end-slice (uint16_t) the offset to read through (inclusive)
    @param data the data contained in the fields from start-slice thru end-slice
    ------------------------------------------------------*/
    IOP_MMC_READ_CSD                    = 7455,
    IOP_MMC_READ_EXT_CSD                = 7456,

    /*------------------------------------------------------
    Passive InfraRed Sensor Instrumentation ID group
    ------------------------------------------------------*/
    IOP_PIR_INST_START                  = 7457,
    IOP_PIR_INST_RAW                    = 7457, /*sint16*/
    IOP_PIR_INST_TRIGGER                = 7458, /*sint16*/
    IOP_PIR_INST_END                    = 7467,

    /*------------------------------------------------------
    Device Serial Number
    This is a combination of 8 to 9 letters or numbers,
    without spaces or dashes externally printed on a device.
    ------------------------------------------------------*/
    IOP_SERIAL_NUMBER_DATA              = 7468,

    /*------------------------------------------------------
    IO remote master/slave ID
    ------------------------------------------------------*/
    IOP_IO_REMOTE_GPIO_EXPANDER         = 7469,

    /*------------------------------------------------------
    SIQ - Sensor-IQ
    ------------------------------------------------------*/
    IOP_SIQ_START                       = 7470, /* Marker */

    IOP_SIQ_APP_PRELOAD_ADDRESS         = 7470, /* Start address of a preloaded app */
    IOP_SIQ_LOG_DATA                    = 7471, /* Data from SIQ data router to be logged */

    IOP_SIQ_END                         = 7479, /* Marker */

    /*------------------------------------------------------
    Vibration test automation command
    Triggers a periodic vibration test
    ------------------------------------------------------*/
    IOP_VIB_TEST_PERIODIC               = 7480,

    /*------------------------------------------------------
    UMM (User Metrics Manager) Module
    ------------------------------------------------------*/
    IOP_UMM_INST_START                  = 7481, /* Marker */

    IOP_UMM_TLV_DATA                    = 7481, /* TLV payload */

    IOP_UMM_INST_END                    = 7488, /* Marker */

    /*------------------------------------------------------
    Wireless Certification and Testing
    gerrit.consumer.garmin.com
    technology/communications/wireless-certification-testing
    ------------------------------------------------------*/
    IOP_WCT_INST_START                  = 7489, /* first WCT ID (inclusive) */

    IOP_WCT_REQUEST                     = 7489, /* Request */
    IOP_WCT_REPLY                       = 7490, /* Reply to request */

    IOP_WCT_INST_END                    = 7499, /* last WCT ID (inclusive) */

    /*------------------------------------------------------
    Manufacturing commands for maxim 8617x AFEs
    ------------------------------------------------------*/
    IOP_MAX_8617X_MANUF_START              = 7500,

    IOP_MAX_8617X_MANUF_BIST_RESP          = 7500,
    IOP_MAX_8617X_MANUF_CURRENT_RESP       = 7501,
    IOP_MAX_8617X_MANUF_LED_RESP           = 7502,
    IOP_MAX_8617X_MANUF_PD_RESP            = 7503,
    IOP_MAX_8617X_MANUF_REFLECTED_RESP_STD = 7504,
    IOP_MAX_8617X_MANUF_SET_LED_UA         = 7505,
    IOP_MAX_8617X_MANUF_SET_LED_UA_RESP    = 7506,
    IOP_MAX_8617X_ILP_RESP                 = 7507,
    IOP_MAX_8617X_MANUF_SET_FSP2           = 7508,
    IOP_MAX_8617X_MANUF_SET_LED_CW         = 7509,
    IOP_MAX_8617X_MANUF_SET_LED_CW_RESP    = 7510,
    IOP_MAX_8617X_MANUF_DAC_CAL_RESP       = 7511,
    IOP_MAX_8617X_MANUF_CTR_CAL_RESP       = 7512,
    IOP_MAX_8617X_MANUF_CTR_CAL_RATIO      = 7513,

    IOP_MAX_8617X_MANUF_END                = 7525,

    /*------------------------------------------------------
    Profiler
    ------------------------------------------------------*/
    IOP_PFL_START                       = 7526, /* Marker */

    IOP_PFL_DATA_MSG                    = 7526, /* Profiler output message */

    IOP_PFL_END                         = 7529, /* Marker */

    /*------------------------------------------------------
    Gyroscope self-test result.
    -----------------------------------------------------*/
    IOP_GYRO_DATA_SELF_TEST_RESULT     = 7530,

    /*------------------------------------------------------
    Alpha-specific instrumentation range 2
    ------------------------------------------------------*/
    IOP_ALPHA_INST2_START               = 7531,
    IOP_ALPHA_PROTOCOL_DATA             = 7531,
    IOP_ALPHA_SEND_CONTROL_PACKET       = 7532,
    IOP_ALPHA_SEND_TDMA_INST            = 7533,
    IOP_ALPHA_CCA_DATA                  = 7534,
    IOP_ALPHA_TDMA_REQUEST_WINDOW       = 7535,
    IOP_ALPHA_TDMA_CALLBACK_DATA        = 7536,
    IOP_ALPHA_INST2_END                 = 7540,

    /*------------------------------------------------------
    Touchscreen Controller instructions (cont.)
    ------------------------------------------------------*/
    IOP_TSC_NORMALIZATION_FACTOR_CMND   = 7541,
    IOP_TSC_NORMALIZATION_FACTOR_RSLT   = 7542,
    IOP_TSC_NOTIFICATION_CHANGE_REQ     = 7543, /* Prohibit/Allow sending of touch screen notifications request */
    IOP_TSC_NOTIFICATION_CHANGE_RSP     = 7544, /* Prohibit/Allow sending of touch screen notifications response */

    IOP_TSC_CTRL_INST_END               = 7550,


    /*------------------------------------------------------
    Commit ID query
    ------------------------------------------------------*/
    IOP_COMMIT_ID_RQST                  = 7551,
    IOP_COMMIT_ID_DATA                  = 7552,

    /*------------------------------------------------------
    MCU-based PND mount
    ------------------------------------------------------*/
    IOP_MCU_MOUNT_REQUEST               = 7553,
    IOP_MCU_MOUNT_RESPONSE              = 7554,

    /*------------------------------------------------------
    Generalized DLP display interface
    ------------------------------------------------------*/
    IOP_DLP_INST_START                  = 7555, /* Marker */
    IOP_DLP_INST_READ                   = 7555,
    IOP_DLP_INST_WRITE                  = 7556,
    IOP_DLP_INST_SET_OFFSET             = 7557,
    IOP_DLP_INST_OFFSET_DATA            = 7558,
    IOP_DLP_INST_SET_BRIGHT_LEVEL       = 7559,
    IOP_DLP_INST_VLED                   = 7560,
    IOP_DLP_INST_START_TEST_PTRN_GEN    = 7561,
    IOP_DLP_INST_SFLASH_BUILD_VER_DATA  = 7562,
    IOP_DLP_INST_BIST_RESULT            = 7563,
    IOP_DLP_INST_SET_WHITE_BAL          = 7564,
    IOP_DLP_INST_SET_BRIGHTNESS_HW      = 7565,
    IOP_DLP_INST_SET_FOV_TEST_PAGE      = 7566,
    IOP_DLP_INST_DISABLE_TIMEOUT        = 7567,
    IOP_DLP_INST_END                    = 7570, /* Marker */

    /*------------------------------------------------------
    Response for auto burn in mode configuration request
    ------------------------------------------------------*/
    IOP_AUTO_BURN_IN_RESPONSE           = 7571,

    /*------------------------------------------------------
    hwm-core backlight and auto-backlight control msg
    ------------------------------------------------------*/
    IOP_AUTO_BACKLIGHT_MSG              = 7572,
    IOP_BACKLIGHT_MSG                   = 7573,

    /*------------------------------------------------------
    Trail Camera specific IOPs
    ------------------------------------------------------*/
    IOP_INST_TRAIL_CAM_START            = 7574,
    IOP_INST_TRAIL_CAM_SET_PIR_THRESH   = 7574, /*0-255, 1 byte */
    IOP_INST_TRAIL_CAM_SET_FILTER_MODE  = 7575, /*0=NBP, 1=VISIBLE, 2=AUTO*/
    IOP_INST_TRAIL_CAM_SET_FILTER_THRESH= 7576, /*uint16=ALS Low, uint16=ALS High*/
    IOP_INST_TRAIL_CAM_GET_FILTER_MODE  = 7577,
    IOP_INST_TRAIL_CAM_SET_PIR_ENABLED  = 7578, /*See STGS module */
    IOP_INST_TRAIL_CAM_GET_NIGHT_DAY    = 7579, /*0 = Night, 1 = Day */
    IOP_INST_TRAIL_CAM_SET_TRIGGER_DELAYS = 7580, /*uint16 night seconds, uint16 day seconds */
    IOP_INST_TRAIL_CAM_GET_TRIGGER_MODE = 7581, /*see hwm_trigger_mngr_state*/
    IOP_INST_TRAIL_CAM_SET_FIELD_SCAN   = 7582,
    IOP_INST_TRAIL_CAM_SHUTDOWN_CAUSE   = 7583, /* see AMBA_REF_POWER_OFF_REASON_e */

    IOP_INST_TRAIL_CAM_END              = 7584,

    /*------------------------------------------------------
    hwm-core vibe proxy control msg
    ------------------------------------------------------*/
    IOP_VIB_DRVPROXY_MSG                = 7585,

    /*------------------------------------------------------
    Reserve IOPs for I/O testing of USB ports.
    Command & response format:
    PC: IOP_USB_START_PORT_IO_TEST <usb-port>
    DUT: IOP_USB_PORT_IO_TEST_RESPONSE <usb-port> <completion-status>
    @param usb-port (uint8_t) zero based index of usb port to test
    @param completion-status (uint8_t) test passed if non-zero
    ------------------------------------------------------*/
    IOP_USB_START_PORT_IO_TEST          = 7586,
    IOP_USB_PORT_IO_TEST_RESPONSE       = 7587,

    /*------------------------------------------------------
    Debug interface into the BTM module for test stats and
    control, see https://confluence.garmin.com/x/shGxF
    ------------------------------------------------------*/
    IOP_BTM_DEBUG                       = 7588,

    /*------------------------------------------------------
    Extended baro data. Similar to IOP_BARO_DATA but with ID
    info so multiple baros can be sent with the same IOP.
    ------------------------------------------------------*/
    IOP_BARO_DATA_EXT                   = 7589,

    /*------------------------------------------------------
    BLE Beacon IOPs
    ------------------------------------------------------*/
    IOP_BEACON_INST_START               = 7590,
    IOP_BEACON_INST_ENABLE              = 7590,
    IOP_BEACON_INST_END                 = 7594,

    /*------------------------------------------------------
    Reserve IOPs for setting and monitoring the speed of the
    fan in the head unit.
    Command & response format:
    PC: IOP_SET_FAN_DUTY_CYCLE <duty-cycle>
    DUT: IOP_SET_FAN_DUTY_CYCLE <duty-cycle> <completion-status>
    PC: IOP_GET_FAN_RPM
    DUT: IOP_GET_FAN_RPM <rpm>
    @param duty-cycle (uint8_t) expressed as a percent
        0 = fan off, 100 = full speed
        0xFF = enable DUT to resume control of the fan
    @param completion-status (uint8_t) IOP successful if non-zero
    @param rpm (uint16_t) current fan speed in rpm
    ------------------------------------------------------*/
    IOP_SET_FAN_DUTY_CYCLE              = 7595,
    IOP_GET_FAN_RPM                     = 7596,

    /*------------------------------------------------------
    Sensor Axes Standard Deviation Test IOPs
    ------------------------------------------------------*/
    IOP_SENSOR_NOISE_TEST_START         = 7597,
    IOP_SENSOR_NOISE_TEST_DATA          = 7598,

    /*------------------------------------------------------
    SiriusXM IOPs
    ------------------------------------------------------*/
    IOP_SXM_INST_START                  = 7599, /* Marker */

    IOP_SXM_REQUEST                     = 7599,
    IOP_SXM_RESULT                      = 7600,
    IOP_SXM_FAILURE                     = 7601,

    IOP_SXM_INST_END                    = 7601, /* Marker */

    /*------------------------------------------------------
    Connect IQ Developer Console Message
    ------------------------------------------------------*/
    IOP_CIQ_CONSOLE_MESSAGE             = 7602,

    /*------------------------------------------------------
    Approach radar message
    Detail for this message type can be found at:
    https://confluence.garmin.com/display/OUTDOOR/Approach+R10%3A+Board-level+test+IOP+commands
    ------------------------------------------------------*/
    IOP_APPROACH_RADAR_MESSAGE          = 7603,

    /*------------------------------------------------------
    SPI IOP Time Synchronization
    ------------------------------------------------------*/
    IOP_SPI_IOP_TIMESYNC_START          = 7604,
    IOP_SPI_IOP_TIMESYNC_RESULT         = 7605,

    /*------------------------------------------------------
    A generic IOP for uploading data to a product
    ------------------------------------------------------*/
    IOP_DATA_UPLOAD                     = 7606,

    /*------------------------------------------------------
    Information to be used by Firstbeat recovery calculations
    ------------------------------------------------------*/
    IOP_FIRSTBEAT_GRADIENT_SUM          = 7607,

    /*------------------------------------------------------
    Battery pack serial number
    ------------------------------------------------------*/
    IOP_BATTERY_PACK_ID_DATA            = 7608,

    /*------------------------------------------------------
    USB peripheral ID query (VID/PID of attached USB periphs)
    ------------------------------------------------------*/
    IOP_USB_PERIPHERAL_ID               = 7609,

    /*------------------------------------------------------
    Forcibly remount a partition
    ------------------------------------------------------*/
    IOP_REMOUNT_PARTITION               = 7610,

    /*------------------------------------------------------
    Pull high/low specific GPIO to test load switch elements
    ------------------------------------------------------*/
    IOP_LOAD_SWITCH_EN_TEST             = 7611,

    /*------------------------------------------------------
    Pull high/low specific GPIO to test 26MHz output clock synthesizer
    ------------------------------------------------------*/
    IOP_CLK_SYNTH_26MHZ_EN_TEST         = 7612,

    /*------------------------------------------------------
    USB-C Power Delivery
    ------------------------------------------------------*/
    IOP_USB_TYPEC_START                 = 7613,
    IOP_USB_TYPEC_SNK_PWR_DLVRY_DATA    = 7613,
    IOP_USB_TYPEC_END                   = 7618,

    /*------------------------------------------------------
    Ethernet MAC with Most Significant Byte first
    ------------------------------------------------------*/
    IOP_NET_MAC_ADDR_DATA_MSB           = 7619,

    /*------------------------------------------------------
    Debug interface into the BTF module for test stats and
    control, see https://confluence.garmin.com/x/shGxF
    ------------------------------------------------------*/
    IOP_BTF_DEBUG                       = 7620,


    /*------------------------------------------------------
    GPS Total Isotropic Sensitivity test data
    ------------------------------------------------------*/
    IOP_GPS_TIS_DATA                    = 7621,

    /*------------------------------------------------------
    What hardware variant (final element of HW GPNs) the
    unit is
    ------------------------------------------------------*/
    IOP_HW_VARIANT_DATA                 = 7622,

    /*------------------------------------------------------
    Set what the unit's hardware variant (final element of
    HW GPNs) is
    ------------------------------------------------------*/
    IOP_SET_HW_VARIANT                  = 7623,

    /*------------------------------------------------------
    IOP for RFC Audio
    ------------------------------------------------------*/
    IOP_RFC_AUD_START                   = 7624,

    IOP_RFC_AUD_CALLID_UPDATE           = 7624,
    IOP_RFC_AUD_AUDIO_ACTIVE            = 7625,
    IOP_RFC_AUD_VOL_UPDATE              = 7626,

    IOP_RFC_AUD_AUDIO_DATA              = 7627,
    IOP_RFC_AUD_AUDIO_DATA_ACTIVE       = 7628,

    IOP_RFC_AUD_SET_PATH                = 7629,
    IOP_RFC_AUD_AUDIO_AVAILABLE         = 7630,
    IOP_RFC_AUD_SET_ROGER_TONE          = 7631,

    IOP_RFC_AUD_END                     = 7634,

    /*------------------------------------------------------
    Build information about the software consuming this IOP
    ------------------------------------------------------*/
    IOP_SW_BUILD_DESCRIPTION            = 7635,

    /*----------------------------------------------------------
    Bike Aero Sensor Messages
    ----------------------------------------------------------*/
    IOP_BIKE_AERO_INST_START           = 7636, /* marker */

    IOP_BIKE_AERO_BARO_SAMPLE          = 7636, /* Sensor raw data */
    IOP_BIKE_AERO_WIND_SAMPLE          = 7637, /* Sensor raw data */
    IOP_BIKE_AERO_IMU_SAMPLE           = 7638, /* Sensor raw data */
    IOP_BIKE_AERO_SPEED_SAMPLE         = 7639, /* External spd sensor sample data */
    IOP_BIKE_AERO_POWER_SAMPLE         = 7640, /* External pwr sensor sample data */
    IOP_BIKE_AERO_AERO_DATA            = 7641, /* Algorithm aero mode data output */
    IOP_BIKE_AERO_PWR_DATA             = 7642, /* Algorithm power mode data output */
    IOP_BIKE_AERO_PAIRING_DATA         = 7643, /* external sensor pairing data */
    IOP_BIKE_AERO_AIR_CAL_DATA         = 7644, /* Vector Air MFG Cal data */
    IOP_BIKE_AERO_CONFIG_DATA          = 7645, /* Vector Air configuration data */
    IOP_BIKE_AERO_BATTERY_DATA         = 7646, /* Battery data */
    IOP_BIKE_AERO_STATE_DATA           = 7647, /* Internal state data */
    IOP_BIKE_AERO_INST_END             = 7655, /* marker */

    /*------------------------------------------------------
    IOP to specify which IOP insts to allow on BLE pipe
    ------------------------------------------------------*/
    IOP_COMM_BLE_FILTER_CONFIG         = 7656,

    /*------------------------------------------------------
    RSSI reported from radio
    ------------------------------------------------------*/
    IOP_RFC_RSSI_DATA                  = 7657,

    /*------------------------------------------------------
    File transfer IOP insts
    ------------------------------------------------------*/
    IOP_FILE_TRANSFER_START            = 7658, /* Begin file transfer */
    IOP_FILE_TRANSFER_STATUS           = 7659, /* Status of file transfer */
    IOP_FILE_TRANSFER_DATA             = 7660, /* File tranfer data packet */
    IOP_FILE_TRANSFER_STOP             = 7661, /* End file transfer */

    IOP_FILE_TRANSFER_END              = 7663, /* marker */

    /*------------------------------------------------------
    Skipper automated testing
    ------------------------------------------------------*/
    IOP_SKIPPER_START                  = 7664, /* marker */
    IOP_SKIPPER_CONFIG                 = 7664,
    IOP_SKIPPER_STATUS                 = 7665,
    IOP_SKIPPER_END                    = 7669, /* marker */

    /*------------------------------------------------------
    Debug interface into Blueooth Classic for test stats and
    control, see https://confluence.garmin.com/x/shGxF
    ------------------------------------------------------*/
    IOP_BLUETOOTH_CLASSIC_DEBUG        = 7671,

    /*------------------------------------------------------
    Alpha dog/contact tracking RFC module
    ------------------------------------------------------*/
    IOP_RFC_INST_START                 = 7672, /* marker */
    IOP_RFC_AUTO_CALIBRATE_POWER       = 7672,
    IOP_RFC_POWER_CAL_DATA             = 7673,
    IOP_RFC_FINAL_PA_BIAS_CURRENT_DATA = 7674,
    IOP_RFC_WAYPOINT                   = 7675, /* shared location/waypoint message */
    IOP_RFC_ALPHA_NEW_ASSET            = 7676,

    IOP_RFC_INST_END                   = 7685, /* marker */

    /*------------------------------------------------------
    Additional IDs reserved for GPS IOP extensions
    -----------------------------------------------------*/
    IOP_GPS_GENERIC_START_2            = 7686,
    IOP_GPS_BIAS_SETTINGS_CHECK        = 7686,
    IOP_GPS_BIAS_GPN_DATA              = 7687,
    IOP_GPS_GENERIC_RSRVD_10           = 7688,
    IOP_GPS_GENERIC_RSRVD_11           = 7689,
    IOP_GPS_GENERIC_RSRVD_12           = 7690,
    IOP_GPS_GENERIC_RSRVD_13           = 7691,
    IOP_GPS_GENERIC_RSRVD_14           = 7692,
    IOP_GPS_GENERIC_RSRVD_15           = 7693,
    IOP_GPS_GENERIC_RSRVD_16           = 7694,
    IOP_GPS_GENERIC_RSRVD_17           = 7695,
    IOP_GPS_GENERIC_END_2              = 7695,

    /*------------------------------------------------------
    RTC Calibration
    Note: Get calibration is in IOP_pub_cmnd.h
    ------------------------------------------------------*/
    IOP_RTC_SET_CAL_FREQUENCY          = 7696,
    IOP_RTC_GET_CAL_FREQUENCY_RESPONSE = 7697,

    /*------------------------------------------------------
    Memory stats
    ------------------------------------------------------*/
    IOP_MEMORY_STATS                   = 7698,

    /*------------------------------------------------------
    Biometrics module ECG data
    ------------------------------------------------------*/
    IOP_BMX_ECG_DATA                   = 7699,

    /*------------------------------------------------------
    Handsfree BTNS commands
    ------------------------------------------------------*/
    IOP_HFP_INST_START                 = 7700, /* marker */
    IOP_HFP_START_VOICE_ASST           = 7700,
    IOP_HFP_STOP_VOICE_ASST            = 7701,
    IOP_HFP_DIAL_NUMBER                = 7702,
    IOP_HFP_ANSWER                     = 7703,
    IOP_HFP_HANGUP                     = 7704,
    IOP_HFP_TRANSMIT_DTMF              = 7705,
    IOP_HFP_CONNECT_TO_AG              = 7706,
    IOP_HFP_DISCONNECT                 = 7707,
    IOP_HFP_GET_FEATURES               = 7708,
    IOP_HFP_ENABLE_AUDIO               = 7709,
    IOP_HFP_DISABLE_AUDIO              = 7710,
    IOP_HFP_TRANSFER_AUDIO_TO_AG       = 7711,
    IOP_HFP_ANSWER_CALL_WAITING        = 7712,
    IOP_HFP_REJECT_CALL_WAITING        = 7713,
    IOP_HFP_MERGE_CALL                 = 7714,
    IOP_HFP_INST_END                   = 7720, /* marker */

    /*------------------------------------------------------
    Trail Camera specific IOPs, part 2
    ------------------------------------------------------*/
    IOP_INST_TRAIL_CAM2_START          = 7721,
    IOP_INST_TRAIL_CAM2_END            = 7731,

    /*------------------------------------------------------
    Start of next instrumentation ID group.
    ------------------------------------------------------*/
    IOP_START_OF_NEXT                  = 7732,

    /*------------------------------------------------------
    Invalid instrumentation ID.
    ------------------------------------------------------*/
    IOP_INV_INST_ID                    = 0xFFFF
    };

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
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif  /* IOP_PUB_INST_H */
