#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct student
{
    int num;
    struct student*next; 
}STU,*linklist;
linklist initlist()
{
    linklist head;
    head=(STU*)malloc(sizeof(STU));
    head->next=NULL;
    return head;
}
linklist weicha(linklist head)
{
    STU *r,*s;
    int num;
    r=head;
    printf("请输入数字\n");
    while(1) 
    {
       scanf("%d",&num);
       if(num<0)
       break;
       s=(STU*)malloc(sizeof(STU));
       s->num=num;
       r->next=s;
       r=s;
    }
     s->next=NULL;
     return head;       
 }
 int length(linklist head)
 {
     STU *p;
     int cnt=0;
     p=head->next;
     while(p)
     {
        cnt++;
        p=p->next;
     }
     return cnt;

 }
 
linklist deletetheN(linklist head, int n) {
    if(n==0)
    {
        return head;
    }
    linklist fastp=NULL,slowp=NULL,slowq=NULL;
    for(fastp=head;n>0;fastp=fastp->next,n--);
    slowp=head;
    while(fastp){
        slowq=slowp;
        slowp=slowp->next;
        fastp=fastp->next;
    }
    if(slowp==head){
        head=head->next;
    }else{
         slowq->next=slowp->next;  
          free(slowp);
    }
    return head;
}
void output(linklist head)
{
	STU *r;
	r=head->next;
	while(r)
	{	
		printf("%d ",r->num);
		r=r->next;
    }
    printf("\n");
}
int main(void)
{
    STU *stu1,*stu2;
    int n;
    stu1=initlist();
    stu1=weicha(stu1);
    printf("请输入你要删除倒数第n个节点");
    scanf("%d",&n);
    stu1=deletetheN(stu1,n);
    output(stu1);
    return 0;
}