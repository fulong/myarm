#ifndef __S3C2440_H__
#define __S3C2440_H__

#include 	"def.h"
#include 	"../../libc/cpu_typed.h"

// Memory control
#define BWSCON    (*(__IO INT32U *)0x48000000)	//Bus width & wait status
#define BANKCON0  (*(__IO INT32U *)0x48000004)	//Boot ROM control
#define BANKCON1  (*(__IO INT32U *)0x48000008)	//BANK1 control
#define BANKCON2  (*(__IO INT32U *)0x4800000c)	//BANK2 cControl
#define BANKCON3  (*(__IO INT32U *)0x48000010)	//BANK3 control
#define BANKCON4  (*(__IO INT32U *)0x48000014)	//BANK4 control
#define BANKCON5  (*(__IO INT32U *)0x48000018)	//BANK5 control
#define BANKCON6  (*(__IO INT32U *)0x4800001c)	//BANK6 control
#define BANKCON7  (*(__IO INT32U *)0x48000020)	//BANK7 control
#define REFRESH   (*(__IO INT32U *)0x48000024)	//DRAM/SDRAM refresh
#define BANKSIZE  (*(__IO INT32U *)0x48000028)	//Flexible Bank Size
#define MRSRB6    (*(__IO INT32U *)0x4800002c)	//Mode register set for SDRAM
#define MRSRB7    (*(__IO INT32U *)0x48000030)	//Mode register set for SDRAM
// USB Host

