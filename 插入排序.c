#include<stdio.h>
int *insertsort(int *a,int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
       j=i-1;
       temp=a[i];
       while (j>=0&&temp<a[j])
       {
           a[j+1]=a[j];
           j--;
       }
       a[j+1]=temp;
    } 
    // for(i=0;i<n;i++)
    // printf("%2d",a[i]);
    return a;
}
int main(void)
{
    int n,i;
    scanf("%d",&n);
    int a[n],*b;
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    insertsort(a,n);
    for(i=0;i<n;i++)
    printf("%2d",a[i]);
    return 0;
}