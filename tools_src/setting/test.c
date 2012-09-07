/**
 *  \file	test.c
 *  \brief      
 *
 *  \author 	fulong\n
 *  Mail:fulong.mo@gmail.com\n
 *  \version: 	1.0\n
 *  compiler:GCC\n
 *  \date       Aug 4, 2012 11:51:43 PM
 */

#include "test.h"
#include <unistd.h>
#include <sys/stat.h>
//#include <fcntl.h>
#include <stdlib.h>
//#include <sys/types.h>
//#include <sys/stat.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

void printdir(char *dir , int depth)
{

	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
	if((dp = opendir(dir)) == NULL )
	{
		fprintf(stderr , "can't not open directory:%s\n" , dir);
		return;
	}
	chdir(dir);
	while((entry = readdir(dp)) != NULL )
	{
		lstat(entry->d_name , &statbuf);

		if(S_ISDIR(statbuf.st_mode))
		{
			if(strcmp("." , entry->d_name) == 0 || strcmp(".." , entry->d_name) == 0)
				{continue;}
			printf("%*s%s/\n" , depth , "" , entry->d_name);
			printdir(entry->d_name , depth);
		}
		else
		{
			printf("%*s%s\n" , depth+1 , "" , entry->d_name);
		}

//		chdir("..");
//		closedir(dp);
	}

}
