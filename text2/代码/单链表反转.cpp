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
	int data;
	r=head;
	while(1){
		scanf("%d",&data);
		if(data==0) break;
		s=(Node*)malloc(sizeof(Node));
		s->data=data;
		r->next=s;
		r=s;
	}
	r->next=NULL;
	return head;
}
//打印链表 
void OutPut(LinkList head){
	Node *p;
	p=head->next ;
	while(p){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

//非递归法 
/*
LinkList Reverse(LinkList head){
	Node *p,*q;
	p=head->next;         //p指向第一个数据结点 
	head->next=NULL;      //将原链表置为空表
	while(p){
		q=p;
		p=p->next;
		q->next=head->next;
		head->next=q;
	} 
	return head; 
} 
*/

//递归法 

LinkList Reverse(LinkList head){
	if(head->next==NULL){
		return head; 
	}
	Node *newhead=Reverse(head->next);
	head->next->next=head;
	head->next=NULL;
	return newhead;
} 
 
 
int main(){
	LinkList ha;
	ha=CreatByRear();
	printf("原链表为；\n");
	OutPut(ha);
	ha=Reverse(ha);
	printf("现链表为；\n"); 
	OutPut(ha);
}
