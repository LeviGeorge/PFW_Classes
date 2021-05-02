#!/bin/bash
set -u
for filename in ./project3/webSearchSol/searchFiles/*.txt
do
  numLines=$(wc --lines ${filename} | \
    awk '{ print $1 }')
  echo ${filename} has ${numLines} lines.
done
# Instead of looping, could just do wc --lines *.txt
