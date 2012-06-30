/**
  ******************************************************************************
  * @file    stm32f10x_gpio.h
  * @author  MCD Application Team
  * @version V3.1.0
  * @date    06/19/2009
  * @brief   This file contains all the functions prototypes for the GPIO 
  *          firmware library.
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2009 STMicroelectronics</center></h2>
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F10x_GPIO_H
#define __STM32F10x_GPIO_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "../../../cpu/stm32f103/STM32F10x/stm32f10x.h"


/** @addtogroup STM32F10x_StdPeriph_Driver
  * @{
  */

/** @addtogroup GPIO
  * @{
  */

/** @defgroup GPIO_Exported_Types
  * @{
  */
                                     
/** 
  * @brief  Output Maximum frequency selection  
  */

typedef enum
{ 
  GPIO_Speed_10MHz = 1,
  GPIO_Speed_2MHz, 
  GPIO_Speed_50MHz
}GPIOSpeed_TypeDef;
#define IS_GPIO_SPEED(SPEED) (((SPEED) == GPIO_Speed_10MHz) || ((SPEED) == GPIO_Speed_2MHz) || \
                              ((SPEED) == GPIO_Speed_50MHz))

/** 
  * @brief  Configuration Mode enumeration  
  */
typedef enum
{ GPIO_Mode_AIN = 0x0,/*!< 模拟输入 */
  GPIO_Mode_IN_FLOATING = 0x04,/*!< 悬空输入 */
  GPIO_Mode_IPD = 0x28,/*!< 下拉输入 */
  GPIO_Mode_IPU = 0x48,/*!< 上拉输入 */
  GPIO_Mode_Out_OD = 0x14,/*!< 推挽输出 */
  GPIO_Mode_Out_PP = 0x10,/*!< 开漏复用 */
  GPIO_Mode_AF_OD = 0x1C,/*!< 开漏输出 */
  GPIO_Mode_AF_PP = 0x18 /*!< 推挽复用 */
}GPIOMode_TypeDef;

/** 
  * @brief  GPIO Init structure definition  
  */

typedef struct
{
  INT16U GPIO_Pin;             /*!< Specifies the GPIO pins to be configured.
                                      This parameter can be any value of @ref GPIO_pins_define */

  GPIOSpeed_TypeDef GPIO_Speed;  /*!< Specifies the speed for the selected pins.
                                      This parameter can be a value of @ref GPIOSpeed_TypeDef */

  GPIOMode_TypeDef GPIO_Mode;    /*!< Specifies the operating mode for the selected pins.
                                      This parameter can be a value of @ref GPIOMode_TypeDef */
}GPIO_InitTypeDef;


/** 
  * @brief  Bit_SET and Bit_RESET enumeration  
  */

typedef enum
{ Bit_RESET = 0,
  Bit_SET
}BitAction;

/**
  * @}
  */

/** @defgroup GPIO_Exported_Constants
  * @{
  */

/** @defgroup GPIO_pins_define 
  * @{
  */

#define GPIO_Pin_0                 ((INT16U)0x0001)  /*!< Pin 0 selected */
#define GPIO_Pin_1                 ((INT16U)0x0002)  /*!< Pin 1 selected */
#define GPIO_Pin_2                 ((INT16U)0x0004)  /*!< Pin 2 selected */
#define GPIO_Pin_3                 ((INT16U)0x0008)  /*!< Pin 3 selected */
#define GPIO_Pin_4                 ((INT16U)0x0010)  /*!< Pin 4 selected */
#define GPIO_Pin_5                 ((INT16U)0x0020)  /*!< Pin 5 selected */
#define GPIO_Pin_6                 ((INT16U)0x0040)  /*!< Pin 6 selected */
#define GPIO_Pin_7                 ((INT16U)0x0080)  /*!< Pin 7 selected */
#define GPIO_Pin_8                 ((INT16U)0x0100)  /*!< Pin 8 selected */
#define GPIO_Pin_9                 ((INT16U)0x0200)  /*!< Pin 9 selected */
#define GPIO_Pin_10                ((INT16U)0x0400)  /*!< Pin 10 selected */
#define GPIO_Pin_11                ((INT16U)0x0800)  /*!< Pin 11 selected */
#define GPIO_Pin_12                ((INT16U)0x1000)  /*!< Pin 12 selected */
#define GPIO_Pin_13                ((INT16U)0x2000)  /*!< Pin 13 selected */
#define GPIO_Pin_14                ((INT16U)0x4000)  /*!< Pin 14 selected */
#define GPIO_Pin_15                ((INT16U)0x8000)  /*!< Pin 15 selected */
#define GPIO_Pin_All               ((INT16U)0xFFFF)  /*!< All pins selected */

/**
  * @}
  */

/** @defgroup GPIO_Remap_define 
  * @{
  */

