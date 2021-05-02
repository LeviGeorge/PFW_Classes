#!/bin/bash
set -u
logFile=backup.log
userList=$(cat users.txt)
echo "Backup log for "$(date) >${logFile}
for user in ${userList}
do
  backupFile=./backup/${user}.tar.gz
  rm ${backupFile}
  echo "***   ${user}   ***" >>${logFile}
  tar cvzf ${backupFile} ./users/${user} >>${logFile} 2>&1
done
