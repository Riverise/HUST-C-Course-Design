/*********************
 * 仿windows资源管理器，界面绘制
 *
 * 绘制基本模块
 * 1st > 2022/3/10,初步绘制背景
 * 2nd > 2022/3/14,绘制一些小图标和按钮
 * 3rd > 2022/3/18,修改检测模块，实现鼠标停留图标加深或者背景变蓝
 * 4th > 2022/3/19,大改原有函数，旧参数不兼容检测和绘制模块
 * 5th > 2022/3/26,绘制功能区，设置新函数：包括不可点击状态的灰图标绘制
 * 6th > 2022/3/27,增加初始化按键状态
 * 7th > 2022/4/10,增加一个输出文本函数，用于列表详细信息模式的说明
 * **********************/

#ifndef _IFDR_H_

#define _IFDR_H_

#include "main.h"

#ifndef _STATE_

#define _STATE_

/**********************
 * 关于按位类型State的说明
 * State是一个unsigned char型，按位存储信息的量
 * 其各个位置的信息为
 *  _ _ _ _ _ _ _ _
 * |_|_|_|_|_|_|_|_|
 *  1 2 3 4 5 6 7 8
 * > 1 （按键）此次循环是否可以点击（是否变灰/变亮）
 * > 2 此次循环鼠标在/不在状态      //鼠标是否在此按键范围内（是否颜色加深/背景变蓝）
 * > 3 上次循环鼠标在/不在状态      //是否再画一遍
 * > 4 是否用图标画过一次			//点击文件（选中）时功能模块需要改变这个值
 * > 5 这次循环是否选中该按键		//功能模块需要改变其值
 * > 6 上次循环是否选中该按键
 * > 7 上次循环是否可以点击
 *
 * bool量，0表示否，1表示是
 * ********************/
typedef unsigned char State;

enum state_bit
{
	IFP_N = 1, //此次循环是否可以点击
	IFH_N,	   //上次循环鼠标在不在这里
	IFH_L,	   //这次循环鼠标在不在这里
	IFD_1,	   //是否显示过一次
	IFC_N,	   //这次循环是否选中该按键
	IFC_L,	   //上次循环是否选中该按键
	IFP_L,	   //上次循环是否可以点击
};
#endif

#define HEIGHT_MENU_FILE 106
#define WIDTH_MENU_FILE 100
#define HEIGHT_MENU_DIR 106
#define WIDTH_MENU_DIR 100

#define SPACE_BLACK 2

enum direct_menu
{
	LEFT_UP,
	LEFT_DOWN,
	RIGHT_UP,
	RIGHT_DOWN,
};

enum mode_menu
{
	DIR_MENU,
	FILE_MENU,
};

enum direct_sonmenu
{
	LEFT,
	RIGHT,
};

/********************************
 * FUNCTION:drawbk
 * DESCRIPTION:绘制背景
 * INPUT:无
 * RETURN:成功绘图返回1
 * OTHERS:主要包括：分区，右下按键等更换目录（切换界面时不变部分
 ********************************/
int drawbk(void);

/********************************
 * FUNCTION:display_listnodes
 * DESCRIPTION:在列表详细信息显示模式输出说明各个部分的文本
 * INPUT:无
 * RETURN:无
 * OTHERS:无
 ********************************/
void display_listnodes(void);

/********************************
 * FUNCTION:changedisplay_fixedbt
 * DESCRIPTION:固定按键的实时刷新显示函数
 * INPUT:被调用绘图函数（按键绘制函数），对应绘制函数缺省绘制颜色，激发背景颜色，激发边框颜色，state状态地址。
 * RETURN:无
 * OTHERS:通过调用不同函数（函数指针）实现背景颜色的转变，激发背景颜色。检测状态
 ********************************/
void changedisplay_fixedbt(void (*drawfunc)(int bkcolor, int bordercolor),
						   int defbkcolor, int excbkcolor, int excbordercolor, State *state);
void changedisplay_fixedbt(void (*drawfunc)(int bkcolor), int defbkcolor, int excbkcolor, State *state);

/********************************
 * FUNCTION:changedisplay_function
 * DESCRIPTION:非 常亮按键的实时刷新显示（是否显示，背景改变）函数
 * INPUT:被调用绘图函数（按键绘制函数），对应绘制函数缺省背景绘制颜色，激发背景颜色，激发边框颜色，state状态地址。
 * RETURN:无
 * OTHERS:通过调用不同函数（函数指针）实现判断显示状态，背景颜色的转变，激发背景颜色。检测状态
 ********************************/
void changedisplay_function(void (*drawfunc)(int bkcolor, int bordercolor, State state),
							int defbkcolor, int excbkcolor, int excbordercolor, State *state);
void changedisplay_function(void (*drawfunc)(int bkcolor, State state), int defbkcolor, int excbkcolor, State *state);

