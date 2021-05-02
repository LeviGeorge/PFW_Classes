#!/bin/bash
set -u
userList=$(cat users.txt)
for user in ${userList}
do
  if [[ "${user}" != "chenz" && \
        "${user}" != "root" ]]
  then
    backupFile=./backup/${user}.tar.gz
    rm ${backupFile}
    tar cvzf ${backupFile} ./users/${user}
  fi
done
