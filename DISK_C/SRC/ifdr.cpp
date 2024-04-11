/*******************************
 * ��windows��Դ���������������
 * *****************************/
#include "ifdr.h"

/********************
 * ���Ʊ�����
 * ��Ҫ���������������°����ȸ���Ŀ¼���л�����ʱ���䲿�֣�
 * �����룻
 * �ɹ���ͼ����1
 * *********************/
int drawbk(void)
{
	int x, y;
	setlinestyle(0, 0, 1);
	/*��䷽��*/
	setfillstyle(SOLID_FILL, RGBffffff);
	bar(0, 0, 0 + 1023, 0 + 1023); //����

	setfillstyle(SOLID_FILL, RGB007fff);
	bar(0, 0, 0 + 1023, 0 + 23); //����
	put12hz(10, 5, "��", 12, RGBffffff);
	setcolor(RGBffffff);
	outtextxy(10 + 12 + 2, 5 + 4, "Windows");
	put12hz(24 + 7 * 8 + 1, 5, "��Դ������", 12, RGBffffff);

	setfillstyle(SOLID_FILL, RGBfffbf0);
	bar(0, 24, 0 + 1023, 24 + 105); //�������͵׿�
	bar(0, 746, 0 + 1023, 746 + 21);

	setcolor(RGBa0a0a4);
	line(0, 130, 1023, 130); //�ֽ���
	line(209, 168, 209, 745);
	line(201, 24, 201, 129);
	line(378, 24, 378, 129);
	line(538, 24, 538, 129);
	line(619, 24, 619, 129);
	line(841, 24, 841, 129);

	put12hz(86, 116, "���а�", 13, RGB808080); //���ֲ���
	put12hz(274, 116, "��֯", 13, RGB808080);
	put12hz(449, 116, "�½�", 13, RGB808080);
	put12hz(568, 116, "��", 13, RGB808080);
	put12hz(719, 116, "ѡ��", 13, RGB808080);

	rectangle(132, 137, 817, 161); //��ַ��

	rectangle(817, 137, 841, 161); //ˢ�°���

	rectangle(848, 137, 1016, 161); //������

	circle(868, 146, 5); //�Ŵ󾵣�������
	line(865, 150, 858, 157);

	return 1;
}

/********************************
 * FUNCTION:display_listnodes
 * DESCRIPTION:���б���ϸ��Ϣ��ʾģʽ���˵���������ֵ��ı�
 * INPUT:��
 * RETURN:��
 * OTHERS:��
 ********************************/
void display_listnodes(void)
{
	put12hz(223, 168, "����", 13, RGB808080);
	put12hz(457, 168, "�޸�����", 13, RGB808080);
	put12hz(643, 168, "����", 13, RGB808080);
	put12hz(749, 168, "��С", 13, RGB808080);
}

/********************************
 * FUNCTION:changedisplay_fixedbt
 * DESCRIPTION:�̶�������ʵʱˢ����ʾ����
 * INPUT:�����û�ͼ�������������ƺ���������Ӧ���ƺ���ȱʡ������ɫ������������ɫ�������߿���ɫ��state״̬��ַ��
 * RETURN:��
 * OTHERS:ͨ�����ò�ͬ����������ָ�룩ʵ�ֱ�����ɫ��ת�䣬����������ɫ�����״̬
 *
 * ��ע�����state�����ظ��ã���Ȼ�ڴ���
 * 3/23�����ǻ��������ֻ��һ��steat���ظ��ػ�Ҳ���ڴ����	��ʱȷ���Ǻ�����������⣬û�г���ͷ��ڴ档
 * ��ע����Ϊmlrmous��mflag�����0����mflagֻ��1��ʱ������У�������ѭ����nem_mouse��bufferû���ͷţ�ͬһ��ָ����������ڴ棬����ʹ���ڴ����
 * �������޸�mouse.h�ļ���ʹ��buffer�Ƿ��ͷ�Ҳ���������
 ********************************/
void changedisplay_fixedbt(void (*drawfunc)(int bkcolor, int bordercolor),
						   int defbkcolor, int excbkcolor, int excbordercolor, State *state)
{
	if (getonebit(*state, IFH_L) != getonebit(*state, IFH_N)) //״̬�ı䣬�ػ�һ��
	{
		/*��ʱӦ�ñ�����걳����¼���ͺ�����*/
		clrmous(MouseX, MouseY);	  //�����꣬ʹ�û��ƺ󱣴汳��ʱ�������������뱳�����������Ӱ��
		if (getonebit(*state, IFH_N)) //����������
		{
			drawfunc(excbkcolor, excbordercolor);
		}
		else //��������
		{
			drawfunc(defbkcolor, defbkcolor);
		}
	}
	else //״̬���ı䣬����
	{
		if (getonebit(*state, IFD_1) == 0) //û��ʾ��
		{
			drawfunc(defbkcolor, defbkcolor);
			set1onebit(state, IFD_1);
		}
	}
}

void changedisplay_fixedbt(void (*drawfunc)(int bkcolor), int defbkcolor, int excbkcolor, State *state)
{
	if (getonebit(*state, IFH_L) != getonebit(*state, IFH_N)) //״̬�ı䣬�ػ�һ��
	{
		/*��ʱӦ�ñ�����걳����¼���ͺ�����*/
		clrmous(MouseX, MouseY);	  //�����꣬ʹ�û��ƺ󱣴汳��ʱ�������������뱳�����������Ӱ��
		if (getonebit(*state, IFH_N)) //����������
		{
			drawfunc(excbkcolor);
		}
		else //��������
		{
			drawfunc(defbkcolor);
		}
	}
	else //״̬���ı䣬����
	{
		if (getonebit(*state, IFD_1) == 0) //û��ʾ��
		{
			drawfunc(defbkcolor);
			set1onebit(state, IFD_1);
		}
	}
}
/********************************
 * FUNCTION:changedisplay_function
 * DESCRIPTION:�� ����������ʵʱˢ����ʾ���Ƿ���ʾ�������ı䣩����
 * INPUT:�����û�ͼ�������������ƺ���������Ӧ���ƺ���ȱʡ����������ɫ������������ɫ�������߿���ɫ��state״̬��ַ��
 * RETURN:��
 * OTHERS:ͨ�����ò�ͬ����������ָ�룩ʵ���ж���ʾ״̬��������ɫ��ת�䣬����������ɫ�����״̬
 ********************************/
