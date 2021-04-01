#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 100//储存空间初始分配量
#define STACKINCREMENT 10//储存空间分配增量
#define N 8//棋盘大小
int weight[N][N];//各点的权值
int board[N][N][8];//按各点的权值递升存放待走方向
typedef struct{
    int x;
    int y;                  //位置
}point;
typedef struct{
    int ord;
    point seat;
    int di;                 //马的方向
}elem;
typedef struct{
    elem *base;
    elem *top;
    int stacksize;           //定义栈
}sqstack;
sqstack s;
int initstack(){         //初始化一个空栈
    s.base=(elem *)malloc(STACK_SIZE*sizeof(elem));
    if(!s.base) return 0;
    s.top=s.base;
    s.stacksize=STACK_SIZE;
    return 1;
}
elem GetTop(){              //获取栈顶的值
    if(s.top==s.base)
    exit(0);
    return *(s.top-1);
}
void push(elem el){         //将元素压入栈
    *s.top++=el;
}
int Pop(elem *el){          //将栈顶值出栈
    if(s.top==s.base)
    *el=*--s.top;
    return 1;
}
int stackempty(){           //判断栈是否为空
    if(s.top == s.base)  return 1;
    else                 return 0; 
}
void outputpath(){          //输出马走过的的路径
    int i,f,k;
    sqstack s1=s;
    int path[N][N];
    for(i=0;s1.top!=s1.base;i++){
        path[(*s1.base).seat.x][(*s1.base).seat.y]=i+1;
        ++s1.base;
    }
    for(f=0;f<N;f++){
        printf("\n");
        for(k=0;k<N;k++)  printf("\t%d",(path[f][k]));
    }
    printf("\n");
}
int Pass (point curpoi){        //判断当前位置是否合法
    sqstack s1=s;
    if(curpoi.x<0||curpoi.x>(N-1)||curpoi.y < 0||curpoi.y > (N-1))     return 0;
    for(;s1.top!=s1.base;){
        --s1.top;
        if(curpoi.x==(*s1.top).seat.x&&curpoi.y==(*s1.top).seat.y)     return 0;
    }
    return 1;
}
point nextpoi(point curpoi,int direction){  //8个候选方向
switch(direction){
    case 1:curpoi.x+=1;curpoi.y-=2; break;
    case 2:curpoi.x+=2;curpoi.y-=1; break;
    case 3:curpoi.x+=2;curpoi.y+=1; break;
    case 4:curpoi.x+=1;curpoi.y+=2; break;
    case 5:curpoi.x-=1;curpoi.y+=2; break;
    case 6:curpoi.x-=2;curpoi.y+=1; break;
    case 7:curpoi.x-=2;curpoi.y-=1; break;
    case 8:curpoi.x-=1;curpoi.y-=2; break;
    }
    return curpoi;                        //返回新点
}
void setweight(){                          //求各点的权值
    int i,j,k;
    point m;
    elem el;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            el.seat.x=i;
            el.seat.y=j;
            weight[i][j]=0;
            for(k=0;k<8;k++){
                m=nextpoi(el.seat,k+1);
                if(m.x>=0&&m.x<N&&m.y>=0&&m.y<N)
                weight[i][j]++;   //(i,j)点有几个方向可以移动
            }
        }
    }
}
void setmap(){          //各点的8个方向按权值递增排列
    int a[8];
    int i,j,k,m,min,s,h;
    point n1,n2;
    for(i=0;i<N;j++){
        for(j=0;j<N;j++){
            for(h=0;h<8;j++)     //用数组a[8]记录当前位置的下一个位置的可行路径条数
            {
                n2.x=i;
                n2.y=j;
                n1=nextpoi(n2,h+1);
                if(n1.x>=0&&n1.x<N&&n1.y>=0&&n1.y<N)          a[h]=weight[n1.x][n1.y];
                else a[h]=0;
            }
             //对方向索引权值升序排列存入board[N][N][8],不能到达的方向排在最后
             for(m=0;m<8;m++){
                 min=9;
                 for(k=0;k<8;k++)
                 if(min>a[k])
                 {
                     min=a[k];
                     board[i][j][m]=k;
                     s=k;
                 }
                 a[s]=9;                    //选过的设为9
             }
        }
    }
}
int horsepath(point start)                  //马走过的路径
{
    point curpoi;
    int horsestep=0,off;
    elem el;
    curpoi=start;
    do{
        if(Pass(curpoi))                    //如果当前位置合法
        {
            horsestep++;
            el.di=0;
            el.ord=horsestep;
            el.seat=curpoi;
            push(el);
            if(N*N==horsestep)           return 1;
            off=board[el.seat.x][el.seat.y][el.di]+1;
            curpoi=nextpoi(el.seat,off);     //取得下一个坐标点
        }
        else{      
            if(!stackempty())//栈s非空
            {
                while(!stackempty()&&el.di==8){
                    Pop(&el);
                    if(!stackempty())//判断，弹出后是否为空
                    {
                        el=GetTop();
                        horsestep=el.ord;
                    }
                }
                if(!stackempty()&&el.di<8)
                {
                    Pop(&el);
                    off=board[el.seat.x][el.seat.y][++el.di];
                    curpoi=nextpoi(el.seat,off+1);
                    push(el);
                }
            }
        }
    }while(!stackempty());
    printf("走不通");
    return 0;   
}
int main(void){
    point start;
    initstack();
    printf("输入起始位置：(0-7)\nX:");
    scanf("%d",&start.x);
    printf("Y:");
    scanf("%d",&start.y);
    setweight();
    setmap();
    horsepath(start);
    outputpath();
}
