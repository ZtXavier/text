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
linklist nizhi(linklist head)
{
	if(head->next==NULL)
	return head;
	STU *newhead=nizhi(head->next);
	head->next->next=head;
	head->next=NULL;
	return newhead;
}
void output(linklist head)
{
	STU *p;
	p=head;
	while(p)
	{
		printf("%d\n",p->num);
		p=p->next;
	}
}
int main(void)
{
	STU *p;
	p=created();
	output(p);
	printf("ÄæÖÃ½á¹ûÎª£º\n");
	p=nizhi(p);
	output(p);
	return 0;
}
