#include "menu.h"

/********************************
 * FUNCTION:getdirect_menu
 * DESCRIPTION:获取右键菜单显示方向
 * INPUT:鼠标坐标，菜单尺寸
 * RETURN:显示方向（宏定义）
 * OTHERS:无
 ********************************/
int getdirect_menu(int mousex, int mousey, int height_menu, int width_menu)
{
	int rightp, downp;
	rightp = 1023 - mousex;
	downp = 767 - mousey;
	if (height_menu > downp)
	{
		if (width_menu > rightp)
		{
			return LEFT_UP;
		}
		else
		{
			return RIGHT_UP;
		}
	}
	else
	{
		if (width_menu > rightp)
		{
			return LEFT_DOWN;
		}
		else
		{
			return RIGHT_DOWN;
		}
	}
}

int getdirect_sonmenu(int width, int x2)
{
	int rightp;
	rightp = 1023 - x2;
	if (width > rightp)
	{
		return LEFT;
	}
	else
	{
		return RIGHT;
	}
}

void getxy_menu(int *xy, int direct, int height, int width)
{
	switch (direct)
	{
	case RIGHT_DOWN:
		xy[0] = MouseX;
		xy[1] = MouseY;
		xy[2] = MouseX + width;
		xy[3] = MouseY + height;
		break;
	case RIGHT_UP:
		xy[0] = MouseX;
		xy[1] = MouseY - height;
		xy[2] = MouseX + width;
		xy[3] = MouseY;
		break;
	case LEFT_DOWN:
		xy[0] = MouseX - width;
		xy[1] = MouseY;
		xy[2] = MouseX;
		xy[3] = MouseY + height;
		break;
	case LEFT_UP:
		xy[0] = MouseX - width;
		xy[1] = MouseY - height;
		xy[2] = MouseX;
		xy[3] = MouseY;
		break;
	}
}

/********************************
 * FUNCTION:draw_menu
 * DESCRIPTION:画菜单
 * INPUT:方向，模式
 * RETURN:无
 * OTHERS:无
 ********************************/
void draw_menu(int direct, int mode, State state_menu)
{
	int xy[4];
	int height, width;
	int x, y;
	int i;
	int color;
	char name1[5][10] = {"剪切", "复制", "删除", "重命名", "属性"};
	char name2[5][10] = {"查看", "排序方式", "刷新", "新建", "粘贴"};
	char(*name)[10];

	switch (mode)
	{
	case FILE_MENU:
		height = HEIGHT_MENU_FILE + 2;
		width = WIDTH_MENU_FILE + 2;
		name = name1;
		break;
	case DIR_MENU:
		height = HEIGHT_MENU_DIR + 2;
		width = WIDTH_MENU_DIR + 2;
		name = name2;
		break;
	default:
		break;
	}

	getxy_menu(xy, direct, height, width);

	clrmous(MouseX, MouseY);
	record_imagedata(xy[0], xy[1], xy[2] + 2, xy[3] + 2, "IMDATA_4");
	setfillstyle(SOLID_FILL, RGB000000);
	bar(xy[0] + 2, xy[1] + 2, xy[2], xy[3]);
	setfillstyle(SOLID_FILL, RGBfffbf0);
	bar(xy[0], xy[1], xy[2] - 2, xy[3] - 2);
	setcolor(RGBa0a0a4);
	rectangle(xy[0], xy[1], xy[2] - 2, xy[3] - 2);
	x = xy[0] + 17;
	y = xy[1] + 6;
	for (i = 0; i < 5; i++)
	{
		if (getonebit(state_menu, i + 1) == 1)
		{
			color = RGB000000;
		}
		else
		{
			color = RGBa0a0a4;
		}
		put12hz(x, y, name[i], 13, color);
		y += 21;
	}
	line(xy[0] + 4, xy[1] + 2 * 21 + 1, xy[0] + WIDTH_MENU_FILE - 4, xy[1] + 2 * 21 + 1);

	line(xy[0] + 4, xy[1] + 4 * 21 + 1, xy[0] + WIDTH_MENU_FILE - 4, xy[1] + 4 * 21 + 1);
}

