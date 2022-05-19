# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

!IF "$(CFG)" == ""
CFG=testcfile64 - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to testcfile64 - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "testcfile64 - Win32 Release" && "$(CFG)" !=\
 "testcfile64 - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "testcfile64.mak" CFG="testcfile64 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "testcfile64 - Win32 Release" (based on\
 "Win32 (x86) Console Application")
!MESSAGE "testcfile64 - Win32 Debug" (based on\
 "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "testcfile64 - Win32 Debug"
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "testcfile64 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\testcfile64.exe"

CLEAN : 
	-@erase "$(INTDIR)\cfile64.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\testcfile64.obj"
	-@erase "$(OUTDIR)\testcfile64.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /YX /c
# ADD CPP /nologo /MD /W4 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_AFXDLL" /D "_MBCS" /YX /c
CPP_PROJ=/nologo /MD /W4 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D\
 "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/testcfile64.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x1809 /d "NDEBUG"
# ADD RSC /l 0x1809 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/testcfile64.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 /nologo /subsystem:console /machine:I386
LINK32_FLAGS=/nologo /subsystem:console /incremental:no\
 /pdb:"$(OUTDIR)/testcfile64.pdb" /machine:I386 /out:"$(OUTDIR)/testcfile64.exe"\
 
LINK32_OBJS= \
	"$(INTDIR)\cfile64.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\testcfile64.obj"

"$(OUTDIR)\testcfile64.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "testcfile64 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "$(OUTDIR)\testcfile64.exe"

CLEAN : 
	-@erase "$(INTDIR)\cfile64.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\testcfile64.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\testcfile64.exe"
	-@erase "$(OUTDIR)\testcfile64.ilk"
	-@erase "$(OUTDIR)\testcfile64.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /YX /c
# ADD CPP /nologo /MDd /W4 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_AFXDLL" /D "_MBCS" /YX /c
CPP_PROJ=/nologo /MDd /W4 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE"\
 /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)/testcfile64.pch" /YX /Fo"$(INTDIR)/"\
 /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x1809 /d "_DEBUG"
# ADD RSC /l 0x1809 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/testcfile64.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386
# ADD LINK32 /nologo /subsystem:console /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:console /incremental:yes\
 /pdb:"$(OUTDIR)/testcfile64.pdb" /debug /machine:I386\
 /out:"$(OUTDIR)/testcfile64.exe" 
LINK32_OBJS= \
	"$(INTDIR)\cfile64.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\testcfile64.obj"

"$(OUTDIR)\testcfile64.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "testcfile64 - Win32 Release"
# Name "testcfile64 - Win32 Debug"

!IF  "$(CFG)" == "testcfile64 - Win32 Release"

!ELSEIF  "$(CFG)" == "testcfile64 - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\testcfile64.cpp
DEP_CPP_TESTC=\
	".\cfile64.h"\
	".\stdafx.h"\
	

"$(INTDIR)\testcfile64.obj" : $(SOURCE) $(DEP_CPP_TESTC) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\cfile64.cpp
DEP_CPP_CFILE=\
	".\cfile64.h"\
	".\stdafx.h"\
	

"$(INTDIR)\cfile64.obj" : $(SOURCE) $(DEP_CPP_CFILE) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\stdafx.h"\
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"


# End Source File
# End Target
# End Project
################################################################################
