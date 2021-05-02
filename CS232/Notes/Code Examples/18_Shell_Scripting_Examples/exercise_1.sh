#!/bin/bash
set -u

theDate=$(date +"%b %d")
ls -altr | grep "${theDate}" | awk '{ print $9 }'
