#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
		pid_t pid;
		int sum1 =0, sum2=0, sum=0;
		int i;

		printf("vfork program starting\n");

		pid=vfork();

		switch(pid)
		{
				case -1:
						printf("vfork failed");
						exit(1);

				case 0:
						for(i=5001;i<10001;i++)
							sum+=i;
						printf("sum child = %2d\n",sum);
						break;
				default:
						for(i=1;i<5001;i++)
							sum+=i;
						printf("sum parent = %2d\n",sum);
						break;
		}
		if(pid!=0)
		{
			//sum=sum1+sum2;
			printf("sum = %2d \n",sum);
		}

		exit(0);
}
