#ifndef _drawfunc_h_
#define _drawfunc_h_
#include "lift.h"
void stairbutton(int x, int y, char *floor, int stop);

void uparrow(int x, int y, int color);  //�ϼ�ͷ ,(x,y)Ϊ��ͷ�����ϼ��


void downarrow(int x, int y, int color);   //�¼�ͷ ��(x,y)Ϊ��ͷ�����¼��

void sbutton(int x, int y, int color);    //�ϼ�ͷ��ť 

void xbutton(int x, int y, int color);   //�¼�ͷ��ť 


//belows are for insidepage
int inside(liftinfo *q);
void InsideButton(int x, int y, char *floornum);
void DrawInsidePage(liftinfo *q);

#endif


