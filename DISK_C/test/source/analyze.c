#include "lift.h"
#include "overmode.h"
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>





void revertime(liftsys *p, int i) //���ݲ�ͬ�龰�ж���̨���ݷֱ���Ӧ�����������⣩��Ҫ����Ĵ���
{
	int j;	
		//�ܽ���ѭ����i��¥�ĺ���ֵcall[i]ֻ������ȡֵ��1��-1��3,����������i��ʾ��i�����������Ӧ��������¥������¥������Ӧ�ı�����p->wait[i].flo

		//�ȷ�������ݣ��ҵ�����֮�Գ�
		if (p->liftL.condition == 0)  //������ݾ�ֹ
		{
			if (p->liftL.flag == 0)   //����ǵ�һ�η�����Ӧ
			{
				p->wait[i].L_revert = 0;
				//p->liftL.flag = 1;  not ought fo assign flag as 1 here, but deploying.
				j = p->wait[0].flo;   //�����״ε���Ӧ�ж�

				if (p->wait[i].flo > p->liftL.cur)  //���Ŀ��¥����ڵ�������¥��
				{
					//p->liftL.condition = 1;	����ֻ��Ԥ��һ�����򣬲���ֱ��ȷ����ȷ�����з������ڷ���������������

					if (p->call[p->wait[i].flo] == 1)
						p->liftL.post_condition = 1;
					else if (p->call[p->wait[i].flo] == -1)
						p->liftL.post_condition = -1;
					else
						p->liftL.post_condition = 1;
				}
				else if (p->wait[i].flo < p->liftL.cur)
				{
					//p->liftL.condition = -1; ����ֻ��Ԥ��һ�����򣬲���ֱ��ȷ����ȷ�����з������ڷ���������������

					if (p->call[p->wait[i].flo] == 1)
						p->liftL.post_condition = 1;
					else if (p->call[p->wait[i].flo] == -1)
						p->liftL.post_condition = -1;
					else
						p->liftL.post_condition = -1;
				}
				else
				{
					if (p->call[p->wait[i].flo] != 3)	p->liftL.post_condition = p->call[p->wait[i].flo];
					else                    p->liftL.post_condition = 1;					
				}
			}
			else if(p->liftL.flag == 1)
			{
				if (j > p->liftL.cur)
				{
					if (p->liftL.post_condition == 1)
					{
						if (p->wait[i].flo > j)
						{
							if (p->call[p->wait[i].flo] == 1)	p->wait[i].L_revert = 0;
							else if (p->call[p->wait[i].flo] == -1) p->wait[i].L_revert = 1;
							else    p->wait[i].L_revert == 0;
						}
						else if (p->wait[i].flo < p->liftL.cur)
						{
							switch (p->call[p->wait[i].flo])
							{
							case 1:
								p->wait[i].L_revert = 2;
								break;
							case -1:
								p->wait[i].L_revert = 1;
								break;
							case 3:
								p->wait[i].L_revert = 1;
								break;
							}
						}
						else  //�˴��е����ϵͳ�ĸо������ܲ�׼ȷ����������˵��Ӧ������ȥ�����֧
						{
							switch (p->call[p->wait[i].flo])   
							{
							case 1:
								p->wait[i].L_revert = 0;
								break;
							case -1:
								p->wait[i].L_revert = 1;
								break;
							case 3:
								p->wait[i].L_revert = 0;
								break;
							}
						}

					}
					else if (p->liftL.post_condition == -1)
					{
						if (p->wait[i].flo > j)
						{
							switch (p->call[p->wait[i].flo])
							{
							case 1:
								p->wait[i].L_revert = 1;
								break;
							case -1:
								p->wait[i].L_revert = 2;
								break;
							case 3:
								p->wait[i].L_revert = 1;
								break;
							}
						}
						else if (p->wait[i].flo < p->liftL.cur)
						{
							switch (p->call[p->wait[i].flo])
							{
							case 1:
								p->wait[i].L_revert = 1;
								break;
							case -1:
								p->wait[i].L_revert = 0;
								break;
							case 3:
								p->wait[i].L_revert = 0;
								break;
							}

						}
						else
						{
							switch (p->call[p->wait[i].flo])
							{
							case 1:
								p->wait[i].L_revert = 0;
								break;
							case -1:
								p->wait[i].L_revert = 1;
								break;
							case 3:
								p->wait[i].L_revert = 0;
								break;
							}
						}
					}
				}
				else if (j < p->liftL.cur)
				{
					if (p->liftL.post_condition == -1)
					{
						if (p->wait[i].flo < j)
						{
							switch (p->call[p->wait[i].flo])
							{
							case 1:
								p->wait[i].L_revert = 1;
								break;
							case -1:
								p->wait[i].L_revert = 0;
								break;
							case 3:
								p->wait[i].L_revert = 0;
								break;
							}

						}
						else if (p->wait[i].flo > p->liftL.cur)
						{
							switch (p->call[p->wait[i].flo])
							{
							case 1:
								p->wait[i].L_revert = 1;
								break;
							case -1:
								p->wait[i].L_revert = 2;
								break;
							case 3:
								p->wait[i].L_revert = 1
;
								break;
							}
						}
						else
						{
							switch (p->call[p->wait[i].flo])
							{
							case 1:
								p->wait[i].L_revert = 1;
								break;
							case -1:
								p->wait[i].L_revert = 0;
								break;
							case 3:
								p->wait[i].L_revert = 0;
								break;
							}
						}
					}
					else if (p->liftL.post_condition == 1)
					{
						if (p->wait[i].flo < j)
						{
							switch (p->call[p->wait[i].flo])
							{
							case 1:
								p->wait[i].L_revert = 2;
								break;
							case -1:
								p->wait[i].L_revert = 1;
								break;
							case 3:
								p->wait[i].L_revert = 1;
								break;
							}
						}
						else if (p->wait[i].flo > p->liftL.cur)
						{
							switch (p->call[p->wait[i].flo])
							{
							case 1:
								p->wait[i].L_revert = 0;
								break;
							case -1:
								p->wait[i].L_revert = 1
;
								break;
							case 3:
								p->wait[i].L_revert = 0;
								break;
							}
						}

						{
							switch (p->call[p->wait[i].flo])
							{
							case 1:
								p->wait[i].L_revert = 1;
								break;
							case -1:
								p->wait[i].L_revert = 0;
								break;
							case 3:
								p->wait[i].L_revert = 0;
								break;
							}
						}
					}
				}
			}
		}
		else if (p->liftL.condition == 1)   //�������������������
		{
			if (p->wait[i].flo > p->liftL.cur)
		{
			switch (p->call[p->wait[i].flo])
			{
			case 1:
				p->wait[i].L_revert = 0;
				break;
			case -1:
				p->wait[i].L_revert = 1;
				break;
			case 3:
				p->wait[i].L_revert = 0;
				break;
			}
		}
			else if (p->wait[i].flo == p->liftL.cur)
		{
			switch (p->call[p->wait[i].flo])
			{
			case 1:
				p->wait[i].L_revert = 2;
				break;
			case -1:
				p->wait[i].L_revert = 1;
				break;
			case 3:
				p->wait[i].L_revert = 1;
				break;
			}
		}
			else if (p->wait[i].flo < p->liftL.cur)
		{
			switch (p->call[p->wait[i].flo])
			{
			case 1:
				p->wait[i].L_revert = 2;
				break;
			case -1:
				p->wait[i].L_revert = 1;
				break;
			case 3:
				p->wait[i].L_revert = 1;
				break;
			}
		}		
		}
		else if (p->liftL.condition == -1)  //���������������
		{
			if (p->wait[i].flo < p->liftL.cur)
			{
				switch (p->call[p->wait[i].flo])
				{
				case 1:
					p->wait[i].L_revert = 1;
					break;
				case -1:
					p->wait[i].L_revert = 0;
					break;
				case 3:
					p->wait[i].L_revert = 0;
					break;
				}
			}
			else
			{
				switch (p->call[p->wait[i].flo])
				{
				case 1:
					p->wait[i].L_revert = 1;
					break;
				case -1:
					p->wait[i].L_revert = 2;
					break;
				case 3:
					p->wait[i].L_revert = 1;
					break;
				}
			}
		}

		
		//�����ҵ�����Ӧ������������Ķ��ⷴ����
		if (p->liftR.condition == 0)  //������ݾ�ֹ
		{
			if (p->liftR.flag == 0)   //����ǵ�һ�η�����Ӧ
			{
				p->wait[i].R_revert = 0;
			//	p->liftR.flag = 1;
				j = p->wait[0].flo;   //�����״ε���Ӧ�ж�

				if (p->wait[i].flo > p->liftR.cur)  //���Ŀ��¥����ڵ�������¥��
				{
					//p->liftR.condition = 1;	����ֻ��Ԥ��һ�����򣬲���ֱ��ȷ����ȷ�����з������ڷ���������������

					if (p->call[p->wait[i].flo] == 1)
						p->liftR.post_condition = 1;
					else if (p->call[p->wait[i].flo] == -1)
						p->liftR.post_condition = -1;
					else
						p->liftR.post_condition = 1;
				}
				else if (p->wait[i].flo < p->liftR.cur)
				{
					//p->liftR.condition = -1; ����ֻ��Ԥ��һ�����򣬲���ֱ��ȷ����ȷ�����з������ڷ���������������

					if (p->call[p->wait[i].flo] == 1)
						p->liftR.post_condition = 1;
					else if (p->call[p->wait[i].flo] == -1)
						p->liftR.post_condition = -1;
					else
						p->liftR.post_condition = -1;
				}
				else
				{
					if (p->call[p->wait[i].flo] != 3)	p->liftR.post_condition = p->call[p->wait[i].flo];
					else                    p->liftR.post_condition = 1;
				}
			}
			else if(p->liftR.flag == 1)
			{
				if (j > p->liftR.cur)
				{
					if (p->liftR.post_condition == 1)
					{
						if (p->wait[i].flo > j)
						{
							if (p->call[p->wait[i].flo] == 1)	p->wait[i].R_revert = 0;
							else if (p->call[p->wait[i].flo] == -1) p->wait[i].R_revert = 1;
							else    p->wait[i].R_revert == 0;
						}
						else if (p->wait[i].flo < p->liftR.cur)
						{
							switch (p->call[p->wait[i].flo])
							{
							case 1:
								p->wait[i].R_revert = 2;
								break;
							case -1:
								p->wait[i].R_revert = 1;
								break;
							case 3:
								p->wait[i].R_revert = 1;
								break;
							}
						}
						else  //�˴��е����ϵͳ�ĸо������ܲ�׼ȷ����������˵��Ӧ������ȥ�����֧
						{
							switch (p->call[p->wait[i].flo])
							{
							case 1:
								p->wait[i].R_revert = 0;
								break;
							case -1:
								p->wait[i].R_revert = 1;
								break;
							case 3:
								p->wait[i].R_revert = 0;
								break;
							}
						}

					}
					else if (p->liftR.post_condition == -1)
					{
						if (p->wait[i].flo > j)
						{
							switch (p->call[p->wait[i].flo])
							{
							case 1:
								p->wait[i].R_revert = 1;
								break;
							case -1:
								p->wait[i].R_revert = 2;
								break;
							case 3:
								p->wait[i].R_revert = 1;
								break;
							}
						}
						else if (p->wait[i].flo < p->liftR.cur)
						{
							switch (p->call[p->wait[i].flo])
							{
							case 1:
								p->wait[i].R_revert = 1;
								break;
							case -1:
								p->wait[i].R_revert = 0;
								break;
							case 3:
								p->wait[i].R_revert = 0;
								break;
							}

						}
						else
						{
							switch (p->call[p->wait[i].flo])
							{
							case 1:
								p->wait[i].R_revert = 0;
								break;
							case -1:
								p->wait[i].R_revert = 1;
								break;
							case 3:
								p->wait[i].R_revert = 0;
								break;
							}
						}
					}
				}
				else if (j < p->liftR.cur)
				{
					if (p->liftR.post_condition == -1)
					{
						if (p->wait[i].flo < j)
						{
							switch (p->call[p->wait[i].flo])
							{
							case 1:
								p->wait[i].R_revert = 1;
								break;
							case -1:
								p->wait[i].R_revert = 0;
								break;
							case 3:
								p->wait[i].R_revert = 0;
								break;
							}

						}
						else if (p->wait[i].flo > p->liftR.cur)
						{
							switch (p->call[p->wait[i].flo])
							{
							case 1:
								p->wait[i].R_revert = 1;
								break;
							case -1:
								p->wait[i].R_revert = 2;
								break;
							case 3:
								p->wait[i].R_revert = 1
									;
								break;
							}
						}
						else
						{
							switch (p->call[p->wait[i].flo])
							{
							case 1:
								p->wait[i].R_revert = 1;
								break;
							case -1:
								p->wait[i].R_revert = 0;
								break;
							case 3:
								p->wait[i].R_revert = 0;
								break;
							}
						}
					}
					else if (p->liftR.post_condition == 1)
					{
						if (p->wait[i].flo < j)
						{
							switch (p->call[p->wait[i].flo])
							{
							case 1:
								p->wait[i].R_revert = 2;
								break;
							case -1:
								p->wait[i].R_revert = 1;
								break;
							case 3:
								p->wait[i].R_revert = 1;
								break;
							}
						}
						else if (p->wait[i].flo > p->liftR.cur)
						{
							switch (p->call[p->wait[i].flo])
							{
							case 1:
								p->wait[i].R_revert = 0;
								break;
							case -1:
								p->wait[i].R_revert = 1
									;
								break;
							case 3:
								p->wait[i].R_revert = 0;
								break;
							}
						}

						{
							switch (p->call[p->wait[i].flo])
							{
							case 1:
								p->wait[i].R_revert = 1;
								break;
							case -1:
								p->wait[i].R_revert = 0;
								break;
							case 3:
								p->wait[i].R_revert = 0;
								break;
							}
						}
					}
				}
			}
		}
		else if (p->liftR.condition == 1)   //�������������������
		{
			if (p->wait[i].flo > p->liftR.cur)
			{
				switch (p->call[p->wait[i].flo])
				{
				case 1:
					p->wait[i].R_revert = 0;
					break;
				case -1:
					p->wait[i].R_revert = 1;
					break;
				case 3:
					p->wait[i].R_revert = 0;
					break;
				}
			}
			else if (p->wait[i].flo == p->liftR.cur)
			{
				switch (p->call[p->wait[i].flo])
				{
				case 1:
					p->wait[i].R_revert = 2;
					break;
				case -1:
					p->wait[i].R_revert = 1;
					break;
				case 3:
					p->wait[i].R_revert = 1;
					break;
				}
			}
			else if (p->wait[i].flo < p->liftR.cur)
			{
				switch (p->call[p->wait[i].flo])
				{
				case 1:
					p->wait[i].R_revert = 2;
					break;
				case -1:
					p->wait[i].R_revert = 1;
					break;
				case 3:
					p->wait[i].R_revert = 1;
					break;
				}
			}
		}
		else if (p->liftR.condition == -1)  //���������������
		{
			if (p->wait[i].flo < p->liftR.cur)
			{
				switch (p->call[p->wait[i].flo])
				{
				case 1:
					p->wait[i].R_revert = 1;
					break;
				case -1:
					p->wait[i].R_revert = 0;
					break;
				case 3:
					p->wait[i].R_revert = 0;
					break;
				}
			}
			else
			{
				switch (p->call[p->wait[i].flo])
				{
				case 1:
					p->wait[i].R_revert = 1;
					break;
				case -1:
					p->wait[i].R_revert = 2;
					break;
				case 3:
					p->wait[i].R_revert = 1;
					break;
				}
			}
		}
}

