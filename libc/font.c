/**
 *  \file	font.c
 *  \brief      
 *
 *  \author 	fulong\n
 *  Mail:fulong.mo@gmail.com\n
 *  \version: 	1.0\n
 *  compiler:GCC\n
 *  \date       2012-3-30 下午2:37:29
 *  @note 下表总结了编码规则，字母x表示可用编码的位。\n
 *	Unicode符号范围 		| UTF-8编码方式\n
 *  (十六进制) 			| （二进制）\n
 *	--------------------+---------------------------------------------\n
 *	0000 0000-0000 007F | 0xxxxxxx\n
 *	0000 0080-0000 07FF | 110xxxxx 10xxxxxx\n
 *	0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx\n
 *	0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx\n
 *
 *	字库的索引表使用，修改三个变量chinese_font_mode  High_Byte_Index   Low_Byte_Index
 *	chinese_font_mode，根据configure.h头文件中的一个宏确定其模式，一个是保存点阵模，一个是保存图片字库的数组首地址，如果需要增加字库只需要在这个数组中增加\n
 *	相应的字库或者图片字数组首地址。然后这个字模所在的位置通过High_Byte_Index与Low_Byte_Index
 */

#include "font.h"
#ifdef __DEBUG__
#include "../package/usart_package.h"
#endif
#if LIB_FONT == IMAGE_LIB
#include "../chip/font_image.h"
#endif
/*
 |-------------------|-------------------|
 |                   |					 |
 |	 8*8方格1        |        8*8方格  2   |
 |                   |					 |
 |                   |                   |
 |                   |                   |
 |                   |                   |
 |-------------------|-------------------|
 |                   |					 |
 |   8*8方格3        |      8*8方格 4     |
 |                   |					 |
 |                   |					 |
 |                   |					 |
 |                   |					 |
 |-------------------|-------------------|
 |   1*8方格5        |    1*8方格6        |
 |-------------------|-------------------|
 下面模的取得方式是按着数字顺序取得，并一个方格完成再到另外一个方格
 使用的软件是，http://115.com/file/dpv52ce2
 使用的字体格式是雅黑，14号，16*17
 http://115.com/file/dpv5lpuo
 这个是文字编码，查询
 */
/*
 * @brief 存储着字模的数组。
 * @note 暂时存在数组中，如果字库大的时候，可将下面数组以二进制形式存储，就可以放到SD卡中访问
 */
#if LIB_FONT == POINT_LIB
const INT8U chinese_font_mode[] =
{
	/*--  文字0:  我  --*/
	/*--  微软雅黑14;  此字体下对应的点阵为：宽x高=16x17   --*/
//01: "",ASCII码:0x00,点阵8x8,长度8字节
	0x00, 0x00, 0x00, 0x07, 0x7E, 0x18, 0xFF, 0x18,
//02: "",ASCII码:0x00,点阵8x8,长度8字节
	0x00, 0x00, 0x00, 0xCC, 0xCC, 0xE0, 0xFF, 0x60,
//03: "",ASCII码:0x00,点阵8x8,长度8字节
	0x18, 0x1F, 0xF8, 0x18, 0x18, 0x7B, 0x00, 0x00,
	//04: "",ASCII码:0x00,点阵8x8,长度8字节
	0x64, 0x6E, 0x78, 0x72, 0xF3, 0x1E, 0x00, 0x00,
	//05: "",ASCII码:0x00,点阵8x1,长度1字节
	0x00,
	//06: "",ASCII码:0x00,点阵8x1,长度1字节
	0x00,
	/*--  文字1:  是  --*/
	/*--  微软雅黑14;  此字体下对应的点阵为：宽x高=16x17   --*/
	//01: "",ASCII码:0x00,点阵8x8,长度8字节
	0x00, 0x00, 0x00, 0x3F, 0x30, 0x3F, 0x30, 0x3F,
	//02: "",ASCII码:0x00,点阵8x8,长度8字节
	0x00, 0x00, 0x00, 0xFC, 0x0C, 0xFC, 0x0C, 0xFC,
	//03: "",ASCII码:0x00,点阵8x8,长度8字节
	0x00, 0xFF, 0x19, 0x39, 0x7D, 0x67, 0x00, 0x00,
	//04: "",ASCII码:0x00,点阵8x8,长度8字节
	0x00, 0xFF, 0x80, 0xFE, 0x80, 0xFE, 0x00, 0x00,
	//05: "",ASCII码:0x00,点阵8x1,长度1字节
	0x00,
	//06: "",ASCII码:0x00,点阵8x1,长度1字节
	0x00,
	/*--  文字2:  笨  --*/
	/*--  微软雅黑14;  此字体下对应的点阵为：宽x高=16x17   --*/
	//01: "",ASCII码:0x00,点阵8x8,长度8字节
	0x00, 0x00, 0x00, 0x38, 0x3F, 0x6C, 0x47, 0x7F,
	//02: "",ASCII码:0x00,点阵8x8,长度8字节
	0x00, 0x00, 0x00, 0x70, 0xFF, 0xD8, 0x88, 0xFE,
	//03: "",ASCII码:0x00,点阵8x8,长度8字节
	0x07, 0x0D, 0x19, 0x71, 0x7F, 0x01, 0x01, 0x00,
	//04: "",ASCII码:0x00,点阵8x8,长度8字节
	0xE0, 0xB0, 0x98, 0x8E, 0xFA, 0x80, 0x80, 0x00,
	//05: "",ASCII码:0x00,点阵8x1,长度1字节
	0x00,
	//06: "",ASCII码:0x00,点阵8x1,长度1字节
	0x00,
	/*--  文字3:  蛋  --*/
	/*--  微软雅黑14;  此字体下对应的点阵为：宽x高=16x17   --*/
	//01: "",ASCII码:0x00,点阵8x8,长度8字节
	0x00, 0x00, 0x00, 0x7F, 0x19, 0x31, 0x39, 0x67,
	//02: "",ASCII码:0x00,点阵8x8,长度8字节
	0x00, 0x00, 0x00, 0xFE, 0x86, 0xFE, 0x80, 0xFE,
	//03: "",ASCII码:0x00,点阵8x8,长度8字节
	0x41, 0x3F, 0x31, 0x3F, 0x01, 0x7F, 0x00, 0x00,
	//04: "",ASCII码:0x00,点阵8x8,长度8字节
	0x80, 0xFC, 0x8C, 0xFC, 0x8E, 0xFE, 0x00, 0x00,
	//05: "",ASCII码:0x00,点阵8x1,长度1字节
	0x00,
	//06: "",ASCII码:0x00,点阵8x1,长度1字节
	0x00};
