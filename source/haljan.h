
#ifndef __HALJAN__
#define __HALJAN__

#ifndef HALJAN_DEBUG
#define HALJAN_DEBUG
#endif



class CGameParam
{
public:

	CGameParam(void);
	~CGameParam(void);
	VOID Initialize(void);
	VOID CleanUp(void);

	//ゲームシステム関連
	BOOL Main(void);	//ゲームのメインルーチン
	DWORD* IsKeyDown(void);	//キーの管理メソッド
	BOOL SetPalette(LPSTR szBitmap,INT rPalIndex,INT PalIndex,INT NumOfPal);
	BOOL RealizePalette(void);
	LPSTR GetJoystickProduct(LONG lNum);

	VOID UseWaveSound(BOOL bUse);
	BOOL IsUseWaveSound(void);
	VOID UseMidiSound(BOOL bUse);
	BOOL IsUseMidiSound(void);

	MGLMidi* pMidi;
	BOOL bPresent;	//プレゼン用の特別モード

	VOID SetFps(DWORD dwFps);
	VOID PlayMidi(LPSTR lpFileName);
	VOID StopMidi(void);
	VOID FadeOutPalette(LONG lNum,LONG lVal);

	static BOOL bWin;
	static LONG lScorePlayer;
	static LONG lScoreEnemy;
	static LONG lStage;
	static BOOL bLastBattle;

protected:

	MGLWindow* pWindow;
	MGLDraw *MglDraw;
	MGLInput *MglInput;
	MGLSound *MglSound;
	MglWait Wait;
	DWORD dwKeyBitFlag;	//どのキーが押されたかを格納

	BOOL bUseWaveSound;	//WAVEを再生するか
	BOOL bUseMidiSound;	//MIDIを再生するか

};

extern CGameParam CGame;

#endif


