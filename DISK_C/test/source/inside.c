#include "drawfunc.h"// <graphics.h> included
#include <graphics.h>
#include "lift.h"
#include "hz.h"
#include <mouse.h>

int inside(liftinfo *q)
{
	delay(1000);
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	DrawInsidePage(q);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (my_mouse_press(275, 70, 20))
		{
			if (my_mouse_press(275, 70, 20) == 2)  //11F
				MouseS = 1;
			else if (my_mouse_press(275, 70, 20) == 1)
			{
				setcolor(YELLOW);
				setlinestyle(0, 0, 3);
				circle(275, 70, 20);
				q->path[11] = 1;

			}
			else if (my_mouse_press(275, 70, 20) == 3)
			{
				setcolor(DARKGRAY);
				setlinestyle(0, 0, 3);
				circle(275, 70, 20);
				q->path[11] = 0;
			}
		}
		else if (my_mouse_press(275, 120, 20))
		{
			if (my_mouse_press(275, 120, 20) == 2)  //9F
				MouseS = 1;
			else if (my_mouse_press(275, 120, 20) == 1)
			{
				setcolor(YELLOW);
				setlinestyle(0, 0, 3);
				circle(275, 120, 20);
				q->path[9] = 1;

			}
			else if (my_mouse_press(275, 120, 20) == 3)
			{
				setcolor(DARKGRAY);
				setlinestyle(0, 0, 3);
				circle(275, 120, 20);
				q->path[9] = 0;
			}
		}
		else if (my_mouse_press(275, 170, 20))
		{
			if (my_mouse_press(275, 170, 20) == 2)  //7F
				MouseS = 1;
			else if (my_mouse_press(275, 170, 20) == 1)
			{
				setcolor(YELLOW);
				setlinestyle(0, 0, 3);
				circle(275, 170, 20);
				q->path[7] = 1;

			}
			else if (my_mouse_press(275, 170, 20) == 3)
			{
				setcolor(DARKGRAY);
				setlinestyle(0, 0, 3);
				circle(275, 170, 20);
				q->path[7] = 0;
			}
		}
		else if (my_mouse_press(275, 220, 20))
		{
			if (my_mouse_press(275, 220, 20) == 2)  //5F
				MouseS = 1;
			else if (my_mouse_press(275, 220, 20) == 1)
			{
				setcolor(YELLOW);
				setlinestyle(0, 0, 3);
				circle(275, 220, 20);
				q->path[5] = 1;

			}
			else if (my_mouse_press(275, 220, 20) == 3)
			{
				setcolor(DARKGRAY);
				setlinestyle(0, 0, 3);
				circle(275, 220, 20);
				q->path[5] = 0;
			}
		}
		else if (my_mouse_press(275, 270, 20))
		{
			if (my_mouse_press(275, 270, 20) == 2)  //3F
				MouseS = 1;
			else if (my_mouse_press(275, 270, 20) == 1)
			{
				setcolor(YELLOW);
				setlinestyle(0, 0, 3);
				circle(275, 270, 20);
				q->path[3] = 1;

			}
			else if (my_mouse_press(275, 270, 20) == 3)
			{
				setcolor(DARKGRAY);
				setlinestyle(0, 0, 3);
				circle(275, 270, 20);
				q->path[3] = 0;
			}
		}
		else if (my_mouse_press(275, 320, 20))
		{
			if (my_mouse_press(275, 320, 20) == 2)  //1F
				MouseS = 1;
			else if (my_mouse_press(275, 320, 20) == 1)
			{
				setcolor(YELLOW);
				setlinestyle(0, 0, 3);
				circle(275, 320, 20);
				q->path[1] = 1;

			}
			else if (my_mouse_press(275, 320, 20) == 3)
			{
				setcolor(DARKGRAY);
				setlinestyle(0, 0, 3);
				circle(275, 320, 20);
				q->path[1] = 0;
			}
		}
		else if (my_mouse_press(275, 370, 20) && q->num ==1 )
		{
			if (my_mouse_press(275, 370, 20) == 2)  //-1F
				MouseS = 1;
			else if (my_mouse_press(275, 370, 20) == 1)
			{
				setcolor(YELLOW);
				setlinestyle(0, 0, 3);
				circle(275, 370, 20);
				q->path[0] = 1;
	
			}
			else if (my_mouse_press(275, 370, 20) == 3)
			{
				setcolor(DARKGRAY);
				setlinestyle(0, 0, 3);
				circle(275, 370, 20);
				q->path[0] = 0;
			}
		}
		else if (my_mouse_press(385, 70, 20))
		{
			if (my_mouse_press(385, 70, 20) == 2)  //12F
				MouseS = 1;
			else if (my_mouse_press(385, 70, 20) == 1)
			{
				setcolor(YELLOW);
				setlinestyle(0, 0, 3);
				circle(385, 70, 20);
				q->path[12] = 1;

			}
			else if (my_mouse_press(385, 70, 20) == 3)
			{
				setcolor(DARKGRAY);
				setlinestyle(0, 0, 3);
				circle(385, 70, 20);
				q->path[12] = 0;
			}
		}
		else if (my_mouse_press(385, 120, 20))
		{
		if (my_mouse_press(385, 120, 20) == 2)  //10F
			MouseS = 1;
		else if (my_mouse_press(385, 120, 20) == 1)
		{
			setcolor(YELLOW);
			setlinestyle(0, 0, 3);
			circle(385, 120, 20);
			q->path[10] = 1;

		}
		else if (my_mouse_press(385, 120, 20) == 3)
		{
			setcolor(DARKGRAY);
			setlinestyle(0, 0, 3);
			circle(385, 120, 20);
			q->path[10] = 0;
		}
		}
		else if (my_mouse_press(385, 170, 20))
		{
			if (my_mouse_press(385, 170, 20) == 2)  //8F
				MouseS = 1;
			else if (my_mouse_press(385, 170, 20) == 1)
			{
				setcolor(YELLOW);
				setlinestyle(0, 0, 3);
				circle(385, 170, 20);
				q->path[8] = 1;

			}
			else if (my_mouse_press(385, 170, 20) == 3)
			{
				setcolor(DARKGRAY);
				setlinestyle(0, 0, 3);
				circle(385, 170, 20);
				q->path[8] = 0;
			}
		}
		else if (my_mouse_press(385, 220, 20))
		{
			if (my_mouse_press(385, 220, 20) == 2)  //6F
				MouseS = 1;
			else if (my_mouse_press(385, 220, 20) == 1)
			{
				setcolor(YELLOW);
				setlinestyle(0, 0, 3);
				circle(385, 220, 20);
				q->path[6] = 1;

			}
			else if (my_mouse_press(385, 220, 20) == 3)
			{
				setcolor(DARKGRAY);
				setlinestyle(0, 0, 3);
				circle(385, 220, 20);
				q->path[6] = 0;
			}
		}
		else if (my_mouse_press(385, 270, 20))
		{
			if (my_mouse_press(385, 270, 20) == 2)  //4F
				MouseS = 1;
			else if (my_mouse_press(385, 270, 20) == 1)
			{
				setcolor(YELLOW);
				setlinestyle(0, 0, 3);
				circle(385, 270, 20);
				q->path[4] = 1;

			}
			else if (my_mouse_press(385, 270, 20) == 3)
			{
				setcolor(DARKGRAY);
				setlinestyle(0, 0, 3);
				circle(385, 270, 20);
				q->path[4] = 0;
			}
		}
		else if (my_mouse_press(385, 320, 20))
		{
			if (my_mouse_press(385, 320, 20) == 2)  //2F
				MouseS = 1;
			else if (my_mouse_press(385, 320, 20) == 1)
			{
				setcolor(YELLOW);
				setlinestyle(0, 0, 3);
				circle(385, 320, 20);
				q->path[2] = 1;

			}
			else if (my_mouse_press(385, 320, 20) == 3)
			{
				setcolor(DARKGRAY);
				setlinestyle(0, 0, 3);
				circle(385, 320, 20);
				q->path[2] = 0;
			}
		}
		else if (my_mouse_press(500, 370, 30))//finish
		{
			if(my_mouse_press(500, 370, 30)==2)
				MouseS=1;

			else if (my_mouse_press(500, 370, 30) == 1)
			{
				cleardevice();				
				return 0;
			}
		}
		else
			MouseS=0;
			
		
	}
	
}