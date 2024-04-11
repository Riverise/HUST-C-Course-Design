#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void main()
{
	int i,a,b;
	randomize();
	b=random(101);
	for(i=0;i<20;i++)
	{
		scanf("%d",&a);
		if(a<b)
		{
			printf("small\n");
		}
		else if(a>b)
		{
			printf("large\n");
		}
		else
		{
			printf("right\n");
			break;
		}
	}
}

