#include<stdio.h>
int main(void)
{
	int a=1,b=1,fn,cnt=0;
	while(1)
	{
		fn=a+b;
		a=b;
		b=fn;
		if(fn>1000)
		{
		printf("%d",b);
		break;
	}
	}
	return 0;
}

