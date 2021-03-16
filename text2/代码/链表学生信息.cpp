#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*typedef struct Poetry
{
	int id;
	char name[20];
	char dynasty[10];
	char author[20];
	char content[200];
	float score;
	struct Poetry*next;
 }poetry,*linklist;*/
 typedef struct student
{
	int number;
	char name[20];
	struct student*next;
 }Node,*linklist;
linklist initlist () 
{
	linklist head;
	head=(Node*)malloc(sizeof(Node));
	head->next=NULL;
	return head;
}
void weicha(linklist head)
{
	Node *r,*s;
	char name[20];
	int number;
	r=head;
	printf("请输入学生的姓名和学号\n");
	while(1)
	{
		scanf("%s",name);
		scanf("%d",&number);
		if(number==0)
		break;
		s=(Node*)malloc(sizeof(Node));
		strcpy(s->name,name);
		s->number=number;
		r->next=s;
		r=s;
	 } 
	 r->next=NULL;
}
void toucha(linklist head)
{
	Node *s;
	char name[20];
	int number;
	printf("请输入学生的学号和姓名\n");
	while(1)
	{
		scanf("%s",name);
		scanf("%d",&number);
		if(number==0)
		break;
		s=(Node*)malloc(sizeof(Node));
		strcpy(s->name,name);
		s->number=number;
		s->next=head->next;
		head->next=s;
	}
}
void output(linklist head)
{
	Node*p;
	p=head->next;
	printf("\n***********学生信息如下**********\n");
	while(p)
	{
		printf("姓名：%s\n",p->name);
		printf("学号：%d\n\n",p->number);
		p=p->next;
	 } 
}
int main(void)
 {
 	linklist ha,hb;
 	ha=initlist();
 	weicha(ha);
 	output(ha);
 	hb=initlist();
 	toucha(hb);
 	output(hb);
 	return 0;
 }
