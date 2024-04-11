#include<stdio.h>
void main()
{
	int a1=10,a2=-3,sum=1;
	while(sum<=5)
	{
		sum++;
		printf("%d  %d  ",a1,a2);
		a1+=a2*3;
		a2+=a1*3;
	}

}