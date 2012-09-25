

#ifndef __S3C2440_H__
#define __S3C2440_H__

#include 	"def.h"

// Memory control
#define BWSCON    (*(volatile unsigned *)0x48000000)	//Bus width & wait status
#define BANKCON0  (*(volatile unsigned *)0x48000004)	//Boot ROM control
#define BANKCON1  (*(volatile unsigned *)0x48000008)	//BANK1 control
#define BANKCON2  (*(volatile unsigned *)0x4800000c)	//BANK2 cControl
#define BANKCON3  (*(volatile unsigned *)0x48000010)	//BANK3 control
#define BANKCON4  (*(volatile unsigned *)0x48000014)	//BANK4 control
#define BANKCON5  (*(volatile unsigned *)0x48000018)	//BANK5 control
#define BANKCON6  (*(volatile unsigned *)0x4800001c)	//BANK6 control
#define BANKCON7  (*(volatile unsigned *)0x48000020)	//BANK7 control
#define REFRESH   (*(volatile unsigned *)0x48000024)	//DRAM/SDRAM refresh
#define BANKSIZE  (*(volatile unsigned *)0x48000028)	//Flexible Bank Size
#define MRSRB6    (*(volatile unsigned *)0x4800002c)	//Mode register set for SDRAM
#define MRSRB7    (*(volatile unsigned *)0x48000030)	//Mode register set for SDRAM

// USB Host


// INTERRUPT
#define SRCPND     (*(volatile unsigned *)0x4a000000)	//Interrupt request status
#define INTMOD     (*(volatile unsigned *)0x4a000004)	//Interrupt mode control
#define INTMSK     (*(volatile unsigned *)0x4a000008)	//Interrupt mask control
#define PRIORITY   (*(volatile unsigned *)0x4a00000c)	//IRQ priority control
#define INTPND     (*(volatile unsigned *)0x4a000010)	//Interrupt request status
#define INTOFFSET  (*(volatile unsigned *)0x4a000014)	//Interruot request source offset
#define SUBSRCPND  (*(volatile unsigned *)0x4a000018)	//Sub source pending
#define INTSUBMSK  (*(volatile unsigned *)0x4a00001c)	//Interrupt sub mask

// DMA
#define DISRC0     (*(volatile unsigned *)0x4b000000)	//DMA 0 Initial source
#define DISRCC0    (*(volatile unsigned *)0x4b000004)	//DMA 0 Initial source control
#define DIDST0     (*(volatile unsigned *)0x4b000008)	//DMA 0 Initial Destination
#define DIDSTC0    (*(volatile unsigned *)0x4b00000c)	//DMA 0 Initial Destination control
#define DCON0      (*(volatile unsigned *)0x4b000010)	//DMA 0 Control
#define DSTAT0     (*(volatile unsigned *)0x4b000014)	//DMA 0 Status
#define DCSRC0     (*(volatile unsigned *)0x4b000018)	//DMA 0 Current source
#define DCDST0     (*(volatile unsigned *)0x4b00001c)	//DMA 0 Current destination
#define DMASKTRIG0 (*(volatile unsigned *)0x4b000020)	//DMA 0 Mask trigger

#define DISRC1     (*(volatile unsigned *)0x4b000040)	//DMA 1 Initial source
#define DISRCC1    (*(volatile unsigned *)0x4b000044)	//DMA 1 Initial source control
#define DIDST1     (*(volatile unsigned *)0x4b000048)	//DMA 1 Initial Destination
#define DIDSTC1    (*(volatile unsigned *)0x4b00004c)	//DMA 1 Initial Destination control
#define DCON1      (*(volatile unsigned *)0x4b000050)	//DMA 1 Control
#define DSTAT1     (*(volatile unsigned *)0x4b000054)	//DMA 1 Status
#define DCSRC1     (*(volatile unsigned *)0x4b000058)	//DMA 1 Current source
#define DCDST1     (*(volatile unsigned *)0x4b00005c)	//DMA 1 Current destination
#define DMASKTRIG1 (*(volatile unsigned *)0x4b000060)	//DMA 1 Mask trigger

