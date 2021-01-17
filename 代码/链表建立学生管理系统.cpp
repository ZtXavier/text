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
	  printf("释放完毕！按任意键返回。\n");
	  getch();
}
 	
  void main_deal(student **head)
  {
  	int select=1;
  	while(select)
	{
  		printf("********************\n");
  		printf("**   学生通讯录   **\n");
  		printf("**================**\n");
  		printf("**    1.录入      **\n");
  		printf("**    2.修改      **\n");
  		printf("**    3.删除      **\n");
  		printf("**    4.查询      **\n");
  		printf("**    5.打印      **\n");
  		printf("**    0.退出      **\n");
  		printf("********************\n");
  		printf("请选择：");
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
			printf("选择错误！请重新选择。\n");
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
		printf("目前尚未录入数据！按任意键返回。\n");
		getch();
		return;
	}
	while(p!=NULL)
	{
		printf("   姓名:%s\n",p->name);
		printf("   性别:%s\n",p->sex);
		printf("出生日期:%d.%d.%d\n",
		p->birthday.year,
		p->birthday.month,
		p->birthday.day);
		printf("电话号码:%s\n",p->phone);
		printf("按任意键继续。\n\n");
		getch();
		p=p->next;
	}
 }
 
 int input(STU **head)
 {
 	int sure;
 	STU stu;
 	STU *q,*p;
 	printf("请输入姓名:(为空将返回)\n");
	gets(stu.name);
	gets(stu.name);
	if(strlen(stu.name)==0) return 1;
	printf("性别: ");
	scanf("%s",stu.sex);
	printf("出生日期:");
	scanf("%d.%d.%d",
	&stu.birthday.year,&stu.birthday.month,&stu.birthday.day);
	printf("电话号码:");
	scanf("%s",&stu.phone);
	printf("确认是否保存: 1--保存；2--放弃");
	scanf("%d",&sure);
	if(sure!=1) return 1;
	p=(STU*)malloc(sizeof(STU));
	if(p==NULL)
	{
		printf("申请空间出错！按任意键返回。\n");
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
	 printf("保存完毕！按任意键返回.\n");
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

