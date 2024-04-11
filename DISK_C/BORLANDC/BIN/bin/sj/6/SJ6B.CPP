#include<stdio.h>
#include<math.h>
void f1(float,float,float,float * x1,float * x2);
void f2(float,float,float,float * x1,float * x2);
void main()
{
	float a,b,c,x1,x2 ;
	scanf("%f%f%f",&a,&b,&c);
	if(b*b-4*a*c>0)
	{
		f1(a,b,c,&x1,&x2);
		printf("x1=%.2f,x2=%.2f\n",x1,x2);
	}
	if(b*b-4*a*c==0)
	{
		f1(a,b,c,&x1,&x2);
		printf("x1=x2=%.2f\n",x1);
	}
	if(b*b-4*a*c<0)
	{
		f2(a,b,c,&x1,&x2);
		printf("x1=%.2f+%.2fi,x2=%.2f-%.2fi\n",x1,x2,x1,x2);
	}
}
void f1(float a,float b, float c,float * x1,float * x2)
{
	* x1=(-b-sqrt(b*b-4*a*c))/(2*a);
	* x2=(-b+sqrt(b*b-4*a*c))/(2*a);
}
void f2(float a,float b,float c,float * x1,float * x2)
{
	* x1=(-b)/(2*a);
	* x2=sqrt(4*a*c-b*b)/(2*a);
}