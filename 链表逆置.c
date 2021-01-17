#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
    int n;
    struct student *next;
}STU,*linklist;
linklist initlist()
{
    STU *head;
    head=(STU*)malloc(sizeof(STU));
    head->next=NULL;
    return head;
}
linklist createbyreal(linklist head)
{
    STU *s,*r;
    int n;
    r=head;
    while(1)
    {
        scanf("%d",&n);
        if(n<0)
        break;
        s=(STU*)malloc(sizeof(STU));
        s->n=n;
        s->next=r->next;
        r->next=s;
        r=s;
    }
    return head;
}
linklist createbyhead(linklist head)
{
    STU *p;
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n<0)
        break;
        p=(STU*)malloc(sizeof(STU));
        p->n=n;
        p->next=head->next;
        head->next=p;
    }
    return head;
}
linklist nizhi(linklist head)
{
    STU *p,*q;
    p=head->next;
    head->next=NULL;
    while(p)
    {
        q=p->next;
        p->next=head->next;
        head->next=p;
        p=q;
    }
    return head;
}
linklist tobetogether(linklist head1,linklist head2)
{
    STU *p,*q,*r,*newhead;
    p=head1->next;
    q=head2->next;
    newhead=r=head1;
    while(p&&q)
    {
        if((q->n)<=(p->n))
        {
             r->next=q;
             r=q;
             q=q->next;
        }
        else
        {
             r->next=p;
             r=p;
             p=p->next;
        }
    }
        if(p) r->next=p;
        if(q) r->next=q;
    free(head2);
    return newhead;
}
void output(linklist head)
{
    STU *p;
    p=head->next;
    while(p)
    {
        printf("--%d",p->n);
        p=p->next;
    }
    printf("\n");
}
int main(void)
{
    linklist stu1,stu2;
    stu1=initlist();
    stu1=createbyreal(stu1);
    output(stu1);
    stu2=nizhi(stu1);
    output(stu2);
    return 0;
     
}