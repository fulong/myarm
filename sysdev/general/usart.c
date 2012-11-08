#include "../../user/user_configure/configure.h"
#if CPU_TYPE == STM32F103VE
#include "../cortex-m3/inc/usart.h"
#include "../cortex-m3/inc/rcc.h"
/* 关于STM32F103VE宏定义 --------------------------------------------------------------*/

#define CR1_UE_Set                ((INT16U)0x2000)  /*!< USART Enable Mask */
#define CR1_UE_Reset              ((INT16U)0xDFFF)  /*!< USART Disable Mask */

#define CR1_WAKE_Mask             ((INT16U)0xF7FF)  /*!< USART WakeUp Method Mask */

#define CR1_RWU_Set               ((INT16U)0x0002)  /*!< USART mute mode Enable Mask */
#define CR1_RWU_Reset             ((INT16U)0xFFFD)  /*!< USART mute mode Enable Mask */
#define CR1_SBK_Set               ((INT16U)0x0001)  /*!< USART Break Character send Mask */
#define CR1_CLEAR_Mask            ((INT16U)0xE9F3)  /*!< USART CR1 Mask */
#define CR2_Address_Mask          ((INT16U)0xFFF0)  /*!< USART address Mask */

#define CR2_LINEN_Set              ((INT16U)0x4000)  /*!< USART LIN Enable Mask */
#define CR2_LINEN_Reset            ((INT16U)0xBFFF)  /*!< USART LIN Disable Mask */

#define CR2_LBDL_Mask             ((INT16U)0xFFDF)  /*!< USART LIN Break detection Mask */
#define CR2_STOP_CLEAR_Mask       ((INT16U)0xCFFF)  /*!< USART CR2 STOP Bits Mask */
#define CR2_CLOCK_CLEAR_Mask      ((INT16U)0xF0FF)  /*!< USART CR2 Clock Mask */

#define CR3_SCEN_Set              ((INT16U)0x0020)  /*!< USART SC Enable Mask */
#define CR3_SCEN_Reset            ((INT16U)0xFFDF)  /*!< USART SC Disable Mask */

#define CR3_NACK_Set              ((INT16U)0x0010)  /*!< USART SC NACK Enable Mask */
#define CR3_NACK_Reset            ((INT16U)0xFFEF)  /*!< USART SC NACK Disable Mask */

#define CR3_HDSEL_Set             ((INT16U)0x0008)  /*!< USART Half-Duplex Enable Mask */
#define CR3_HDSEL_Reset           ((INT16U)0xFFF7)  /*!< USART Half-Duplex Disable Mask */

#define CR3_IRLP_Mask             ((INT16U)0xFFFB)  /*!< USART IrDA LowPower mode Mask */
#define CR3_CLEAR_Mask            ((INT16U)0xFCFF)  /*!< USART CR3 Mask */

#define CR3_IREN_Set              ((INT16U)0x0002)  /*!< USART IrDA Enable Mask */
#define CR3_IREN_Reset            ((INT16U)0xFFFD)  /*!< USART IrDA Disable Mask */
#define GTPR_LSB_Mask             ((INT16U)0x00FF)  /*!< Guard Time Register LSB Mask */
#define GTPR_MSB_Mask             ((INT16U)0xFF00)  /*!< Guard Time Register MSB Mask */
#define IT_Mask                   ((INT16U)0x001F)  /*!< USART Interrupt Mask */
#endif

#if CPU_TYPE == S3C2440
#include "../arm920t/inc/uart.h"

#ifdef TESTING__
#define     PCLK                           50000000
#define UART_CLK                                 PCLK
#define UART_BRD(UART_BAUD_RATE) (UART_CLK / ((UART_BAUD_RATE) * 16)-1)
void uart0_init(INT32U baudrate)
{
	UART0_PORT_SET()
	USART0->ULCON = ULCON0_SET;
	USART0->UCON = UCON_SET;
	USART0->UFCON = UFCON_SET;
	USART0->UMCON = 0; /*关闭流控*/
	UBRDIV0 = UART_BRD(baudrate);
}
#endif
#endif
/**
 * @����  ��� USART_InitStruct ��ָ���Ĳ����ʼ������ USARTx �Ĵ���.
 * @����  USARTx: ѡ�� USART ��Χ�豸.
 *                ���������ȡ����ֵ֮һ: USART1, USART2, USART3, UART4 �� UART5.
 * @����  USART_InitStruct: ָ��ṹ USART_InitTypeDef ��ָ�룬�������� USART ��������Ϣ.
 * @����  û��
 */
