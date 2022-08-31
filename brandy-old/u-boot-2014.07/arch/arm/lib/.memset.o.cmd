cmd_arch/arm/lib/memset.o := /home/taga/NuttX/brandy/u-boot-2014.07/../gcc-linaro/bin/arm-linux-gnueabi-gcc -Wp,-MD,arch/arm/lib/.memset.o.d  -nostdinc -isystem /home/taga/NuttX/brandy/gcc-linaro/bin/../lib/gcc/arm-linux-gnueabi/4.6.3/include -Iinclude  -I/home/taga/NuttX/brandy/u-boot-2014.07/arch/arm/include -I/home/taga/NuttX/brandy/u-boot-2014.07/include/openssl -D__KERNEL__ -DCONFIG_SYS_TEXT_BASE=0x4A000000  -D__ASSEMBLY__ -g       -march=armv7-a -Werror  -mno-unaligned-access -DCONFIG_ARM -D__ARM__ -marm -mno-thumb-interwork  -mabi=aapcs-linux  -mword-relocations  -ffunction-sections -fdata-sections -fno-common -ffixed-r9  -msoft-float  -pipe     -c -o arch/arm/lib/memset.o arch/arm/lib/memset.S

source_arch/arm/lib/memset.o := arch/arm/lib/memset.S

deps_arch/arm/lib/memset.o := \
  /home/taga/NuttX/brandy/u-boot-2014.07/arch/arm/include/asm/assembler.h \

arch/arm/lib/memset.o: $(deps_arch/arm/lib/memset.o)

$(deps_arch/arm/lib/memset.o):
