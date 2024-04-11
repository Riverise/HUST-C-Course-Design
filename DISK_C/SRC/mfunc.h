/*************************************
 * 主要的功能函数
 *
 * 2022/4/8  把按键检测，主文件区选中实现加入
 * **********************************/

#ifndef _MFUNC_H_

#define _MFUNC_H_

#include "main.h"

#define MAXDIRNUM_TREE 20 //树形文件区最大显示文件块数
#define X_TREEFILE 2
#define Y_TREEFILE 178
#define HEIGHT_TREEFILE 24
#define WIDTH_TREEFILE 176
#define SPACE_X_ARROE 25

#define X_MAINFILE_LIST 215		//主文件区列表左上角横坐标
#define Y_MAINFILE_LIST 178		//主文件区列表左上角纵坐标
#define HEIGHT_MAINFILE_LIST 23 //主文件区列表显示高度
#define WIDTH_MAINFILE_LIST 604 //主文件区列表有效显示宽度

#define X_MAINFILE_ICON_SUOER 230	   //主文件区缩略图超大图标左上角横坐标
#define Y_MAINFILE_ICON_SUOER 181	   //主文件区缩略图超大图标左上角纵坐标
#define NUMBER_X_MAINFILE_ICON_SUOER 5 //主文件区缩略图超大图标每行显示文件数
#define NUMBER_Y_MAINFILE_ICON_SUOER 3 //主文件区缩略图超大图标每列显示文件数
#define HEIGHT_MAINFILE_ICON_SUPER 170 //主文件区缩略图超大图标有效显示高度
#define WIDTH_MAINFILE_ICON_SUPER 134  //主文件区缩略图超大图标有效显示宽度
#define SPACE_Y_MAINFILE_ICON_SUPER 15 //主文件区缩略图超大图标，文件块纵向间隔
#define SPACE_X_MAINFILE_ICON_SUPER 24 //主文件区缩略图超大图标，文件块横向间隔

#define X_MAINFILR_SEARCH 215
#define Y_MAINFILE_SEARCH (138 + 52)
#define HEIGHT_MAINFILE_SEARCH 48
#define WIDTH_MAINFILE_SEARCH 799
#define SPACE_Y_MAINFILE_SEARCH 4

#define DOUBLEPRESS_TIME 6 //双击间隔时间，单位十八分之一秒
/* 主文件区有效空间范围 */
#define MAINFILEAREA_X1 210
#define MAINFILEAREA_Y1 168
#define MAINFILEAREA_X2 1016
#define MAINFILEAREA_Y2 745
/* 树形文件区有效范围 */
#define TREEFILEAREA_X1 1
#define TREEFILEAREA_Y1 168
#define TREEFILEAREA_X2 208
#define TREEFILEAREA_Y2 745

#define SEARCHBAR_MAXNUM 15	 //搜索框最大容纳字符数
#define ADDRESSBAR_MAXNUM 64 //地址栏最大容纳字符数

enum max_filenumber
{
	MAXFILENUM_LIST = 20,
	MAXFILENUM_ICON_SUPER = 15,
	MAXFILENUM_SEARCH = 10,
};

enum area_numbar
{
	TREEFILE_NUMBAR,
	MAINFILE_NUMBAR,
	SEARCH_NUMBER,
	SEARCH_NUMBER_CTT, //用于同前者对比以确定是否刷新，相当于旧量，初值取-1，
	OTHER_NUMBAR,
};

enum refresh_file_wheremode
{
	REFRESH_NOTATALL,
	REFRESH_MAINFILE_ONLY,
	REFRESH_TREEFILE_ONLY,
	REFRESH_FILE_ALL,
	REFRESH_ALL,
	REFRESH_MAINFILE_SEARCHMODE_ONLY,
};

/*********************
 * 各个按键编号
 * *******************/
