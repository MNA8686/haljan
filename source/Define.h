
#ifndef __Define__
#define __Define__

//#define FREE(x) 	if(x){free(x);(x)=NULL;}
#define IDELETE(x) 	if(x){delete(x);(x)=NULL;}

#define LOGOPANEL_X 634
#define LOGOPANEL_Y 0

#define MVAL(x) 	((x)<<8)
#define SRCVAL(x) 	((x)>>8)

#define PLAYER_1		0x80000000
#define PLAYER_2		0x40000000
#define PLAYER_3		0x20000000
#define PLAYER_4		0x10000000
#define PLAYER_5		0x08000000
#define PLAYER_6		0x04000000
#define PLAYER_7		0x00800000
#define PLAYER_8		0x00400000
#define PLAYER_9		0x00200000
#define PLAYER_RON		0x00100000
#define PLAYER_PON		0x00080000

#define PLAYER2_BOMB	0x00040000

#define EXITGAME		0x00000001
#define SUBARU			0x00000002
#define SUMERAGI		0x00000004
#define SUZAKU			0x00000008

#define ADDCREDIT		0x00000010
#define FAILEDGAME		0x00000020

#define JIKIPALINDEX	10
#define JIKIPALNUM		90

#define BGPALINDEX		(JIKIPALINDEX + JIKIPALNUM)
#define BGPALNUM		64

#define ENEMYPALINDEX	(BGPALINDEX + BGPALNUM)
#define ENEMYPALNUM		48

#define SCROLL_X		80

#define SCREEN_X	224
#define SCREEN_Y	240


#endif