void changedisplay_function(void (*drawfunc)(int bkcolor, int bordercolor, State state),
							int defbkcolor, int excbkcolor, int excbordercolor, State *state)
{
	if (getonebit(*state, IFP_N) == 0)
	{
		if (getonebit(*state, IFD_1) == 0) //û����ʾ����ɫͼ��
		{
			clrmous(MouseX, MouseY);
			drawfunc(defbkcolor, defbkcolor, *state);
			set1onebit(state, IFD_1);
		}
		//��ʾ����ɫͼ��
	}
	else //���Ե���Ĳ�ɫͼ��
	{
		if (getonebit(*state, IFH_L) != getonebit(*state, IFH_N)) //״̬�ı�
		{
			clrmous(MouseX, MouseY);
			if (getonebit(*state, IFH_N)) //����������
			{
				drawfunc(excbkcolor, excbordercolor, *state);
			}
			else //��������
			{
				drawfunc(defbkcolor, defbkcolor, *state);
			}
		}
		else //״̬����
		{
			if (getonebit(*state, IFD_1) == 0) //û��ʾ��
			{
				drawfunc(defbkcolor, defbkcolor, *state);
				set1onebit(state, IFD_1);
			}
		}
	}
}
void changedisplay_function(void (*drawfunc)(int bkcolor, State state), int defbkcolor, int excbkcolor, State *state)
{
	if (getonebit(*state, IFP_N) == 0)
	{
		if (getonebit(*state, IFD_1) == 0) //û����ʾ����ɫͼ��
		{
			clrmous(MouseX, MouseY);
			drawfunc(defbkcolor, *state);
			set1onebit(state, IFD_1);
		}
		//��ʾ����ɫͼ��
	}
	else //���Ե���Ĳ�ɫͼ��
	{
		if (getonebit(*state, IFH_L) != getonebit(*state, IFH_N)) //״̬�ı�
		{
			clrmous(MouseX, MouseY);
			if (getonebit(*state, IFH_N)) //����������
			{
				drawfunc(excbkcolor, *state);
			}
			else //��������
			{
				drawfunc(defbkcolor, *state);
			}
		}
		else //״̬����
		{
			if (getonebit(*state, IFD_1) == 0) //û��ʾ��
			{
				drawfunc(defbkcolor, *state);
				set1onebit(state, IFD_1);
			}
		}
	}
}

/********************************
 * FUNCTION:changedisplay_chfixedbt
 * DESCRIPTION:�ر�ģ�ָ���½��������̶�������ʵʱˢ����ʾ����
 * INPUT:�����û�ͼ�������������ƺ���������Ӧ���ƺ���ȱʡ����������ɫ������������ɫ�������߿���ɫ��state״̬��ַ��
 * RETURN:��
 * OTHERS:ͨ�����ò�ͬ����������ָ�룩ʵ���ж���ʾ״̬��������ɫ��ת�䣬����������ɫ�����״̬
 ********************************/
void changedisplay_chfixedbt(void (*drawfunc)(int bkcolor, int bordercolor, State state),
							 int defbkcolor, int excbkcolor, int excbordercolor, State *state)
{
	if (getonebit(*state, IFC_N) == 1) //�Ѿ���ѡ����
	{
		if (getonebit(*state, IFD_1) == 0) //û��ʾ������ʾһ�Σ���Ҫ�ǳ�ʼ������
		{
			drawfunc(excbkcolor, excbordercolor, *state);
			set1onebit(state, IFD_1);
		}
		else //�Ѿ���ʾ��һ��
		{
			if (getonebit(*state, IFC_L) == 0) //ѡ��״̬�ı��ˣ�Ҫ��ʾ
			{
				clrmous(MouseX, MouseY);
				drawfunc(excbkcolor, excbordercolor, *state);
				set1onebit(state, IFC_L);
			}
			//Īˢ��
		}
	}
	else //���Ե���Ĳ�ɫͼ��
	{
		if (getonebit(*state, IFH_L) != getonebit(*state, IFH_N)) //״̬�ı�
		{
			clrmous(MouseX, MouseY);
			if (getonebit(*state, IFH_N)) //����������
			{
				drawfunc(excbkcolor, excbordercolor, *state);
			}
			else //��������
			{
				drawfunc(defbkcolor, defbkcolor, *state);
			}
		}
		else //״̬����
		{
			if (getonebit(*state, IFD_1) == 0) //û��ʾ��
			{
				drawfunc(defbkcolor, defbkcolor, *state);
				set1onebit(state, IFD_1);
			}
			else
			{
				if (getonebit(*state, IFC_L) == 1) //ѡ��״̬�ı�
				{
					clrmous(MouseX, MouseY);
					drawfunc(defbkcolor, defbkcolor, *state);
					set0onebit(state, IFC_L);
				}
				//��ֹˢ��
			}
		}
	}
}

/***********************
 * �رղ����ƣ�
 * ���ݲ�������ͷ��ɫ��
 * �޷���
 * ***********************/
void closeXdraw_o(int bkcolor)
{
	setfillstyle(SOLID_FILL, bkcolor);
	bar(988, 0, 1023, 23);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(RGBffffff);
	line(999, 6, 1011, 18); //�رղ��
	line(999, 18, 1011, 6);
	line(999, 6 + 1, 1011, 18 + 1); //�Ӵ�
	line(999, 18 + 1, 1011, 6 + 1);
	/* û�б߿� */
}

/********************************
 * FUNCTION:
 * DESCRIPTION:
 * INPUT:
 * RETURN:
 * OTHERS:
 ********************************/
void downarrow_draw(int icocolor, State state)
{
	if (getonebit(state, IFP_N) == 0) //��ɫͼ�����
	{
		downarrow_draw_o(RGBa0a0a4);
	}
	else
	{
		downarrow_draw_o(icocolor);
	}
}
void downarrow_draw_o(int icocolor)
{
	/*������ͷ*/
	setcolor(icocolor);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	moveto(89 - 1, 148); //������ͷ
	lineto(92 - 1, 151);
	lineto(95 - 1, 148);
	moveto(90 - 1, 148); //�Ӵ�
	lineto(93 - 1, 151);
	lineto(96 - 1, 148);
}

/********************************
 * FUNCTION:larrowdraw_b
 * DESCRIPTION:�Ժ��˼�ͷ�Ļ��ƺͷ�Ӧ
 * INPUT:��ɫ���ڶ���û���ã�Ϊ�˱��ֺ���ָ����ò���һ�£�������״̬
 * RETURN:��
 * OTHERS:���ϽǺ��˻���
 ********************************/
void larrowdraw_b(int icocolor, State state)
{
	if (getonebit(state, IFP_N) == 0) //��ɫͼ�����
	{
		larrowdraw_o(RGBa0a0a4, 27, 149);
	}
	else
	{
		larrowdraw_o(icocolor, 27, 149);
	}
}
/********************************
 * FUNCTION:larrowdraw_main_npg
 * DESCRIPTION:���ļ�����һҳ��ͷ
 * INPUT:��ɫ���ڶ���û���ã�Ϊ�˱��ֺ���ָ����ò���һ�£�������״̬
 * RETURN:��
 * OTHERS:��
 ********************************/
