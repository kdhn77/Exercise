#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
		pid_t pid,child_pid;
		int sum=0, status=0;
		int i;
		printf("fork program starting\n");
		pid = fork();

		switch(pid)
		{
				case -1:
						printf("fork failed");
						return -1;
				case 0: //자식프로세스
					for(i=5001;i<10001;i++)
						sum +=i;
					printf("child : %d \n",sum);
					break;
				default: //부모프로세스
					for(i=1;i<5001;i++)
						sum+=i;
					printf("parent : %d \n",sum);
					break;
		}
		//부모프로세스인경우
		if(pid !=0)
		{
			child_pid=wait(&status);
			printf("Child has finishied : PID = %d\n",child_pid);

			//정상종료일경우
			if(WIFEXITED(status))
					printf("normal termination, exit status = %d\n",WEXITSTATUS(status));

			//시그널에 의해서 종료된경우
			else if(WIFSIGNALED(status))
				printf("abnormal termination, signal number = %d%s\n",WTERMSIG(status),WCOREDUMP(status) ? "(core file generated)" : "");
			else if (WIFSTOPPED(status))
			    printf("child stopped, signal number = %d\n", WSTOPSIG(status));
		}
	return 111;
}
		


