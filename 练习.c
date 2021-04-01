#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//1.分析以下代码，解释并说出原因
// int main(int argc,char *argv[]){
//    int nums[2][4]={1,2,3,4,5,6,7,8};
//    int (*p)[4];
//    p=nums;
//    int *q[2]={nums[0],nums[2]};
//    printf("%d\n",nums[0][3]);
//    printf("%d\n",(*p)[3]);
//    printf("%d\n",*q[0]);
//    return 0;
// }
//2.分析以下代码，给出输出结果，并给出自己的理解
// int main(int argc,char *argv[]){
//    int a[5][2]={2,0,2,1};
//    char *str = (char *)malloc(sizeof(char)*20);
//    strcpy(str,"Xi \byoulinux\0group");
//    printf("%zu\n",sizeof(a));
//    printf("%s\n",str);
//    printf("%zu\n",sizeof(a[1][1]));
//    printf("%zu %zu",sizeof(str),strlen(str));
//    return 0;
// }
// 3.参考以下代码来解释对于static关键字的理解
// static int a=2021;
// static void func(void)
// {
//     static int b = 0;
//     int c =0;
//     printf("a = %d,b = %d,c = %d\n",a++,b++,c++);
// }
// int main(int argc,char *argv[]){
//     func();
//     func();
//     func();
//    return 0;
// }
//4.分析以下代码的运行原理,谈一谈输出的结果
// union myunion{
//     int a;
//     char b;
// };
// int is_little_endian(void){
//     union myunion u1;
//     u1.a=0x12345678;
//     if(0x78 == u1.b)
//     return 1;
//     else if(0x12 == u1.b)
//     return 0;
// }
// int is_little_endian2(void){
//     int x=0x1122;
//     char p;
//     p=((char*)&x)[0];
//     if(p==0x22)
//     return 1;
//     else
//     return 0;
    
// }
// int main(int argc,char *argv[]){
//     int i=is_little_endian2();
//     printf("%d",i);
//     return 0;
// }
//5.根据所给的代码，说明const关键字的用法，并指出标号那些是错误的
// char y[] = "Xiyoulinuxgroup",x[]="2018";
// char *const p1 = y;
// char const *p2 = y;
//     p1=x;
//     p2=x;
//    *p1=x;
//    *p2=x;
//6.猜想下面程序的输出，并谈谈自己的理解
// int main()
// {
//     int a[5][4];
//     printf("%d\n",*a);
//     printf("%d\n",*a+1);
//     printf("%d\n",*(a+1));
//     printf("%d\n",a);
//     printf("%d\n",a+1);
//     printf("%d\n",&a);
//     printf("%d\n",&a+1);
//     return 0;
// }
//7.如何将一个杂乱无章链表排序，请用多种方法解答
//8.以下输出两个代码的值相等吗
// struct icd{
//     int a;
//     char b;
//     short c;
// };
// struct cdi{
//     char a;
//     int b;
//     short c;
// };
// int main(int argc,char *argv[]){
//     printf("%zu %zu",sizeof(struct icd),sizeof(struct cdi));
//     return 0;
// }
//9.分析下面代码，并解释其结果
// #define year 2021
// #define OPERATION(x) "Xiyoulinux"#x"\n"
// #define OPERATION2(x) OPERATION(x)
// #define CALCULATE(x,y) x*y
// int main(int argc,char *argv[]){
//     int x=CALCULATE(1 + 3,4);
//     printf("%d\n",x);
//     printf(OPERATION(year));
//     printf(OPERATION2(year));
//     return 0;
// }
//10.编码题，请利用函数递归的方法逆置一个链表
//11.编码题，请利用桶排序将数组中的数进行排序
//12.我们学习的过程中会遇到阶乘的问题，请计想一想1！+2！+3！+...+50!,请写出你的思路，想想是否会数据溢出，请写出你的思路。