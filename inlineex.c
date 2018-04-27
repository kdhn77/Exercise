#include <stdio.h>

extern inline int square(int x)
{
	return x*x;
}
double add(int x,int y)
{
	return (square(x)+square(y));
}

main()
{
	int x=2, y=3;
	double result;
	result=(double)add(x,y);
	printf("%lf\n",result);
}
