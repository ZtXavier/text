#include<stdio.h>                                                                                                                                  //����
void josephus(int n, int m,int s);

int main(void)
{
	int num, t, s;
	printf("������������");
	scanf("%d", &num);

	printf("������������");
	scanf("%d", &t);

    printf("����ʤ���ߵ�������");
    scanf("%d", &s);
    
	josephus(num, t, s);
}

//δ���ֵ��˱��Ϊ0�����ֵ��˱��Ϊ1

void josephus(int n, int m,int s)
{
	int a[200] = { 0 };
	int count = 0;//��¼���ֵ����� 
	int i, j = -1;

	while (count < (n - s))//ʹn-s���˳��� 
	{
		i = 0;//����ÿ�δ�1��ʼ 
		while (1) {
		    j = (j + 1) % n;//Ϊ����ÿת��һȦ���ܴӵ�һ���˿�ʼ���� 
			if (a[j] == 0)//�ж�������Ƿ���� 
			{
				i++;//����˲����ֲű��� 
			}
			
			if (i == m)//�жϱ������Ƿ�Ϊm 
			{
				++count;//��¼���ֵ����� 
				a[j] = 1;//�����ֵ�����ֵ
				printf("%d�ų���\n", j + 1);
				break;//������ѭ�� 
			}
		}
	}
	
	for( i = 0; i < n; i++)//������Ϊ0��������Ϊʤ���� 
	{
		if (a[i] == 0)
		{
			printf("ʤ���ߣ�%d��\n", i + 1);
		}
	}
}
