#!/bin/sh
TMP_NOW=`date '+%F(%a) %T'`
git add .
git commit -m "Updated at $TMP_NOW"
git push origin master