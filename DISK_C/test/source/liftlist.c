#include "liftlist.h"
#include <mouse.h>

int liftselect()
{
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(40, 40, 280, 440) == 2 || mouse_press(360, 40, 600, 440) == 2)
		{
			MouseS = 1;
		}
		else if (mouse_press(40, 40, 280, 440) == 1)//进入一号楼
		{
			return 7;
		}
		else if (mouse_press(360, 40, 600, 440) == 1)//进入二号楼
		{
			return 8;
		}
		else
		{
			MouseS = 0;
		}

	}
}