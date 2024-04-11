#include<stdio.h>
void fa(int **pp);
void fb(int **pp);
void fc(int **pp);
void main()
{
	int a[4][5]={{90,41,65,59,57}, {85,97,93,95,88}, {25,61,61,21,62}, {55,90,33,66,55}};
	int *p[4],**pp;
	int i;
	for(i=0;i<4;i++)
		p[i]=a[i];
	pp=p;
	fa(pp);
	fb(pp);
	fc(pp);
}
void fa(int **p)
{
	printf("a:\n");
	int i,j;
	for(i=0;i<4;i++)
	{
		printf("average%d=%d ",i,(p[i][0]+p[i][1]+p[i][2]+p[i][3]+p[i][4])/5);
	}
	printf("\n");
}
void fb(int **p)
{
	printf("b:\n");
	int i,j;
	int t;
	for(i=0;i<4;i++)
	{	
		t=0;
		for(j=0;j<5;j++)
		{
			if(p[i][j]<60)
				t++;
		}
		if(t>2)	
			printf("%d:%d,%d,%d,%d,%d.average:%d\n",i,p[i][0],p[i][1],p[i][2],p[i][3],p[i][4],(p[i][0]+p[i][1]+p[i][2]+p[i][3]+p[i][4])/5);
	}
}
void fc(int **p)
{
	printf("c:\n");
	int i,j;
	for(i=0;i<4;i++)
	{
		if((p[i][0]+p[i][1]+p[i][2]+p[i][3]+p[i][4])/5>90||(p[i][0]>85&&p[i][1]>85&&p[i][2]>85&&p[i][3]>85&&p[i][4]>85))
			printf("%d ",i);
	}
	printf("\n");
}