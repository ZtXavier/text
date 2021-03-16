#include<stdio.h>                                                                                                                                  //数组
void josephus(int n, int m,int s);

int main(void)
{
	int num, t, s;
	printf("输入总人数：");
	scanf("%d", &num);

	printf("输入间隔人数：");
	scanf("%d", &t);

    printf("输入胜利者的人数：");
    scanf("%d", &s);
    
	josephus(num, t, s);
}

//未出局的人标记为0，出局的人标记为1

void josephus(int n, int m,int s)
{
	int a[200] = { 0 };
	int count = 0;//记录出局的人数 
	int i, j = -1;

	while (count < (n - s))//使n-s个人出局 
	{
		i = 0;//报数每次从1开始 
		while (1) {
		    j = (j + 1) % n;//为了让每转完一圈都能从第一个人开始报数 
			if (a[j] == 0)//判断这个人是否出局 
			{
				i++;//这个人不出局才报数 
			}
			
			if (i == m)//判断报的数是否为m 
			{
				++count;//记录出局的人数 
				a[j] = 1;//给出局的数赋值
				printf("%d号出局\n", j + 1);
				break;//跳到外循环 
			}
		}
	}
	
	for( i = 0; i < n; i++)//数组中为0的数，即为胜利者 
	{
		if (a[i] == 0)
		{
			printf("胜利者：%d号\n", i + 1);
		}
	}
}
