#include<stdio.h>
void main()
{
	long x,i;
	scanf("%5ld",&x);
	printf("%ld\t",x);
	for(i=0;x>=1;i++)
	{
		printf("%d",x%10);
		x/=10;
	}
	printf("\t%d\n",i);
}