// INTERRUPT
#define SRCPND     (*(__IO INT32U *)0x4a000000)	//Interrupt request status
#define INTMOD     (*(__IO INT32U *)0x4a000004)	//Interrupt mode control
#define INTMSK     (*(__IO INT32U *)0x4a000008)	//Interrupt mask control
#define PRIORITY   (*(__IO INT32U *)0x4a00000c)	//IRQ priority control
#define INTPND     (*(__IO INT32U *)0x4a000010)	//Interrupt request status
#define INTOFFSET  (*(__IO INT32U *)0x4a000014)	//Interruot request source offset
#define SUBSRCPND  (*(__IO INT32U *)0x4a000018)	//Sub source pending
#define INTSUBMSK  (*(__IO INT32U *)0x4a00001c)	//Interrupt sub mask
// DMA
#define DISRC0     (*(__IO INT32U *)0x4b000000)	//DMA 0 Initial source
#define DISRCC0    (*(__IO INT32U *)0x4b000004)	//DMA 0 Initial source control
#define DIDST0     (*(__IO INT32U *)0x4b000008)	//DMA 0 Initial Destination
#define DIDSTC0    (*(__IO INT32U *)0x4b00000c)	//DMA 0 Initial Destination control
#define DCON0      (*(__IO INT32U *)0x4b000010)	//DMA 0 Control
#define DSTAT0     (*(__IO INT32U *)0x4b000014)	//DMA 0 Status
#define DCSRC0     (*(__IO INT32U *)0x4b000018)	//DMA 0 Current source
#define DCDST0     (*(__IO INT32U *)0x4b00001c)	//DMA 0 Current destination
#define DMASKTRIG0 (*(__IO INT32U *)0x4b000020)	//DMA 0 Mask trigger
#define DISRC1     (*(__IO INT32U *)0x4b000040)	//DMA 1 Initial source
#define DISRCC1    (*(__IO INT32U *)0x4b000044)	//DMA 1 Initial source control
#define DIDST1     (*(__IO INT32U *)0x4b000048)	//DMA 1 Initial Destination
#define DIDSTC1    (*(__IO INT32U *)0x4b00004c)	//DMA 1 Initial Destination control
#define DCON1      (*(__IO INT32U *)0x4b000050)	//DMA 1 Control
#define DSTAT1     (*(__IO INT32U *)0x4b000054)	//DMA 1 Status
#define DCSRC1     (*(__IO INT32U *)0x4b000058)	//DMA 1 Current source
#define DCDST1     (*(__IO INT32U *)0x4b00005c)	//DMA 1 Current destination
#define DMASKTRIG1 (*(__IO INT32U *)0x4b000060)	//DMA 1 Mask trigger
#define DISRC2     (*(__IO INT32U *)0x4b000080)	//DMA 2 Initial source
#define DISRCC2    (*(__IO INT32U *)0x4b000084)	//DMA 2 Initial source control
#define DIDST2     (*(__IO INT32U *)0x4b000088)	//DMA 2 Initial Destination
#define DIDSTC2    (*(__IO INT32U *)0x4b00008c)	//DMA 2 Initial Destination control
#define DCON2      (*(__IO INT32U *)0x4b000090)	//DMA 2 Control
#define DSTAT2     (*(__IO INT32U *)0x4b000094)	//DMA 2 Status
#define DCSRC2     (*(__IO INT32U *)0x4b000098)	//DMA 2 Current source
#define DCDST2     (*(__IO INT32U *)0x4b00009c)	//DMA 2 Current destination
#define DMASKTRIG2 (*(__IO INT32U *)0x4b0000a0)	//DMA 2 Mask trigger
#define DISRC3     (*(__IO INT32U *)0x4b0000c0)	//DMA 3 Initial source
#define DISRCC3    (*(__IO INT32U *)0x4b0000c4)	//DMA 3 Initial source control
#define DIDST3     (*(__IO INT32U *)0x4b0000c8)	//DMA 3 Initial Destination
#define DIDSTC3    (*(__IO INT32U *)0x4b0000cc)	//DMA 3 Initial Destination control
#define DCON3      (*(__IO INT32U *)0x4b0000d0)	//DMA 3 Control
#define DSTAT3     (*(__IO INT32U *)0x4b0000d4)	//DMA 3 Status
#define DCSRC3     (*(__IO INT32U *)0x4b0000d8)	//DMA 3 Current source
#define DCDST3     (*(__IO INT32U *)0x4b0000dc)	//DMA 3 Current destination
#define DMASKTRIG3 (*(__IO INT32U *)0x4b0000e0)	//DMA 3 Mask trigger
// CLOCK & POWER MANAGEMENT
#define LOCKTIME   (*(__IO INT32U *)0x4c000000)	//PLL lock time counter
#define MPLLCON    (*(__IO INT32U *)0x4c000004)	//MPLL Control
#define UPLLCON    (*(__IO INT32U *)0x4c000008)	//UPLL Control
#define CLKCON     (*(__IO INT32U *)0x4c00000c)	//Clock generator control
#define CLKSLOW    (*(__IO INT32U *)0x4c000010)	//Slow clock control
#define CLKDIVN    (*(__IO INT32U *)0x4c000014)	//Clock divider control
#define CAMDIVN    (*(__IO INT32U *)0x4c000018)	//USB, CAM Clock divider control
// LCD CONTROLLER
#define LCDCON1    (*(__IO INT32U *)0x4d000000)	//LCD control 1
#define LCDCON2    (*(__IO INT32U *)0x4d000004)	//LCD control 2
#define LCDCON3    (*(__IO INT32U *)0x4d000008)	//LCD control 3
#define LCDCON4    (*(__IO INT32U *)0x4d00000c)	//LCD control 4
#define LCDCON5    (*(__IO INT32U *)0x4d000010)	//LCD control 5
#define LCDSADDR1  (*(__IO INT32U *)0x4d000014)	//STN/TFT Frame buffer start address 1
#define LCDSADDR2  (*(__IO INT32U *)0x4d000018)	//STN/TFT Frame buffer start address 2
#define LCDSADDR3  (*(__IO INT32U *)0x4d00001c)	//STN/TFT Virtual screen address set
#define REDLUT     (*(__IO INT32U *)0x4d000020)	//STN Red lookup table
#define GREENLUT   (*(__IO INT32U *)0x4d000024)	//STN Green lookup table
#define BLUELUT    (*(__IO INT32U *)0x4d000028)	//STN Blue lookup table
#define DITHMODE   (*(__IO INT32U *)0x4d00004c)	//STN Dithering mode
#define TPAL       (*(__IO INT32U *)0x4d000050)	//TFT Temporary palette
#define LCDINTPND  (*(__IO INT32U *)0x4d000054)	//LCD Interrupt pending
#define LCDSRCPND  (*(__IO INT32U *)0x4d000058)	//LCD Interrupt source
#define LCDINTMSK  (*(__IO INT32U *)0x4d00005c)	//LCD Interrupt mask
#define TCONSEL     (*(__IO INT32U *)0x4d000060)	//LPC3600 Control --- edited by junon
#define PALETTE     0x4d000400						//Palette start address
//Nand Flash
#define NFCONF		(*(__IO INT32U *)0x4E000000)		//NAND Flash configuration
#define NFCONT		(*(__IO INT32U *)0x4E000004)      //NAND Flash control
#define NFCMD		(*(__IO INT32U *)0x4E000008)      //NAND Flash command
#define NFADDR		(*(__IO INT32U *)0x4E00000C)      //NAND Flash address
#define NFDATA		(*(__IO INT32U *)0x4E000010)      //NAND Flash data
#define NFDATA8	(*(__IO INT32U char *)0x4E000010)     //NAND Flash data
#define NFMECCD0	(*(__IO INT32U *)0x4E000014)      //NAND Flash ECC for Main Area
#define NFMECCD1	(*(__IO INT32U *)0x4E000018)
#define NFSECCD	(*(__IO INT32U *)0x4E00001C)		//NAND Flash ECC for Spare Area
#define NFSTAT		(*(__IO INT32U *)0x4E000020)		//NAND Flash operation status
#define NFESTAT0	(*(__IO INT32U *)0x4E000024)
#define NFESTAT1	(*(__IO INT32U *)0x4E000028)
#define NFMECC0	(*(__IO INT32U *)0x4E00002C)
#define NFMECC1	(*(__IO INT32U *)0x4E000030)
#define NFSECC		(*(__IO INT32U *)0x4E000034)
#define NFSBLK		(*(__IO INT32U *)0x4E000038)		//NAND Flash Start block address
#define NFEBLK		(*(__IO INT32U *)0x4E00003C)		//NAND Flash End block address
//Camera Interface.  Edited for 2440A
#define CISRCFMT           (*(__IO INT32U *)0x4F000000)
#define CIWDOFST           (*(__IO INT32U *)0x4F000004)
#define CIGCTRL            (*(__IO INT32U *)0x4F000008)
#define CICOYSA1           (*(__IO INT32U *)0x4F000018)
#define CICOYSA2           (*(__IO INT32U *)0x4F00001C)
#define CICOYSA3           (*(__IO INT32U *)0x4F000020)
#define CICOYSA4           (*(__IO INT32U *)0x4F000024)
#define CICOCBSA1          (*(__IO INT32U *)0x4F000028)
#define CICOCBSA2          (*(__IO INT32U *)0x4F00002C)
#define CICOCBSA3          (*(__IO INT32U *)0x4F000030)
#define CICOCBSA4          (*(__IO INT32U *)0x4F000034)
#define CICOCRSA1          (*(__IO INT32U *)0x4F000038)
#define CICOCRSA2          (*(__IO INT32U *)0x4F00003C)
#define CICOCRSA3          (*(__IO INT32U *)0x4F000040)
#define CICOCRSA4          (*(__IO INT32U *)0x4F000044)
#define CICOTRGFMT         (*(__IO INT32U *)0x4F000048)
#define CICOCTRL           (*(__IO INT32U *)0x4F00004C)
#define CICOSCPRERATIO     (*(__IO INT32U *)0x4F000050)
#define CICOSCPREDST       (*(__IO INT32U *)0x4F000054)
#define CICOSCCTRL         (*(__IO INT32U *)0x4F000058)
#define CICOTAREA          (*(__IO INT32U *)0x4F00005C)
#define CICOSTATUS         (*(__IO INT32U *)0x4F000064)
#define CIPRCLRSA1         (*(__IO INT32U *)0x4F00006C)
#define CIPRCLRSA2         (*(__IO INT32U *)0x4F000070)
#define CIPRCLRSA3         (*(__IO INT32U *)0x4F000074)
#define CIPRCLRSA4         (*(__IO INT32U *)0x4F000078)
#define CIPRTRGFMT         (*(__IO INT32U *)0x4F00007C)
#define CIPRCTRL           (*(__IO INT32U *)0x4F000080)
#define CIPRSCPRERATIO     (*(__IO INT32U *)0x4F000084)
#define CIPRSCPREDST       (*(__IO INT32U *)0x4F000088)
#define CIPRSCCTRL         (*(__IO INT32U *)0x4F00008C)
#define CIPRTAREA          (*(__IO INT32U *)0x4F000090)
#define CIPRSTATUS         (*(__IO INT32U *)0x4F000098)
#define CIIMGCPT           (*(__IO INT32U *)0x4F0000A0)

