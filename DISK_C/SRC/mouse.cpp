#include "mouse.h"

/**************************
MOUSE.c
UPDATER: dengshuumin
FUNCTION: mouse action
ABSTRACT:
		A.mread
		B.newmouse
VERSION: 3.0
***************************/
int MouseX;
int MouseY;
int MouseS;
int press;
void *buffer;
union REGS regs;
int mflag = 0; //鼠标显示状态

void mouseinit() //初始化
{
	int retcode;
	int xmax, ymax;
	int size;
	xmax = XMAX;
	ymax = YMAX;

	regs.x.ax = 0x00; //初始化鼠标
	int86(0x33, &regs, &regs);
	retcode = regs.x.ax;

	if (retcode == 0) //不支持鼠标
	{
		pop_error(-1, "MOUSEINIT:", "Mouse or Mouse Driver Obsent,Please Install!");
	}
	else
	{
		regs.x.ax = 7;			   //设置水平边界
		regs.x.cx = XMIN;		   //最小
		regs.x.dx = xmax;		   //最大
		int86(0x33, &regs, &regs); //传递设置值
		regs.x.ax = 8;			   //设置竖直边界
		regs.x.cx = YMIN;		   //最小
		regs.x.dx = ymax;		   //最大
		int86(0x33, &regs, &regs); //传递参数值
	}
	MouseS = 0;					//初始化结果为箭头形式
	MouseX = 320, MouseY = 240; //指定位置画一次鼠标
	save_bk_mou(320, 240);
	mouse(MouseX, MouseY);
	mflag = 1;
}

/*****************************
FUNCTION: mouse
DESCRIPTION: 画不同形态的鼠标
INPUT: x,y
RETURN: 无
******************************/
void mouse(int x, int y)
{

	switch (MouseS)
	{
	case 1: //手势鼠标
	{
		setcolor(RGBffffff);
		setlinestyle(0, 0, 1);
		line(x - 1, y + 9, x - 1, y + 8);
		line(x, y + 7, x, y + 11);
		line(x + 1, y + 6, x + 1, y + 13);
		line(x + 2, y + 8, x + 2, y + 14);
		line(x + 3, y - 1, x + 3, y + 15);
		arc(x + 4, y - 1, 0, 180, 1);
		line(x + 4, y - 2, x + 4, y + 15);
		line(x + 5, y - 1, x + 5, y + 16);
		arc(x + 6, y + 3, 0, 180, 1);
		line(x + 6, y + 2, x + 6, y + 16);
		line(x + 7, y + 3, x + 7, y + 17);
		arc(x + 8, y + 5, 0, 180, 1);
		line(x + 8, y + 4, x + 8, y + 17);
		line(x + 9, y + 5, x + 9, y + 16);
		arc(x + 10, y + 7, 0, 180, 1);
		line(x + 10, y + 6, x + 10, y + 16);
		line(x + 11, y + 7, x + 11, y + 13);

		setcolor(RGB000000);
		line(x - 1, y + 9, x - 1, y + 8);
		line(x - 1, y + 8, x + 1, y + 6);
		line(x + 1, y + 6, x + 3, y + 10);
		line(x + 3, y + 10, x + 3, y - 1);
		arc(x + 4, y - 1, 0, 180, 1);
		line(x + 5, y - 1, x + 5, y + 5);
		arc(x + 6, y + 3, 0, 180, 1);
		line(x + 7, y + 3, x + 7, y + 7);
		arc(x + 8, y + 5, 0, 180, 1);
		line(x + 9, y + 5, x + 9, y + 9);
		arc(x + 10, y + 7, 0, 180, 1);
		line(x + 11, y + 7, x + 11, y + 13);
		arc(x + 7, y + 13, -90, 0, 4);
		line(x + 7, y + 17, x + 3, y + 15);
		line(x + 3, y + 15, x + 1, y + 13);
		line(x + 1, y + 13, x - 1, y + 9);
	}
	break;
	case 2: //光标
	{
		setcolor(RGB000000);
		setlinestyle(0, 0, 1);
		line(x + 1, y - 1, x + 9, y - 1);
		line(x + 1, y + 15, x + 9, y + 15);
		line(x + 5, y - 1, x + 5, y + 15);
	}
	break;
	case 3: //十字
	{
		setcolor(RGBffffff);
		setlinestyle(0, 0, 1);
		line(x - 1, y + 7, x + 11, y + 7);
		line(x + 5, y - 1, x + 5, y + 15);
	}
	break;
	default: //默认鼠标
	{
		setlinestyle(0, 0, 1);
		setcolor(RGBffffff);
		line(x, y, x, y + 13);
		line(x + 1, y + 1, x + 1, y + 12);
		line(x + 2, y + 2, x + 2, y + 11);
		line(x + 3, y + 3, x + 3, y + 10);
		line(x + 4, y + 4, x + 4, y + 12);
		line(x + 5, y + 5, x + 5, y + 9);
		line(x + 5, y + 11, x + 5, y + 14);
		line(x + 6, y + 6, x + 6, y + 9);
		line(x + 6, y + 13, x + 6, y + 15);
		line(x + 7, y + 7, x + 7, y + 9);
		line(x + 8, y + 8, x + 8, y + 9);
		line(x + 9, y + 9, x + 9, y + 9);
		setcolor(RGB000000);
		line(x - 1, y - 1, x - 1, y + 14);
		line(x - 1, y + 14, x + 3, y + 11);
		line(x + 3, y + 11, x + 3, y + 12);
		line(x + 3, y + 12, x + 4, y + 13);
		line(x + 4, y + 13, x + 4, y + 14);
		line(x + 4, y + 14, x + 7, y + 17);
		line(x + 7, y + 17, x + 7, y + 13);
		line(x + 7, y + 13, x + 6, y + 12);
		line(x + 6, y + 12, x + 6, y + 11);
		line(x + 6, y + 11, x + 5, y + 10);
		line(x + 5, y + 10, x + 11, y + 10);
		line(x + 11, y + 10, x - 1, y - 2);
	}
	break;
	}
}

