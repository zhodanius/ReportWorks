@echo off
echo ______________________________________________________________________________
echo Usage: buildocx [LIVE1.0,LIVE1LOC,TIP,TMP] [POP,NOPOP] [CLEAN,NOCLEAN] [TMP #]
echo 
echo To build a TMP, call w/ TMP argument and WO# at end.  Uses "Rrw8.0 Arp2.0 FCS"
echo     for Live 1.0 sources, call w/ "LIVE1.0" argument, 
echo     for 1.0 localized sources, use "LIVE1LOC",
echo     else use "TIP"
echo To skip populate, call w/ NOPOP as second arg, else "POP"
echo To do a full build, call w/ "CLEAN" as third arg, else "NOCLEAN"
echo 
echo To build, must have MSVC 4.2 in t:\MSDEV4.2,
echo           the MS ActiveX SDK in t:\inetsdk, 
echo           and the MS Win32 SDK in t:\mstools.
echo ______________________________________________________________________
pause

if not '%1' == 'LIVE1.0' if not '%1' == 'TIP' if not '%1' == 'LIVE1LOC' if not '%1' == 'TMP' goto USAGE
if not '%2' == 'POP' if not '%2' == 'NOPOP' goto USAGE
if not '%3' == 'CLEAN' if not '%3' == 'NOCLEAN' goto USAGE
if '%1' == 'TMP' and '%4' == '' goto USAGE

md \rrw7
md \rrw7\alive
md \rrw7\alive\rrlite
md \rrw7\alive\h
md \rrw7\alive\rrlite\framewrk
md \rrw7\alive\rrlite\framewrk\include
md \rrw7\alive\rrlite\framewrk\libs

set vproj=rrmfc

if '%2' == 'NOPOP' goto DONEPOP

rem Always clean source tree before populating
cd \rrw7
echo y > y.txt
attrib -r h\*.* 
del h\*.* <y.txt
attrib -r alive\rrlite\framewrk\*.* 
del alive\rrlite\framewrk\*.* <y.txt
attrib -r alive\rrlite\framewrk\include\*.* 
del alive\rrlite\framewrk\include\*.* <y.txt
attrib -r alive\rrlite\framewrk\libs\*.* 
del alive\rrlite\framewrk\libs\*.* <y.txt
attrib -r alive\rrlite\*.* 
del alive\rrlite\*.* <y.txt
attrib -r resource\*.* 
del resource\*.* <y.txt

if '%1' == 'LIVE1.0' goto LIVE10
if '%1' == 'LIVE1LOC' goto LIVE1LOC
if '%1' == 'TMP' goto TMPGET
rem else, get the TIP

cd \rrw7\h
set vdir=h
get _pdx.h
get alo.hpp
get appres.hm
get pd.h
get pdx.h
get version.h
cd \rrw7\alive\rrlite\framewrk
set vdir=alive\rrlite\framewrk
get *.??v
cd include
set vdir=alive\rrlite\framewrk\include
get *.??v
cd ..\libs
set vdir=alive\rrlite\framewrk\libs
get *.??v
cd \rrw7\alive\rrlite
set vdir=alive\rrlite
get *.??v
rename rrprvi~1.h "RRPrViewInterfaces.h"
cd \rrw7\resource
set vdir=resource
get rsw.ico
goto DONEPOP

:LIVE10
cd \rrw7\h
set vdir=h
get -v"Live1.0 FCS" _pdx.h
get -v"Live1.0 FCS" alo.hpp
get -v"Live1.0 FCS" appres.hm
get -v"Live1.0 FCS" pd.h
get -v"Live1.0 FCS" pdx.h
get -v"Live1.0 FCS" version.h
cd \rrw7\alive\rrlite\framewrk
set vdir=alive\rrlite\framewrk
get -v"Live1.0 FCS" *.??v
cd include
set vdir=alive\rrlite\framewrk\include
get -v"Live1.0 FCS" *.??v
cd ..\libs
set vdir=alive\rrlite\framewrk\libs
get -v"Live1.0 FCS" *.??v
cd \rrw7\alive\rrlite
set vdir=alive\rrlite
get -v"Live1.0 FCS" *.??v
rename rrprvi~1.h "RRPrViewInterfaces.h"
cd \rrw7\resource
set vdir=resource
get -v"Live1.0 FCS" rsw.ico
goto DONEPOP

:LIVE1LOC
cd \rrw7\h
set vdir=h
get -v"Live1.0 Loc" _pdx.h
get -v"Live1.0 Loc" alo.hpp
get -v"Live1.0 Loc" appres.hm
get -v"Live1.0 Loc" pd.h
get -v"Live1.0 Loc" pdx.h
get -v"Live1.0 Loc" version.h
cd \rrw7\alive\rrlite\framewrk
set vdir=alive\rrlite\framewrk
get -v"Live1.0 Loc" *.??v
cd include
set vdir=alive\rrlite\framewrk\include
get -v"Live1.0 Loc" *.??v
cd ..\libs
set vdir=alive\rrlite\framewrk\libs
get -v"Live1.0 Loc" *.??v
cd \rrw7\alive\rrlite
set vdir=alive\rrlite
get -v"Live1.0 Loc" *.??v
rename rrprvi~1.h "RRPrViewInterfaces.h"
cd \rrw7\resource
set vdir=resource
get -v"Live1.0 Loc" rsw.ico

:TMPGET
cd \rrw7\h
set vdir=h
get -v"ARP20006" _pdx.h
get -v"%4" _pdx.h
get -v"ARP20006" alo.hpp
get -v"%4" alo.hpp
get -v"ARP20006" appres.hm
get -v"%4" appres.hm
get -v"ARP20006" pd.h
get -v"%4" pd.h
get -v"ARP20006" pdx.h
get -v"%4" pdx.h
get -v"ARP20006" version.h
get -v"%4" version.h
cd \rrw7\alive\rrlite\framewrk
set vdir=alive\rrlite\framewrk
get -v"ARP20006" *.??v
get -v"%4" *.??v
cd include
set vdir=alive\rrlite\framewrk\include
get -v"ARP20006" *.??v
get -v"%4" *.??v
cd ..\libs
set vdir=alive\rrlite\framewrk\libs
get -v"ARP20006" *.??v
get -v"%4" *.??v
cd \rrw7\alive\rrlite
set vdir=alive\rrlite
get -v"ARP20006" *.??v
get -v"%4" *.??v
rename rrprvi~1.h "RRPrViewInterfaces.h"
cd \rrw7\resource
set vdir=resource
get -v"ARP20006" rsw.ico
get -v"%4" rsw.ico

:DONEPOP

set TEMPINC=%INCLUDE%
set INCLUDE=t:\inetsdk\include;t:\inetsdk\samples\basectl\include;t:\mstools\include;t:\msdev4.2\include;\rrw7\alive\rrlite;\rrw7\alive\rrlite\framewrk\include;\rrw7\h
set TEMPPATH=%PATH%
set PATH=%PATH%;t:\msdev4.2\bin
set TEMPLIB=%LIB%
set LIB=t:\inetsdk\lib;t:\mstools\lib;t:\msdev4.2\lib;\rrw7\alive\rrlite\framewrk\libs

cd \rrw7\alive\rrlite
if not '%3' == 'CLEAN' goto BUILD
cd \rrw7\alive\rrlite
echo y > y.txt
del debug\*.* <y.txt
del release\*.* <y.txt

:BUILD
t:\msdev4.2\bin\nmake /f rrprview.mak /x debug.txt CFG="rrprview - Win32 Debug"
t:\msdev4.2\bin\nmake /f rrprview.mak /x release.txt CFG="rrprview - Win32 Release"

:SIGN
call buildcab

type debug.txt
pause
type release.txt
pause

set INCLUDE=%TEMPINC%
set PATH=%TEMPPATH%
set LIB=%TEMPLIB%

goto END
:USAGE
echo ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
echo Usage: buildocx [LIVE1.0,LIVE1LOC,TIP,TMP] [POP,NOPOP] [CLEAN,NOCLEAN] [WO#]
echo ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
:END
