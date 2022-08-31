#!/bin/sh
export PATH=/home/taga/NuttX/gcc-arm-none-eabi-8-2018-q4-major/bin:${PATH}
make distclean
tools/configure.sh -l pcduino-a10/nsh
make -j4
