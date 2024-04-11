#include <overmode.h> //"lift.h"included
#include "quitbutt.h"
#include "hz.h"
#include "drawfunc.h"  
#include <stdlib.h>
#include <mouse.h>
#include <graphics.h>


void drawpage(liftsys *q)
{
	char a[3];
	char b[3];

	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	setbkcolor(WHITE);
	quitbutt();
	setcolor(LIGHTRED);
	puthz(15, 160, "限载", 16, 16, LIGHTRED);
	settextstyle(2, 0, 6);
	puthz(70, 160, "人", 16, 16, LIGHTRED);
	setcolor(LIGHTRED);
	outtextxy(50, 157, "18");
	puthz(15, 180, "限重", 16, 16, LIGHTRED);
	outtextxy(50, 177, "1350kg");
	puthz(15, 220, "紧急求助电话：", 16, 16, GREEN);
	settextstyle(0, 0, 2);
	setcolor(GREEN);
	outtextxy(15, 250, "963333");
	setcolor(CYAN);
	rectangle(0,0,120,35);      //说明书框 
	puthz(5,5, "使用说明", 24, 29, GREEN);
	puthz(180, 3, "一号梯", 16, 20, DARKGRAY);  //一号梯按键 
	stairbutton(290, 60, "12", q->liftL.path[12]);  //待修正，此处应是path判断颜色
	stairbutton(290, 90, "11", q->liftL.path[11]);
	stairbutton(290, 120, "10", q->liftL.path[10]);
	stairbutton(290, 150, "9", q->liftL.path[9]);
	stairbutton(290, 180, "8", q->liftL.path[8]);
	stairbutton(290, 210, "7", q->liftL.path[7]);
	stairbutton(290, 240, "6", q->liftL.path[6]);
	stairbutton(290, 270, "5", q->liftL.path[5]);
	stairbutton(290, 300, "4", q->liftL.path[4]);
	stairbutton(290, 330, "3", q->liftL.path[3]);
	stairbutton(290, 360, "2", q->liftL.path[2]);
	stairbutton(290, 390, "1", q->liftL.path[1]);
	stairbutton(290, 420, "-1", q->liftL.path[0]);
	puthz(400, 3, "二号梯", 16, 20, DARKGRAY);    //二号梯按键 
	stairbutton(350, 60, "12", q->liftR.path[12]);
	stairbutton(350, 90, "11", q->liftR.path[11]);
	stairbutton(350, 120, "10", q->liftR.path[10]);
	stairbutton(350, 150, "9", q->liftR.path[9]);
	stairbutton(350, 180, "8", q->liftR.path[8]);
	stairbutton(350, 210, "7", q->liftR.path[7]);
	stairbutton(350, 240, "6", q->liftR.path[6]);
	stairbutton(350, 270, "5", q->liftR.path[5]);
	stairbutton(350, 300, "4", q->liftR.path[4]);
	stairbutton(350, 330, "3", q->liftR.path[3]);
	stairbutton(350, 360, "2", q->liftR.path[2]);
	stairbutton(350, 390, "1", q->liftR.path[1]);
	settextstyle(4, 0, 1);                             //楼层数字
	outtextxy(530, 50, "12");
	outtextxy(530, 75, "11");
	outtextxy(530, 100, "10");
	outtextxy(530, 125, "9");
	outtextxy(530, 150, "8");
	outtextxy(530, 175, "7");
	outtextxy(530, 200, "6");
	outtextxy(530, 225, "5");
	outtextxy(530, 250, "4");
	outtextxy(530, 275, "3");
	outtextxy(530, 300, "2");
	outtextxy(530, 325, "1");
	outtextxy(530, 350, "-1");
	itoa(q->liftL.cur, a, 10);
	itoa(q->liftR.cur, b, 10);
	settextstyle(4, 0, 2);
	setcolor(RED);
	outtextxy(275, 20, a);                                   //一号梯楼层 
	outtextxy(345, 20, b);                                   //二号梯楼层 
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	line(190, 29, 250, 29);
	line(390, 29, 450, 29);
	cable(1, 390 - q->liftL.cur * 30);							//左缆绳
	cable(0, 390 - q->liftR.cur * 30);							//右缆绳
	if (q->liftL.cur == -1)             //画一号梯 
	{
		rectangle(190, 390, 250, 450);
		uparrow(205, 392, BLUE);
		downarrow(235, 412, BLUE);
	}
	else
	{
		rectangle(190, 420 - q->liftL.cur * 30 - 30, 250, 420 - q->liftL.cur * 30 + 30);
		uparrow(205, 420 - q->liftL.cur * 30 - 28, q->liftL.condition);
		downarrow(235, 420 - q->liftL.cur * 30 - 8, q->liftL.condition);
	}
	rectangle(390, 390 - (q->liftR.cur - 1) * 30 - 30, 450, 390 - (q->liftR.cur - 1) * 30 + 30);  //画二号梯
	uparrow(405, 390 - (q->liftR.cur - 1) * 30 - 28, q->liftR.condition);
	downarrow(435, 390 - (q->liftR.cur - 1) * 30 - 8, q->liftR.condition);
	setfillstyle(1, CYAN);
	circle(590, 430, 20);      //画操作按钮
	floodfill(590, 430, DARKGRAY);
	puthz(560, 390, "外部按钮", 16, 16, BLUE);
	sbutton(570, 90, q->call[11]);         //上按钮 
	sbutton(570, 115, q->call[10]);
	sbutton(570, 140, q->call[9]);
	sbutton(570, 165, q->call[8]);
	sbutton(570, 190, q->call[7]);
	sbutton(570, 215, q->call[6]);
	sbutton(570, 240, q->call[5]);
	sbutton(570, 265, q->call[4]);
	sbutton(570, 290, q->call[3]);
	sbutton(570, 315, q->call[2]);
	sbutton(570, 340, q->call[1]);
	sbutton(570, 365, q->call[0]);
	xbutton(600, 65, q->call[12]);        //下按钮 
	xbutton(600, 90, q->call[11]);
	xbutton(600, 115, q->call[10]);
	xbutton(600, 140, q->call[9]);
	xbutton(600, 165, q->call[8]);
	xbutton(600, 190, q->call[7]);
	xbutton(600, 215, q->call[6]);
	xbutton(600, 240, q->call[5]);
	xbutton(600, 265, q->call[4]);
	xbutton(600, 290, q->call[3]);
	xbutton(600, 315, q->call[2]);
	xbutton(600, 340, q->call[1]);

}
