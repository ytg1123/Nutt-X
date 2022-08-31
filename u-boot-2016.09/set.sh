#!/bin/sh

export PATH=/home/taga/NuttX/gcc-arm-none-eabi-8-2018-q4-major/bin:${PATH}
make distclean
make Vividnode_defconfig ARCH=arm CROSS_COMPILE=arm-none-eabi-
make ARCH=arm CROSS_COMPILE=arm-none-eabi-
