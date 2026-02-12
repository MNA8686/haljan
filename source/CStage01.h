
#ifndef __CSTAGE01__
#define __CSTAGE01__

#include "CStage.h"


class CStage;
class CStage01 : public CStage
{

protected:
	
	MGLSprite* pBG;
	MGLSprite* pHarumi;
	MGLSprite* pFairy;
	MGLSprite* pEnemy;
	MGLSprite* pTitle;
	
	MGLWave* pUtsu;
	LONG lSerihu;

	LONG lSerihuMax;
	LONG lSerihuCenter;
	LONG* pHarumiTbl;
	LONG* pFairyTbl;
	LONG* pFairyRightTbl;
	LONG* pTeacherTbl;

public:

	CStage01(void);
	~CStage01(void);
	virtual BOOL SetUp(LONG lParam);
	virtual BOOL Go(DWORD* dwKeyFlag);
	virtual BOOL Draw(void);
	virtual BOOL CleanUp(void);

};

#endif