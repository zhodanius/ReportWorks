# Microsoft Developer Studio Generated NMAKE File, Based on rrusers.dsp
!IF "$(CFG)" == ""
CFG=rrusers - Win32 Debug
!MESSAGE No configuration specified. Defaulting to rrusers - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "rrusers - Win32 Release" && "$(CFG)" != "rrusers - Win32 Debug" && "$(CFG)" != "rrusers - Win32 Release with Asserts"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "rrusers.mak" CFG="rrusers - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "rrusers - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "rrusers - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "rrusers - Win32 Release with Asserts" (based on "Win32 (x86) Application")
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

!IF  "$(CFG)" == "rrusers - Win32 Release"

OUTDIR=.\WinRel
INTDIR=.\WinRel
# Begin Custom Macros
OutDir=.\WinRel
# End Custom Macros

ALL : "$(OUTDIR)\Rrwusers.exe"


CLEAN :
	-@erase "$(INTDIR)\CRYPTO.OBJ"
	-@erase "$(INTDIR)\RRUSERS.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\WRRDAT.OBJ"
	-@erase "$(INTDIR)\WUSERS.OBJ"
	-@erase "$(OUTDIR)\Rrwusers.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /Zp1 /ML /W3 /Gm /GX /Zi /Ot /Og /Ob1 /I "\rrw7\h" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "INTERACTIVE" /D "_MBCS" /Fp"$(INTDIR)\rrusers.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /J /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\RRUSERS.res" /i "\rrw7\resource" /i "\rrw7\h" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\rrusers.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=oldnames.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /stack:0x10240 /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\Rrwusers.pdb" /machine:IX86 /def:".\RRUSERS.DEF" /out:"$(OUTDIR)\Rrwusers.exe" 
DEF_FILE= \
	".\RRUSERS.DEF"
LINK32_OBJS= \
	"$(INTDIR)\CRYPTO.OBJ" \
	"$(INTDIR)\WRRDAT.OBJ" \
	"$(INTDIR)\WUSERS.OBJ" \
	"$(INTDIR)\RRUSERS.res"

"$(OUTDIR)\Rrwusers.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "rrusers - Win32 Debug"

OUTDIR=.\WinDebug
INTDIR=.\WinDebug
# Begin Custom Macros
OutDir=.\WinDebug
# End Custom Macros

ALL : "$(OUTDIR)\Rrwusers.exe" "$(OUTDIR)\rrusers.bsc"


CLEAN :
	-@erase "$(INTDIR)\CRYPTO.OBJ"
	-@erase "$(INTDIR)\CRYPTO.SBR"
	-@erase "$(INTDIR)\RRUSERS.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\WRRDAT.OBJ"
	-@erase "$(INTDIR)\WRRDAT.SBR"
	-@erase "$(INTDIR)\WUSERS.OBJ"
	-@erase "$(INTDIR)\WUSERS.SBR"
	-@erase "$(OUTDIR)\rrusers.bsc"
	-@erase "$(OUTDIR)\Rrwusers.exe"
	-@erase "$(OUTDIR)\Rrwusers.ilk"
	-@erase "$(OUTDIR)\Rrwusers.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /Zp1 /MLd /W3 /Gm /GX /ZI /Od /I "\rrw7\h" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "INTERACTIVE" /D "_MBCS" /Fr"$(INTDIR)\\" /Fp"$(INTDIR)\rrusers.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /J /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\RRUSERS.res" /i "\rrw7\resource" /i "\rrw7\h" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\rrusers.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\CRYPTO.SBR" \
	"$(INTDIR)\WRRDAT.SBR" \
	"$(INTDIR)\WUSERS.SBR"

"$(OUTDIR)\rrusers.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=oldnames.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\Rrwusers.pdb" /debug /machine:IX86 /def:".\RRUSERS.DEF" /out:"$(OUTDIR)\Rrwusers.exe" 
DEF_FILE= \
	".\RRUSERS.DEF"
LINK32_OBJS= \
	"$(INTDIR)\CRYPTO.OBJ" \
	"$(INTDIR)\WRRDAT.OBJ" \
	"$(INTDIR)\WUSERS.OBJ" \
	"$(INTDIR)\RRUSERS.res"

"$(OUTDIR)\Rrwusers.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "rrusers - Win32 Release with Asserts"

OUTDIR=.\WinRel
INTDIR=.\WinRel
# Begin Custom Macros
OutDir=.\WinRel
# End Custom Macros

ALL : "$(OUTDIR)\Rrwusers.exe"


CLEAN :
	-@erase "$(INTDIR)\CRYPTO.OBJ"
	-@erase "$(INTDIR)\RRUSERS.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\WRRDAT.OBJ"
	-@erase "$(INTDIR)\WUSERS.OBJ"
	-@erase "$(OUTDIR)\Rrwusers.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /Zp1 /ML /W3 /Gm /GX /Zi /Ot /Og /Ob1 /I "\rrw7\h" /D "_RRDEBUG" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "INTERACTIVE" /D "_MBCS" /Fp"$(INTDIR)\rrusers.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /J /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\RRUSERS.res" /i "\rrw7\resource" /i "\rrw7\h" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\rrusers.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=oldnames.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /stack:0x10240 /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\Rrwusers.pdb" /machine:IX86 /def:".\RRUSERS.DEF" /out:"$(OUTDIR)\Rrwusers.exe" 
DEF_FILE= \
	".\RRUSERS.DEF"
LINK32_OBJS= \
	"$(INTDIR)\CRYPTO.OBJ" \
	"$(INTDIR)\WRRDAT.OBJ" \
	"$(INTDIR)\WUSERS.OBJ" \
	"$(INTDIR)\RRUSERS.res"

"$(OUTDIR)\Rrwusers.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("rrusers.dep")
!INCLUDE "rrusers.dep"
!ELSE 
!MESSAGE Warning: cannot find "rrusers.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "rrusers - Win32 Release" || "$(CFG)" == "rrusers - Win32 Debug" || "$(CFG)" == "rrusers - Win32 Release with Asserts"
SOURCE=.\CRYPTO.CPP

!IF  "$(CFG)" == "rrusers - Win32 Release"


"$(INTDIR)\CRYPTO.OBJ" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "rrusers - Win32 Debug"


"$(INTDIR)\CRYPTO.OBJ"	"$(INTDIR)\CRYPTO.SBR" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "rrusers - Win32 Release with Asserts"


"$(INTDIR)\CRYPTO.OBJ" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\RRUSERS.RC

"$(INTDIR)\RRUSERS.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=\rrw7\SETUP\WRRDAT.CPP

!IF  "$(CFG)" == "rrusers - Win32 Release"


"$(INTDIR)\WRRDAT.OBJ" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "rrusers - Win32 Debug"


"$(INTDIR)\WRRDAT.OBJ"	"$(INTDIR)\WRRDAT.SBR" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "rrusers - Win32 Release with Asserts"


"$(INTDIR)\WRRDAT.OBJ" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\WUSERS.CPP

!IF  "$(CFG)" == "rrusers - Win32 Release"


"$(INTDIR)\WUSERS.OBJ" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "rrusers - Win32 Debug"


"$(INTDIR)\WUSERS.OBJ"	"$(INTDIR)\WUSERS.SBR" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "rrusers - Win32 Release with Asserts"


"$(INTDIR)\WUSERS.OBJ" : $(SOURCE) "$(INTDIR)"


!ENDIF 


!ENDIF 

