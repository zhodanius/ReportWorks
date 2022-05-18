set destdir=rrw7

md \%destdir%\ALIVE
md \%destdir%\ALIVE\rrlite
cd \%destdir%\ALIVE\rrlite
set vdir=ALIVE\rrlite
get %1 %2 %3 %4 %5 %6 %7 %8 %9 *.??v

md \%destdir%\ALIVE\rrlite\framewrk
cd \%destdir%\ALIVE\rrlite\framewrk
set vdir=ALIVE\rrlite\framewrk
get %1 %2 %3 %4 %5 %6 %7 %8 %9 *.??v

md \%destdir%\ALIVE\rrlite\framewrk\include
cd \%destdir%\ALIVE\rrlite\framewrk\include
set vdir=ALIVE\rrlite\framewrk\include
get %1 %2 %3 %4 %5 %6 %7 %8 %9 *.??v

md \%destdir%\ALIVE\rrlite\framewrk\libs
cd \%destdir%\ALIVE\rrlite\framewrk\libs
set vdir=ALIVE\rrlite\framewrk\libs
get %1 %2 %3 %4 %5 %6 %7 %8 %9 *.??v

cd \%destdir%\ALIVE\rrlite
