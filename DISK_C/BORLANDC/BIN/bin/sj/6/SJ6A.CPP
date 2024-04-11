#include<stdio.h>
int squSum(int a,int b);
void main()
{
	int r,h,x;
	scanf("%d%d",&r,&h);
	x=squSum(r,h);
	printf("%d\n",x);
}
int squSum(int a,int b)
{
	return(a*a+b*b);
}