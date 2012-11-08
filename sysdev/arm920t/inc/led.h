/**
 *  \file       led.h
 *  \brief      
 *
 *  \author     fulong\n
 *  Mail:fulong.mo@gmail.com\n
 *  \version:   1.0\n
 *  compiler:GCC\n
 *  \date   Oct 28, 2012 2012
 */


#ifndef LED_H_
#define LED_H_

#include "../../../user/user_configure/configure.h"
#if CPU_TYPE == STM32F103VE
#include "../stm32f103/STM32F10x/stm32f10x.h"
#endif

extern void LED_Init(void);

#endif /* LED_H_ */
