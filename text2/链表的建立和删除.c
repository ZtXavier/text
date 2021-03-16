#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
    int id;
    char name[20];
    char sex[3];
    int age;
    struct student*next; 
}STU,*linklist;
linklist weicha()
{
    linklist head=NULL;
    STU *r,*s;
    int id;
    char name[20];
    char sex[3];
    int age;
    while(1)
    {    
        printf("请输入学生的学号\n");
        scanf("%d",&id);
        if(id==0)
        break;
        printf("请输入学生的姓名\n");
        scanf("%s",name);
        printf("请输入学生的性别\n");
        scanf("%s",sex);
        printf("请输入学生的年龄\n");
        scanf("%d",&age);
        s=(STU*)malloc(sizeof(STU));
        strcpy(s->name,name);
        strcpy(s->sex,sex);
        s->id=id;
        s->age=age;
        s->next=NULL;
        if(head==NULL)
        {
            head=s;
            r=head;
        }
        else
        {
            r->next=s;
            r=s;
        }
    }
    return head;
}
void output(linklist head)
{
    STU *q;
    q=head;
    printf("学生信息如下：\n");
    while(q)
    {
        printf("学号：%d\n",q->id);
        printf("姓名:%s\n",q->name);
        printf("性别:%s\n",q->sex);
        printf("年龄:%d\n\n",q->age);
        q=q->next;
    }
}
linklist shanchu(linklist head,int age)
{
    STU *q,*m;
    q=head;
    m=head;
    while(q)
    {
        if(q->age==age)
        {
            if(q==head)
            {
                head=q->next;
            }
            else
            {
                m->next=q->next;
            }
            free(q);
            break;
        }
        m=q;
        q=q->next;
    }
    return head;
}
int main(void)
{
    linklist ha;
    int age;
    ha=weicha();
    output(ha);
    printf("请输入要删除的年龄：\n");
    scanf("%d",&age);
    ha=shanchu(ha,age);
    output(ha);
    return 0;
}