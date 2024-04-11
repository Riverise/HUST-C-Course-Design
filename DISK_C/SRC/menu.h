
#ifndef _MENU_H_

#define _MENU_H_

#include "main.h"

/********************************
 * FUNCTION:getdirect_menu
 * DESCRIPTION:获取右键菜单显示方向
 * INPUT:鼠标坐标，菜单尺寸
 * RETURN:显示方向（宏定义）
 * OTHERS:无
 ********************************/
int getdirect_menu(int mousex, int mousey, int height_menu, int width_menu);

/********************************
 * FUNCTION:getdirect_sonmenu
 * DESCRIPTION:获取右键子菜单显示方向
 * INPUT:宽度，主菜单右界x坐标
 * RETURN:示方向（宏定义）
 * OTHERS:无
 ********************************/
int getdirect_sonmenu(int width, int x2);

/********************************
 * FUNCTION:getxy_menu
 * DESCRIPTION:获取菜单的坐标，
 * INPUT:坐标地址，方向，高度，宽度
 * RETURN:无
 * OTHERS:在数组内，地址传递
 ********************************/
void getxy_menu(int *xy, int direct, int height, int width);

/********************************
 * FUNCTION:getxy_sonmenu
 * DESCRIPTION:获取子菜单的坐标，
 * INPUT:坐标地址，方向，主菜单左右界x坐标，触发菜单功能数
 * RETURN:无
 * OTHERS:在数组内，地址传递
 ********************************/
void getxy_sonmenu(int *xy, int direct, int x1, int x2, int y, int btnnum);

/********************************
 * FUNCTION:draw_menu
 * DESCRIPTION:画菜单
 * INPUT:方向，模式
 * RETURN:无
 * OTHERS:无
 ********************************/
void draw_menu(int direct, int mode, State state_menu);

/********************************
 * FUNCTION:draw_sonmenu
 * DESCRIPTION:画子菜单
 * INPUT:子菜单类型，两侧x坐标，绘制y坐标
 * RETURN:无
 * OTHERS:无
 ********************************/
void draw_sonmenu(int menuno, int x1, int x2, int y);

/********************************
 * FUNCTION:
 * DESCRIPTION:菜单功能函数
 * INPUT:菜单模式，菜单状态量，按键状态，当前节点地址，ph,ph_for_paste,粘贴板，textipt，page，粘贴模式地址，排序方式地址
 * RETURN:
 * OTHERS:
 ********************************/
int func_menu(int mode, State state_menu, State *state_btn, My_filenode **p_headnode_current,
			  My_filenode *ph, My_filenode *ph_for_paste, My_vector_ *paste, char *textipt, unsigned char *page,
			  int *p_judge_paste, int *p_judge_sort);

/********************************
 * FUNCTION:
 * DESCRIPTION:菜单功能执行
 * INPUT:菜单键编号，模式，主菜单左上角坐标，菜单状态，功能按键状态，当前节点地址，ph,,ph_for_paste,粘贴板，textipt，page，粘贴模式地址，排序方式地址
 * RETURN:
 * OTHERS:
 ********************************/
int do_menu(int num, int mode, int x1, int y, State state_menu, State *state_btn, My_filenode **p_headnode_current,
			My_filenode *ph, My_filenode *ph_for_paste, My_vector_ *paste, char *textipt, unsigned char *page,
			int *p_judge_paste, int *p_judge_sort);

/********************************
 * FUNCTION:
 * DESCRIPTION:子菜单功能执行
 * INPUT:主菜单点击编号，子菜单点击编号，textipt，功能按键状态，页数，当前节点地址，ph，排序方式地址
 * RETURN:
 * OTHERS:
 ********************************/
int do_sonmenu(int num, int funcnum, char *textipt, State *state_btn, unsigned char *page,
			   My_filenode **p_headnode_current, My_filenode *ph, int *judge_sort);

int func_sonmenu(int num, int x0, int y0, char *textipt, State *state_btn, unsigned char *page,
				 My_filenode **p_headnode_current, My_filenode *ph, int *p_judge_sort);

/* 根据菜单号获取子功能数 */
int getnum_sonmenunum(int no);

/********************************
 * FUNCTION:setstate_menu
 * DESCRIPTION:设置菜单状态
 * INPUT:菜单状态数组，菜单模式，粘贴板，当前指针
 * RETURN:
 * OTHERS:
 ********************************/
void setstate_menu(State *p_state_menu, int mode, My_vector_ *paste, My_filenode *headnode_current);

void draw_history(struct My_vector_ *history, int *xy);

int *getxy_history(int *xy, struct My_vector_ *history);

int func_history(struct My_vector_ *history, struct My_vector_ **pcurrenthead, struct My_filenode **pch, struct My_filenode *ph, int *xy);

#endif