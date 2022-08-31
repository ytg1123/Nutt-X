cmd_nand_sunxi/sun8iw11p1/osal/nand_lib_cfg.o := /home/taga/NuttX/brandy/u-boot-2014.07/../gcc-linaro/bin/arm-linux-gnueabi-gcc -Wp,-MD,nand_sunxi/sun8iw11p1/osal/.nand_lib_cfg.o.d  -nostdinc -isystem /home/taga/NuttX/brandy/gcc-linaro/bin/../lib/gcc/arm-linux-gnueabi/4.6.3/include -Iinclude  -I/home/taga/NuttX/brandy/u-boot-2014.07/arch/arm/include -I/home/taga/NuttX/brandy/u-boot-2014.07/include/openssl -D__KERNEL__ -DCONFIG_SYS_TEXT_BASE=0x4A000000 -Wall -Wstrict-prototypes -Wno-format-security -fno-builtin -ffreestanding -Os -fno-stack-protector -g -fstack-usage -Wno-format-nonliteral -march=armv7-a -Werror -mno-unaligned-access -DCONFIG_ARM -D__ARM__ -marm -mno-thumb-interwork -mabi=aapcs-linux -mword-relocations -ffunction-sections -fdata-sections -fno-common -ffixed-r9 -msoft-float -pipe    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(nand_lib_cfg)"  -D"KBUILD_MODNAME=KBUILD_STR(nand_lib_cfg)" -c -o nand_sunxi/sun8iw11p1/osal/nand_lib_cfg.o nand_sunxi/sun8iw11p1/osal/nand_lib_cfg.c

source_nand_sunxi/sun8iw11p1/osal/nand_lib_cfg.o := nand_sunxi/sun8iw11p1/osal/nand_lib_cfg.c

deps_nand_sunxi/sun8iw11p1/osal/nand_lib_cfg.o := \

nand_sunxi/sun8iw11p1/osal/nand_lib_cfg.o: $(deps_nand_sunxi/sun8iw11p1/osal/nand_lib_cfg.o)

$(deps_nand_sunxi/sun8iw11p1/osal/nand_lib_cfg.o):
