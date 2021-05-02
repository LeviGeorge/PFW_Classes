#!/bin/bash
set -u
userList=$(cat users.txt)
for user in ${userList}
do
  backupFile=./backup/${user}.tar.gz

  rm ${backupFile}
  tar cvzf ${backupFile} ./users/${user}
done
