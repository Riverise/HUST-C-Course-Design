#include<stdio.h>
void main()
{
	int a[12];
	int i,j,b=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<3;j++){a[i*3+j]=3*(i+1)+5*(j+1);}
	}
	for(i=1;i<12;i++)
	{
		int k=0;
		for(j=i-1;j>=0;j--)
		{if(a[j]==a[i]){k++;}}
		if(k==0){b++;}
	}
	printf("%d",b);
}