#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	FILE *fp;
	int i,j,count,count1;
	char string[160]="",t,ch;
	fp=fopen("d:\\L\\string1.txt","rt");
	if(fp==NULL)
	{
		printf("���ܴ��ļ� string1!\n");
		exit(1);
	}
	printf("\n ��ȡ���ļ� string1!���ڴ�Ϊ:\n");
	for(i=0;((ch=fgetc(fp))!=EOF);i++)
	{
		string[i]=ch;
		putchar(string[i]);
	}
	fclose(fp);
	count1=i;
	fp=fopen("D:\\M\\string2.txt","rt");
	if(fp==NULL)
	{
		printf("���ܴ��ļ� string2��\n");
		exit(1);
	}
    printf("\n��ȡ���ļ� string2 ������Ϊ��\n");
    for(i=count1;(ch=fgetc(fp))!=EOF;i++)
    {
    	string[i]=ch;
    	putchar(string[i]);
	}
	fclose(fp);
	count1=i;
	for(i=0;i<count;i++)
	for(j=i+1;j<count;j++)
	if(string[i]>string[j])
	{
		t=string[i];
		string[i]=string[j];
		string[j]=t;
	}
	printf("\n����������string������Ϊ:\n");
	printf("%s\n",string);
	fp=fopen("D:\\C\\string.txt","wt");
	fputs(string,fp);
	printf("���ѽ�������д���ļ�string.txt�У�");
	fclose(fp);    //д�����Ĳ���// 
    return 0; 
}
