@echo off
set ASTYLEEXE=c:\bin\astyle.exe
set ASTYLEOPT=-n -Q --options=astyle-cpp-options
%ASTYLEEXE% %ASTYLEOPT% *.cpp *.h dumpobj\*.cpp testanalyzer\*.cpp
