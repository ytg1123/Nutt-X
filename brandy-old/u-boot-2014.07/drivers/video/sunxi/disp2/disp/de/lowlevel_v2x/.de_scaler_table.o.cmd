cmd_drivers/video/sunxi/disp2/disp/de/lowlevel_v2x/de_scaler_table.o := /home/taga/NuttX/brandy/u-boot-2014.07/../gcc-linaro/bin/arm-linux-gnueabi-gcc -Wp,-MD,drivers/video/sunxi/disp2/disp/de/lowlevel_v2x/.de_scaler_table.o.d  -nostdinc -isystem /home/taga/NuttX/brandy/gcc-linaro/bin/../lib/gcc/arm-linux-gnueabi/4.6.3/include -Iinclude  -I/home/taga/NuttX/brandy/u-boot-2014.07/arch/arm/include -I/home/taga/NuttX/brandy/u-boot-2014.07/include/openssl -D__KERNEL__ -DCONFIG_SYS_TEXT_BASE=0x4A000000 -Wall -Wstrict-prototypes -Wno-format-security -fno-builtin -ffreestanding -Os -fno-stack-protector -g -fstack-usage -Wno-format-nonliteral -march=armv7-a -Werror -mno-unaligned-access -DCONFIG_ARM -D__ARM__ -marm -mno-thumb-interwork -mabi=aapcs-linux -mword-relocations -ffunction-sections -fdata-sections -fno-common -ffixed-r9 -msoft-float -pipe    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(de_scaler_table)"  -D"KBUILD_MODNAME=KBUILD_STR(de_scaler_table)" -c -o drivers/video/sunxi/disp2/disp/de/lowlevel_v2x/de_scaler_table.o drivers/video/sunxi/disp2/disp/de/lowlevel_v2x/de_scaler_table.c

source_drivers/video/sunxi/disp2/disp/de/lowlevel_v2x/de_scaler_table.o := drivers/video/sunxi/disp2/disp/de/lowlevel_v2x/de_scaler_table.c

deps_drivers/video/sunxi/disp2/disp/de/lowlevel_v2x/de_scaler_table.o := \
  drivers/video/sunxi/disp2/disp/de/lowlevel_v2x/de_scaler_table.h \

drivers/video/sunxi/disp2/disp/de/lowlevel_v2x/de_scaler_table.o: $(deps_drivers/video/sunxi/disp2/disp/de/lowlevel_v2x/de_scaler_table.o)

$(deps_drivers/video/sunxi/disp2/disp/de/lowlevel_v2x/de_scaler_table.o):
