cmd_u-boot.lds := /home/taga/NuttX/brandy/u-boot-2014.07/../gcc-linaro/bin/arm-linux-gnueabi-gcc -E -Wp,-MD,./.u-boot.lds.d -D__KERNEL__ -DCONFIG_SYS_TEXT_BASE=0x4A000000    -march=armv7-a -Werror  -mno-unaligned-access -DCONFIG_ARM -D__ARM__ -marm -mno-thumb-interwork  -mabi=aapcs-linux  -mword-relocations  -ffunction-sections -fdata-sections -fno-common -ffixed-r9  -msoft-float  -pipe -Iinclude  -I/home/taga/NuttX/brandy/u-boot-2014.07/arch/arm/include -I/home/taga/NuttX/brandy/u-boot-2014.07/include/openssl  -nostdinc -isystem /home/taga/NuttX/brandy/gcc-linaro/bin/../lib/gcc/arm-linux-gnueabi/4.6.3/include -include /home/taga/NuttX/brandy/u-boot-2014.07/include/u-boot/u-boot.lds.h -DCPUDIR=arch/arm/cpu/armv7 -DBOOTADDR=0x4A000000  -ansi -D__ASSEMBLY__ -x assembler-with-cpp -P -o u-boot.lds /home/taga/NuttX/brandy/u-boot-2014.07/arch/arm/cpu/armv7/u-boot.lds

source_u-boot.lds := /home/taga/NuttX/brandy/u-boot-2014.07/arch/arm/cpu/armv7/u-boot.lds

deps_u-boot.lds := \
    $(wildcard include/config/sys/text/base.h) \
  /home/taga/NuttX/brandy/u-boot-2014.07/include/u-boot/u-boot.lds.h \

u-boot.lds: $(deps_u-boot.lds)

$(deps_u-boot.lds):
