/**
 *  \file       s3c2440_globle.c
 *  \brief      
 *
 *  \author     fulong\n
 *  Mail:fulong.mo@gmail.com\n
 *  \version:   1.0\n
 *  compiler:GCC\n
 *  \date   Oct 28, 2012
 */
#include "s3c2440_globle.h"
/*****************************************************/
/*usart*/
USART_TypeDef* USART0 =(USART_TypeDef*)UART0_BASE;
USART_TypeDef* USART1 =(USART_TypeDef*)UART1_BASE;
USART_TypeDef* USART2 =(USART_TypeDef*)UART2_BASE;

USARTDATA_TypeDef* USART_DATA0 =(USARTDATA_TypeDef*)UART0DATA_BASE;
USARTDATA_TypeDef* USART_DATA1 =(USARTDATA_TypeDef*)UART1DATA_BASE;
USARTDATA_TypeDef* USART_DATA2 =(USARTDATA_TypeDef*)UART2DATA_BASE;

USARTSTAT_TypeDef* USART_STAT0 =(USARTSTAT_TypeDef*)USAR0STAT_BASE;
USARTSTAT_TypeDef* USART_STAT1 =(USARTSTAT_TypeDef*)UART1STAT_BASE;
USARTSTAT_TypeDef* USART_STAT2 =(USARTSTAT_TypeDef*)UART2STAT_BASE;
/*usart*/
/********************************************************/