/********************************
 * FUNCTION:
 * DESCRIPTION:
 * INPUT:
 * RETURN:
 * OTHERS:
 ********************************/
int func_menu(int mode, State state_menu, State *state_btn, My_filenode **p_headnode_current, My_filenode *ph, My_filenode *ph_for_paste, My_vector_ *paste, char *textipt, unsigned char *page, int *p_judge_paste, int *p_judge_sort)
{
	int height, width;
	int direct;
	int num_btn, maxnum;
	int x[2], y[2];
	int xy[4];
	int btnnum;
	My_filenode *ttnode;
	void (*draw_mainfile)(int x1, int y1, struct My_filenode *headnode,
						  int n, int state, int page); //函数指针
	Funcdata data_current;

	maxnum = 5;
	height = HEIGHT_MENU_FILE + 2;
	width = WIDTH_MENU_FILE + 2;

	direct = getdirect_menu(MouseX, MouseY, height, width);
	getxy_menu(xy, direct, height, width);

	setstate_menu(&state_menu, mode, paste, *p_headnode_current);
	draw_menu(direct, mode, state_menu);

	while (testmouse_bar(xy[0], xy[1], xy[2] - 2, xy[3] - 2, MOUSETEST_ALL) != MOUSE_OUTBAR_L)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (testmouse_inoutbar(xy[0], xy[1], xy[2] - 2, xy[3] - 2) == 1)
		{
			num_btn = (MouseY - xy[1]) / 21 + 1;

			if (num_btn > maxnum)
			{
				num_btn = maxnum;
			}
			if (testmouse_bar(xy[0], xy[1], xy[2], xy[3], MOUSETEST_INBAR) == MOUSE_INBAR_L)
			{
				btnnum = do_menu(num_btn, mode, xy[0], xy[1], state_menu, state_btn, p_headnode_current, ph, ph_for_paste, paste, textipt, page, p_judge_paste, p_judge_sort);

				clrmous(MouseX, MouseY);
				write_imagedata(xy[0], xy[1], xy[2] + 2, xy[3] + 2, "IMDATA_4");
				if (btnnum == RENAME_BTN)
				{
					getfuncdata(&data_current, &draw_mainfile, p_headnode_current, ph);
					func_rename(*p_headnode_current, textipt, data_current.x0, data_current.y0, data_current.height, data_current.width, data_current.space_x_n, data_current.space_y_n, data_current.displaytype_main, page, draw_mainfile);
				}
				return btnnum;
			}
		}
		if (testmouse_bar(xy[0], xy[1], xy[2], xy[3], MOUSETEST_ALL) == MOUSE_OUTBAR_L)
		{
			clrmous(MouseX, MouseY);
			write_imagedata(xy[0], xy[1], xy[2] + 2, xy[3] + 2, "IMDATA_4");
			longpress_fit();
			return BTN_NO_USE;
		}
	}
	return BTN_NO_USE;
}

