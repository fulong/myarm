/**
 *  \file       s3c2440_globle.h
 *  \brief      
 *
 *  \author     fulong\n
 *  Mail:fulong.mo@gmail.com\n
 *  \version:   1.0\n
 *  compiler:GCC\n
 *  \date   Oct 28, 2012 2012
 */


#ifndef S3C2440_GLOBLE_H_
#define S3C2440_GLOBLE_H_

#include "../../user/user_configure/configure.h"
#include "s3c2440.h"
/**
  * @brief usart控制寄存器
  */
typedef struct
{
	__IO INT32U ULCON; /*!< uart线路控制 0*/
	__IO INT32U UCON; /*!< uart控制 4*/
	__IO INT32U UFCON; /*!< uart FIFO控制 8*/
	__IO INT32U UMCON; /*!< uart modem控制 C*/
} USART_TypeDef;
/**
  * @brief usart状态寄存器
  */
typedef struct
{
	__IO INT32U UTRSTAT; /*!< uart Tx/Rx状态 10*/
	__IO INT32U UERSTAT; /*!< uart Rx错误状态 14*/
	__IO INT32U UFSTAT; /*!< uart FIFO状态 18*/
	__IO INT32U UMSTAT; /*!< usart modem状态 1c*/
} USARTSTAT_TypeDef;
/**
  * @brief usart数据发送接受寄存器
  */
typedef struct
{
	__IO INT8U UTXH; /*!< usart 发送保持 20*/
	INT8U RESERVE1;
	INT16U RESERVE2;
	__IO INT8U URXH; /*!< usart 接受缓冲器 24*/
} USARTDATA_TypeDef;

extern USART_TypeDef* USART0;/*!< 控制配置usart0的变量*/
extern USART_TypeDef* USART1;/*!< 控制配置usart1的变量*/
extern USART_TypeDef* USART2;/*!< 控制配置usart2的变量*/

extern USARTDATA_TypeDef* USART_DATA0;/*!< usart0数据发送接受*/
extern USARTDATA_TypeDef* USART_DATA1;/*!< usart1数据发送接受*/
extern USARTDATA_TypeDef* USART_DATA2;/*!< usart2数据发送接受*/

extern USARTSTAT_TypeDef* USART_STAT0;/*!< 查询usart0的状态*/
extern USARTSTAT_TypeDef* USART_STAT1;/*!< 查询usart0的状态*/
extern USARTSTAT_TypeDef* USART_STAT2;/*!< 查询usart0的状态*/



#endif /* S3C2440_GLOBLE_H_ */