void larrowdraw_main_lpg(int icocolor, State state)
{
	if (getonebit(state, IFP_N) == 0) //��ɫͼ�����
	{
		larrowdraw_o(RGBa0a0a4, 935, 756);
	}
	else
	{
		larrowdraw_o(icocolor, 935, 756);
	}
}

/********************************
 * FUNCTION:larrowdraw_tree_npg
 * DESCRIPTION:�����ļ�����һҳ��ͷ
 * INPUT:��ɫ���ڶ���û���ã�Ϊ�˱��ֺ���ָ����ò���һ�£�������״̬
 * RETURN:��
 * OTHERS:��
 ********************************/
void larrowdraw_tree_lpg(int icocolor, State state)
{
	if (getonebit(state, IFP_N) == 0) //��ɫͼ�����
	{
		larrowdraw_o(RGBa0a0a4, 28, 756);
	}
	else
	{
		larrowdraw_o(icocolor, 28, 756);
	}
}

/********************************
 * FUNCTION:larrowdraw_o
 * DESCRIPTION:���ͷ���ơ�
 * INPUT:��ɫ������
 * RETURN:��
 * OTHERS:��
 ********************************/
void larrowdraw_o(int icocolor, int x, int y)
{
	setcolor(icocolor);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	moveto(x, y); //���ͷ
	lineto(x - 18, y);
	lineto(x - 12, y - 6);
	moveto(x - 12, y + 6);
	lineto(x - 18, y);
	moveto(x, y - 1); //�Ӵ�
	lineto(x - 18, y - 1);
	lineto(x - 12, y - 7);
	moveto(x - 12, y + 6 - 1);
	lineto(x - 18, y - 1);
	/* ���ͷֻ�øı��ͷ��ɫ��û�б����ͱ߿�ĸı� */
}

/********************************
 * FUNCTION:rarrowdraw_f
 * DESCRIPTION:��ǰ����ͷ�Ļ��ƺͷ�Ӧ
 * INPUT:��ɫ���ڶ���û���ã�Ϊ�˱��ֺ���ָ����ò���һ�£�������״̬
 * RETURN:��
 * OTHERS:���Ͻ�ǰ������
 ********************************/
void rarrowdraw_f(int icocolor, State state)
{
	if (getonebit(state, IFP_N) == 0) //��ɫͼ�����
	{
		rarrowdraw_o(RGBa0a0a4, 59, 149);
	}
	else
	{
		rarrowdraw_o(icocolor, 59, 149);
	}
}
/********************************
 * FUNCTION:rarrowdraw_main_npg
 * DESCRIPTION:���ļ�����һҳ
 * INPUT:��ɫ���ڶ���û���ã�Ϊ�˱��ֺ���ָ����ò���һ�£�������״̬
 * RETURN:��
 * OTHERS:��
 ********************************/
void rarrowdraw_main_npg(int icocolor, State state)
{
	if (getonebit(state, IFP_N) == 0) //��ɫͼ�����
	{
		rarrowdraw_o(RGBa0a0a4, 943, 756);
	}
	else
	{
		rarrowdraw_o(icocolor, 943, 756);
	}
}

/********************************
 * FUNCTION:rarrowdraw_tree_npg
 * DESCRIPTION:�����ļ�����һҳ
 * INPUT:��ɫ���ڶ���û���ã�Ϊ�˱��ֺ���ָ����ò���һ�£�������״̬
 * RETURN:��
 * OTHERS:��
 ********************************/
void rarrowdraw_tree_npg(int icocolor, State state)
{
	if (getonebit(state, IFP_N) == 0) //��ɫͼ�����
	{
		rarrowdraw_o(RGBa0a0a4, 36, 756);
	}
	else
	{
		rarrowdraw_o(icocolor, 36, 756);
	}
}

/********************************
 * FUNCTION:rarrowdraw_o
 * DESCRIPTION:�����Ҽ�ͷ����
 * INPUT:��ɫ������
 * RETURN:��
 * OTHERS:��
 ********************************/
void rarrowdraw_o(int icocolor, int x, int y)
{
	setcolor(icocolor);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	moveto(x, y); //�Ҽ�ͷ
	lineto(x + 19, y);
	lineto(x + 13, y - 6);
	moveto(x + 13, y + 6);
	lineto(x + 19, y);
	moveto(x, y - 1); //�Ӵ�
	lineto(x + 19, y - 1);
	lineto(x + 13, y - 6 - 1);
	moveto(x + 13, y + 6 - 1);
	lineto(x + 19, y - 1);
	/* �Ҽ�ͷֻ�øı��ͷ��ɫ��û�б����ͱ߿�ĸı� */
}

/*******************
 * �ϼ�ͷ����
 * ���ݲ�����������ɫ���߿���ɫ
 * �޷���ֵ
 * ��ע����ͷ����û�б߿򣬹���һ������û������
 * *****************/
void uparrowdraw(int bkcolor, State state)
{
	if (getonebit(state, IFP_N) == 0) //��ɫͼ�����
	{
		setfillstyle(SOLID_FILL, bkcolor);
		bar(100, 139, 123, 160);
		uparrowdraw_o(RGBa0a0a4);
	}
	else
	{
		setfillstyle(SOLID_FILL, bkcolor);
		bar(100, 139, 123, 160);
		uparrowdraw_o(RGB808080);
		/* ��ͷ��ɫ�ޱ߿� */
	}
}
void uparrowdraw_o(int bordercolor)
{
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(bordercolor);
	moveto(103, 149); //�ϼ�ͷ
	lineto(111, 141);
	lineto(119, 149);
	moveto(111, 158);
	lineto(111, 141);
	moveto(103 + 1, 149); //�Ӵ�
	lineto(111 + 1, 141);
	lineto(119 + 1, 149);
	moveto(111 + 1, 158);
	lineto(111 + 1, 141);
}

/***********************************
 * ˢ��ͼ�����
 * ���ݲ���������ɫ���߿�ɫ
 * �޷���ֵ
 * ***********************************/
void refreshicodraw_o(int bkcolor, int bordercolor)
{
	setfillstyle(SOLID_FILL, bkcolor);
	bar(817, 137, 841, 161);

	setlinestyle(SOLID_LINE, 0, THICK_WIDTH); //ˢ�·���
	setcolor(RGBa0a0a4);
	circle(829, 149, 6);
	moveto(828, 149);
	lineto(828, 146);
	lineto(823 - 2, 144);
	setcolor(bkcolor);
	line(830 + 1, 141, 830 + 1, 148);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	line(831 + 1, 146 - 1, 834, 143);
	putpixel(824 - 2, 146, bkcolor);

	if (bordercolor != bkcolor)
	{
		setcolor(bordercolor);
		rectangle(817, 137, 841, 161);
	}
	else
	{
		setcolor(RGBa0a0a4);
		rectangle(817, 137, 841, 161);
	}
}

