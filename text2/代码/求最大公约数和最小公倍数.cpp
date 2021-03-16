#include<stdio.h>
int main(void)
{
	int n,m,t,w,z; 
	scanf("%d%d",&n,&m);
	w=n*m;
	while(n)
	{
		t=m%n;
		m=n;
		n=t;
	}
	z=w/m;
	printf("%d %d",m,z);
	return 0;
}

