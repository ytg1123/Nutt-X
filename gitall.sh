#!/bin/bash
set -e
git add .
git commit -m "Update Commit For nuttx source  `date '+%F(%H:%M)'` "
git push -f -u origin --all

