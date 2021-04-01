#include<stdio.h>
#include<math.h>
int main(void)
{
    int n,i,j,x=1,num=0;
    scanf("%d",&n);
	for(i=pow(10,n-1);i<pow(10,n);i++)
	{
		j=i;
		while(j)
		{
		 x=j%10;
		 num+=pow(x,n);
		 j/=10;
	    }
	    if(num==i)
	    printf("%d ",i);
		num=0;
	 } 
	 return 0;
 } 
