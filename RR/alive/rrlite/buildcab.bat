rem build rrprview.cab
rem don't know why this always goes to disk1, even if I try to change it.

del disk1\Rrprview.cab

rem t:\inetsdk\cabsdk\bin\makecab /f rrprview.ddf


set TEMPPATH=%PATH%
rem set PATH=t:\inetsdk\bin;%PATH%

set PATH=d:\tools\activex;%PATH%

makecab /f rrprview.ddf
rem signcode -spc wallkey.spc -v wallkey.pvk -n "Wall Data Viewer Control" -i http://www.walldata.com -t http://timestamp.verisign.com/scripts/timstamp.dll Disk1\Rrprview.cab
signcode -spc liveware.spc -v liveware.pvk -n "Liveware Viewer Control" -i http://www.livewarepub.com -t http://timestamp.verisign.com/scripts/timstamp.dll Disk1\Rrprview.cab
chktrust -c Disk1\Rrprview.cab

set PATH=%TEMPPATH%

rem :END
