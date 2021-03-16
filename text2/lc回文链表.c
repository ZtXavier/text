#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct student
{
    int num;
    struct student *next;
    struct student *pirror;
}STU,*linklist;
linklist initlist()
{
    linklist head;
    head=(STU*)malloc(sizeof(STU));
    head->next=NULL;
    return head;
}
linklist weicha(linklist head)
{
    STU *r,*s;
    int num;
    r=head;
    printf("请输入数字\n");
    while(1) 
    {
       scanf("%d",&num);
       if(num<0)
       break;
       s=(STU*)malloc(sizeof(STU));
       s->num=num;
       r->next=s;
       s->pirror=r;
       r=s;
    }
     s->next=NULL;
     return head;       
 }
int length(linklist head)
 {
     STU *p;
     int cnt=0;
     p=head->next;
     while(p)
     {
        cnt++;
        p=p->next;
     }
     return cnt;

 }
 int  panduan(linklist head,int pos)
 {
     STU *p,*s;
     int n=pos;
     s=p=head;
     while(n)
     {
        p=p->next;
        n--;
     }
     s=p;
     p=p->next;
     while (pos)
     {
        pos--;
        if(s->num!=p->num)
        {
            printf("false");
            return 0;
        }
         p=p->next;
         s=s->pirror;  
     }
     printf("ture");
     return 0;
 }
 int main(void)
 {
    STU *head;
    int n;
    head=initlist();
    head=weicha(head);
    n=length(head);
    if(n%2==0)
        panduan(head,(n+1)/2);
    else
        printf("false");
    return 0;
 }