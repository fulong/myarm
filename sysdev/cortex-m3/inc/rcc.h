/**
  ******************************************************************************
  * @file    stm32f10x_rcc.h
  * @author  MCD Application Team
  * @version V3.1.0
  * @date    06/19/2009
  * @brief   This file contains all the functions prototypes for the RCC firmware 
  *          library.
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
#ifndef __STM32F10x_RCC_H
#define __STM32F10x_RCC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "../../../cpu/cortex-m3/stm32f103/STM32F10x/stm32f10x.h"


/** @addtogroup STM32F10x_StdPeriph_Driver
  * @{
  */

/** @addtogroup RCC
  * @{
  */

/** @defgroup RCC_Exported_Types
  * @{
  */

typedef struct
{
  INT32U SYSCLK_Frequency;  /*!< returns SYSCLK clock frequency expressed in Hz */
  INT32U HCLK_Frequency;    /*!< returns HCLK clock frequency expressed in Hz */
  INT32U PCLK1_Frequency;   /*!< returns PCLK1 clock frequency expressed in Hz */
  INT32U PCLK2_Frequency;   /*!< returns PCLK2 clock frequency expressed in Hz */
  INT32U ADCCLK_Frequency;  /*!< returns ADCCLK clock frequency expressed in Hz */
}RCC_ClocksTypeDef;

/**
  * @}
  */

/** @defgroup RCC_Exported_Constants
  * @{
  */

/** @defgroup HSE_configuration 
  * @{
  */

#define RCC_HSE_OFF                      ((INT32U)0x00000000)
#define RCC_HSE_ON                       ((INT32U)0x00010000)
#define RCC_HSE_Bypass                   ((INT32U)0x00040000)
#define IS_RCC_HSE(HSE) (((HSE) == RCC_HSE_OFF) || ((HSE) == RCC_HSE_ON) || \
                         ((HSE) == RCC_HSE_Bypass))

/**
  * @}
  */ 

/** @defgroup PLL_entry_clock_source 
  * @{
  */

#define RCC_PLLSource_HSI_Div2           ((INT32U)0x00000000)

#ifndef STM32F10X_CL
 #define RCC_PLLSource_HSE_Div1           ((INT32U)0x00010000)
 #define RCC_PLLSource_HSE_Div2           ((INT32U)0x00030000)
 #define IS_RCC_PLL_SOURCE(SOURCE) (((SOURCE) == RCC_PLLSource_HSI_Div2) || \
                                   ((SOURCE) == RCC_PLLSource_HSE_Div1) || \
                                   ((SOURCE) == RCC_PLLSource_HSE_Div2))
#else
 #define RCC_PLLSource_PREDIV1            ((INT32U)0x00010000)
#define IS_RCC_PLL_SOURCE(SOURCE) (((SOURCE) == RCC_PLLSource_HSI_Div2) || \
                                   ((SOURCE) == RCC_PLLSource_PREDIV1))
#endif /* STM32F10X_CL */ 

/**
  * @}
  */ 

/** @defgroup PLL_multiplication_factor 
  * @{
  */
#ifndef STM32F10X_CL
 #define RCC_PLLMul_2                    ((INT32U)0x00000000)
 #define RCC_PLLMul_3                    ((INT32U)0x00040000)
 #define RCC_PLLMul_4                    ((INT32U)0x00080000)
 #define RCC_PLLMul_5                    ((INT32U)0x000C0000)
 #define RCC_PLLMul_6                    ((INT32U)0x00100000)
 #define RCC_PLLMul_7                    ((INT32U)0x00140000)
 #define RCC_PLLMul_8                    ((INT32U)0x00180000)
 #define RCC_PLLMul_9                    ((INT32U)0x001C0000)
 #define RCC_PLLMul_10                   ((INT32U)0x00200000)
 #define RCC_PLLMul_11                   ((INT32U)0x00240000)
 #define RCC_PLLMul_12                   ((INT32U)0x00280000)
 #define RCC_PLLMul_13                   ((INT32U)0x002C0000)
 #define RCC_PLLMul_14                   ((INT32U)0x00300000)
 #define RCC_PLLMul_15                   ((INT32U)0x00340000)
 #define RCC_PLLMul_16                   ((INT32U)0x00380000)
 #define IS_RCC_PLL_MUL(MUL) (((MUL) == RCC_PLLMul_2) || ((MUL) == RCC_PLLMul_3)   || \
                              ((MUL) == RCC_PLLMul_4) || ((MUL) == RCC_PLLMul_5)   || \
                              ((MUL) == RCC_PLLMul_6) || ((MUL) == RCC_PLLMul_7)   || \
                              ((MUL) == RCC_PLLMul_8) || ((MUL) == RCC_PLLMul_9)   || \
                              ((MUL) == RCC_PLLMul_10) || ((MUL) == RCC_PLLMul_11) || \
                              ((MUL) == RCC_PLLMul_12) || ((MUL) == RCC_PLLMul_13) || \
                              ((MUL) == RCC_PLLMul_14) || ((MUL) == RCC_PLLMul_15) || \
                              ((MUL) == RCC_PLLMul_16))

