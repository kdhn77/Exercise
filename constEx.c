#include<stdio.h>

int max(int *p)
{
	int i, tmp=-10000;
	for(i=0;i<10;i++)
	{
	if(tmp<p[i])
		tmp=p[i];
	}
	return tmp;
}
void main()
{
	int a[]={1,2,3,4,5,6,7,8,9,10};
	int m;
	printf("%d\n",m=max(a));

}


