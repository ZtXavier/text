#include<stdio.h>
int maxScore(int* cardPoints, int cardPointsSize, int k){
int i,sum=0,max,loop=k,n=cardPointsSize,j=0;
for(i=k-1;i>=0;i--)
sum+=cardPoints[i];
max=sum;
while(j<loop)
{
    sum=sum-cardPoints[loop-j-1]+cardPoints[n-j-1];
    j++;
    if(sum>max)
    max=sum;
}
return max;
}
int main(void)
{
    int n,m,k;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    scanf("%d",&k);
    m=maxScore(a,n,k);
    printf("%d",m);
    return 0;
}