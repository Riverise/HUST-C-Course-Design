#include "intro2.h"
#include "hz.h"
#include "quitbutt.h"
#include <graphics.h>
#include <mouse.h>

int intro2()
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
	puthz(32, 45, "此模式为全局模式，以上帝视角查看所有楼层间电梯的运行情况，在不同的情境中体现电梯的调度逻辑", 16, 17, DARKGRAY);
	outtextxy(5, 92, "2.");
	puthz(32, 97, "画面正中间两行数字代表楼层，若某层为绿表明电梯会在此楼停顿。右边两行数字若变绿，表示该楼有人呼叫，圈内尖头向上表示该楼呼上，向下反之。", 16, 17, DARKGRAY);
	outtextxy(5, 145, "3.");
	puthz(32, 150, "点击右上角红色按钮可以返回至主界面，以便体验乘客模式。", 16, 17, DARKGRAY);
	outtextxy(5, 175, "4.");
	puthz(32, 180, "点击左上角的绿色按钮可以再次查看此使用说明", 16, 17, DARKGRAY);
	outtextxy(5, 210, "5.");
	puthz(32, 215, "电梯调度的模拟从右下角绿色按钮开始，点击则进入呼叫界面，选择合适的楼层按上或下，对应于现实生活中的某楼呼上某楼某楼呼下，点击确定后即可返回。电梯会对楼层的呼应做出反应，白色方块（对应电梯）会开始移动，到达对应楼层会出现如“某楼向上（下）的操作”，选择合适的楼层则会在几楼停顿（如果按错可以右键单击取消之）。", 16, 17, DARKGRAY);
	outtextxy(5, 343, "6.");
	puthz(32, 348, "在电梯运行过程中可以随时按返回键、操作说明键与外部按钮键，体会本产品的功能。", 16, 17, DARKGRAY);
	outtextxy(5, 390, "7");
	puthz(32, 395,"为了更好地了解电梯的运行情况，电梯在运行后会通过显色的方式表征其上次运行方向" , 16, 17, DARKGRAY);

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(575, 0, 640, 35) == 2)  //unclick on quit
		{
			MouseS = 1;
		}
		else if (mouse_press(575, 0, 640, 35) == 1)
		{
			return 1;
		}
		else if (mouse_press(575, 445, 640, 480) == 2) //unclick on go
		{
			MouseS = 1;
		}
		else if (mouse_press(575, 445, 640, 480) == 1)
		{
			return 5;
		}
		else
			MouseS = 0;
	}
}