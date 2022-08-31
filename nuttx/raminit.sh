#!/bin/sh

sudo sunxi-fel -v version
sudo sunxi-fel -v write-with-progress 0x2000 fes1.fex
sudo sunxi-fel -v exec 0x2000

