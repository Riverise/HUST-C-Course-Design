#include "DRAWFILE.h"

/*
	函数功能：将flag代表的文件类型复制进dest字符串里
	参数：flag，字符串
	返回值：无
*/

void filetypecpy(char flag, char *dest)
{
	char type = flag & 15;
	switch (type)
	{
	case THIS_PC:
		break;
	case C_DISK:
		strcpy(dest, "DISK");
		break;
	case DIC:
		strcpy(dest, "DIR");
		break;
	case TXT:
		strcpy(dest, "TXT");
		break;
	case C:
		strcpy(dest, "C");
		break;
	case CPP:
		strcpy(dest, "CPP");
		break;
	case H:
		strcpy(dest, "H");
		break;
	case OBJ:
		strcpy(dest, "OBJ");
		break;
	case EXE:
		strcpy(dest, "EXE");
		break;
	case JPG:
		strcpy(dest, "JPG");
		break;
	case PNG:
		strcpy(dest, "PNG");
		break;
	case DOC:
		strcpy(dest, "DOC");
		break;
	case XLS:
		strcpy(dest, "XLS");
		break;
	case PPT:
		strcpy(dest, "PPT");
		break;
	case PDF:
		strcpy(dest, "PDF");
		break;
	case OTHER:
		strcpy(dest, "UNKNOW");
		break;
	default:
		break;
	}
}

/*
	函数功能：画右下框文件条背景（列表显示）
	参数：左上角坐标，颜色
	返回值：无
*/

void main_file_bar1(int x1, int y1, int color)
{
	setfillstyle(1, color);
	bar(x1, y1, x1 + 604, y1 + 22);
}

/*
	函数功能：画右下文件条（列表显示）
	参数：左上坐标，文件所在链表头节点，第几个文件，显示所处的页数-1
	返回值：无
*/

void draw_main_file1(int x1, int y1, struct My_filenode *headNode, int n, int state, int page)
{
	if (count_nodes(headNode) < n)
	{
		return;
	}
	struct My_filenode *tempp = count_to_node(headNode, (n + page * 20));
	if (tempp == NULL)
	{
		return;
	}
	char type = tempp->flag & 15;
	if (state)
	{
		main_file_bar1(x1, y1, RGBccffff);
	}
	else
	{
		main_file_bar1(x1, y1, RGBffffff);
	}
	if (tempp->flag & SELECT)
	{
		main_file_bar1(x1, y1, RGBccffff);
		setcolor(RGB553fff);
		setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
		rectangle(x1, y1, x1 + 604, y1 + 22);
	}
	fileicodraw(type, x1 + 5, y1 + 3, 0);
	setcolor(RGB000000);
	outtextxy(x1 + 35, y1 + 10, tempp->name);
	if (!(type == C_DISK))
	{
		int size;
		struct Filetime *t = get_file_base(tempp, &size);
		char timec[16];
		char tempc[8];
		itoa(t->y, tempc, 10);
		strcpy(timec, tempc);
		strcat(timec, "/");
		itoa(t->month, tempc, 10);
		strcat(timec, tempc);
		strcat(timec, "/");
		itoa(t->d, tempc, 10);
		strcat(timec, tempc);
		strcat(timec, " ");
		itoa(t->h, tempc, 10);
		strcat(timec, tempc);
		strcat(timec, ":");
		itoa(t->min, tempc, 10);
		strcat(timec, tempc);
		setcolor(RGB808080);
		outtextxy(x1 + 220, y1 + 10, timec);

		filetypecpy(type, tempc);
		outtextxy(x1 + 430, y1 + 10, tempc);

		if (!(tempp->flag & IS_DIR))
		{
			itoa(size, tempc, 10);
			strcat(tempc, "kb");
			outtextxy(x1 + 535, y1 + 10, tempc);
		}
		free(t);
	}
}

/*
	函数功能：画右下框文件条背景（缩略显示）
	参数：左上角坐标，颜色
	返回值：无
*/

void main_file_bar2(int x1, int y1, int color)
{
	setfillstyle(1, color);
	bar(x1, y1, x1 + 134, y1 + 170);
}

