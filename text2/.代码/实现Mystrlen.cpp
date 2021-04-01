#include<stdio.h>
int Mystrlen(char *a);
int main(void)
{
	char a[10];
	scanf("%s",a);
	printf("%d",Mystrlen(a));
	return 0;
}
int Mystrlen(char *a)
{
	int count=0;
    while(*a)
    {
    	count++;
    	a++; 
	}
	return count;	
}
