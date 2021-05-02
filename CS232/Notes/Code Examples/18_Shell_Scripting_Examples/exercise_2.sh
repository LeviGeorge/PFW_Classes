#!/bin/bash
set -u

dirList=$(cat includeDirs.txt)

for dir in ${dirList}
do
    fileList=$(ls ${dir}/*.txt)
    
    for file in ${fileList}
    do
        cat ${file}
    done
done
