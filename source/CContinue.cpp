
#include "MGLInit.h"
#include "haljan.h"
#include "CContinue.h"



BOOL CContinue :: SetUp(LONG lParam)
{
	//背景を作る
	pBG = new MGLSprite;
	pBG->LoadBmpFile("CharaData\\continue.hal",10,FALSE);
	for(int cnt=0;cnt < 9;cnt++)
		pBG->AddPtr(0 + cnt*320,0,320 + cnt*320,240);

	//主人公を作る
	pHarumi = new MGLSprite;
	pHarumi->LoadBmpFile("CharaData\\harumi.hal",10 + 88,TRUE);
	for(cnt=0;cnt < 9;cnt++)
		pHarumi->AddPtr(cnt*87,0,cnt*87 + 87,117);

	//タイトル画面を作る
	pTitle = new MGLSprite;
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

	//背景を作る
	pEnd = new MGLSprite;
	pEnd->LoadBmpFile("CharaData\\end.hal",10 + 88 + 48 + 20 + 32 + 32,FALSE);
	pEnd->AddPtr(0,0,320,240);

	//WAVEを作る
	pUtsu = new MGLWave;
	pUtsu->LoadWave("Sound\\utsu.wav");

	//パレットをセット
	CGame.SetPalette("CharaData\\continue.hal",0,10,88);
	CGame.SetPalette("CharaData\\harumi.hal",0,10 + 88,48);
	CGame.SetPalette("CharaData\\title_boutou.hal",0,10 + 88 + 48,20);
	CGame.SetPalette("CharaData\\yousei.hal",0,10 + 88 + 48 + 20,32);
	CGame.SetPalette("CharaData\\masaru.hal",0,10 + 88 + 48 + 20 + 32,32);
	CGame.SetPalette("CharaData\\end.hal",0,10 + 88 + 48 + 20 + 32 + 32,2);
	CGame.RealizePalette();

//	if(!CGameParam :: bWin)
	{
		lSerihu = 0;
		lSection = 10;
	}
/*	else
	{
		lSerihu = lSerihuCenter;
		lSection = 10;
	}
*/
	lCount = lCountMem = 0;

	//BGM関連
	if(CGame.IsUseMidiSound())
	{
		CGame.StopMidi();
		CGame.PlayMidi("Bgm\\continue.mid");
	}

	return TRUE;
}


BOOL CContinue :: Go(DWORD* dwKeyFlag)
{

	//エスケープで終了
	if((*dwKeyFlag & EXITGAME))
	{
		dwNextStage = CSTAGE_CLEANUP;
		return FALSE;
	}

	static LONG lKeyDownFlag = 1;

	switch(lSection)
	{
	case 10:

		if(lCount - lCountMem < 40)
			break;

		lSection = 11;
		lCountMem = lCount;
		break;

	case 11:

		if((*dwKeyFlag & PLAYER_RON ||
			*dwKeyFlag & PLAYER_PON) &&
			lKeyDownFlag == 0)
		{
			pUtsu->StopWave();
			pUtsu->PlayWave(FALSE);
		
			CGameParam :: bWin = FALSE;
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
				dwNextStage = CSTAGE_STAGE09;
				break;
			case 10:
				dwNextStage = CSTAGE_STAGE10;
				break;
			}
			if(*dwKeyFlag & PLAYER_PON)
				lSection = 110;
			else
				lSection = 100;
			lCountMem = lCount;
		}
		break;

	case 100:

		if(lCount - lCountMem < 40)
			break;

		return FALSE;

	case 110:

		if(lCount - lCountMem < 120)
			break;

		lSection = 120;
		lCountMem = lCount;
		dwNextStage = CSTAGE_TITLE;
		break;

	case 120:

		if(lCount - lCountMem < 40)
			break;

		return FALSE;
	}

	if(*dwKeyFlag & PLAYER_RON ||
		*dwKeyFlag & PLAYER_PON)
		lKeyDownFlag = 1;

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
		lKeyDownFlag = 0;
	}

	lCount ++;
 	return TRUE;

}


BOOL CContinue :: Draw(void)
{

	switch(lSection)
	{
	//画面開く
	case 10:

		int cnt;
		for(cnt = 0;cnt < 240;cnt++)
		{
			if(cnt & 1)
				pTitle->Blt((lCount - lCountMem) * 8,cnt,1);
			else
				pTitle->Blt(-(lCount - lCountMem) * 8,cnt,1);
		}
		break;

	//画面閉じる
	case 100:
	case 120:
	
		for(cnt = 0;cnt < 240;cnt++)
		{
			if(cnt & 1)
				pTitle->Blt((lCount - lCountMem) * 8 - 320,cnt,1);
			else
				pTitle->Blt(-(lCount - lCountMem) * 8 + 320,cnt,1);
		}
		break;

//	case 120:


//		break;
	}

	if(lSection >= 110)
	{
		pEnd->Blt(0,0,0);
	}
	else
	{
		pHarumi->Blt(182,40,1);
		pFairy->Blt(62,40,5);
		pBG->Blt(0,0,CGameParam::lStage - 1);
	}
	return TRUE;
}


BOOL CContinue :: CleanUp(void)
{
	IDELETE(pBG);
	IDELETE(pHarumi);
	IDELETE(pFairy);
	IDELETE(pTitle);
	IDELETE(pEnemy);

	IDELETE(pUtsu);

	IDELETE(pEnd);

	if(CGame.IsUseMidiSound())
		CGame.StopMidi();

	return TRUE;
}







