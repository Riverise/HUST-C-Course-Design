/**********************
 * 图标绘制
 * ***********************/

#include "icodr.h"

/*************************
 * 文件底板（白色矩形）绘制函数
 * 传递左上角坐标参数,大小倍率
 * 最小为 16*21大小，支持：
 * > 0，SMALL, 小图标，用于列表显示
 * > 1，MIDDLE,用于中等图标
 * > 2，BIG,用于大图标
 * > 3，SUPER,用于超大图标
 * 无返回值
 * ************************/
void filebasicdraw_o(int x, int y, Size size)
{
	setcolor(RGBa0a0a4);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	switch (size)
	{
	case SMALL:
		x += 5;
		y += 3;
		moveto(x + 6, y);
		lineto(x + 10, y + 4);
		lineto(x + 10, y + 14);
		lineto(x, y + 14);
		lineto(x, y);
		lineto(x + 6, y);
		lineto(x + 6, y + 4);
		lineto(x + 10, y + 4);

		setfillstyle(SOLID_FILL, RGBffffff);
		floodfill(x + 4, y + 10, RGBa0a0a4);
		floodfill(x + 7, y + 3, RGBa0a0a4);
		break;
	case MIDDLE:
		filebasicdraw_o_o(x, y, SIZE_MIDDLE);
		break;
	case BIG:
		filebasicdraw_o_o(x, y, SIZE_BIG);
		break;
	case SUPER:
		filebasicdraw_o_o(x, y, SIZE_SUPER);
		break;
	default:
		break;
	}
}
void filebasicdraw_o_o(int x, int y, int size_size)
{
	setcolor(RGBa0a0a4);
	if (size_size == SIZE_SUPER)
	{
		setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	}
	else
	{
		setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	}
	int xy[14];
	xy[0] = x;
	xy[1] = y;
	xy[2] = x + 17 * size_size - 1;
	xy[3] = y;
	xy[4] = xy[2];
	xy[5] = y + 7 * size_size;
	xy[6] = x + 24 * size_size - 1;
	xy[7] = xy[5];
	xy[8] = xy[6];
	xy[9] = y + 32 * size_size - 1;
	xy[10] = x;
	xy[11] = xy[9];
	xy[12] = x;
	xy[13] = y;
	drawpoly(7, xy);
	line(xy[2], xy[3], xy[6], xy[7]);
	setfillstyle(SOLID_FILL, RGBffffff);
	floodfill(xy[0] + 4, xy[1] + 10, RGBa0a0a4);
	floodfill(xy[4] + 3, xy[5] - 3, RGBa0a0a4);
}

/*************************
 * txt 绘制函数
 * 传递左上角坐标和大小
 * 无返回值
 * **********************/
void txticodraw_o(int x, int y, Size size)
{
	char i; //循环辅助变量
	int y_;
	switch (size)
	{
	case SMALL:
		x += 5;
		y += 3;
		filebasicdraw_o(x - 5, y - 3, size);
		setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
		y_ = y + 2;
		for (i = 0; i < 2; i++)
		{
			line(x + 2, y_, x + 5, y_);
			y_ += 2;
		}
		for (i = 0; i < 4; i++)
		{
			line(x + 2, y_, x + 8, y_);
			y_ += 2;
		}
		break;
	case MIDDLE:
		txticodraw_o_o(x, y, SIZE_MIDDLE);
		break;
	case BIG:
		txticodraw_o_o(x, y, SIZE_BIG);
		break;
	case SUPER:
		txticodraw_o_o(x, y, SIZE_SUPER);
		break;
	default:
		break;
	}
}
void txticodraw_o_o(int x, int y, int size_size)
{
	char i; //循环辅助变量
	int y_;
	filebasicdraw_o_o(x, y, size_size);
	if (size_size == SIZE_SUPER)
	{
		setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	}
	else
	{
		setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	}
	y_ = y + 3 * size_size;
	for (i = 0; i < 2; i++)
	{
		line(x + 2 * size_size, y_, x + 14 * size_size, y_);
		y_ += 3 * size_size;
	}
	for (i = 0; i < 7; i++)
	{
		line(x + 2 * size_size, y_, x + 21 * size_size, y_);
		y_ += 3 * size_size;
	}
}

/*************************
 * photo(jpg,png)绘制函数
 * 传递左上角坐标和大小
 * 无返回值
 * **********************/
