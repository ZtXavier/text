#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
    int a[5];
    printf("%p\n",a);
    printf("%p\n",a+1);
    printf("%p\n",&a);
    printf("%p\n",&a+1);
    return 0;
}
