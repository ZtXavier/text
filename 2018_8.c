#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int f(unsigned int num){  //与运算计算num二进制中的1的个数
    unsigned int i;
    for(i=0;num;i++){
    printf("%d\n",num);
    num &= (num-1);  //目的是将该num末尾的1去掉
    }
    return i;
}
int main(int argc,char *argv[]){
    int num=2018;
    int i;
    i=f(num);
    printf("%d\n",i);
}

