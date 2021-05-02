#!/bin/bash
set -u
user=$1
backupFile=./backup/project3_${user}.tar.gz

rm ${backupFile}
tar cvzf ${backupFile} ./project3
