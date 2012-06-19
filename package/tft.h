#ifndef __TFT_H__
#define __TFT_H__

#include "../stm32f103/STM32F10x/stm32f10x.h"

extern void LCD_Init(void);
extern void LCD_Display_Words(INT8U* word_display, INT16U x0, INT16U y0);

#endif
