#include<stdio.h>
struct Employee
{
	char *name;
	char sex;
	int old;
	int wage;
}wang;
void main()
{
	printf("%d",sizeof(wang));
}