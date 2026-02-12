
#include "MGLInit.h"
#include "haljan.h"
#include "CBattle.h"


//0＝遅刻、1=未済、2=欠席		赤の牌
//3=マシン、4=故障マシン、5=ウイルス	青の牌
//6=サボリ、7=徹夜、8=コピー		黄色の牌

#define PAI_CHIKOKU		0
#define PAI_MISAI		1
#define PAI_KESSEKI		2

#define PAI_MACHINE		3
#define PAI_KOSYOU		4
#define PAI_VIRUS		5

#define PAI_SABORI		6
#define PAI_TETSUYA		7
#define PAI_COPY		8



LONG lInchiki[138][9] = 
{
{0,0,0,0,0,0,0,0,0},	//遅刻の帝王
{0,0,0,0,0,0,1,1,1},	//再提出
{0,0,0,0,0,0,2,2,2},	//再提出
{0,0,0,0,0,0,3,3,3},	//再提出
{0,0,0,0,0,0,4,4,4},	//再提出
{0,0,0,0,0,0,5,5,5},	//再提出
{0,0,0,0,0,0,6,6,6},	//再提出
{0,0,0,0,0,0,7,7,7},	//再提出
{0,0,0,0,0,0,8,8,8},	//再提出
{0,0,0,1,1,1,1,1,1},	//再提出

//10

{0,0,0,1,1,1,2,2,2},	//留年コンボ
{0,0,0,1,1,1,3,3,3},	//中だるみ
{0,0,0,1,1,1,4,4,4},	//中だるみ
{0,0,0,1,1,1,5,5,5},	//中だるみ
{0,0,0,1,1,1,6,6,6},	//未済教室
{0,0,0,1,1,1,7,7,7},	//未済教室
{0,0,0,1,1,1,8,8,8},	//未済教室
{0,0,0,2,2,2,2,2,2},	//再提出
{0,0,0,2,2,2,3,3,3},	//中だるみ
{0,0,0,2,2,2,4,4,4},	//中だるみ

//20

{0,0,0,2,2,2,5,5,5},	//中だるみ
{0,0,0,2,2,2,6,6,6},	//未済教室
{0,0,0,2,2,2,7,7,7},	//未済教室
{0,0,0,2,2,2,8,8,8},	//未済教室
{0,0,0,3,3,3,3,3,3},	//再提出
{0,0,0,3,3,3,4,4,4},	//中だるみ
{0,0,0,3,3,3,5,5,5},	//中だるみ
{0,0,0,4,4,4,4,4,4},	//再提出
{0,0,0,4,4,4,5,5,5},	//中だるみ
{0,0,0,5,5,5,5,5,5},	//再提出

//30

{0,0,0,6,6,6,6,6,6},	//再提出
{0,0,0,6,6,6,7,7,7},	//未済教室
{0,0,0,6,6,6,8,8,8},	//未済教室
{0,0,0,7,7,7,7,7,7},	//再提出
{0,0,0,7,7,7,8,8,8},	//未済教室
{0,0,0,8,8,8,8,8,8},	//再提出
{1,1,1,1,1,1,1,1,1},	//留年確定
{1,1,1,1,1,1,2,2,2},	//再提出
{1,1,1,1,1,1,3,3,3},	//再提出
{1,1,1,1,1,1,4,4,4},	//再提出

//40

{1,1,1,1,1,1,5,5,5},	//再提出
{1,1,1,1,1,1,6,6,6},	//再提出
{1,1,1,1,1,1,7,7,7},	//再提出
{1,1,1,1,1,1,8,8,8},	//再提出
{1,1,1,2,2,2,2,2,2},	//再提出
{1,1,1,2,2,2,3,3,3},	//中だるみ
{1,1,1,2,2,2,4,4,4},	//中だるみ
{1,1,1,2,2,2,5,5,5},	//中だるみ
{1,1,1,2,2,2,6,6,6},	//未済教室
{1,1,1,2,2,2,7,7,7},	//未済教室

//50

{1,1,1,2,2,2,8,8,8},	//未済教室
{1,1,1,3,3,3,3,3,3},	//再提出
{1,1,1,3,3,3,4,4,4},	//中だるみ
{1,1,1,3,3,3,5,5,5},	//中だるみ
{1,1,1,4,4,4,4,4,4},	//再提出
{1,1,1,5,5,5,5,5,5},	//再提出
{1,1,1,5,5,5,5,5,5},	//再提出
{1,1,1,6,6,6,6,6,6},	//再提出
{1,1,1,6,6,6,7,7,7},	//未済教室
{1,1,1,6,6,6,8,8,8},	//未済教室

//60

{1,1,1,7,7,7,7,7,7},	//再提出
{1,1,1,7,7,7,8,8,8},	//未済教室
{1,1,1,8,8,8,8,8,8},	//再提出
{2,2,2,2,2,2,2,2,2},	//自主休学？
{2,2,2,2,2,2,3,3,3},	//再提出
{2,2,2,2,2,2,4,4,4},	//再提出
{2,2,2,2,2,2,5,5,5},	//再提出
{2,2,2,2,2,2,6,6,6},	//再提出
{2,2,2,2,2,2,7,7,7},	//再提出
{2,2,2,2,2,2,8,8,8},	//再提出

//70

{2,2,2,3,3,3,3,3,3},	//再提出
{2,2,2,3,3,3,4,4,4},	//中だるみ
{2,2,2,3,3,3,5,5,5},	//中だるみ
{2,2,2,4,4,4,4,4,4},	//再提出
{2,2,2,4,4,4,5,5,5},	//中だるみ
{2,2,2,5,5,5,5,5,5},	//再提出
{2,2,2,6,6,6,6,6,6},	//再提出
{2,2,2,6,6,6,7,7,7},	//未済教室
{2,2,2,6,6,6,8,8,8},	//未済教室
{2,2,2,7,7,7,7,7,7},	//再提出

//80

{2,2,2,7,7,7,8,8,8},	//未済教室
{2,2,2,8,8,8,8,8,8},	//再提出
{3,3,3,3,3,3,3,3,3},	//マシン入れ替え
{3,3,3,3,3,3,4,4,4},	//再提出
{3,3,3,3,3,3,5,5,5},	//再提出
{3,3,3,3,3,3,6,6,6},	//再提出
{3,3,3,3,3,3,7,7,7},	//再提出
{3,3,3,3,3,3,8,8,8},	//再提出
{3,3,3,4,4,4,4,4,4},	//再提出
{3,3,3,4,4,4,5,5,5},	//課題コンボ

//90

{3,3,3,4,4,4,6,6,6},	//課題締め切り
{3,3,3,4,4,4,7,7,7},	//課題締め切り
{3,3,3,4,4,4,8,8,8},	//課題締め切り
{3,3,3,5,5,5,5,5,5},	//再提出
{3,3,3,5,5,5,6,6,6},	//課題締め切り
{3,3,3,5,5,5,7,7,7},	//課題締め切り
{3,3,3,5,5,5,8,8,8},	//課題締め切り
{3,3,3,6,6,6,6,6,6},	//再提出
{3,3,3,6,6,6,7,7,7},	//課題締め切り
{3,3,3,6,6,6,8,8,8},	//課題締め切り

//100

{3,3,3,7,7,7,7,7,7},	//再提出
{3,3,3,7,7,7,8,8,8},	//課題締め切り
{3,3,3,8,8,8,8,8,8},	//再提出
{4,4,4,4,4,4,4,4,4},	//年度末マシンルーム
{4,4,4,4,4,4,5,5,5},	//再提出
{4,4,4,4,4,4,6,6,6},	//再提出
{4,4,4,4,4,4,7,7,7},	//再提出
{4,4,4,4,4,4,8,8,8},	//再提出
{4,4,4,5,5,5,5,5,5},	//再提出
{4,4,4,5,5,5,6,6,6},	//課題締め切り

//110

{4,4,4,5,5,5,7,7,7},	//課題締め切り
{4,4,4,5,5,5,8,8,8},	//課題締め切り
{4,4,4,6,6,6,6,6,6},	//再提出
{4,4,4,6,6,6,7,7,7},	//課題締め切り
{4,4,4,6,6,6,8,8,8},	//課題締め切り
{4,4,4,7,7,7,7,7,7},	//再提出
{4,4,4,7,7,7,8,8,8},	//課題締め切り
{4,4,4,8,8,8,8,8,8},	//再提出
{5,5,5,5,5,5,5,5,5},	//ぴーち炸裂
{5,5,5,5,5,5,6,6,6},	//再提出

//120

{5,5,5,5,5,5,7,7,7},	//再提出
{5,5,5,5,5,5,8,8,8},	//再提出
{5,5,5,6,6,6,6,6,6},	//再提出
{5,5,5,6,6,6,7,7,7},	//課題締め切り
{5,5,5,6,6,6,8,8,8},	//課題締め切り
{5,5,5,7,7,7,7,7,7},	//再提出
{5,5,5,7,7,7,8,8,8},	//課題締め切り
{5,5,5,8,8,8,8,8,8},	//再提出
{6,6,6,6,6,6,6,6,6},	//呼び出し面接
{6,6,6,6,6,6,7,7,7},	//再提出

//130

{6,6,6,6,6,6,8,8,8},	//再提出
{6,6,6,7,7,7,7,7,7},	//再提出
{6,6,6,7,7,7,8,8,8},	//ザ・マシンルーム
{6,6,6,8,8,8,8,8,8},	//再提出
{7,7,7,7,7,7,7,7,7},	//ＨＡＬフェスティバル
{7,7,7,7,7,7,8,8,8},	//再提出
{7,7,7,8,8,8,8,8,8},	//再提出
{8,8,8,8,8,8,8,8,8}		//不正行為

//138

};


LONG lYakuten[138] = {90,40,40,40,40,40,40,40,40,40,30,20,20,20,20,20,20,40,20,20,20,20,20,20,40,20,20,40,20,40,40,20,20,40,20,40,90,40,40,40,40,40,40,40,40,20,20,20,20,20,20,40,20,20,40,40,40,40,20,20,40,20,40,90,40,40,40,40,40,40,40,20,20,40,20,40,40,20,20,40,20,40,90,40,40,40,40,40,40,30,20,20,20,40,20,20,20,40,20,20,40,20,40,90,40,40,40,40,40,20,20,20,40,20,20,40,20,40,90,40,40,40,40,20,20,40,20,40,90,40,40,40,30,40,90,40,40,90};

//0=未再教室　1=中だるみ　2=課題絞め切り
//3=留年コンボ　4=ザ・マシンルーム　5=課題コンボ　6=再提出
//7=遅刻の帝王　8=自主休学？　9=留年確定　10=マシン入れ替え
//11=年度末マシンルーム　12=ぴーち炸裂　13=ＨＡＬフェスティバル
//14=呼び出し面接　15=不正行為　
//16=怠惰な日々（ソースから消された役）
LONG lYakuTbl[138] = {7,6,6,6,6,6,6,6,6,6,3,1,1,1,0,0,0,6,1,1,1,0,0,0,6,1,1,6,1,6,6,0,0,6,0,6,9,6,6,6,6,6,6,6,6,1,1,1,0,0,0,6,1,1,6,6,6,6,0,0,6,0,6,8,6,6,6,6,6,6,6,1,1,6,1,6,6,0,0,6,0,6,10,6,6,6,6,6,6,5,2,2,2,6,2,2,2,6,2,2,6,2,6,11,6,6,6,6,6,2,2,2,6,2,2,6,2,6,12,6,6,6,6,2,2,6,2,6,14,6,6,6,4,6,13,6,6,15};

LONG CBattle::lKaisen = 0;

CBattle :: CBattle(void)
{
	//初期化
	pBG = NULL;
	pPai = NULL;
	pSuuji = NULL;
	pRonMsg = NULL;
	pIcon = NULL;

	pKokuban = NULL;
	pTokuten = NULL;
	pYaku = NULL;

	pTsumo = NULL;
	pSute = NULL;
	pVictory = NULL;
	pLose = NULL;
	pPon = NULL;

	pAgariVoice = NULL;
	pWinVoice = NULL;
	pAgarareVoice = NULL;
	pLoseVoice = NULL;
	pHissatsuVoice = NULL;

	for(int cnt = 0;cnt < 9;cnt++)
	{
		PaiPlayer[cnt].lKind = 999;
		PaiPlayer[cnt].lStat = 0;

		PaiEnemy[cnt].lKind = 999;
		PaiEnemy[cnt].lStat = 0;
		lHaipaiFlag[cnt] = 0;
	}
	for(cnt = 0;cnt < 81;cnt++)
	{
		PaiYama[cnt].lKind = 999;
	}
	for(cnt = 0;cnt < 19;cnt++)
	{
		SutePaiPlayer[cnt].lKind = 999;
		SutePaiPlayer[cnt].lStat = 0;
		SutePaiEnemy[cnt].lKind = 999;
		SutePaiEnemy[cnt].lStat = 0;
	}

}


CBattle :: ~CBattle(void)
{
	CleanUp();	
}