int do_menu(int num, int mode, int x1, int y, State state_menu, State *state_btn, My_filenode **p_headnode_current, My_filenode *ph, My_filenode *ph_for_paste, My_vector_ *paste, char *textipt, unsigned char *page, int *p_judge_paste, int *p_judge_sort)
{
	void (*draw_mainfile)(int x1, int y1, struct My_filenode *headnode,
						  int n, int state, int page); //函数指针
	Funcdata data_current;
	getfuncdata(&data_current, &draw_mainfile, p_headnode_current, ph);

	switch (mode)
	{
	case FILE_MENU:
		switch (num)
		{
		case 1: /* 剪切 */
			if (getonebit(state_menu, 1) == 1)
			{
				func_cut(*p_headnode_current, paste);
				longpress_fit();
				*p_judge_paste = CUT_BTN;
				return CUT_BTN;
			}
			else
			{
				return BTN_NO_USE;
			}
			// break;
		case 2: /* 复制 */
			if (getonebit(state_menu, 2) == 1)
			{
				func_copy(*p_headnode_current, paste);
				longpress_fit();
				*p_judge_paste = COPY_BTN;
				return COPY_BTN;
			}
			else
			{
				return BTN_NO_USE;
			}
			// break;
		case 3: /* 删除 */
			if (getonebit(state_menu, 3) == 1)
			{
				func_delete(*p_headnode_current);
				longpress_fit();
				return DELETE_BTN;
			}
			else
			{
				return BTN_NO_USE;
			}
			// break;
		case 4: /* 重命名 */
			if (getonebit(state_menu, 4) == 1)
			{
				longpress_fit();
				return RENAME_BTN;
			}
			else
			{
				return BTN_NO_USE;
			}
			// break;
		case 5: /* 属性 */
			if (getonebit(state_menu, 5) == 1)
			{
				longpress_fit();
				func_attridisplay((*p_headnode_current));
				return ATTRI_BTN;
			}
			else
			{
				return BTN_NO_USE;
			}
			// break;
		default:
			break;
		}
	case DIR_MENU:
		switch (num)
		{
		case 1: /* 显示 */
			if (getonebit(state_menu, 1) == 1)
			{
				longpress_fit();
				return func_sonmenu(1, x1, y, textipt, state_btn, page, p_headnode_current, ph, p_judge_sort);
			}
			else
			{
				return BTN_NO_USE;
			}
			// break;
		case 2: /* 排序 */
			if (getonebit(state_menu, 2) == 1)
			{
				longpress_fit();
				return func_sonmenu(2, x1, y, textipt, state_btn, page, p_headnode_current, ph, p_judge_sort);
			}
			else
			{
				return BTN_NO_USE;
			}
			// break;
		case 3: /* 刷新 */
			if (getonebit(state_menu, 3) == 1)
			{
				longpress_fit();
				func_refresh(*p_headnode_current, ph);
				return REFRESH_BTN;
			}
			else
			{
				return BTN_NO_USE;
			}
			// break;
		case 4: /* 新建 */
			if (getonebit(state_menu, 4) == 1)
			{
				longpress_fit();
				return func_sonmenu(4, x1, y, textipt, state_btn, page, p_headnode_current, ph, p_judge_sort);
			}
			else
			{
				return BTN_NO_USE;
			}
			// break;
		case 5: /* 粘贴 */
			if (getonebit(state_menu, 5) == 1)
			{
				longpress_fit();
				func_paste(*p_headnode_current, ph_for_paste, paste, *p_judge_paste);
				return PASTE_BTN;
			}
			else
			{
				return BTN_NO_USE;
			}
			// break;
		default:
			break;
		}
		// break;
	default:
		return BTN_NO_USE;
	}
}

void setstate_menu(State *p_state_menu, int mode, My_vector_ *paste, My_filenode *headnode_current)
{
	if (mode == FILE_MENU)
	{
		My_filenode *ttnode;
		int num;

		num = 0;
		for (ttnode = headnode_current->next; ttnode != NULL; ttnode = ttnode->next)
		{
			if (getonebit(ttnode->flag, 1) == 1)
			{
				num++;
			}
		}
		if (num == 1)
		{
			set1onebit(p_state_menu, 1);
			set1onebit(p_state_menu, 2);
			set1onebit(p_state_menu, 3);
			set1onebit(p_state_menu, 4);
			set1onebit(p_state_menu, 5);
		}
		else
		{
			set1onebit(p_state_menu, 1);
			set1onebit(p_state_menu, 2);
			set1onebit(p_state_menu, 3);
			set0onebit(p_state_menu, 4);
			set0onebit(p_state_menu, 5);
		}
	}
	else
	{
		set1onebit(p_state_menu, 1);
		set1onebit(p_state_menu, 2);
		set1onebit(p_state_menu, 3);
		set1onebit(p_state_menu, 4);

		if (count_nodes(paste) == 0) //剪切板没有内容
		{
			set0onebit(p_state_menu, 5);
		}
		else
		{
			set1onebit(p_state_menu, 5);
		}
	}
}

