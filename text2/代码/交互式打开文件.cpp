#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<string.h>
#include<conio.h>
#define LEN 100
int main(void)
{
FILE *fp;
char filename[40];
int fno,fsize;
printf("请输入要打开文件的完整的路径和文件名:\n");
gets(filename);
fp=fopen(filename,"r");
if(fp==NULL)
{
	printf("\n打开文件失败，%s可能不存在",filename);
	exit(1);
 } 
 fno=fileno(fp);
 fsize=filelength(fno);
 printf("\n%s打开文件成功，文件大小%d Bytes\n",filename,fsize);
 fclose(fp);
 return 0; 
}