/********************************
 * FUNCTION:changedisplay_chfixedbt
 * DESCRIPTION:特别的（指右下角两个）固定按键的实时刷新显示函数
 * INPUT:被调用绘图函数（按键绘制函数），对应绘制函数缺省背景绘制颜色，激发背景颜色，激发边框颜色，state状态地址。
 * RETURN:无
 * OTHERS:通过调用不同函数（函数指针）实现判断显示状态，背景颜色的转变，激发背景颜色。检测状态
 ********************************/
void changedisplay_chfixedbt(void (*drawfunc)(int bkcolor, int bordercolor, State state),
							 int defbkcolor, int excbkcolor, int excbordercolor, State *state);

/***********************
 * 关闭叉叉绘制，
 * 传递参数：箭头颜色，第二个随便
 * 无返回
 * ***********************/
void closeXdraw_o(int bkcolor);

/********************************
 * FUNCTION:larrowdraw_b
 * DESCRIPTION:对后退箭头的绘制和反应
 * INPUT:颜色，第二个没有用（为了保持函数指针调用参数一致），按键状态
 * RETURN:无
 * OTHERS:左上角后退绘制
 ********************************/
void larrowdraw_b(int icocolor, State state);
void larrowdraw_o(int icocolor, int x, int y);

/********************************
 * FUNCTION:larrowdraw_main_npg
 * DESCRIPTION:树形文件区上一页箭头
 * INPUT:颜色，第二个没有用（为了保持函数指针调用参数一致），按键状态
 * RETURN:无
 * OTHERS:无
 ********************************/
void larrowdraw_main_lpg(int icocolor, State state);

/********************************
 * FUNCTION:larrowdraw_tree_npg
 * DESCRIPTION:树形文件区上一页箭头
 * INPUT:颜色，第二个没有用（为了保持函数指针调用参数一致），按键状态
 * RETURN:无
 * OTHERS:无
 ********************************/
void larrowdraw_tree_lpg(int icocolor, State state);

/********************************
 * FUNCTION:rarrowdraw_f
 * DESCRIPTION:对前进箭头的绘制和反应
 * INPUT:颜色，第二个没有用（为了保持函数指针调用参数一致），按键状态
 * RETURN:无
 * OTHERS:左上角前进绘制
 ********************************/
void rarrowdraw_f(int icocolor, State state);

/********************************
 * FUNCTION:rarrowdraw_main_npg
 * DESCRIPTION:主文件区下一页
 * INPUT:颜色，第二个没有用（为了保持函数指针调用参数一致），按键状态
 * RETURN:无
 * OTHERS:无
 ********************************/
void rarrowdraw_main_npg(int icocolor, State state);

/********************************
 * FUNCTION:rarrowdraw_tree_npg
 * DESCRIPTION:树形文件区下一页
 * INPUT:颜色，第二个没有用（为了保持函数指针调用参数一致），按键状态
 * RETURN:无
 * OTHERS:无
 ********************************/
void rarrowdraw_tree_npg(int icocolor, State state);
/********************************
 * FUNCTION:rarrowdraw_o
 * DESCRIPTION:绘制右箭头函数
 * INPUT:颜色，坐标
 * RETURN:无
 * OTHERS:无
 ********************************/
void rarrowdraw_o(int icocolor, int x, int y);

/*******************
 * 上箭头绘制
 * 传递参数：背景颜色，边框颜色
 * 无返回值
 * 备注：箭头背景没有边框，故下一个参数没有作用
 * *****************/
void uparrowdraw(int bkcolor, State state);
void uparrowdraw_o(int bordercolor);

/***********************************
 * 刷新图标绘制
 * 传递参数：背景色，边框色
 * 无返回值
 * ***********************************/
void refreshicodraw_o(int bkcolor, int bordercolor);

/*************************
 * 右下角左按钮绘制
 * 传递参数：背景底板颜色，边框颜色
 * 无返回值
 * ************************/
void listdisplay_draw(int bkcolor, int bordercolor, State state);
void listdisplay_draw_o(int bkcolor, int bordercolor);

/*************************
 * 右下角右按钮绘制
 * 传递参数：背景底板颜色，边框颜色
 * 无返回值
 * ************************/
void icondisplay_draw(int bkcolor, int bordercolor, State state);
void icondisplay_draw_o(int bkcolor, int bordercolor);
void icondisplaywrite(void);

/*******************************
 * 复制按键 绘制
 * 传递参数：；背景颜色，边框颜色
 * 无返回值
 * *****************************/
void copybtn_draw(int bkcolor, int bordercolor, State state);
void copybtn_draw_o(int bkcolor, int bordercolor, int linecolor, int textcolor);

/*****************************
 * 粘贴按键 绘制
 * 传递参数：背景颜色，边框颜色，状态量（是否可以点击）
 * 无返回值
 * *****************************/
void pastebtn_draw(int bkcolor, int bordercolor, State state);
void pastebtn_draw_o(int bkcolor, int bordercolor, int linecolor,
					 int trianglecolor, int textcolor);

