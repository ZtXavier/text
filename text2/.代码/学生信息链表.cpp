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
        printf("������ѧ����ѧ��\n");
        scanf("%d",&id);
        if(id==0)
        break;
        printf("������ѧ��������\n");
        scanf("%s",name);
        printf("������ѧ�����Ա�\n");
        scanf("%s",sex);
        printf("������ѧ��������\n");
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
    printf("ѧ����Ϣ���£�\n");
    while(q)
    {
        printf("ѧ�ţ�%d\n",q->id);
        printf("����:%s\n",q->name);
        printf("�Ա�:%s\n",q->sex);
        printf("����:%d\n\n",q->age);
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
    printf("������Ҫɾ�������䣺\n");
    scanf("%d",&age);
    ha=shanchu(ha,age);
    output(ha);
    return 0;
}
