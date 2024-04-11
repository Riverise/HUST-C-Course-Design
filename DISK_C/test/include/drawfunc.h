#ifndef _drawfunc_h_
#define _drawfunc_h_
#include "lift.h"
void stairbutton(int x, int y, char *floor, int stop);

void uparrow(int x, int y, int color);  //上箭头 ,(x,y)为箭头的向上尖端


void downarrow(int x, int y, int color);   //下箭头 ，(x,y)为箭头的向下尖端

void sbutton(int x, int y, int color);    //上箭头按钮 

void xbutton(int x, int y, int color);   //下箭头按钮 


//belows are for insidepage
int inside(liftinfo *q);
void InsideButton(int x, int y, char *floornum);
void DrawInsidePage(liftinfo *q);

#endif


