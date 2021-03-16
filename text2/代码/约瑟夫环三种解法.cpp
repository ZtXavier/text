#include<stdio.h>                                                                                                                      //链表
#include<stdlib.h>  
void Josephus(int n, int m, int k);
int main()
{
    int m, k, n;
    printf("请输入总人数：");
    scanf("%d", &n);
    printf("请输入从第几人报数：");
    scanf("%d", &k);
    printf("请输入间隔人数：");
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
        p = (LNode*)malloc(sizeof(LNode));//向系统申请内存  
        p->data = i;//给n个人编号  
        if (t == NULL)  t = p;//t作头节点 
            // 为头节点的操作不一样 
        else  x->next = p;//将链表串起来 
            
        x = p; //刷新x，使x为p的前驱节点 
    }
    p->next = t;//将链表的尾与头连起来 
    p = t;//建立一个循环链表  
    
    
    for (i = 1; i < k; i++)
    {
        x = p;
        p = p->next;
    }            //此时p指向第第k个节点 
    
    
    while (p->next != p)
    {
        for (i = 1; i < m; i++)
        {
            x = p;
            p = p->next;
        }  //p指向第m个结点，x指向第m-1个结点     
		               
        x->next = p->next;              //删除第m个结点  
        printf("%d号出局\n", p->data); 
        free(p);   
        p = x->next;                    //p指向新的出发点  
    }
    
    printf("胜利者为：%d号\n", p->data);
    free(p);
}