// UART
#define UART0_BASE 					0x50000000
#define UART1_BASE 					0x50004000
#define UART2_BASE 					0x50008000
typedef struct
{
	__IO INT32U ULCON; /*!< uart线路控制 0*/
	__IO INT32U UCON; /*!< uart控制 4*/
	__IO INT32U UFCON; /*!< uart FIFO控制 8*/
	__IO INT32U UMCON; /*!< uart modem控制 C*/
} USART_TypeDef;
typedef struct
{
	__IO INT32U UTRSTAT; /*!< uart Tx/Rx状态 10*/
	__IO INT32U UERSTAT; /*!< uart Rx错误状态 14*/
	__IO INT32U UFSTAT; /*!< uart FIFO状态 18*/
	__IO INT32U UMSTAT; /*!< usart modem状态 1c*/
} USARTSTAT_TypeDef;
typedef struct
{
	__IO INT8U UTXH; /*!< usart 发送保持 20*/
	INT8U RESERVE1;
	INT16U RESERVE2;__IO INT8U URXH; /*!< usart 接受缓冲器 24*/
} USARTDATA_TypeDef;
#define UBRDIV0  (*(__IO INT32U *)(UART0_BASE+0x28))	/*!< usart 波特率分频器 28*/
#define UBRDIV1  (*(__IO INT32U *)(UART1_BASE+0x28))	/*!< usart 波特率分频器 28*/
#define UBRDIV2  (*(__IO INT32U *)(UART2_BASE+0x28))	/*!< usart 波特率分频器 28*/

