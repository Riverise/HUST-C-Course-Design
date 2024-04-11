#include "mmfc.h"

void refresh_all(My_filenode **p_headnode_current, My_filenode *pc_for_dir, My_filenode *ph, My_vector_ *currenthead,
				 char *refresh_mode, char *tree_ch_num, char *page, State *state_bt)
{
	close_all(pc_for_dir);
	*p_headnode_current = find_node_by_path(ph, currenthead->path);
	find_all_dir(pc_for_dir);
	if (*refresh_mode == REFRESH_ALL)
	{
		settype_dirdisplay(&((*p_headnode_current)->flag), gettype_dirdisplay(ph->flag));
	}
	*refresh_mode = REFRESH_FILE_ALL;
	tree_ch_num[LAST] = -1;
	tree_ch_num[NOW] = -1;
	page[TREEFILE_NUMBAR] = 0;
	page[MAINFILE_NUMBAR] = 0;
	page[SEARCH_NUMBER] = 0;
	drawbk();
	initbtnstate(state_bt); //初始化按键状态
}

void pcinit(My_filenode **ch, My_filenode **p0, My_filenode **ph, My_filenode **pc, My_filenode **p0_for_dir, My_filenode **ph_for_dir, My_filenode **pc_for_dir,
			My_filenode **p0_for_paste, My_filenode **ph_for_paste, My_filenode **pc_for_paste, My_vector_ **paste, My_vector_ **history,
			My_vector_ **currenthead, My_vector_ **search, char *sort_way, State *state_bt)
{
	My_init(p0, ph, pc, p0_for_dir, ph_for_dir, pc_for_dir,
			p0_for_paste, ph_for_paste, pc_for_paste, paste,
			history, currenthead, search, sort_way);
	*ch = *ph;
	initbtnstate(state_bt);	 //初始化按键状态
	mouseinit();			 //初始化鼠标
	clrmous(MouseX, MouseY); //清除掉鼠标
}

int func_refresh(State *state_bt, My_filenode **pch, My_vector_ *history, My_vector_ *search,
				 My_filenode *ph, My_filenode *pc_for_dir, My_vector_ *paste,
				 My_vector_ **pcurrenthead, char *page, char *textipt, int *pjudge_search,
				 char *refresh_mode)
{
	testbtnstate_setgbl(state_bt, *pch, history, search, ph, pc_for_dir->son_list_head, paste, *pcurrenthead, page, *pjudge_search);
	refreshbtnstate(state_bt); //刷新按键显示状态
	if (*refresh_mode == REFRESH_ALL)
	{
		return 1;
	}
	else
	{
		refresh_filebk(pc_for_dir, pch, ph, search, history, pcurrenthead,
					   textipt, pjudge_search, page, *refresh_mode); //第一次进入循环全部刷新
	}

	*refresh_mode = REFRESH_NOTATALL; //此后都是默认不刷新
	return 0;
}

/********************************
 * FUNCTION:func_mianfile
 * DESCRIPTION:检测鼠标位置并相应变色和刷新按键，选中文件，Ctrl选中，取消选中（点击选中的文件）
 * INPUT:	主文件区鼠标点击检测数组（有效区点击，框内点击，点击位置）
 * 			主文件区鼠标状态检测数组（这个循环鼠标位置，上个循环鼠标位置）
 *			主文件区文件块是否能选中显示状态数组首地址（按位量，依次存放是否显示为选中）
 * 			主文件区文件链表头节点指针
 *			页数
 *			旧的鼠标检测状态量
 * 			按键状态数组地址
 * 			粘贴板指针
 * 			历史记录指针
 * 			此电脑指针
 * 			C盘指针
 * 			树形文件指针头指针
 * 			当前目录指针
 * RETURN:双击返回1，未双击返回0
 * OTHERS:全程，除长按适配外，无鼠标状态刷新
 ********************************/
int func_mianfile(int **pressstate_fm, int *state_fm, Bit *mainfile_chos_dsplstate,
				  My_filenode *headnode_main, char *page, int press_last, State *state_bt,
				  struct My_vector_ *search, struct My_vector_ *paste, struct My_vector_ *history,
				  struct My_filenode *ph, struct My_filenode *pc_dir_sonhead,
				  struct My_vector_ *currenthead, int judge_search)
{
	My_filenode *ttnode; //目标节点指针
	int i;
	void (*draw_mainfile)(int x1, int y1, struct My_filenode *headnode,
						  int n, int state, int page); //函数指针

