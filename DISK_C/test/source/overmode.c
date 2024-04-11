#include "overmode.h"  //<lift.h>included
#include <mouse.h>
#include <stdlib.h>
#include <graphics.h>
#include "drawfunc.h"
//#include<stdio.h>

int overmode(liftsys *p)
{
	int i, record;
	

	//calling(p);//for debug
	deploy(p);
	//condition_logic(p);//for debug
	
	drawpage(p);
	

	delay(50);
	while (1)
	{
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
		else if(mouse_press(0, 0, 120, 35) == 1)
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
				
		condition_logic(p);
		
		
		if (p->liftL.condition != 0 || p->liftR.condition != 0)
		{
			
			record = cartoon(p);
			if(record !=0)	return record;
			//p->liftL.path[2] = 1;//for debug
			drawpage(p);
		}
		else//update arrow_state after update lift_condition
		{
			uparrow(205, 420 - p->liftL.cur * 30 - 28, 0);
			downarrow(235, 420 - p->liftL.cur * 30 - 8, p->liftL.condition);
			uparrow(405, 390 - (p->liftR.cur - 1) * 30 - 28, p->liftR.condition);
			downarrow(435, 390 - (p->liftR.cur - 1) * 30 - 8, p->liftR.condition);
		}

	}

	
}