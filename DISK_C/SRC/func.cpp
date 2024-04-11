
#include "func.h"

void func_setdisplay_list(State *state, char *page, My_filenode *ph, My_filenode *headnode_current)
{
	setonebit(&state[LISTDISPLAY_BTN], IFC_L, getonebit(state[LISTDISPLAY_BTN], IFC_N));
	setonebit(&state[LISTDISPLAY_BTN], IFC_N, 1); //图标选中

	setonebit(&state[ICONDISPLAY_BTN], IFC_L, getonebit(state[ICONDISPLAY_BTN], IFC_N));
	setonebit(&state[ICONDISPLAY_BTN], IFC_N, 0); //图标不选中

	/*功能模块调用*/
	settype_dirdisplay(&(ph->flag), TYPE_LIST_DISPLAY);
	settype_dirdisplay(&(headnode_current->flag), TYPE_LIST_DISPLAY);
	page[MAINFILE_NUMBAR] = 0;
}

void func_setdisplay_icon(State *state, char *page, My_filenode *ph, My_filenode *headnode_current)
{
	setonebit(&state[ICONDISPLAY_BTN], IFC_L, getonebit(state[ICONDISPLAY_BTN], IFC_N));
	setonebit(&state[ICONDISPLAY_BTN], IFC_N, 1); //图标选中

	setonebit(&state[LISTDISPLAY_BTN], IFC_L, getonebit(state[LISTDISPLAY_BTN], IFC_N));
	setonebit(&state[LISTDISPLAY_BTN], IFC_N, 0); //图标不选中

	/*功能模块调用*/
	settype_dirdisplay(&(ph->flag), TYPE_SUPERICON_DISPLAY);
	settype_dirdisplay(&(headnode_current->flag), TYPE_SUPERICON_DISPLAY);
	page[MAINFILE_NUMBAR] = 0;
}

void func_changedir_father(My_filenode **p_headnode_current, My_filenode *ph, My_vector_ **p_currenthead, My_vector_ *history, char *page)
{
	move_dir(history, p_currenthead, 'n', (*p_headnode_current)->father->father);
	*p_headnode_current = find_node_by_path(ph, (*p_currenthead)->path);
	settype_dirdisplay(&((*p_headnode_current)->flag), gettype_dirdisplay(ph->flag));
	page[MAINFILE_NUMBAR] = 0;
}

void func_refresh(My_filenode *headnode_current, My_filenode *ph)
{
	if (headnode_current != ph)
	{
		My_filenode *ttnode;
		ttnode = end_of_list(headnode_current);
		new_file(headnode_current, "_reflsh_", 0);
		delet_next_node(ttnode);
	}
}

void func_changedir_last(My_filenode **p_headnode_current, My_filenode *ph, My_vector_ **p_currenthead, My_vector_ *history, char *page)
{
	move_dir(history, p_currenthead, 'f');
	*p_headnode_current = find_node_by_path(ph, (*p_currenthead)->path);
	settype_dirdisplay(&((*p_headnode_current)->flag), gettype_dirdisplay(ph->flag));
	page[MAINFILE_NUMBAR] = 0;
}

void func_changedir_next(My_filenode **p_headnode_current, My_filenode *ph, My_vector_ **p_currenthead, My_vector_ *history, char *page)
{
	move_dir(history, p_currenthead, 'n');
	*p_headnode_current = find_node_by_path(ph, (*p_currenthead)->path);
	settype_dirdisplay(&((*p_headnode_current)->flag), gettype_dirdisplay(ph->flag));
	page[MAINFILE_NUMBAR] = 0;
}

void func_copy(My_filenode *headnode_current, My_vector_ *paste)
{
	My_filenode *ttnode;
	free_vector_list(paste);
	for (ttnode = (headnode_current)->next; ttnode != NULL; ttnode = ttnode->next)
	{
		if (getonebit(ttnode->flag, 1) == 1)
		{
			add_to_vector_(paste, ttnode);
		}
	}
}

