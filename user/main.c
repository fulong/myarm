#include "../user/user_configure/include.h"

int main(void)
{
#ifdef __DEBUG__
	printfs("enter the main function\r\n");
#endif
	LCD_Display_Words("我是笨蛋", 10, 10);

	while (1)
		;

	return 0;
}