enum btn_num
{
	CLOSE_BTN,
	COPY_BTN,
	PASTE_BTN,
	CUT_BTN,
	DELETE_BTN,
	RENAME_BTN,
	NEWDIR_BTN,
	NEWFILE_BTN,
	ATTRI_BTN,
	CHALL_BTN,
	CLRALL_BTN,
	CHCTRY_BTN,
	L_ARROW_BTN,
	R_ARROE_BTN,
	UP_ARROE_BTN,
	REFRESH_BTN,
	LISTDISPLAY_BTN,
	ICONDISPLAY_BTN,
	SEARCH_BAR,
	ADDRESS_BAR,
	MAIN_NEXTPAGE_BTN,
	MAIN_LASTPAGE_BTN,
	TREE_NEXTPAGE_BTN,
	TREE_LASTPAGE_BTN,
	BTN_NO_USE,
	DOWN_ARROW_BTN,
};

typedef struct
{
	int x0; //显示区左上角坐标
	int y0;
	int height; //长和宽（无意义用0代替）
	int width;
	int space_x_ico; //图表显示处相对于左上角的坐标
	int space_y_ico;
	int space_x_n; //输入处(文字)相对左上角的坐标
	int space_y_n;
	int displaytype_main;
	int maxfilenum; //模式
	int maxnum_currenttype;
} Funcdata;

/****************************
 * 初始化按键状态
 * 传递参数：按键状态检测数组首地址
 * 无返回值
 * ***********************/
void initbtnstate(State *state);

/***************************
 * 检测各个按键状态
 * 传递参数：按键状态检测数组首地址
 * 无返回值
 * ***********************/
void testbtnstate_mouse(State *state);

/********************************
 * FUNCTION:testbtnstate_setgbl
 * DESCRIPTION:根据交互/结点内置/设置来设置全局按键显示方式
 * INPUT:按键状态数组地址，主文件头节点，历史记录链表头节点，此电脑指针，C盘指针，粘贴板指针,当前目录指针
 * RETURN:无
 * OTHERS:不包括翻页检测
 ********************************/
void testbtnstate_setgbl(State *state, struct My_filenode *headnode_main, struct My_vector_ *history, struct My_vector_ *search,
						 struct My_filenode *ph, struct My_filenode *pc_dir_sonhead, struct My_vector_ *headnode_pasting,
						 struct My_vector_ *currenthead, char *page, int judge_search);

/**************************
 * 刷新显示各个按键状态
 * 刷新显示
 * 传递参数：按键状态检测数组首地址
 * 无返回值
 * ***********************/
void refreshbtnstate(State *state);

/****************************************
 * 检测主页所有按键是否左键单击并执行相关功能
 * 传递参数：按键状态数组地址，主文件头节点，历史记录链表头节点，
 * 			当前结点指针地址，C盘指针，主文件显示状态数组首地址，字符记录数组，当前页数，
 * 返回值：功能按键编号
 * **************************************/
int testdo_mainbt(State *state, struct My_filenode **p_headNode_main, struct My_vector_ *history,
				  struct My_vector_ **p_currenthead, struct My_filenode *ph,
				  struct My_filenode *pc_for_dir, Bit *dsplstate_main, struct My_vector_ *currenthead,
				  struct My_vector_ *search, struct My_vector_ *paste, struct My_filenode *ph_for_paste, char *textipt,
				  char *page, int judge_paste, int judge_search);

/***************************************
 * 鼠标所处区域检测
 * 检测鼠标位于哪个区域
 * 传递参数：鼠标位置
 * 返回值：	主文件区返回0；
 * 			树形文件区返回1；
 * 			其他区域返回2。（建议使用宏定义）
 * ************************************/
int testmouse_wherenow(int mousex, int mousey);

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
					struct My_vector_ **p_currenthead, char *textipt, int *p_num_search, char *page, int mode);

/********************************
 * FUNCTION:testdo_sortbt
 * DESCRIPTION:主文件区列表显示模式，改变排序模式
 * INPUT:显示模式，排序方式变量，当前节点
 * RETURN:成功返回1
 * OTHERS:无
 ********************************/
int testdo_sortbt(int mode, char *sorttype, My_filenode *headnode_current);
/********************************
 * FUNCTION:
 * DESCRIPTION:获取节点相关信息
 * INPUT:信息结构体，画图函数指针地址，*ch，ph
 * RETURN:
 * OTHERS:
 ********************************/
void getfuncdata(Funcdata *func_current, void (**draw_mainfile)(int x1, int y1, struct My_filenode *headnode, int n, int state, int page), My_filenode **p_headnode_current, My_filenode *ph);

#endif