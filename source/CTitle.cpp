
#include "MGLInit.h"
#include "haljan.h"
#include "CTitle.h"



BOOL CTitle :: SetUp(LONG lParam)
{

	//背景を作る
	pBG = new MGLSprite;
	pBG->LoadBmpFile("CharaData\\continue.hal",10,FALSE);
	for(int cnt=0;cnt < 9;cnt++)
		pBG->AddPtr(0 + cnt*320,0,320 + cnt*320,240);

	//タイトル画面を作る
	pTitle = new MGLSprite;
	pTitle->LoadBmpFile("CharaData\\title_boutou.hal",10 + 88,FALSE);
	pTitle->AddPtr(0,0,320,240);
	pTitle->AddPtr(0,0,320,1);

	pTitleLogo = new MGLSprite;
	pTitleLogo->LoadBmpFile("CharaData\\title01.hal",10 + 88 + 20,TRUE);
	pTitleLogo->AddPtr(0,0,320,240);

	pTitleBG = new MGLSprite;
	pTitleBG->LoadBmpFile("CharaData\\title02.hal",10 + 88 + 20 + 32,FALSE);
	pTitleBG->AddPtr(0,0,287,41);

	pLogo = new MGLSprite;
	pLogo->LoadBmpFile("CharaData\\srogo.hal",10 + 88 + 20 + 32 + 16,FALSE);
	pLogo->AddPtr(0,0,320,240);
	pLogo->AddPtr(320,0,640,240);
	for(cnt=0;cnt < 240;cnt ++)
		pLogo->AddPtr(320,cnt,640,cnt+1);

	//WAVEを作る
	pUtsu = new MGLWave;
	pUtsu->LoadWave("Sound\\utsu.wav");

	//パレットをセット
	CGame.SetPalette("CharaData\\continue.hal",0,10,88);
	CGame.SetPalette("CharaData\\title_boutou.hal",0,10 + 88,20);
	CGame.SetPalette("CharaData\\title01.hal",0,10 + 88 + 20,32);
	CGame.SetPalette("CharaData\\title02.hal",0,10 + 88 + 20 + 32,16);
	CGame.SetPalette("CharaData\\srogo.hal",0,10 + 88 + 20 + 32 + 16,16);
	CGame.RealizePalette();

	lSerihu = 0;
	lSection = 0;
	lCount = lCountMem = 0;

	//BGM関連
	if(CGame.IsUseMidiSound())
	{
		CGame.StopMidi();
		CGame.PlayMidi("Bgm\\title.mid");
	}

	return TRUE;
}


BOOL CTitle :: Go(DWORD* dwKeyFlag)
{

	//エスケープで終了
	if((*dwKeyFlag & EXITGAME))
	{
		dwNextStage = CSTAGE_CLEANUP;
		return FALSE;
	}

	if((*dwKeyFlag & PLAYER_RON ||
		*dwKeyFlag & PLAYER_PON) &&
		lSection < 100)
		lCount += 2;

	static LONG lKeyDownFlag = 1;

	switch(lSection)
	{
	case 0:

		if(lCount - lCountMem < 80)
			break;

		lSection = 1;
		lCountMem = lCount;
		break;

	case 1:

		if(lCount - lCountMem < 90)
			break;

		lSection = 2;
		lCountMem = lCount;
		break;

	case 2:

		if(lCount - lCountMem < 70)
			break;

		lSection = 10;
		lCountMem = lCount;
		break;
	
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
			dwNextStage = CSTAGE_STAGE00;
			lSection = 100;
			lCountMem = lCount;
		}
		break;

	case 100:

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


BOOL CTitle :: Draw(void)
{

	int cnt;
	switch(lSection)
	{
	//ロゴ画面開く
	case 0:

		for(cnt = 0;cnt < 240;cnt++)
		{
			if(cnt & 1)
				pLogo->Blt((lCount - lCountMem) * 4 - 320,cnt,cnt + 2);
			else
				pLogo->Blt(-(lCount - lCountMem) * 4 + 320,cnt,cnt + 2);
		}
		break;
	
	//画面開く
	case 10:

		for(cnt = 0;cnt < 240;cnt++)
		{
			if(cnt & 1)
				pTitle->Blt((lCount - lCountMem) * 8,cnt,1);
			else
				pTitle->Blt(-(lCount - lCountMem) * 8,cnt,1);
		}
		break;

	//ロゴ画面閉じる
	case 2:

		for(cnt = 0;cnt < 240;cnt++)
		{
			if(cnt & 1)
				pLogo->Blt((lCount - lCountMem) * 8,cnt,cnt + 2);
			else
				pLogo->Blt(-(lCount - lCountMem) * 8,cnt,cnt + 2);
		}
		break;

	//画面閉じる
	case 100:
	
		for(cnt = 0;cnt < 240;cnt++)
		{
			if(cnt & 1)
				pTitle->Blt((lCount - lCountMem) * 8 - 320,cnt,1);
			else
				pTitle->Blt(-(lCount - lCountMem) * 8 + 320,cnt,1);
		}
		break;
	}

	if(lSection >= 10)
	{
		pTitleLogo->Blt(0,0,0);

		static LONG lX = 0;
		static LONG lY = 0;

//		for(int cnt=-1;cnt < 6;cnt ++)
		for(int cnt=-1;cnt < 12;cnt ++)
		{
			pTitleBG->Blt(-287 + lX,lY + cnt*41,0);
			pTitleBG->Blt(0 + lX,lY + cnt*41,0);
			pTitleBG->Blt(287 + lX,lY + cnt*41,0);
			pTitleBG->Blt(287*2 + lX,lY + cnt*41,0);
		}
		lX ++;
		if(lX >= 287)
			lX = 0;
		lY ++;
		if(lY >= 41)
			lY = 0;
	}
	else
	{
		if(lSection > 0 && lSection < 2)
		{
			pLogo->Blt(0,0,1);
		}
		else
		{
			for(cnt = 0;cnt < 240;cnt++)
				pTitle->Blt(0,cnt,1);
		}
	}

	return TRUE;
}


BOOL CTitle :: CleanUp(void)
{
	IDELETE(pBG);
	IDELETE(pHarumi);
	IDELETE(pFairy);
	IDELETE(pTitle);
	IDELETE(pEnemy);

	IDELETE(pUtsu);

	IDELETE(pTitleLogo);
	IDELETE(pTitleBG);
	IDELETE(pLogo);

	if(CGame.IsUseMidiSound())
		CGame.StopMidi();

	return TRUE;
}





