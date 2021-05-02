#!/bin/bash
set -u
for filename in ./wikipediaData/*.txt
do
  numLines=$(wc --lines ${filename} | \
    awk '{ print $1 }')

  if (( numLines >= 1500 ))
    # The $ is not needed with variables in (( ))
    #         except special variables like $?
  then
    echo ${filename} has WAY too many lines ${numLines}.
  elif (( ${numLines} > 1000 ))
  then
    # But the $ can be used anyway
    echo ${filename} has too many lines ${numLines}.
  fi
done  
