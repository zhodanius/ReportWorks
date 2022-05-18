# Microsoft Developer Studio Generated NMAKE File, Based on rrprview.dsp
!IF "$(CFG)" == ""
CFG=rrprview - Win32 Release
!MESSAGE No configuration specified. Defaulting to rrprview - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "rrprview - Win32 Release" && "$(CFG)" != "rrprview - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
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

!IF  "$(CFG)" == "rrprview - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\rrprview.ocx" "$(OUTDIR)\rrprview.tlb" "$(OUTDIR)\rrprview.bsc"


CLEAN :
	-@erase "$(INTDIR)\accusoft.obj"
	-@erase "$(INTDIR)\accusoft.sbr"
	-@erase "$(INTDIR)\Cathelp.obj"
	-@erase "$(INTDIR)\Cathelp.sbr"
	-@erase "$(INTDIR)\CONTAIN.OBJ"
	-@erase "$(INTDIR)\CONTAIN.SBR"
	-@erase "$(INTDIR)\DISPPROP.OBJ"
	-@erase "$(INTDIR)\DISPPROP.SBR"
	-@erase "$(INTDIR)\drawctrl.obj"
	-@erase "$(INTDIR)\drawctrl.sbr"
	-@erase "$(INTDIR)\fileread.obj"
	-@erase "$(INTDIR)\fileread.sbr"
	-@erase "$(INTDIR)\Guids.obj"
	-@erase "$(INTDIR)\Guids.sbr"
	-@erase "$(INTDIR)\IMGPATH.OBJ"
	-@erase "$(INTDIR)\IMGPATH.SBR"
	-@erase "$(INTDIR)\pagetip.obj"
	-@erase "$(INTDIR)\pagetip.sbr"
	-@erase "$(INTDIR)\printrep.obj"
	-@erase "$(INTDIR)\printrep.sbr"
	-@erase "$(INTDIR)\READCHRT.OBJ"
	-@erase "$(INTDIR)\READCHRT.SBR"
	-@erase "$(INTDIR)\readimg.obj"
	-@erase "$(INTDIR)\readimg.sbr"
	-@erase "$(INTDIR)\READOBJ.OBJ"
	-@erase "$(INTDIR)\READOBJ.SBR"
	-@erase "$(INTDIR)\Readv2.obj"
	-@erase "$(INTDIR)\Readv2.sbr"
	-@erase "$(INTDIR)\reppage.obj"
	-@erase "$(INTDIR)\reppage.sbr"
	-@erase "$(INTDIR)\repurl.obj"
	-@erase "$(INTDIR)\repurl.sbr"
	-@erase "$(INTDIR)\Rrprfile.obj"
	-@erase "$(INTDIR)\Rrprfile.sbr"
	-@erase "$(INTDIR)\rrprview.obj"
	-@erase "$(INTDIR)\rrprview.res"
	-@erase "$(INTDIR)\rrprview.sbr"
	-@erase "$(INTDIR)\rrprview.tlb"
	-@erase "$(INTDIR)\rrutil.obj"
	-@erase "$(INTDIR)\rrutil.sbr"
	-@erase "$(INTDIR)\rrvwctrl.obj"
	-@erase "$(INTDIR)\rrvwctrl.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\viewbox.obj"
	-@erase "$(INTDIR)\viewbox.sbr"
	-@erase "$(INTDIR)\VIEWCHRT.OBJ"
	-@erase "$(INTDIR)\VIEWCHRT.SBR"
	-@erase "$(INTDIR)\viewimg.obj"
	-@erase "$(INTDIR)\viewimg.sbr"
	-@erase "$(INTDIR)\viewlbox.obj"
	-@erase "$(INTDIR)\viewlbox.sbr"
	-@erase "$(INTDIR)\viewline.obj"
	-@erase "$(INTDIR)\viewline.sbr"
	-@erase "$(INTDIR)\VIEWOBJ.OBJ"
	-@erase "$(INTDIR)\VIEWOBJ.SBR"
	-@erase "$(INTDIR)\viewrep.obj"
	-@erase "$(INTDIR)\viewrep.sbr"
	-@erase "$(INTDIR)\viewtext.obj"
	-@erase "$(INTDIR)\viewtext.sbr"
	-@erase "$(OUTDIR)\rrprview.bsc"
	-@erase "$(OUTDIR)\rrprview.exp"
	-@erase "$(OUTDIR)\rrprview.lib"
	-@erase "$(OUTDIR)\rrprview.ocx"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /Zp1 /MT /W3 /GX /O1 /I "\rrw7\alive\rrlite\framewrk\include" /I "\rrw7\h" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Fr"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /I "\rrw7\alive\rrlite\framewrk\include" /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\rrprview.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\rrprview.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\accusoft.sbr" \
	"$(INTDIR)\Cathelp.sbr" \
	"$(INTDIR)\CONTAIN.SBR" \
	"$(INTDIR)\DISPPROP.SBR" \
	"$(INTDIR)\drawctrl.sbr" \
	"$(INTDIR)\fileread.sbr" \
	"$(INTDIR)\Guids.sbr" \
	"$(INTDIR)\IMGPATH.SBR" \
	"$(INTDIR)\pagetip.sbr" \
	"$(INTDIR)\printrep.sbr" \
	"$(INTDIR)\READCHRT.SBR" \
	"$(INTDIR)\readimg.sbr" \
	"$(INTDIR)\READOBJ.SBR" \
	"$(INTDIR)\Readv2.sbr" \
	"$(INTDIR)\reppage.sbr" \
	"$(INTDIR)\repurl.sbr" \
	"$(INTDIR)\Rrprfile.sbr" \
	"$(INTDIR)\rrprview.sbr" \
	"$(INTDIR)\rrutil.sbr" \
	"$(INTDIR)\rrvwctrl.sbr" \
	"$(INTDIR)\viewbox.sbr" \
	"$(INTDIR)\VIEWCHRT.SBR" \
	"$(INTDIR)\viewimg.sbr" \
	"$(INTDIR)\viewlbox.sbr" \
	"$(INTDIR)\viewline.sbr" \
	"$(INTDIR)\VIEWOBJ.SBR" \
	"$(INTDIR)\viewrep.sbr" \
	"$(INTDIR)\viewtext.sbr"

