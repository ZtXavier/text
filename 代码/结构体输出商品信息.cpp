#include<stdio.h>
struct information
{
	int n;
	char name[20];
	char add[20];
	int phnum;
	int date;
	int jprice;
	int number;
	int xprice;
};
int main(void)
{
	struct information m;
	scanf("%d%s%s%d%d%d%d%d",&m.n,m.name,m.add,&m.phnum,&m.date,&m.jprice,&m.number,&m.xprice);
	printf("%d%s%s%d%d%d%d%d",m.n,m.name,m.add,m.phnum,m.date,m.jprice,m.number,m.xprice);
	return 0;
}
