#include<stdio.h>
void quicksort(int *a,int l,int r)
{
	int i=r,j=l,temp;
	int mid=a[(r/2)+1];
	while(j<=i)
	{
	while(a[j]>mid)
	j++;
	while(a[i]<mid)
	i--;
	if(i>=j)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		j++;
		i--;
	}
}
    if(i>l) quicksort(a,l,i);
    if(j<r) quicksort(a,j,r);
}
int main(void)
{
	int n,i;
	printf("������Ԫ�ظ�����\n");
	scanf("%d",&n);
	int a[n];
	printf("����������Ԫ��"); 
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	quicksort(a,0,n-1);
	printf("������Ϊ:\n");
	for(i=0;i<n;i++)
	printf("%d",a[i]);
	return 0;
}
