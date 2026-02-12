
#include "MGLInit.h"
#include "haljan.h"
#include "CEnding.h"



BOOL CEnding :: SetUp(LONG lParam)
{

	pEnd00 = new MGLSprite;
	pEnd00->LoadBmpFile("CharaData\\staff1.hal",10,FALSE);
	for(int cnt=0;cnt < 240;cnt++)
		pEnd00->AddPtr(0,cnt,320,cnt + 1);

	pEnd01 = new MGLSprite;
	pEnd01->LoadBmpFile("CharaData\\staff2.hal",10 + 32,FALSE);
	for(cnt=0;cnt < 240;cnt++)
		pEnd01->AddPtr(0,cnt,320,cnt + 1);

	pEnd02 = new MGLSprite;
	pEnd02->LoadBmpFile("CharaData\\staff3.hal",10 + 32 + 32,FALSE);
	for(cnt=0;cnt < 240;cnt++)
		pEnd02->AddPtr(0,cnt,320,cnt + 1);

	pEnd03 = new MGLSprite;
	pEnd03->LoadBmpFile("CharaData\\end.hal",10 + 32 + 32,FALSE);
	for(cnt=0;cnt < 240;cnt++)
		pEnd03->AddPtr(0,cnt,320,cnt + 1);

	//WAVEを作る
	pUtsu = new MGLWave;
	pUtsu->LoadWave("Sound\\utsu.wav");

	//パレットをセット
	CGame.SetPalette("CharaData\\staff1.hal",0,10,32);
	CGame.SetPalette("CharaData\\staff2.hal",0,10 + 32,32);
	CGame.SetPalette("CharaData\\staff3.hal",0,10 + 32 + 32,32);
	CGame.SetPalette("CharaData\\end.hal",0,10 + 32 + 32 + 32,32);
	CGame.RealizePalette();

	lSerihu = 0;
	lSection = 0;
	lCount = lCountMem = 0;

	//BGM関連
	if(CGame.IsUseMidiSound())
	{
		CGame.StopMidi();
		CGame.PlayMidi("Bgm\\staffroll.mid");
	}

	return TRUE;
}


BOOL CEnding :: Go(DWORD* dwKeyFlag)
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

		if(lCount - lCountMem < 20)
			break;

		lSection = 1;
		lCountMem = lCount;
		break;

	case 1:

		if(lCount - lCountMem < 60)
			break;

		lSection = 2;
		lCountMem = lCount;
		break;

	case 2:

		if(lCount - lCountMem < 20)
			break;

		lSection = 10;
		lCountMem = lCount;
		break;




	case 10:

		if(lCount - lCountMem < 20)
			break;

		lSection = 11;
		lCountMem = lCount;
		break;

	case 11:

		if(lCount - lCountMem < 60)
			break;

		lSection = 12;
		lCountMem = lCount;
		break;

	case 12:

		if(lCount - lCountMem < 20)
			break;

		lSection = 100;
		lCountMem = lCount;
		break;




	case 100:

		if(lCount - lCountMem < 20)
			break;

		lSection = 101;
		lCountMem = lCount;
		break;

	case 101:

		if(lCount - lCountMem < 60)
			break;

		lSection = 102;
		lCountMem = lCount;
		break;

	case 102:

		if(lCount - lCountMem < 20)
			break;

		lSection = 1000;
		lCountMem = lCount;
		break;

	case 1000:

		if(lCount - lCountMem < 20)
			break;

		lSection = 1001;
		lCountMem = lCount;
		break;

	case 1001:

		if(lCount - lCountMem < 40)
			break;

		lSection = 1002;
		lCountMem = lCount;
		break;

	case 1002:

		if(lCount - lCountMem < 20)
			break;

		lSection = 200;
		lCountMem = lCount;
		break;


/*	
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
*/
	case 200:

		if(lCount - lCountMem < 40)
			break;

		CGameParam :: bWin = FALSE;
		dwNextStage = CSTAGE_TITLE;
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