/*************************
 * ���½���ť����
 * ���ݲ����������װ���ɫ���߿���ɫ
 * �޷���ֵ
 * ************************/
void listdisplay_draw(int bkcolor, int bordercolor, State state)
{
	if (getonebit(state, IFC_N) == 1) //�˴������Ƿ�ѡ�У���ʱΪѡ��
	{
		listdisplay_draw_o(RGBccffff, RGB2a7fff);
	}
	else
	{
		listdisplay_draw_o(bkcolor, bordercolor);
	}
}
void listdisplay_draw_o(int bkcolor, int bordercolor)
{
	setfillstyle(SOLID_FILL, bkcolor);
	bar(973, 746, 994, 767);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(RGBa0a0a4); //���½���ť���ڴ�����ʾ�ļ������Ϣ
	rectangle(977, 751, 980, 763);
	line(977, 760, 980, 760);
	line(977, 757, 980, 757);
	line(977, 754, 980, 754);
	line(983, 752, 991, 752);
	line(983, 755, 991, 755);
	line(983, 758, 991, 758);
	line(983, 761, 991, 761);
	setcolor(bkcolor);
	line(987, 752, 987, 761);
	setcolor(RGB2a5fff);
	rectangle(978, 752, 979, 753);
	setcolor(RGBd45f00);
	rectangle(978, 755, 979, 756);
	setcolor(RGBd40000);
	rectangle(978, 758, 979, 759);
	setcolor(RGB559f00);
	rectangle(978, 761, 979, 762);
	if (bordercolor != bkcolor) //�����ݵı߿���ɫ�뱳����ɫ��ͬ�����
	{
		setcolor(bordercolor);
		rectangle(973, 746, 994, 767);
	}
}

/*************************
 * ���½��Ұ�ť����
 * ���ݲ����������װ���ɫ���߿���ɫ
 * �޷���ֵ
 * ************************/
void icondisplay_draw(int bkcolor, int bordercolor, State state)
{
	if (getonebit(state, IFC_N) == 1) //�˴������Ƿ�ѡ�У���ʱΪѡ��
	{
		icondisplay_draw_o(RGBccffff, RGB2a7fff);
	}
	else
	{
		icondisplay_draw_o(bkcolor, bordercolor);
	}
}
void icondisplay_draw_o(int bkcolor, int bordercolor)
{
	setfillstyle(SOLID_FILL, bkcolor);
	bar(995, 746, 1016, 767);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(RGBa0a0a4); //���½��Ұ�ť��ʹ�ô�����ͼ��ʾ��,����д����
	rectangle(997, 752, 1014, 762);
	setcolor(RGBffffff);
	rectangle(997 + 1, 752 + 1, 1014 - 1, 762 - 1);
	icondisplaywrite();
	if (bordercolor != bkcolor) //�����ݵı߿���ɫ�뱳����ɫ��ͬ�����
	{
		setcolor(bordercolor);
		rectangle(995, 746, 1016, 767);
	}
}
void icondisplaywrite(void)
{
	int x, y;
	x = 999;
	y = 754;
	putpixel(x++, y, RGB2a7fff);
	putpixel(x++, y, RGB2a7fff);
	putpixel(x++, y, RGB7fbfff);
	putpixel(x++, y, RGBaabfff);
	putpixel(x++, y, RGB7fbfff);
	putpixel(x++, y, RGB7fbfff);
	putpixel(x++, y, RGB559fff);
	putpixel(x++, y, RGBaabfff);
	putpixel(x++, y, RGBd4dfff);
	putpixel(x++, y, RGBd4dfff);
	putpixel(x++, y, RGBd4dfff);
	putpixel(x++, y, RGBd4dfff);
	putpixel(x++, y, RGBd4dfff);
	putpixel(x++, y, RGB7fbfff);
	x = 999;
	y++;
	putpixel(x++, y, RGB2a7fff);
	putpixel(x++, y, RGB2a7fff);
	putpixel(x++, y, RGBaabfff);
	putpixel(x++, y, RGB7fbfff);
	putpixel(x++, y, RGB7fbfff);
	putpixel(x++, y, RGBaabfff);
	putpixel(x++, y, RGBd4dfff);
	putpixel(x++, y, RGBd4dfff);
	putpixel(x++, y, RGBd4dfff);
	putpixel(x++, y, RGBd4dfff);
	putpixel(x++, y, RGBd4dfff);
	putpixel(x++, y, RGBffffff);
	putpixel(x++, y, RGB7fbfff);
	putpixel(x++, y, RGB7fbfff);
	x = 999;
	y++;
	putpixel(x++, y, RGB2a7fff);
	putpixel(x++, y, RGB008080);
	putpixel(x++, y, RGB2a9faa);
	putpixel(x++, y, RGB008080);
	putpixel(x++, y, RGB2a7faa);
	putpixel(x++, y, RGB2a7fff);
	putpixel(x++, y, RGB2a7fff);
	putpixel(x++, y, RGB2a7fff);
	putpixel(x++, y, RGB2a7fff);
	putpixel(x++, y, RGB2a7fff);
	putpixel(x++, y, RGB2a7fff);
	putpixel(x++, y, RGB2a7fff);
	putpixel(x++, y, RGB7fbfff);
	putpixel(x++, y, RGBaabfff);
	x = 999;
	y++;
	putpixel(x++, y, RGB2a7faa);
	putpixel(x++, y, RGB009f55);
	putpixel(x++, y, RGB007f55);
	putpixel(x++, y, RGB2a9f55);
	putpixel(x++, y, RGB009f55);
	putpixel(x++, y, RGB2a7faa);
	putpixel(x++, y, RGB2a7fff);
	putpixel(x++, y, RGB2a7fff);
	putpixel(x++, y, RGB2a7fff);
	putpixel(x++, y, RGB2a7fff);
	putpixel(x++, y, RGB2a7fff);
	putpixel(x++, y, RGB2a7fff);
	putpixel(x++, y, RGB2a7fff);
	putpixel(x++, y, RGB2a7fff);
	x = 999;
	y++;
	putpixel(x++, y, RGB2a9faa);
	putpixel(x++, y, RGB008080);
	putpixel(x++, y, RGB2a9f55);
	putpixel(x++, y, RGB008080);
	putpixel(x++, y, RGB008080);
	putpixel(x++, y, RGB008080);
	putpixel(x++, y, RGB559faa);
	putpixel(x++, y, RGB7f9fff);
	putpixel(x++, y, RGB559fff);
	putpixel(x++, y, RGB559fff);
	putpixel(x++, y, RGB559fff);
	putpixel(x++, y, RGB559fff);
	putpixel(x++, y, RGB559fff);
	putpixel(x++, y, RGB559fff);
	x = 999;
	y++;
	putpixel(x++, y, RGB2a7faa);
	putpixel(x++, y, RGB008080);
	putpixel(x++, y, RGB2a9faa);
	putpixel(x++, y, RGB008080);
	putpixel(x++, y, RGBa6caf0);
	putpixel(x++, y, RGBd4ffff);
	putpixel(x++, y, RGBd4ffff);
	putpixel(x++, y, RGBffffff);
	putpixel(x++, y, RGBd4dfff);
	putpixel(x++, y, RGBccccff);
	putpixel(x++, y, RGBaadfff);
	putpixel(x++, y, RGBccccff);
	putpixel(x++, y, RGBaadfff);
	putpixel(x++, y, RGBccccff);
	x = 999;
	y++;
	putpixel(x++, y, RGB2a7faa);
	putpixel(x++, y, RGB008080);
	putpixel(x++, y, RGB2a9faa);
	putpixel(x++, y, RGB008080);
	putpixel(x++, y, RGB2a7faa);
	putpixel(x++, y, RGBffffff);
	putpixel(x++, y, RGBffffff);
	putpixel(x++, y, RGBccccff);
	putpixel(x++, y, RGBd4dfff);
	putpixel(x++, y, RGBd4dfff);
	putpixel(x++, y, RGBd4dfff);
	putpixel(x++, y, RGBd4dfff);
	putpixel(x++, y, RGBd4dfff);
	putpixel(x++, y, RGBd4dfff);
}