#else
 #define RCC_PLLMul_4                    ((INT32U)0x00080000)
 #define RCC_PLLMul_5                    ((INT32U)0x000C0000)
 #define RCC_PLLMul_6                    ((INT32U)0x00100000)
 #define RCC_PLLMul_7                    ((INT32U)0x00140000)
 #define RCC_PLLMul_8                    ((INT32U)0x00180000)
 #define RCC_PLLMul_9                    ((INT32U)0x001C0000)
 #define RCC_PLLMul_6_5                  ((INT32U)0x00340000)

 #define IS_RCC_PLL_MUL(MUL) (((MUL) == RCC_PLLMul_4) || ((MUL) == RCC_PLLMul_5) || \
                              ((MUL) == RCC_PLLMul_6) || ((MUL) == RCC_PLLMul_7) || \
                              ((MUL) == RCC_PLLMul_8) || ((MUL) == RCC_PLLMul_9) || \
                              ((MUL) == RCC_PLLMul_6_5))
#endif /* STM32F10X_CL */                              
/**
  * @}
  */

#ifdef STM32F10X_CL
/** @defgroup PREDIV1_division_factor
  * @{
  */
 #define  RCC_PREDIV1_Div1               ((INT32U)0x00000000)
 #define  RCC_PREDIV1_Div2               ((INT32U)0x00000001)
 #define  RCC_PREDIV1_Div3               ((INT32U)0x00000002)
 #define  RCC_PREDIV1_Div4               ((INT32U)0x00000003)
 #define  RCC_PREDIV1_Div5               ((INT32U)0x00000004)
 #define  RCC_PREDIV1_Div6               ((INT32U)0x00000005)
 #define  RCC_PREDIV1_Div7               ((INT32U)0x00000006)
 #define  RCC_PREDIV1_Div8               ((INT32U)0x00000007)
 #define  RCC_PREDIV1_Div9               ((INT32U)0x00000008)
 #define  RCC_PREDIV1_Div10              ((INT32U)0x00000009)
 #define  RCC_PREDIV1_Div11              ((INT32U)0x0000000A)
 #define  RCC_PREDIV1_Div12              ((INT32U)0x0000000B)
 #define  RCC_PREDIV1_Div13              ((INT32U)0x0000000C)
 #define  RCC_PREDIV1_Div14              ((INT32U)0x0000000D)
 #define  RCC_PREDIV1_Div15              ((INT32U)0x0000000E)
 #define  RCC_PREDIV1_Div16              ((INT32U)0x0000000F)

 #define IS_RCC_PREDIV1(PREDIV1) (((PREDIV1) == RCC_PREDIV1_Div1) || ((PREDIV1) == RCC_PREDIV1_Div2) || \
                                  ((PREDIV1) == RCC_PREDIV1_Div3) || ((PREDIV1) == RCC_PREDIV1_Div4) || \
                                  ((PREDIV1) == RCC_PREDIV1_Div5) || ((PREDIV1) == RCC_PREDIV1_Div6) || \
                                  ((PREDIV1) == RCC_PREDIV1_Div7) || ((PREDIV1) == RCC_PREDIV1_Div8) || \
                                  ((PREDIV1) == RCC_PREDIV1_Div9) || ((PREDIV1) == RCC_PREDIV1_Div10) || \
                                  ((PREDIV1) == RCC_PREDIV1_Div11) || ((PREDIV1) == RCC_PREDIV1_Div12) || \
                                  ((PREDIV1) == RCC_PREDIV1_Div13) || ((PREDIV1) == RCC_PREDIV1_Div14) || \
                                  ((PREDIV1) == RCC_PREDIV1_Div15) || ((PREDIV1) == RCC_PREDIV1_Div16))
/**
  * @}
  */


/** @defgroup PREDIV1_clock_source
  * @{
  */
/* PREDIV1 clock source (only for STM32 connectivity line devices) */
 #define  RCC_PREDIV1_Source_HSE         ((INT32U)0x00000000)
 #define  RCC_PREDIV1_Source_PLL2        ((INT32U)0x00010000)

 #define IS_RCC_PREDIV1_SOURCE(SOURCE) (((SOURCE) == RCC_PREDIV1_Source_HSE) || \
                                        ((SOURCE) == RCC_PREDIV1_Source_PLL2)) 
/**
  * @}
  */