BOOL CBattle :: SetUp(LONG lParam)
{
	//卓を作る
	pBG = new MGLSprite;
//	pBG->LoadBmpFile("CharaData\\taku.hal",BGPALINDEX,TRUE);
	if(CGameParam::bLastBattle)
		pBG->LoadBmpFile("CharaData\\takuf.hal",10,FALSE);
	else
		pBG->LoadBmpFile("CharaData\\taku.hal",10,FALSE);
	pBG->AddPtr(0,0,320,240);
	pBG->AddPtr(0,240,320,241);
	pBG->AddPtr(0,241,320,242);

	//牌を作る
	pPai = new MGLSprite;
	pPai->LoadBmpFile("CharaData\\pai.hal",10 + 12,FALSE);

	for(int y=0;y < 3;y++)
	{
		int cnt;
		cnt = 1;
		pPai->AddPtr(0 + cnt*24,0 + y*70,24 + cnt*24,36 + y*70);
		cnt = 2;
		pPai->AddPtr(0 + cnt*24,0 + y*70,24 + cnt*24,36 + y*70);
		cnt = 0;
		pPai->AddPtr(0 + cnt*24,0 + y*70,24 + cnt*24,36 + y*70);

		cnt = 3;
		pPai->AddPtr(0 + cnt*24,0 + y*70,24 + cnt*24,36 + y*70);
		cnt = 4;
		pPai->AddPtr(0 + cnt*24,0 + y*70,24 + cnt*24,36 + y*70);
		cnt = 5;
		pPai->AddPtr(0 + cnt*24,0 + y*70,24 + cnt*24,36 + y*70);

		cnt = 8;
		pPai->AddPtr(0 + cnt*24,0 + y*70,24 + cnt*24,36 + y*70);
		cnt = 6;
		pPai->AddPtr(0 + cnt*24,0 + y*70,24 + cnt*24,36 + y*70);
		cnt = 7;
		pPai->AddPtr(0 + cnt*24,0 + y*70,24 + cnt*24,36 + y*70);

		cnt = 9;
		pPai->AddPtr(0 + cnt*24,0 + y*70,24 + cnt*24,36 + y*70);

		//寝かせた牌
		cnt = 1;
		pPai->AddPtr(0 + cnt*24,36 + y*70,24 + cnt*24,70 + y*70);
		cnt = 2;
		pPai->AddPtr(0 + cnt*24,36 + y*70,24 + cnt*24,70 + y*70);
		cnt = 0;
		pPai->AddPtr(0 + cnt*24,36 + y*70,24 + cnt*24,70 + y*70);

		cnt = 3;
		pPai->AddPtr(0 + cnt*24,36 + y*70,24 + cnt*24,70 + y*70);
		cnt = 4;
		pPai->AddPtr(0 + cnt*24,36 + y*70,24 + cnt*24,70 + y*70);
		cnt = 5;
		pPai->AddPtr(0 + cnt*24,36 + y*70,24 + cnt*24,70 + y*70);

		cnt = 8;
		pPai->AddPtr(0 + cnt*24,36 + y*70,24 + cnt*24,70 + y*70);
		cnt = 6;
		pPai->AddPtr(0 + cnt*24,36 + y*70,24 + cnt*24,70 + y*70);
		cnt = 7;
		pPai->AddPtr(0 + cnt*24,36 + y*70,24 + cnt*24,70 + y*70);

		cnt = 9;
		pPai->AddPtr(0 + cnt*24,36 + y*70,24 + cnt*24,70 + y*70);
	}

	pPai->AddPtr(216,36,216 + 24,36 + 4);

	//数字を作る
	pSuuji = new MGLSprite;
	pSuuji->LoadBmpFile("CharaData\\suuji.hal",10 + 12 + 30,TRUE);
	for(int cnt=0;cnt < 10;cnt++)
	{
		pSuuji->AddPtr(cnt*9,0,cnt*9 + 8,7);
	}
	for(cnt=0;cnt < 10;cnt++)
	{
		pSuuji->AddPtr(cnt*9,8,cnt*9 + 8,16);
	}

	pRonMsg = new MGLSprite;
	pRonMsg->LoadBmpFile("CharaData\\ron.hal",10 + 12 + 30 + 7,FALSE);
	for(cnt=0;cnt < 9;cnt++)
	{
		pRonMsg->AddPtr(cnt*112,0,cnt*112 + 112,64);
	}

	pReach = new MGLSprite;
	pReach->UnionSprite(pPai);
	pReach->AddPtr(216,40,216 + 24,45);
	pReach->AddPtr(216,45,216 + 24,50);

	//主人公を作る
	pHarumi = new MGLSprite;
	pHarumi->LoadBmpFile("CharaData\\harumi.hal",10 + 12 + 30 + 7 + 18,FALSE);
	for(cnt=0;cnt < 9;cnt++)
		pHarumi->AddPtr(cnt*87,0,cnt*87 + 87,117);

	
	//アイコンを作る
	pIcon = new MGLSprite;
	pIcon->LoadBmpFile("CharaData\\icon.hal",10 + 12 + 30 + 7 + 18 + 48 + 32,FALSE);
	for(cnt=0;cnt < 5;cnt++)
		pIcon->AddPtr(cnt*28,0,cnt*28 + 28,20);
 	
	//黒板を作る
	pKokuban = new MGLSprite;
	pKokuban->LoadBmpFile("CharaData\\kokuban.hal",10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32,TRUE);
	pKokuban->AddPtr(0,0,320,240);
	
	//得点を作る
	pTokuten = new MGLSprite;
	pTokuten->LoadBmpFile("CharaData\\tennsuu.hal",10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32 + 8,TRUE);
	for(cnt=0;cnt < 15;cnt++)
		pTokuten->AddPtr(0 + cnt*60,0,60 + cnt*60,20);
	 
	//役を作る
	pYaku = new MGLSprite;
	pYaku->LoadBmpFile("CharaData\\yakuhyou.hal",10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32 + 8 + 4,TRUE);
	for(cnt=0;cnt < 16;cnt++)
		pYaku->AddPtr(0 + cnt*128,0,128 + cnt*128,52);
	
	//敵を作る
	pEnemy = new MGLSprite;
	//必殺技を作る
	pHissatsu = new MGLSprite;
	//必殺技の説明を作る
	pHissatsuSetsumei = new MGLSprite;

	switch(CGameParam::lStage)
	{
	//石田
	case 1:
		pEnemy->LoadBmpFile("CharaData\\ishida.hal",10 + 12 + 30 + 7 + 18 + 48,FALSE);
		for(cnt=0;cnt < 4;cnt++)
			pEnemy->AddPtr(cnt*87,0,cnt*87 + 87,117);

		pHissatsu->LoadBmpFile("CharaData\\waza_ishida.hal",10 + 12 + 30 + 7 + 18 + 48 + 32 + 11,FALSE);
		pHissatsu->AddPtr(0,0,320,94);
		pHissatsuSetsumei->LoadBmpFile("CharaData\\waza2_ishida.hal",10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32 + 8 + 4 + 3,FALSE);
		pHissatsuSetsumei->AddPtr(0,0,320,94);
		break;

	//荒井
	case 2:
		pEnemy->LoadBmpFile("CharaData\\arai.hal",10 + 12 + 30 + 7 + 18 + 48,FALSE);
		for(cnt=0;cnt < 4;cnt++)
			pEnemy->AddPtr(cnt*87,0,cnt*87 + 87,117);

		pHissatsu->LoadBmpFile("CharaData\\waza_arai.hal",10 + 12 + 30 + 7 + 18 + 48 + 32 + 11,FALSE);
		pHissatsu->AddPtr(0,0,320,94);
		pHissatsuSetsumei->LoadBmpFile("CharaData\\waza2_arai.hal",10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32 + 8 + 4 + 3,FALSE);
		pHissatsuSetsumei->AddPtr(0,0,320,94);
		break;

	//加藤
	case 3:
		pEnemy->LoadBmpFile("CharaData\\katou.hal",10 + 12 + 30 + 7 + 18 + 48,FALSE);
		for(cnt=0;cnt < 4;cnt++)
			pEnemy->AddPtr(cnt*87,0,cnt*87 + 87,117);

		pHissatsu->LoadBmpFile("CharaData\\waza_katou.hal",10 + 12 + 30 + 7 + 18 + 48 + 32 + 11,FALSE);
		pHissatsu->AddPtr(0,0,320,94);
		pHissatsuSetsumei->LoadBmpFile("CharaData\\waza2_katou.hal",10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32 + 8 + 4 + 3,FALSE);
		pHissatsuSetsumei->AddPtr(0,0,320,94);
		break;

	//原秀
	case 4:
		pEnemy->LoadBmpFile("CharaData\\harahide.hal",10 + 12 + 30 + 7 + 18 + 48,FALSE);
		for(cnt=0;cnt < 3;cnt++)
			pEnemy->AddPtr(cnt*87,0,cnt*87 + 87,117);

		pHissatsu->LoadBmpFile("CharaData\\waza_harahide.hal",10 + 12 + 30 + 7 + 18 + 48 + 32 + 11,FALSE);
		pHissatsu->AddPtr(0,0,320,94);
		pHissatsuSetsumei->LoadBmpFile("CharaData\\waza2_harahide.hal",10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32 + 8 + 4 + 3,FALSE);
		pHissatsuSetsumei->AddPtr(0,0,320,94);
		break;

	//今西
	case 5:
		pEnemy->LoadBmpFile("CharaData\\imanishi.hal",10 + 12 + 30 + 7 + 18 + 48,FALSE);
		for(cnt=0;cnt < 3;cnt++)
			pEnemy->AddPtr(cnt*87,0,cnt*87 + 87,117);

		pHissatsu->LoadBmpFile("CharaData\\waza_imanishi.hal",10 + 12 + 30 + 7 + 18 + 48 + 32 + 11,FALSE);
		pHissatsu->AddPtr(0,0,320,94);
		pHissatsuSetsumei->LoadBmpFile("CharaData\\waza2_imanishi.hal",10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32 + 8 + 4 + 3,FALSE);
		pHissatsuSetsumei->AddPtr(0,0,320,94);
		break;

	//デビル
	case 6:
		pEnemy->LoadBmpFile("CharaData\\sakai.hal",10 + 12 + 30 + 7 + 18 + 48,FALSE);
		for(cnt=0;cnt < 3;cnt++)
			pEnemy->AddPtr(cnt*87,0,cnt*87 + 87,117);

		pHissatsu->LoadBmpFile("CharaData\\waza_sakai.hal",10 + 12 + 30 + 7 + 18 + 48 + 32 + 11,FALSE);
		pHissatsu->AddPtr(0,0,320,94);
		pHissatsuSetsumei->LoadBmpFile("CharaData\\waza2_sakai.hal",10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32 + 8 + 4 + 3,FALSE);
		pHissatsuSetsumei->AddPtr(0,0,320,94);
		break;

	//中川
	case 7:
		pEnemy->LoadBmpFile("CharaData\\nakagawa.hal",10 + 12 + 30 + 7 + 18 + 48,FALSE);
		for(cnt=0;cnt < 4;cnt++)
			pEnemy->AddPtr(cnt*87,0,cnt*87 + 87,117);

		pHissatsu->LoadBmpFile("CharaData\\waza_nakagawa.hal",10 + 12 + 30 + 7 + 18 + 48 + 32 + 11,FALSE);
		pHissatsu->AddPtr(0,0,320,94);

		pHissatsuSetsumei->LoadBmpFile("CharaData\\waza2_nakagawa.hal",10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32 + 8 + 4 + 3,FALSE);
		pHissatsuSetsumei->AddPtr(0,0,320,94);
		break;

	//木曽
	case 8:
		pEnemy->LoadBmpFile("CharaData\\kiso.hal",10 + 12 + 30 + 7 + 18 + 48,FALSE);
		for(cnt=0;cnt < 3;cnt++)
			pEnemy->AddPtr(cnt*87,0,cnt*87 + 87,117);

		pHissatsu->LoadBmpFile("CharaData\\waza_kiso.hal",10 + 12 + 30 + 7 + 18 + 48 + 32 + 11,FALSE);
		for(cnt=0;cnt < 94;cnt++)
			pHissatsu->AddPtr(0,cnt,320,cnt + 1);

		pHissatsuSetsumei->LoadBmpFile("CharaData\\waza2_kiso.hal",10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32 + 8 + 4 + 3,FALSE);
		pHissatsuSetsumei->AddPtr(0,0,320,94);
		break;

	//ラスト
	case 9:


		if(CGameParam::bLastBattle)
		{
			pEnemy->LoadBmpFile("CharaData\\masaru.hal",10 + 12 + 30 + 7 + 18 + 48,FALSE);
			for(cnt=0;cnt < 3;cnt++)
				pEnemy->AddPtr(cnt*87,0,cnt*87 + 87,117);
			pHissatsu->LoadBmpFile("CharaData\\waza_robo2.hal",10 + 12 + 30 + 7 + 18 + 48 + 32 + 11,FALSE);
			pHissatsu->AddPtr(0,0,320,94);
			pHissatsuSetsumei->LoadBmpFile("CharaData\\waza2_robo2.hal",10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32 + 8 + 4 + 3,FALSE);
			pHissatsuSetsumei->AddPtr(0,0,320,94);
		}
		else
		{
			pEnemy->LoadBmpFile("CharaData\\robo.hal",10 + 12 + 30 + 7 + 18 + 48,FALSE);
			for(cnt=0;cnt < 3;cnt++)
				pEnemy->AddPtr(cnt*87,0,cnt*87 + 87,117);
			pHissatsu->LoadBmpFile("CharaData\\waza_robo.hal",10 + 12 + 30 + 7 + 18 + 48 + 32 + 11,FALSE);
			pHissatsu->AddPtr(0,0,320,94);
			pHissatsuSetsumei->LoadBmpFile("CharaData\\waza2_robo.hal",10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32 + 8 + 4 + 3,FALSE);
			pHissatsuSetsumei->AddPtr(0,0,320,94);
		}
		break;
	}

	pKaisen = new MGLSprite;
	pKaisen->LoadBmpFile("CharaData\\kaisenn.hal",10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32 + 8 + 4 + 3 + 16,TRUE);
	for(cnt=0;cnt < 5;cnt++)
		pKaisen->AddPtr(0 + cnt*112,0,112 + cnt*112,64);
		

	//WAVEを作る
	pTsumo = new MGLWave;
	pTsumo->LoadWave("Sound\\tsumo.wav");
	pSute = new MGLWave;
	pSute->LoadWave("Sound\\sute.wav");
	pVictory = new MGLWave;
	pVictory->LoadWave("Sound\\victory.wav");
	pLose = new MGLWave;
	pLose->LoadWave("Sound\\lose.wav");
	pPon = new MGLWave;
	pPon->LoadWave("Sound\\Pon.wav");
	pGetScore = new MGLWave;
	pGetScore->LoadWave("Sound\\getscore.wav");

	switch(CGameParam::lStage)
	{
	//石田
	case 1:

		pAgariVoice = new MGLWave;
		pAgariVoice->LoadWave("Sound\\ishida\\00.wav");
		pWinVoice = new MGLWave;
		pWinVoice->LoadWave("Sound\\ishida\\02.wav");
		pAgarareVoice = new MGLWave;
		pAgarareVoice->LoadWave("Sound\\ishida\\03.wav");
		pLoseVoice = new MGLWave;
		pLoseVoice->LoadWave("Sound\\ishida\\01.wav");
		pHissatsuVoice = new MGLWave;
		pHissatsuVoice->LoadWave("Sound\\ishida\\04.wav");
		break;

	//荒井
	case 2:

		pAgariVoice = new MGLWave;
		pAgariVoice->LoadWave("Sound\\arai\\00.wav");
		pWinVoice = new MGLWave;
		pWinVoice->LoadWave("Sound\\arai\\01.wav");
		pAgarareVoice = new MGLWave;
		pAgarareVoice->LoadWave("Sound\\arai\\02.wav");
		pLoseVoice = new MGLWave;
		pLoseVoice->LoadWave("Sound\\arai\\03.wav");
		pHissatsuVoice = new MGLWave;
		pHissatsuVoice->LoadWave("Sound\\arai\\04.wav");
		break;

	//加藤
	case 3:

		pAgariVoice = new MGLWave;
		pAgariVoice->LoadWave("Sound\\katou\\00.wav");
		pWinVoice = new MGLWave;
		pWinVoice->LoadWave("Sound\\katou\\01.wav");
		pAgarareVoice = new MGLWave;
		pAgarareVoice->LoadWave("Sound\\katou\\02.wav");
		pLoseVoice = new MGLWave;
		pLoseVoice->LoadWave("Sound\\katou\\03.wav");
		pHissatsuVoice = new MGLWave;
		pHissatsuVoice->LoadWave("Sound\\katou\\04.wav");
		break;

	//原秀
	case 4:

		pAgariVoice = new MGLWave;
		pAgariVoice->LoadWave("Sound\\hara\\00.wav");
		pWinVoice = new MGLWave;
		pWinVoice->LoadWave("Sound\\hara\\01.wav");
		pAgarareVoice = new MGLWave;
		pAgarareVoice->LoadWave("Sound\\hara\\02.wav");
		pLoseVoice = new MGLWave;
		pLoseVoice->LoadWave("Sound\\hara\\03.wav");
		break;

	//今西
	case 5:

		pAgariVoice = new MGLWave;
		pAgariVoice->LoadWave("Sound\\imanishi\\00.wav");
		pWinVoice = new MGLWave;
		pWinVoice->LoadWave("Sound\\imanishi\\01.wav");
		pAgarareVoice = new MGLWave;
		pAgarareVoice->LoadWave("Sound\\imanishi\\02.wav");
		pLoseVoice = new MGLWave;
		pLoseVoice->LoadWave("Sound\\imanishi\\03.wav");
		pHissatsuVoice = new MGLWave;
		pHissatsuVoice->LoadWave("Sound\\imanishi\\04.wav");
		break;

	//デビル
	case 6:

		pAgariVoice = new MGLWave;
		pAgariVoice->LoadWave("Sound\\sakai\\00.wav");
		pWinVoice = new MGLWave;
		pWinVoice->LoadWave("Sound\\sakai\\01.wav");
		pAgarareVoice = new MGLWave;
		pAgarareVoice->LoadWave("Sound\\sakai\\02.wav");
		pLoseVoice = new MGLWave;
		pLoseVoice->LoadWave("Sound\\sakai\\03.wav");
		pHissatsuVoice = new MGLWave;
		pHissatsuVoice->LoadWave("Sound\\sakai\\04.wav");
		break;

	//中川
	case 7:

		pAgariVoice = new MGLWave;
		pAgariVoice->LoadWave("Sound\\nakagawa\\00.wav");
		pWinVoice = new MGLWave;
		pWinVoice->LoadWave("Sound\\nakagawa\\01.wav");
		pAgarareVoice = new MGLWave;
		pAgarareVoice->LoadWave("Sound\\nakagawa\\02.wav");
		pLoseVoice = new MGLWave;
		pLoseVoice->LoadWave("Sound\\nakagawa\\03.wav");
		pHissatsuVoice = new MGLWave;
		pHissatsuVoice->LoadWave("Sound\\nakagawa\\04.wav");
		break;

	//木曽
	case 8:

		pAgariVoice = new MGLWave;
		pAgariVoice->LoadWave("Sound\\kiso\\00.wav");
		pWinVoice = new MGLWave;
		pWinVoice->LoadWave("Sound\\kiso\\01.wav");
		pAgarareVoice = new MGLWave;
		pAgarareVoice->LoadWave("Sound\\kiso\\02.wav");
		pLoseVoice = new MGLWave;
		pLoseVoice->LoadWave("Sound\\kiso\\03.wav");
		pHissatsuVoice = new MGLWave;
		pHissatsuVoice->LoadWave("Sound\\kiso\\04.wav");
		break;

	//ラスボス
	case 9:

		pAgariVoice = new MGLWave;
		pAgariVoice->LoadWave("Sound\\dammy.wav");
		pWinVoice = new MGLWave;
		pWinVoice->LoadWave("Sound\\dammy.wav");
		pAgarareVoice = new MGLWave;
		pAgarareVoice->LoadWave("Sound\\dammy.wav");
		pLoseVoice = new MGLWave;
		pLoseVoice->LoadWave("Sound\\dammy.wav");
		pHissatsuVoice = new MGLWave;
		pHissatsuVoice->LoadWave("Sound\\akusaba.wav");
		break;

	}

	//パレットをセット
	if(CGameParam::bLastBattle)
		CGame.SetPalette("CharaData\\takuf.hal",0,10,12);
	else
		CGame.SetPalette("CharaData\\taku.hal",0,10,12);
	CGame.SetPalette("CharaData\\pai.hal",0,10 + 12,30);
	CGame.SetPalette("CharaData\\suuji.hal",0,10 + 12 + 30,7);
	CGame.SetPalette("CharaData\\ron.hal",0,10 + 12 + 30 + 7,18);
	CGame.SetPalette("CharaData\\harumi.hal",0,10 + 12 + 30 + 7 + 18,48);

	CGame.SetPalette("CharaData\\icon.hal",0,10 + 12 + 30 + 7 + 18 + 48 + 32,11);
	CGame.SetPalette("CharaData\\kokuban.hal",0,10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32,8);
	CGame.SetPalette("CharaData\\tennsuu.hal",0,10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32 + 8,4);
	CGame.SetPalette("CharaData\\yakuhyou.hal",0,10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32 + 8 + 4,3);

	switch(CGameParam::lStage)
	{
	case 1:
		CGame.SetPalette("CharaData\\ishida.hal",0,10 + 12 + 30 + 7 + 18 + 48,32);
		CGame.SetPalette("CharaData\\waza_ishida.hal",0,10 + 12 + 30 + 7 + 18 + 48 + 32 + 11,32);
		CGame.SetPalette("CharaData\\waza2_ishida.hal",0,10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32 + 8 + 4 + 3,16);
		break;
	case 2:
		CGame.SetPalette("CharaData\\arai.hal",0,10 + 12 + 30 + 7 + 18 + 48,32);
		CGame.SetPalette("CharaData\\waza_arai.hal",0,10 + 12 + 30 + 7 + 18 + 48 + 32 + 11,32);
		CGame.SetPalette("CharaData\\waza2_arai.hal",0,10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32 + 8 + 4 + 3,16);
		break;
	case 3:
		CGame.SetPalette("CharaData\\katou.hal",0,10 + 12 + 30 + 7 + 18 + 48,32);
		CGame.SetPalette("CharaData\\waza_katou.hal",0,10 + 12 + 30 + 7 + 18 + 48 + 32 + 11,32);
		CGame.SetPalette("CharaData\\waza2_katou.hal",0,10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32 + 8 + 4 + 3,16);
		break;
	case 4:
		CGame.SetPalette("CharaData\\harahide.hal",0,10 + 12 + 30 + 7 + 18 + 48,32);
		CGame.SetPalette("CharaData\\waza_harahide.hal",0,10 + 12 + 30 + 7 + 18 + 48 + 32 + 11,32);
		CGame.SetPalette("CharaData\\waza2_harahide.hal",0,10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32 + 8 + 4 + 3,16);
		break;
	case 5:
		CGame.SetPalette("CharaData\\imanishi.hal",0,10 + 12 + 30 + 7 + 18 + 48,32);
		CGame.SetPalette("CharaData\\waza_imanishi.hal",0,10 + 12 + 30 + 7 + 18 + 48 + 32 + 11,32);
		CGame.SetPalette("CharaData\\waza2_imanishi.hal",0,10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32 + 8 + 4 + 3,16);
		break;
	case 6:
		CGame.SetPalette("CharaData\\sakai.hal",0,10 + 12 + 30 + 7 + 18 + 48,32);
		CGame.SetPalette("CharaData\\waza_sakai.hal",0,10 + 12 + 30 + 7 + 18 + 48 + 32 + 11,32);
		CGame.SetPalette("CharaData\\waza2_sakai.hal",0,10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32 + 8 + 4 + 3,16);
		break;
	case 7:
		CGame.SetPalette("CharaData\\nakagawa.hal",0,10 + 12 + 30 + 7 + 18 + 48,32);
		CGame.SetPalette("CharaData\\waza_nakagawa.hal",0,10 + 12 + 30 + 7 + 18 + 48 + 32 + 11,32);
		CGame.SetPalette("CharaData\\waza2_nakagawa.hal",0,10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32 + 8 + 4 + 3,16);
		break;
	case 8:
		CGame.SetPalette("CharaData\\kiso.hal",0,10 + 12 + 30 + 7 + 18 + 48,32);
		CGame.SetPalette("CharaData\\waza_kiso.hal",0,10 + 12 + 30 + 7 + 18 + 48 + 32 + 11,32);
		CGame.SetPalette("CharaData\\waza2_kiso.hal",0,10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32 + 8 + 4 + 3,16);
		break;
	case 9:
		if(CGameParam::bLastBattle)
		{
			CGame.SetPalette("CharaData\\masaru.hal",0,10 + 12 + 30 + 7 + 18 + 48,32);
			CGame.SetPalette("CharaData\\waza_robo2.hal",0,10 + 12 + 30 + 7 + 18 + 48 + 32 + 11,32);
			CGame.SetPalette("CharaData\\waza2_robo2.hal",0,10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32 + 8 + 4 + 3,16);
		}
		else
		{
			CGame.SetPalette("CharaData\\robo.hal",0,10 + 12 + 30 + 7 + 18 + 48,32);
			CGame.SetPalette("CharaData\\waza_robo.hal",0,10 + 12 + 30 + 7 + 18 + 48 + 32 + 11,32);
			CGame.SetPalette("CharaData\\waza2_robo.hal",0,10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32 + 8 + 4 + 3,16);
		}
		break;
	}
	CGame.SetPalette("CharaData\\kaisenn.hal",0,10 + 12 + 30 + 7 + 18 + 48 + 32 + 11 + 32 + 8 + 4 + 3 + 16,3);

	CGame.RealizePalette();

	MGLMath::InitRand(timeGetTime());
	srand(timeGetTime());

	//どの積みこみテーブルを使うか決める
	lAgariNumEnemy = MGLMath::GetRand() % 138;

	//配牌を行う

	//まずは敵さん
	for(cnt = 0;cnt < 8;cnt++)
	{
		PaiEnemy[cnt].lKind = lInchiki[lAgariNumEnemy][cnt];
		lHaipaiFlag[lInchiki[lAgariNumEnemy][cnt]] ++;
	}
	//敵の上がり牌を決定
	lAgariPai = lInchiki[lAgariNumEnemy][8];

	//プレイヤー
	for(cnt = 0;cnt < 8;cnt++)
	{
		while(TRUE)
		{
			LONG lTempPai = rand() % 9;
			//その牌がまだ残っていたら
			if(lHaipaiFlag[lTempPai] < 9)
			{
				PaiPlayer[cnt].lKind = lTempPai;
				lHaipaiFlag[lTempPai] ++;
				break;
			}
		}
	}

	//山
	for(cnt = 0;cnt < 81;cnt++)
	{
		while(TRUE)
		{
			LONG lTempPai = rand() % 9;
			//その牌がまだ残っていたら
			if(lHaipaiFlag[lTempPai] < 9)
			{
				PaiYama[cnt].lKind = lTempPai;
				lHaipaiFlag[lTempPai] ++;
				break;
			}
			else
			{
				//81枚全て出ていたら終了する
				LONG lCheckCount = 0;
				for(int cnt2 = 0;cnt2 < 9;cnt2++)
				{
					//この種類の牌は全て出ていたら
					if(lHaipaiFlag[cnt2] >= 9)
					{
						lCheckCount ++;
					}
				}
				//全ての牌が出尽くしたら終わり
				if(lCheckCount >= 9)
					break;
			}
		}
	}


	//自牌9枚目
	lYamaIndex = 0;

	PaiPlayer[8].lKind = PaiYama[lYamaIndex].lKind;
	lYamaIndex ++;

	//自牌はソートする
//	SortPaiPlayer();
	SortPai(PaiPlayer);

	lPhase = 10000;	//配牌のシーンへ
	lNextPhase = 30;
	lHaiPaiNum[_PLAYER_] = 0;
	lHaiPaiNum[_ENEMY_] = 0;

	lSutePaiNum[_PLAYER_] = 0;	
	lSutePaiNum[_ENEMY_] = 0;

	lPonNum[_PLAYER_] = 0;
	lPonNum[_ENEMY_] = 0;

	bReach[_PLAYER_] = FALSE;
	bReach[_ENEMY_] = FALSE;
	lReachIppatsu[_PLAYER_] = 0;
	lReachIppatsu[_ENEMY_] = 0;

	bTempai[_PLAYER_] = FALSE;
	bTempai[_ENEMY_] = FALSE;

	bAllowRon[_PLAYER_] = TRUE;
	bAllowRon[_ENEMY_] = TRUE;
	bRonOK = FALSE;
	bTsumoOK = FALSE;
	bPonOK = FALSE;
	bReachOK = FALSE;
	bNextTsumoOK = FALSE;
	bTsumo[_PLAYER_] = FALSE;
	bTsumo[_ENEMY_] = FALSE;
	bYakuman[_PLAYER_] = FALSE;
	bYakuman[_ENEMY_] = FALSE;
	bHissatsu[_PLAYER_] = FALSE;
	bHissatsu[_ENEMY_] = FALSE;

	bAgari = FALSE;
	lLoop = 0;
	lOdoshi = FALSE;
	bRyukyoku = FALSE;
	lWinLose = 0;
	CGameParam :: bWin = FALSE;

	switch(CGameParam::lStage)
	{
	case 1:
		lAgaruKakuritsu = 15;
		lReachKakuritsu = 7;
		lTekagen = 6;
		break;

	case 2:
		lAgaruKakuritsu = 18;
		lReachKakuritsu = 0;
		lTekagen = 6;
		break;

	case 3:
		lAgaruKakuritsu = 20;
		lReachKakuritsu = 1;
		lTekagen = 5;
		break;

	case 4:
		lAgaruKakuritsu = 22;
		lReachKakuritsu = 1;
		lTekagen = 4;
		break;

	case 5:
		lAgaruKakuritsu = 25;
		lReachKakuritsu = 0;
		lTekagen = 5;
		break;

	case 6:
		lAgaruKakuritsu = 30;
		lReachKakuritsu = 5;
		lTekagen = 3;
		break;

	case 7:
		lAgaruKakuritsu = 35;
		lReachKakuritsu = 0;
		lTekagen = 2;
		break;

	case 8:
		lAgaruKakuritsu = 40;
		lReachKakuritsu = 12;
		lTekagen = 2;
		break;

	case 9:
		if(CGameParam::bLastBattle)
		{
			lAgaruKakuritsu = 60;
			lReachKakuritsu = 10;
			lTekagen = 0;
		}
		else
		{
			lAgaruKakuritsu = 50;
			lReachKakuritsu = 4;
			lTekagen = 1;
		}
		break;
	}
	return TRUE;
}


