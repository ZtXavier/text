#include <stdio.h>
void tobin(int n);
int main(void)
{
    int n;
    scanf("%d",&n);
    printf("%d",n);
    return 0;
}
void tobin(int n)
{
    int b;   
    b = n%2;
    if(n<2)
    {
        printf("%d",b);
    }
    else
    {
        n = n/2;
        tobin(n);
        printf("%d",b);
    }
        
}
