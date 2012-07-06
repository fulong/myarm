#include "../inc/rcc.h"
#define CFGR_PLLMull_Mask         ((INT32U)0x003C0000)
#define CFGR_PLLSRC_Mask          ((INT32U)0x00010000)
#define CFGR_PLLXTPRE_Mask        ((INT32U)0x00020000)
#define CFGR_SWS_Mask             ((INT32U)0x0000000C)
#define CFGR_SW_Mask              ((INT32U)0xFFFFFFFC)
#define CFGR_HPRE_Reset_Mask      ((INT32U)0xFFFFFF0F)
#define CFGR_HPRE_Set_Mask        ((INT32U)0x000000F0)
#define CFGR_PPRE1_Reset_Mask     ((INT32U)0xFFFFF8FF)
#define CFGR_PPRE1_Set_Mask       ((INT32U)0x00000700)
#define CFGR_PPRE2_Reset_Mask     ((INT32U)0xFFFFC7FF)
#define CFGR_PPRE2_Set_Mask       ((INT32U)0x00003800)
#define CFGR_ADCPRE_Reset_Mask    ((INT32U)0xFFFF3FFF)
#define CFGR_ADCPRE_Set_Mask      ((INT32U)0x0000C000)

/* �������� --------------------------------------------------------------*/
/* ���ö��� --------------------------------------------------------------*/

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

/* ���ú� -------------------------------------------------------------*/
/* ���ñ��� -----------------------------------------------------------*/
static __I INT8U APBAHBPrescTable[16] = {0, 0, 0, 0, 1, 2, 3, 4, 1, 2, 3, 4, 6, 7, 8, 9};
static __I INT8U ADCPrescTable[4] = {2, 4, 6, 8};
/**
  * @����  ʹ�ܻ�ʧ�ܸ��� APB (APB2) ��Χ�豸ʱ��.
  * @����  RCC_APB2Periph: �����ſ�ʱ�ӵ� AHB2 ��Χ�豸.
  *                        ��������������������ֵ�����:
  *          RCC_APB2Periph_AFIO, RCC_APB2Periph_GPIOA, RCC_APB2Periph_GPIOB,
  *          RCC_APB2Periph_GPIOC, RCC_APB2Periph_GPIOD, RCC_APB2Periph_GPIOE,
  *          RCC_APB2Periph_GPIOF, RCC_APB2Periph_GPIOG, RCC_APB2Periph_ADC1,
  *          RCC_APB2Periph_ADC2, RCC_APB2Periph_TIM1, RCC_APB2Periph_SPI1,
  *          RCC_APB2Periph_TIM8, RCC_APB2Periph_USART1, RCC_APB2Periph_ADC3
  * @����  NewState: ָ����Χ�豸ʱ�ӵ���״̬.
  *                  ����������ȡ: ENABLE �� DISABLE.
  * @����  û��
  */
void RCC_APB2PeriphClockCmd(INT32U RCC_APB2Periph, FunctionalState NewState)
{
  if (NewState != DISABLE)
  {
    RCC->APB2ENR |= RCC_APB2Periph;
  }
  else
  {
    RCC->APB2ENR &= ~RCC_APB2Periph;
  }
}
/**
  * @����  ����Ƭ��ʱ�ӵĲ�ͬƵ��.
  * @����  RCC_Clocks: ָ�����ʱ��Ƶ�ʵ� RCC_ClocksTypeDef �ṹ��ָ��.
  * @����  û��
  */
