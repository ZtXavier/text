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
//	head=(Node*)malloc(sizeof(Node));
//	head->next =NULL;
	head=NULL; 
	int data;
//	r=head;
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
//	p=head->next ;
	p=head;
	while(p){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

//��ͷ���
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

// ��ͷ���
 LinkList Reverse(LinkList head){
 	LinkList p1=head;
 	LinkList p2=head->next;
 	LinkList p3=NULL;
 	while(p2!=NULL){
 		p3=p2->next;
 		p2->next=p1;
 		p1=p2;
 		p2=p3;
	 }
	 head->next=NULL;
	 head=p1;
	 return head;
 }

//�ݹ鷨 
/*
LinkList Reverse(LinkList head){
	if(head->next==NULL){
		return head; 
	}
	Node *newhead=Reverse(head->next);
	head->next->next=head;
	head->next=NULL;
	return newhead;
} 
*/ 
public Node reverseLinkedList(Node head,Node q)//��һ�ε���ʱ�ѣ�null��head������

{
   if(q == null)

     return head;

  else

      {
          Node p = q;

          q=q.next;

          p.next = head;

          head = p;

          head = reverseLinkedList(head,q);

      }

      return head;

}
Node *create(){
	int input=0;
	scanf("%d",&input);
	if (input!=-1)
	{
		Node *node=new Node();
		node->v=input;
		node->nxt=create();
		return node;
	}
	return NULL;
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
