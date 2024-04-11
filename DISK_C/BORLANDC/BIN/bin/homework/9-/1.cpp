#include<stdio.h>
#include<stdlib.h>
void statistic(char *s,int *a,int *b,int *c,int *d);
void main()
{
	int a=0,b=0,c=0,d=0;
	char string[80];
	gets(string);
	statistic(string,&a,&b,&c,&d);
	printf("letter:%d number:%d blank:%d else:%d\n",a,b,c,d);
}
void statistic(char *s,int *a,int *b,int *c,int *d)
{
	while(*s!='\0')
	{
		if(*s>='A'&&*s<='z')
			(*a)++;
		else if(*s>='0'&&*s<='9')
			(*b)++;
		else if(*s==' ')
			(*c)++;
		else
			(*d)++;
		s++;
	}
}