/** @defgroup PREDIV2_division_factor
  * @{
  */
  
 #define  RCC_PREDIV2_Div1               ((INT32U)0x00000000)
 #define  RCC_PREDIV2_Div2               ((INT32U)0x00000010)
 #define  RCC_PREDIV2_Div3               ((INT32U)0x00000020)
 #define  RCC_PREDIV2_Div4               ((INT32U)0x00000030)
 #define  RCC_PREDIV2_Div5               ((INT32U)0x00000040)
 #define  RCC_PREDIV2_Div6               ((INT32U)0x00000050)
 #define  RCC_PREDIV2_Div7               ((INT32U)0x00000060)
 #define  RCC_PREDIV2_Div8               ((INT32U)0x00000070)
 #define  RCC_PREDIV2_Div9               ((INT32U)0x00000080)
 #define  RCC_PREDIV2_Div10              ((INT32U)0x00000090)
 #define  RCC_PREDIV2_Div11              ((INT32U)0x000000A0)
 #define  RCC_PREDIV2_Div12              ((INT32U)0x000000B0)
 #define  RCC_PREDIV2_Div13              ((INT32U)0x000000C0)
 #define  RCC_PREDIV2_Div14              ((INT32U)0x000000D0)
 #define  RCC_PREDIV2_Div15              ((INT32U)0x000000E0)
 #define  RCC_PREDIV2_Div16              ((INT32U)0x000000F0)

 #define IS_RCC_PREDIV2(PREDIV2) (((PREDIV2) == RCC_PREDIV2_Div1) || ((PREDIV2) == RCC_PREDIV2_Div2) || \
                                  ((PREDIV2) == RCC_PREDIV2_Div3) || ((PREDIV2) == RCC_PREDIV2_Div4) || \
                                  ((PREDIV2) == RCC_PREDIV2_Div5) || ((PREDIV2) == RCC_PREDIV2_Div6) || \
                                  ((PREDIV2) == RCC_PREDIV2_Div7) || ((PREDIV2) == RCC_PREDIV2_Div8) || \
                                  ((PREDIV2) == RCC_PREDIV2_Div9) || ((PREDIV2) == RCC_PREDIV2_Div10) || \
                                  ((PREDIV2) == RCC_PREDIV2_Div11) || ((PREDIV2) == RCC_PREDIV2_Div12) || \
                                  ((PREDIV2) == RCC_PREDIV2_Div13) || ((PREDIV2) == RCC_PREDIV2_Div14) || \
                                  ((PREDIV2) == RCC_PREDIV2_Div15) || ((PREDIV2) == RCC_PREDIV2_Div16))
/**
  * @}
  */


/** @defgroup PLL2_multiplication_factor
  * @{
  */
  
 #define  RCC_PLL2Mul_8                  ((INT32U)0x00000600)
 #define  RCC_PLL2Mul_9                  ((INT32U)0x00000700)
 #define  RCC_PLL2Mul_10                 ((INT32U)0x00000800)
 #define  RCC_PLL2Mul_11                 ((INT32U)0x00000900)
 #define  RCC_PLL2Mul_12                 ((INT32U)0x00000A00)
 #define  RCC_PLL2Mul_13                 ((INT32U)0x00000B00)
 #define  RCC_PLL2Mul_14                 ((INT32U)0x00000C00)
 #define  RCC_PLL2Mul_16                 ((INT32U)0x00000E00)
 #define  RCC_PLL2Mul_20                 ((INT32U)0x00000F00)

 #define IS_RCC_PLL2_MUL(MUL) (((MUL) == RCC_PLL2Mul_8) || ((MUL) == RCC_PLL2Mul_9)  || \
                               ((MUL) == RCC_PLL2Mul_10) || ((MUL) == RCC_PLL2Mul_11) || \
                               ((MUL) == RCC_PLL2Mul_12) || ((MUL) == RCC_PLL2Mul_13) || \
                               ((MUL) == RCC_PLL2Mul_14) || ((MUL) == RCC_PLL2Mul_16) || \
                               ((MUL) == RCC_PLL2Mul_20))
/**
  * @}
  */


/** @defgroup PLL3_multiplication_factor
  * @{
  */

 #define  RCC_PLL3Mul_8                  ((INT32U)0x00006000)
 #define  RCC_PLL3Mul_9                  ((INT32U)0x00007000)
 #define  RCC_PLL3Mul_10                 ((INT32U)0x00008000)
 #define  RCC_PLL3Mul_11                 ((INT32U)0x00009000)
 #define  RCC_PLL3Mul_12                 ((INT32U)0x0000A000)
 #define  RCC_PLL3Mul_13                 ((INT32U)0x0000B000)
 #define  RCC_PLL3Mul_14                 ((INT32U)0x0000C000)
 #define  RCC_PLL3Mul_16                 ((INT32U)0x0000E000)
 #define  RCC_PLL3Mul_20                 ((INT32U)0x0000F000)

 #define IS_RCC_PLL3_MUL(MUL) (((MUL) == RCC_PLL3Mul_8) || ((MUL) == RCC_PLL3Mul_9)  || \
                               ((MUL) == RCC_PLL3Mul_10) || ((MUL) == RCC_PLL3Mul_11) || \
                               ((MUL) == RCC_PLL3Mul_12) || ((MUL) == RCC_PLL3Mul_13) || \
                               ((MUL) == RCC_PLL3Mul_14) || ((MUL) == RCC_PLL3Mul_16) || \
                               ((MUL) == RCC_PLL3Mul_20))
