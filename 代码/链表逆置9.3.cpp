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
//��ӡ���� 
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
	printf("ԭ����Ϊ��\n");
	OutPut(ha);
	ha=nizhi(ha);
	printf("������Ϊ��\n"); 
	OutPut(ha);
}
