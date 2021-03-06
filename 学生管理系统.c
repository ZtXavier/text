#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
#include<string.h>
#include<assert.h>
#include<ctype.h>
//#include<io.h>
typedef struct Date
{
	int year;
	int month;
	int day;
}date;
typedef struct Bike
{
	char name[16];
	char sex[16];
	char card[24];
	char phone[24];
	date time;
	int Number;
	int age;
	struct Bike *next;
}bike,*linklist;

void free_linklist(bike *head);
void CycleList_menu(bike **head);
void display(bike *head);
int _Deletemission(bike **head);
int correct(bike **head);
int input(bike **head);
int Find(bike *head);
int length_list(bike *head,int Number);
int pop_sort(bike *head);
int Sort(bike **head);
int reverse(bike *head); 
int FileWrite(bike *head);
int printf_inf(bike *h); 
linklist initlist(bike *head);
linklist FileRead();

linklist initlist(bike *head){
	head=(bike*)malloc(sizeof(bike));
	head->next=NULL;
	return head;
}

int printf_inf(bike *h){
	bike *by;
	printf("\n车辆停放信息为:\n");
	printf("\t车号\t姓名\t性别\t年龄\t身份号码\t电话号码\t停放日期\n");
	for(by=h->next;by->next!=NULL;by=by->next)
	printf("\t%d\t%s\t%s\t%d\t%s\t%s\t%d\t%d\t%d",by->Number,by->name,by->sex,by->age,by->phone,by->card,by->time.year,by->time.month,by->time.day);
	return 1;
}

//文件储存 
int FileWrite(bike *head){
	FILE *fp; 
	char filename[20];
	bike *p=NULL;
	int sure;
	printf("是否确认要储存？1--确认；0--取消\n");
	scanf("%d",&sure);
	if(sure==0)
	return 0; 
	printf("\t请输入要存储的文件名：\n");
	scanf("%s",filename);
	if((fp=fopen(filename,"wt"))==NULL){
		printf("写文件出错，按任意键退出！\n");
		getchar();
		exit(1);
	}
	for(p=head->next;p!=NULL;p=p->next)
	fprintf(fp,"%s %s %s %s %d %d %d %d %d\n",p->name,p->sex,p->phone,p->card,p->age,p->Number,p->time.year,p->time.month,p->time.day);
    printf("文件已成功保存！！！\n");
	printf("按任意键返回\n");
	getchar(); 
	fclose(fp);
	return 1;
}
//文件读取 
linklist FileRead(){
	FILE *fp;
	bike *p,*by,*ghead;
	char ch;
	char filename[20];
	printf("请输入要读取的文件名：\n");
	scanf("%s",filename);
	if((fp=fopen(filename,"rt"))==NULL){
		printf("读文件错误，按任意键返回。\n");
		system("pause");
		return 0;
	}
	ghead=(bike*)malloc(sizeof(bike));
	ghead->next=NULL;
	by=ghead;
	while(!feof(fp)){
	    p=(bike*)malloc(sizeof(bike));
		fscanf(fp,"%s %s %s %s %d %d %d %d %d",by->name,by->sex,by->phone,by->card,&by->age,&by->Number,&by->time.year,&by->time.month,&by->time.day);
	    by->next=p;
		by=p;
	}
	by->next=NULL;
	fclose(fp);
    printf("\n文件信息打开成功,按任意键返回.\n");
	getchar();
	return ghead;
 } 

int reverse(bike *head){
	bike *p,*q;
	p=head->next;	
    head->next=NULL;
    while(p){
    q=p->next;
    p->next=head->next;
    head->next=p;
    p=q;
	} 
	printf("逆置完成！按任意键继续.\n");
	getchar();
	return 1;
}

int pop_sort(bike *head)    
{							
	bike *pre,*p,*tail,*temp;
	tail=NULL;
	pre=head;
	if(head->next!=NULL)
	{ 
	while((head->next->next)!=tail) 
	{
		p=head->next;
		pre=head;
		while(p->next!=tail)
		{
			if((p->Number)>(p->next->Number))
			{
                pre->next=p->next;  
                temp=p->next->next;
                p->next->next=p;
                p->next=temp;
                p=pre->next;  
			}
			p=p->next; 
			pre=pre->next;	
		}
		tail=p;
	}
}
        else{
        printf("没有车辆停放！！！\n");
        printf("按任意键继续.\n");
        getchar();
        return 1;
    }
    printf("排序完毕!按任意键继续.");
    getchar();
	return 1;
}

