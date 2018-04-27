#include<stdio.h>

struct Test1
{
	char a;
	int b;
	char c;
	int d;
};

struct Test2
{
	char a;
	char c;
	int b;
	int d;
};

int main()
{
	struct Test1 T1;
	struct Test2 T2;
	printf("%d\n",sizeof(T1));
	printf("%d\n",sizeof(T2));
	
	printf("%p\n",&T1.a);
	printf("%p\n",&T2.a);
	return 0;
}
