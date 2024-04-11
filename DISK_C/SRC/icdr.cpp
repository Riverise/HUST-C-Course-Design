/***************
 * 初始化和关闭图形界面
 * **************/

#include "icdr.h"

/********************
 * 初始化svga驱动，以便于使用SVGA绘制图形
 * *****************/

int huge detectSVGA256(void) //设置驱动必须的函数
{
	return SVGA1024x768x256; //高分辨率实现
}

int initsvga256(void) //初始化函数
{
	int G_driver = DETECT, G_model;
	char Gr_error; //错误信息储存
	chdir("C:\\win_pro\\etc");
	installuserdriver("Svga256", detectSVGA256);
	initgraph(&G_driver, &G_model, "");
	Gr_error = graphresult();
	if (Gr_error != grOk)
	{
		return 0;
	}
	return 1;
}

int closesvga256(void) //关闭图像模式函数
{
	char Gr_error; //错误信息储存
	closegraph();
	Gr_error = graphresult();
	if (Gr_error != grOk)
	{
		return 0;
	}
	return 1;
}

/**************************
 * 初始化Windows系统256色 函数
 * ***********************/
/* 处理Windows系统256色RGB编码 */
DacPalette256 *getwinRGB(void)
{
	unsigned long int win_rgb[256] = {
		0x000000,
		0x800000,
		0x008000,
		0x808000,
		0x000080,
		0x800080,
		0x008080,
		0x808080,
		0xc0dcc0,
		0xa6caf0,
		0x2a3faa,
		0x2a3fff,
		0x2a5f00,
		0x2a5f55,
		0x2a5faa,
		0x2a5fff,
		0x2a7f00,
		0x2a7f55,
		0x2a7faa,
		0x2a7fff,
		0x2a9f00,
		0x2a9f55,
		0x2a9faa,
		0x2a9fff,
		0x2abf00,
		0x2abf55,
		0x2abfaa,
		0x2abfff,
		0x2adf00,
		0x2adf55,
		0x2adfaa,
		0x2adfff,
		0x2aff00,
		0x2aff55,
		0x2affaa,
		0x2affff,
		0x550000,
		0x550055,
		0x5500aa,
		0x5500ff,
		0x551f00,
		0x551f55,
		0x551faa,
		0x551fff,
		0x553f00,
		0x553f55,
		0x553faa,
		0x553fff,
		0x555f00,
		0x555f55,
		0x555faa,
		0x555fff,
		0x557f00,
		0x557f55,
		0x557faa,
		0x557fff,
		0x559f00,
		0x559f55,
		0x559faa,
		0x559fff,
		0x55bf00,
		0x55bf55,
		0x55bfaa,
		0x55bfff,
		0x55df00,
		0x55df55,
		0x55dfaa,
		0x55dfff,
		0x55ff00,
		0x55ff55,
		0x55ffaa,
		0x55ffff,
		0x7f0000,
		0x7f0055,
		0x7f00aa,
		0x7f00ff,
		0x7f1f00,
		0x7f1f55,
		0x7f1faa,
		0x7f1fff,
		0x7f3f00,
		0x7f3f55,
		0x7f3faa,
		0x7f3fff,
		0x7f5f00,
		0x7f5f55,
		0x7f5faa,
		0x7f5fff,
		0x7f7f00,
		0x7f7f55,
		0x7f7faa,
		0x7f7fff,
		0x7f9f00,
		0x7f9f55,
		0x7f9faa,
		0x7f9fff,
		0x7fbf00,
		0x7fbf55,
		0x7fbfaa,
		0x7fbfff,
		0x7fdf00,
		0x7fdf55,
		0x7fdfaa,
		0x7fdfff,
		0x7fff00,
		0x7fff55,
		0x7fffaa,
		0x7fffff,
		0xaa0000,
		0xaa0055,
		0xaa00aa,
		0xaa00ff,
		0xaa1f00,
		0xaa1f55,
		0xaa1faa,
		0xaa1fff,
		0xaa3f00,
		0xaa3f55,
		0xaa3faa,
		0xaa3fff,
		0xaa5f00,
		0xaa5f55,
		0xaa5faa,
		0xaa5fff,
		0xaa7f00,
		0xaa7f55,
		0xaa7faa,
		0xaa7fff,
		0xaa9f00,
		0xaa9f55,
		0xaa9faa,
		0xaa9fff,
		0xaabf00,
		0xaabf55,
		0xaabfaa,
		0xaabfff,
		0xaadf00,
		0xaadf55,
		0xaadfaa,
		0xaadfff,
		0xaaff00,
		0xaaff55,
		0xaaffaa,
		0xaaffff,
		0xd40000,
		0xd40055,
		0xd400aa,
		0xd400ff,
		0xd41f00,
		0xd41f55,
		0xd41faa,
		0xd41fff,
		0xd43f00,
		0xd43f55,
		0xd43faa,
		0xd43fff,
		0xd45f00,
		0xd45f55,
		0xd45faa,
		0xd45fff,
		0xd47f00,
		0xd47f55,
		0xd47faa,
		0xd47fff,
		0xd49f00,
		0xd49f55,
		0xd49faa,
		0xd49fff,
		0xd4bf00,
		0xd4bf55,
		0xd4bfaa,
		0xd4bfff,
		0xd4df00,
		0xd4df55,
		0xd4dfaa,
		0xd4dfff,
		0xd4ff00,
		0xd4ff55,
		0xd4ffaa,
		0xd4ffff,
		0xff0055,
		0xff00aa,
		0xff1f00,
		0xff1f55,
		0xff1faa,
		0xff1fff,
		0xff3f00,
		0xff3f55,
		0xff3faa,
		0xff3fff,
		0xff5f00,
		0xff5f55,
		0xff5faa,
		0xff5fff,
		0xff7f00,
		0xff7f55,
		0xff7faa,
		0xff7fff,
		0xff9f00,
		0xff9f55,
		0xff9faa,
		0xff9fff,
		0xffbf00,
		0xffbf55,
		0xffbfaa,
		0xffbfff,
		0xffdf00,
		0xffdf55,
		0xffdfaa,
		0xffdfff,
		0xffff55,
		0xffffaa,
		0xccccff,
		0xffccff,
		0x33ffff,
		0x66ffff,
		0x99ffff,
		0xccffff,
		0x007f00,
		0x007f55,
		0x007faa,
		0x007fff,
		0x009f00,
		0x009f55,
		0x009faa,
		0x009fff,
		0x00bf00,
		0x00bf55,
		0x00bfaa,
		0x00bfff,
		0x00df00,
		0x00df55,
		0x00dfaa,
		0x00dfff,
		0x00ff55,
		0x00ffaa,
		0x2a0000,
		0x2a0055,
		0x2a00aa,
		0x2a00ff,
		0x2a1f00,
		0x2a1f55,
		0x2a1faa,
		0x2a1fff,
		0x2a3f00,
		0x2a3f55,
		0xfffbf0,
		0xa0a0a4,
		0x808080,
		0xff0000,
		0x00ff00,
		0xffff00,
		0x0000ff,
		0xff00ff,
		0x00ffff,
		0xffffff,
	}; // windows系统配色
	DacPalette256 win_color;
	int i; //循环辅助变量
	for (i = 0; i < 256; i++)
	{
		win_color[i][0] = (win_rgb[i] >> 16) / 4;
		win_color[i][1] = ((win_rgb[i] & 0x00ff00) >> 8) / 4;
		win_color[i][2] = (win_rgb[i] & 0x0000ff) / 4;
	}
	return &win_color;
}
/* 调色板初始化，获得Windows系统256色 */
void initcolor256(void)
{
	setvgapalette256(getwinRGB());
}

