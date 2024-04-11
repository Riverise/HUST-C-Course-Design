#include "moin.h"

/*****************************
 * 检测鼠标，在框内/框外点击，
 * 在框内传递0，在框外传递1；
 * 传递参数：框四角坐标，模式选择(MOUSETEST_INBAR,MOUSETEST_OUTBAR,MOUSETEST_ALL)
 * 返回值：在框内未点击传递0，在框内左键点击传递1，在框内右键点击传递2，在框外不点击传递3，
 * 			在框外左键传递4，在框外右键传递5；
 * ****************************/
int testmouse_bar(int x1, int y1, int x2, int y2, int mode)
{
	switch (mode)
	{
	case 0:
		if (MouseX > x1 && MouseX < x2 && MouseY > y1 && MouseY < y2)
		{
			switch (press)
			{
			case 0:
				return MOUSE_INBAR_NO;
			case 1:
				return MOUSE_INBAR_L;
			case 2:
				return MOUSE_INBAR_R;
			default:
				return 10;
			}
		}
		else
		{
			return MOUSE_OUTBAR;
		}
	case 1:
		if (MouseX < x1 || MouseX > x2 || MouseY < y1 || MouseY > y2)
		{
			switch (press)
			{
			case 0:
				return MOUSE_OUTBAR_NO;
			case 1:
				return MOUSE_OUTBAR_L;
			case 2:
				return MOUSE_OUTBAR_R;
			default:
				return 10;
			}
		}
		else
		{
			return MOUSE_INBAR;
		}
	case 2:
		if (MouseX > x1 && MouseX < x2 && MouseY > y1 && MouseY < y2)
		{
			switch (press)
			{
			case 0:
				return MOUSE_INBAR_NO;
			case 1:
				return MOUSE_INBAR_L;
			case 2:
				return MOUSE_INBAR_R;
			default:
				return 10;
			}
		}
		else
		{
			switch (press)
			{
			case 0:
				return MOUSE_OUTBAR_NO;
			case 1:
				return MOUSE_OUTBAR_L;
			case 2:
				return MOUSE_OUTBAR_R;
			default:
				return 10;
			}
		}
	default:
		return 10;
	}
}

/********************************
 * FUNCTION:testmouse_inoutbar
 * DESCRIPTION:检测鼠标位置 是否在框内/外
 * INPUT:框四角坐标
 * RETURN:1为在框内，0为在框外
 * OTHERS:无
 ********************************/
