# Microsoft Developer Studio Generated NMAKE File, Based on rswusers.dsp
!IF "$(CFG)" == ""
CFG=rswusers - Win32 Debug
!MESSAGE No configuration specified. Defaulting to rswusers - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "rswusers - Win32 Release" && "$(CFG)" != "rswusers - Win32 Debug" && "$(CFG)" != "rswusers - Win32 Release with Asserts"
!MESSAGE Invalid configuration "$(CFG)" specified.
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
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "rswusers - Win32 Release"

OUTDIR=.\WinRel
INTDIR=.\WinRel
# Begin Custom Macros
OutDir=.\WinRel
# End Custom Macros

ALL : "$(OUTDIR)\rswusers.exe"


CLEAN :
	-@erase "$(INTDIR)\crypto.obj"
	-@erase "$(INTDIR)\rrusers.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\WRRDAT.OBJ"
	-@erase "$(INTDIR)\wusers.obj"
	-@erase "$(OUTDIR)\rswusers.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /Zp1 /ML /W3 /Gm /GX /Zi /Ot /Og /Ob1 /I "\rrw7\h" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "INTERACTIVE" /D "_MBCS" /D "RSW" /Fp"$(INTDIR)\rswusers.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /J /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\rrusers.res" /i "\rrw7\resource" /i "\rrw7\h" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\rswusers.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=oldnames.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /stack:0x10240 /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\rswusers.pdb" /machine:IX86 /def:".\rswusers.DEF" /out:"$(OUTDIR)\rswusers.exe" 
DEF_FILE= \
	".\rswusers.DEF"
LINK32_OBJS= \
	"$(INTDIR)\crypto.obj" \
	"$(INTDIR)\WRRDAT.OBJ" \
	"$(INTDIR)\wusers.obj" \
	"$(INTDIR)\rrusers.res"

"$(OUTDIR)\rswusers.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "rswusers - Win32 Debug"

OUTDIR=.\WinDebug
INTDIR=.\WinDebug
# Begin Custom Macros
OutDir=.\WinDebug
# End Custom Macros

ALL : "$(OUTDIR)\rswusers.exe" "$(OUTDIR)\rswusers.bsc"


CLEAN :
	-@erase "$(INTDIR)\crypto.obj"
	-@erase "$(INTDIR)\crypto.sbr"
	-@erase "$(INTDIR)\rrusers.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\WRRDAT.OBJ"
	-@erase "$(INTDIR)\WRRDAT.SBR"
	-@erase "$(INTDIR)\wusers.obj"
	-@erase "$(INTDIR)\wusers.sbr"
	-@erase "$(OUTDIR)\rswusers.bsc"
	-@erase "$(OUTDIR)\rswusers.exe"
	-@erase "$(OUTDIR)\rswusers.ilk"
	-@erase "$(OUTDIR)\rswusers.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /Zp1 /MLd /W3 /Gm /GX /ZI /Od /I "\rrw7\h" /D "_DEBUG" /D "RSW" /D "WIN32" /D "_WINDOWS" /D "INTERACTIVE" /D "_MBCS" /Fr"$(INTDIR)\\" /Fp"$(INTDIR)\rswusers.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /J /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\rrusers.res" /i "\rrw7\resource" /i "\rrw7\h" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\rswusers.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\crypto.sbr" \
	"$(INTDIR)\WRRDAT.SBR" \
	"$(INTDIR)\wusers.sbr"

"$(OUTDIR)\rswusers.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=oldnames.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\rswusers.pdb" /debug /machine:IX86 /def:".\rswusers.DEF" /out:"$(OUTDIR)\rswusers.exe" 
DEF_FILE= \
	".\rswusers.DEF"
LINK32_OBJS= \
	"$(INTDIR)\crypto.obj" \
	"$(INTDIR)\WRRDAT.OBJ" \
	"$(INTDIR)\wusers.obj" \
	"$(INTDIR)\rrusers.res"

