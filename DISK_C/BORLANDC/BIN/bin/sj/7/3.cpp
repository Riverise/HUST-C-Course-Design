#include<stdio.h>
void main()
{
	int i,j,t;
	int a[8]={6,5,3,1,8,7,2,4};
    a[-1]=0;
	for(i=1;i<8;i++)
	{
		t=a[i];
		for(j=i;j>0;j--)
		{
			
			if(t<a[j-1])
			{a[j]=a[j-1];}
			else{break;}
		}
        a[j]=t;
		for(j=0;j<8;j++)
		{printf("a%d=%d ",j,a[j]);}
    	printf("\n");
	}
}