#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct student
{
    char num[6];
    char name[11];
    int a,b,c;
    
}STU;
int main(void)
{
    int n,i,j,max=0;
    scanf("%d",&n);
    STU stu[n];
    for(i=0;i<n;i++)
    {
        scanf("%s",stu[i].num);
        getchar();
        scanf("%s",stu[i].name);
        getchar();
        scanf("%d %d %d",&stu[i].a,&stu[i].b,&stu[i].c);
    }
    for(i=0;i<n;i++)
    {
        if(max<(stu[i].a+stu[i].b+stu[i].c))
        {
            max=(stu[i].a+stu[i].b+stu[i].c);
            j=i;
        }
    }
    printf("%s %s %d",stu[j].num,stu[j].name,max);
    return 0;
}