void func_paste(My_filenode *headnode_current, My_filenode *ph_for_paste, My_vector_ *paste, int judge_paste)
{
	if (judge_paste == COPY_BTN)
	{
		My_paste(paste, headnode_current, ph_for_paste);
	}
	else if (judge_paste == CUT_BTN)
	{
		My_cut(paste, headnode_current, ph_for_paste);
	}
}

void func_cut(My_filenode *headnode_current, My_vector_ *paste)
{
	My_filenode *ttnode;
	free_vector_list(paste);
	for (ttnode = (headnode_current)->next; ttnode != NULL; ttnode = ttnode->next)
	{
		if (getonebit(ttnode->flag, 1) == 1)
		{
			add_to_vector_(paste, ttnode);
		}
	}
}

void func_delete(My_filenode *headnode_current)
{
	My_filenode *ttnode_1, *ttnode_2;
	ttnode_1 = headnode_current;
	ttnode_2 = ttnode_1->next;
	do
	{
		if (getonebit(ttnode_2->flag, 1) == 1)
		{
			delet_next_node(ttnode_1);
			if (ttnode_1->next == ttnode_2)
			{
				return;
			}
			ttnode_2 = ttnode_1->next;
		}
		else
		{
			ttnode_1 = ttnode_1->next, ttnode_2 = ttnode_2->next;
		}
	} while (ttnode_2 != NULL);
}

void func_rename(My_filenode *headnode_current, char *textipt, int x0, int y0,
				 int height, int width, int space_x_n, int space_y_n, int displaytype_main,
				 char *page, void (*draw_mainfile)(int x1, int y1, struct My_filenode *headnode, int n, int state, int page))
{
	int i, j;
	struct My_filenode *ttnode;
	int *lc;
	char newname[15];
	int maxnum_current;
	int num;
	if (displaytype_main == TYPE_LIST_DISPLAY)
	{
		maxnum_current = MAXFILENUM_LIST;
	}
	else
	{
		maxnum_current = MAXFILENUM_ICON_SUPER;
	}

	for (i = 1; i <= maxnum_current; i++)
	{
		num = i + maxnum_current * page[MAINFILE_NUMBAR];
		ttnode = count_to_node(headnode_current, num); //第i个节点（文件）
		if (getonebit(ttnode->flag, 1) == 1)		   //如果找到一个被选中了
		{
			/* 输入模式，记录其新文件名 */
			lc = get_lc_maindisplay(displaytype_main, i);
			setcolor(RGB000000);
			setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
			record_imagedata(x0 + lc[COLUMN] * width + space_x_n - 2 - 1, y0 + lc[LINE] * height + space_y_n - 2 - 1,
							 x0 + lc[COLUMN] * width + space_x_n + 13 * 8 + 2, y0 + lc[LINE] * height + space_y_n + 8 + 2,
							 "IMDATA_5");
			rectangle(x0 + lc[COLUMN] * width + space_x_n - 2 - 1, y0 + lc[LINE] * height + space_y_n - 2 - 1,
					  x0 + lc[COLUMN] * width + space_x_n + 13 * 8 + 1, y0 + lc[LINE] * height + space_y_n + 8 + 1);
			keybdintraction(textipt, x0 + lc[COLUMN] * width + space_x_n, y0 + lc[LINE] * height + space_y_n,
							x0 + lc[COLUMN] * width + space_x_n - 2, y0 + lc[LINE] * height + space_y_n - 2,
							x0 + lc[COLUMN] * width + space_x_n + 13 * 8, y0 + lc[LINE] * height + space_y_n + 8,
							8, RGBffffff, 12, TEXTNOTDISPLAY, 0);
			/* 相应文件操作和链表设置 */
			for (i = 0; i < 12 && textipt[i] != '.'; i++)
			{
				newname[i] = textipt[i];
			}
			newname[i] = '\0';
			if (strlen(newname) <= 8) //判断名称是否越界
			{
				if (textipt[0] == '\0')
				{
					write_imagedata(x0 + lc[COLUMN] * width + space_x_n - 2 - 1, y0 + lc[LINE] * height + space_y_n - 2 - 1,
									x0 + lc[COLUMN] * width + space_x_n + 13 * 8 + 2, y0 + lc[LINE] * height + space_y_n + 8 + 2,
									"IMDATA_5");
				}
				else
				{
					textipt[13] = '\0';
					strcpy(newname, textipt);
					My_rename(ttnode, newname);			  //重命名
					for (j = 1; j <= maxnum_current; j++) //刷新文件显示
					{
						num = j + maxnum_current * page[MAINFILE_NUMBAR];
						ttnode = count_to_node(headnode_current, num);
						clrmous(MouseX, MouseY);
						lc = get_lc_maindisplay(displaytype_main, j);
						draw_mainfile(x0 + lc[COLUMN] * width, y0 + lc[LINE] * height, headnode_current, j, 0, page[MAINFILE_NUMBAR]);
					}
				}
			}
			else
			{
				pop_error(0, "func_rename", "Too long name.", "Input shorter one.");
				for (j = 1; j <= maxnum_current; j++) //刷新文件显示
				{
					num = j + maxnum_current * page[MAINFILE_NUMBAR];
					ttnode = count_to_node(headnode_current, num);
					clrmous(MouseX, MouseY);
					lc = get_lc_maindisplay(displaytype_main, j);
					draw_mainfile(x0 + lc[COLUMN] * width, y0 + lc[LINE] * height, headnode_current, j, 0, page[MAINFILE_NUMBAR]);
				}
			}
			break;
		}
	}
}