void RCC_GetClocksFreq(RCC_ClocksTypeDef* RCC_Clocks)
{
  INT32U tmp = 0, pllmull = 0, pllsource = 0, presc = 0;

#ifdef  STM32F10X_CL
  INT32U prediv1source = 0, prediv1factor = 0, prediv2factor = 0, pll2mull = 0;
#endif /* STM32F10X_CL */
    
  /* �õ�ϵͳʱ��Դ -------------------------------------------------------*/
  tmp = RCC->CFGR & CFGR_SWS_Mask;
  
  switch (tmp)
  {
    case 0x00:  /* HSI used as system clock */
      RCC_Clocks->SYSCLK_Frequency = HSI_Value;
      break;
    case 0x04:  /* HSE used as system clock */
      RCC_Clocks->SYSCLK_Frequency = HSE_Value;
      break;
    case 0x08:  /* PLL used as system clock */

      /* �õ� PLL ʱ��Դ�ͱ�Ƶ���� ----------------------*/
      pllmull = RCC->CFGR & CFGR_PLLMull_Mask;
      pllsource = RCC->CFGR & CFGR_PLLSRC_Mask;
      
#ifndef STM32F10X_CL      
      pllmull = ( pllmull >> 18) + 2;
      
      if (pllsource == 0x00)
      {/* HSI ��ʱ�ӵ�2��Ƶ��Ϊ PLL ʱ��Դ */
        RCC_Clocks->SYSCLK_Frequency = (HSI_Value >> 1) * pllmull;
      }
      else
      {/* HSE ��Ϊ PLL ʱ��Դ */
        if ((RCC->CFGR & CFGR_PLLXTPRE_Mask) != (INT32U)RESET)
        {/* HSE ��ʱ�ӱ�2��Ƶ */
          RCC_Clocks->SYSCLK_Frequency = (HSE_Value >> 1) * pllmull;
        }
        else
        {
          RCC_Clocks->SYSCLK_Frequency = HSE_Value * pllmull;
        }
      }
#else
      pllmull = pllmull >> 18;
      
      if (pllmull != 0x0D)
      {
         pllmull += 2;
      }
      else
      { /* PLL ��Ƶ���� = PLL ����ʱ�� * 6.5 */
        pllmull = 13 / 2; 
      }
            
      if (pllsource == 0x00)
      {/* HSI ��ʱ�ӱ�2��Ƶ��Ϊ PLL ʱ��Դ */
        RCC_Clocks->SYSCLK_Frequency = (HSI_Value >> 1) * pllmull;
      }
      else
      {/* PREDIV1 ��Ϊ PLL ʱ��Դ */
        
        /* ָ�� PREDIV1 ʱ��Դ�ͷ�Ƶϵ�� */
        prediv1source = RCC->CFGR2 & CFGR2_PREDIV1SRC;
        prediv1factor = (RCC->CFGR2 & CFGR2_PREDIV1) + 1;
        
        if (prediv1source == 0)
        { /* HSE ��ʱ�ӱ�ѡ����Ϊ PREDIV1 ʱ��Դ */
          RCC_Clocks->SYSCLK_Frequency = (HSE_Value / prediv1factor) * pllmull;          
        }
        else
        {/* PLL2 ʱ����Ϊ PREDIV1 ʱ��Դ */
          
          /* ָ�� PREDIV2 ��Ƶϵ�� �� PLL2 ��Ƶϵ�� */
          prediv2factor = ((RCC->CFGR2 & CFGR2_PREDIV2) >> 4) + 1;
          pll2mull = ((RCC->CFGR2 & CFGR2_PLL2MUL) >> 8 ) + 2; 
          RCC_Clocks->SYSCLK_Frequency = (((HSE_Value / prediv2factor) * pll2mull) / prediv1factor) * pllmull;                         
        }
      }
#endif /* STM32F10X_CL */ 
      break;

    default:
      RCC_Clocks->SYSCLK_Frequency = HSI_Value;
      break;
  }

  /* ���� HCLK, PCLK1, PCLK2 , ADCCLK ʱ��Ƶ�� ----------------*/
  /* �õ� HCLK Ԥ��Ƶ�� */
  tmp = RCC->CFGR & CFGR_HPRE_Set_Mask;
  tmp = tmp >> 4;
  presc = APBAHBPrescTable[tmp];
  /* HCLK ʱ��Ƶ�� */
  RCC_Clocks->HCLK_Frequency = RCC_Clocks->SYSCLK_Frequency >> presc;
  /* �õ� PCLK1 Ԥ��Ƶ�� */
  tmp = RCC->CFGR & CFGR_PPRE1_Set_Mask;
  tmp = tmp >> 8;
  presc = APBAHBPrescTable[tmp];
  /* PCLK1 ʱ��Ƶ�� */
  RCC_Clocks->PCLK1_Frequency = RCC_Clocks->HCLK_Frequency >> presc;
  /* �õ� PCLK2 Ԥ��Ƶ�� */
  tmp = RCC->CFGR & CFGR_PPRE2_Set_Mask;
  tmp = tmp >> 11;
  presc = APBAHBPrescTable[tmp];
  /* PCLK2 ʱ��Ƶ�� */
  RCC_Clocks->PCLK2_Frequency = RCC_Clocks->HCLK_Frequency >> presc;
  /* �õ� ADCCLK Ԥ��Ƶ�� */
  tmp = RCC->CFGR & CFGR_ADCPRE_Set_Mask;
  tmp = tmp >> 14;
  presc = ADCPrescTable[tmp];
  /* ADCCLK ʱ��Ƶ�� */
  RCC_Clocks->ADCCLK_Frequency = RCC_Clocks->PCLK2_Frequency / presc;
}
/**
  * @����  ʹ�ܻ���ʧ�� USART ����.
  * @����  USARTx: ѡ�� USART ���� UART ����Χ�豸. 
  *                �����������������ֵ֮һ : USART1, USART2, USART3, UART4 �� UART5.
  * @����  NewState: USARTx ��Χ�豸����״̬.
  *                  ������������: ENABLE or DISABLE.
  * @����  û��
  */
