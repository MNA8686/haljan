
#include "MGLInit.h"
#include "haljan.h"
#include "CStage09.h"

//	ロボ編　文章は34枚です

LONG lHarumiTbl09[] = {
5,5,2,4,0,4,5,6,6,6,6,5,5,-1,-1,4,5,2,5,5,8,8,5,6,7,8,8,8,2,2,6,6,4,6
};

//	左側に表示する妖精です
LONG lFairyTbl09[] = {
0,2,0,0,3,0,0,0,5,5,5,-1,-1,-1,-1,-1,-1,4,-1,-1,-1,-1,-1,-1,-1,4,-1,-1,0,2,2,2,-1,-1
};

//	追加しました　右側に表示する妖精です
LONG lFairyRightTbl09[] = {
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
};

//	追加しました	先生のデータです
LONG lTeacherTbl09[] = {
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,1,0,2,-1,0,0,1,1,0,0,2,-1,1,-1,-1,-1,-1,-1,-1,-1
};



BOOL CStage09 :: SetUp(LONG lParam)
{
	lSerihuCenter = 20;
	lSerihuMax = 34;
	CGameParam::lStage = 9;
	pHarumiTbl = lHarumiTbl09;
	pFairyTbl = lFairyTbl09;
	pFairyRightTbl = lFairyRightTbl09;
	pTeacherTbl = lTeacherTbl09;

	//背景を作る
	pBG = new MGLSprite;
	pBG->LoadBmpFile("CharaData\\sinario_rasu.hal",10,FALSE);
	for(int cnt=0;cnt < lSerihuMax;cnt++)
		pBG->AddPtr(0 + cnt*320,0,320 + cnt*320,240);

	//主人公を作る
	pHarumi = new MGLSprite;
	pHarumi->LoadBmpFile("CharaData\\harumi.hal",10 + 88,TRUE);
	for(cnt=0;cnt < 9;cnt++)
		pHarumi->AddPtr(cnt*87,0,cnt*87 + 87,117);

	//タイトル画面を作る
	pTitle = new MGLSprite;
	pTitle->LoadBmpFile("CharaData\\title_rasu.hal",10 + 88 + 48,FALSE);
	pTitle->AddPtr(0,0,320,240);
	pTitle->AddPtr(0,0,320,1);

	//妖精を作る
	pFairy = new MGLSprite;
	pFairy->LoadBmpFile("CharaData\\yousei.hal",10 + 88 + 48 + 20,TRUE);
	for(cnt=0;cnt < 6;cnt++)
		pFairy->AddPtr(cnt*87,0,cnt*87 + 87,117);

	//敵を作る
	pEnemy = new MGLSprite;
	pEnemy->LoadBmpFile("CharaData\\robo.hal",10 + 88 + 48 + 20 + 32,TRUE);
	for(cnt=0;cnt < 3;cnt++)
		pEnemy->AddPtr(cnt*87,0,cnt*87 + 87,117);


	//WAVEを作る
	pUtsu = new MGLWave;
	pUtsu->LoadWave("Sound\\utsu.wav");

	//BGM関連
	if(CGame.IsUseMidiSound())
	{
		CGame.StopMidi();
		CGame.PlayMidi("Bgm\\stage9.mid");
	}

	//パレットをセット
	CGame.SetPalette("CharaData\\sinario_rasu.hal",0,10,88);
	CGame.SetPalette("CharaData\\harumi.hal",0,10 + 88,48);
	CGame.SetPalette("CharaData\\title_rasu.hal",0,10 + 88 + 48,20);
	CGame.SetPalette("CharaData\\yousei.hal",0,10 + 88 + 48 + 20,32);
	CGame.SetPalette("CharaData\\robo.hal",0,10 + 88 + 48 + 20 + 32,32);
	CGame.RealizePalette();

	if(!CGameParam :: bWin)
	{
		lSerihu = -1;
		lSection = 0;
	}
	else
	{
//		lSection = 100;
		lSection = 10;
		lSerihu = lSerihuCenter;
	}
	lCount = lCountMem = 0;

	return TRUE;
}








