#!/bin/bash
set -u

user=chenz
backupFile=./backup/project3_${user}.tar.gz

# creates a gzipped backup of project 3
rm ${backupFile}
tar cvzf ${backupFile} ./project3
