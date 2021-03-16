#include<stdio.h>
int main(void){
    int n,sum=0,cnt=0,i,j;
    scanf("%d",&n);
    for(i=2;i<=n;i++){
    for(j=2;(j<=i)&&(i%j!=0);j++);
    if(j==i){
    sum+=i;
    if(sum>n){
    break;
    }
    cnt++;
    printf("%d\n",i);
    }
}
    printf("%d\n",cnt);
    return 0;
}