/********************************
 * 欢迎和登录界面
 * *******************************/
#ifndef _WLCM_H_

#define _WLCM_H_

#include "main.h"

void welcome_page0(void);

void welcome_page1(void);

void log_page(void);

void keybox_draw(void);

void dot_write(int x, int y);

/* 登录功能 */
int function_log(char *textipt);

void wrong_key(void);

#endif
