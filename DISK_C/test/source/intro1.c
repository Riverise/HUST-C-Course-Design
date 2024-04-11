#include "intro1.h"
#include"hz.h"
#include"quitbutt.h"
#include<graphics.h>
#include<mouse.h>
#include<stdlib.h>
int intro1()
{
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	setbkcolor(WHITE);
	quitbutt();
	setcolor(GREEN);
	rectangle(575, 445, 640, 480);
	settextstyle(1, 0, 0);
	outtextxy(585, 445, "GO");

	settextstyle(1, 0, 2);
	setcolor(DARKGRAY);
	puthz(240, 10, "使用指南", 32, 33, 12);
	outtextxy(5, 40, "1.");
	puthz(32, 45, "本模式为乘客模式，即以一名乘客的视角展示此电梯，体现电梯的细节。", 16, 17, DARKGRAY);
	outtextxy(5, 70, "2.");
	puthz(32, 75, "你可以通过鼠标点击来模拟现实中手指按下按钮。", 16,17,DARKGRAY);
	outtextxy(5, 125, "3.");
	puthz(32, 130, "智能双电梯调度的具体原则，将在全局模式中体现", 16, 17, DARKGRAY);
	outtextxy(5, 155, "4.");
	puthz(32, 160, "在这个过程中，你可以在合适的位置点击右上角的退出按钮回到主界面", 16, 17, DARKGRAY);
	outtextxy(5, 210, "5.");
	puthz(32, 215, "如果阅读完本说明，请点击右下角按钮进入下一个界面", 16, 17, DARKGRAY);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(575, 0, 640, 35) == 2)
		{
			MouseS = 1;
		}
		else if (mouse_press(575, 0, 640, 35) == 1)
		{
			return 1;
		}
		else if (mouse_press(575, 445, 640, 480) == 2)
		{
			MouseS = 1;
		}
		else if (mouse_press(575, 445, 640, 480) == 1)
		{
			return 3;
		}
		else
			MouseS = 0;
	}
}
