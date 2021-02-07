#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h> 
typedef struct Date
{
	int year;
	int month;
	int day;
}date;
typedef struct student
{
	char name[9];
	char sex[3];
	date birthday;
	char phone[12];
	struct student *next;
 }STU;
 
 void free_linklist(STU *head);
void main_deal(student **head);
void display(STU *head);
int input(STU **head);

 void free_linklist(STU *head)
 {
 	STU *q,*p;
 	q=head;
 	while(q!=NULL)
	 {
	 	p=q;
	 	q=q->next;
	 	free(p);
	  } 
	  printf("�ͷ���ϣ�����������ء�\n");
	  getch();
}
 	
  void main_deal(student **head)
  {
  	int select=1;
  	while(select)
	{
  		printf("********************\n");
  		printf("**   ѧ��ͨѶ¼   **\n");
  		printf("**================**\n");
  		printf("**    1.¼��      **\n");
  		printf("**    2.�޸�      **\n");
  		printf("**    3.ɾ��      **\n");
  		printf("**    4.��ѯ      **\n");
  		printf("**    5.��ӡ      **\n");
  		printf("**    0.�˳�      **\n");
  		printf("********************\n");
  		printf("��ѡ��");
		scanf("%d",&select);
		switch(select)
		{
			case 1:input(head);
			break; 
			case 2:
			break;
			case 3:
			break;
			case 4:
			break;
			case 5:display(*head);
			break;
			case 0:
			break;
			defualt:
			printf("ѡ�����������ѡ��\n");
			getch();
			break;
		}	
	} 
  }
   
void display(STU *head)
{
	STU *p;
	p=head;
	if(p==NULL)
	{
		printf("Ŀǰ��δ¼�����ݣ�����������ء�\n");
		getch();
		return;
	}
	while(p!=NULL)
	{
		printf("   ����:%s\n",p->name);
		printf("   �Ա�:%s\n",p->sex);
		printf("��������:%d.%d.%d\n",
		p->birthday.year,
		p->birthday.month,
		p->birthday.day);
		printf("�绰����:%s\n",p->phone);
		printf("�������������\n\n");
		getch();
		p=p->next;
	}
 }
 
 int input(STU **head)
 {
 	int sure;
 	STU stu;
 	STU *q,*p;
 	printf("����������:(Ϊ�ս�����)\n");
	gets(stu.name);
	gets(stu.name);
	if(strlen(stu.name)==0) return 1;
	printf("�Ա�: ");
	scanf("%s",stu.sex);
	printf("��������:");
	scanf("%d.%d.%d",
	&stu.birthday.year,&stu.birthday.month,&stu.birthday.day);
	printf("�绰����:");
	scanf("%s",&stu.phone);
	printf("ȷ���Ƿ񱣴�: 1--���棻2--����");
	scanf("%d",&sure);
	if(sure!=1) return 1;
	p=(STU*)malloc(sizeof(STU));
	if(p==NULL)
	{
		printf("����ռ����������������ء�\n");
		getch();
		return -1;
	}
	strcpy(p->name,stu.name);
	strcpy(p->sex,stu.sex);
	strcpy(p->phone,stu.phone);
	p->birthday=stu.birthday;
	p->next=NULL;
	q=*head;
	if(q==NULL) *head=p;
	else
	{
		while(q->next!=NULL)q=q->next;
		q->next=p;
	}
	 printf("������ϣ������������.\n");
	 getch();
	 return 1;
  } 
int main(void)
{
	STU *head=NULL;
	main_deal(&head);
	free_linklist(head);
	head=NULL;
}