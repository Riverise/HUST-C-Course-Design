#include<stdio.h>
char *strstr(char *s1,char *s2);
void main()
{
	char s1[80],s2[80];
	gets(s1);
	gets(s2);
	puts(strstr(s1,s2));
}
char *strstr(char *s1,char *s2)
{
	if(*s2=='\0')
		return s1;
	while(1)
	{
		if(*s1!=*s2&&*s1!='\0')
			s1++;
		else if(*s1!='\0')
			{
			char *a1=s1;
			char *a2=s2;
			while(*s1++==*s2++!='\0') ;
			if(*--s2=='\0')
					return a1;
			else
				s1=a1+1,s2=a2;
				continue;
			}
		else
			return '\0';
	}
}