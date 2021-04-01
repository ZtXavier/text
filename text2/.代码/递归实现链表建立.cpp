#include<stdio.h>
#include<stdlib.h>
#include<malloc.h> 
typedef struct student
{
	int num;
	struct student *next; 
}STU,*linklist;
linklist created()
{
	STU *p;
	int num;
	scanf("%d",&num);
	if(num>=0)
	{
		p=(STU*)malloc(sizeof(STU));
		p->num=num;
		p->next=created();
		return p;
	 } 
	 return NULL;
}
void output(linklist head)
{
	STU *p;
	p=head;
	printf("链表结果为：\n");
	while(p)
	{
		printf("%d\n",p->num);
		p=p->next;
	}
}
int main(void)
{
	STU *p;
	printf("请输入数字：\n");
	p=created();
	output(p);
	return 0;
	
 } 
