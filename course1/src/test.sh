#!/bin/sh
# References:
# - https://www.moreofless.co.uk/egrep-color-linux-shell-commands/

# *.o
echo "*.o"
make clean
make memory.o PLATFORM=HOST
make main.o PLATFORM=HOST
ls *.o | grep -E --color=always "."

make clean
make memory.o PLATFORM=MSP432
make main.o PLATFORM=MSP432
ls *.o | grep -E --color=always "."

# build 
echo "build"
make clean
make build PLATFORM=HOST
make c1m2.asm PLATFORM=HOST
ls *.out *.map *.o *.d *.asm | grep -E --color=always "."
make clean
make build PLATFORM=MSP432
make c1m2.asm PLATFORM=MSP32
ls *.out *.map *.o *.d *.asm | grep -E --color=always "."

# *.asm
echo "*.asm"
make clean
make memory.asm PLATFORM=HOST
make main.asm PLATFORM=HOST
ls *.asm | grep -E --color=always "."

make clean
make memory.asm PLATFORM=MSP432
make main.asm PLATFORM=MSP432
ls *.asm | grep -E --color=always "."

# %.i
echo "*.i"
make clean
make memory.i PLATFORM=HOST
make main.i PLATFORM=HOST
ls *.i | grep -E --color=always "."

make clean
make memory.i PLATFORM=MSP432
make main.i PLATFORM=MSP432
ls *.i | grep -E --color=always "."

# compile-all
echo "compile-all"
make compile-all
ls *.o | grep -E --color=always "."
make clean


