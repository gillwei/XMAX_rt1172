/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/* GPIO_SD_B1_02 (coord C15), TFT_CONNECTED */
/* Routed pin properties */
#define BOARD_INITPINS_TFT_CONNECTED_PERIPHERAL                           GPIO10   /*!< Peripheral name */
#define BOARD_INITPINS_TFT_CONNECTED_SIGNAL                              gpio_io   /*!< Signal name */
#define BOARD_INITPINS_TFT_CONNECTED_CHANNEL                                  5U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_TFT_CONNECTED_GPIO                                 GPIO10   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_TFT_CONNECTED_GPIO_PIN                                 5U   /*!< GPIO pin number */
#define BOARD_INITPINS_TFT_CONNECTED_GPIO_PIN_MASK                    (1U << 5U)   /*!< GPIO pin mask */

/* GPIO_SD_B1_01 (coord D15), TFT_ASIL */
/* Routed pin properties */
#define BOARD_INITPINS_TFT_ASIL_PERIPHERAL                                GPIO10   /*!< Peripheral name */
#define BOARD_INITPINS_TFT_ASIL_SIGNAL                                   gpio_io   /*!< Signal name */
#define BOARD_INITPINS_TFT_ASIL_CHANNEL                                       4U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_TFT_ASIL_GPIO                                      GPIO10   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_TFT_ASIL_GPIO_PIN                                      4U   /*!< GPIO pin number */
#define BOARD_INITPINS_TFT_ASIL_GPIO_PIN_MASK                         (1U << 4U)   /*!< GPIO pin mask */

/* WAKEUP (coord T8), IGN_WAKE */
/* Routed pin properties */
#define BOARD_INITPINS_IGN_WAKE_PERIPHERAL                                GPIO13   /*!< Peripheral name */
#define BOARD_INITPINS_IGN_WAKE_SIGNAL                                   gpio_io   /*!< Signal name */
#define BOARD_INITPINS_IGN_WAKE_CHANNEL                                       0U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_IGN_WAKE_GPIO                                      GPIO13   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_IGN_WAKE_GPIO_PIN                                      0U   /*!< GPIO pin number */
#define BOARD_INITPINS_IGN_WAKE_GPIO_PIN_MASK                         (1U << 0U)   /*!< GPIO pin mask */

/* PMIC_ON_REQ (coord U9), SYS_EN */
/* Routed pin properties */
#define BOARD_INITPINS_SYS_EN_PERIPHERAL                                  GPIO13   /*!< Peripheral name */
#define BOARD_INITPINS_SYS_EN_SIGNAL                                     gpio_io   /*!< Signal name */
#define BOARD_INITPINS_SYS_EN_CHANNEL                                         1U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_SYS_EN_GPIO                                        GPIO13   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_SYS_EN_GPIO_PIN                                        1U   /*!< GPIO pin number */
#define BOARD_INITPINS_SYS_EN_GPIO_PIN_MASK                           (1U << 1U)   /*!< GPIO pin mask */

/* GPIO_SNVS_07 (coord R9), IGN_WAKE_GPIO */
/* Routed pin properties */
#define BOARD_INITPINS_IGN_WAKE_GPIO_PERIPHERAL                           GPIO13   /*!< Peripheral name */
#define BOARD_INITPINS_IGN_WAKE_GPIO_SIGNAL                              gpio_io   /*!< Signal name */
#define BOARD_INITPINS_IGN_WAKE_GPIO_CHANNEL                                 10U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_IGN_WAKE_GPIO_GPIO                                 GPIO13   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_IGN_WAKE_GPIO_GPIO_PIN                                10U   /*!< GPIO pin number */
#define BOARD_INITPINS_IGN_WAKE_GPIO_GPIO_PIN_MASK                   (1U << 10U)   /*!< GPIO pin mask */

/* GPIO_AD_11 (coord P16), 5V_CAN_PGOOD */
/* Routed pin properties */
#define BOARD_INITPINS_CAN_PGOOD_PERIPHERAL                                GPIO9   /*!< Peripheral name */
#define BOARD_INITPINS_CAN_PGOOD_SIGNAL                                  gpio_io   /*!< Signal name */
#define BOARD_INITPINS_CAN_PGOOD_CHANNEL                                     10U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_CAN_PGOOD_GPIO                                      GPIO9   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_CAN_PGOOD_GPIO_PIN                                    10U   /*!< GPIO pin number */
#define BOARD_INITPINS_CAN_PGOOD_GPIO_PIN_MASK                       (1U << 10U)   /*!< GPIO pin mask */

/* GPIO_AD_27 (coord N16), 5V_CAN_EN */
/* Routed pin properties */
#define BOARD_INITPINS_CAN_EN_PERIPHERAL                                   GPIO9   /*!< Peripheral name */
#define BOARD_INITPINS_CAN_EN_SIGNAL                                     gpio_io   /*!< Signal name */
#define BOARD_INITPINS_CAN_EN_CHANNEL                                        26U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_CAN_EN_GPIO                                         GPIO9   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_CAN_EN_GPIO_PIN                                       26U   /*!< GPIO pin number */
#define BOARD_INITPINS_CAN_EN_GPIO_PIN_MASK                          (1U << 26U)   /*!< GPIO pin mask */

