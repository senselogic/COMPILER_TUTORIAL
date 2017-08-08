#!/bin/sh
set -x

for f in P/*.p;
    do
        ../pc $f >$f.pcode
    done;
