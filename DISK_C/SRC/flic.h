
#ifndef _FLIC_H_

#define _FLIC_H_

#include "main.h"

/********************************
 * FUNCTION:fileicodraw
 * DESCRIPTION:根据文件类型绘制文件图标
 * INPUT:文件类型按位量，文件图标显示大小
 * RETURN:无
 * OTHERS:无
 ********************************/
void fileicodraw(Flag flag, int x, int y, Size size);

/********************************
 * FUNCTION:getnum_dir_andopen
 * DESCRIPTION:查找根目录（包括打开的子级）文件夹数目
 * INPUT:头节点
 * RETURN:文件夹数
 * OTHERS:应用于树形文件区的有效区域判断
 ********************************/
int getnum_dir_andopen(struct My_filenode *headNode);

#endif