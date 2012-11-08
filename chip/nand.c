#include "nand.h"

static void NF_Reset()
{
	NF_Enable();
	NF_Enable_RB();
	NF_Send_Cmd(CMD_RESET);
	NF_Check_Busy();
	NF_Disable();
}

void NF_Init(void)
{
	GPACON &= ~(0X3F << 17) ;
	GPACON |= (0X3F << 17) ;
	NFCONF = (TACLS<<12)|(TWRPH0<<8)|(TWRPH1<<4);
	NFCONT = (0<<12)|(1<<0);
	NFSTAT = 0;
	NF_Reset();
}


void RdNF2SDRAM(void)
{
	unsigned int i;
	unsigned int start_addr = 0x0;
	unsigned char * dstaddr = (unsigned char *)0x30000000;
	unsigned int size = 0x100000;
	NF_Init();
	for(i = (start_addr >> 11); size > 0;i ++ )
	{
		NF_ReadPage(i/64,i%64, dstaddr);
		size -= 2048;
		dstaddr += 2048;

	}
}

void NF_ReadPage(unsigned int block,unsigned int page, unsigned char * dstaddr)
{
	unsigned int i;
    unsigned int blockPage = (block<<6)+page;
	NF_Reset();

	NF_Enable();
	NF_Enable_RB();


	NF_Send_Cmd(CMD_READ1);		//CMD_READ1= 0x00

	NF_Send_Addr(0x00);
	NF_Send_Addr(0x00);
	NF_Send_Addr((blockPage) & 0xff);
	NF_Send_Addr((blockPage >> 8) & 0xff);
	NF_Send_Addr((blockPage >> 16) & 0x1);

	NF_Send_Cmd(CMD_READ2);   //CMD_READ12= 0x30

	NF_Check_Busy();

	for (i = 0; i < 2048; i++)
	{
		dstaddr[i] =  NF_Read_Byte();
	}

	NF_Disable();

}

void NF_WritePage(unsigned int block,unsigned int page, unsigned char *buffer)
{
        unsigned int i;
        unsigned int blockPage = (block<<6)+page;
        unsigned char *bufPt = buffer;

        NF_Reset();                                                                             //�����addrʵ���Ͼ���ҳ��
        NF_Enable();
        NF_Enable_RB();

        NF_Send_Cmd(CMD_WRITE1);

        NF_Send_Addr(0x00);
        NF_Send_Addr(0x00);
        NF_Send_Addr((blockPage) & 0xff);
        NF_Send_Addr((blockPage >> 8) & 0xff);
        NF_Send_Addr((blockPage >> 16) & 0x1);
        for(i=0;i<2048;i++)
        {
        	NF_Send_Data(*bufPt++);
        }

        NF_Send_Cmd(CMD_WRITE2);
        NF_Check_Busy();
        NF_Disable();
}

int NF_EraseBlock(unsigned int block)
{
        unsigned int blocknum=(block<<6);
        int i;
        NF_Reset();
        NF_Enable();
        NF_Enable_RB();
        NF_Send_Cmd(CMD_ERASE1);

        NF_Send_Addr( blocknum & 0xff);
        NF_Send_Addr((blocknum>>8) & 0xff);
        NF_Send_Addr((blocknum>>16) & 0xff);

        NF_Send_Cmd(CMD_ERASE2) ;
        for (i = 0; i < 1000; i++) ;

        NF_Check_Busy() ;


        NF_Disable() ;

        return 1 ;

}
