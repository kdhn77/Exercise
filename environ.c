#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main()
{
	setenv("MYDIR","/home/pi",0);
	setenv("KERNEL_SRC","/usr/src/linux",0);
	
	printf("MYDIR=%s\n",getenv("MYDIR"));
	printf("KERNEL_SRC=%s\n",getenv("KERNEL_SRC"));
	
	//현재 설정된 환경변수값을 모두 출력할 경우
	/*
	while(*environ)
		printf("%s\n",*environ++);
	*/
	return 0;
}