"$(OUTDIR)\rrprview.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=\rrw7\alive\rrlite\framewrk\release\CtlFwR32.Lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib urlmon.lib wininet.lib comctl32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\rrprview.pdb" /machine:I386 /nodefaultlib:"libc.lib" /nodefaultlib:"msvcrt.lib" /nodefaultlib:"libcd.lib" /nodefaultlib:"libcmtd.lib" /nodefaultlib:"msvcrtd.lib" /def:".\rrprview.def" /out:"$(OUTDIR)\rrprview.ocx" /implib:"$(OUTDIR)\rrprview.lib" 
DEF_FILE= \
	".\rrprview.def"
LINK32_OBJS= \
	"$(INTDIR)\accusoft.obj" \
	"$(INTDIR)\Cathelp.obj" \
	"$(INTDIR)\CONTAIN.OBJ" \
	"$(INTDIR)\DISPPROP.OBJ" \
	"$(INTDIR)\drawctrl.obj" \
	"$(INTDIR)\fileread.obj" \
	"$(INTDIR)\Guids.obj" \
	"$(INTDIR)\IMGPATH.OBJ" \
	"$(INTDIR)\pagetip.obj" \
	"$(INTDIR)\printrep.obj" \
	"$(INTDIR)\READCHRT.OBJ" \
	"$(INTDIR)\readimg.obj" \
	"$(INTDIR)\READOBJ.OBJ" \
	"$(INTDIR)\Readv2.obj" \
	"$(INTDIR)\reppage.obj" \
	"$(INTDIR)\repurl.obj" \
	"$(INTDIR)\Rrprfile.obj" \
	"$(INTDIR)\rrprview.obj" \
	"$(INTDIR)\rrutil.obj" \
	"$(INTDIR)\rrvwctrl.obj" \
	"$(INTDIR)\viewbox.obj" \
	"$(INTDIR)\VIEWCHRT.OBJ" \
	"$(INTDIR)\viewimg.obj" \
	"$(INTDIR)\viewlbox.obj" \
	"$(INTDIR)\viewline.obj" \
	"$(INTDIR)\VIEWOBJ.OBJ" \
	"$(INTDIR)\viewrep.obj" \
	"$(INTDIR)\viewtext.obj" \
	"$(INTDIR)\rrprview.res"

"$(OUTDIR)\rrprview.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

SOURCE="$(InputPath)"
PostBuild_Desc=Make a cabinet file
DS_POSTBUILD_DEP=$(INTDIR)\postbld.dep

ALL : $(DS_POSTBUILD_DEP)

# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

$(DS_POSTBUILD_DEP) : "$(OUTDIR)\rrprview.ocx" "$(OUTDIR)\rrprview.tlb" "$(OUTDIR)\rrprview.bsc"
   buildcab.bat
	echo Helper for Post-build step > "$(DS_POSTBUILD_DEP)"

