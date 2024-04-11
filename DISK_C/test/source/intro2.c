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
	puthz(240, 10, "ʹ��ָ��", 32, 33, 12);
	outtextxy(5, 40, "1.");
	puthz(32, 45, "��ģʽΪȫ��ģʽ�����ϵ��ӽǲ鿴����¥�����ݵ�����������ڲ�ͬ���龳�����ֵ��ݵĵ����߼�", 16, 17, DARKGRAY);
	outtextxy(5, 92, "2.");
	puthz(32, 97, "�������м��������ִ���¥�㣬��ĳ��Ϊ�̱������ݻ��ڴ�¥ͣ�١��ұ��������������̣���ʾ��¥���˺��У�Ȧ�ڼ�ͷ���ϱ�ʾ��¥���ϣ����·�֮��", 16, 17, DARKGRAY);
	outtextxy(5, 145, "3.");
	puthz(32, 150, "������ϽǺ�ɫ��ť���Է����������棬�Ա�����˿�ģʽ��", 16, 17, DARKGRAY);
	outtextxy(5, 175, "4.");
	puthz(32, 180, "������Ͻǵ���ɫ��ť�����ٴβ鿴��ʹ��˵��", 16, 17, DARKGRAY);
	outtextxy(5, 210, "5.");
	puthz(32, 215, "���ݵ��ȵ�ģ������½���ɫ��ť��ʼ������������н��棬ѡ����ʵ�¥�㰴�ϻ��£���Ӧ����ʵ�����е�ĳ¥����ĳ¥ĳ¥���£����ȷ���󼴿ɷ��ء����ݻ��¥��ĺ�Ӧ������Ӧ����ɫ���飨��Ӧ���ݣ��Ὺʼ�ƶ��������Ӧ¥�������硰ĳ¥���ϣ��£��Ĳ�������ѡ����ʵ�¥������ڼ�¥ͣ�٣������������Ҽ�����ȡ��֮����", 16, 17, DARKGRAY);
	outtextxy(5, 343, "6.");
	puthz(32, 348, "�ڵ������й����п�����ʱ�����ؼ�������˵�������ⲿ��ť������᱾��Ʒ�Ĺ��ܡ�", 16, 17, DARKGRAY);
	outtextxy(5, 390, "7");
	puthz(32, 395,"Ϊ�˸��õ��˽���ݵ�������������������к��ͨ����ɫ�ķ�ʽ�������ϴ����з���" , 16, 17, DARKGRAY);

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