
#include "MGLInit.h"

#include "haljan.h"
#include "CStage.h"

#include "CStage00.h"
#include "CStage01.h"
#include "CStage02.h"
#include "CStage03.h"
#include "CStage04.h"
#include "CStage05.h"
#include "CStage06.h"
#include "CStage07.h"
#include "CStage08.h"
#include "CStage09.h"
#include "CStage10.h"
#include "CTitle.h"
#include "CContinue.h"
#include "CEnding.h"
#include "CBattle.h"

CStage* CStage :: pStage = NULL;
DWORD CStage :: dwNextStage = CSTAGE_TITLE;//99;
MGLSprite* CStage :: pFont = NULL;


CStage :: CStage(void)
{
	if(pFont == NULL)
	{
/*		pFont = new MGLSprite;
		pFont->LoadBmpFile("CharaData\\taku.hal",10,TRUE);
		int cnt;
		for(cnt=0;cnt<10;cnt++)
			pFont->AddPtr(858+cnt*8,0,858+cnt*8+8,0+8);
		for(cnt=0;cnt<26;cnt++)
			pFont->AddPtr(858+cnt*8,16,858+cnt*8+8,16+8);
		for(cnt=0;cnt<26;cnt++)
			pFont->AddPtr(858+cnt*8,16+8,858+cnt*8+8,16+8+8);

		pFont->AddPtr(858+4*8,32,858+4*8+8,32+8);
		pFont->AddPtr(858+12*8,32,858+12*8+8,32+8);

		pFont->AddPtr(858,8,858+8,8+8);
*/	}

	if(CGame.IsUseWaveSound())
	{
		;
	}

	lCount = 0;	//内部カウンタを初期化
	lCountMem = 0;
}


BOOL CStage :: SetUp(LONG lParam)
{
	return TRUE;
}


BOOL CStage :: Go(DWORD* dwKeyFlag)
{
	//これが呼ばれたということは終了
	return FALSE;
}


BOOL CStage :: Draw(void)
{
	return TRUE;
}


BOOL CStage :: CleanUp(void)
{
	IDELETE(pFont);

	return TRUE;
}

VOID CStage :: SceneSelect(void)
{
	//シーンが定義されていなければ
	if(pStage == NULL)
	{
		//次のシーンで分岐
		switch(dwNextStage)
		{
		case CSTAGE_CLEANUP:

			pStage = new CStage;
			pStage->CleanUp();
			return;
		
		case CSTAGE_TITLE:

			pStage = new CTitle;
			break;

		case CSTAGE_CONTINUE:

			pStage = new CContinue;
			break;

		case CSTAGE_ENDING:

			pStage = new CEnding;
			break;

		case CSTAGE_BATTLE:

			pStage = new CBattle;
			break;

		case CSTAGE_STAGE00:
			//オープニング
			pStage = new CStage00;
			break;

		case CSTAGE_STAGE01:
			//ステージ1
			pStage = new CStage01;
			break;

		case CSTAGE_STAGE02:
			//ステージ2
			pStage = new CStage02;
			break;

		case CSTAGE_STAGE03:
			//ステージ3
			pStage = new CStage03;
			break;

		case CSTAGE_STAGE04:
			//ステージ4
			pStage = new CStage04;
			break;

		case CSTAGE_STAGE05:
			//ステージ5
			pStage = new CStage05;
			break;

		case CSTAGE_STAGE06:
			//ステージ6
			pStage = new CStage06;
			break;

		case CSTAGE_STAGE07:
			//ステージ7
			pStage = new CStage07;
			break;

		case CSTAGE_STAGE08:
			//ステージ8
			pStage = new CStage08;
			break;

		case CSTAGE_STAGE09:
			//ステージ9
			pStage = new CStage09;
			break;


/*
		case CSTAGE_TITLE:
			//タイトル画面
			pStage = new CTitle;
			break;
		case CSTAGE_STAGE01:
			//ステージ1
			pStage = new CStage01;
			break;
		case CSTAGE_STAGE02:
			//ステージ2
			pStage = new CStage02;
			break;
		case CSTAGE_JIKISELECT:
			//機体セレクト
			pStage = new CJikiSelect;
			break;
		case CSTAGE_GAMEOVER:
			//ゲームオーバー
			pStage = new CGameOver;
			break;
*/		}
		//そのシーンの初期化を行なう
		pStage->SetUp(NULL);
		return;
	}
}


BOOL CStage :: Main(DWORD* dwKeyFlag)
{
	//次のシーンが0なら終了
	if(dwNextStage == CSTAGE_CLEANUP)	return FALSE;

	SceneSelect();	//シーンを選択

	//シーンのメイン処理へ
	if(!pStage->Go(dwKeyFlag))
	{
		//シーンが終了したら
		pStage->CleanUp();
		IDELETE(pStage);
		SceneSelect();	//シーンを選択
	}
	return TRUE;
}


VOID CStage :: ShowText(LPSTR str,LONG lX,LONG lY)
{
	ShowText(str,lX,lY,256);
}


//文字を表示する（文字数指定）
VOID CStage :: ShowText(LPSTR str,LONG lX,LONG lY,LONG lNum)
{
	for(int charcnt = 0;str[charcnt] != '\0' && charcnt < lNum;charcnt ++)
	{

		//数字かどうか
		if(str[charcnt] >= '0' && str[charcnt] <= '9')
			pFont->Blt(lX+charcnt*8,lY,str[charcnt]-'0');
		//大文字アルファベットかどうか
		else if(str[charcnt] >= 'A' && str[charcnt] <= 'Z')
			pFont->Blt(lX+charcnt*8,lY,str[charcnt]-'A'+10);
		else if(str[charcnt] >= 'a' && str[charcnt] <= 'z')
			pFont->Blt(lX+charcnt*8,lY,str[charcnt]-'a'+10);
		else if(str[charcnt] == '.')
			pFont->Blt(lX+charcnt*8,lY,10+26+26);
		else if(str[charcnt] == ',')
			pFont->Blt(lX+charcnt*8,lY,10+26+26+1);

	}

}