/***************************************
 * ��������������
 * ***************************************/

/*******************************
 * ���ư��� ����
 * ���ݲ�����������ɫ���߿���ɫ��״̬�����Ƿ���Ե����
 * �޷���ֵ
 * *****************************/
void copybtn_draw(int bkcolor, int bordercolor, State state)
{
	if (getonebit(state, IFP_N) == 0) //��ɫͼ�����
	{
		setfillstyle(SOLID_FILL, bkcolor);
		bar(9, 31, 71, 111);
		copybtn_draw_o(RGBd4dfff, RGBa0a0a4, RGBa0a0a4, RGB808080);
	}
	else
	{
		setfillstyle(SOLID_FILL, bkcolor);
		bar(9, 31, 71, 111);
		copybtn_draw_o(RGBffffff, RGB808080, RGB559fff, RGB000000);
		if (bkcolor != bordercolor)
		{
			setcolor(bordercolor);
			rectangle(9, 31, 71, 111);
		}
	}
}
void copybtn_draw_o(int bkcolor, int bordercolor, int linecolor, int textcolor)
{
	int y, i; //ѭ��
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(bordercolor);
	moveto(56, 55);
	lineto(50, 49);
	lineto(50, 55);
	lineto(56, 55);
	lineto(56, 79);
	lineto(33, 79);
	lineto(33, 49);
	lineto(50, 49);
	moveto(47, 42);
	lineto(41, 36);
	lineto(41, 42);
	lineto(47, 42);
	lineto(47, 48);
	moveto(32, 66);
	lineto(24, 66);
	lineto(24, 36);
	lineto(40, 36);
	setfillstyle(SOLID_FILL, bkcolor);
	floodfill(38, 52, bordercolor);
	floodfill(40, 46, bordercolor);
	floodfill(43, 40, bordercolor);
	floodfill(52, 53, bordercolor);
	setcolor(linecolor);
	y = 53;
	for (i = 0; i < 2; i++)
	{
		line(36, y, 46, y);
		y += 3;
	}
	for (i = 0; i < 6; i++)
	{
		line(36, y, 53, y);
		y += 3;
	}
	y = 40;
	for (i = 0; i < 2; i++)
	{
		line(27, y, 37, y);
		y += 3;
	}
	line(27, y, 44, y);
	y += 3;
	for (i = 0; i < 5; i++)
	{
		line(27, y, 33, y);
		y += 3;
	}
	put12hz(29, 88, "����", 13, textcolor);
}

/*****************************
 * ճ������ ����
 * ���ݲ�����������ɫ���߿���ɫ��״̬�����Ƿ���Ե����
 * �޷���ֵ
 * *****************************/
void pastebtn_draw(int bkcolor, int bordercolor, State state)
{
	if (getonebit(state, IFP_N) == 0) //��ɫͼ�����
	{
		setfillstyle(SOLID_FILL, bkcolor);
		bar(72, 31, 131, 111);
		pastebtn_draw_o(RGBd4dfff, RGB7f7faa, RGBa0a0a4, RGBa0a0a4, RGB808080);
	}
	else
	{
		setfillstyle(SOLID_FILL, bkcolor);
		bar(72, 31, 131, 111);
		pastebtn_draw_o(RGBffffff, RGB7f5f00, RGBa6caf0, RGBaa9faa, RGB000000);
		if (bkcolor != bordercolor)
		{
			setcolor(bordercolor);
			rectangle(72, 31, 131, 111);
		}
	}
}
void pastebtn_draw_o(int bkcolor, int bordercolor, int linecolor,
					 int trianglecolor, int textcolor)
{
	int y;
	int i;
	int peaks[] = {101, 35, 92, 44, 111, 44, 102, 35};
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	setcolor(bordercolor);
	rectangle(88, 42, 115, 79);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(SOLID_FILL, bkcolor);
	floodfill(101, 47, bordercolor);
	setcolor(trianglecolor);
	drawpoly(4, peaks);
	setfillstyle(SOLID_FILL, trianglecolor);
	floodfill(102, 40, trianglecolor);
	setcolor(linecolor);
	y = 48;
	for (i = 0; i < 9; i++)
	{
		line(90, y, 112, y);
		y += 3;
	}
	put12hz(89, 88, "ճ��", 13, textcolor);
}

/************************************
 * ���а��� ����
 * ���ݲ�����������ɫ���߿���ɫ��״̬�����Ƿ���Ե����
 * �޷���ֵ
 * *****************************/