#define UART0DATA_BASE				(UART0_BASE+0x20)
#define UART1DATA_BASE				(UART1_BASE+0x20)
#define UART2DATA_BASE				(UART2_BASE+0x20)

#define USAR0STAT_BASE				(UART0_BASE+0x10)
#define UART1STAT_BASE				(UART1_BASE+0x10)
#define UART2STAT_BASE				(UART2_BASE+0x10)

extern USART_TypeDef* USART0;/*!< 控制配置usart0的变量*/
extern USART_TypeDef* USART1;/*!< 控制配置usart1的变量*/
extern USART_TypeDef* USART2;/*!< 控制配置usart2的变量*/

extern USARTDATA_TypeDef* USART_DATA0;/*!< usart0数据发送接受*/
extern USARTDATA_TypeDef* USART_DATA1;/*!< usart1数据发送接受*/
extern USARTDATA_TypeDef* USART_DATA2;/*!< usart2数据发送接受*/

extern USARTSTAT_TypeDef* USART_STAT0;/*!< 查询usart0的状态*/
extern USARTSTAT_TypeDef* USART_STAT1;/*!< 查询usart0的状态*/
extern USARTSTAT_TypeDef* USART_STAT2;/*!< 查询usart0的状态*/

// PWM TIMER
#define TCFG0  (*(__IO INT32U *)0x51000000)	//Timer 0 configuration
#define TCFG1  (*(__IO INT32U *)0x51000004)	//Timer 1 configuration
#define TCON   (*(__IO INT32U *)0x51000008)	//Timer control
#define TCNTB0 (*(__IO INT32U *)0x5100000c)	//Timer count buffer 0
#define TCMPB0 (*(__IO INT32U *)0x51000010)	//Timer compare buffer 0
#define TCNTO0 (*(__IO INT32U *)0x51000014)	//Timer count observation 0
#define TCNTB1 (*(__IO INT32U *)0x51000018)	//Timer count buffer 1
#define TCMPB1 (*(__IO INT32U *)0x5100001c)	//Timer compare buffer 1
#define TCNTO1 (*(__IO INT32U *)0x51000020)	//Timer count observation 1
#define TCNTB2 (*(__IO INT32U *)0x51000024)	//Timer count buffer 2
#define TCMPB2 (*(__IO INT32U *)0x51000028)	//Timer compare buffer 2
#define TCNTO2 (*(__IO INT32U *)0x5100002c)	//Timer count observation 2
#define TCNTB3 (*(__IO INT32U *)0x51000030)	//Timer count buffer 3
#define TCMPB3 (*(__IO INT32U *)0x51000034)	//Timer compare buffer 3
#define TCNTO3 (*(__IO INT32U *)0x51000038)	//Timer count observation 3
#define TCNTB4 (*(__IO INT32U *)0x5100003c)	//Timer count buffer 4
#define TCNTO4 (*(__IO INT32U *)0x51000040)	//Timer count observation 4
// WATCH DOG TIMER
#define WTCON   (*(__IO INT32U *)0x53000000)	//Watch-dog timer mode
#define WTDAT   (*(__IO INT32U *)0x53000004)	//Watch-dog timer data
#define WTCNT   (*(__IO INT32U *)0x53000008)	//Eatch-dog timer count
// IIC
#define IICCON		(*(__IO INT32U *)0x54000000)	//IIC control
#define IICSTAT	(*(__IO INT32U *)0x54000004)	//IIC status
#define IICADD		(*(__IO INT32U *)0x54000008)	//IIC address
#define IICDS		(*(__IO INT32U *)0x5400000c)	//IIC data shift
#define IICLC		(*(__IO INT32U *)0x54000010)	//IIC multi-master line control
// IIS
#define IISCON  (*(__IO INT32U *)0x55000000)	//IIS Control
#define IISMOD  (*(__IO INT32U *)0x55000004)	//IIS Mode
#define IISPSR  (*(__IO INT32U *)0x55000008)	//IIS Prescaler
#define IISFCON (*(__IO INT32U *)0x5500000c)	//IIS FIFO control
#define IISFIFO  ((__IO INT32U short *)0x55000010)	//IIS FIFO entry
//AC97, Added for S3C2440A
#define AC_GLBCTRL		*(__IO INT32U *)0x5b000000
#define AC_GLBSTAT		*(__IO INT32U *)0x5b000004
#define AC_CODEC_CMD		*(__IO INT32U *)0x5b000008
#define AC_CODEC_STAT		*(__IO INT32U *)0x5b00000C
#define AC_PCMADDR		*(__IO INT32U *)0x5b000010
#define AC_MICADDR		*(__IO INT32U *)0x5b000014
#define AC_PCMDATA		*(__IO INT32U *)0x5b000018
#define AC_MICDATA		*(__IO INT32U *)0x5b00001C

