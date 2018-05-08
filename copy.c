#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#define BUFSIZE 256

int main(int argc, char* argv[])
{
	char buf[BUFSIZE];
	int r_fd,w_fd,rcount;
	
	if(argc<3)
	{
		perror("usage : copy file1 file2");
		return -1;
	}
	//원본파일열기
	r_fd=open(argv[1],O_RDONLY);
	if(r_fd=-1)
	{
		perror("argv[1]");
		return -1;
	}
	//새로 생성되는 파일 열기
	w_fd=open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,S_IRUSR|S_IWUSR);
	if(w_fd=-1)
	{
		perror("argv[2]");
		return -1;
	}
	//복사하기
	while((rcount=read(r_fd,buf,sizeof(buf)))>0)
		write(w_fd,buf,rcount);
	close(r_fd);
	close(w_fd);
		
	return 0;
}
