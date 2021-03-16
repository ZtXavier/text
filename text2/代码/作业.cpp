#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
typedef struct student
{
    char name[11];
    int birthday;
    char phonenumber[20];
}STU;
int main(void)
{
    int n,i,j,k,temp;
    scanf("%d",&n);
    //getchar();
    STU stu[n];
    for(i=0;i<n;i++)
    {
    gets(stu[i].name);
    scanf("%d",&stu[i].birthday);
    gets(stu[i].phonenumber);
    //getchar();
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            k=j;
        if(stu[k].birthday<stu[k+1].birthday)
        {
          temp=k;
          k=k+1;
          temp=k+1;
        }
        }
    }
   for(i=0;i<n;i++)
       printf("%s %d %s\n",stu[i].name,stu[i].birthday,stu[i].phonenumber);
    return 0;
}