// I/O PORT
#define GPACON    (*(__IO INT32U *)0x56000000)	//Port A control
#define GPADAT    (*(__IO INT32U *)0x56000004)	//Port A data
#define GPBCON    (*(__IO INT32U *)0x56000010)	//Port B control
#define GPBDAT    (*(__IO INT32U *)0x56000014)	//Port B data
#define GPBUP     (*(__IO INT32U *)0x56000018)	//Pull-up control B
#define GPCCON    (*(__IO INT32U *)0x56000020)	//Port C control
#define GPCDAT    (*(__IO INT32U *)0x56000024)	//Port C data
#define GPCUP     (*(__IO INT32U *)0x56000028)	//Pull-up control C
#define GPDCON    (*(__IO INT32U *)0x56000030)	//Port D control
#define GPDDAT    (*(__IO INT32U *)0x56000034)	//Port D data
#define GPDUP     (*(__IO INT32U *)0x56000038)	//Pull-up control D
#define GPECON    (*(__IO INT32U *)0x56000040)	//Port E control
#define GPEDAT    (*(__IO INT32U *)0x56000044)	//Port E data
#define GPEUP     (*(__IO INT32U *)0x56000048)	//Pull-up control E
#define GPFCON    (*(__IO INT32U *)0x56000050)	//Port F control
#define GPFDAT    (*(__IO INT32U *)0x56000054)	//Port F data
#define GPFUP     (*(__IO INT32U *)0x56000058)	//Pull-up control F
#define GPGCON    (*(__IO INT32U *)0x56000060)	//Port G control
#define GPGDAT    (*(__IO INT32U *)0x56000064)	//Port G data
#define GPGUP     (*(__IO INT32U *)0x56000068)	//Pull-up control G
#define GPHCON    (*(__IO INT32U *)0x56000070)	//Port H control
#define GPHDAT    (*(__IO INT32U *)0x56000074)	//Port H data
#define GPHUP     (*(__IO INT32U *)0x56000078)	//Pull-up control H
#define GPJCON    (*(__IO INT32U *)0x560000d0)	//Port J control
#define GPJDAT    (*(__IO INT32U *)0x560000d4)	//Port J data
#define GPJUP     (*(__IO INT32U *)0x560000d8)	//Pull-up control J
#define MISCCR    (*(__IO INT32U *)0x56000080)	//Miscellaneous control
#define DCLKCON   (*(__IO INT32U *)0x56000084)	//DCLK0/1 control
#define EXTINT0   (*(__IO INT32U *)0x56000088)	//External interrupt control register 0
#define EXTINT1   (*(__IO INT32U *)0x5600008c)	//External interrupt control register 1
#define EXTINT2   (*(__IO INT32U *)0x56000090)	//External interrupt control register 2
#define EINTFLT0  (*(__IO INT32U *)0x56000094)	//Reserved
#define EINTFLT1  (*(__IO INT32U *)0x56000098)	//Reserved
#define EINTFLT2  (*(__IO INT32U *)0x5600009c)	//External interrupt filter control register 2
#define EINTFLT3  (*(__IO INT32U *)0x560000a0)	//External interrupt filter control register 3
#define EINTMASK  (*(__IO INT32U *)0x560000a4)	//External interrupt mask
#define EINTPEND  (*(__IO INT32U *)0x560000a8)	//External interrupt pending
#define GSTATUS0  (*(__IO INT32U *)0x560000ac)	//External pin status
#define GSTATUS1  (*(__IO INT32U *)0x560000b0)	//Chip ID(0x32440000)
#define GSTATUS2  (*(__IO INT32U *)0x560000b4)	//Reset type
#define GSTATUS3  (*(__IO INT32U *)0x560000b8)	//Saved data0(32-bit) before entering POWER_OFF mode
#define GSTATUS4  (*(__IO INT32U *)0x560000bc)	//Saved data0(32-bit) before entering POWER_OFF mode
// Added for 2440
#define FLTOUT		(*(__IO INT32U *)0x560000c0)	// Filter output(Read only)
#define DSC0			(*(__IO INT32U *)0x560000c4)	// Strength control register 0
#define DSC1			(*(__IO INT32U *)0x560000c8)	// Strength control register 1
#define MSLCON		(*(__IO INT32U *)0x560000cc)	// Memory sleep control register
#define RTCCON    (*(__IO INT32U char *)0x57000040)	//RTC control
#define TICNT     (*(__IO INT32U char *)0x57000044)	//Tick time count
#define RTCALM    (*(__IO INT32U char *)0x57000050)	//RTC alarm control
#define ALMSEC    (*(__IO INT32U char *)0x57000054)	//Alarm second
#define ALMMIN    (*(__IO INT32U char *)0x57000058)	//Alarm minute
#define ALMHOUR   (*(__IO INT32U char *)0x5700005c)	//Alarm Hour
#define ALMDATE   (*(__IO INT32U char *)0x57000060)	//Alarm date  // edited by junon
#define ALMMON    (*(__IO INT32U char *)0x57000064)	//Alarm month
#define ALMYEAR   (*(__IO INT32U char *)0x57000068)	//Alarm year
#define RTCRST    (*(__IO INT32U char *)0x5700006c)	//RTC round reset
#define BCDSEC    (*(__IO INT32U char *)0x57000070)	//BCD second
#define BCDMIN    (*(__IO INT32U char *)0x57000074)	//BCD minute
#define BCDHOUR   (*(__IO INT32U char *)0x57000078)	//BCD hour
#define BCDDATE   (*(__IO INT32U char *)0x5700007c)	//BCD date  //edited by junon
#define BCDDAY    (*(__IO INT32U char *)0x57000080)	//BCD day   //edited by junon
#define BCDMON    (*(__IO INT32U char *)0x57000084)	//BCD month
#define BCDYEAR   (*(__IO INT32U char *)0x57000088)	//BCD year
// ADC
#define ADCCON    (*(__IO INT32U *)0x58000000)	//ADC control
#define ADCTSC    (*(__IO INT32U *)0x58000004)	//ADC touch screen control
#define ADCDLY    (*(__IO INT32U *)0x58000008)	//ADC start or Interval Delay
#define ADCDAT0   (*(__IO INT32U *)0x5800000c)	//ADC conversion data 0
#define ADCDAT1   (*(__IO INT32U *)0x58000010)	//ADC conversion data 1
#define ADCUPDN   (*(__IO INT32U *)0x58000014)	//Stylus Up/Down interrupt status
// SPI
#define SPCON0    (*(__IO INT32U *)0x59000000)	//SPI0 control
#define SPSTA0    (*(__IO INT32U *)0x59000004)	//SPI0 status
#define SPPIN0    (*(__IO INT32U *)0x59000008)	//SPI0 pin control
#define SPPRE0    (*(__IO INT32U *)0x5900000c)	//SPI0 baud rate prescaler
#define SPTDAT0   (*(__IO INT32U *)0x59000010)	//SPI0 Tx data
#define SPRDAT0   (*(__IO INT32U *)0x59000014)	//SPI0 Rx data
#define SPCON1    (*(__IO INT32U *)0x59000020)	//SPI1 control
#define SPSTA1    (*(__IO INT32U *)0x59000024)	//SPI1 status
#define SPPIN1    (*(__IO INT32U *)0x59000028)	//SPI1 pin control
#define SPPRE1    (*(__IO INT32U *)0x5900002c)	//SPI1 baud rate prescaler
#define SPTDAT1   (*(__IO INT32U *)0x59000030)	//SPI1 Tx data
#define SPRDAT1   (*(__IO INT32U *)0x59000034)	//SPI1 Rx data
// SD Interface
#define SDICON     (*(__IO INT32U *)0x5a000000)	//SDI control
#define SDIPRE     (*(__IO INT32U *)0x5a000004)	//SDI baud rate prescaler
#define SDICARG    (*(__IO INT32U *)0x5a000008)	//SDI command argument
#define SDICCON    (*(__IO INT32U *)0x5a00000c)	//SDI command control
#define SDICSTA    (*(__IO INT32U *)0x5a000010)	//SDI command status
#define SDIRSP0    (*(__IO INT32U *)0x5a000014)	//SDI response 0
#define SDIRSP1    (*(__IO INT32U *)0x5a000018)	//SDI response 1
#define SDIRSP2    (*(__IO INT32U *)0x5a00001c)	//SDI response 2
#define SDIRSP3    (*(__IO INT32U *)0x5a000020)	//SDI response 3
#define SDIDTIMER  (*(__IO INT32U *)0x5a000024)	//SDI data/busy timer
#define SDIBSIZE   (*(__IO INT32U *)0x5a000028)	//SDI block size
#define SDIDCON    (*(__IO INT32U *)0x5a00002c)	//SDI data control
#define SDIDCNT    (*(__IO INT32U *)0x5a000030)	//SDI data remain counter
#define SDIDSTA    (*(__IO INT32U *)0x5a000034)	//SDI data status
#define SDIFSTA    (*(__IO INT32U *)0x5a000038)	//SDI FIFO status
#define SDIIMSK    (*(__IO INT32U *)0x5a00003c)	//SDI interrupt mask. edited for 2440A
#define SDIDAT    (*(__IO INT32U *)0x5a000040)	//SDI data
// Exception vector
#define pISR_RESET		(*(INT32U *)(_ISR_STARTADDRESS+0x0))
#define pISR_UNDEF		(*(INT32U *)(_ISR_STARTADDRESS+0x4))
#define pISR_SWI		(*(INT32U *)(_ISR_STARTADDRESS+0x8))
#define pISR_PABORT		(*(INT32U *)(_ISR_STARTADDRESS+0xc))
#define pISR_DABORT		(*(INT32U *)(_ISR_STARTADDRESS+0x10))
#define pISR_RESERVED	(*(INT32U *)(_ISR_STARTADDRESS+0x14))
#define pISR_IRQ		(*(INT32U *)(_ISR_STARTADDRESS+0x18))
#define pISR_FIQ		(*(INT32U *)(_ISR_STARTADDRESS+0x1c))
// Interrupt vector
#define pISR_EINT0		(*(INT32U *)(_ISR_STARTADDRESS+0x20))
#define pISR_EINT1		(*(INT32U *)(_ISR_STARTADDRESS+0x24))
#define pISR_EINT2		(*(INT32U *)(_ISR_STARTADDRESS+0x28))
#define pISR_EINT3		(*(INT32U *)(_ISR_STARTADDRESS+0x2c))
#define pISR_EINT4_7	(*(INT32U *)(_ISR_STARTADDRESS+0x30))
#define pISR_EINT8_23	(*(INT32U *)(_ISR_STARTADDRESS+0x34))
#define pISR_CAM		(*(INT32U *)(_ISR_STARTADDRESS+0x38))		// Added for 2440.
#define pISR_BAT_FLT	(*(INT32U *)(_ISR_STARTADDRESS+0x3c))
#define pISR_TICK		(*(INT32U *)(_ISR_STARTADDRESS+0x40))
#define pISR_WDT_AC97		(*(INT32U *)(_ISR_STARTADDRESS+0x44))   //Changed to pISR_WDT_AC97 for 2440A
#define pISR_TIMER0	 	(*(INT32U *)(_ISR_STARTADDRESS+0x48))
#define pISR_TIMER1	 	(*(INT32U *)(_ISR_STARTADDRESS+0x4c))
#define pISR_TIMER2		(*(INT32U *)(_ISR_STARTADDRESS+0x50))
#define pISR_TIMER3		(*(INT32U *)(_ISR_STARTADDRESS+0x54))
#define pISR_TIMER4		(*(INT32U *)(_ISR_STARTADDRESS+0x58))
#define pISR_UART2		(*(INT32U *)(_ISR_STARTADDRESS+0x5c))
#define pISR_LCD		(*(INT32U *)(_ISR_STARTADDRESS+0x60))
#define pISR_DMA0		(*(INT32U *)(_ISR_STARTADDRESS+0x64))
#define pISR_DMA1		(*(INT32U *)(_ISR_STARTADDRESS+0x68))
#define pISR_DMA2		(*(INT32U *)(_ISR_STARTADDRESS+0x6c))
#define pISR_DMA3		(*(INT32U *)(_ISR_STARTADDRESS+0x70))
#define pISR_SDI		(*(INT32U *)(_ISR_STARTADDRESS+0x74))
#define pISR_SPI0		(*(INT32U *)(_ISR_STARTADDRESS+0x78))
#define pISR_UART1		(*(INT32U *)(_ISR_STARTADDRESS+0x7c))
#define pISR_NFCON		(*(INT32U *)(_ISR_STARTADDRESS+0x80))		// Added for 2440.
#define pISR_USBD		(*(INT32U *)(_ISR_STARTADDRESS+0x84))
#define pISR_USBH		(*(INT32U *)(_ISR_STARTADDRESS+0x88))
#define pISR_IIC		(*(INT32U *)(_ISR_STARTADDRESS+0x8c))
#define pISR_UART0		(*(INT32U *)(_ISR_STARTADDRESS+0x90))
#define pISR_SPI1		(*(INT32U *)(_ISR_STARTADDRESS+0x94))
#define pISR_RTC		(*(INT32U *)(_ISR_STARTADDRESS+0x98))
#define pISR_ADC		(*(INT32U *)(_ISR_STARTADDRESS+0x9c))

