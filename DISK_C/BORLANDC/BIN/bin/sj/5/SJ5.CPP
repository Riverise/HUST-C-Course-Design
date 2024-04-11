#include<stdio.h>
void main()
{
	int b,c;
	long a,x;
	for(a=1;a<10;a++)
	{
		for(b=0;b<10;b++)
		{
			for(c=0;c<10;c++)
			{
				x=10000*a+b*100+c+2030;
				if(x%23==0)
				{
					printf("%ld ",x);
				}
			}
		}
	}
	printf("\n");
}
