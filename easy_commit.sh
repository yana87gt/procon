#!/bin/sh
TMP_NOW=`date '+%F(%a) %T'`
while getopts ":a" optKey; do
  case "$optKey" in
    a)
      git add .
      ;;
  esac
done
git commit -m "Updated at $TMP_NOW"
git push origin master
