
#include "MGLInit.h"
#include "Define.h"
#include "haljan.h"
#include "CStage.h"

BOOL CGameParam :: bWin = FALSE;
LONG CGameParam::lScorePlayer = 100;
LONG CGameParam::lScoreEnemy = 150;
LONG CGameParam::lStage = 0;
BOOL CGameParam::bLastBattle = FALSE;

CGameParam :: CGameParam(void)
{
	bUseWaveSound = TRUE;	//WAVEを再生するか
	bUseMidiSound = TRUE;	//MIDIをセットするか    

	pMidi = NULL;
}


CGameParam :: ~CGameParam(void)
{
	CleanUp();
}


VOID CGameParam :: Initialize(void)
{
	MGLMath::Initialize();	//数学系の関数初期化

	//Windowを作る
	pWindow = new MGLWindow;
	pWindow->InitWindow("HAL-JAN",640,480);

	//描画クラスの初期化  
	MglDraw = new MGLDraw; 
//	MglDraw->UseFlip(TRUE);
 	MglDraw->Initialize(pWindow->GetHwnd(),8,FULLSCREENMODE,320,240);
// 	MglDraw->Initialize(pWindow->GetHwnd(),8,WINDOWMODE,320,240);
//	MglDraw->SetPalette("CharaData\\taku.hal",0,10,11);
	MglDraw->RealizePalette(); 
//	MglDraw->SetPaintArea(0,0,224,240);
  	MglDraw->SetPaintArea(0,0,320*1,240*1);
          
	//入力系クラスの初期化
	MglInput = new MGLInput;  
	MglInput->Initialize(pWindow->GetHwnd(),Mgl.GethInst());

	MglSound = new MGLSound;
	MglSound->Initialize(pWindow->GetHwnd());
	MglSound->CreatePrimaryBuffer(1,11025,1,8);

	Wait.SetFps(60);	//FPSをセット
}


VOID CGameParam :: CleanUp(void)
{
	IDELETE(MglDraw);
	IDELETE(MglInput);
	IDELETE(MglSound);
	IDELETE(pWindow);
}


//パレットをセットする
BOOL CGameParam :: SetPalette(LPSTR szBitmap,INT rPalIndex,INT PalIndex,INT NumOfPal)
{
	return MglDraw->SetPalette(szBitmap,rPalIndex,PalIndex,NumOfPal);
}


//パレットを実体化する
BOOL CGameParam :: RealizePalette(void)
{
	return MglDraw->RealizePalette();
}


//現在認識されているジョイスティックの名前を取得する
LPSTR CGameParam :: GetJoystickProduct(LONG lNum)
{
	return MglInput->GetJoystickProduct(lNum);
}


//WAVEの使用の可否をセット
VOID CGameParam :: UseWaveSound(BOOL bUse)
{
	bUseWaveSound = bUse;
}


//WAVEを使うか？
BOOL CGameParam :: IsUseWaveSound(void)
{
	return bUseWaveSound;
}


//MIDIの使用の可否をセット
VOID CGameParam :: UseMidiSound(BOOL bUse)
{
	bUseMidiSound = bUse;
}


//MIDIを使うか？
BOOL CGameParam :: IsUseMidiSound(void)
{
	return bUseMidiSound;
}


