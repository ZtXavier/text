#include<stdio.h>
#include<math.h>
int taijie(int n)
{
	if(n==1)
	return 1;
	if(n==2)
	return 2;
	if(n==3)
	return 4;
	if(n>3)
	return taijie(n-1)+taijie(n-2)+taijie(n-3); 
	
}
int main(void)
{
    int n;
    scanf("%d",&n);
   printf("%d",taijie(n));
    return 0;
}