#elif LIB_FONT == IMAGE_LIB
const INT32U chinese_font_mode[] =
{ (INT32U)gImage_wo, (INT32U)gImage_shi, (INT32U)gImage_ben, (INT32U)gImage_dan };

#endif
/**
 * @brief 自定义字库高字节索引表
 */

const INT8U High_Byte_Index[256] =
{
//0-23
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		//24-47
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		//48-71
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		//72-95
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		//96-119
		0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		//120-143
		0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		//144-167
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		//168-191
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		//192-215
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		//216-239
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		//240-255
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
/**
 * @brief 自定义字库低字节索引表
 */
const INT8U Low_Byte_Index[256] =
{
//0-23
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
		//24-47
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1,
		//48-71
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		//72-95
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		//96-119
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		//120-143
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		//144-167
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		//168-191
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		//192-215
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		//216-239
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		//240-255
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

/**
 * @brief  将UFT-8编码的字符变成能够索引自己定义的字库时所需要的信息
 * @param font: 转换的目标字体
 *  这个参数可以取得到以下的值：\n
 *  	@arg
 * @param myUTF8: 需要用到的信息，将会向这个结构体保存信息
 * @retval
 * \date 2012-3-31 上午9:53:37
 * @note 在这些信息中包括了UTF8编码的构成大小，组成UTF8编码的各字节的值，还有UTF8编码变换成unicode码时的高低字节，unicode码是16位的
 */

void UTF8_2_Unicode(INT8U* font, MyUTF8* myUTF8)
{
	/*判断改字体编码是由多少位组成*/
	if ((*font & 0xF8) == 0xF0)
		myUTF8->UTF8_size = 4;
	else if ((*font & 0xE0) == 0xE0)
		myUTF8->UTF8_size = 3;
	else if ((*font & 0xC0) == 0xC0)
		myUTF8->UTF8_size = 2;
	else if ((*font & 0x80) == 0x00)
		myUTF8->UTF8_size = 1;
	/*按字节数存储UTF-8编码，以后后面转换*/
	switch (myUTF8->UTF8_size)
	{
	case 4:
		myUTF8->UTF8_highest = *font;
		myUTF8->UTF8_high = *(font + 1);
		myUTF8->UTF8_low = *(font + 2);
		myUTF8->UTF8_lowest = *(font + 3);
		/*转换成unicode码 utf-8码 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx*/
		myUTF8->High_Byte_Index = ((*(font + 1) & 0x03C) << 4)
				+ ((*(font + 2) & 0x3F) >> 2);
		myUTF8->Low_Byte_Index = ((*(font + 2) & 0x3) << 6)
				+ (*(font + 3) & 0x3F);
		break;
	case 3:
		myUTF8->UTF8_highest = 0;
		myUTF8->UTF8_high = *(font);
		myUTF8->UTF8_low = *(font + 1);
		myUTF8->UTF8_lowest = *(font + 2);
		/*转换成unicode码 utf-8码1110xxxx 10xxxxxx 10xxxxxx*/
		myUTF8->High_Byte_Index = ((*(font) & 0x0F) << 4)
				+ ((*(font + 1) & 0x3F) >> 2);
		myUTF8->Low_Byte_Index = ((*(font + 1) & 0x3) << 6)
				+ (*(font + 2) & 0x3F);
		break;
	case 2:
		myUTF8->UTF8_highest = 0;
		myUTF8->UTF8_high = 0;
		myUTF8->UTF8_low = *(font);
		myUTF8->UTF8_lowest = *(font + 1);
		/*转换成unicode码 utf-8码110xxxxx 10xxxxxx*/
		myUTF8->High_Byte_Index = ((*(font) & 0x1F) >> 2);
		myUTF8->Low_Byte_Index = ((*(font) & 0x3) << 6) + (*(font + 1) & 0x3F);
		break;
	case 1:
		myUTF8->UTF8_highest = 0;
		myUTF8->UTF8_high = 0;
		myUTF8->UTF8_low = 0;
		myUTF8->UTF8_lowest = *font;
		/*转换成unicode码 utf-8码 0xxxxxxx*/
		myUTF8->High_Byte_Index = 0;
		myUTF8->Low_Byte_Index = *font;
		break;
	default:
		break;
	}
}
/**
 * @brief 将所要显示的字符串转换为要显示的字库序列，这个序列所索引的字库存在chinese_font_mode这个数组中，并将这个序列保存在my_font_index数组上
 * @param font: 将要显示的目标字符串
 *  这个参数可以取得到以下的值：\n
 *  	@arg
 * @param myfont_index: 要显示的目标字符串在自定义字库上的显示序列，并保存在这里，myfont_index，数组的第一个元素保存的是该显示序列的长度。
 * @retval none
 * \date 2012-3-31 下午2:45:35
 * @note
 */
void Unicode_Index_MyFont(INT8U* font, INT32U* myfont_index)
{
	MyUTF8 myutf8;
	INT32U* index_temp = myfont_index;
	*index_temp = 0;
	myfont_index++; //数组的第一个元素存储显示的长度，后面存储所需要显示文字的序列
	while (*font)
	{
		*index_temp += 1;
		UTF8_2_Unicode(font, &myutf8);
		font += myutf8.UTF8_size;
#if LIB_FONT != NO_LIB
		*myfont_index++ = (WORD_FONT_SIZE
				* (High_Byte_Index[myutf8.High_Byte_Index]
						* Low_Byte_Index[myutf8.Low_Byte_Index]));
#endif
/*
#ifdef __DEBUG__
		printfs("myutf8.High_Byte_Index :");
		printf_num(myutf8.High_Byte_Index, 'h');
		printfs("\r\n");
		printfs("myutf8.Low_Byte_Index :");
		printf_num(myutf8.Low_Byte_Index, 'h');
		printfs("\r\n");
		printfs("myutf8.UTF8_highest :");
		printf_num(myutf8.UTF8_highest, 'h');
		printfs("\r\n");
		printfs("myutf8.UTF8_high :");
		printf_num(myutf8.UTF8_high, 'h');
		printfs("\r\n");
		printfs("myutf8.UTF8_low :");
		printf_num(myutf8.UTF8_low, 'h');
		printfs("\r\n");
		printfs("myutf8.UTF8_lowest :");
		printf_num(myutf8.UTF8_lowest, 'h');
		printfs("\r\n");
		printfs("myutf8.UTF8_size :");
		printf_num(myutf8.UTF8_size, 'h');
		printfs("\r\n");
		printfs("Low_Byte_Index[myutf8.Low_Byte_Index] :");
		printf_num(Low_Byte_Index[myutf8.Low_Byte_Index], 'h');
		printfs("\r\n");
		printfs("High_Byte_Index[myutf8.High_Byte_Index :");
		printf_num(High_Byte_Index[myutf8.High_Byte_Index], 'h');
		printfs("\r\n");
#endif
*/
	}
}

