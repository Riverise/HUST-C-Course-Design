#include "quitbutt.h"
#include <graphics.h>
void quitbutt()
{
	setcolor(RED);
	rectangle(575, 0, 640, 35);
	settextstyle(1, 0, 0);
	outtextxy(575, 0, "QUIT");
}