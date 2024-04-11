
#include "flic.h"

/********************************
 * FUNCTION:fileicodraw
 * DESCRIPTION:根据文件类型绘制文件图标
 * INPUT:文件类型按位量，文件图标显示大小
 * RETURN:无
 * OTHERS:无
 ********************************/
void fileicodraw(Flag flag, int x, int y, Size size)
{
	switch (get_file(flag))
	{
	case THIS_PC:
		break;
	case C_DISK:
		diskicodraw_o(x, y, size);
		break;
	case DIC:
		diricodraw_o(x, y, size);
		break;
	case TXT:
		txticodraw_o(x, y, size);
		break;
	case C:
		cicodraw_o(x, y, size);
		break;
	case CPP:
		cppicodraw_o(x, y, size);
		break;
	case H:
		hicodraw_o(x, y, size);
		break;
	case OBJ:
		objicodraw_o(x, y, size);
		break;
	case EXE:
		exeicodraw_o(x, y, size);
		break;
	case JPG:
	case PNG:
		photoicodraw_o(x, y, size);
		break;
	case DOC:
		docicodraw_o(x, y, size);
		break;
	case XLS:
		xlsicodraw_o(x, y, size);
		break;
	case PPT:
		ppticodraw_o(x, y, size);
		break;
	case PDF:
		pdficodraw_o(x, y, size);
		break;
	case OTHER:
		filebasicdraw_o(x, y, size);
		break;
	default:
		break;
	}
}

/********************************
 * FUNCTION:getnum_dir_andopen
 * DESCRIPTION:查找根目录（包括打开的子级）文件夹数目
 * INPUT:头节点
 * RETURN:文件夹数
 * OTHERS:应用于树形文件区的有效区域判断
 ********************************/
int getnum_dir_andopen(struct My_filenode *headNode)
{
	struct My_filenode *ttnode, *ttnodet;
	int num;
	for (ttnode = headNode->next; ttnode != NULL; ttnode = ttnode->next)
	{
		if (getonebit(ttnode->flag, 2) == 1) //是文件夹
		{
			num++;
			if (getonebit(ttnode->flag, 4)) //是打开的文件夹
			{
				for (ttnodet = ttnode->son_list_head; ttnodet != NULL; ttnodet = ttnodet->next)
				{
					num++;
				}
			}
		}
	}
	return num;
}