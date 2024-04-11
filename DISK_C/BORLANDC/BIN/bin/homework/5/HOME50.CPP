#include<stdio.h>
void main()
{
	int i,a;
	scanf("%d",&a);
	for(i=0;!(a%2);i++)
	{
    	a/=2;
	}
	printf("%d\n",i);
}