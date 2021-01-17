#include<stdio.h>                                                                                                                            //链式数组
//简化题目，用特殊情况，总人数10，3人一循环，第1人开始
int main(void) {     //为了方便理解，部分注释采用了链表的说辞。
	int a[10] = { 1,2,3,4,5,6,7,8,9,0 };//数组中每个结点中存放下一个结点的位置，如 a[0]= 1
	int i = 0, count = 1,prev=0;    //count用于计数，prev存放上一个结点的位置，i为目前结点的位置
	while (a[i] != i) {    //当一个结点指向自己时表示只剩一个人 
		if (count == 0) a[prev] = a[i];//将第三人出局
		count = (count + 1) % 3;//保证count的值只有0,1,2
		prev = i;//记录当前结点位置
		i = a[i];//让i“指向”下一个结点
	}
	printf("%d\n", i + 1);
	return 0;
}