void photoicodraw_o(int x, int y, Size size)
{
	switch (size)
	{
	case SMALL:
		filebasicdraw_o(x, y, size);
		x += 5;
		y += 3;	
		photoicowrite(x + 2, y + 6, size);
		break;
	case MIDDLE:
		filebasicdraw_o(x, y, size);
		photoicowrite(x + 4, y + 10, size);
		break;
	case BIG:
		filebasicdraw_o(x, y, size);
		photoicowrite(x + 9, y + 19, size);
		break;
	case SUPER:
		filebasicdraw_o(x, y, size);
		photoicowrite(x + 14, y + 36, size);
		break;
	default:
		break;
	}
}
void photoicowrite(int x, int y, Size size)
{
	int x_, y_;
	x_ = x;
	y_ = y;
	switch (size)
	{
	case SMALL:
	{
		putpixel(x_++, y_, RGB2abfff);
		putpixel(x_++, y_, RGB2a9fff);
		putpixel(x_++, y_, RGB2abfff);
		putpixel(x_++, y_, RGB2abfaa);
		putpixel(x_++, y_, RGB2a9faa);
		putpixel(x_++, y_, RGB2abfaa);
		putpixel(x_++, y_, RGB2a9fff);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGB2abfff);
		putpixel(x_++, y_, RGB2a9fff);
		putpixel(x_++, y_, RGB2abfff);
		putpixel(x_++, y_, RGB2a9fff);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGB559fff);
		putpixel(x_++, y_, RGB559faa);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGB2abfff);
		putpixel(x_++, y_, RGB2a3f55);
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB559fff);
		putpixel(x_++, y_, RGB559fff);
		putpixel(x_++, y_, RGB559fff);
		putpixel(x_++, y_, RGB559fff);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB008080);
		putpixel(x_++, y_, RGB2a3f55);
		putpixel(x_++, y_, RGB557faa);
		putpixel(x_++, y_, RGB555faa);
		putpixel(x_++, y_, RGB7f7fff);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGB2a3f55);
		putpixel(x_++, y_, RGB008080);
		putpixel(x_++, y_, RGB2a3f55);
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB2a5faa);
		putpixel(x_++, y_, RGB555fff);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGB000080);
		putpixel(x_++, y_, RGB008080);
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB2a3f55);
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB2a3f55);
		putpixel(x_++, y_, RGB2a3f55);
	}
	break;
	case MIDDLE:
		write_photodata("C:\\win_pro\\etc\\ico\\pho_m", x, y);
		break;
	case BIG:
		write_photodata("C:\\win_pro\\etc\\ico\\pho_b", x, y);
		break;
	case SUPER:
		write_photodata("C:\\win_pro\\etc\\ico\\pho_s", x, y);
		break;
	default:
		break;
	}
}

/**********************
 * c文件绘制函数
 * 传递左上角坐标参数和大小
 * 无返回值
 * ***************************/
void cicodraw_o(int x, int y, Size size)
{
	switch (size)
	{
	case SMALL:
		filebasicdraw_o(x, y, size);
		x += 5;
		y += 3;
		cicowrite(x + 3, y + 6, size);
		break;
	case MIDDLE:
		filebasicdraw_o(x, y, size);
		cicowrite(x + 5, y + 12, size);
		break;
	case BIG:
		filebasicdraw_o(x, y, size);
		cicowrite(x + 10, y + 20, size);
		break;
	case SUPER:
		filebasicdraw_o(x, y, size);
		cicowrite(x + 21, y + 40, size);
		break;
	default:
		break;
	}
}
void cicowrite(int x, int y, Size size)
{
	int x_, y_;
	x_ = x;
	y_ = y;
	switch (size)
	{
	case SMALL:
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBaa7faa);
		putpixel(x_++, y_, RGBaa5faa);
		putpixel(x_++, y_, RGBaa3faa);
		putpixel(x_++, y_, RGBaa7faa);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGBd4bfff);
		putpixel(x_++, y_, RGBaa3faa);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGBd4bfaa);
		putpixel(x_++, y_, RGBaa5faa);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGBaa00aa);
		putpixel(x_++, y_, RGBd49faa);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBffffff);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGBaa00aa);
		putpixel(x_++, y_, RGBd49faa);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBffffff);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGBd4bfff);
		putpixel(x_++, y_, RGBaa3faa);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBd4dfff);
		putpixel(x_++, y_, RGBaa3faa);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGBaa5faa);
		putpixel(x_++, y_, RGBaa3faa);
		putpixel(x_++, y_, RGBaa5faa);
		putpixel(x_++, y_, RGBaa7faa);
		break;
	case MIDDLE:
		write_photodata("C:\\win_pro\\etc\\ico\\c_m", x, y);
		break;
	case BIG:
		write_photodata("C:\\win_pro\\etc\\ico\\c_b", x, y);
		break;
	case SUPER:
		write_photodata("C:\\win_pro\\etc\\ico\\c_s", x, y);
		break;
	default:
		break;
	}
}

/***********************
 * cpp文件图标绘制函数
 * 传递左上角坐标参数和大小
 * 无返回值
 * ***************************/