#define DISRC2     (*(volatile unsigned *)0x4b000080)	//DMA 2 Initial source
#define DISRCC2    (*(volatile unsigned *)0x4b000084)	//DMA 2 Initial source control
#define DIDST2     (*(volatile unsigned *)0x4b000088)	//DMA 2 Initial Destination
#define DIDSTC2    (*(volatile unsigned *)0x4b00008c)	//DMA 2 Initial Destination control
#define DCON2      (*(volatile unsigned *)0x4b000090)	//DMA 2 Control
#define DSTAT2     (*(volatile unsigned *)0x4b000094)	//DMA 2 Status
#define DCSRC2     (*(volatile unsigned *)0x4b000098)	//DMA 2 Current source
#define DCDST2     (*(volatile unsigned *)0x4b00009c)	//DMA 2 Current destination
#define DMASKTRIG2 (*(volatile unsigned *)0x4b0000a0)	//DMA 2 Mask trigger

#define DISRC3     (*(volatile unsigned *)0x4b0000c0)	//DMA 3 Initial source
#define DISRCC3    (*(volatile unsigned *)0x4b0000c4)	//DMA 3 Initial source control
#define DIDST3     (*(volatile unsigned *)0x4b0000c8)	//DMA 3 Initial Destination
#define DIDSTC3    (*(volatile unsigned *)0x4b0000cc)	//DMA 3 Initial Destination control
#define DCON3      (*(volatile unsigned *)0x4b0000d0)	//DMA 3 Control
#define DSTAT3     (*(volatile unsigned *)0x4b0000d4)	//DMA 3 Status
#define DCSRC3     (*(volatile unsigned *)0x4b0000d8)	//DMA 3 Current source
#define DCDST3     (*(volatile unsigned *)0x4b0000dc)	//DMA 3 Current destination
#define DMASKTRIG3 (*(volatile unsigned *)0x4b0000e0)	//DMA 3 Mask trigger


// CLOCK & POWER MANAGEMENT
#define LOCKTIME   (*(volatile unsigned *)0x4c000000)	//PLL lock time counter
#define MPLLCON    (*(volatile unsigned *)0x4c000004)	//MPLL Control
#define UPLLCON    (*(volatile unsigned *)0x4c000008)	//UPLL Control
#define CLKCON     (*(volatile unsigned *)0x4c00000c)	//Clock generator control
#define CLKSLOW    (*(volatile unsigned *)0x4c000010)	//Slow clock control
#define CLKDIVN    (*(volatile unsigned *)0x4c000014)	//Clock divider control
#define CAMDIVN    (*(volatile unsigned *)0x4c000018)	//USB, CAM Clock divider control


// LCD CONTROLLER
#define LCDCON1    (*(volatile unsigned *)0x4d000000)	//LCD control 1
#define LCDCON2    (*(volatile unsigned *)0x4d000004)	//LCD control 2
#define LCDCON3    (*(volatile unsigned *)0x4d000008)	//LCD control 3
#define LCDCON4    (*(volatile unsigned *)0x4d00000c)	//LCD control 4
#define LCDCON5    (*(volatile unsigned *)0x4d000010)	//LCD control 5
#define LCDSADDR1  (*(volatile unsigned *)0x4d000014)	//STN/TFT Frame buffer start address 1
#define LCDSADDR2  (*(volatile unsigned *)0x4d000018)	//STN/TFT Frame buffer start address 2
#define LCDSADDR3  (*(volatile unsigned *)0x4d00001c)	//STN/TFT Virtual screen address set
#define REDLUT     (*(volatile unsigned *)0x4d000020)	//STN Red lookup table
#define GREENLUT   (*(volatile unsigned *)0x4d000024)	//STN Green lookup table
#define BLUELUT    (*(volatile unsigned *)0x4d000028)	//STN Blue lookup table
#define DITHMODE   (*(volatile unsigned *)0x4d00004c)	//STN Dithering mode
#define TPAL       (*(volatile unsigned *)0x4d000050)	//TFT Temporary palette
#define LCDINTPND  (*(volatile unsigned *)0x4d000054)	//LCD Interrupt pending
#define LCDSRCPND  (*(volatile unsigned *)0x4d000058)	//LCD Interrupt source
#define LCDINTMSK  (*(volatile unsigned *)0x4d00005c)	//LCD Interrupt mask
#define TCONSEL     (*(volatile unsigned *)0x4d000060)	//LPC3600 Control --- edited by junon
#define PALETTE     0x4d000400						//Palette start address


