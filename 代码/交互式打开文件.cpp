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
printf("������Ҫ���ļ���������·�����ļ���:\n");
gets(filename);
fp=fopen(filename,"r");
if(fp==NULL)
{
	printf("\n���ļ�ʧ�ܣ�%s���ܲ�����",filename);
	exit(1);
 } 
 fno=fileno(fp);
 fsize=filelength(fno);
 printf("\n%s���ļ��ɹ����ļ���С%d Bytes\n",filename,fsize);
 fclose(fp);
 return 0; 
}
