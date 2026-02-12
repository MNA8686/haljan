
#ifndef __CENDING__
#define __CENDING__

#include "CStage.h"
#include "CStage01.h"

class CStage;
class CEnding : public CStage01
{
protected:

	MGLSprite* pEnd00;
	MGLSprite* pEnd01;
	MGLSprite* pEnd02;
	MGLSprite* pEnd03;

public:

	BOOL SetUp(LONG lParam);
	BOOL Go(DWORD* dwKeyFlag);
	BOOL Draw(void);
	BOOL CleanUp(void);
};

#endif