/********************************
 * FUNCTION:record_imagedata
 * DESCRIPTION:通过文件操作记录图像数据函数
 * INPUT:矩形坐标，数据库文件名
 * RETURN:无
 * OTHERS:无
 ********************************/
void record_imagedata(int x1, int y1, int x2, int y2, char *filename)
{
	int dx, dy, x_, y_;
	int i, j;
	FILE *fp;
	char color; //颜色色号数据记录

	dx = x2 - x1;
	dy = y2 - y1;
	x_ = x1;
	y_ = y1;
	if (chdir("C:\\win_pro\\etc\\data") == -1)
	{
		pop_error(-1, "RECORD_IMAGEDATA:", "Error on chdir.");
	}
	if ((fp = fopen(filename, "wb")) == NULL)
	{
		pop_error(-1, "RECORD_IMAGEDATA:", "Can't open the file:", filename);
		exit(1);
	}
	clrmous(MouseX, MouseY);
	rewind(fp);
	for (i = 0; i < dy; i++)
	{
		for (j = 0; j < dx; j++)
		{
			color = getpixel(x_++, y_);
			fputc(color, fp);
		}
		x_ = x1;
		y_++;
	}

	fclose(fp);
}

/*************************************
 * 从数据库读文件并将其写在屏幕上
 * 传递参数：矩形坐标，数据库名称
 * 返回值：无
 * *************************************/
void write_imagedata(int x1, int y1, int x2, int y2, char *filename)
{
	int dx, dy, x_, y_;
	int i, j;
	FILE *fp;
	char color; //颜色色号数据记录

	dx = x2 - x1;
	dy = y2 - y1;
	x_ = x1;
	y_ = y1;

	if (chdir("C:\\win_pro\\etc\\data") == -1)
	{
		pop_error(-1, "RECORD_IMAGEDATA:", "Error on chdir.");
	}
	if ((fp = fopen(filename, "rb")) == NULL)
	{
		pop_error(-1, "WRITE_IMAGEDATA:", "Can't open the file:", filename);
		exit(1);
	}

	rewind(fp);
	for (i = 0; i < dy; i++)
	{
		for (j = 0; j < dx; j++)
		{
			color = fgetc(fp);
			putpixel(x_++, y_, color);
		}
		x_ = x1;
		y_++;
	}

	fclose(fp);
}