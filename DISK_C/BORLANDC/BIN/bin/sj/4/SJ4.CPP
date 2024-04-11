#include<stdio.h>
void main()
{
	int y,x,a,b;
	scanf("%d%d",&x,&y);
	a=x;
	b=y;
	while(x!=y)
	{
		if(x>y)
		{
			x-=y;
		}
		else
		{
			y-=x;
		}
	}
	printf("%d\t%d\n",a/y*b,y);
}