// PENDING BIT
#define BIT_EINT0		(0x1)
#define BIT_EINT1		(0x1<<1)
#define BIT_EINT2		(0x1<<2)
#define BIT_EINT3		(0x1<<3)
#define BIT_EINT4_7		(0x1<<4)
#define BIT_EINT8_23	(0x1<<5)
#define BIT_CAM			(0x1<<6)		// Added for 2440.
#define BIT_BAT_FLT		(0x1<<7)
#define BIT_TICK		(0x1<<8)
#define BIT_WDT_AC97	(0x1<<9)	// Changed from BIT_WDT to BIT_WDT_AC97 for 2440A
#define BIT_TIMER0		(0x1<<10)
#define BIT_TIMER1		(0x1<<11)
#define BIT_TIMER2		(0x1<<12)
#define BIT_TIMER3		(0x1<<13)
#define BIT_TIMER4		(0x1<<14)
#define BIT_UART2		(0x1<<15)
#define BIT_LCD			(0x1<<16)
#define BIT_DMA0		(0x1<<17)
#define BIT_DMA1		(0x1<<18)
#define BIT_DMA2		(0x1<<19)
#define BIT_DMA3		(0x1<<20)
#define BIT_SDI			(0x1<<21)
#define BIT_SPI0		(0x1<<22)
#define BIT_UART1		(0x1<<23)
#define BIT_NFCON		(0x1<<24)		// Added for 2440.
#define BIT_USBD		(0x1<<25)
#define BIT_USBH		(0x1<<26)
#define BIT_IIC			(0x1<<27)
#define BIT_UART0		(0x1<<28)
#define BIT_SPI1		(0x1<<29)
#define BIT_RTC			(0x1<<30)
#define BIT_ADC			(0x1<<31)
#define BIT_ALLMSK		(0xffffffff)

#define BIT_SUB_ALLMSK	(0x7fff)			//Changed from 0x7ff to 0x7fff for 2440A
#define BIT_SUB_AC97	(0x1<<14)		//Added for 2440A
#define BIT_SUB_WDT	(0x1<<13)		//Added for 2440A
#define BIT_SUB_CAM_P	(0x1<<12)		// edited for 2440A.
#define BIT_SUB_CAM_C   (0x1<<11)       // edited for 2440A
#define BIT_SUB_ADC		(0x1<<10)
#define BIT_SUB_TC		(0x1<<9)
#define BIT_SUB_ERR2	(0x1<<8)
#define BIT_SUB_TXD2	(0x1<<7)
#define BIT_SUB_RXD2	(0x1<<6)
#define BIT_SUB_ERR1	(0x1<<5)
#define BIT_SUB_TXD1	(0x1<<4)
#define BIT_SUB_RXD1	(0x1<<3)
#define BIT_SUB_ERR0	(0x1<<2)
#define BIT_SUB_TXD0	(0x1<<1)
#define BIT_SUB_RXD0	(0x1<<0)

#endif  //__2440ADDR_H__
