#!/bin/sh

make distclean
tools/configure.sh -l cubieboard-a10/nsh
make menuconfig
