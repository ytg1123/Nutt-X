cmd_arch/arm/lib/crt0_arm_efi.o := arm-none-eabi-gcc -Wp,-MD,arch/arm/lib/.crt0_arm_efi.o.d  -nostdinc -isystem /home/taga/NuttX/gcc-arm-none-eabi-8-2018-q4-major/bin/../lib/gcc/arm-none-eabi/8.2.1/include -Iinclude    -I./arch/arm/include -include ./include/linux/kconfig.h -D__KERNEL__ -D__UBOOT__ -D__ASSEMBLY__ -fno-PIE -g -DCONFIG_THUMB2_KERNEL -D__ARM__ -Wa,-mimplicit-it=always -mthumb -mthumb-interwork -mabi=aapcs-linux -mword-relocations -fno-pic -mno-unaligned-access -ffunction-sections -fdata-sections -fno-common -ffixed-r9 -msoft-float -pipe -march=armv7-a -D__LINUX_ARM_ARCH__=7 -mtune=generic-armv7-a -I./arch/arm/mach-sunxi/include   -c -o arch/arm/lib/crt0_arm_efi.o arch/arm/lib/crt0_arm_efi.S

source_arch/arm/lib/crt0_arm_efi.o := arch/arm/lib/crt0_arm_efi.S

deps_arch/arm/lib/crt0_arm_efi.o := \
  include/asm-generic/pe.h \

arch/arm/lib/crt0_arm_efi.o: $(deps_arch/arm/lib/crt0_arm_efi.o)

$(deps_arch/arm/lib/crt0_arm_efi.o):
