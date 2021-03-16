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
		printf("不能打开文件 string1!\n");
		exit(1);
	}
	printf("\n 读取到文件 string1!的内存为:\n");
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
		printf("不能打开文件 string2！\n");
		exit(1);
	}
    printf("\n读取到文件 string2 的内容为：\n");
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
	printf("\n排序后的数组string的内容为:\n");
	printf("%s\n",string);
	fp=fopen("D:\\C\\string.txt","wt");
	fputs(string,fp);
	printf("并已将该内容写入文件string.txt中！");
	fclose(fp);    //写入必须的步骤// 
    return 0; 
}
