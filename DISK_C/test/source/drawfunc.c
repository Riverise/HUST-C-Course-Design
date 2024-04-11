#include "drawfunc.h"
#include <graphics.h>
#include "hz.h"
#include <stdlib.h>
void stairbutton(int x, int y, char *floor, int stop)  //¥�㰴ť 
{
	int flo;
		flo = atoi(floor);
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);  //�������� 
	circle(x, y, 14);
	settextstyle(4, 0, 1);  //���������ʽ 
	setcolor(BROWN);
	if (stop == 0)
	{
		//****
		if (flo > 0 && flo < 10)
			outtextxy(x-6, y-12, floor);
		else
		//***	
		outtextxy(x - 10, y - 12, floor);
	}
	else if (stop == 1)
	{
		setfillstyle(1, LIGHTGREEN);
		floodfill(x, y, DARKGRAY);
		//***
		if (flo > 0 && flo < 10)
			outtextxy(x-6, y-12, floor);
		else
		//***
		outtextxy(x - 10, y - 12, floor);
	}
}

void uparrow(int x, int y, int color)   //�ϼ�ͷ ,(x,y)Ϊ��ͷ�����ϼ��
{
	setcolor(DARKGRAY);
	line(x, y, x - 10, y + 10);
	line(x - 10, y + 10, x - 5, y + 10);
	line(x - 5, y + 10, x - 5, y + 20);
	line(x - 5, y + 20, x + 5, y + 20);
	line(x + 5, y + 20, x + 5, y + 10);
	line(x + 5, y + 10, x + 10, y + 10);
	line(x + 10, y + 10, x, y);
	if (color == 1)
	{
		setfillstyle(1, LIGHTGREEN);
		floodfill(x, y + 5, DARKGRAY);
	}
}

void downarrow(int x, int y, int color)   //�¼�ͷ ��(x,y)Ϊ��ͷ�����¼��
{
	setcolor(DARKGRAY);
	line(x, y, x - 10, y - 10);
	line(x - 10, y - 10, x - 5, y - 10);
	line(x - 5, y - 10, x - 5, y - 20);
	line(x - 5, y - 20, x + 5, y - 20);
	line(x + 5, y - 20, x + 5, y - 10);
	line(x + 5, y - 10, x + 10, y - 10);
	line(x + 10, y - 10, x, y);
	if (color == -1)
	{
		setfillstyle(1, LIGHTGREEN);
		floodfill(x, y - 5, DARKGRAY);
	}
}
void sbutton(int x, int y, int color)     //�ϼ�ͷ��ť 
{
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);  //�������� 
	circle(x, y, 12);
	line(x - 5, y, x, y - 4);
	line(x, y - 4, x + 5, y);
	if (color == 1 || color == 3)
	{
		setfillstyle(1, LIGHTGREEN);
		floodfill(x, y, DARKGRAY);
	}
}
void xbutton(int x, int y, int color)     //�¼�ͷ��ť 
{
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);  //�������� 
	circle(x, y, 12);
	line(x - 5, y, x, y + 4);
	line(x, y + 4, x + 5, y);
	if (color == -1 || color == 3)
	{
		setfillstyle(1, LIGHTGREEN);
		floodfill(x, y, DARKGRAY);
	}
}
void cable(int num, int y)
{
	if (num == 1)	line(220, 30, 220, y);
	if (num == 0)	line(420, 30, 420, y);
}
//belows are for insidepage
int inside(liftinfo *q);
void InsideButton(int x, int y, char *floornum)
{

	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	circle(x, y, 20);
	setfillstyle(1, WHITE);
	floodfill(x, y, DARKGRAY);
	settextstyle(4, 0, 1);
	setcolor(BROWN);
	outtextxy(x - 10, y - 12, floornum);

}

void DrawInsidePage(liftinfo *q)
{
	char flo[3];
	itoa(q->cur, flo, 10);
	//below are drawing functions 
	InsideButton(275, 70, "11");
	InsideButton(275, 120, "9");
	InsideButton(275, 170, "7");
	InsideButton(275, 220, "5");
	InsideButton(275, 270, "3");
	InsideButton(275, 320, "1");
	if (q->num == 1)
		InsideButton(275, 370, "-1");
	InsideButton(385, 70, "12");
	InsideButton(385, 120, "10");
	InsideButton(385, 170, "8");
	InsideButton(385, 220, "6");
	InsideButton(385, 270, "4");
	InsideButton(385, 320, "2");
	setcolor(DARKGRAY);
	line(220, 0, 220, 480);
	line(440, 0, 440, 480);
	circle(500, 370, 30);
	setfillstyle(1, CYAN);
	floodfill(500, 370, DARKGRAY);
	puthz(473, 360, "ȷ��", 24, 29, RED);
	if (q->num == 1)
	{
		puthz(7, 5, "������������", 24, 29, RED);
		settextstyle(4, 0, 2);
		setcolor(RED);
		outtextxy(6, 33, flo);
		puthz(23, 35, "¥�ϵİ�ť����",24, 29, RED);
	}
	if (q->num == 0)
	{
		puthz(7, 5, "������ҵ�����", 24, 29, RED);
		settextstyle(4, 0, 2);
		setcolor(RED);
		outtextxy(6, 33, flo);
		puthz(23, 35, "¥�ϵİ�ť����", 24, 29, RED);
	}
}