
#include "MGLInit.h"
#include "haljan.h"
#include "CStage03.h"


//	加藤先生編　文章は27枚です

LONG lHarumiTbl03[] = {
6,4,0,8,-1,-1,-1,-1,7,-1,-1,4,6,-1,-1,6,-1,5,3,8,8,4,4,4,4,4,0
};

//	左側に表示する妖精です
LONG lFairyTbl03[] = {
5,0,1,0,4,0,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,2
};

//	追加しました　右側に表示する妖精です
LONG lFairyRightTbl03[] = {
-1,-1,-1,-1,-1,-1,-1,4,-1,1,2,-1,-1,1,1,-1,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
};


//	追加しました	先生のデータです
LONG lTeacherTbl03[] = {
-1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,2,2,2,2,1,1,0,0,0,0,1,-1,-1
};	



BOOL CStage03 :: SetUp(LONG lParam)
{
	lSerihuCenter = 18;
	lSerihuMax = 27;
	CGameParam::lStage = 3;
	pHarumiTbl = lHarumiTbl03;
	pFairyTbl = lFairyTbl03;
	pFairyRightTbl = lFairyRightTbl03;
	pTeacherTbl = lTeacherTbl03;

	//背景を作る
	pBG = new MGLSprite;
	pBG->LoadBmpFile("CharaData\\sinario_katou.hal",10,FALSE);
	for(int cnt=0;cnt < lSerihuMax;cnt++)
		pBG->AddPtr(0 + cnt*320,0,320 + cnt*320,240);

	//主人公を作る
	pHarumi = new MGLSprite;
	pHarumi->LoadBmpFile("CharaData\\harumi.hal",10 + 88,TRUE);
	for(cnt=0;cnt < 9;cnt++)
		pHarumi->AddPtr(cnt*87,0,cnt*87 + 87,117);

	//タイトル画面を作る
	pTitle = new MGLSprite;
	pTitle->LoadBmpFile("CharaData\\title_katou.hal",10 + 88 + 48,FALSE);
	pTitle->AddPtr(0,0,320,240);
	pTitle->AddPtr(0,0,320,1);

	//妖精を作る
	pFairy = new MGLSprite;
	pFairy->LoadBmpFile("CharaData\\yousei.hal",10 + 88 + 48 + 20,TRUE);
	for(cnt=0;cnt < 6;cnt++)
		pFairy->AddPtr(cnt*87,0,cnt*87 + 87,117);

	//敵を作る
	pEnemy = new MGLSprite;
	pEnemy->LoadBmpFile("CharaData\\katou.hal",10 + 88 + 48 + 20 + 32,TRUE);
	for(cnt=0;cnt < 3;cnt++)
		pEnemy->AddPtr(cnt*87,0,cnt*87 + 87,117);


	//WAVEを作る
	pUtsu = new MGLWave;
	pUtsu->LoadWave("Sound\\utsu.wav");

	//BGM関連
	if(CGame.IsUseMidiSound())
	{
		CGame.StopMidi();
		CGame.PlayMidi("Bgm\\stage3.mid");
	}

	//パレットをセット
	CGame.SetPalette("CharaData\\sinario_katou.hal",0,10,88);
	CGame.SetPalette("CharaData\\harumi.hal",0,10 + 88,48);
	CGame.SetPalette("CharaData\\title_katou.hal",0,10 + 88 + 48,20);
	CGame.SetPalette("CharaData\\yousei.hal",0,10 + 88 + 48 + 20,32);
	CGame.SetPalette("CharaData\\katou.hal",0,10 + 88 + 48 + 20 + 32,32);
	CGame.RealizePalette();

	if(!CGameParam :: bWin)
	{
		lSerihu = -1;
		lSection = 0;
	}
	else
	{
		lSerihu = lSerihuCenter;
		lSection = 10;
	}
	lCount = lCountMem = 0;

	return TRUE;
}








