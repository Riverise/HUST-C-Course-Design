#include <stdio.h>
void main()
{
	unsigned int x =015,y=0x2b,z;
	z=~x+~y;
	printf("%u%u%u\n",~x,~y,z);
}