//Nand Flash
#define NFCONF		(*(volatile unsigned *)0x4E000000)		//NAND Flash configuration
#define NFCONT		(*(volatile unsigned *)0x4E000004)      //NAND Flash control
#define NFCMD		(*(volatile unsigned *)0x4E000008)      //NAND Flash command
#define NFADDR		(*(volatile unsigned *)0x4E00000C)      //NAND Flash address
#define NFDATA		(*(volatile unsigned *)0x4E000010)      //NAND Flash data
#define NFDATA8	(*(volatile unsigned char *)0x4E000010)     //NAND Flash data
#define NFMECCD0	(*(volatile unsigned *)0x4E000014)      //NAND Flash ECC for Main Area
#define NFMECCD1	(*(volatile unsigned *)0x4E000018)
#define NFSECCD	(*(volatile unsigned *)0x4E00001C)		//NAND Flash ECC for Spare Area
#define NFSTAT		(*(volatile unsigned *)0x4E000020)		//NAND Flash operation status
#define NFESTAT0	(*(volatile unsigned *)0x4E000024)
#define NFESTAT1	(*(volatile unsigned *)0x4E000028)
#define NFMECC0	(*(volatile unsigned *)0x4E00002C)
#define NFMECC1	(*(volatile unsigned *)0x4E000030)
#define NFSECC		(*(volatile unsigned *)0x4E000034)
#define NFSBLK		(*(volatile unsigned *)0x4E000038)		//NAND Flash Start block address
#define NFEBLK		(*(volatile unsigned *)0x4E00003C)		//NAND Flash End block address


//Camera Interface.  Edited for 2440A
#define CISRCFMT           (*(volatile unsigned *)0x4F000000)
#define CIWDOFST           (*(volatile unsigned *)0x4F000004)
#define CIGCTRL            (*(volatile unsigned *)0x4F000008)
#define CICOYSA1           (*(volatile unsigned *)0x4F000018)
#define CICOYSA2           (*(volatile unsigned *)0x4F00001C)
#define CICOYSA3           (*(volatile unsigned *)0x4F000020)
#define CICOYSA4           (*(volatile unsigned *)0x4F000024)
#define CICOCBSA1          (*(volatile unsigned *)0x4F000028)
#define CICOCBSA2          (*(volatile unsigned *)0x4F00002C)
#define CICOCBSA3          (*(volatile unsigned *)0x4F000030)
#define CICOCBSA4          (*(volatile unsigned *)0x4F000034)
#define CICOCRSA1          (*(volatile unsigned *)0x4F000038)
#define CICOCRSA2          (*(volatile unsigned *)0x4F00003C)
#define CICOCRSA3          (*(volatile unsigned *)0x4F000040)
#define CICOCRSA4          (*(volatile unsigned *)0x4F000044)
#define CICOTRGFMT         (*(volatile unsigned *)0x4F000048)
#define CICOCTRL           (*(volatile unsigned *)0x4F00004C)
#define CICOSCPRERATIO     (*(volatile unsigned *)0x4F000050)
#define CICOSCPREDST       (*(volatile unsigned *)0x4F000054)
#define CICOSCCTRL         (*(volatile unsigned *)0x4F000058)
#define CICOTAREA          (*(volatile unsigned *)0x4F00005C)
#define CICOSTATUS         (*(volatile unsigned *)0x4F000064)
#define CIPRCLRSA1         (*(volatile unsigned *)0x4F00006C)
#define CIPRCLRSA2         (*(volatile unsigned *)0x4F000070)
#define CIPRCLRSA3         (*(volatile unsigned *)0x4F000074)
#define CIPRCLRSA4         (*(volatile unsigned *)0x4F000078)
#define CIPRTRGFMT         (*(volatile unsigned *)0x4F00007C)
#define CIPRCTRL           (*(volatile unsigned *)0x4F000080)
#define CIPRSCPRERATIO     (*(volatile unsigned *)0x4F000084)
#define CIPRSCPREDST       (*(volatile unsigned *)0x4F000088)
#define CIPRSCCTRL         (*(volatile unsigned *)0x4F00008C)
#define CIPRTAREA          (*(volatile unsigned *)0x4F000090)
#define CIPRSTATUS         (*(volatile unsigned *)0x4F000098)
#define CIIMGCPT           (*(volatile unsigned *)0x4F0000A0)

