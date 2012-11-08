/**
 *  \file	uart.h
 *  \brief      
 *
 *  \author 	fulong\n
 *  Mail:fulong.mo@gmail.com\n
 *  \version: 	1.0\n
 *  compiler:GCC\n
 *  \date       Sep 26, 2012 12:05:26 PM
 */

#ifndef UART_H_
#define UART_H_
#include "../../../user/user_configure/configure.h"
#include "../../../cpu/arm920t/s3c2440.h"
#include "../../../cpu/arm920t/s3c2440_globle.h"
#ifdef TESTING__
#	define TXD0						2		//设为TXD口
#	define RXD0						2		//设为RXD口
#	define STOP_BIT					(0 << 2)//有一位停止位
#	define DATA_BIT					(3 << 0)//有八位数据位
#	define TX_INT_TYPE				(0 << 9)//中断请求类型 0：脉冲，1：边沿
#	define RX_INT_TYPE				(0 << 8)//中断请求类型 0：脉冲，1：边沿
#	define R_TIME_OUT				(0 << 7)//读超时中断请求开关 0：关，1：开
#	define R_ERROR_INT				(0 << 6)//错误，例如，break信号，帧错误，奇偶错误，等中断请求开关 0：关，1：开
#	define SEND_SIGNAL				(0 << 4)//0:正常传输，1：break信号传输
#	define TRANSMIT_MODE			(1 << 2)//中断或查询方式
#	define RRECEIVE_MODE			(1 << 0)//中断或查询方式
#	define TX_FIFO_TRIGGER			(0 << 6)//uart的FIFO发送的触发阀值
#	define RX_FIFO_TRIGGER			(0 << 4)//uart的FIFO发送的触发阀值
#	define TX_FIFO_RESET			(0 << 2)//uart的TXFIFO清空
#	define RX_FIFO_RESET			(0 << 1)//uart的RXFIFO清空
#	define FIFO_ENABLE				(0 << 1)//uart的FIFO发送的触发阀值
#	define UFCON_SET				(FIFO_ENABLE+RX_FIFO_RESET+TX_FIFO_RESET+RX_FIFO_TRIGGER+TX_FIFO_TRIGGER)
#	define UCON_SET					(RRECEIVE_MODE+TRANSMIT_MODE+SEND_SIGNAL+R_ERROR_INT+\
									R_TIME_OUT+RX_INT_TYPE+TX_INT_TYPE)
#	define ULCON0_SET				(STOP_BIT+DATA_BIT)
#	define UART0_PORT_SET()			\
			GPHCON &= ~((3 << 4)+(3 << 6));\
			GPHCON |= ((TXD0 << 4)+(RXD0 << 6));\
			GPHUP  = 0x00;

extern void uart0_init(INT32U baudrate);

#endif
/**
 * @brief  USART Init Structure definition
 */

typedef struct
{
		INT32U USART_BaudRate; /*!< This member configures the USART communication baud rate.
		 The baud rate is computed using the following formula:
		 - IntegerDivider = ((PCLKx) / (16 * (USART_InitStruct->USART_BaudRate)))
		 - FractionalDivider = ((IntegerDivider - ((u32) IntegerDivider)) * 16) + 0.5 */

		INT16U USART_WordLength; /*!< Specifies the number of data bits transmitted or received in a frame.
		 This parameter can be a value of @ref USART_Word_Length */

		INT16U USART_StopBits; /*!< Specifies the number of stop bits transmitted.
		 This parameter can be a value of @ref USART_Stop_Bits */

		INT16U USART_Parity; /*!< Specifies the parity mode.
		 This parameter can be a value of @ref USART_Parity
		 @note When parity is enabled, the computed parity is inserted
		 at the MSB position of the transmitted data (9th bit when
		 the word length is set to 9 data bits; 8th bit when the
		 word length is set to 8 data bits). */

		INT16U USART_Mode; /*!< Specifies wether the Receive or Transmit mode is enabled or disabled.
		 This parameter can be a value of @ref USART_Mode */

		INT16U USART_HardwareFlowControl; /*!< Specifies wether the hardware flow control mode is enabled
		 or disabled.
		 This parameter can be a value of @ref USART_Hardware_Flow_Control */
} USART_InitTypeDef;
/************ULCON*****************/
/**
 * @brief 波特率的取值范围
 */
enum
{
	USART_BaudRate_9600 = 9600, USART_BaudRate_115200 = 112500
} enum_USART_BaudRate;
/**
 * @brief usart的字长
 */
enum
{
	USART_WordLength_5b = (0 << 0)/*!< 发送接收字长为5字节 */,
	USART_WordLength_6b = (1 << 0)/*!< 发送接收字长为6字节 */,
	USART_WordLength_7b = (2 << 0)/*!< 发送接收字长为7字节 */,
	USART_WordLength_8b = (3 << 0)/*!< 发送接收字长为8字节 */
} enum_USART_WordLength;
/**
 * @brief usart每帧的停止位
 */
enum
{
	USART_STOP_1BIT = (0 << 2)/*!< 1位停止位 */, USART_STOP_2BIT = (1 << 2)/*!< 2位停止位 */
} enum_STOP_BIT;
/**
 * @brief usart的奇偶校验
 */
enum
{
	USART_Parity_No = 0 /*!< 没奇偶校验 */,
	USART_Parity_Odd = (4 << 3) /*!< 奇校验 */,
	USART_Parity_Even /*!< 偶校验 */,
	USART_Parity_One /*!< 固定检查奇偶校验为1 */,
	USART_Parity_Zero /*!< 固定检查奇偶校验为0 */
} enum_USART_Parity;
enum
{
	USART_Infrared_MODE_Disable = 0 /*!< 正常模式 */,
	USART_Infrared_MODE_Enable = (1 << 6)/*!< 红外TX，RX模式 */
} enum_USART_Infrared_MODE;
/************ULCON*****************/
/************UMCON*****************/
enum
{
	USART_HardwareFlowControl_None = 0, USART_HardwareFlowControl_Enable = (1
				<< 4)
} enum_USART_HardwareFlowControl;
/************UMCON*****************/
/************UCON*****************/
enum{
	USART_TX_INT_REQ_Level = (1<<9)/*!< TX中断请求是电平触发 */,
	USART_TX_INT_REQ_Pulse = (0<<9)/*!< TX中断请求是脉冲触发 */,
	USART_RX_INT_REQ_Level = (1<<8)/*!< RX中断请求是电平触发 */,
	USART_RX_INT_REQ_Pulse = (0<<8)/*!< RX中断请求是脉冲触发 */,
	USART_RX_Over_Time_Enable
}enum_UCON;
/************UCON*****************/

#endif /* UART_H_ */