/**
  * @}
  */

#endif /* STM32F10X_CL */


/** @defgroup System_clock_source 
  * @{
  */

#define RCC_SYSCLKSource_HSI             ((INT32U)0x00000000)
#define RCC_SYSCLKSource_HSE             ((INT32U)0x00000001)
#define RCC_SYSCLKSource_PLLCLK          ((INT32U)0x00000002)
#define IS_RCC_SYSCLK_SOURCE(SOURCE) (((SOURCE) == RCC_SYSCLKSource_HSI) || \
                                      ((SOURCE) == RCC_SYSCLKSource_HSE) || \
                                      ((SOURCE) == RCC_SYSCLKSource_PLLCLK))
/**
  * @}
  */

/** @defgroup AHB_clock_source 
  * @{
  */

#define RCC_SYSCLK_Div1                  ((INT32U)0x00000000)
#define RCC_SYSCLK_Div2                  ((INT32U)0x00000080)
#define RCC_SYSCLK_Div4                  ((INT32U)0x00000090)
#define RCC_SYSCLK_Div8                  ((INT32U)0x000000A0)
#define RCC_SYSCLK_Div16                 ((INT32U)0x000000B0)
#define RCC_SYSCLK_Div64                 ((INT32U)0x000000C0)
#define RCC_SYSCLK_Div128                ((INT32U)0x000000D0)
#define RCC_SYSCLK_Div256                ((INT32U)0x000000E0)
#define RCC_SYSCLK_Div512                ((INT32U)0x000000F0)
#define IS_RCC_HCLK(HCLK) (((HCLK) == RCC_SYSCLK_Div1) || ((HCLK) == RCC_SYSCLK_Div2) || \
                           ((HCLK) == RCC_SYSCLK_Div4) || ((HCLK) == RCC_SYSCLK_Div8) || \
                           ((HCLK) == RCC_SYSCLK_Div16) || ((HCLK) == RCC_SYSCLK_Div64) || \
                           ((HCLK) == RCC_SYSCLK_Div128) || ((HCLK) == RCC_SYSCLK_Div256) || \
                           ((HCLK) == RCC_SYSCLK_Div512))
/**
  * @}
  */ 

/** @defgroup APB1_APB2_clock_source 
  * @{
  */

#define RCC_HCLK_Div1                    ((INT32U)0x00000000)
#define RCC_HCLK_Div2                    ((INT32U)0x00000400)
#define RCC_HCLK_Div4                    ((INT32U)0x00000500)
#define RCC_HCLK_Div8                    ((INT32U)0x00000600)
#define RCC_HCLK_Div16                   ((INT32U)0x00000700)
#define IS_RCC_PCLK(PCLK) (((PCLK) == RCC_HCLK_Div1) || ((PCLK) == RCC_HCLK_Div2) || \
                           ((PCLK) == RCC_HCLK_Div4) || ((PCLK) == RCC_HCLK_Div8) || \
                           ((PCLK) == RCC_HCLK_Div16))
/**
  * @}
  */

/** @defgroup RCC_Interrupt_source 
  * @{
  */

#define RCC_IT_LSIRDY                    ((INT8U)0x01)
#define RCC_IT_LSERDY                    ((INT8U)0x02)
#define RCC_IT_HSIRDY                    ((INT8U)0x04)
#define RCC_IT_HSERDY                    ((INT8U)0x08)
#define RCC_IT_PLLRDY                    ((INT8U)0x10)
#define RCC_IT_CSS                       ((INT8U)0x80)

#ifndef STM32F10X_CL
 #define IS_RCC_IT(IT) ((((IT) & (INT8U)0xE0) == 0x00) && ((IT) != 0x00))
 #define IS_RCC_GET_IT(IT) (((IT) == RCC_IT_LSIRDY) || ((IT) == RCC_IT_LSERDY) || \
                            ((IT) == RCC_IT_HSIRDY) || ((IT) == RCC_IT_HSERDY) || \
                            ((IT) == RCC_IT_PLLRDY) || ((IT) == RCC_IT_CSS))
 #define IS_RCC_CLEAR_IT(IT) ((((IT) & (INT8U)0x60) == 0x00) && ((IT) != 0x00))
