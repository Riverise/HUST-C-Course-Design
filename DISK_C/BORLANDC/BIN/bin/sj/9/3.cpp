#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *simplyfy(char *s);
void main()
{
	char string[80];
	gets(string);
	puts(simplyfy(string));
}
char *simplyfy(char *s)
{
	int i=1,j=1,k=1,m=0;
	char *a[80];
	char *ss=s,*sss;
	while(*s!='\0')
	{
		for(k=0,i=j,sss=s;i>0;i--,sss--)
		{
			if(*sss==*s)
				k++;	
		}
		if(k!=1&&k!=3&&k!=6&&*s!=' ')
			a[m]=s,m++;
		s++,j++;
	}
	i=m;
	for(m=0;m<=i;m++)
	{
		strcpy(a[m]-m,a[m]+1-m);
	}
	return ss;
}