#include "mfunc.h"

/****************************
 * 初始化按键状态
 * ...为了好改数据...
 * 传递参数：按键状态检测数组首地址
 * 无返回值
 * ***********************/
void initbtnstate(State *state)
{
	state[LISTDISPLAY_BTN] = 0x8c;
	state[ICONDISPLAY_BTN] = 0x80;
	state[UP_ARROE_BTN] = 0x80;
	state[REFRESH_BTN] = 0x80;
	state[L_ARROW_BTN] = 0x80;
	state[MAIN_LASTPAGE_BTN] = 0x80;
	state[MAIN_NEXTPAGE_BTN] = 0x80;
	state[TREE_LASTPAGE_BTN] = 0x80;
	state[TREE_NEXTPAGE_BTN] = 0x80;
	state[R_ARROE_BTN] = 0x80;
	state[CLOSE_BTN] = 0x80;
	state[COPY_BTN] = 0x80;
	state[PASTE_BTN] = 0x80;
	state[CUT_BTN] = 0x80;
	state[DELETE_BTN] = 0x80;
	state[RENAME_BTN] = 0x80;
	state[NEWDIR_BTN] = 0x80;
	state[NEWFILE_BTN] = 0x80;
	state[ATTRI_BTN] = 0x80;
	state[CHALL_BTN] = 0x80;
	state[CLRALL_BTN] = 0x80;
	state[CHCTRY_BTN] = 0x80;
	state[DOWN_ARROW_BTN] = 0x80;
}

/********************************
 * FUNCTION:testbtnstate_mouse
 * DESCRIPTION:检测各个按键关于鼠标的状态
 * INPUT:按键状态检测数组首地址
 * RETURN:无
 * OTHERS:无
 ********************************/
void testbtnstate_mouse(State *state)
{
	testmouse_ico(973, 746, 994, 767, &state[LISTDISPLAY_BTN]);
	testmouse_ico(995, 746, 1016, 767, &state[ICONDISPLAY_BTN]);
	testmouse_ico(100, 139, 123, 160, &state[UP_ARROE_BTN]);
	testmouse_ico(817, 137, 841, 161, &state[REFRESH_BTN]);
	testmouse_ico(5, 139, 31, 160, &state[L_ARROW_BTN]);
	testmouse_ico(56, 139, 82, 160, &state[R_ARROE_BTN]);
	testmouse_ico(940, 746, 966, 767, &state[MAIN_NEXTPAGE_BTN]);
	testmouse_ico(913, 746, 939, 767, &state[MAIN_LASTPAGE_BTN]);
	testmouse_ico(33, 746, 59, 767, &state[TREE_NEXTPAGE_BTN]);
	testmouse_ico(6, 746, 32, 767, &state[TREE_LASTPAGE_BTN]);
	testmouse_ico(988, 0, 1023, 23, &state[CLOSE_BTN]);
	testmouse_ico(9, 31, 71, 111, &state[COPY_BTN]);
	testmouse_ico(72, 31, 131, 111, &state[PASTE_BTN]);
	testmouse_ico(132, 31, 192, 111, &state[CUT_BTN]);
	testmouse_ico(219, 31, 280, 111, &state[DELETE_BTN]);
	testmouse_ico(281, 31, 361, 111, &state[RENAME_BTN]);
	testmouse_ico(395, 31, 456, 111, &state[NEWDIR_BTN]);
	testmouse_ico(457, 31, 519, 111, &state[NEWFILE_BTN]);
	testmouse_ico(548, 31, 609, 111, &state[ATTRI_BTN]);
	testmouse_ico(634, 31, 698, 111, &state[CHALL_BTN]);
	testmouse_ico(699, 31, 763, 111, &state[CLRALL_BTN]);
	testmouse_ico(764, 31, 828, 111, &state[CHCTRY_BTN]);
	testmouse_ico(89, 139, 99, 160, &state[DOWN_ARROW_BTN]);
}

/********************************
 * FUNCTION:testbtnstate_setgbl
 * DESCRIPTION:根据交互/结点内置/设置来设置全局按键显示方式
 * INPUT:按键状态数组地址，主文件头节点，历史记录链表头节点，此电脑指针，C盘指针，粘贴板指针，当前目录指针
 * RETURN:无
 * OTHERS:不包括翻页检测
 ********************************/
