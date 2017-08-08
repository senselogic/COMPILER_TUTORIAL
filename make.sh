#!/bin/sh
set -x
flex *.l
bison -dty --report=all *.y
gcc -g3 -DDEBUG -c *.c
gcc -g3 -o pc *.o
rm *.o


