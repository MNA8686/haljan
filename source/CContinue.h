
#ifndef __CCONTINUE__
#define __CCONTINUE__

#include "CStage.h"
#include "CStage01.h"

class CStage;
class CContinue : public CStage01
{
protected:

	MGLSprite* pEnd;

public:

	BOOL SetUp(LONG lParam);
	BOOL Go(DWORD* dwKeyFlag);
	BOOL Draw(void);
	BOOL CleanUp(void);
};

#endif