void deploy(liftsys *p)
{
	//���õ�Чʱ�䷨����ÿ̨������Ӧ���е�ʱ�䣬�����з������Чʱ����̵ĵ���
	//��Ϊǰ����Ӧ�ķ����Ӱ�쵽������еķ��䣬���������������������Խ�ǿ���ʷ���һ��ѭ����ͬʱ����
	int i,j;
	int RUN_T;//ֱ�����й�ÿһ��¥����ʱ�䣬direct
	int RSP_T; //��Ӧÿһ����ѡָ��������źŵ�ʱ��,respond
	int RVS_T; //���ⷴһ�����������ĵ�ʱ�䣬reverse
	char s[100];
	FILE *fp;

	if ((fp = fopen("C:\\test\\material\\liftdata.txt", "rt")) == NULL)
	{
		printf("wrong operation,any button to quit");
		getch();
		exit(0);
	}

	fscanf(fp, "%s%d", s, &RUN_T);
	fscanf(fp, "%s%d", s, &RSP_T);
	fscanf(fp, "%s%d", s, &RVS_T);
	fclose(fp);
	

	for (i = 0;  p->wait[i].flo != -5; i++)
	{
		//���ݲ�ͬ�龰�ж���̨���ݷֱ���Ӧ��i�������������⣩��Ҫ����Ĵ���
		revertime(p, i);
		//�������ҵ�����Ӧ����¥���е�Чʱ��ĵȴ���Ӧ��
		if (p->wait[i].flo > p->liftL.cur)  //�������¥���ڵ�ǰ¥�����棬���Է����������ѿ��ǣ���������ͣ���Ĵ���
		{
			for (j = p->liftL.cur;  j < p->wait[i].flo; j++)
			{
				if (p->liftL.pstop[j] == 1)		p->wait[i].L_respond++;
				if (p->liftL.path[j] == 1)		p->wait[i].L_respond++;
				if (p->liftL.pstop[j] == 1 && p->liftL.path[j] == 1)	p->wait[i].L_respond--;
			}			
		}
		if (p->wait[i].flo < p->liftL.cur)
		{
			for (j = p->liftL.cur; j > p->wait[i].flo; j--)
			{
				if (p->liftL.pstop[j] == 1)		p->wait[i].L_respond++;
				if (p->liftL.path[j] == 1)		p->wait[i].L_respond++;
				if (p->liftL.pstop[j] == 1 && p->liftL.path[j] == 1)	p->wait[i].L_respond--;
			}
		}
		if (p->wait[i].flo > p->liftR.cur)  //�������¥���ڵ�ǰ¥�����棬���Է����������ѿ��ǣ���������ͣ���Ĵ���
		{
			for (j = p->liftR.cur;  j < p->wait[i].flo; j++)
			{
				if (p->liftR.pstop[j]== 1)		p->wait[i].R_respond++;
				if (p->liftR.path[j] == 1)		p->wait[i].R_respond++;
				if (p->liftR.pstop[j] == 1 && p->liftR.path[j] == 1)	p->wait[i].R_respond--;
			}
		}
		if (p->wait[i].flo < p->liftR.cur)
		{
			for (j = p->liftR.cur;  j > p->wait[i].flo; j--)
			{
				if (p->liftR.pstop[j] == 1)		p->wait[i].R_respond++;
				if (p->liftR.path[j] == 1)		p->wait[i].R_respond++;
				if (p->liftR.pstop[j] == 1 && p->liftR.path[j] == 1)	p->wait[i].R_respond--;
			}
		}


		//�Ⱥ�������ҵ��ݵĵ�Чʱ��
		p->wait[i].L_eqtime = RUN_T * abs(p->wait[i].flo - p->liftL.cur) + RSP_T * p->wait[i].L_respond + RVS_T * p->wait[i].L_revert;
		p->wait[i].R_eqtime = RUN_T * abs(p->wait[i].flo - p->liftR.cur) + RSP_T * p->wait[i].R_respond + RVS_T * p->wait[i].R_revert;

		//�������񣬵�ʱ����ͬʱ�����ȷ���������

		//�˴���Ϊ�յ������ܵ㣬�Ȳ���һ�飬��ע�͵�
		/*if (p->wait[i].flo == 0) //process specially for -1F
		{
			p->liftL.pstop[p->wait[i].flo] = 1;
			if (p->liftL.flag == 0) p->liftL.flag = 1;
		}
		else
		{*/
			if (p->wait[i].L_eqtime > p->wait[i].R_eqtime)//deploy to the right lift
			{
				p->liftR.pstop[p->wait[i].flo] = 1;
				if (p->liftR.flag == 0) p->liftR.flag = 1;
			}

			else//deploy to the left lift
			{
				p->liftL.pstop[p->wait[i].flo] = 1;
				if (p->liftL.flag == 0) p->liftL.flag = 1;
			}
		//}

		p->wait[i].flo = -5;  //ÿ���һ�η��䣬��ʼ��Ϊ-5
		p->wait[i].L_respond = 0;  //ÿ����ɼ�������Ϊ�Ѿ��������ã�������������㣩�������㣬�Թ����ֺ���ʹ��
		p->wait[i].R_respond = 0;  

	}
}

