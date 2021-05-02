#!/bin/bash
set -u
for filename in ./project3/webSearchSol/urlFiles/*.txt
do
  dirpart=$(dirname ${filename})
  namepart=$(basename ${filename} .txt)
  cp ${filename} ${dirpart}/${namepart}.bak
done
