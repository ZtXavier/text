#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
    int id;
	char name[20];
	char sex[3];
	int score[4];
	float ave;	
}STU;
void input(STU st[],int n)
{
	int i,j;
	printf("\t-------------------------------------------\n");
	printf("\t           ******请输入学生信息******      \n");
	printf("\t-------------------------------------------\n");
	printf("学号\t姓名\t性别\t英语\t高数\t计导\tC语言\t");
	printf("----------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&st[i].id);
		scanf("%s",st[i].name);
		scanf("%s",st[i].sex);
		for(j=0;j<4;j++)
		{
		   scanf("%d",&st[i].score[j]);
		}
	}
}
void Aver(STU st[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		int s=0;
		for(j=0;j<4;j++)
		s+=st[i].score[j];
		st[i].ave=s/4.0; 
	}
}
void sort(STU st[],int n)
{
	int i,j,k;
	STU t;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(st[k].ave<st[j].ave)
			k=j;
		}
		if(k!=i)
		{
			t=st[k];
			st[k]=st[i];
			st[i]=t;
		}
	}
}
void output(STU st[],int n)
{
	int i,j;
	printf("\n    	******学生信息如下******      \n");
	printf("学号\t姓名\t英语\t高数\t计导\tC语言\t平均分\t");
	printf("---------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%s\t",st[i].id,st[i].name);
		for(j=0;j<4;j++)
		printf("%d\t",st[i].score[j]);
		printf("%.2f\n",st[i].ave);
	 } 
}
int main(void)
{
	int n;
	printf("请输入学生总人数:\n");
	scanf("%d",&n);
	STU st[n];
	input(st,n);
	Aver(st,n);
	sort(st,n);
	output(st,n);
	return 0;
 } 
