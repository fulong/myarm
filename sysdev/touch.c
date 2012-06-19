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
#include "touch.h"
#include "../chip/tsc2046.h"
#include "sys.h"
#ifdef __DEBUG__
#include "../package/usart_package.h"
#endif

void init_touch(void)
{
	INT32U X = 0;
	INT32U Y = 0;
	TSC2046_io_init();
 	Read_ADS(&X,&Y);//第一次读取初始化
#ifdef __DEBUG__
 	printf_num(X,'h');
 	printfs("\r\n");
 	printf_num(Y,'h');
 	printfs("\r\n");
#endif
}

