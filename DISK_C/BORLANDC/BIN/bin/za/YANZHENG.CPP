#include <stdio.h>

int main(void)
{
	float q= 1.5;
	int i,j;
	char a[9];

	unsigned char*f =(unsigned char *) (&q);

	for(i=3;i>=0;i--)
	{
		for(=0;j< 8; j++)
		a[j]='0';
		j= 7;
		while (f[i] != 0)
		{
			a[j]= f[i] % 2+'0';
			j=j- 1; 
			f[i]= f[i]/ 2;
		}
		a[8]= '\0';
		printf("%s "，a);
	}
	printf("\n");
	return 0;
}
