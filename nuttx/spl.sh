#!/bin/sh

sudo sunxi-fel spl sunxi-spl.bin
sudo sunxi-fel -v exec 0x4a000000

