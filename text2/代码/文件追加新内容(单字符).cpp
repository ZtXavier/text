#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#define LEN 100
int main(void)
{
	FILE *fp;
	char filename[LEN],data[LEN]; 
    int fno,fsize,i;
    char ch;
    printf("写文件程序...\n");
    printf("请输入要打开文件的完整路径及文件名\n");
    gets(filename);
    fp=fopen(filename,"a+");
    if(fp==NULL)
    {
    	printf("\n打开文件夹失败.%s可能不存在",filename);
    	exit(1);
	}
	fno=fileno(fp);
	fsize=filelength(fno);
	printf("\n%s 文件打开！\n",filename);
	printf("\n 文件大小 %d Bytes\n",fsize);
	printf("\n 文件内容为:");
	while((ch=fgetc(fp))!=EOF)
	{
		printf("%c",ch);
	} 
	while(1)
	{	
	    printf("\n\n请问是否要添加数据(Y/N):");
		if(toupper(getche())=='Y')
		{
	    printf("\n\n请输入要添加的数据：");  
		gets(data);
		for(i=0;i<strlen(data);i++)
		fputc(data[i],fp);
        }
	else
	{
		fclose(fp);
		break;
	}
    }
    fp=fopen(filename,"rt");
    if(fp==NULL)
    {
    	printf("\n\n打开文件夹失败，%s 可能不存在\n",filename);
    	exit(1);
	}
	fno=fileno(fp);
	fsize=filelength(fno);
	printf("\n\n%s 文件打开!\n",filename);
	printf("\n文件大小 %d Bytes\n",fsize);
	printf("\n文件内容为:");
	while((ch=fgetc(fp))!=EOF)
	printf("%c",ch);
	fclose(fp);
	printf("\n\n"); 
 return 0; 
}
