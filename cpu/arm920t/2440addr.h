/*
 * =====================================================================================
 *
 *       Filename:  2440addr.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  8:27:49 AM  Apr 7, 2012
 *       Revision:  none
 *       Compiler:  arm
 *
 *         Author:  fulong, fulong.mo@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */





//=================
// Memory control
//=================
#define		BWSCON  	  0x48000000     //Bus width & wait status
#define		BANKCON0	  0x48000004     //Boot ROM control
#define		BANKCON1	  0x48000008     //BANK1 control
#define		BANKCON2	  0x4800000c     //BANK2 control
#define		BANKCON3	  0x48000010     //BANK3 control
#define		BANKCON4	  0x48000014     //BANK4 control
#define		BANKCON5	  0x48000018     //BANK5 control
#define		BANKCON6	  0x4800001c     //BANK6 control
#define		BANKCON7	  0x48000020     //BANK7 control
#define		REFRESH 	  0x48000024     //DRAM/SDRAM refresh
#define		BANKSIZE	  0x48000028     //Flexible Bank Size
#define		MRSRB6  	  0x4800002c     //Mode register set for SDRAM Bank6
#define		MRSRB7  	  0x48000030     //Mode register set for SDRAM Bank7


//==========================
// CLOCK & POWER MANAGEMENT
//==========================
#define		LOCKTIME	  0x4c000000     //PLL lock time counter
#define		MPLLCON 	  0x4c000004     //MPLL Control
#define		UPLLCON 	  0x4c000008     //UPLL Control
#define		CLKCON  	  0x4c00000c     //Clock generator control
#define		CLKSLOW 	  0x4c000010     //Slow clock control
#define		CLKDIVN 	  0x4c000014     //Clock divider control


//=================
// INTERRUPT
//=================
#define		SRCPND   	  0x4a000000    //Interrupt rest status
#define		INTMOD   	  0x4a000004    //Interrupt mode control
#define		INTMSK   	  0x4a000008    //Interrupt mask control
#define		PRIORITY 	  0x4a00000c    //IRQ priority control           <-- May 06, 2002 SOP
#define		INTPND   	  0x4a000010    //Interrupt rest status
#define		INTOFFSET	  0x4a000014    //Interruot rest source offset
#define		SUSSRCPND	  0x4a000018    //Sub source pending
#define		INTSUBMSK	  0x4a00001c    //Interrupt sub mask


//=================
// I/O PORT for LED
//=================
#define		GPFCON  	  0x56000050     //Port F control
#define		GPFDAT  	  0x56000054     //Port F data
#define		GPFUP   	  0x56000058     //Pull-up control F

//Miscellaneous register
#define		MISCCR  	  0x56000080     //Miscellaneous control
#define		DCKCON  	  0x56000084     //DCLK0/1 control
#define		EXTINT0 	  0x56000088     //External interrupt control register 0
#define		EXTINT1 	  0x5600008c     //External interrupt control register 1
#define		EXTINT2 	  0x56000090     //External interrupt control register 2
#define		EINTFLT0	  0x56000094     //Reserved
#define		EINTFLT1	  0x56000098     //Reserved
#define		EINTFLT2	  0x5600009c     //External interrupt filter control register 2
#define		EINTFLT3	  0x560000a0     //External interrupt filter control register 3
#define		EINTMASK	  0x560000a4     //External interrupt mask
#define		EINTPEND	  0x560000a8     //External interrupt pending
#define		GSTATUS0	  0x560000ac     //External pin status
#define		GSTATUS1	  0x560000b0     //Chip ID(0x32440000)
#define		GSTATUS2	  0x560000b4     //Reset type
#define		GSTATUS3	  0x560000b8     //Saved data0(32-bit) before entering POWER_OFF mode
#define		GSTATUS4	  0x560000bc     //Saved data1(32-bit) before entering POWER_OFF mode

//Added for 2440					// DonGo
#define		MSLCON		  0x560000cc     //Memory sleep control register

//=================
// WATCH DOG TIMER
//=================
#define		WTCON 	  0x53000000       //Watch-dog timer mode
#define		WTDAT 	  0x53000004       //Watch-dog timer data
#define		WTCNT 	  0x53000008       //Eatch-dog timer count

//=================
// Nand Flash
//=================
#define		NFCONF			0x4E000000	//NAND Flash configuration
#define		NFCONT			0x4E000004      //NAND Flash control
#define		NFCMD			0x4E000008      //NAND Flash command
#define		NFADDR			0x4E00000C      //NAND Flash address
#define		NFDATA			0x4E000010      //NAND Flash data
#define		NFDATA8			0x4E000010      //NAND Flash data
#define		NFMECCD0		0x4E000014      //NAND Flash ECC for Main Area
#define		NFMECCD1		0x4E000018
#define		NFSECCD			0x4E00001C	//NAND Flash ECC for Spare Area
#define		NFSTAT			0x4E000020	//NAND Flash operation status
#define		NFESTAT0		0x4E000024
#define		NFESTAT1		0x4E000028
#define		NFMECC0			0x4E00002C
#define		NFMECC1			0x4E000030
#define		NFSECC			0x4E000034
#define		NFSBLK			0x4E000038	//NAND Flash Start block address
#define			NFEBLK			0x4E00003C	//NAND Flash End block address



