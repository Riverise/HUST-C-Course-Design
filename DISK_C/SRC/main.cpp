#include "main.h"

int main(void)
{
	/* ��Ӧ��ʼ������ */
	struct My_filenode *p0;				  //�˵���ָ�룬��Ϊ������ȡ���յ�ָ�룬
	struct My_filenode *p0_for_dir;		  //�˵���Ŀ¼ָ�룬��Ϊ������ȡ���յ�ָ��
	struct My_filenode *p0_for_paste;	  //�˵���ճ����ָ�룬��Ϊ������ȡ���յ�ָ��
	struct My_filenode *ph;				  // C��ָ�룬�൱�ڸ�Ŀ¼������ֻ��һ����
	struct My_filenode *ph_for_dir;		  // C������Ŀ¼ָ�룬������Ŀ¼�����ͷ�ڵ�ָ��
	struct My_filenode *ph_for_paste;	  //��˲�����ָ�򱻸��ƴ���ָ�룬�Ӷ���pc_for_paste��ָ���ݸ��Ƶ��˴�
	struct My_filenode *pc;				  // �������ļ�����ʾ
	struct My_filenode *pc_for_dir;		  // C������Ŀ¼
	struct My_filenode *pc_for_paste;	  //��ʱ��ճ����ָ�룬�õ�ճ�����ʱ�����������þ��ͷ�
	struct My_filenode *ch;				  // pc�����յ㣬�Ժ�����ָ��ǰĿ¼�����ͷ�ڵ��ָ�룬�Ӷ�������ǰĿ¼���ݴ�ͷ�ڵ㣩
	struct My_filenode *ttnode, *ttnode_; //Ŀ��ָ�룬ָ��Ҫ�����Ľڵ�
	struct My_filenode *tt_node;
	struct My_vector_ *search;		//����������������������ͷ����ָ��
	struct My_vector_ *paste;		//ճ���壬ָ��ճ��������ͷ�ڵ��ָ��
	struct My_vector_ *history;		//��ʷ��¼��ָ����ʷ��¼�����ڴ򿪵�Ŀ¼����ʷ����ͷ���ָ��
	struct My_vector_ *currenthead; //ָ��history���ĵ�ǰ��ʾ��Ŀ¼��Ӧ��history�ڵ㣬��¼����·��
	// struct My_vector_ *tt_node;		//Ŀ��ָ�룬ָ��Ҫ�����Ľڵ�
	char sort_way = 0; //����ʽ
	char state_menu;
	int judge_sort;				  //�ж��Ƿ�����ˢ��
	char textipt[33];			  //���ڽ����������֣����32���ַ�
	char refresh_mode;			  //ˢ����ʾģʽ��Ĭ��ȫ��ˢ��
	char page[4] = {0, 0, 0, -1}; //ҳ��
	int if_doublepress;			  //˫���ж�/��¼����
	int i;						  //ѭ����������
	int num_count;
	int judge_search = 0;						 //������������,��0Ϊ����ģʽ
	int judge_paste;							 //�ж�ճ��ģʽ������or����
	int *pressstate_fm;							 //���ļ��������״ָ̬�루��ָ��static��
	int *pressstate_tr;							 //�����������״ָ̬�루��ָ������һ����ͬ��static��
	int *pressstate_srch;						 //�������������ָ�루ָ������һ����ͬ��static��
	int press_l;								 //��һ��ѭ����press��״̬�����ڼ�����״̬�仯���Ӷ����˫��
	int state_ft[2], state_fm[2], state_srch[2]; //�ļ���ʾ״̬�������ж�״̬�仯���Ӷ�ʵʱ�����겢�ı䱳������
	char tree_ch_num[2] = {-1, -1};				 //���ڱ�֤һ��ֻѡ�л��չ��һ��
	State state_bt[25] = {0};					 //������ʾ״̬��λ������¼�Ϳ�����ʾ״̬
	Bit mainfile_ch_dsplstate[3] = {0};			 //���ļ��������ļ�����ʾ״̬����ֹ����ˢ�£�����ˢ�´���
	int menu_number;
	int search_num;

	/* ��ӭ���� */
	initsvga256();
	initcolor256();
	delay(600);
	welcome_page0();
	delay(500);
	welcome_page1();

	pcinit(&ch, &p0, &ph, &pc, &p0_for_dir, &ph_for_dir, &pc_for_dir,
		   &p0_for_paste, &ph_for_paste, &pc_for_paste, &paste,
		   &history, &currenthead, &search, &sort_way, state_bt);

	delay(500);

	/* ��ӭ���� */
	if (function_log(textipt) == 1)
	{
		/* �˳����ͷź��� */
		// sleep(1); //��ʱ1s
		close_init(p0, ph, pc, p0_for_dir, ph_for_dir, pc_for_dir,
				   p0_for_paste, ph_for_paste, pc_for_paste, paste,
				   history, search);
		closesvga256();
		chdir("C:\\win_pro\\SRC\\"); //������һ�δ�
		return 0;
	}

	drawbk(); //����������
	move_dir(history, &currenthead, 'n', p0);
	/* ������ѭ��1 */
	while (1)
	{
		/* ���ݽڵ�����ɨ���ļ��ͽ������� ��ˢ�£� */
		refresh_all(&ch, pc_for_dir, ph, currenthead, &refresh_mode, tree_ch_num, page, state_bt);
		/* ��ѭ��2 */
		while (1)
		{
			/* һЩ����������������������������Ƶĺ�����������ƺ��� */
			if (1 == func_refresh(state_bt, &ch, history, search, ph, pc_for_dir, paste,
								  &currenthead, page, textipt, &judge_search, &refresh_mode))
			{
				break;
			}
			display_filenum(ch);
			state_ft[LAST] = -1;   //��⣨������ѭ������״̬���ĳ�ʼ��
			state_fm[LAST] = -1;   //ͬ��
			state_srch[LAST] = -1; //ͬ��

			/* ��ѭ��3 */
			while (1)
			{
				press_l = press; //�����ݱ���
				newmouse(&MouseX, &MouseY, &press);
				testbtnstate_setgbl(state_bt, ch, history, search, ph, pc_for_dir->son_list_head, paste, currenthead, page, judge_search);
				/* ������λ�ã����벻ͬ���������� */
				switch (testmouse_wherenow(MouseX, MouseY))
				{
				case TREEFILE_NUMBAR:
					do //����������͹��ܵ��÷�ѭ��
					{
						press_l = press; //�����ݱ���
						newmouse(&MouseX, &MouseY, &press);
						refresh_filetreestate(state_ft, pc_for_dir->son_list_head, page[TREEFILE_NUMBAR]);
						pressstate_tr = test_file_mousepress(pc_for_dir->son_list_head, page);
						if (pressstate_tr[0] == LEFTPRESS && pressstate_tr[2] != -1) //�����
						{
							chgto_treedir(&ch, history, &currenthead, search, ph, pc_for_dir, tree_ch_num, pressstate_tr, page, &judge_search, &refresh_mode);
							break;
						}
					} while (testmouse_wherenow(MouseX, MouseY) == TREEFILE_NUMBAR);
					break;
				case MAINFILE_NUMBAR:
					//����������͹��ܵ��÷�ѭ��
					if (judge_search == 0)
					{
						do //������ģʽ��������͹��ܵ��÷�ѭ��
						{
							press_l = press; //�����ݱ���
							newmouse(&MouseX, &MouseY, &press);
							refresh_filemainstate(state_fm, ch, ph, page[MAINFILE_NUMBAR]);
							if_doublepress = func_mianfile(&pressstate_fm, state_fm, mainfile_ch_dsplstate,
														   ch, page, press_l, state_bt, search,
														   paste, history, ph, pc_for_dir->son_list_head,
														   currenthead, judge_search); //��Ҫ����ʵ��,���˫������1
							if (if_doublepress == 1)
							{
								/*˫������ģ��ִ��*/

								tt_node = count_to_node(ch, pressstate_fm[2] + get_maxfilenum(ch, ph) * page[MAINFILE_NUMBAR]);

								if (tt_node->flag & IS_DIR)
								{
									/* �޸ĵ�ǰĿ¼ */
									move_dir(history, &currenthead, 'n', tt_node);
									ch = find_node_by_path(ph, currenthead->path);
									settype_dirdisplay(&(ch->flag), gettype_dirdisplay(ph->flag));
									refresh_mode = REFRESH_MAINFILE_ONLY; //��Ҫˢ����ʾ
									break;
								}
							}
							if (testmouse_bar(MAINFILEAREA_X1, MAINFILEAREA_Y1, MAINFILEAREA_X2, MAINFILEAREA_Y2, MOUSETEST_INBAR) == MOUSE_INBAR_R)
							{
								if (state_fm[NOW] > 0 && getnum_choose(ch) > 0) //��Ч����
								{
									menu_number = func_menu(FILE_MENU, state_menu, state_bt, &ch, ph, ph_for_paste, paste, textipt, page, &judge_paste, &judge_sort);
									if (menu_number == BTN_NO_USE || menu_number == ATTRI_BTN)
									{
									}
									else if (menu_number == DELETE_BTN)
									{
										refresh_mode = REFRESH_MAINFILE_ONLY;
										break;
									}
									else if (menu_number == CUT_BTN || menu_number == COPY_BTN)
									{
										judge_paste = menu_number;
										break;
									}
								}
								else
								{
									menu_number = func_menu(DIR_MENU, state_menu, state_bt, &ch, ph, ph_for_paste, paste, textipt, page, &judge_paste, &judge_sort);
									if (menu_number == BTN_NO_USE)
									{
									}
									else if (menu_number == NEWDIR_BTN || menu_number == NEWFILE_BTN)
									{
										refresh_mode = REFRESH_MAINFILE_ONLY;
										break;
									}
									else if (judge_sort == 1)
									{
										refresh_mode = REFRESH_MAINFILE_ONLY;
										break;
									}
									else if (menu_number == LISTDISPLAY_BTN || menu_number == ICONDISPLAY_BTN)
									{
										refresh_mode = REFRESH_MAINFILE_ONLY;
										break;
									}
									else if (menu_number == REFRESH_BTN)
									{
										if (judge_search != 0)
										{
											judge_search = 0;
										}
										refresh_mode = REFRESH_ALL;
										break;
									}
									else if (menu_number == PASTE_BTN)
									{
										refresh_mode = REFRESH_MAINFILE_ONLY;
										break;
									}
									else if (menu_number == 10)
									{
										refresh_mode = REFRESH_MAINFILE_ONLY;
										break;
									}
								}
							}
							while (testmouse_inoutbar(219, 165, 835, 181) == 1)
							{
								newmouse(&MouseX, &MouseY, &press);
								judge_sort = testdo_sortbt(gettype_mainfile_display(ch, ph), &sort_way, ch);
								if (judge_sort == 1)
								{
									refresh_mode = REFRESH_MAINFILE_ONLY; //��Ҫˢ����ʾ
									break;
								}
							}
							if (judge_sort == 1)
							{
								judge_sort = 0;
								break;
							}
						} while (testmouse_wherenow(MouseX, MouseY) == MAINFILE_NUMBAR);
					}
					else
					{
						do //����ģʽ��������͹��ܵ��÷�ѭ��
						{
							press_l = press; //�����ݱ���
							newmouse(&MouseX, &MouseY, &press);

							refresh_filesearch_state(state_srch, search);
							search_num = test_search_mousepress(press_l);
							if (-1 != search_num)
							{
								tt_node = vector_to_filenode(ph, count_to_node(search, search_num));
								if (tt_node->flag & IS_DIR)
								{
									move_dir(history, &currenthead, 'n', tt_node);
									ch = find_node_by_path(ph, currenthead->path);
									settype_dirdisplay(&(ch->flag), gettype_dirdisplay(ph->flag));
									page[MAINFILE_NUMBAR] = 0;
									refresh_mode = REFRESH_MAINFILE_ONLY; //��Ҫˢ����ʾ
									judge_search = 0;
									break;
								}
								else
								{
									ch = find_node_by_path(ph, count_to_node(search, search_num)->path);
									move_dir(history, &currenthead, 'n', ch->father);
									settype_dirdisplay(&(ch->flag), gettype_dirdisplay(ph->flag));
									page[MAINFILE_NUMBAR] = 0;
									refresh_mode = REFRESH_MAINFILE_ONLY; //��Ҫˢ����ʾ
									judge_search = 0;
									break;
								}
							}

						} while (testmouse_wherenow(MouseX, MouseY) == MAINFILE_NUMBAR);
					}

					break;
				case OTHER_NUMBAR:
					int btn_number;
					do //����������͹��ܵ��÷�ѭ��
					{
						newmouse(&MouseX, &MouseY, &press);
						/* ���ܼ���ʵ��ģ�� */
						btn_number = testdo_mainbt(state_bt, &ch, history, &currenthead, ph, pc_for_dir,
												   mainfile_ch_dsplstate, currenthead, search, paste, ph_for_paste,
												   textipt, page, judge_paste, judge_search);
						if (btn_number == BTN_NO_USE)
						{
							/* ʲô������ */
						}
						else if (btn_number == L_ARROW_BTN || btn_number == UP_ARROE_BTN)
						{
							if (judge_search != 0) //��������ģʽ
							{
								page[SEARCH_NUMBER] = 0;
								judge_search = 0; //�˳�����ģʽ
							}
							page[MAINFILE_NUMBAR] = 0;
							refresh_mode = REFRESH_MAINFILE_ONLY;
							break;
						}
						else if (btn_number == R_ARROE_BTN)
						{
							refresh_mode = REFRESH_MAINFILE_ONLY;
							page[MAINFILE_NUMBAR] = 0;
							break;
						}
						else if (btn_number == LISTDISPLAY_BTN || btn_number == ICONDISPLAY_BTN ||
								 btn_number == NEWDIR_BTN || btn_number == NEWFILE_BTN ||
								 btn_number == DELETE_BTN || btn_number == PASTE_BTN)
						{
							if (judge_search == 0)
							{
								refresh_mode = REFRESH_MAINFILE_ONLY;
							}
							break;
						}
						else if (btn_number == MAIN_NEXTPAGE_BTN || btn_number == MAIN_LASTPAGE_BTN)
						{
							if (judge_search == 0)
							{
								refresh_mode = REFRESH_MAINFILE_ONLY;
							}
							else
							{
								refresh_mode = REFRESH_MAINFILE_SEARCHMODE_ONLY;
							}
							break;
						}
						else if (btn_number == TREE_NEXTPAGE_BTN || btn_number == TREE_LASTPAGE_BTN)
						{
							refresh_mode = REFRESH_TREEFILE_ONLY;
							break;
						}
						else if (btn_number == CLOSE_BTN)
						{
							/* �˳����ͷź��� */
							// sleep(1); //��ʱ1s
							close_init(p0, ph, pc, p0_for_dir, ph_for_dir, pc_for_dir,
									   p0_for_paste, ph_for_paste, pc_for_paste, paste,
									   history, search);
							closesvga256();
							chdir("C:\\win_pro\\SRC\\"); //������һ�δ�
							return 0;
						}
						else if (btn_number == SEARCH_BAR)
						{
							/* �������� */
							if (strlen(textipt) != 0)
							{
								refresh_mode = REFRESH_MAINFILE_SEARCHMODE_ONLY;
								page[SEARCH_NUMBER] = 0;
								page[SEARCH_NUMBER_CTT] = -1; //����ģʽ��ʼ��
								break;
							}
						}
						else if (btn_number == CUT_BTN || btn_number == COPY_BTN)
						{
							judge_paste = btn_number;
							break;
						}
						else if (btn_number == REFRESH_BTN)
						{
							if (judge_search != 0)
							{
								judge_search = 0;
							}
							refresh_mode = REFRESH_ALL;
							break;
						}
						else if (btn_number == ADDRESS_BAR)
						{
							if (chdir(textipt) == -1) //·����Ч
							{
								pop_error(0, "MAIN:", "illegle address.");
								write_imagedata(164, 138, 816, 160, "IMDATA_0");
								break;
							}
							else
							{
								if (judge_search != 0) //��������ģʽ
								{
									page[SEARCH_NUMBER] = 0;
									judge_search = 0; //�˳�����ģʽ
								}
								ch = find_node_by_path(ph, textipt);
								move_dir(history, &currenthead, 'n', ch->father);
								settype_dirdisplay(&(ch->flag), gettype_dirdisplay(ph->flag));
								refresh_mode = REFRESH_MAINFILE_ONLY;
								break;
							}
						}
						else if (btn_number == DOWN_ARROW_BTN)
						{
							refresh_mode = REFRESH_MAINFILE_ONLY; //��Ҫˢ����ʾ

							page[MAINFILE_NUMBAR] = 0;
							judge_search = 0;
							break;
						}
						testbtnstate_mouse(state_bt); //���
						refreshbtnstate(state_bt);
						changemouse_write(848, 137, 1016, 161, CURSORWRITE_NOTINPUT_MODE);
					} while (testmouse_wherenow(MouseX, MouseY) == OTHER_NUMBAR);
					for (i = 0; i < 20; i++)
					{
						set0onebit(&state_bt[i], IFH_N);
					}
					break;
				}
				if (refresh_mode != REFRESH_NOTATALL)
				{
					break;
				}
			}
		}
	}
}