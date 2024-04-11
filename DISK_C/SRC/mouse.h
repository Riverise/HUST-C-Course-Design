#ifndef _mouse_h_
#define _mouse_h_

//*********************************
#define XMAX 1023
#define YMAX 767
#define XMIN 1
#define YMIN 2
//*********************************

#include "main.h"

int mouse_press(int x1, int y1, int x2, int y2); //如果在框中点击，则返回1；在框中未点击，则返回2；右键则3；不在框中则返回0
void mouse(int, int);							 //设计鼠标
void mouseinit(void);							 //初始化
void mread(int *, int *, int *);				//改坐标不画
void save_bk_mou(int x, int y);					//存鼠标背景
void clrmous(int x, int y);						//清除鼠标
void drawmous(int x, int y);					//画鼠标
void newmouse(int *nx, int *ny, int *nbuttons); //更新鼠标

/*************************************
 * 以下为自设函数
 * *************************************/

/**************************
 * 判断函数，若鼠标在边界则改变保存图像区域
 * 传递参数：x, y(鼠标所在坐标)
 * 无返回值
 * *********************/
void judgemousbk(int *x, int *y);

void freebuffer(void);

/********************************
 * FUNCTION:refresh_mouse_display
 * DESCRIPTION:无条件刷新鼠标显示
 * INPUT:鼠标位置和按压状态
 * RETURN:无
 * OTHERS:调用前加上clrmous函数
 ********************************/
void refresh_mouse_display(int *mousex, int *mousey, int *m_press);

/*******************************
 * 以上
 * *****************************/

extern int MouseX;
extern int MouseY;
extern int MouseS;
extern int press;
extern union REGS regs;

#endif
