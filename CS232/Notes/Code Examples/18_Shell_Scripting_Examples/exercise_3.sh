#!/bin/bash
set -u

userList=$(cat users.txt)
rm fileList.txt
for user in ${userList}
do
  #find ./users/${user} -name "*.c" -print0 \
  #  | xargs -0 -I REPL echo ${user} REPL >>fileList.txt
  fileList=$(find ./users/${user} -name "*.c")
  for file in ${fileList}
  do
	 echo ${user} ${file} >>fileList.txt
  done
done
