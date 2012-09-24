/**
 *  \file	tsc2046.c
 *  \brief  这个是一个AD转换芯片。这个文件包含着基本操作函数
 *
 *  \author 	fulong\n
 *  Mail:fulong.mo@gmail.com\n
 *  \version: 	1.0\n
 *  compiler:GCC\n
 *  \date       2012-5-23 上午9:25:12
 */
#include "tsc2046.h"
#ifdef TSC2046_DEVICE
#if CPU_TYPE == STM32F103VE
#include "../sysdev/cortex-m3/inc/gpio.h"
#include "../sysdev/cortex-m3/inc/rcc.h"
#include "../sysdev/cortex-m3/inc/sys.h"
#define TP_CS					PCout(1)
#define SPI_SCK					PBout(13)
#define SPI_MISO				PBin(14)
#define SPI_MISI				PBout(15)
#define TP_IRQ					PCout(5)
#endif

/* ADS7843/7846/UH7843/7846/XPT2046/TSC2046 指令集 */
#define CMD_RDY 0x90  //0B10010000即用差分方式读X坐标
#define CMD_RDX	0xD0  //0B11010000即用差分方式读Y坐标
/**
 * @brief  配置初始化需要用到的IO口，这里没有用到芯片上的spi接口
 * @param  none
 *  这个参数可以取得到以下的值：\n
 *  	@arg
 * @retval none
 * \date 2012-5-23 上午10:26:44
 * @note TP_CS SPI_SCK SPI_MISO SPI_MISI TP_IRQ
 */
void TSC2046_io_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC, ENABLE); //重要！！
	//下面是SPI相关GPIO初始化  	Configure PB13 PB15 pin: SPI_SCK pin SPI_MISI
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //通用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	//下面是SPI相关GPIO初始化 SPI_MISO PB14
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //上拉输入
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	//Configure PC1 pin: TP_CS pin
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //通用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	//Configure PC5 pin: TP_INT pin
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //上拉输入
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	TP_CS = 1; //禁止SPI2上的其他外设
}
//SPI写数据
//向7843写入1byte数据
void ADS_Write_Byte(INT8U num)
{
	INT8U count=0;
	for(count=0;count<8;count++)
	{
		if(num&0x80)SPI_MISI=1;
		else SPI_MISI=0;
		num<<=1;
		SPI_SCK=0;//上升沿有效
		SPI_SCK=1;
	}
}
//SPI读数据
//从7846/7843/XPT2046/UH7843/UH7846读取adc值
INT16U ADS_Read_AD(INT8U CMD)
{
	INT8U i;
	INT8U count=0;
	INT16U Num=0;
	SPI_SCK=0;//先拉低时钟
	TP_CS=0; //选中ADS7843
	ADS_Write_Byte(CMD);//发送命令字
	for(i=200;i>0;i--);
	SPI_SCK=1;//给1个时钟，清除BUSY
	SPI_SCK=0;
	for(count=0;count<16;count++)
	{
		Num<<=1;
		SPI_SCK=0;//下降沿有效
		SPI_SCK=1;
		if(SPI_MISO)Num++;
	}
	Num>>=4;   //只有高12位有效.
	TP_CS=1;//释放ADS7843
	return(Num);
}
#define READ_TIMES 15 //读取次数
#define LOST_VAL 5	  //丢弃值
INT16U ADS_Read_XY(INT8U xy)
{
	INT16U i, j;
	INT16U buf[READ_TIMES];
	INT16U sum=0;
	INT16U temp;
	for(i=0;i<READ_TIMES;i++)
	{
		buf[i]=ADS_Read_AD(xy);
	}
	for(i=0;i<READ_TIMES-1; i++)//排序
	{
		for(j=i+1;j<READ_TIMES;j++)
		{
			if(buf[i]>buf[j])//升序排列
			{
				temp=buf[i];
				buf[i]=buf[j];
				buf[j]=temp;
			}
		}
	}
	sum=0;
	for(i=LOST_VAL;i<READ_TIMES-LOST_VAL;i++)sum+=buf[i];
	temp=sum/(READ_TIMES-2*LOST_VAL);
	return temp;
}
INT32U Read_ADS(INT32U* x, INT32U* y)
{
	INT16U xtemp,ytemp;
	xtemp=ADS_Read_XY(CMD_RDX);
	ytemp=ADS_Read_XY(CMD_RDY);
	if(xtemp<30||ytemp<30)return 0;//读数失败
	*x=xtemp;
	*y=ytemp;
	return 1;//读数成功

}
#endif
