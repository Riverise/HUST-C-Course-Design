#include <stdio.h>
#include <graphics.h>
#include "INIT.H"
#include "left.h"
void init()
{
 
	setbkcolor(LIGHTGRAY);
	setcolor(WHITE);
	rectangle(260,40,400,450);     //max 640*480
	line(260,245,400,245);
	circle(330,348,30);        //F1 only one button-up
 //	circle(330,296,30);        //used for floor between
 //	circle(330,400,30);
	moveto(315,360);         //picture a up button
	lineto(345,360);
	lineto(330,330);
	lineto(315,360);
	left();

//	getchar();

//	closegraph();
}
