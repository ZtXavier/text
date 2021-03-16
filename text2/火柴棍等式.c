#include<stdio.h>
int  fun(int x){
    int num=0;//用来计数的变量，初始化
    int f[10]={6,2,5,5,4,5,6,3,7,6};//用一个数组来记录0到9的火柴数
    while(x/10!=0){//如果x/10的商不等于零的话,这个数至少有两位
             //获得这个数的末尾数字并将所需要的火柴棍的根数累加到num中
    num+=f[x%10];
    x/=10;
    }
    num+=f[x];
    return num;
}
int main(void){
    int a,b,c,m,sum=0;//sum是用来计数的，因此要初始化
    scanf("%d",&m);//读入火柴棍的个数
                   //开始枚举a和b
    for(a=0;a<=1111;a++){
        for(b=0;b<=1111;b++){
            c=a+b;//计算出c
            //fun是用来计算每一个数所用的火柴棍的个数
            if((fun(a)+fun(b)+fun(c))==(m-4)){//减去等号和加号所需要的火柴棍共四根
            printf("%d+%d=%d\n",a,b,c);
            sum++;
        }
    }
 }
        printf("一共可以拼出%d各不同的等式",sum);
        getchar();
        getchar();
        return 0;
}