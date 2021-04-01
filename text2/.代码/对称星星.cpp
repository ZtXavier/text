#include<stdio.h>
int main(void)
{
    int n,j,i,m;
	scanf("%d",&n);
	m=((n+1)/2);
	for(i=1;i<=n;i++)
	{
		if(i<=m)
		{
		for(j=1;j<=(2*(m-i));j++)
		printf(" ");
		for(j=1;j<=(2*i);j++)
		printf("*");
		printf("\n");
	    }
	    else
	    {
	    for(j=1;j<=(2*(i-m));j++)
		printf(" ");
		for(j=1;j<=(2*(n-i+1));j++)
		printf("*");
		printf("\n");
		}
	 } 
	 return 0;
 } 
