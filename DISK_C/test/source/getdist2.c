#include <stdio.h>
#include "getdist2.h"
#include <math.h>

double getdist2(int x2,int y2, int x1, int y1)
{
	double distance2=(pow(x2-x1,2)+pow(y2-y1,2));
	return distance2;
}
	
