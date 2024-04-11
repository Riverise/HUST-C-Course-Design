
#ifndef _FLAG_H_
#define _FLAG_H_

enum file
{
	THIS_PC = 0, //此电脑
	C_DISK,		 // C盘
	DIC,		 //目录
	/*以下为文件类型*/
	TXT,
	C,
	CPP,
	H,
	OBJ,
	EXE,
	JPG,
	PNG,
	DOC,
	XLS,
	PPT,
	PDF,
	OTHER,
	IS_OPEN = 16,
	H_NODE = 32, //头节点，0010 0000
	IS_DIR = 64, //判断文件状态，0100 0000
	SELECT = 128 //判断选中，1000 0000
};

#endif