/*
	函数功能：画右下文件条（缩略显示）
	参数：左上坐标，文件所在链表头节点，第几个文件，显示所处的页数-1
	返回值：无
*/

void draw_main_file2(int x1, int y1, struct My_filenode *headNode, int n, int state, int page)
{
	if (count_nodes(headNode) < n || n > 15)
	{
		return;
	}
	struct My_filenode *tempp = count_to_node(headNode, (n + page * 15));
	if (tempp == NULL)
	{
		return;
	}
	char type = tempp->flag & 15;
	if (state)
	{
		main_file_bar2(x1, y1, RGBccffff);
	}
	else
	{
		main_file_bar2(x1, y1, RGBffffff);
	}
	if (tempp->flag & SELECT)
	{
		main_file_bar2(x1, y1, RGBccffff);
		setcolor(RGB553fff);
		setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
		rectangle(x1, y1, x1 + 134, y1 + 170);
	}
	fileicodraw(type, x1 + 21, y1 + 14, 3);
	setcolor(RGB000000);
	outtextxy(x1 + 29, y1 + 152, tempp->name);
}

/*
	函数功能：数文件夹节点数
	参数：头节点
	返回值：无
*/

int count_dirs(struct My_filenode *headNode)
{
	int n = 0;
	struct My_filenode *temp = headNode->next;
	for (; temp != NULL; temp = temp->next)
	{
		if (temp->flag & IS_DIR)
		{
			n++;
		}
	}
	return n;
}

/*
	函数功能：数到文件夹节点
	参数：头节点，数到第几个
	返回值：数到的节点，如果失败则返回NULL
*/

struct My_filenode *count_to_dir(struct My_filenode *headNode, int *n)
{
	if (headNode == NULL)
	{
		return NULL;
	}
	int t;
	struct My_filenode *temp = headNode->next;
	struct My_filenode *temps;
	for (; temp != NULL; temp = temp->next)
	{
		if (temp->flag & IS_DIR)
		{
			(*n)--;
		}
		if ((*n) == 0)
		{
			return temp;
		}
		if (temp->flag & IS_OPEN)
		{
			temps = count_to_dir(temp->son_list_head, n);
			if (temps != NULL)
			{
				return temps;
			}
		}
	}
	return NULL;
}

/*
	函数功能：画左下框文件夹条背景
	参数：左上角坐标，颜色
	返回值：无
*/

void tree_file_bar(int x1, int y1, int color)
{
	setfillstyle(1, color);
	bar(x1, y1, x1 + 205, y1 + 24);
}

/*
	函数功能：画左下文件条
	参数：左上坐标，文件所在链表头节点，第几个文件夹，所处状态，显示所处的页数-1
	返回值：无
*/

void draw_tree_file(int x1, int y1, struct My_filenode *headNode, int n, int state, int page)
{
	int n_n;
	n_n = (n + page * 20);
	struct My_filenode *tempp = count_to_dir(headNode, &n_n);
	if (tempp == NULL)
	{
		return;
	}
	struct My_filenode *temppp;
	int de = 0;
	for (temppp = tempp->father; temppp->father->father != NULL; temppp = temppp->father)
	{
		de += 6;
	}
	char type = tempp->flag & 15;

	if (state)
	{
		tree_file_bar(x1, y1, RGBccffff);
	}
	else
	{
		tree_file_bar(x1, y1, RGBffffff);
	}

	if (tempp->flag & SELECT)
	{
		setcolor(RGB553fff);
		setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	}
	x1 += de;
	if (!(tempp->flag & IS_OPEN))
	{
		find_all_dir(tempp);
		if (count_dirs(tempp->son_list_head) != 0)
		{
			setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
			setcolor(RGB000000);
			line(x1 + 10, y1 + 9, x1 + 15, y1 + 14);
			line(x1 + 15, y1 + 14, x1 + 20, y1 + 9);
			line(x1 + 10, y1 + 10, x1 + 15, y1 + 15);
			line(x1 + 15, y1 + 15, x1 + 20, y1 + 10);
		}
		free_list(tempp->son_list_head);
	}
	else
	{
		if (count_dirs(tempp->son_list_head) != 0)
		{
			setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
			setcolor(RGB000000);
			line(x1 + 10, y1 + 9, x1 + 15, y1 + 14);
			line(x1 + 15, y1 + 14, x1 + 20, y1 + 9);
			line(x1 + 10, y1 + 10, x1 + 15, y1 + 15);
			line(x1 + 15, y1 + 15, x1 + 20, y1 + 10);
		}
	}
	fileicodraw(type, x1 + 28, y1 + 5, 0);
	setcolor(RGB000000);
	outtextxy(x1 + 55, y1 + 11, tempp->name);
}