#else
 #define RCC_IT_PLL2RDY                  ((INT8U)0x20)
 #define RCC_IT_PLL3RDY                  ((INT8U)0x40)
 #define IS_RCC_IT(IT) ((((IT) & (INT8U)0x80) == 0x00) && ((IT) != 0x00))
 #define IS_RCC_GET_IT(IT) (((IT) == RCC_IT_LSIRDY) || ((IT) == RCC_IT_LSERDY) || \
                            ((IT) == RCC_IT_HSIRDY) || ((IT) == RCC_IT_HSERDY) || \
                            ((IT) == RCC_IT_PLLRDY) || ((IT) == RCC_IT_CSS) || \
                            ((IT) == RCC_IT_PLL2RDY) || ((IT) == RCC_IT_PLL3RDY))
 #define IS_RCC_CLEAR_IT(IT) ((IT) != 0x00)
#endif /* STM32F10X_CL */ 


/**
  * @}
  */

#ifndef STM32F10X_CL
/** @defgroup USB_Device_clock_source 
  * @{
  */

 #define RCC_USBCLKSource_PLLCLK_1Div5   ((INT8U)0x00)
 #define RCC_USBCLKSource_PLLCLK_Div1    ((INT8U)0x01)

 #define IS_RCC_USBCLK_SOURCE(SOURCE) (((SOURCE) == RCC_USBCLKSource_PLLCLK_1Div5) || \
                                      ((SOURCE) == RCC_USBCLKSource_PLLCLK_Div1))
#else
/** @defgroup USB_OTG_FS_clock_source 
  * @{
  */
 #define RCC_OTGFSCLKSource_PLLVCO_Div3    ((INT8U)0x00)
 #define RCC_OTGFSCLKSource_PLLVCO_Div2    ((INT8U)0x01)

 #define IS_RCC_OTGFSCLK_SOURCE(SOURCE) (((SOURCE) == RCC_OTGFSCLKSource_PLLVCO_Div3) || \
                                         ((SOURCE) == RCC_OTGFSCLKSource_PLLVCO_Div2))
#endif /* STM32F10X_CL */ 
/**
  * @}
  */

#ifdef STM32F10X_CL
/** @defgroup I2S2_clock_source 
  * @{
  */
 #define RCC_I2S2CLKSource_SYSCLK        ((INT8U)0x00)
 #define RCC_I2S2CLKSource_PLL3_VCO      ((INT8U)0x01)

 #define IS_RCC_I2S2CLK_SOURCE(SOURCE) (((SOURCE) == RCC_I2S2CLKSource_SYSCLK) || \
                                        ((SOURCE) == RCC_I2S2CLKSource_PLL3_VCO))
/**
  * @}
  */

/** @defgroup I2S3_clock_source 
  * @{
  */
 #define RCC_I2S3CLKSource_SYSCLK        ((INT8U)0x00)
 #define RCC_I2S3CLKSource_PLL3_VCO      ((INT8U)0x01)

 #define IS_RCC_I2S3CLK_SOURCE(SOURCE) (((SOURCE) == RCC_I2S3CLKSource_SYSCLK) || \
                                        ((SOURCE) == RCC_I2S3CLKSource_PLL3_VCO))    
/**
  * @}
  */
#endif /* STM32F10X_CL */  
  

/** @defgroup ADC_clock_source 
  * @{
  */

#define RCC_PCLK2_Div2                   ((INT32U)0x00000000)
#define RCC_PCLK2_Div4                   ((INT32U)0x00004000)
#define RCC_PCLK2_Div6                   ((INT32U)0x00008000)
#define RCC_PCLK2_Div8                   ((INT32U)0x0000C000)
#define IS_RCC_ADCCLK(ADCCLK) (((ADCCLK) == RCC_PCLK2_Div2) || ((ADCCLK) == RCC_PCLK2_Div4) || \
                               ((ADCCLK) == RCC_PCLK2_Div6) || ((ADCCLK) == RCC_PCLK2_Div8))
/**
  * @}
  */

/** @defgroup LSE_configuration 
  * @{
  */

#define RCC_LSE_OFF                      ((INT8U)0x00)
#define RCC_LSE_ON                       ((INT8U)0x01)
#define RCC_LSE_Bypass                   ((INT8U)0x04)
#define IS_RCC_LSE(LSE) (((LSE) == RCC_LSE_OFF) || ((LSE) == RCC_LSE_ON) || \
                         ((LSE) == RCC_LSE_Bypass))
/**
  * @}
  */

/** @defgroup RTC_clock_source 
  * @{
  */