void cutbtn_draw(int bkcolor, int bordercolor, State state)
{
	if (getonebit(state, IFP_N) == 0) //��ɫͼ�����
	{
		setfillstyle(SOLID_FILL, bkcolor);
		bar(132, 31, 192, 111);
		cutbtn_draw_o(RGBa0a0a4, RGB555faa, RGB808080);
	}
	else
	{
		setfillstyle(SOLID_FILL, bkcolor);
		bar(132, 31, 192, 111);
		cutbtn_draw_o(RGBa0a0a4, RGB009fff, RGB000000);
		if (bkcolor != bordercolor)
		{
			setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
			setcolor(bordercolor);
			rectangle(132, 31, 192, 111);
		}
	}
}
void cutbtn_draw_o(int upcolor, int handlecolor, int textcolor)
{
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	setcolor(upcolor);
	moveto(151, 41);
	lineto(161, 60);
	moveto(162, 60);
	lineto(172, 41);
	setcolor(handlecolor);
	moveto(161, 61);
	lineto(148, 70);
	lineto(153, 79);
	lineto(161, 64);
	lineto(162, 59);
	moveto(161, 59);
	lineto(162, 64);
	lineto(171, 79);
	lineto(176, 72);
	lineto(162, 61);
	put12hz(151, 88, "����", 13, textcolor);
}

/*******************************
 * ɾ������ ����
 * ���ݲ�����������ɫ���߿���ɫ��״̬�����Ƿ���Ե����
 * �޷���ֵ
 * *****************************/
void deletebtn_draw(int bkcolor, int bordercolor, State state)
{
	if (getonebit(state, IFP_N) == 0) //��ɫͼ�����
	{
		setfillstyle(SOLID_FILL, bkcolor);
		bar(219, 31, 280, 111);
		deletebtn_draw_o(RGB7f7faa, RGB808080);
	}
	else
	{
		setfillstyle(SOLID_FILL, bkcolor);
		bar(219, 31, 280, 111);
		deletebtn_draw_o(RGBaa0000, RGB000000);
		if (bkcolor != bordercolor)
		{
			setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
			setcolor(bordercolor);
			rectangle(219, 31, 280, 111);
		}
	}
}
void deletebtn_draw_o(int btncolor, int textcolor)
{
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	setcolor(btncolor);
	line(232, 41, 267, 76);
	line(232, 76, 267, 41);
	put12hz(238, 88, "ɾ��", 13, textcolor);
}

/*****************************
 * ���������� ����
 * ���ݲ�����������ɫ���߿���ɫ��״̬�����Ƿ���Ե����
 * �޷���ֵ
 * *****************************/
void renamebtn_draw(int bkcolor, int bordercolor, State state)
{
	if (getonebit(state, IFP_N) == 0) //��ɫͼ�����
	{
		setfillstyle(SOLID_FILL, bkcolor);
		bar(281, 31, 361, 111);
		renamebtn_draw_o(RGBd4dfff, RGB7f7faa, RGB555faa, RGB808080);
	}
	else
	{
		setfillstyle(SOLID_FILL, bkcolor);
		bar(281, 31, 361, 111);
		renamebtn_draw_o(RGBffffff, RGB808080, RGB007fff, RGB000000);
		if (bkcolor != bordercolor)
		{
			setcolor(bordercolor);
			rectangle(281, 31, 361, 111);
		}
	}
}
void renamebtn_draw_o(int bkcolor, int linecolor, int squarecolor, int textcolor)
{
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(linecolor);
	rectangle(297, 50, 344, 70);
	setfillstyle(SOLID_FILL, bkcolor);
	floodfill(327, 58, linecolor);
	setfillstyle(SOLID_FILL, squarecolor);
	bar(303, 56, 322, 64);
	setfillstyle(SOLID_FILL, linecolor);
	bar(327, 40, 341, 42);
	bar(327, 78, 341, 80);
	bar(333, 43, 335, 77);
	put12hz(304, 88, "������", 13, textcolor);
}

/*******************************************
 * �½��ļ��а��� ����
 * ���ݲ�����������ɫ���߿���ɫ��״̬�����Ƿ���Ե����
 * �޷���ֵ
 * *****************************/
void newdirbtn_draw(int bkcolor, int bordercolor, State state)
{
	if (getonebit(state, IFP_N) == 0) //��ɫͼ�����
	{
		setfillstyle(SOLID_FILL, bkcolor);
		bar(395, 31, 456, 111);
		newdirbtn_draw_o(RGB7f7faa, RGB7f7faa, RGBccccff, RGB808080);
	}
	else
	{
		setfillstyle(SOLID_FILL, bkcolor);
		bar(395, 31, 456, 111);
		newdirbtn_draw_o(RGBffbf00, RGBffbf00, RGBffdf55, RGB000000);
		if (bkcolor != bordercolor)
		{
			setcolor(bordercolor);
			rectangle(395, 31, 456, 111);
		}
	}
}
void newdirbtn_draw_o(int linecolor, int behindbkcolor, int frontbkcolor, int textcolor)
{
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(linecolor);
	moveto(411, 34);
	lineto(420, 43);
	lineto(420, 68);
	lineto(417, 65);
	lineto(417, 79);
	lineto(411, 73);
	lineto(411, 34);
	lineto(435, 34);
	lineto(435, 56);
	lineto(438, 59);
	lineto(438, 72);
	lineto(418, 72);
	setfillstyle(SOLID_FILL, behindbkcolor);
	floodfill(427, 55, behindbkcolor);
	setfillstyle(SOLID_FILL, frontbkcolor);
	floodfill(415, 56, linecolor);
	put12hz(414, 84, "�½�", 13, textcolor);
	put12hz(408, 98, "�ļ���", 13, textcolor);
}

/********************************************
 * �½��ļ����� ����
 * ���ݲ�����������ɫ���߿���ɫ��״̬�����Ƿ���Ե����
 * �޷���ֵ
 * *****************************/
void newfilebtn_draw(int bkcolor, int bordercolor, State state)
{
	if (getonebit(state, IFP_N) == 0) //��ɫͼ�����
	{
		setfillstyle(SOLID_FILL, bkcolor);
		bar(457, 31, 519, 111);
		newfilebtn_draw_o(RGBa0a0a4, RGBd4dfff, RGB7f7faa, RGB808080);
	}
	else
	{
		setfillstyle(SOLID_FILL, bkcolor);
		bar(457, 31, 519, 111);
		newfilebtn_draw_o(RGB808080, RGBffffff, RGB5500ff, RGB000000);
		if (bkcolor != bordercolor)
		{
			setcolor(bordercolor);
			rectangle(457, 31, 519, 111);
		}
	}
}
void newfilebtn_draw_o(int bordercolor, int bkcolor, int addcolor, int textcolor)
{
	btnfilebasic_draw(470, 35, bordercolor, bkcolor);
	setfillstyle(SOLID_FILL, addcolor);
	bar(486, 70, 506, 72);
	bar(495, 61, 497, 81);
	put12hz(476, 84, "�½�", 13, textcolor);
	put12hz(476, 98, "�ļ�", 13, textcolor);
}
void btnfilebasic_draw(int x, int y, int bordercolor, int bkcolor)
{
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setcolor(bordercolor);
	moveto(x + 24, y);
	lineto(x + 31, y + 7);
	lineto(x + 31, y + 41);
	lineto(x, y + 41);
	lineto(x, y);
	lineto(x + 24, y);
	lineto(x + 24, y + 7);
	lineto(x + 31, y + 7);
	setfillstyle(SOLID_FILL, bkcolor);
	floodfill(x + 5, y + 5, bordercolor);
	floodfill(x + 25, y + 6, bordercolor);
}

