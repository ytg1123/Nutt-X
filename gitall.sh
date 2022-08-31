#!/bin/bash
set -e
rm -rf .git_credentials
git add .
git commit -m "Update Commit For nuttx source  `date '+%F(%H:%M)'` "
git push -f -u origin --all

