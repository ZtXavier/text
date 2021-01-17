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
//	head = (Node*)malloc(sizeof(Node)); //如果传入指针需要先在此分配空间 
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
int createlist(Node **p,int i)    //此处头指针还没分配空间，需要传入指针地址；如果已分配空间，可以传入 
{
	Node *pp,*temp;
	int j;
	int k;
	*p=(Node*)malloc(sizeof(Node));
	temp=*p;       //此处需要临时变量，防止传入指针值被修改 
	for(j=0;j<i;j++)    //也可采用递归，递归调用 createlist(p->next,i) 来创建链表 
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
int pop_sort(Node *head)   //链表冒泡排序，节点交换法（还有换值法）；传入头节点指针 
{							//排序中没有修改头节点指针值，只是修改指针内容head->next的值 
	Node *pre,*p,*tail,*temp;
	tail=NULL;
	pre=head;
	
	while((head->next->next)!=tail)//(head->next)!=tail同样适用 ，多执行最后一个步比较 
	{
		p=head->next;
		pre=head;
		while(p->next!=tail)
		{
			if((p->data)>(p->next->data))
			{
			/*	pre->next=p->next; //交换节点方法一
				p->next = p->next->next;
                pre->next->next = p;
                p = pre->next; */
                
                pre->next=p->next; //交换节点方法二 
                temp=p->next->next;
                p->next->next=p;
                p->next=temp;
                p=pre->next;  //p回退一个节点 
                
			}
			p=p->next;  //p再前进一个节点 
			pre=pre->next;	
		}
		tail=p;
	}
	return 0 ;
}
