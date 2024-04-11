#include<iostream>
#include<cstring>
#include<conio.h>
#include<ctime>
#include<windows.h>
using namespace std;
int main()
{
	const int R=20,C=60;
	int i,j,r,c,score;
	char buffer[R+1][C+1]={0};
	for(i=0;i<C;i++)
		buffer[0][i]='=',buffer[R-1][i]='=',buffer[R][i]=' ';
	for(i=0;i<R;i++)
		buffer[i][0]=1,buffer[i][C-1]=1,buffer[i][C]='\n';
	buffer[R][0]='s';
	buffer[R][1]='c';
	buffer[R][2]='o';
	buffer[R][3]='r';
	buffer[R][4]='e';
	buffer[R][C]='\n';
	const int MS=(R-2)*(C-2);
	int sk[MS][2]={0};
	int h=0,t=0;
	int len=0;
	int sy,sx;
	time_t n;
	n=time(&n);	srand(n);	sy=rand()%(R-2)+1;
	n=time(&n);	srand(n+1);	sx=rand()%(C-2)+1;
	sk[t][0]=sy,sk[t][1]=sx;
	t++,len++;
	int ay,ax;
	n=time(&n);	srand(n+1);	ay=rand()%(R-4)+2;
	n=time(&n);	srand(n+2);	ax=rand()%(C-4)+2;
	char play;
	int flag=1;
	HANDLE hOutput=	GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO	cci;
	cci.dwSize=1;	cci.bVisible=0;
	SetConsoleCursorInfo(hOutput,&cci);
	COORD coord={0,0};
	do
	{
		if(buffer[sy][sx]=='*')
			return 0;
		SetConsoleCursorPosition(hOutput,coord);
		score=len-1;
		for(i=0;i<4;i++)
			buffer[R][10-i]=char(48+score%10),score/=10;
		for(r=1;r<R-1;r++)
			for(c=1;c<C-1;c++)
				buffer[r][c]=' ';
		for(j=0;j<len;j++)
		{
			i=(h+j)%MS;
			buffer[sk[i][0]][sk[i][1]]='*';
		}
		buffer[sk[h][0]][sk[h][1]]='+';
		buffer[sy][sx]='o';
		buffer[ay][ax]='@';
		for(r=0;r<R+1;r++)
			for(c=0;c<C+1;c++)
				cout<<buffer[r][c];
		play=getch();
		flag=1;
		switch(play)
		{
		case'w':	case'W':
			sk[t][0]=--sy,sk[t][1]=sx;t=(t+1)%MS;	break;
		case's':	case'S':
			sk[t][0]=++sy,sk[t][1]=sx;t=(t+1)%MS;	break;
		case'a':	case'A':
			sk[t][0]=sy,sk[t][1]=--sx;t=(t+1)%MS;	break;
		case'd':	case'D':
			sk[t][0]=sy,sk[t][1]=++sx;t=(t+1)%MS;	break;
		default:	flag=0;
		}
		if(flag==1)
		{
			if(sy==ay&&sx==ax)
			{
				n=time(&n);	srand(n+1);	ay=rand()%(R-4)+2;
				n=time(&n);	srand(n+2);	ax=rand()%(C-4)+2;
				++len;
			}
			else h=(h+1)%MS;
		}
	}while(play!=' '&&sy!=0&&sy!=R-1&&sx!=0&&sx!=C-1);
	return 0;
}