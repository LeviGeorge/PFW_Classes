#!/bin/bash
# the first line tells the interpreter for the script

# comments start with # and run to the end of the line

# creates a gzipped backup of project 3

rm ./backup/project3.tar.gz
tar cvzf ./backup/project3.tar.gz ./project3
