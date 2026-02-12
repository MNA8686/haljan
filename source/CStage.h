/*-------------------------------------------------------------------------
	ステージ用の基底クラス
--------------------------------------------------------------------------*/

#ifndef __CSTAGE__
#define __CSTAGE__

#include "Define.h"
//#include "CJiki.h"

#define CSTAGE_CLEANUP		0
#define CSTAGE_TITLE		1
#define CSTAGE_BATTLE		100
#define CSTAGE_CONTINUE		200
#define CSTAGE_STAGE00		1000
#define CSTAGE_STAGE01		1100
#define CSTAGE_STAGE02		1200
#define CSTAGE_STAGE03		1300
#define CSTAGE_STAGE04		1400
#define CSTAGE_STAGE05		1500
#define CSTAGE_STAGE06		1600
#define CSTAGE_STAGE07		1700
#define CSTAGE_STAGE08		1800
#define CSTAGE_STAGE09		1900
#define CSTAGE_STAGE10		2000
#define CSTAGE_ENDING		9999


#define CSTAGE_END			99


class CStage
{

protected:

	static VOID SceneSelect(void);
	static DWORD dwNextStage;
	//共通スプライト関連
	static MGLSprite* pFont;

	LONG lCount;	//内部カウンタ
	LONG lCountMem;	//内部カウンタ保持用

	LONG lStageSituation;	//ステージの状態（どの場面か？）
	LONG lSection;	//ステージのメイン部分での区切り

public:

	CStage(void);
	virtual BOOL SetUp(LONG lParam);
	virtual BOOL Go(DWORD* dwKeyFlag);
	virtual BOOL Draw(void);
	virtual BOOL CleanUp(void);

	static BOOL Main(DWORD* dwKeyFlag);
	static CStage* pStage;	//各ステージのポインタを入れる
	static VOID ShowText(LPSTR lpStr,LONG lX,LONG lY);
	static VOID ShowText(LPSTR lpStr,LONG lX,LONG lY,LONG lNum);

};


#endif