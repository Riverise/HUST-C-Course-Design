#include "mfunc.h"

/****************************
 * ��ʼ������״̬
 * ...Ϊ�˺ø�����...
 * ���ݲ���������״̬��������׵�ַ
 * �޷���ֵ
 * ***********************/
void initbtnstate(State *state)
{
	state[LISTDISPLAY_BTN] = 0x8c;
	state[ICONDISPLAY_BTN] = 0x80;
	state[UP_ARROE_BTN] = 0x80;
	state[REFRESH_BTN] = 0x80;
	state[L_ARROW_BTN] = 0x80;
	state[MAIN_LASTPAGE_BTN] = 0x80;
	state[MAIN_NEXTPAGE_BTN] = 0x80;
	state[TREE_LASTPAGE_BTN] = 0x80;
	state[TREE_NEXTPAGE_BTN] = 0x80;
	state[R_ARROE_BTN] = 0x80;
	state[CLOSE_BTN] = 0x80;
	state[COPY_BTN] = 0x80;
	state[PASTE_BTN] = 0x80;
	state[CUT_BTN] = 0x80;
	state[DELETE_BTN] = 0x80;
	state[RENAME_BTN] = 0x80;
	state[NEWDIR_BTN] = 0x80;
	state[NEWFILE_BTN] = 0x80;
	state[ATTRI_BTN] = 0x80;
	state[CHALL_BTN] = 0x80;
	state[CLRALL_BTN] = 0x80;
	state[CHCTRY_BTN] = 0x80;
	state[DOWN_ARROW_BTN] = 0x80;
}

/********************************
 * FUNCTION:testbtnstate_mouse
 * DESCRIPTION:������������������״̬
 * INPUT:����״̬��������׵�ַ
 * RETURN:��
 * OTHERS:��
 ********************************/
void testbtnstate_mouse(State *state)
{
	testmouse_ico(973, 746, 994, 767, &state[LISTDISPLAY_BTN]);
	testmouse_ico(995, 746, 1016, 767, &state[ICONDISPLAY_BTN]);
	testmouse_ico(100, 139, 123, 160, &state[UP_ARROE_BTN]);
	testmouse_ico(817, 137, 841, 161, &state[REFRESH_BTN]);
	testmouse_ico(5, 139, 31, 160, &state[L_ARROW_BTN]);
	testmouse_ico(56, 139, 82, 160, &state[R_ARROE_BTN]);
	testmouse_ico(940, 746, 966, 767, &state[MAIN_NEXTPAGE_BTN]);
	testmouse_ico(913, 746, 939, 767, &state[MAIN_LASTPAGE_BTN]);
	testmouse_ico(33, 746, 59, 767, &state[TREE_NEXTPAGE_BTN]);
	testmouse_ico(6, 746, 32, 767, &state[TREE_LASTPAGE_BTN]);
	testmouse_ico(988, 0, 1023, 23, &state[CLOSE_BTN]);
	testmouse_ico(9, 31, 71, 111, &state[COPY_BTN]);
	testmouse_ico(72, 31, 131, 111, &state[PASTE_BTN]);
	testmouse_ico(132, 31, 192, 111, &state[CUT_BTN]);
	testmouse_ico(219, 31, 280, 111, &state[DELETE_BTN]);
	testmouse_ico(281, 31, 361, 111, &state[RENAME_BTN]);
	testmouse_ico(395, 31, 456, 111, &state[NEWDIR_BTN]);
	testmouse_ico(457, 31, 519, 111, &state[NEWFILE_BTN]);
	testmouse_ico(548, 31, 609, 111, &state[ATTRI_BTN]);
	testmouse_ico(634, 31, 698, 111, &state[CHALL_BTN]);
	testmouse_ico(699, 31, 763, 111, &state[CLRALL_BTN]);
	testmouse_ico(764, 31, 828, 111, &state[CHCTRY_BTN]);
	testmouse_ico(89, 139, 99, 160, &state[DOWN_ARROW_BTN]);
}

/********************************
 * FUNCTION:testbtnstate_setgbl
 * DESCRIPTION:���ݽ���/�������/����������ȫ�ְ�����ʾ��ʽ
 * INPUT:����״̬�����ַ�����ļ�ͷ�ڵ㣬��ʷ��¼����ͷ�ڵ㣬�˵���ָ�룬C��ָ�룬ճ����ָ�룬��ǰĿ¼ָ��
 * RETURN:��
 * OTHERS:��������ҳ���
 ********************************/
