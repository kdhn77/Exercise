#include <stdio.h>
#include <string.h>

#define DEBUG
void Inputstring(char *arr)
{
	char a;
	int i=0;
	printf("영어 소문자(a~z)중 입력하세요(최대50개)\n");
	while(1)
	{
		if(i>=50)
			break;
		scanf("%c",&a);
		getchar();
		if(a=='`')
			break;
		if(a<'a'|| a>'z')
		{
			printf("영어 소문자가 아닙니다.다시입력하세요.\n");
			continue;
		}
	
		arr[i]=a;
		i++;
	}
}

void Printarr(char *arr)
{
	int i=0;
	while(arr[i]!=NULL)
	{
		printf("%c ",arr[i]);
		i++;
	}
	printf("\n");
}

//팰린드롬인지 확인한다
//문자열의 개수
void Chk_pld(char *arr)
{
	int i=0;
	int strsize=strlen(arr);
	if(strsize%2==1)
		printf("strsize is odd\n");
	else
		printf("strsize is even\n");
	for(i=0;i<(strsize>>1);i++)
	{
		if(arr[i]!=arr[strsize-1-i])
		{
			printf("arr is not pallidrome.\n");
			return;
		}
	}
	printf("arr is pallidrome\n");
	
}

main()
{
	char arr[50]={NULL};
	Inputstring(arr);
#ifdef DEBUG
	Printarr(arr);
#endif
	Chk_pld(arr);
}