/*
	函数功能：画搜索文件条背景
	参数：左上角坐标，颜色
	返回值：无
*/

void search_file_bar(int x1, int y1, int color)
{
	setfillstyle(1, color);
	bar(x1, y1, x1 + 799, y1 + 48);
}

/*
	函数功能：画搜索文件条
	参数：左上坐标，文件所在链表头节点，第几个文件，所处状态，显示所处的页数-1
	返回值：无
*/
void draw_search_file(int x1, int y1, struct My_vector_ *headNode, int n, int state)
{
	if (count_nodes(headNode) < n)
	{
		return;
	}
	struct My_vector_ *tempv = count_to_node(headNode, n);
	if (tempv == NULL)
	{
		return;
	}
	struct ffblk ff;
	chdir(tempv->path);
	findfirst(tempv->name, &ff, FA_DIREC);
	struct My_filenode *tempp = (struct My_filenode *)malloc(sizeof(struct My_filenode));
	if (tempp == NULL)
	{
		pop_error(-1, "DRAW_SEARCH_FILE:", "malloc return NULL pointer.");
		return;
	}
	if (ff.ff_attrib & FA_DIREC)
	{
		tempp->flag = IS_DIR;
		tempp->flag += DIC;
	}
	else
	{
		tempp->flag = 0;
		add_type(&tempp->flag, ff.ff_name);
	}
	strcpy(tempp->name, ff.ff_name);
	tempp->next = NULL;
	tempp->son_list_head = NULL;
	tempp->father = NULL;
	char type = tempp->flag & 15;
	if (state)
	{
		search_file_bar(x1, y1, RGBccffff);
	}
	else
	{
		search_file_bar(x1, y1, RGBffffff);
	}
	if (tempp->flag & SELECT)
	{
		search_file_bar(x1, y1, RGBccffff);
		setcolor(RGB553fff);
		setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
		rectangle(x1, y1, x1 + 799, y1 + 48);
	}
	fileicodraw(type, x1 + 11, y1 + 9, 1);
	setcolor(RGB000000);
	outtextxy(x1 + 65, y1 + 14, tempp->name);
	int size;
	size = (int)ff.ff_fsize / 1024;
	if (ff.ff_fsize % 1024)
	{
		size++;
	}
	if (size < 0)
	{
		size = 0;
	}
	char timec[16];
	char tempc[8];
	itoa(((0xfe00 & ff.ff_fdate) >> 9) + 1980, tempc, 10);
	strcpy(timec, tempc);
	strcat(timec, "/");
	itoa((0x1e0 & ff.ff_fdate) >> 5, tempc, 10);
	strcat(timec, tempc);
	strcat(timec, "/");
	itoa(0x1f & ff.ff_fdate, tempc, 10);
	strcat(timec, tempc);
	strcat(timec, " ");
	itoa((0xf800 & ff.ff_ftime) >> 11, tempc, 10);
	strcat(timec, tempc);
	strcat(timec, ":");
	itoa((0x7E0 & ff.ff_ftime) >> 5, tempc, 10);
	strcat(timec, tempc);
	setcolor(RGB808080);
	outtextxy(x1 + 540, y1 + 14, timec);
	filetypecpy(type, tempc);
	outtextxy(x1 + 400, y1 + 33, tempc);

	outtextxy(x1 + 65, y1 + 33, tempv->path);
	if (!(tempp->flag & IS_DIR))
	{
		itoa(size, tempc, 10);
		strcat(tempc, "kb");
		outtextxy(x1 + 540, y1 + 33, tempc);
	}
	free(tempp);
}

/*
	函数功能：画右下文件条（列表）
	参数：第几个文件夹，文件所在链表头节点，显示状态（显示鼠标在文件条上的情况），显示所处的页数-1
	返回值：无
*/