//��Ҫ�޸ģ���ֹˢ������Ҫ����ֵ��Ϊ��λ����
void testbtnstate_setgbl(State *state, struct My_filenode *headnode_main, struct My_vector_ *history, struct My_vector_ *search,
						 struct My_filenode *ph, struct My_filenode *pc_dir_sonhead, struct My_vector_ *headnode_pasting,
						 struct My_vector_ *currenthead, char *page, int judge_search)
{
	int displaytype_main;
	int ch_num = 0, node_num = 0, node_searchnum;
	int max_filenum;
	struct My_filenode *ttnode;
	/* �����ʾģʽ */
	// displaytype_main = gettype_dirdisplay(headnode_main->flag);
	displaytype_main = gettype_mainfile_display(headnode_main, ph);
	switch (displaytype_main)
	{
	case TYPE_LIST_DISPLAY:
		max_filenum = MAXFILENUM_LIST;
		break;
	case TYPE_SUPERICON_DISPLAY:
		max_filenum = MAXFILENUM_ICON_SUPER;
		break;
	default:
		pop_error(-1, "TESTBTNSTATE_SETGBL:", "Assignment error.");
		break;
	}
	if (displaytype_main == TYPE_LIST_DISPLAY)
	{
		if (state[LISTDISPLAY_BTN] != 0x9c)
		{
			state[LISTDISPLAY_BTN] = 0x8c;
		}
		if (state[ICONDISPLAY_BTN] != 0x90)
		{
			state[ICONDISPLAY_BTN] = 0x80;
		}
	}
	else
	{
		if (state[LISTDISPLAY_BTN] != 0x90)
		{
			state[LISTDISPLAY_BTN] = 0x80;
		}
		if (state[ICONDISPLAY_BTN] != 0x9c)
		{
			state[ICONDISPLAY_BTN] = 0x8c;
		}
	}
	/* �����ʷ��¼�Ƿ���ǰ������ */
	if (My_count(history, currenthead) < 2) //���ɺ���(��)
	{
		if (state[L_ARROW_BTN] != 0x10)
		{
			state[L_ARROW_BTN] = 0x00;
		}
		if (state[DOWN_ARROW_BTN] != 0x10)
		{
			state[DOWN_ARROW_BTN] = 0x00;
		}
	}
	else
	{
		if (state[L_ARROW_BTN] != 0x90)
		{
			state[L_ARROW_BTN] = 0x80;
		}
		if (state[DOWN_ARROW_BTN] != 0x90)
		{
			state[DOWN_ARROW_BTN] = 0x80;
		}
	}
	if (currenthead->next == NULL) //����ǰ�����ң�
	{
		if (state[R_ARROE_BTN] != 0x10)
		{
			state[R_ARROE_BTN] = 0x00;
		}
	}
	else
	{
		if (state[R_ARROE_BTN] != 0x90)
		{
			state[R_ARROE_BTN] = 0x80;
		}
	}
	/* ��������ļ�����ҳ������ */
	if (!(page[TREEFILE_NUMBAR] > 0))
	{
		if (state[TREE_LASTPAGE_BTN] != 0x10)
		{
			state[TREE_LASTPAGE_BTN] = 0x00;
		}
	}
	else
	{
		if (state[TREE_LASTPAGE_BTN] != 0x90)
		{
			state[TREE_LASTPAGE_BTN] = 0x80;
		}
	}
	if ((getnum_dir_andopen(pc_dir_sonhead) - page[TREEFILE_NUMBAR] * MAXDIRNUM_TREE) / MAXDIRNUM_TREE == 0)
	{
		if (state[TREE_NEXTPAGE_BTN] != 0x10)
		{
			state[TREE_NEXTPAGE_BTN] = 0x00;
		}
	}
	else
	{
		if (state[TREE_NEXTPAGE_BTN] != 0x90)
		{
			state[TREE_NEXTPAGE_BTN] = 0x80;
		}
	}
	/* ��⵱ǰ��ʾĿ¼�Ƿ�Ϊ��Ŀ¼������Ƿ�Ϊ�˵��ԣ� */
	if (headnode_main == ph || judge_search != 0)
	{
		/* ���ɵ�� */
		if (state[COPY_BTN] != 0x10)
		{
			state[COPY_BTN] = 0x00;
		}
		if (state[PASTE_BTN] != 0x10)
		{
			state[PASTE_BTN] = 0x00;
		}
		if (state[CUT_BTN] != 0x10)
		{
			state[CUT_BTN] = 0x00;
		}
		if (state[DELETE_BTN] != 0x10)
		{
			state[DELETE_BTN] = 0x00;
		}
		if (state[RENAME_BTN] != 0x10)
		{
			state[RENAME_BTN] = 0x00;
		}
		if (state[NEWDIR_BTN] != 0x10)
		{
			state[NEWDIR_BTN] = 0x00;
		}
		if (state[NEWFILE_BTN] != 0x10)
		{
			state[NEWFILE_BTN] = 0x00;
		}
		if (state[CHALL_BTN] != 0x10)
		{
			state[CHALL_BTN] = 0x00;
		}
		if (state[CLRALL_BTN] != 0x10)
		{
			state[CLRALL_BTN] = 0x00;
		}
		if (state[CHCTRY_BTN] != 0x10)
		{
			state[CHCTRY_BTN] = 0x00;
		}
		if (state[UP_ARROE_BTN] != 0x10)
		{
			state[UP_ARROE_BTN] = 0x00;
		}
		if (state[MAIN_NEXTPAGE_BTN] != 0x10)
		{
			state[MAIN_NEXTPAGE_BTN] = 0x00;
		}
		if (state[MAIN_LASTPAGE_BTN] != 0x10)
		{
			state[MAIN_LASTPAGE_BTN] = 0x00;
		}
		if (state[MAIN_NEXTPAGE_BTN] != 0x10)
		{
			state[MAIN_NEXTPAGE_BTN] = 0x00;
		}
		if (state[ATTRI_BTN] != 0x10)
		{
			state[ATTRI_BTN] = 0x00;
		}
		if (!(page[SEARCH_NUMBER] > 0))
		{
			if (state[MAIN_LASTPAGE_BTN] != 0x10)
			{
				state[MAIN_LASTPAGE_BTN] = 0x00;
			}
		}
		else
		{
			if (state[MAIN_LASTPAGE_BTN] != 0x90)
			{
				state[MAIN_LASTPAGE_BTN] = 0x80;
			}
		}
		if (judge_search != 0)
		{
			node_searchnum = count_nodes(search);
			if (node_searchnum >= 10)
			{
				if (state[MAIN_NEXTPAGE_BTN] != 0x90)
				{
					state[MAIN_NEXTPAGE_BTN] = 0x80;
				}
			}
			else
			{
				if (state[MAIN_NEXTPAGE_BTN] != 0x10)
				{
					state[MAIN_NEXTPAGE_BTN] = 0x00;
				}
			}
			if (!(page[SEARCH_NUMBER] > 0))
			{
				if (state[MAIN_LASTPAGE_BTN] != 0x10)
				{
					state[MAIN_LASTPAGE_BTN] = 0x00;
				}
			}
			else
			{
				if (state[MAIN_LASTPAGE_BTN] != 0x90)
				{
					state[MAIN_LASTPAGE_BTN] = 0x80;
				}
			}
		}
		return;
	}
	else
	{
		if (state[NEWDIR_BTN] != 0x90)
		{
			state[NEWDIR_BTN] = 0x80;
		}
		if (state[NEWFILE_BTN] != 0x90)
		{
			state[NEWFILE_BTN] = 0x80;
		}
		if (state[CHALL_BTN] != 0x90)
		{
			state[CHALL_BTN] = 0x80;
		}
		if (state[CLRALL_BTN] != 0x90)
		{
			state[CLRALL_BTN] = 0x80;
		}
		if (state[CHCTRY_BTN] != 0x90)
		{
			state[CHCTRY_BTN] = 0x80;
		}
		if (state[UP_ARROE_BTN] != 0x90)
		{
			state[UP_ARROE_BTN] = 0x80;
		}
	}

