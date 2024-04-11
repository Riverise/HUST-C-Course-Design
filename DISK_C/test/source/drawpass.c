#include "drawpass.h" 
#include "quitbutt.h"
#include "liftlist.h"
#include "anipass.h"
#include <mouse.h>
#include <graphics.h>

void initview()//initial scene of button
{
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	setbkcolor(LIGHTGRAY);
	quitbutt();
	setfillstyle(SOLID_FILL, BROWN);
	bar(165, 150, 265, 330);
	bar(380, 150, 480, 330);
	setfillstyle(SOLID_FILL, WHITE);
	bar(185, 180, 245, 300);
	bar(400, 210, 460, 270);
	setfillstyle(SOLID_FILL, BLACK);
	setcolor(BLACK);
	sector(215, 165, 0, 360, 10, 10);
	sector(430, 165, 0, 360, 10, 10);
	setcolor(WHITE);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(213, 165, "1");
	outtextxy(425, 165, "2");
	setlinestyle(0, 0, 3);
	setcolor(BLACK);
	//电梯一楼外部图
	line(185, 240, 245, 240);
	//2号电梯
	line(430, 255, 430, 225);
	line(430, 225, 425, 230);
	line(430, 225, 435, 230);
	//1号电梯
	line(215, 250, 215, 280);
	line(215, 230, 215, 200);
	line(215, 200, 210, 205);
	line(215, 200, 220, 205);
	line(215, 280, 210, 275);
	line(215, 280, 220, 275);
}

void insideview(int num)
{
	clrmous(MouseX, MouseY);
	cleardevice();
	setfillstyle(SOLID_FILL, BLACK);
	bar(0, 0, 640, 480);
	//quitbutt();
	setfillstyle(SOLID_FILL, WHITE);
	bar(215, 0, 430, 480);
	setfillstyle(SOLID_FILL, BLACK);
	//十二个电梯按钮
	setcolor(BLACK);
	sector(268, 30, 0, 360, 15, 15);//11
	sector(268, 90, 0, 360, 15, 15);//9
	sector(268, 150, 0, 360, 15, 15);//7
	sector(268, 210, 0, 360, 15, 15);//5
	sector(268, 270, 0, 360, 15, 15);//3
	sector(268, 330, 0, 360, 15, 15);//1
	if (num == 1)
		sector(268, 450, 0, 360, 15, 15);//-1楼
	sector(376, 30, 0, 360, 15, 15);//12
	sector(376, 90, 0, 360, 15, 15);//10
	sector(376, 150, 0, 360, 15, 15);//8
	sector(376, 210, 0, 360, 15, 15);//6
	sector(376, 270, 0, 360, 15, 15);//4
	sector(376, 330, 0, 360, 15, 15);//2
	setcolor(WHITE);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(263, 30, "11");
	outtextxy(263, 90, "9");
	outtextxy(263, 150, "7");
	outtextxy(263, 210, "5");
	outtextxy(263, 270, "3");
	outtextxy(263, 330, "1");
	if (num == 0)
		outtextxy(263, 450, "-1");// why "-1" cannot be displayed
	outtextxy(371, 30, "12");
	outtextxy(371, 90, "10");
	outtextxy(371, 150, "8");
	outtextxy(371, 210, "6");
	outtextxy(371, 270, "4");
	outtextxy(371, 330, "2");
	setfillstyle(SOLID_FILL, RED);
	sector(376, 450, 0, 360, 15, 15);//报警按钮
	setfillstyle(SOLID_FILL, GREEN);
	sector(376, 390, 0, 360, 15, 15);//关门按钮
	sector(268, 390, 0, 360, 15, 15);//开门按钮
	setlinestyle(SOLID_LINE, 0, 1);//开门按钮的绘制
	setcolor(WHITE);
	moveto(266, 395);
	lineto(266, 385);
	lineto(263, 390);
	lineto(266, 395);
	moveto(270, 395);
	lineto(270, 385);
	lineto(273, 390);
	lineto(270, 395);
	//关门按钮的绘制
	line(376, 385, 376, 395);
	moveto(374, 390);
	lineto(371, 395);
	lineto(371, 385);
	lineto(374, 390);
	moveto(378, 390);
	lineto(381, 395);
	lineto(381, 385);
	lineto(378, 390);
	//警报按钮的绘制
}

