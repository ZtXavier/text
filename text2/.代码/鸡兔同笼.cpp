#include<stdio.h>
int main(void)
{
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	for(a=0;a<n;a++)
	{
	    b=n-a;
	    if(a*2+b*4==m)
	    	printf("%d %d",a,b);
	    else
		continue; 
	}
	return 0;
 } 
