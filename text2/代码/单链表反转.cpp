#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
//����ṹ�� 
typedef struct node{
	int data;
	struct node *next;
}Node,*LinkList;

//�������� 
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
//��ӡ���� 
void OutPut(LinkList head){
	Node *p;
	p=head->next ;
	while(p){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

//�ǵݹ鷨 
/*
LinkList Reverse(LinkList head){
	Node *p,*q;
	p=head->next;         //pָ���һ�����ݽ�� 
	head->next=NULL;      //��ԭ������Ϊ�ձ�
	while(p){
		q=p;
		p=p->next;
		q->next=head->next;
		head->next=q;
	} 
	return head; 
} 
*/

//�ݹ鷨 

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
	printf("ԭ����Ϊ��\n");
	OutPut(ha);
	ha=Reverse(ha);
	printf("������Ϊ��\n"); 
	OutPut(ha);
}
