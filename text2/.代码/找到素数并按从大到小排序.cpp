#include<stdio.h>
int main(void)
{
int i,j,temp,flag=1,cnt=1;
int a[10],b[10];
for(i=0;i<10;i++)
scanf("%d",&a[i]);
for(i=0;i<9;i++)
{
	for(j=0;j<9-i;j++)
	{
	if(a[j]>a[j+1])
	{
		temp=a[j];
		a[j]=a[j+1];
		a[j+1]=temp;
	}
    }
}
for(i=0;i<10;i++)
{
	if(a[i]==1)
	continue;
	for(j=2;j<a[i]&&(a[i]%j);j++);
	if(j>=a[i])
	{
		b[cnt]=a[i];
		flag=0;
		cnt++;
	}
     
}
if(flag)
printf("Not found!");
else
for(i=1;i<cnt;i++)
{
printf("%d",b[i]);
if(i<cnt-1)
printf(",");
}

return 0;
}
