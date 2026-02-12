
#define INITGUID
#include "MGLInit.h"
#include "Define.h"
#include "haljan.h"
#include "Main.h"

CGameParam CGame;

	 
void MGLMain(void)
{

	CGame.bPresent = FALSE;
	CGame.Initialize();
 
	StartGameLoop()
	{
		if(!CGame.Main())
		{
			CGame.CleanUp();
			return;
		}

		EndGameLoop();
	}

}


