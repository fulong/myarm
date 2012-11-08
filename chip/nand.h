/*
 * nand.h
 *
 *  Created on: Mar 30, 2012
 *      Author: fulong
 */

#ifndef NAND_H_
#define NAND_H_
#include "../cpu/arm920t/s3c2440.h"



//********NAND FLASH CMMOND especially for K9F2G08UMB
#define CMD_READ1 0x00 //页读命令周期1
#define CMD_READ2 0x30 //页读命令周期2
#define CMD_READID 0x90 //读ID命令
#define CMD_WRITE1 0x80 //页写命令周期1
#define CMD_WRITE2 0x10 //页写命令周期2
#define CMD_ERASE1 0x60 //块擦除命令周期1
#define CMD_ERASE2 0xd0 //块擦除命令周期2
#define CMD_STATUS 0x70 //读状态命令
#define CMD_RESET 0xff //复位
#define CMD_RANDOMREAD1 0x05 //随意读命令周期1
#define CMD_RANDOMREAD2 0xE0 //随意读命令周期2
#define CMD_RANDOMWRITE 0x85 //随意写命令

//  Status bit pattern
#define STATUS_READY                    0x40    //  Ready
#define STATUS_ERROR                    0x01    //  Error

#define NF_Send_Cmd(cmd)        {NFCMD  = (cmd); }
#define NF_Send_Addr(addr)      {NFADDR = (addr); }
#define NF_Send_Data(data)      {NFDATA8 = (data); }
#define NF_Enable()                     {NFCONT &= ~(1<<1); }           //nand flash控制器使能
#define NF_Disable()            {NFCONT |= (1<<1); }
#define NF_Enable_RB()          {NFSTAT |= (1<<2); }         //开启RnB监视模式；
#define NF_Check_Busy()         {while(!(NFSTAT&(1<<2)));}  //相当于等待RnB置1----这说明nand flash不忙了
#define NF_Read_Byte()          (NFDATA8)

// HCLK=100Mhz
#define TACLS                           1       // 1-clk(0ns)
#define TWRPH0                          4       // 3-clk(25ns)
#define TWRPH1                          0       // 1-clk(10ns)  //TACLS+TWRPH0+TWRPH1>=50ns

extern void NF_Init(void) ;
extern void NF_ReadPage(unsigned int block,unsigned int page, unsigned char * dstaddr) ;
extern void NF_WritePage(unsigned int block,unsigned int page, unsigned char *buffer) ;
extern int  NF_EraseBlock(unsigned int block) ;//

//extern void rRdNF2SDRAM(void) ;

#endif /* NAND_H_ */
