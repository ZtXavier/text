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
       
linklist lianbiaoxiangjia(linklist head1,linklist head2)
{
    STU *p1,*p2;
    p1=head1;
    p2=head2;
    int n=0;
    STU *head=(STU*)malloc(sizeof(STU));
    STU *pre=head;
    while(p1||p2||n)
    {
        STU *newline;
        newline=(STU*)malloc(sizeof(STU));
        newline->next=NULL;
        pre->next=newline;
        pre=newline;
        if(p1&&p2)
        {
            int sum=p1->num+p2->num+n;
            newline->num=sum%10;
            n=sum/10;
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1 && p2==NULL){
            int sum=p1->num+n;
            newline->num=sum%10;
            n=sum/10;
            p1=p1->next;
        }else if(p1==NULL && p2){
            int sum=p2->num+n;
            newline->num=sum%10;
            n=sum/10;
            p2=p2->next;
        }else{
            newline->num=n;
            n=0;
        }
        
    }
    return head->next; 
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
// int lianbiaolength(linklist head)
// {
//     int cnt=0;
//     STU *p;
//     p=head->next;
//     while(p)
//     {
//         ++cnt;
//         p=p->next;
//     }
//     return cnt;
// }
int main(void)
{
    linklist ha,hb,hc;
    ha=initlist();
    ha=weicha(ha);
    hb=initlist();
    hb=weicha(hb);
    hc=lianbiaoxiangjia(ha,hb);
    output(hc);
    return 0;
}