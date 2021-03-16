#include<stdio.h>
int main(void)
{
	int loop=1,n=1;
	float sum=0.0,x=0.8;
	while(loop<11)
	{
		sum+=x/n;
		printf("%f ",sum);
		x*=x;
		++loop;
		n*=loop;
	}
	return 0;
}