void func_newdir(My_filenode *headnode_current, char *textipt, int maxnum_currenttype, int x0, int y0,
				 int height, int width, int space_x_n, int space_y_n, int space_x_ico, int space_y_ico, int displaytype_main)
{
	int num_node;
	int *lc;
	num_node = count_nodes(headnode_current); //获得有效节点数，从而确定输入框位置
	num_node %= maxnum_currenttype;
	/*功能模块调用*/
	lc = get_lc_maindisplay(displaytype_main, num_node + 1);
	longpress_fit(); //长按适配
	diricodraw_o(x0 + lc[COLUMN] * width + space_x_ico, y0 + lc[LINE] * height + space_y_ico, displaytype_main);
	setcolor(RGB000000);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	rectangle(x0 + lc[COLUMN] * width + space_x_n - 2 - 1, y0 + lc[LINE] * height + space_y_n - 2 - 1,
			  x0 + lc[COLUMN] * width + space_x_n + 13 * 8 + 1, y0 + lc[LINE] * height + space_y_n + 8 + 1);
	keybdintraction(textipt, x0 + lc[COLUMN] * width + space_x_n, y0 + lc[LINE] * height + space_y_n,
					x0 + lc[COLUMN] * width + space_x_n - 2, y0 + lc[LINE] * height + space_y_n - 2,
					x0 + lc[COLUMN] * width + space_x_n + 13 * 8, y0 + lc[LINE] * height + space_y_n + 8,
					8, RGBffffff, 12, TEXTNOTDISPLAY, 0);

	if (strlen(textipt) <= 8)
	{
		if (textipt[0] == '\0')
		{
			strcpy(textipt, "NEW");
		}
		else
		{
			textipt[13] = '\0';
		}
		new_file(headnode_current, textipt, 1); //有缺陷
	}
	else
	{
		pop_error(0, "FUNC_NEWDIR:", "Too long name.", "Input shorter one.");
	}
}

