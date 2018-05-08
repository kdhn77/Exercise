#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 100
int main(void)
{
    int fd,pos;
    char temp[100];
    char temp1[100];
    char rbuf[100];
    int wcount;
    int rcount;
    fd= open("./test.txt",O_RDWR | O_CREAT | O_TRUNC, \
          S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH);
//읽고쓰기로 없으면 만들고 있다면 공백상태로 만든다.
//파일권한은 유저에게 쓰기와 읽기 그룹에겐 읽기 다른사용자는 읽기로
    //예외처리 if문 오픈 실패시 -1값임.
    if(fd==-1)
    {
        printf("file open error!!\n");
	return -1;
    }
    printf("fd=%d\n",fd);
//버퍼에 테스트 문자열 만들기
    sprintf(temp,"Do not count the before they hatch.\n");
   // write(1,temp,strlen(temp)); 
   // stdin -> fd=0 stout -> fd=1 stderr-> fd=2
//test.txt에 문자열 쓰기
    wcount= write(fd,temp,strlen(temp)); 
//파일에 쓴 문자열 갯수 출력
    printf("wcount =%d \n",wcount);
   // close(fd);
   // fd=open("./test.txt",O_RDONLY);
//파일내 커서 위치를 시작점 기준으로 offset 0번지로 이동
    pos= lseek(fd,0,SEEK_SET);
	//lseek(fd,offset,SEEK_END);
	//lseek(fd,offset,SEK_CUR);
// lssek로 정상적 이동이 되었는지 확인
    printf("pos=%d\n",pos);    
//파일읽기 -> rbuf에 채움
    rcount= read(fd,rbuf,BUFSIZE);
    strncpy(temp1,rbuf,17);
    printf("%s\n",temp1);
    strcat(temp1,"eggs ");
    printf("%s\n",temp1);
    lseek(fd,17,SEEK_SET);
    read(fd,rbuf,BUFSIZE);
    printf("%s\n",rbuf);
    strcat(temp1,rbuf);
    printf("%s\n",temp1);
    lseek(fd,0,SEEK_SET);
    write(fd,temp1,strlen(temp1));


//읽은 문자열 갯수확인
    printf("rcount=%d\n",rcount);
//읽은 버퍼의 내용 확인
    printf("rbuf : %s\n",rbuf);
//파일 닫기
    close(fd);
/*
    fd = creat("./test2.txt",0764);
    if(fd==-1)
    {
        printf("file open error!!\n");
	return -1;
    }
    printf("fd=%d\n",fd);
    close(fd);
*/
    return 0;
}