void cppicodraw_o(int x, int y, Size size)
{
	switch (size)
	{
	case SMALL:
		cicodraw_o(x, y, size);
		x += 5;
		y += 3;
		setfillstyle(SOLID_FILL, RGBffffff);
		bar(x + 4, y - 1, x + 11, y + 3);
		setcolor(RGBaa3faa);
		line(x + 5, y + 1, x + 11, y + 1);
		line(x + 6, y, x + 6, y + 2);
		line(x + 10, y, x + 10, y + 2);
		putpixel(x + 8, y + 1, RGBffffff);
		// cppicodraw_o_o(x, y, 1);
		break;
	case MIDDLE:
		cicodraw_o(x, y, size);
		ppicodraw_o_o(x, y, SIZE_MIDDLE);
		break;
	case BIG:
		cicodraw_o(x, y, size);
		ppicodraw_o_o(x, y, SIZE_BIG);
		break;
	case SUPER:
		cicodraw_o(x, y, size);
		ppicodraw_o_o(x, y, SIZE_SUPER);
		break;
	default:
		break;
	}
}
/********************************
 * FUNCTION:cppicodraw_o_o
 * DESCRIPTION:画cpp图标的基础函数之一，用于画右上角的加加号
 * INPUT:指定坐标，相对大小
 * RETURN:无
 * OTHERS:相对大小为1，2，4，8
 ********************************/
void ppicodraw_o_o(int x, int y, int size_size)
{
	setfillstyle(SOLID_FILL, RGBffffff);
	bar(x + 10 * size_size, y - 2 * size_size, x + 28 * size_size /* + 16 * size_size */ - 1, y + 8 * size_size - 1);
	// setcolor(RGBaa3faa);
	setfillstyle(SOLID_FILL, RGBaa3faa);
	bar(x + 12 * size_size /* + 2 * size_size */, y + 2 * size_size, x + 10 * size_size + 16 * size_size - 1, y + 4 * size_size - 1);
	bar(x + 14 * size_size, y, x + 16 * size_size - 1, y + 6 * size_size - 1);
	bar(x + 22 * size_size, y, x + 24 * size_size - 1, y + 6 * size_size - 1);
	setfillstyle(SOLID_FILL, RGBffffff);
	bar(x + 18 * size_size, y + 2 * size_size, x + 20 * size_size - 1, y + 4 * size_size - 1);
}

/**********************
 * h文件图标绘制函数
 * 传递左上角坐标参数和大小
 * 无返回值
 * ***************************/
void hicodraw_o(int x, int y, Size size)
{
	switch (size)
	{
	case SMALL:
		filebasicdraw_o(x, y, size);
		x += 5;
		y += 3;
		setfillstyle(SOLID_FILL, RGBffffff);
		bar(x + 4, y - 1, x + 11, y + 3);
		setcolor(RGBaa3faa);
		line(x + 5, y + 1, x + 11, y + 1);
		line(x + 6, y, x + 6, y + 2);
		line(x + 10, y, x + 10, y + 2);
		putpixel(x + 8, y + 1, RGBffffff);
		hicowrite(x + 2, y + 5, size);
		setcolor(RGBa0a0a4);
		line(x + 2, y + 4, x + 3, y + 4);
		break;
	case MIDDLE:
		filebasicdraw_o(x, y, size);
		hicowrite(x + 5, y + 6, size);
		ppicodraw_o_o(x, y, SIZE_MIDDLE);
		break;
	case BIG:
		filebasicdraw_o(x, y, size);
		hicowrite(x + 10, y + 13, size);
		ppicodraw_o_o(x, y, SIZE_BIG);
		break;
	case SUPER:
		filebasicdraw_o(x, y, size);
		hicowrite(x + 24, y + 30, size);
		ppicodraw_o_o(x, y, SIZE_SUPER);
		break;
	default:
		break;
	}
}
void hicowrite(int x, int y, Size size)
{
	int x_, y_;
	x_ = x;
	y_ = y;
	switch (size)
	{
	case SMALL:
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBa0a0a4);
		putpixel(x_++, y_, RGBa0a0a4);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBffffff);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBa0a0a4);
		putpixel(x_++, y_, RGBccccff);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBffffff);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBa0a0a4);
		putpixel(x_++, y_, RGBaabfaa);
		putpixel(x_++, y_, RGBaa9faa);
		putpixel(x_++, y_, RGBaa9faa);
		putpixel(x_++, y_, RGBaabfaa);
		putpixel(x_++, y_, RGBffffff);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBaabfaa);
		putpixel(x_++, y_, RGBa0a0a4);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBc0dcc0);
		putpixel(x_++, y_, RGBa0a0a4);
		putpixel(x_++, y_, RGBffffff);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBa0a0a4);
		putpixel(x_++, y_, RGBccccff);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBd4dfff);
		putpixel(x_++, y_, RGBa0a0a4);
		putpixel(x_++, y_, RGBffffff);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBa0a0a4);
		putpixel(x_++, y_, RGBc0dcc0);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBc0dcc0);
		putpixel(x_++, y_, RGBa0a0a4);
		putpixel(x_++, y_, RGBffffff);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBa0a0a4);
		putpixel(x_++, y_, RGBc0dcc0);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGBccccff);
		putpixel(x_++, y_, RGBaa9faa);
		putpixel(x_++, y_, RGBffffff);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGBa0a0a4);
		putpixel(x_++, y_, RGBa0a0a4);
		putpixel(x_++, y_, RGBaa9faa);
		putpixel(x_++, y_, RGBffdfff);
		putpixel(x_++, y_, RGBa0a0a4);
		putpixel(x_++, y_, RGBa0a0a4);
		putpixel(x_++, y_, RGBa0a0a4);
		break;
	case MIDDLE:
		write_photodata("C:\\win_pro\\etc\\ico\\h_m", x, y);
		break;
	case BIG:
		write_photodata("C:\\win_pro\\etc\\ico\\h_b", x, y);
		break;
	case SUPER:
		write_photodata("C:\\win_pro\\etc\\ico\\h_s", x, y);
		break;
	default:
		break;
	}
}