!ELSEIF  "$(CFG)" == "rrprview - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\rrprview.ocx" "$(OUTDIR)\rrprview.tlb" "$(OUTDIR)\rrprview.bsc"


CLEAN :
	-@erase "$(INTDIR)\accusoft.obj"
	-@erase "$(INTDIR)\accusoft.sbr"
	-@erase "$(INTDIR)\Cathelp.obj"
	-@erase "$(INTDIR)\Cathelp.sbr"
	-@erase "$(INTDIR)\CONTAIN.OBJ"
	-@erase "$(INTDIR)\CONTAIN.SBR"
	-@erase "$(INTDIR)\DISPPROP.OBJ"
	-@erase "$(INTDIR)\DISPPROP.SBR"
	-@erase "$(INTDIR)\drawctrl.obj"
	-@erase "$(INTDIR)\drawctrl.sbr"
	-@erase "$(INTDIR)\fileread.obj"
	-@erase "$(INTDIR)\fileread.sbr"
	-@erase "$(INTDIR)\Guids.obj"
	-@erase "$(INTDIR)\Guids.sbr"
	-@erase "$(INTDIR)\IMGPATH.OBJ"
	-@erase "$(INTDIR)\IMGPATH.SBR"
	-@erase "$(INTDIR)\pagetip.obj"
	-@erase "$(INTDIR)\pagetip.sbr"
	-@erase "$(INTDIR)\printrep.obj"
	-@erase "$(INTDIR)\printrep.sbr"
	-@erase "$(INTDIR)\READCHRT.OBJ"
	-@erase "$(INTDIR)\READCHRT.SBR"
	-@erase "$(INTDIR)\readimg.obj"
	-@erase "$(INTDIR)\readimg.sbr"
	-@erase "$(INTDIR)\READOBJ.OBJ"
	-@erase "$(INTDIR)\READOBJ.SBR"
	-@erase "$(INTDIR)\Readv2.obj"
	-@erase "$(INTDIR)\Readv2.sbr"
	-@erase "$(INTDIR)\reppage.obj"
	-@erase "$(INTDIR)\reppage.sbr"
	-@erase "$(INTDIR)\repurl.obj"
	-@erase "$(INTDIR)\repurl.sbr"
	-@erase "$(INTDIR)\Rrprfile.obj"
	-@erase "$(INTDIR)\Rrprfile.sbr"
	-@erase "$(INTDIR)\rrprview.obj"
	-@erase "$(INTDIR)\rrprview.res"
	-@erase "$(INTDIR)\rrprview.sbr"
	-@erase "$(INTDIR)\rrprview.tlb"
	-@erase "$(INTDIR)\rrutil.obj"
	-@erase "$(INTDIR)\rrutil.sbr"
	-@erase "$(INTDIR)\rrvwctrl.obj"
	-@erase "$(INTDIR)\rrvwctrl.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\viewbox.obj"
	-@erase "$(INTDIR)\viewbox.sbr"
	-@erase "$(INTDIR)\VIEWCHRT.OBJ"
	-@erase "$(INTDIR)\VIEWCHRT.SBR"
	-@erase "$(INTDIR)\viewimg.obj"
	-@erase "$(INTDIR)\viewimg.sbr"
	-@erase "$(INTDIR)\viewlbox.obj"
	-@erase "$(INTDIR)\viewlbox.sbr"
	-@erase "$(INTDIR)\viewline.obj"
	-@erase "$(INTDIR)\viewline.sbr"
	-@erase "$(INTDIR)\VIEWOBJ.OBJ"
	-@erase "$(INTDIR)\VIEWOBJ.SBR"
	-@erase "$(INTDIR)\viewrep.obj"
	-@erase "$(INTDIR)\viewrep.sbr"
	-@erase "$(INTDIR)\viewtext.obj"
	-@erase "$(INTDIR)\viewtext.sbr"
	-@erase "$(OUTDIR)\rrprview.bsc"
	-@erase "$(OUTDIR)\rrprview.exp"
	-@erase "$(OUTDIR)\rrprview.ilk"
	-@erase "$(OUTDIR)\rrprview.lib"
	-@erase "$(OUTDIR)\rrprview.ocx"
	-@erase "$(OUTDIR)\rrprview.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /Zp1 /MTd /W3 /Gm /GX /ZI /Od /I "\rrw7\alive\rrlite\framewrk\include" /I "\rrw7\h" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fr"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /I "\rrw7\alive\rrlite\framewrk\include" /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\rrprview.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\rrprview.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\accusoft.sbr" \
	"$(INTDIR)\Cathelp.sbr" \
	"$(INTDIR)\CONTAIN.SBR" \
	"$(INTDIR)\DISPPROP.SBR" \
	"$(INTDIR)\drawctrl.sbr" \
	"$(INTDIR)\fileread.sbr" \
	"$(INTDIR)\Guids.sbr" \
	"$(INTDIR)\IMGPATH.SBR" \
	"$(INTDIR)\pagetip.sbr" \
	"$(INTDIR)\printrep.sbr" \
	"$(INTDIR)\READCHRT.SBR" \
	"$(INTDIR)\readimg.sbr" \
	"$(INTDIR)\READOBJ.SBR" \
	"$(INTDIR)\Readv2.sbr" \
	"$(INTDIR)\reppage.sbr" \
	"$(INTDIR)\repurl.sbr" \
	"$(INTDIR)\Rrprfile.sbr" \
	"$(INTDIR)\rrprview.sbr" \
	"$(INTDIR)\rrutil.sbr" \
	"$(INTDIR)\rrvwctrl.sbr" \
	"$(INTDIR)\viewbox.sbr" \
	"$(INTDIR)\VIEWCHRT.SBR" \
	"$(INTDIR)\viewimg.sbr" \
	"$(INTDIR)\viewlbox.sbr" \
	"$(INTDIR)\viewline.sbr" \
	"$(INTDIR)\VIEWOBJ.SBR" \
	"$(INTDIR)\viewrep.sbr" \
	"$(INTDIR)\viewtext.sbr"