BOOL CEnding :: Draw(void)
{

	int cnt;
	switch(lSection)
	{
	//画面開く
	case 0:

		for(cnt = 0;cnt < 240;cnt++)
		{
			if(cnt & 1)
				pEnd00->Blt((lCount - lCountMem) * 16 - 320,cnt,cnt);
			else
				pEnd00->Blt(-(lCount - lCountMem) * 16 + 320,cnt,cnt);
		}
		break;
	
	//画面開く
	case 10:

		for(cnt = 0;cnt < 240;cnt++)
		{
			if(cnt & 1)
				pEnd01->Blt((lCount - lCountMem) * 16 - 320,cnt,cnt);
			else
				pEnd01->Blt(-(lCount - lCountMem) * 16 + 320,cnt,cnt);
		}
		break;

	//画面開く
	case 100:

		for(cnt = 0;cnt < 240;cnt++)
		{
			if(cnt & 1)
				pEnd02->Blt((lCount - lCountMem) * 16 - 320,cnt,cnt);
			else
				pEnd02->Blt(-(lCount - lCountMem) * 16 + 320,cnt,cnt);
		}
		break;
	//画面開く
	case 1000:

		for(cnt = 0;cnt < 240;cnt++)
		{
			if(cnt & 1)
				pEnd03->Blt((lCount - lCountMem) * 16 - 320,cnt,cnt);
			else
				pEnd03->Blt(-(lCount - lCountMem) * 16 + 320,cnt,cnt);
		}
		break;



	//ロゴ画面閉じる
	case 2:

		for(cnt = 0;cnt < 240;cnt++)
		{
			if(cnt & 1)
				pEnd00->Blt((lCount - lCountMem) * 16,cnt,cnt);
			else
				pEnd00->Blt(-(lCount - lCountMem) * 16,cnt,cnt);
		}
		break;

	//画面閉じる
	case 12:
	
		for(cnt = 0;cnt < 240;cnt++)
		{
			if(cnt & 1)
				pEnd01->Blt((lCount - lCountMem) * 16,cnt,cnt);
			else
				pEnd01->Blt(-(lCount - lCountMem) * 16,cnt,cnt);
		}
		break;

	//画面閉じる
	case 102:
	
		for(cnt = 0;cnt < 240;cnt++)
		{
			if(cnt & 1)
				pEnd02->Blt((lCount - lCountMem) * 16,cnt,cnt);
			else
				pEnd02->Blt(-(lCount - lCountMem) * 16,cnt,cnt);
		}
		break;

	//画面閉じる
	case 1002:
	
		for(cnt = 0;cnt < 240;cnt++)
		{
			if(cnt & 1)
				pEnd03->Blt((lCount - lCountMem) * 16,cnt,cnt);
			else
				pEnd03->Blt(-(lCount - lCountMem) * 16,cnt,cnt);
		}
		break;




	case 1:

		for(cnt = 0;cnt < 240;cnt++)
		{
			pEnd00->Blt(0,cnt,cnt);
		}
		break;

	case 11:

		for(cnt = 0;cnt < 240;cnt++)
		{
			pEnd01->Blt(0,cnt,cnt);
		}
		break;

	case 101:

		for(cnt = 0;cnt < 240;cnt++)
		{
			pEnd02->Blt(0,cnt,cnt);
		}
		break;

	case 1001:

		for(cnt = 0;cnt < 240;cnt++)
		{
			pEnd03->Blt(0,cnt,cnt);
		}
		break;

	}

	for(cnt = 0;cnt < 240;cnt++)
	{
		pEnd00->Blt(0,cnt,0);
	}

/*
	if(lSection >= 10)
	{
		pTitleLogo->Blt(0,0,0);

		static LONG lX = 0;
		static LONG lY = 0;

		for(int cnt=-1;cnt < 6;cnt ++)
		{
			pTitleBG->Blt(-287 + lX,lY + cnt*41,0);
			pTitleBG->Blt(0 + lX,lY + cnt*41,0);
			pTitleBG->Blt(287 + lX,lY + cnt*41,0);
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
*/
	return TRUE;
}


BOOL CEnding :: CleanUp(void)
{
	IDELETE(pUtsu);

	IDELETE(pEnd00);
	IDELETE(pEnd01);
	IDELETE(pEnd02);
	IDELETE(pEnd03);


	if(CGame.IsUseMidiSound())
		CGame.StopMidi();

	return TRUE;
}