//需要修改，防止刷屏，需要将赋值改为按位操作
void testbtnstate_setgbl(State *state, struct My_filenode *headnode_main, struct My_vector_ *history, struct My_vector_ *search,
						 struct My_filenode *ph, struct My_filenode *pc_dir_sonhead, struct My_vector_ *headnode_pasting,
						 struct My_vector_ *currenthead, char *page, int judge_search)
{
	int displaytype_main;
	int ch_num = 0, node_num = 0, node_searchnum;
	int max_filenum;
	struct My_filenode *ttnode;
	/* 检测显示模式 */
	// displaytype_main = gettype_dirdisplay(headnode_main->flag);
	displaytype_main = gettype_mainfile_display(headnode_main, ph);
	switch (displaytype_main)
	{
	case TYPE_LIST_DISPLAY:
		max_filenum = MAXFILENUM_LIST;
		break;
	case TYPE_SUPERICON_DISPLAY:
		max_filenum = MAXFILENUM_ICON_SUPER;
		break;
	default:
		pop_error(-1, "TESTBTNSTATE_SETGBL:", "Assignment error.");
		break;
	}
	if (displaytype_main == TYPE_LIST_DISPLAY)
	{
		if (state[LISTDISPLAY_BTN] != 0x9c)
		{
			state[LISTDISPLAY_BTN] = 0x8c;
		}
		if (state[ICONDISPLAY_BTN] != 0x90)
		{
			state[ICONDISPLAY_BTN] = 0x80;
		}
	}
	else
	{
		if (state[LISTDISPLAY_BTN] != 0x90)
		{
			state[LISTDISPLAY_BTN] = 0x80;
		}
		if (state[ICONDISPLAY_BTN] != 0x9c)
		{
			state[ICONDISPLAY_BTN] = 0x8c;
		}
	}
	/* 检测历史记录是否有前后内容 */
	if (My_count(history, currenthead) < 2) //不可后退(左)
	{
		if (state[L_ARROW_BTN] != 0x10)
		{
			state[L_ARROW_BTN] = 0x00;
		}
		if (state[DOWN_ARROW_BTN] != 0x10)
		{
			state[DOWN_ARROW_BTN] = 0x00;
		}
	}
	else
	{
		if (state[L_ARROW_BTN] != 0x90)
		{
			state[L_ARROW_BTN] = 0x80;
		}
		if (state[DOWN_ARROW_BTN] != 0x90)
		{
			state[DOWN_ARROW_BTN] = 0x80;
		}
	}
	if (currenthead->next == NULL) //不可前进（右）
	{
		if (state[R_ARROE_BTN] != 0x10)
		{
			state[R_ARROE_BTN] = 0x00;
		}
	}
	else
	{
		if (state[R_ARROE_BTN] != 0x90)
		{
			state[R_ARROE_BTN] = 0x80;
		}
	}
	/* 检测树形文件区翻页并设置 */
	if (!(page[TREEFILE_NUMBAR] > 0))
	{
		if (state[TREE_LASTPAGE_BTN] != 0x10)
		{
			state[TREE_LASTPAGE_BTN] = 0x00;
		}
	}
	else
	{
		if (state[TREE_LASTPAGE_BTN] != 0x90)
		{
			state[TREE_LASTPAGE_BTN] = 0x80;
		}
	}
	if ((getnum_dir_andopen(pc_dir_sonhead) - page[TREEFILE_NUMBAR] * MAXDIRNUM_TREE) / MAXDIRNUM_TREE == 0)
	{
		if (state[TREE_NEXTPAGE_BTN] != 0x10)
		{
			state[TREE_NEXTPAGE_BTN] = 0x00;
		}
	}
	else
	{
		if (state[TREE_NEXTPAGE_BTN] != 0x90)
		{
			state[TREE_NEXTPAGE_BTN] = 0x80;
		}
	}
	/* 检测当前显示目录是否为根目录（结点是否为此电脑） */
	if (headnode_main == ph || judge_search != 0)
	{
		/* 不可点击 */
		if (state[COPY_BTN] != 0x10)
		{
			state[COPY_BTN] = 0x00;
		}
		if (state[PASTE_BTN] != 0x10)
		{
			state[PASTE_BTN] = 0x00;
		}
		if (state[CUT_BTN] != 0x10)
		{
			state[CUT_BTN] = 0x00;
		}
		if (state[DELETE_BTN] != 0x10)
		{
			state[DELETE_BTN] = 0x00;
		}
		if (state[RENAME_BTN] != 0x10)
		{
			state[RENAME_BTN] = 0x00;
		}
		if (state[NEWDIR_BTN] != 0x10)
		{
			state[NEWDIR_BTN] = 0x00;
		}
		if (state[NEWFILE_BTN] != 0x10)
		{
			state[NEWFILE_BTN] = 0x00;
		}
		if (state[CHALL_BTN] != 0x10)
		{
			state[CHALL_BTN] = 0x00;
		}
		if (state[CLRALL_BTN] != 0x10)
		{
			state[CLRALL_BTN] = 0x00;
		}
		if (state[CHCTRY_BTN] != 0x10)
		{
			state[CHCTRY_BTN] = 0x00;
		}
		if (state[UP_ARROE_BTN] != 0x10)
		{
			state[UP_ARROE_BTN] = 0x00;
		}
		if (state[MAIN_NEXTPAGE_BTN] != 0x10)
		{
			state[MAIN_NEXTPAGE_BTN] = 0x00;
		}
		if (state[MAIN_LASTPAGE_BTN] != 0x10)
		{
			state[MAIN_LASTPAGE_BTN] = 0x00;
		}
		if (state[MAIN_NEXTPAGE_BTN] != 0x10)
		{
			state[MAIN_NEXTPAGE_BTN] = 0x00;
		}
		if (state[ATTRI_BTN] != 0x10)
		{
			state[ATTRI_BTN] = 0x00;
		}
		if (!(page[SEARCH_NUMBER] > 0))
		{
			if (state[MAIN_LASTPAGE_BTN] != 0x10)
			{
				state[MAIN_LASTPAGE_BTN] = 0x00;
			}
		}
		else
		{
			if (state[MAIN_LASTPAGE_BTN] != 0x90)
			{
				state[MAIN_LASTPAGE_BTN] = 0x80;
			}
		}
		if (judge_search != 0)
		{
			node_searchnum = count_nodes(search);
			if (node_searchnum >= 10)
			{
				if (state[MAIN_NEXTPAGE_BTN] != 0x90)
				{
					state[MAIN_NEXTPAGE_BTN] = 0x80;
				}
			}
			else
			{
				if (state[MAIN_NEXTPAGE_BTN] != 0x10)
				{
					state[MAIN_NEXTPAGE_BTN] = 0x00;
				}
			}
			if (!(page[SEARCH_NUMBER] > 0))
			{
				if (state[MAIN_LASTPAGE_BTN] != 0x10)
				{
					state[MAIN_LASTPAGE_BTN] = 0x00;
				}
			}
			else
			{
				if (state[MAIN_LASTPAGE_BTN] != 0x90)
				{
					state[MAIN_LASTPAGE_BTN] = 0x80;
				}
			}
		}
		return;
	}
	else
	{
		if (state[NEWDIR_BTN] != 0x90)
		{
			state[NEWDIR_BTN] = 0x80;
		}
		if (state[NEWFILE_BTN] != 0x90)
		{
			state[NEWFILE_BTN] = 0x80;
		}
		if (state[CHALL_BTN] != 0x90)
		{
			state[CHALL_BTN] = 0x80;
		}
		if (state[CLRALL_BTN] != 0x90)
		{
			state[CLRALL_BTN] = 0x80;
		}
		if (state[CHCTRY_BTN] != 0x90)
		{
			state[CHCTRY_BTN] = 0x80;
		}
		if (state[UP_ARROE_BTN] != 0x90)
		{
			state[UP_ARROE_BTN] = 0x80;
		}
	}

