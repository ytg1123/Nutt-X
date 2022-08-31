#!/bin/sh
export PATH=/home/taga/NuttX/gcc-arm-none-eabi-8-2018-q4-major/bin:${PATH}
make distclean
tools/configure.sh -l vividnode-a33/nsh
make menuconfig
make -j4
