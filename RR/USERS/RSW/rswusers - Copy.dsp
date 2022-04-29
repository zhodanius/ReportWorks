# Microsoft Developer Studio Project File - Name="rswusers" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=rswusers - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "rswusers.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "rswusers.mak" CFG="rswusers - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "rswusers - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "rswusers - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "rswusers - Win32 Release with Asserts" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "rswusers - Win32 Release"

# PROP BASE Use_MFC 1
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WinRel"
# PROP BASE Intermediate_Dir "WinRel"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WinRel"
# PROP Intermediate_Dir "WinRel"
# PROP Ignore_Export_Lib 0
# ADD BASE CPP /nologo /Zp1 /MT /W3 /GX /Zi /Ot /Og /Ob1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "INTERACTIVE" /D "_MBCS" /FR /YX /J /c
# ADD CPP /nologo /Zp1 /W3 /Gm /GX /Zi /Ot /Og /Ob1 /I "\rrw7\h" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "INTERACTIVE" /D "_MBCS" /D "RSW" /YX /J /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /i "\rr\resource" /i "\rr\h" /d "NDEBUG" /d "RSW"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 oldnames.lib /nologo /stack:0x10240 /subsystem:windows /map /machine:IX86
# ADD LINK32 oldnames.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /stack:0x10240 /subsystem:windows /machine:IX86
# SUBTRACT LINK32 /map /nodefaultlib

!ELSEIF  "$(CFG)" == "rswusers - Win32 Debug"

# PROP BASE Use_MFC 1
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WinDebug"
# PROP BASE Intermediate_Dir "WinDebug"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WinDebug"
# PROP Intermediate_Dir "WinDebug"
# PROP Ignore_Export_Lib 0
# ADD BASE CPP /nologo /Zp1 /MT /W3 /GX /Zi /Od /Gf /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "INTERACTIVE" /D "_MBCS" /FR /YX /J /c
# ADD CPP /nologo /Zp1 /W3 /Gm /GX /ZI /Od /I "\rrw7\h" /D "_DEBUG" /D "RSW" /D "WIN32" /D "_WINDOWS" /D "INTERACTIVE" /D "_MBCS" /Fr /YX /J /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /i "\rrw7\resource" /i "\rrw7\h" /d "_DEBUG" /d "RSW"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 oldnames.lib /nologo /subsystem:windows /debug /machine:IX86
# ADD LINK32 oldnames.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:IX86

!ELSEIF  "$(CFG)" == "rswusers - Win32 Release with Asserts"

# PROP BASE Use_MFC 1
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Win32_Re"
# PROP BASE Intermediate_Dir "Win32_Re"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WinRel"
# PROP Intermediate_Dir "WinRel"
# PROP Ignore_Export_Lib 0
# ADD BASE CPP /nologo /Zp1 /MT /W3 /GX /Zi /Ot /Og /Ob1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "INTERACTIVE" /D "_MBCS" /FR /YX /J /c
# ADD CPP /nologo /Zp1 /W3 /Gm /GX /Zi /Ot /Og /Ob1 /I "\rrw7\h" /D "_RRDEBUG" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "INTERACTIVE" /D "_MBCS" /D "RSW" /YX /J /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /i "\rrw7\resource" /i "\rrw7\h" /d "NDEBUG" /d "RSW"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 oldnames.lib /nologo /stack:0x10240 /subsystem:windows /map /machine:IX86 /nodefaultlib /out:"WinRel/Rrwusers.exe"
# ADD LINK32 oldnames.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /stack:0x10240 /subsystem:windows /machine:IX86
# SUBTRACT LINK32 /map /nodefaultlib

!ENDIF 

# Begin Target

# Name "rswusers - Win32 Release"
# Name "rswusers - Win32 Debug"
# Name "rswusers - Win32 Release with Asserts"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Source File

SOURCE=..\crypto.cpp

!IF  "$(CFG)" == "rswusers - Win32 Release"

# ADD CPP /I "\rr\h"
# SUBTRACT CPP /I "\rrw7\h"

!ELSEIF  "$(CFG)" == "rswusers - Win32 Debug"

!ELSEIF  "$(CFG)" == "rswusers - Win32 Release with Asserts"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\rrusers.RC
# End Source File
# Begin Source File

SOURCE=.\rswusers.DEF
# End Source File
# Begin Source File

SOURCE=\rrw7\SETUP\WRRDAT.CPP

!IF  "$(CFG)" == "rswusers - Win32 Release"

# ADD CPP /I "\rr\h"
# SUBTRACT CPP /I "\rrw7\h"

!ELSEIF  "$(CFG)" == "rswusers - Win32 Debug"

!ELSEIF  "$(CFG)" == "rswusers - Win32 Release with Asserts"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\wusers.cpp

!IF  "$(CFG)" == "rswusers - Win32 Release"

# ADD CPP /I "\rr\h"
# SUBTRACT CPP /I "\rrw7\h"

!ELSEIF  "$(CFG)" == "rswusers - Win32 Debug"

!ELSEIF  "$(CFG)" == "rswusers - Win32 Release with Asserts"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=.\resource.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=..\rrusers.ico
# End Source File
# Begin Source File

SOURCE=.\rswusers.ICO
# End Source File
# End Group
# End Target
# End Project
