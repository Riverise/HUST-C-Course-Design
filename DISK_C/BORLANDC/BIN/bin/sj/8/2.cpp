#include<stdio.h>
#define N 5
void f1(int a[],int m,int n);
void switc(int a[],int n);
void main()
{
	int a[N]={5,6,7,1,0};
	int m,n,i;
	printf("m=:,n=:\n");
	scanf("%d%d",&m,&n);
	f1(a,m,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void f1(int a[],int m,int n)
{
	int i;
	for(i=0;i<m;i++)
	{
		switc(a,n);
	}
}
void switc(int a[],int n)
{
	int i,t;
	t=a[n-1];
	for(i=n-1;i>0;i--)
	{
		a[i]=a[i-1];
	}
	a[0]=t;
}

