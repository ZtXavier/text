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
       
linklist pop_swap(linklist head)
{
    linklist pre,p,tail,temp;
    tail=NULL;
    pre=head;
    while ((head->next->next)!=NULL)
    {
        p=head->next;
        pre=head;
        while ((p->next)!=tail)
        {
            if((p->num)>(p->next->num))
            {
                temp=p->next;
                pre->next=p->next;
                p->next=p->next->next;
                pre->next->next=p;
                p=temp;

            }
            p=p->next;
            pre=pre->next;
        }
        tail=p;
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
    ha=initlist();
    ha=weicha(ha);
    output(ha);
    hb=pop_swap(ha);
    printf("排序结果为:");
    output(hb);
    return 0;
}