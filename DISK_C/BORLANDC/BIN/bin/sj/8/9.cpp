#include<stdio.h>
#define N 5
void do_la_loubere(int **p);
void main()
{
	int a[N][N]={{0},{0},{0},{0},{0}};
	int *p[N],**pp,i,j;
	for(i=0;i<N;i++)
		p[i]=a[i];
	pp=p;
	do_la_loubere(pp);
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
void do_la_loubere(int **p)
{
	int i,k=0,j=2,t;
	for(i=1;i<=N*N;i++)
	{
		if(j>=5)
			j-=5;
		if(k<0)
			k+=5;
		for(;;)
		{
			if(p[k][j]!=0)
			{
				k++;
				if(k>=5)
					k-=5;
			}
			else
				break;
		}
		p[k][j]=i;
		k--;
		j++;
	}
}