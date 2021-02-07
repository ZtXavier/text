#include<stdio.h>
void Moveaddelement(int *a,int n)
{
    int i,j,e;
    for(i=0;i<n;i++)
        if(a[i]%2)
        {
        e=a[i];
        for(j=i;j<n-1;j++)
        a[j]=a[j+1];
        a[j]=e;
        n--;
        }
}
void MoveaddElement(int *a,int n)
{
    int t,i=0,j=n-1;
    while(i<j)
    if(!(a[i]%2))
    i++;
    else if(a[j]%2)
    j--;
    else
    {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
}
void moveaddelement(int *a,int n)
{
    int t,mid=a[0],i=0,j=n-1;
    while(i<j)
    if((a[i]<mid))
    i++;
    else if(a[j]>mid)
    j--;
    else
    {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
}  
int main(void)
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    //Moveaddelement(a,n);
    //MoveaddElement(a,n);
    moveaddelement(a,n);
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;
}