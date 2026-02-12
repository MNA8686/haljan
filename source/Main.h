#pragma comment(lib,"MGL.lib")


#define StartGameLoop() \
\
	while(TRUE)\
	{\
		if(PeekMessage(Mgl.GetMessage(),0,0,0,PM_REMOVE))\
		{\
			if((Mgl.GetMessage())->message == WM_QUIT)\
			{\
				break;\
			}\
\
			TranslateMessage(Mgl.GetMessage());\
			DispatchMessage(Mgl.GetMessage());\
		}\
		{\
			if(!Mgl.PAUSE)\
\


#define EndGameLoop() \
\
			}\
			else\
			{\
				SleepEx(100,TRUE);\
			}\
\
		}\
\