/********************************************
 * ���԰��� ����
 * ���ݲ�����������ɫ���߿���ɫ��״̬�����Ƿ���Ե����
 * �޷���ֵ
 * *****************************/
void attributebtn_draw(int bkcolor, int bordercolor, State state)
{
	if (getonebit(state, IFP_N) == 0) //��ɫͼ�����
	{
		setfillstyle(SOLID_FILL, bkcolor);
		bar(548, 31, 609, 111);
		attributebtn_draw_o(RGBa0a0a4, RGBd4dfff, RGB7f7faa, RGB808080);
	}
	else
	{
		setfillstyle(SOLID_FILL, bkcolor);
		bar(548, 31, 609, 111);
		attributebtn_draw_o(RGB808080, RGBffffff, RGBd41f00, RGB000000);
		if (bkcolor != bordercolor)
		{
			setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
			setcolor(bordercolor);
			rectangle(548, 31, 609, 111);
		}
	}
}
void attributebtn_draw_o(int bordercolor, int bkcolor, int tickcolor, int textcolor)
{
	btnfilebasic_draw(564, 38, bordercolor, bkcolor);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	setcolor(tickcolor);
	moveto(568, 62);
	lineto(574, 68);
	lineto(590, 52);
	put12hz(568, 88, "����", 13, textcolor);
}

/*********************************************
 * ȫ��ѡ�а��� ����
 * ���ݲ�����������ɫ���߿���ɫ��״̬�����Ƿ���Ե����
 * �޷���ֵ
 * *****************************/
void challbtn_draw(int bkcolor, int bordercolor, State state)
{
	if (getonebit(state, IFP_N) == 0) //��ɫͼ�����
	{
		setfillstyle(SOLID_FILL, bkcolor);
		bar(635, 31, 698, 111);
		challbtn_draw_o(RGB7f7faa, RGBffffff, RGBaabfff, RGB808080);
	}
	else
	{
		setfillstyle(SOLID_FILL, bkcolor);
		bar(635, 31, 698, 111);
		challbtn_draw_o(RGB2a7fff, RGBffffff, RGB2adfff, RGB000000);
		if (bkcolor != bordercolor)
		{
			setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
			setcolor(bordercolor);
			rectangle(635, 31, 698, 111);
		}
	}
}
void challbtn_draw_o(int bordercolor, int bkcolor, int incolor, int textcolor)
{
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(SOLID_FILL, bkcolor);
	bar(644, 39, 686, 81);
	setcolor(bordercolor);
	rectangle(644, 39, 664, 59);
	rectangle(666, 39, 686, 59);
	rectangle(644, 61, 664, 81);
	rectangle(666, 61, 686, 81);
	setfillstyle(SOLID_FILL, incolor);
	floodfill(646, 41, bordercolor);
	floodfill(668, 41, bordercolor);
	floodfill(646, 64, bordercolor);
	floodfill(668, 63, bordercolor);
	put12hz(643, 88, "ȫ��ѡ��", 13, textcolor);
}

/********************************************
 * ȫ��ȡ������ ����
 * ���ݲ�����������ɫ���߿���ɫ��״̬�����Ƿ���Ե����
 * �޷���ֵ
 * *****************************/
void cclallbtn_draw(int bkcolor, int bordercolor, State state)
{
	if (getonebit(state, IFP_N) == 0) //��ɫͼ�����
	{
		setfillstyle(SOLID_FILL, bkcolor);
		bar(699, 31, 763, 111);
		cclallbtn_draw_o(RGB7f7faa, RGBffffff, RGBccccff, RGB808080);
	}
	else
	{
		setfillstyle(SOLID_FILL, bkcolor);
		bar(699, 31, 763, 111);
		cclallbtn_draw_o(RGB808080, RGBffffff, RGBffffff, RGB000000);
		if (bkcolor != bordercolor)
		{
			setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
			setcolor(bordercolor);
			rectangle(699, 31, 763, 111);
		}
	}
}
void cclallbtn_draw_o(int bordercolor, int bkcolor, int incolor, int textcolor)
{
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(SOLID_FILL, bkcolor);
	bar(711, 42, 749, 79);
	setcolor(bordercolor);
	rectangle(711, 42, 729, 59);
	rectangle(731, 42, 749, 59);
	rectangle(711, 61, 729, 79);
	rectangle(731, 61, 749, 79);
	setfillstyle(SOLID_FILL, incolor);
	floodfill(713, 45, bordercolor);
	floodfill(733, 44, bordercolor);
	floodfill(713, 64, bordercolor);
	floodfill(733, 64, bordercolor);
	put12hz(708, 88, "ȫ��ȡ��", 13, textcolor);
}

/***********************************************
 * ����ѡ�񰴼� ����
 * ���ݲ�����������ɫ���߿���ɫ��״̬�����Ƿ���Ե����
 * �޷���ֵ
 * *****************************/
void chctrybtn_draw(int bkcolor, int bordercolor, State state) // RGB2a7fff, RGBffffff, RGB2adfff
{
	if (getonebit(state, IFP_N) == 0) //��ɫͼ�����
	{
		setfillstyle(SOLID_FILL, bkcolor);
		bar(764, 31, 828, 111);
		chctrybtn_draw_o(RGB7f7faa, RGB7f7faa, RGBffffff, RGBccccff, RGBaabfff, RGB808080);
	}
	else
	{
		setfillstyle(SOLID_FILL, bkcolor);
		bar(764, 31, 828, 111);
		chctrybtn_draw_o(RGB808080, RGB2a7fff, RGBffffff, RGBffffff, RGB2adfff, RGB000000);
		if (bkcolor != bordercolor)
		{
			setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
			setcolor(bordercolor);
			rectangle(764, 31, 828, 111);
		}
	}
}
void chctrybtn_draw_o(int bordercolor_a, int bordercolor_b, int bkcolor,
					  int incolor_a, int incolor_b, int textcolor)
{
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(SOLID_FILL, bkcolor);
	bar(774, 39, 816, 81);
	setcolor(bordercolor_a);
	rectangle(776, 41, 794, 59);
	rectangle(796, 61, 814, 79);
	setfillstyle(SOLID_FILL, incolor_a);
	floodfill(778, 43, bordercolor_a);
	floodfill(798, 63, bordercolor_a);
	setcolor(bordercolor_b);
	rectangle(796, 39, 816, 59);
	rectangle(774, 61, 794, 81);
	setfillstyle(SOLID_FILL, incolor_b);
	floodfill(798, 41, bordercolor_b);
	floodfill(776, 63, bordercolor_b);
	put12hz(773, 88, "����ѡ��", 13, textcolor);
}

