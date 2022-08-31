#!/bin/sh

make distclean
tools/configure.sh -l vividnode-a33/nsh
make menuconfig
