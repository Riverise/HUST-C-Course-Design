#include<stdio.h>
int main()
{
	int a=1;
    printf("%d\n",a--&&a);
	if(a--&&a)
		printf("test\n");
}