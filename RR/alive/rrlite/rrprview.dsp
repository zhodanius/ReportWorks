# Microsoft Developer Studio Project File - Name="rrprview" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=rrprview - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "rrprview.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "rrprview.mak" CFG="rrprview - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "rrprview - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "rrprview - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "rrprview - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\Release"
# PROP BASE Intermediate_Dir ".\Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".\Release"
# PROP Intermediate_Dir ".\Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /Zp1 /MT /W3 /GX /O1 /I "\rr\alive\rrlite\framewrk\include" /I "\rr\h" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Fr /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /I "\rr\alive\rrlite\framewrk\include" /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 CtlFwR32.Lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib urlmon.lib wininet.lib comctl32.lib /nologo /subsystem:windows /dll /machine:I386 /nodefaultlib:"libc.lib" /nodefaultlib:"msvcrt.lib" /nodefaultlib:"libcd.lib" /nodefaultlib:"libcmtd.lib" /nodefaultlib:"msvcrtd.lib" /out:".\Release\rrprview.ocx"
# SUBTRACT LINK32 /pdb:none
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Desc=Make a cabinet file
PostBuild_Cmds=buildcab.bat
# End Special Build Tool

!ELSEIF  "$(CFG)" == "rrprview - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\Debug"
# PROP BASE Intermediate_Dir ".\Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".\Debug"
# PROP Intermediate_Dir ".\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /Zp1 /MTd /W3 /Gm /GX /ZI /Od /I "\rr\alive\rrlite\framewrk\include" /I "\rr\h" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fr /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /I "\rr\alive\rrlite\framewrk\include" /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 CtlFwD32.Lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib urlmon.lib wininet.lib comctl32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /nodefaultlib:"libc.lib" /nodefaultlib:"libcmt.lib" /nodefaultlib:"msvcrt.lib" /nodefaultlib:"libcd.lib" /nodefaultlib:"msvcrtd.lib" /out:".\Debug\rrprview.ocx" /nodefaultlib:libc.lib, /nodefaultlib:libcmt.lib, /nodefaultlib:msvcrt.lib,
# SUBTRACT LINK32 /pdb:none /nodefaultlib

!ENDIF 

# Begin Target

# Name "rrprview - Win32 Release"
# Name "rrprview - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat;for;f90"
# Begin Source File

SOURCE=.\accusoft.cpp
# End Source File
# Begin Source File

SOURCE=.\Cathelp.cpp
# End Source File
# Begin Source File

SOURCE=.\CONTAIN.CPP
# End Source File
# Begin Source File

SOURCE=.\DISPPROP.CPP
# End Source File
# Begin Source File

SOURCE=.\drawctrl.cpp
# End Source File
# Begin Source File

SOURCE=.\fileread.cpp
# End Source File
# Begin Source File

SOURCE=.\Guids.cpp
# End Source File
# Begin Source File

SOURCE=.\IMGPATH.CPP
# End Source File
# Begin Source File

SOURCE=.\pagetip.cpp
# End Source File
# Begin Source File

SOURCE=.\printrep.cpp
# End Source File
# Begin Source File

SOURCE=.\READCHRT.CPP
# End Source File
# Begin Source File

SOURCE=.\readimg.cpp
# End Source File
# Begin Source File

SOURCE=.\READOBJ.CPP
# End Source File
# Begin Source File

SOURCE=.\Readv2.cpp
# End Source File
# Begin Source File

SOURCE=.\reppage.cpp
# End Source File
# Begin Source File

SOURCE=.\repurl.cpp
# End Source File
# Begin Source File

SOURCE=.\Rrprfile.cpp
# End Source File
# Begin Source File

SOURCE=.\rrprview.cpp
# End Source File
# Begin Source File

SOURCE=.\rrprview.def
# End Source File
# Begin Source File

SOURCE=.\rrprview.odl
# End Source File
# Begin Source File

SOURCE=.\rrprview.rc
# End Source File
# Begin Source File

SOURCE=.\rrutil.cpp
# End Source File
# Begin Source File

SOURCE=.\rrvwctrl.cpp
# End Source File
# Begin Source File

SOURCE=.\viewbox.cpp
# End Source File
# Begin Source File

SOURCE=.\VIEWCHRT.CPP
# End Source File
# Begin Source File

SOURCE=.\viewimg.cpp
# End Source File
# Begin Source File

SOURCE=.\viewlbox.cpp
# End Source File
# Begin Source File

SOURCE=.\viewline.cpp
# End Source File
# Begin Source File

SOURCE=.\VIEWOBJ.CPP
# End Source File
# Begin Source File

SOURCE=.\viewrep.cpp
# End Source File
# Begin Source File

SOURCE=.\viewtext.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=.\ACCUSOFT.H
# End Source File
# Begin Source File

SOURCE=.\Cathelp.h
# End Source File
# Begin Source File

SOURCE=.\CONTAIN.H
# End Source File
# Begin Source File

SOURCE=.\Dispids.h
# End Source File
# Begin Source File

SOURCE=.\fileread.h
# End Source File
# Begin Source File

SOURCE=.\IMGLIB.H
# End Source File
# Begin Source File

SOURCE=.\Localobj.h
# End Source File
# Begin Source File

SOURCE=.\reppage.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\rrlangid.h
# End Source File
# Begin Source File

SOURCE=.\rrutil.h
# End Source File
# Begin Source File

SOURCE=.\rrvwctrl.h
# End Source File
# Begin Source File

SOURCE=.\viewchrt.h
# End Source File
# Begin Source File

SOURCE=.\Viewimg.h
# End Source File
# Begin Source File

SOURCE=.\Viewlbox.h
# End Source File
# Begin Source File

SOURCE=.\viewobj.h
# End Source File
# Begin Source File

SOURCE=.\Viewrep.h
# End Source File
# Begin Source File

SOURCE=.\Viewtext.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\arplogo.bmp
# End Source File
# Begin Source File

SOURCE=.\RrvwCtrl.bmp
# End Source File
# Begin Source File

SOURCE=..\..\RESOURCE\rsw.ico
# End Source File
# Begin Source File

SOURCE=..\..\RESOURCE\rswbig.bmp
# End Source File
# Begin Source File

SOURCE=..\..\rrocx\rsw\rswbig.bmp
# End Source File
# Begin Source File

SOURCE=.\toolbar.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\rrprview.tlb
# End Source File
# End Target
# End Project