void func_newfile(My_filenode *headnode_current, char *textipt, int maxnum_currenttype, int x0, int y0, int height, int width,
				  int space_x_n, int space_y_n, int space_x_ico, int space_y_ico, int displaytype_main)
{
	int num_node;
	int *lc;
	int i;
	char newname[15];
	num_node = count_nodes(headnode_current); //获得有效节点数，从而确定输入框位置

	num_node %= maxnum_currenttype;

	lc = get_lc_maindisplay(displaytype_main, num_node + 1);
	longpress_fit(); //长按适配
	filebasicdraw_o(x0 + lc[COLUMN] * width + space_x_ico, y0 + lc[LINE] * height + space_y_ico, displaytype_main);
	setcolor(RGB000000);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	rectangle(x0 + lc[COLUMN] * width + space_x_n - 2 - 1, y0 + lc[LINE] * height + space_y_n - 2 - 1,
			  x0 + lc[COLUMN] * width + space_x_n + 13 * 8 + 1, y0 + lc[LINE] * height + space_y_n + 8 + 1);
	keybdintraction(textipt, x0 + lc[COLUMN] * width + space_x_n, y0 + lc[LINE] * height + space_y_n,
					x0 + lc[COLUMN] * width + space_x_n - 2, y0 + lc[LINE] * height + space_y_n - 2,
					x0 + lc[COLUMN] * width + space_x_n + 13 * 8, y0 + lc[LINE] * height + space_y_n + 8,
					8, RGBffffff, 12, TEXTNOTDISPLAY, 0);
	for (i = 0; i < 12 && textipt[i] != '.'; i++)
	{
		newname[i] = textipt[i];
	}
	newname[i] = '\0';
	if (strlen(newname) <= 8) //判断名称是否越界
	{
		if (strlen(textipt) <= 12)
		{
			if (textipt[0] == '\0')
			{
				strcpy(textipt, "NEW");
			}
			else
			{
				textipt[13] = '\0';
			}
			new_file(headnode_current, textipt, 0);
		}
		else
		{
			pop_error(0, "FUNC_NEWFILE:", "Too long name.", "Input shorter one.");
		}
	}
	else
	{
		pop_error(0, "FUNC_NEWFILE:", "Too long name.", "Input shorter one.");
	}
}

void func_attridisplay(My_filenode *headnode_current)
{
	My_filenode *ttnode;
	for (ttnode = headnode_current->next; ttnode != NULL; ttnode = ttnode->next)
	{
		if (getonebit(ttnode->flag, 1) == 1)
		{
			pop_properties(ttnode);
			return;
		}
	}
}

void func_chall(State *state, My_filenode *headnode_current, My_filenode *ph, My_filenode *pc_for_dir,
				My_vector_ *currenthead, My_vector_ *history, My_vector_ *search, My_vector_ *paste, int maxfilenum, int height,
				int width, int x0, int y0, int displaytype_main, Bit *dsplstate_main, char *page, int judge_search,
				void (*draw_mainfile)(int x1, int y1, struct My_filenode *headnode, int n, int state, int page))
{
	unsigned char i;
	int *lc;
	select_all(headnode_current);
	for (i = 1; i <= maxfilenum; i++) //再刷新状态
	{
		clrmous(MouseX, MouseY);
		lc = get_lc_maindisplay(displaytype_main, i);
		draw_mainfile(x0 + lc[COLUMN] * width, y0 + lc[LINE] * height, headnode_current, i, 0, page[MAINFILE_NUMBAR]);
		set1onebit(dsplstate_main, i);
	}
	display_choosenum(headnode_current);
	testbtnstate_setgbl(state, headnode_current, history, search, ph, pc_for_dir->son_list_head, paste, currenthead, page, judge_search);
}

void func_clrall(State *state, My_filenode *headnode_current, My_filenode *ph, My_filenode *pc_for_dir,
				 My_vector_ *currenthead, My_vector_ *history, My_vector_ *search, My_vector_ *paste, int maxfilenum, int height,
				 int width, int x0, int y0, int displaytype_main, Bit *dsplstate_main, char *page, int judge_search,
				 void (*draw_mainfile)(int x1, int y1, struct My_filenode *headnode, int n, int state, int page))
{
	unsigned char i;
	int *lc;
	unselect_all(headnode_current);
	for (i = 1; i <= maxfilenum; i++) //再刷新状态
	{
		clrmous(MouseX, MouseY);
		lc = get_lc_maindisplay(displaytype_main, i);
		draw_mainfile(x0 + lc[COLUMN] * width, y0 + lc[LINE] * height, headnode_current, i, 0, page[MAINFILE_NUMBAR]);
		set0onebit(dsplstate_main, i);
	}
	display_choosenum(headnode_current);
	testbtnstate_setgbl(state, headnode_current, history, search, ph, pc_for_dir->son_list_head, paste, currenthead, page, judge_search);
}

