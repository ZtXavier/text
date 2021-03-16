#include<stdio.h>
void quicksort(int *a,int l,int r)
{
    int t,i=l,j=r,temp;
    if(l>r)
    return;
    temp=a[l];
    i=l;
    j=r;
    while (i!=j)
    {
        while(a[j]>=temp&&i<j)
        j--;
        while (a[i]<=temp&&i<j)
        i++;
        if(i<j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
        
    }
    a[l]=a[i];
    a[i]=temp;
    quicksort(a,l,i-1);
    quicksort(a,i+1,r);
}
int main(void)
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;
}