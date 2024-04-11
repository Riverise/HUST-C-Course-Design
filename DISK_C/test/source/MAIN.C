#include <stdio.h>
#include <stdlib.h>
#include "INIT.H"
#include "mouse.h"
#include "getdist2.h"
#include "graphics.h"
#include "left.h"
#include "intro1.h"
#include "quitbutt.h"
#include "overmode.h"  //<lift.h>included
//#include"lift.h"


void main()
{
	liftsys s;   //the elevate system to be studied
	liftsys *p;
	
	int *pnow;
	int now;
	int i;
	int pagenum=1;
	int driver=VGA;
	int mode=VGAHI;

	p = &s;
	pnow = &now;
	

	for (i = 0; i < 13; i++)  //state initialization
	{
		s.call[i] = 0;
		s.liftL.path[i] = 0;
		s.liftR.pstop[i] = 0;
		s.liftL.path[i] = 0;
		s.liftR.pstop[i] = 0;	
		s.wait[i].flo = -5;  //-5 for non-request/calling
		s.wait[i].L_eqtime = 0;
		s.wait[i].R_eqtime = 0;
		s.wait[i].L_respond = 0;
		s.wait[i].L_revert = 0;
		s.wait[i].R_respond = 0;
		s.wait[i].R_revert = 0;
	}
	s.liftL.num = 1;
	s.liftR.num = 0;
	s.liftL.cur = 1;
	s.liftR.cur = 1;
	s.liftL.condition = 0;
	s.liftR.condition = 0;
	s.liftL.post_condition = 0;
	s.liftR.post_condition = 0;
	s.liftL.flag = 0;
	s.liftR.flag = 0;
	now = 1;

	
	
	initgraph(&driver,&mode,"c:\\borlandc\\bgi");
	mouseinit();
	clrmous(MouseX,MouseY);
	delay(500);	
	
	while(1)
	{
		switch(pagenum)
		{
			case 1:
				pagenum=welcome();  //mainpage
				break;

			case 2:
				pagenum = intro1(); //introduction for the passenger mode
				break;

			case 3:
				pagenum = passmode();//the detailed view of passenger mode
				break;

			case 4:
				pagenum = intro2(); //introduction for the overall mode
				break;

			case 5:
				pagenum = overmode(p); //the overall view of lift system
				break;

			case 6:
				pagenum = calling(p);  //calling page of overmode
				break;

			case 7:
				pagenum = liftrun1(pnow);  //the inside page of leftlift of passmode
				break;

			case 8:
				pagenum = liftrun2(pnow);  //the inside page of leftlift of passmode
				break;

			case 9:
				pagenum = outside();	//outside of the lift of passmode
				break;




		}

			
			
	}
	closegraph();

}