void getxy_sonmenu(int *xy, int direct, int x1, int x2, int y, int btnnum)
{
	if (direct == RIGHT)
	{
		xy[0] = x2 + 1;
		xy[2] = x2 + WIDTH_MENU_DIR + 2;
	}
	else
	{
		xy[0] = x1 - WIDTH_MENU_DIR + 2;
		xy[2] = x1;
	}
	xy[1] = y - 1;
	xy[3] = y + getnum_sonmenunum(btnnum) * 21 + 1;
}

int getnum_sonmenunum(int no)
{
	switch (no)
	{
	case 1:
		return 2;
		// break;
	case 2:
		return 6;
		// break;
	case 4:
		return 2;
	// break;
	default:
		return 0;
	}
}

void draw_sonmenu(int menuno, int x1, int x2, int y)
{
	int direct;
	int xy[4];
	int btnnum;
	int color;
	int i;
	int x_, y_;
	char built[3][10] = {"文件", "文件夹"};
	char sort[6][10] = {"按名称正", "按名称倒", "按日期正", "按日期倒", "按大小正", "按大小倒"};
	char dspl[2][10] = {"详细信息", "缩略显示"};
	char(*pname)[10];
	if (menuno == 1)
	{
		btnnum = 2;
		pname = dspl;
	}
	else if (menuno == 4)
	{
		btnnum = 2;
		pname = built;
	}
	else if (menuno == 2)
	{
		btnnum = 6;
		pname = sort;
	}
	direct = getdirect_sonmenu(WIDTH_MENU_DIR + 2, x2);
	getxy_sonmenu(xy, direct, x1, x2, y, menuno);

	clrmous(MouseX, MouseY);
	record_imagedata(xy[0], xy[1], xy[2] + 2, xy[3] + 2, "IMDATA_5");
	setfillstyle(SOLID_FILL, RGB000000);
	bar(xy[0] + 2, xy[1] + 2, xy[2], xy[3]);
	setfillstyle(SOLID_FILL, RGBfffbf0);
	bar(xy[0], xy[1], xy[2] - 2, xy[3] - 2);
	setcolor(RGBa0a0a4);
	rectangle(xy[0], xy[1], xy[2] - 2, xy[3] - 2);
	x_ = xy[0] + 17;
	y_ = xy[1] + 6;
	for (i = 0; i < btnnum; i++)
	{
		put12hz(x_, y_, pname[i], 13, RGB000000);
		y_ += 21;
	}
}

