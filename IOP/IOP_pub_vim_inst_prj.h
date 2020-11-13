/*********************************************************************
*
*   HEADER NAME:
*       IOP_pub_vim_inst_prj.h - VIM packet specific declarations
*
* Copyright 2015 by Garmin Ltd. or its subsidiaries.
*********************************************************************/


#ifndef IOP_PUB_VIM_INST_PRJ_H
#define IOP_PUB_VIM_INST_PRJ_H

#if defined( __cplusplus )
extern "C"
{
#endif

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                          LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define IOP_VIM_COMM_INST_ID_MSB_POS    (2)
#define IOP_VIM_COMM_INST_ID_LSB_POS    (3)
#define IOP_VIM_COMM_SUB_ID_MSB_POS     (6)
#define IOP_VIM_COMM_SUB_ID_LSB_POS     (7)
#define IOP_VIM_COMM_CASE_ID_MSB_POS    (8)
#define IOP_VIM_COMM_CASE_ID_LSB_POS    (9)
#define IOP_VIM_COMM_DATA_POS           (IOP_VIM_COMM_CASE_ID_LSB_POS + 1)

#define IOP_VIM_CAN_MSG_UPDT_FLAG_POS   (14)
#define IOP_VIM_CAN_SIG_UPDT_FLAG_POS   (4)
#define IOP_VIM_CAN_MSG_TX_FLAG_POS     (6)
#define IOP_VIM_CAN_MSG_RQST_FLAG_POS   (6)
#define IOP_VIM_CAN_SIG_RQST_FLAG_POS   (4)
#define IOP_VIM_CAN_SIG_UPDT_DATA_POS   (5)

/*--------------------------------------------------------------------
                                TYPES
--------------------------------------------------------------------*/
/*--------------------------------------------------------------------
                                 TYPES
--------------------------------------------------------------------*/

typedef enum tagIOP_VIM_CMD_PKT_ID_TYPE     //!< IOP VIM command packet sub ID definitions
    {
    IOP_VIM_PKT_RESERVED_CMD            , /* 0x0000  */
    IOP_VIM_PKT_COMM_CTRL_CMD           , /* 0x0001  */
    IOP_VIM_PKT_GSM_PWR_CMD             , /* 0x0002  */
    IOP_VIM_PKT_HU_PWR_CMD              , /* 0x0003  */
    IOP_VIM_PKT_LOW_PWR_CMD             , /* 0x0004  */
    IOP_VIM_PKT_SHUT_DOWN_CMD           , /* 0x0005  */
    IOP_VIM_PKT_SYS_RESET_CMD           , /* 0x0006  */
    IOP_VIM_PKT_XFER_TO_BB_CMD          , /* 0x0007  */
    IOP_VIM_PKT_SW_VER_CMD              , /* 0x0008  */
    IOP_VIM_PKT_VEH_DOOR_LOCK_CMD       , /* 0x0009  */
    IOP_VIM_PKT_CAN_MSG_RQST_CMD        , /* 0x000A  */
    IOP_VIM_PKT_CAN_SIG_RQST_CMD        , /* 0x000B  */
    IOP_VIM_PKT_CAN_MSG_UPDT_CMD        , /* 0x000C  */
    IOP_VIM_PKT_CAN_SIG_UPDT_CMD        , /* 0x000D  */
    IOP_VIM_PKT_CAN_MSG_TX_CMD          , /* 0x000E  */
    IOP_VIM_PKT_PASS_THRU_CMD           , /* 0x000F  */
    IOP_VIM_PKT_CHK_SUM_RGN_CMD         , /* 0x0010  */
    IOP_VIM_PKT_FULL_SW_UPDT_CMD        , /* 0x0011  */
    IOP_VIM_PKT_NVM_ERASE_CMD           , /* 0x0012  */
    IOP_VIM_PKT_AMP_CTRL_CMD            , /* 0x0013  */
    IOP_VIM_PKT_SW_VER_DATA             , /* 0x0014  */
    IOP_VIM_PKT_VIM_WKUP_SRC_DATA       , /* 0x0015  */
    IOP_VIM_PKT_DIG_IO_STATUS_DATA      , /* 0x0016  */
    IOP_VIM_PKT_CAN_MSG_DATA            , /* 0x0017  */
    IOP_VIM_PKT_CAN_SIG_DATA            , /* 0x0018  */
    IOP_VIM_PKT_VEH_DOOR_LOCK_DATA      , /* 0x0019  */
    IOP_VIM_PKT_VEH_IGN_KEY_DATA        , /* 0x001A  */
    IOP_VIM_PKT_CHK_SUM_RGN_DATA        , /* 0x001B  */
    IOP_VIM_PKT_FAULT_CODE              , /* 0x001C  */
    IOP_VIM_PKT_PASS_THRU_DATA          , /* 0x001D  */
    IOP_VIM_PKT_GYRO_MEAS_DATA          , /* 0x001E  */
    IOP_VIM_PKT_GYRO_TEMP_DATA          , /* 0x001F  */
    IOP_VIM_PKT_ODOM_MEAS_DATA          , /* 0x0020  */
    IOP_VIM_PKT_CD_PWR_CMD              , /* 0x0021  */
    IOP_VIM_PKT_CD_CTRL_CMD             , /* 0x0022  */
    IOP_VIM_PKT_INT_TEMP_DATA           , /* 0x0023  */
    IOP_VIM_PKT_TIME_SYNC_RQST_CMD      , /* 0x0024  */
    IOP_VIM_PKT_TIME_SYNC_DATA          , /* 0x0025  */
    IOP_VIM_PKT_ADC_CNT_CMD             , /* 0x0026  */
    IOP_VIM_PKT_AUD_ADC_DATA            , /* 0x0027  */
    IOP_VIM_PKT_BT_ADC_DATA             , /* 0x0028  */
    IOP_VIM_PKT_HU_FACTORY_PWR_OFF_CMD  , /* 0x0029  */
    IOP_VIM_PKT_DR_BUF_RQST_CMD         , /* 0x002A  */
    IOP_VIM_PKT_GYRO_BUF_RQST_DATA      , /* 0x002B  */
    IOP_VIM_PKT_ODOM_BUF_RQST_DATA      , /* 0x002C  */
    IOP_VIM_PKT_CD_PWR_GOOD_DATA        , /* 0x002D  */
    IOP_VIM_PKT_STNDBY_TIME_CMD         , /* 0x002E  */
    IOP_VIM_PKT_BATT_VOLT_DATA          , /* 0x002F  */
    IOP_VIM_PKT_BB_VER_CMD              , /* 0x0030  */
    IOP_VIM_PKT_BB_VER_DATA             , /* 0x0031  */
    IOP_VIM_PKT_GDR_CMD                 , /* 0x0032  */
    IOP_VIM_PKT_GDR_DATA                , /* 0x0033  */
    IOP_VIM_PKT_HU_UART_TEST_CMD        , /* 0x0034  */
    IOP_VIM_PKT_HU_UART_TEST_DATA       , /* 0x0035  */
    IOP_VIM_PKT_ADC_KEY_TBL_CMD         , /* 0x0036  */
    IOP_VIM_PKT_C5_0x21F_DATA           , /* 0x0037  */
    IOP_VIM_PKT_C5_0x0A2_DATA           , /* 0x0038  */
    IOP_VIM_PKT_C5_0x018_DATA           , /* 0x0039  */
    IOP_VIM_PKT_AIR_CONDITION_DATA      , /* 0x003A  */
    IOP_VIM_PKT_GEAR_DATA               , /* 0x003B  */
    IOP_VIM_PKT_GEAR_M_MODE_STATUS_DATA , /* 0x003C  */
    IOP_VIM_PKT_GEAR_M_MODE_ENABLE_DATA , /* 0x003D  */
    IOP_VIM_PKT_ACC_STATUS_DATA         , /* 0x003E  */
    IOP_VIM_PKT_BRAKE_STATUS_DATA       , /* 0x003F  */
    IOP_VIM_PKT_DRIVER_INFO_DATA        , /* 0x0040  */
    IOP_VIM_PKT_TPMS_CMD                , /* 0x0041  */
    IOP_VIM_PKT_TPMS_DATA               , /* 0x0042  */
    IOP_VIM_PKT_HUD_CMD                 , /* 0x0043  */
    IOP_VIM_PKT_HUD_DATA                , /* 0x0044  */
    IOP_VIM_PKT_PLDS_CMD                , /* 0x0045  */
    IOP_VIM_PKT_PLDS_DATA               , /* 0x0046  */
    IOP_VIM_PKT_HU_UART2_TEST_CMD       , /* 0x0047  */
    IOP_VIM_PKT_HU_UART2_TEST_DATA      , /* 0x0048  */
    IOP_VIM_PKT_AMP_MUTE_S_CMD          , /* 0x0049  */
    IOP_VIM_PKT_SWC_TOLERANCE_CMD       , /* 0x004A  */
    IOP_VIM_PKT_GPIO_CMD                , /* 0x004B  */
    IOP_VIM_PKT_VIDEO_AUDIO_SWITCH_CMD  , /* 0x004C  */
    IOP_VIM_PKT_VIDEO_AUDIO_SWITCH_DATA , /* 0x004D  */
    IOP_VIM_PKT_VCOM_CMD                , /* 0x004E  */
    IOP_VIM_PKT_VCOM_DATA               , /* 0x004F  */
    IOP_VIM_PKT_RADIO_TUNER_CMD         , /* 0x0050  */
    IOP_VIM_PKT_RADIO_TUNER_DATA        , /* 0x0051  */
    IOP_VIM_PKT_TW8836_SWITCH_SRC_CMD   , /* 0x0052  */
    IOP_VIM_PKT_TW8836_SWITCH_SRC_DATA  , /* 0x0053  */
    IOP_VIM_PKT_ADC_CHANNEL_CMD         , /* 0x0054  */
    IOP_VIM_PKT_ADC_CHANNEL_DATA        , /* 0x0055  */
    IOP_VIM_PKT_NVM_WRITE_CMD           , /* 0x0056  */
    IOP_VIM_PKT_NVM_READ_CMD            , /* 0x0057  */
    IOP_VIM_PKT_NVM_READ_DATA           , /* 0x0058  */
    IOP_VIM_PKT_AUDIO_SRC_CHANGE_CMD    , /* 0x0059  */
    IOP_VIM_PKT_AUDIO_SRC_DATA          , /* 0x005A  */
    IOP_VIM_PKT_AUDIO_VOLUME_CMD        , /* 0x005B  */
    IOP_VIM_PKT_AUDIO_LOUDNESS_CMD      , /* 0x005C  */
    IOP_VIM_PKT_AUDIO_EQ_CMD            , /* 0x005D  */
    IOP_VIM_PKT_AUDIO_HPF_CMD           , /* 0x005E  */
    IOP_VIM_PKT_AUDIO_LPF_CMD           , /* 0x005F  */
    IOP_VIM_PKT_AUDIO_BALANCE_CMD       , /* 0x0060  */
    IOP_VIM_PKT_PWM_OUTPUT_CMD          , /* 0x0061  */
    IOP_VIM_PKT_PWM_INPUT_CMD           , /* 0x0062  */
    IOP_VIM_PKT_PWM_INPUT_DATA_CMD      , /* 0x0063  */
    IOP_VIM_PKT_QUERY_CMD               , /* 0x0064  */
    IOP_VIM_PKT_DVD_CMD                 , /* 0x0065  */
    IOP_VIM_PKT_DVD_DATA                , /* 0x0066  */
    IOP_VIM_PKT_FAULT_CODE_CMD          , /* 0x0067  */
    IOP_VIM_PKT_CAN_PASS_THRU_CMD       , /* 0x0068  */
    IOP_VIM_PKT_AUDIO_QUERY_DATA        , /* 0x0069  */
    IOP_VIM_PKT_GPIO_MANUAL_CMD         , /* 0x006A  */
    IOP_VIM_PKT_TW8836_ADC_DATA         , /* 0x006B  */
    IOP_VIM_PKT_DB_CHECKSUM_CMD         , /* 0x006C  */
    IOP_VIM_PKT_DB_CHECKSUM_DATA        , /* 0x006D  */
    IOP_VIM_PKT_DB_EXEC_CMD             , /* 0x006E  */
    IOP_VIM_PKT_DB_EXEC_DATA            , /* 0x006F  */
    IOP_VIM_PKT_CAN_MSG_TBL_CMD         , /* 0x0070  */
    IOP_VIM_PKT_CAN_MSG_TBL_DATA        , /* 0x0071  */
    IOP_VIM_PKT_CAN_SIG_TBL_CMD         , /* 0x0072  */
    IOP_VIM_PKT_CAN_SIG_TBL_DATA        , /* 0x0073  */
    IOP_VIM_PKT_CAN_EVT_TBL_CMD         , /* 0x0074  */
    IOP_VIM_PKT_CAN_EVT_TBL_DATA        , /* 0x0075  */
    IOP_VIM_PKT_ADC_KEY_TBL_DATA        , /* 0x0076  */
    IOP_VIM_PKT_DVD_QUERY_DATA          , /* 0x0077  */
    IOP_VIM_PKT_EXPANDER_GPIO_CMD       , /* 0x0078  */
    IOP_VIM_PKT_EXPANDER_GPIO_DATA      , /* 0x0079  */
    IOP_VIM_PKT_EXPANDER_UART_RX_DATA   , /* 0x007A  */
    IOP_VIM_PKT_EXPANDER_UART_TX_CMD    , /* 0x007B  */
    IOP_VIM_PKT_EXPANDER_UART_TX_DATA   , /* 0x007C  */
    IOP_VIM_PKT_EXPANDER_LOOPBACK_CMD   , /* 0x007D  */
    IOP_VIM_PKT_EXPANDER_SET_BAUD_CMD   , /* 0x007E  */
    IOP_VIM_PKT_EXPANDER_REG_OP_CMD     , /* 0x007F  */
    IOP_VIM_PKT_EXPANDER_REG_OP_DATA    , /* 0x0080  */
    IOP_VIM_PKT_AUDIO_CROSSOVER_CMD     , /* 0x0081  */
    IOP_VIM_PKT_AUDIO_EQ_BATCH_CMD      , /* 0x0082  */
    IOP_VIM_PKT_PWM_SYNC_CMD            , /* 0x0083  */
    IOP_VIM_PKT_PWM_SYNC_DATA           , /* 0x0084  */
    IOP_VIM_PKT_PWR_CHARGER_ACK         , /* 0x0085  */
    IOP_VIM_PKT_TW8836_SRC_TEST_CMD     , /* 0x0086  */
    IOP_VIM_PKT_TW8836_SRC_TEST_DATA    , /* 0x0087  */
    IOP_VIM_PKT_PCB_VER_CMD             , /* 0x0088  */
    IOP_VIM_PKT_PCB_VER_DATA            , /* 0x0089  */
    IOP_VIM_PKT_PWR_MODE_CMD            , /* 0x008A  */
    IOP_VIM_PKT_PWR_MODE_DATA           , /* 0x008B  */
    IOP_VIM_PKT_TW8836_RVC_BT656_CMD    , /* 0x008C  */
    IOP_VIM_PKT_TW8836_RVC_BT656_DATA   , /* 0x008D  */
    IOP_VIM_PKT_TW8836_REG_OP_CMD       , /* 0x008E  */
    IOP_VIM_PKT_TW8836_REG_OP_DATA      , /* 0x008F  */
    IOP_VIM_PKT_VIM_TEMP_DATA           , /* 0x0090  */
    IOP_VIM_PKT_VIM_CALLSTACK_CMD       , /* 0x0091  */
    IOP_VIM_PKT_VIM_CALLSTACK_DATA      , /* 0x0092  */
    IOP_VIM_PKT_VIM_UPDATE_SW_CMD       , /* 0x0093  */
    IOP_VIM_PKT_VIM_UPDATE_SW_ACK       , /* 0x0094  */
    IOP_VIM_PKT_TEST_MODE_CMD           , /* 0x0095  */
    IOP_VIM_PKT_TEST_MODE_DATA          , /* 0x0096  */
    IOP_VIM_PKT_TW8836_EB_VOL_SOSD_CMD  , /* 0x0097  */
    IOP_VIM_PKT_TW8836_EB_VOL_SOSD_DATA , /* 0x0098  */
    IOP_VIM_PKT_TW8836_SPI_FLASH_CMD    , /* 0x0099  */
    IOP_VIM_PKT_TW8836_SPI_FLASH_DATA   , /* 0x009A  */
    IOP_VIM_PKT_PWR_QUERY_DATA          , /* 0x009B  */
    IOP_VIM_PKT_KEYPAD_BACK_LIGHT_CMD   , /* 0x009C  */
    IOP_VIM_PKT_CTP_KEY_CMD             , /* 0x009D  */
    IOP_VIM_PKT_CTP_KEY_DATA            , /* 0x009E  */
    IOP_VIM_PKT_PARK_LINE_CMD           , /* 0x009F  */
    IOP_VIM_PKT_PARK_LINE_DATA          , /* 0x00A0  */
    IOP_VIM_PKT_AGREE_TOUCHED_CMD       , /* 0x00A1  */
    IOP_VIM_PKT_CARMAX_TPMS_CMD         , /* 0x00A2  */
    IOP_VIM_PKT_CARMAX_TPMS_DATA        , /* 0x00A3  */
    IOP_VIM_PKT_CARMAX_HUD_CMD          , /* 0x00A4  */
    IOP_VIM_PKT_CARMAX_HUD_DATA         , /* 0x00A5  */
    IOP_VIM_PKT_CARMAX_DVR_CMD          , /* 0x00A6  */
    IOP_VIM_PKT_CARMAX_DVR_DATA         , /* 0x00A7  */
    IOP_VIM_PKT_ADC_DVR_DATA            , /* 0x00A8  */
    IOP_VIM_PKT_ADC_TPMS_DATA           , /* 0x00A9  */
    IOP_VIM_PKT_HU_UART3_TEST_CMD       , /* 0x00AA  */
    IOP_VIM_PKT_HU_UART3_TEST_DATA      , /* 0x00AB  */
    IOP_VIM_PKT_MUTE_AUDIO_PATH_CMD     , /* 0x00AC  */
    IOP_VIM_PKT_GPIO_STATUS_CMD         , /* 0x00AD  */
    IOP_VIM_PKT_GPIO_STATUS_DATA        , /* 0x00AE  */
    IOP_VIM_PKT_TEXT_LANGUAGE_CMD       , /* 0x00AF  */
    IOP_VIM_PKT_TEXT_LANGUAGE_DATA      , /* 0x00B0  */
    IOP_VIM_PKT_AGREE_TOUCHED_DATA      , /* 0x00B1  */
    IOP_VIM_PKT_FLASH_DB_CHECKSUM_CMD   , /* 0x00B2  */
    IOP_VIM_PKT_FLASH_DB_CHECKSUM_DATA  , /* 0x00B3  */
    IOP_VIM_PKT_CTP_OP_RESET_CMD        , /* 0x00B4  */
    IOP_VIM_PKT_CTP_OP_RESET_DATA       , /* 0x00B5  */
    IOP_VIM_PKT_RVC_VIEW_CMD            , /* 0x00B6  */
    IOP_VIM_PKT_RVC_VIEW_DATA           , /* 0x00B7  */
    IOP_VIM_PKT_ENG_AUD_EFF_SET_CMD     , /* 0x00B8  */
    IOP_VIM_PKT_TW8836_PWM_CMD          , /* 0x00B9  */
    IOP_VIM_PKT_TW8836_PWM_DATA         , /* 0x00BA  */
    IOP_VIM_PKT_HOPPER_CMD              , /* 0x00BB  */
    IOP_VIM_PKT_DUMP_AUDIO_PARAM_CMD    , /* 0x00BC  */
    IOP_VIM_PKT_PVM_TOUCH_CMD           , /* 0x00BD  */
    IOP_VIM_PKT_TW8836_GPIO_CMD         , /* 0x00BE  */
    IOP_VIM_PKT_TW8836_GPIO_DATA        , /* 0x00BF  */
    IOP_VIM_PKT_CUSTOM_EQ_REL_FUNC_CMD  , /* 0x00C0  */
    IOP_VIM_PKT_CUSTOM_EQ_REL_FUNC_DATA , /* 0x00C1  */
    IOP_VIM_PKT_CTP_RAW_CMD             , /* 0x00C2  */
    IOP_VIM_PKT_CTP_RAW_DATA            , /* 0x00C3  */
    IOP_VIM_PKT_DA_UPDATE_CMD           , /* 0x00C4  */
    IOP_VIM_PKT_DA_UPDATE_DATA          , /* 0x00C5  */
    IOP_VIM_PKT_SRC_SWTCH_DONE_ACK      , /* 0x00C6  */
    IOP_VIM_PKT_DA_USB_CHECK_CMD        , /* 0x00C7  */
    IOP_VIM_PKT_DA_USB_CHECK_DATA       , /* 0x00C8  */
    IOP_VIM_PKT_TOUCH_FIRMWARE_VER_CMD  , /* 0x00C9  */
    IOP_VIM_PKT_TOUCH_FIRMWARE_VER_ACK  , /* 0x00CA  */
    IOP_VIM_PKT_DA_FAN_SPEED_DATA       , /* 0x00CB  */
    IOP_VIM_PKT_DA_FAN_SPEED_CMD        , /* 0x00CC  */
    IOP_VIM_PKT_TW8836_SOSD_CMD         , /* 0x00CD  */
    IOP_VIM_PKT_TW8836_SOSD_DATA        , /* 0x00CE  */
    IOP_BURN_IN_TEST_DATA               , /* 0x00CF  */
    IOP_VIM_PKT_DRC_FUNC_CMD            , /* 0x00D0  */
    IOP_VIM_PKT_NVM_CLR_RESET_CMD       , /* 0x00D1  */
    IOP_VIM_PKT_NVM_DUMP_A2_CMD         , /* 0x00D2  */
    IOP_VIM_PKT_NVM_ROM_CRC_DEBUG       , /* 0x00D3  */
    IOP_VIM_PKT_ILL_MINUS_VOLT_CMD      , /* 0x00D4  */
    IOP_VIM_PKT_ILL_MINUS_VOLT_DATA     , /* 0x00D5  */
    IOP_VIM_PKT_PRODUCT_SKU_CMD         , /* 0x00D6  */
    IOP_VIM_PKT_PRODUCT_SKU_DATA        , /* 0x00D7  */
    IOP_VIM_PKT_TEST_PAGE               , /* 0x00D8  */
    IOP_VIM_PKT_SD_UART_DATA            , /* 0x00D9  */
    IOP_VIM_PKT_PB_CARPLAY_SET_CMD      , /* 0x00DA  */
    IOP_VIM_PKT_PB_CARPLAY_SET_ACK      , /* 0x00DB  */
    IOP_VIM_PKT_DIG_IO_STATUS_64_DATA   , /* 0x00DC  */
    IOP_VIM_PKT_DAY_NGT_AUTO_MODE_CMD   , /* 0x00DD  */
    IOP_VIM_PKT_KYPD_BKLGT_VAL_CMD      , /* 0x00DE  */
    IOP_VIM_PKT_ILLUM_ADC_CMD           , /* 0x00DF  */
    IOP_VIM_PKT_ILLUM_ADC_DATA          , /* 0x00E0  */
    IOP_VIM_PKT_CAR_TYPE_CMD            , /* 0x00E1  */
    IOP_VIM_PKT_CAR_TYPE_DAT            , /* 0x00E2  */
    IOP_VIM_PKT_DCM_STATUS_QUERY_CMD    , /* 0x00E3  */
    IOP_VIM_PKT_DCM_STATUS_DATA         , /* 0x00E4  */
    IOP_VIM_PKT_DC_OFFSET_QUERY_CMD     , /* 0x00E5  */
    IOP_VIM_PKT_DC_OFFSET_STATUS_DATA   , /* 0x00E6  */
    IOP_VIM_PKT_SD_TOUCH_DATA           , /* 0x00E7  */
    IOP_VIM_PKT_NISSAN_YVCAN_DATA       , /* 0x00E8  */
    IOP_VIM_PKT_NISSAN_MCAN_DATA        , /* 0x00E9  */
    IOP_VIM_PKT_NISSAN_NAVI_DATA        , /* 0x00EA  */
    IOP_VIM_PKT_NISSAN_DIAG_DATA        , /* 0x00EB  */
    IOP_VIM_PKT_NISSAN_CPU_REQUEST      , /* 0x00EC  */
    IOP_VIM_PKT_AUTO_SOUND_LEVEL_DATA   , /* 0x00ED  */
    IOP_VIM_PKT_AMP_SET_CMD             , /* 0x00EE  */
    IOP_VIM_PKT_AMP_SET_DATA            , /* 0x00EF  */
    IOP_VIM_PKT_PMU_EXT_SIGNAL          , /* 0x00F0  */
    IOP_BT_ACCEPT_NEXT_PAIR_REQUEST     , /* 0x00F1  */
    IOP_MCU_FW_VERSION_REQUEST          , /* 0x00F2  */
    IOP_BOOT_LOADER_VERSION_REQUEST     , /* 0x00F3  */
    IOP_VIM_PKT_CARMAX_HDTV_CMD         , /* 0x00F4  */
    IOP_VIM_PKT_ADC_HDTV_DATA           , /* 0x00F5  */
    IOP_VIM_PKT_BACK_KEY_HDTV_DATA      , /* 0x00F6  */
    IOP_VIM_PKT_GET_TW8836_ADC_CMD      , /* 0x00F7  */
    IOP_VIM_PKT_GET_TW8836_ADC_DATA     , /* 0x00F8  */
    IOP_VIM_PKT_ESN_CMD                 , /* 0x00F9  */
    IOP_VIM_PKT_ESN_DATA                , /* 0x00FA  */
    IOP_VIM_PKT_OVER_CURRENT_CMD        , /* 0x00FB  */
    IOP_VIM_PKT_DA_UPDATE_STATUS        , /* 0x00FC  */
    IOP_VIM_PKT_GPIO_KEY_STATUS_CMD     , /* 0x00FD  */
    IOP_VIM_PKT_M3_UART2_TEST_CMD       , /* 0x00FE  */
    IOP_VIM_PKT_M3_UART2_TEST_DATA      , /* 0x00FF  */
    IOP_BT_SET_TO_ACTIVE                , /* 0x0100  */
    IOP_BT_SET_TO_INACTIVE              , /* 0x0101  */

    IOP_VIM_PKT_MAX_PKT_ID            /* End of list marker */

    } iop_vim_cmd_pkt_id_t;

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

#if defined( __cplusplus )
}
#endif

#endif /* IOP_PUB_VIM_INST_PRJ_H */


