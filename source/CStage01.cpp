
#include "MGLInit.h"
#include "haljan.h"
#include "CStage01.h"

//	石田先生編　文章は35枚です

LONG lHarumiTbl01[] = {
4,0,4,0,4,0,2,8,4,-1,-1,7,7,6,-1,-1,4,4,6,6,2,2,4,4,6,6,6,6,0,2,4,4,6,6
};

//	左側に表示する妖精です
LONG lFairyTbl01[] = {
0,2,0,3,0,5,0,5,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,2,2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,4
};

//	追加しました　右側に表示する妖精です
LONG lFairyRightTbl01[] = {
-1,-1,-1,-1,-1,-1,-1,-1,-1,4,4,-1,-1,-1,3,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
};

//	追加しました	先生のデータです
LONG lTeacherTbl01[] = {
-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,1,1,0,0,0,-1,-1,-1,0,0,1,3,3,3,3,2,2,2,2,-1,-1
};

CStage01 :: CStage01(void)
{
	//初期化
	pBG = NULL;
	pHarumi = NULL;
	pFairy = NULL;
	pEnemy = NULL;

	pUtsu = NULL;
}


CStage01 :: ~CStage01(void)
{
	CleanUp();	
}


BOOL CStage01 :: SetUp(LONG lParam)
{
	lSerihuCenter = 28;
	lSerihuMax = 34;
	CGameParam::lStage = 1;
	pHarumiTbl = lHarumiTbl01;
	pFairyTbl = lFairyTbl01;
	pFairyRightTbl = lFairyRightTbl01;
	pTeacherTbl = lTeacherTbl01;

	//背景を作る
	pBG = new MGLSprite;
	pBG->LoadBmpFile("CharaData\\sinario_ishida.hal",10,FALSE);
	for(int cnt=0;cnt < lSerihuMax;cnt++)
		pBG->AddPtr(0 + cnt*320,0,320 + cnt*320,240);

	//主人公を作る
	pHarumi = new MGLSprite;
	pHarumi->LoadBmpFile("CharaData\\harumi.hal",10 + 88,TRUE);
	for(cnt=0;cnt < 9;cnt++)
		pHarumi->AddPtr(cnt*87,0,cnt*87 + 87,117);

	//タイトル画面を作る
	pTitle = new MGLSprite;
	pTitle->LoadBmpFile("CharaData\\title_ishida.hal",10 + 88 + 48,FALSE);
	pTitle->AddPtr(0,0,320,240);
	pTitle->AddPtr(0,0,320,1);

	//妖精を作る
	pFairy = new MGLSprite;
	pFairy->LoadBmpFile("CharaData\\yousei.hal",10 + 88 + 48 + 20,TRUE);
	for(cnt=0;cnt < 6;cnt++)
		pFairy->AddPtr(cnt*87,0,cnt*87 + 87,117);

	//敵を作る
	pEnemy = new MGLSprite;
	pEnemy->LoadBmpFile("CharaData\\ishida.hal",10 + 88 + 48 + 20 + 32,TRUE);
	for(cnt=0;cnt < 4;cnt++)
		pEnemy->AddPtr(cnt*87,0,cnt*87 + 87,117);


	//WAVEを作る
	pUtsu = new MGLWave;
	pUtsu->LoadWave("Sound\\utsu.wav");

	//BGM関連
	if(CGame.IsUseMidiSound())
	{
		CGame.StopMidi();
		CGame.PlayMidi("Bgm\\stage1.mid");
	}

	//パレットをセット
	CGame.SetPalette("CharaData\\sinario_ishida.hal",0,10,88);
	CGame.SetPalette("CharaData\\harumi.hal",0,10 + 88,48);
	CGame.SetPalette("CharaData\\title_ishida.hal",0,10 + 88 + 48,20);
	CGame.SetPalette("CharaData\\yousei.hal",0,10 + 88 + 48 + 20,32);
	CGame.SetPalette("CharaData\\ishida.hal",0,10 + 88 + 48 + 20 + 32,32);
	CGame.RealizePalette();

	if(!CGameParam :: bWin)
	{
		lSerihu = -1;
		lSection = 0;
	}
	else
	{
		lSection = 10;
		lSerihu = lSerihuCenter;
	}

	lCount = lCountMem = 0;

	return TRUE;
}