/********************************
 * FUNCTION:addressnow_display
 * DESCRIPTION:����ַ����ַ
 * INPUT:��ǰָ�룬C��ָ��
 * RETURN:��
 * OTHERS:��
 ********************************/
void addressnow_display(My_filenode *headnode_current, My_filenode *ph, My_vector_ *currenthead)
{

	if (headnode_current == ph)
	{
		setfillstyle(SOLID_FILL, RGBffffff);
		bar(134, 138, 816, 160);
		put12hz(166, 144, "�˵���", 13, RGB000000);
		diskicodraw_o(138, 142, SMALL);
	}
	else
	{
		char address[80];
		maketext_addressbar(address, currenthead->path);
		settextstyle(DEFAULT_FONT, HORIZ_DIR, 0);
		setcolor(RGB000000);
		setfillstyle(SOLID_FILL, RGBffffff);
		bar(133, 138, 816, 160);
		outtextxy(167, 147, address);
		diricodraw_o(142 - 6, 141 - 2, SMALL);
	}
	return;
}

/********************************
 * FUNCTION: maketext_addressbar
 * DESCRIPTION:�ѱ�׼·��ת��һ��
 * INPUT:Ŀ���ַ�����Դ�ַ���
 * RETURN:��
 * OTHERS:��
 ********************************/
void maketext_addressbar(char *ttstring, char *soursestring)
{
	char *thischar, *ttchar;
	for (thischar = soursestring, ttchar = ttstring; *thischar != '\0'; thischar++, ttchar++)
	{
		if (*thischar == '\\')
		{
			*ttchar = '>';
		}
		else
		{
			*ttchar = *thischar;
		}
	}
	*ttchar = '\0';
}

/********************************
 * FUNCTION:close_searchbar
 * DESCRIPTION:�˳�����ģʽʱ���������
 * INPUT:��ǰָ�룬C��ָ��
 * RETURN:��
 * OTHERS:��
 ********************************/
void close_searchbar(void)
{
	setfillstyle(SOLID_FILL, RGBffffff);
	bar(878, 139, 1015, 159);
	put12hz(883, 144, "����", 13, RGB808080);
}

/********************************
 * FUNCTION:display_pagenum
 * DESCRIPTION:���ҳ��������
 * INPUT:ҳָ�룬ģʽ
 * RETURN:��
 * OTHERS:��
 ********************************/
void display_pagenum(char *page, int mode)
{
	int x0_hz1, y0_hz1, x0_hz2, y0_hz2;
	int x0_num, y0_num;
	int space_x, space_y;
	char number[4];
	int strnumber;
	space_x = 4;
	space_y = 2;
	if (mode == TREEFILEMODE)
	{
		x0_hz1 = 67;
		y0_hz1 = 751;
		x0_num = x0_hz1 + 12 + space_x;
		y0_num = y0_hz1 + space_y;
		itoa(page[TREEFILE_NUMBAR] + 1, number, 10);
		strnumber = strlen(number);
		x0_hz2 = x0_num + 8 * strnumber + space_x;
		y0_hz2 = y0_hz1;
	}
	else
	{
		x0_hz1 = 848;
		y0_hz1 = 751;
		x0_num = x0_hz1 + 12 + space_x;
		y0_num = y0_hz1 + space_y;
		if (mode == MAINFILEMODE_SEARCH)
		{
			itoa(page[SEARCH_NUMBER] + 1, number, 10);
			strnumber = strlen(number);
		}
		else
		{
			itoa(page[MAINFILE_NUMBAR] + 1, number, 10);
			strnumber = strlen(number);
		}
		x0_hz2 = x0_num + 8 * strnumber + space_x;
		y0_hz2 = y0_hz1;
	}
	setfillstyle(SOLID_FILL, RGBfffbf0);
	bar(x0_hz1 - 1, y0_hz1 - 1, x0_hz2 + 30, y0_hz2 + 12 * 2);
	put12hz(x0_hz1, y0_hz1, "��", 12, RGB808080);
	settextstyle(0, 0, 0);
	setcolor(RGB808080);
	outtextxy(x0_num, y0_num, number);
	put12hz(x0_hz2, y0_hz2, "ҳ", 12, RGB808080);
}

/********************************
 * FUNCTION:
 * DESCRIPTION:��ʾ��Ŀ��
 * INPUT:��ǰ�ڵ�
 * RETURN:
 * OTHERS:
 ********************************/
void display_filenum(My_filenode *ch)
{
	My_filenode *ttnode;
	int num_node;
	int x = 209, y = 749;
	int space;
	char number[6];
	num_node = count_nodes(ch);

	setfillstyle(SOLID_FILL, RGBfffbf0);
	bar(x, y, x + 70, y + 16);
	itoa(num_node, number, 10);
	setcolor(RGB808080);
	outtextxy(x + 4, y + 4, number);
	space = (strlen(number) + 1) * 8 - 4;
	put12hz(x + 4 + space, y + 2, "����Ŀ", 12, RGB808080);
}

/********************************
 * FUNCTION:
 * DESCRIPTION:��ʾѡ����
 * INPUT:��ǰ�ڵ�
 * RETURN:
 * OTHERS:
 ********************************/
void display_choosenum(My_filenode *ch)
{
	My_filenode *ttnode;
	int i;
	int num_choose = 0;
	int space;
	int x = 284, y = 749;
	char number[6];
	for (ttnode = ch->next, i = 0; ttnode != NULL && i < 800; ttnode = ttnode->next, i++)
	{
		if (getonebit(ttnode->flag, 1) == 1)
		{
			num_choose++;
		}
	}
	setfillstyle(SOLID_FILL, RGBfffbf0);
	bar(x, y, x + 160, y + 16);
	if (num_choose == 0)
	{
		return; //����ʾ
	}
	else
	{
		setcolor(RGB808080);
		itoa(num_choose, number, 10);
		put12hz(x + 4, y + 2, "ѡ��", 12, RGB808080);
		outtextxy(x + 4 + 12 * 2 + 8, y + 4, number);
		space = (strlen(number) + 1) * 8 - 4;
		put12hz(x + 4 + 12 * 2 + 4 + space + 4, y + 2, "����Ŀ", 12, RGB808080);
	}
}