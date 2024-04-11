#include<stdio.h>
void f1(int a[],int n);
void f2(int a[],int n);
void main()
{
	int k,n;
	int a[]={7,3,7,3,5,4,1};
    printf("k,n");
	scanf("%d%d",&k,&n);
	if(n>=10){printf("wrong");}
	else if(k==1){f1(a,n);}
	else{f2(a,n);}
	printf("\n");
}
void f1(int a[],int n)
{
	int i,j;
	int t=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]<a[j+1]){t=a[j];a[j]=a[j+1];a[j+1]=t;}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("a%d=%d",i,a[i]);
	}
}
void f2(int a[],int n)
{
	int i,j;
	int t=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1]){t=a[j];a[j]=a[j+1];a[j+1]=t;}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("a%d=%d",i,a[i]);
	}
}

 