/************************************
 * 剪切按键 绘制
 * 传递参数：背景颜色，边框颜色，状态量（是否可以点击）
 * 无返回值
 * *****************************/
void cutbtn_draw(int bkcolor, int bordercolor, State state);
void cutbtn_draw_o(int upcolor, int handlecolor, int textcolor);

/*******************************
 * 删除按键 绘制
 * 传递参数：背景颜色，边框颜色，状态量（是否可以点击）
 * 无返回值
 * *****************************/
void deletebtn_draw(int bkcolor, int bordercolor, State state);
void deletebtn_draw_o(int btncolor, int textcolor);

/*****************************
 * 重命名按键 绘制
 * 传递参数：背景颜色，边框颜色，状态量（是否可以点击）
 * 无返回值
 * *****************************/
void renamebtn_draw(int bkcolor, int bordercolor, State state);
void renamebtn_draw_o(int bkcolor, int linecolor, int squarecolor, int textcolor);

/*******************************************
 * 新建文件夹按键 绘制
 * 传递参数：背景颜色，边框颜色，状态量（是否可以点击）
 * 无返回值
 * *****************************/
void newdirbtn_draw(int bkcolor, int bordercolor, State state);
void newdirbtn_draw_o(int linecolor, int behindbkcolor, int frontbkcolor, int textcolor);

/********************************************
 * 新建文件按键 绘制
 * 传递参数：背景颜色，边框颜色，状态量（是否可以点击）
 * 无返回值
 * *****************************/
void newfilebtn_draw(int bkcolor, int bordercolor, State state);
void newfilebtn_draw_o(int bordercolor, int bkcolor, int addcolor, int textcolor);
void btnfilebasic_draw(int x, int y, int bordercolor, int bkcolor);

/********************************************
 * 属性按键 绘制
 * 传递参数：背景颜色，边框颜色，状态量（是否可以点击）
 * 无返回值
 * *****************************/
void attributebtn_draw(int bkcolor, int bordercolor, State state);
void attributebtn_draw_o(int bordercolor, int bkcolor, int tickcolor, int textcolor);

/*********************************************
 * 全部选中按键 绘制
 * 传递参数：背景颜色，边框颜色，状态量（是否可以点击）
 * 无返回值
 * *****************************/
void challbtn_draw(int bkcolor, int bordercolor, State state);
void challbtn_draw_o(int bordercolor, int bkcolor, int incolor, int textcolor);

/********************************************
 * 全部取消按键 绘制
 * 传递参数：背景颜色，边框颜色，状态量（是否可以点击）
 * 无返回值
 * *****************************/
void cclallbtn_draw(int bkcolor, int bordercolor, State state);
void cclallbtn_draw_o(int bordercolor, int bkcolor, int incolor, int textcolor);

/***********************************************
 * 反向选择按键 绘制
 * 传递参数：背景颜色，边框颜色，状态量（是否可以点击）
 * 无返回值
 * *****************************/
void chctrybtn_draw(int bkcolor, int bordercolor, State state);
void chctrybtn_draw_o(int bordercolor_a, int bordercolor_b, int bkcolor,
					  int incolor_a, int incolor_b, int textcolor);

/********************************
 * FUNCTION:addressnow_display
 * DESCRIPTION:画地址栏地址
 * INPUT:当前指针，C盘指针
 * RETURN:无
 * OTHERS:无
 ********************************/
void addressnow_display(My_filenode *headnode_current, My_filenode *ph, My_vector_ *currenthead);

/********************************
 * FUNCTION: maketext_addressbar
 * DESCRIPTION:把标准路径转化一下
 * INPUT:目标字符串，源字符串
 * RETURN:无
 * OTHERS:无
 ********************************/
void maketext_addressbar(char *ttstring, char *soursestring);

/********************************
 * FUNCTION:close_searchbar
 * DESCRIPTION:退出搜索模式时清空搜索框
 * INPUT:当前指针，C盘指针
 * RETURN:无
 * OTHERS:无
 ********************************/
void close_searchbar(void);

/********************************
 * FUNCTION:display_pagenum
 * DESCRIPTION:输出页数到界面
 * INPUT:页指针，模式
 * RETURN:无
 * OTHERS:无
 ********************************/
void display_pagenum(char *page, int mode);

/********************************
 * FUNCTION:
 * DESCRIPTION:显示项目数
 * INPUT:当前节点
 * RETURN:
 * OTHERS:
 ********************************/
void display_filenum(My_filenode *ch);

/********************************
 * FUNCTION:
 * DESCRIPTION:显示选中数
 * INPUT:当前节点
 * RETURN:
 * OTHERS:
 ********************************/
void display_choosenum(My_filenode *ch);

void downarrow_draw(int icocolor, State state);
void downarrow_draw_o(int icocolor);

#endif