void free_linklist(bike *head)
 {
 	bike *q,*p;
 	q=head->next;
 	while(q!=NULL)
	 {
	 	p=q;
	 	q=q->next;
	 	free(p);
	 } 
	  printf("释放完毕！按任意键返回。\n");
	  getchar();
}

int length_list(bike *head,int Number)
{
	bike *p;
	int cnt=0,flag=0;
	p=head->next;
	while(p!=NULL){
	if(p->Number==Number){
    flag=1;	
	printf("此车位已满！！！\n");
}
	p=p->next;
	cnt++;
  }
    printf("目前已使用了%d个车位.\n",cnt);
    return flag;
}

void CycleList_menu(bike **head)
{
	char first[9];
	int secret,n;
	    printf("\t**********************************\n");
  		printf("\t**    欢迎使用自行车管理系统    **\n");
  		printf("\t**==============================**\n");
  		printf("\t**          1.用户登录          **\n");
  		printf("\t**          0.取消退出          **\n");
  		printf("\t**********************************\n");
  		printf("\t请选择：");
		scanf("%d",&n);   
  		if(n){
		while(n){
		printf("\t请输入用户名:(最多9位)");
		scanf("%s",first); 
		printf("\t请输入密码:(最多9位)");
		scanf("%d",&secret);
		if(strcmp(first,"ZTDSG")==0&&secret==521){	
		printf("\t身份验证成功！！！\n");
		printf("\t按任意键继续\n");
		getchar();
		break;
	}
		else
		printf("用户名或密码验证失败，请重新输入！！\n");
		printf("按任意键继续\n");
		getchar(); 
	}
	
//	while(n){
//		printf("\t请输入用户名:(最多9位)");
//		scanf("%s",first);
//		if(strcmp(first,"ZTDSG")==0){	
//		printf("用户名验证成功！！！\n");
//		printf("按任意键继续\n");
//		getch();
//		break;
//	}
//		else
//		printf("验证失败，请重新输入！！\n");
//		printf("按任意键继续\n");
//		getch(); 
//	}
//	while(n){
//		printf("\t请输入密码:(最多9位)");
//		scanf("%d",&secret);
//		if(secret==521){	
//		printf("用户名验证成功！！！\n");
//		printf("按任意键继续\n");
//		getch();
//		break;
//	}
//		else
//		printf("验证失败，请重新输入！！\n");
//		printf("按任意键继续\n");
//		getch(); 
//	}
}
	else
	return;
	
	int select=1;
  	while(select)
	{
  		printf("*************************************\n");
  		printf("**          自行车管理系统           **\n");
  		printf("**=================================**\n");
  		printf("**          1.信息登记              **\n");
  		printf("**          2.信息修改              **\n");
  		printf("**          3.用户取车              **\n");
  		printf("**          4.信息查询              **\n");
  		printf("**          5.车位排序              **\n");
  		printf("**          6.车辆停放状态           **\n");
  		printf("**          7.打印车辆信息           **\n");
  		printf("**          0.退出管理系统           **\n");
  		printf("*************************************\n");
  		printf("*     每天停放自行车费用为2元哦     *\n");
  		printf("**************************************\n");
  		printf("请选择：");
		scanf("%d",&select);
		switch(select)
		{
			case 1:
	               input(head);
			      break; 
			case 2:
			      correct(head); 
			      break;
			case 3:
			      _Deletemission(head);
			      break;
			case 4:
			      Find(*head);
			      break;
			case 5:
			      Sort(head);
			      break;
			case 6:
			      display(*head);
			      break;
		    case 7:
			      printf_inf(*head);
			      break;
			case 0:
			      break;
			defualt:
			printf("选择错误！请重新选择。\n");
			getchar();
			break;
		}	
	} 
}