/*****************************
 * obj文件图标绘制函数
 * 传递左上角坐标参数和大小
 * 无返回值
 * ***************************/
void objicodraw_o(int x, int y, Size size)
{
	switch (size)
	{
	case SMALL:
		filebasicdraw_o(x, y, size);
		x += 5;
		y += 3;
		objicowrite(x - 2, y + 6, size);
		break;
	case MIDDLE:
		filebasicdraw_o(x, y, size);
		objicowrite(x - 3, y + 12, size);
		break;
	case BIG:
		filebasicdraw_o(x, y, size);
		objicowrite(x - 6, y + 23, size);
		break;
	case SUPER:
		filebasicdraw_o(x, y, size);
		objicowrite(x - 12, y + 47, size);
		break;
	default:
		break;
	}
}
void objicowrite(int x, int y, Size size)
{
	int x_, y_;
	x_ = x;
	y_ = y;
	switch (size)
	{
	case SMALL:
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB808080);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGB808080);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGBaa9faa);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBa0a0a4);
		putpixel(x_++, y_, RGB2a3f55);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGB000000);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB2a1f00);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGB000000);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBa0a0a4);
		putpixel(x_++, y_, RGBaa9faa);
		putpixel(x_++, y_, RGBa0a0a4);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGB000000);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGB000000);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB808080);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGB808080);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBa0a0a4);
		putpixel(x_++, y_, RGB2a3f55);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB555f55);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBa0a0a4);
		putpixel(x_++, y_, RGB000000);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);
		putpixel(x_++, y_, RGB000000);

		break;
	case MIDDLE:
		write_photodata("C:\\win_pro\\etc\\ico\\obj_m", x, y);
		break;
	case BIG:
		write_photodata("C:\\win_pro\\etc\\ico\\obj_b", x, y);
		break;
	case SUPER:
		write_photodata("C:\\win_pro\\etc\\ico\\obj_s", x, y);
		break;
	default:
		break;
	}
}

/***************************
 * doc文件图标绘制函数
 * 传递左上角坐标参数和大小
 * 无返回值
 * ***************************/
void docicodraw_o(int x, int y, Size size)
{

	int y_;
	int i; //循环
	switch (size)
	{
	case SMALL:
		filebasicdraw_o(x + 1, y, size);
		x += 6;
		y += 3;
		docicowrite(x - 2, y + 5, size);
		setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
		setcolor(RGB2a3faa);
		y_ = y + 6;
		for (i = 0; i < 3; i++)
		{
			line(x + 6, y_, x + 8, y_);
			y_ += 2;
		}
		break;
	case MIDDLE:
		filebasicdraw_o(x, y, size);
		docicodraw_o_o(x, y, size);
		break;
	case BIG:
		filebasicdraw_o(x, y, size);
		docicodraw_o_o(x, y, size);
		break;
	case SUPER:
		filebasicdraw_o(x, y, size);
		docicodraw_o_o(x, y, size);
		break;
	default:
		break;
	}
}
void docicodraw_o_o(int x, int y, int size)
{
	int i;
	int size_size;
	int y_y, line_x;
	switch (size)
	{
	case MIDDLE:
		size_size = SIZE_MIDDLE;
		line_x = 7;
		break;
	case BIG:
		size_size = SIZE_BIG;
		line_x = 15;
		break;
	case SUPER:
		size_size = SIZE_SUPER;
		line_x = 30;
		break;
	default:
		break;
	}
	docicowrite(x - 4 * size_size, y + 8 * size_size, size);
	setfillstyle(SOLID_FILL, RGB2a3faa);
	y_y = y + 8 * size_size + 3 * size_size;
	for (i = 0; i < 4; i++)
	{
		bar(x + 12 * size_size + 2 * size_size + 1, y_y,
			x + 12 * size_size + 2 * size_size + 1 + line_x - 1, y_y + size_size - 1);
		y_y += 2 * size_size + size_size;
	}
}
void docicowrite(int x, int y, Size size)
{
	int x_, y_;
	x_ = x;
	y_ = y;
	switch (size)
	{
	case SMALL:
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB2a3faa);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB555faa);
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB555faa);
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB555faa);
		putpixel(x_++, y_, RGB2a3faa);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGB2a3faa);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGBaa9fff);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBa6caf0);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBaa9fff);
		putpixel(x_++, y_, RGB2a3faa);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB557faa);
		putpixel(x_++, y_, RGBffdfff);
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGBffdfff);
		putpixel(x_++, y_, RGB7f7faa);
		putpixel(x_++, y_, RGB2a3faa);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB557faa);
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB557faa);
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB2a3faa);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB2a3faa);
		putpixel(x_++, y_, RGB2a3faa);
		break;
	case MIDDLE:
		write_photodata("C:\\win_pro\\etc\\ico\\doc_m", x, y);
		break;
	case BIG:
		write_photodata("C:\\win_pro\\etc\\ico\\doc_b", x, y);
		break;
	case SUPER:
		write_photodata("C:\\win_pro\\etc\\ico\\doc_s", x, y);
		break;
	default:
		break;
	}
}

