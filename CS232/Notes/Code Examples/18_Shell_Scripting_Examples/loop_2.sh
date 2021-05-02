#!/bin/bash
set -u

#notice: no $ before variables in the (( ... ))
for (( i=1; i<=3; i++ ))
do
  # but we use ${i} outside the (( ... ))
  user=user${i}
  backupFile=./backup/${user}.tar.gz

  rm ${backupFile}
  tar cvzf ${backupFile} ./users/${user}
done