void func_chctry(State *state, My_filenode *headnode_current, My_filenode *ph, My_filenode *pc_for_dir,
				 My_vector_ *currenthead, My_vector_ *history, My_vector_ *search, My_vector_ *paste, int maxfilenum, int height,
				 int width, int x0, int y0, int displaytype_main, Bit *dsplstate_main, char *page, int judge_search,
				 void (*draw_mainfile)(int x1, int y1, struct My_filenode *headnode, int n, int state, int page))
{
	unsigned char i;
	int *lc;
	inverse_select_all(headnode_current);
	for (i = 1; i <= maxfilenum; i++) //再刷新状态
	{
		clrmous(MouseX, MouseY);
		lc = get_lc_maindisplay(displaytype_main, i);
		draw_mainfile(x0 + lc[COLUMN] * width, y0 + lc[LINE] * height, headnode_current, i, 0, page[MAINFILE_NUMBAR]);
		reverseonebit(dsplstate_main, i);
	}
	display_choosenum(headnode_current);
	testbtnstate_setgbl(state, headnode_current, history, search, ph, pc_for_dir->son_list_head, paste, currenthead, page, judge_search);
}

void getfuncdata(Funcdata *func_current, void (**draw_mainfile)(int x1, int y1, struct My_filenode *headnode, int n, int state, int page), My_filenode **p_headnode_current, My_filenode *ph)
{
	func_current->displaytype_main = gettype_mainfile_display(*p_headnode_current, ph);

	func_current->maxfilenum = count_nodes(*p_headnode_current);
	switch (func_current->displaytype_main) //根据不同模式进行相应检测和设置
	{
	case TYPE_LIST_DISPLAY:
		*draw_mainfile = draw_main_file1;
		func_current->x0 = X_MAINFILE_LIST;
		func_current->y0 = Y_MAINFILE_LIST;
		func_current->width = 0;
		func_current->height = HEIGHT_MAINFILE_LIST;
		if (func_current->maxfilenum > MAXFILENUM_LIST)
		{
			func_current->maxfilenum = MAXFILENUM_LIST;
		}
		func_current->space_x_n = 35;
		func_current->space_y_n = 10;
		func_current->space_x_ico = 5;
		func_current->space_y_ico = 3;
		func_current->maxnum_currenttype = MAXFILENUM_LIST;
		break;
	case TYPE_SUPERICON_DISPLAY:
		*draw_mainfile = draw_main_file2;
		func_current->x0 = X_MAINFILE_ICON_SUOER;
		func_current->y0 = Y_MAINFILE_ICON_SUOER;
		func_current->width = WIDTH_MAINFILE_ICON_SUPER + SPACE_X_MAINFILE_ICON_SUPER;
		func_current->height = HEIGHT_MAINFILE_ICON_SUPER + SPACE_Y_MAINFILE_ICON_SUPER;
		func_current->space_x_n = 15;
		func_current->space_y_n = 152;
		func_current->space_x_ico = 21;
		func_current->space_y_ico = 14;
		if (func_current->maxfilenum > MAXFILENUM_ICON_SUPER)
		{
			func_current->maxfilenum = MAXFILENUM_ICON_SUPER;
		}
		func_current->maxnum_currenttype = MAXFILENUM_ICON_SUPER;
		break;
	default:
		pop_error(-1, "TESTDO_MAINBT:", "Assignment error.");
		exit(1);
		break;
	}
}

int getnum_choose(My_filenode *headnode_current)
{
	My_filenode *ttnode;
	int num = 0;
	for (ttnode = (headnode_current)->next; ttnode != NULL; ttnode = ttnode->next)
	{
		if (getonebit(ttnode->flag, 1) == 1)
		{
			num += 1;
		}
	}
	return num;
}
