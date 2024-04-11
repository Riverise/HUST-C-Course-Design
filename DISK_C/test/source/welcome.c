#include "welcome.h"
#include "modelist.h"
#include <graphics.h>
#include <stdlib.h>
#include <mouse.h>
#include "hz.h"
int welcome()
{
	int value; //get a value from function modelist to go to another page
	cleardevice();
	setbkcolor(LIGHTGRAY);
	puthz(160,50,"科技楼双电梯模拟系统",32,33,LIGHTRED);
	setcolor(15);
	rectangle(280,300,370,340);                
	rectangle(280,360,370,400); 
	settextstyle(1,0,2);
	setcolor(RED);
	outtextxy(300,305,"Start");
	setcolor(RED);
	outtextxy(300,365,"Leave");	
	
	mouseinit();
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(280,300,370,340)==2)   //unclicked on start
		{
			MouseS=1;
			
			setcolor(YELLOW);
			rectangle(280,300,370,340);
		}
		else if(mouse_press(280,300,370,340)==1)
		{
			value=modelist();	
			if (!value)	exit(0);
			if (value)	return value;
		}
		
		 else if(mouse_press(280,360,370,400)==2) //unclicked on leave
		 {
			MouseS=1;
			setcolor(YELLOW);
			rectangle(280,360,370,400);
		 }
		 else if (mouse_press(280, 360, 370, 400) == 1)
		 {
			cleardevice();
			setbkcolor(WHITE);
			puthz(170, 210, "期待与你的下一次相遇：）", 24, 29, RED);
			delay(3000);
			exit(0);
	   	 }
		  

		 else
		 {
			MouseS = 0;

			setcolor(15);
			rectangle(280, 300, 370, 340);
			rectangle(280, 360, 370, 400);
		 }

		 
		
	}
	
	
	
			   
}