"$(OUTDIR)\rswusers.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "rswusers - Win32 Release with Asserts"

OUTDIR=.\WinRel
INTDIR=.\WinRel
# Begin Custom Macros
OutDir=.\WinRel
# End Custom Macros

ALL : "$(OUTDIR)\rswusers.exe"


CLEAN :
	-@erase "$(INTDIR)\crypto.obj"
	-@erase "$(INTDIR)\rrusers.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\WRRDAT.OBJ"
	-@erase "$(INTDIR)\wusers.obj"
	-@erase "$(OUTDIR)\rswusers.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /Zp1 /ML /W3 /Gm /GX /Zi /Ot /Og /Ob1 /I "\rrw7\h" /D "_RRDEBUG" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "INTERACTIVE" /D "_MBCS" /D "RSW" /Fp"$(INTDIR)\rswusers.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /J /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\rrusers.res" /i "\rrw7\resource" /i "\rrw7\h" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\rswusers.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=oldnames.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /stack:0x10240 /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\rswusers.pdb" /machine:IX86 /def:".\rswusers.DEF" /out:"$(OUTDIR)\rswusers.exe" 
DEF_FILE= \
	".\rswusers.DEF"
LINK32_OBJS= \
	"$(INTDIR)\crypto.obj" \
	"$(INTDIR)\WRRDAT.OBJ" \
	"$(INTDIR)\wusers.obj" \
	"$(INTDIR)\rrusers.res"

"$(OUTDIR)\rswusers.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("rswusers.dep")
!INCLUDE "rswusers.dep"
!ELSE 
!MESSAGE Warning: cannot find "rswusers.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "rswusers - Win32 Release" || "$(CFG)" == "rswusers - Win32 Debug" || "$(CFG)" == "rswusers - Win32 Release with Asserts"
SOURCE=..\crypto.cpp

!IF  "$(CFG)" == "rswusers - Win32 Release"


"$(INTDIR)\crypto.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "rswusers - Win32 Debug"


"$(INTDIR)\crypto.obj"	"$(INTDIR)\crypto.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "rswusers - Win32 Release with Asserts"


"$(INTDIR)\crypto.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\rrusers.RC

!IF  "$(CFG)" == "rswusers - Win32 Release"


"$(INTDIR)\rrusers.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\rrusers.res" /i "\rrw7\resource" /i "\rrw7\h" /i "\rrw7\USERS" /d "NDEBUG" $(SOURCE)


!ELSEIF  "$(CFG)" == "rswusers - Win32 Debug"


"$(INTDIR)\rrusers.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\rrusers.res" /i "\rrw7\resource" /i "\rrw7\h" /i "\rrw7\USERS" /d "_DEBUG" $(SOURCE)


!ELSEIF  "$(CFG)" == "rswusers - Win32 Release with Asserts"


"$(INTDIR)\rrusers.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\rrusers.res" /i "\rrw7\resource" /i "\rrw7\h" /i "\rrw7\USERS" /d "NDEBUG" $(SOURCE)


!ENDIF 

SOURCE=\rrw7\SETUP\WRRDAT.CPP

!IF  "$(CFG)" == "rswusers - Win32 Release"


"$(INTDIR)\WRRDAT.OBJ" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "rswusers - Win32 Debug"


"$(INTDIR)\WRRDAT.OBJ"	"$(INTDIR)\WRRDAT.SBR" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "rswusers - Win32 Release with Asserts"


"$(INTDIR)\WRRDAT.OBJ" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\wusers.cpp

!IF  "$(CFG)" == "rswusers - Win32 Release"


"$(INTDIR)\wusers.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "rswusers - Win32 Debug"


"$(INTDIR)\wusers.obj"	"$(INTDIR)\wusers.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "rswusers - Win32 Release with Asserts"


"$(INTDIR)\wusers.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 


!ENDIF 