/****************************
 * xls文件图标绘制函数
 * 传递左上角坐标参数和大小
 * 无返回值
 * **************************/
void xlsicodraw_o(int x, int y, Size size)
{
	int y_;
	int i; //循环辅助变量
	switch (size)
	{
	case SMALL:
		filebasicdraw_o(x + 1, y, size);
		x += 6;
		y += 3;
		xlsicowrite(x - 2, y + 5, size);
		setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
		setcolor(RGB008000);
		y_ = y + 6;
		for (i = 0; i < 3; i++)
		{
			line(x + 6, y_, x + 8, y_);
			y_ += 2;
		}
		setcolor(RGBffffff);
		line(x + 7, y + 6, x + 7, y + 10);
		break;
	case MIDDLE:
		filebasicdraw_o(x, y, size);
		xlsicodraw_o_o(x, y, size);
		break;
	case BIG:
		filebasicdraw_o(x, y, size);
		xlsicodraw_o_o(x, y, size);
		break;
	case SUPER:
		filebasicdraw_o(x, y, size);
		xlsicodraw_o_o(x, y, size);
		break;
	default:
		break;
	}
}
void xlsicodraw_o_o(int x, int y, int size)
{
	int size_size;
	int i;
	int line_y, y_, space_y, space_x, y_y;
	switch (size)
	{
	case MIDDLE:
		size_size = SIZE_MIDDLE;
		y_y = y + 8 * size_size + 4;
		line_y = 1;
		space_y = 3;
		space_x = 3;
		break;
	case BIG:
		size_size = SIZE_BIG;
		y_y = y + 8 * size_size + 9;
		line_y = 3;
		space_y = 4;
		space_x = 4;
		break;
	case SUPER:
		size_size = SIZE_SUPER;
		y_y = y + 8 * size_size + 15;
		line_y = 7;
		space_y = 8;
		space_x = 6;
		break;
	default:
		break;
	}
	xlsicowrite(x - 4 * size_size, y + 8 * size_size, size);
	// setcolor(RGB008000);
	setfillstyle(SOLID_FILL, RGB008000);
	y_ = y_y;
	for (i = 0; i < 3; i++)
	{
		bar(x + 12 * size_size + space_x, y_,
			x + 12 * size_size + space_x + 9 * size_size - 3, y_ + line_y - 1);
		y_ += space_y + line_y;
	}
	setfillstyle(SOLID_FILL, RGBffffff);
	bar(x + 12 * size_size + space_x + (9 * size_size - space_y) / 2 - 1, y_y,
		x + 12 * size_size + space_x + (9 * size_size - space_y) / 2 + space_y - 3, y_ - space_y - 1);
}
void xlsicowrite(int x, int y, Size size)
{
	int x_, y_;
	x_ = x;
	y_ = y;
	switch (size)
	{
	case SMALL:
		putpixel(x_++, y_, RGB008000);
		putpixel(x_++, y_, RGB007f00);
		putpixel(x_++, y_, RGB007f00);
		putpixel(x_++, y_, RGB007f00);
		putpixel(x_++, y_, RGB007f00);
		putpixel(x_++, y_, RGB007f00);
		putpixel(x_++, y_, RGB008000);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGB007f00);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGB559f55);
		putpixel(x_++, y_, RGB008000);
		putpixel(x_++, y_, RGB2a9f55);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGB008000);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGB008000);
		putpixel(x_++, y_, RGB008000);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGB7fbfaa);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGB008000);
		putpixel(x_++, y_, RGB008000);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGB007f00);
		putpixel(x_++, y_, RGB007f00);
		putpixel(x_++, y_, RGB55bf55);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGB2a9f00);
		putpixel(x_++, y_, RGB007f00);
		putpixel(x_++, y_, RGB008000);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGB008000);
		putpixel(x_++, y_, RGB007f00);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGB2a9f00);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGB007f00);
		putpixel(x_++, y_, RGB007f00);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGB007f00);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGB559f55);
		putpixel(x_++, y_, RGB008000);
		putpixel(x_++, y_, RGB7fbf55);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGB007f00);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGB008000);
		putpixel(x_++, y_, RGB008000);
		putpixel(x_++, y_, RGB008000);
		putpixel(x_++, y_, RGB007f00);
		putpixel(x_++, y_, RGB007f00);
		putpixel(x_++, y_, RGB008000);
		putpixel(x_++, y_, RGB008000);
		break;
	case MIDDLE:
		write_photodata("C:\\win_pro\\etc\\ico\\xls_m", x, y);
		break;
	case BIG:
		write_photodata("C:\\win_pro\\etc\\ico\\xls_b", x, y);
		break;
	case SUPER:
		write_photodata("C:\\win_pro\\etc\\ico\\xls_s", x, y);
		break;
	default:
		break;
	}
}