	/* 检测选中数量 */
	node_num = count_nodes(headnode_main); //有效结点数
	if (node_num > 0)					   //有内容
	{
		ttnode = count_to_node(headnode_main, 1);
		for (ch_num = 0; ttnode != NULL; ttnode = ttnode->next)
		{
			if (getonebit(ttnode->flag, 1) == 1) //被选中
			{
				ch_num++;
			}
		}
		if (ch_num == 0) //没选中任何一个
		{
			/* 不可点击 */
			if (state[COPY_BTN] != 0x10)
			{
				state[COPY_BTN] = 0x00;
			}
			if (state[CUT_BTN] != 0x10)
			{
				state[CUT_BTN] = 0x00;
			}
			if (state[DELETE_BTN] != 0x10)
			{
				state[DELETE_BTN] = 0x00;
			}
			if (state[RENAME_BTN] != 0x10)
			{
				state[RENAME_BTN] = 0x00;
			}
			if (state[ATTRI_BTN] != 0x10)
			{
				state[ATTRI_BTN] = 0x00;
			}
		}
		else //选中了
		{
			if (state[COPY_BTN] != 0x90)
			{
				state[COPY_BTN] = 0x80;
			}
			if (state[CUT_BTN] != 0x90)
			{
				state[CUT_BTN] = 0x80;
			}
			if (state[DELETE_BTN] != 0x90)
			{
				state[DELETE_BTN] = 0x80;
			}
			if (state[RENAME_BTN] != 0x90)
			{
				state[ATTRI_BTN] = 0x80;
				if (ch_num == 1) //仅仅选中一个
				{
					if (state[ATTRI_BTN] != 0x90)
					{
						state[RENAME_BTN] = 0x80;
					}
				}
			}
		}
		/* 翻页按键的设置 */
		if ((node_num - page[MAINFILE_NUMBAR] * max_filenum) / max_filenum == 0) //没有下一页了
		{
			if (state[MAIN_NEXTPAGE_BTN] != 0x10)
			{
				state[MAIN_NEXTPAGE_BTN] = 0x00;
			}
		}
		else
		{
			if (state[MAIN_NEXTPAGE_BTN] != 0x90)
			{
				state[MAIN_NEXTPAGE_BTN] = 0x80;
			}
		}
		if (!(page[MAINFILE_NUMBAR] > 0))
		{
			if (state[MAIN_LASTPAGE_BTN] != 0x10)
			{
				state[MAIN_LASTPAGE_BTN] = 0x00;
			}
		}
		else
		{
			if (state[MAIN_LASTPAGE_BTN] != 0x90)
			{
				state[MAIN_LASTPAGE_BTN] = 0x80;
			}
		}
	}
	else //没有内容
	{
		/* 不可点击 */

		if (state[COPY_BTN] != 0x10)
		{
			state[COPY_BTN] = 0x00;
		}
		if (state[CUT_BTN] != 0x10)
		{
			state[CUT_BTN] = 0x00;
		}
		if (state[DELETE_BTN] != 0x10)
		{
			state[DELETE_BTN] = 0x00;
		}
		if (state[RENAME_BTN] != 0x10)
		{
			state[RENAME_BTN] = 0x00;
		}
		if (state[CHALL_BTN] != 0x10)
		{
			state[CHALL_BTN] = 0x00;
		}
		if (state[CLRALL_BTN] != 0x10)
		{
			state[CLRALL_BTN] = 0x00;
		}
		if (state[CHCTRY_BTN] != 0x10)
		{
			state[CHCTRY_BTN] = 0x00;
		}
		if (state[ATTRI_BTN] != 0x10)
		{
			state[ATTRI_BTN] = 0x00;
		}
		if (state[MAIN_LASTPAGE_BTN] != 0x10)
		{
			state[MAIN_LASTPAGE_BTN] = 0x00;
		}
		if (state[MAIN_NEXTPAGE_BTN] != 0x10)
		{
			state[MAIN_NEXTPAGE_BTN] = 0x00;
		}
	}