void light0()
{
	setfillstyle(SOLID_FILL, YELLOW);
	setcolor(YELLOW);
	sector(268, 450, 0, 360, 15, 15);
	setcolor(BLACK);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(263, 450, "-1");
	delay(500);
	setfillstyle(SOLID_FILL, BLACK);
	setcolor(BLACK);
	sector(268, 450, 0, 360, 15, 15);
	setcolor(WHITE);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(263, 450, "-1");
	delay(500);
}
void light1()
{
	setfillstyle(SOLID_FILL, YELLOW);
	setcolor(YELLOW);
	sector(268, 330, 0, 360, 15, 15);
	setcolor(BLACK);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(263, 330, "1");
	delay(500);
	setfillstyle(SOLID_FILL, BLACK);
	setcolor(BLACK);
	sector(268, 330, 0, 360, 15, 15);
	setcolor(WHITE);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(263, 330, "1");
	delay(500);
}
void light2()
{
	setfillstyle(SOLID_FILL, YELLOW);
	setcolor(YELLOW);
	sector(376, 330, 0, 360, 15, 15);
	setcolor(BLACK);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(371, 330, "2");
	delay(500);
	setfillstyle(SOLID_FILL, BLACK);
	setcolor(BLACK);
	sector(376, 330, 0, 360, 15, 15);
	setcolor(WHITE);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(371, 330, "2");
	delay(500);
}
void light3()
{
	setfillstyle(SOLID_FILL, YELLOW);
	setcolor(YELLOW);
	sector(268, 270, 0, 360, 15, 15);
	setcolor(BLACK);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(263, 330, "3");
	delay(500);
	setfillstyle(SOLID_FILL, BLACK);
	setcolor(BLACK);
	sector(268, 270, 0, 360, 15, 15);
	setcolor(WHITE);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(263, 330, "3");
	delay(500);
}
void light4()
{
	setfillstyle(SOLID_FILL, YELLOW);
	setcolor(YELLOW);
	sector(376, 270, 0, 360, 15, 15);
	setcolor(BLACK);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(371, 270, "4");
	delay(500);
	setfillstyle(SOLID_FILL, BLACK);
	setcolor(BLACK);
	sector(376, 270, 0, 360, 15, 15);
	setcolor(WHITE);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(371, 270, "4");
	delay(500);
}
void light5()
{
	setfillstyle(SOLID_FILL, YELLOW);
	setcolor(YELLOW);
	sector(268, 210, 0, 360, 15, 15);
	setcolor(BLACK);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(263, 330, "5");
	delay(500);
	setfillstyle(SOLID_FILL, BLACK);
	setcolor(BLACK);
	sector(268, 210, 0, 360, 15, 15);
	setcolor(WHITE);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(263, 330, "5");
	delay(500);
}
void light6()
{
	setfillstyle(SOLID_FILL, YELLOW);
	setcolor(YELLOW);
	sector(376, 210, 0, 360, 15, 15);
	setcolor(BLACK);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(371, 330, "6");
	delay(500);
	setfillstyle(SOLID_FILL, BLACK);
	setcolor(BLACK);
	sector(376, 210, 0, 360, 15, 15);
	setcolor(WHITE);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(371, 330, "6");
	delay(500);
}
void light7()
{
	setfillstyle(SOLID_FILL, YELLOW);
	setcolor(YELLOW);
	sector(268, 150, 0, 360, 15, 15);
	setcolor(BLACK);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(263, 330, "7");
	delay(500);
	setfillstyle(SOLID_FILL, BLACK);
	setcolor(BLACK);
	sector(268, 150, 0, 360, 15, 15);
	setcolor(WHITE);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(371, 330, "7");
	delay(500);
}
void light8()
{
	setfillstyle(SOLID_FILL, YELLOW);
	setcolor(YELLOW);
	sector(376, 150, 0, 360, 15, 15);
	setcolor(BLACK);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(371, 330, "8");
	delay(500);
	setfillstyle(SOLID_FILL, BLACK);
	setcolor(BLACK);
	sector(376, 150, 0, 360, 15, 15);
	setcolor(WHITE);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(371, 330, "8");
	delay(500);
}
void light9()
{
	setfillstyle(SOLID_FILL, YELLOW);
	setcolor(YELLOW);
	sector(268, 90, 0, 360, 15, 15);
	setcolor(BLACK);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(263, 330, "9");
	delay(500);
	setfillstyle(SOLID_FILL, BLACK);
	setcolor(BLACK);
	sector(268, 90, 0, 360, 15, 15);
	setcolor(WHITE);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(263, 330, "9");
	delay(500);
}
void light10()
{
	setfillstyle(SOLID_FILL, YELLOW);
	setcolor(YELLOW);
	sector(376, 90, 0, 360, 15, 15);
	setcolor(BLACK);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(371, 330, "10");
	delay(500);
	setfillstyle(SOLID_FILL, BLACK);
	setcolor(BLACK);
	sector(376, 90, 0, 360, 15, 15);
	setcolor(WHITE);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(371, 330, "10");
	delay(500);
}
void light11()
{
	setfillstyle(SOLID_FILL, YELLOW);
	setcolor(YELLOW);
	sector(268, 30, 0, 360, 15, 15);
	setcolor(BLACK);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(263, 330, "11");
	delay(500);
	setfillstyle(SOLID_FILL, BLACK);
	setcolor(BLACK);
	sector(268, 30, 0, 360, 15, 15);
	setcolor(WHITE);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(263, 330, "11");
	delay(500);
}
void light12()
{
	setfillstyle(SOLID_FILL, YELLOW);
	setcolor(YELLOW);
	sector(376, 30, 0, 360, 15, 15);
	setcolor(BLACK);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(371, 330, "12");
	delay(500);
	setfillstyle(SOLID_FILL, BLACK);
	setcolor(BLACK);
	sector(376, 30, 0, 360, 15, 15);
	setcolor(WHITE);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(371, 330, "12");
	delay(500);
}

