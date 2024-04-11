#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *simplify(char *s);
void main()
{
	char string[80];
	printf("please input from 'A'to'Z':");
	gets(string);
	if(*string!=‘2’)
	{
		puts(simplify(string));
	}
}
char *simplify(char *s)
{
	char *ss=s;
	int k=1;
	while(*s!='\0')
	{
		char *temp=s;
		while(*s==*(s+1))
		{
			k++,s++;
		}	
		if(k!=1)
			*temp='0'+k,strcpy(temp+1,s),s=temp+1;
		k=1;
		s++;
	}
 	return ss;
}