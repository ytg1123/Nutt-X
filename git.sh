#!/bin/bash
set -e
git init
git remote add origin git@github.com:ytg1123/Nutt_X.git
git add .
git commit -m "Update Commit For nuttx source  `date '+%F(%H:%M)'` "
git push -u origin --all
