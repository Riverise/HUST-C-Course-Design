#include<stdio.h>
#define  N 5
void main()
{
	int a[N][N]={{2},{1,1},{3,2},{2,8},{1,4}};
	int b[N];
	int i,j,c;
	for(i=0;i<N;i++)
	{
		c=a[i][0];
		for(j=1;j<N;j++)
		{
			if(a[i][j]>c)
			{
				c=a[i][j];
			}
		}
		b[i]=c;
	}
	for(i=0;i<5;i++){printf("%d ",b[i]);}
	printf("\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4-i;j++)
		{
			if(b[j]>b[j+1]){c=b[j+1];b[j+1]=b[j];b[j]=c;}
		}
	}
	for(i=0;i<5;i++){printf("%d ",b[i]);}
    printf("\n");
}
