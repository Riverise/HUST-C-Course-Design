#include<stdio.h>
#define C 2204
#define T 20221212
struct students
{
	int clas;
	int time;
	char name[10];
	long No;
	float grades[4];
};
void ranking(struct students *s);
void putbest(struct students *s,float *average,int *a);
void putinpass(struct students *s,float *average);
void main()
{
	struct students stu[10]={{C,T,"weiyang",202215022,{25,60,75,83}},{C,T,"qiqi",202215077,{15,62,76,87}},{C,T,"lingren",202215080,{67,93,99,55}},{C,T,"sanbing",202215029,{75,60,76,75}},{C,T,"yidou",202215069,{60,75,83,55}},{C,T,"yanfei",202215002,{95,65,65,75}},{C,T,"zhanhan",202215011,{99,77,85,75}},{C,T,"fenyang",202215072,{75,60,55,67}},{C,T,"weiyan",202215042,{85,70,66,99}},{C,T,"anay",202215024,{45,95,79,75}}};
	ranking(stu);
}
void ranking(struct students *s)
{
	int i,j,a[10];
	float average[10],k;
	for(i=0;i<10;i++)
	{
		a[i]=i+1;
		average[i]=(s[i].grades[0]+s[i].grades[1]+s[i].grades[2]+s[i].grades[3]+0.00)/4;
	}
	struct students temp;
	for(i=1;i<10;i++)
	{
		for(j=i;j>0;j--)
		{
			if(average[i]>average[i-1])
			{
				temp=s[i];s[i]=s[i-1];s[i-1]=temp;
				k=average[i];average[i]=average[i-1];average[i-1]=k;
			}
		}
	}
	for(i=1;i<10;i++)
	{
		if(average[i-1]==average[i])
			a[i]=a[i-1];
	}
	printf("No\t\t\tname\t\taverage\t\trank\n");
	for(i=0;i<10;i++)
	{
		printf("%ld\t\t%s\t\t%.2f\t\t%d\n",s[i].No,s[i].name,average[i],a[i]);
	}
	putbest(s,average,a);
	putinpass(s,average);
}
void putbest(struct students *s,float *average,int *a)
{
	printf("the best\nNo\t\t\tname\t\taverage\n");
	int i;
	int u;
	for(i=0;i<10;i++)
	{
		if(a[i]==1)
			printf("%ld\t\t%s\t\t%.2f\n",s[i].No,s[i].name,average[i]);
	}
}
void putinpass(struct students *s,float *average)
{
	printf("didn't pass\nNo\t\t\tname\t\taverage\n");
	int i;
	for(i=0;i<10;i++)
	{
		if(average[i]<60)
			printf("%ld\t\t%s\t\t%.2f\n",s[i].No,s[i].name,average[i]);
	}
}
