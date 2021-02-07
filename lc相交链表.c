#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct student
{
    int num;
    struct student*next; 
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
       r=s;
    }
     s->next=NULL;
     return head;       
 }
 linklist charu(linklist head1,linklist head2)
 {
    STU *p,*q;
    int loop;
    p=head1;
    q=head2;
    printf("输入要插入的节点:\n");
    scanf("%d",&loop);
    while(q->next)
    q=q->next;
    while (loop)
    {
        p=p->next;
        loop--;
    }
    q->next=p;
    return head1;
 }
void output(linklist head)
{
	STU *r;
	r=head->next;
	while(r)
	{	
		printf("%d ",r->num);
		r=r->next;
    }
    printf("\n");
}
linklist panduan(linklist head1,linklist head2)
{
    STU *p,*s,*L,*I;
    L=p=head1->next;
    I=s=head2->next;
   while(s!=p) 
    {
        p=p==NULL?I:p->next;
        s=s==NULL?L:s->next;
    }
    return p;
}


int main(void)
{
    STU *stu1,*stu2,*p;
    stu1=initlist();
    stu2=initlist();
    stu1=weicha(stu1);
    stu2=weicha(stu2);
    output(stu1);
    output(stu2);
    //stu1=charu(stu1,stu2);
   //output(stu1);
    //output(stu2);
    p=panduan(stu1,stu2);
    if(p==NULL)
    printf("NULL");
    else
    printf("相交的数字为：%d",p->num);
    return 0;
}