// UART
#define ULCON0     (*(volatile unsigned *)0x50000000)	//UART 0 Line control
#define UCON0      (*(volatile unsigned *)0x50000004)	//UART 0 Control
#define UFCON0     (*(volatile unsigned *)0x50000008)	//UART 0 FIFO control
#define UMCON0     (*(volatile unsigned *)0x5000000c)	//UART 0 Modem control
#define UTRSTAT0   (*(volatile unsigned *)0x50000010)	//UART 0 Tx/Rx status
#define UERSTAT0   (*(volatile unsigned *)0x50000014)	//UART 0 Rx error status
#define UFSTAT0    (*(volatile unsigned *)0x50000018)	//UART 0 FIFO status
#define UMSTAT0    (*(volatile unsigned *)0x5000001c)	//UART 0 Modem status
#define UBRDIV0    (*(volatile unsigned *)0x50000028)	//UART 0 Baud rate divisor

#define ULCON1     (*(volatile unsigned *)0x50004000)	//UART 1 Line control
#define UCON1      (*(volatile unsigned *)0x50004004)	//UART 1 Control
#define UFCON1     (*(volatile unsigned *)0x50004008)	//UART 1 FIFO control
#define UMCON1     (*(volatile unsigned *)0x5000400c)	//UART 1 Modem control
#define UTRSTAT1   (*(volatile unsigned *)0x50004010)	//UART 1 Tx/Rx status
#define UERSTAT1   (*(volatile unsigned *)0x50004014)	//UART 1 Rx error status
#define UFSTAT1    (*(volatile unsigned *)0x50004018)	//UART 1 FIFO status
#define UMSTAT1    (*(volatile unsigned *)0x5000401c)	//UART 1 Modem status
#define UBRDIV1    (*(volatile unsigned *)0x50004028)	//UART 1 Baud rate divisor
#define ULCON2     (*(volatile unsigned *)0x50008000)	//UART 2 Line control
#define UCON2      (*(volatile unsigned *)0x50008004)	//UART 2 Control
#define UFCON2     (*(volatile unsigned *)0x50008008)	//UART 2 FIFO control
#define UMCON2     (*(volatile unsigned *)0x5000800c)	//UART 2 Modem control
#define UTRSTAT2   (*(volatile unsigned *)0x50008010)	//UART 2 Tx/Rx status
#define UERSTAT2   (*(volatile unsigned *)0x50008014)	//UART 2 Rx error status
#define UFSTAT2    (*(volatile unsigned *)0x50008018)	//UART 2 FIFO status
#define UMSTAT2    (*(volatile unsigned *)0x5000801c)	//UART 2 Modem status
#define UBRDIV2    (*(volatile unsigned *)0x50008028)	//UART 2 Baud rate divisor


#define UTXH0 (*(volatile unsigned char *)0x50000020)	//UART 0 Transmission Hold
#define URXH0 (*(volatile unsigned char *)0x50000024)	//UART 0 Receive buffer
#define UTXH1 (*(volatile unsigned char *)0x50004020)	//UART 1 Transmission Hold
#define URXH1 (*(volatile unsigned char *)0x50004024)	//UART 1 Receive buffer
#define UTXH2 (*(volatile unsigned char *)0x50008020)	//UART 2 Transmission Hold
#define URXH2 (*(volatile unsigned char *)0x50008024)	//UART 2 Receive buffer



