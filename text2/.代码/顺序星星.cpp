#include<stdio.h>
int main(void)
{
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n-i;j++)
    	printf("*");
    	printf("\n");
    	for(j=0;j<i+1;j++)
    	printf(" ");
	}
	return 0;
 } 
