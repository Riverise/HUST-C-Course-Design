#include "anipass.h"
#include "quitbutt.h"
#include "drawpass.h"
#include <graphics.h>
#include <mouse.h>
#include "hz.h"
#include<time.h>
#include<ERRNO.H>
#include<stdio.h>


void doorsopen()  //open animation of liftdoor
{
	int i = 1;
	
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, WHITE);
	bar(0, 0, 640, 480);
	quitbutt();
	floodfill(1, 1, BLACK);
	setfillstyle(1, LIGHTGRAY);
	bar(40, 40, 280, 440);
	bar(360, 40, 600, 440);
	setfillstyle(SOLID_FILL, BLACK);
	setcolor(BLACK);
	sector(160, 20, 0, 360, 10, 10);
	sector(480, 20, 0, 360, 10, 10);
	setcolor(WHITE);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(155, 15, "1");
	outtextxy(475, 15, "2");
	for (i = 1; i < 20; i++)
	{
		setfillstyle(1, WHITE);
		bar(160 - 5 * i, 41, 160 + 5 * i, 439);
		bar(480 - 5 * i, 41, 480 + 5 * i, 439);
		setcolor(BLACK);
		line(160, 40, 160, 440);
		line(480, 40, 480, 440);
		setcolor(BLACK);
		rectangle(40, 40, 280, 440);
		rectangle(360, 40, 600, 440);
		delay(100);
	}
}

void doorsclose()
{
	int i = 0;

	cleardevice();
	quitbutt();
	setfillstyle(SOLID_FILL, WHITE);
	bar(0, 0, 640, 480);
	floodfill(1, 1, BLACK);
	//cleardevice();
	setfillstyle(1, WHITE);
	bar(200, 50, 440, 450);
	setcolor(BLACK);
	line(320, 50, 320, 450);
	for (i = 1; i < 21; i++)
	{
		setfillstyle(1, LIGHTGRAY);
		bar(200, 51, 220 + 5 * i, 449);
		bar(420 - 5 * i, 51, 440, 449);
		setcolor(BLACK);
		line(320, 50, 320, 450);
		setcolor(BLACK);
		rectangle(200, 50, 440, 450);
		delay(100);
	}
}

void singleopen()
{
	int i = 0;
	cleardevice();
	quitbutt();
	setfillstyle(SOLID_FILL, BLACK);
	bar(0, 0, 640, 480);
	floodfill(1, 1, BLACK);
	//cleardevice();
	setfillstyle(1, LIGHTGRAY);
	bar(200, 50, 440, 450);
	setcolor(BLACK);
	for (i = 1; i < 20; i++)
	{

		setfillstyle(1, WHITE);
		bar(320 - 5 * i, 51, 320 + 5 * i, 449);
		setcolor(BLACK);
		line(320, 50, 320, 450);
		delay(100);

	}
}

void singleclose()
{
		int i = 0;
		cleardevice();
		quitbutt();
		setfillstyle(SOLID_FILL, WHITE);
		bar(0, 0, 640, 480);
		floodfill(1, 1, BLACK);
		//cleardevice();
		setfillstyle(1, WHITE);
		bar(200, 50, 440, 450);
		setcolor(BLACK);
		line(320, 50, 320, 450);
		for (i = 1; i < 21; i++)
		{
			setfillstyle(1, LIGHTGRAY);
			bar(200, 51, 220 + 5 * i, 449);
			bar(420 - 5 * i, 51, 440, 449);
			setcolor(BLACK);
			line(320, 50, 320, 450);
			setcolor(BLACK);
			rectangle(200, 50, 440, 450);
			delay(100);
		}

	
}

int numvary(int *now,int want)
{
	
	while ((*now) != want)
	{
		//newmouse(&MouseX, &MouseY, &press);
		if ((*now) < want)
		{
			upward();
			(*now)++;
			figure(*now);
			delay(700);
		}
		if ((*now) > want)
		{

			downward();
			(*now)--;
			figure(*now);
			delay(700);
		}
		/*if (mouse_press(575, 0, 640, 35) == 2)//unclick on quit
		{
			MouseS = 1;
		}
		else if (mouse_press(575, 0, 640, 35) == 1)
		{
			return 1;
		}
		else
		{
			MouseS = 0;
		}*/
	}	
	
		setfillstyle(SOLID_FILL, WHITE);
		bar(500, 150, 600, 250);
	
	return 0;
}