void condition_logic(liftsys *p)
{

	int i, m1, m2, mindex1, mindex2, flag11, flag12, flag21, flag22, flag1, flag2;//flag1/2 shows if there is any request to be responded beneath the Maxflo or over the MInflo
	int  Max1, Max2, Min1, Min2;
	int access1, access2;//ֻ��accessΪ1���������������ڻ�����ʱ�����ڵ��ݾ�ֹʱ����condition���жϣ����򣬽�condition����
	int dis[13] = { 0 };
	int Lpstop[13] = { 0 }, Lpath[13] = { 0 }, Rpstop[13] = { 0 }, Rpath[13] = { 0 };//������condition�߼��жϵĸ���
	flag11 = 0; 
	flag12 = 0;
	flag21 = 0;
	flag22 = 0;
	access1 = 0;
	access2 = 0;
	flag1 = 0;
	flag2 = 0;
	Max1 = 0;
	Max2 = 0;
	Min1 = 12;
	Min2 = 12;
	/*�����ڵ���
	p->call[5] = 1;
	p->liftL.pstop[5] = 1;
	*/

	for (i = 0; i < 13; i++)
	{
		if (p->liftL.pstop[i] == 1 || p->liftL.path[i] == 1)
		{
			access1 = 1;
			break;
		}
	}
	for (i = 0; i < 13; i++)
	{
		if (p->liftR.pstop[i] == 1 || p->liftR.path[i] == 1)
		{
			access2 = 1;
			break;
		}
	}
	for (i = 0; i < 13; i++)
	{
		Lpstop[i] = p->liftL.pstop[i];
		Lpath[i] = p->liftL.path[i];
		Rpstop[i] = p->liftR.pstop[i];
		Rpath[i] = p->liftR.path[i];
	}

	if (p->liftL.condition == 0 && access1 == 1)
	{

		
		for (i = 0; i < 13; i++)	dis[i] = 13;

		for (i = 0; i < 13; i++)
		{
			if (p->liftL.pstop[i] == 1 && i != p->liftL.cur)	dis[i] = abs(i - p->liftL.cur);//���������к�������Ĳ���������λ�õľ���
			else if (p->liftL.pstop[i] == 1 && i == p->liftL.cur) dis[i] = 13;
		}

		m1 = dis[0];
		mindex1 = 0;
		for (i = 1; i < 13; i++)
		{
			if (dis[i] < m1)
			{
				m1 = dis[i];
				mindex1 = i;
			}
		}    //find the closest floor��mindex
		if (p->liftL.pstop[p->liftL.cur] == 1)//dispose specially
		{
			switch (p->call[p->liftL.cur])
			{
			case 1:
				p->liftL.condition = 1;
				break;

			case -1:
				p->liftL.condition = -1;
				break;

			case 3:
				if (mindex1 > p->liftL.cur)		p->liftL.condition = 1;
				else if (mindex1 < p->liftL.cur) p->liftL.condition = -1;
				break;
			}
			//inside operate
			p->liftL.pstop[p->liftL.cur] = 0;
			p->call[p->liftL.cur] = 0;
			delay(500);//pausing time to be reconsidered

			inside(&p->liftL);//to avoid going against the cartoon function
			drawpage(p);
		}
		else if (p->liftL.pstop[p->liftL.cur] == 0)
		{
			if (mindex1 > p->liftL.cur)		p->liftL.condition = 1;
			else if (mindex1 < p->liftL.cur) p->liftL.condition = -1;  //��ʲô��û�ɣ�condition�ڴ˴�����Ϊ-1
		}
	}
	else if (p->liftL.condition == 1)  //�������������������
	{
		for (i = p->liftL.cur; i < 13; i++)
		{
			if (p->liftL.pstop[i] == 1 || p->liftL.path[i] == 1)
			{
				flag11 = 1;
				Max1 = i;
			}						
		}
		if (flag11 == 0)	Max1 = p->liftL.cur;

	

		

		//�м�Ӧ�е������й��̣����һ����/�����󣬾ͻ�����һ���ź�
		//��Ϊ�˴���ķ�װ�ԣ������ȼ��������źţ������������ٻָ��ź�
		//���������ź�ʱ�������Ķ�����cur��Max֮�����е�path[i]==1��path�ź���pstop[i]==1&&call[i]==1/3��pstop�ź�

		for (i = p->liftL.cur; i <= Max1; i++)
		{
			Lpath[i] = 0;
			if (Lpstop[i] == 1 && (p->call[i] == 1 || p->call[i] == 3))	Lpstop[i] = 0;
		}

		for (i = 0; i <= Max1; i++)
		{
			if (Lpstop[i] == 1 || Lpath[i] == 1)
			{
				flag1 = 1;  //��ʾMax¥���»������ٻ�����
				break;
			}
		}
		if (p->liftL.cur == Max1 && flag1 == 0)		p->liftL.condition = 0;// delay(100);
		else if (p->liftL.cur == Max1 && flag1 == 1)	p->liftL.condition = -1;
	}
	else if (p->liftL.condition == -1)
	{
		for (i = p->liftL.cur; i >= 0; i--)
		{
			if (p->liftL.pstop[i] == 1 || p->liftL.path[i] == 1)
			{
				Min1 = i;
				flag12 = 1;
			}
			
		}
		if (flag12 == 0)	Min1 = p->liftL.cur;

		for (i = p->liftL.cur; i >= Min1; i--)
		{
			Lpath[i] = 0;
			if (Lpstop[i] == 1 && (p->call[i] == -1 || p->call[i] == 3))	Lpstop[i] = 0;
		}//��������

		for (i = Min1; i < 13; i++)
		{
			if (Lpstop[i] == 1 || Lpath[i] == 1)
			{
				flag1 = 1;  //��ʾMin¥���ϻ������ٻ�����
				break;
			}
		}
		if (p->liftL.cur == Min1 && flag1 == 0)		p->liftL.condition = 0;
		else if (p->liftL.cur == Min1 && flag1 == 1)	p->liftL.condition = 1;

	}
	
	if (p->liftR.condition == 0 && access2 == 1)
	{

		for (i = 0; i < 13; i++)	dis[i] = 13;

		for (i = 0; i < 13; i++)
		{
			if (p->liftR.pstop[i] == 1 && i != p->liftR.cur)	dis[i] = abs(i - p->liftR.cur);
			else if (p->liftR.pstop[i] == 1 && i == p->liftR.cur) dis[i] = 13;
		}

		m2 = dis[0];
		mindex2 = 0;
		for (i = 1; i < 13; i++)
		{
			if (dis[i] < m2)
			{
				m2 = dis[i];
				mindex2 = i;
			}
		}    //������¥������Ѱ�ң�mindex
		if (p->liftR.pstop[p->liftR.cur] == 1)
		{
			switch (p->call[p->liftR.cur])
			{
			case 1:
				p->liftR.condition = 1;
				break;

			case -1:
				p->liftR.condition = -1;
				break;

			case 3:
				if (mindex2 > p->liftR.cur)		p->liftR.condition = 1;
				else if (mindex2 < p->liftR.cur) p->liftR.condition = -1;
				break;
			}
			p->liftR.pstop[p->liftR.cur] = 0;
			p->call[p->liftR.cur] = 0;
			delay(500);//pausing time to be reconsidered
			inside(&p->liftR);
			drawpage(p);
		}
		else if (p->liftR.pstop[p->liftR.cur] != 1)
		{
			if (mindex2 > p->liftR.cur)		p->liftR.condition = 1;
			else if (mindex2 < p->liftR.cur) p->liftR.condition = -1;
		}
	}
	else if (p->liftR.condition == 1)  //�������������������
	{
		for (i = p->liftR.cur; i < 13; i++)
		{
			if (p->liftR.pstop[i] == 1 || p->liftR.path[i] == 1)
			{
				Max2 = i;
				flag21 = 1;
			}
			
		}
		if (flag21 == 0)	Max2 = p->liftR.cur;
		for (i = p->liftR.cur; i <= Max2; i++)
		{
			Rpath[i] = 0;
			if (Rpstop[i] == 1 && (p->call[i] == 1 || p->call[i] == 3))	Rpstop[i] = 0;
		}

		for (i = 0; i <= Max2; i++)
		{
			if (Rpstop[i] == 1 || Rpath[i] == 1)
			{
				flag2 = 1;  //��ʾMax¥���»������ٻ�����
				break;
			}
		}
		if (p->liftR.cur == Max2 && flag2 == 0)		p->liftR.condition = 0;
		else if (p->liftR.cur == Max2 && flag2 == 1)	p->liftR.condition = -1;
	}
	else if (p->liftR.condition == -1)
	{
		for (i = p->liftR.cur; i >= 0; i--)
		{
			if (p->liftR.pstop[i] == 1 || p->liftR.path[i] == 1)
			{
				Min2 = i;
				flag22 = 1;
			}
		}
		if (flag22 == 0)	Min2 = p->liftR.cur;
		for (i = p->liftR.cur; i >= Min2; i--)
		{
			Rpath[i] = 0;
			if (Rpstop[i] == 1 && (p->call[i] == -1 || p->call[i] == 3))	Rpstop[i] = 0;
		}//��������

		for (i = Min2; i < 13; i++)
		{
			if (Rpstop[i] == 1 || Rpath[i] == 1)
			{
				flag2 = 1;  //��ʾMin¥���ϻ������ٻ�����
				break;
			}
		}
		if (p->liftR.cur == Min2 && flag2 == 0)		p->liftR.condition = 0;
		else if (p->liftR.cur == Min2 && flag2 == 1)	p->liftR.condition = 1;

	}
}
