# Microsoft Developer Studio Project File - Name="haljan" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** 編集しないでください **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=haljan - Win32 Debug
!MESSAGE これは有効なﾒｲｸﾌｧｲﾙではありません。 このﾌﾟﾛｼﾞｪｸﾄをﾋﾞﾙﾄﾞするためには NMAKE を使用してください。
!MESSAGE [ﾒｲｸﾌｧｲﾙのｴｸｽﾎﾟｰﾄ] ｺﾏﾝﾄﾞを使用して実行してください
!MESSAGE 
!MESSAGE NMAKE /f "haljan.mak".
!MESSAGE 
!MESSAGE NMAKE の実行時に構成を指定できます
!MESSAGE ｺﾏﾝﾄﾞ ﾗｲﾝ上でﾏｸﾛの設定を定義します。例:
!MESSAGE 
!MESSAGE NMAKE /f "haljan.mak" CFG="haljan - Win32 Debug"
!MESSAGE 
!MESSAGE 選択可能なﾋﾞﾙﾄﾞ ﾓｰﾄﾞ:
!MESSAGE 
!MESSAGE "haljan - Win32 Release" ("Win32 (x86) Application" 用)
!MESSAGE "haljan - Win32 Debug" ("Win32 (x86) Application" 用)
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "haljan - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "haljan___Win32_Release"
# PROP BASE Intermediate_Dir "haljan___Win32_Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "."
# PROP Intermediate_Dir "haljan___Win32_Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /Ox /Ot /Oa /Og /Oi /Op /Ob2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x411 /d "NDEBUG"
# ADD RSC /l 0x411 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386 /nodefaultlib:"msvcrt.lib" /nodefaultlib:"libcmt.lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "haljan - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "haljan___Win32_Debug"
# PROP BASE Intermediate_Dir "haljan___Win32_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "haljan___Win32_Debug"
# PROP Intermediate_Dir "haljan___Win32_Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x411 /d "_DEBUG"
# ADD RSC /l 0x411 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "haljan - Win32 Release"
# Name "haljan - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\source\CBattle.cpp
# End Source File
# Begin Source File

SOURCE=.\source\CContinue.cpp
# End Source File
# Begin Source File

SOURCE=.\source\CEnding.cpp
# End Source File
# Begin Source File

SOURCE=.\source\CStage.cpp
# End Source File
# Begin Source File

SOURCE=.\source\CStage00.cpp
# End Source File
# Begin Source File

SOURCE=.\source\CStage01.cpp
# End Source File
# Begin Source File

SOURCE=.\source\CStage02.cpp
# End Source File
# Begin Source File

SOURCE=.\source\CStage03.cpp
# End Source File
# Begin Source File

SOURCE=.\source\CStage04.cpp
# End Source File
# Begin Source File

SOURCE=.\source\CStage05.cpp
# End Source File
# Begin Source File

SOURCE=.\source\CStage06.cpp
# End Source File
# Begin Source File

SOURCE=.\source\CStage07.cpp
# End Source File
# Begin Source File

SOURCE=.\source\CStage08.cpp
# End Source File
# Begin Source File

SOURCE=.\source\CStage09.cpp
# End Source File
# Begin Source File

SOURCE=.\source\CStage10.cpp
# End Source File
# Begin Source File

SOURCE=.\source\CTitle.cpp
# End Source File
# Begin Source File

SOURCE=.\source\haljan.cpp
# End Source File
# Begin Source File

SOURCE=.\source\Main.cpp
# End Source File
# Begin Source File

SOURCE=.\Script2.rc
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\source\CBattle.h
# End Source File
# Begin Source File

SOURCE=.\source\CContinue.h
# End Source File
# Begin Source File

SOURCE=.\source\CEnding.h
# End Source File
# Begin Source File

SOURCE=.\source\CStage.h
# End Source File
# Begin Source File

SOURCE=.\source\CStage00.h
# End Source File
# Begin Source File

SOURCE=.\source\CStage01.h
# End Source File
# Begin Source File

SOURCE=.\source\CStage02.h
# End Source File
# Begin Source File

SOURCE=.\source\CStage03.h
# End Source File
# Begin Source File

SOURCE=.\source\CStage04.h
# End Source File
# Begin Source File

SOURCE=.\source\CStage05.h
# End Source File
# Begin Source File

SOURCE=.\source\CStage06.h
# End Source File
# Begin Source File

SOURCE=.\source\CStage07.h
# End Source File
# Begin Source File

SOURCE=.\source\CStage08.h
# End Source File
# Begin Source File

SOURCE=.\source\CStage09.h
# End Source File
# Begin Source File

SOURCE=.\source\CStage10.h
# End Source File
# Begin Source File

SOURCE=.\source\CTitle.h
# End Source File
# Begin Source File

SOURCE=.\source\haljan.h
# End Source File
# Begin Source File

SOURCE=.\source\Main.h
# End Source File
# Begin Source File

SOURCE=.\source\Define.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\haljan_vs.ico
# End Source File
# End Group
# End Target
# End Project
