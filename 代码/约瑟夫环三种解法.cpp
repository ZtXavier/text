#include<stdio.h>                                                                                                                      //����
#include<stdlib.h>  
void Josephus(int n, int m, int k);
int main()
{
    int m, k, n;
    printf("��������������");
    scanf("%d", &n);
    printf("������ӵڼ��˱�����");
    scanf("%d", &k);
    printf("��������������");
    scanf("%d", &m);
    Josephus(n, m, k);
}

typedef struct Node {
    int data;
    struct Node* next;
}LNode, * LinkList;

void Josephus(int n, int m, int k)
{
    LinkList p = NULL, x = NULL, t = NULL;
    int i;
    for (i = 1; i <= n; i++)
    {
        p = (LNode*)malloc(sizeof(LNode));//��ϵͳ�����ڴ�  
        p->data = i;//��n���˱��  
        if (t == NULL)  t = p;//t��ͷ�ڵ� 
            // Ϊͷ�ڵ�Ĳ�����һ�� 
        else  x->next = p;//���������� 
            
        x = p; //ˢ��x��ʹxΪp��ǰ���ڵ� 
    }
    p->next = t;//�������β��ͷ������ 
    p = t;//����һ��ѭ������  
    
    
    for (i = 1; i < k; i++)
    {
        x = p;
        p = p->next;
    }            //��ʱpָ��ڵ�k���ڵ� 
    
    
    while (p->next != p)
    {
        for (i = 1; i < m; i++)
        {
            x = p;
            p = p->next;
        }  //pָ���m����㣬xָ���m-1�����     
		               
        x->next = p->next;              //ɾ����m�����  
        printf("%d�ų���\n", p->data); 
        free(p);   
        p = x->next;                    //pָ���µĳ�����  
    }
    
    printf("ʤ����Ϊ��%d��\n", p->data);
    free(p);
}
