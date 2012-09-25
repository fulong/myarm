/*
 * =====================================================================================
 *
 *       Filename:  clock_option.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  8:34:12 AM  Apr 7, 2012
 *       Revision:  none
 *       Compiler:  arm
 *
 *         Author:  fulong, fulong.mo@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

//Start address of each stacks,
#define		_STACK_BASEADDRESS       0x33ff8000
#define		_ISR_STARTADDRESS        0x33ffff00




#define			CLKDIV_VAL			3



#define			M_MDIV              92              //Fin=12.0MHz Fout=200MHz
#define			M_PDIV               4
#define			M_SDIV               1               // 2440A



#define			U_MDIV               56              //Fin=12.0MHz Fout=48MHz
#define			U_PDIV               2
#define			U_SDIV               2               // 2440A

