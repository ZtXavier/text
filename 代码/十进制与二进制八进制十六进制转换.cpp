#include<stdio.h>
int main(void)
{
	int i,n,m,count=-1;
	int a[100];
	scanf("%d",&n);
	printf("要转换成多少进制数呢?\n");
	scanf("%d",&m);
	switch(m)
	{
		case 2:while(n)
	    {
	    	++count;
		    a[count]=n%2;
		    n/=2;
	    }
		while(count>=0)
		{
			printf("%d ",a[count]);
			--count; 
		};break;
	    case 8:while(n)
	    {
	    	++count;
		    a[count]=n%8;
		    n/=8;
	    }
		while(count>=0)
		{
			printf("%d ",a[count]);
			--count; 
		};break;
	    case 16:while(n)
	    {
	    	++count;
		    a[count]=n%16;
		    n/=16;
	    }
		while(count>=0)
		{
			
			if(a[count]==10)
	    	printf("A ");
	    	else if(a[count]==11)
	    	printf("B ");
	    	else if(a[count]==12)
	    	printf("C ");
	    	else if(a[count]==13)
	    	printf("D ");
	    	else if(a[count]==14)
	    	printf("E ");
	    	else if(a[count]==15)
	    	printf("F ");
	    	else
			printf("%d ",a[count]);
			--count; 
		};break;
		
	 }
	 return 0;
}
