#!/bin/sh

sudo sunxi-fel -v version
sudo sunxi-fel -v write-with-progress 0x2000 fes1_sun8iw5p1.fex
sudo sunxi-fel -v exec 0x2000

