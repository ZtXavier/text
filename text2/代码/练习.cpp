#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
struct Node
{
	char name[10];
	int num;
	int age;
	char addr[15];
	struct Node *next;
};
struct Node*creat_inf()
{
    struct Node *head,*r,*stu;
    int i=0;
    char choice;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->next=NULL;
    r=head;
    do
{
	stu=(struct Node*)malloc(sizeof(struct Node));
	printf("\n\n第%d个人的信息:\n",++i);
	printf("\n 姓名:");
	scanf("%s",stu->name);
	printf("\n 学号:");
	scanf("%d",&stu->num);
	printf("\n 年龄:");
	scanf("%d",&stu->age);
	printf("\n 住址:");
	scanf("%s",stu->addr);
	r->next=stu;
	r-stu;
	printf("continue?(Y/N)");
	choice=getche();
}
	while(choice=='Y'||choice=='y');
	r->next==NULL;
	return (head);
}
save_inf(struct Node *h)
{
	struct Node *stu;
	FILE *fp;
	char filename[40];
	printf("\n请输入要保存的文件名:");
	scanf("%s",filename);
	if((fp=fopen(filename,"w"))==NULL)
	{
		printf("写文件出错，按任意键退出！");
		getch();
		exit(1); 
	}
	for(stu=h->next;stu!=NULL;stu=stu->next)
	fprintf(fp,"%s %d %d %s\n",stu->name,stu->num,stu->age,stu->addr);
	printf("\n文件已经保存，按任意键返回！");
	getch();
	fclose(fp); 
}
    struct Node *read_inf()
    {
    	struct Node *head,*r,*stu;
    	FILE *fp;
    	char filename[40];
    	printf("\n请输入要打开的文件名：");
		gets(filename);
		if((fp=fopen(filename,"r"))==NULL)
		{
			printf("读文件出错，按任意键退出!");
			getch();
			exit(1); 
		}
		head=(struct Node *)malloc(sizeof(struct Node));
		head->next=NULL;
		r=head;
		while(!feof(fp))
		{
			stu=(struct Node*)malloc(sizeof(struct Node));
			fscanf(fp,"%s %d %d %s",stu->name,&stu->num,&stu->age,stu->addr);
			r->next=stu;
			r=stu;
		 } 
		 r->next=NULL;
		 fclose(fp);
		 printf("\n文件信息已正确读出，按任意键返回！");
		 getch();
		 return head; 
	}
	print_inf(struct Node *h)
	{
		struct Node *stu;
		printf("\n 该班数据为：\n");
		printf("姓名	学号	年龄	住址\n");
		for(stu=h->next;stu->next!=NULL;stu=stu->next)
		printf("%s	%d	%d	%s\n",stu->name,stu->num,stu->age,stu->addr);
	}
int main(void)
{
    struct Node *head;
    head=creat_inf();
    save_inf(head);
    head=read_inf();
    print_inf(head);
}
