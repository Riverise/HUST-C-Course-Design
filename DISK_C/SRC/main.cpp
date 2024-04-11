#include "main.h"

int main(void)
{
	/* 相应初始化变量 */
	struct My_filenode *p0;				  //此电脑指针，作为父级读取的终点指针，
	struct My_filenode *p0_for_dir;		  //此电脑目录指针，作为父级读取的终点指针
	struct My_filenode *p0_for_paste;	  //此电脑粘贴板指针，作为父级读取的终点指针
	struct My_filenode *ph;				  // C盘指针，相当于根目录，但是只是一个根
	struct My_filenode *ph_for_dir;		  // C盘所有目录指针，是所有目录链表的头节点指针
	struct My_filenode *ph_for_paste;	  //后端操作，指向被复制处的指针，从而将pc_for_paste所指内容复制到此处
	struct My_filenode *pc;				  // 对于主文件区显示
	struct My_filenode *pc_for_dir;		  // C盘所有目录
	struct My_filenode *pc_for_paste;	  //暂时的粘贴板指针，用到粘贴板的时候建立链表，不用就释放
	struct My_filenode *ch;				  // pc链的终点，以后用作指向当前目录链表的头节点的指针，从而画出当前目录（暂存头节点）
	struct My_filenode *ttnode, *ttnode_; //目标指针，指向要操作的节点
	struct My_filenode *tt_node;
	struct My_vector_ *search;		//保存搜索结果，保存链表的头结点的指针
	struct My_vector_ *paste;		//粘贴板，指向粘贴板链表头节点的指针
	struct My_vector_ *history;		//历史记录，指向历史记录（对于打开的目录的历史）的头结点指针
	struct My_vector_ *currenthead; //指向history链的当前显示的目录对应的history节点，记录绝对路径
	// struct My_vector_ *tt_node;		//目标指针，指向要操作的节点
	char sort_way = 0; //排序方式
	char state_menu;
	int judge_sort;				  //判断是否排序刷新
	char textipt[33];			  //用于接受输入文字，最多32个字符
	char refresh_mode;			  //刷新显示模式，默认全部刷新
	char page[4] = {0, 0, 0, -1}; //页数
	int if_doublepress;			  //双击判定/记录变量
	int i;						  //循环辅助变量
	int num_count;
	int judge_search = 0;						 //搜索辅助变量,非0为搜索模式
	int judge_paste;							 //判断粘贴模式：复制or剪切
	int *pressstate_fm;							 //主文件区鼠标点击状态指针（会指向static）
	int *pressstate_tr;							 //树形区鼠标点击状态指针（会指向与上一个相同的static）
	int *pressstate_srch;						 //搜索界面鼠标点击指针（指向与上一个相同的static）
	int press_l;								 //上一个循环中press的状态，用于检测鼠标状态变化，从而检测双击
	int state_ft[2], state_fm[2], state_srch[2]; //文件显示状态，用于判断状态变化，从而实时检测鼠标并改变背景变蓝
	char tree_ch_num[2] = {-1, -1};				 //用于保证一次只选中或和展开一个
	State state_bt[25] = {0};					 //按键显示状态按位量，记录和控制显示状态
	Bit mainfile_ch_dsplstate[3] = {0};			 //主文件区各个文件块显示状态，防止过多刷新，限制刷新次数
	int menu_number;
	int search_num;

	/* 欢迎界面 */
	initsvga256();
	initcolor256();
	delay(600);
	welcome_page0();
	delay(500);
	welcome_page1();

	pcinit(&ch, &p0, &ph, &pc, &p0_for_dir, &ph_for_dir, &pc_for_dir,
		   &p0_for_paste, &ph_for_paste, &pc_for_paste, &paste,
		   &history, &currenthead, &search, &sort_way, state_bt);

	delay(500);

	/* 欢迎界面 */
	if (function_log(textipt) == 1)
	{
		/* 退出和释放函数 */
		// sleep(1); //延时1s
		close_init(p0, ph, pc, p0_for_dir, ph_for_dir, pc_for_dir,
				   p0_for_paste, ph_for_paste, pc_for_paste, paste,
				   history, search);
		closesvga256();
		chdir("C:\\win_pro\\SRC\\"); //便于下一次打开
		return 0;
	}

	drawbk(); //主背景绘制
	move_dir(history, &currenthead, 'n', p0);
	/* 进入主循环1 */
	while (1)
	{
		/* 根据节点重新扫描文件和建立链表 （刷新） */
		refresh_all(&ch, pc_for_dir, ph, currenthead, &refresh_mode, tree_ch_num, page, state_bt);
		/* 主循环2 */
		while (1)
		{
			/* 一些链表遍历操作函数，依靠参数控制的函数，链表绘制函数 */
			if (1 == func_refresh(state_bt, &ch, history, search, ph, pc_for_dir, paste,
								  &currenthead, page, textipt, &judge_search, &refresh_mode))
			{
				break;
			}
			display_filenum(ch);
			state_ft[LAST] = -1;   //检测（交互）循环进入状态量的初始化
			state_fm[LAST] = -1;   //同上
			state_srch[LAST] = -1; //同上

			/* 主循环3 */
			while (1)
			{
				press_l = press; //旧数据保存
				newmouse(&MouseX, &MouseY, &press);
				testbtnstate_setgbl(state_bt, ch, history, search, ph, pc_for_dir->son_list_head, paste, currenthead, page, judge_search);
				/* 检测鼠标位置，进入不同功能区调用 */
				switch (testmouse_wherenow(MouseX, MouseY))
				{
				case TREEFILE_NUMBAR:
					do //进入区域检测和功能调用分循环
					{
						press_l = press; //旧数据保存
						newmouse(&MouseX, &MouseY, &press);
						refresh_filetreestate(state_ft, pc_for_dir->son_list_head, page[TREEFILE_NUMBAR]);
						pressstate_tr = test_file_mousepress(pc_for_dir->son_list_head, page);
						if (pressstate_tr[0] == LEFTPRESS && pressstate_tr[2] != -1) //点击了
						{
							chgto_treedir(&ch, history, &currenthead, search, ph, pc_for_dir, tree_ch_num, pressstate_tr, page, &judge_search, &refresh_mode);
							break;
						}
					} while (testmouse_wherenow(MouseX, MouseY) == TREEFILE_NUMBAR);
					break;
				case MAINFILE_NUMBAR:
					//进入区域检测和功能调用分循环
					if (judge_search == 0)
					{
						do //非搜索模式，区域检测和功能调用分循环
						{
							press_l = press; //旧数据保存
							newmouse(&MouseX, &MouseY, &press);
							refresh_filemainstate(state_fm, ch, ph, page[MAINFILE_NUMBAR]);
							if_doublepress = func_mianfile(&pressstate_fm, state_fm, mainfile_ch_dsplstate,
														   ch, page, press_l, state_bt, search,
														   paste, history, ph, pc_for_dir->son_list_head,
														   currenthead, judge_search); //主要功能实现,检测双击返回1
							if (if_doublepress == 1)
							{
								/*双击功能模块执行*/

								tt_node = count_to_node(ch, pressstate_fm[2] + get_maxfilenum(ch, ph) * page[MAINFILE_NUMBAR]);

								if (tt_node->flag & IS_DIR)
								{
									/* 修改当前目录 */
									move_dir(history, &currenthead, 'n', tt_node);
									ch = find_node_by_path(ph, currenthead->path);
									settype_dirdisplay(&(ch->flag), gettype_dirdisplay(ph->flag));
									refresh_mode = REFRESH_MAINFILE_ONLY; //需要刷新显示
									break;
								}
							}
							if (testmouse_bar(MAINFILEAREA_X1, MAINFILEAREA_Y1, MAINFILEAREA_X2, MAINFILEAREA_Y2, MOUSETEST_INBAR) == MOUSE_INBAR_R)
							{
								if (state_fm[NOW] > 0 && getnum_choose(ch) > 0) //有效区域
								{
									menu_number = func_menu(FILE_MENU, state_menu, state_bt, &ch, ph, ph_for_paste, paste, textipt, page, &judge_paste, &judge_sort);
									if (menu_number == BTN_NO_USE || menu_number == ATTRI_BTN)
									{
									}
									else if (menu_number == DELETE_BTN)
									{
										refresh_mode = REFRESH_MAINFILE_ONLY;
										break;
									}
									else if (menu_number == CUT_BTN || menu_number == COPY_BTN)
									{
										judge_paste = menu_number;
										break;
									}
								}
								else
								{
									menu_number = func_menu(DIR_MENU, state_menu, state_bt, &ch, ph, ph_for_paste, paste, textipt, page, &judge_paste, &judge_sort);
									if (menu_number == BTN_NO_USE)
									{
									}
									else if (menu_number == NEWDIR_BTN || menu_number == NEWFILE_BTN)
									{
										refresh_mode = REFRESH_MAINFILE_ONLY;
										break;
									}
									else if (judge_sort == 1)
									{
										refresh_mode = REFRESH_MAINFILE_ONLY;
										break;
									}
									else if (menu_number == LISTDISPLAY_BTN || menu_number == ICONDISPLAY_BTN)
									{
										refresh_mode = REFRESH_MAINFILE_ONLY;
										break;
									}
									else if (menu_number == REFRESH_BTN)
									{
										if (judge_search != 0)
										{
											judge_search = 0;
										}
										refresh_mode = REFRESH_ALL;
										break;
									}
									else if (menu_number == PASTE_BTN)
									{
										refresh_mode = REFRESH_MAINFILE_ONLY;
										break;
									}
									else if (menu_number == 10)
									{
										refresh_mode = REFRESH_MAINFILE_ONLY;
										break;
									}
								}
							}
							while (testmouse_inoutbar(219, 165, 835, 181) == 1)
							{
								newmouse(&MouseX, &MouseY, &press);
								judge_sort = testdo_sortbt(gettype_mainfile_display(ch, ph), &sort_way, ch);
								if (judge_sort == 1)
								{
									refresh_mode = REFRESH_MAINFILE_ONLY; //需要刷新显示
									break;
								}
							}
							if (judge_sort == 1)
							{
								judge_sort = 0;
								break;
							}
						} while (testmouse_wherenow(MouseX, MouseY) == MAINFILE_NUMBAR);
					}
					else
					{
						do //搜索模式，区域检测和功能调用分循环
						{
							press_l = press; //旧数据保存
							newmouse(&MouseX, &MouseY, &press);

							refresh_filesearch_state(state_srch, search);
							search_num = test_search_mousepress(press_l);
							if (-1 != search_num)
							{
								tt_node = vector_to_filenode(ph, count_to_node(search, search_num));
								if (tt_node->flag & IS_DIR)
								{
									move_dir(history, &currenthead, 'n', tt_node);
									ch = find_node_by_path(ph, currenthead->path);
									settype_dirdisplay(&(ch->flag), gettype_dirdisplay(ph->flag));
									page[MAINFILE_NUMBAR] = 0;
									refresh_mode = REFRESH_MAINFILE_ONLY; //需要刷新显示
									judge_search = 0;
									break;
								}
								else
								{
									ch = find_node_by_path(ph, count_to_node(search, search_num)->path);
									move_dir(history, &currenthead, 'n', ch->father);
									settype_dirdisplay(&(ch->flag), gettype_dirdisplay(ph->flag));
									page[MAINFILE_NUMBAR] = 0;
									refresh_mode = REFRESH_MAINFILE_ONLY; //需要刷新显示
									judge_search = 0;
									break;
								}
							}

						} while (testmouse_wherenow(MouseX, MouseY) == MAINFILE_NUMBAR);
					}

					break;
				case OTHER_NUMBAR:
					int btn_number;
					do //进入区域检测和功能调用分循环
					{
						newmouse(&MouseX, &MouseY, &press);
						/* 功能检测和实现模块 */
						btn_number = testdo_mainbt(state_bt, &ch, history, &currenthead, ph, pc_for_dir,
												   mainfile_ch_dsplstate, currenthead, search, paste, ph_for_paste,
												   textipt, page, judge_paste, judge_search);
						if (btn_number == BTN_NO_USE)
						{
							/* 什么都不做 */
						}
						else if (btn_number == L_ARROW_BTN || btn_number == UP_ARROE_BTN)
						{
							if (judge_search != 0) //若在搜索模式
							{
								page[SEARCH_NUMBER] = 0;
								judge_search = 0; //退出搜索模式
							}
							page[MAINFILE_NUMBAR] = 0;
							refresh_mode = REFRESH_MAINFILE_ONLY;
							break;
						}
						else if (btn_number == R_ARROE_BTN)
						{
							refresh_mode = REFRESH_MAINFILE_ONLY;
							page[MAINFILE_NUMBAR] = 0;
							break;
						}
						else if (btn_number == LISTDISPLAY_BTN || btn_number == ICONDISPLAY_BTN ||
								 btn_number == NEWDIR_BTN || btn_number == NEWFILE_BTN ||
								 btn_number == DELETE_BTN || btn_number == PASTE_BTN)
						{
							if (judge_search == 0)
							{
								refresh_mode = REFRESH_MAINFILE_ONLY;
							}
							break;
						}
						else if (btn_number == MAIN_NEXTPAGE_BTN || btn_number == MAIN_LASTPAGE_BTN)
						{
							if (judge_search == 0)
							{
								refresh_mode = REFRESH_MAINFILE_ONLY;
							}
							else
							{
								refresh_mode = REFRESH_MAINFILE_SEARCHMODE_ONLY;
							}
							break;
						}
						else if (btn_number == TREE_NEXTPAGE_BTN || btn_number == TREE_LASTPAGE_BTN)
						{
							refresh_mode = REFRESH_TREEFILE_ONLY;
							break;
						}
						else if (btn_number == CLOSE_BTN)
						{
							/* 退出和释放函数 */
							// sleep(1); //延时1s
							close_init(p0, ph, pc, p0_for_dir, ph_for_dir, pc_for_dir,
									   p0_for_paste, ph_for_paste, pc_for_paste, paste,
									   history, search);
							closesvga256();
							chdir("C:\\win_pro\\SRC\\"); //便于下一次打开
							return 0;
						}
						else if (btn_number == SEARCH_BAR)
						{
							/* 搜索功能 */
							if (strlen(textipt) != 0)
							{
								refresh_mode = REFRESH_MAINFILE_SEARCHMODE_ONLY;
								page[SEARCH_NUMBER] = 0;
								page[SEARCH_NUMBER_CTT] = -1; //搜索模式初始化
								break;
							}
						}
						else if (btn_number == CUT_BTN || btn_number == COPY_BTN)
						{
							judge_paste = btn_number;
							break;
						}
						else if (btn_number == REFRESH_BTN)
						{
							if (judge_search != 0)
							{
								judge_search = 0;
							}
							refresh_mode = REFRESH_ALL;
							break;
						}
						else if (btn_number == ADDRESS_BAR)
						{
							if (chdir(textipt) == -1) //路径无效
							{
								pop_error(0, "MAIN:", "illegle address.");
								write_imagedata(164, 138, 816, 160, "IMDATA_0");
								break;
							}
							else
							{
								if (judge_search != 0) //若在搜索模式
								{
									page[SEARCH_NUMBER] = 0;
									judge_search = 0; //退出搜索模式
								}
								ch = find_node_by_path(ph, textipt);
								move_dir(history, &currenthead, 'n', ch->father);
								settype_dirdisplay(&(ch->flag), gettype_dirdisplay(ph->flag));
								refresh_mode = REFRESH_MAINFILE_ONLY;
								break;
							}
						}
						else if (btn_number == DOWN_ARROW_BTN)
						{
							refresh_mode = REFRESH_MAINFILE_ONLY; //需要刷新显示

							page[MAINFILE_NUMBAR] = 0;
							judge_search = 0;
							break;
						}
						testbtnstate_mouse(state_bt); //鼠标
						refreshbtnstate(state_bt);
						changemouse_write(848, 137, 1016, 161, CURSORWRITE_NOTINPUT_MODE);
					} while (testmouse_wherenow(MouseX, MouseY) == OTHER_NUMBAR);
					for (i = 0; i < 20; i++)
					{
						set0onebit(&state_bt[i], IFH_N);
					}
					break;
				}
				if (refresh_mode != REFRESH_NOTATALL)
				{
					break;
				}
			}
		}
	}
}