int do_sonmenu(int num, int funcnum, char *textipt, State *state_btn, unsigned char *page, My_filenode **p_headnode_current, My_filenode *ph, int *judge_sort)
{
	void (*draw_mainfile)(int x1, int y1, struct My_filenode *headnode,
						  int n, int state, int page); //函数指针
	Funcdata data_current;
	getfuncdata(&data_current, &draw_mainfile, p_headnode_current, ph);
	switch (num)
	{
	case 1:
		switch (funcnum)
		{
		case 1:
			func_setdisplay_list(state_btn, page, ph, *p_headnode_current);
			longpress_fit();
			return (LISTDISPLAY_BTN);
			// break;
		case 2:
			func_setdisplay_icon(state_btn, page, ph, *p_headnode_current);
			longpress_fit();
			return (ICONDISPLAY_BTN);
		// break;
		default:
			return BTN_NO_USE;
		}
		//	break;
	case 4:
		switch (funcnum)
		{
		case 1:
			func_newfile(*p_headnode_current, textipt, data_current.maxnum_currenttype, data_current.x0, data_current.y0, data_current.height, data_current.width, data_current.space_x_n, data_current.space_y_n, data_current.space_x_ico, data_current.space_y_ico, data_current.displaytype_main);
			return NEWFILE_BTN;
			// break;
		case 2:
			func_newdir(*p_headnode_current, textipt, data_current.maxnum_currenttype, data_current.x0, data_current.y0, data_current.height, data_current.width, data_current.space_x_n, data_current.space_y_n, data_current.space_x_ico, data_current.space_y_ico, data_current.displaytype_main);
			return NEWDIR_BTN;
		// break;
		default:
			return BTN_NO_USE;
		}
		//	break;
	case 2:
		switch (funcnum)
		{
		case 1:
			My_sort(*p_headnode_current, 1);
			*judge_sort = 1;
			longpress_fit();
			return 10;
			// break;
		case 2:
			My_sort(*p_headnode_current, 2);
			*judge_sort = 1;
			longpress_fit();
			return 10;
			// break;
		case 3:
			My_sort(*p_headnode_current, 3);
			*judge_sort = 1;
			longpress_fit();
			return 10;
			// break;
		case 4:
			My_sort(*p_headnode_current, 4);
			*judge_sort = 1;
			longpress_fit();
			return 10;
			// break;
		case 5:
			My_sort(*p_headnode_current, 5);
			*judge_sort = 1;
			longpress_fit();
			// break;
			return 10;
		case 6:
			My_sort(*p_headnode_current, 6);
			*judge_sort = 1;
			longpress_fit();
			// break;
			return 10;
		default:
			break;
		}
		return BTN_NO_USE;
	default:
		return BTN_NO_USE;
	}
}
int func_sonmenu(int num, int x0, int y0, char *textipt, State *state_btn, unsigned char *page, My_filenode **p_headnode_current, My_filenode *ph, int *p_judge_sort)
{
	int direct;
	int xy[4];
	int x[2], y;
	int width;
	int num_btn, maxnum, btnnum;
	width = WIDTH_MENU_DIR + 2;
	// height = HEIGHT_MENU_DIR + 2;
	x[0] = x0;
	x[1] = x0 + width - 2;
	y = y0 + 21 * (num - 1) + 1; //纵坐标位置

	direct = getdirect_sonmenu(width, x[1]);
	getxy_sonmenu(xy, direct, x[0], x[1], y, num);
	draw_sonmenu(num, x[0], x[1], y);

	if (num == 1)
	{
		maxnum = 2;
	}
	else if (num == 4)
	{
		maxnum = 2;
	}
	else if (num == 2)
	{
		maxnum = 6;
	}

	while (testmouse_bar(xy[0], xy[1], xy[2] - 2, xy[3] - 2, MOUSETEST_ALL) != MOUSE_OUTBAR_L)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (testmouse_inoutbar(xy[0], xy[1], xy[2] - 2, xy[3] - 2) == 1)
		{
			num_btn = (MouseY - xy[1]) / 21 + 1;

			if (num_btn > maxnum)
			{
				num_btn = maxnum;
			}
			if (testmouse_bar(xy[0], xy[1], xy[2], xy[3], MOUSETEST_INBAR) == MOUSE_INBAR_L)
			{
				btnnum = do_sonmenu(num, num_btn, textipt, state_btn, page, p_headnode_current, ph, p_judge_sort);
				clrmous(MouseX, MouseY);
				write_imagedata(xy[0], xy[1], xy[2] + 2, xy[3] + 2, "IMDATA_5");
				return btnnum;
			}
		}
		if (testmouse_bar(xy[0], xy[1], xy[2], xy[3], MOUSETEST_ALL) == MOUSE_OUTBAR_L)
		{
			longpress_fit();
			clrmous(MouseX, MouseY);
			write_imagedata(xy[0], xy[1], xy[2] + 2, xy[3] + 2, "IMDATA_5");
			return BTN_NO_USE;
		}
	}
	return BTN_NO_USE;
}