#define RCC_RTCCLKSource_LSE             ((INT32U)0x00000100)
#define RCC_RTCCLKSource_LSI             ((INT32U)0x00000200)
#define RCC_RTCCLKSource_HSE_Div128      ((INT32U)0x00000300)
#define IS_RCC_RTCCLK_SOURCE(SOURCE) (((SOURCE) == RCC_RTCCLKSource_LSE) || \
                                      ((SOURCE) == RCC_RTCCLKSource_LSI) || \
                                      ((SOURCE) == RCC_RTCCLKSource_HSE_Div128))
/**
  * @}
  */

/** @defgroup AHB_peripheral 
  * @{
  */

#define RCC_AHBPeriph_DMA1               ((INT32U)0x00000001)
#define RCC_AHBPeriph_DMA2               ((INT32U)0x00000002)
#define RCC_AHBPeriph_SRAM               ((INT32U)0x00000004)
#define RCC_AHBPeriph_FLITF              ((INT32U)0x00000010)
#define RCC_AHBPeriph_CRC                ((INT32U)0x00000040)

#ifndef STM32F10X_CL
 #define RCC_AHBPeriph_FSMC              ((INT32U)0x00000100)
 #define RCC_AHBPeriph_SDIO              ((INT32U)0x00000400)
 #define IS_RCC_AHB_PERIPH(PERIPH) ((((PERIPH) & 0xFFFFFAA8) == 0x00) && ((PERIPH) != 0x00))
#else
 #define RCC_AHBPeriph_OTG_FS            ((INT32U)0x00001000)
 #define RCC_AHBPeriph_ETH_MAC           ((INT32U)0x00004000)
 #define RCC_AHBPeriph_ETH_MAC_Tx        ((INT32U)0x00008000)
 #define RCC_AHBPeriph_ETH_MAC_Rx        ((INT32U)0x00010000)

 #define IS_RCC_AHB_PERIPH(PERIPH) ((((PERIPH) & 0xFFFE2FA8) == 0x00) && ((PERIPH) != 0x00))
 #define IS_RCC_AHB_PERIPH_RESET(PERIPH) ((((PERIPH) & 0xFFFFAFFF) == 0x00) && ((PERIPH) != 0x00))
#endif /* STM32F10X_CL */
/**
  * @}
  */

/** @defgroup APB2_peripheral 
  * @{
  */

#define RCC_APB2Periph_AFIO              ((INT32U)0x00000001)
#define RCC_APB2Periph_GPIOA             ((INT32U)0x00000004)
#define RCC_APB2Periph_GPIOB             ((INT32U)0x00000008)
#define RCC_APB2Periph_GPIOC             ((INT32U)0x00000010)
#define RCC_APB2Periph_GPIOD             ((INT32U)0x00000020)
#define RCC_APB2Periph_GPIOE             ((INT32U)0x00000040)
#define RCC_APB2Periph_GPIOF             ((INT32U)0x00000080)
#define RCC_APB2Periph_GPIOG             ((INT32U)0x00000100)
#define RCC_APB2Periph_ADC1              ((INT32U)0x00000200)
#define RCC_APB2Periph_ADC2              ((INT32U)0x00000400)
#define RCC_APB2Periph_TIM1              ((INT32U)0x00000800)
#define RCC_APB2Periph_SPI1              ((INT32U)0x00001000)
#define RCC_APB2Periph_TIM8              ((INT32U)0x00002000)
#define RCC_APB2Periph_USART1            ((INT32U)0x00004000)
#define RCC_APB2Periph_ADC3              ((INT32U)0x00008000)

#define IS_RCC_APB2_PERIPH(PERIPH) ((((PERIPH) & 0xFFFF0002) == 0x00) && ((PERIPH) != 0x00))
/**
  * @}
  */ 

/** @defgroup APB1_peripheral 
  * @{
  */

#define RCC_APB1Periph_TIM2              ((INT32U)0x00000001)
#define RCC_APB1Periph_TIM3              ((INT32U)0x00000002)
#define RCC_APB1Periph_TIM4              ((INT32U)0x00000004)
#define RCC_APB1Periph_TIM5              ((INT32U)0x00000008)
#define RCC_APB1Periph_TIM6              ((INT32U)0x00000010)
#define RCC_APB1Periph_TIM7              ((INT32U)0x00000020)
#define RCC_APB1Periph_WWDG              ((INT32U)0x00000800)
#define RCC_APB1Periph_SPI2              ((INT32U)0x00004000)
#define RCC_APB1Periph_SPI3              ((INT32U)0x00008000)
#define RCC_APB1Periph_USART2            ((INT32U)0x00020000)
#define RCC_APB1Periph_USART3            ((INT32U)0x00040000)
#define RCC_APB1Periph_UART4             ((INT32U)0x00080000)
#define RCC_APB1Periph_UART5             ((INT32U)0x00100000)
#define RCC_APB1Periph_I2C1              ((INT32U)0x00200000)
#define RCC_APB1Periph_I2C2              ((INT32U)0x00400000)
#define RCC_APB1Periph_USB               ((INT32U)0x00800000)
#define RCC_APB1Periph_CAN1              ((INT32U)0x02000000)
#define RCC_APB1Periph_BKP               ((INT32U)0x08000000)
#define RCC_APB1Periph_PWR               ((INT32U)0x10000000)
#define RCC_APB1Periph_DAC               ((INT32U)0x20000000)
#define RCC_APB1Periph_CAN2             ((INT32U)0x04000000)
#define IS_RCC_APB1_PERIPH(PERIPH) ((((PERIPH) & 0xC10137C0) == 0x00) && ((PERIPH) != 0x00))