"$(OUTDIR)\rrprview.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=CtlFwD32.Lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib urlmon.lib wininet.lib comctl32.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\rrprview.pdb" /debug /machine:I386 /nodefaultlib:"libc.lib" /nodefaultlib:"libcmt.lib" /nodefaultlib:"msvcrt.lib" /nodefaultlib:"libcd.lib" /nodefaultlib:"msvcrtd.lib" /def:".\rrprview.def" /out:"$(OUTDIR)\rrprview.ocx" /implib:"$(OUTDIR)\rrprview.lib" /nodefaultlib:libc.lib, /nodefaultlib:libcmt.lib, /nodefaultlib:msvcrt.lib, 
DEF_FILE= \
	".\rrprview.def"
LINK32_OBJS= \
	"$(INTDIR)\accusoft.obj" \
	"$(INTDIR)\Cathelp.obj" \
	"$(INTDIR)\CONTAIN.OBJ" \
	"$(INTDIR)\DISPPROP.OBJ" \
	"$(INTDIR)\drawctrl.obj" \
	"$(INTDIR)\fileread.obj" \
	"$(INTDIR)\Guids.obj" \
	"$(INTDIR)\IMGPATH.OBJ" \
	"$(INTDIR)\pagetip.obj" \
	"$(INTDIR)\printrep.obj" \
	"$(INTDIR)\READCHRT.OBJ" \
	"$(INTDIR)\readimg.obj" \
	"$(INTDIR)\READOBJ.OBJ" \
	"$(INTDIR)\Readv2.obj" \
	"$(INTDIR)\reppage.obj" \
	"$(INTDIR)\repurl.obj" \
	"$(INTDIR)\Rrprfile.obj" \
	"$(INTDIR)\rrprview.obj" \
	"$(INTDIR)\rrutil.obj" \
	"$(INTDIR)\rrvwctrl.obj" \
	"$(INTDIR)\viewbox.obj" \
	"$(INTDIR)\VIEWCHRT.OBJ" \
	"$(INTDIR)\viewimg.obj" \
	"$(INTDIR)\viewlbox.obj" \
	"$(INTDIR)\viewline.obj" \
	"$(INTDIR)\VIEWOBJ.OBJ" \
	"$(INTDIR)\viewrep.obj" \
	"$(INTDIR)\viewtext.obj" \
	"$(INTDIR)\rrprview.res"

"$(OUTDIR)\rrprview.ocx" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("rrprview.dep")
!INCLUDE "rrprview.dep"
!ELSE 
!MESSAGE Warning: cannot find "rrprview.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "rrprview - Win32 Release" || "$(CFG)" == "rrprview - Win32 Debug"
SOURCE=.\accusoft.cpp

"$(INTDIR)\accusoft.obj"	"$(INTDIR)\accusoft.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Cathelp.cpp

"$(INTDIR)\Cathelp.obj"	"$(INTDIR)\Cathelp.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\CONTAIN.CPP

"$(INTDIR)\CONTAIN.OBJ"	"$(INTDIR)\CONTAIN.SBR" : $(SOURCE) "$(INTDIR)"