// PWM TIMER
#define TCFG0  (*(volatile unsigned *)0x51000000)	//Timer 0 configuration
#define TCFG1  (*(volatile unsigned *)0x51000004)	//Timer 1 configuration
#define TCON   (*(volatile unsigned *)0x51000008)	//Timer control
#define TCNTB0 (*(volatile unsigned *)0x5100000c)	//Timer count buffer 0
#define TCMPB0 (*(volatile unsigned *)0x51000010)	//Timer compare buffer 0
#define TCNTO0 (*(volatile unsigned *)0x51000014)	//Timer count observation 0
#define TCNTB1 (*(volatile unsigned *)0x51000018)	//Timer count buffer 1
#define TCMPB1 (*(volatile unsigned *)0x5100001c)	//Timer compare buffer 1
#define TCNTO1 (*(volatile unsigned *)0x51000020)	//Timer count observation 1
#define TCNTB2 (*(volatile unsigned *)0x51000024)	//Timer count buffer 2
#define TCMPB2 (*(volatile unsigned *)0x51000028)	//Timer compare buffer 2
#define TCNTO2 (*(volatile unsigned *)0x5100002c)	//Timer count observation 2
#define TCNTB3 (*(volatile unsigned *)0x51000030)	//Timer count buffer 3
#define TCMPB3 (*(volatile unsigned *)0x51000034)	//Timer compare buffer 3
#define TCNTO3 (*(volatile unsigned *)0x51000038)	//Timer count observation 3
#define TCNTB4 (*(volatile unsigned *)0x5100003c)	//Timer count buffer 4
#define TCNTO4 (*(volatile unsigned *)0x51000040)	//Timer count observation 4





// WATCH DOG TIMER
#define WTCON   (*(volatile unsigned *)0x53000000)	//Watch-dog timer mode
#define WTDAT   (*(volatile unsigned *)0x53000004)	//Watch-dog timer data
#define WTCNT   (*(volatile unsigned *)0x53000008)	//Eatch-dog timer count


// IIC
#define IICCON		(*(volatile unsigned *)0x54000000)	//IIC control
#define IICSTAT	(*(volatile unsigned *)0x54000004)	//IIC status
#define IICADD		(*(volatile unsigned *)0x54000008)	//IIC address
#define IICDS		(*(volatile unsigned *)0x5400000c)	//IIC data shift
#define IICLC		(*(volatile unsigned *)0x54000010)	//IIC multi-master line control


// IIS
#define IISCON  (*(volatile unsigned *)0x55000000)	//IIS Control
#define IISMOD  (*(volatile unsigned *)0x55000004)	//IIS Mode
#define IISPSR  (*(volatile unsigned *)0x55000008)	//IIS Prescaler
#define IISFCON (*(volatile unsigned *)0x5500000c)	//IIS FIFO control

#define IISFIFO  ((volatile unsigned short *)0x55000010)	//IIS FIFO entry


//AC97, Added for S3C2440A
#define AC_GLBCTRL		*(volatile unsigned *)0x5b000000
#define AC_GLBSTAT		*(volatile unsigned *)0x5b000004
#define AC_CODEC_CMD		*(volatile unsigned *)0x5b000008
#define AC_CODEC_STAT		*(volatile unsigned *)0x5b00000C
#define AC_PCMADDR		*(volatile unsigned *)0x5b000010
#define AC_MICADDR		*(volatile unsigned *)0x5b000014
#define AC_PCMDATA		*(volatile unsigned *)0x5b000018
#define AC_MICDATA		*(volatile unsigned *)0x5b00001C



// I/O PORT
#define GPACON    (*(volatile unsigned *)0x56000000)	//Port A control
#define GPADAT    (*(volatile unsigned *)0x56000004)	//Port A data

#define GPBCON    (*(volatile unsigned *)0x56000010)	//Port B control
#define GPBDAT    (*(volatile unsigned *)0x56000014)	//Port B data
#define GPBUP     (*(volatile unsigned *)0x56000018)	//Pull-up control B

#define GPCCON    (*(volatile unsigned *)0x56000020)	//Port C control
#define GPCDAT    (*(volatile unsigned *)0x56000024)	//Port C data
#define GPCUP     (*(volatile unsigned *)0x56000028)	//Pull-up control C

#define GPDCON    (*(volatile unsigned *)0x56000030)	//Port D control
#define GPDDAT    (*(volatile unsigned *)0x56000034)	//Port D data
#define GPDUP     (*(volatile unsigned *)0x56000038)	//Pull-up control D

