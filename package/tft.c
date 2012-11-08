#include "tft.h"
#if CPU_TYPE == STM32F103VE
#include "../sysdev/cortex-m3/inc/gpio.h"
#include "../sysdev/cortex-m3/inc/rcc.h"
#include "../sysdev/cortex-m3/inc/fsmc.h"
#endif
#include "../chip/ssd1963.h"
#include "../libc/font.h"
/*
#ifdef __DEBUG__
#include "../sysdev/systick.h"
#include "../package/usart_package.h"
#endif
*/
#if LIB_FONT == POINT_LIB
extern const INT8U chinese_font_mode[];
#elif LIB_FONT == IMAGE_LIB
extern const INT32U chinese_font_mode[];
#endif
#if TFT_SIZE !=NO_TFT
/**
 * @brief 将字体的点阵模显示出来
 * @param index_word_lib 该字体的模所在的首地址
 *  这个参数可以取得到以下的值：\n
 *  	@arg
 * @param x0 该字体的模显示的横坐标
 * @param y0 该字体的模显示的纵坐标
 * @retval none
 * \date 2012-3-31 下午4:55:52
 * @note 不足的是不能显示不够整数方框个数的字模，如果能显示也会有安全隐患
 */
void display_word_mode(INT8U* index_word_lib , INT16U x0 , INT16U y0)
{
#if LIB_FONT == POINT_LIB
	INT32U word_mode_size = WORD_FONT_SIZE;                    //为了确认到字模什么时候能够写完
	INT8U temp;
	INT16U count = 0;
	INT16U x0_no_change = x0;
	INT16U x = x0;
	INT16U y = y0;//这两个变量是为了方便控制x0，y0。
#ifdef __DEBUG__
	printfs("index_word_lib:");
	printf_num((INT32U) index_word_lib, 'h');
	printfs("\r\n");
#endif
	/*
	 * 假设下面是一个点阵汉字，取模由4个8*8的方框按顺序组成
	 *
	 *
	 *	一开始的时候
	 *		 |x=x0,count指的是字库里面的原始数据，x0_no_change,这个变量不会变，如果y>8的适合将x0被这个变量置位
	 *	 	 |
	 *	 	 V
	 y=y0--> ******************************
	 *			   *			  *
	 *			   *			  *
	 *	1		   *		2	  *
	 *	 		   *			  *
	 *			   *			  *
	 ******************************
	 *			   *			  *
	 *			   *			  *
	 *	3		   *		4	  *
	 *			   * 			  *
	 *			   *			  *
	 ******************************
	 *	当一个字节写好后
	 *		 |x
	 *		 |x0_no_change |count
	 *		 |			   |x0
	 *	 	 |			   |
	 *	 	 V			   v
	 y-->  ******************************
	 y0--> *			   *			  *				y0指向下一行的时候，x0将会被x置位，即x0，又回到一开始的位置
	 *			   *			  *
	 *	1		   *		2	  *
	 *	 		   *			  *
	 *			   *			  *
	 ******************************
	 *			   *			  *
	 *			   *			  *
	 *	3		   *		4	  *
	 *			   * 			  *
	 *			   *			  *
	 ******************************
	 *	当八个字节写好后，x,y的坐标将会指向下一个方框的首地址，都是被x,y值重置了，因为到了同一行的另外一个字框，所以x的指向会被修改为x+8，而count是只管增加就行了
	 *		 |
	 *		 |x0_no_change  |count
	 *		 |			    |x
	 *	 	 |			    |x0
	 *	 	 V			    v
	 y0=y--> ******************************
	 *			   *			  *
	 *			   *			  *
	 *	1		   *		2	  *
	 *	 		   *			  *
	 *			   *			  *
	 ******************************
	 *			   *			  *
	 *			   *			  *
	 *	3		   *		4	  *
	 *			   * 			  *
	 *			   *			  *
	 ******************************
	 *第一行的方框全部写完后，x0,x将会被原本的x0_no_change改变，重新修改为指向第一列
	 *		 |x0
	 *		 |x0_no_change  |
	 *		 |x			    |
	 *	 	 |			    |
	 *	 	 V			    v
	 ******************************
	 *			   *			  *
	 *			   *			  *
	 *	1		   *		2	  *
	 *	 		   *			  *
	 *			   *			  *
	 y0=y-->	 ******************************
	 * <--count	   *			  *
	 *			   *			  *
	 *	3		   *		4	  *
	 *			   * 			  *
	 *			   *			  *
	 ******************************
	 */
	while(word_mode_size --)
	{
		temp = *(index_word_lib + count);
		count ++;
		if (temp == 0)
		{
			y0 ++;
		}
		else
		{
			while(temp)
			{
				if (temp & 0x80)
				{
					draw_word_point(x0 , y0);
					x0 ++;
				}
				else
				{
					x0 ++;
				}
				temp <<= 1;
			}
			y0 ++;
			x0 = x;
		}

		if (count % 8 == 0)
		{
			y0 = y;
			x += 8;
			x0 = x;
		}
		if (count % WORD_FONT_WIDTH == 0)
		{
			y += 8;
			y0 = y;
			x = x0_no_change;
			x0 = x0_no_change;
		}

	}
#elif LIB_FONT == IMAGE_LIB
#ifdef __DEBUG__
	printf_num((INT32U) index_word_lib, 'h');
#endif
	set_rect(x0, y0,WORD_FONT_WIDTH,WORD_FONT_HIGH);
	write_to_FramRam((INT16U*)index_word_lib,WORD_FONT_WIDTH,WORD_FONT_HIGH);
#endif
}
#if TFT_CONTROL_WAY == TFT_FSMC && CPU_TYPE == STM32F103VE
/**
 * @brief  FSMC引脚配置
 * @param  none
 *  这个参数可以取得到以下的值：\n
 *  	@arg
 * @retval none
 * \date May 22, 2012 1:46:13 PM
 * @note
 */