/* GPIO_SD_B2_01 (coord J14), DEBUG_LED */
/* Routed pin properties */
#define BOARD_INITPINS_DEBUG_LED_PERIPHERAL                               GPIO10   /*!< Peripheral name */
#define BOARD_INITPINS_DEBUG_LED_SIGNAL                                  gpio_io   /*!< Signal name */
#define BOARD_INITPINS_DEBUG_LED_CHANNEL                                     10U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_DEBUG_LED_GPIO                                     GPIO10   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_DEBUG_LED_GPIO_PIN                                    10U   /*!< GPIO pin number */
#define BOARD_INITPINS_DEBUG_LED_GPIO_PIN_MASK                       (1U << 10U)   /*!< GPIO pin mask */

/* GPIO_AD_28 (coord L17), CAN_STBY */
/* Routed pin properties */
#define BOARD_INITPINS_CAN_STBY_PERIPHERAL                                 GPIO9   /*!< Peripheral name */
#define BOARD_INITPINS_CAN_STBY_SIGNAL                                   gpio_io   /*!< Signal name */
#define BOARD_INITPINS_CAN_STBY_CHANNEL                                      27U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_CAN_STBY_GPIO                                       GPIO9   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_CAN_STBY_GPIO_PIN                                     27U   /*!< GPIO pin number */
#define BOARD_INITPINS_CAN_STBY_GPIO_PIN_MASK                        (1U << 27U)   /*!< GPIO pin mask */

/* GPIO_EMC_B2_04 (coord M1), HW_ID1 */
/* Routed pin properties */
#define BOARD_INITPINS_HW_ID1_PERIPHERAL                                   GPIO8   /*!< Peripheral name */
#define BOARD_INITPINS_HW_ID1_SIGNAL                                     gpio_io   /*!< Signal name */
#define BOARD_INITPINS_HW_ID1_CHANNEL                                        14U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_HW_ID1_GPIO                                         GPIO8   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_HW_ID1_GPIO_PIN                                       14U   /*!< GPIO pin number */
#define BOARD_INITPINS_HW_ID1_GPIO_PIN_MASK                          (1U << 14U)   /*!< GPIO pin mask */

/* GPIO_EMC_B2_05 (coord N1), HW_ID2 */
/* Routed pin properties */
#define BOARD_INITPINS_HW_ID2_PERIPHERAL                                   GPIO8   /*!< Peripheral name */
#define BOARD_INITPINS_HW_ID2_SIGNAL                                     gpio_io   /*!< Signal name */
#define BOARD_INITPINS_HW_ID2_CHANNEL                                        15U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_HW_ID2_GPIO                                         GPIO8   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_HW_ID2_GPIO_PIN                                       15U   /*!< GPIO pin number */
#define BOARD_INITPINS_HW_ID2_GPIO_PIN_MASK                          (1U << 15U)   /*!< GPIO pin mask */

/* GPIO_EMC_B2_08 (coord P1), HW_ID3 */
/* Routed pin properties */
#define BOARD_INITPINS_HW_ID3_PERIPHERAL                                   GPIO8   /*!< Peripheral name */
#define BOARD_INITPINS_HW_ID3_SIGNAL                                     gpio_io   /*!< Signal name */
#define BOARD_INITPINS_HW_ID3_CHANNEL                                        18U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_HW_ID3_GPIO                                         GPIO8   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_HW_ID3_GPIO_PIN                                       18U   /*!< GPIO pin number */
#define BOARD_INITPINS_HW_ID3_GPIO_PIN_MASK                          (1U << 18U)   /*!< GPIO pin mask */

/* GPIO_EMC_B2_03 (coord R1), HW_ID0 */
/* Routed pin properties */
#define BOARD_INITPINS_HW_ID0_PERIPHERAL                                   GPIO8   /*!< Peripheral name */
#define BOARD_INITPINS_HW_ID0_SIGNAL                                     gpio_io   /*!< Signal name */
#define BOARD_INITPINS_HW_ID0_CHANNEL                                        13U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_HW_ID0_GPIO                                         GPIO8   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_HW_ID0_GPIO_PIN                                       13U   /*!< GPIO pin number */
#define BOARD_INITPINS_HW_ID0_GPIO_PIN_MASK                          (1U << 13U)   /*!< GPIO pin mask */

/* GPIO_EMC_B2_12 (coord M2), SKU_ID2 */
/* Routed pin properties */
#define BOARD_INITPINS_SKU_ID2_PERIPHERAL                                  GPIO8   /*!< Peripheral name */
#define BOARD_INITPINS_SKU_ID2_SIGNAL                                    gpio_io   /*!< Signal name */
#define BOARD_INITPINS_SKU_ID2_CHANNEL                                       22U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_SKU_ID2_GPIO                                        GPIO8   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_SKU_ID2_GPIO_PIN                                      22U   /*!< GPIO pin number */
#define BOARD_INITPINS_SKU_ID2_GPIO_PIN_MASK                         (1U << 22U)   /*!< GPIO pin mask */

