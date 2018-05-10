#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int global = 10;
int main()
{
		int i = 20; 
		pid_t pid; 
		int status;

		if((pid = fork()) == 0) 
		{
				/*child process */
				global += 10;
				i +=10;
		}
		else
		{
				/*fork() returns a pid != = */
				/* parent process           */

				global +=100;
				i+=100;
		}
		printf("global = =%d; i =%d\n",global,i);
}

