@echo off
SET PCLINK11=..\..\Debug\pclink11.exe
DEL /S /Q *-my.log *-my.SAV *-my.MAP *-my.STB > NUL
rem
echo ASHC4
CD ASHC4
%PCLINK11% ASHC4.OBJ > ASHC4-my.log
RENAME ASHC4.SAV ASHC4-my.SAV
RENAME ASHC4.MAP ASHC4-my.MAP
RENAME ASHC4.STB ASHC4-my.STB
rem
echo CLINE-UKNC
CD ..\CLINE-UKNC
%PCLINK11% CLINE.OBJ CENV.OBJ CWENV.OBJ CSPR.OBJ CKING.OBJ > CLINE-my.log
RENAME CLINE.SAV CLINE-my.SAV
RENAME CLINE.MAP CLINE-my.MAP
RENAME CLINE.STB CLINE-my.STB
rem
echo DATIME
CD ..\DATIME
%PCLINK11% DATIME.OBJ > DATIME-my.log
RENAME DATIME.SAV DATIME-my.SAV
RENAME DATIME.MAP DATIME-my.MAP
RENAME DATIME.STB DATIME-my.STB
rem
echo DEMO2-FORTRANIV
CD ..\DEMO2-FORTRANIV
%PCLINK11% DEMO2.OBJ FORLIB.OBJ > DEMO2-my.log
RENAME DEMO2.SAV DEMO2-my.SAV
RENAME DEMO2.MAP DEMO2-my.MAP
RENAME DEMO2.STB DEMO2-my.STB
rem
echo DISSAV-DBIT
CD ..\DISSAV-DBIT
%PCLINK11% DISSAV.OBJ > DISSAV-my.log
RENAME DISSAV.SAV DISSAV-my.SAV
RENAME DISSAV.MAP DISSAV-my.MAP
RENAME DISSAV.STB DISSAV-my.STB
rem
echo DW-ANDREY
CD ..\DW-ANDREY
%PCLINK11% /EXECUTE:DW.SYS DW.OBJ /X > DW-my.log
RENAME DW.SYS DW-my.SAV
RENAME DW.MAP DW-my.MAP
RENAME DW.STB DW-my.STB
rem
echo DW-FD6W
CD ..\DW-FD6W
%PCLINK11% /EXECUTE:DW.SYS DW.OBJ /X > DW-my.log
RENAME DW.SYS DW-my.SAV
RENAME DW.MAP DW-my.MAP
RENAME DW.STB DW-my.STB
rem
echo DWOPT
CD ..\DWOPT
%PCLINK11% DWOPT.OBJ > DWOPT-my.log
RENAME DWOPT.SAV DWOPT-my.SAV
RENAME DWOPT.MAP DWOPT-my.MAP
RENAME DWOPT.STB DWOPT-my.STB
rem
echo ELCOPY-FD6W
CD ..\ELCOPY-FD6W
%PCLINK11% ELCOPY.OBJ ELTASK.OBJ > ELCOPY-my.log
RENAME ELCOPY.SAV ELCOPY-my.SAV
RENAME ELCOPY.MAP ELCOPY-my.MAP
RENAME ELCOPY.STB ELCOPY-my.STB
rem
echo ELINIT-FD6W
CD ..\ELINIT-FD6W
%PCLINK11% ELINIT.OBJ > ELINIT-my.log
RENAME ELINIT.SAV ELINIT-my.SAV
RENAME ELINIT.MAP ELINIT-my.MAP
RENAME ELINIT.STB ELINIT-my.STB
rem
echo EMPIRE-WBRIGHT
CD ..\EMPIRE-WBRIGHT
%PCLINK11% /EXECUTE:EMPIRE.SAV VAR.OBJ EMPIRE.OBJ MOVE2.OBJ SUB1.OBJ TTY.OBJ HMOVE.OBJ HMOVE2.OBJ PATH.OBJ CITY.OBJ SUB2.OBJ MAPS.OBJ CMOVE.OBJ CMOVE2.OBJ ARMYMV.OBJ FIGHMV.OBJ SHIPMV.OBJ SECTOR.OBJ MOVE.OBJ IOMOD.OBJ INIT.OBJ > EMPIRE-my.log
RENAME EMPIRE.SAV EMPIRE-my.SAV
RENAME EMPIRE.MAP EMPIRE-my.MAP
RENAME EMPIRE.STB EMPIRE-my.STB
rem
echo EXPRES-24
CD ..\EXPRES-24
%PCLINK11% EXPRES.OBJ > EXPRES-my.log
RENAME EXPRES.SAV EXPRES-my.SAV
RENAME EXPRES.MAP EXPRES-my.MAP
RENAME EXPRES.STB EXPRES-my.STB
rem
echo EXPRES-BK-12
CD ..\EXPRES-BK-12
%PCLINK11% EXPRES.OBJ > EXPRES-my.log
RENAME EXPRES.SAV EXPRES-my.SAV
RENAME EXPRES.MAP EXPRES-my.MAP
RENAME EXPRES.STB EXPRES-my.STB
rem
echo EMUL-DISK25
CD ..\EMUL-DISK25
%PCLINK11% EMUL.OBJ > EMUL-my.log
RENAME EMUL.SAV EMUL-my.SAV
RENAME EMUL.MAP EMUL-my.MAP
RENAME EMUL.STB EMUL-my.STB
rem
echo FCU
CD ..\FCU
%PCLINK11% FCU.OBJ FCUE.OBJ FCUMNG.OBJ FCUD.OBJ SELF.OBJ > FCU-my.log
RENAME FCU.SAV FCU-my.SAV
RENAME FCU.MAP FCU-my.MAP
RENAME FCU.STB FCU-my.STB
rem
echo FIG-FORTH-1-3
CD ..\FIG-FORTH-1-3
%PCLINK11% FORTH.OBJ > FORTH-my.log
RENAME FORTH.SAV FORTH-my.SAV
RENAME FORTH.MAP FORTH-my.MAP
RENAME FORTH.STB FORTH-my.STB
rem
echo GAD2-HOBOT
CD ..\GAD2-HOBOT
%PCLINK11% GAD2.OBJ > GAD2-my.log
RENAME GAD2.SAV GAD2-my.SAV
RENAME GAD2.MAP GAD2-my.MAP
RENAME GAD2.STB GAD2-my.STB
rem
echo HAND-11
CD ..\HAND-11
%PCLINK11% HAND.OBJ > HAND-my.log
RENAME HAND.SAV HAND-my.SAV
RENAME HAND.MAP HAND-my.MAP
RENAME HAND.STB HAND-my.STB
rem
echo HANDLE-503
CD ..\HANDLE-503
%PCLINK11% HANDLE.OBJ > HANDLE-my.log
RENAME HANDLE.SAV HANDLE-my.SAV
RENAME HANDLE.MAP HANDLE-my.MAP
RENAME HANDLE.STB HANDLE-my.STB
rem
echo HD-DVKEmulator
CD ..\HD-DVKEmulator
%PCLINK11% /EXECUTE:HD.SYS HD.OBJ /X > HD-my.log
RENAME HD.SYS HD-my.SAV
RENAME HD.MAP HD-my.MAP
RENAME HD.STB HD-my.STB
rem
echo HELLO
CD ..\HELLO
%PCLINK11% HELLO.OBJ > HELLO-my.log
RENAME HELLO.SAV HELLO-my.SAV
RENAME HELLO.MAP HELLO-my.MAP
RENAME HELLO.STB HELLO-my.STB
rem
echo HWYENC-62
CD ..\HWYENC-62
%PCLINK11% HWYENC.OBJ > HWYENC-my.log
RENAME HWYENC.SAV HWYENC-my.SAV
RENAME HWYENC.MAP HWYENC-my.MAP
RENAME HWYENC.STB HWYENC-my.STB
rem
echo INTERFACE-DISK02
CD ..\INTERFACE-DISK02
%PCLINK11% IF.OBJ IFMAIN.OBJ IFCOPY.OBJ IFTRP.OBJ IFSPEC.OBJ IFPP.OBJ > IF-my.log
RENAME IF.SAV IF-my.SAV
RENAME IF.MAP IF-my.MAP
RENAME IF.STB IF-my.STB
rem
echo LD-FD6W
CD ..\LD-FD6W
%PCLINK11% /EXECUTE:LD.SYS LD.OBJ /X > LD-my.log
RENAME LD.SYS LD-my.SAV
RENAME LD.MAP LD-my.MAP
RENAME LD.STB LD-my.STB
rem
echo LZSAV
CD ..\LZSAV
%PCLINK11% LZSAV.OBJ > LZSAV-my.log
RENAME LZSAV.SAV LZSAV-my.SAV
RENAME LZSAV.MAP LZSAV-my.MAP
RENAME LZSAV.STB LZSAV-my.STB
rem
echo MAIN-50
CD ..\MAIN-50
%PCLINK11% MAIN.OBJ LEVELS.OBJ > MAIN-my.log
RENAME MAIN.SAV MAIN-my.SAV
RENAME MAIN.MAP MAIN-my.MAP
RENAME MAIN.STB MAIN-my.STB
rem
echo MUL
CD ..\MUL
%PCLINK11% MUL.OBJ > MUL-my.log
RENAME MUL.SAV MUL-my.SAV
RENAME MUL.MAP MUL-my.MAP
RENAME MUL.STB MUL-my.STB
rem
echo MYTEST1
CD ..\MYTEST1
%PCLINK11% MYTST1.OBJ OTHER.OBJ > MYTST1-my.log
RENAME MYTST1.SAV MYTST1-my.SAV
RENAME MYTST1.MAP MYTST1-my.MAP
RENAME MYTST1.STB MYTST1-my.STB
rem
echo MYTEST2
CD ..\MYTEST2
%PCLINK11% MYTST2.OBJ OTHER.OBJ > MYTST2-my.log
RENAME MYTST2.SAV MYTST2-my.SAV
RENAME MYTST2.MAP MYTST2-my.MAP
RENAME MYTST2.STB MYTST2-my.STB
rem
echo MYTEST3
CD ..\MYTEST3
%PCLINK11% MYTST3.OBJ OTHER.OBJ > MYTST3-my.log
RENAME MYTST3.SAV MYTST3-my.SAV
RENAME MYTST3.MAP MYTST3-my.MAP
RENAME MYTST3.STB MYTST3-my.STB
rem
echo NL-FD6W
CD ..\NL-FD6W
%PCLINK11% /EXECUTE:NL.SYS NL.OBJ /X > NL-my.log
RENAME NL.SYS NL-my.SAV
RENAME NL.MAP NL-my.MAP
RENAME NL.STB NL-my.STB
rem
echo PAKDMP-PHOOKY
CD ..\PAKDMP-PHOOKY
%PCLINK11% PAKDMP.OBJ > PAKDMP-my.log
RENAME PAKDMP.SAV PAKDMP-my.SAV
RENAME PAKDMP.MAP PAKDMP-my.MAP
RENAME PAKDMP.STB PAKDMP-my.STB
rem
echo PAKWRT-PHOOKY
CD ..\PAKWRT-PHOOKY
%PCLINK11% PAKWRT.OBJ > PAKWRT-my.log
RENAME PAKWRT.SAV PAKWRT-my.SAV
RENAME PAKWRT.MAP PAKWRT-my.MAP
RENAME PAKWRT.STB PAKWRT-my.STB
rem
echo PCBUG-1801BM1
CD ..\PCBUG-1801BM1
%PCLINK11% PCBUG.OBJ > PCBUG-my.log
RENAME PCBUG.SAV PCBUG-my.SAV
RENAME PCBUG.MAP PCBUG-my.MAP
RENAME PCBUG.STB PCBUG-my.STB
rem
echo PCM-DISK09
CD ..\PCM-DISK09
%PCLINK11% PCM.OBJ > PCM-my.log
RENAME PCM.SAV PCM-my.SAV
RENAME PCM.MAP PCM-my.MAP
RENAME PCM.STB PCM-my.STB
rem
echo PDPCLK
CD ..\PDPCLK
%PCLINK11% PDPCLK.OBJ > PDPCLK-my.log
RENAME PDPCLK.SAV PDPCLK-my.SAV
RENAME PDPCLK.MAP PDPCLK-my.MAP
RENAME PDPCLK.STB PDPCLK-my.STB
rem
echo PITEST-1801BM1
CD ..\PITEST-1801BM1
%PCLINK11% PITEST.OBJ > PITEST-my.log
RENAME PITEST.SAV PITEST-my.SAV
RENAME PITEST.MAP PITEST-my.MAP
RENAME PITEST.STB PITEST-my.STB
rem
echo PRIM-FORTRANIV
CD ..\PRIM-FORTRANIV
%PCLINK11% PRIM.OBJ FORLIB.OBJ > PRIM-my.log
RENAME PRIM.SAV PRIM-my.SAV
RENAME PRIM.MAP PRIM-my.MAP
RENAME PRIM.STB PRIM-my.STB
rem
echo RDMTUN-DSKMXC
CD ..\RDMTUN-DSKMXC
%PCLINK11% RDMTUN.OBJ > RDMTUN-my.log
RENAME RDMTUN.SAV RDMTUN-my.SAV
RENAME RDMTUN.MAP RDMTUN-my.MAP
RENAME RDMTUN.STB RDMTUN-my.STB
rem
echo REGCOP-ODE11
CD ..\REGCOP-ODE11
%PCLINK11% REGCOP.OBJ > REGCOP-my.log
RENAME REGCOP.SAV REGCOP-my.SAV
RENAME REGCOP.MAP REGCOP-my.MAP
RENAME REGCOP.STB REGCOP-my.STB
rem
echo REGPER-ODE11
CD ..\REGPER-ODE11
%PCLINK11% REGPER.OBJ > REGPER-my.log
RENAME REGPER.SAV REGPER-my.SAV
RENAME REGPER.MAP REGPER-my.MAP
RENAME REGPER.STB REGPER-my.STB
rem
echo RTS
CD ..\RTS
%PCLINK11% RTS.OBJ > RTS-my.log
RENAME RTS.SAV RTS-my.SAV
RENAME RTS.MAP RTS-my.MAP
RENAME RTS.STB RTS-my.STB
rem
echo RTLEM
CD ..\RTLEM
%PCLINK11% RTLEM.OBJ > RTLEM-my.log
RENAME RTLEM.SAV RTLEM-my.SAV
RENAME RTLEM.MAP RTLEM-my.MAP
RENAME RTLEM.STB RTLEM-my.STB
rem
echo SATMON-HADI3DSK
CD ..\SATMON-HADI3DSK
%PCLINK11% SATMON.OBJ > SATMON-my.log
RENAME SATMON.SAV SATMON-my.SAV
RENAME SATMON.MAP SATMON-my.MAP
RENAME SATMON.STB SATMON-my.STB
rem
echo SNDOFF-ANDREY14
CD ..\SNDOFF-ANDREY14
%PCLINK11% SNDOFF.OBJ > SNDOFF-my.log
RENAME SNDOFF.SAV SNDOFF-my.SAV
RENAME SNDOFF.MAP SNDOFF-my.MAP
RENAME SNDOFF.STB SNDOFF-my.STB
rem
echo SOKOBA
CD ..\SOKOBA
%PCLINK11% SOKOBA.OBJ SOKDAT.OBJ ALP.OBJ RALP.OBJ SOKMAZ.OBJ > SOKOBA-my.log
RENAME SOKOBA.SAV SOKOBA-my.SAV
RENAME SOKOBA.MAP SOKOBA-my.MAP
RENAME SOKOBA.STB SOKOBA-my.STB
rem
echo SOKOED
CD ..\SOKOED
%PCLINK11% SOKOED.OBJ SOKED.OBJ SOKDAT.OBJ > SOKOED-my.log
RENAME SOKOED.SAV SOKOED-my.SAV
RENAME SOKOED.MAP SOKOED-my.MAP
RENAME SOKOED.STB SOKOED-my.STB
rem
echo SPCINV
CD ..\SPCINV
%PCLINK11% SPCINV.OBJ > SPCINV-my.log
RENAME SPCINV.SAV SPCINV-my.SAV
RENAME SPCINV.MAP SPCINV-my.MAP
RENAME SPCINV.STB SPCINV-my.STB
rem
echo SPLIT-DSKMXC
CD ..\SPLIT-DSKMXC
%PCLINK11% SPLIT.OBJ > SPLIT-my.log
RENAME SPLIT.SAV SPLIT-my.SAV
RENAME SPLIT.MAP SPLIT-my.MAP
RENAME SPLIT.STB SPLIT-my.STB
rem
echo T401-1801BM1
CD ..\T401-1801BM1
%PCLINK11% T401.OBJ > T401-my.log
RENAME T401.SAV T401-my.SAV
RENAME T401.MAP T401-my.MAP
RENAME T401.STB T401-my.STB
rem
echo T402-1801BM1
CD ..\T402-1801BM1
%PCLINK11% T402.OBJ > T402-my.log
RENAME T402.SAV T402-my.SAV
RENAME T402.MAP T402-my.MAP
RENAME T402.STB T402-my.STB
rem
echo T404-1801BM1
CD ..\T404-1801BM1
%PCLINK11% T404.OBJ > T404-my.log
RENAME T404.SAV T404-my.SAV
RENAME T404.MAP T404-my.MAP
RENAME T404.STB T404-my.STB
rem
echo TEST-PASCAL
CD ..\TEST-PASCAL
%PCLINK11% TEST.OBJ PASCAL.OBJ > TEST-my.log
RENAME TEST.SAV TEST-my.SAV
RENAME TEST.MAP TEST-my.MAP
RENAME TEST.STB TEST-my.STB
rem
echo TSTPAL-01B
CD ..\TSPAL-01B
%PCLINK11% TSPAL.OBJ > TSPAL-my.log
RENAME TSPAL.SAV TSPAL-my.SAV
RENAME TSPAL.MAP TSPAL-my.MAP
RENAME TSPAL.STB TSPAL-my.STB
rem
echo TSTVM1-01A
CD ..\TSTVM1-01A
%PCLINK11% TSTVM1.OBJ > TSTVM1-my.log
RENAME TSTVM1.SAV TSTVM1-my.SAV
RENAME TSTVM1.MAP TSTVM1-my.MAP
RENAME TSTVM1.STB TSTVM1-my.STB
rem
echo TSTVM2-03A
CD ..\TSTVM2-03A
%PCLINK11% TSTVM2.OBJ > TSTVM2-my.log
RENAME TSTVM2.SAV TSTVM2-my.SAV
RENAME TSTVM2.MAP TSTVM2-my.MAP
RENAME TSTVM2.STB TSTVM2-my.STB
rem
echo TT-FD6W
CD ..\TT-FD6W
%PCLINK11% /EXECUTE:TT.SYS TT.OBJ /X > TT-my.log
RENAME TT.SYS TT-my.SAV
RENAME TT.MAP TT-my.MAP
RENAME TT.STB TT-my.STB
rem
echo TVE1-1801BM1
CD ..\TVE1-1801BM1
%PCLINK11% TVE1.OBJ > TVE1-my.log
RENAME TVE1.SAV TVE1-my.SAV
RENAME TVE1.MAP TVE1-my.MAP
RENAME TVE1.STB TVE1-my.STB
rem
echo UKFONT
CD ..\UKFONT
%PCLINK11% UKFONT.OBJ > UKFONT-my.log
RENAME UKFONT.SAV UKFONT-my.SAV
RENAME UKFONT.MAP UKFONT-my.MAP
RENAME UKFONT.STB UKFONT-my.STB
rem
echo VM-FD6W
CD ..\VM-FD6W
%PCLINK11% /EXECUTE:VM.SYS VM.OBJ /X > VM-my.log
RENAME VM.SYS VM-my.SAV
RENAME VM.MAP VM-my.MAP
RENAME VM.STB VM-my.STB
CD ..