void draw_history(struct My_vector_ *history, int *xy)
{
	struct My_vector_ *ttnode;
	const int height = 16;
	int num;
	int x, y;
	int i;

	// setcolor(RGB000000);
	setfillstyle(SOLID_FILL, RGB000000);
	num = count_nodes(history->next);
	clrmous(MouseX, MouseY);
	record_imagedata(xy[0], xy[1], xy[2] + 2, xy[3] + 2, "IMDATA_6");
	bar(xy[0] + 2, xy[1] + 2, xy[2], xy[3]);
	setfillstyle(SOLID_FILL, RGBfffbf0);
	bar(xy[0], xy[1], xy[2] - 2, xy[3] - 2);
	setcolor(RGBa0a0a4);
	rectangle(xy[0], xy[1], xy[2] - 2, xy[3] - 2);
	x = xy[0] + height - 2;
	y = xy[1] + 4;
	for (i = 0; i < num; i++)
	{
		ttnode = count_to_node(history->next, i + 1);
		settextstyle(0, 0, 0);
		setcolor(RGB000000);
		outtextxy(x, y, ttnode->name);
		y += height;
	}
}
int *getxy_history(int *xy, struct My_vector_ *history)
{
	const int height = 16;
	const int width = 200;
	int num;
	xy[0] = 5;
	xy[1] = 163;
	num = count_nodes(history->next);
	xy[3] = xy[1] + height * num + 2;
	xy[2] = xy[0] + width + 2;
	return xy;
}

int func_history(struct My_vector_ *history, struct My_vector_ **pcurrenthead, struct My_filenode **pch, struct My_filenode *ph, int *xy)
{
	struct My_filenode *ttnode;
	const int height = 16;
	// const int width = 200;
	int num;

	while (testmouse_bar(xy[0], xy[1], xy[2] - 2, xy[3] - 2, MOUSETEST_ALL) != MOUSE_OUTBAR_L)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (testmouse_inoutbar(xy[0], xy[1], xy[2] - 2, xy[3] - 2) == 1)
		{
			num = (MouseY - xy[1]) / height + 1;
			if (num > count_nodes(history->next))
			{
				num = count_nodes(history->next);
			}
			if (testmouse_bar(xy[0], xy[1], xy[2], xy[3], MOUSETEST_INBAR) == MOUSE_INBAR_L)
			{
				// printf("%d->", num);
				// ttnode = vector_to_filenode(ph, count_to_node(history->next, num));
				// printf("%s|", count_to_node(history->next, num)->name);
				// printf("%s\n", count_to_node(history->next, num)->path);
				// printf("%s\n", ph->name);
				// printf("%s\n", ttnode->name);

				// move_dir(history, pcurrenthead, 'n', vector_to_filenode(ph, count_to_node(history->next, num)));
				// *pch = find_node_by_path(ph, (*pcurrenthead)->path);
				// printf("%s\n", (*pch)->father->name);
				// settype_dirdisplay(&((*pch)->flag), gettype_dirdisplay(ph->flag));

				*pch = find_node_by_path(ph, count_to_node(history->next, num)->path);
				move_dir(history, pcurrenthead, 'n', (*pch)->father);
				settype_dirdisplay(&((*pch)->flag), gettype_dirdisplay(ph->flag));

				// move_dir(history, p_currenthead, 'n');
				// *p_headnode_current = find_node_by_path(ph, (*p_currenthead)->path);
				// settype_dirdisplay(&((*p_headnode_current)->flag), gettype_dirdisplay(ph->flag));

				clrmous(MouseX, MouseY);
				write_imagedata(xy[0], xy[1], xy[2] + 2, xy[3] + 2, "IMDATA_6");
				// return DOWN_ARROW_BTN;
				longpress_fit();
				return (num + 1);
			}
		}

		if (testmouse_bar(xy[0], xy[1], xy[2], xy[3], MOUSETEST_ALL) == MOUSE_OUTBAR_L)
		{
			clrmous(MouseX, MouseY);
			write_imagedata(xy[0], xy[1], xy[2] + 2, xy[3] + 2, "IMDATA_6");
			longpress_fit();
			return -1;
		}
	}
	return -1;
}