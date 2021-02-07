#include<stdio.h>
#include<stdlib.h> 
#include<malloc.h>
typedef struct infor
{
	int num;
	struct infor *next;
}IN,*linklist;
linklist initlist()
{
	linklist head;
	head=(IN*)malloc(sizeof(IN));
	head->next=NULL;
	return head;
}
linklist weicha(linklist head)
{
	IN *p,*q;
	int num;
	q=head;
	printf("请输入学号(负数结束)：\n");
	while(1)
	{
		scanf("%d",&num);
		if(num<0)
		break;
		p=(IN*)malloc(sizeof(IN));
		p->num=num;
		q->next=p;
		q=p;
	 }
	 p->next=NULL;
	 return head; 
}
linklist toucha(linklist head)
{
	IN *s;
	int num;
	printf("请输入要删除的学号(负数结束)\n");
	while(1)
	{
		scanf("%d",&num);
		if(num<0)
		break;
		s=(IN*)malloc(sizeof(IN));
		s->num=num;
		s->next=head->next;
		head->next=s;
	}
	return head;
}
void output(linklist head)
{
	IN *r;
	r=head->next;
	while(r)
	{	
		printf("%d ",r->num);
		r=r->next;
	}
    printf("\n");
}
linklist bijiaoshanchu(linklist head1,linklist head2)
{
	IN *p=head1->next,*q=head2->next,*s;
    s=head1;
	if(head1->next==NULL||head2->next==NULL)
	{
		printf("wrong");	
	}
	while(q)
 { 
	    if(p->num==q->num)
        {
        s->next=p->next;
        p=p->next;
        }
        else
        {
            p=p->next;
            s=s->next;
        }
		if(p==NULL)
		{
        p=head1->next;
		s=head1;
	    q=q->next;
	    }
 }
return head1;
}
int main(void)
{
	linklist ha,hb,hc;
	ha=initlist();
    hc=initlist();
	ha=weicha(ha);
	output(ha);
	hb=initlist();
	hb=toucha(hb);
	output(hb);
	printf("\n结果为：\n");
	hc=bijiaoshanchu(ha,hb);
	output(hc);
	return 0;
}