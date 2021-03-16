#include<stdio.h>
#include<stdlib.h>
//int n=0;
typedef struct date
{
	int num;
	struct date *next;
}Da,*linklist;

linklist initlist()
{
	Da *head;
	head=(Da*)malloc(sizeof(Da));
	head->next=NULL;
	return head; 
 } 
linklist toucha(linklist head)
{
	Da *p;
	int num;
	printf("请输入序号:\n");
	while(1)
	{ 
	  scanf("%d",&num);
	  if(num<0)
	  break;
      p=(Da*)malloc(sizeof(Da));
	  p->num=num;
	  p->next=head->next;
	  head->next=p;	
    }
    return head;
}
linklist weicha(linklist head)
{
	Da *p,*q;
	p=head;
	int num;
	printf("\n请输入序号:\n");
	while(1)
	{
		scanf("%d",&num);
		if(num<0)
		break;
		q=(Da*)malloc(sizeof(Da));
		q->num=num;
		p->next=q;
		p=q;
	}
	q->next=NULL;
	return head;
}

int length(linklist head)
{
	int n=0;
	Da *r=head->next;
	while(r)
	{
		r=r->next;
		n++;
	}
	return n;
}
linklist paixu(int n,linklist head)
{
	int loop=1;
    Da stu[n];
    Da stu1;
    Da *s=head->next;
    while(loop<n+1)
    {
    	stu[loop].num=s->num;
    	s=s->next;
    	loop++;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n-i+1;j++)
		{
			if(stu[j].num>stu[j+1].num)
			{
			    stu1.num=stu[j].num;
				stu[j].num=stu[j+1].num;
				stu[j+1].num=stu1.num;	
			}
		}
	}
	s=head->next;
	loop=1;
	while(loop<n+1)
    {
    	s->num=stu[loop].num;
    	s=s->next;
    	loop++;
	}
	return head;	
}

void putout(linklist head)
{
	Da *p;
	p=head->next;
	while(p)
	{
	printf("%d",p->num);
	p=p->next;
    }
}
int main(void)
{
	int n,m;
    linklist s1,s2;
	s1=initlist();
	s2=initlist();
	s1=toucha(s1);
	printf("s1的链表如下：");
	putout(s1);
	//s2=weicha(s2);
	//printf("s2的链表如下：");
	//putout(s2);
	n=length(s1);
	//m=length(s2);
	if(n==0)
	printf("s1无数据\n");
	else{
	s1=paixu(n,s1);
	printf("\n排序结果为：\n");
	putout(s1);
    }
//	if(m==0)
//	printf("s2无数据\n");
//	else{
//	s2=paixu(m,s2);
//	printf("\n排序结果为：\n");
//	putout(s2);
//    }
	return 0;
}
