#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Lnode
{
	ElemType date;
	struct Lnode* next;
}*LNode;
 
LNode InitLnode(void)                 //初始化链表
{
	LNode L;
	L = (LNode)malloc(sizeof(struct Lnode));
	if(L == NULL)
		exit(1);
	L->next = NULL;    //就是忘了写它，出错n次
	return L;
}
/*尾插入元素*/
void Insert(LNode head,ElemType x)
{
	struct Lnode *p,*q;
	p = head;
	q = (LNode)malloc(sizeof(struct Lnode));
	if(!q)
	{
		printf("Out of space\n");
		exit(1);
	}
	q->date = x;
	q->next = NULL;
	while(p->next != NULL)  //带头结点的链表
	{
		p = p->next;
	}
	p->next = q;
}
/*输出链表*/
void Print(LNode head)
{
	LNode p;
	p = head->next;
	while(p!=NULL)
	{
		printf("%d ",p->date);
		p = p->next;
	}
}
/*删除值相同的多余结点*/
void DeteleTheSame(LNode head)
{
	LNode p,q,t,s;
	p = head;
	p = p->next;          //头节点未存放数据
	while(p!=NULL)
	{
		t = p;                        //t指针保证始终在q指针前一位
		for(q = p->next;q != NULL;)
		{
			s = q;
			if(p->date == q->date)    //值相同
			{
				t->next = q->next;    //t指针指向q前一个元素，这时t->next指向q->next,跳过q
				q = q->next;          //q指向下一个元素
				free(s);              //释放当前这个多余元素的地址
			}
			else                      //值不同
			{
				t = t->next;          //t和q要同时后移一位
				q = q->next;          //上面值相同的情况只要求q后移，t不后移一位
			}
		}
		p = p->next;
	}
}
/*测试一下*/
int main(void)
{
	LNode head;
	head = InitLnode();
	//head->date = 4;
	ElemType n;
	printf("输入你要放入链表中的数据，输入为零是代表输入结束\n");
	while(scanf("%d",&n)!=EOF)
	{
		if(n == 0)
			break;
		Insert(head,n);
	}
	printf("现在链表里的数据为：\n");
	Print(head);
	printf("\n");
	DeteleTheSame(head);
	printf("删去重复多于元素后链表为：\n");
	Print(head);
	printf("\n");
 
	return 0;
}
