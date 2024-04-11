#ifndef _FUNC_H_

#define _FUNC_H_

#include "main.h"
/********************************
 * FUNCTION:
 * DESCRIPTION:详细信息
 * INPUT:按键状态，页数，ph,ch
 * RETURN:
 * OTHERS:
 ********************************/
void func_setdisplay_list(State *state, char *page, My_filenode *ph, My_filenode *headnode_current);

/********************************
 * FUNCTION:
 * DESCRIPTION:缩略图
 * INPUT:按键状态，页数，ph,ch
 * RETURN:
 * OTHERS:
 ********************************/
void func_setdisplay_icon(State *state, char *page, My_filenode *ph, My_filenode *headnode_current);

/********************************
 * FUNCTION:
 * DESCRIPTION:上级目录
 * INPUT:*ch,ph,*currenthead,history,page
 * RETURN:
 * OTHERS:
 ********************************/
void func_changedir_father(My_filenode **p_headnode_current, My_filenode *ph, My_vector_ **p_currenthead, My_vector_ *history, char *page);

/********************************
 * FUNCTION:
 * DESCRIPTION:刷新
 * INPUT:ch,ph
 * RETURN:
 * OTHERS:
 ********************************/
void func_refresh(My_filenode *headnode_current, My_filenode *ph);

/********************************
 * FUNCTION:
 * DESCRIPTION:上历史记录
 * INPUT:*ch,ph,*currenthead,,history,page
 * RETURN:
 * OTHERS:
 ********************************/
void func_changedir_last(My_filenode **p_headnode_current, My_filenode *ph, My_vector_ **p_currenthead,
						 My_vector_ *history, char *page);

/********************************
 * FUNCTION:
 * DESCRIPTION:下历史记录
 * INPUT:同上
 * RETURN:
 * OTHERS:
 ********************************/
void func_changedir_next(My_filenode **p_headnode_current, My_filenode *ph, My_vector_ **p_currenthead,
						 My_vector_ *history, char *page);

/********************************
 * FUNCTION:
 * DESCRIPTION:复制
 * INPUT:ch,paste
 * RETURN:
 * OTHERS:
 ********************************/
void func_copy(My_filenode *headnode_current, My_vector_ *paste);

/********************************
 * FUNCTION:
 * DESCRIPTION:粘贴
 * INPUT:ch,ph_for_paste,paste,粘贴模式判断量
 * RETURN:
 * OTHERS:
 ********************************/
void func_paste(My_filenode *headnode_current, My_filenode *ph_for_paste, My_vector_ *paste, int judge_paste);

/********************************
 * FUNCTION:
 * DESCRIPTION:剪切
 * INPUT:pc,paste
 * RETURN:
 * OTHERS:
 ********************************/
void func_cut(My_filenode *headnode_current, My_vector_ *paste);

/********************************
 * FUNCTION:
 * DESCRIPTION:删除
 * INPUT:pc
 * RETURN:
 * OTHERS:
 ********************************/
void func_delete(My_filenode *headnode_current);

/********************************
 * FUNCTION:
 * DESCRIPTION:重命名
 * INPUT:ch,textipt,本模式左上角文件左上角坐标，文件块尺寸（高宽），相对文件块左上角文本偏移量（x，y），显示方式，page，调用相应画图函数
 * RETURN:
 * OTHERS:
 ********************************/
void func_rename(My_filenode *headnode_current, char *textipt, int x0, int y0,
				 int height, int width, int space_x_n, int space_y_n, int displaytype_main,
				 char *page, void (*draw_mainfile)(int x1, int y1, struct My_filenode *headnode, int n, int state, int page));

/********************************
 * FUNCTION:
 * DESCRIPTION:新文件夹
 * INPUT:ch,textipt,本模式最大文件数，,本模式左上角文件左上角坐标，文件块尺寸（高宽），相对文件块左上角文本偏移量（x，y），相对文件块左上角图标偏移量（x,y），显示模式
 * RETURN:
 * OTHERS:
 ********************************/
void func_newdir(My_filenode *headnode_current, char *textipt, int maxfilenum, int x0, int y0,
				 int height, int width, int space_x_n, int space_y_n, int space_x_ico, int space_y_ico, int displaytype_main);

/********************************
 * FUNCTION:
 * DESCRIPTION:新文件
 * INPUT:ch,textipt,本模式最大文件数，,本模式左上角文件左上角坐标，文件块尺寸（高宽），相对文件块左上角文本偏移量（x，y），相对文件块左上角图标偏移量（x,y），显示模式
 * RETURN:
 * OTHERS:
 ********************************/
void func_newfile(My_filenode *headnode_current, char *textipt, int maxfilenum, int x0, int y0, int height,
				  int width, int space_x_n, int space_y_n, int space_x_ico, int space_y_ico, int displaytype_main);
/********************************
 * FUNCTION:
 * DESCRIPTION:打开属性弹窗
 * INPUT:ch
 * RETURN:
 * OTHERS:
 ********************************/
void func_attridisplay(My_filenode *headnode_current);

/********************************
 * FUNCTION:
 * DESCRIPTION:全选
 * INPUT:按键状态，ch,ph,pc_for_dir,currentheead,history,search,paste,最大文件数,，文件块尺寸（高宽）,本模式左上角文件左上角坐标,显示模式，文件块显示状态，page,搜索判断，绘图函数
 * RETURN:
 * OTHERS:
 ********************************/
void func_chall(State *state, My_filenode *headnode_current, My_filenode *ph, My_filenode *pc_for_dir,
				My_vector_ *currenthead, My_vector_ *history, My_vector_ *search, My_vector_ *paste, int maxfilenum, int height,
				int width, int x0, int y0, int displaytype_main, Bit *dsplstate_main, char *page, int judge_search,
				void (*draw_mainfile)(int x1, int y1, struct My_filenode *headnode, int n, int state, int page));

/********************************
 * FUNCTION:
 * DESCRIPTION:全部取消
 * INPUT:同上
 * RETURN:
 * OTHERS:
 ********************************/
void func_clrall(State *state, My_filenode *headnode_current, My_filenode *ph, My_filenode *pc_for_dir,
				 My_vector_ *currenthead, My_vector_ *history, My_vector_ *search, My_vector_ *paste, int maxfilenum, int height,
				 int width, int x0, int y0, int displaytype_main, Bit *dsplstate_main, char *page, int judge_search,
				 void (*draw_mainfile)(int x1, int y1, struct My_filenode *headnode, int n, int state, int page));

/********************************
 * FUNCTION:
 * DESCRIPTION:反选
 * INPUT:同上
 * RETURN:
 * OTHERS:
 ********************************/
void func_chctry(State *state, My_filenode *headnode_current, My_filenode *ph, My_filenode *pc_for_dir,
				 My_vector_ *currenthead, My_vector_ *history, My_vector_ *search, My_vector_ *paste, int maxfilenum, int height,
				 int width, int x0, int y0, int displaytype_main, Bit *dsplstate_main, char *page, int judge_search,
				 void (*draw_mainfile)(int x1, int y1, struct My_filenode *headnode, int n, int state, int page));

int getnum_choose(My_filenode *headnode_current);

#endif