#define GPIO_Remap_SPI1             ((INT32U)0x00000001)  /*!< SPI1 Alternate Function mapping */
#define GPIO_Remap_I2C1             ((INT32U)0x00000002)  /*!< I2C1 Alternate Function mapping */
#define GPIO_Remap_USART1           ((INT32U)0x00000004)  /*!< USART1 Alternate Function mapping */
#define GPIO_Remap_USART2           ((INT32U)0x00000008)  /*!< USART2 Alternate Function mapping */
#define GPIO_PartialRemap_USART3    ((INT32U)0x00140010)  /*!< USART3 Partial Alternate Function mapping */
#define GPIO_FullRemap_USART3       ((INT32U)0x00140030)  /*!< USART3 Full Alternate Function mapping */
#define GPIO_PartialRemap_TIM1      ((INT32U)0x00160040)  /*!< TIM1 Partial Alternate Function mapping */
#define GPIO_FullRemap_TIM1         ((INT32U)0x001600C0)  /*!< TIM1 Full Alternate Function mapping */
#define GPIO_PartialRemap1_TIM2     ((INT32U)0x00180100)  /*!< TIM2 Partial1 Alternate Function mapping */
#define GPIO_PartialRemap2_TIM2     ((INT32U)0x00180200)  /*!< TIM2 Partial2 Alternate Function mapping */
#define GPIO_FullRemap_TIM2         ((INT32U)0x00180300)  /*!< TIM2 Full Alternate Function mapping */
#define GPIO_PartialRemap_TIM3      ((INT32U)0x001A0800)  /*!< TIM3 Partial Alternate Function mapping */
#define GPIO_FullRemap_TIM3         ((INT32U)0x001A0C00)  /*!< TIM3 Full Alternate Function mapping */
#define GPIO_Remap_TIM4             ((INT32U)0x00001000)  /*!< TIM4 Alternate Function mapping */
#define GPIO_Remap1_CAN1            ((INT32U)0x001D4000)  /*!< CAN1 Alternate Function mapping */
#define GPIO_Remap2_CAN1            ((INT32U)0x001D6000)  /*!< CAN1 Alternate Function mapping */
#define GPIO_Remap_PD01             ((INT32U)0x00008000)  /*!< PD01 Alternate Function mapping */
#define GPIO_Remap_TIM5CH4_LSI      ((INT32U)0x00200001)  /*!< LSI connected to TIM5 Channel4 input capture for calibration */
#define GPIO_Remap_ADC1_ETRGINJ     ((INT32U)0x00200002)  /*!< ADC1 External Trigger Injected Conversion remapping */
#define GPIO_Remap_ADC1_ETRGREG     ((INT32U)0x00200004)  /*!< ADC1 External Trigger Regular Conversion remapping */
#define GPIO_Remap_ADC2_ETRGINJ     ((INT32U)0x00200008)  /*!< ADC2 External Trigger Injected Conversion remapping */
#define GPIO_Remap_ADC2_ETRGREG     ((INT32U)0x00200010)  /*!< ADC2 External Trigger Regular Conversion remapping */
#define GPIO_Remap_ETH              ((INT32U)0x00200020)  /*!< Ethernet remapping (only for Connectivity line devices) */
#define GPIO_Remap_CAN2             ((INT32U)0x00200040)  /*!< CAN2 remapping (only for Connectivity line devices) */
#define GPIO_Remap_SWJ_NoJTRST      ((INT32U)0x00300100)  /*!< Full SWJ Enabled (JTAG-DP + SW-DP) but without JTRST */
#define GPIO_Remap_SWJ_JTAGDisable  ((INT32U)0x00300200)  /*!< JTAG-DP Disabled and SW-DP Enabled */
#define GPIO_Remap_SWJ_Disable      ((INT32U)0x00300400)  /*!< Full SWJ Disabled (JTAG-DP + SW-DP) */
#define GPIO_Remap_SPI3             ((INT32U)0x00201000)  /*!< SPI3 Alternate Function mapping (only for Connectivity line devices) */
#define GPIO_Remap_TIM2ITR1_PTP_SOF ((INT32U)0x00202000)  /*!< Ethernet PTP output or USB OTG SOF (Start of Frame) connected
                                                                 to TIM2 Internal Trigger 1 for calibration
                                                                 (only for Connectivity line devices) */
#define GPIO_Remap_PTP_PPS          ((INT32U)0x00204000)  /*!< Ethernet MAC PPS_PTS output on PB05 (only for Connectivity line devices) */
/**
  * @}
  */ 

/** @defgroup GPIO_Port_Sources 
  * @{
  */

#define GPIO_PortSourceGPIOA       ((INT8U)0x00)
#define GPIO_PortSourceGPIOB       ((INT8U)0x01)
#define GPIO_PortSourceGPIOC       ((INT8U)0x02)
#define GPIO_PortSourceGPIOD       ((INT8U)0x03)
#define GPIO_PortSourceGPIOE       ((INT8U)0x04)
#define GPIO_PortSourceGPIOF       ((INT8U)0x05)
#define GPIO_PortSourceGPIOG       ((INT8U)0x06)
/**
  * @}
  */

/** @defgroup GPIO_Pin_sources 
  * @{
  */

#define GPIO_PinSource0            ((INT8U)0x00)
#define GPIO_PinSource1            ((INT8U)0x01)
#define GPIO_PinSource2            ((INT8U)0x02)
#define GPIO_PinSource3            ((INT8U)0x03)
#define GPIO_PinSource4            ((INT8U)0x04)
#define GPIO_PinSource5            ((INT8U)0x05)
#define GPIO_PinSource6            ((INT8U)0x06)
#define GPIO_PinSource7            ((INT8U)0x07)
#define GPIO_PinSource8            ((INT8U)0x08)
#define GPIO_PinSource9            ((INT8U)0x09)
#define GPIO_PinSource10           ((INT8U)0x0A)
#define GPIO_PinSource11           ((INT8U)0x0B)
#define GPIO_PinSource12           ((INT8U)0x0C)
#define GPIO_PinSource13           ((INT8U)0x0D)
#define GPIO_PinSource14           ((INT8U)0x0E)
#define GPIO_PinSource15           ((INT8U)0x0F)

/**
  * @}
  */

/** @defgroup Ethernet_Media_Interface 
  * @{
  */ 
#define GPIO_ETH_MediaInterface_MII    ((INT32U)0x00000000)
#define GPIO_ETH_MediaInterface_RMII   ((INT32U)0x00000001)

/**
  * @}
  */                                                
/**
  * @}
  */

/** @defgroup GPIO_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup GPIO_Exported_Functions
  * @{
  */
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);

#endif /* __STM32F10x_GPIO_H */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