void FSMC_GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC , ENABLE);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE | RCC_APB2Periph_AFIO ,
						ENABLE); /* 使能各个端口时钟，重要！！！*/

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_7
	| GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOD , &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11
	| GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOE , &GPIO_InitStructure);
}
/**
 * @brief  FSMC 配置使用FSMC的BANK1 NOR/PSRAM
 * @param  none
 *  这个参数可以取得到以下的值：\n
 *  	@arg
 * @retval none
 * \date May 22, 2012 1:47:38 PM
 * @note
 */

void FSMC_LCD_Init(void)
{
	FSMC_NORSRAMInitTypeDef FSMC_NORSRAMInitStructure;
	FSMC_NORSRAMTimingInitTypeDef p;

	/* Configure FSMC Bank1 NOR/PSRAM */

	p.FSMC_AddressSetupTime = 0x02;
	p.FSMC_AddressHoldTime = 0x00;
	p.FSMC_DataSetupTime = 0x05;
	p.FSMC_BusTurnAroundDuration = 0x00;
	p.FSMC_CLKDivision = 0x00;
	p.FSMC_DataLatency = 0x00;
	p.FSMC_AccessMode = FSMC_AccessMode_B;

	FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM1;
	FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;
	FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_NOR;
	FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;
	FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode = FSMC_BurstAccessMode_Disable;
	FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
	FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;
	FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;
	FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;
	FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;
	FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Disable;
	FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable;
	FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &p;
	FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &p;

	FSMC_NORSRAMInit( &FSMC_NORSRAMInitStructure);

	/* Enable FSMC Bank1_SRAM Bank */
	FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM1 , ENABLE);
}
#else
/**
 * @brief  这个函数是用来拓展用的，但用的是其他芯片或其他方式驱动TFT的时候，可将这函数拓展具体一点
 * @param  none
 *  这个参数可以取得到以下的值：\n
 *  	@arg
 * @retval none
 * \date May 22, 2012 3:14:54 PM
 * @note
 */
void something_about_tft_inited_by_another_way(void)
{
}
#endif
/**
 * @brief  LCD初始化
 * @param  none
 *  这个参数可以取得到以下的值：\n
 *  	@arg
 * @retval none
 * \date May 22, 2012 1:44:58 PM
 * @note
 */
void LCD_Init(void)
{
#if CPU_TYPE == STM32F103VE
#if TFT_CONTROL_WAY == TFT_FSMC
	FSMC_GPIO_Configuration();
	FSMC_LCD_Init();
#else
	something_about_tft_inited_by_another_way();
#endif
#endif
#ifdef SSD1963_DEVICE
	ssd1936_init();
#else
	other_device_init();                    //这个函数实际不存在，也是拓展用的，如果使用其他芯片的时候，这个就是那个芯片的初始化程序
#endif
}
/**
 * @brief 使用lcd显示文字
 * @param word_display: 将会显示的目标字符串
 *  这个参数可以取得到以下的值：\n
 *  	@arg
 * @param x0: 字符串显示的横坐标
 * @param y0: 字符串显示的纵坐标
 * @retval none
 * \date 2012-3-31 下午4:45:29
 * @note
 */
void LCD_Display_Words(INT8U* word_display , INT16U x0 , INT16U y0)
{
	INT32U myfont_index[50];
	INT32U count = 1;
	Unicode_Index_MyFont(word_display , myfont_index);                    //转换unicode码
#ifdef __DEBUG__
	printfs("myfont_index[0] :");
	printf_num(*myfont_index, 'h');
	printfs("\r\n");
	printfs("myfont_index[1] :");
	printf_num(*(myfont_index + 1), 'h');
	printfs("\r\n");
	printfs("myfont_index[2] :");
	printf_num(*(myfont_index + 2), 'h');
	printfs("\r\n");
	printfs("myfont_index[3] :");
	printf_num(*(myfont_index + 3), 'h');
	printfs("\r\n");
	printfs("myfont_index[4] :");
	printf_num(*(myfont_index + 4), 'h');
	printfs("\r\n");
#endif
#if LIB_FONT == POINT_LIB
	while(myfont_index[0] --)
	{
		display_word_mode((INT8U*) &chinese_font_mode[ *(myfont_index + count)] , x0 , y0); //显示一个汉字，只需要给显示字模函数一个字库索引
		x0 += WORD_FONT_WIDTH;
#ifdef __DEBUG__
		printfs("chinese_font_mode[*(myfont_index + count)] :");
		printf_num(&chinese_font_mode, 'h');
		printfs("\r\n");
#endif
		count ++;
	}
#elif LIB_FONT == IMAGE_LIB
	while (myfont_index[0]--)
	{
		display_word_mode(chinese_font_mode[*(myfont_index + count)], x0, y0); //显示一个汉字，只需要给显示字模函数一个字库索引
		count++;
		x0 += WORD_FONT_WIDTH;
	}
#endif
}
#endif