int input(bike **head)
{
	int sure;
	bike by;
	bike *q,*p,*head1,*k;
	head1=*head;
	k=*head;
	k=k->next;
	printf("请输入姓名(为空将返回):");
	scanf("%s",by.name);
	if(strlen(by.name)==0) return 1;
	printf("性别: ");
	scanf("%s",by.sex);
	printf("年龄: ");
	scanf("%d",&by.age);
	printf("存放日期(例1991.5.21): ");
	scanf("%d.%d.%d",
	&by.time.year,&by.time.month,&by.time.day);
	printf("身份号码: ");
	scanf("%s",by.card); 
	printf("电话号码: ");
	scanf("%s",by.phone);
	printf("请输入停车位号:(限存20) ");
	scanf("%d",&by.Number);
	if(length_list(*head,by.Number)||by.Number>20){
	printf("请重新选择，按任意键继续.");
	getchar();
	return 1;
}
	printf("确认是否保存: 1--保存；2--放弃");
	scanf("%d",&sure);
	if(sure!=1) return 1;
	p=(bike*)malloc(sizeof(bike));
	if(p==NULL)
	{
		printf("申请空间出错！按任意键返回。\n");
		getchar();
		return -1;
	}
	strcpy(p->name,by.name);
	strcpy(p->sex,by.sex);
	strcpy(p->phone,by.phone);
	strcpy(p->card,by.card);
	p->time=by.time;
	p->age=by.age;
	p->Number=by.Number;
	p->next=NULL;
	q=head1->next;
	if(q==NULL)head1->next=p;
	else
	{
		while(q->next!=NULL)q=q->next;
		q->next=p;
	}
//	FILE *fp=fopen("d://c//file.txt","a");
//	fprintf(fp,"姓名：%s\n性别： %s\n电话: %s\n身份号码： %s\n年龄： %d\n车位号： %d\n停车时间： %d年%d月%d日",by.name,by.sex,by.phone,by.card,by.age,by.Number,by.time.year,by.time.month,by.time.day);
//	fclose(fp);
	printf("保存完毕！按任意键返回.\n");
	getchar();
	return 1;
    }

int _Deletemission(bike **head)
{
	bike *p,*q,*m;
	int fee=0;
	int point,sure,select=1,num; 
	int year;
	int month;
	int day;
	char name[9];
	q=p=*head;
	p=p->next;
	while(select){
  		printf("************************\n");
  		printf("**      删除选项      **\n");
  		printf("**====================**\n");
  		printf("**     1.姓名删除     **\n");
  		printf("**     2.车号删除     **\n");
  		printf("**     0.退出系统     **\n");
  		printf("************************\n");
  		printf("请选择：");
  		scanf("%d",&point);
  		switch(point)
  		{
		    case 1:printf("是否确认当前删除选择: 1--确认；0--放弃");
	               scanf("%d",&sure);
	               if(sure==1){
				   printf("请输入要取车人的姓名:\n");
	               scanf("%s",name); 
	               printf("请输入您的取车日期:(例1991.5.21)\n");
	               scanf("%d.%d.%d",
	               &year,&month,&day); 
	               if(p!=NULL)
	               while(p!=NULL){
		           if(strcmp(p->name,name)==0){
		           printf("请核对您的信息是否正确！！！\n");
		           printf("\t姓名:%s\n",p->name);
		           printf("\t性别:%s\n",p->sex);
		           printf("\t年龄:%d\n",p->age);
		           printf("\t电话号码:%s\n",p->phone);
		           printf("\t身份号码:%s\n",p->card);
		           printf("\t停车位号:%d\n",p->Number);
		           printf("\t车辆停放时间:%d.%d.%d\n",
		           p->time.year,
		           p->time.month,
		           p->time.day);		
		           printf("是否要取车？1--确定 0--取消");
		           scanf("%d",&sure);
		           if(sure==1){
		           fee=((year-(p->time.year))*365*24+(month-(p->time.month))*30+(day-(p->time.day)));
	      	       q->next=p->next;
	      	       m=p;
	               p=p->next;
	      	       m->next=NULL;
	      	       free(m);
	      	       printf("感谢您的光临，您需要缴纳的费用为：%d元\n",fee);
	      	       printf("按任意键继续...\n");
	      	       getchar(); 
	      	       return 1;
                }
                   else
                   return 1;
	        }
		           else{
			       p=p->next;
			       q=q->next;
			       if(p==NULL)
			       printf("查询不到此人！！！\n");
			       printf("按任意键继续\n");
			       getchar();
		        }	
        }   
	               else
	               printf("没有录入信息！！！\n");
	               printf("按任意键继续\n");
	               getchar();
	               return 1;
			}
			       break; 
		    case 2:printf("是否确认车号删除: 1--确认；0--放弃");
	               scanf("%d",&sure);
	               if(sure==1){   
			    
   printf("请输入要取车人的车号:\n");
	               scanf("%d",&num); 
	               printf("请输入您的取车日期:(例1991.5.21)\n");
	               scanf("%d.%d.%d",
	               &year,&month,&day); 
	               if(p!=NULL)
	               while(p!=NULL){
		           if(p->Number==num){
		           printf("请核对您的信息是否正确！！！\n");
		           printf("\t姓名:%s\n",p->name);
		           printf("\t性别:%s\n",p->sex);
		           printf("\t年龄:%d\n",p->age);
		           printf("\t电话号码:%s\n",p->phone);
		           printf("\t身份号码:%s\n",p->card);
		           printf("\t停车位号:%d\n",p->Number);
		           printf("\t车辆停放时间:%d.%d.%d\n",
		           p->time.year,
		           p->time.month,
		           p->time.day);		
		           printf("是否要取车？1--确定 0--取消");
		           scanf("%d",&sure);
		           if(sure==1){
		           fee=((year-(p->time.year))*365*24+(month-(p->time.month))*30+(day-(p->time.day)));
	      	       q->next=p->next;
	      	       m=p;
	               p=p->next;
	      	       m->next=NULL;
	      	       free(m);
	      	       printf("感谢您的光临，您需要缴纳的费用为：%d元\n",fee);
	      	       printf("按任意键继续...\n");
	      	       getchar(); 
	      	       return 1;
                }
                   else
                   return 1;
	        }
		           else{
			       p=p->next;
			       q=q->next;
			       if(p==NULL)
			       printf("查询不到此人！！！\n");
			       printf("按任意键继续\n");
			       getchar();
		        }	
        }   
	               else
	               printf("没有录入信息！！！\n");
	               printf("按任意键继续\n");
	               getchar();
	               return 1;
			}
			       break; 
			case 0:return 1;
		   defualt:printf("选择错误！请重新选择。\n");
		           printf("按任意键继续\n");
			       getchar();
			       break;
	    }
    }
	return 1;
}