void USART_Cmd(USART_TypeDef* USARTx, FunctionalState NewState)
{  
  if (NewState != DISABLE)
  {
    /* Enable the selected USART by setting the UE bit in the CR1 register */
    USARTx->CR1 |= CR1_UE_Set;
  }
  else
  {
    /* Disable the selected USART by clearing the UE bit in the CR1 register */
    USARTx->CR1 &= CR1_UE_Reset;
  }
}
/**
  * @����  ʹ�ܻ�ʧ�� AHB ��Χ�豸ʱ��.
  * @����  RCC_AHBPeriph: �����ſ�ʱ�ӵ� AHB ��Χ�豸.
  *   
  *        STM32_����ϵ��΢������, ����������ȡ����ֵ�е�һ��:      
  *                                RCC_AHBPeriph_DMA1
  *                                RCC_AHBPeriph_DMA2
  *                                RCC_AHBPeriph_SRAM
  *                                RCC_AHBPeriph_FLITF
  *                                RCC_AHBPeriph_CRC
  *                                RCC_AHBPeriph_OTG_FS    
  *                                RCC_AHBPeriph_ETH_MAC   
  *                                RCC_AHBPeriph_ETH_MAC_Tx
  *                                RCC_AHBPeriph_ETH_MAC_Rx
  * 
  *           ����_STM32_΢������, ����������ȡ����ֵ�е�һ��:         
  *                                RCC_AHBPeriph_DMA1
  *                                RCC_AHBPeriph_DMA2
  *                                RCC_AHBPeriph_SRAM
  *                                RCC_AHBPeriph_FLITF
  *                                RCC_AHBPeriph_CRC
  *                                RCC_AHBPeriph_FSMC
  *                                RCC_AHBPeriph_SDIO
  *   
  * @ע��  SRAM �� FLITF ʱ��ֻ����˯�ߵ�ģʽ�¿�����Ч.
  * @����  NewState: ָ����Χ�豸ʱ���µ�״̬.
  *                  ����������ȡ: ENABLE �� DISABLE.
  * @����  û��
  */
void RCC_AHBPeriphClockCmd(INT32U RCC_AHBPeriph, FunctionalState NewState)
{
  /* ������ */

  if (NewState != DISABLE)
  {
    RCC->AHBENR |= RCC_AHBPeriph;
  }
  else
  {
    RCC->AHBENR &= ~RCC_AHBPeriph;
  }
}