#define GPECON    (*(volatile unsigned *)0x56000040)	//Port E control
#define GPEDAT    (*(volatile unsigned *)0x56000044)	//Port E data
#define GPEUP     (*(volatile unsigned *)0x56000048)	//Pull-up control E

#define GPFCON    (*(volatile unsigned *)0x56000050)	//Port F control
#define GPFDAT    (*(volatile unsigned *)0x56000054)	//Port F data
#define GPFUP     (*(volatile unsigned *)0x56000058)	//Pull-up control F

#define GPGCON    (*(volatile unsigned *)0x56000060)	//Port G control
#define GPGDAT    (*(volatile unsigned *)0x56000064)	//Port G data
#define GPGUP     (*(volatile unsigned *)0x56000068)	//Pull-up control G

#define GPHCON    (*(volatile unsigned *)0x56000070)	//Port H control
#define GPHDAT    (*(volatile unsigned *)0x56000074)	//Port H data
#define GPHUP     (*(volatile unsigned *)0x56000078)	//Pull-up control H

#define GPJCON    (*(volatile unsigned *)0x560000d0)	//Port J control
#define GPJDAT    (*(volatile unsigned *)0x560000d4)	//Port J data
#define GPJUP     (*(volatile unsigned *)0x560000d8)	//Pull-up control J

#define MISCCR    (*(volatile unsigned *)0x56000080)	//Miscellaneous control
#define DCLKCON   (*(volatile unsigned *)0x56000084)	//DCLK0/1 control
#define EXTINT0   (*(volatile unsigned *)0x56000088)	//External interrupt control register 0
#define EXTINT1   (*(volatile unsigned *)0x5600008c)	//External interrupt control register 1
#define EXTINT2   (*(volatile unsigned *)0x56000090)	//External interrupt control register 2
#define EINTFLT0  (*(volatile unsigned *)0x56000094)	//Reserved
#define EINTFLT1  (*(volatile unsigned *)0x56000098)	//Reserved
#define EINTFLT2  (*(volatile unsigned *)0x5600009c)	//External interrupt filter control register 2
#define EINTFLT3  (*(volatile unsigned *)0x560000a0)	//External interrupt filter control register 3
#define EINTMASK  (*(volatile unsigned *)0x560000a4)	//External interrupt mask
#define EINTPEND  (*(volatile unsigned *)0x560000a8)	//External interrupt pending
#define GSTATUS0  (*(volatile unsigned *)0x560000ac)	//External pin status
#define GSTATUS1  (*(volatile unsigned *)0x560000b0)	//Chip ID(0x32440000)
#define GSTATUS2  (*(volatile unsigned *)0x560000b4)	//Reset type
#define GSTATUS3  (*(volatile unsigned *)0x560000b8)	//Saved data0(32-bit) before entering POWER_OFF mode
#define GSTATUS4  (*(volatile unsigned *)0x560000bc)	//Saved data0(32-bit) before entering POWER_OFF mode

// Added for 2440
#define FLTOUT		(*(volatile unsigned *)0x560000c0)	// Filter output(Read only)
#define DSC0			(*(volatile unsigned *)0x560000c4)	// Strength control register 0
#define DSC1			(*(volatile unsigned *)0x560000c8)	// Strength control register 1
#define MSLCON		(*(volatile unsigned *)0x560000cc)	// Memory sleep control register

#define RTCCON    (*(volatile unsigned char *)0x57000040)	//RTC control
#define TICNT     (*(volatile unsigned char *)0x57000044)	//Tick time count
#define RTCALM    (*(volatile unsigned char *)0x57000050)	//RTC alarm control
#define ALMSEC    (*(volatile unsigned char *)0x57000054)	//Alarm second
#define ALMMIN    (*(volatile unsigned char *)0x57000058)	//Alarm minute
#define ALMHOUR   (*(volatile unsigned char *)0x5700005c)	//Alarm Hour
#define ALMDATE   (*(volatile unsigned char *)0x57000060)	//Alarm date  // edited by junon
#define ALMMON    (*(volatile unsigned char *)0x57000064)	//Alarm month
#define ALMYEAR   (*(volatile unsigned char *)0x57000068)	//Alarm year
#define RTCRST    (*(volatile unsigned char *)0x5700006c)	//RTC round reset
#define BCDSEC    (*(volatile unsigned char *)0x57000070)	//BCD second
#define BCDMIN    (*(volatile unsigned char *)0x57000074)	//BCD minute
#define BCDHOUR   (*(volatile unsigned char *)0x57000078)	//BCD hour
#define BCDDATE   (*(volatile unsigned char *)0x5700007c)	//BCD date  //edited by junon
#define BCDDAY    (*(volatile unsigned char *)0x57000080)	//BCD day   //edited by junon
#define BCDMON    (*(volatile unsigned char *)0x57000084)	//BCD month
#define BCDYEAR   (*(volatile unsigned char *)0x57000088)	//BCD year