BOOL CGameParam :: Main(void)
{

	//ゲームを進行させる
	if(!CStage::Main(IsKeyDown()))
	{
		return FALSE;
	}

	//Draw開始
	if(MglDraw->BeginDraw())
	{ 
		CStage::pStage->Draw();	//バックバッファに描画
		MglDraw->EndDraw();	//Draw終わり
	}

	Wait.UpDateTime();	//時間を更新

	//時間が余っていたらSleep
	DWORD dwRemainderTime = Wait.GetRemainderTime();
  
 	Wait.EraseTime();	//余った時間を潰す

	MglDraw->BltScreen();	//プライマリへ転送
	Wait.CountFps();	//FPSを測る

#if defined(HALJAN_DEBUG)
	static BOOL bShowDebug = TRUE;
	if(GetAsyncKeyState(VK_F5) & 0x80000000)
	{
		bShowDebug ^= 0x00000001;
	}

	//デバッグメッセージを表示する？
	if(bShowDebug)
	{
		//FPSを表示
		char str[256];
		sprintf(str,"F%3d/60 ",Wait.GetNowFps()+1);
		MGL::ShowText(pWindow->GetHwnd(),str,0,0);

		//マシンの余力を表示
		DWORD P = (dwRemainderTime*100)/16;
		P = 100 - P;
		sprintf(str,"T%3d",dwRemainderTime);
		MGL::ShowText(pWindow->GetHwnd(),str,0,18);
	}
#endif

	return TRUE;
}


//どのキーが押されているかを全て管理
DWORD* CGameParam :: IsKeyDown(void)
{
	//1P側のキーを調べる
	{
/*
		MglInput->dijs.lX = 0;
		MglInput->dijs.lY = 0;
		MglInput->dijs.rgbButtons[0] = 0;
		MglInput->dijs.rgbButtons[1] = 0;
*/
		//キーバッファから情報を取り出す
		MglInput->GetKeyBoardStat();
		MglInput->GetJoyStickStat(0);
		
		dwKeyBitFlag = 0;
	}

	{
		if(MglInput->IsKeyDown(MGLKEY_1))
		{
			dwKeyBitFlag |= PLAYER_1;
		}
		if(MglInput->IsKeyDown(MGLKEY_2))
		{
			dwKeyBitFlag |= PLAYER_2;
		}
		if(MglInput->IsKeyDown(MGLKEY_3))
		{
			dwKeyBitFlag |= PLAYER_3;
		}
		if(MglInput->IsKeyDown(MGLKEY_4))
		{
			dwKeyBitFlag |= PLAYER_4;
		}
		if(MglInput->IsKeyDown(MGLKEY_5))
		{
			dwKeyBitFlag |= PLAYER_5;
		}
		if(MglInput->IsKeyDown(MGLKEY_6))
		{
			dwKeyBitFlag |= PLAYER_6;
		}
		if(MglInput->IsKeyDown(MGLKEY_7))
		{
			dwKeyBitFlag |= PLAYER_7;
		}
		if(MglInput->IsKeyDown(MGLKEY_8))
		{
			dwKeyBitFlag |= PLAYER_8;
		}
		if(MglInput->IsKeyDown(MGLKEY_9))
		{
			dwKeyBitFlag |= PLAYER_9;
		}
		if(MglInput->IsKeyDown(MGLKEY_RETURN))
		{
			dwKeyBitFlag |= PLAYER_RON;
		}
		if(MglInput->IsKeyDown(MGLKEY_SPACE))
		{
			dwKeyBitFlag |= PLAYER_PON;
		}


		//F8で捨てゲー
		if(MglInput->IsKeyDown(MGLKEY_F8))
		{
			dwKeyBitFlag |= FAILEDGAME;
		}
		if(MglInput->IsKeyDown(MGLKEY_ESCAPE))
		{
			dwKeyBitFlag |= EXITGAME;
		}
	}
	return &dwKeyBitFlag;
}


VOID CGameParam :: SetFps(DWORD dwFps)
{
	Wait.SetFps(dwFps);
}


VOID CGameParam :: PlayMidi(LPSTR lpFileName)
{
	if(pMidi == NULL)
		pMidi = new MGLMidi;
	pMidi->Initialize(pWindow->GetHwnd(),lpFileName);
	pMidi->Play();
}


VOID CGameParam :: StopMidi(void)
{
	if(pMidi != NULL)
	{ 
		pMidi->Stop();
		pMidi->CleanUp();
//		delete pMidi;
//		pMidi = NULL;
	}
}


VOID CGameParam :: FadeOutPalette(LONG lNum,LONG lVal)
{
	MglDraw->FadeOutPalette(lNum,lVal);
}



