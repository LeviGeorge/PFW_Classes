#!/bin/bash
set -u

user=$(whoami)
backupFile=./backup/project3_${user}.tar.gz

rm ${backupFile}
tar cvzf ${backupFile} ./project3
