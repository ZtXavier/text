#include<stdio.h>
int main(void)
{
    int n,a[1000]={0},b[1000]={0}; //初始化数组使其便为零
    scanf("%d",&n);
    a[0]=b[0]=1;          //将第一个元素作为1方便后面的乘法运算
    for(int i=2;i<=n;i++){
    for(int j=0;j<100;j++)
           a[j]*=i;      //在a这个数组中计算每个数的阶乘
    for(int j=0;j<100;j++)
        if(a[j]>9){
           a[j+1]+=a[j]/10;
           a[j]%=10;
        }
        //此部分为在计算每个部分的阶乘的数的结果
        for(int j=0;j<100;j++){
            b[j]+=a[j];
            if(b[j]>9){
            b[j+1]+=b[j]/10;
            b[j]%=10;
            }
        }
        //此部分为计算每个阶乘结果的和
}
    int i;
    for(i=100;i>=0&&a[i]==0;i--);
    for(int j=i;j>=0;j--)
    printf("%d",b[j]);
    return 0;
}