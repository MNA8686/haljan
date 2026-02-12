
#ifndef __CSTAGE00__
#define __CSTAGE00__

#include "CStage.h"
#include "CStage01.h"
//#include "CStage04.h"


class CStage;
class CStage00 : public CStage01
{
public:

	BOOL SetUp(LONG lParam);
};

#endif