SOURCE=.\DISPPROP.CPP

"$(INTDIR)\DISPPROP.OBJ"	"$(INTDIR)\DISPPROP.SBR" : $(SOURCE) "$(INTDIR)"


SOURCE=.\drawctrl.cpp

"$(INTDIR)\drawctrl.obj"	"$(INTDIR)\drawctrl.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\fileread.cpp

"$(INTDIR)\fileread.obj"	"$(INTDIR)\fileread.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Guids.cpp

"$(INTDIR)\Guids.obj"	"$(INTDIR)\Guids.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\IMGPATH.CPP

"$(INTDIR)\IMGPATH.OBJ"	"$(INTDIR)\IMGPATH.SBR" : $(SOURCE) "$(INTDIR)"


SOURCE=.\pagetip.cpp

"$(INTDIR)\pagetip.obj"	"$(INTDIR)\pagetip.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\printrep.cpp

"$(INTDIR)\printrep.obj"	"$(INTDIR)\printrep.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\READCHRT.CPP

"$(INTDIR)\READCHRT.OBJ"	"$(INTDIR)\READCHRT.SBR" : $(SOURCE) "$(INTDIR)"


SOURCE=.\readimg.cpp

"$(INTDIR)\readimg.obj"	"$(INTDIR)\readimg.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\READOBJ.CPP

"$(INTDIR)\READOBJ.OBJ"	"$(INTDIR)\READOBJ.SBR" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Readv2.cpp

"$(INTDIR)\Readv2.obj"	"$(INTDIR)\Readv2.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\reppage.cpp

"$(INTDIR)\reppage.obj"	"$(INTDIR)\reppage.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\repurl.cpp

"$(INTDIR)\repurl.obj"	"$(INTDIR)\repurl.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Rrprfile.cpp

"$(INTDIR)\Rrprfile.obj"	"$(INTDIR)\Rrprfile.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\rrprview.cpp

"$(INTDIR)\rrprview.obj"	"$(INTDIR)\rrprview.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\rrprview.odl

!IF  "$(CFG)" == "rrprview - Win32 Release"

MTL_SWITCHES=/nologo /I "\rrw7\alive\rrlite\framewrk\include" /D "NDEBUG" /tlb "$(OUTDIR)\rrprview.tlb" /mktyplib203 /win32 

"$(OUTDIR)\rrprview.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "rrprview - Win32 Debug"

MTL_SWITCHES=/nologo /I "\rrw7\alive\rrlite\framewrk\include" /D "_DEBUG" /tlb "$(OUTDIR)\rrprview.tlb" /mktyplib203 /win32 

"$(OUTDIR)\rrprview.tlb" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\rrprview.rc

!IF  "$(CFG)" == "rrprview - Win32 Release"


"$(INTDIR)\rrprview.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\rrprview.res" /i ".\Release" /d "NDEBUG" $(SOURCE)


!ELSEIF  "$(CFG)" == "rrprview - Win32 Debug"


"$(INTDIR)\rrprview.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\rrprview.res" /i ".\Debug" /d "_DEBUG" $(SOURCE)


!ENDIF 

SOURCE=.\rrutil.cpp

"$(INTDIR)\rrutil.obj"	"$(INTDIR)\rrutil.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\rrvwctrl.cpp

"$(INTDIR)\rrvwctrl.obj"	"$(INTDIR)\rrvwctrl.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\viewbox.cpp

"$(INTDIR)\viewbox.obj"	"$(INTDIR)\viewbox.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\VIEWCHRT.CPP

"$(INTDIR)\VIEWCHRT.OBJ"	"$(INTDIR)\VIEWCHRT.SBR" : $(SOURCE) "$(INTDIR)"


SOURCE=.\viewimg.cpp

"$(INTDIR)\viewimg.obj"	"$(INTDIR)\viewimg.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\viewlbox.cpp

"$(INTDIR)\viewlbox.obj"	"$(INTDIR)\viewlbox.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\viewline.cpp

"$(INTDIR)\viewline.obj"	"$(INTDIR)\viewline.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\VIEWOBJ.CPP

"$(INTDIR)\VIEWOBJ.OBJ"	"$(INTDIR)\VIEWOBJ.SBR" : $(SOURCE) "$(INTDIR)"


SOURCE=.\viewrep.cpp

"$(INTDIR)\viewrep.obj"	"$(INTDIR)\viewrep.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\viewtext.cpp

"$(INTDIR)\viewtext.obj"	"$(INTDIR)\viewtext.sbr" : $(SOURCE) "$(INTDIR)"



!ENDIF 

