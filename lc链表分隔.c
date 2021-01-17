
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
    linklist fenge(linklist head, int x) {
         linklist less_head,more_head;
         less_head=initlist();
         more_head=initlist();
         STU *prel=less_head,*prem=more_head;
         head=head->next;

        while(head){
            if(head->num<x)
            {
                prel->next=head;
                prel=head;
            }
            else
            {
                prem->next=head;
                prem=head;
            }
            head=head->next;
        }
        prel->next=more_head->next;
        prem->next=NULL;
        return less_head;
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
    int main(void)
{
    STU *stu1,*stu2;
    int n;
    stu1=initlist();
    stu1=weicha(stu1);
    output(stu1);
    printf("请输入你要分隔的数");
    scanf("%d",&n);
    stu2=fenge(stu1,n);
    output(stu2);
    return 0;
}