void upward()//向上的箭头
{


	setfillstyle(SOLID_FILL, WHITE);
	bar(500, 150, 600, 250);
	setcolor(RED);
	line(550, 225, 550, 175);
	line(550, 175, 530, 195);
	line(550, 175, 570, 195);
}
void downward()//向下的箭头
{
	setfillstyle(SOLID_FILL, WHITE);
	bar(500, 150, 600, 250);
	setcolor(RED);
	line(550, 225, 550, 175);
	line(550, 225, 570, 205);
	line(550, 225, 530, 205);
}
void figure(int present)
{

	switch (present)
	{
	case 1:
		setfillstyle(SOLID_FILL, WHITE);
		bar(500, 250, 600, 350);
		setcolor(BLACK);
		line(550, 275, 550, 325);
		break;

	case 2:
		setfillstyle(SOLID_FILL, WHITE);
		bar(500, 250, 600, 350);
		setcolor(BLACK);
		line(520, 275, 580, 275);
		line(580, 275, 580, 300);
		line(580, 300, 520, 300);
		line(520, 300, 520, 325);
		line(520, 325, 580, 325);
		break;

	case 3:
		setfillstyle(SOLID_FILL, WHITE);
		bar(500, 250, 600, 350);
		setcolor(BLACK);
		line(570, 275, 570, 325);
		line(530, 275, 570, 275);
		line(530, 300, 570, 300);
		line(530, 325, 570, 325);
		break;

	case 4:
		setfillstyle(SOLID_FILL, WHITE);
		bar(500, 250, 600, 350);
		setcolor(BLACK);
		line(525, 275, 525, 300);
		line(525, 300, 575, 300);
		line(550, 275, 550, 325);
		break;

	case 5:
		setfillstyle(SOLID_FILL, WHITE);
		bar(500, 250, 600, 350);
		setcolor(BLACK);
		line(560, 275, 530, 275);
		line(530, 275, 530, 300);
		line(530, 300, 560, 300);
		line(560, 300, 560, 325);
		line(560, 325, 530, 325);
		break;

	case 6:
		setfillstyle(SOLID_FILL, WHITE);
		bar(500, 250, 600, 350);
		setcolor(BLACK);
		line(530, 275, 560, 275);
		line(530, 275, 530, 325);
		line(530, 325, 560, 325);
		line(560, 325, 560, 300);
		line(560, 300, 530, 300);
		break;

	case 7:
		setfillstyle(SOLID_FILL, WHITE);
		bar(500, 250, 600, 350);
		setcolor(BLACK);
		line(530, 275, 560, 275);
		line(560, 275, 560, 325);
		break;

	case 8:
		setfillstyle(SOLID_FILL, WHITE);
		bar(500, 250, 600, 350);
		setcolor(BLACK);
		line(560, 275, 530, 275);
		line(530, 275, 530, 325);
		line(530, 325, 560, 325);
		line(560, 325, 560, 300);
		line(560, 300, 530, 300);
		line(560, 275, 560, 300);
		break;

	case 9:
		setfillstyle(SOLID_FILL, WHITE);
		bar(500, 250, 600, 350);
		setcolor(BLACK);
		line(530, 275, 560, 275);
		line(530, 300, 560, 300);
		line(560, 275, 560, 325);
		line(530, 275, 530, 300);
		line(530, 325, 560, 325);
		break;

	case 10:
		setfillstyle(SOLID_FILL, WHITE);
		bar(500, 250, 600, 350);
		setcolor(BLACK);
		line(525, 275, 525, 325);
		line(550, 285, 550, 315);
		line(550, 315, 580, 315);
		line(580, 315, 580, 285);
		line(580, 285, 550, 285);
		break;
		//500,250,600,350
	case 11:
		setfillstyle(SOLID_FILL, WHITE);
		bar(500, 250, 600, 350);
		setcolor(BLACK);
		line(525, 275, 525, 325);
		line(560, 275, 560, 325);
		break;

	case 12:
		setfillstyle(SOLID_FILL, WHITE);
		bar(500, 250, 600, 350);
		setcolor(BLACK);
		line(525, 275, 525, 325);
		line(535, 275, 560, 275);
		line(560, 275, 560, 300);
		line(560, 300, 535, 300);
		line(535, 300, 535, 325);
		line(535, 325, 560, 325);
		break;

	case -1:
		setfillstyle(SOLID_FILL, WHITE);
		bar(500, 250, 600, 350);
		setcolor(BLACK);
		line(550, 275, 550, 325);
		line(525, 300, 545, 300);
		break;

	}
	

}

