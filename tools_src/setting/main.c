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
#include "test.h"
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
 printf("Directory scan of .:\n");
 printdir(".",10);
 printf("done.\n");
 exit(0);
}

