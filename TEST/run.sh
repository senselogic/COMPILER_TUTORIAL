#!/bin/sh
set -x

for file_path in *.p; do	
    ../pc "$file_path" >"${file_path%.*}.pcode"
done
