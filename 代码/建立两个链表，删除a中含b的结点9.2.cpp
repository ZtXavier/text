#include<stdio.h>
#include<stdlib.h> 
//���⣺1.�޷�ɾ��������ͬ����2.ɾ����һ���������ȫ��ɾ�� (��free����ȥ���ɽ��)
typedef struct infor
{
	int num;
	int pos;
	struct infor *next;
}IN,*linklist;
linklist weicha()
{
	linklist head=NULL;
	IN *p,*q;
	int num;
	int pos=1;
	printf("������ѧ��(�����)��\n");
	while(1)
	{
		scanf("%d",&num);
		if(num==0)
		break;
		p=(IN*)malloc(sizeof(IN));
		p->num=num;
		p->pos=pos; 
		pos++;
		p->next=NULL;
		if(head==NULL)
		{
			head=p;
			q=head;
		}
		else
		{
			q->next=p;
			q=p;
		} 
	 }
	 return head; 
}
linklist toucha()
{
	linklist head=NULL;
	IN *s,*r;
	int num;
	int pos=1;
	printf("������Ҫɾ����ѧ��(�����)\n");
	while(1)
	{
		scanf("%d",&num);
		if(num==0)
		break;
		s=(IN*)malloc(sizeof(IN));
		s->num=num;
		s->pos=pos;
		pos++;
		if(head==NULL)
	{ 
		head=s;
		s->next=NULL;
		r=s;
	}
	else
	{
		head=s;
		s->next=r;
		r=s;
	}	
	}
	return head;
}

void output(linklist head)
{
	IN *r;
	r=head;
	while(r)
	{	
		printf("%d\n",r->num);
		r=r->next;
	}
}

linklist Delete(linklist head,int pos)
{
	IN *p=head,*q;
	if(head==NULL)
	{
		printf("wrong");	
	}
	if(pos==1)
	{
		q=head;
		head=q->next;
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
		if(p==NULL)
		printf("error");
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
	IN *p=head1,*q=head2;
	
	if(head1==NULL||head2==NULL)
		printf("wrong");
	while(q)
 { 
	if(p->num==q->num)
		head1=p=Delete(head1,p->pos);
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
	ha=weicha();
	output(ha);
	hb=toucha();
	output(hb);
	printf("\n���Ϊ��\n");
	hc=bijiaoshanchu(ha,hb);
	output(hc);
	return 0;
}
