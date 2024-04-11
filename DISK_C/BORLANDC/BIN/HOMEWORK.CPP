#include<stdio.h>
void main()
{
	float c,s,S,V,r;
	scanf("%f",&r);
	c=3.1415*r*2;
	s=3.1415*r*r;
	S=4*s;
	V=4*3.1415*r*r*r/3;
	if(r<2&&r>=1)
	{
		printf("c=%f\n s=%f\n S=%f\n V=%f\n",c,s,S,V);
	}
	else
	{
		printf("r=%f\n",r);
	}
}