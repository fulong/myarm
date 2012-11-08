/**
 *  \file	font.h
 *  \brief  自定义字库的使用接口，和与电脑编码兼容的算法，目前只兼容UTF-8\n
 *  MyUTF8中的高低字节索引的乘积就来索引字库里所表示的字模.是乘积的话，字库的索引量将会达到65536个字符，如果是加的话就只有512个字符。一开始按乘积算，字库可以很大程度地扩容\n
 *  在这里的字模是16*17，所以在字库中每个字模的偏移是16*17/8的偏移量。
 *
 *  \author 	fulong\n
 *  Mail:fulong.mo@gmail.com\n
 *  \version: 	1.0\n
 *  compiler:GCC\n
 *  \date       2012-3-30 下午2:37:44
 */

#ifndef FONT_H_
#define FONT_H_

#include "../user/user_configure/configure.h"

#if LIB_FONT == POINT_LIB
#define WORD_FONT_WIDTH													(16)
#define WORD_FONT_HIGH													(17)
#define WORD_FONT_SIZE													((WORD_FONT_WIDTH*WORD_FONT_HIGH)/8)
#elif LIB_FONT == IMAGE_LIB
#define WORD_FONT_WIDTH													(32)
#define WORD_FONT_HIGH													(32)
#define WORD_FONT_SIZE													(1)
#endif
/**
 * @brief 描述UTF8的结构，取用的是大端存储
 */
typedef struct
{
		INT8U UTF8_size;/*!< 该编码是多少个字节组成。取值为，1,2,3,4 */
		INT8U UTF8_highest;/*!< 该编码的最高字节 */
		INT8U UTF8_high;/*!<  该编码的次高字节*/
		INT8U UTF8_low;/*!< 该编码的次低字节 */
		INT8U UTF8_lowest;/*!< 该编码的最低字节 */
		INT8U High_Byte_Index;/*!< 该编码在自定义字库高字节索引表的偏移量 unicode的高字节*/
		INT8U Low_Byte_Index;/*!< 该编码在自定义字库低字节索引表的偏移量 unicode的低字节*/
} MyUTF8;
extern void
UTF8_2_Unicode(INT8U* font , MyUTF8* myUTF8);
extern void
Unicode_Index_MyFont(INT8U* font , INT32U* myfont_index);

#endif /* FONT_H_ */
