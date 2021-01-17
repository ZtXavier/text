#include <stdio.h>
int main(void)
{
    int i=0,j=0,m,n;
     scanf("%d,%d",&n,&m);
     int a[n],b[n]; 
    for(i=0;i<n;i++)
	{
    	scanf("%d,",&a[i]);  
    }
    m=m%n;
        for(i=m-1;i>=0;i--)
        {
            b[i]=a[n-j-1];
            j++;
        }
        i=m;
            for(j=0;j<n-m;j++)
        {	
            b[i]=a[j];
            i++;
        }
        
for(i=0;i<n;i++)
{
if(i<n-1)
    printf("%d,",b[i]);
else
printf("%d",b[i]);
}
return 0;
}
