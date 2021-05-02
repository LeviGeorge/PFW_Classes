#!/bin/bash

for filename in *
do
  grep "${filename}" exclude.txt >/dev/null
  if (( $? == 1 ))
  then
    echo ${filename}
  fi
done
