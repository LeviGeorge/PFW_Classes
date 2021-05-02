#!/bin/bash
set -u

backupFile=./backup/project3.tar.gz

# creates a gzipped backup of project 3

rm ${backupFile}
tar cvzf ${backupFile} ./project3