BOOL CBattle :: Go(DWORD* dwKeyFlag)
{

	//捨てゲーしたらタイトル画面へ戻る
	if(*dwKeyFlag & FAILEDGAME)
	{
		dwNextStage = CSTAGE_TITLE;
		CGameParam::bWin = FALSE;
		lKaisen = 0;
		return FALSE;   
	}

	//エスケープで終了
	if((*dwKeyFlag & EXITGAME))
	{
		dwNextStage = CSTAGE_CLEANUP;
		return FALSE;
	}

	if(GetAsyncKeyState('T') & 0x80000000)
		CGame.SetFps(0);
	if(GetAsyncKeyState('R') & 0x80000000)
		CGame.SetFps(60); 
	if(GetAsyncKeyState('Z') & 0x80000000)
		CGameParam::lScorePlayer = 999;
	if(GetAsyncKeyState('X') & 0x80000000)
		CGameParam::lScoreEnemy = 5;

	static BOOL bKeyDownFlag = FALSE;
	switch(lPhase)
	{
	//プレイヤーの番なら
	case 0:

		bReachOK = FALSE;
		bTsumoOK = FALSE;

		lNum = 0;	//どのキーが押されたか。
		if(!bKeyDownFlag)
		{
			if(*dwKeyFlag & PLAYER_1)
				lNum = 1;
			if(*dwKeyFlag & PLAYER_2)
				lNum = 2;
			if(*dwKeyFlag & PLAYER_3)
				lNum = 3;
			if(*dwKeyFlag & PLAYER_4)
				lNum = 4;
			if(*dwKeyFlag & PLAYER_5)
				lNum = 5;
			if(*dwKeyFlag & PLAYER_6)
				lNum = 6;
			if(*dwKeyFlag & PLAYER_7)
				lNum = 7;
			if(*dwKeyFlag & PLAYER_8)
				lNum = 8;
			if(*dwKeyFlag & PLAYER_9)
				lNum = 9;
			if(*dwKeyFlag & PLAYER_RON)
				lNum = 10;
			//ここではリーチに使う
			if(*dwKeyFlag & PLAYER_PON)
				lNum = 11;

			//加藤の必殺技が有効なら強制ツモ切り
			if(CGameParam::lStage == 3 &&
				bHissatsu[_ENEMY_])
			{
				lNum = 9;
				bHissatsu[_ENEMY_] = FALSE;
			}
			if(lNum > 0)
				bKeyDownFlag = TRUE;
		}

		//切る
		if((lNum > 0 && lNum < 10) &&
			PaiPlayer[lNum - 1].lStat == 0)
		{
			//捨て牌に放りこむ
			SutePaiPlayer[lSutePaiNum[_PLAYER_]].lKind = PaiPlayer[lNum - 1].lKind;
			//捨て牌の枚数に追加
			lSutePaiNum[_PLAYER_] ++;

			//切った牌の配列は空に
			PaiPlayer[lNum - 1].lKind = 999;
//			SortPaiPlayer();
			SortPai(PaiPlayer);

			lPhase = 1;	//切る
			lWaitTime = MGLMath::GetRand() % 30;
			lCountMem = lCount;
			bAllowRon[_PLAYER_] = TRUE;
			bTsumoOK = FALSE;

			pSute->StopWave();
			pSute->PlayWave(FALSE);

			lReachIppatsu[_PLAYER_] --;

			//すでにリーチしているがテンパイでなくなったときは
			int cnt;
			for(cnt = 0;cnt < 9;cnt ++)
				PaiTemp[cnt].lKind = PaiPlayer[cnt].lKind;
			SortPaiTemp();
			if(bReach[_PLAYER_] && IsTempai() == 0)
			{
				//一発フラグを初期化
				lReachIppatsu[_PLAYER_] = 0;
				//リーチ無効
				bReach[_PLAYER_] = FALSE;
				//点棒も戻ってくる
				CGameParam::lScorePlayer += 10;
				//曲も元に戻す
				if(CGame.IsUseMidiSound())
				{
					CGame.StopMidi();
					CGame.PlayMidi("Bgm\\battle.mid");
				}
			}

			//流局？
			if(lSutePaiNum[_PLAYER_] >= 18 &&
				lSutePaiNum[_ENEMY_] >= 18)
			{
				bRyukyoku = TRUE;
				lCountMem = lCount;
				lPhase = 44;
				break;
			}
			break;
		}

		//テンパイしてる？
		int cnt;
		for(cnt = 0;cnt < 9;cnt ++)
			PaiTemp[cnt].lKind = PaiPlayer[cnt].lKind;
		SortPaiTemp();
		//リーチ可能？
		if(IsTempai() > 0 && !bReach[_PLAYER_] &&
			lPonNum[_PLAYER_] == 0 && CGameParam::lScorePlayer >= 10)
		{
			bReachOK = TRUE;
			//キーが押されたらリーチ
			if(lNum == 11)// && CGameParam::lScorePlayer >= 10)
			{
				bAllowRon[_PLAYER_] = FALSE;
				//10点減らす
				CGameParam::lScorePlayer -= 10;
				//一発カウンタセット
				lReachIppatsu[_PLAYER_] = 3;
				lCountMem = lCount;
				//リーチの場面へ
				lPhase = 46;

				pPon->StopWave();
				pPon->PlayWave(FALSE);
				if(CGame.IsUseMidiSound())
				{
					CGame.StopMidi();
					CGame.PlayMidi("Bgm\\reachplayer.mid");
				}
				break;
			}
		}
		//リーチしている場合はとにかく3枚組みが３つあればいい
//		else if(IsTempai() == 2 && bReach[_PLAYER_] && bAllowRon[_PLAYER_])
		if(IsTempai() == 2 && bAllowRon[_PLAYER_] && lPonNum[_PLAYER_] == 0)
		{
			if(bAllowRon)
				bTsumoOK = TRUE;
			//キーが押されたら上がり
			if(lNum == 10 && bAllowRon)
			{
				lCountMem = lCount;
				CGameParam :: bWin = TRUE;
				lPhase = 40;
				//ツモった
				bTsumo[_PLAYER_] = TRUE;

				pVictory->StopWave();
				pVictory->PlayWave(FALSE);
//				pLose->StopWave();
//				pLose->PlayWave(FALSE);
				break;
			}
		}
	
		//ツモですか？
		for(cnt = 0;cnt < 9;cnt ++)
			PaiTemp[cnt].lKind = PaiPlayer[cnt].lKind;
		SortPaiTemp();
		lAgariNumPlayer = AgariCheck();
		//条件が成立していて
		if(lAgariNumPlayer >= 0)
		{
			if(bAllowRon[_PLAYER_])
				bTsumoOK = TRUE;
			if(!bAllowRon[_PLAYER_] && bReach[_PLAYER_])
				bTsumoOK = TRUE;

			//キーが押されたら上がり
			if(lNum == 10 && bAllowRon[_PLAYER_])
			{
				//加藤なら
				if(CGameParam::lStage == 3 &&
					timeGetTime() % 100 < 30)
				{
					//必殺技恐怖のモーニングコール
					lCountMem = lCount;
					lPhase = 1300;
					bHissatsu[_ENEMY_] = TRUE;

					pHissatsuVoice->StopWave();
					pHissatsuVoice->PlayWave(FALSE);
				}
				else
				{
					lCountMem = lCount;
					CGameParam :: bWin = TRUE;
					bTsumo[_PLAYER_] = TRUE;
					lPhase = 40;

					//プレイヤーが上がったら敵の牌すり替え
					LONG lSurikae = 0;
					if(!bReach[_ENEMY_])
					{
						lSurikae = timeGetTime() % 5;
						int cnt;
						for(cnt=0;cnt < lSurikae;cnt ++)
							PaiEnemy[MGLMath::GetRand() % 8].lKind = PaiYama[81 - 18 - 1 - cnt].lKind;
					}
					SortPai(PaiEnemy);

					pVictory->StopWave();
					pVictory->PlayWave(FALSE);
				}
				break;
			}
			//リーチしたのと同じ順目ならなかったことにして上がる
			else if(lNum == 10 && !bAllowRon[_PLAYER_] && bReach[_PLAYER_])
//			if(lNum == 10 && lReachIppatsu[_PLAYER_] == 3 && bReach[_PLAYER_])
			{
				bReach[_PLAYER_] = FALSE;
				CGameParam::lScorePlayer += 10;
				lReachIppatsu[_PLAYER_] = 0;

				lCountMem = lCount;
				CGameParam :: bWin = TRUE;
				bTsumo[_PLAYER_] = TRUE;
				lPhase = 40;

				pVictory->StopWave();
				pVictory->PlayWave(FALSE);
				
				//敵の牌すり替え
				LONG lSurikae = 0;
				if(!bReach[_ENEMY_])
				{
					lSurikae = timeGetTime() % 5;
					int cnt;
					for(cnt=0;cnt < lSurikae;cnt ++)
						PaiEnemy[MGLMath::GetRand() % 8].lKind = PaiYama[81 - 18 - 1 - cnt].lKind;
				}
				SortPai(PaiEnemy);
				break;
			}

		}

		break;

	//敵がなくかロンか
	case 1:

		if(lCount - lCountMem < 20 + lWaitTime)
			break;

		//プレイヤーが切ったのが当たり?
		if(lAgariPai == SutePaiPlayer[lSutePaiNum[_PLAYER_] - 1].lKind &&
			timeGetTime() % 100 < lAgaruKakuritsu &&
			lLoop > lTekagen)
		{
			SutePaiPlayer[lSutePaiNum[_PLAYER_] - 1].lStat = 2;
			lCountMem = lCount;
			lPhase = 43;

			pLose->StopWave();
			pLose->PlayWave(FALSE);
		}
		else
		{
			lReachIppatsu[_ENEMY_] --;
			lWaitTime = MGLMath::GetRand() % 30;
			lCountMem = lCount;
			lPhase = 10;

			pTsumo->StopWave();
			pTsumo->PlayWave(FALSE);
		}
		break;

	//敵の番なら
	case 10:

		if(lCount - lCountMem < 20 + lWaitTime)
			break;

		//テンパイしてる？
		for(cnt = 0;cnt < 9;cnt ++)
			PaiTemp[cnt].lKind = PaiEnemy[cnt].lKind;
		SortPaiTemp();
		//リーチ可能？
		if(IsTempai() > 0 && !bReach[_ENEMY_] &&
			lPonNum[_ENEMY_] == 0 &&
			lLoop < 16)
		{
			//キーが押されたらリーチ
			if((timeGetTime() % 100 < lReachKakuritsu) && (CGameParam::lScoreEnemy >= 10))
			{
				bAllowRon[_ENEMY_] = FALSE;
				//10点減らす
				CGameParam::lScoreEnemy -= 10;
				lReachIppatsu[_ENEMY_] = 3;
				lCountMem = lCount;
				lWaitTime = timeGetTime() % 30;

				pPon->StopWave();
				pPon->PlayWave(FALSE);

				//リーチの場面へ
				lPhase = 47;

				if(CGame.IsUseMidiSound())
				{
					CGame.StopMidi();
					CGame.PlayMidi("Bgm\\reachenemy.mid");
				}
				break;
			}
		}

		//デビルリーチが有効なら
		if(CGameParam::lStage == 6 &&
			bHissatsu[_ENEMY_] &&
			bAllowRon[_ENEMY_])
		{
			lTekagen = 0;
			//絶対ツモる
			if(PaiYama[lYamaIndex].lKind != lAgariPai)
			{
				for(int cnt = lYamaIndex + 1;cnt < 81;cnt++)
				{
					if(PaiYama[cnt].lKind == lAgariPai)
					{
						LONG lTemp = PaiYama[cnt].lKind;
						PaiYama[cnt].lKind = PaiYama[lYamaIndex].lKind;
						PaiYama[lYamaIndex].lKind = lTemp;
						break;
					}
				}
			}
		}

		//ツモであがり？
		PaiEnemy[8].lKind = PaiYama[lYamaIndex].lKind;
		if(lAgariPai == PaiYama[lYamaIndex].lKind &&
			timeGetTime() % 100 < lAgaruKakuritsu &&
			lLoop > lTekagen &&
			bAllowRon[_ENEMY_])
		{
			PaiEnemy[8].lKind = PaiYama[lYamaIndex].lKind;
//			lPhase = 30;
			lCountMem = lCount;
			bTsumo[_ENEMY_] = TRUE;
			lPhase = 42;

			pLose->StopWave();
			pLose->PlayWave(FALSE);
			break;
		}
		else
		{//切る

			//捨て牌に放りこむ
			SutePaiEnemy[lSutePaiNum[_ENEMY_]].lKind = PaiYama[lYamaIndex].lKind;
			//捨て牌の枚数に追加
			lSutePaiNum[_ENEMY_] ++;

			lYamaIndex ++;

			PaiEnemy[8].lKind = 999;
			lPhase = 11;

			lReachIppatsu[_PLAYER_] --;
			lReachIppatsu[_ENEMY_] --;

			pSute->StopWave();
			pSute->PlayWave(FALSE);

			//リーチする確率を上げる
			lReachKakuritsu ++;
			bAllowRon[_ENEMY_] = TRUE;
			break;
		}


		break;

	//プレイヤーがなくかロンか
	case 11:

		lNum = 0;
		if(!bKeyDownFlag)
		{
			if(*dwKeyFlag & PLAYER_9)
				lNum = 9;
			if(*dwKeyFlag & PLAYER_RON)
				lNum = 10;
			if(*dwKeyFlag & PLAYER_PON)
				lNum = 11;

			//加藤の必殺技が有効なら
			if(CGameParam :: lStage == 3 &&
				bHissatsu[_ENEMY_])
			{
				//ロンを見逃す
				lNum = 9;
				bHissatsu[_ENEMY_] = FALSE;
			}

			if(lNum > 0)
				bKeyDownFlag = TRUE;
		}

		//木曽用
		if(lOdoshi > 0)
		{
			lOdoshi --;
			break;
		}

		bNextTsumoOK = TRUE;
		if(lNum == 9)
		{
			bTsumoOK = FALSE;
			bRonOK = FALSE;
//			bReachOK = FALSE;

			//流局？
			if(lSutePaiNum[_PLAYER_] >= 18 &&
				lSutePaiNum[_ENEMY_] >= 18 &&
				lPhase != 44)
			{
				//流局したらすり替え
				LONG lSurikae = 0;
				if(!bReach[_ENEMY_])
				{
					lSurikae = timeGetTime() % 5;
					int cnt;
					for(cnt=0;cnt < lSurikae;cnt ++)
						PaiEnemy[MGLMath::GetRand() % 8].lKind = PaiYama[81 - 18 - 1 - cnt].lKind;
				}
				SortPai(PaiEnemy);
	
				bRyukyoku = TRUE;
				lCountMem = lCount;
				lPhase = 44;
				break;
			}
			//ツモってくる
			PaiPlayer[8].lKind = PaiYama[lYamaIndex].lKind;
			PaiPlayer[8].lStat = 0;

			lYamaIndex ++;
			lPhase = 0;	//プレイヤーの番
			bPonOK = FALSE;			
			lLoop ++;

			pTsumo->StopWave();
			pTsumo->PlayWave(FALSE);
			break;
		}

		//ロン？
		bRonOK = FALSE;
		for(cnt = 0;cnt < 8;cnt ++)
			PaiTemp[cnt].lKind = PaiPlayer[cnt].lKind;

		PaiTemp[8].lKind = SutePaiEnemy[lSutePaiNum[_ENEMY_] - 1].lKind;
		SortPaiTemp();

		lAgariNumPlayer = AgariCheck();
		//条件が成立していたら
		if(lAgariNumPlayer >= 0 ||
			(IsTempai() == 2 && bReach[_PLAYER_]))
		{
			bRonOK = TRUE;

			if(lNum == 10)
			{
				//木曽の必殺技が有効なら
				if(CGameParam :: lStage == 8 &&
					bHissatsu[_ENEMY_])
				{
					//脅して上がらせない
					pHissatsuVoice->StopWave();
					pHissatsuVoice->PlayWave(FALSE);
					lOdoshi = 120;
				}
				//加藤のステージなら
				else if(CGameParam :: lStage == 3 &&
					timeGetTime() % 100 < 30)
				{
					//恐怖のモーニングコール発動
					lCountMem = lCount;
					lPhase = 1301;
					bHissatsu[_ENEMY_] = TRUE;

					pHissatsuVoice->StopWave();
					pHissatsuVoice->PlayWave(FALSE);
				}
				else
				{
					CGameParam :: bWin = TRUE;
					SutePaiEnemy[lSutePaiNum[_ENEMY_] - 1].lStat = 2;
					lCountMem = lCount;
					lPhase = 41;

					pVictory->StopWave();
					pVictory->PlayWave(FALSE);

					//敵の牌すり替え
					LONG lSurikae = 0;
					if(!bReach[_ENEMY_])
					{
						lSurikae = timeGetTime() % 5;
						int cnt;
						for(cnt=0;cnt < lSurikae;cnt ++)
							PaiEnemy[MGLMath::GetRand() % 8].lKind = PaiYama[81 - 18 - 1 - cnt].lKind;
					}
					SortPai(PaiEnemy);
				}
				break;
			}
		}

		//ポン？
		LONG lPonTemp;
		lPonTemp = SutePaiEnemy[lSutePaiNum[_ENEMY_] - 1].lKind;
		LONG lIndex;
		lIndex = 0;
		LONG lPonCheckNum;
		lPonCheckNum = 0;

		if(PaiPlayer[3].lStat != 1)
		{
			while(lIndex < 8)
			{
				//2個あるか調べる
				if(PaiPlayer[lIndex].lStat == 0 &&
					PaiPlayer[lIndex].lKind == lPonTemp)
				{
					//ポン成立
					if(lPonCheckNum >= 1 && !bReach[_PLAYER_])
					{
						bPonOK = TRUE;
						if(lNum == 11)
						{
							//捨て牌の色を変える
							SutePaiEnemy[lSutePaiNum[_ENEMY_] - 1].lStat = 1;
							//ないた自牌の色を変える
							PaiPlayer[lIndex - 1].lStat = 1;
							PaiPlayer[lIndex].lStat = 1;
							PaiPlayer[8].lStat = 1;
							//ないてきた牌を新規に追加
							PaiPlayer[8].lKind = lPonTemp;

							//ないたあと上がる可能性があるので封じておく
							bAllowRon[_PLAYER_] = FALSE;
							//敵の一発は無効
							lReachIppatsu[_ENEMY_] = 0;

							lCountMem = lCount;
							lPhase = 45;
							bPonOK = FALSE;
							bRonOK = FALSE;
							bTsumoOK = FALSE;
							bNextTsumoOK = FALSE;
							lPonNum[_PLAYER_] ++;
	
							pPon->StopWave();
							pPon->PlayWave(FALSE);
							break;
						}
					}
					else
						lPonCheckNum ++;
				}
				else
				{
					lPonCheckNum = 0;
				}
				lIndex ++;
			}
		}
		break;

	//ステージ終了の処理
	case 30:

		if(*dwKeyFlag & PLAYER_RON &&
			!bKeyDownFlag)
		{
			lKaisen ++;

			if(CGame.IsUseMidiSound())
				CGame.StopMidi();

			if(CGameParam::lScorePlayer == 0)
			{
				lKaisen = 0;
//				dwNextStage = CSTAGE_STAGE00;
				dwNextStage = CSTAGE_CONTINUE;
				CGameParam::bLastBattle = FALSE;
			}

			if(CGameParam :: bWin)
			{
				if(CGameParam::lScoreEnemy == 0 ||
					lKaisen >= 5)
				{
					//クリア後のせりふの画面へ
					switch(CGameParam::lStage)
					{
					case 1:
						dwNextStage = CSTAGE_STAGE01;
						break;
					case 2:
						dwNextStage = CSTAGE_STAGE02;
						break;
					case 3:
						dwNextStage = CSTAGE_STAGE03;
						break;
					case 4:
						dwNextStage = CSTAGE_STAGE04;
						break;
					case 5:
						dwNextStage = CSTAGE_STAGE05;
						break;
					case 6:
						dwNextStage = CSTAGE_STAGE06;
						break;
					case 7:
						dwNextStage = CSTAGE_STAGE07;
		   				break;
					case 8:
						dwNextStage = CSTAGE_STAGE08;
						break;
					case 9:
						if(!CGameParam::bLastBattle)
						{
							dwNextStage = CSTAGE_BATTLE;
							CGameParam :: bWin = FALSE;
							CGameParam::bLastBattle = TRUE;
							CGameParam::lScoreEnemy = 256;
						}  
						else
						{
							dwNextStage = CSTAGE_STAGE09;
							CGameParam::bLastBattle = FALSE;
						}
						break;
					}
					lKaisen = 0;
				}
				else
					CGameParam :: bWin = FALSE;
			}
			else
			{
				if(lKaisen >= 5)
				{
					lKaisen = 0;
//					dwNextStage = CSTAGE_STAGE00;
					dwNextStage = CSTAGE_CONTINUE;
					CGameParam::bLastBattle = FALSE;
				}
			}
//			return FALSE;
			lCountMem = lCount;
			lPhase = 99999;
		}
		break;

	//勝ちポーズ、負けポーズ、勝ち台詞、負け台詞
	case 31:

		if(lCount - lCountMem > 60)
		{
			if(CGame.IsUseMidiSound())
				CGame.StopMidi();
			lCountMem = lCount;
			lPhase = 32;
		}
		break;

	//得点を計算
	case 32:

		//プレイヤーが勝った?
		if(CGameParam :: bWin)
		{
			if(lAgariNumPlayer >= 0)
			{
				//役満?
				if(lYakuten[lAgariNumPlayer] == 90)
				{
					lShowScore = 90;
					bYakuman[_PLAYER_] = TRUE;
					lPhase = 33;
					break;
				}
			}

			//役の得点を代入
			if(lAgariNumPlayer >= 0)
				lShowScore = lYakuten[lAgariNumPlayer];
			else
				//リーチのみ
				lShowScore = 0;

			//ボーナスいろいろ
			if(bReach[_PLAYER_])
			{
				lShowScore += 10;
				if(lReachIppatsu[_PLAYER_] > 0)
					lShowScore += 10;
			}
			//面前ツモ
			if(bTsumo[_PLAYER_] && lPonNum[_PLAYER_] == 0)
				lShowScore += 10;
			//なきあり？
			if(lPonNum[_PLAYER_] > 0)
				lShowScore -= 5;
		}
		else
		{
			if(lAgariNumEnemy >= 0)
			{
				if(lYakuten[lAgariNumEnemy] == 90)
				{
					lShowScore = 90;
					bYakuman[_ENEMY_] = TRUE;
					lPhase = 33;
					break;
				}
			}

			if(lAgariNumEnemy >= 0)
				lShowScore = lYakuten[lAgariNumEnemy];
			else
				lShowScore = 0;
			if(bReach[_ENEMY_])
			{
				lShowScore += 10;
				if(lReachIppatsu[_ENEMY_] > 0)
					lShowScore += 10;
			}
			if(bTsumo[_ENEMY_] && lPonNum[_ENEMY_] == 0)
				lShowScore += 10;
			if(lPonNum[_ENEMY_] > 0)
				lShowScore -= 5;

		}

		lPhase = 33;
		break;

	//得点を表示
	case 33:

		//しばらく待つ
		if(lCount - lCountMem > 200) 
		{
			lCountMem = lCount;
			//ラスボスなら必殺技あり
			if(CGameParam::lStage == 9 &&
				CGameParam :: bWin &&
				!CGameParam :: bLastBattle &&
				!bYakuman[_PLAYER_] &&
				timeGetTime() % 100 < 22) 
			{
				pHissatsuVoice->StopWave();
				pHissatsuVoice->PlayWave(FALSE);
				lCountMem = lCount;
				lPhase = 1900;
			}
			//真ボス催眠術 
			else if(CGameParam::lStage == 9 &&
				!CGameParam :: bWin &&
				CGameParam :: bLastBattle &&
				timeGetTime() % 100 < 80)
			{  
				pHissatsuVoice->StopWave();
				pHissatsuVoice->PlayWave(FALSE);
				lCountMem = lCount;
				lPhase = 1950;
			}
			else
				lPhase = 38;
		}
		break;

	//得点が入っていくシーン
	case 34:

		if(lCount & 1)
			break;
		if(CGameParam :: bWin)
		{
			CGameParam::lScorePlayer ++;
			if(CGameParam::lScorePlayer > 999)
				CGameParam::lScorePlayer = 999;
			CGameParam::lScoreEnemy --;
			if(CGameParam::lScoreEnemy < 0)
				CGameParam::lScoreEnemy = 0;
		}
		else
		{
			CGameParam::lScorePlayer --;
			CGameParam::lScoreEnemy ++;
			if(CGameParam::lScorePlayer < 0)
				CGameParam::lScorePlayer = 0;
		}

		pGetScore->StopWave();
		pGetScore->PlayWave(FALSE);

		lShowScore --;
		if(lShowScore <= 0)
		{
			lCountMem = lCount;
			if(!bReach[_PLAYER_] && !bReach[_ENEMY_])
				lPhase = 35;
			else
				lPhase = 36;
		}
		break;

	case 35:
  
		//しばらく待つ
		if(lCount - lCountMem > 60)
		{
			//5回戦?
			if(lKaisen >= 4)
			{
				if(CGameParam::lScorePlayer < CGameParam::lScoreEnemy)
				{
					pWinVoice->StopWave();
			  		pWinVoice->PlayWave(FALSE);
 					CGameParam::bWin = FALSE;
					lWinLose = 2;
				}
				else
				{ 
					pLoseVoice->StopWave();
					pLoseVoice->PlayWave(FALSE);
					CGameParam::bWin = TRUE;
				lWinLose = 1;
				}
			}
			else
			{
				if(CGameParam::lScorePlayer <= 0)
				{
					pWinVoice->StopWave();
					pWinVoice->PlayWave(FALSE);
					lWinLose = 2;
				}
				if(CGameParam::lScoreEnemy <= 0)
				{
					pLoseVoice->StopWave();
					pLoseVoice->PlayWave(FALSE);
					lWinLose = 1;
				}
			}
			lCountMem = lCount;
			lPhase = 30;
		}
		break;

	//リーチ棒の返却
	case 36:

		//しばらく待つ
		if(lCount - lCountMem < 40)
			break;

		lShowScore = 0;
		if(bReach[_PLAYER_])
		{
			lShowScore += 10;
			bReach[_PLAYER_] = FALSE;
		}
		if(bReach[_ENEMY_])
		{
			lShowScore += 10;
			bReach[_ENEMY_] = FALSE;
		}
		lPhase = 37;
		break;

	case 37:

		if(lCount & 1)
			break;
		if(CGameParam :: bWin)
		{
			CGameParam::lScorePlayer ++;
			if(CGameParam::lScorePlayer > 999)
				CGameParam::lScorePlayer = 999;
		}
		else
			CGameParam::lScoreEnemy ++;

		pGetScore->StopWave();
		pGetScore->PlayWave(FALSE);

		lShowScore --;
		if(lShowScore <= 0)
		{
			lCountMem = lCount;
			lPhase = 35;
		}
		break;

	case 38:

		//しばらく待つ
		if(lCount - lCountMem < 40)
			break;

		//荒井の必殺技が有効なら
		if(CGameParam::lStage == 2 &&
			bHissatsu[_ENEMY_])
		{
			lShowScore *= 3;
			lShowScore /= 2;
		}
		//今西の必殺技が有効なら
		if(CGameParam::lStage == 5 &&
			bHissatsu[_ENEMY_])
		{
			lShowScore *= 130;
			lShowScore /= 100;
		}
		lPhase = 34;
		break;


	//ロンとかのメッセージ
	case 40:
	case 41:

		if(lCount - lCountMem < 120)
			break;

		bAgari = TRUE;

		//原秀ステージなら
		if(CGameParam::lStage == 4 &&
			timeGetTime() % 100 < (30 - lKaisen * 5) &&
			lYakuten[lAgariNumPlayer] != 90)
		{
			//リーチ棒は戻ってくる
			if(bReach[_PLAYER_])
				CGameParam::lScorePlayer += 10;
			lCountMem = lCount;
			//原秀の必殺技へ
			lPhase = 1000;
		}
		else
		{
			pAgarareVoice->StopWave();
			pAgarareVoice->PlayWave(FALSE);
			
			lCountMem = lCount;
			lPhase = 31;
		}
		break;
	
	//ロンとかのメッセージ
	case 42:
	case 43:

		if(lCount - lCountMem < 120)
			break;
		

		bAgari = TRUE;
		lCountMem = lCount;

		//荒井がロン上がりなら
		if(lPhase == 43 &&
			CGameParam::lStage == 2 &&
			timeGetTime() % 100 < 30)
		{
			lPhase = 1200;
			bHissatsu[_ENEMY_] = TRUE;

			pHissatsuVoice->StopWave();
			pHissatsuVoice->PlayWave(FALSE);
		}
		//今西が上がったら
		else if(CGameParam::lStage == 5 &&
			timeGetTime() % 100 < 75)
		{
			lPhase = 1500;
			bHissatsu[_ENEMY_] = TRUE;

			pHissatsuVoice->StopWave();
			pHissatsuVoice->PlayWave(FALSE);
		}
		else
		{
			pAgariVoice->StopWave();
			pAgariVoice->PlayWave(FALSE);
			lPhase = 31;
		}
		break;

	//流局
	case 44:

		bAgari = TRUE;
		if(lCount - lCountMem > 120)
		{
			//ノーテンチェック

			//プレイヤー テンパイしてる？
			int cnt;
			for(cnt = 0;cnt < 9;cnt ++)
				PaiTemp[cnt].lKind = PaiPlayer[cnt].lKind;
			SortPaiTemp();
			//リーチ可能？
			if(IsTempai() > 0)
				bTempai[_PLAYER_] = TRUE;
			else
				bTempai[_PLAYER_] = FALSE;


			//敵 テンパイしてる？
			for(cnt = 0;cnt < 9;cnt ++)
				PaiTemp[cnt].lKind = PaiEnemy[cnt].lKind;
			SortPaiTemp();
			if(IsTempai() > 0)
				bTempai[_ENEMY_] = TRUE;
			else
				bTempai[_ENEMY_] = FALSE;


			lCountMem = lCount;
//			lPhase = 30;
			lPhase = 50;
		}
		break;

	//ポン
	case 45:

		if(lCount - lCountMem > 90)
			lPhase = 0;
		break;

	//リーチ!
	case 46:
	case 47:

		if(lCount - lCountMem < 80)
			break;

		//リーチしたのがプレイヤー？
		if(lPhase == 46)
		{
			//リーチした！
			bReach[_PLAYER_] = TRUE;
			switch(CGameParam::lStage)
			{
			//中川
			case 7:

				if(!bReach[_ENEMY_] &&
					timeGetTime() % 100 < 40)
				{
					pHissatsuVoice->StopWave();
					pHissatsuVoice->PlayWave(FALSE);
 
					bHissatsu[_ENEMY_] = TRUE;
					lCountMem = lCount;
					lPhase = 1700;
				}
				else
					lPhase = 0;
				break;

			//木曽
			case 8:

				if(timeGetTime() % 100 < 70)
				{
					bHissatsu[_ENEMY_] = TRUE;
					lCountMem = lCount;
					lPhase = 1800;
				}
				else
					lPhase = 0;
				break;

			default:
				lPhase = 0;
				break;
			}
		}
		//リーチしたのが敵？
		if(lPhase == 47)
		{
			//リーチした！
			bReach[_ENEMY_] = TRUE;
			switch(CGameParam::lStage)
			{
			//石田
			case 1:

				//リーチ後は上がる確率が高い
				lAgaruKakuritsu += 20;
				//石田なら必殺技
				lPhase = 1100;
				pHissatsuVoice->StopWave();
				pHissatsuVoice->PlayWave(FALSE);
				if(CGame.IsUseMidiSound())
				{
					CGame.StopMidi();
					CGame.PlayMidi("Bgm\\ishida.mid");
				}

				break;

			//デビル
			case 6:

				if(timeGetTime() % 100 < 55)
				{
					//リーチ後は上がる確率が高い
					lAgaruKakuritsu += 100;
					bHissatsu[_ENEMY_] = TRUE;
					//必殺技
					lPhase = 1600;
					pHissatsuVoice->StopWave();
					pHissatsuVoice->PlayWave(FALSE);
				}
				else
				{
					//リーチ後は上がる確率が高い
					lAgaruKakuritsu += 8;
					lPhase = 10;
				}
				if(CGame.IsUseMidiSound())
				{
					CGame.StopMidi();
					CGame.PlayMidi("Bgm\\reachenemy.mid");
				}
				break;

			//ラスボス
			case 9:

				//ラスボスはリーチ後は確率アップ
				if(CGameParam::lStage == 9)
					lAgaruKakuritsu += 25;
				lWaitTime = timeGetTime() % 40;
				lPhase = 10;
				if(CGame.IsUseMidiSound())
				{
					CGame.StopMidi();
					CGame.PlayMidi("Bgm\\reachenemy.mid");
				}
				break;

			default:

				lAgaruKakuritsu += 5;
				lPhase = 10;
				if(CGame.IsUseMidiSound())
				{
					CGame.StopMidi();
					CGame.PlayMidi("Bgm\\reachenemy.mid");
				}
				break;
			}
			lCountMem = lCount;
		}
		break;

	//テンパイ！ノーテン！
	case 50:

		if(lCount - lCountMem < 40 + 40 + 60)
			break;

		lShowScore = 0;
		if(bTempai[_PLAYER_] && !bTempai[_ENEMY_])
		{
			CGameParam :: bWin = TRUE;
			lShowScore = 10;
		}
		if(!bTempai[_PLAYER_] && bTempai[_ENEMY_])
		{
			CGameParam :: bWin = FALSE;
			lShowScore = 10;
		}
		bReach[_PLAYER_] = FALSE;
		bReach[_ENEMY_] = FALSE;
		lCountMem = lCount;
		if(lShowScore == 0)
			lPhase = 35;
		else
			lPhase = 34;
		break;

	//配牌
	case 100:

		if(lCount % 10 == 0)
		{
			lHaiPaiNum[_PLAYER_] ++;
			pTsumo->StopWave();
			pTsumo->PlayWave(FALSE);
		}
		if(lCount % 10 == 5)
		{
			lHaiPaiNum[_ENEMY_] ++;
			pTsumo->StopWave();
			pTsumo->PlayWave(FALSE);
		}
		if(lHaiPaiNum[_PLAYER_] >= 9)
		{
			lPhase = 0;
			lCount = 0;
			lCountMem = 0;

			//BGM関連
			if(CGame.IsUseMidiSound())
				CGame.PlayMidi("Bgm\\battle.mid");
		}
		break;

	//原秀の必殺技
	case 1000:

		if(lCount - lCountMem < 80)
			break;
//		lKaisen ++;
		lCountMem = lCount;
		lNextPhase = 1001;
		lPhase = 1990;
		break;

	case 1001:

		if(lCount - lCountMem < 120)
			break;
		if(CGame.IsUseMidiSound())
			CGame.StopMidi();

		lCountMem = lCount;
		lPhase = 30;
		break;

	//サイバースーツ！
	case 1100:

		if(lCount - lCountMem < 80)
			break;
		lCountMem = lCount;
		lNextPhase = 10;
		lPhase = 1990;
		break;

	//荒井
	case 1200:

		if(lCount - lCountMem < 80)
			break;
		lCountMem = lCount;
		lNextPhase = 31;
		lPhase = 1990;
		break;

	//恐怖のモーニングコール
	case 1300:

		if(lCount - lCountMem < 80)
			break;
		lCountMem = lCount;
		lNextPhase = 0;
		lPhase = 1990;
		break;

	//恐怖のモーニングコール
	case 1301:

		if(lCount - lCountMem < 80)
			break;
		lCountMem = lCount;
		lNextPhase = 11;
		lPhase = 1990;
		break;

	//今西
	case 1500:

		if(lCount - lCountMem < 80)
			break;
		lCountMem = lCount;
		lNextPhase = 31;
		lPhase = 1990;
		break;

	//デビルリーチ！
	case 1600:

		if(lCount - lCountMem < 80)
			break;
		lCountMem = lCount;
		lNextPhase = 10;
		lPhase = 1990;
		break;

	//中川
	case 1700:

		if(lCount - lCountMem < 80)
			break;
		lCountMem = lCount;
		lNextPhase = 99999;
		lPhase = 1990;
		break;

	//木曽！
	case 1800:

		if(lCount - lCountMem < 100)
			break;
		lCountMem = lCount;
		lNextPhase = 0;
		lPhase = 1990;
		break;

	//悪のサーバ！
	case 1900:

		if(lCount - lCountMem < 80)
			break;
		lCountMem = lCount;
		lNextPhase = 38;
		CGameParam :: bWin = FALSE;
		lPhase = 1990;
		break;

	//悪の催眠術！
	case 1950:

		if(lCount - lCountMem < 80)
			break;
		lCountMem = lCount;
		lNextPhase = 38;
		CGameParam :: bWin = FALSE;
		lShowScore = 90;
		lPhase = 1990;
		break;

	//技の説明
	case 1990:

		if(lCount - lCountMem < 120)
			break;
		lCountMem = lCount;
		lPhase = 1991;
		break;

	//技の説明消す
	case 1991:

		if(lCount - lCountMem < 94/3)
			break;
		lCountMem = lCount;
		lPhase = lNextPhase;
		break;

	case 10000:

		if(lCount - lCountMem < 40)
			break;

		lCountMem = lCount;
		lPhase = 100;
		break;
	
	case 99999:

		if(lCount - lCountMem < 40)
			break;
		return FALSE;
	}


	if(!(*dwKeyFlag & PLAYER_1) &&
		!(*dwKeyFlag & PLAYER_2) &&
		!(*dwKeyFlag & PLAYER_3) &&
		!(*dwKeyFlag & PLAYER_4) &&
		!(*dwKeyFlag & PLAYER_5) &&
		!(*dwKeyFlag & PLAYER_6) &&
		!(*dwKeyFlag & PLAYER_7) &&
		!(*dwKeyFlag & PLAYER_8) &&
		!(*dwKeyFlag & PLAYER_9) &&
		!(*dwKeyFlag & PLAYER_RON) &&
		!(*dwKeyFlag & PLAYER_PON))
	{
		bKeyDownFlag = FALSE;
	}

	lCount ++;
 	return TRUE;

}


