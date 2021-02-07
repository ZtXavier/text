#include<stdio.h>
int main(void)
{
    int sum = 0,numSize,k;
    printf("请输入元素个数:\n");
    scanf("%d",&numSize);
    int nums[numSize];
    for(int i=0;i<numSize;i++)
    scanf("%d",&nums[i]);
    printf("请输入子数组个数:");
    scanf("%d",&k);
    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }
    int max = sum;
    for (int i = k; i < numSize; i++) {
        sum = sum - nums[i - k] + nums[i];//利用窗口滑动的模式//
         max=max>sum?max:sum;
    }
    //double计算比int要慢，所以中间记录的值要设成int型，最后返回的时候再转换成double//
    printf("%lf",(double)(max) / k);
    return 0;
}