/*************************
 * ppt文件绘制函数
 * 传递参数：左上角坐标参数和大小
 * 无返回值
 * **********************/
void ppticodraw_o(int x, int y, Size size)
{
	switch (size)
	{
	case SMALL:
		filebasicdraw_o(x + 1, y, size);
		x += 6;
		y += 3;
		ppticowrite(x - 2, y + 5, size);
		setfillstyle(SOLID_FILL, RGBff5f00);
		bar(x + 6, y + 6, x + 8, y + 8);
		break;
	case MIDDLE:
		filebasicdraw_o(x, y, size);
		ppticodraw_o_o(x, y, size);
		break;
	case BIG:
		filebasicdraw_o(x, y, size);
		ppticodraw_o_o(x, y, size);
		break;
	case SUPER:
		filebasicdraw_o(x, y, size);
		ppticodraw_o_o(x, y, size);
		break;
	default:
		break;
	}
}
void ppticodraw_o_o(int x, int y, int size)
{
	int size_size;
	int space_y;
	switch (size)
	{
	case MIDDLE:
		size_size = SIZE_MIDDLE;
		space_y = 3;
		break;
	case BIG:
		size_size = SIZE_BIG;
		space_y = 6;
		break;
	case SUPER:
		size_size = SIZE_SUPER;
		space_y = 11;
		break;
	default:
		break;
	}
	ppticowrite(x - 4 * size_size, y + 8 * size_size, size);
	pptpicowrite(x + 12 * size_size, y + 8 * size_size + space_y, size);
	setfillstyle(SOLID_FILL, RGBffffff);
}
void pptpicowrite(int x, int y, Size size)
{
	switch (size)
	{
	case SMALL:
		break;
	case MIDDLE:
		write_photodata("C:\\win_pro\\etc\\ico\\pptp_m", x, y);
		break;
	case BIG:
		write_photodata("C:\\win_pro\\etc\\ico\\pptp_b", x, y);
		break;
	case SUPER:
		write_photodata("C:\\win_pro\\etc\\ico\\pptp_s", x, y);
		break;
	default:
		break;
	}
}
void ppticowrite(int x, int y, Size size)
{
	int x_, y_;
	x_ = x;
	y_ = y;
	switch (size)
	{
	case SMALL:
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBd43f00);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBffdfff);
		putpixel(x_++, y_, RGBffdfff);
		putpixel(x_++, y_, RGBd47f55);
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBd43f00);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBd47f55);
		putpixel(x_++, y_, RGBffdfff);
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBd43f00);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBd47f55);
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBd43f00);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBd43f00);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBffffff);
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBd43f00);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBd43f00);
		putpixel(x_++, y_, RGBd43f00);
		break;
	case MIDDLE:
		write_photodata("C:\\win_pro\\etc\\ico\\ppt_m", x, y);
		break;
	case BIG:
		write_photodata("C:\\win_pro\\etc\\ico\\ppt_b", x, y);
		break;
	case SUPER:
		write_photodata("C:\\win_pro\\etc\\ico\\ppt_s", x, y);
		break;
	default:
		break;
	}
}

/**********************
 * pdf文件绘制函数
 * 传递参数：左上角坐标参数和大小
 * 无返回值
 * **********************/
void pdficodraw_o(int x, int y, Size size)
{
	switch (size)
	{
	case SMALL:
		txticodraw_o(x, y, size);
		x += 5;
		y += 3;
		pdficowrite(x - 2, y + 6, size);
		break;
	case MIDDLE:
		txticodraw_o(x, y, size);
		pdficowrite(x - 2, y + 11, size);
		break;
	case BIG:
		txticodraw_o(x, y, size);
		pdficowrite(x - 4, y + 22, size);
		break;
	case SUPER:
		txticodraw_o(x, y, size);
		pdficowrite(x - 8, y + 42, size);
		break;
	default:
		break;
	}
}
void pdficowrite(int x, int y, Size size)
{
	int x_, y_;
	x_ = x;
	y_ = y;
	switch (size)
	{
	case SMALL:
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBffbfaa);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGBff9faa);
		putpixel(x_++, y_, RGBd41f00);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGBd47f55);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGBff9faa);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBaa1f00);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBffccff);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBffdfff);
		putpixel(x_++, y_, RGBd43f55);
		putpixel(x_++, y_, RGBffdfff);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBaa1f00);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGBff7f55);
		putpixel(x_++, y_, RGBd43f55);
		putpixel(x_++, y_, RGBffdfff);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBffbfaa);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGBff9faa);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBaa1f00);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGBd41f55);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBd41f00);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGBd43f55);
		putpixel(x_++, y_, RGBffdfff);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBaa1f00);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBffbfaa);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGBfffbf0);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBffbfaa);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBd40000);
		putpixel(x_++, y_, RGBaa1f00);
		x_ = x;
		y_++;
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		putpixel(x_++, y_, RGBaa1f00);
		break;
	case MIDDLE:
		write_photodata("C:\\win_pro\\etc\\ico\\pdf_m", x, y);
		break;
	case BIG:
		write_photodata("C:\\win_pro\\etc\\ico\\pdf_b", x, y);
		break;
	case SUPER:
		write_photodata("C:\\win_pro\\etc\\ico\\pdf_s", x, y);
		break;
	default:
		break;
	}
}