/***************************************
FUNCTION: mread
DESCRIPTION: 获取新的寄存器信息
INPUT: nx,ny,nbuttons
RETURN: 无
****************************************/
void mread(int *nx, int *ny, int *nbuttons)
{
	regs.x.ax = 3;			   //设置成读取鼠标状态
	int86(0x33, &regs, &regs); //读取
	*nx = regs.x.cx;		   //横坐标
	*ny = regs.x.dx;		   //纵坐标
	*nbuttons = regs.x.bx;	   //按键状态，位0，位1，位2依次是左键，右键，中键，1为按下
}

/*******************************************
FUNCTION: newmouse
DESCRIPTION: 鼠标状态发生变化则更新鼠标
INPUT: nx,ny,nbuttons
RETURN: 无
********************************************/
void newmouse(int *nx, int *ny, int *nbuttons)
{
	int xn, yn, buttonsn;
	int x0 = *nx, y0 = *ny /* , buttons0 = *nbuttons */;
	mread(&xn, &yn, &buttonsn); //读取值
	*nx = xn;					//赋新值
	*ny = yn;					//这时候把几个全局变量都赋上位置值了
	*nbuttons = buttonsn;
	// if (buttons0 == *nbuttons) //啥？没看懂
	//  	*nbuttons = 0;		   //开发者说：使得能连续按键
	if (xn == x0 && yn == y0 /*&& buttonsn == buttons0*/)
		return; //鼠标状态不变则直接返回S
	/*说明鼠标状态发生了改变*/
	clrmous(x0, y0);	   //清除鼠标
	save_bk_mou(*nx, *ny); //保存背景
	drawmous(*nx, *ny);	   //画鼠标
}

void save_bk_mou(int nx, int ny) //存鼠标背景
{
	int size;
	int x_, y_;
	x_ = nx + 11;
	y_ = ny + 17;
	/*加入判断函数*/
	judgemousbk(&x_, &y_);

	size = imagesize(nx - 1, ny - 2, x_, y_); //读大小
	buffer = malloc(size);
	if (buffer != NULL)							  //如果buffer不是空指针
		getimage(nx - 1, ny - 2, x_, y_, buffer); //存背景
	else										  //如果是空指针
	{
		pop_error(-1, "save_bk_mou", "Mouse save background Error.");
	}
}

void clrmous(int nx, int ny) //清除鼠标
{
	if (mflag == 1)
	{
		setwritemode(XOR_PUT);						//图像和原有像素作异或运算，有效地擦除该图像，留下原始屏幕
		mouse(nx, ny);								//画(擦除)鼠标
		putimage(nx - 1, ny - 2, buffer, COPY_PUT); //放图，取代原有像素
		free(buffer);								//清除背景缓存
		buffer = NULL;
		freebuffer();
		mflag = 0;				//没鼠标了
		setwritemode(COPY_PUT); //把绘制方式改成缺省模式
	}
}
void drawmous(int nx, int ny)
{
	if (mflag == 0) //在没鼠标的情况下
	{
		setwritemode(COPY_PUT); //给我画！
		mouse(nx, ny);
		mflag = 1;
	}
}

//如果在框中点击，则返回1；在框中未点击，则返回2；不在框中则返回0
//读者问：为啥不用中断去去现读Mouse位置？//前面调用一次了，没必要再来一遍
int mouse_press(int x1, int y1, int x2, int y2)
{
	//在框中点击，则返回1
	if (MouseX > x1 && MouseX < x2 && MouseY > y1 && MouseY < y2 && press == 1)
	{
		return 1;
	}

	//在框中未点击，则返回2
	else if (MouseX > x1 && MouseX < x2 && MouseY > y1 && MouseY < y2 && press == 0)
	{
		return 2;
	}

	//在框中点击右键，则返回3
	else if (MouseX > x1 && MouseX < x2 && MouseY > y1 && MouseY < y2 && press == 2)
	{
		return 3;
	}
	else //不加中键检测，差评
	{
		return 0;
	}
}

/*************************************
 * 以下为自设函数
 * *************************************/

/**************************
 * 判断函数，若鼠标在边界则改变保存图像区域
 * 传递参数：x, y(鼠标所在坐标)
 * 无返回值
 * *********************/
void judgemousbk(int *x_, int *y_)
{
	if (*x_ <= XMAX && *y_ <= YMAX)
		return;
	else
	{
		if (*x_ > XMAX)
		{
			*x_ = XMAX;
		}
		if (*y_ > YMAX)
		{
			*y_ = YMAX;
		}
	}
}

/*******************************
 * 保证指针的释放，没啥用的函数
 * *******************************/
void freebuffer(void)
{
	if (buffer != NULL)
		free(buffer);
}

/********************************
 * FUNCTION:refresh_mouse_display
 * DESCRIPTION:无条件刷新鼠标显示
 * INPUT:鼠标位置和按压状态
 * RETURN:无
 * OTHERS:调用前加上clrmous函数
 ********************************/
void refresh_mouse_display(int *mousex, int *mousey, int *m_press)
{
	mread(mousex, mousey, m_press); //读取新值
	save_bk_mou(*mousex, *mousey);	//保存背景
	drawmous(*mousex, *mousey);		//画鼠标
}