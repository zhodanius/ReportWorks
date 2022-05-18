# Microsoft Developer Studio Generated NMAKE File, Based on ctlfw32.dsp
!IF "$(CFG)" == ""
CFG=ctlfw32 - Win32 Release
!MESSAGE No configuration specified. Defaulting to ctlfw32 - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "ctlfw32 - Win32 Release" && "$(CFG)" != "ctlfw32 - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ctlfw32.mak" CFG="ctlfw32 - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ctlfw32 - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "ctlfw32 - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ctlfw32 - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\ctlfwR32.lib"


CLEAN :
	-@erase "$(INTDIR)\Autoobj.obj"
	-@erase "$(INTDIR)\Classf.obj"
	-@erase "$(INTDIR)\Ctlembed.obj"
	-@erase "$(INTDIR)\Ctlhelp.obj"
	-@erase "$(INTDIR)\Ctlmisc.obj"
	-@erase "$(INTDIR)\Ctlocx96.obj"
	-@erase "$(INTDIR)\Ctlpsst.obj"
	-@erase "$(INTDIR)\Ctlview.obj"
	-@erase "$(INTDIR)\Ctlwrap.obj"
	-@erase "$(INTDIR)\Debug.obj"
	-@erase "$(INTDIR)\Extobj.obj"
	-@erase "$(INTDIR)\Globals.obj"
	-@erase "$(INTDIR)\Internet.obj"
	-@erase "$(INTDIR)\Ipserver.obj"
	-@erase "$(INTDIR)\Proppage.obj"
	-@erase "$(INTDIR)\Stdenum.obj"
	-@erase "$(INTDIR)\Unknown.obj"
	-@erase "$(INTDIR)\Util.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\ctlfwR32.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /Zp1 /ML /W3 /GX /O2 /I ".\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\ctlfw32.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ctlfw32.bsc" 
BSC32_SBRS= \
	
LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\ctlfwR32.lib" 
LIB32_OBJS= \
	"$(INTDIR)\Autoobj.obj" \
	"$(INTDIR)\Classf.obj" \
	"$(INTDIR)\Ctlembed.obj" \
	"$(INTDIR)\Ctlhelp.obj" \
	"$(INTDIR)\Ctlmisc.obj" \
	"$(INTDIR)\Ctlocx96.obj" \
	"$(INTDIR)\Ctlpsst.obj" \
	"$(INTDIR)\Ctlview.obj" \
	"$(INTDIR)\Ctlwrap.obj" \
	"$(INTDIR)\Debug.obj" \
	"$(INTDIR)\Extobj.obj" \
	"$(INTDIR)\Globals.obj" \
	"$(INTDIR)\Internet.obj" \
	"$(INTDIR)\Ipserver.obj" \
	"$(INTDIR)\Proppage.obj" \
	"$(INTDIR)\Stdenum.obj" \
	"$(INTDIR)\Unknown.obj" \
	"$(INTDIR)\Util.obj"

"$(OUTDIR)\ctlfwR32.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ctlfw32 - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\ctlfwD32.lib"


CLEAN :
	-@erase "$(INTDIR)\Autoobj.obj"
	-@erase "$(INTDIR)\Classf.obj"
	-@erase "$(INTDIR)\Ctlembed.obj"
	-@erase "$(INTDIR)\Ctlhelp.obj"
	-@erase "$(INTDIR)\Ctlmisc.obj"
	-@erase "$(INTDIR)\Ctlocx96.obj"
	-@erase "$(INTDIR)\Ctlpsst.obj"
	-@erase "$(INTDIR)\Ctlview.obj"
	-@erase "$(INTDIR)\Ctlwrap.obj"
	-@erase "$(INTDIR)\Debug.obj"
	-@erase "$(INTDIR)\Extobj.obj"
	-@erase "$(INTDIR)\Globals.obj"
	-@erase "$(INTDIR)\Internet.obj"
	-@erase "$(INTDIR)\Ipserver.obj"
	-@erase "$(INTDIR)\Proppage.obj"
	-@erase "$(INTDIR)\Stdenum.obj"
	-@erase "$(INTDIR)\Unknown.obj"
	-@erase "$(INTDIR)\Util.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\ctlfwD32.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /Zp1 /MLd /W3 /GX /Z7 /Od /I ".\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Fp"$(INTDIR)\ctlfw32.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ctlfw32.bsc" 
BSC32_SBRS= \
	
LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\ctlfwD32.lib" 
LIB32_OBJS= \
	"$(INTDIR)\Autoobj.obj" \
	"$(INTDIR)\Classf.obj" \
	"$(INTDIR)\Ctlembed.obj" \
	"$(INTDIR)\Ctlhelp.obj" \
	"$(INTDIR)\Ctlmisc.obj" \
	"$(INTDIR)\Ctlocx96.obj" \
	"$(INTDIR)\Ctlpsst.obj" \
	"$(INTDIR)\Ctlview.obj" \
	"$(INTDIR)\Ctlwrap.obj" \
	"$(INTDIR)\Debug.obj" \
	"$(INTDIR)\Extobj.obj" \
	"$(INTDIR)\Globals.obj" \
	"$(INTDIR)\Internet.obj" \
	"$(INTDIR)\Ipserver.obj" \
	"$(INTDIR)\Proppage.obj" \
	"$(INTDIR)\Stdenum.obj" \
	"$(INTDIR)\Unknown.obj" \
	"$(INTDIR)\Util.obj"

"$(OUTDIR)\ctlfwD32.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
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
!IF EXISTS("ctlfw32.dep")
!INCLUDE "ctlfw32.dep"
!ELSE 
!MESSAGE Warning: cannot find "ctlfw32.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "ctlfw32 - Win32 Release" || "$(CFG)" == "ctlfw32 - Win32 Debug"
SOURCE=.\Autoobj.cpp

"$(INTDIR)\Autoobj.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Classf.cpp

"$(INTDIR)\Classf.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Ctlembed.cpp

"$(INTDIR)\Ctlembed.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Ctlhelp.cpp

"$(INTDIR)\Ctlhelp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Ctlmisc.cpp

"$(INTDIR)\Ctlmisc.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Ctlocx96.cpp

"$(INTDIR)\Ctlocx96.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Ctlpsst.cpp

"$(INTDIR)\Ctlpsst.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Ctlview.cpp

"$(INTDIR)\Ctlview.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Ctlwrap.cpp

"$(INTDIR)\Ctlwrap.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Debug.cpp

"$(INTDIR)\Debug.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Extobj.cpp

"$(INTDIR)\Extobj.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Globals.cpp

"$(INTDIR)\Globals.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Internet.cpp

"$(INTDIR)\Internet.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Ipserver.cpp

"$(INTDIR)\Ipserver.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Proppage.cpp

"$(INTDIR)\Proppage.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Stdenum.cpp

"$(INTDIR)\Stdenum.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Unknown.cpp

"$(INTDIR)\Unknown.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Util.cpp

"$(INTDIR)\Util.obj" : $(SOURCE) "$(INTDIR)"



!ENDIF 