INT32U USART_Init(USART_TypeDef* USARTx , USART_InitTypeDef* USART_InitStruct)
{
#if CPU_TYPE == STM32F103VE
	INT32U tmpreg = 0x00, apbclock = 0x00;
	INT32U integerdivider = 0x00;
	INT32U fractionaldivider = 0x00;
	INT32U usartxbase = 0;
	RCC_ClocksTypeDef RCC_ClocksStatus;
	/* The hardware flow control is available only for USART1, USART2 and USART3 */
	usartxbase = (INT32U)USARTx;

	/*---------------------------- USART CR2 Configuration -----------------------*/
	tmpreg = USARTx->CR2;
	/* ��� STOP[13:12] λ */
	tmpreg &= CR2_STOP_CLEAR_Mask;
	/* ���� USART ����λ, ʱ��, ʱ�Ӽ���, ʱ����λ �� ĩλ ------------*/
	/* ���� STOP[13:12] λ������ USART_StopBits ��ֵ */
	tmpreg |= (INT32U)USART_InitStruct->USART_StopBits;

	/* д USART CR2 */
	USARTx->CR2 = (INT16U)tmpreg;

	/*---------------------------- USART CR1 Configuration -----------------------*/
	tmpreg = USARTx->CR1;
	/* ��� M, PCE, PS, TE �� RE λ */
	tmpreg &= CR1_CLEAR_Mask;
	/* ���� USART �ֳ�, ��ż �� ģʽ ----------------------- */
	/* ���� M   λ������ USART_WordLength ��ֵ */
	/* ���� PCE �� PS λ������ USART_Parity ��ֵ */
	/* ���� TE  �� RE λ������ USART_Mode ��ֵ */
	tmpreg |= (INT32U)USART_InitStruct->USART_WordLength | USART_InitStruct->USART_Parity |
	USART_InitStruct->USART_Mode;
	/* д USART CR1 */
	USARTx->CR1 = (INT16U)tmpreg;

	/*---------------------------- USART CR3 Configuration -----------------------*/
	tmpreg = USARTx->CR3;
	/* ��� CTSE �� RTSE λ */
	tmpreg &= CR3_CLEAR_Mask;
	/* ���� USART HFC -------------------------------------------------*/
	/* ���� CTSE �� RTSE λ������ USART_HardwareFlowControl ��ֵ */
	tmpreg |= USART_InitStruct->USART_HardwareFlowControl;
	/* д USART CR3 */
	USARTx->CR3 = (INT16U)tmpreg;

	/*---------------------------- USART BRR Configuration -----------------------*/
	/* ���� USART ������ -------------------------------------------*/
	RCC_GetClocksFreq(&RCC_ClocksStatus);
	if (usartxbase == USART1_BASE)
	{
		apbclock = RCC_ClocksStatus.PCLK2_Frequency;
	}
	else
	{
		apbclock = RCC_ClocksStatus.PCLK1_Frequency;
	}
	/* ȷ������� */
	integerdivider = ((0x19 * apbclock) / (0x04 * (USART_InitStruct->USART_BaudRate)));
	tmpreg = (integerdivider / 0x64) << 0x04;
	/* ȷ������� */
	fractionaldivider = integerdivider - (0x64 * (tmpreg >> 0x04));
	tmpreg |= ((((fractionaldivider * 0x10) + 0x32) / 0x64)) & ((uint8_t)0x0F);
	/* д USART BRR */
	USARTx->BRR = (INT16U)tmpreg;
	return apbclock;
#endif
#if CPU_TYPE == S3C2440
	UART0_PORT_SET()
	USARTx->ULCON = USART_InitStruct->USART_Parity
				+ USART_InitStruct->USART_Mode
				+ USART_InitStruct->USART_StopBits
				+ USART_InitStruct->USART_WordLength;
	if( USARTX != USART2 )
	{
		USARTx->UMCON = USART_InitStruct->USART_HardwareFlowControl;
	}
#endif
}
/**
 * @brief  Transmits single data through the USARTx peripheral.
 * @param  USARTx: Select the USART or the UART peripheral.
 *   This parameter can be one of the following values:
 *   USART1, USART2, USART3, UART4 or UART5.
 * @param  Data: the data to transmit.
 * @retval None
 */
void USART_SendData(USART_TypeDef* USARTx , INT16U Data)
{
#if CPU_TYPE == STM32F103VE
	/* Transmit Data */
	while (!(USARTx->SR & USART_FLAG_TXE));
	USARTx->DR = (Data & (INT16U)0x01FF);
#endif
}
/**
 * @brief  Checks whether the specified USART flag is set or not.
 * @param  USARTx: Select the USART or the UART peripheral.
 *   This parameter can be one of the following values:
 *   USART1, USART2, USART3, UART4 or UART5.
 * @param  USART_FLAG: specifies the flag to check.
 *   This parameter can be one of the following values:
 *     @arg USART_FLAG_CTS:  CTS Change flag (not available for UART4 and UART5)
 *     @arg USART_FLAG_LBD:  LIN Break detection flag
 *     @arg USART_FLAG_TXE:  Transmit data register empty flag
 *     @arg USART_FLAG_TC:   Transmission Complete flag
 *     @arg USART_FLAG_RXNE: Receive data register not empty flag
 *     @arg USART_FLAG_IDLE: Idle Line detection flag
 *     @arg USART_FLAG_ORE:  OverRun Error flag
 *     @arg USART_FLAG_NE:   Noise Error flag
 *     @arg USART_FLAG_FE:   Framing Error flag
 *     @arg USART_FLAG_PE:   Parity Error flag
 * @retval The new state of USART_FLAG (SET or RESET).
 */
FlagStatus USART_GetFlagStatus(USART_TypeDef* USARTx , INT16U USART_FLAG)
{
#if CPU_TYPE == STM32F103VE
	FlagStatus bitstatus = RESET;
	/* Check the parameters */
	//assert_param(IS_USART_ALL_PERIPH(USARTx));
	//assert_param(IS_USART_FLAG(USART_FLAG));
	/* The CTS flag is not available for UART4 and UART5 */
	if (USART_FLAG == USART_FLAG_CTS)
	{
		//assert_param(IS_USART_123_PERIPH(USARTx));
	}

	if ((USARTx->SR & USART_FLAG) != (INT16U)RESET)
	{
		bitstatus = SET;
	}
	else
	{
		bitstatus = RESET;
	}
	return bitstatus;
#endif
}
