
#include "MGLInit.h"
#include "haljan.h"
#include "CStage02.h"


//	荒井先生編　文章は27枚です

LONG lHarumiTbl02[] = {
6,0,0,0,3,3,7,7,7,7,7,7,7,7,-1,4,7,7,6,7,6,8,-1,6,-1
};

//	左側に表示する妖精です
LONG lFairyTbl02[] = {
0,1,0,1,0,5,4,4,5,5,4,4,5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,-1
};

//	追加しました　右側に表示する妖精です
LONG lFairyRightTbl02[] = {
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,2,-1,-1,-1,-1,-1,-1,-1,4,-1,-1
};


//	追加しました	先生のデータです
LONG lTeacherTbl02[] = {
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,1,1,0,0,1,1,2,1,-1,1
};	



BOOL CStage02 :: SetUp(LONG lParam)
{
	lSerihuCenter = 21;
	lSerihuMax = 25;
	CGameParam::lStage = 2;
	pHarumiTbl = lHarumiTbl02;
	pFairyTbl = lFairyTbl02;
	pFairyRightTbl = lFairyRightTbl02;
	pTeacherTbl = lTeacherTbl02;

	//背景を作る
	pBG = new MGLSprite;
	pBG->LoadBmpFile("CharaData\\sinario_arai.hal",10,FALSE);
	for(int cnt=0;cnt < lSerihuMax;cnt++)
		pBG->AddPtr(0 + cnt*320,0,320 + cnt*320,240);

	//主人公を作る
	pHarumi = new MGLSprite;
	pHarumi->LoadBmpFile("CharaData\\harumi.hal",10 + 88,TRUE);
	for(cnt=0;cnt < 9;cnt++)
		pHarumi->AddPtr(cnt*87,0,cnt*87 + 87,117);

	//タイトル画面を作る
	pTitle = new MGLSprite;
	pTitle->LoadBmpFile("CharaData\\title_arai.hal",10 + 88 + 48,FALSE);
	pTitle->AddPtr(0,0,320,240);
	pTitle->AddPtr(0,0,320,1);

	//妖精を作る
	pFairy = new MGLSprite;
	pFairy->LoadBmpFile("CharaData\\yousei.hal",10 + 88 + 48 + 20,TRUE);
	for(cnt=0;cnt < 6;cnt++)
		pFairy->AddPtr(cnt*87,0,cnt*87 + 87,117);

	//敵を作る
	pEnemy = new MGLSprite;
	pEnemy->LoadBmpFile("CharaData\\arai.hal",10 + 88 + 48 + 20 + 32,TRUE);
	for(cnt=0;cnt < 3;cnt++)
		pEnemy->AddPtr(cnt*87,0,cnt*87 + 87,117);


	//WAVEを作る
	pUtsu = new MGLWave;
	pUtsu->LoadWave("Sound\\utsu.wav");

	//BGM関連
	if(CGame.IsUseMidiSound())
	{
		CGame.StopMidi();
		CGame.PlayMidi("Bgm\\stage2.mid");
	}

	//パレットをセット
	CGame.SetPalette("CharaData\\sinario_arai.hal",0,10,88);
	CGame.SetPalette("CharaData\\harumi.hal",0,10 + 88,48);
	CGame.SetPalette("CharaData\\title_arai.hal",0,10 + 88 + 48,20);
	CGame.SetPalette("CharaData\\yousei.hal",0,10 + 88 + 48 + 20,32);
	CGame.SetPalette("CharaData\\arai.hal",0,10 + 88 + 48 + 20 + 32,32);
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