int correct(bike **head)
	{ 
	    bike *p,by;
	    int flag=0,select,point;
	    printf("请输入要修改的车主姓名\n:");
		scanf("%s",by.name);
	    p=*head;
	    p=p->next;
		while(p!=NULL)
		{
			if(strcmp(by.name,p->name)==0)
			{
			    flag=1;
			    break;
		    }
		    else
			p=p->next;
		}
		if(flag)
		{
		while(flag)
		{
	    printf("********************\n");
  		printf("   选择要修改信息   \n");
  		printf("**================**\n");
  		printf("**    1.姓名      **\n");
  		printf("**    2.性别      **\n");
  		printf("**    3.年龄      **\n");
  		printf("**    4.身份号码  **\n"); 
  		printf("**    5.停车日期  **\n");
  		printf("**    6.电话号码  **\n");
  		printf("**    7.停车位号  **\n");
  		printf("**    0.退出      **\n");
  		printf("********************\n");
  		printf("请选择：");
		scanf("%d",&select);
		switch(select)
		{
			case 1:printf("请重新输入姓名:\n");
			       scanf("%s",by.name);
			       printf("确认是否保存:( 1--保存；2--放弃)");
			       scanf("%d",&point);
			       if(point==0)
			       break;
			       else
			       strcpy(p->name,by.name);
			       printf("保存成功!\n");
			       printf("按任意键继续\n");
			       getchar();
			       return 1; 
		    case 2:printf("请重新输入性别:");
			       scanf("%s",by.sex);
			       printf("确认是否保存: 1--保存；2--放弃");
			       scanf("%d",&point);
			       if(point==0)
			       break;
			       else
			       strcpy(p->sex,by.sex);
			       printf("保存成功!\n");
			       return 1;
			case 3:printf("请重新输入年龄:");
			       scanf("%d",&by.age) ;
			       printf("确认是否保存: 1--保存；2--放弃");
			       scanf("%d",&point);
			       if(point==0)
			       break;
			       else
			       p->age=by.age;
			       printf("保存成功!\n");
			       printf("按任意键继续\n");
			       getchar();
			       return 1;
			case 4:printf("请重新输入身份号码:");
			       scanf("%s",by.card);
			       printf("确认是否保存: 1--保存；2--放弃");
			       scanf("%d",&point);
			       if(point==0)
			       break;
			       else
			       strcpy(p->card,by.card);
			       printf("保存成功!\n");
			       printf("按任意键继续\n");
			       getchar();
			       return 1;   
			case 5:printf("请重新输入存车日期:(例1991.5.21)\n");
	               scanf("%d.%d.%d",
	               &by.time.year,&by.time.month,&by.time.day);
			       printf("确认是否保存: 1--保存；2--放弃");
			       scanf("%d",&point);
			       if(point==0)
			       break;
			       else
			       p->time.year=by.time.year;
			       p->time.month=by.time.month;
			       p->time.day=by.time.day;
			       printf("保存成功!\n");
			       printf("按任意键继续\n");
			       getchar();
			       return 1; 
			case 6:printf("请重新输入电话号码:");
			       scanf("%s",by.phone);
			       printf("确认是否保存: 1--保存；2--放弃");
			       scanf("%d",&point);
			       if(point==0)
			       break;
			       else
			       strcpy(p->phone,by.phone);
			       printf("保存成功!\n");
			       printf("按任意键继续\n");
			       getchar();
			       return 1;
			case 7:printf("请重新输入停车位号:");
			       scanf("%d",&by.Number);
			       printf("确认是否保存: 1--保存；2--放弃");
			       scanf("%d",&point);
			       if(point==0)
			       break;
			       else
			       p->Number=by.Number;
			       printf("保存成功!!!\n");
			       printf("按任意键继续\n");
			       getchar();
			       return 1;  
			case 0://FILE *fp=fopen("d://c//file.txt","a");
//	               fprintf(fp,"姓名：%s\n性别： %s\n电话: %s\n身份号码： %s\n年龄： %d\n车位号： %d\n停车时间： %d年%d月%d日",by.name,by.sex,by.phone,by.card,by.age,by.Number,by.time.year,by.time.month,by.time.day);
//	               fclose(fp);
			       return 1;
			       break;
		   defualt:printf("选择错误！请重新选择。\n");
			       getchar();
			       break;
		}
		}
	}
		else
		{
			printf("!!!!!!!!!!!!!!!!!!!!!!!!!没有学生信息!!!\n");
			return 1; 
		}
		
	     return 1;
	 }