BOOL CBattle :: Draw(void)
{

	if(lOdoshi > 0)
	{
		pHarumi->Blt(225,115,7);
		pEnemy->Blt(8,8,1);
	}

	switch(lPhase)
	{
	case 1:

		if(lCount - lCountMem < 20 + lWaitTime)
			pHarumi->Blt(225,115,3);
		break;
	//得点表を表示
	case 33:

		//プレイヤーが勝った?
		if(CGameParam :: bWin)
		{
			//役で上がっていれば
			if(lCount - lCountMem > 15)
			{
				if(lAgariNumPlayer >= 0)
					pYaku->Blt(96,64,lYakuTbl[lAgariNumPlayer]);
			}
			if(lCount - lCountMem > 30)
			{
				if(bReach[_PLAYER_])
					pTokuten->Blt(67,119,12);
			}
			//リーチ一発?
			if(lCount - lCountMem > 45)
			{
				if(lReachIppatsu[_PLAYER_] > 0)
					pTokuten->Blt(130,119,13);
			}
			//面前ツモ？
			if(lCount - lCountMem > 60)
			{
				if(bTsumo[_PLAYER_] && lPonNum[_PLAYER_] == 0)
					pTokuten->Blt(193,119,11);
			}
			//ないた？
			if(lCount - lCountMem > 45)
			{
				if(lPonNum[_PLAYER_] > 0 &&
					!bYakuman[_PLAYER_])
					pTokuten->Blt(67,141,14);
			}
		}
		else
		{
			if(lCount - lCountMem > 15)
			{
				if(lAgariNumEnemy >= 0)
					pYaku->Blt(96,64,lYakuTbl[lAgariNumEnemy]);
			}
			if(lCount - lCountMem > 30)
			{
				if(bReach[_ENEMY_])
					pTokuten->Blt(67,119,12);
			}
			//リーチ一発?
			if(lCount - lCountMem > 45)
			{
				if(lReachIppatsu[_ENEMY_] > 0)
					pTokuten->Blt(130,119,13);
			}
			if(lCount - lCountMem > 60)
			{
				if(bTsumo[_ENEMY_] && lPonNum[_ENEMY_] == 0)
					pTokuten->Blt(193,119,11);
			}
			if(lCount - lCountMem > 45)
			{
				if(lPonNum[_ENEMY_] > 0 &&
					!bYakuman[_ENEMY_])
					pTokuten->Blt(67,141,14);
			}
		}
		if(lCount - lCountMem > 80)
		{
			LONG lPtr = 0;
			switch(lShowScore)
			{
			case 10:
				lPtr = 0;
				break;
			case 15:
				lPtr = 1;
				break;
			case 20:
				lPtr = 3;
				break;
			case 25:
				lPtr = 2;
				break;
			case 30:
				lPtr = 4;
				break;
			case 35:
				lPtr = 5;
				break;
			case 40:
				lPtr = 6;
				break;
			case 50:
				lPtr = 7;
				break;
			case 60:
				lPtr = 8;
				break;
			case 70:
				lPtr = 9;
				break;
			case 90:
				lPtr = 10;
				break;
			}
			pTokuten->Blt(130,141,lPtr);
		}
		pKokuban->Blt(0,0,0);
		break;

	//プレイヤーがつもった
	case 40:

		pRonMsg->Blt(104,160,2);
		pHarumi->Blt(225,115,3);
		break;

	//プレイヤーがロン
	case 41:

		pRonMsg->Blt(104,160,0);
		pHarumi->Blt(225,115,3);
		break;

	//敵がツモった
	case 42:

		pRonMsg->Blt(104,20,2);
		pHarumi->Blt(225,115,1);
		break;

	//敵がロン
	case 43:

		pRonMsg->Blt(104,20,0);
		pHarumi->Blt(225,115,1);
		break;

	//流局
	case 44:

		pRonMsg->Blt(104,83,3);
		pHarumi->Blt(225,115,4);
		pEnemy->Blt(8,8,2);
		break;

	//プレイヤーがポン
	case 45:

		pRonMsg->Blt(104,160,1);
		pHarumi->Blt(225,115,5);
		break;

	//リーチ!
	case 46:
		pRonMsg->Blt(104,160,4);
		break;
	//リーチ!
	case 47:
		pRonMsg->Blt(104,20,4);
		break;

	//テンパイ！ノーテン！!
	case 50:

		if(bTempai[_ENEMY_])
			pRonMsg->Blt(104,20,5);
		else
			pRonMsg->Blt(104,20,6);

		if(lCount - lCountMem > 40)
		{
			if(bTempai[_PLAYER_])
				pRonMsg->Blt(104,160,5);
			else
				pRonMsg->Blt(104,160,6);
		}
		break;

	//配牌
	case 100:

		//第何回戦かを表示
		pKaisen->Blt(104,88,lKaisen);

		int cnt;
		for(cnt=0;cnt < lHaiPaiNum[_PLAYER_];cnt++)
		{
			pPai->Blt(3 + cnt*24 - cnt,195,39);
			//牌の影
			if(lCount & 1)
				pPai->Blt(3 + cnt*24 - cnt,195 + 34,60);
		}
		for(cnt=0;cnt < lHaiPaiNum[_ENEMY_];cnt++)
		{
			pPai->Blt(132 + (7 - cnt)*24 - (7 - cnt),3,59); 
			//牌の影
			if(lCount & 1)
				pPai->Blt(132 + (7 - cnt)*24 - (7 - cnt),3 + 34,60);
		}
		break;

	//原秀の必殺技
	case 1000:

		pHissatsu->Blt(0,60,0);
		break;

	//サイバースーツ
	case 1100:
		pHissatsu->Blt(0,60,0);
		break;

	//荒井
	case 1200:
		pHissatsu->Blt(0,60,0);
		break;

	//恐怖のモーニングコール
	case 1300:
	case 1301:
		pHissatsu->Blt(0,60,0);
		break;

	//今西
	case 1500:
		pHissatsu->Blt(0,60,0);
		break;

	//デビルリーチ
	case 1600:
		pHissatsu->Blt(0,60,0);
		if(lCount & 1)
		{
			for(cnt = 0;cnt < 240;cnt++)
				pBG->Blt(0,cnt,2);
		}
		break;

	//中川
	case 1700:
		pHissatsu->Blt(0,60,0);
		break;

	//木曽
	case 1800:

		{
			static LONG kakeru = 0;
			static LONG l = 0;
			//ラスタをかける
			for(cnt = 0;cnt < 94;cnt++)
			{
				int x = 0;
				x += (kakeru/3)*MGLMath::GetSin(l+cnt*6);
				pHissatsu->Blt((x/1024)+320,cnt + 60,cnt);
				pHissatsu->Blt((x/1024),cnt + 60,cnt);
				pHissatsu->Blt((x/1024)-320,cnt + 60,cnt);
			}
			l += 15;
			kakeru ++;
			if(kakeru > 30)
				kakeru = 30;
		}
		break;

	//悪のサーバ
	case 1900:
		pHissatsu->Blt(0,60,0);
		if(lCount & 1)
		{
			for(cnt = 0;cnt < 240;cnt++)
				pBG->Blt(0,cnt,1);
		}
		break;

	//催眠術
	case 1950:
		pHissatsu->Blt(0,60,0);
		if(lCount & 1)
		{
			for(cnt = 0;cnt < 240;cnt++)
				pBG->Blt(0,cnt,1);
		}
		break;

	//必殺技の説明
	case 1990:
		pHissatsuSetsumei->Blt(0,60,0);
		break;

	//画面開く
	case 10000:

		for(cnt = 0;cnt < 240;cnt++)
		{
			if(cnt & 1)
				pBG->Blt((lCount - lCountMem) * 8,cnt,1);
			else
				pBG->Blt(-(lCount - lCountMem) * 8,cnt,1);
		}
		break;

	//画面閉じる
	case 99999:
		for(cnt = 0;cnt < 240;cnt++)
		{
			if(cnt & 1)
				pBG->Blt((lCount - lCountMem) * 8 - 320,cnt,1);
			else
				pBG->Blt(-(lCount - lCountMem) * 8 + 320,cnt,1);
		}
		break;

	}

	//勝ち負けの表示
	switch(lWinLose)
	{
	case 1:

		pRonMsg->Blt(104,20,8);
		pRonMsg->Blt(104,160,7);
		break;

	case 2:

		pRonMsg->Blt(104,20,7);
		pRonMsg->Blt(104,160,8);
		break;
	}



	//得点を表示
	char str[4];
	sprintf(str,"%3d",CGameParam::lScorePlayer);
	for(int cnt=0;cnt < 3;cnt++)
	{
		if(str[cnt] >= '0' && str[cnt] <= '9')
			pSuuji->Blt(183 + cnt*8,117,str[cnt]-'0' + 10);
		else
			pSuuji->Blt(183 + cnt*8,117,10);
	}
	sprintf(str,"%3d",CGameParam::lScoreEnemy);
	for(cnt=0;cnt < 3;cnt++)
	{
		if(str[cnt] >= '0' && str[cnt] <= '9')
			pSuuji->Blt(125 + cnt*8,117,str[cnt]-'0' + 10);
		else
			pSuuji->Blt(125 + cnt*8,117,10);
	}

	//リーチ棒を表示
	if(bReach[_PLAYER_])
	{
		pReach->Blt(100,156 + 34,0);
		pReach->Blt(100 + 24,156 + 34,1);
	}
	if(bReach[_ENEMY_])
	{
		pReach->Blt(200,42,0);
		pReach->Blt(200 + 24,42,1);
	}

	//自分の牌

	//決着がついている?
	if((lPhase >= 30 && lPhase < 40) || lPhase == 50 || bAgari)
	{
		for(int cnt=0;cnt < 8;cnt++)
		{
			if(PaiPlayer[cnt].lKind != 999)
			{
				if(PaiPlayer[cnt].lStat == 0)
				{
					pPai->Blt(3 + cnt*24 - cnt,195,PaiPlayer[cnt].lKind + 10);
					//牌の影
					if(lCount & 1)
						pPai->Blt(3 + cnt*24 - cnt,195 + 34,60);
				}
				else
				{
					pPai->Blt(3 + cnt*24 - cnt,195 + 3,PaiPlayer[cnt].lKind + 30);
					//牌の影
					if(lCount & 1)
						pPai->Blt(3 + cnt*24 - cnt,195 + 3 + 34,60);
				}
			}
		}
		//つもった牌
		if(PaiPlayer[cnt].lKind != 999)
		{
			if(PaiPlayer[cnt].lStat == 0)
			{
				pPai->Blt(192,195,PaiPlayer[cnt].lKind + 10);
				//牌の影
				if(lCount & 1)
					pPai->Blt(192,195 + 34,60);
			}
			else
			{
				pPai->Blt(192,195 + 3,PaiPlayer[cnt].lKind + 30);
				//牌の影
				if(lCount & 1)
					pPai->Blt(192,195 + 5 + 34,60);
			}
		}
		//顔を表示
		if(lPhase != 99999)
		{
			if(CGameParam::bWin)
			{
				pHarumi->Blt(225,115,3);
				pEnemy->Blt(8,8,2);
			}
			else
			{
				pHarumi->Blt(225,115,1);
				if(bRyukyoku)
					pEnemy->Blt(8,8,2);
				else
					pEnemy->Blt(8,8,1);
			}
		}
	}
	else if(lPhase != 100 && lPhase != 10000)
	{
		if(bRonOK)
			pIcon->Blt(190,190,0);
		if(bTsumoOK)
			pIcon->Blt(190,190,2);
		if(bReachOK)
			pIcon->Blt(190,190,3);
		if(bPonOK)
			pIcon->Blt(190,190,1);

		if(bNextTsumoOK)
		{
			LONG lTemp = lCount % 20;
			if(lTemp > 10)
				pIcon->Blt(190,210 - (lTemp - 10),4);
			else
				pIcon->Blt(190,200 + lTemp,4);

			bNextTsumoOK = FALSE;
		}

		for(int cnt=0;cnt < 8;cnt++)
		{
			if(PaiPlayer[cnt].lKind != 999)
			{
				if(PaiPlayer[cnt].lStat == 0)
				{
					pPai->Blt(3 + cnt*24 - cnt,195,PaiPlayer[cnt].lKind);
					pSuuji->Blt(11 + cnt*23,232,cnt + 1);
					//牌の影
					if(lCount & 1)
						pPai->Blt(3 + cnt*24 - cnt,195 + 36,60);
				}
				else
				{
					//ないた牌
					pPai->Blt(3 + cnt*24 - cnt,195 + 5,PaiPlayer[cnt].lKind + 30);
					//牌の影
					if(lCount & 1)
						pPai->Blt(3 + cnt*24 - cnt,195 + 5 + 34,60);
				}
			}
		}
		pSuuji->Blt(200,232,cnt + 1);
		if(PaiPlayer[cnt].lKind != 999)
		{
			if(PaiPlayer[cnt].lStat == 0)
				pPai->Blt(192,195,PaiPlayer[cnt].lKind);
			else
				pPai->Blt(192,195 + 5,PaiPlayer[cnt].lKind + 30);

			//牌の影
			if(lCount & 1)
				pPai->Blt(192,195 + 36,60);
		}
		pHarumi->Blt(225,115,0);
		if(CGameParam::lStage == 1 &&
			bReach[_ENEMY_])
			pEnemy->Blt(8,8,3);
		else
			pEnemy->Blt(8,8,0);

	}

	if(lPhase != 100 && lPhase != 10000)
	{
		for(cnt=0;cnt < 9;cnt++)
		{
			if(SutePaiPlayer[cnt + 9].lKind != 999)
			{
				if(SutePaiPlayer[cnt + 9].lStat == 0)
					pPai->Blt(8 + cnt*24 - cnt,156,SutePaiPlayer[cnt + 9].lKind + 10);
				else if(SutePaiPlayer[cnt + 9].lStat == 1)
					pPai->Blt(8 + cnt*24 - cnt,156,SutePaiPlayer[cnt + 9].lKind + 30);
				else
					pPai->Blt(8 + cnt*24 - cnt,156,SutePaiPlayer[cnt + 9].lKind + 50);

				//牌の影
				if(lCount & 1)
					pPai->Blt(8 + cnt*24 - cnt,156 + 34,60);
			}
		}
		for(cnt=0;cnt < 9;cnt++)
		{
			if(SutePaiPlayer[cnt].lKind != 999)
			{
				if(SutePaiPlayer[cnt].lStat == 0)
					pPai->Blt(8 + cnt*24 - cnt,132,SutePaiPlayer[cnt].lKind + 10);
				else if(SutePaiPlayer[cnt].lStat == 1)
					pPai->Blt(8 + cnt*24 - cnt,132,SutePaiPlayer[cnt].lKind + 30);
				else
					pPai->Blt(8 + cnt*24 - cnt,132,SutePaiPlayer[cnt].lKind + 50);

				//牌の影
				if(lCount & 1)
					pPai->Blt(8 + cnt*24 - cnt,132 + 34,60);
			}
		}
	}

	//敵の牌

	//決着がついている?
	if((lPhase >= 30 && lPhase < 40) || lPhase == 50 || bAgari)
	{
		for(cnt=0;cnt < 8;cnt++)
		{
			if(PaiEnemy[cnt].lKind != 999)
			{
				pPai->Blt(132 + cnt*24 - cnt,3,PaiEnemy[cnt].lKind + 10);
				//牌の影
				if(lCount & 1)
					pPai->Blt(132 + cnt*24 - cnt,3 + 34,60);
			}
		}
		if(PaiEnemy[cnt].lKind != 999)
		{
			pPai->Blt(104,3,PaiEnemy[cnt].lKind + 10);
			//牌の影
			if(lCount & 1)
				pPai->Blt(104,3 + 34,60);
		}
	}
	else if(lPhase != 100 && lPhase != 10000)
	{
		for(cnt=0;cnt < 8;cnt++)
		{
			pPai->Blt(132 + cnt*24 - cnt,3,9);
			//牌の影
			if(lCount & 1)
				pPai->Blt(132 + cnt*24 - cnt,3 + 36,60);
		}
		if(lPhase == 10)
		{
			pPai->Blt(104,3,9);
			//牌の影
			if(lCount & 1)
				pPai->Blt(104,3 + 36,60);
		}
	}

	if(lPhase != 100)
	{
		for(cnt=0;cnt < 9;cnt++)
		{
			if(SutePaiEnemy[cnt + 9].lKind != 999)
			{
				if(SutePaiEnemy[cnt + 9].lStat == 0)
					pPai->Blt(104 + cnt*24 - cnt,71,SutePaiEnemy[cnt + 9].lKind + 10);
				else if(SutePaiEnemy[cnt + 9].lStat == 1)
					pPai->Blt(104 + cnt*24 - cnt,71,SutePaiEnemy[cnt + 9].lKind + 30);
				else
					pPai->Blt(104 + cnt*24 - cnt,71,SutePaiEnemy[cnt + 9].lKind + 50);

				//牌の影
				if(lCount & 1)
					pPai->Blt(104 + cnt*24 - cnt,71 + 34,60);
			}
		}
		for(cnt=0;cnt < 9;cnt++)
		{
			if(SutePaiEnemy[cnt].lKind != 999)
			{
				if(SutePaiEnemy[cnt].lStat == 0)
					pPai->Blt(104 + cnt*24 - cnt,47,SutePaiEnemy[cnt].lKind + 10);
				else if(SutePaiEnemy[cnt].lStat == 1)
					pPai->Blt(104 + cnt*24 - cnt,47,SutePaiEnemy[cnt].lKind + 30);
				else
					pPai->Blt(104 + cnt*24 - cnt,47,SutePaiEnemy[cnt].lKind + 50);

				//牌の影
				if(lCount & 1)
					pPai->Blt(104 + cnt*24 - cnt,47 + 34,60);
			}
		}
	}

	if(CGameParam::lStage == 9 &&
		CGameParam::bLastBattle &&
		MGLMath::GetRand() % 30 == 0)
	{
		for(int cnt = 0;cnt < 240;cnt++)
			pBG->Blt(0,cnt,1);
	}

	//卓
	pBG->Blt(0,0,0);
 
	//必殺技の説明消す
	if(lPhase == 1991)
		pHissatsuSetsumei->StretchBlt(0 - (lCount - lCountMem)*3/2,60 + (lCount - lCountMem)*3/2,0,320 + (lCount - lCountMem)*2*3/2,94 - (lCount - lCountMem)*2*3/2);  
	//今西のデブ
	if(lPhase == 1500)
		pHissatsu->StretchBlt(0 - (lCount - lCountMem)*3,60 - (lCount - lCountMem)*3,0,320 + (lCount - lCountMem)*2*3,94 + (lCount - lCountMem)*2*3);  
 
	return TRUE;
}


