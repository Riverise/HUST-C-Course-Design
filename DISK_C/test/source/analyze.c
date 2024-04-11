#include "lift.h"
#include "overmode.h"
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>





void revertime(liftsys *p, int i) //根据不同情景判断两台电梯分别响应呼叫所（额外）需要反向的次数
{
	int j;	
		//能进入循环的i层楼的呼叫值call[i]只有三种取值，1，-1，3,但是在这里i表示第i个待处理的响应，不代表楼层数，楼层数对应的变量是p->wait[i].flo

		//先分析左电梯，右电梯与之对称
		if (p->liftL.condition == 0)  //如果电梯静止
		{
			if (p->liftL.flag == 0)   //如果是第一次分配响应
			{
				p->wait[i].L_revert = 0;
				//p->liftL.flag = 1;  not ought fo assign flag as 1 here, but deploying.
				j = p->wait[0].flo;   //供非首次的响应判断

				if (p->wait[i].flo > p->liftL.cur)  //如果目标楼层高于电梯现在楼层
				{
					//p->liftL.condition = 1;	现在只能预定一个方向，不能直接确定，确定运行方向是在分配完任务后决定的

					if (p->call[p->wait[i].flo] == 1)
						p->liftL.post_condition = 1;
					else if (p->call[p->wait[i].flo] == -1)
						p->liftL.post_condition = -1;
					else
						p->liftL.post_condition = 1;
				}
				else if (p->wait[i].flo < p->liftL.cur)
				{
					//p->liftL.condition = -1; 现在只能预定一个方向，不能直接确定，确定运行方向是在分配完任务后决定的

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
						else  //此处有点混沌系统的感觉，可能不准确，但按理来说，应跳不进去这个分支
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
		else if (p->liftL.condition == 1)   //如果电梯正在向上运行
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
		else if (p->liftL.condition == -1)  //如果电梯向下运行
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

		
		//分析右电梯响应呼叫请求所需的额外反向数
		if (p->liftR.condition == 0)  //如果电梯静止
		{
			if (p->liftR.flag == 0)   //如果是第一次分配响应
			{
				p->wait[i].R_revert = 0;
			//	p->liftR.flag = 1;
				j = p->wait[0].flo;   //供非首次的响应判断

				if (p->wait[i].flo > p->liftR.cur)  //如果目标楼层高于电梯现在楼层
				{
					//p->liftR.condition = 1;	现在只能预定一个方向，不能直接确定，确定运行方向是在分配完任务后决定的

					if (p->call[p->wait[i].flo] == 1)
						p->liftR.post_condition = 1;
					else if (p->call[p->wait[i].flo] == -1)
						p->liftR.post_condition = -1;
					else
						p->liftR.post_condition = 1;
				}
				else if (p->wait[i].flo < p->liftR.cur)
				{
					//p->liftR.condition = -1; 现在只能预定一个方向，不能直接确定，确定运行方向是在分配完任务后决定的

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
						else  //此处有点混沌系统的感觉，可能不准确，但按理来说，应跳不进去这个分支
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
		else if (p->liftR.condition == 1)   //如果电梯正在向上运行
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
		else if (p->liftR.condition == -1)  //如果电梯向下运行
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
	//采用等效时间法计算每台电梯响应呼叫的时间，将呼叫分配给等效时间最短的电梯
	//因为前面响应的分配会影响到后面呼叫的分配，计算与分配两个过程耦合性较强，故放在一个循环内同时处理
	int i,j;
	int RUN_T;//直接运行过每一层楼所用时间，direct
	int RSP_T; //响应每一次内选指令与呼叫信号的时间,respond
	int RVS_T; //额外反一次向所多消耗的时间，reverse
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
		//根据不同情景判断两台电梯分别响应第i个呼叫所（额外）需要反向的次数
		revertime(p, i);
		//计算左右电梯响应呼叫楼层中等效时间的等待响应数
		if (p->wait[i].flo > p->liftL.cur)  //如果呼叫楼层在当前楼层上面，忽略反向的情况（已考虑），计算需停靠的次数
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
		if (p->wait[i].flo > p->liftR.cur)  //如果呼叫楼层在当前楼层上面，忽略反向的情况（已考虑），计算需停靠的次数
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


		//先后计算左右电梯的等效时间
		p->wait[i].L_eqtime = RUN_T * abs(p->wait[i].flo - p->liftL.cur) + RSP_T * p->wait[i].L_respond + RVS_T * p->wait[i].L_revert;
		p->wait[i].R_eqtime = RUN_T * abs(p->wait[i].flo - p->liftR.cur) + RSP_T * p->wait[i].R_respond + RVS_T * p->wait[i].R_revert;

		//分配任务，当时间相同时，优先分配给左电梯

		//此处作为诱导增功能点，先测试一遍，再注释掉
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

		p->wait[i].flo = -5;  //每完成一次分配，初始化为-5
		p->wait[i].L_respond = 0;  //每次完成计数，因为已经发挥作用（参与上面的运算），都置零，以供下轮呼唤使用
		p->wait[i].R_respond = 0;  

	}
}

void condition_logic(liftsys *p)
{

	int i, m1, m2, mindex1, mindex2, flag11, flag12, flag21, flag22, flag1, flag2;//flag1/2 shows if there is any request to be responded beneath the Maxflo or over the MInflo
	int  Max1, Max2, Min1, Min2;
	int access1, access2;//只有access为1（电梯有外召与内唤请求）时，才在电梯静止时进行condition的判断，否则，将condition置零
	int dis[13] = { 0 };
	int Lpstop[13] = { 0 }, Lpath[13] = { 0 }, Rpstop[13] = { 0 }, Rpath[13] = { 0 };//仅用于condition逻辑判断的副本
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
	/*仅用于调试
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
			if (p->liftL.pstop[i] == 1 && i != p->liftL.cur)	dis[i] = abs(i - p->liftL.cur);//计算所有有呼叫请求的层数到电梯位置的距离
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
		}    //find the closest floor：mindex
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
			else if (mindex1 < p->liftL.cur) p->liftL.condition = -1;  //若什么都没干，condition在此处被赋为-1
		}
	}
	else if (p->liftL.condition == 1)  //如果电梯正在向上运行
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

	

		

		//中间应有电梯运行过程，完成一个内/外请求，就会消除一个信号
		//但为了代码的封装性，我们先假设消除信号，分析结束后再恢复信号
		//虚拟消除信号时，消除的对象是cur与Max之间所有的path[i]==1的path信号与pstop[i]==1&&call[i]==1/3的pstop信号

		for (i = p->liftL.cur; i <= Max1; i++)
		{
			Lpath[i] = 0;
			if (Lpstop[i] == 1 && (p->call[i] == 1 || p->call[i] == 3))	Lpstop[i] = 0;
		}

		for (i = 0; i <= Max1; i++)
		{
			if (Lpstop[i] == 1 || Lpath[i] == 1)
			{
				flag1 = 1;  //表示Max楼层下还有内召或外求
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
		}//虚拟置零

		for (i = Min1; i < 13; i++)
		{
			if (Lpstop[i] == 1 || Lpath[i] == 1)
			{
				flag1 = 1;  //表示Min楼层上还有内召或外求
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
		}    //完成最近楼层数的寻找：mindex
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
	else if (p->liftR.condition == 1)  //如果电梯正在向上运行
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
				flag2 = 1;  //表示Max楼层下还有内召或外求
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
		}//虚拟置零

		for (i = Min2; i < 13; i++)
		{
			if (Rpstop[i] == 1 || Rpath[i] == 1)
			{
				flag2 = 1;  //表示Min楼层上还有内召或外求
				break;
			}
		}
		if (p->liftR.cur == Min2 && flag2 == 0)		p->liftR.condition = 0;
		else if (p->liftR.cur == Min2 && flag2 == 1)	p->liftR.condition = 1;

	}
}
