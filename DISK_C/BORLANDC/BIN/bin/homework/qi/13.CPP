#include<stdio.h>
#define L 5
#define R 6
void main()
{
	int a[R][L]={{0},{0},{0},{0},{0},{0}};
	int i,j,k,b,c,d,e;
	d=0;
	e=0;
	for(i=0;i<R;i++)
	{
		b=a[i][0];
		c=0;
		for(j=1;j<L;j++)
		{
			if(b<a[i][j])
			{
				b=a[i][j];        //找出第一个最大值
				c=j;                                //第一个最小值的列
			}
		}
		for(e=0,j=0;j<R;j++){if(b<=a[j][c]){e+=1;}}       //看是否此数为列上最小值
		if(e==R)
		{
			printf("row=%d\tline=%d\tsaddle point=%d\n",i,c,b);
			d+=1;
		}
		for(k=c+1;k<L;k++)
		{
			if(a[i][k]==a[i][c])
			{
				for(e=0,j=0;j<R;j++){if(b<=a[j][k]){e+=1;}}
				if(e==R)
				{
					printf("row=%d\tline=%d\tsaddle point=%d\n",i,k,b);
					d+=1;
				}
			}
		}
		
	}
	if(d==0)
	{
		printf("no saddle point\n");
	}
}