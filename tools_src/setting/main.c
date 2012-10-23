/**
 *  \file	main.c
 *  \brief      
 *
 *  \author 	fulong\n
 *  Mail:fulong.mo@gmail.com\n
 *  \version: 	1.0\n
 *  compiler:GCC\n
 *  \date       Jul 29, 2012 10:03:12 PM
 */
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
int main(void)
{
 char c;
 int in,out;
 in = open("file.in",O_RDONLY);
 out = open("file.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
 while(read(in,&c,1) == 1)
	 write(out,&c,1);
 exit(0);
}

