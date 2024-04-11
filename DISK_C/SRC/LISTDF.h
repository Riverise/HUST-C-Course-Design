#ifndef _LISTDF_H
#define _LISTDF_H

#include "flag.h"

struct My_filenode
{
	unsigned char flag;
	char name[13];
	struct My_filenode *next;
	struct My_filenode *father;		   //同一条链用同一个父节点（为了做返回上一级功能）
	struct My_filenode *son_list_head; //一个父节点拥有子链的头节点地址
};

/*与flag有关的枚举*/
/*
enum file_flag
{
	THIS_PC = 0, //此电脑
	C_DISK,		 // C盘
	DIC,		 //目录
	//以下为文件类型
	TXT, C, CPP, H, OBJ, EXE, JPG, PNG, DOC, XLS, PPT, PDF, OTHER,
	IS_OPEN = 16,
	H_NODE = 32,		 //判断头节点
	IS_DIR = 64,           //判断文件
	SELECT = 128           //判断选中
};*/

struct Filetime
{
	int s, min, h, d, month, y;
};


struct My_vector_
{
	char path[50];
	char name[13];
	struct My_vector_* next;
};


#endif /* _LISTDF_H */