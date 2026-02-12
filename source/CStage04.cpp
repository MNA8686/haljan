
#include "MGLInit.h"
#include "haljan.h"
#include "CStage04.h"

//	原秀先生編　文章は21枚です

LONG lHarumiTbl04[] = {
4,0,0,0,4,4,6,6,4,0,8,8,7,3,3,-1,-1,6,0,4,4
};

//	左側に表示する妖精です
LONG lFairyTbl04[] = {
0,1,0,1,-1,2,2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4
};

//	追加しました　右側に表示する妖精です
LONG lFairyRightTbl04[] = {
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,2,2,-1,-1,-1,-1
};

//	追加しました	先生のデータです
LONG lTeacherTbl04[] = {
-1,-1,-1,-1,0,-1,-1,0,0,2,1,2,2,2,2,2,0,0,0,0,-1
};



BOOL CStage04 :: SetUp(LONG lParam)
{
	lSerihuCenter = 13;
	lSerihuMax = 21;
	CGameParam::lStage = 4;
	pHarumiTbl = lHarumiTbl04;
	pFairyTbl = lFairyTbl04;
	pFairyRightTbl = lFairyRightTbl04;
	pTeacherTbl = lTeacherTbl04;

	//背景を作る
	pBG = new MGLSprite;
	pBG->LoadBmpFile("CharaData\\sinario_harahide.hal",10,FALSE);
	for(int cnt=0;cnt < lSerihuMax;cnt++)
		pBG->AddPtr(0 + cnt*320,0,320 + cnt*320,240);

	//主人公を作る
	pHarumi = new MGLSprite;
	pHarumi->LoadBmpFile("CharaData\\harumi.hal",10 + 88,TRUE);
	for(cnt=0;cnt < 9;cnt++)
		pHarumi->AddPtr(cnt*87,0,cnt*87 + 87,117);

	//タイトル画面を作る
	pTitle = new MGLSprite;
	pTitle->LoadBmpFile("CharaData\\title_harahide.hal",10 + 88 + 48,FALSE);
	pTitle->AddPtr(0,0,320,240);
	pTitle->AddPtr(0,0,320,1);

	//妖精を作る
	pFairy = new MGLSprite;
	pFairy->LoadBmpFile("CharaData\\yousei.hal",10 + 88 + 48 + 20,TRUE);
	for(cnt=0;cnt < 6;cnt++)
		pFairy->AddPtr(cnt*87,0,cnt*87 + 87,117);

	//敵を作る
	pEnemy = new MGLSprite;
	pEnemy->LoadBmpFile("CharaData\\harahide.hal",10 + 88 + 48 + 20 + 32,TRUE);
	for(cnt=0;cnt < 3;cnt++)
		pEnemy->AddPtr(cnt*87,0,cnt*87 + 87,117);


	//WAVEを作る
	pUtsu = new MGLWave;
	pUtsu->LoadWave("Sound\\utsu.wav");

	//パレットをセット
	CGame.SetPalette("CharaData\\sinario_harahide.hal",0,10,88);
	CGame.SetPalette("CharaData\\harumi.hal",0,10 + 88,48);
	CGame.SetPalette("CharaData\\title_harahide.hal",0,10 + 88 + 48,20);
	CGame.SetPalette("CharaData\\yousei.hal",0,10 + 88 + 48 + 20,32);
	CGame.SetPalette("CharaData\\harahide.hal",0,10 + 88 + 48 + 20 + 32,32);
	CGame.RealizePalette();

	if(!CGameParam :: bWin)
	{
		lSection = 0;
		lSerihu = -1;
	}
	else
	{
		lSection = 10;
		lSerihu = lSerihuCenter;
	}
	lCount = lCountMem = 0;
	//BGM関連
	if(CGame.IsUseMidiSound())
	{
		CGame.StopMidi();
		CGame.PlayMidi("Bgm\\stage4.mid");
	}
	return TRUE;
}