	/* ���ѡ������ */
	node_num = count_nodes(headnode_main); //��Ч�����
	if (node_num > 0)					   //������
	{
		ttnode = count_to_node(headnode_main, 1);
		for (ch_num = 0; ttnode != NULL; ttnode = ttnode->next)
		{
			if (getonebit(ttnode->flag, 1) == 1) //��ѡ��
			{
				ch_num++;
			}
		}
		if (ch_num == 0) //ûѡ���κ�һ��
		{
			/* ���ɵ�� */
			if (state[COPY_BTN] != 0x10)
			{
				state[COPY_BTN] = 0x00;
			}
			if (state[CUT_BTN] != 0x10)
			{
				state[CUT_BTN] = 0x00;
			}
			if (state[DELETE_BTN] != 0x10)
			{
				state[DELETE_BTN] = 0x00;
			}
			if (state[RENAME_BTN] != 0x10)
			{
				state[RENAME_BTN] = 0x00;
			}
			if (state[ATTRI_BTN] != 0x10)
			{
				state[ATTRI_BTN] = 0x00;
			}
		}
		else //ѡ����
		{
			if (state[COPY_BTN] != 0x90)
			{
				state[COPY_BTN] = 0x80;
			}
			if (state[CUT_BTN] != 0x90)
			{
				state[CUT_BTN] = 0x80;
			}
			if (state[DELETE_BTN] != 0x90)
			{
				state[DELETE_BTN] = 0x80;
			}
			if (state[RENAME_BTN] != 0x90)
			{
				state[ATTRI_BTN] = 0x80;
				if (ch_num == 1) //����ѡ��һ��
				{
					if (state[ATTRI_BTN] != 0x90)
					{
						state[RENAME_BTN] = 0x80;
					}
				}
			}
		}
		/* ��ҳ���������� */
		if ((node_num - page[MAINFILE_NUMBAR] * max_filenum) / max_filenum == 0) //û����һҳ��
		{
			if (state[MAIN_NEXTPAGE_BTN] != 0x10)
			{
				state[MAIN_NEXTPAGE_BTN] = 0x00;
			}
		}
		else
		{
			if (state[MAIN_NEXTPAGE_BTN] != 0x90)
			{
				state[MAIN_NEXTPAGE_BTN] = 0x80;
			}
		}
		if (!(page[MAINFILE_NUMBAR] > 0))
		{
			if (state[MAIN_LASTPAGE_BTN] != 0x10)
			{
				state[MAIN_LASTPAGE_BTN] = 0x00;
			}
		}
		else
		{
			if (state[MAIN_LASTPAGE_BTN] != 0x90)
			{
				state[MAIN_LASTPAGE_BTN] = 0x80;
			}
		}
	}
	else //û������
	{
		/* ���ɵ�� */

		if (state[COPY_BTN] != 0x10)
		{
			state[COPY_BTN] = 0x00;
		}
		if (state[CUT_BTN] != 0x10)
		{
			state[CUT_BTN] = 0x00;
		}
		if (state[DELETE_BTN] != 0x10)
		{
			state[DELETE_BTN] = 0x00;
		}
		if (state[RENAME_BTN] != 0x10)
		{
			state[RENAME_BTN] = 0x00;
		}
		if (state[CHALL_BTN] != 0x10)
		{
			state[CHALL_BTN] = 0x00;
		}
		if (state[CLRALL_BTN] != 0x10)
		{
			state[CLRALL_BTN] = 0x00;
		}
		if (state[CHCTRY_BTN] != 0x10)
		{
			state[CHCTRY_BTN] = 0x00;
		}
		if (state[ATTRI_BTN] != 0x10)
		{
			state[ATTRI_BTN] = 0x00;
		}
		if (state[MAIN_LASTPAGE_BTN] != 0x10)
		{
			state[MAIN_LASTPAGE_BTN] = 0x00;
		}
		if (state[MAIN_NEXTPAGE_BTN] != 0x10)
		{
			state[MAIN_NEXTPAGE_BTN] = 0x00;
		}
	}