BOOL CBattle :: CleanUp(void)
{
	IDELETE(pBG);
	IDELETE(pPai);
	IDELETE(pSuuji);
	IDELETE(pRonMsg);
	IDELETE(pReach);

	IDELETE(pHarumi);
	IDELETE(pEnemy);
	IDELETE(pIcon);
	IDELETE(pHissatsu);
	IDELETE(pHissatsuSetsumei);
	IDELETE(pKaisen);

	IDELETE(pKokuban);
	IDELETE(pTokuten);
	IDELETE(pYaku);

	IDELETE(pTsumo);
	IDELETE(pSute);
	IDELETE(pVictory);
	IDELETE(pLose);
	IDELETE(pPon);
	IDELETE(pGetScore);

	IDELETE(pAgariVoice);
	IDELETE(pWinVoice);
	IDELETE(pAgarareVoice);
	IDELETE(pLoseVoice);
	IDELETE(pHissatsuVoice);

	if(CGame.IsUseMidiSound())
		CGame.StopMidi();

	return TRUE;
}


VOID CBattle :: SortPai(PAI* pPai)
{
	LONG lIndex = 0;
	while(lIndex < 8)
	{
		for(int cnt = lIndex + 1;cnt < 9;cnt ++)
		{
			if(pPai[lIndex].lKind >= pPai[cnt].lKind)
			{
				LONG lTempKind = pPai[lIndex].lKind;
				pPai[lIndex].lKind = pPai[cnt].lKind;
				pPai[cnt].lKind = lTempKind;

				LONG lTempStat = pPai[lIndex].lStat;
				pPai[lIndex].lStat = pPai[cnt].lStat;
				pPai[cnt].lStat = lTempStat;
			}
		}
		lIndex ++;
	}

	//ないた牌は前へ持ってくる
	lIndex = 0;
	while(lIndex < 8)
	{
		for(int cnt = lIndex + 1;cnt < 9;cnt ++)
		{
			if(pPai[lIndex].lStat < pPai[cnt].lStat)
			{
				LONG lTempKind = pPai[lIndex].lKind;
				pPai[lIndex].lKind = pPai[cnt].lKind;
				pPai[cnt].lKind = lTempKind;

				LONG lTempStat = pPai[lIndex].lStat;
				pPai[lIndex].lStat = pPai[cnt].lStat;
				pPai[cnt].lStat = lTempStat;
			}
		}
		lIndex ++;
	}

	//何個ないているか調べる
	lIndex = 0;
	if(pPai[6].lStat == 1)
		lIndex = 9;
	else if(pPai[3].lStat == 1)
		lIndex = 6;
	else if(pPai[0].lStat == 1)
		lIndex = 3;

	if(lIndex > 0)
	{
		while(lIndex < 8)
		{
			for(int cnt = lIndex + 1;cnt < 9;cnt ++)
			{
				if(pPai[lIndex].lKind >= pPai[cnt].lKind)
				{
					LONG lTempKind = pPai[lIndex].lKind;
					pPai[lIndex].lKind = pPai[cnt].lKind;
					pPai[cnt].lKind = lTempKind;

					LONG lTempStat = pPai[lIndex].lStat;
					pPai[lIndex].lStat = pPai[cnt].lStat;
					pPai[cnt].lStat = lTempStat;
				}
			}
			lIndex ++;
		}
	}


}


