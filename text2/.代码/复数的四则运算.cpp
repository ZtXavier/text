#include <stdio.h>
#include <math.h>
 
struct MyStruct
{
	double a;
	double b;
};
 
void print(struct MyStruct X, char op, struct MyStruct A, struct MyStruct B);

int main()
{
	struct MyStruct x[6] = { 0,0 };
	scanf("%lf %lf %lf %lf", &x[0].a, &x[0].b, &x[1].a, &x[1].b);
 
	x[2].a = x[0].a + x[1].a;
	x[2].b = x[0].b + x[1].b;
	print(x[2], '+', x[0], x[1]);
 
	x[3].a = x[0].a - x[1].a;
	x[3].b = x[0].b - x[1].b;
	print(x[3], '-', x[0], x[1]);
 
	x[4].a = x[0].a*x[1].a - x[0].b*x[1].b;
	x[4].b = x[0].a*x[1].b + x[1].a*x[0].b;
	print(x[4], '*', x[0], x[1]);
 
	x[5].a = x[0].a*x[1].a + x[0].b*x[1].b;
	x[5].b = x[0].b*x[1].a - x[0].a*x[1].b;
	x[5].a = x[5].a / (x[1].a*x[1].a + x[1].b*x[1].b);
	x[5].b = x[5].b / (x[1].a*x[1].a + x[1].b*x[1].b);
	print(x[5], '/', x[0], x[1]);
 
	return 0;
}
 
void print(struct MyStruct X, char op, struct MyStruct A, struct MyStruct B)
{
	printf("(%.1lf%+.1lfi) %c (%.1lf%+.1lfi) = ", A.a, A.b, op, B.a, B.b);
	if (fabs(X.a) < 0.05&&fabs(X.b) < 0.05)
		printf("0.0\n");
	else if (fabs(X.a) < 0.05)
		printf("%.1lfi\n", X.b);
	else if (fabs(X.b) < 0.05)
		printf("%.1lf\n", X.a);
	else
		printf("%.1lf%+.1lfi\n", X.a, X.b);
}
