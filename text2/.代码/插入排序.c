#include<stdio.h>
int main(void)
{
	int n,i,j,temp;
	printf("������Ԫ�ظ���:\n");
	scanf("%d",&n);
	int a[n];
	printf("������Ԫ��:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=1;i<n;i++)
	{
		j=i-1;
		temp=a[i];
		while(j>=0&&temp<a[j])
		{
	    a[j+1]=a[j];
	    j--;
	    }
	    a[j+1]=temp;
	 } 
	 printf("������Ϊ��\n");
	 for(i=0;i<n;i++)
	 printf("%2d",a[i]);
	return 0;
}
