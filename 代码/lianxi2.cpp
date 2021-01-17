#include<stdio.h>
int main(void)
{
	int i,j,n,m,max=-1,min=101,k,l,sum=0;
	scanf("%d%d",&i,&j);
	int a[i][j];
	float ave[i],ma;
	for(n=0;n<i;n++)
	{
		for(m=0;m<j;m++)
		scanf("%d",&a[n][m]);
	}
	for(n=0;n<i;n++)
	{
		for(m=0;m<j;m++)
		{
			if(min>=a[n][m])
			{
				min=a[n][m];
				k=n;
				l=m;
			}
		}
		a[k][l]=0;
		min=101;
	}
	max=-1;
	for(n=0;n<i;n++)
	{
		for(m=0;m<j;m++)
		{
			if(max<=a[n][m])
			{
				max=a[n][m];
				k=n;
				l=m;
			}
		}
		a[k][l]=0;
		max=-1;
	}	
	
	for(n=0;n<i;n++)
	{
		for(m=0;m<j;m++)
		sum+=a[n][m];
		ave[n]=sum/((j-2)*1.0);
		sum=0.0;
	}
	ma=ave[0];
	for(n=0;n<i;n++)
	if(ma<=ave[n])
	{
		ma=ave[n];
	}
	printf("%.2f",ma);
	return 0;
 } 
