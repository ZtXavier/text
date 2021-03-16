#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
//定义结构体 
typedef struct node{
	int data;
	struct node *next;
}Node,*LinkList;

//创建链表 
LinkList CreatByRear(){
	Node *r,*s,*head;
	head=(Node*)malloc(sizeof(Node));
	head->next =NULL;
	head=NULL; 
	int data;
	r=head;
	while(1){
		scanf("%d",&data);
		if(data==0) break;
		s=(Node*)malloc(sizeof(Node));
		s->data=data;
		if(head==NULL){
			head=s;
			r=head;
		}
		else{
			r->next=s;
			r=s;	
		}
	}
	r->next=NULL;
	return head;
}
//打印链表 
void OutPut(LinkList head){
	Node *p;
	p=head->next ;
	p=head;
	while(p){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
LinkList nizhi(LinkList head)
{
	Node *r,*s;
	s=r=head;
	s=s->next;	
    r->next=NULL;
    while(s)
    {
    r=s->next;
    s->next=head;
    head=s;
	s=r;
	} 
	return head;
}
int main(void){
	LinkList ha;
	ha=CreatByRear();
	printf("原链表为；\n");
	OutPut(ha);
	ha=nizhi(ha);
	printf("现链表为；\n"); 
	OutPut(ha);
}