/**
  * @}
  */

/** @defgroup Clock_source_to_output_on_MCO_pin 
  * @{
  */

#define RCC_MCO_NoClock                  ((INT8U)0x00)
#define RCC_MCO_SYSCLK                   ((INT8U)0x04)
#define RCC_MCO_HSI                      ((INT8U)0x05)
#define RCC_MCO_HSE                      ((INT8U)0x06)
#define RCC_MCO_PLLCLK_Div2              ((INT8U)0x07)

#ifndef STM32F10X_CL
 #define IS_RCC_MCO(MCO) (((MCO) == RCC_MCO_NoClock) || ((MCO) == RCC_MCO_HSI) || \
                          ((MCO) == RCC_MCO_SYSCLK)  || ((MCO) == RCC_MCO_HSE) || \
                          ((MCO) == RCC_MCO_PLLCLK_Div2))
#else
 #define RCC_MCO_PLL2CLK                 ((INT8U)0x08)
 #define RCC_MCO_PLL3CLK_Div2            ((INT8U)0x09)
 #define RCC_MCO_XT1                     ((INT8U)0x0A)
 #define RCC_MCO_PLL3CLK                 ((INT8U)0x0B)

 #define IS_RCC_MCO(MCO) (((MCO) == RCC_MCO_NoClock) || ((MCO) == RCC_MCO_HSI) || \
                          ((MCO) == RCC_MCO_SYSCLK)  || ((MCO) == RCC_MCO_HSE) || \
                          ((MCO) == RCC_MCO_PLLCLK_Div2) || ((MCO) == RCC_MCO_PLL2CLK) || \
                          ((MCO) == RCC_MCO_PLL3CLK_Div2) || ((MCO) == RCC_MCO_XT1) || \
                          ((MCO) == RCC_MCO_PLL3CLK))
#endif /* STM32F10X_CL */ 

/**
  * @}
  */

/** @defgroup RCC_Flag 
  * @{
  */

#define RCC_FLAG_HSIRDY                  ((INT8U)0x21)
#define RCC_FLAG_HSERDY                  ((INT8U)0x31)
#define RCC_FLAG_PLLRDY                  ((INT8U)0x39)
#define RCC_FLAG_LSERDY                  ((INT8U)0x41)
#define RCC_FLAG_LSIRDY                  ((INT8U)0x61)
#define RCC_FLAG_PINRST                  ((INT8U)0x7A)
#define RCC_FLAG_PORRST                  ((INT8U)0x7B)
#define RCC_FLAG_SFTRST                  ((INT8U)0x7C)
#define RCC_FLAG_IWDGRST                 ((INT8U)0x7D)
#define RCC_FLAG_WWDGRST                 ((INT8U)0x7E)
#define RCC_FLAG_LPWRRST                 ((INT8U)0x7F)

#ifndef STM32F10X_CL
 #define IS_RCC_FLAG(FLAG) (((FLAG) == RCC_FLAG_HSIRDY) || ((FLAG) == RCC_FLAG_HSERDY) || \
                            ((FLAG) == RCC_FLAG_PLLRDY) || ((FLAG) == RCC_FLAG_LSERDY) || \
                            ((FLAG) == RCC_FLAG_LSIRDY) || ((FLAG) == RCC_FLAG_PINRST) || \
                            ((FLAG) == RCC_FLAG_PORRST) || ((FLAG) == RCC_FLAG_SFTRST) || \
                            ((FLAG) == RCC_FLAG_IWDGRST)|| ((FLAG) == RCC_FLAG_WWDGRST)|| \
                            ((FLAG) == RCC_FLAG_LPWRRST))