	int displaytype_main;	  //显示模式
	int x0, y0;				  //整体区域，左上坐标
	int width, height;		  //文件块宽度、高度
	int line_num, column_num; //行列数
	int maxfilenum;			  //最大显示文件数
	int *lc;				  //要显示的行列数

	*pressstate_fm = test_file_mousepress(headnode_main, ph, MAINFILEMODE);

	displaytype_main = gettype_mainfile_display(headnode_main, ph);
	switch (displaytype_main) //根据不同模式进行相应检测和设置
	{
	case TYPE_LIST_DISPLAY:
		draw_mainfile = draw_main_file1;
		x0 = X_MAINFILE_LIST;
		y0 = Y_MAINFILE_LIST;
		width = WIDTH_MAINFILE_LIST;
		height = HEIGHT_MAINFILE_LIST;
		line_num = (*pressstate_fm)[2];
		column_num = 0;
		maxfilenum = MAXFILENUM_LIST;
		break;
	case TYPE_SUPERICON_DISPLAY:
		draw_mainfile = draw_main_file2;
		lc = get_lc_maindisplay(TYPE_SUPERICON_DISPLAY, (*pressstate_fm)[2]);
		x0 = X_MAINFILE_ICON_SUOER;
		y0 = Y_MAINFILE_ICON_SUOER;
		width = WIDTH_MAINFILE_ICON_SUPER + SPACE_X_MAINFILE_ICON_SUPER;
		height = HEIGHT_MAINFILE_ICON_SUPER + SPACE_Y_MAINFILE_ICON_SUPER;
		line_num = lc[LINE];
		column_num = lc[COLUMN];
		maxfilenum = MAXFILENUM_ICON_SUPER;
		break;
	default:
		pop_error(-1, "FUNC_MIANFILE:", "Assignment error.");
		exit(1);
		break;
	}

