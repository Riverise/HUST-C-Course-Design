#include "wlcm.h"

/********************************
 * FUNCTION:
 * DESCRIPTION:
 * INPUT:
 * RETURN:
 * OTHERS:
 ********************************/
void welcome_page0(void)
{
	setfillstyle(SOLID_FILL, RGB009fff);
	bar(0, 0, 1023, 767);
	write_photodata("C:\\win_pro\\ETC\\WLCM\\windows", 391, 265);
}

void welcome_page1(void)
{
	delay(500);
	setfillstyle(SOLID_FILL, RGB009fff);
	bar(0, 0, 1023, 767);
	write_photodata("C:\\win_pro\\ETC\\WLCM\\develop", 888, 727);
	delay(500);
	write_photodata("C:\\win_pro\\ETC\\WLCM\\welcome", 110, 88);
	delay(500);
	write_photodata("C:\\win_pro\\ETC\\WLCM\\waiting", 326, 611);
}

void log_page(void)
{
	setfillstyle(SOLID_FILL, RGB009fff);
	bar(0, 0, 1023, 767);
	write_photodata("C:\\win_pro\\ETC\\WLCM\\bkphoto", 0, 0);
	record_imagedata(360, 408, 663, 496, "IMDATA_3");
}

void keybox_draw(void)
{
	setfillstyle(SOLID_FILL, RGBffffff);
	setlinestyle(0, 0, 3);
	setcolor(RGB808080);
	bar(363, 411, 660, 442);
	rectangle(363, 411, 660, 442);
}

void dot_write(int x, int y)
{
	write_photodata("C:\\win_pro\\ETC\\WLCM\\dot", x, y);
}

int function_log(char *textipt)
{
	FILE *keyfp;
	char keyword[9];
	char temp;
	clearbuffer_keybd();
	welcome_page0();
	getch();
	log_page();
	keybox_draw();

	if ((keyfp = fopen("C:\\win_pro\\ETC\\WLCM\\keyword.txt", "rw")) == NULL)
	{
		pop_error(0, "function_log", "Can't open C:\\win_pro\\ETC\\WLCM\\keyword.txt ", "wlcm.cpp");
	}
	fseek(keyfp, 0, SEEK_SET);
	fgets(keyword, 9, keyfp);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		temp = getbuffer_keybd();
		if (temp == VK_ESCAPE)
		{
			return 1;
		}
		if (testmouse_bar(363, 411, 660, 442, MOUSETEST_INBAR) == MOUSE_INBAR_L)
		{
			longpress_fit();
			keybdintraction(textipt, 376, 421, 363 + 2, 411 + 2, 660 - 2, 442 - 2, 13, RGBffffff, 16, TEXTDISPLAY, 1);
			if (textipt[0] == '\0')
			{
				continue;
			}
			if (strlen(textipt) > 8)
			{
				wrong_key();
			}
			else
			{
				if (strcmp(keyword, textipt) == 0)
				{
					delay(200);
					return 0;
				}
				else
				{
					wrong_key();
				}
			}
		}
	}
}

void wrong_key(void)
{
	char temp;
	clrmous(MouseX, MouseY);
	write_imagedata(360, 408, 663, 496, "IMDATA_3");
	write_photodata("C:\\win_pro\\ETC\\WLCM\\keywrong", 407, 412);
	write_photodata("C:\\win_pro\\ETC\\WLCM\\okbtn", 453, 457);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		temp = getbuffer_keybd();
		if (testmouse_bar(453, 457, 552, 494, MOUSETEST_INBAR) == MOUSE_INBAR_L)
		{
			longpress_fit();
			clrmous(MouseX, MouseY);
			write_imagedata(360, 408, 663, 496, "IMDATA_3");
			keybox_draw();
			return;
		}
		else if (temp == VK_RETURN)
		{
			clrmous(MouseX, MouseY);
			write_imagedata(360, 408, 663, 496, "IMDATA_3");
			keybox_draw();
			return;
		}
	}
}