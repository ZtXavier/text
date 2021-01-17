#include<stdio.h>
int main(void)
{
	int a=0,b=1,fn,loop=1;
	double sum;
	while(loop<21)
	{
		fn=a+b;
		sum=(fn*1.0)/b;
		a=b;
		b=fn;
		printf("%lf ",sum);
		++loop;
	}
	return 0;
}

