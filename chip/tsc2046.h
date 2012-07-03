/**
 *  \file	tsc2046.h
 *  \brief  这个是一个AD转换芯片。这个文件包含着基本操作函数
 *
 *  \author 	fulong\n
 *  Mail:fulong.mo@gmail.com\n
 *  \version: 	1.0\n
 *  compiler:GCC\n
 *  \date       2012-5-23 上午9:26:59
 */


#ifndef TSC2046_H_
#define TSC2046_H_

#include "../user/user_configure/configure.h"
#if CPU_TYPE == STM32F103VE
#include "../cpu/cortex-m3/stm32f103/STM32F10x/stm32f10x.h"
#endif

extern void TSC2046_io_init(void);
extern INT32U Read_ADS(INT32U*x,INT32U*y);
#endif /* TSC2046_H_ */
