#include<stdio.h>
#include<stdlib.h> 
//问题：1.无法删除两个相同的数2.删掉第一个数结果会全部删除 
typedef struct infor
{
	int num;
	int pos;
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
	int pos=1;
	q=head;
	printf("请输入学号(负数结束)：\n");
	while(1)
	{
		scanf("%d",&num);
		if(num<0)
		break;
		p=(IN*)malloc(sizeof(IN));
		p->num=num;
		p->pos=pos; 
		pos++;
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
	int pos=1;
	printf("请输入要删除的学号(负数结束)\n");
	while(1)
	{
		scanf("%d",&num);
		if(num<0)
		break;
		s=(IN*)malloc(sizeof(IN));
		s->num=num;
		s->pos=pos;
		pos++;
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
		printf("%d\n",r->num);
		r=r->next;
	}
}
linklist Delete(linklist head,int pos)
{
	IN *p=head->next,*q;
	if(p==NULL)
	{
		printf("wrong");	
	}
	if(pos==1)
	{
		q=head->next;
		head->next=q->next;
		//free(q);
	}
	else
	{
		int j=1;
		while(j<pos-1&&p)
		{
			p=p->next;
			j++;
		}
		if(p==NULL||p->next==NULL)
		{
		printf("error");
		getchar();
		return head;
		}
		else
		{
			q=p->next;
			p->next=q->next;
			free(q);
		}
		return head;
	}
}
linklist bijiaoshanchu(linklist head1,linklist head2)
{
	IN *p=head1->next,*q=head2->next;
	
	if(head1->next==NULL||head2->next==NULL)
	{
		printf("wrong");
		
	}
	while(q)
 { 
	    if(p->num==q->num)
		p=Delete(head1,p->pos);
		p=p->next;
		if(p==NULL)
		{
		p=head1;
	    q=q->next;
	    }
 }
return head1;
}
int main(void)
{
	linklist ha,hb,hc;
	ha=initlist();
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