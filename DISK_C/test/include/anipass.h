#ifndef _anipass_h_
#define _anipass_h_

typedef struct rizhi
{
	char year[5];
	char month[3];
	char day[3];
	char reason[20];
}DATA;

void doorsopen();
void doorsclose();
void singleopen();
void singleclose();
int numvary(int*now, int want);

int warning();
void yuanyin();
char* zcinput(int x, int y, int l, int flag);

#endif
