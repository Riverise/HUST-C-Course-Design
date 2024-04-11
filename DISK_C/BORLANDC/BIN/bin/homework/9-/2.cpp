#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insert(char *s,char *s1,int k);
void main()
{
	char string[80],string1[80];
	int k;
	printf("please input old string");
	gets(string);
	printf("please input inserted string");
	gets(string1);
	printf("please input position");
	scanf("%d",&k);
	if(k>=0&&k<80)
		insert(string,string1,k);
	puts(string);
}
void insert(char *s,char *s1,int k)
{
	char temp[80];
	s+=k;
	strcpy(temp,s);
	strcpy(s,s1);
	while((*s++)!=0)
		;
	s--;
	strcpy(s,temp);
}