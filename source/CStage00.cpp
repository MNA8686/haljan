
#include "MGLInit.h"
#include "haljan.h"
#include "CStage00.h"

//	序章編　文章は35枚です

LONG lHarumiTbl00[] = {
-1,-1,-1,-1,6,
4,4,4,4,4,6,6,
6,4,6,4,2,2,2,
2,8,8,4,0,4,0,
0,6,6,4,0,0,6,
6,6
};

//	左側に表示する妖精です
LONG lFairyTbl00[] = {
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,2,2,3,0,3,3,5,0,1,0,2,2,0,1,0,1,1,0,2,2
};

//	追加しました　右側に表示する妖精です
LONG lFairyRightTbl00[] = {
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
};

//	追加しました	先生のデータです
LONG lTeacherTbl00[] = {
-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
};




BOOL CStage00 :: SetUp(LONG lParam)
{
	CGameParam::bLastBattle = FALSE;

	lSerihuCenter = 35;
	lSerihuMax = 35;
	CGameParam::lStage = 0;
	pHarumiTbl = lHarumiTbl00;
	pFairyTbl = lFairyTbl00;
	pFairyRightTbl = lFairyRightTbl00;
	pTeacherTbl = lTeacherTbl00;

	//背景を作る
	pBG = new MGLSprite;
	pBG->LoadBmpFile("CharaData\\sinario_boutou.hal",10,FALSE);
	for(int cnt=0;cnt < lSerihuMax;cnt++)
		pBG->AddPtr(0 + cnt*320,0,320 + cnt*320,240);

	//主人公を作る
	pHarumi = new MGLSprite;
	pHarumi->LoadBmpFile("CharaData\\harumi.hal",10 + 88,TRUE);
	for(cnt=0;cnt < 9;cnt++)
		pHarumi->AddPtr(cnt*87,0,cnt*87 + 87,117);

	//タイトル画面を作る
	pTitle = new MGLSprite;
//	pTitle->LoadBmpFile("CharaData\\title.hal",10 + 88 + 48,FALSE);
	pTitle->LoadBmpFile("CharaData\\title_boutou.hal",10 + 88 + 48,FALSE);
	pTitle->AddPtr(0,0,320,240);
	pTitle->AddPtr(0,0,320,1);

	//妖精を作る
	pFairy = new MGLSprite;
	pFairy->LoadBmpFile("CharaData\\yousei.hal",10 + 88 + 48 + 20,TRUE);
	for(cnt=0;cnt < 6;cnt++)
		pFairy->AddPtr(cnt*87,0,cnt*87 + 87,117);

	//敵を作る
	pEnemy = new MGLSprite;
	pEnemy->LoadBmpFile("CharaData\\masaru.hal",10 + 88 + 48 + 20 + 32,TRUE);
	pEnemy->AddPtr(0,0,87,117);


	//WAVEを作る
	pUtsu = new MGLWave;
	pUtsu->LoadWave("Sound\\utsu.wav");

	//パレットをセット
	CGame.SetPalette("CharaData\\sinario_boutou.hal",0,10,88);
	CGame.SetPalette("CharaData\\harumi.hal",0,10 + 88,48);
	CGame.SetPalette("CharaData\\title_boutou.hal",0,10 + 88 + 48,20);
	CGame.SetPalette("CharaData\\yousei.hal",0,10 + 88 + 48 + 20,32);
	CGame.SetPalette("CharaData\\masaru.hal",0,10 + 88 + 48 + 20 + 32,32);
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

	//BGM関連
	if(CGame.IsUseMidiSound())
	{
		CGame.StopMidi();
		CGame.PlayMidi("Bgm\\boutou.mid");
	}

	return TRUE;
}