// ADC
#define ADCCON    (*(volatile unsigned *)0x58000000)	//ADC control
#define ADCTSC    (*(volatile unsigned *)0x58000004)	//ADC touch screen control
#define ADCDLY    (*(volatile unsigned *)0x58000008)	//ADC start or Interval Delay
#define ADCDAT0   (*(volatile unsigned *)0x5800000c)	//ADC conversion data 0
#define ADCDAT1   (*(volatile unsigned *)0x58000010)	//ADC conversion data 1
#define ADCUPDN   (*(volatile unsigned *)0x58000014)	//Stylus Up/Down interrupt status


// SPI
#define SPCON0    (*(volatile unsigned *)0x59000000)	//SPI0 control
#define SPSTA0    (*(volatile unsigned *)0x59000004)	//SPI0 status
#define SPPIN0    (*(volatile unsigned *)0x59000008)	//SPI0 pin control
#define SPPRE0    (*(volatile unsigned *)0x5900000c)	//SPI0 baud rate prescaler
#define SPTDAT0   (*(volatile unsigned *)0x59000010)	//SPI0 Tx data
#define SPRDAT0   (*(volatile unsigned *)0x59000014)	//SPI0 Rx data

#define SPCON1    (*(volatile unsigned *)0x59000020)	//SPI1 control
#define SPSTA1    (*(volatile unsigned *)0x59000024)	//SPI1 status
#define SPPIN1    (*(volatile unsigned *)0x59000028)	//SPI1 pin control
#define SPPRE1    (*(volatile unsigned *)0x5900002c)	//SPI1 baud rate prescaler
#define SPTDAT1   (*(volatile unsigned *)0x59000030)	//SPI1 Tx data
#define SPRDAT1   (*(volatile unsigned *)0x59000034)	//SPI1 Rx data


// SD Interface
#define SDICON     (*(volatile unsigned *)0x5a000000)	//SDI control
#define SDIPRE     (*(volatile unsigned *)0x5a000004)	//SDI baud rate prescaler
#define SDICARG    (*(volatile unsigned *)0x5a000008)	//SDI command argument
#define SDICCON    (*(volatile unsigned *)0x5a00000c)	//SDI command control
#define SDICSTA    (*(volatile unsigned *)0x5a000010)	//SDI command status
#define SDIRSP0    (*(volatile unsigned *)0x5a000014)	//SDI response 0
#define SDIRSP1    (*(volatile unsigned *)0x5a000018)	//SDI response 1
#define SDIRSP2    (*(volatile unsigned *)0x5a00001c)	//SDI response 2
#define SDIRSP3    (*(volatile unsigned *)0x5a000020)	//SDI response 3
#define SDIDTIMER  (*(volatile unsigned *)0x5a000024)	//SDI data/busy timer
#define SDIBSIZE   (*(volatile unsigned *)0x5a000028)	//SDI block size
#define SDIDCON    (*(volatile unsigned *)0x5a00002c)	//SDI data control
#define SDIDCNT    (*(volatile unsigned *)0x5a000030)	//SDI data remain counter
#define SDIDSTA    (*(volatile unsigned *)0x5a000034)	//SDI data status
#define SDIFSTA    (*(volatile unsigned *)0x5a000038)	//SDI FIFO status
#define SDIIMSK    (*(volatile unsigned *)0x5a00003c)	//SDI interrupt mask. edited for 2440A

#define SDIDAT    (*(volatile unsigned *)0x5a000040)	//SDI data



