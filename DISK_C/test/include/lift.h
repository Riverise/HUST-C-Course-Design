#ifndef _lift_h_
#define _lift_h_
typedef struct
{
	int flo;  //�ȴ���Ӧ�ĺ�������¥����,-5��ʾ�ޣ�0���Ǹ�һ�㣬5���ǵ����
	double L_eqtime;  //�������Ӧ����¥��ĵ�Чʱ��
	double R_eqtime;	
	int L_revert;		//�������Ӧ����¥������Ҫ���ⷴ��Ĵ���
	int R_revert;
	int L_respond;		//�������Ӧ����¥��;����Ҫ�ȴ�����Ӧ����
	int R_respond;

}waitinfo;

typedef struct
{
	int num;   //1��ʾ����ݣ�0��ʾ�ҵ���
	int path[13];    //������ѡָ����Ƶ�Ŀ��¥�㣬0��ͣ��1Ҫͣ��
	int cur;    //current_place
	int pstop[13];  // ���ݺ�����ѡָ�1 for stop ,0 for non-stop, default 0
	int condition; //0������1���ϣ�-1����
	int post_condition;  //1��ʾ��Ҫ���ϣ�-1��ʾ��Ҫ����
//	int weight;
	int flag;         //0��ʾ�ǵ�һ����Ӧ��1��ʾ���ǵ�һ����Ӧ
}liftinfo;

typedef struct
{
	int call[13];   //1���ϣ�-1����,3Ϊ�������£�0û��
	waitinfo wait[13];
	liftinfo liftL;
	liftinfo liftR;	
}   liftsys;



void revertime(liftsys *p,int i);
void deploy(liftsys *p);
void condition_logic(liftsys *p);
int cartoon(liftsys *p);

#endif

