#!/bin/bash
set -u

user=chenz
backupFile=./backup/${user}.tar.gz
rm ${backupFile}
tar cvzf ${backupFile} ./users/${user}

user=user1
backupFile=./backup/${user}.tar.gz
rm ${backupFile}
tar cvzf ${backupFile} ./users/${user}

user=user2
backupFile=./backup/${user}.tar.gz
rm ${backupFile}
tar cvzf ${backupFile} ./users/${user}

user=user3
backupFile=./backup/${user}.tar.gz
rm ${backupFile}
tar cvzf ${backupFile} ./users/${user}
