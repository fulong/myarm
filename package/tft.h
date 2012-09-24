#ifndef __TFT_H__
#define __TFT_H__
#include "../user/user_configure/configure.h"
#include "../libc/cpu_typed.h"
#if CPU_TYPE == STM32F103VE
#include "../cpu/cortex-m3/stm32f103/STM32F10x/stm32f10x.h"
#endif
extern void LCD_Init(void);
extern void LCD_Display_Words(INT8U* word_display, INT16U x0, INT16U y0);

#endif
