#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *look_for_the_longest(char *s);
void main()
{
	char string[200];
	gets(string);
	puts(look_for_the_longest(string));
}
char *look_for_the_longest(char *s)
{
	int a=0,c=0;
	char *b,*d;
	s--;
	while(*s!='\0')
	{
		s++;
		while(*s>='A'&&*s<='z')
		{
			a+=1,s++;
		}
		if(a>c)
			c=a,b=s-a,d=s;
		a=0;
	}
	*d='\0';
	return b;
}