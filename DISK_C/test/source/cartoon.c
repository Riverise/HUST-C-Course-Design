#include "lift.h"
#include "drawfunc.h"
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <mouse.h>

int cartoon(liftsys *p)
{

	int i, j, Max1_, Max2_, Min1_, Min2_;
	int tag1, tag2;// pause1, pause2
	char max[3];//for debug
	char a[3];
	char b[3];
	Max1_ = 0;
	Max2_ = 0;
	Min2_ = 12;
	Min2_ = 12;
	tag1 = 1; //1 for moving,0 for terminating moving
	tag2 = 1;
	//pause1 = 0;//1 for pausing 
	//pause2 = 0;

   //先分析左电梯向上的情况
	if (p->liftL.condition == 1 && p->liftR.condition == 0)
	{
		for (i = 0; i < 13; i++)//to find the highest floor with request to be responded
		{
			if (p->liftL.pstop[i] == 1 || p->liftL.path[i] == 1)	 Max1_ = i;
		}
		while (p->liftL.cur < Max1_)
		{
			//for debug
			//itoa(Max1_, max, 10);
		//	outtextxy(50, 50, max);
			//end of debug
			for (i = 0; i < 15; i++)//电梯的上下平移
			{
				//mouseusing
				newmouse(&MouseX, &MouseY, &press);
				if (mouse_press(575, 0, 640, 35) == 2)  //unclick on quit
				{
					MouseS = 1;
				}
				else if (mouse_press(575, 0, 640, 35) == 1)
				{
					//回到主界面后应初始化之前改变的状态值，保证每次进入都是全新的状态
					for (i = 0; i < 13; i++)  //state initialization
					{
						p->call[i] = 0;
						p->liftL.pstop[i] = 0;
						p->liftR.pstop[i] = 0;
						p->liftL.path[i] = 0;
						p->liftR.path[i] = 0;
						p->wait[i].flo = -5;  //-5 for non-request/calling
						p->wait[i].L_eqtime = 0;
						p->wait[i].R_eqtime = 0;
						p->wait[i].L_respond = 0;
						p->wait[i].L_revert = 0;
						p->wait[i].R_respond = 0;
						p->wait[i].R_revert = 0;
					}
					p->liftL.cur = 1;
					p->liftR.cur = 1;
					p->liftL.condition = 0;
					p->liftR.condition = 0;
					p->liftL.post_condition = 0;
					p->liftR.post_condition = 0;
					p->liftL.flag = 0;
					p->liftR.flag = 0;
					return 1;	//return to the homepage
				}
				else if (mouse_press(0, 0, 120, 35) == 2)  //unclick on the manual
				{
					MouseS = 1;
				}
				else if (mouse_press(0, 0, 120, 35) == 1)
				{

					return 4;	//return to the manual 
				}
				else if (my_mouse_press(590, 430, 20) == 2)	//unclick on the operating button
				{
					MouseS = 1;
				}
				else if (my_mouse_press(590, 430, 20) == 1)
				{

					return 6;  //return to the calling page

				}
				else
					MouseS = 0;
				//mouseusing
				setlinestyle(0, 0, 3);
				setcolor(DARKGRAY);
				setfillstyle(1, WHITE);
				bar(185, 30, 255, 480);
				cable(1, 390 - 30 * p->liftL.cur - 2 * i);
				rectangle(190, 390 - 30 * p->liftL.cur - 2 * i, 250, 450 - 30 * p->liftL.cur - 2 * i);
				uparrow(205, 392 - 30 * p->liftL.cur - 2 * i, p->liftL.condition);
				downarrow(235, 412 - 30 * p->liftL.cur - 2 * i, p->liftL.condition);
				delay(40);
			}

			p->liftL.cur++;
			//电梯楼层数字更换
			setfillstyle(1, WHITE);
			bar(265, 15, 315, 47);
			//bar(335, 15, 385, 47);
			itoa(p->liftL.cur, a, 10);
			//itoa(p->liftR.cur, b, 10);
			settextstyle(4, 0, 2);
			setcolor(RED);
			outtextxy(275, 20, a);                                   //一号梯楼层 
			//outtextxy(345, 20, b);                                   //二号梯楼层 

			if (p->liftL.pstop[p->liftL.cur] == 1 && p->liftL.path[p->liftL.cur] == 0 && (p->call[p->liftL.cur] == 1 || p->call[p->liftL.cur] == 3))
			{

				p->liftL.pstop[p->liftL.cur] = 0;
				p->call[p->liftL.cur] = 0;
				delay(1000);//pausing time to be reconsidered

				inside(&p->liftL);
				break;
			}
			else if (p->liftL.pstop[p->liftL.cur] == 0 && p->liftL.path[p->liftL.cur] == 1)
			{
				p->liftL.path[p->liftL.cur] = 0;
				delay(1000);
				break;
			}
			else if (p->liftL.pstop[p->liftL.cur] == 1 && p->liftL.path[p->liftL.cur] == 1 && (p->call[p->liftL.cur] == 1 || p->call[p->liftL.cur] == 3))
			{

				p->liftL.pstop[p->liftL.cur] = 0;
				p->call[p->liftL.cur] = 0;
				p->liftL.path[p->liftL.cur] = 0;
				delay(1000);

				inside(&p->liftL);
				break;
			}

			//到达最目标高层后，对反方向的呼唤应作出响应
			if (p->liftL.cur == Max1_ && p->liftL.pstop[p->liftL.cur] == 1 && p->call[p->liftL.cur] == -1)
			{
				p->liftL.pstop[p->liftL.cur] = 0;
				p->call[p->liftL.cur] = 0;
				delay(1000);
				inside(&p->liftL);
				break;
			}

		}
	}
	else if (p->liftR.condition == 1 && p->liftL.condition == 0)
	{
		for (i = 0; i < 13; i++)//to find the highest floor with request to be responded
		{
			if (p->liftR.pstop[i] == 1 || p->liftR.path[i] == 1)	 Max2_ = i;
		}
		while (p->liftR.cur < Max2_)
		{
			for (i = 0; i < 15; i++)
			{
				//mouseusing
				newmouse(&MouseX, &MouseY, &press);
				if (mouse_press(575, 0, 640, 35) == 2)  //unclick on quit
				{
					MouseS = 1;
				}
				else if (mouse_press(575, 0, 640, 35) == 1)
				{
					//回到主界面后应初始化之前改变的状态值，保证每次进入都是全新的状态
					for (i = 0; i < 13; i++)  //state initialization
					{
						p->call[i] = 0;
						p->liftL.pstop[i] = 0;
						p->liftR.pstop[i] = 0;
						p->liftL.path[i] = 0;
						p->liftR.path[i] = 0;
						p->wait[i].flo = -5;  //-5 for non-request/calling
						p->wait[i].L_eqtime = 0;
						p->wait[i].R_eqtime = 0;
						p->wait[i].L_respond = 0;
						p->wait[i].L_revert = 0;
						p->wait[i].R_respond = 0;
						p->wait[i].R_revert = 0;
					}
					p->liftL.cur = 1;
					p->liftR.cur = 1;
					p->liftL.condition = 0;
					p->liftR.condition = 0;
					p->liftL.post_condition = 0;
					p->liftR.post_condition = 0;
					p->liftL.flag = 0;
					p->liftR.flag = 0;
					return 1;	//return to the homepage
				}
				else if (mouse_press(0, 0, 120, 35) == 2)  //unclick on the manual
				{
					MouseS = 1;
				}
				else if (mouse_press(0, 0, 120, 35) == 1)
				{

					return 4;	//return to the manual 
				}
				else if (my_mouse_press(590, 430, 20) == 2)	//unclick on the operating button
				{
					MouseS = 1;
				}
				else if (my_mouse_press(590, 430, 20) == 1)
				{

					return 6;  //return to the calling page

				}
				else
					MouseS = 0;
				//mouseusing
				setcolor(8);
				setlinestyle(0, 0, 3);
				setfillstyle(1, WHITE);
				bar(385, 30, 455, 480);
				cable(0, 390 - 30 * p->liftR.cur - 2 * i);
				rectangle(390, 390 - 30 * p->liftR.cur - 2 * i, 450, 450 - 30 * p->liftR.cur - 2 * i);
				uparrow(405, 392 - 30 * p->liftR.cur - 2 * i, p->liftR.condition);
				downarrow(435, 412 - 30 * p->liftR.cur - 2 * i, p->liftR.condition);
				delay(40);
			}//电梯的上下平移

			p->liftR.cur++;
			//电梯楼层数字更换
			setfillstyle(1, WHITE);
			//bar(265, 15, 315, 47);
			bar(335, 15, 385, 47);
			//itoa(p->liftR.cur, a, 10);
			itoa(p->liftR.cur, b, 10);
			settextstyle(4, 0, 2);
			setcolor(RED);
			//outtextxy(275, 20, a);                                   //一号梯楼层 
			outtextxy(345, 20, b);                                   //二号梯楼层 

			if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 0 && (p->call[p->liftR.cur] == 1 || p->call[p->liftR.cur] == 3))
			{

				p->liftR.pstop[p->liftR.cur] = 0;
				p->call[p->liftR.cur] = 0;
				delay(1000);//pausing time to be reconsidered
				inside(&p->liftR);
				break;
			}
			else if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 1)
			{
				p->liftR.path[p->liftR.cur] = 0;
				delay(1000);
				break;
			}
			else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 1 && (p->call[p->liftR.cur] == 1 || p->call[p->liftR.cur] == 3))
			{

				p->liftR.pstop[p->liftR.cur] = 0;
				p->call[p->liftR.cur] = 0;
				p->liftR.path[p->liftR.cur] = 0;
				delay(1000);
				inside(&p->liftR);
				break;
			}
			//到达最目标高层后，对反方向的呼唤应作出响应
			if (p->liftR.cur == Max2_ && p->liftR.pstop[p->liftR.cur] == 1 && p->call[p->liftR.cur] == -1)
			{
				p->liftR.pstop[p->liftR.cur] = 0;
				p->call[p->liftR.cur] = 0;
				delay(1000);
				inside(&p->liftR);
				break;
			}
		}
	}
	else if (p->liftL.condition == -1 && p->liftR.condition == 0)
	{
		for (i = 12; i >= 0; i--)//to find the lowest floor with request to be responded
		{
			if (p->liftL.pstop[i] == 1 || p->liftL.path[i] == 1)	 Min1_ = i;
		}
		while (p->liftL.cur > Min1_)
		{
			//for debug
			//itoa(Max1_, max, 10);
		//	outtextxy(50, 50, max);
			//end of debug
			for (i = 0; i < 15; i++)
			{
				//mouseusing
				newmouse(&MouseX, &MouseY, &press);
				if (mouse_press(575, 0, 640, 35) == 2)  //unclick on quit
				{
					MouseS = 1;
				}
				else if (mouse_press(575, 0, 640, 35) == 1)
				{
					//回到主界面后应初始化之前改变的状态值，保证每次进入都是全新的状态
					for (i = 0; i < 13; i++)  //state initialization
					{
						p->call[i] = 0;
						p->liftL.pstop[i] = 0;
						p->liftR.pstop[i] = 0;
						p->liftL.path[i] = 0;
						p->liftR.path[i] = 0;
						p->wait[i].flo = -5;  //-5 for non-request/calling
						p->wait[i].L_eqtime = 0;
						p->wait[i].R_eqtime = 0;
						p->wait[i].L_respond = 0;
						p->wait[i].L_revert = 0;
						p->wait[i].R_respond = 0;
						p->wait[i].R_revert = 0;
					}
					p->liftL.cur = 1;
					p->liftR.cur = 1;
					p->liftL.condition = 0;
					p->liftR.condition = 0;
					p->liftL.post_condition = 0;
					p->liftR.post_condition = 0;
					p->liftL.flag = 0;
					p->liftR.flag = 0;
					return 1;	//return to the homepage
				}
				else if (mouse_press(0, 0, 120, 35) == 2)  //unclick on the manual
				{
					MouseS = 1;
				}
				else if (mouse_press(0, 0, 120, 35) == 1)
				{

					return 4;	//return to the manual 
				}
				else if (my_mouse_press(590, 430, 20) == 2)	//unclick on the operating button
				{
					MouseS = 1;
				}
				else if (my_mouse_press(590, 430, 20) == 1)
				{

					return 6;  //return to the calling page

				}
				else
					MouseS = 0;
				//mouseusing
				setlinestyle(0, 0, 3);
				setcolor(DARKGRAY);
				setfillstyle(1, WHITE);
				bar(185, 30, 255, 480);
				cable(1, 390 - 30 * p->liftL.cur + 2 * i);
				rectangle(190, 390 - 30 * p->liftL.cur + 2 * i, 250, 450 - 30 * p->liftL.cur + 2 * i);
				uparrow(205, 392 - 30 * p->liftL.cur + 2 * i, p->liftL.condition);
				downarrow(235, 412 - 30 * p->liftL.cur + 2 * i, p->liftL.condition);
				delay(40);
			}//电梯的上下平移

			p->liftL.cur--;
			//电梯楼层数字更换
			setfillstyle(1, WHITE);
			bar(265, 15, 315, 47);
			//bar(335, 15, 385, 47);
			itoa(p->liftL.cur, a, 10);
			//itoa(p->liftR.cur, b, 10);
			settextstyle(4, 0, 2);
			setcolor(RED);
			outtextxy(275, 20, a);                                   //一号梯楼层 
			//outtextxy(345, 20, b);                                   //二号梯楼层 

			if (p->liftL.pstop[p->liftL.cur] == 1 && p->liftL.path[p->liftL.cur] == 0 && (p->call[p->liftL.cur] == -1 || p->call[p->liftL.cur] == 3))
			{

				p->liftL.pstop[p->liftL.cur] = 0;
				p->call[p->liftL.cur] = 0;
				delay(1000);//pausing time to be reconsidered

				inside(&p->liftL);
				break;
			}
			else if (p->liftL.pstop[p->liftL.cur] == 0 && p->liftL.path[p->liftL.cur] == 1)
			{
				p->liftL.path[p->liftL.cur] = 0;
				delay(1000);
				break;
			}
			else if (p->liftL.pstop[p->liftL.cur] == 1 && p->liftL.path[p->liftL.cur] == 1 && (p->call[p->liftL.cur] == -1 || p->call[p->liftL.cur] == 3))
			{

				p->liftL.pstop[p->liftL.cur] = 0;
				p->call[p->liftL.cur] = 0;
				p->liftL.path[p->liftL.cur] = 0;
				delay(1000);

				inside(&p->liftL);
				break;
			}
			//到达最低目标层后，对反方向的呼唤应作出响应
			if (p->liftL.cur == Min1_ && p->liftL.pstop[p->liftL.cur] == 1 && p->call[p->liftL.cur] == 1)
			{
				p->liftL.pstop[p->liftL.cur] = 0;
				p->call[p->liftL.cur] = 0;
				delay(1000);
				inside(&p->liftL);
				break;
			}
		}
	}
	else if (p->liftR.condition == -1 && p->liftL.condition == 0)
	{
		for (i = 12; i >= 0; i--)//to find the lowest floor with request to be responded
		{
			if (p->liftR.pstop[i] == 1 || p->liftR.path[i] == 1)	 Min2_ = i;
		}
		while (p->liftR.cur > Min2_)
		{
			//for debug
			//itoa(Max1_, max, 10);
			//outtextxy(50, 50, max);
			//end of debug
			for (i = 0; i < 15; i++)
			{
				//mouseusing
				newmouse(&MouseX, &MouseY, &press);
				if (mouse_press(575, 0, 640, 35) == 2)  //unclick on quit
				{
					MouseS = 1;
				}
				else if (mouse_press(575, 0, 640, 35) == 1)
				{
					//回到主界面后应初始化之前改变的状态值，保证每次进入都是全新的状态
					for (i = 0; i < 13; i++)  //state initialization
					{
						p->call[i] = 0;
						p->liftL.pstop[i] = 0;
						p->liftR.pstop[i] = 0;
						p->liftL.path[i] = 0;
						p->liftR.path[i] = 0;
						p->wait[i].flo = -5;  //-5 for non-request/calling
						p->wait[i].L_eqtime = 0;
						p->wait[i].R_eqtime = 0;
						p->wait[i].L_respond = 0;
						p->wait[i].L_revert = 0;
						p->wait[i].R_respond = 0;
						p->wait[i].R_revert = 0;
					}
					p->liftL.cur = 1;
					p->liftR.cur = 1;
					p->liftL.condition = 0;
					p->liftR.condition = 0;
					p->liftL.post_condition = 0;
					p->liftR.post_condition = 0;
					p->liftL.flag = 0;
					p->liftR.flag = 0;
					return 1;	//return to the homepage
				}
				else if (mouse_press(0, 0, 120, 35) == 2)  //unclick on the manual
				{
					MouseS = 1;
				}
				else if (mouse_press(0, 0, 120, 35) == 1)
				{

					return 4;	//return to the manual 
				}
				else if (my_mouse_press(590, 430, 20) == 2)	//unclick on the operating button
				{
					MouseS = 1;
				}
				else if (my_mouse_press(590, 430, 20) == 1)
				{

					return 6;  //return to the calling page

				}
				else
					MouseS = 0;
				//mouseusing
				setcolor(8);
				setlinestyle(0, 0, 3);
				setfillstyle(1, WHITE);
				bar(385, 30, 455, 480);
				cable(0, 390 - 30 * p->liftR.cur + 2 * i);
				rectangle(390, 390 - 30 * p->liftR.cur + 2 * i, 450, 450 - 30 * p->liftR.cur + 2 * i);
				uparrow(405, 392 - 30 * p->liftR.cur + 2 * i, p->liftR.condition);
				downarrow(435, 412 - 30 * p->liftR.cur + 2 * i, p->liftR.condition);
				delay(40);
			}//电梯的上下平移

			p->liftR.cur--;
			//电梯楼层数字更换
			setfillstyle(1, WHITE);
			//bar(265, 15, 315, 47);
			bar(335, 15, 385, 47);
			//itoa(p->liftL.cur, a, 10);
			itoa(p->liftR.cur, b, 10);
			settextstyle(4, 0, 2);
			setcolor(RED);
			//outtextxy(275, 20, a);                                   //一号梯楼层 
			outtextxy(345, 20, b);                                   //二号梯楼层 

			if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 0 && (p->call[p->liftR.cur] == -1 || p->call[p->liftR.cur] == 3))
			{

				p->liftR.pstop[p->liftR.cur] = 0;
				p->call[p->liftR.cur] = 0;
				delay(1000);//pausing time to be reconsidered

				inside(&p->liftR);
				break;
			}
			else if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 1)
			{
				p->liftR.path[p->liftR.cur] = 0;
				delay(1000);
				break;
			}
			else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 1 && (p->call[p->liftR.cur] == -1 || p->call[p->liftR.cur] == 3))
			{

				p->liftR.pstop[p->liftR.cur] = 0;
				p->call[p->liftR.cur] = 0;
				p->liftR.path[p->liftR.cur] = 0;
				delay(1000);

				inside(&p->liftR);
				break;
			}

			if (p->liftR.cur == Min2_ && p->liftR.pstop[p->liftR.cur] == 1 && p->call[p->liftR.cur] == 1)
			{
				p->liftR.pstop[p->liftR.cur] = 0;
				p->call[p->liftR.cur] = 0;
				delay(1000);
				inside(&p->liftR);
				break;
			}
		}
	}

	else if (p->liftL.condition == 1 && p->liftR.condition == 1)
	{
		for (i = 0; i < 13; i++)
		{
			if (p->liftL.pstop[i] == 1 || p->liftL.path[i] == 1)	Max1_ = i;
			if (p->liftR.pstop[i] == 1 || p->liftR.path[i] == 1)	Max2_ = i;
		}
		while (p->liftL.cur < Max1_ || p->liftR.cur < Max2_)
		{
			//lift-moving animation
			for (j = 0; j < 30; j++)
			{
				//mouseusing
				newmouse(&MouseX, &MouseY, &press);
				if (mouse_press(575, 0, 640, 35) == 2)  //unclick on quit
				{
					MouseS = 1;
				}
				else if (mouse_press(575, 0, 640, 35) == 1)
				{
					//回到主界面后应初始化之前改变的状态值，保证每次进入都是全新的状态
					for (i = 0; i < 13; i++)  //state initialization
					{
						p->call[i] = 0;
						p->liftL.pstop[i] = 0;
						p->liftR.pstop[i] = 0;
						p->liftL.path[i] = 0;
						p->liftR.path[i] = 0;
						p->wait[i].flo = -5;  //-5 for non-request/calling
						p->wait[i].L_eqtime = 0;
						p->wait[i].R_eqtime = 0;
						p->wait[i].L_respond = 0;
						p->wait[i].L_revert = 0;
						p->wait[i].R_respond = 0;
						p->wait[i].R_revert = 0;
					}
					p->liftL.cur = 1;
					p->liftR.cur = 1;
					p->liftL.condition = 0;
					p->liftR.condition = 0;
					p->liftL.post_condition = 0;
					p->liftR.post_condition = 0;
					p->liftL.flag = 0;
					p->liftR.flag = 0;
					return 1;	//return to the homepage
				}
				else if (mouse_press(0, 0, 120, 35) == 2)  //unclick on the manual
				{
					MouseS = 1;
				}
				else if (mouse_press(0, 0, 120, 35) == 1)
				{

					return 4;	//return to the manual 
				}
				else if (my_mouse_press(590, 430, 20) == 2)	//unclick on the operating button
				{
					MouseS = 1;
				}
				else if (my_mouse_press(590, 430, 20) == 1)
				{

					return 6;  //return to the calling page

				}
				else
					MouseS = 0;
				//mouseusing
				if (j % 2 == 0 && tag1 == 1)//left lift move
				{
					setlinestyle(0, 0, 3);
					setcolor(DARKGRAY);
					setfillstyle(1, WHITE);
					bar(185, 30, 255, 480);
					cable(1, 390 - 30 * p->liftL.cur - j);
					rectangle(190, 390 - 30 * p->liftL.cur - j, 250, 450 - 30 * p->liftL.cur - j);
					uparrow(205, 392 - 30 * p->liftL.cur - j, p->liftL.condition);
					downarrow(235, 412 - 30 * p->liftL.cur - j, p->liftL.condition);
					delay(20);//pausing time & k of k*j (stride) to be re-negotiated
				}
				else if (j % 2 == 1 && tag2 == 1)
				{
					setcolor(8);
					setlinestyle(0, 0, 3);
					setfillstyle(1, WHITE);
					bar(385, 30, 455, 480);
					cable(0, 390 - 30 * p->liftR.cur - j);
					rectangle(390, 390 - 30 * p->liftR.cur - j, 450, 450 - 30 * p->liftR.cur - j);
					uparrow(405, 392 - 30 * p->liftR.cur - j, p->liftR.condition);
					downarrow(435, 412 - 30 * p->liftR.cur - j, p->liftR.condition);
					delay(20);
				}

			}

			p->liftL.cur++;
			p->liftR.cur++;
			if (p->liftL.cur == Max1_)	tag1 = 0;
			if (p->liftR.cur == Max2_)  tag2 = 0;

			//Floor Num Update
			setfillstyle(1, WHITE);
			bar(265, 15, 315, 47);
			bar(335, 15, 385, 47);
			itoa(p->liftL.cur, a, 10);
			itoa(p->liftR.cur, b, 10);
			settextstyle(4, 0, 2);
			setcolor(RED);
			outtextxy(275, 20, a);                                   //一号梯楼层 
			outtextxy(345, 20, b);
			//二号梯楼层 
			//judge the state
			if (p->liftL.pstop[p->liftL.cur] == 0 && p->liftL.path[p->liftL.cur] == 0)
			{
				if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 0)
				{
					continue;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 1)
				{
					p->liftR.path[p->liftR.cur] = 0;
					delay(200);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 0 && (p->call[p->liftR.cur] == 1 || p->call[p->liftR.cur] == 3))
				{
					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftR);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 1 && (p->call[p->liftR.cur] == 1 || p->call[p->liftR.cur] == 3))
				{

					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					p->liftR.path[p->liftR.cur] = 0;
					delay(200);
					inside(&p->liftR);
					break;
				}

			}
			else if (p->liftL.pstop[p->liftL.cur] == 0 && p->liftL.path[p->liftL.cur] == 1)
			{
				p->liftL.path[p->liftL.cur] = 0;
				if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 0)
				{

					delay(200);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 1)
				{
					p->liftR.path[p->liftR.cur] = 0;
					delay(200);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 0 && (p->call[p->liftR.cur] == 1 || p->call[p->liftR.cur] == 3))
				{
					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftR);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 1 && (p->call[p->liftR.cur] == 1 || p->call[p->liftR.cur] == 3))
				{

					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					p->liftR.path[p->liftR.cur] = 0;
					delay(200);
					inside(&p->liftR);
					break;
				}
			}
			else if (p->liftL.pstop[p->liftL.cur] == 1 && p->liftL.path[p->liftL.cur] == 0 && (p->call[p->liftL.cur] == 1 || p->call[p->liftL.cur] == 3))
			{
				if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 0)
				{
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 1)
				{
					p->liftR.path[p->liftR.cur] = 0;
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 0 && (p->call[p->liftR.cur] == 1 || p->call[p->liftR.cur] == 3))
				{
					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					inside(&p->liftR);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 1 && (p->call[p->liftR.cur] == 1 || p->call[p->liftR.cur] == 3))
				{
					p->liftR.path[p->liftR.cur] = 0;
					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					inside(&p->liftR);
					break;
				}

			}
			else if (p->liftL.pstop[p->liftL.cur] == 1 && p->liftL.path[p->liftL.cur] == 1 && (p->call[p->liftL.cur] == 1 || p->call[p->liftL.cur] == 3))
			{
				p->liftL.path[p->liftL.cur] = 0;
				if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 0)
				{
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 1)
				{
					p->liftR.path[p->liftR.cur] = 0;
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 0 && (p->call[p->liftR.cur] == 1 || p->call[p->liftR.cur] == 3))
				{
					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					inside(&p->liftR);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 1 && (p->call[p->liftR.cur] == 1 || p->call[p->liftR.cur] == 3))
				{
					p->liftR.path[p->liftR.cur] = 0;
					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					inside(&p->liftR);
					break;
				}
			}
			//到达最目标高层后，对反方向的呼唤应作出响应
			if (p->liftR.cur == Max2_ && p->liftR.pstop[p->liftR.cur] == 1 && p->call[p->liftR.cur] == -1)
			{
				p->liftR.pstop[p->liftR.cur] = 0;
				p->call[p->liftR.cur] = 0;
				delay(200);
				inside(&p->liftR);
				break;
			}
			if (p->liftL.cur == Max1_ && p->liftL.pstop[p->liftL.cur] == 1 && p->call[p->liftL.cur] == -1)
			{
				p->liftL.pstop[p->liftL.cur] = 0;
				p->call[p->liftL.cur] = 0;
				delay(200);
				inside(&p->liftL);
				break;
			}
		}
	}
	else if (p->liftL.condition == 1 && p->liftR.condition == -1)//左上右下
	{
		for (i = 0; i < 13; i++)//to find the highest floor with request to be responded
		{
			if (p->liftL.pstop[i] == 1 || p->liftL.path[i] == 1)	 Max1_ = i;
		}
		for (i = 12; i >= 0; i--)//to find the lowest floor with request to be responded
		{
			if (p->liftR.pstop[i] == 1 || p->liftR.path[i] == 1)	 Min2_ = i;
		}
		while (p->liftL.cur < Max1_ || p->liftR.cur > Min2_)
		{
			//lift-moving animation
			for (j = 0; j < 30; j++)
			{
				//mouseusing
				newmouse(&MouseX, &MouseY, &press);
				if (mouse_press(575, 0, 640, 35) == 2)  //unclick on quit
				{
					MouseS = 1;
				}
				else if (mouse_press(575, 0, 640, 35) == 1)
				{
					//回到主界面后应初始化之前改变的状态值，保证每次进入都是全新的状态
					for (i = 0; i < 13; i++)  //state initialization
					{
						p->call[i] = 0;
						p->liftL.pstop[i] = 0;
						p->liftR.pstop[i] = 0;
						p->liftL.path[i] = 0;
						p->liftR.path[i] = 0;
						p->wait[i].flo = -5;  //-5 for non-request/calling
						p->wait[i].L_eqtime = 0;
						p->wait[i].R_eqtime = 0;
						p->wait[i].L_respond = 0;
						p->wait[i].L_revert = 0;
						p->wait[i].R_respond = 0;
						p->wait[i].R_revert = 0;
					}
					p->liftL.cur = 1;
					p->liftR.cur = 1;
					p->liftL.condition = 0;
					p->liftR.condition = 0;
					p->liftL.post_condition = 0;
					p->liftR.post_condition = 0;
					p->liftL.flag = 0;
					p->liftR.flag = 0;
					return 1;	//return to the homepage
				}
				else if (mouse_press(0, 0, 120, 35) == 2)  //unclick on the manual
				{
					MouseS = 1;
				}
				else if (mouse_press(0, 0, 120, 35) == 1)
				{

					return 4;	//return to the manual 
				}
				else if (my_mouse_press(590, 430, 20) == 2)	//unclick on the operating button
				{
					MouseS = 1;
				}
				else if (my_mouse_press(590, 430, 20) == 1)
				{

					return 6;  //return to the calling page

				}
				else
					MouseS = 0;
				//mouseusing
				if (j % 2 == 0 && tag1 == 1)//left lift move
				{
					setlinestyle(0, 0, 3);
					setcolor(DARKGRAY);
					setfillstyle(1, WHITE);
					bar(185, 30, 255, 480);
					cable(1, 390 - 30 * p->liftL.cur - j);
					rectangle(190, 390 - 30 * p->liftL.cur - j, 250, 450 - 30 * p->liftL.cur - j);
					uparrow(205, 392 - 30 * p->liftL.cur - j, p->liftL.condition);
					downarrow(235, 412 - 30 * p->liftL.cur - j, p->liftL.condition);
					delay(20);//pausing time & k of k*j (stride) to be re-negotiated
				}
				else if (j % 2 == 1 && tag2 == 1)
				{
					setcolor(8);
					setlinestyle(0, 0, 3);
					setfillstyle(1, WHITE);
					bar(385, 30, 455, 480);
					cable(0, 390 - 30 * p->liftR.cur + j);
					rectangle(390, 390 - 30 * p->liftR.cur + j, 450, 450 - 30 * p->liftR.cur + j);
					uparrow(405, 392 - 30 * p->liftR.cur + j, p->liftR.condition);
					downarrow(435, 412 - 30 * p->liftR.cur + j, p->liftR.condition);
					delay(20);
				}

			}

			p->liftL.cur++;
			p->liftR.cur--;
			if (p->liftL.cur == Max1_)	tag1 = 0;
			if (p->liftR.cur == Min2_)  tag2 = 0;

			setfillstyle(1, WHITE);
			bar(265, 15, 315, 47);
			bar(335, 15, 385, 47);
			itoa(p->liftL.cur, a, 10);
			itoa(p->liftR.cur, b, 10);
			settextstyle(4, 0, 2);
			setcolor(RED);
			outtextxy(275, 20, a);                                   //一号梯楼层 
			outtextxy(345, 20, b);

			if (p->liftL.pstop[p->liftL.cur] == 0 && p->liftL.path[p->liftL.cur] == 0)
			{
				if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 0)
				{
					continue;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 1)
				{
					p->liftR.path[p->liftR.cur] = 0;
					delay(200);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 0 && (p->call[p->liftR.cur] == -1 || p->call[p->liftR.cur] == 3))
				{
					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftR);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 1 && (p->call[p->liftR.cur] == -1 || p->call[p->liftR.cur] == 3))
				{

					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					p->liftR.path[p->liftR.cur] = 0;
					delay(200);
					inside(&p->liftR);
					break;
				}

			}
			else if (p->liftL.pstop[p->liftL.cur] == 0 && p->liftL.path[p->liftL.cur] == 1)
			{
				p->liftL.path[p->liftL.cur] = 0;
				if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 0)
				{

					delay(200);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 1)
				{
					p->liftR.path[p->liftR.cur] = 0;
					delay(200);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 0 && (p->call[p->liftR.cur] == -1 || p->call[p->liftR.cur] == 3))
				{
					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftR);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 1 && (p->call[p->liftR.cur] == -1 || p->call[p->liftR.cur] == 3))
				{

					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					p->liftR.path[p->liftR.cur] = 0;
					delay(200);
					inside(&p->liftR);
					break;
				}
			}
			else if (p->liftL.pstop[p->liftL.cur] == 1 && p->liftL.path[p->liftL.cur] == 0 && (p->call[p->liftL.cur] == 1 || p->call[p->liftL.cur] == 3))
			{
				if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 0)
				{
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 1)
				{
					p->liftR.path[p->liftR.cur] = 0;
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 0 && (p->call[p->liftR.cur] == -1 || p->call[p->liftR.cur] == 3))
				{
					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					inside(&p->liftR);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 1 && (p->call[p->liftR.cur] == -1 || p->call[p->liftR.cur] == 3))
				{
					p->liftR.path[p->liftR.cur] = 0;
					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					inside(&p->liftR);
					break;
				}

			}
			else if (p->liftL.pstop[p->liftL.cur] == 1 && p->liftL.path[p->liftL.cur] == 1 && (p->call[p->liftL.cur] == 1 || p->call[p->liftL.cur] == 3))
			{
				p->liftL.path[p->liftL.cur] = 0;
				if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 0)
				{
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 1)
				{
					p->liftR.path[p->liftR.cur] = 0;
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 0 && (p->call[p->liftR.cur] == -1 || p->call[p->liftR.cur] == 3))
				{
					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					inside(&p->liftR);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 1 && (p->call[p->liftR.cur] == -1 || p->call[p->liftR.cur] == 3))
				{
					p->liftR.path[p->liftR.cur] = 0;
					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					inside(&p->liftR);
					break;
				}
			}
			//到达最目标高层后，对反方向的呼唤应作出响应
			if (p->liftR.cur == Min2_ && p->liftR.pstop[p->liftR.cur] == 1 && p->call[p->liftR.cur] == 1)
			{
				p->liftR.pstop[p->liftR.cur] = 0;
				p->call[p->liftR.cur] = 0;
				delay(200);
				inside(&p->liftR);
				break;
			}
			if (p->liftL.cur == Max1_ && p->liftL.pstop[p->liftL.cur] == 1 && p->call[p->liftL.cur] == -1)
			{
				p->liftL.pstop[p->liftL.cur] = 0;
				p->call[p->liftL.cur] = 0;
				delay(200);
				inside(&p->liftL);
				break;
			}

		}
	}
	else if (p->liftL.condition == -1 && p->liftR.condition == 1)//左下右上
	{
		for (i = 0; i < 13; i++)//to find the highest floor with request to be responded
		{
			if (p->liftR.pstop[i] == 1 || p->liftR.path[i] == 1)	 Max2_ = i;
		}
		for (i = 12; i >= 0; i--)//to find the lowest floor with request to be responded
		{
			if (p->liftL.pstop[i] == 1 || p->liftL.path[i] == 1)	 Min1_ = i;
		}
		while (p->liftR.cur < Max2_ || p->liftL.cur > Min1_)
		{
			//lift-moving animation
			for (j = 0; j < 30; j++)
			{
				//mouseusing
				newmouse(&MouseX, &MouseY, &press);
				if (mouse_press(575, 0, 640, 35) == 2)  //unclick on quit
				{
					MouseS = 1;
				}
				else if (mouse_press(575, 0, 640, 35) == 1)
				{
					//回到主界面后应初始化之前改变的状态值，保证每次进入都是全新的状态
					for (i = 0; i < 13; i++)  //state initialization
					{
						p->call[i] = 0;
						p->liftL.pstop[i] = 0;
						p->liftR.pstop[i] = 0;
						p->liftL.path[i] = 0;
						p->liftR.path[i] = 0;
						p->wait[i].flo = -5;  //-5 for non-request/calling
						p->wait[i].L_eqtime = 0;
						p->wait[i].R_eqtime = 0;
						p->wait[i].L_respond = 0;
						p->wait[i].L_revert = 0;
						p->wait[i].R_respond = 0;
						p->wait[i].R_revert = 0;
					}
					p->liftL.cur = 1;
					p->liftR.cur = 1;
					p->liftL.condition = 0;
					p->liftR.condition = 0;
					p->liftL.post_condition = 0;
					p->liftR.post_condition = 0;
					p->liftL.flag = 0;
					p->liftR.flag = 0;
					return 1;	//return to the homepage
				}
				else if (mouse_press(0, 0, 120, 35) == 2)  //unclick on the manual
				{
					MouseS = 1;
				}
				else if (mouse_press(0, 0, 120, 35) == 1)
				{

					return 4;	//return to the manual 
				}
				else if (my_mouse_press(590, 430, 20) == 2)	//unclick on the operating button
				{
					MouseS = 1;
				}
				else if (my_mouse_press(590, 430, 20) == 1)
				{

					return 6;  //return to the calling page

				}
				else
					MouseS = 0;
				//mouseusing
				if (j % 2 == 0 && tag1 == 1)//left lift move
				{
					setlinestyle(0, 0, 3);
					setcolor(DARKGRAY);
					setfillstyle(1, WHITE);
					bar(185, 30, 255, 480);
					cable(1, 390 - 30 * p->liftL.cur + j);
					rectangle(190, 390 - 30 * p->liftL.cur + j, 250, 450 - 30 * p->liftL.cur + j);
					uparrow(205, 392 - 30 * p->liftL.cur + j, p->liftL.condition);
					downarrow(235, 412 - 30 * p->liftL.cur + j, p->liftL.condition);
					delay(20);//pausing time & k of k*j (stride) to be re-negotiated
				}
				else if (j % 2 == 1 && tag2 == 1)
				{
					setcolor(8);
					setlinestyle(0, 0, 3);
					setfillstyle(1, WHITE);
					bar(385, 30, 455, 480);
					cable(0, 390 - 30 * p->liftR.cur - j);
					rectangle(390, 390 - 30 * p->liftR.cur - j, 450, 450 - 30 * p->liftR.cur - j);
					uparrow(405, 392 - 30 * p->liftR.cur - j, p->liftR.condition);
					downarrow(435, 412 - 30 * p->liftR.cur - j, p->liftR.condition);
					delay(20);
				}

			}

			p->liftL.cur--;
			p->liftR.cur++;
			if (p->liftL.cur == Min1_)	tag1 = 0;
			if (p->liftR.cur == Max2_)  tag2 = 0;

			setfillstyle(1, WHITE);
			bar(265, 15, 315, 47);
			bar(335, 15, 385, 47);
			itoa(p->liftL.cur, a, 10);
			itoa(p->liftR.cur, b, 10);
			settextstyle(4, 0, 2);
			setcolor(RED);
			outtextxy(275, 20, a);                                   //一号梯楼层 
			outtextxy(345, 20, b);

			if (p->liftL.pstop[p->liftL.cur] == 0 && p->liftL.path[p->liftL.cur] == 0)
			{
				if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 0)
				{
					continue;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 1)
				{
					p->liftR.path[p->liftR.cur] = 0;
					delay(200);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 0 && (p->call[p->liftR.cur] == 1 || p->call[p->liftR.cur] == 3))
				{
					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftR);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 1 && (p->call[p->liftR.cur] == 1 || p->call[p->liftR.cur] == 3))
				{

					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					p->liftR.path[p->liftR.cur] = 0;
					delay(200);
					inside(&p->liftR);
					break;
				}

			}
			else if (p->liftL.pstop[p->liftL.cur] == 0 && p->liftL.path[p->liftL.cur] == 1)
			{
				p->liftL.path[p->liftL.cur] = 0;
				if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 0)
				{

					delay(200);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 1)
				{
					p->liftR.path[p->liftR.cur] = 0;
					delay(200);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 0 && (p->call[p->liftR.cur] == 1 || p->call[p->liftR.cur] == 3))
				{
					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftR);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 1 && (p->call[p->liftR.cur] == 1 || p->call[p->liftR.cur] == 3))
				{

					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					p->liftR.path[p->liftR.cur] = 0;
					delay(200);
					inside(&p->liftR);
					break;
				}
			}
			else if (p->liftL.pstop[p->liftL.cur] == 1 && p->liftL.path[p->liftL.cur] == 0 && (p->call[p->liftL.cur] == -1 || p->call[p->liftL.cur] == 3))
			{
				if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 0)
				{
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 1)
				{
					p->liftR.path[p->liftR.cur] = 0;
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 0 && (p->call[p->liftR.cur] == 1 || p->call[p->liftR.cur] == 3))
				{
					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					inside(&p->liftR);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 1 && (p->call[p->liftR.cur] == 1 || p->call[p->liftR.cur] == 3))
				{
					p->liftR.path[p->liftR.cur] = 0;
					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					inside(&p->liftR);
					break;
				}

			}
			else if (p->liftL.pstop[p->liftL.cur] == 1 && p->liftL.path[p->liftL.cur] == 1 && (p->call[p->liftL.cur] == -1 || p->call[p->liftL.cur] == 3))
			{
				p->liftL.path[p->liftL.cur] = 0;
				if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 0)
				{
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 1)
				{
					p->liftR.path[p->liftR.cur] = 0;
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 0 && (p->call[p->liftR.cur] == 1 || p->call[p->liftR.cur] == 3))
				{
					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					inside(&p->liftR);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 1 && (p->call[p->liftR.cur] == 1 || p->call[p->liftR.cur] == 3))
				{
					p->liftR.path[p->liftR.cur] = 0;
					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					inside(&p->liftR);
					break;
				}
			}
			//到达最目标高层后，对反方向的呼唤应作出响应
			if (p->liftR.cur == Max2_ && p->liftR.pstop[p->liftR.cur] == 1 && p->call[p->liftR.cur] == -1)
			{
				p->liftR.pstop[p->liftR.cur] = 0;
				p->call[p->liftR.cur] = 0;
				delay(200);
				inside(&p->liftR);
				break;
			}
			if (p->liftL.cur == Min1_ && p->liftL.pstop[p->liftL.cur] == 1 && p->call[p->liftL.cur] == 1)
			{
				p->liftL.pstop[p->liftL.cur] = 0;
				p->call[p->liftL.cur] = 0;
				delay(200);
				inside(&p->liftL);
				break;
			}

		}
	}
	else if (p->liftL.condition == -1 && p->liftR.condition == -1)//左下右下
	{

		for (i = 12; i >= 0; i--)//to find the lowest floor with request to be responded
		{
			if (p->liftL.pstop[i] == 1 || p->liftL.path[i] == 1)	 Min1_ = i;
			if (p->liftR.pstop[i] == 1 || p->liftR.path[i] == 1)	 Min2_ = i;
		}
		while (p->liftL.cur > Min1_ || p->liftR.cur > Min2_)
		{
			//lift-moving animation
			for (j = 0; j < 30; j++)
			{
				//mouseusing
				newmouse(&MouseX, &MouseY, &press);
				if (mouse_press(575, 0, 640, 35) == 2)  //unclick on quit
				{
					MouseS = 1;
				}
				else if (mouse_press(575, 0, 640, 35) == 1)
				{
					//回到主界面后应初始化之前改变的状态值，保证每次进入都是全新的状态
					for (i = 0; i < 13; i++)  //state initialization
					{
						p->call[i] = 0;
						p->liftL.pstop[i] = 0;
						p->liftR.pstop[i] = 0;
						p->liftL.path[i] = 0;
						p->liftR.path[i] = 0;
						p->wait[i].flo = -5;  //-5 for non-request/calling
						p->wait[i].L_eqtime = 0;
						p->wait[i].R_eqtime = 0;
						p->wait[i].L_respond = 0;
						p->wait[i].L_revert = 0;
						p->wait[i].R_respond = 0;
						p->wait[i].R_revert = 0;
					}
					p->liftL.cur = 1;
					p->liftR.cur = 1;
					p->liftL.condition = 0;
					p->liftR.condition = 0;
					p->liftL.post_condition = 0;
					p->liftR.post_condition = 0;
					p->liftL.flag = 0;
					p->liftR.flag = 0;
					return 1;	//return to the homepage
				}
				else if (mouse_press(0, 0, 120, 35) == 2)  //unclick on the manual
				{
					MouseS = 1;
				}
				else if (mouse_press(0, 0, 120, 35) == 1)
				{

					return 4;	//return to the manual 
				}
				else if (my_mouse_press(590, 430, 20) == 2)	//unclick on the operating button
				{
					MouseS = 1;
				}
				else if (my_mouse_press(590, 430, 20) == 1)
				{

					return 6;  //return to the calling page

				}
				else
					MouseS = 0;
				//mouseusing
				if (j % 2 == 0 && tag1 == 1)//left lift move
				{
					setlinestyle(0, 0, 3);
					setcolor(DARKGRAY);
					setfillstyle(1, WHITE);
					bar(185, 30, 255, 480);
					cable(1, 390 - 30 * p->liftL.cur + j);
					rectangle(190, 390 - 30 * p->liftL.cur + j, 250, 450 - 30 * p->liftL.cur + j);
					uparrow(205, 392 - 30 * p->liftL.cur + j, p->liftL.condition);
					downarrow(235, 412 - 30 * p->liftL.cur + j, p->liftL.condition);
					delay(20);//pausing time & k of k*j (stride) to be re-negotiated
				}
				else if (j % 2 == 1 && tag2 == 1)
				{
					setcolor(8);
					setlinestyle(0, 0, 3);
					setfillstyle(1, WHITE);
					bar(385, 30, 455, 480);
					cable(0, 390 - 30 * p->liftR.cur + j);
					rectangle(390, 390 - 30 * p->liftR.cur + j, 450, 450 - 30 * p->liftR.cur + j);
					uparrow(405, 392 - 30 * p->liftR.cur + j, p->liftR.condition);
					downarrow(435, 412 - 30 * p->liftR.cur + j, p->liftR.condition);
					delay(20);
				}

			}

			p->liftL.cur--;
			p->liftR.cur--;
			if (p->liftL.cur == Min1_)	tag1 = 0;
			if (p->liftR.cur == Min2_)  tag2 = 0;

			setfillstyle(1, WHITE);
			bar(265, 15, 315, 47);
			bar(335, 15, 385, 47);
			itoa(p->liftL.cur, a, 10);
			itoa(p->liftR.cur, b, 10);
			settextstyle(4, 0, 2);
			setcolor(RED);
			outtextxy(275, 20, a);                                   //一号梯楼层 
			outtextxy(345, 20, b);

			if (p->liftL.pstop[p->liftL.cur] == 0 && p->liftL.path[p->liftL.cur] == 0)
			{
				if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 0)
				{
					continue;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 1)
				{
					p->liftR.path[p->liftR.cur] = 0;
					delay(200);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 0 && (p->call[p->liftR.cur] == -1 || p->call[p->liftR.cur] == 3))
				{
					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftR);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 1 && (p->call[p->liftR.cur] == -1 || p->call[p->liftR.cur] == 3))
				{

					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					p->liftR.path[p->liftR.cur] = 0;
					delay(200);
					inside(&p->liftR);
					break;
				}

			}
			else if (p->liftL.pstop[p->liftL.cur] == 0 && p->liftL.path[p->liftL.cur] == 1)
			{
				p->liftL.path[p->liftL.cur] = 0;
				if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 0)
				{

					delay(200);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 1)
				{
					p->liftR.path[p->liftR.cur] = 0;
					delay(200);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 0 && (p->call[p->liftR.cur] == -1 || p->call[p->liftR.cur] == 3))
				{
					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftR);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 1 && (p->call[p->liftR.cur] == -1 || p->call[p->liftR.cur] == 3))
				{

					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					p->liftR.path[p->liftR.cur] = 0;
					delay(200);
					inside(&p->liftR);
					break;
				}
			}
			else if (p->liftL.pstop[p->liftL.cur] == 1 && p->liftL.path[p->liftL.cur] == 0 && (p->call[p->liftL.cur] == -1 || p->call[p->liftL.cur] == 3))
			{
				if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 0)
				{
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 1)
				{
					p->liftR.path[p->liftR.cur] = 0;
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 0 && (p->call[p->liftR.cur] == -1 || p->call[p->liftR.cur] == 3))
				{
					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					inside(&p->liftR);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 1 && (p->call[p->liftR.cur] == -1 || p->call[p->liftR.cur] == 3))
				{
					p->liftR.path[p->liftR.cur] = 0;
					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					inside(&p->liftR);
					break;
				}

			}
			else if (p->liftL.pstop[p->liftL.cur] == 1 && p->liftL.path[p->liftL.cur] == 1 && (p->call[p->liftL.cur] == -1 || p->call[p->liftL.cur] == 3))
			{
				p->liftL.path[p->liftL.cur] = 0;
				if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 0)
				{
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 0 && p->liftR.path[p->liftR.cur] == 1)
				{
					p->liftR.path[p->liftR.cur] = 0;
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 0 && (p->call[p->liftR.cur] == -1 || p->call[p->liftR.cur] == 3))
				{
					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					inside(&p->liftR);
					break;
				}
				else if (p->liftR.pstop[p->liftR.cur] == 1 && p->liftR.path[p->liftR.cur] == 1 && (p->call[p->liftR.cur] == -1 || p->call[p->liftR.cur] == 3))
				{
					p->liftR.path[p->liftR.cur] = 0;
					p->liftR.pstop[p->liftR.cur] = 0;
					p->call[p->liftR.cur] = 0;
					p->liftL.pstop[p->liftL.cur] = 0;
					p->call[p->liftL.cur] = 0;
					delay(200);//pausing time to be reconsidered
					inside(&p->liftL);
					inside(&p->liftR);
					break;
				}
			}
			//到达最目标高层后，对反方向的呼唤应作出响应
			if (p->liftR.cur == Min2_ && p->liftR.pstop[p->liftR.cur] == 1 && p->call[p->liftR.cur] == 1)
			{
				p->liftR.pstop[p->liftR.cur] = 0;
				p->call[p->liftR.cur] = 0;
				delay(200);
				inside(&p->liftR);
				break;
			}
			if (p->liftL.cur == Min1_ && p->liftL.pstop[p->liftL.cur] == 1 && p->call[p->liftL.cur] == 1)
			{
				p->liftL.pstop[p->liftL.cur] = 0;
				p->call[p->liftL.cur] = 0;
				delay(200);
				inside(&p->liftL);
				break;
			}

		}
	}

	return 0;
}