
#ifndef __CBATTLE__
#define __CBATTLE__

#include "CStage.h"

//0:プレイヤー
//1:敵

#define _PLAYER_	0
#define _ENEMY_		1


class CStage;
class CBattle : public CStage
{

protected:
	
	typedef struct
	{
		LONG lKind;
		LONG lStat;
	}PAI;

	MGLSprite* pBG;
	MGLSprite* pPai;
	MGLSprite* pSuuji;
	MGLSprite* pRonMsg;
	MGLSprite* pReach;

	MGLSprite* pHarumi;
	MGLSprite* pHissatsu;
	MGLSprite* pHissatsuSetsumei;
	MGLSprite* pEnemy;
	MGLSprite* pIcon;

	MGLSprite* pKokuban;
	MGLSprite* pTokuten;
	MGLSprite* pYaku;
	MGLSprite* pKaisen;

	MGLWave* pTsumo;
	MGLWave* pSute;
	MGLWave* pVictory;
	MGLWave* pLose;
	MGLWave* pPon;
	MGLWave* pGetScore;

	MGLWave* pAgariVoice;
	MGLWave* pWinVoice;
	MGLWave* pAgarareVoice;
	MGLWave* pLoseVoice;
	MGLWave* pHissatsuVoice;

	PAI PaiPlayer[9];
	PAI PaiEnemy[9];
	PAI PaiYama[81];

	//あがりの判定用
	PAI PaiTemp[9];

	//捨て牌リスト
	PAI SutePaiPlayer[18 + 1];
	PAI SutePaiEnemy[18 + 1];
	//何枚捨てられているか
	LONG lSutePaiNum[2];	
//	LONG lSutePaiEnemyNum;

	LONG lYamaIndex;	//山の中の何枚目か

	LONG lHaipaiFlag[9];	//すでに9枚でているかどうかを調べるフラグ
	LONG lAgariPai;

	LONG lPhase;	//自分の番か、敵の番か
	LONG lNextPhase;
	LONG lNum;
	LONG lWaitTime;
	BOOL bAllowRon[2];
	BOOL bRyukyoku;

	LONG lAgariNumPlayer;
	LONG lAgariNumEnemy;
	LONG lLoop;

	BOOL bRonOK;
	BOOL bTsumoOK;
	BOOL bPonOK;
	BOOL bReachOK;
	BOOL bNextTsumoOK;

	LONG lHaiPaiNum[2];	//何個配った?

	//ないた回数
	LONG lPonNum[2];
	//テンパイしてる?
	BOOL bTempai[2];
	//リーチしてる?
	BOOL bReach[2];
	//一発判定用
	LONG lReachIppatsu[2];
	//ツモ？
	BOOL bTsumo[2];
	//役満？
	BOOL bYakuman[2];
	//上がった?
	BOOL bAgari;
	//木曽用
	LONG lOdoshi;

	//必殺技有効?
	BOOL bHissatsu[2];

	//点数表に表示されるスコア
	LONG lShowScore;

	LONG lAgaruKakuritsu;
	LONG lReachKakuritsu;
	LONG lTekagen;

	//今何回戦?
	static LONG lKaisen;
	LONG lWinLose;

public:

	CBattle(void);
	~CBattle(void);
	BOOL SetUp(LONG lParam);
	BOOL Go(DWORD* dwKeyFlag);
	BOOL Draw(void);
	BOOL CleanUp(void);

	VOID SortPai(PAI* pPai);
//	VOID SortPaiEnemy(void);
	VOID SortPaiTemp(void);
	LONG AgariCheck(void);
	LONG IsTempai(void);
};

#endif