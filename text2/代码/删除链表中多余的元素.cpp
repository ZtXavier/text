#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Lnode
{
	ElemType date;
	struct Lnode* next;
}*LNode;
 
LNode InitLnode(void)                 //��ʼ������
{
	LNode L;
	L = (LNode)malloc(sizeof(struct Lnode));
	if(L == NULL)
		exit(1);
	L->next = NULL;    //��������д��������n��
	return L;
}
/*β����Ԫ��*/
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
	while(p->next != NULL)  //��ͷ��������
	{
		p = p->next;
	}
	p->next = q;
}
/*�������*/
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
/*ɾ��ֵ��ͬ�Ķ�����*/
void DeteleTheSame(LNode head)
{
	LNode p,q,t,s;
	p = head;
	p = p->next;          //ͷ�ڵ�δ�������
	while(p!=NULL)
	{
		t = p;                        //tָ�뱣֤ʼ����qָ��ǰһλ
		for(q = p->next;q != NULL;)
		{
			s = q;
			if(p->date == q->date)    //ֵ��ͬ
			{
				t->next = q->next;    //tָ��ָ��qǰһ��Ԫ�أ���ʱt->nextָ��q->next,����q
				q = q->next;          //qָ����һ��Ԫ��
				free(s);              //�ͷŵ�ǰ�������Ԫ�صĵ�ַ
			}
			else                      //ֵ��ͬ
			{
				t = t->next;          //t��qҪͬʱ����һλ
				q = q->next;          //����ֵ��ͬ�����ֻҪ��q���ƣ�t������һλ
			}
		}
		p = p->next;
	}
}
/*����һ��*/
int main(void)
{
	LNode head;
	head = InitLnode();
	//head->date = 4;
	ElemType n;
	printf("������Ҫ���������е����ݣ�����Ϊ���Ǵ����������\n");
	while(scanf("%d",&n)!=EOF)
	{
		if(n == 0)
			break;
		Insert(head,n);
	}
	printf("���������������Ϊ��\n");
	Print(head);
	printf("\n");
	DeteleTheSame(head);
	printf("ɾȥ�ظ�����Ԫ�غ�����Ϊ��\n");
	Print(head);
	printf("\n");
 
	return 0;
}