char* zcinput(int x, int y, int l, int flag)           //x,y为左下角,flag=0:正常输出，flag=1：输出* 
{
	char p[20], px[20], py[20];
	char *ch;
	int i = 0, j;
	ch = py;
	settextjustify(0, 0);
	settextstyle(1, 0, 2);
	setcolor(DARKGRAY);
	clrmous(MouseX, MouseY);
	delay(100);
	setfillstyle(1, WHITE);
	bar(x, y - 20, x + l, y + 3);
	while (bioskey(1))//清除键盘缓冲区  防止误输入
	{
		bioskey(0);
	}
	if ((ch = (char*)malloc(200)) == NULL)
	{
		outtextxy(x, y, "no memory");
		return 0;
	}
	setfillstyle(1, WHITE);
	while (1)
	{
		j = bioskey(0);
		if (j != 0x0e08 && j != 0x1c0d)
		{
			ch[i] = j;
			px[i] = '*';
			i++;
			ch[i] = '\0';
			px[i] = '\0';
		}
		else if (j == 0x1c0d)
			break;     //退出输入法
		else
		{
			i--;
			ch[i] = '\0';
			px[i] = '\0';
		}
		bar(x, y - 20, x + l, y + 3);
		if (flag == 0)
			outtextxy(x, y, ch);
		else if (flag == 1)
		{
			settextstyle(0, 0, 2);
			outtextxy(x, y, px);
		}
	}
	strcpy(p, ch);
	free(ch);
	delay(120);
	//bar(x,y-20,x+100,y+3);
	settextjustify(0, 2);
	return p;
}




void yuanyin(int x1, int y1, int x2, int y2, char *s, int a)//a表示间距
{
	setfillstyle(1, 12);
	bar(x1, y1, x2, y2);
	setcolor(7);
	rectangle(x1, y1, x2, y2);
	setcolor(15);
	circle(x1 + 10, y1 + 17, 4);
	setfillstyle(1, 15);
	floodfill(x1 + 10, y1 + 17, 15);
	puthz(x1 + 15, y1 + 6, s, 24, a, 8);
}

