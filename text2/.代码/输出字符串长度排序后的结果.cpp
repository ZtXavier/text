#include <stdio.h>
#include <string.h>
int main(void)
{
    char str[20][10],t[20],str1[10];
    int i,j,n=0;
    while(1)
	{
    	scanf("%s",str1);
    	if(str1[0]=='#')
	    {
    		break;
    	}
        else
		{
        strcpy(str[n],str1);
        n++;
        }
    }
    for(i=0;i<n-1;i++)
    	for(j=0;j<n-i-1;j++)
	    {
            if(strlen(str[j])>strlen(str[j+1]))
		    {
               strcpy(t,str[j]);      //注意在进行交换时的方法为strcpy// 
               strcpy(str[j],str[j+1]);
               strcpy(str[j+1],t);
            }
        }
    for(i=0;i<n;i++)
	{
        printf("%s ",str[i]);
    }
    return 0;
}
