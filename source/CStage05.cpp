
#include "MGLInit.h"
#include "haljan.h"
#include "CStage05.h"


//	今西先生編　文章は31枚です
LONG lHarumiTbl05[] = {
0,0,8,-1,2,1,7,7,2,2,4,4,5,5,5,5,6,1,2,2,2,2,5,5,4,0,8,0,3,3,8
};

//	左側に表示する妖精です
LONG lFairyTbl05[] = {
0,2,0,0,0,4,0,3,0,5,0,3,-1,-1,-1,-1,-1,5,0,3,0,1,0,-1,-1,-1,-1,-1,-1,-1,-1
};

//	追加しました　右側に表示する妖精です
LONG lFairyRightTbl05[] = {
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
};

//	追加しました	先生のデータです
LONG lTeacherTbl05[] = {
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,1,1,-1,-1,-1,-1,-1,-1,0,0,1,1,2,1,1,1
};




BOOL CStage05 :: SetUp(LONG lParam)
{
	lSerihuCenter = 27;
	lSerihuMax = 31;
	CGameParam::lStage = 5;
	pHarumiTbl = lHarumiTbl05;
	pFairyTbl = lFairyTbl05;
	pFairyRightTbl = lFairyRightTbl05;
	pTeacherTbl = lTeacherTbl05;

	//背景を作る
	pBG = new MGLSprite;
	pBG->LoadBmpFile("CharaData\\sinario_imanishi.hal",10,FALSE);
	for(int cnt=0;cnt < lSerihuMax;cnt++)
		pBG->AddPtr(0 + cnt*320,0,320 + cnt*320,240);

	//主人公を作る
	pHarumi = new MGLSprite;
	pHarumi->LoadBmpFile("CharaData\\harumi.hal",10 + 88,TRUE);
	for(cnt=0;cnt < 9;cnt++)
		pHarumi->AddPtr(cnt*87,0,cnt*87 + 87,117);

	//タイトル画面を作る
	pTitle = new MGLSprite;
	pTitle->LoadBmpFile("CharaData\\title_imanishi.hal",10 + 88 + 48,FALSE);
	pTitle->AddPtr(0,0,320,240);
	pTitle->AddPtr(0,0,320,1);

	//妖精を作る
	pFairy = new MGLSprite;
	pFairy->LoadBmpFile("CharaData\\yousei.hal",10 + 88 + 48 + 20,TRUE);
	for(cnt=0;cnt < 6;cnt++)
		pFairy->AddPtr(cnt*87,0,cnt*87 + 87,117);

	//敵を作る
	pEnemy = new MGLSprite;
	pEnemy->LoadBmpFile("CharaData\\imanishi.hal",10 + 88 + 48 + 20 + 32,TRUE);
	for(cnt=0;cnt < 3;cnt++)
		pEnemy->AddPtr(cnt*87,0,cnt*87 + 87,117);


	//WAVEを作る
	pUtsu = new MGLWave;
	pUtsu->LoadWave("Sound\\utsu.wav");

	//BGM関連
	if(CGame.IsUseMidiSound())
	{
		CGame.StopMidi();
		CGame.PlayMidi("Bgm\\stage5.mid");
	}

	//パレットをセット
	CGame.SetPalette("CharaData\\sinario_imanishi.hal",0,10,88);
	CGame.SetPalette("CharaData\\harumi.hal",0,10 + 88,48);
	CGame.SetPalette("CharaData\\title_imanishi.hal",0,10 + 88 + 48,20);
	CGame.SetPalette("CharaData\\yousei.hal",0,10 + 88 + 48 + 20,32);
	CGame.SetPalette("CharaData\\imanishi.hal",0,10 + 88 + 48 + 20 + 32,32);
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








