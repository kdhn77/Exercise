#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern char **environ;

int main()
{
	char strDir[50];
	char strName[10];
	char strResult[40];
	
	sprintf(strDir,"%s",getenv("FILEDIR"));
	sprintf(strName,"%s",getenv("FILENAME"));
	sprintf(strResult,"gcc -o hello ");
	strcat(strResult,strDir);
	strcat(strResult,strName);
	//gcc -o hello /home/hwan/Exericse/hello.c
	system(strResult);
	system("./hello");

	return 0;
}
