//用数组作为每一个分数的桶，每个桶里的数作为该分数出现的次数//
#include<stdio.h>
int main(void)
{
    int n,j,i,k;
    printf("请输入桶的数量\n");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<=n;i++)
    a[i]=0;
    printf("请输入排序的数的个数:\n");
    scanf("%d",&k);
    for(i=1;i<=k;i++)
    {
        scanf("%d",&j);
        a[j]++;
    }
    for(i=0;i<=n;i++)
    for(j=1;j<=a[i];j++)
    printf("%d ",i);
    getchar();
    getchar();
    return 0;
}