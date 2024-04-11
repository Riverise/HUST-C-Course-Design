#include<stdio.h>
void main()
{
	int a,b;
	for(a=3;a<1000;a+=3)
	{
		if(a/100==5||a/10%10==5||a%10==5)
		printf("%d ",a);
	}
	printf("\n");
}