#include<stdio.h>
#include<malloc.h>
struct Node{
	int data;
	Node *next;
};
int createlist(Node **p,int i);
int pop_sort(Node *p);
int main()
{
	int i=0;
	Node *p,*head,*ph;
//	head = (Node*)malloc(sizeof(Node)); //�������ָ����Ҫ���ڴ˷���ռ� 
	createlist(&head,5); 
	ph=head;
	pop_sort(head);
	while(head->next)
	{
	//	printf("... ");
		printf("%d ",head->next->data);
		head=head->next;
	}
	
	free(ph);
	ph=NULL;
	return 0;
}
int createlist(Node **p,int i)    //�˴�ͷָ�뻹û����ռ䣬��Ҫ����ָ���ַ������ѷ���ռ䣬���Դ��� 
{
	Node *pp,*temp;
	int j;
	int k;
	*p=(Node*)malloc(sizeof(Node));
	temp=*p;       //�˴���Ҫ��ʱ��������ֹ����ָ��ֵ���޸� 
	for(j=0;j<i;j++)    //Ҳ�ɲ��õݹ飬�ݹ���� createlist(p->next,i) ���������� 
	{
		pp = (Node*)malloc(sizeof(Node));
		scanf("%d",&k);
		pp->data=(k);
		
		temp->next=pp;
		temp=pp;
	}
 	temp->next= NULL;
	return 0;
}
int pop_sort(Node *head)   //����ð�����򣬽ڵ㽻���������л�ֵ����������ͷ�ڵ�ָ�� 
{							//������û���޸�ͷ�ڵ�ָ��ֵ��ֻ���޸�ָ������head->next��ֵ 
	Node *pre,*p,*tail,*temp;
	tail=NULL;
	pre=head;
	
	while((head->next->next)!=tail)//(head->next)!=tailͬ������ ����ִ�����һ�����Ƚ� 
	{
		p=head->next;
		pre=head;
		while(p->next!=tail)
		{
			if((p->data)>(p->next->data))
			{
			/*	pre->next=p->next; //�����ڵ㷽��һ
				p->next = p->next->next;
                pre->next->next = p;
                p = pre->next; */
                
                pre->next=p->next; //�����ڵ㷽���� 
                temp=p->next->next;
                p->next->next=p;
                p->next=temp;
                p=pre->next;  //p����һ���ڵ� 
                
			}
			p=p->next;  //p��ǰ��һ���ڵ� 
			pre=pre->next;	
		}
		tail=p;
	}
	return 0 ;
}
