#include<stdio.h>
void main()
{
	long i,sum=1;
	for(i=1;i<=10;i++)
	{
		sum*=i;
		printf("%ld ",sum);
	}
	printf("\n");
}