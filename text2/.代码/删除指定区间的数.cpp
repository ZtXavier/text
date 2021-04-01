#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int num;
	struct node *next;
 }Node,*linklist;
linklist initlist() 
{
	linklist head;
	head=(Node*)malloc(sizeof(Node));
	head->next=NULL;
	return head;
}
linklist weicha(linklist head)
{
	Node *p,*q;
	int num;
	int pos=1;
	printf("请输入学号(零结束)：\n");
	while(1)
	{
		scanf("%d",&num);
		if(num==0)
		break;
		p=(Node*)malloc(sizeof(Node));
		p->num=num;		
		p->next=NULL;
		if(head->next==NULL)
		{
			head->next=p;
			q=head->next;
		}
		else
		{
			q->next=p;
			q=p;
		} 
	 }
	 return head; 
}
linklist Delete(linklist head,int a,int b)
{
	Node *p=head,*q,*r;
	if(p->next==NULL)
		printf("error");	
	while(p)
	{
		r=p;
		q=p->next;
		if(q->num==a)
		{
			while(q)
			{
				if(q->num==b)
				{
				r->next=q->next;
				return head;
			    } 
				q=q->next;
			}
		}
		p=p->next;
	}
	
}
void output(linklist head)
{
	Node *p;
	p=head->next;
	while(p)
	{
		printf("%d\n",p->num);
		p=p->next;
	 } 
}
int main(void)
 {
 	int n,m;
 	linklist ha;
 	ha=initlist();
 	ha=weicha(ha);
 	output(ha);
 	printf("请输入要删除的区间："); 
 	scanf("%d%d",&n,&m);
 	ha=Delete(ha,n,m);
 	output(ha);
 	return 0;
 }
