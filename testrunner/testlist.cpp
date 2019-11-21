// testdest.cpp : Test list.
//

#include "testrunner.h"

const TestDescriptor g_Tests[] =
{
    /* directory           name        commandline */
    { "ADD32-PATRON",     "ADD32",    "/SYMBOLTABLE /MAP ADD32.OBJ" },
    { "ASHC4",            "ASHC4",    "/SYMBOLTABLE /MAP ASHC4.OBJ" },
    { "BATCH-V14",        "BATCH",    "/SYMBOLTABLE /MAP BATCH.OBJ" },
    { "BIRITM-FORTRANIV", "BIRITM",   "/SYMBOLTABLE /MAP BIRITM.OBJ FORLIB.OBJ SYSLIB.OBJ" },
    { "CPS-PATRON",       "CPS",      "/SYMBOLTABLE /MAP CPS.OBJ" },
    { "CPS2-PATRON",      "CPS2",     "/SYMBOLTABLE /MAP CPS2.OBJ" },
    { "CLINE-UKNC",       "CLINE",    "/SYMBOLTABLE /MAP CLINE.OBJ CENV.OBJ CWENV.OBJ CSPR.OBJ CKING.OBJ" },
    { "CLINE-UKNC-2",     "CLINE",    "/SYMBOLTABLE /MAP CLINE.OBJ CWENV.OBJ CENV.OBJ CSPR.OBJ CKING.OBJ" },
    { "DATIME",           "DATIME",   "/SYMBOLTABLE /MAP DATIME.OBJ" },
    { "DEMO-FORTRANIV",   "DEMO",     "/SYMBOLTABLE /MAP DEMO.OBJ FORLIB.OBJ" },
    { "DEMO2-FORTRANIV",  "DEMO2",    "/SYMBOLTABLE /MAP DEMO2.OBJ FORLIB.OBJ" },
    { "DISSAV-DBIT",      "DISSAV",   "/SYMBOLTABLE /MAP DISSAV.OBJ" },
    { "DW-ANDREY",        "DW",       "/SYMBOLTABLE /MAP /EXECUTE:DW.SYS DW.OBJ /X" },
    { "DW-FD6W",          "DW",       "/SYMBOLTABLE /MAP /EXECUTE:DW.SYS DW.OBJ /X" },
    { "DWKQOBJ-HOBOT",    "DWKQCO",   "/SYMBOLTABLE /MAP DWKQCO.OBJ PASDWK.OBJ" },
    { "DWOPT",            "DWOPT",    "/SYMBOLTABLE /MAP DWOPT.OBJ" },
    { "DX-0517",          "DX",       "/SYMBOLTABLE /MAP /EXECUTE:DX.SYS DX.OBJ /X" },
    { "DYABIN-novay_kopiya_161", "F", "/SYMBOLTABLE /MAP /EXECUTE:F.SAV TEKLIB.LIB FK.OBJ FP.OBJ DPSP.OBJ PMAG.OBJ TEKDAT.OBJ FKP.OBJ F100.OBJ FKL.OBJ FDKL.OBJ FD.OBJ FD1.OBJ FDM.OBJ FDD.OBJ FKFO.OBJ PSDISK.OBJ MAG.OBJ TEKCOD.OBJ F160.OBJ FPM.OBJ FPM1.OBJ FLT.OBJ TSTHLT.OBJ FPM2.OBJ FSM.OBJ FDP.OBJ TESTUK.OBJ FNK.OBJ" },
    { "EDINST-V2-17-NYS", "EDINST",   "/SYMBOLTABLE /MAP EDINST.OBJ VER.OBJ" },
    { "ELCOPY-FD6W",      "ELCOPY",   "/SYMBOLTABLE /MAP ELCOPY.OBJ ELTASK.OBJ" },
    { "ELINIT-FD6W",      "ELINIT",   "/SYMBOLTABLE /MAP ELINIT.OBJ" },
    { "EMPIRE-WBRIGHT",   "EMPIRE",   "/SYMBOLTABLE /MAP /EXECUTE:EMPIRE.SAV VAR.OBJ EMPIRE.OBJ MOVE2.OBJ SUB1.OBJ TTY.OBJ HMOVE.OBJ HMOVE2.OBJ PATH.OBJ CITY.OBJ SUB2.OBJ MAPS.OBJ CMOVE.OBJ CMOVE2.OBJ ARMYMV.OBJ FIGHMV.OBJ SHIPMV.OBJ SECTOR.OBJ MOVE.OBJ IOMOD.OBJ INIT.OBJ" },
    { "EXPRES-24",        "EXPRES",   "/SYMBOLTABLE /MAP EXPRES.OBJ" },
    { "EXPRES-BK-12",     "EXPRES",   "/SYMBOLTABLE /MAP EXPRES.OBJ" },
    { "EMUL-DISK25",      "EMUL",     "/SYMBOLTABLE /MAP EMUL.OBJ" },
    { "F4V28-LTHR",       "FORTRA",   "/SYMBOLTABLE /MAP /EXECUTE:FORTRA.SAV FROOT.OBJ F0.OBJ INLINE.OBJ F1.OBJ F2.OBJ F3.OBJ F4.OBJ F5.OBJ F6.OBJ F7.OBJ F8.OBJ F9.OBJ F10.OBJ LOOP.OBJ F11.OBJ F12.OBJ F13.OBJ F14.OBJ F15.OBJ F16.OBJ F17.OBJ CDUMP.OBJ" },
    { "FCU",              "FCU",      "/SYMBOLTABLE /MAP FCU.OBJ FCUE.OBJ FCUMNG.OBJ FCUD.OBJ SELF.OBJ" },
    { "FDTVER-FORTRANIV", "FDTVER",   "/SYMBOLTABLE /MAP FDTVER.OBJ FORLIB.OBJ" },
    { "FIG-FORTH-1-3",    "FORTH",    "/SYMBOLTABLE /MAP FORTH.OBJ" },
    { "GAD2-HOBOT",       "GAD2",     "/SYMBOLTABLE /MAP GAD2.OBJ" },
    { "GRAFOR-DEMO-FORTRANIV", "DEMO", "/SYMBOLTABLE /MAP DEMO.OBJ ENDPG.OBJ PAGE.OBJ GRAFOR.OBJ FORLIB.OBJ" },
    { "GRAFOR-MOVE-FORTRANIV", "MOVE", "/SYMBOLTABLE /MAP MOVE.OBJ GRAFOR.OBJ FORLIB.OBJ" },
    { "HAND-11",          "HAND",     "/SYMBOLTABLE /MAP HAND.OBJ" },
    { "HANDLE-503",       "HANDLE",   "/SYMBOLTABLE /MAP HANDLE.OBJ" },
    { "HD-DVKEmulator",   "HD",       "/SYMBOLTABLE /MAP /EXECUTE:HD.SYS HD.OBJ /X" },
    { "HELLO",            "HELLO",    "/SYMBOLTABLE /MAP HELLO.OBJ" },
    { "HWYENC-62",        "HWYENC",   "/SYMBOLTABLE /MAP HWYENC.OBJ" },
    { "INTERFACE-DISK02", "IF",       "/SYMBOLTABLE /MAP IF.OBJ IFMAIN.OBJ IFCOPY.OBJ IFTRP.OBJ IFSPEC.OBJ IFPP.OBJ" },
    { "KVANT4C-181ROM-NOSTB", "181",  "/MAP /EXECUTE:181.SAV /NOBITMAP /M:0 /B:20000 /T:0 181.OBJ" },
    { "LD-FD6W",          "LD",       "/SYMBOLTABLE /MAP /EXECUTE:LD.SYS LD.OBJ SYSLIB.OBJ /X" },
    { "LZSAV",            "LZSAV",    "/SYMBOLTABLE /MAP LZSAV.OBJ" },
    { "LP-DISK09",        "LP",       "/SYMBOLTABLE /MAP /EXECUTE:LP.SYS LP.OBJ /X" },
    { "MAIN-50",          "MAIN",     "/SYMBOLTABLE /MAP MAIN.OBJ LEVELS.OBJ" },
    { "MUL",              "MUL",      "/SYMBOLTABLE /MAP MUL.OBJ" },
    { "MY304",            "MY",       "/EXECUTE:MY.SYS MY.OBJ /SYMBOLTABLE /MAP /X" },
    { "MYTEST1",          "MYTST1",   "/SYMBOLTABLE /MAP MYTST1.OBJ OTHER.OBJ" },
    { "MYTEST2",          "MYTST2",   "/SYMBOLTABLE /MAP MYTST2.OBJ OTHER.OBJ" },
    { "MYTEST3",          "MYTST3",   "/SYMBOLTABLE /MAP MYTST3.OBJ OTHER.OBJ" },
    { "MYTEST3-ALPHAMAP", "MYTST3",   "/SYMBOLTABLE /MAP /ALPHABETIZE MYTST3.OBJ OTHER.OBJ" },
    { "MYTEST3-NOMAP",    "MYTST3",   "/SYMBOLTABLE MYTST3.OBJ OTHER.OBJ" },
    { "MYTEST3-NOSTB",    "MYTST3",   "/MAP MYTST3.OBJ OTHER.OBJ" },
    { "MYTEST3-WIDEMAP",  "MYTST3",   "/SYMBOLTABLE /MAP /WIDE MYTST3.OBJ OTHER.OBJ" },
    { "NET-DISK09",       "NET",      "/SYMBOLTABLE /MAP NET.OBJ" },
    { "NETTST-DISK09",    "NETTST",   "/SYMBOLTABLE /MAP NETTST.OBJ" },
    { "NL-FD6W",          "NL",       "/SYMBOLTABLE /MAP /EXECUTE:NL.SYS NL.OBJ /X" },
    { "PAKDMP-PHOOKY",    "PAKDMP",   "/SYMBOLTABLE /MAP PAKDMP.OBJ" },
    { "PAKWRT-PHOOKY",    "PAKWRT",   "/SYMBOLTABLE /MAP PAKWRT.OBJ" },
    { "PC20-PAF40",       "PAF40",    "/EXECUTE:PAF40.SAV /SYMBOLTABLE /MAP DIR40.OBJ PAF40.OBJ" },
    { "PC20-PAF80",       "PAF80",    "/EXECUTE:PAF80.SAV /SYMBOLTABLE /MAP DIR80.OBJ PAF80.OBJ" },
    { "PCBUG-1801BM1",    "PCBUG",    "/SYMBOLTABLE /MAP PCBUG.OBJ" },
    { "PCM-DISK09",       "PCM",      "/SYMBOLTABLE /MAP PCM.OBJ" },
    { "PDPCLK",           "PDPCLK",   "/SYMBOLTABLE /MAP PDPCLK.OBJ" },
    { "PEEKPOKE-FORTRANIV", "PEKPOK", "/SYMBOLTABLE /MAP PEKPOK.OBJ FORLIB.OBJ SYSLIB.OBJ" },
    { "PIFPAF",           "PIFPAF",   "/SYMBOLTABLE /MAP PIFPAF.OBJ" },
    { "PITEST-1801BM1",   "PITEST",   "/SYMBOLTABLE /MAP PITEST.OBJ" },
    { "PLOT-FORTRANIV",   "PLOT",     "/SYMBOLTABLE /MAP PLOT.OBJ PIX.OBJ FORLIB.OBJ" },
    { "PRIM-FORTRANIV",   "PRIM",     "/SYMBOLTABLE /MAP PRIM.OBJ FORLIB.OBJ" },
    { "PPTEST-REL",       "PPTEST",   "/R /SYMBOLTABLE /MAP PPTEST.OBJ" },
    { "RDMTUN-DSKMXC",    "RDMTUN",   "/SYMBOLTABLE /MAP RDMTUN.OBJ SYSLIB.OBJ" },
    { "REGCOP-ODE11",     "REGCOP",   "/SYMBOLTABLE /MAP REGCOP.OBJ" },
    { "REGPER-ODE11",     "REGPER",   "/SYMBOLTABLE /MAP REGPER.OBJ" },
    { "RTS",              "RTS",      "/SYMBOLTABLE /MAP RTS.OBJ" },
    { "RTLEM",            "RTLEM",    "/SYMBOLTABLE /MAP RTLEM.OBJ" },
    { "SATMON-HADI3DSK",  "SATMON",   "/SYMBOLTABLE /MAP SATMON.OBJ" },
    { "SFUN-SCHORS",      "SFUN",     "/EXECUTE:SFUN.SAV /SYMBOLTABLE /MAP FASIN.OBJ FATAN.OBJ FATAN2.OBJ FCOS.OBJ FFABS.OBJ FSQRT.OBJ FTAN.OBJ LBSC.OBJ" },
    { "SNDOFF-ANDREY14",  "SNDOFF",   "/SYMBOLTABLE /MAP SNDOFF.OBJ" },
    { "SOKOBA",           "SOKOBA",   "/SYMBOLTABLE /MAP SOKOBA.OBJ SOKDAT.OBJ ALP.OBJ RALP.OBJ SOKMAZ.OBJ" },
    { "SOKOED",           "SOKOED",   "/SYMBOLTABLE /MAP SOKOED.OBJ SOKED.OBJ SOKDAT.OBJ" },
    { "SPCINV",           "SPCINV",   "/SYMBOLTABLE /MAP SPCINV.OBJ" },
    { "SPLIT-DSKMXC",     "SPLIT",    "/SYMBOLTABLE /MAP SPLIT.OBJ" },
    { "T401-1801BM1",     "T401",     "/SYMBOLTABLE /MAP T401.OBJ" },
    { "T402-1801BM1",     "T402",     "/SYMBOLTABLE /MAP T402.OBJ" },
    { "T404-1801BM1",     "T404",     "/SYMBOLTABLE /MAP T404.OBJ" },
    { "TEST-PASCAL",      "TEST",     "/SYMBOLTABLE /MAP TEST.OBJ PASCAL.OBJ" },
    { "TPF-FORTRANIV",    "TPF",      "/SYMBOLTABLE /MAP TPF.OBJ GRAFOR.OBJ FORLIB.OBJ" },
    { "TPK-FORTRANIV",    "TPK",      "/SYMBOLTABLE /MAP TPK.OBJ FORLIB.OBJ" },
    { "TSPAL-01B",        "TSPAL",    "/SYMBOLTABLE /MAP TSPAL.OBJ" },
    { "TSTVM1-01A",       "TSTVM1",   "/SYMBOLTABLE /MAP TSTVM1.OBJ" },
    { "TSTVM2-03A",       "TSTVM2",   "/SYMBOLTABLE /MAP TSTVM2.OBJ" },
    { "TT-FD6W",          "TT",       "/SYMBOLTABLE /MAP /EXECUTE:TT.SYS TT.OBJ /X" },
    { "TVE1-1801BM1",     "TVE1",     "/SYMBOLTABLE /MAP TVE1.OBJ" },
    { "UCL-HOBOT",        "UCL",      "/SYMBOLTABLE /MAP UCL.OBJ" },
    { "UKFONT",           "UKFONT",   "/SYMBOLTABLE /MAP UKFONT.OBJ" },
    { "UKROM",            "UKROM",    "/SYMBOLTABLE /MAP UKROM.OBJ" },
    { "VM-FD6W",          "VM",       "/SYMBOLTABLE /MAP /EXECUTE:VM.SYS VM.OBJ /X" },
};
const int g_TestNumber = sizeof(g_Tests) / sizeof(g_Tests[0]);
