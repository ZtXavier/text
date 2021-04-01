#include<stdio.h>
int main(void)
{
	int n,i,j,temp;
	printf("请输入元素个数:\n");
	scanf("%d",&n);
	int a[n];
	printf("请输入元素:\n");
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
	 printf("排序结果为：\n");
	 for(i=0;i<n;i++)
	 printf("%2d",a[i]);
	return 0;
}