/**************************
 * exe文件图标绘制函数
 * 传递左上角坐标参数和大小
 * 无返回值
 * ***************************/
void exeicodraw_o(int x, int y, Size size)
{
	char x_, y_1, y_2;
	char i; //循环用辅助变量
	switch (size)
	{
	case SMALL:
		x += 3;
		y += 5;
		setcolor(RGB808080);
		setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
		x_ = 11;
		y_1 = 3;
		y_2 = 4;
		rectangle(x, y, x + 16, y + 12);
		line(x + 1, y + 1, x + 15, y + 1);
		setfillstyle(SOLID_FILL, RGBfffbf0);
		bar(x + 1, y + 3, x + 3, y + 11);
		for (i = 0; i < 2; i++)
		{
			line(x + 2, y + y_2, x + 3, y + y_2);
			y_2 += 2;
		}
		for (i = 0; i < 2; i++)
		{
			line(x + 11, y + y_1, x + 13, y + y_1);
			y_1 += 2;
		}
		setfillstyle(SOLID_FILL, RGB007fff);
		bar(x + 5, y + 3, x + 9, y + 8);
		for (i = 0; i < 3; i++)
		{
			putpixel(x + x_, y + 1, RGBa0a0a4);
			x_ += 2;
		}
		break;
	case MIDDLE:
		exeicodraw_o_o(x, y, size);

		break;
	case BIG:
		// setcolor(RGB808080);
		exeicodraw_o_o(x, y, size);

		break;
	case SUPER:
		// setcolor(RGB808080);
		exeicodraw_o_o(x-17, y+17, size);

		break;
	default:
		break;
	}
}
void exeicodraw_o_o(int x, int y, Size size)
{
	switch (size)
	{
	case MIDDLE:
		write_photodata("C:\\win_pro\\etc\\ico\\exe_m", x, y);
		break;
	case BIG:
		write_photodata("C:\\win_pro\\etc\\ico\\exe_b", x, y);
		break;
	case SUPER:
		write_photodata("C:\\win_pro\\etc\\ico\\exe_s", x, y);
		break;
	default:
		break;
	}
}

/********************
 * 文件夹图形绘制函数，
 * 输入左上角横纵坐标、相对大小（倍率）
 * 无返回值
 * *******************/
void diricodraw_o(int x, int y, Size size)
{

	switch (size)
	{
	case SMALL:
		x += 6;
		y += 2;
		diricodraw_o_o(x, y, 1);
		break;
	case MIDDLE:
		// setcolor(RGBffbf00);
		// setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
		x += 2;
		diricodraw_o_o(x, y, 2);
		break;
	case BIG:
		// setcolor(RGBffbf00);
		// setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
		diricodraw_o_o(x, y, 4);
		break;
	case SUPER:
		// setcolor(RGBffbf00);
		// setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
		diricodraw_o_o(x, y, 8);
		break;
	default:
		break;
	}
}
void diricodraw_o_o(int x, int y, int size_size)
{
	setcolor(RGBffdf55);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	moveto(x, y);
	// delay(500);
	lineto(x + 3 * size_size, y + 3 * size_size);
	// delay(500);
	lineto(x + 3 * size_size, y + 11 * size_size);
	// delay(500);
	lineto(x + 2 * size_size, y + 10 * size_size);
	// delay(500);
	lineto(x + 2 * size_size, y + 16 * size_size);
	// delay(500);
	lineto(x, y + 14 * size_size);
	// delay(500);
	lineto(x, y);
	// delay(500);
	moveto(x /* + 1 * size_size */, y);
	// delay(500);
	//  setcolor(RGBffbf00);
	lineto(x + 8 * size_size, y);
	// delay(500);
	lineto(x + 8 * size_size, y + 8 * size_size);
	// delay(500);
	lineto(x + 9 * size_size, y + 9 * size_size);
	// delay(500);
	lineto(x + 9 * size_size, y + 13 * size_size);
	// delay(500);
	lineto(x + 2 * size_size, y + 13 * size_size);
	// getch();
	setfillstyle(SOLID_FILL, RGBffbf00);
	floodfill(x + 6 * size_size, y + 6 * size_size, RGBffdf55);
	// getch();
	setfillstyle(SOLID_FILL, RGBffdf55);
	floodfill(x + 1 * size_size, y + 6 * size_size, RGBffdf55);
}

