#include "liftrun.h"
#include "drawpass.h"
#include "lift.h"
#include "anipass.h"
#include <mouse.h>
int liftrun1(int *now)
{
	int goal;
	

	insideview(1);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);

		if (my_mouse_press(268, 30, 15) == 2// 11
			|| my_mouse_press(268, 90, 15) == 2// 9
			|| my_mouse_press(268, 150, 15) == 2// 7
			|| my_mouse_press(268, 210, 15) == 2// 5
			|| my_mouse_press(268, 270, 15) == 2// 3
			|| my_mouse_press(268, 330, 15) == 2// 1
			|| my_mouse_press(268, 450, 15) == 2//-1
			|| my_mouse_press(376, 30, 15) == 2// 12
			|| my_mouse_press(376, 90, 15) == 2// 10
			|| my_mouse_press(376, 150, 15) == 2// 8
			|| my_mouse_press(376, 210, 15) == 2// 6
			|| my_mouse_press(376, 270, 15) == 2// 4
			|| my_mouse_press(376, 330, 15) == 2// 2
			|| my_mouse_press(376, 390, 15) == 2//关门按钮
			|| my_mouse_press(268, 390, 15) == 2//开门按钮
			|| my_mouse_press(376, 450, 15) == 2//警报按钮
			)
		{
			MouseS = 1;
		}
		else if (my_mouse_press(376, 450, 15) == 1)//警报按钮
		{
			warning();
			insideview(1);
		}
		else if (my_mouse_press(268, 450, 15) == 1)//-1楼
		{
			light0();
			delay(400);
			singleclose();
			insideview(1);
			goal = -1;
			
			if (numvary(now, goal))	return 1;

		}
		else if (my_mouse_press(268, 330, 15) == 1)//1楼
		{
			light1();
			delay(400);
			singleclose();
			insideview(1);
			goal = 1;
			
			if (numvary(now, goal))	return 1;

		}
		else if (my_mouse_press(376, 330, 15) == 1)//2楼
		{
			light2();
			delay(400);
			singleclose();
			insideview(1);
			goal = 2;
			
			if (numvary(now, goal))	return 1;
		}
		else if (my_mouse_press(268, 270, 15) == 1)//3楼
		{
			light3();
			delay(400);
			singleclose();
			insideview(1);
			goal = 3;
			
			if (numvary(now, goal))	return 1;
		}
		else if (my_mouse_press(376, 270, 15) == 1)//4楼
		{
			light4();
			delay(400);
			singleclose();
			insideview(1);
			goal = 4;
		
			if (numvary(now, goal))	return 1;
		}
		else if (my_mouse_press(268, 210, 15) == 1)//5楼
		{
			light5();
			delay(400);
			singleclose();
			insideview(1);
			goal = 5;
			
			if (numvary(now, goal))	return 1;
		}
		else if (my_mouse_press(376, 210, 15) == 1)//6楼
		{
			light6();
			delay(400);
			singleclose();
			insideview(1);
			goal = 6;
			 
			if (numvary(now, goal))	return 1;
		}
		else if (my_mouse_press(268, 150, 15) == 1)//7楼
		{
			light7();
			delay(400);
			singleclose();
			insideview(1);
			goal = 7;
			 
			if (numvary(now, goal))	return 1;
		}
		else if (my_mouse_press(376, 150, 15) == 1)//8楼
		{
			light8();
			delay(400);
			singleclose();
			insideview(1);
			goal = 8;
			 
			if (numvary(now, goal))	return 1;
		}
		else if (my_mouse_press(268, 90, 15) == 1)//9楼
		{
			light9();
			delay(400);
			singleclose();
			insideview(1);
			goal = 9;
			 
			if (numvary(now, goal))	return 1;
		}
		else if (my_mouse_press(376, 90, 15) == 1)//10楼
		{
			light10();
			delay(400);
			singleclose();
			insideview(1);
			goal = 10;
			 
			if (numvary(now, goal))	return 1;
		}
		else if (my_mouse_press(268, 30, 15) == 1)//11楼
		{
			light11();
			delay(400);
			singleclose();
			insideview(1);
			goal = 11;
			 
			if (numvary(now, goal))	return 1;
		}
		else if (my_mouse_press(376, 30, 15) == 1)//12楼
		{
			light12();
			delay(400);
			singleclose();
			insideview(1);
			goal = 12;
			 
			if (numvary(now, goal))	return 1;
		}
		else if (my_mouse_press(268, 390, 15) == 1)//开门按钮
		{
			singleopen();
			delay(100);
			singleclose();
			return 9;
		}
		else if (my_mouse_press(376, 390, 15) == 1)//关门按钮
		{
			singleclose();
			insideview(1);
		}
		else
			MouseS = 0;
		
	}
	
}
int liftrun2(int *now)
{
	int goal;

	goal = 0;

	insideview(0);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);

		if (my_mouse_press(268, 30, 15) == 2// 11
			|| my_mouse_press(268, 90, 15) == 2// 9
			|| my_mouse_press(268, 150, 15) == 2// 7
			|| my_mouse_press(268, 210, 15) == 2// 5
			|| my_mouse_press(268, 270, 15) == 2// 3
			|| my_mouse_press(268, 330, 15) == 2// 1
			|| my_mouse_press(376, 30, 15) == 2// 12
			|| my_mouse_press(376, 90, 15) == 2// 10
			|| my_mouse_press(376, 150, 15) == 2// 8
			|| my_mouse_press(376, 210, 15) == 2// 6
			|| my_mouse_press(376, 270, 15) == 2// 4
			|| my_mouse_press(376, 330, 15) == 2// 2
			|| my_mouse_press(376, 390, 15) == 2//关门按钮
			|| my_mouse_press(268, 390, 15) == 2//开门按钮
			|| my_mouse_press(376, 450, 15) == 2//警报按钮
			)
		{
			MouseS = 1;
		}
		else if (my_mouse_press(376, 450, 15) == 1)//警报按钮
		{
			warning();
			insideview(0);
		}
		else if (my_mouse_press(268, 330, 15) == 1)//1楼
		{
			light1();
			delay(400);
			singleclose();
			insideview(0);
			goal = 1;
			 
			if (numvary(now, goal))	return 1;

		}
		else if (my_mouse_press(376, 330, 15) == 1)//2楼
		{
			light2();
			delay(400);
			singleclose();
			insideview(0);
			goal = 2;
			 
			if (numvary(now, goal))	return 1;
		}
		else if (my_mouse_press(268, 270, 15) == 1)//3楼
		{
			light3();
			delay(400);
			singleclose();
			insideview(0);
			goal = 3;
			 
			if (numvary(now, goal))	return 1;
		}
		else if (my_mouse_press(376, 270, 15) == 1)//4楼
		{
			light4();
			delay(400);
			singleclose();
			insideview(0);
			goal = 4;
			 
			if (numvary(now, goal))	return 1;
		}
		else if (my_mouse_press(268, 210, 15) == 1)//5楼
		{
			light5();
			delay(400);
			singleclose();
			insideview(0);
			goal = 5;
			 
			if (numvary(now, goal))	return 1;
		}
		else if (my_mouse_press(376, 210, 15) == 1)//6楼
		{
			light6();
			delay(400);
			singleclose();
			insideview(0);
			goal = 6;
			 
			if (numvary(now, goal))	return 1;
		}
		else if (my_mouse_press(268, 150, 15) == 1)//7楼
		{
			light7();
			delay(400);
			singleclose();
			insideview(0);
			goal = 7;
			 
			if (numvary(now, goal))	return 1;
		}
		else if (my_mouse_press(376, 150, 15) == 1)//8楼
		{
			light8();
			delay(400);
			singleclose();
			insideview(0);
			goal = 8;
			 
			if (numvary(now, goal))	return 1;
		}
		else if (my_mouse_press(268, 90, 15) == 1)//9楼
		{
			light9();
			delay(400);
			singleclose();
			insideview(0);
			goal = 9;
			 
			if (numvary(now, goal))	return 1;
		}
		else if (my_mouse_press(376, 90, 15) == 1)//10楼
		{
			light10();
			delay(400);
			singleclose();
			insideview(0);
			goal = 10;
			 
			if (numvary(now, goal))	return 1;
		}
		else if (my_mouse_press(268, 30, 15) == 1)//11楼
		{
			light11();
			delay(400);
			singleclose();
			insideview(0);
			goal = 11;
			 
			if (numvary(now, goal))	return 1;
		}
		else if (my_mouse_press(376, 30, 15) == 1)//12楼
		{
			light12();
			delay(400);
			singleclose();
			insideview(0);
			goal = 12;
			 
			if (numvary(now, goal))	return 1;
		}
		else if (my_mouse_press(268, 390, 15) == 1)//开门按钮
		{
			singleopen();
			delay(100);
			singleclose();
			return 9;
		}
		else if (my_mouse_press(376, 390, 15) == 1)//关门按钮
		{
			singleclose();
			insideview(0);
		}
		else
			MouseS = 0;

	}

}