void My_draw_main_file1(int n, struct My_filenode *headNode, int state, int page)
{
	draw_main_file1(215, 178 + (n * 23), headNode, n, state, page);
}

/*
	函数功能：画右下文件条（缩略）
	参数：第几个文件夹，文件所在链表头节点，显示状态（显示鼠标在文件条上的情况），显示所处的页数-1
	返回值：无
*/

void My_draw_main_file2(int n, struct My_filenode *headNode, int state, int page)
{
	// int row=(n-1)/5;
	draw_main_file2(230 - 158 + 158 * (n - 5 * ((n - 1) / 5)), 181 + 185 * ((n - 1) / 5), headNode, n, state, page);
}

/*
	函数功能：画左下文件条
	参数：第几个文件夹，文件所在链表头节点，显示状态（显示鼠标在文件条上的情况），显示所处的页数-1
	返回值：无
*/

void My_draw_tree_file(int n, struct My_filenode *headNode, int state, int page)
{
	draw_tree_file(2, 178 + (n * 24), headNode, n, state, page);
}

/*
	函数功能：画搜索文件条
	参数：第几个文件，搜索头节点，显示状态（显示鼠标在文件条上的情况），显示所处的页数-1
	返回值：无
*/

void My_draw_search_file(int n, struct My_vector_ *headNode, int state)
{
	draw_search_file(215, 138 + (n * 52), headNode, n, state);
}

/*
	函数功能：报错弹窗
	参数：报错类型（-1为error,否则为warning），报错函数名，报错原因，错误对象（默认为NULL）
	返回值：error返回0，warning返回0（点击取消）或1（点击确认）
*/

int pop_error(int pop_type, char *func_name, char *cause, char *object_name)
{
	int r = 0;
	clrmous(MouseX, MouseY);
	record_imagedata(338, 244, 686, 474, "c:\\win_pro\\etc\\data\\IMDATA_1");
	setfillstyle(1, RGB2a7fff);
	bar(340, 246, 684, 472);
	setfillstyle(1, RGBffffff);
	bar(343, 270, 681, 407);
	setfillstyle(1, RGBfffbf0);
	bar(343, 407, 681, 469);
	setcolor(RGB553fff);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	rectangle(340, 246, 684, 472);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	rectangle(343, 270, 681, 469);
	if (pop_type == -1)
	{
		errorico_write(360, 290);
		setcolor(RGB000000);
		outtextxy(347, 256, "ERROR");
		outtextxy(484, 434, "Comfirm");
		setcolor(RGB553fff);
		setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
		rectangle(482, 427, 540, 447);
		setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	}
	else
	{
		warningico_write(360, 290);
		setcolor(RGB000000);
		outtextxy(345, 260, "WARNING");
		outtextxy(414, 434, "Comfirm");
		outtextxy(558, 434, "Cancel");
		setcolor(RGB553fff);
		setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
		rectangle(412, 427, 470, 447);
		rectangle(552, 427, 610, 447);
		setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	}
	setcolor(RGB000000);
	outtextxy(412, 307, func_name);
	outtextxy(430, 340, cause);
	if (object_name != NULL)
	{
		outtextxy(430, 373, object_name);
	}
	if (pop_type == -1)
	{
		while (1)
		{
			newmouse(&MouseX, &MouseY, &press);
			if (testmouse_bar(482, 427, 540, 447, MOUSETEST_INBAR) == 1)
			{
				longpress_fit();
				break;
			}
		}
	}
	else
	{
		while (1)
		{
			newmouse(&MouseX, &MouseY, &press);
			if (testmouse_bar(412, 427, 470, 447, MOUSETEST_INBAR) == 1)
			{
				r = 1;
				longpress_fit();
				break;
			}
			else if (testmouse_bar(552, 427, 610, 447, MOUSETEST_INBAR) == 1)
			{
				longpress_fit();
				break;
			}
		}
	}
	clrmous(MouseX, MouseY);
	write_imagedata(338, 244, 686, 474, "c:\\win_pro\\etc\\data\\IMDATA_1");
	return r;
}

/*
	函数功能：属性弹窗
	参数：文件节点指针
	返回值：无
*/