/****************************
 * 磁盘绘制函数
 * 输入左上角横纵坐标、相对大小（倍率）
 * 无返回值
 * *******************/
void diskicodraw_o(int x, int y, Size size)
{

	switch (size)
	{
	case SMALL:
		diskicodraw_o_o(x, y, 1);
		break;
	case MIDDLE:
		diskicodraw_o_o(x, y, 2);
		break;
	case BIG:
		diskicodraw_o_o(x, y, 4);
		break;
	case SUPER:
		x -= 14;
		y += 10;
		diskicodraw_o_o(x, y, 8);
		break;
	default:
		break;
	}
}
void diskicodraw_o_o(int x, int y, int size_size)
{
	int xy[8];
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);

	xy[0] = x - 1 * size_size;
	xy[1] = y + 7 * size_size;
	xy[2] = xy[0];
	xy[3] = y + 10 * size_size;
	xy[4] = x + 6 * size_size;
	xy[5] = y + 14 * size_size;
	xy[6] = xy[4];
	xy[7] = y + 11 * size_size;
	setfillstyle(SOLID_FILL, RGB000000);
	setcolor(RGB000000);
	fillpoly(4, xy);
	if (size_size == 1)
	{
		putpixel(x + 5, y + 12, RGB2aff00);
	}
	else
	{
		setfillstyle(SOLID_FILL, RGB2aff00);
		setcolor(RGB2aff00);
		fillellipse(x + 5 * size_size, y + 12 * size_size, size_size / 2, size_size / 2);
	}
	xy[0] = xy[6];
	xy[1] = xy[7];
	xy[2] = xy[4];
	xy[3] = xy[5];
	xy[4] = x + 16 * size_size;
	xy[5] = y + 9 * size_size;
	xy[6] = x + 16 * size_size;
	xy[7] = y + 6 * size_size;
	setfillstyle(SOLID_FILL, RGB808080);
	setcolor(RGB808080);
	fillpoly(4, xy);
	xy[0] = xy[6];
	xy[1] = xy[7];
	xy[2] = x + 9 * size_size;
	xy[3] = y + 2 * size_size;
	xy[4] = x - 1 * size_size;
	xy[5] = y + 7 * size_size;
	xy[6] = x + 6 * size_size;
	xy[7] = y + 11 * size_size;
	setfillstyle(SOLID_FILL, RGBa0a0a4);
	setcolor(RGBa0a0a4);
	fillpoly(4, xy);
	setfillstyle(SOLID_FILL, RGB00bfff);
	bar(x, y, x + 6 * size_size, y + 6 * size_size);
	if (size_size == 1)
	{
		setcolor(RGBffffff);
		line(x + 3, y, x + 3, y + 6);
		line(x, y + 3, x + 6, y + 3);
	}
	else
	{
		setfillstyle(SOLID_FILL, RGBffffff);
		setcolor(RGBffffff);
		bar(x + 3 * size_size - size_size / 8, y, x + 3 * size_size + size_size / 8, y + 6 * size_size);
		bar(x, y + 3 * size_size - size_size / 8, x + 6 * size_size, y + 3 * size_size + size_size / 8);
	}
}

/********************************
 * FUNCTION:errorico_write
 * DESCRIPTION:写错误图标
 * INPUT:左上坐标
 * RETURN:无
 * OTHERS:无
 ********************************/
void errorico_write(int x,int y)
{
	write_photodata("C:\\win_pro\\etc\\ico\\error", x, y);
}

/********************************
 * FUNCTION:arningico_write
 * DESCRIPTION:写警告图标
 * INPUT:左上坐标
 * RETURN:无
 * OTHERS:无
 ********************************/
void warningico_write(int x,int y)
{
	write_photodata("C:\\win_pro\\etc\\ico\\warning", x, y);
}

/**********************
 * 写屏辅助函数，读取生成的图片数据并画图
 * 传递参数：文件名（绝对路径），图片左上角坐标
 * 返回值：无
 * **********************/
void write_photodata(char *filename, int x, int y)
{
	unsigned short dx, dy;
	int i, j;
	int x_, y_;
	char color;
	FILE *fp;
	if ((fp = fopen(filename, "rb")) == NULL)
	{
		pop_error(-1, "WRITE_PHOTODATA:", "Can't open the file:", filename);
		exit(1);
	}
	rewind(fp);

	fread(&dx, sizeof(dx), 1, fp);
	fread(&dy, sizeof(dy), 1, fp);
	x_ = x;
	y_ = y;
	for (i = 0; i < dy; i++)
	{
		for (j = 0; j < dx; j++)
		{
			color = fgetc(fp);
			putpixel(x_++, y_, color);
		}
		x_ = x;
		y_++;
	}
	fclose(fp);
}
