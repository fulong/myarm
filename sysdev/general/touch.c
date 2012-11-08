/**
 *  \file	touch.c
 *  \brief      
 *
 *  \author 	fulong\n
 *  Mail:fulong.mo@gmail.com\n
 *  \version: 	1.0\n
 *  compiler:GCC\n
 *  \date       2012-5-21 下午5:24:41
 */
#include "../../user/user_configure/configure.h"
#if CPU_TYPE == STM32F103VE
#include "../cortex-m3/inc/touch.h"
#include "../cortex-m3/inc/sys.h"
#endif
#ifdef TSC2046_DEVICE
#include "../../chip/tsc2046.h"
#endif
/*
#ifdef __DEBUG__
#include "../package/usart_package.h"
#endif
*/

void init_touch(void)
{
	INT32U X = 0;
	INT32U Y = 0;
#ifdef TSC2046_DEVICE
	TSC2046_io_init();
 	Read_ADS(&X,&Y);//第一次读取初始化
#endif
/*
#ifdef __DEBUG__
 	printf_num(X,'h');
 	printfs("\r\n");
 	printf_num(Y,'h');
 	printfs("\r\n");
#endif
*/
}

