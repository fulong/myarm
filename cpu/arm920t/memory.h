/*
 * memory.h
 *
 *  Created on: Mar 29, 2012
 *      Author: fulong
 */

#ifndef MEMORY_H_
#define MEMORY_H_

#	define DW0_RO			(0<<1)			//因OM【0:1】改变，而改变
#	define DW1				(1<<4)
#	define WS1				(0<<6)
#	define ST1				(0<<7)
#	define DW2				(1<<8)
#	define WS2				(0<<10)
#	define ST2				(0<<11)
#	define DW3				(1<<12)
#	define WS3				(0<<14)
#	define ST3				(0<<15)
#	define DW4				(1<<16)
#	define WS4				(0<<18)
#	define ST4				(0<<19)
#	define DW5				(0<<20)
#	define WS5				(0<<22)
#	define ST5				(0<<23)
#	define DW6				(2<<24)
#	define WS6				(0<<26)
#	define ST6				(0<<27)
#	define DW7				(2<<28)
#	define WS7				(0<<30)
#	define ST7				(0<<31)

#	define MT				(3 << 15)		//0的话，BANKCON6-7跟1-5一样的位功能
#	if MT == (3 << 15)
#	define SCAN				(1)
#	define Tcrd				(1<<2)

#	define BANKCONN_SET		MT+SCAN+Tcrd
#	else
#	define	BANKCONN_SET	0x00000700	//n[6-7]
#endif

#	define REFEH			(1<<23)
#	define TREFMD			(0<<22)
#	define Trp				(0<<20)
#	define Tscr				(1<<18)
#	define Refresh_period	7810	//单位KHz
#	define HCLK				100		//单位MHz
#	define Refresh_count 	2049-(Refresh_period*HCLK)/1000

#	define BURST_EN			(1<<7)
#	define SCKE_EN			(1<<5)
#	define SCLK_EN			(1<<4)
#	define BK76MAP			1

#	define CL				(3<<4)

#	define MRSRBx_SET		CL
#	define BANKSIZE_SET		BURST_EN+SCKE_EN+SCLK_EN+BK76MAP
#	define REFRESH_SET		Refresh_count+Tscr+Trp+TREFMD+REFEH
#	define BANKCONn_SET		BANKCONN_SET
#	define BANKCONx_SET		0x00000700			//x[0-5]
#	define BWSCON_SET		DW0_RO+DW1+WS1+ST2+\
							   DW2+WS2+ST2+\
							   DW3+WS3+ST3+\
							   DW4+WS4+ST4+\
							   DW5+WS5+ST5+\
							   DW6+WS6+ST6+\
							   DW7+WS7+ST7

#	define MEM_CTL_BASE		0x48000000
#	define SDRAM_BASE		0x30000000

#endif /* MEMORY_H_ */
