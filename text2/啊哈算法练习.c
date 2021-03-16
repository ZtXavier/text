#include<stdio.h>
int main(void)
{
    int a[1001],n,i,t;
    for(i=1;i<1000;i++)
    a[i]=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&t);
        a[t]=1;
    }
    for(i=1;i<=1000;i++)
    {
    if(a[i]==1)
    printf("%d ",i);
    }
    getchar();getchar();
    return 0;
}
//第二种用冒泡排序，之后再用if(a[i]!=a[i-1]);printf("%d ",a[i])从i-1开始