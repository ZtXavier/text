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
	printf("\n\n��%d���˵���Ϣ:\n",++i);
	printf("\n ����:");
	scanf("%s",stu->name);
	printf("\n ѧ��:");
	scanf("%d",&stu->num);
	printf("\n ����:");
	scanf("%d",&stu->age);
	printf("\n סַ:");
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
	printf("\n������Ҫ������ļ���:");
	scanf("%s",filename);
	if((fp=fopen(filename,"w"))==NULL)
	{
		printf("д�ļ�������������˳���");
		getch();
		exit(1); 
	}
	for(stu=h->next;stu!=NULL;stu=stu->next)
	fprintf(fp,"%s %d %d %s\n",stu->name,stu->num,stu->age,stu->addr);
	printf("\n�ļ��Ѿ����棬����������أ�");
	getch();
	fclose(fp); 
}
    struct Node *read_inf()
    {
    	struct Node *head,*r,*stu;
    	FILE *fp;
    	char filename[40];
    	printf("\n������Ҫ�򿪵��ļ�����");
		gets(filename);
		if((fp=fopen(filename,"r"))==NULL)
		{
			printf("���ļ�������������˳�!");
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
		 printf("\n�ļ���Ϣ����ȷ����������������أ�");
		 getch();
		 return head; 
	}
	print_inf(struct Node *h)
	{
		struct Node *stu;
		printf("\n �ð�����Ϊ��\n");
		printf("����	ѧ��	����	סַ\n");
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