VOID CBattle :: SortPaiTemp(void)
{
	LONG lIndex = 0;
	while(lIndex < 8)
	{
		for(int cnt = lIndex + 1;cnt < 9;cnt ++)
		{
			if(PaiTemp[lIndex].lKind > PaiTemp[cnt].lKind)
			{
				LONG lTemp = PaiTemp[lIndex].lKind;
				PaiTemp[lIndex].lKind = PaiTemp[cnt].lKind;
				PaiTemp[cnt].lKind = lTemp;
			}
		}
		lIndex ++;
	}
}


LONG CBattle :: AgariCheck(void)
{
	LONG lIndex = 0;
	while(lIndex < 138)
	{
		LONG lMuch = 0;
		for(int cnt = 0;cnt < 9;cnt ++)
		{
			if(lInchiki[lIndex][cnt] == PaiTemp[cnt].lKind)
				lMuch ++;
		}
		if(lMuch >= 9)
			return lIndex;

		lIndex ++;
	}
	return -1;
}


//テンパイしてる？
LONG CBattle :: IsTempai(void)
{
	SortPaiTemp();
	LONG l3Mai = 0;
	LONG l2Mai = 0;
	LONG l1Mai = 0;
	LONG lTempKind = 999;
	LONG lPaiCount = 0;

	lTempKind = PaiTemp[0].lKind;
	for(int cnt = 1;cnt < 9;cnt ++)
	{
		if(PaiTemp[cnt].lKind == lTempKind)
		{
			lPaiCount ++;

			if(lPaiCount == 1 &&
				cnt == 8)
			{
				l2Mai ++;
			}
			//3枚組？
			else if(lPaiCount >= 2)
			{
				//3枚組みの数にたす
				l3Mai ++;
				lPaiCount = 0;
				if(cnt + 1 != 9)
				{
					lTempKind = PaiTemp[cnt + 1].lKind;
					cnt ++;
				}
			}
			if(cnt == 9)
				l1Mai ++;
		}
		else
		{
			//0ということは1枚組
			if(lPaiCount == 0)
			{
				//1枚組みの数にたす
				l1Mai ++;
				//1枚組みが2つ以上あったらテンパイではない
//				if(l1Mai >= 2)
//					return FALSE;

				lPaiCount = 0;
				lTempKind = PaiTemp[cnt].lKind;

				if(cnt == 8)
					l1Mai ++;
//				cnt ++;
			}
			//2枚組み？
			else if(lPaiCount == 1)
			{
				//2枚組みの数にたす
				l2Mai ++;
				//2枚組みが2つ以上あったらテンパイではない
//				if(l2Mai >= 2)
//					return FALSE;
				lPaiCount = 0;
				lTempKind = PaiTemp[cnt].lKind;
				if(cnt == 8)
					l1Mai ++;

//				cnt ++;
			}
		}
	}

	//上がってるよ
	if(l3Mai >= 3)
		return 2;
	else if(l3Mai >= 2 && l2Mai >= 1 && l1Mai <= 1)
		return 1;
	else
		return 0;
}



