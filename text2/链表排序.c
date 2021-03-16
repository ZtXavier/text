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
     linklist r;
     int i=0;
     r=head->next;
     while(r)
     {
         i++;
         r=r->next;
     }
     return i;
 }
       
linklist pop_swap(linklist head,int n)
{
    int loop=1;
    linklist r,p,tail,temp;
    tail=NULL;
    r=head;
    printf(".......");
    while (loop<n)
    {
        p=head->next;
        r=head;
        while ((p->next)!=tail)
        {
            if((p->num)>(p->next->num))
            {
                temp=p->next;
                r->next=p->next;
                p->next=p->next->next;
                r->next->next=p;
                p=temp;

            }
            p=p->next;
            r=r->next;
        }
        tail=p;
        loop++;
    }
    return head;
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
}
int main(void)
{
    linklist ha,hb;
    int i;
    ha=initlist();
    ha=weicha(ha);
    output(ha);
    i=length(ha);
    hb=pop_swap(ha,i);
    printf("排序结果为:");
    output(hb);
    return 0;
}