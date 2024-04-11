#include "calling.h"	//"lift.h" &<graphics.h>&"hz.h" included
#include <mouse.h>
#include <stdio.h>
int calling(liftsys *p)   //receive the lift system to be adjusted , *p=s
{
	delay(1000);
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	DrawCallingPage();

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (my_mouse_press(330,50,15))
		{
			if (my_mouse_press(330,50,15) == 2)  //左11楼上
				MouseS = 1;
			else if (my_mouse_press(330,50,15) == 1)
			{
				setfillstyle(1, LIGHTCYAN);
				floodfill(330, 50, DARKGRAY);
				if (p->call[11] == 0 || p->call[11] == 1)
					p->call[11] = 1;
				else if (p->call[11] == -1 || p->call[11] == 3)
					p->call[11] = 3;
			}
			else if (my_mouse_press(330,50,15) == 3)
			{
				setfillstyle(1, WHITE);
				floodfill(330, 50, DARKGRAY);
				if (p->call[11] == 0 || p->call[11] == 1)
					p->call[11] = 0;
				else if (p->call[11] == -1 || p->call[11] == 3)
					p->call[11] = -1;
			}
		}
		else if (my_mouse_press(330,85,15))
		{
			if (my_mouse_press(330,85,15) == 2)  //左10楼上
				MouseS = 1;
			else if (my_mouse_press(330,85,15) == 1)
			{
				setfillstyle(1, LIGHTCYAN);
				floodfill(330, 85, DARKGRAY);
				if (p->call[10] == 0 || p->call[10] == 1)
					p->call[10] = 1;
				else if (p->call[10] == -1 || p->call[10] == 3)
					p->call[10] = 3;
			}
			else if (my_mouse_press(330,85,15) == 3)
			{
				setfillstyle(1, 15);
				floodfill(330, 85, 8);
				if (p->call[10] == 0 || p->call[10] == 1)
					p->call[10] = 0;
				else if (p->call[10] == -1 || p->call[10] == 3)
					p->call[10] = -1;
			}
		}
		else if (my_mouse_press(330,120,15))
		{
			if (my_mouse_press(330,120,15) == 2)  //左9楼上
				MouseS = 1;
			else if (my_mouse_press(330,120,15) == 1)
			{
				setfillstyle(1, LIGHTCYAN);
				floodfill(330, 120, DARKGRAY);
				if (p->call[9] == 0 || p->call[9] == 1)
					p->call[9] = 1;
				else if (p->call[9] == -1 || p->call[9] == 3)
					p->call[9] = 3;
			}
			else if (my_mouse_press(330,120,15) == 3)
			{
				setfillstyle(1, 15);
				floodfill(330, 120, 8);
				if (p->call[9] == 0 || p->call[9] == 1)
					p->call[9] = 0;
				else if (p->call[9] == -1 || p->call[9] == 3)
					p->call[9] = -1;
			}
		}
		else if (my_mouse_press(330,155,15))
		{
			if (my_mouse_press(330,155,15) == 2)  //左8楼上
				MouseS = 1;
			else if (my_mouse_press(330,155,15) == 1)
			{
				setfillstyle(1, LIGHTCYAN);
				floodfill(330, 155, DARKGRAY);
				if (p->call[8] == 0 || p->call[8] == 1)
					p->call[8] = 1;
				else if (p->call[8] == -1 || p->call[8] == 3)
					p->call[8] = 3;
			}
			else if (my_mouse_press(330,155,15) == 3)
			{
				setfillstyle(1, 15);
				floodfill(330, 155, 8);
				if (p->call[8] == 0 || p->call[8] == 1)
					p->call[8] = 0;
				else if (p->call[8] == -1 || p->call[8] == 3)
					p->call[8] = -1;
			}
		}
		else if (my_mouse_press(330,190,15))
		{
			if (my_mouse_press(330,190,15) == 2)  //左7楼上
				MouseS = 1;
			else if (my_mouse_press(330,190,15) == 1)
			{
				setfillstyle(1, LIGHTCYAN);
				floodfill(330, 190, DARKGRAY);
				if (p->call[7] == 0 || p->call[7] == 1)
					p->call[7] = 1;
				else if (p->call[7] == -1 || p->call[7] == 3)
					p->call[7] = 3;
			}
			else if (my_mouse_press(330,190,15) == 3)
			{
				setfillstyle(1, 15);
				floodfill(330, 190, 8);
				if (p->call[7] == 0 || p->call[7] == 1)
					p->call[7] = 0;
				else if (p->call[7] == -1 || p->call[7] == 3)
					p->call[7] = -1;
			}
		}
		else if (my_mouse_press(330,225,15))
		{
			if (my_mouse_press(330,225,15) == 2)  //左6楼上
				MouseS = 1;
			else if (my_mouse_press(330,225,15) == 1)
			{
				setfillstyle(1, LIGHTCYAN);
				floodfill(330, 225, DARKGRAY);
				if (p->call[6] == 0 || p->call[6] == 1)
					p->call[6] = 1;
				else if (p->call[6] == -1 || p->call[6] == 3)
					p->call[6] = 3;
			}
			else if (my_mouse_press(330,225,15) == 3)
			{
				setfillstyle(1, 15);
				floodfill(330, 225, 8);
				if (p->call[6] == 0 || p->call[6] == 1)
					p->call[6] = 0;
				else if (p->call[6] == -1 || p->call[6] == 3)
					p->call[6] = -1;
			}
		}
		else if (my_mouse_press(330,260,15))
		{
			if (my_mouse_press(330,260,15) == 2)  //左5楼上
				MouseS = 1;
			else if (my_mouse_press(330,260,15) == 1)
			{
				setfillstyle(1, LIGHTCYAN);
				floodfill(330, 260, DARKGRAY);
				if (p->call[5] == 0 || p->call[5] == 1)
					p->call[5] = 1;
				else if (p->call[5] == -1 || p->call[5] == 3)
					p->call[5] = 3;
			}
			else if (my_mouse_press(330,260,15) == 3)
			{
				setfillstyle(1, 15);
				floodfill(330, 260, 8);
				if (p->call[5] == 0 || p->call[5] == 1)
					p->call[5] = 0;
				else if (p->call[5] == -1 || p->call[5] == 3)
					p->call[5] = -1;
			}
		}
		else if (my_mouse_press(330,295,15))
		{
			if (my_mouse_press(330,295,15) == 2)  //左4楼上
				MouseS = 1;
			else if (my_mouse_press(330,295,15) == 1)
			{
				setfillstyle(1, LIGHTCYAN);
				floodfill(330, 295, DARKGRAY);
				if (p->call[4] == 0 || p->call[4] == 1)
					p->call[4] = 1;
				else if (p->call[4] == -1 || p->call[4] == 3)
					p->call[4] = 3;
			}
			else if (my_mouse_press(330,295,15) == 3)
			{
				setfillstyle(1, 15);
				floodfill(330, 295, 8);
				if (p->call[4] == 0 || p->call[4] == 1)
					p->call[4] = 0;
				else if (p->call[4] == -1 || p->call[4] == 3)
					p->call[4] = -1;
			}
		}
		else if (my_mouse_press(330,330,15))
		{
			if (my_mouse_press(330,330,15) == 2)  //左3楼上
				MouseS = 1;
			else if (my_mouse_press(330,330,15) == 1)
			{
				setfillstyle(1, LIGHTCYAN);
				floodfill(330, 330, DARKGRAY);
				if (p->call[3] == 0 || p->call[3] == 1)
					p->call[3] = 1;
				else if (p->call[3] == -1 || p->call[3] == 3)
					p->call[3] = 3;
			}
			else if (my_mouse_press(330,330,15) == 3)
			{
				setfillstyle(1, 15);
				floodfill(330, 330, 8);
				if (p->call[3] == 0 || p->call[3] == 1)
					p->call[3] = 0;
				else if (p->call[3] == -1 || p->call[3] == 3)
					p->call[3] = -1;
			}
		}
		else if (my_mouse_press(330,365,15))
		{
			if (my_mouse_press(330,365,15) == 2)  //左2楼上
				MouseS = 1;
			else if (my_mouse_press(330,365,15) == 1)
			{
				setfillstyle(1, LIGHTCYAN);
				floodfill(330, 365, DARKGRAY);
				if (p->call[2] == 0 || p->call[2] == 1)
					p->call[2] = 1;
				else if (p->call[2] == -1 || p->call[2] == 3)
					p->call[2] = 3;
			}
			else if (my_mouse_press(330,365,15) == 3)
			{
				setfillstyle(1, 15);
				floodfill(330, 365, 8);
				if (p->call[2] == 0 || p->call[2] == 1)
					p->call[2] = 0;
				else if (p->call[2] == -1 || p->call[2] == 3)
					p->call[2] = -1;
			}
		}
		else if (my_mouse_press(330,400,15))
		{
			if (my_mouse_press(330,400,15) == 2)  //左1楼上
				MouseS = 1;
			else if (my_mouse_press(330,400,15) == 1)
			{
				setfillstyle(1, LIGHTCYAN);
				floodfill(330, 400, DARKGRAY);
				if (p->call[1] == 0 || p->call[1] == 1)
					p->call[1] = 1;
				else if (p->call[1] == -1 || p->call[1] == 3)
					p->call[1] = 3;
			}
			else if (my_mouse_press(330,400,15) == 3)
			{
				setfillstyle(1, 15);
				floodfill(330, 400, 8);
				if (p->call[1] == 0 || p->call[1] == 1)
					p->call[1] = 0;
				else if (p->call[1] == -1 || p->call[1] == 3)
					p->call[1] = -1;
			}
		}
		else if (my_mouse_press(330,435,15))
		{
			if (my_mouse_press(330,435,15) == 2)  //左-1楼上
				MouseS = 1;
			else if (my_mouse_press(330,435,15) == 1)
			{
				setfillstyle(1, LIGHTCYAN);
				floodfill(330, 435, DARKGRAY);
				p->call[0] = 1;
			}
			else if (my_mouse_press(330,435,15) == 3)
			{
				setfillstyle(1, 15);
				floodfill(330, 435, 8);
				p->call[0] = 0;
			}
		}
		else if (my_mouse_press(385,15,15))
		{
			if (my_mouse_press(385,15,15) == 2)  //右12楼下 
				MouseS = 1;
			else if (my_mouse_press(385,15,15) == 1)
			{
				setfillstyle(1, LIGHTCYAN);
				floodfill(385, 15, DARKGRAY);
				p->call[12] = -1;
			}
			else if (my_mouse_press(385,15,15) == 3)
			{
				setfillstyle(1, 15);
				floodfill(385, 15, 8);
				p->call[12] = 0;
			}
		}
		else if (my_mouse_press(385,50,15))
		{
			if (my_mouse_press(385,50,15) == 2)  //右11楼下 
				MouseS = 1;
			else if (my_mouse_press(385,50,15) == 1)
			{
				setfillstyle(1, LIGHTCYAN);
				floodfill(385, 50, DARKGRAY);
				if (p->call[11] == 0 || p->call[11] == -1)
					p->call[11] = -1;
				else if (p->call[11] == 1 || p->call[11] == 3)
					p->call[11] = 3;
			}
			else if (my_mouse_press(385,50,15) == 3)
			{
				setfillstyle(1, 15);
				floodfill(385, 50, 8);
				if (p->call[11] == 0 || p->call[11] == -1)
					p->call[11] = 0;
				else if (p->call[11] == 1 || p->call[11] == 3)
					p->call[11] = 1;
			}
		}
		else if (my_mouse_press(385,85,15))
		{
			if (my_mouse_press(385,85,15) == 2)  //右10楼下 
				MouseS = 1;
			else if (my_mouse_press(385,85,15) == 1)
			{
				setfillstyle(1, LIGHTCYAN);
				floodfill(385, 85, DARKGRAY);
				if (p->call[10] == 0 || p->call[10] == -1)
					p->call[10] = -1;
				else if (p->call[10] == 1 || p->call[10] == 3)
					p->call[10] = 3;
			}
			else if (my_mouse_press(385,85,15) == 3)
			{
				setfillstyle(1, 15);
				floodfill(385, 85, 8);
				if (p->call[10] == 0 || p->call[10] == -1)
					p->call[10] = 0;
				else if (p->call[10] == 1 || p->call[10] == 3)
					p->call[10] = 1;
			}
		}
		else if (my_mouse_press(385,120,15))
		{
			if (my_mouse_press(385,120,15) == 2)  //右9楼下 
				MouseS = 1;
			else if (my_mouse_press(385,120,15) == 1)
			{
				setfillstyle(1, LIGHTCYAN);
				floodfill(385, 120, DARKGRAY);
				if (p->call[9] == 0 || p->call[9] == -1)
					p->call[9] = -1;
				else if (p->call[9] == 1 || p->call[9] == 3)
					p->call[9] = 3;
			}
			else if (my_mouse_press(385,120,15) == 3)
			{
				setfillstyle(1, 15);
				floodfill(385, 120, 8);
				if (p->call[9] == 0 || p->call[9] == -1)
					p->call[9] = 0;
				else if (p->call[9] == 1 || p->call[9] == 3)
					p->call[9] = 1;
			}
		}
		else if (my_mouse_press(385,155,15))
		{
			if (my_mouse_press(385,155,15) == 2)  //右8楼下 
				MouseS = 1;
			else if (my_mouse_press(385,155,15) == 1)
			{
				setfillstyle(1, LIGHTCYAN);
				floodfill(385, 155, DARKGRAY);
				if (p->call[8] == 0 || p->call[8] == -1)
					p->call[8] = -1;
				else if (p->call[8] == 1 || p->call[8] == 3)
					p->call[8] = 3;
			}
			else if (my_mouse_press(385,155,15) == 3)
			{
				setfillstyle(1, 15);
				floodfill(385, 155, 8);
				if (p->call[8] == 0 || p->call[8] == -1)
					p->call[8] = 0;
				else if (p->call[8] == 1 || p->call[8] == 3)
					p->call[8] = 1;
			}
		}
		else if (my_mouse_press(385,190,15))
		{
			if (my_mouse_press(385,190,15) == 2)  //右7楼下 
				MouseS = 1;
			else if (my_mouse_press(385,190,15) == 1)
			{
				setfillstyle(1, LIGHTCYAN);
				floodfill(385, 190, DARKGRAY);
				if (p->call[7] == 0 || p->call[7] == -1)
					p->call[7] = -1;
				else if (p->call[7] == 1 || p->call[7] == 3)
					p->call[7] = 3;
			}
			else if (my_mouse_press(385,190,15) == 3)
			{
				setfillstyle(1, 15);
				floodfill(385, 190, 8);
				if (p->call[7] == 0 || p->call[7] == -1)
					p->call[7] = 0;
				else if (p->call[7] == 1 || p->call[7] == 3)
					p->call[7] = 1;
			}
		}
		else if (my_mouse_press(385,225,15))
		{
			if (my_mouse_press(385,225,15) == 2)  //右6楼下 
				MouseS = 1;
			else if (my_mouse_press(385,225,15) == 1)
			{
				setfillstyle(1, LIGHTCYAN);
				floodfill(385, 225, DARKGRAY);
				if (p->call[6] == 0 || p->call[6] == -1)
					p->call[6] = -1;
				else if (p->call[6] == 1 || p->call[6] == 3)
					p->call[6] = 3;
			}
			else if (my_mouse_press(385,225,15) == 3)
			{
				setfillstyle(1, 15);
				floodfill(385, 225, 8);
				if (p->call[6] == 0 || p->call[6] == -1)
					p->call[6] = 0;
				else if (p->call[6] == 1 || p->call[6] == 3)
					p->call[6] = 1;
			}
		}
		else if (my_mouse_press(385,260,15))
		{
			if (my_mouse_press(385,260,15) == 2)  //右5楼下 
				MouseS = 1;
			else if (my_mouse_press(385,260,15) == 1)
			{
				setfillstyle(1, LIGHTCYAN);
				floodfill(385, 260, DARKGRAY);
				if (p->call[5] == 0 || p->call[5] == -1)
					p->call[5] = -1;
				else if (p->call[5] == 1 || p->call[5] == 3)
					p->call[5] = 3;
			}
			else if (my_mouse_press(385,260,15) == 3)
			{
				setfillstyle(1, 15);
				floodfill(385, 260, 8);
				if (p->call[5] == 0 || p->call[5] == -1)
					p->call[5] = 0;
				else if (p->call[5] == 1 || p->call[5] == 3)
					p->call[5] = 1;
			}
		}
		else if (my_mouse_press(385,295,15))
		{
			if (my_mouse_press(385,295,15) == 2)  //右4楼下 
				MouseS = 1;
			else if (my_mouse_press(385,295,15) == 1)
			{
				setfillstyle(1, LIGHTCYAN);
				floodfill(385, 295, DARKGRAY);
				if (p->call[4] == 0 || p->call[4] == -1)
					p->call[4] = -1;
				else if (p->call[4] == 1 || p->call[4] == 3)
					p->call[4] = 3;
			}
			else if (my_mouse_press(385,295,15) == 3)
			{
				setfillstyle(1, 15);
				floodfill(385, 295, 8);
				if (p->call[4] == 0 || p->call[4] == -1)
					p->call[4] = 0;
				else if (p->call[4] == 1 || p->call[4] == 3)
					p->call[4] = 1;
			}
		}
		else if (my_mouse_press(385,330,15))
		{
			if (my_mouse_press(385,330,15) == 2)  //右3楼下 
				MouseS = 1;
			else if (my_mouse_press(385,330,15) == 1)
			{
				setfillstyle(1, LIGHTCYAN);
				floodfill(385, 330, DARKGRAY);
				if (p->call[3] == 0 || p->call[3] == -1)
					p->call[3] = -1;
				else if (p->call[3] == 1 || p->call[3] == 3)
					p->call[3] = 3;
			}
			else if (my_mouse_press(385,330,15) == 3)
			{
				setfillstyle(1, 15);
				floodfill(385, 330, 8);
				if (p->call[3] == 0 || p->call[3] == -1)
					p->call[3] = 0;
				else if (p->call[3] == 1 || p->call[3] == 3)
					p->call[3] = 1;
			}
		}
		else if (my_mouse_press(385,365,15))
		{
			if (my_mouse_press(385,365,15) == 2)  //右2楼下 
				MouseS = 1;
			else if (my_mouse_press(385,365,15) == 1)
			{
				setfillstyle(1, LIGHTCYAN);
				floodfill(385, 365, DARKGRAY);
				if (p->call[2] == 0 || p->call[2] == -1)
					p->call[2] = -1;
				else if (p->call[2] == 1 || p->call[2] == 3)
					p->call[2] = 3;
			}
			else if (my_mouse_press(385,365,15) == 3)
			{
				setfillstyle(1, 15);
				floodfill(385, 365, 8);
				if (p->call[2] == 0 || p->call[2] == -1)
					p->call[2] = 0;
				else if (p->call[2] == 1 || p->call[2] == 3)
					p->call[2] = 1;
			}
		}
		else if (my_mouse_press(385,400,15))
		{
			if (my_mouse_press(385,400,15) == 2)  //右1楼下 
				MouseS = 1;
			else if (my_mouse_press(385,400,15) == 1)
			{
				setfillstyle(1, LIGHTCYAN);
				floodfill(385, 400, DARKGRAY);
				if (p->call[1] == 0 || p->call[1] == -1)
					p->call[1] = -1;
				else if (p->call[1] == 1 || p->call[1] == 3)
					p->call[1] = 3;
			}
			else if (my_mouse_press(385,400,15) == 3)
			{
				setfillstyle(1, 15);
				floodfill(385, 400, 8);
				if (p->call[1] == 0 || p->call[1] == -1)
					p->call[1] = 0;
				else if (p->call[1] == 1 || p->call[1] == 3)
					p->call[1] = 1;
			}
		}
		else if (my_mouse_press(500, 370, 30))
		{
			if (my_mouse_press(500, 370, 30) == 2)  //完成按钮 
				MouseS = 1;

			else if (my_mouse_press(500, 370, 30) == 1)
			{
				//cleardevice();
				updatewait(p); //将呼叫信息传给系统
				return 5;
				
				
				
			}
		}
		else
			MouseS = 0;

	}

}

