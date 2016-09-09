@set BASE=G:\SourceMod
@set PATHS=--hl2sdk-root=%BASE%\ --mms-path=%BASE%\mmsource-1.10\ --sm-path=%BASE%\sourcemod\
@set COMMON=--gen=vs --vs-split %PATHS% --sdks=tf2 --sigsegv-convenience
@set DEBUG=--enable-debug
@set RELEASE=--enable-optimize

python2 ..\configure.py %COMMON% --vs-version=2010 %DEBUG%
python2 ..\configure.py %COMMON% --vs-version=2010 %RELEASE%

python2 ..\configure.py %COMMON% --vs-version=2012 %DEBUG%
python2 ..\configure.py %COMMON% --vs-version=2012 %RELEASE%

python2 ..\configure.py %COMMON% --vs-version=2013 %DEBUG%
python2 ..\configure.py %COMMON% --vs-version=2013 %RELEASE%
