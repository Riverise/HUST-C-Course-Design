
#include "hz.h"

/********************************
 * FUNCTION:put12hz
 * DESCRIPTION:输出12*12的汉字
 * INPUT:左上角坐标x， y，字体间距（大于12），颜色
 * RETURN:无
 * OTHERS:无
 ********************************/
void put12hz(int x, int y, char *s, int part, int color)
{
	FILE *hzfp = NULL;				 //指针
	unsigned char areacode, bitcode; //区码，位码
	unsigned long offset;			 //偏移量
	int i, j, k;					 //循环辅助
	int y0;
	char sto[24]; // 24字节储存单字数据

	y0 = y;
	if ((hzfp = fopen("C:\\win_pro\\etc\\HZK\\HZK12", "rb")) == NULL)
	{
		pop_error(-1, "PUT12HZ:", "Can't open the file:", "C:\\win_pro\\etc\\HZK\\HZK12");
		exit(1);
	}
	while (*s != NULL)
	{
		/*读数据*/
		y = y0;
		areacode = s[0] - 0xa0;
		bitcode = s[1] - 0xa0;
		offset = (94 * (areacode - 1) + (bitcode - 1)) * 24L;
		fseek(hzfp, offset, SEEK_SET); //找到汉字位置，开始读取
		fread(sto, 24, 1, hzfp);	   //读取数据
		/*显示*/
		for (i = 0; i < 12; i++) //一列12个像素， 12个字节
		{
			for (j = 0; j < 2; j++) //一行16个像素, 2个字节
			{
				for (k = 0; k < 8; k++) //每个字节8位
				{
					if (getonebit(sto[2 * i + j], k + 1))
					{
						putpixel((x + 8 * j + k), y, color);
					}
				}
			}
			y++;
		} //显示完一个汉字
		/*准备检测下一个*/
		x = x + part;
		s += 2;
	}
	fclose(hzfp);
}