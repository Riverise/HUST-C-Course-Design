#ifndef _lift_h_
#define _lift_h_
typedef struct
{
	int flo;  //等待响应的呼叫所在楼层数,-5表示无，0就是负一层，5就是第五层
	double L_eqtime;  //左电梯响应呼叫楼层的等效时间
	double R_eqtime;	
	int L_revert;		//左电梯响应呼叫楼层所需要额外反向的次数
	int R_revert;
	int L_respond;		//左电梯响应呼叫楼层途中需要等待的响应个数
	int R_respond;

}waitinfo;

typedef struct
{
	int num;   //1表示左电梯，0表示右电梯
	int path[13];    //电梯内选指令控制的目标楼层，0不停，1要停，
	int cur;    //current_place
	int pstop[13];  // 电梯呼叫外选指令，1 for stop ,0 for non-stop, default 0
	int condition; //0不动，1是上，-1是下
	int post_condition;  //1表示将要向上，-1表示将要向下
//	int weight;
	int flag;         //0表示是第一次响应，1表示不是第一次响应
}liftinfo;

typedef struct
{
	int call[13];   //1是上，-1是下,3为又上又下，0没按
	waitinfo wait[13];
	liftinfo liftL;
	liftinfo liftR;	
}   liftsys;



void revertime(liftsys *p,int i);
void deploy(liftsys *p);
void condition_logic(liftsys *p);
int cartoon(liftsys *p);

#endif

