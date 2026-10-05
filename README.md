# pclink11
[![License: LGPL v3](https://img.shields.io/badge/License-LGPL%20v3-blue.svg)](https://www.gnu.org/licenses/lgpl-3.0)
[![Build status](https://ci.appveyor.com/api/projects/status/3lt4c9rxx2bv0g0g?svg=true)](https://ci.appveyor.com/project/nzeemin/pclink11)
[![Build Status](https://travis-ci.org/nzeemin/pclink11.svg?branch=master)](https://travis-ci.org/nzeemin/pclink11)
[![CodeFactor](https://www.codefactor.io/repository/github/nzeemin/pclink11/badge)](https://www.codefactor.io/repository/github/nzeemin/pclink11)

Attempt to port PDP-11 LINKer to PC C/C++ — learning how the linker works, the hard way.

The code (partially) ported from MACRO-11 sources to C/C++.
Port source: RT-11 LINK V05.45.

## Status: Work in Progress 🚧

Currently the PCLINK11 links most of test OBJ files properly, but we have some troubles linking tests with libraries.

## Usage
The source code is able to compile under Windows (VS2013), and also under Linux/MacOS (gcc/clang, use the Makefile).

Command line:

`pclink11 <input files and options>`

Options (both `/` and `-` prefixes are allowed):
- `/EXECUTE:filespec` — Specifies the name of the memory image file
- `/NOBITMAP` `/X` — Do not emit bit map
- `/WIDE` `/W` — Produces a load map that is 132-columns wide
- `/ALPHABETIZE` `/A` — Lists global symbols on the link map in alphabetical order
- `/SYMBOLTABLE` `/STB` — Generates a symbol table file (.STB file)
- `/MAP` — Generates map file
- `/BIN` — Generates `.bin` memory image (load address, byte count, data) instead of `.SAV`
- `/LDA` — Generates absolute loader (paper tape) `.LDA` file instead of `.SAV`: one block per run of loaded bytes, then the transfer address block (odd if `.END` gives no start address)
- `--version` — Show the program version information
- `--help` — Show quick help on the command line options

Input files and options are space-separated.

Examples:
- `pclink11 HELLO.OBJ` — link the object file, will produce `HELLO.SAV` executable
- `pclink11 /MAP /SYMBOLTABLE /EXECUTE:LD.SYS LD.OBJ SYSLIB.OBJ /X` — link object file with system library, produce map file and symbol file, save output as `LD.SYS`, do not put bitmap in the first block
- `pclink11 TEST1.OBJ TEST2.OBJ /MAP /WIDE /A` — link two object files, generate map file with wide format, alphabetize list of symbols

## Unit Tests
Folder `unittests` contains GoogleTest unit tests (needs GoogleTest 1.17+ and CMake):
- `test_options` — command line option parsing, including error cases;
- `test_lda` — end-to-end checks of `/LDA` output for the `.obj` fixtures in `unittests/data`
  (format, checksums, block layout, transfer address, and loaded bytes equal to the `.SAV` image).

```
cmake -S . -B build-tests -DPCLINK11_TESTS=ON    # add -DCMAKE_PREFIX_PATH=/opt/local for MacPorts GTest
cmake --build build-tests
cd build-tests && ctest --output-on-failure
```

The fixtures' MACRO-11 sources are in `unittests/data/*.mac`; `unittests/data/regen.sh` rebuilds
 the `. obj` files with `macro11`.

## Testing Strategy
Folder `tests` contains several dozens sub-folders with .OBJ files.

First, we use [RT-11 simulator](http://emulator.pdp-11.org.ru/RT-11/distr/) written by Dmitry Patronov to produce "etalon"/"original" output files, they renamed with `-11` suffix — see `!runtest11.cmd` command file.
Then, we run the `pclink11` with to produce "our" output files, they renamed with `-my` suffix — see `!runtestmy.cmd` command file and `testrunner` utility.
And finally, we compare "original" files with "our" files, line-to-line or byte-to-byte, using `testanalyzer` utility.

"Our" MAP files differs in the first line (program name, date/time, no page number), and there's no paging, so no page header lines.
SAV/SYS/REL and STB files are binary, compared byte-to-byte, should be no differences.
Log files are absolutely different, we're not comparing them, but in "our" log files we're looking for "SUCCESS"/"ERROR" and so on.

## TODO

First priority:
- Fix bugs for the failing test cases
 
Second priority:
- Need more tests, currently we have 115 test cases
- Reduce amount of logging, add option for verbosity level
- Process other command-line options, including file-specific ones

Not implemented now, and not sure we will:
- Link for foreground execution with /R or /FOREGROUND option, produce .REL file
- LDA output — produce a file in absolute binary loader format
- Overlays
- Linkage with separated instructions/data spaces

## Links
- [DEC-11-ZLDA-D PDP-11 LINK-11 Linker and LIBR-11 Librarian May71](https://archive.org/details/bitsavers_decpdp11do11LINK11LinkerandLIBR11LibrarianMay71_1259623)
- [macro-11 - cross-assembler by Richard Krehbiel](https://github.com/simh/simtools/tree/master/crossassemblers/macro11)
