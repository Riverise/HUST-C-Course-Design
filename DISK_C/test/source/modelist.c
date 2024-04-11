#include "modelist.h"
#include <graphics.h>
#include "hz.h"
#include <mouse.h>
#include <stdlib.h>
#include <stdio.h>
int modelist()
{
	setlinestyle(0,0,3);
	setcolor(WHITE);
	rectangle(100,100,250,280);
	rectangle(400,100,550,280);
	puthz(140,155,"乘客",32,33,LIGHTRED);
	puthz(140,195,"模式",32,33,LIGHTRED);
	puthz(440,155,"全局",32,33,LIGHTRED);
	puthz(440,195,"模式",32,33,LIGHTRED);
	while (1) {

		newmouse(&MouseX, &MouseY, &press);
		
		if (mouse_press(100, 100, 250, 280) == 2) //unclicked
		{
			MouseS = 1;
			setcolor(YELLOW);
			rectangle(100, 100, 250, 280);
		}
		else if (mouse_press(100, 100, 250, 280) == 1)
		{
			return 2;  //return to the intro1 of passenger mode, page 2
		}
		else if (mouse_press(400, 100, 550, 280) == 2) //unclicked
		{
			MouseS = 1;
			setcolor(YELLOW);
			rectangle(400, 100, 550, 280);
		}
		else if (mouse_press(400, 100, 550, 280) == 1) //click on the overall mode
		{
			return 4; //return to the intro2 of overall mode ,page 4
		}
		else if (mouse_press(280, 360, 370, 400) == 2) //unclied on leave
		{
			MouseS = 1;
			setcolor(YELLOW);
			rectangle(280, 360, 370, 400);
		}
		else if (mouse_press(280, 360, 370, 400) == 1)
		{
			printf("0");
			return 0;
		}

		else
		{

			
			MouseS = 0;
			setcolor(15);
			rectangle(100, 100, 250, 280);
			rectangle(400, 100, 550, 280);
			rectangle(280, 360, 370, 400);
		}

	}
}