void pop_properties(struct My_filenode *theNode)
{
	int n;
	clrmous(MouseX, MouseY);
	record_imagedata(328, 138, 696, 574, "c:\\win_pro\\etc\\data\\IMDATA_2");
	setfillstyle(1, RGBffffff);
	bar(330, 140, 694, 164);
	setfillstyle(1, RGBfffbf0);
	bar(330, 164, 694, 572);
	bar(647, 542, 684, 562);
	setfillstyle(1, RGBffffff);
	bar(334, 170, 690, 568);
	setcolor(RGBa0a0a4);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	rectangle(330, 140, 694, 572);
	rectangle(334, 170, 690, 568);
	rectangle(647, 542, 684, 562);
	rectangle(646, 541, 685, 563);
	put12hz(651, 546, "确认", 14, RGB000000);
	line(334, 285, 690, 285);
	setcolor(RGBff0055);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	line(676, 141, 690, 155);
	line(676, 155, 690, 141);
	setfillstyle(1, RGBff0055);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	rectangle(672, 140, 694, 156);
	rectangle(673, 141, 693, 155);
	char type = theNode->flag & 15;
	fileicodraw(type, 334, 143, 0);
	setcolor(RGB000000);
	outtextxy(357, 149, theNode->name);
	put12hz(360 + (8 * strlen(theNode->name)), 147, "的属性", 14, RGB000000);
	fileicodraw(type, 355, 196, 2);
	put12hz(458, 240, "名称", 14, RGB000000);
	setcolor(RGB000000);
	outtextxy(487, 243, ":");
	outtextxy(507, 243, theNode->name);
	int size;
	struct Filetime *t = get_file_base(theNode, &size);
	char timec[16];
	char tempc[8];
	char buffer[80];
	itoa(t->y, tempc, 10);
	strcpy(timec, tempc);
	strcat(timec, "/");
	itoa(t->month, tempc, 10);
	strcat(timec, tempc);
	strcat(timec, "/");
	itoa(t->d, tempc, 10);
	strcat(timec, tempc);
	strcat(timec, " ");
	itoa(t->h, tempc, 10);
	strcat(timec, tempc);
	strcat(timec, ":");
	itoa(t->min, tempc, 10);
	strcat(timec, tempc);
	filetypecpy(type, tempc);
	get_path(theNode, buffer);
	n = strlen(buffer);
	buffer[n - 1] = '\0';
	put12hz(344, 340, "文件类型", 14, RGB000000);
	outtextxy(401, 343, ":");
	outtextxy(412, 343, tempc);
	put12hz(344, 390, "文件位置", 14, RGB000000);
	outtextxy(401, 393, ":");
	if (My_strcmp(theNode->name, "c:"))
	{
		if (strlen(buffer) < 30)
		{
			outtextxy(412, 393, buffer);
		}
		else
		{
			char snd_row[20];
			strcpy(snd_row, &buffer[30]);
			buffer[30] = '\0';
			outtextxy(412, 393, buffer);
			outtextxy(412, 410, snd_row);
		}
	}
	put12hz(344, 440, "修改时间", 14, RGB000000);
	outtextxy(401, 443, ":");
	outtextxy(412, 443, timec);
	if (theNode->flag & IS_DIR)
	{
		size = count_all_file(theNode);
		put12hz(344, 490, "包含", 14, RGB000000);
		outtextxy(373, 493, ":");
		itoa(size, tempc, 10);
		outtextxy(390, 493, tempc);
		put12hz(421, 490, "个项目", 14, RGB000000);
	}
	else
	{
		put12hz(344, 490, "大小", 14, RGB000000);
		outtextxy(373, 493, ":");
		tempc[0] = '\0';
		itoa(size, tempc, 10);
		outtextxy(390, 493, tempc);
		outtextxy(415, 493, "kb");
	}

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (testmouse_bar(647, 542, 684, 562, MOUSETEST_INBAR) == 1 || testmouse_bar(673, 141, 693, 155, MOUSETEST_INBAR) == 1)
		{
			longpress_fit();
			break;
		}
	}
	clrmous(MouseX, MouseY);
	write_imagedata(328, 138, 696, 574, "c:\\win_pro\\etc\\data\\IMDATA_2");
}