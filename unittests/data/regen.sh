#!/bin/sh
# Regenerate the .obj test fixtures from their .mac sources.
# Needs the macro11 cross-assembler (github.com/Rhialto/macro11) on PATH.
# The .obj files are committed so the tests themselves don't need macro11.
set -e
cd "$(dirname "$0")"
for src in *.mac; do
    name="${src%.mac}"
    macro11 -o "$name.obj" "$src"
done
ls -l *.obj
