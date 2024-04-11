#include "passmode.h"
#include "drawpass.h"
#include "anipass.h"
#include "liftlist.h"
#include <mouse.h>
#include <graphics.h>
int passmode()
{
	initview();
	delay(50);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(185, 180, 245, 240) == 2)
		{
			MouseS = 1;
		}
		else if (mouse_press(185, 180, 245, 240) == 1)//1ºÅÂ¥ÉÏÉı
		{
			doorsopen();
			return liftselect();
		}
		else if (mouse_press(185, 240, 245, 300) == 2)
		{
			MouseS = 1;
		}
		else if (mouse_press(185, 240, 245, 300) == 1)//1ºÅÂ¥ÏÂ½µ
		{
			doorsopen();
			return liftselect();
		}
		else if (mouse_press(400, 210, 460, 270) == 2)
		{
			MouseS = 1;
		}
		else if (mouse_press(400, 210, 460, 270) == 1)//2ºÅÂ¥ÉÏÉı
		{
			doorsopen();
			return liftselect();
			
		}
		else if (mouse_press(575, 0, 640, 35) == 2)//unclick on quit
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
		}
	}
	
}