	/* ���ճ�����Ƿ������� */
	if (count_nodes(headnode_pasting) == 0) //���а�û������
	{
		if (state[PASTE_BTN] != 0x10)
		{
			state[PASTE_BTN] = 0x00;
		}
	}
	else
	{
		if (state[PASTE_BTN] != 0x90)
		{
			state[PASTE_BTN] = 0x80;
		}
	}
}

/**************************
 * ˢ����ʾ��������״̬
 * ˢ����ʾ
 * ���ݲ���������״̬�������
 * �޷���ֵ
 * ***********************/
void refreshbtnstate(State *state)
{
	changedisplay_fixedbt(closeXdraw_o, RGB007fff, RGBd40000, &state[CLOSE_BTN]);
	changedisplay_function(copybtn_draw, RGBfffbf0, RGBccffff, RGB2a7fff, &state[COPY_BTN]);
	changedisplay_function(pastebtn_draw, RGBfffbf0, RGBccffff, RGB2a7fff, &state[PASTE_BTN]);
	changedisplay_function(cutbtn_draw, RGBfffbf0, RGBccffff, RGB2a7fff, &state[CUT_BTN]);
	changedisplay_function(deletebtn_draw, RGBfffbf0, RGBccffff, RGB2a7fff, &state[DELETE_BTN]);
	changedisplay_function(renamebtn_draw, RGBfffbf0, RGBccffff, RGB2a7fff, &state[RENAME_BTN]);
	changedisplay_function(newdirbtn_draw, RGBfffbf0, RGBccffff, RGB2a7fff, &state[NEWDIR_BTN]);
	changedisplay_function(newfilebtn_draw, RGBfffbf0, RGBccffff, RGB2a7fff, &state[NEWFILE_BTN]);
	changedisplay_function(attributebtn_draw, RGBfffbf0, RGBccffff, RGB2a7fff, &state[ATTRI_BTN]);
	changedisplay_function(challbtn_draw, RGBfffbf0, RGBccffff, RGB2a7fff, &state[CHALL_BTN]);
	changedisplay_function(cclallbtn_draw, RGBfffbf0, RGBccffff, RGB2a7fff, &state[CLRALL_BTN]);
	changedisplay_function(chctrybtn_draw, RGBfffbf0, RGBccffff, RGB2a7fff, &state[CHCTRY_BTN]);
	changedisplay_function(larrowdraw_b, RGB808080, RGB007faa, &state[L_ARROW_BTN]);
	changedisplay_function(downarrow_draw, RGB808080, RGB007faa, &state[DOWN_ARROW_BTN]);
	changedisplay_function(rarrowdraw_f, RGB808080, RGB007faa, &state[R_ARROE_BTN]);
	changedisplay_function(uparrowdraw, RGBffffff, RGBccffff, &state[UP_ARROE_BTN]);
	changedisplay_function(larrowdraw_main_lpg, RGB808080, RGB007faa, &state[MAIN_LASTPAGE_BTN]);
	changedisplay_function(rarrowdraw_main_npg, RGB808080, RGB007faa, &state[MAIN_NEXTPAGE_BTN]);
	changedisplay_function(larrowdraw_tree_lpg, RGB808080, RGB007faa, &state[TREE_LASTPAGE_BTN]);
	changedisplay_function(rarrowdraw_tree_npg, RGB808080, RGB007faa, &state[TREE_NEXTPAGE_BTN]);
	changedisplay_fixedbt(refreshicodraw_o, RGBffffff, RGBccffff, RGB2a7fff, &state[REFRESH_BTN]);
	changedisplay_chfixedbt(listdisplay_draw, RGBfffbf0, RGBccffff, RGB2a7fff, &state[LISTDISPLAY_BTN]);
	changedisplay_chfixedbt(icondisplay_draw, RGBfffbf0, RGBccffff, RGB2a7fff, &state[ICONDISPLAY_BTN]);
}

/****************************************
 * �����ҳ���а����Ƿ����������ִ����ع���
 * ���ݲ���������״̬�����ַ�����ļ�ͷ�ڵ㣬��ʷ��¼����ͷ�ڵ㣬
 * 			��ǰ���ָ���ַ��C��ָ�룬���ļ���ʾ״̬�����׵�ַ���ַ���¼���飬��ǰҳ����ճ��ģʽ�ж�
 * ����ֵ�����ܰ������
 * **************************************/
/********************************
 * FUNCTION:
 * DESCRIPTION:
 * INPUT:
 * RETURN:
 * OTHERS:ճ��ģʽ�ж������жϸ���/����
 ********************************/