int warning()
{
	FILE *fp;
	int i;
	DATA *per;
	DATA jilu;
	per = &jilu;
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	setfillstyle(1, 9);
	bar(0, 0, 640, 80);         //上 
	setfillstyle(1, 3);
	bar(0, 80, 240, 480);       //左下 
	setfillstyle(1, 15);
	bar(240, 80, 640, 480);      //右下 
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 3);
	line(0, 80, 640, 80);
	line(240, 80, 240, 480);
	setfillstyle(1, 14);
	setcolor(15);
	puthz(445, 15, "维护日志", 32, 40, 15);
	settextstyle(3, 0, 3);
	outtextxy(445, 45, "Maintenance log");
	puthz(20, 100, "输入时间：", 24, 24, 8);                //输入区 
	setfillstyle(1, WHITE);
	bar(15, 135, 70, 160);
	puthz(72, 140, "年", 24, 24, 6);
	bar(100, 135, 125, 160);
	puthz(127, 140, "月", 24, 24, 6);
	bar(155, 135, 180, 160);
	puthz(182, 140, "日", 24, 24, 6);
	setcolor(7);
	rectangle(4, 130, 210, 165);
	puthz(20, 175, "选择原因：", 24, 24, 8);
	yuanyin(10, 200, 120, 230, "异常停电", 24);
	yuanyin(125, 200, 235, 230, "异常响动", 24);
	yuanyin(10, 240, 120, 270, "层门故障", 24);
	yuanyin(125, 240, 235, 270, "梯门故障", 24);
	yuanyin(10, 280, 120, 310, "驱动故障", 24);
	yuanyin(125, 280, 235, 310, "急停故障", 24);
	yuanyin(10, 320, 235, 350, "楼层位置计算器错误", 24);
	yuanyin(10, 360, 235, 390, "热敏开关保护", 34);
	yuanyin(10, 400, 235, 430, "轿厢速度数据异常", 25);
	setcolor(7);
	setlinestyle(0, 0, 1);
	rectangle(180, 445, 230, 470);
	setfillstyle(1, 10);
	floodfill(210, 453, 7);
	setcolor(9);
	settextstyle(0, 0, 2);
	outtextxy(190, 450, "OK");
	puthz(370, 90, "历史记录", 24, 34, 7);                  //数据记录区 
	setcolor(8);
	setlinestyle(3, 0, 3);
	line(240, 115, 640, 115);
	setfillstyle(1, RED);
	bar(20, 20, 80, 40);
	setcolor(WHITE);
	settextstyle(3, 0, 3);
	outtextxy(30, 13, "EXIT");

	if ((fp = fopen(".\\error.txt", "rt")) == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	for (i = 0; i < 12; i++)
	{
		strcpy(per->year, NULL);
		fscanf(fp, "%s %s %s %s\n", per->year, per->month, per->day, per->reason);
		if (strcmp(per->year, NULL) == 0)
			break;
		else
		{
			settextstyle(4, 0, 1);
			setcolor(6);
			outtextxy(260, 120 + 30 * i, per->year);
			puthz(310, 125 + 30 * i, "年", 16, 16, 6);
			outtextxy(330, 120 + 30 * i, per->month);
			puthz(340, 125 + 30 * i, "月", 16, 16, 6);
			outtextxy(360, 120 + 30 * i, per->day);
			puthz(385, 125 + 30 * i, "日", 16, 16, 6);
			puthz(450, 125 + 30 * i, per->reason, 16, 16, 6);
			setcolor(8);
			line(240, 145 + 30 * i, 640, 145 + 30 * i);
		}

	}
	fclose(fp);
	//drawrepg();
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(20, 20, 80, 40) == 2)//返回 
			MouseS = 1;
		else if (mouse_press(20, 20, 80, 40) == 1)
			return 0;
		else if (mouse_press(15, 135, 70, 160) == 2)        //年输入框
			MouseS = 1;
		else if (mouse_press(15, 135, 70, 160) == 1)
			strcpy(per->year, zcinput(20, 155, 45, 0));
		else if (mouse_press(100, 135, 125, 160) == 2)        //月输入框
			MouseS = 1;
		else if (mouse_press(100, 135, 125, 160) == 1)
			strcpy(per->month, zcinput(105, 155, 20, 0));
		else if (mouse_press(155, 135, 180, 160) == 2)        //日输入框
			MouseS = 1;
		else if (mouse_press(155, 135, 180, 160) == 1)
			strcpy(per->day, zcinput(160, 155, 20, 0));
		else if (mouse_press(10, 200, 120, 230) == 2)                   //异常停电 
			MouseS = 1;
		else if (mouse_press(10, 200, 120, 230) == 1)
		{
			strcpy(per->reason, "异常停电");
			setcolor(GREEN);
			sector(20, 217, 0, 360, 4, 4);
		}
		else if (mouse_press(125, 200, 235, 230) == 2)                  //异常响动 
			MouseS = 1;
		else if (mouse_press(125, 200, 235, 230) == 1)
		{
			strcpy(per->reason, "异常响动");
			setcolor(GREEN);
			sector(135, 217, 0, 360, 4, 4);
		}
		else if (mouse_press(10, 240, 120, 270) == 2)                  //层门故障 
			MouseS = 1;
		else if (mouse_press(10, 240, 120, 270) == 1)
		{
			strcpy(per->reason, "层门故障");
			setcolor(GREEN);
			sector(20, 257, 0, 360, 4, 4);
		}
		else if (mouse_press(125, 240, 235, 270) == 2)                  //梯门故障 
			MouseS = 1;
		else if (mouse_press(125, 240, 235, 270) == 1)
		{
			strcpy(per->reason, "梯门故障");
			setcolor(GREEN);
			sector(135, 257, 0, 360, 4, 4);
		}
		else if (mouse_press(10, 280, 120, 310) == 2)                  //驱动故障 
			MouseS = 1;
		else if (mouse_press(10, 280, 120, 310) == 1)
		{
			strcpy(per->reason, "驱动故障");
			setcolor(GREEN);
			sector(20, 297, 0, 360, 4, 4);
		}
		else if (mouse_press(125, 280, 235, 310) == 2)                  //急停故障 
			MouseS = 1;
		else if (mouse_press(125, 280, 235, 310) == 1)
		{
			strcpy(per->reason, "急停故障");
			setcolor(GREEN);
			sector(135, 297, 0, 360, 4, 4);
		}
		else if (mouse_press(10, 320, 235, 350) == 2)                  //楼层位置计算器错误 
			MouseS = 1;
		else if (mouse_press(10, 320, 235, 350) == 1)
		{
			strcpy(per->reason, "楼层位置计算器错误");
			setcolor(GREEN);
			sector(20, 337, 0, 360, 4, 4);
		}
		else if (mouse_press(10, 360, 235, 390) == 2)                  //热敏开关保护 
			MouseS = 1;
		else if (mouse_press(10, 360, 235, 390) == 1)
		{
			strcpy(per->reason, "热敏开关保护");
			setcolor(GREEN);
			sector(20, 377, 0, 360, 4, 4);
		}
		else if (mouse_press(10, 400, 235, 430) == 2)                  //轿厢速度数据异常 
			MouseS = 1;
		else if (mouse_press(10, 400, 235, 430) == 1)
		{
			strcpy(per->reason, "轿厢速度数据异常");
			setcolor(GREEN);
			sector(20, 417, 0, 360, 4, 4);
		}
		else if (mouse_press(180, 445, 230, 470) == 2)                   //完成按钮 
			MouseS = 1;
		else if (mouse_press(180, 445, 230, 470) == 1)
		{
			if ((fp = fopen(".\\error.txt", "at+")) == NULL)
			{
				{
					printf("%s\n", strerror(errno));
				}
			}
			fprintf(fp, "%s %s %s %s\n", per->year, per->month, per->day, per->reason);
			fclose(fp);
			return 0;
		}
		else MouseS = 0;
	}
}


