
#ifndef __CTITLE__
#define __CTITLE__

#include "CStage.h"
#include "CStage01.h"

class CStage;
class CTitle : public CStage01
{
protected:

	MGLSprite* pLogo;
	MGLSprite* pTitleLogo;
	MGLSprite* pTitleBG;

public:

	BOOL SetUp(LONG lParam);
	BOOL Go(DWORD* dwKeyFlag);
	BOOL Draw(void);
	BOOL CleanUp(void);
};

#endif