#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize){
int a=ASize,b=BSize,i=0,j=0,ret;
*returnSize=2;
int* ans=malloc(sizeof(int)*(*returnSize));
int sumA = 0;
    for (i = 0; i < a; ++i) {
        sumA += A[i];
    }
int sumB = 0;
    for (i = 0; i < b; ++i) {
        sumB += B[i];
    }
ret=(sumA-sumB)/2;
int bk=1;
for(i=0;i<b&&bk;i++){
for(j=0;j<a;j++){
    if(ret==(A[j]-B[i])){
    ans[0]=A[j];
    ans[1]=B[i];
    bk=0;   //减少时长的条件，找到答案后立刻停止//
    break;
    }
}
}
 return ans;
}
//暴力破解法，要学习哈希算法//