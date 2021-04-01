#include<stdio.h>
void hannuo(int n,char x,char y,char z)
{
	if(n==1)printf("%c-->%c\n",x,z);
	else
	{
		hannuo(n-1,x,z,y);
	    printf("%c-->%c\n",x,z);
	    hannuo(n-1,y,x,z);
	}
}
int main(void)
{
	int m;
	scanf("%d",&m);
	hannuo(m,'A','B','C');
	return 0;
}