int testmouse_inoutbar(int x1, int y1, int x2, int y2)
{
	if (MouseX > x1 && MouseX < x2 && MouseY > y1 && MouseY < y2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*****************
 * 检测鼠标函数
 * 将上次循环鼠标在/不在的值后移一位，并将本次循环鼠标在/不在的值记录在第二位
 * 检测鼠标框内状态，并保持上一个循环内鼠标框内状态
 * 传递：矩形边框坐标，state变量的地址
 * 改变state的值
 * ************************/
void testmouse_ico(int x1, int y1, int x2, int y2, State *pstate)
{
	char s = mouse_press(x1, y1, x2, y2);
	setonebit(pstate, IFH_L, getonebit(*pstate, IFH_N)); //旧量后移一位
	/*赋新值*/
	if (2 == s) //在区域，未点击
	{
		set1onebit(pstate, IFH_N);
	}
	else if (0 == s) //不在区域
	{
		set0onebit(pstate, IFH_N);
	}
}

/********************************
 * FUNCTION:test_filenum_list
 * DESCRIPTION:检测鼠标在文件区的文件区域编号，列表显示模式
 * INPUT:左上坐标，文件所在链表头节点，子区域高度，子区域宽度, 检测位置（模式）
 * RETURN:鼠标所处文件区的编号, 无效位置返回-1
 * OTHERS:在调用之前要先确定鼠标此时位于指定有效区域
 * 			模式仅有主文件区列表模式、树形文件区模式、搜索模式（毕竟是列表检测）
 ********************************/
int test_filenum_list(int x1, int y1, struct My_filenode *headNode,
					  int height, int width, int mode)
{
	int num = 0;
	int t;
	int num_count;
	struct My_filenode *temp;

	t = testmouse_inoutbar(x1, y1, x1 + width, y1 + MAXFILENUM_LIST * height);
	if (t == 1) //在区域里
	{
		num = (MouseY - y1) / height + 1; //获得鼠标当前所处文件区域位置编号
		if (mode == TREEFILEMODE)
		{
			num_count = num;
			temp = count_to_dir(headNode, &num_count);
		}
		else
		{
			temp = count_to_node(headNode, num);
		}
		if (temp == NULL)
		{
			return (-1); //空指针
		}
		else
		{
			return num;
		}
	}
	else
	{
		return (-1); //不在区域
	}
}

/********************************
 * FUNCTION:test_filenum_list
 * DESCRIPTION:检测鼠标在文件区的文件区域编号，列表显示模式
 * INPUT:左上坐标，文件所在链表头节点，子区域高度，子区域宽度,
 * RETURN:鼠标所处文件区的编号, 无效位置返回-1
 * OTHERS:重载版本
 ********************************/
int test_filenum_list(int x1, int y1, struct My_vector_ *headNode, int height, int width)
{
	int num = 0;
	int t;
	struct My_vector_ *temp;

	t = testmouse_inoutbar(x1, y1, x1 + width, y1 + MAXFILENUM_SEARCH * height);
	if (t == 1) //在区域里
	{
		num = (MouseY - y1) / height + 1; //获得鼠标当前所处文件区域位置编号

		temp = count_to_node(headNode, num);
		if (temp == NULL)
		{
			return -1; //空指针
		}
		else
		{
			// printf("%d\n", num);
			return num;
		}
	}
	else
	{
		return -1; //不在区域
	}
}

// /********************************
//  * FUNCTION:test_file_mousepress
//  * DESCRIPTION:检测鼠标在文件区点击位置
//  * INPUT:文件所在链表头节点 检测位置（模式）
//  * RETURN:数组,元素---	 （1）框内没有点击1，框内左键2，框内右键3，框外没有点击4，框外左键5，框外右键6[推荐使用宏定义]
//  * 						（2）同（1），相对于大区域
//  * 						（3）点击位置对应文件编号
//  * OTHERS:对于搜索界面的重载版本
//  ********************************/
// int *test_file_mousepress(struct My_vector_ *headNode)
// {
// 	static int t[3] = {NOT_INBAR, NOT_INBAR, 0}; //静态变量，用于传递返回值数组
// 	int state[2];								 //鼠标点击状态
// 	t[0] = test_mainfile_search_effec(headNode);
// 	t[1] = 1 + testmouse_bar(MAINFILEAREA_X1, MAINFILEAREA_Y1, MAINFILEAREA_X2, MAINFILEAREA_Y2,
// 							 MOUSETEST_ALL);
// 	t[2] = test_filenum_list(X_MAINFILR_SEARCH, Y_MAINFILE_SEARCH, headNode,
// 							 HEIGHT_MAINFILE_SEARCH, WIDTH_MAINFILE_SEARCH /* , MAINFILEMODE_SEARCH */);
// }

/********************************
 * FUNCTION:test_filenum_icon
 * DESCRIPTION:缩略图显示模式（图标），获取鼠标在文件区的文件区域编号
 * INPUT:左上坐标，文件所在链表头节点，子区域高度，子区域宽度
 * RETURN:鼠标所处文件区的编号, 无效位置返回-1
 * OTHERS:在调用之前要先确定鼠标此时位于指定有效区域
 ********************************/
int test_filenum_icon(int x1, int y1, struct My_filenode *headNode)
{
	int line, column;		//鼠标所处文件位置行列数
	int num = 0;			//获取编号
	int t;					//判断是否位于有效区域内
	int height, width;		//文件区域有效高度，有效宽度
	int space_x, space_y;	//文件横、纵向间隔
	int number_x, number_y; //横、纵向文件数量
	struct My_filenode *temp;

	switch (gettype_dirdisplay(headNode->flag))
	{
	case TYPE_LIST_DISPLAY:
		pop_error(-1, "TEST_FILENUM_ICON:", "Assignment error.");
		exit(1);
		break;
	case TYPE_SUPERICON_DISPLAY:
		height = HEIGHT_MAINFILE_ICON_SUPER;
		width = WIDTH_MAINFILE_ICON_SUPER;
		space_x = SPACE_X_MAINFILE_ICON_SUPER;
		space_y = SPACE_Y_MAINFILE_ICON_SUPER;
		number_x = NUMBER_X_MAINFILE_ICON_SUOER;
		number_y = NUMBER_Y_MAINFILE_ICON_SUOER;
		break;
	default:
		pop_error(-1, "TEST_FILENUM_ICON:", "Assignment error.");
		exit(1);
		break;
	}

	/* 检测鼠标处于哪个显示（包括无效区域）文件块区域 */
	if (((line = (MouseY - y1) / (height + space_y)) + 1) > number_y) //真值-1,如果鼠标位置越界则返回无效值（-1）
	{
		return -1;
	}
	if ((column = (MouseX - x1) / (width + space_x) + 1) > number_x) //真值,如果鼠标位置越界则返回无效值（-1）
	{
		return -1;
	}
	num = line * number_x + column; //获取文件数
	temp = count_to_node(headNode, num);
	if (temp == NULL) //无效区域
	{
		return -1;
	}
	else
	{
		t = testmouse_inoutbar(x1 + (column - 1) * (width + space_x), y1 + line * (height + space_y),
							   x1 + (column - 1) * (width + space_x) + width, y1 + line * (height + space_y) + height);
		if (t == 0) //不在有效文件区域内
		{
			return -1;
		}
		else //有效了
		{
			return num;
		}
	}
}

/********************************
 * FUNCTION:refresh_filetreestate
 * DESCRIPTION:实时检测鼠标，并刷新树形文件区文件块显示状态
 * INPUT:状态数组首地址，目标指针，页数
 * RETURN:无
 * OTHERS:无
 ********************************/
void refresh_filetreestate(int *state, struct My_filenode *headnode_dir, int page)
{
	state[NOW] = test_filenum_list(X_TREEFILE, Y_TREEFILE + HEIGHT_TREEFILE, headnode_dir,
								   HEIGHT_TREEFILE, WIDTH_TREEFILE, TREEFILEMODE);
	if (state[LAST] != state[NOW]) //说明状态需要改变
	{
		clrmous(MouseX, MouseY);
		if (state[NOW] > 0)
		{
			draw_tree_file(X_TREEFILE, Y_TREEFILE + state[NOW] * HEIGHT_TREEFILE, headnode_dir, state[NOW] /* + MAXDIRNUM_TREE * page */, 1, page);
		}
		if (state[LAST] > 0)
		{
			draw_tree_file(X_TREEFILE, Y_TREEFILE + state[LAST] * HEIGHT_TREEFILE, headnode_dir, state[LAST] /* + MAXDIRNUM_TREE * page */, 0, page);
		}
	}
	state[LAST] = state[NOW];
}

/********************************
 * FUNCTION:refresh_filemainstate
 * DESCRIPTION:实时刷新主文件区显示状态
 * INPUT:状态数组首地址，目标指针，C盘头指针，页数，
 * RETURN:无
 * OTHERS:无
 ********************************/
void refresh_filemainstate(int *state, struct My_filenode *headnode_current, struct My_filenode *ph, int page)
{
	int mode; //显示模式，从头结点中获取
	int x[2]; //新旧x坐标
	int y[2]; //新旧y坐标
	void (*draw_mainfile)(int x1, int y1, struct My_filenode *headNode,
						  int n, int state, int page);	   //函数指针
	mode = gettype_mainfile_display(headnode_current, ph); //获取显示模式

	switch (mode) //根据不同模式进行相应检测和设置
	{
	case TYPE_LIST_DISPLAY:
		draw_mainfile = draw_main_file1;
		state[NOW] = test_filenum_list(X_MAINFILE_LIST, Y_MAINFILE_LIST + HEIGHT_MAINFILE_LIST,
									   headnode_current, HEIGHT_MAINFILE_LIST, WIDTH_MAINFILE_LIST, MAINFILEMODE_LIST);
		if (state[LAST] != state[NOW])
		{
			x[NOW] = X_MAINFILE_LIST;
			y[NOW] = Y_MAINFILE_LIST + state[NOW] * HEIGHT_MAINFILE_LIST;
			x[LAST] = X_MAINFILE_LIST;
			y[LAST] = Y_MAINFILE_LIST + state[LAST] * HEIGHT_MAINFILE_LIST;
		}
		break;
	case TYPE_SUPERICON_DISPLAY:
		draw_mainfile = draw_main_file2;
		state[NOW] = test_filenum_icon(X_MAINFILE_ICON_SUOER, Y_MAINFILE_ICON_SUOER, headnode_current);

		if (state[LAST] != state[NOW])
		{
			int *lc_mainfile[2];
			if (state[NOW] > 0)
			{
				lc_mainfile[NOW] = get_lc_maindisplay(TYPE_SUPERICON_DISPLAY, state[NOW]);
				x[NOW] = X_MAINFILE_ICON_SUOER + lc_mainfile[NOW][COLUMN] * (WIDTH_MAINFILE_ICON_SUPER + SPACE_X_MAINFILE_ICON_SUPER);
				y[NOW] = Y_MAINFILE_ICON_SUOER + lc_mainfile[NOW][LINE] * (HEIGHT_MAINFILE_ICON_SUPER + SPACE_Y_MAINFILE_ICON_SUPER);
			}
			if (state[LAST] > 0)
			{
				lc_mainfile[LAST] = get_lc_maindisplay(TYPE_SUPERICON_DISPLAY, state[LAST]);
				x[LAST] = X_MAINFILE_ICON_SUOER + lc_mainfile[LAST][COLUMN] * (WIDTH_MAINFILE_ICON_SUPER + SPACE_X_MAINFILE_ICON_SUPER);
				y[LAST] = Y_MAINFILE_ICON_SUOER + lc_mainfile[LAST][LINE] * (HEIGHT_MAINFILE_ICON_SUPER + SPACE_Y_MAINFILE_ICON_SUPER);
			}
		}
		// maxnum = MAXFILENUM_ICON_SUPER;
		break;
	default:
		pop_error(-1, "REFRESH_FILEMAINSTATE:", "Assignment error.");
		getch();
		exit(1);
		break;
	}
	if (state[LAST] != state[NOW]) //说明状态需要改变
	{
		clrmous(MouseX, MouseY);
		if (state[NOW] > 0)
		{
			draw_mainfile(x[NOW], y[NOW], headnode_current, state[NOW], 1, page);
			if (state[LAST] > 0)
			{
				draw_mainfile(x[LAST], y[LAST], headnode_current, state[LAST], 0, page);
			}
		}
		else if (state[LAST] > 0)
		{
			draw_mainfile(x[LAST], y[LAST], headnode_current, state[LAST], 0, page);
		}
		if (state[LAST] > 0)
		{
			draw_mainfile(x[LAST], y[LAST], headnode_current, state[LAST], 0, page);
		}
	}
	state[LAST] = state[NOW];
}

/********************************
 * FUNCTION:refresh_filesearch_state
 * DESCRIPTION:实时刷新搜索模式主文件区显示状态
 * INPUT:状态数组首地址，目标指针，被复制指针，页数，
 * RETURN:无
 * OTHERS:无
 ********************************/
void refresh_filesearch_state(int *state, struct My_vector_ *headnode_current)
{
	state[NOW] = test_filenum_list(X_MAINFILR_SEARCH, Y_MAINFILE_SEARCH, headnode_current,
								   HEIGHT_MAINFILE_SEARCH + SPACE_Y_MAINFILE_SEARCH,
								   WIDTH_MAINFILE_SEARCH);
	if (state[LAST] != state[NOW])
	{
		clrmous(MouseX, MouseY);
		if (state[NOW] > 0)
		{
			draw_search_file(X_MAINFILR_SEARCH, Y_MAINFILE_SEARCH + (state[NOW] - 1) * (HEIGHT_MAINFILE_SEARCH + SPACE_Y_MAINFILE_SEARCH),
							 headnode_current, state[NOW], 1);
		}
		if (state[LAST] > 0)
		{
			draw_search_file(X_MAINFILR_SEARCH, Y_MAINFILE_SEARCH + (state[LAST] - 1) * (HEIGHT_MAINFILE_SEARCH + SPACE_Y_MAINFILE_SEARCH),
							 headnode_current, state[LAST], 0);
		}
	}
	state[LAST] = state[NOW];
}

/********************************
 * FUNCTION:test_search_mousepress
 * DESCRIPTION:检测搜索模式双击
 * INPUT:press_last
 * RETURN:-1没双击，正数为序号
 * OTHERS:无
 ********************************/
int test_search_mousepress(int press_last)
{
	int filenum;
	if (testmouse_presschange(press_last, press) == BTOP) //在一个确定的循环中，鼠标从没按到按下的历史性进步发生了
	{
		inittimer(); //初始化计时器
					 // printf("111\n");
	}
	if (testmouse_bar(MAINFILEAREA_X1, MAINFILEAREA_Y1, MAINFILEAREA_X2, MAINFILEAREA_Y2, MOUSETEST_ALL) == MOUSE_INBAR_L) //左键点击有效区
	{
		filenum = (MouseY - Y_MAINFILE_SEARCH) / (HEIGHT_MAINFILE_SEARCH + SPACE_Y_MAINFILE_SEARCH);

		longpress_fit(); //长按适配
		// printf("%d\n", filenum);

		/*双击检测模块*/
		if (testmouse_doublepress(X_MAINFILR_SEARCH, Y_MAINFILE_SEARCH + filenum * (HEIGHT_MAINFILE_SEARCH + SPACE_Y_MAINFILE_SEARCH), X_MAINFILR_SEARCH + WIDTH_MAINFILE_SEARCH,
								  Y_MAINFILE_SEARCH + (filenum + 1) * (HEIGHT_MAINFILE_SEARCH + SPACE_Y_MAINFILE_SEARCH)) == 1) //如果检测到双击
		{
			return (filenum + 1);
		}
		else
		{
			return -1;
		}
	}
	else //在无效区点击
	{
		return -1;
	}
}

/********************************
 * FUNCTION:test_file_mousepress
 * DESCRIPTION:检测鼠标在文件区点击位置
 * INPUT:文件所在链表头节点 ,C盘头指针，检测位置（模式）
 * RETURN:数组,元素---	 （1）框内没有点击1，框内左键2，框内右键3，框外没有点击4，框外左键5，框外右键6[推荐使用宏定义]
 * 						（2）同（1），相对于大区域
 * 						（3）点击位置对应文件编号
 * OTHERS:实际上只有前几个用到了
 ********************************/
int *test_file_mousepress(struct My_filenode *headnode, My_filenode *ph, int mode /*, unsigned char *page */)
{
	static int t[3] = {NOT_INBAR, NOT_INBAR, 0}; //静态变量，用于传递返回值数组
	int state[2];								 //鼠标点击状态
	int judge;
	int type_mainfile_display; //用于记录主文件区结点显示模式
	type_mainfile_display = gettype_mainfile_display(headnode, ph);
	switch (type_mainfile_display)
	{
	case TYPE_LIST_DISPLAY:
		/* 有效区检测点击 */
		t[0] = test_mainfile_icon_effec(TYPE_LIST_DISPLAY, headnode);
		judge = test_filenum_list(X_MAINFILE_LIST, Y_MAINFILE_LIST + HEIGHT_MAINFILE_LIST,
								  headnode, HEIGHT_MAINFILE_LIST, WIDTH_MAINFILE_LIST /* MAINFILEAREA_X2 - X_MAINFILE_LIST */, mode); //检测鼠标所在文件编号
		if (judge > 0)
		{
			t[2] = judge;
		}
		else
		{
			t[2] = -1;
		}
		break;
	case TYPE_SUPERICON_DISPLAY:
		/* 有效区检测点击 */
		t[0] = test_mainfile_icon_effec(TYPE_SUPERICON_DISPLAY, headnode);
		/* 检测编号 */
		judge = test_filenum_icon(X_MAINFILE_ICON_SUOER, Y_MAINFILE_ICON_SUOER, headnode);
		if (judge > 0)
		{
			t[2] = judge;
		}
		else
		{
			t[2] = -1;
		}
		break;
	}
	//由于仅仅相差1，取消原来的检测赋值，改用加法
	t[1] = 1 + testmouse_bar(MAINFILEAREA_X1, MAINFILEAREA_Y1, MAINFILEAREA_X2, MAINFILEAREA_Y2,
							 MOUSETEST_ALL); //是否在主文件区部分

	return t;
}

/********************************
 * FUNCTION:test_file_mousepress
 * DESCRIPTION:检测鼠标在文件区点击位置
 * INPUT:文件所在链表头节点 ,C盘头指针，检测位置（模式）
 * RETURN:数组,元素---	 （1）框内没有点击1，框内左键2，框内右键3，框外没有点击4，框外左键5，框外右键6[推荐使用宏定义]
 * 						（2）同（1），相对于大区域
 * 						（3）点击位置对应文件编号
 * OTHERS:对于树形文件区的重载版本
 ********************************/
int *test_file_mousepress(struct My_filenode *headnode, char *page)
{
	static int t[3] = {NOT_INBAR, NOT_INBAR, 0}; //静态变量，用于传递返回值数组
	int state[2];
	int judge;
	t[0] = test_treefile_list_effec(headnode);
	t[1] = 1 + testmouse_bar(TREEFILEAREA_X1, TREEFILEAREA_Y1, TREEFILEAREA_X2, TREEFILEAREA_Y2,
							 MOUSETEST_ALL);
	judge = test_filenum_list(X_TREEFILE, Y_TREEFILE + HEIGHT_TREEFILE, headnode,
							  HEIGHT_TREEFILE, WIDTH_TREEFILE, TREEFILEMODE); //检测鼠标所在文件编号
	if (judge > 0)
	{
		t[2] = page[TREEFILE_NUMBAR] * MAXFILENUM_LIST + judge;
	}
	else
	{
		t[2] = -1;
	}
	return t;
}

/********************************
 * FUNCTION:test_mainfile_icon_effec
 * DESCRIPTION:检测主文件区鼠标此时是否处于有效区域
 * INPUT:显示模式
 * RETURN:框内没有点击1，框内左键2，框内右键3，框外没有点击4，框外左键5，框外右键6[推荐使用宏定义]
 * OTHERS:无
 ********************************/
int test_mainfile_icon_effec(int type_maindisplay, struct My_filenode *headNode)
{
	int nodenum;
	int t;
	switch (type_maindisplay)
	{
	case TYPE_LIST_DISPLAY:
		nodenum = count_nodes(headNode);
		if (nodenum > MAXFILENUM_LIST)
		{
			nodenum = MAXFILENUM_LIST;
		}
		t = testmouse_bar(X_MAINFILE_LIST, Y_MAINFILE_LIST + HEIGHT_MAINFILE_LIST,
						  X_MAINFILE_LIST + WIDTH_MAINFILE_LIST, Y_MAINFILE_LIST + HEIGHT_MAINFILE_LIST + nodenum * HEIGHT_MAINFILE_LIST,
						  MOUSETEST_ALL);
		return (1 + t);
	case TYPE_SUPERICON_DISPLAY:
		/* 超大图标 */
		int line, column; //鼠标所处文件位置行列数
		int num_file_area;

		nodenum = count_nodes(headNode);
		if (nodenum > MAXFILENUM_ICON_SUPER)
		{
			nodenum = MAXFILENUM_ICON_SUPER;
		}

		if (((line = (MouseY - Y_MAINFILE_ICON_SUOER) / (HEIGHT_MAINFILE_ICON_SUPER + SPACE_Y_MAINFILE_ICON_SUPER)) + 1) > NUMBER_Y_MAINFILE_ICON_SUOER)
		{					//真值-1,如果鼠标位置越界则返回无效值（框外）
			if (press == 0) //没点击
			{
				return OUT_NOPRESS;
			}
			else if (press == 1)
			{
				return OUT_LEFTPRESS;
			}
		}
		if ((column = (MouseX - X_MAINFILE_ICON_SUOER) / (WIDTH_MAINFILE_ICON_SUPER + SPACE_X_MAINFILE_ICON_SUPER) + 1) > NUMBER_X_MAINFILE_ICON_SUOER)
		{					//真值,如果鼠标位置越界则返回无效值（框外）
			if (press == 0) //没点击
			{
				return OUT_NOPRESS;
			}
			else if (press == 1)
			{
				return OUT_LEFTPRESS;
			}
		}
		num_file_area = line * NUMBER_X_MAINFILE_ICON_SUOER + column; //获取文件数

		if (num_file_area > nodenum) //无效区域,返回无效值（框外）
		{
			if (press == 0) //没点击
			{
				return OUT_NOPRESS;
			}
			else if (press == 1) //左键点击
			{
				return OUT_LEFTPRESS;
			}
		}
		else
		{
			t = testmouse_bar(X_MAINFILE_ICON_SUOER + (column - 1) * (WIDTH_MAINFILE_ICON_SUPER + SPACE_X_MAINFILE_ICON_SUPER),
							  Y_MAINFILE_ICON_SUOER + line * (HEIGHT_MAINFILE_ICON_SUPER + SPACE_Y_MAINFILE_ICON_SUPER),
							  X_MAINFILE_ICON_SUOER + (column - 1) * (WIDTH_MAINFILE_ICON_SUPER + SPACE_X_MAINFILE_ICON_SUPER) + WIDTH_MAINFILE_ICON_SUPER,
							  Y_MAINFILE_ICON_SUOER + line * (HEIGHT_MAINFILE_ICON_SUPER + SPACE_Y_MAINFILE_ICON_SUPER) + HEIGHT_MAINFILE_ICON_SUPER,
							  MOUSETEST_ALL);
			return (t + 1);
		}
		break;
	}
	return -1;
}

/********************************
 * FUNCTION:test_treefile_list_effec
 * DESCRIPTION:检测树形文件区鼠标此时是否处于有效区域
 * INPUT:树形文件区头节点
 * RETURN:框内没有点击1，框内左键2，框内右键3，框外没有点击4，框外左键5，框外右键6[推荐使用宏定义]
 * OTHERS:无
 ********************************/
int test_treefile_list_effec(struct My_filenode *headNode)
{
	int nodenum;
	int t;
	nodenum = getnum_dir_andopen(headNode);
	if (nodenum > MAXDIRNUM_TREE)
	{
		nodenum = MAXDIRNUM_TREE;
	}
	t = testmouse_bar(X_TREEFILE, Y_TREEFILE + HEIGHT_TREEFILE, X_TREEFILE + WIDTH_TREEFILE,
					  Y_TREEFILE + (nodenum + 1) * HEIGHT_TREEFILE, MOUSETEST_ALL);
	return (t + 1);
}

/********************************
 * FUNCTION:test_mainfile_search_effec
 * DESCRIPTION:检测搜索文件区文件区鼠标此时是否处于有效区域
 * INPUT:头节点
 * RETURN:框内没有点击1，框内左键2，框内右键3，框外没有点击4，框外左键5，框外右键6[推荐使用宏定义]
 * OTHERS:无
 ********************************/
int test_mainfile_search_effec(struct My_vector_ *headnode)
// int test_mainfile_search_effec(struct My_filenode *headnode)
{
	int nodenum;
	int t;
	nodenum = count_nodes(headnode);
	t = testmouse_bar(X_MAINFILR_SEARCH, Y_MAINFILE_SEARCH, X_MAINFILR_SEARCH + WIDTH_MAINFILE_SEARCH,
					  Y_MAINFILE_SEARCH + (nodenum)*HEIGHT_MAINFILE_SEARCH, MOUSETEST_ALL);
	return (t + 1);
}

/**********************************
 * 对文件进行选中操作
 * 鼠标左键点击某个文件，其被选中，节点相应内容变化，
 * 传递参数：文件所在链表头节点,页数，被点击文件编号，
 * 返回值：无
 * ****************************************/
void refresh_filechstate(struct My_filenode *headNode, struct My_filenode *ph, int page, int pressnum)
{
	struct My_filenode *ttnode;
	int maxnum;
	maxnum = get_maxfilenum(headNode, ph);
	ttnode = count_to_node(headNode, pressnum + maxnum * page); //获得目标节点
	/*检测是否为Ctrl模式，并相应改变改变节点内部参量*/
	if (!(getonebit(bioskey(2), 6) == 1)) // Ctrl按下，保持原有状态不变
	{
		unselect_all(headNode);
	}
	reverseonebit(&(ttnode->flag), 1); //改成反选
}

/********************************
 * FUNCTION:get_lc_maindisplay
 * DESCRIPTION:根据文件标号和模式，计算显示位置的行列数
 * INPUT:显示模式，编号
 * RETURN:数组，元素为（1）行数-1（2）列数-1
 * OTHERS:无
 ********************************/
int *get_lc_maindisplay(int type_maindisplay, int num)
{
	static lc[2] = {0};
	switch (type_maindisplay) //根据不同模式进行相应检测和设置
	{
	case TYPE_LIST_DISPLAY:
		lc[LINE] = num;
		lc[COLUMN] = 0; //只有一列
		break;
	case TYPE_MIDDLEICON_DISPLAY:
		/* 暂不支持 */
		break;
	case TYPE_BIGICON_DISPLAY:
		/* 暂不支持 */
		break;
	case TYPE_SUPERICON_DISPLAY:
		lc[LINE] = (num - 1) / 5;
		lc[COLUMN] = (num - 1) % 5;
		break;
	default:
		pop_error(-1, "GET_LC_MAINDISPLAY:", "Assignment error.");
		exit(1);
		break;
	}
	return lc;
}

/********************************
 * FUNCTION:gettype_mainfile_display
 * DESCRIPTION:获取显示模式
 * INPUT:当前目录头节点，C盘头指针
 * RETURN:显示模式（推荐使用宏定义）
 * OTHERS:无
 ********************************/
int gettype_mainfile_display(struct My_filenode *headnode_current, struct My_filenode *ph)
{
	int type_current, type_all;
	type_all = gettype_dirdisplay(ph->flag);
	type_current = gettype_dirdisplay(headnode_current->flag);
	if (type_all != type_current)
	{
		return type_current;
	}
	else
	{
		return type_all;
	}
}

/********************************
 * FUNCTION:changemouse_write
 * DESCRIPTION:面向搜索框的鼠标光标改变函数
 * INPUT:搜索框（文本框）四点坐标，此时所处模式
 * RETURN:无
 * OTHERS:在搜索框内则变为工形,不在就不变或者变成缺省光标样式，
 * 			从而实现不断更新鼠标情况下鼠标形式的改变
 ********************************/
void changemouse_write(int x1, int y1, int x2, int y2, int mode)
{
	if (MouseX > x1 && MouseX < x2 && MouseY > y1 && MouseY < y2)
	{
		MouseS = 2; //光标显示
	}
	else if (mode == CURSORWRITE_INPUT_MODE) //若是在输入模式内
	{
		MouseS = 0; //设置光标显示
	}
	else
	{
		MouseS = 0; //设置光标显示
	}
}

/****************************
 * 键盘交互模块
 * 返回1说明输入有效，0说明无效。
 * 传递参数：字符数组（栈）指针， 输入处坐标，输入框坐标（四个）,输入字体宽度，
 * 			背景颜色，最大容纳字符数，文本输入模式（输入结束后是否继续显示文本）
 * 返回值：无
 * *************************/
void keybdintraction(char *textipt, int x0, int y0, int x1, int y1, int x2, int y2,
					 int width, int bkcolor, int maxnum, int mode, int ifkey)
{
	int num = 0;		   //栈数计算量，当前位置
	char temp;			   //储存当前字符
	union REGS regs;	   //用于读取键盘缓冲区
	char state_cursor = 0; //光标状态
	int i;

	/*
		ffresh(stdin);	//清空输入缓冲区
		ffresh(stdout); //清空输出缓冲区
						//不能清除？？？？
	*/
	for (i = 0; i < maxnum; i++)
	{
		textipt[i] = '\0';
	}

	clearbuffer_keybd();

	inittimer();
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	setfillstyle(SOLID_FILL, bkcolor);
	clrmous(MouseX, MouseY);
	bar(x1, y1, x2, y2);
	refresh_mouse_display(&MouseX, &MouseY, &press);

	while (1) //主循环，检测状态
	{
		/*鼠标刷新模块*/
		changemouse_write(x1, y1, x2, y2, CURSORWRITE_INPUT_MODE);
		newmouse(&MouseX, &MouseY, &press);

		/*检测字符模块*/
		temp = getbuffer_keybd();

		/*是否退出，如何退出*/

		if (testmouse_bar(x1, y1, x2, y2, MOUSETEST_OUTBAR) == MOUSE_OUTBAR_L)
		{
			textipt[num] = '\0';
			if (mode == TEXTDISPLAY)
			{
				clear_textcursor(x0, width, y1 + 2, y2 - 2, 1, 2, num, bkcolor, maxnum);
			}
			close_textinput(x0, y1 + 1, x2 - 1, y2 - 1, bkcolor, mode);
			longpress_fit();
			MouseS = 0;
			return;
		}
		/*光标闪烁*/
		refresh_textcursor(x0, width, y1 + 2, y2 - 2, 1, 2, RGB000000, 9, num, &state_cursor, bkcolor, maxnum);

		if (temp == 0) //缓冲区为空
		{
			continue;
		}
		else
		{
			switch (temp)
			{
			case VK_ESCAPE: // ESC
				close_textinput(x0, y1 + 1, x2 - 1, y2 - 1, bkcolor, TEXTNOTDISPLAY);
				MouseS = 0;
				return;
			case VK_RETURN: //回车
				textipt[num] = '\0';
				if (mode == TEXTDISPLAY)
				{
					clear_textcursor(x0, width, y1 + 2, y2 - 2, 1, 2, num, bkcolor, maxnum);
				}
				close_textinput(x0, y1 + 1, x2 - 1, y2 - 1, bkcolor, mode);
				MouseS = 0;
				return;
			case VK_BACK: //退格
				if (num > 0)
				{
					num--;
				}
				break;
			default:
				if (('0' <= temp && temp <= '9') || ('A' <= temp && temp <= 'Z') ||
					('_' == temp) || ('a' <= temp && temp <= 'z') || temp == '.' ||
					(temp == '\\') || (temp == ':') ||
					(VK_NUMPAD0 <= temp && temp <= VK_NUMPAD9)) //小键盘
				{
					textipt[num] = temp;
					num++;
					break;
				}
				else
				{
					break;
				}
			}
		}
		/*更新输入框模块*/
		if (ifkey == 0)
		{
			refresh_textbox(x0, y0, y1 + 1, y2 - 1, width, num, bkcolor, textipt, temp, maxnum);
		}
		else
		{
			refresh_keybox(x0, y0, y1 + 1, y2 - 1, width, num, bkcolor, textipt, temp, maxnum);
		}
		/* 更新鼠标图标 */
		// if (testmouse_inoutbar())
	}
}

/*******************************
 * 检测缓冲区函数
 * 若缓冲区有字符,则返回字符的键值（ASCII码）；
 * 若缓冲区无字符，则返回0（NULL的ASCII码）
 * 传递参数：无
 * 返回值：char型数字，可能是0，也可能是有效ASCII码，但是不检测其值
 * *******************************/
char getbuffer_keybd(void)
{
	union REGS regs;	 //用于读取键盘缓冲区
	if (bioskey(1) == 0) //中断不能用……
	{
		return 0;
	}
	else
	{
		regs.h.ah = 0x00;
		int86(0x16, &regs, &regs);
		return (regs.h.al); //把16位寄存器的后八位ASCII码返回
	}
}

/***********************************
 * 清除键盘输入缓冲区函数
 * 传递参数：无
 * 返回值：无
 * ************************************/
void clearbuffer_keybd(void)
{
	char temp;
	temp = getbuffer_keybd();
	while (temp != 0)
	{
		temp = getbuffer_keybd();
	}
	return;
}

/********************************
 * FUNCTION:inittimer
 * DESCRIPTION:初始化定时器，精度18.2分之一秒
 * INPUT:无
 * RETURN:无
 * OTHERS:无
 ********************************/
void inittimer(void) // bios计时器置零
{
	biostime(1, 0);
}

/********************************
 * FUNCTION:judgetimer
 * DESCRIPTION:判断计时函数
 * INPUT:时间间隔（单位为18.2分之一秒）
 * RETURN:0或者1
 * OTHERS:输入时间间隔（），时间达到或者超过设定值返回1并重置计时器，时间未达到设定值返回0
 ********************************/
int judgetimer(long interval)
{
	if (biostime(0, 0) >= interval)
	{
		inittimer();
		return 1;
	}
	else
	{
		return 0;
	}
}

/*********************************************
 * 输入框刷新函数
 * 显示新字，刷掉旧字
 * 传递参数：文字输入位置坐标，输入框上下输出边界，
 * 			字间隔，字符栈数，输入框背景颜色，字符栈（指针），当前（该循环）获得键盘字符，框容纳最大字符量
 * 返回值：无
 * ********************************************/
void refresh_textbox(int x0, int y0, int y1, int y2, int width, int num,
					 int bkcolor, char *textipt, char temp, int maxnum)
{
	setfillstyle(SOLID_FILL, bkcolor);
	if (temp == VK_BACK)
	{
		if (num >= maxnum)
		{
			return;
		}
		else
		{
			clrmous(MouseX, MouseY);
			bar(x0 + width * num, y1, x0 + width * (num + 2), y2); //不包括边框覆盖
			refresh_mouse_display(&MouseX, &MouseY, &press);
		}
	}
	else if (temp == textipt[num - 1]) //字符串增加
	{
		if (num > maxnum)
		{
			return;
		}
		else
		{
			char t[2];
			t[0] = textipt[num - 1];
			t[1] = '\0';
			clrmous(MouseX, MouseY);
			bar(x0 + width * (num - 1), y1, x0 + width * (num + 1), y2);
			refresh_mouse_display(&MouseX, &MouseY, &press);

			outtextxy(x0 + width * (num - 1), y0, t);
		}
	}
}
/********************************
 * FUNCTION:
 * DESCRIPTION:密码输入框刷新
 * INPUT:	文字输入位置坐标，输入框上下输出边界，
 * 			字间隔，字符栈数，输入框背景颜色，当前（该循环）获得键盘字符，框容纳最大字符量
 * RETURN:
 * OTHERS:
 ********************************/
void refresh_keybox(int x0, int y0, int y1, int y2, int width, int num,
					int bkcolor, char *textipt, char temp, int maxnum)
{
	setfillstyle(SOLID_FILL, bkcolor);
	if (temp == VK_BACK)
	{
		if (num >= maxnum)
		{
			return;
		}
		else
		{
			clrmous(MouseX, MouseY);
			bar(x0 + width * num, y1, x0 + width * (num + 2), y2); //不包括边框覆盖
			refresh_mouse_display(&MouseX, &MouseY, &press);
		}
	}
	else if (temp == textipt[num - 1]) //字符串增加
	{
		if (num > maxnum)
		{
			return;
		}
		else
		{
			clrmous(MouseX, MouseY);
			bar(x0 + width * (num - 1), y1, x0 + width * (num + 1), y2);
			refresh_mouse_display(&MouseX, &MouseY, &press);

			dot_write(x0 + width * (num - 1), y0);
		}
	}
}
/********************************
 * FUNCTION:refresh_textcursor
 * DESCRIPTION:光标显示函数，一闪一闪
 * INPUT:字符初始位置，字宽，输入框上下有效边界，线宽，线离字间距，线颜色，
 * 		闪烁间隔（18.2分之一秒），字符栈数，光标状态量（0或1）, 背景颜色,最大容纳字符数
 * RETURN:无
 * OTHERS:无
 ********************************/
void refresh_textcursor(int x0, int width, int y1_, int y2_,
						int L_width, int space, int L_color, int interval,
						int num, char *state, int bkcolor, int maxnum)
{
	if (judgetimer(interval) == 0) //没到设定时间值
	{
		return;
	}
	else if (num <= maxnum) //到时间了,看看是否超过框，超过不画
	{
		*state = !*state;
		if (*state)
		{
			setfillstyle(SOLID_FILL, L_color);
		}
		else
		{
			setfillstyle(SOLID_FILL, bkcolor);
		}
		bar(x0 + num * width + space, y1_, x0 + num * width + L_width, y2_);
	}
}
/********************************
 * FUNCTION:clear_textcursor
 * DESCRIPTION:清除文本输入光标
 * INPUT:字符初始位置，字宽，输入框上下有效边界，线宽，线离字间距，字符栈数, 背景颜色,最大容纳字符数
 * RETURN:无
 * OTHERS:用于退出输入模式但显示文本的情况，防止刷出来一个去不掉的光标
 ********************************/
void clear_textcursor(int x0, int width, int y1_, int y2_, int L_width, int space,
					  int num, int bkcolor, int maxnum)
{
	if (num <= maxnum)
	{
		setfillstyle(SOLID_FILL, bkcolor);
		bar(x0 + num * width + space, y1_, x0 + num * width + L_width, y2_);
	}
}
/************************************
 * 结束图形化输入模式函数
 * 复原输入框
 * 传递参数：输入框有效边界,背景颜色,结束模式
 * 返回值：无
 * ********************************/
void close_textinput(int x1, int y1, int x2, int y2, int bkcolor, int mode)
{
	if (mode == TEXTNOTDISPLAY)
	{
		setfillstyle(SOLID_FILL, bkcolor);
		clrmous(MouseX, MouseY);
		bar(x1, y1, x2, y2);
		refresh_mouse_display(&MouseX, &MouseY, &press);
	}
	else
	{
	}
	clearbuffer_keybd();
}

/****************************
 * 防止按键连续调用功能（关于长按的适配和按一次随缘调用模块的避免）
 * 传递参数：无
 * 返回值：无
 * ***************************/
void longpress_fit(void)
{
	int mousex, mousey, press_last;

	clrmous(MouseX, MouseY); //清除鼠标
	refresh_mouse_display(&MouseX, &MouseY, &press);
	do
	{
		mousex = MouseX;
		mousey = MouseY;
		press_last = press;
		mread(&MouseX, &MouseY, &press); //读取新值

		if (mousex == MouseX && mousey == MouseY)
		{
			continue;
		}
		else
		{
			clrmous(mousex, mousey);	 //清除鼠标
			save_bk_mou(MouseX, MouseY); //保存背景
			drawmous(MouseX, MouseY);	 //画鼠标
		}
	} while (testmouse_presschange(press_last, press) != PTOB);
}

/**********************************
 * 双击检测函数
 * 最多持续7/9秒，检测是否双击
 * 传递参数：方框坐标
 * 返回值：双击为1，非双击为0
//  * *********************************/
int testmouse_doublepress(int x1, int y1, int x2, int y2)
{
	int press_last;
	do
	{
		press_last = press;
		newmouse(&MouseX, &MouseY, &press);								//刷新鼠标
		if ((testmouse_presschange(press_last, press) == PTOB) &&		//鼠标又一次从按下到弹起
			(MouseX > x1 && MouseX < x2 && MouseY > y1 && MouseY < y2)) //且在指定区域
		{
			return 1; //双击了
		}
	} while (judgetimer(DOUBLEPRESS_TIME) == 0); //且在7/9秒内

	return 0; //并没有双击 */
}

/********************************
 * 鼠标点击状态变化检测函数
 * 用于检测鼠标状态切换
 * 传递参数：上一个循环鼠标按下状态数据，本次循环鼠标按下状态数据
 * 返回值：0为不变，1为按到不按，2为不按到按
 * ********************************/
int testmouse_presschange(int press_last, int press_new)
{
	switch (getonebit((Bit)press_last, 8)) //鼠标左键上次循环状态
	{
	case 1: //鼠标左键上次循环处于按下状态
		switch (getonebit((Bit)press_new, 8))
		{
		case 1: //该循环按下
			return PTOP;
		case 0: //弹起
			return PTOB;
		default:
			return 10;
		}
	case 0:
		switch (getonebit((Bit)press_new, 8))
		{
		case 1: //该循环按下
			return BTOP;
		case 0: //弹起
			return BTOB;
		default:
			return 10;
		}
	default:
		pop_error(-1, "TESTMOUSE_PRESSCHANGE:", "Assignment error.");
		exit(1);
		return 10;
	}
}

int get_maxfilenum(My_filenode *headnode_current, My_filenode *ph)
{
	int maxnum;
	switch (gettype_mainfile_display(headnode_current, ph))
	{
	case TYPE_LIST_DISPLAY:
		maxnum = MAXFILENUM_LIST;
		break;
	case TYPE_SUPERICON_DISPLAY:
		maxnum = MAXFILENUM_ICON_SUPER;
		break;
	}
	return maxnum;
}