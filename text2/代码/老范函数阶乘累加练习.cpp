#include<stdio.h>
double leijiajiecheng(int n)
{
	int i,x=1;
	double sum=0;
	for(i=1;i<n+1;sum+=1.0/(x*=i++)){
	};
	
	return sum;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	printf("%lf",leijiajiecheng(n));
	return 0;
}
