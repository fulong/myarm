#include "../user/user_configure/include.h"

int main(void)
{
#ifdef __DEBUG__
	printfs("enter the main function\r\n");
#endif
	while (1)
		;

	return 0;
}