BOOL CStage01 :: Go(DWORD* dwKeyFlag)
{

	//エスケープで終了
	if((*dwKeyFlag & EXITGAME))
	{
		dwNextStage = CSTAGE_CLEANUP;
		return FALSE;
	}

	static LONG lKeyDownFlag = 0;

	switch(lSection)
	{
	case 0:

		if(*dwKeyFlag & PLAYER_RON ||
			*dwKeyFlag & PLAYER_PON)
			lCount += 2;

		if(lCount - lCountMem < 120)
			break;
		lSerihu = 0;
		lCountMem = lCount;
		lSection = 10;
		break;

	case 10:

		if(*dwKeyFlag & PLAYER_RON ||
			*dwKeyFlag & PLAYER_PON)
			lCount += 2;
		if(lCount - lCountMem < 40)
			break;

		lSection = 11;
		lCountMem = lCount;
		break;

	case 11:

		if(*dwKeyFlag & PLAYER_RON &&
			(lKeyDownFlag == 0 || lKeyDownFlag >= 40))
		{
			pUtsu->StopWave();
			pUtsu->PlayWave(FALSE);
		
			lSerihu ++;
			if(lSerihu >= lSerihuMax &&
				CGameParam :: bWin)
			{
				CGameParam :: bWin = FALSE;
				switch(CGameParam::lStage)
				{
				case 0:
					dwNextStage = CSTAGE_STAGE01;
					break;
				case 1:
					dwNextStage = CSTAGE_STAGE02;
					break;
				case 2:
					dwNextStage = CSTAGE_STAGE03;
					break;
				case 3:
					dwNextStage = CSTAGE_STAGE04;
					break;
				case 4:
					dwNextStage = CSTAGE_STAGE05;
					break;
				case 5:
					dwNextStage = CSTAGE_STAGE06;
					break;
				case 6:
					dwNextStage = CSTAGE_STAGE07;
					break;
				case 7:
					dwNextStage = CSTAGE_STAGE08;
					break;
				case 8:
					dwNextStage = CSTAGE_STAGE09;
					break;
				case 9:
					dwNextStage = CSTAGE_ENDING;
//					dwNextStage = CSTAGE_STAGE10;
					break;
				case 10:
					dwNextStage = CSTAGE_ENDING;
					break;
				}
				lSerihu --;
				lCountMem = lCount;
				lSection = 100;
				break;
			}
			if(lSerihu >= lSerihuCenter &&
				!CGameParam :: bWin)
			{
				CGameParam::lScorePlayer = 50;
				switch(CGameParam::lStage)
				{
				case 1:
					CGameParam::lScoreEnemy = 61;
					break;
				case 2:
					CGameParam::lScoreEnemy = 66;
					break;
				case 3:
					CGameParam::lScoreEnemy = 71;
					break;
				case 4:
					CGameParam::lScoreEnemy = 81;
					break;
				case 5:
					CGameParam::lScoreEnemy = 91;
					break;
				case 6:
					CGameParam::lScoreEnemy = 101;
					break;
				case 7:
					CGameParam::lScoreEnemy = 111;
					break;
				case 8:
					CGameParam::lScoreEnemy = 121;
					break;
				case 9:
					CGameParam::lScoreEnemy = 181;
					break;
				case 10:
					CGameParam::lScoreEnemy = 1;//333;
					break;
				}

				switch(CGameParam::lStage)
				{
				case 0:
					dwNextStage = CSTAGE_STAGE01;
					break;

				default:
					dwNextStage = CSTAGE_BATTLE;
				}
				lSerihu --;
				lCountMem = lCount;
				lSection = 100;
				break;
			}
		}
		break;

	case 100:

		if(*dwKeyFlag & PLAYER_RON ||
			*dwKeyFlag & PLAYER_PON)
			lCount += 2;
		if(lCount - lCountMem < 40)
			break;

		return FALSE;
	}

	if(*dwKeyFlag & PLAYER_RON)
		lKeyDownFlag ++;

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


BOOL CStage01 :: Draw(void)
{

	switch(lSection)
	{
	//タイトル表示
	case 0:

		if(lCount <= 1 || lCount >= 110)
		{
			int cnt;
			for(cnt=0;cnt < 240;cnt++)
				pTitle->Blt(0,cnt,1);
		}
		if(lCount <= 117)
			pTitle->StretchBlt(lCount*1 + 10,lCount*1 - 10,0,280 + (120 - lCount*2)*2 - 30,200 + (120 - lCount*2)*2);  
		break;

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
	
		for(cnt = 0;cnt < 240;cnt++)
		{
			if(cnt & 1)
				pTitle->Blt((lCount - lCountMem) * 8 - 320,cnt,1);
			else
				pTitle->Blt(-(lCount - lCountMem) * 8 + 320,cnt,1);
		}
		break;
	}

	if(lSerihu >= 0 && lSerihu < lSerihuMax)
	{
		if(pHarumiTbl[lSerihu] >= 0)
			pHarumi->Blt(182,40,pHarumiTbl[lSerihu]);
		if(pFairyRightTbl[lSerihu] >= 0)
			pFairy->Blt(182,40,pFairyRightTbl[lSerihu]);
		if(pFairyTbl[lSerihu] >= 0)
			pFairy->Blt(62,40,pFairyTbl[lSerihu]);
		if(pTeacherTbl[lSerihu] >= 0)
			pEnemy->Blt(62,40,pTeacherTbl[lSerihu]);
		pBG->Blt(0,0,lSerihu);
	}
	return TRUE;
}


BOOL CStage01 :: CleanUp(void)
{
	IDELETE(pBG);
	IDELETE(pHarumi);
	IDELETE(pFairy);
	IDELETE(pTitle);
	IDELETE(pEnemy);

	IDELETE(pUtsu);

	if(CGame.IsUseMidiSound())
		CGame.StopMidi();

	return TRUE;
}








