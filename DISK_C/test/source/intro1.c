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
	puthz(240, 10, "ʹ��ָ��", 32, 33, 12);
	outtextxy(5, 40, "1.");
	puthz(32, 45, "��ģʽΪ�˿�ģʽ������һ���˿͵��ӽ�չʾ�˵��ݣ����ֵ��ݵ�ϸ�ڡ�", 16, 17, DARKGRAY);
	outtextxy(5, 70, "2.");
	puthz(32, 75, "�����ͨ���������ģ����ʵ����ָ���°�ť��", 16,17,DARKGRAY);
	outtextxy(5, 125, "3.");
	puthz(32, 130, "����˫���ݵ��ȵľ���ԭ�򣬽���ȫ��ģʽ������", 16, 17, DARKGRAY);
	outtextxy(5, 155, "4.");
	puthz(32, 160, "����������У�������ں��ʵ�λ�õ�����Ͻǵ��˳���ť�ص�������", 16, 17, DARKGRAY);
	outtextxy(5, 210, "5.");
	puthz(32, 215, "����Ķ��걾˵�����������½ǰ�ť������һ������", 16, 17, DARKGRAY);
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
