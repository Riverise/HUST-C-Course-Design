#ifndef _calling_h_
#define _calling_h_

#include <graphics.h>
#include <stdlib.h>
#include "lift.h"
#include "hz.h"

int calling(liftsys *p);
void CallingButton(int x, int y, char *floornum)
{
	int flo;
	flo = atoi(floornum);
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	circle(x, y, 15);
	setfillstyle(1, WHITE);
	floodfill(x, y, DARKGRAY);
	settextstyle(4, 0, 1);
	setcolor(BROWN);
	if (flo > 0 && flo < 10)
		outtextxy(x - 6, y - 12, floornum);
	else		
		outtextxy(x - 10, y - 12, floornum);
	//outtextxy(x - 10, y - 12, floornum);
}
void UpArrow(int x, int y, int condition)
{
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	circle(x, y, 15);
	line(x, y - 8, x + 7, y + 4);
	line(x + 7, y + 4, x - 7, y + 4);
	line(x - 7, y + 4, x, y - 8);
	if (condition)
	{
		setcolor(YELLOW);
		setlinestyle(0, 0, 3);
		circle(x, y, 15);
	}
}
void DownArrow(int x, int y ,int condition)
{
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	circle(x, y, 15);
	line(x, y + 8, x + 7, y - 4);
	line(x + 7, y -4, x - 7, y - 4);
	line(x - 7, y - 4, x, y + 8);
	if (condition)
	{
		setcolor(YELLOW);
		setlinestyle(0, 0, 3);
		circle(x, y, 15);
	}
}
void DrawCallingPage()
{
	
	CallingButton(275, 15, "12");
	CallingButton(275, 50, "11");
	CallingButton(275, 85, "10");
	CallingButton(275, 120, "9");
	CallingButton(275, 155, "8");
	CallingButton(275, 190, "7");
	CallingButton(275, 225, "6");
	CallingButton(275, 260, "5");
	CallingButton(275, 295, "4");
	CallingButton(275, 330, "3");
	CallingButton(275, 365, "2");
	CallingButton(275, 400, "1");
	CallingButton(275, 435, "-1");
	//UpArrow(330, 15, 0);
	UpArrow(330, 50, 0);
	UpArrow(330, 85, 0);
	UpArrow(330, 120, 0);
	UpArrow(330, 155, 0);
	UpArrow(330, 190, 0);
	UpArrow(330, 225, 0);
	UpArrow(330, 260, 0);
	UpArrow(330, 295, 0);
	UpArrow(330, 330, 0);
	UpArrow(330, 365, 0);
	UpArrow(330, 400, 0);
	UpArrow(330, 435, 0);
	DownArrow(385, 15, 0);
	DownArrow(385, 50, 0);
	DownArrow(385, 85, 0);
	DownArrow(385, 120, 0);
	DownArrow(385, 155, 0);
	DownArrow(385, 190, 0);
	DownArrow(385, 225, 0);
	DownArrow(385, 260, 0);
	DownArrow(385, 295, 0);
	DownArrow(385, 330, 0);
	DownArrow(385, 365, 0);
	DownArrow(385, 400, 0);
	//DownArrow(385, 430, 0);
	setcolor(DARKGRAY);
	line(220, 0, 220, 480);
	line(440, 0, 440, 480);
	circle(500, 370, 30);
	setfillstyle(1, CYAN);
	floodfill(500, 370, DARKGRAY);
	puthz(473, 360, "确认", 24, 29, RED);
	puthz(5, 5, "各楼层的上下按钮均可点击，", 16, 17, DARKGRAY);
	puthz(5, 25, "模拟当前楼层电梯外有乘客", 16, 17, DARKGRAY);
	puthz(5, 45, "想上行或下行", 16, 17, DARKGRAY);
	puthz(5, 85, "完成外部按钮后请按确认键", 16, 17, DARKGRAY);
}
void updatewait(liftsys *p)  //将呼叫信息传给wait列表以供分析与任务分配
{
	int i, j;
	int temp[13];
	for (i = 0; i < 13; i++)	
	{
		if (p->call[i])	temp[i] = p->call[i];
		else            temp[i] = -5;
	}
	for (j = 0; j < 13; j++)
	{
		for (i = 0; i < 13; i++)
		{
			if (temp[i] != -5)
			{				
					p->wait[j].flo = i;
					temp[i] = -5;
					break;								
			}
		}
	}
}


#endif
