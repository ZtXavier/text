#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<conio.h>
int main(void)
{
FILE *fp;
char ch;
int fno,fsize;
fp=fopen("d://c//file.txt","rt");
if(fp==NULL)
printf("不能打开文件"); 
while((ch=fgetc(fp))!=EOF)
printf("%c",ch);
printf("\n");
getch();
fno=fileno(fp);
fsize=filelength(fno);
printf("%d %d",fno,fsize);
fclose(fp);
return 0; 
}