// Exception vector
#define pISR_RESET		(*(unsigned *)(_ISR_STARTADDRESS+0x0))
#define pISR_UNDEF		(*(unsigned *)(_ISR_STARTADDRESS+0x4))
#define pISR_SWI		(*(unsigned *)(_ISR_STARTADDRESS+0x8))
#define pISR_PABORT		(*(unsigned *)(_ISR_STARTADDRESS+0xc))
#define pISR_DABORT		(*(unsigned *)(_ISR_STARTADDRESS+0x10))
#define pISR_RESERVED	(*(unsigned *)(_ISR_STARTADDRESS+0x14))
#define pISR_IRQ		(*(unsigned *)(_ISR_STARTADDRESS+0x18))
#define pISR_FIQ		(*(unsigned *)(_ISR_STARTADDRESS+0x1c))
// Interrupt vector
#define pISR_EINT0		(*(unsigned *)(_ISR_STARTADDRESS+0x20))
#define pISR_EINT1		(*(unsigned *)(_ISR_STARTADDRESS+0x24))
#define pISR_EINT2		(*(unsigned *)(_ISR_STARTADDRESS+0x28))
#define pISR_EINT3		(*(unsigned *)(_ISR_STARTADDRESS+0x2c))
#define pISR_EINT4_7	(*(unsigned *)(_ISR_STARTADDRESS+0x30))
#define pISR_EINT8_23	(*(unsigned *)(_ISR_STARTADDRESS+0x34))
#define pISR_CAM		(*(unsigned *)(_ISR_STARTADDRESS+0x38))		// Added for 2440.
#define pISR_BAT_FLT	(*(unsigned *)(_ISR_STARTADDRESS+0x3c))
#define pISR_TICK		(*(unsigned *)(_ISR_STARTADDRESS+0x40))
#define pISR_WDT_AC97		(*(unsigned *)(_ISR_STARTADDRESS+0x44))   //Changed to pISR_WDT_AC97 for 2440A
#define pISR_TIMER0	 	(*(unsigned *)(_ISR_STARTADDRESS+0x48))
#define pISR_TIMER1	 	(*(unsigned *)(_ISR_STARTADDRESS+0x4c))
#define pISR_TIMER2		(*(unsigned *)(_ISR_STARTADDRESS+0x50))
#define pISR_TIMER3		(*(unsigned *)(_ISR_STARTADDRESS+0x54))
#define pISR_TIMER4		(*(unsigned *)(_ISR_STARTADDRESS+0x58))
#define pISR_UART2		(*(unsigned *)(_ISR_STARTADDRESS+0x5c))
#define pISR_LCD		(*(unsigned *)(_ISR_STARTADDRESS+0x60))
#define pISR_DMA0		(*(unsigned *)(_ISR_STARTADDRESS+0x64))
#define pISR_DMA1		(*(unsigned *)(_ISR_STARTADDRESS+0x68))
#define pISR_DMA2		(*(unsigned *)(_ISR_STARTADDRESS+0x6c))
#define pISR_DMA3		(*(unsigned *)(_ISR_STARTADDRESS+0x70))
#define pISR_SDI		(*(unsigned *)(_ISR_STARTADDRESS+0x74))
#define pISR_SPI0		(*(unsigned *)(_ISR_STARTADDRESS+0x78))
#define pISR_UART1		(*(unsigned *)(_ISR_STARTADDRESS+0x7c))
#define pISR_NFCON		(*(unsigned *)(_ISR_STARTADDRESS+0x80))		// Added for 2440.
#define pISR_USBD		(*(unsigned *)(_ISR_STARTADDRESS+0x84))
#define pISR_USBH		(*(unsigned *)(_ISR_STARTADDRESS+0x88))
#define pISR_IIC		(*(unsigned *)(_ISR_STARTADDRESS+0x8c))
#define pISR_UART0		(*(unsigned *)(_ISR_STARTADDRESS+0x90))
#define pISR_SPI1		(*(unsigned *)(_ISR_STARTADDRESS+0x94))
#define pISR_RTC		(*(unsigned *)(_ISR_STARTADDRESS+0x98))
#define pISR_ADC		(*(unsigned *)(_ISR_STARTADDRESS+0x9c))


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
