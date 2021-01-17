#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main(void)
{
FILE *fp;
char ch;
fp=fopen("d://c//file.txt","rt");
printf("......\n");
while((ch=fgetc(fp))!=EOF)
         printf("%c",ch);
printf("\n......\n");
if(fp==NULL) 
{
	printf("\n不能打开。");
    putchar(ch);
	exit(1);
 }
 else
 while((ch=fgetc(fp))!=EOF)
        putchar(ch);
        fclose(fp);
        getch();
 return 0;
}
