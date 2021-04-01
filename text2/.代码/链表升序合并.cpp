#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
typedef struct student
{
    char name[20];
	int id;
	int score;
	struct student *next;	
}STU,*linklist;
linklist weicha()
{
	STU *r,*s;
	linklist head=NULL;
	char name[20];
	int id;
	int score;
	while(1)
	{
		scanf("%d",&id);
		if(id<0)
		break;
		scanf("%s",name);
		scanf("%d",&score);
		s=(STU*)malloc(sizeof(STU));
		strcpy(s->name,name);
		s->id=id;
		s->score=score;
		s->next=NULL;
		if(head==NULL)
		{
			head=s;
			r=head;
		}
		else
		{
			r->next=s;
			r=s;
		}
	}
	return head;
}
linklist hebing(linklist ha,linklist hb)
{
	linklist hc;
	STU *p,*q,*r;
	p=ha;
	q=hb;
	hc=NULL;
	while(p&&q)
	{
		if(hc==NULL)
		{
			if(p->id<=q->id)	
		      {
			   r=hc=p;
			   p=ha->next;
			   }  	
		    else
			{
		       r=hc=q;
	           q=hb->next;
	        }
		}
		else
		{
		if(p->id<=q->id)
		{
			
			r->next=p;
			r=p;
			p=p->next;
		}
		else
		{
			r->next=q;
			r=q;
			q=q->next;
		}
	}
	}
	if(p) r->next=p;
	if(q) r->next=q;
	return hc;
	free(hb);
}
void output(linklist head)
{
	STU *p=head;
	if(p==NULL)
	printf("无数据"); 
	while(p)
	{
		printf("学号:%d\n姓名:%s\n分数:%d\n",p->id,p->name,p->score);
		p=p->next;
	}
}
int main(void)
{
	linklist ha,hb,hc;
	ha=weicha();
	output(ha);
	hb=weicha();
	output(hb);
	hc=hebing(ha,hb);
	output(hc);
 } 
