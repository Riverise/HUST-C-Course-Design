#include<stdio.h>
void main()
{
		int x;
        scanf("%d",&x);
		if(x%4==0&&x%100!=0||x%400==0)
        {
			printf("yes\n");
        }
        else
        {
			printf("no\n");
        }
}