	/* 检测粘贴板是否有内容 */
	if (count_nodes(headnode_pasting) == 0) //剪切板没有内容
	{
		if (state[PASTE_BTN] != 0x10)
		{
			state[PASTE_BTN] = 0x00;
		}
	}
	else
	{
		if (state[PASTE_BTN] != 0x90)
		{
			state[PASTE_BTN] = 0x80;
		}
	}
}

/**************************
 * 刷新显示各个按键状态
 * 刷新显示
 * 传递参数：按键状态检测数组
 * 无返回值
 * ***********************/
void refreshbtnstate(State *state)
{
	changedisplay_fixedbt(closeXdraw_o, RGB007fff, RGBd40000, &state[CLOSE_BTN]);
	changedisplay_function(copybtn_draw, RGBfffbf0, RGBccffff, RGB2a7fff, &state[COPY_BTN]);
	changedisplay_function(pastebtn_draw, RGBfffbf0, RGBccffff, RGB2a7fff, &state[PASTE_BTN]);
	changedisplay_function(cutbtn_draw, RGBfffbf0, RGBccffff, RGB2a7fff, &state[CUT_BTN]);
	changedisplay_function(deletebtn_draw, RGBfffbf0, RGBccffff, RGB2a7fff, &state[DELETE_BTN]);
	changedisplay_function(renamebtn_draw, RGBfffbf0, RGBccffff, RGB2a7fff, &state[RENAME_BTN]);
	changedisplay_function(newdirbtn_draw, RGBfffbf0, RGBccffff, RGB2a7fff, &state[NEWDIR_BTN]);
	changedisplay_function(newfilebtn_draw, RGBfffbf0, RGBccffff, RGB2a7fff, &state[NEWFILE_BTN]);
	changedisplay_function(attributebtn_draw, RGBfffbf0, RGBccffff, RGB2a7fff, &state[ATTRI_BTN]);
	changedisplay_function(challbtn_draw, RGBfffbf0, RGBccffff, RGB2a7fff, &state[CHALL_BTN]);
	changedisplay_function(cclallbtn_draw, RGBfffbf0, RGBccffff, RGB2a7fff, &state[CLRALL_BTN]);
	changedisplay_function(chctrybtn_draw, RGBfffbf0, RGBccffff, RGB2a7fff, &state[CHCTRY_BTN]);
	changedisplay_function(larrowdraw_b, RGB808080, RGB007faa, &state[L_ARROW_BTN]);
	changedisplay_function(downarrow_draw, RGB808080, RGB007faa, &state[DOWN_ARROW_BTN]);
	changedisplay_function(rarrowdraw_f, RGB808080, RGB007faa, &state[R_ARROE_BTN]);
	changedisplay_function(uparrowdraw, RGBffffff, RGBccffff, &state[UP_ARROE_BTN]);
	changedisplay_function(larrowdraw_main_lpg, RGB808080, RGB007faa, &state[MAIN_LASTPAGE_BTN]);
	changedisplay_function(rarrowdraw_main_npg, RGB808080, RGB007faa, &state[MAIN_NEXTPAGE_BTN]);
	changedisplay_function(larrowdraw_tree_lpg, RGB808080, RGB007faa, &state[TREE_LASTPAGE_BTN]);
	changedisplay_function(rarrowdraw_tree_npg, RGB808080, RGB007faa, &state[TREE_NEXTPAGE_BTN]);
	changedisplay_fixedbt(refreshicodraw_o, RGBffffff, RGBccffff, RGB2a7fff, &state[REFRESH_BTN]);
	changedisplay_chfixedbt(listdisplay_draw, RGBfffbf0, RGBccffff, RGB2a7fff, &state[LISTDISPLAY_BTN]);
	changedisplay_chfixedbt(icondisplay_draw, RGBfffbf0, RGBccffff, RGB2a7fff, &state[ICONDISPLAY_BTN]);
}

/****************************************
 * 检测主页所有按键是否左键单击并执行相关功能
 * 传递参数：按键状态数组地址，主文件头节点，历史记录链表头节点，
 * 			当前结点指针地址，C盘指针，主文件显示状态数组首地址，字符记录数组，当前页数，粘贴模式判断
 * 返回值：功能按键编号
 * **************************************/
/********************************
 * FUNCTION:
 * DESCRIPTION:
 * INPUT:
 * RETURN:
 * OTHERS:粘贴模式判断用于判断复制/剪切
 ********************************/
