/**********************
 * 图标绘制
 * ***********************/
#ifndef _ICODR_H_

#define _ICODR_H_

#include "main.h"

/**********************
 * 图标大小常量
 * 为了保证文件可移植性
 * ********************/

#ifndef _SIZE_
#define _SIZE_

typedef char Size;

enum size_ico
{
	SMALL = 0,
	MIDDLE,
	BIG,
	SUPER
};

#endif

#define SIZE_MIDDLE 1
#define SIZE_BIG 2
#define SIZE_SUPER 4

/********************************
 * FUNCTION:filebasicdraw_o
 * DESCRIPTION:文件底板（白色矩形）绘制函数
 * INPUT:左上角坐标参数和大小
 * RETURN:无
 * OTHERS:无
 ********************************/
void filebasicdraw_o(int x, int y, Size size);
void filebasicdraw_o_o(int x, int y, int size);

/********************************
 * FUNCTION:txticodraw_o
 * DESCRIPTION:txt 绘制函数
 * INPUT:左上角坐标参数和大小
 * RETURN:无
 * OTHERS:无
 ********************************/
void txticodraw_o(int x, int y, Size size);
void txticodraw_o_o(int x, int y, int size_size);

/********************************
 * FUNCTION:photoicodraw_o
 * DESCRIPTION:photo(jpg,png)绘制函数
 * INPUT:左上角坐标参数和大小
 * RETURN:无
 * OTHERS:无
 ********************************/
void photoicodraw_o(int x, int y, Size size);
void photoicowrite(int x, int y, Size size);

/********************************
 * FUNCTION:cicodraw_o
 * DESCRIPTION:c文件绘制函数
 * INPUT:左上角坐标参数和大小
 * RETURN:无
 * OTHERS:无
 ********************************/
void cicodraw_o(int x, int y, Size size);
void cicowrite(int x, int y, Size size);

/********************************
 * FUNCTION:cppicodraw_o
 * DESCRIPTION:cpp文件图标绘制函数
 * INPUT:左上角坐标参数和大小
 * RETURN:无
 * OTHERS:无
 ********************************/
void cppicodraw_o(int x, int y, Size size);
/********************************
 * FUNCTION:ppicodraw_o_o
 * DESCRIPTION:画右上角的加加号
 * INPUT:指定坐标，相对大小
 * RETURN:无
 * OTHERS:相对大小为1，2，4，8
 ********************************/
void ppicodraw_o_o(int x, int y, int size_size);

/********************************
 * FUNCTION:hicodraw_o
 * DESCRIPTION:h文件图标绘制函数
 * INPUT:左上角坐标参数和大小
 * RETURN:无
 * OTHERS:无
 ********************************/
void hicodraw_o(int x, int y, Size size);
void hicowrite(int x, int y, Size size);

/********************************
 * FUNCTION:objicodraw_o
 * DESCRIPTION:obj文件图标绘制函数
 * INPUT:左上角坐标参数和大小
 * RETURN:无
 * OTHERS:无
 ********************************/
void objicodraw_o(int x, int y, Size size);
void objicowrite(int x, int y, Size size);

/********************************
 * FUNCTION:docicodraw_o
 * DESCRIPTION:doc文件图标绘制函数
 * INPUT:左上角坐标参数和大小
 * RETURN:无
 * OTHERS:无
 ********************************/
void docicodraw_o(int x, int y, Size size);
void docicodraw_o_o(int x, int y, int size);
void docicowrite(int x, int y, Size size);

/********************************
 * FUNCTION:xlsicodraw_o
 * DESCRIPTION:xls文件图标绘制函数
 * INPUT:左上角坐标参数和大小
 * RETURN:无
 * OTHERS:无
 ********************************/
void xlsicodraw_o(int x, int y, Size size);
void xlsicodraw_o_o(int x, int y, int size);
void xlsicowrite(int x, int y, Size size);

/********************************
 * FUNCTION:ppticodraw_o
 * DESCRIPTION:ppt文件绘制函数
 * INPUT:左上角坐标参数和大小
 * RETURN:无
 * OTHERS:无
 ********************************/
void ppticodraw_o(int x, int y, Size size);
void ppticodraw_o_o(int x, int y, int size);
void pptpicowrite(int x, int y, Size size);
void ppticowrite(int x, int y, Size size);

/********************************
 * FUNCTION:pdficodraw_o
 * DESCRIPTION:pdf文件绘制函数
 * INPUT:左上角坐标参数和大小
 * RETURN:无
 * OTHERS:无
 ********************************/
void pdficodraw_o(int x, int y, Size size);
void pdficowrite(int x, int y, Size size);

/********************************
 * FUNCTION:exeicodraw_o,exeicodraw_o_o
 * DESCRIPTION:exe文件图标绘制函数
 * INPUT:左上角坐标参数和大小
 * RETURN:无
 * OTHERS:无
 ********************************/
void exeicodraw_o(int x, int y, Size size);
void exeicodraw_o_o(int x, int y, Size size);

/********************************
 * FUNCTION:diricodraw_o,diricodraw_o_o
 * DESCRIPTION:文件夹图形绘制函数
 * INPUT:左上角横纵坐标、相对大小（倍率）
 * RETURN:无
 * OTHERS:无
 ********************************/
void diricodraw_o(int x, int y, Size size);
void diricodraw_o_o(int x, int y, int size_size);

/********************************
 * FUNCTION:diskicodraw_o,diskicodraw_o_o
 * DESCRIPTION:磁盘绘制函数
 * INPUT:输入左上角横纵坐标、相对大小（倍率）
 * RETURN:无
 * OTHERS:无
 ********************************/
void diskicodraw_o(int x, int y, Size size);
void diskicodraw_o_o(int x, int y, int size_size);

/********************************
 * FUNCTION:errorico_write
 * DESCRIPTION:写错误图标
 * INPUT:左上坐标
 * RETURN:无
 * OTHERS:无
 ********************************/
void errorico_write(int x, int y);

/********************************
 * FUNCTION:arningico_write
 * DESCRIPTION:写警告图标
 * INPUT:左上坐标
 * RETURN:无
 * OTHERS:无
 ********************************/
void warningico_write(int x, int y);

/********************************
 * FUNCTION:write_photodata
 * DESCRIPTION:写屏辅助函数，读取生成的图片数据并画图
 * INPUT:文件名（绝对路径），图片左上角坐标
 * RETURN:无
 * OTHERS:无
 ********************************/
void write_photodata(char *filename, int x, int y);

#endif