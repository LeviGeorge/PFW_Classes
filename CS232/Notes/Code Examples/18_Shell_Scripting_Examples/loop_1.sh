#!/bin/bash
set -u

for user in chenz user1 user2 user3
do
  backupFile=./backup/${user}.tar.gz

  rm ${backupFile}
  tar cvzf ${backupFile} ./users/${user}
done
