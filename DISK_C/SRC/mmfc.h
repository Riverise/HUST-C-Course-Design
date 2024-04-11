#ifndef _MMFC_H_
#define _MMFC_H_
#include "main.h"

void refresh_all(My_filenode **p_headnode_current, My_filenode *pc_for_dir, My_filenode *ph, My_vector_ *currenthead,
				 char *refresh_mode, char *tree_ch_num, char *page, State *state_bt);

void pcinit(My_filenode **ch, My_filenode **p0, My_filenode **ph, My_filenode **pc, My_filenode **p0_for_dir, My_filenode **ph_for_dir, My_filenode **pc_for_dir,
			My_filenode **p0_for_paste, My_filenode **ph_for_paste, My_filenode **pc_for_paste, My_vector_ **paste, My_vector_ **history,
			My_vector_ **currenthead, My_vector_ **search, char *sort_way, State *state_bt);

int func_refresh(State *state_bt, My_filenode **pch, My_vector_ *history, My_vector_ *search,
				 My_filenode *ph, My_filenode *pc_for_dir, My_vector_ *paste,
				 My_vector_ **pcurrenthead, char *page, char *textipt, int *pjudge_search,
				 char *refresh_mode);

// void chgto_treedir(My_filenode **pch, My_vector_ *history, My_vector_ **pcurrenthead, My_filenode *ph, Bit *tree_ch_num, int *pressstate_tr, char *page);
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
 * 			当前目录指针
 * RETURN:双击返回1，未双击返回0
 * OTHERS:全程，除长按适配外，无鼠标状态刷新
 ********************************/
int func_mianfile(int **pressstate_fm, int *state_fm, Bit *mainfile_chos_dsplstate,
				  My_filenode *headnode_main, char *page, int press_last, State *state_bt,
				  struct My_vector_ *search, struct My_vector_ *paste, struct My_vector_ *history,
				  struct My_filenode *ph, struct My_filenode *pc_dir_sonhead,
				  struct My_vector_ *currenthead, int judge_search);
/********************************
 * FUNCTION:
 * DESCRIPTION:目录跳转和树形文件设置
 * INPUT:*ch,history,*currenthead,search,ph,pc_for_dir,树形文件选中编号（新旧），按下状态，page,搜索变量地址，刷新模式地址
 * RETURN:
 * OTHERS:
 ********************************/
void chgto_treedir(My_filenode **pch, My_vector_ *history, My_vector_ **pcurrenthead, My_vector_ *search, My_filenode *ph, My_filenode *pc_for_dir,
				   char *tree_ch_num, int *pressstate_tr, char *page, int *pjudge_search, char *refresh_mode);

#endif