#else
 #define RCC_FLAG_PLL2RDY                ((INT8U)0x3B)
 #define RCC_FLAG_PLL3RDY                ((INT8U)0x3D)
 #define IS_RCC_FLAG(FLAG) (((FLAG) == RCC_FLAG_HSIRDY) || ((FLAG) == RCC_FLAG_HSERDY) || \
                            ((FLAG) == RCC_FLAG_PLLRDY) || ((FLAG) == RCC_FLAG_LSERDY) || \
                            ((FLAG) == RCC_FLAG_PLL2RDY) || ((FLAG) == RCC_FLAG_PLL3RDY) || \
                            ((FLAG) == RCC_FLAG_LSIRDY) || ((FLAG) == RCC_FLAG_PINRST) || \
                            ((FLAG) == RCC_FLAG_PORRST) || ((FLAG) == RCC_FLAG_SFTRST) || \
                            ((FLAG) == RCC_FLAG_IWDGRST)|| ((FLAG) == RCC_FLAG_WWDGRST)|| \
                            ((FLAG) == RCC_FLAG_LPWRRST))
#endif /* STM32F10X_CL */ 

#define IS_RCC_CALIBRATION_VALUE(VALUE) ((VALUE) <= 0x1F)
/**
  * @}
  */

/**
  * @}
  */

/** @defgroup RCC_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup RCC_Exported_Functions
  * @{
  */

void RCC_DeInit(void);
void RCC_HSEConfig(INT32U RCC_HSE);
ErrorStatus RCC_WaitForHSEStartUp(void);
void RCC_AdjustHSICalibrationValue(INT8U HSICalibrationValue);
void RCC_HSICmd(FunctionalState NewState);
void RCC_PLLConfig(INT32U RCC_PLLSource, INT32U RCC_PLLMul);
void RCC_PLLCmd(FunctionalState NewState);

#ifdef STM32F10X_CL
 void RCC_PREDIV1Config(INT32U RCC_PREDIV1_Source, INT32U RCC_PREDIV1_Div);
 void RCC_PREDIV2Config(INT32U RCC_PREDIV2_Div);
 void RCC_PLL2Config(INT32U RCC_PLL2Mul);
 void RCC_PLL2Cmd(FunctionalState NewState);
 void RCC_PLL3Config(INT32U RCC_PLL3Mul);
 void RCC_PLL3Cmd(FunctionalState NewState);
#endif /* STM32F10X_CL */ 

void RCC_SYSCLKConfig(INT32U RCC_SYSCLKSource);
INT8U RCC_GetSYSCLKSource(void);
void RCC_HCLKConfig(INT32U RCC_SYSCLK);
void RCC_PCLK1Config(INT32U RCC_HCLK);
void RCC_PCLK2Config(INT32U RCC_HCLK);
void RCC_ITConfig(INT8U RCC_IT, FunctionalState NewState);

#ifndef STM32F10X_CL
 void RCC_USBCLKConfig(INT32U RCC_USBCLKSource);
#else
 void RCC_OTGFSCLKConfig(INT32U RCC_OTGFSCLKSource);
#endif /* STM32F10X_CL */ 

void RCC_ADCCLKConfig(INT32U RCC_PCLK2);

#ifdef STM32F10X_CL
 void RCC_I2S2CLKConfig(INT32U RCC_I2S2CLKSource);
 void RCC_I2S3CLKConfig(INT32U RCC_I2S3CLKSource);
#endif /* STM32F10X_CL */ 

void RCC_LSEConfig(INT8U RCC_LSE);
void RCC_LSICmd(FunctionalState NewState);
void RCC_RTCCLKConfig(INT32U RCC_RTCCLKSource);
void RCC_RTCCLKCmd(FunctionalState NewState);
void RCC_GetClocksFreq(RCC_ClocksTypeDef* RCC_Clocks);
void RCC_AHBPeriphClockCmd(INT32U RCC_AHBPeriph, FunctionalState NewState);
extern void RCC_APB2PeriphClockCmd(INT32U RCC_APB2Periph, FunctionalState NewState);
void RCC_APB1PeriphClockCmd(INT32U RCC_APB1Periph, FunctionalState NewState);

#ifdef STM32F10X_CL
void RCC_AHBPeriphResetCmd(INT32U RCC_AHBPeriph, FunctionalState NewState);
#endif /* STM32F10X_CL */ 

void RCC_APB2PeriphResetCmd(INT32U RCC_APB2Periph, FunctionalState NewState);
void RCC_APB1PeriphResetCmd(INT32U RCC_APB1Periph, FunctionalState NewState);
void RCC_BackupResetCmd(FunctionalState NewState);
void RCC_ClockSecuritySystemCmd(FunctionalState NewState);
void RCC_MCOConfig(INT8U RCC_MCO);
FlagStatus RCC_GetFlagStatus(INT8U RCC_FLAG);
void RCC_ClearFlag(void);
ITStatus RCC_GetITStatus(INT8U RCC_IT);
void RCC_ClearITPendingBit(INT8U RCC_IT);

#ifdef __cplusplus
}
#endif

#endif /* __STM32F10x_RCC_H */
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