int testdo_mainbt(State *state, struct My_filenode **p_headnode_current, struct My_vector_ *history,
				  struct My_vector_ **p_currenthead, struct My_filenode *ph,
				  struct My_filenode *pc_for_dir, Bit *dsplstate_main, struct My_vector_ *currenthead,
				  struct My_vector_ *search, struct My_vector_ *paste, struct My_filenode *ph_for_paste, char *textipt,
				  char *page, int judge_paste, int judge_search)
{
	void (*draw_mainfile)(int x1, int y1, struct My_filenode *headnode,
						  int n, int state, int page); //函数指针
	Funcdata data_current;
	getfuncdata(&data_current, &draw_mainfile, p_headnode_current, ph);
	/*列表显示*/
	if (testmouse_bar(973, 746, 994, 767, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		if (getonebit(state[LISTDISPLAY_BTN], IFC_N) == 1) //已经是这个状态了
		{
			longpress_fit();   //长按适配
			return BTN_NO_USE; //啥也不干
		}
		else //更改到这个状态
		{
			/*功能模块调用*/
			func_setdisplay_list(state, page, ph, *p_headnode_current);
			longpress_fit(); //长按适配
			return LISTDISPLAY_BTN;
		}
	}
	/*图标显示*/
	else if (testmouse_bar(995, 746, 1016, 767, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		if (getonebit(state[ICONDISPLAY_BTN], IFC_N) == 1) //已经是这个状态了
		{
			longpress_fit();   //长按适配
			return BTN_NO_USE; //啥也不干
		}
		else //更改到这个状态
		{
			/*功能模块调用*/
			func_setdisplay_icon(state, page, ph, *p_headnode_current);
			longpress_fit(); //长按适配
			return ICONDISPLAY_BTN;
		}
	}
	/*上箭头,上级目录*/
	else if (testmouse_bar(100, 139, 123, 160, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		/* 检测是否可以点击并作出反应 */
		if (getonebit(state[UP_ARROE_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			/*功能模块调用*/
			longpress_fit(); //长按适配
			func_changedir_father(p_headnode_current, ph, p_currenthead, history, page);
			return UP_ARROE_BTN;
		}
	}
	/*刷新*/
	else if (testmouse_bar(817, 137, 841, 161, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		/* 检测是否可以点击并作出反应 */
		func_refresh(*p_headnode_current, ph);
		longpress_fit(); //长按适配
		return REFRESH_BTN;
	}
	/*左箭头*/
	else if (testmouse_bar(5, 139, 31, 160, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		/* 检测是否可以点击并作出反应 */
		if (getonebit(state[L_ARROW_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			/*功能模块调用*/
			longpress_fit(); //长按适配
			func_changedir_last(p_headnode_current, ph, p_currenthead, history, page);
			return L_ARROW_BTN;
		}
	}
	/*右箭头*/
	else if (testmouse_bar(56, 139, 82, 160, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		/* 检测是否可以点击并作出反应 */
		if (getonebit(state[R_ARROE_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			/*功能模块调用*/
			func_changedir_next(p_headnode_current, ph, p_currenthead, history, page);
			return R_ARROE_BTN;
		}
	}
	/*关闭叉叉，退出系统*/
	else if (testmouse_bar(988, 0, 1023, 23, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		longpress_fit(); //长按适配
		return CLOSE_BTN;
	}
	/*复制功能*/
	else if (testmouse_bar(9, 31, 71, 111, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		/* 检测是否可以点击并作出反应 */
		if (getonebit(state[COPY_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			/*功能模块调用*/
			longpress_fit(); //长按适配
			func_copy(*p_headnode_current, paste);
			return COPY_BTN;
		}
	}
	/*粘贴功能*/
	else if (testmouse_bar(72, 31, 131, 111, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		/* 检测是否可以点击并作出反应 */
		if (getonebit(state[PASTE_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			/*功能模块调用*/
			longpress_fit(); //长按适配
			func_paste(*p_headnode_current, ph_for_paste, paste, judge_paste);
			return PASTE_BTN;
		}
	}
	/*剪切功能*/
	else if (testmouse_bar(132, 31, 192, 111, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		struct My_filenode *ttnode;
		/* 检测是否可以点击并作出反应 */
		if (getonebit(state[CUT_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			/*功能模块调用*/
			longpress_fit(); //长按适配
			func_cut(*p_headnode_current, paste);
			return CUT_BTN;
		}
	}
	/*删除功能*/
	else if (testmouse_bar(219, 31, 280, 111, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		struct My_filenode *ttnode_1, *ttnode_2;
		/* 检测是否可以点击并作出反应 */
		if (getonebit(state[DELETE_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			/*功能模块调用*/
			longpress_fit(); //长按适配
			func_delete(*p_headnode_current);
			return DELETE_BTN;
		}
	}
	/*重命名功能*/
	else if (testmouse_bar(281, 31, 361, 111, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{

		/* 检测是否可以点击并作出反应 */
		if (getonebit(state[RENAME_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			/*功能模块调用*/
			longpress_fit(); //长按适配
			func_rename(*p_headnode_current, textipt, data_current.x0, data_current.y0, data_current.height,
						data_current.width, data_current.space_x_n, data_current.space_y_n, data_current.displaytype_main, page, draw_mainfile);
			return RENAME_BTN;
		}
	}
	/*新建文件夹功能*/
	else if (testmouse_bar(395, 31, 456, 111, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		/* 检测是否可以点击并作出反应 */
		if (getonebit(state[NEWDIR_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			/*功能模块调用*/
			func_newdir(*p_headnode_current, textipt, data_current.maxnum_currenttype, data_current.x0, data_current.y0, data_current.height,
						data_current.width, data_current.space_x_n, data_current.space_y_n, data_current.space_x_ico, data_current.space_y_ico, data_current.displaytype_main);
			return NEWDIR_BTN;
		}
	}
	/*新建文件功能*/
	else if (testmouse_bar(457, 31, 519, 111, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		/* 检测是否可以点击并作出反应 */
		if (getonebit(state[NEWFILE_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			/*功能模块调用*/
			func_newfile(*p_headnode_current, textipt, data_current.maxnum_currenttype, data_current.x0, data_current.y0, data_current.height,
						 data_current.width, data_current.space_x_n, data_current.space_y_n, data_current.space_x_ico, data_current.space_y_ico, data_current.displaytype_main);
			return NEWFILE_BTN;
		}
	}
	/*打开属性功能*/
	else if (testmouse_bar(548, 31, 609, 111, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		longpress_fit(); //长按适配
		if (getonebit(state[ATTRI_BTN], IFP_N) == 1)
		{
			func_attridisplay(*p_headnode_current);
		}
		return BTN_NO_USE;
	}
	/*全部选择功能*/
	else if (testmouse_bar(634, 31, 698, 111, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		/*功能模块调用*/
		longpress_fit();
		func_chall(state, *p_headnode_current, ph, pc_for_dir, currenthead,
				   history, search, paste, data_current.maxfilenum, data_current.height, data_current.width, data_current.x0, data_current.y0, data_current.displaytype_main,
				   dsplstate_main, page, judge_search, draw_mainfile);
		return CHALL_BTN;
	}
	/*全部取消功能*/
	else if (testmouse_bar(699, 31, 763, 111, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		/*功能模块调用*/
		longpress_fit();
		func_clrall(state, *p_headnode_current, ph, pc_for_dir, currenthead,
					history, search, paste, data_current.maxfilenum, data_current.height, data_current.width, data_current.x0, data_current.y0, data_current.displaytype_main,
					dsplstate_main, page, judge_search, draw_mainfile);
		return CLRALL_BTN;
	}
	/*反向选择功能*/
	else if (testmouse_bar(764, 31, 828, 111, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		/*功能模块调用*/
		longpress_fit();
		func_chctry(state, *p_headnode_current, ph, pc_for_dir, currenthead,
					history, search, paste, data_current.maxfilenum, data_current.height, data_current.width, data_current.x0, data_current.y0, data_current.displaytype_main,
					dsplstate_main, page, judge_search, draw_mainfile);
		return CHCTRY_BTN;
	}
	/* 主，上一页 */
	else if (testmouse_bar(913, 746, 939, 767, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		if (getonebit(state[MAIN_LASTPAGE_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			if (judge_search == 0)
			{
				page[MAINFILE_NUMBAR]--;
			}
			else
			{
				page[SEARCH_NUMBER]--;
			}
			longpress_fit();
			return MAIN_LASTPAGE_BTN;
		}
	}
	/* 主，下一页 */
	else if (testmouse_bar(940, 746, 966, 767, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		if (getonebit(state[MAIN_NEXTPAGE_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			if (judge_search == 0)
			{
				page[MAINFILE_NUMBAR]++;
			}
			else
			{
				page[SEARCH_NUMBER]++;
			}
			longpress_fit();
			return MAIN_NEXTPAGE_BTN;
		}
	}
	/* 树形，上一页 */
	else if (testmouse_bar(6, 746, 32, 767, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		if (getonebit(state[TREE_LASTPAGE_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			page[TREEFILE_NUMBAR]--;
			longpress_fit();
			return TREE_LASTPAGE_BTN;
		}
	}
	/* 树形，下一页 */
	else if (testmouse_bar(33, 746, 59, 767, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		if (getonebit(state[TREE_NEXTPAGE_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			page[TREEFILE_NUMBAR]++;
			longpress_fit();
			return TREE_NEXTPAGE_BTN;
		}
	}
	/* 搜索框 */
	else if (testmouse_bar(848, 137, 1016, 161, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		longpress_fit();
		// printf("%s\n", (*p_headnode_current)->father->name);
		if (strcmp((*p_headnode_current)->father->name, "cidiannao") == 0)
		{
			return BTN_NO_USE;
		}
		keybdintraction(textipt, 882, 147, 878, 139, 1015, 159, 8, RGBffffff, SEARCHBAR_MAXNUM, TEXTDISPLAY, 0);
		return SEARCH_BAR;
	}
	/* 地址栏 */
	else if (testmouse_bar(131, 137, 816, 161, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		longpress_fit();
		record_imagedata(164, 138, 816, 160, "IMDATA_0");
		setfillstyle(SOLID_FILL, RGBffffff);
		bar(164, 138, 816, 160);
		setcolor(RGB000000);
		outtextxy(167, 147, ">");
		keybdintraction(textipt, 167 + 9, 147, 164 + 9, 138, 816, 160, 8, RGBffffff, ADDRESSBAR_MAXNUM, TEXTNOTDISPLAY, 0);
		if (strlen(textipt) == 0)
		{
			write_imagedata(164, 138, 816, 160, "IMDATA_0");
			return BTN_NO_USE;
		}
		else
		{
			return ADDRESS_BAR;
		}
	}
	/* 历史记录 */
	else if (testmouse_bar(85, 139, 99, 160, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		int xy[4];
		int n;
		struct My_filenode *ttnode;
		getxy_history(xy, history);
		longpress_fit();
		draw_history(history, xy);
		n = func_history(history, p_currenthead, p_headnode_current, ph, xy);
		if (n == -1)
		{
			return BTN_NO_USE;
		}
		// ttnode = vector_to_filenode(ph, count_to_node(history, n));
		// move_dir(history, p_currenthead, 'n',ttnode);
		// *p_headnode_current = find_node_by_path(ph, (*p_currenthead)->path);
		// settype_dirdisplay(&((*p_headnode_current)->flag), gettype_dirdisplay(ph->flag));
		// page[MAINFILE_NUMBAR] = 0;

		return DOWN_ARROW_BTN;
	}
	else
	{
		return BTN_NO_USE;
	}
}

/***************************************
 * 鼠标所处区域检测
 * 检测鼠标位于哪个区域
 * 传递参数：鼠标位置
 * 返回值：	主文件区返回0；
 * 			树形文件区返回1；
 * 			其他区域返回2。（建议使用宏定义）
 * ************************************/
int testmouse_wherenow(int mousex, int mousey)
{
	if (TREEFILEAREA_X1 <= mousex && mousex <= TREEFILEAREA_X2 && TREEFILEAREA_Y1 <= mousey && mousey <= TREEFILEAREA_Y2)
	{
		return TREEFILE_NUMBAR;
	}
	else if (MAINFILEAREA_X1 <= mousex && mousex <= MAINFILEAREA_X2 && MAINFILEAREA_Y1 <= mousey && mousey <= MAINFILEAREA_Y2)
	{
		return MAINFILE_NUMBAR;
	}
	else
	{
		return OTHER_NUMBAR;
	}
}

/********************************
 * FUNCTION:refresh_mainfilebk
 * DESCRIPTION:刷新文件区显示绘制
 * INPUT:	树形文件区指针，当前目录指针的指针，C盘指针,搜索链表指针，历史记录链表指针，
 * 			指向history链的当前显示的目录对应的history节点地址，输入字符串，搜索辅助变量地址，
 * 			页数数组首地址，刷新模式
 * RETURN:无
 * OTHERS:模式0，不刷新；模式1 只刷新主文件区；模式2 刷新树形文件区；模式3，全部刷新
 ********************************/
void refresh_filebk(struct My_filenode *pc_for_dir, struct My_filenode **p_headnode_current,
					struct My_filenode *ph, struct My_vector_ *search, struct My_vector_ *history,
					struct My_vector_ **p_currenthead, char *textipt, int *p_num_search, char *page, int mode)
{
	int i;
	int mode_display; //显示模式
	int maxnum;		  //最多显示个数
	void (*draw_mainfile)(int n, struct My_filenode *headnode, int state, int page);
	mode_display = gettype_mainfile_display(*p_headnode_current, ph);
	/* 设置显示模式 */
	if (mode != REFRESH_MAINFILE_SEARCHMODE_ONLY)
	{
		/* 退出搜索模式了 */
		close_searchbar(); //清除搜索框

		switch (mode_display)
		{
		case TYPE_LIST_DISPLAY:
			draw_mainfile = My_draw_main_file1;
			maxnum = MAXFILENUM_LIST;
			break;
		case TYPE_SUPERICON_DISPLAY:
			draw_mainfile = My_draw_main_file2;
			maxnum = MAXFILENUM_ICON_SUPER;
			break;
		default:
			pop_error(-1, "REFRESH_FILEBK:", "Assignment error.");
			exit(1);
			break;
		}

		switch (mode)
		{
		case REFRESH_NOTATALL:
			return;
		case REFRESH_MAINFILE_ONLY:
			setfillstyle(SOLID_FILL, RGBffffff);
			clrmous(MouseX, MouseY);
			bar(MAINFILEAREA_X1, MAINFILEAREA_Y1, MAINFILEAREA_X2, MAINFILEAREA_Y2); //刷新主文件区背景
			for (i = 1; i <= maxnum; i++)											 //主文件区绘制
			{
				draw_mainfile(i, *p_headnode_current, 0, page[MAINFILE_NUMBAR]);
			}

			/* 该显示模式需要不同背景（需要文本说明） */
			if (gettype_dirdisplay((*p_headnode_current)->flag) == TYPE_LIST_DISPLAY)
			{
				display_listnodes();
			}
			addressnow_display(*p_headnode_current, ph, *p_currenthead);
			display_pagenum(page, MAINFILEMODE);
			return;
		case REFRESH_TREEFILE_ONLY:
			setfillstyle(SOLID_FILL, RGBffffff);
			clrmous(MouseX, MouseY);
			bar(TREEFILEAREA_X1, TREEFILEAREA_Y1, TREEFILEAREA_X2, TREEFILEAREA_Y2); //刷新树形文件区背景
			for (i = 1; i <= MAXDIRNUM_TREE; i++)									 //树形文件区绘制
			{
				My_draw_tree_file(i, pc_for_dir->son_list_head, 0, page[TREEFILE_NUMBAR]);
			}
			display_pagenum(page, TREEFILEMODE);
			return;
		case REFRESH_FILE_ALL:
			setfillstyle(SOLID_FILL, RGBffffff);
			clrmous(MouseX, MouseY);
			bar(TREEFILEAREA_X1, TREEFILEAREA_Y1, TREEFILEAREA_X2, TREEFILEAREA_Y2); //刷新树形文件区背景
			bar(MAINFILEAREA_X1, MAINFILEAREA_Y1, MAINFILEAREA_X2, MAINFILEAREA_Y2); //刷新主文件区背景
			for (i = 1; i <= MAXDIRNUM_TREE; i++)									 //树形文件区绘制
			{
				My_draw_tree_file(i, pc_for_dir->son_list_head, 0, page[TREEFILE_NUMBAR]);
			}
			for (i = 1; i <= maxnum; i++) //主文件区绘制
			{
				draw_mainfile(i, *p_headnode_current, 0, page[MAINFILE_NUMBAR]);
			}

			if (gettype_dirdisplay((*p_headnode_current)->flag) == TYPE_LIST_DISPLAY) //该模式需要文本说明
			{
				display_listnodes();
			}
			addressnow_display(*p_headnode_current, ph, *p_currenthead);
			display_pagenum(page, TREEFILEMODE);
			display_pagenum(page, MAINFILEMODE);
			return;
		default:
			pop_error(-1, "REFRESH_FILEBK:", "Assignment error.");
			exit(1);
			return;
		}
	}
	else //搜索模式的刷新
	{
		setfillstyle(SOLID_FILL, RGBffffff);
		clrmous(MouseX, MouseY);
		bar(MAINFILEAREA_X1, MAINFILEAREA_Y1, MAINFILEAREA_X2, MAINFILEAREA_Y2); //刷新主文件区背景
		if (page[SEARCH_NUMBER] != page[SEARCH_NUMBER_CTT] || page[SEARCH_NUMBER_CTT] == -1)
		{
			page[SEARCH_NUMBER_CTT] = page[SEARCH_NUMBER];
			*p_num_search = 0;
			(*p_headnode_current) = find_node_by_path(ph, (*p_currenthead)->path);
			free_vector_list(search);
			My_search(search, *p_headnode_current, textipt, p_num_search, page[SEARCH_NUMBER]);
			move_dir(history, p_currenthead, 'n', (*p_headnode_current)->father);
			(*p_headnode_current) = find_node_by_path(ph, (*p_currenthead)->path);
			if (*p_num_search == 0) //没搜到东西
			{
				*p_num_search = -1; //要区分0（非搜索模式）
			}
		}
		if (*p_headnode_current != ph)
		{
			free_list(*p_headnode_current);
		}
		for (i = 1; i <= 10; i++)
		{
			My_draw_search_file(i, search, 0);
		}
		(*p_headnode_current) = find_node_by_path(ph, (*p_currenthead)->path);
		display_pagenum(page, MAINFILEMODE_SEARCH);
	}
}

/********************************
 * FUNCTION:testdo_sortbt
 * DESCRIPTION:主文件区列表显示模式，改变排序模式
 * INPUT:显示模式，排序方式变量，当前节点
 * RETURN:成功返回1
 * OTHERS:无
 ********************************/
int testdo_sortbt(int type, char *sorttype, My_filenode *headnode_current)
{
	if (type == TYPE_LIST_DISPLAY)
	{
		/* 名称排序 */
		if (testmouse_bar(219, 165, 370, 181, MOUSETEST_INBAR) == MOUSE_INBAR_L)
		{
			if (*sorttype == 1)
			{
				*sorttype = 2;
			}
			else if (*sorttype == 2)
			{
				*sorttype = 1;
			}
			else
			{
				*sorttype = 1;
			}
		}
		/* 时间排序 */
		else if (testmouse_bar(454, 165, 639, 181, MOUSETEST_INBAR) == MOUSE_INBAR_L)
		{
			if (*sorttype == 3)
			{
				*sorttype = 4;
			}
			else if (*sorttype == 4)
			{
				*sorttype = 3;
			}
			else
			{
				*sorttype = 3;
			}
		}
		/* 大小排序 */
		else if (testmouse_bar(746, 165, 835, 181, MOUSETEST_INBAR) == MOUSE_INBAR_L)
		{
			if (*sorttype == 5)
			{
				*sorttype = 6;
			}
			else if (*sorttype == 6)
			{
				*sorttype = 5;
			}
			else
			{
				*sorttype = 5;
			}
		}
		else
		{
			return 0;
		}
		My_sort(headnode_current, *sorttype);
		longpress_fit();
		return 1;
	}
	else
	{
		return 0;
	}
}