int testdo_mainbt(State *state, struct My_filenode **p_headnode_current, struct My_vector_ *history,
				  struct My_vector_ **p_currenthead, struct My_filenode *ph,
				  struct My_filenode *pc_for_dir, Bit *dsplstate_main, struct My_vector_ *currenthead,
				  struct My_vector_ *search, struct My_vector_ *paste, struct My_filenode *ph_for_paste, char *textipt,
				  char *page, int judge_paste, int judge_search)
{
	void (*draw_mainfile)(int x1, int y1, struct My_filenode *headnode,
						  int n, int state, int page); //����ָ��
	Funcdata data_current;
	getfuncdata(&data_current, &draw_mainfile, p_headnode_current, ph);
	/*�б���ʾ*/
	if (testmouse_bar(973, 746, 994, 767, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		if (getonebit(state[LISTDISPLAY_BTN], IFC_N) == 1) //�Ѿ������״̬��
		{
			longpress_fit();   //��������
			return BTN_NO_USE; //ɶҲ����
		}
		else //���ĵ����״̬
		{
			/*����ģ�����*/
			func_setdisplay_list(state, page, ph, *p_headnode_current);
			longpress_fit(); //��������
			return LISTDISPLAY_BTN;
		}
	}
	/*ͼ����ʾ*/
	else if (testmouse_bar(995, 746, 1016, 767, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		if (getonebit(state[ICONDISPLAY_BTN], IFC_N) == 1) //�Ѿ������״̬��
		{
			longpress_fit();   //��������
			return BTN_NO_USE; //ɶҲ����
		}
		else //���ĵ����״̬
		{
			/*����ģ�����*/
			func_setdisplay_icon(state, page, ph, *p_headnode_current);
			longpress_fit(); //��������
			return ICONDISPLAY_BTN;
		}
	}
	/*�ϼ�ͷ,�ϼ�Ŀ¼*/
	else if (testmouse_bar(100, 139, 123, 160, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		/* ����Ƿ���Ե����������Ӧ */
		if (getonebit(state[UP_ARROE_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			/*����ģ�����*/
			longpress_fit(); //��������
			func_changedir_father(p_headnode_current, ph, p_currenthead, history, page);
			return UP_ARROE_BTN;
		}
	}
	/*ˢ��*/
	else if (testmouse_bar(817, 137, 841, 161, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		/* ����Ƿ���Ե����������Ӧ */
		func_refresh(*p_headnode_current, ph);
		longpress_fit(); //��������
		return REFRESH_BTN;
	}
	/*���ͷ*/
	else if (testmouse_bar(5, 139, 31, 160, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		/* ����Ƿ���Ե����������Ӧ */
		if (getonebit(state[L_ARROW_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			/*����ģ�����*/
			longpress_fit(); //��������
			func_changedir_last(p_headnode_current, ph, p_currenthead, history, page);
			return L_ARROW_BTN;
		}
	}
	/*�Ҽ�ͷ*/
	else if (testmouse_bar(56, 139, 82, 160, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		/* ����Ƿ���Ե����������Ӧ */
		if (getonebit(state[R_ARROE_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			/*����ģ�����*/
			func_changedir_next(p_headnode_current, ph, p_currenthead, history, page);
			return R_ARROE_BTN;
		}
	}
	/*�رղ�棬�˳�ϵͳ*/
	else if (testmouse_bar(988, 0, 1023, 23, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		longpress_fit(); //��������
		return CLOSE_BTN;
	}
	/*���ƹ���*/
	else if (testmouse_bar(9, 31, 71, 111, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		/* ����Ƿ���Ե����������Ӧ */
		if (getonebit(state[COPY_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			/*����ģ�����*/
			longpress_fit(); //��������
			func_copy(*p_headnode_current, paste);
			return COPY_BTN;
		}
	}
	/*ճ������*/
	else if (testmouse_bar(72, 31, 131, 111, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		/* ����Ƿ���Ե����������Ӧ */
		if (getonebit(state[PASTE_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			/*����ģ�����*/
			longpress_fit(); //��������
			func_paste(*p_headnode_current, ph_for_paste, paste, judge_paste);
			return PASTE_BTN;
		}
	}
	/*���й���*/
	else if (testmouse_bar(132, 31, 192, 111, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		struct My_filenode *ttnode;
		/* ����Ƿ���Ե����������Ӧ */
		if (getonebit(state[CUT_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			/*����ģ�����*/
			longpress_fit(); //��������
			func_cut(*p_headnode_current, paste);
			return CUT_BTN;
		}
	}
	/*ɾ������*/
	else if (testmouse_bar(219, 31, 280, 111, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		struct My_filenode *ttnode_1, *ttnode_2;
		/* ����Ƿ���Ե����������Ӧ */
		if (getonebit(state[DELETE_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			/*����ģ�����*/
			longpress_fit(); //��������
			func_delete(*p_headnode_current);
			return DELETE_BTN;
		}
	}
	/*����������*/
	else if (testmouse_bar(281, 31, 361, 111, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{

		/* ����Ƿ���Ե����������Ӧ */
		if (getonebit(state[RENAME_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			/*����ģ�����*/
			longpress_fit(); //��������
			func_rename(*p_headnode_current, textipt, data_current.x0, data_current.y0, data_current.height,
						data_current.width, data_current.space_x_n, data_current.space_y_n, data_current.displaytype_main, page, draw_mainfile);
			return RENAME_BTN;
		}
	}
	/*�½��ļ��й���*/
	else if (testmouse_bar(395, 31, 456, 111, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		/* ����Ƿ���Ե����������Ӧ */
		if (getonebit(state[NEWDIR_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			/*����ģ�����*/
			func_newdir(*p_headnode_current, textipt, data_current.maxnum_currenttype, data_current.x0, data_current.y0, data_current.height,
						data_current.width, data_current.space_x_n, data_current.space_y_n, data_current.space_x_ico, data_current.space_y_ico, data_current.displaytype_main);
			return NEWDIR_BTN;
		}
	}
	/*�½��ļ�����*/
	else if (testmouse_bar(457, 31, 519, 111, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		/* ����Ƿ���Ե����������Ӧ */
		if (getonebit(state[NEWFILE_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			/*����ģ�����*/
			func_newfile(*p_headnode_current, textipt, data_current.maxnum_currenttype, data_current.x0, data_current.y0, data_current.height,
						 data_current.width, data_current.space_x_n, data_current.space_y_n, data_current.space_x_ico, data_current.space_y_ico, data_current.displaytype_main);
			return NEWFILE_BTN;
		}
	}
	/*�����Թ���*/
	else if (testmouse_bar(548, 31, 609, 111, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		longpress_fit(); //��������
		if (getonebit(state[ATTRI_BTN], IFP_N) == 1)
		{
			func_attridisplay(*p_headnode_current);
		}
		return BTN_NO_USE;
	}
	/*ȫ��ѡ����*/
	else if (testmouse_bar(634, 31, 698, 111, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		/*����ģ�����*/
		longpress_fit();
		func_chall(state, *p_headnode_current, ph, pc_for_dir, currenthead,
				   history, search, paste, data_current.maxfilenum, data_current.height, data_current.width, data_current.x0, data_current.y0, data_current.displaytype_main,
				   dsplstate_main, page, judge_search, draw_mainfile);
		return CHALL_BTN;
	}
	/*ȫ��ȡ������*/
	else if (testmouse_bar(699, 31, 763, 111, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		/*����ģ�����*/
		longpress_fit();
		func_clrall(state, *p_headnode_current, ph, pc_for_dir, currenthead,
					history, search, paste, data_current.maxfilenum, data_current.height, data_current.width, data_current.x0, data_current.y0, data_current.displaytype_main,
					dsplstate_main, page, judge_search, draw_mainfile);
		return CLRALL_BTN;
	}
	/*����ѡ����*/
	else if (testmouse_bar(764, 31, 828, 111, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		/*����ģ�����*/
		longpress_fit();
		func_chctry(state, *p_headnode_current, ph, pc_for_dir, currenthead,
					history, search, paste, data_current.maxfilenum, data_current.height, data_current.width, data_current.x0, data_current.y0, data_current.displaytype_main,
					dsplstate_main, page, judge_search, draw_mainfile);
		return CHCTRY_BTN;
	}
	/* ������һҳ */
	else if (testmouse_bar(913, 746, 939, 767, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		if (getonebit(state[MAIN_LASTPAGE_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			if (judge_search == 0)
			{
				page[MAINFILE_NUMBAR]--;
			}
			else
			{
				page[SEARCH_NUMBER]--;
			}
			longpress_fit();
			return MAIN_LASTPAGE_BTN;
		}
	}
	/* ������һҳ */
	else if (testmouse_bar(940, 746, 966, 767, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		if (getonebit(state[MAIN_NEXTPAGE_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			if (judge_search == 0)
			{
				page[MAINFILE_NUMBAR]++;
			}
			else
			{
				page[SEARCH_NUMBER]++;
			}
			longpress_fit();
			return MAIN_NEXTPAGE_BTN;
		}
	}
	/* ���Σ���һҳ */
	else if (testmouse_bar(6, 746, 32, 767, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		if (getonebit(state[TREE_LASTPAGE_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			page[TREEFILE_NUMBAR]--;
			longpress_fit();
			return TREE_LASTPAGE_BTN;
		}
	}
	/* ���Σ���һҳ */
	else if (testmouse_bar(33, 746, 59, 767, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		if (getonebit(state[TREE_NEXTPAGE_BTN], IFP_N) == 0)
		{
			return BTN_NO_USE;
		}
		else
		{
			page[TREEFILE_NUMBAR]++;
			longpress_fit();
			return TREE_NEXTPAGE_BTN;
		}
	}
	/* ������ */
	else if (testmouse_bar(848, 137, 1016, 161, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		longpress_fit();
		// printf("%s\n", (*p_headnode_current)->father->name);
		if (strcmp((*p_headnode_current)->father->name, "cidiannao") == 0)
		{
			return BTN_NO_USE;
		}
		keybdintraction(textipt, 882, 147, 878, 139, 1015, 159, 8, RGBffffff, SEARCHBAR_MAXNUM, TEXTDISPLAY, 0);
		return SEARCH_BAR;
	}
	/* ��ַ�� */
	else if (testmouse_bar(131, 137, 816, 161, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		longpress_fit();
		record_imagedata(164, 138, 816, 160, "IMDATA_0");
		setfillstyle(SOLID_FILL, RGBffffff);
		bar(164, 138, 816, 160);
		setcolor(RGB000000);
		outtextxy(167, 147, ">");
		keybdintraction(textipt, 167 + 9, 147, 164 + 9, 138, 816, 160, 8, RGBffffff, ADDRESSBAR_MAXNUM, TEXTNOTDISPLAY, 0);
		if (strlen(textipt) == 0)
		{
			write_imagedata(164, 138, 816, 160, "IMDATA_0");
			return BTN_NO_USE;
		}
		else
		{
			return ADDRESS_BAR;
		}
	}
	/* ��ʷ��¼ */
	else if (testmouse_bar(85, 139, 99, 160, MOUSETEST_INBAR) == MOUSE_INBAR_L)
	{
		int xy[4];
		int n;
		struct My_filenode *ttnode;
		getxy_history(xy, history);
		longpress_fit();
		draw_history(history, xy);
		n = func_history(history, p_currenthead, p_headnode_current, ph, xy);
		if (n == -1)
		{
			return BTN_NO_USE;
		}
		// ttnode = vector_to_filenode(ph, count_to_node(history, n));
		// move_dir(history, p_currenthead, 'n',ttnode);
		// *p_headnode_current = find_node_by_path(ph, (*p_currenthead)->path);
		// settype_dirdisplay(&((*p_headnode_current)->flag), gettype_dirdisplay(ph->flag));
		// page[MAINFILE_NUMBAR] = 0;

		return DOWN_ARROW_BTN;
	}
	else
	{
		return BTN_NO_USE;
	}
}

/***************************************
 * �������������
 * ������λ���ĸ�����
 * ���ݲ��������λ��
 * ����ֵ��	���ļ�������0��
 * 			�����ļ�������1��
 * 			�������򷵻�2��������ʹ�ú궨�壩
 * ************************************/
int testmouse_wherenow(int mousex, int mousey)
{
	if (TREEFILEAREA_X1 <= mousex && mousex <= TREEFILEAREA_X2 && TREEFILEAREA_Y1 <= mousey && mousey <= TREEFILEAREA_Y2)
	{
		return TREEFILE_NUMBAR;
	}
	else if (MAINFILEAREA_X1 <= mousex && mousex <= MAINFILEAREA_X2 && MAINFILEAREA_Y1 <= mousey && mousey <= MAINFILEAREA_Y2)
	{
		return MAINFILE_NUMBAR;
	}
	else
	{
		return OTHER_NUMBAR;
	}
}

/********************************
 * FUNCTION:refresh_mainfilebk
 * DESCRIPTION:ˢ���ļ�����ʾ����
 * INPUT:	�����ļ���ָ�룬��ǰĿ¼ָ���ָ�룬C��ָ��,��������ָ�룬��ʷ��¼����ָ�룬
 * 			ָ��history���ĵ�ǰ��ʾ��Ŀ¼��Ӧ��history�ڵ��ַ�������ַ�������������������ַ��
 * 			ҳ�������׵�ַ��ˢ��ģʽ
 * RETURN:��
 * OTHERS:ģʽ0����ˢ�£�ģʽ1 ֻˢ�����ļ�����ģʽ2 ˢ�������ļ�����ģʽ3��ȫ��ˢ��
 ********************************/
void refresh_filebk(struct My_filenode *pc_for_dir, struct My_filenode **p_headnode_current,
					struct My_filenode *ph, struct My_vector_ *search, struct My_vector_ *history,
					struct My_vector_ **p_currenthead, char *textipt, int *p_num_search, char *page, int mode)
{
	int i;
	int mode_display; //��ʾģʽ
	int maxnum;		  //�����ʾ����
	void (*draw_mainfile)(int n, struct My_filenode *headnode, int state, int page);
	mode_display = gettype_mainfile_display(*p_headnode_current, ph);
	/* ������ʾģʽ */
	if (mode != REFRESH_MAINFILE_SEARCHMODE_ONLY)
	{
		/* �˳�����ģʽ�� */
		close_searchbar(); //���������

		switch (mode_display)
		{
		case TYPE_LIST_DISPLAY:
			draw_mainfile = My_draw_main_file1;
			maxnum = MAXFILENUM_LIST;
			break;
		case TYPE_SUPERICON_DISPLAY:
			draw_mainfile = My_draw_main_file2;
			maxnum = MAXFILENUM_ICON_SUPER;
			break;
		default:
			pop_error(-1, "REFRESH_FILEBK:", "Assignment error.");
			exit(1);
			break;
		}

		switch (mode)
		{
		case REFRESH_NOTATALL:
			return;
		case REFRESH_MAINFILE_ONLY:
			setfillstyle(SOLID_FILL, RGBffffff);
			clrmous(MouseX, MouseY);
			bar(MAINFILEAREA_X1, MAINFILEAREA_Y1, MAINFILEAREA_X2, MAINFILEAREA_Y2); //ˢ�����ļ�������
			for (i = 1; i <= maxnum; i++)											 //���ļ�������
			{
				draw_mainfile(i, *p_headnode_current, 0, page[MAINFILE_NUMBAR]);
			}

			/* ����ʾģʽ��Ҫ��ͬ��������Ҫ�ı�˵���� */
			if (gettype_dirdisplay((*p_headnode_current)->flag) == TYPE_LIST_DISPLAY)
			{
				display_listnodes();
			}
			addressnow_display(*p_headnode_current, ph, *p_currenthead);
			display_pagenum(page, MAINFILEMODE);
			return;
		case REFRESH_TREEFILE_ONLY:
			setfillstyle(SOLID_FILL, RGBffffff);
			clrmous(MouseX, MouseY);
			bar(TREEFILEAREA_X1, TREEFILEAREA_Y1, TREEFILEAREA_X2, TREEFILEAREA_Y2); //ˢ�������ļ�������
			for (i = 1; i <= MAXDIRNUM_TREE; i++)									 //�����ļ�������
			{
				My_draw_tree_file(i, pc_for_dir->son_list_head, 0, page[TREEFILE_NUMBAR]);
			}
			display_pagenum(page, TREEFILEMODE);
			return;
		case REFRESH_FILE_ALL:
			setfillstyle(SOLID_FILL, RGBffffff);
			clrmous(MouseX, MouseY);
			bar(TREEFILEAREA_X1, TREEFILEAREA_Y1, TREEFILEAREA_X2, TREEFILEAREA_Y2); //ˢ�������ļ�������
			bar(MAINFILEAREA_X1, MAINFILEAREA_Y1, MAINFILEAREA_X2, MAINFILEAREA_Y2); //ˢ�����ļ�������
			for (i = 1; i <= MAXDIRNUM_TREE; i++)									 //�����ļ�������
			{
				My_draw_tree_file(i, pc_for_dir->son_list_head, 0, page[TREEFILE_NUMBAR]);
			}
			for (i = 1; i <= maxnum; i++) //���ļ�������
			{
				draw_mainfile(i, *p_headnode_current, 0, page[MAINFILE_NUMBAR]);
			}

			if (gettype_dirdisplay((*p_headnode_current)->flag) == TYPE_LIST_DISPLAY) //��ģʽ��Ҫ�ı�˵��
			{
				display_listnodes();
			}
			addressnow_display(*p_headnode_current, ph, *p_currenthead);
			display_pagenum(page, TREEFILEMODE);
			display_pagenum(page, MAINFILEMODE);
			return;
		default:
			pop_error(-1, "REFRESH_FILEBK:", "Assignment error.");
			exit(1);
			return;
		}
	}
	else //����ģʽ��ˢ��
	{
		setfillstyle(SOLID_FILL, RGBffffff);
		clrmous(MouseX, MouseY);
		bar(MAINFILEAREA_X1, MAINFILEAREA_Y1, MAINFILEAREA_X2, MAINFILEAREA_Y2); //ˢ�����ļ�������
		if (page[SEARCH_NUMBER] != page[SEARCH_NUMBER_CTT] || page[SEARCH_NUMBER_CTT] == -1)
		{
			page[SEARCH_NUMBER_CTT] = page[SEARCH_NUMBER];
			*p_num_search = 0;
			(*p_headnode_current) = find_node_by_path(ph, (*p_currenthead)->path);
			free_vector_list(search);
			My_search(search, *p_headnode_current, textipt, p_num_search, page[SEARCH_NUMBER]);
			move_dir(history, p_currenthead, 'n', (*p_headnode_current)->father);
			(*p_headnode_current) = find_node_by_path(ph, (*p_currenthead)->path);
			if (*p_num_search == 0) //û�ѵ�����
			{
				*p_num_search = -1; //Ҫ����0��������ģʽ��
			}
		}
		if (*p_headnode_current != ph)
		{
			free_list(*p_headnode_current);
		}
		for (i = 1; i <= 10; i++)
		{
			My_draw_search_file(i, search, 0);
		}
		(*p_headnode_current) = find_node_by_path(ph, (*p_currenthead)->path);
		display_pagenum(page, MAINFILEMODE_SEARCH);
	}
}

/********************************
 * FUNCTION:testdo_sortbt
 * DESCRIPTION:���ļ����б���ʾģʽ���ı�����ģʽ
 * INPUT:��ʾģʽ������ʽ��������ǰ�ڵ�
 * RETURN:�ɹ�����1
 * OTHERS:��
 ********************************/
int testdo_sortbt(int type, char *sorttype, My_filenode *headnode_current)
{
	if (type == TYPE_LIST_DISPLAY)
	{
		/* �������� */
		if (testmouse_bar(219, 165, 370, 181, MOUSETEST_INBAR) == MOUSE_INBAR_L)
		{
			if (*sorttype == 1)
			{
				*sorttype = 2;
			}
			else if (*sorttype == 2)
			{
				*sorttype = 1;
			}
			else
			{
				*sorttype = 1;
			}
		}
		/* ʱ������ */
		else if (testmouse_bar(454, 165, 639, 181, MOUSETEST_INBAR) == MOUSE_INBAR_L)
		{
			if (*sorttype == 3)
			{
				*sorttype = 4;
			}
			else if (*sorttype == 4)
			{
				*sorttype = 3;
			}
			else
			{
				*sorttype = 3;
			}
		}
		/* ��С���� */
		else if (testmouse_bar(746, 165, 835, 181, MOUSETEST_INBAR) == MOUSE_INBAR_L)
		{
			if (*sorttype == 5)
			{
				*sorttype = 6;
			}
			else if (*sorttype == 6)
			{
				*sorttype = 5;
			}
			else
			{
				*sorttype = 5;
			}
		}
		else
		{
			return 0;
		}
		My_sort(headnode_current, *sorttype);
		longpress_fit();
		return 1;
	}
	else
	{
		return 0;
	}
}
