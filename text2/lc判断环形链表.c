#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//定义两个指针 一个快指针一个慢指针看作追击问题//
typedef struct student
{
    int num;
    struct student *next;
}STU,*linklist;
linklist initlist()
{
    STU *head;
    head=(STU*)malloc(sizeof(STU));
    head->next=NULL;
    return head;
}
linklist createbyreal(linklist head)
{
    STU *p,*q;
    int n;
    p=head;
    while(1)
    {
        scanf("%d",&n);
        if(n<0)
        break;
        q=(STU*)malloc(sizeof(STU));
        q->num=n;
        q->next=p->next;
        p->next=q;
        p=q;
    }
    q->next=head->next;//判断条件
    return head;
}
void output(linklist head)
{
    STU *p;
    p=head->next;
    while(p)
    {
        printf("%d",p->num);
        p=p->next;
    }
    printf("\n");
}
void panduan(linklist head)
{
    STU *fast=head,*slow=head;
    int flag=0;
    while(fast&&fast->next)
    {
         fast=fast->next->next;
         slow=slow->next;
         if(fast==slow)
         {
         flag=1;
         break;
         }
    }
    if(flag==1)
    printf("true");
    else
    printf("false");
}
int main(void)
{
    STU *stu1;
    stu1=initlist();
    stu1=createbyreal(stu1);
    //output(stu1);
    panduan(stu1);
    return 0;
}