	if (testmouse_presschange(press_last, press) == BTOP) //在一个确定的循环中，鼠标从没按到按下的历史性进步发生了
	{
		inittimer(); //初始化计时器
	}
	if ((*pressstate_fm)[0] == NOPRESS && (*pressstate_fm)[1] == NOPRESS) //在有效区域没有点击，直接刷新显示
	{
		refresh_filemainstate(state_fm, headnode_main, ph, page[MAINFILE_NUMBAR]);
		return 0;
	}
	else if ((*pressstate_fm)[0] == LEFTPRESS && (*pressstate_fm)[2] > 0) //左键点击有效区
	{
		refresh_filechstate(headnode_main, ph, page[MAINFILE_NUMBAR], (*pressstate_fm)[2]);
		display_choosenum(headnode_main);

		/* 重新把被点击的文件块画一次，盖住原来的 */
		clrmous(MouseX, MouseY);
		draw_mainfile(x0 + column_num * width, y0 + line_num * height,
					  headnode_main, (*pressstate_fm)[2], 1, page[MAINFILE_NUMBAR]);

		testbtnstate_setgbl(state_bt, headnode_main, history, search, ph, pc_dir_sonhead, paste, currenthead, page, judge_search); //重新刷新一次按键
		refreshbtnstate(state_bt);
		setonebit(mainfile_chos_dsplstate, (*pressstate_fm)[2], 1); //把相应文件块编号（显示）记录下来

		for (i = 1; i <= maxfilenum; i++) //再刷新其他状态
		{
			ttnode = count_to_node(headnode_main, i + maxfilenum * page[MAINFILE_NUMBAR]);
			if (getonebit(ttnode->flag, 1) == 0) //只要是非选中
			{
				if (getonebit(mainfile_chos_dsplstate, i) == 1) //但是显示的是选中
				{
					clrmous(MouseX, MouseY);
					/* 就刷新显示 */
					lc = get_lc_maindisplay(displaytype_main, i);
					draw_mainfile(x0 + lc[COLUMN] * width, y0 + lc[LINE] * height, headnode_main, i, 0, page[MAINFILE_NUMBAR]);

					setonebit(mainfile_chos_dsplstate, i, 0); //并把显示状态置零
				}
			}
		}
		longpress_fit(); //长按适配

		/*双击检测模块*/
		if (testmouse_doublepress(x0 + column_num * width, y0 + line_num * height, x0 + column_num * width + width,
								  y0 + line_num * height + height) == 1) //如果检测到双击
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (((*pressstate_fm)[0] == OUT_LEFTPRESS) && ((*pressstate_fm)[1] == LEFTPRESS)) //点击有效的空白区域
	{
		for (int i = 1; i <= maxfilenum; i++)
		{
			ttnode = count_to_node(headnode_main, i + page[MAINFILE_NUMBAR] * maxfilenum);
			if (getonebit(ttnode->flag, 1) == 1) //选中了
			{
				set0onebit(&(ttnode->flag), 1); //设置成未选中
				clrmous(MouseX, MouseY);
				lc = get_lc_maindisplay(displaytype_main, i);
				draw_mainfile(x0 + lc[COLUMN] * width, y0 + lc[LINE] * height, headnode_main, i, 0, page[MAINFILE_NUMBAR]);
				setonebit(mainfile_chos_dsplstate, i, 0); //把显示状态置零
			}
		}
		display_choosenum(headnode_main);
		testbtnstate_setgbl(state_bt, headnode_main, history, search, ph, pc_dir_sonhead, paste, currenthead, page, judge_search); //重新刷新一次按键
		refreshbtnstate(state_bt);
		longpress_fit(); //长按适配
		return 0;
	}
	else //在无效区点击
	{
		return 0;
	}
}

void chgto_treedir(My_filenode **pch, My_vector_ *history, My_vector_ **pcurrenthead, My_vector_ *search, My_filenode *ph, My_filenode *pc_for_dir,
				   char *tree_ch_num, int *pressstate_tr, char *page, int *pjudge_search, char *refresh_mode)
{
	My_filenode *ttnode, *ttnode_;
	int delta_x_tree;
	int num_count;
	struct My_filenode *ttnode_t;

	tree_ch_num[NOW] = pressstate_tr[2];
	num_count = tree_ch_num[NOW];
	ttnode = count_to_dir(pc_for_dir->son_list_head, &num_count);
	delta_x_tree = 0;
	for (ttnode_t = ttnode->father; ttnode_t->father->father != NULL; ttnode_t = ttnode_t->father)
	{
		delta_x_tree += 6;
	} //调整缩进（检测）
	if (testmouse_inoutbar(X_TREEFILE + delta_x_tree + 25, TREEFILEAREA_Y1 + pressstate_tr[2] + 1 * HEIGHT_TREEFILE,
						   TREEFILEAREA_X2, TREEFILEAREA_Y1 + (pressstate_tr[2] + 2) * HEIGHT_TREEFILE) == 1)
	{
		if (tree_ch_num[LAST] != -1) //获取旧节点
		{
			num_count = tree_ch_num[LAST];
			ttnode_ = count_to_dir(pc_for_dir->son_list_head, &num_count);
		}
		if (getonebit(ttnode->flag, 1) == 0) //
		{
			set1onebit(&ttnode->flag, 1); //选中
		}
		if (tree_ch_num[LAST] != -1 && tree_ch_num[LAST] != tree_ch_num[NOW])
		{
			set0onebit(&ttnode_->flag, 1);
		}
		tree_ch_num[LAST] = tree_ch_num[NOW];
	}
	else if (testmouse_inoutbar(X_TREEFILE + delta_x_tree + 5, TREEFILEAREA_Y1 + pressstate_tr[2] + 1 * HEIGHT_TREEFILE,
								X_TREEFILE + delta_x_tree + 24, TREEFILEAREA_Y1 + (pressstate_tr[2] + 2) * HEIGHT_TREEFILE) == 1)
	{
		close_all(ttnode->father->son_list_head);

		if (getonebit(ttnode->flag, 1) == 0) //选中
		{
			set1onebit(&ttnode->flag, 1);
		}
		if (getonebit(ttnode->flag, 4) == 0)
		{
			set1onebit(&ttnode->flag, 4); //打开(用+=会多加)
			find_all_dir(ttnode);
		}
	}
	page[MAINFILE_NUMBAR] = 0;
	move_dir(history, pcurrenthead, 'n', ttnode);
	longpress_fit();
	*pch = find_node_by_path(ph, (*pcurrenthead)->path);
	settype_dirdisplay(&((*pch)->flag), gettype_dirdisplay(ph->flag));
	*refresh_mode = REFRESH_FILE_ALL;
	if (*pjudge_search != 0) //若在搜索模式
	{
		free_vector_list(search);
		*pjudge_search = 0; //退出搜索模式
	}
}