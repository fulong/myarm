#ifndef CFG_H__
#define CFG_H__
#include "../../libc/cpu_typed.h"
/**
 *  @file	configure.h
 *  @brief      这个文件是配置doxygen中的分组代码，方便以后对注释文档进行维护与控制一些开关宏。\n
 *
 *      能使用的开关宏有:\n
 *          __DEBUG__:当定义这个宏时，将会打印调试信息，并可以使用调试信息的函数。具体可以看debug_package.h\n
 *          PARAM_CHECK:当定义了这个宏，函数将会进行对参数检查，如果开了将会增加函数的健壮性\n
 *          SYSTICK_INT：当需要使用systick中断的时候，打开这个宏，在systick中，配置好\n
 *          TFT_CONTROL_WAY:配置
 *  \author 	fulong\n
 *  Mail:fulong.mo@gmail.com\n
 *  \version: 	1.0\n
 *  compiler:GCC\n
 *  \date      Apr 24, 2012 6:06:29 PM
 */

/** @addtogroup mystm32
 * @{
 */

/** @addtogroup 变量
 * @{
 */
/**@}*/

/** @addtogroup 宏定义
 * @{
 */
/**@}*/

/** @addtogroup typedef类型
 * @{
 */
/**@}*/

/** @addtogroup 函数
 * @{
 */
/**@}*/

/**@}*/

//#define __DEBUG__
#define PARAM_CHECK									 /*函数是否开启参数检查*/
//#define SYSTICK_INT								 /*!< 这个宏为定义的时候，表明systick将用在systick中断中，否则则只为了单纯的轮询延时。 */
//芯片使用
//#define SSD1963_DEVICE							/*!< 使用了SSD1936TFT驱动芯片 */
//#define TSC2046_DEVICE							/*!< 使用了TSC2046驱动芯片 */
/*屏幕的尺寸，配置SSD1963的参数*/
#define TFT_7_0						1
#define TFT_4_3						2
#define NO_TFT							3

#define STM32F103VE									1/*!<  CPU型号，1，是这个型号在程序中的代号，最后下面功能能通用的话，也可以定义这个型号*/
#define S3C2440										2/*!<  CPU型号，2，是这个型号在程序中的代号，但最后下面功能能通用的话，也可以定义这个型号*/
#define CORTEX_A8									3/*!<  CPU型号，3，是这个型号在程序中的代号，但最后下面功能能通用的话，也可以定义这个型号*/

/*TFT屏幕在CPU中的控制方式*/
#define TFT_FSMC								1/*!<  TFT是以FSMC驱动方式，例如在stm中控制*/
#define TFT_LCD_CONTROL						2/*!<  TFT是用专门的LCD控制器控制，例如在ARM9控制*/
#define TFT_SIMULATATION_SINAL					3/*!<  模拟LCD时序控制，这种方式比较慢，如果由上面两种方式，一般会放弃这种*/
#define TFT_NO_CONTROL									0
/*TFT屏幕在CPU中的控制方式*/
//////////////////////////////////////////////////////////////////////////////////
//控制字体库格式显示格式
#define IMAGE_LIB								1/*!< 使用图片文字库 */
#define POINT_LIB								2/*!< 使用点阵文字库 ，这个存在很多bug*/
#define NO_LIB									3
/*屏幕的尺寸，配置SSD1963的参数*/
/*配置SSD1963的像素点格式*/
//#define PIXEL_16B_565
#ifndef PIXEL_16B_565
//#define PIXEL_16B_PACKAGE
#endif
/*配置SSD1963的像素点格式*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////下面的宏开关的值是受上面影响 ///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//TFT大小
#define TFT_SIZE								NO_TFT 				/*TFT_SIZE宏的值可为		1. TFT_7_0
																											2. TFT_4_3
																											3. NO_TFT*/
#if TFT_SIZE != NO_TFT
#define TFT_CONTROL_WAY						TFT_NO_CONTROL    /*TFT_CONTROL_WAY宏的值可为	1. TFT_FSMC
																												2. TFT_LCD_CONTROL
																												3. TFT_SIMULATATION_SINAL
																												4. TFT_NO_CONTROL  */
#endif
//CPU类型
#define CPU_TYPE								S3C2440 				/*CPU_TYPE宏的值可为		1. S3C2440
																											2. CORTEX_A8
																											3. STM32F103VE  */

//配置字体库格式显示格式
#define LIB_FONT								NO_LIB				/*LIB_FONT宏的值可为		1. IMAGE_LIB
																											2. POINT_LIB
																											3. NO_LIB  */

#endif