int outside()//其他楼层电梯外部按钮
{
	//drawpage part
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, BLACK);
	bar(0, 0, 640, 480);
	quitbutt();
	setfillstyle(SOLID_FILL, RED);
	bar(215, 20, 430, 460);
	setfillstyle(SOLID_FILL, BLUE);
	bar(270, 110, 370, 210);
	bar(270, 330, 370, 430);
	setlinestyle(0, 0, 3);
	setcolor(WHITE);
	line(320, 140, 320, 200);
	line(300, 160, 320, 140);
	line(340, 160, 320, 140);
	line(320, 350, 320, 420);
	line(300, 390, 320, 420);
	line(340, 390, 320, 420);

	
		while (1)
		{
			newmouse(&MouseX, &MouseY, &press);
			if (mouse_press(270, 110, 370, 210) == 2 ||
				mouse_press(270, 330, 370, 430) == 2 || 
				mouse_press(575, 0, 640, 35) == 2)
					MouseS = 1;

			else if (mouse_press(270, 110, 370, 210) == 1)
			{
				doorsopen();
				return liftselect();				
			}

			else if (mouse_press(270, 330, 370, 430) == 1)
			{
				doorsopen();
				return liftselect();				
			}
			else if (mouse_press(575, 0, 640, 35) == 1)
			{
				return 1;
			}
			else
			{
				MouseS = 0;
			}


		}
	

}