int Find(bike *head)
{
	bike *p;
	char name[9];
	p=head->next;
	printf("请输入要查找的姓名:");
	scanf("%s",name);
	if(p==NULL){
	    printf("没有记录学生信息！！！\n");
	    return 0;
	    }
	while(p) 
	{
	    if(strcmp(p->name,name)==0){
	    printf("\t姓名:%s\n",p->name);
		printf("\t性别:%s\n",p->sex);
		printf("\t年龄:%d\n",p->age);
		printf("\t电话号码:%s\n",p->phone);
		printf("\t身份号码:%s\n",p->card);
		printf("\t停车位号:%d\n",p->Number);
		printf("\t车辆停放时间:%d.%d.%d\n",
		p->time.year,
		p->time.month,
		p->time.day);		
		printf("按任意键继续.\n\n");
		getchar();
		return 0;
		}
		else
		p=p->next;
	}
    printf("没有找到该学生信息！！！\n");
    printf("按任意键继续.\n");
	getchar();
	return 0; 
}

int Sort(bike **head){
	int select=1; 
	int point;
	int sure; 
	bike *p;
	p=*head;
	while(select){
  		printf("************************\n");
  		printf("**      排序选项      **\n");
  		printf("**====================**\n");
  		printf("**     1.顺序排序     **\n");
  		printf("**     2.车位逆置     **\n");
  		printf("**     0.退出排序系统 **\n");
  		printf("************************\n");
  		printf("请选择：");
  		scanf("%d",&point);
  		switch(point)
  		{
		    case 1:printf("是否确认当前排序操作: 1--确认；0--放弃");
	               scanf("%d",&sure);
	               if(sure){   
			       pop_sort(p);
			       printf("排序成功！！！"); 
			       }
			       printf("按任意键继续\n");
			       getchar();
			       break; 
		    case 2:printf("是否确认当前逆置操作: 1--确认；0--放弃");
	               scanf("%d",&sure);
	               if(sure){   
			       reverse(p);
			       printf("逆置成功！！！");
			       }
			       printf("按任意键继续\n");
			       getchar();
			       break;
			case 0:return 1;
		   defualt:printf("选择错误！请重新选择。\n");
		           printf("按任意键继续\n");
			       getchar();
			       break;
	    }
    }
	return 1;
}

void display(bike *head){
	bike *p;
	p=head;
	p=p->next;
	if(p==NULL)
	{
		printf("目前尚未录入数据！按任意键返回。\n");
		getchar();
		return;
	}
	while(p!=NULL)
	{
		printf("\t姓名:%s\n",p->name);
		printf("\t性别:%s\n",p->sex);
		printf("\t年龄:%d\n",p->age);
		printf("\t电话号码:%s\n",p->phone);
		printf("\t身份号码:%s\n",p->card);
		printf("\t停车位号:%d\n",p->Number);
		printf("\t车辆停放时间:%d.%d.%d\n",
		p->time.year,
		p->time.month,
		p->time.day);		
		printf("按任意键继续.\n\n");
		getchar();
		p=p->next;
	}
 }

int main(void)
{
	linklist h;
	h=FileRead();
	if(h==NULL) 
	h=initlist(h);	
	CycleList_menu(&h);
	FileWrite(h);
	free_linklist(h);
	return 0;
}