/* GPIO_EMC_B2_09 (coord N2), SKU_ID0 */
/* Routed pin properties */
#define BOARD_INITPINS_SKU_ID0_PERIPHERAL                                  GPIO8   /*!< Peripheral name */
#define BOARD_INITPINS_SKU_ID0_SIGNAL                                    gpio_io   /*!< Signal name */
#define BOARD_INITPINS_SKU_ID0_CHANNEL                                       19U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_SKU_ID0_GPIO                                        GPIO8   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_SKU_ID0_GPIO_PIN                                      19U   /*!< GPIO pin number */
#define BOARD_INITPINS_SKU_ID0_GPIO_PIN_MASK                         (1U << 19U)   /*!< GPIO pin mask */

/* GPIO_EMC_B2_16 (coord P2), SKU_ID3 */
/* Routed pin properties */
#define BOARD_INITPINS_SKU_ID3_PERIPHERAL                                  GPIO8   /*!< Peripheral name */
#define BOARD_INITPINS_SKU_ID3_SIGNAL                                    gpio_io   /*!< Signal name */
#define BOARD_INITPINS_SKU_ID3_CHANNEL                                       26U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_SKU_ID3_GPIO                                        GPIO8   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_SKU_ID3_GPIO_PIN                                      26U   /*!< GPIO pin number */
#define BOARD_INITPINS_SKU_ID3_GPIO_PIN_MASK                         (1U << 26U)   /*!< GPIO pin mask */

/* GPIO_EMC_B2_10 (coord R2), SKU_ID1 */
/* Routed pin properties */
#define BOARD_INITPINS_SKU_ID1_PERIPHERAL                                  GPIO8   /*!< Peripheral name */
#define BOARD_INITPINS_SKU_ID1_SIGNAL                                    gpio_io   /*!< Signal name */
#define BOARD_INITPINS_SKU_ID1_CHANNEL                                       20U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_SKU_ID1_GPIO                                        GPIO8   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_SKU_ID1_GPIO_PIN                                      20U   /*!< GPIO pin number */
#define BOARD_INITPINS_SKU_ID1_GPIO_PIN_MASK                         (1U << 20U)   /*!< GPIO pin mask */

/* GPIO_SD_B1_00 (coord B16), TFT_BL_EN */
/* Routed pin properties */
#define BOARD_INITPINS_TFT_BL_EN_PERIPHERAL                               GPIO10   /*!< Peripheral name */
#define BOARD_INITPINS_TFT_BL_EN_SIGNAL                                  gpio_io   /*!< Signal name */
#define BOARD_INITPINS_TFT_BL_EN_CHANNEL                                      3U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_TFT_BL_EN_GPIO                                     GPIO10   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_TFT_BL_EN_GPIO_PIN                                     3U   /*!< GPIO pin number */
#define BOARD_INITPINS_TFT_BL_EN_GPIO_PIN_MASK                        (1U << 3U)   /*!< GPIO pin mask */

/* GPIO_AD_29 (coord M17), TFT_BL_PWM */
/* Routed pin properties */
#define BOARD_INITPINS_TFT_BL_PWM_PERIPHERAL                               GPIO9   /*!< Peripheral name */
#define BOARD_INITPINS_TFT_BL_PWM_SIGNAL                                 gpio_io   /*!< Signal name */
#define BOARD_INITPINS_TFT_BL_PWM_CHANNEL                                    28U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_TFT_BL_PWM_GPIO                                     GPIO9   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_TFT_BL_PWM_GPIO_PIN                                   28U   /*!< GPIO pin number */
#define BOARD_INITPINS_TFT_BL_PWM_GPIO_PIN_MASK                      (1U << 28U)   /*!< GPIO pin mask */

/* GPIO_SD_B1_03 (coord B17), TFT_RESET */
/* Routed pin properties */
#define BOARD_INITPINS_TFT_RESET_PERIPHERAL                               GPIO10   /*!< Peripheral name */
#define BOARD_INITPINS_TFT_RESET_SIGNAL                                  gpio_io   /*!< Signal name */
#define BOARD_INITPINS_TFT_RESET_CHANNEL                                      6U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_TFT_RESET_GPIO                                     GPIO10   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_TFT_RESET_GPIO_PIN                                     6U   /*!< GPIO pin number */
#define BOARD_INITPINS_TFT_RESET_GPIO_PIN_MASK                        (1U << 6U)   /*!< GPIO pin mask */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);                    /* Function assigned for the Cortex-M7F */

/* GPIO_DISP_B1_01 (coord D13), TFT_RGB_DE */
/* Routed pin properties */
#define BOARD_INITLCDIFPINS_LCDIF_ENABLE_PERIPHERAL                        LCDIF   /*!< Peripheral name */
#define BOARD_INITLCDIFPINS_LCDIF_ENABLE_SIGNAL                     lcdif_enable   /*!< Signal name */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitLcdifPins(void);               /* Function assigned for the Cortex-M7F */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
