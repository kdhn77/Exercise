/*************************************************************************\
*                  Copyright (C) Michael Kerrisk, 2017.                   *
*                                                                         *
* This program is free software. You may use, modify, and redistribute it *
* under the terms of the GNU General Public License as published by the   *
* Free Software Foundation, either version 3 or (at your option) any      *
* later version. This program is distributed without any warranty.  See   *
* the file COPYING.gpl-v3 for details.                                    *
\*************************************************************************/

/* Listing 4-3 */

#include <sys/stat.h>	//여러프로그램에 쓰이는 형 정의
#include <fcntl.h>
#include <ctype.h>
#include "tlpi_hdr.h" //책에서 제공하는 함수가 있는 헤

int
main(int argc, char *argv[])
{
	/*데이터형이 이러한 이유 : c의 기초데이터형을 쓸 수도 있지만 기초 데이터형은 유닉스 
	구현마다 다르거나 컴파일 환경에 따라 다를 수 있어서 이식성이 떨어진다. 따라서 susv3
	데이터형을 명시했고 이를 사용한다.*/
    size_t len;
	//unsigned int.. 바이트수로 나타낸 객체크기
    off_t offset;
	//signed int.. 파일 오프셋 또는 크기
    int fd, ap, j;
    char *buf;
    ssize_t numRead, numWritten;
	//signed int.. 바이트 수 또는 (음수로 나타낸)에러 표시
    if (argc < 3 || strcmp(argv[1], "--help") == 0)
        usageErr("%s file {r<length>|R<length>|w<string>|s<offset>}...\n",
                 argv[0]);
	/*usageErr() 명령행 인자의 용법이 잘못됐을때 쓴다. printf()스타일의 인자 목록을 
	받아서 포맷된 메시지 앞에 usage:를 붙여서 표준에러로 출력한 뒤 exit()를 호출해 
	프로그램 종료.*/
	//명령행 인자가 3미만이거나 2번째 인자가 --help일 경우 usage출력후 프로그램종료.

    fd = open(argv[1], O_RDWR | O_CREAT,
                S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
                S_IROTH | S_IWOTH);                     
	/* rw-rw-rw- 사용자:그룹:other */
    if (fd == -1)
        errExit("open");
	//파일오픈 실패시 예외처리.

    for (ap = 2; ap < argc; ap++) {
	//여러개의 명령행 인자 차례대로 받는 반복
        switch (argv[ap][0]) {
        case 'r':   /* Display bytes at current offset, as text */
        case 'R':   /* Display bytes at current offset, in hex */
            len = getLong(&argv[ap][1], GN_ANY_BASE, argv[ap]);
		/*long getLong(const char *arg, int flags, const char *name) arg가 
		가리키는 문자열을 long으로 변환한다. arg가 유효한 정수 문자열이 아니면 
		에러 메시지 출력후 프로그램 종료. name인자는 null이 아니면 arg에 들어있는 
		인자가 무엇인지를 나타내어야 한다. flag 인자는 getLong() 함수의 동에 
		대한 약간의 제어를 제공.*/
		//문자를 정수로 바꿔주는 함수
            buf = malloc(len);
            if (buf == NULL)
                errExit("malloc");

            numRead = read(fd, buf, len);
	/*read(데이터 수신대상을 나타내는 파일전달, 수신한 데이터를 저장할 버퍼의 주소값,
	수신할 최대 바이트 수)*/
            if (numRead == -1)
                errExit("read");
		//파일읽기 실패시
            if (numRead == 0)//파일 끝 {
                printf("%s: end-of-file\n", argv[ap]);
            } else {
                printf("%s: ", argv[ap]);
                for (j = 0; j < numRead; j++) {
                    if (argv[ap][0] == 'r')
                        printf("%c", isprint((unsigned char) buf[j]) ?
                                                buf[j] : '?');
		//버프값이 프린트 가능한 문자인지 검사. 없으면 '?"출력 가능하면 버프 출력
                    else
                        printf("%02x ", (unsigned int) buf[j]);
                }
                printf("\n");
            }

            free(buf);
            break;

        case 'w':   /* Write string at current offset */
            numWritten = write(fd, &argv[ap][1], strlen(&argv[ap][1]));
            if (numWritten == -1)
                errExit("write");
            printf("%s: wrote %ld bytes\n", argv[ap], (long) numWritten);
            break;

        case 's':   /* Change file offset */
            offset = getLong(&argv[ap][1], GN_ANY_BASE, argv[ap]);
            if (lseek(fd, offset, SEEK_SET) == -1)
                errExit("lseek");
            printf("%s: seek succeeded\n", argv[ap]);
            break;

        default:
            cmdLineErr("Argument must start with [rRws]: %s\n", argv[ap]);
		//프로그램에 넘긴 명령행 인자의 에러를 알려줄 때 사용한다.
        }
    }

    if (close(fd) == -1)
        errExit("close");

    exit(EXIT_SUCCESS);
}
