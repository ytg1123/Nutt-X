cmd_lib/libfdt/fdt_rw.o := /home/taga/NuttX/brandy/u-boot-2014.07/../gcc-linaro/bin/arm-linux-gnueabi-gcc -Wp,-MD,lib/libfdt/.fdt_rw.o.d  -nostdinc -isystem /home/taga/NuttX/brandy/gcc-linaro/bin/../lib/gcc/arm-linux-gnueabi/4.6.3/include -Iinclude  -I/home/taga/NuttX/brandy/u-boot-2014.07/arch/arm/include -I/home/taga/NuttX/brandy/u-boot-2014.07/include/openssl -D__KERNEL__ -DCONFIG_SYS_TEXT_BASE=0x4A000000 -Wall -Wstrict-prototypes -Wno-format-security -fno-builtin -ffreestanding -Os -fno-stack-protector -g -fstack-usage -Wno-format-nonliteral -march=armv7-a -Werror -mno-unaligned-access -DCONFIG_ARM -D__ARM__ -marm -mno-thumb-interwork -mabi=aapcs-linux -mword-relocations -ffunction-sections -fdata-sections -fno-common -ffixed-r9 -msoft-float -pipe    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(fdt_rw)"  -D"KBUILD_MODNAME=KBUILD_STR(fdt_rw)" -c -o lib/libfdt/fdt_rw.o lib/libfdt/fdt_rw.c

source_lib/libfdt/fdt_rw.o := lib/libfdt/fdt_rw.c

deps_lib/libfdt/fdt_rw.o := \
    $(wildcard include/config/sunxi/mulitcore/boot.h) \
    $(wildcard include/config/boot/gui.h) \
  include/libfdt_env.h \
  include/compiler.h \
  /home/taga/NuttX/brandy/gcc-linaro/bin/../lib/gcc/arm-linux-gnueabi/4.6.3/include/stddef.h \
  include/linux/string.h \
  include/linux/types.h \
    $(wildcard include/config/uid16.h) \
  include/linux/posix_types.h \
  include/linux/stddef.h \
  /home/taga/NuttX/brandy/u-boot-2014.07/arch/arm/include/asm/posix_types.h \
  /home/taga/NuttX/brandy/u-boot-2014.07/arch/arm/include/asm/types.h \
    $(wildcard include/config/arm64.h) \
  /home/taga/NuttX/brandy/gcc-linaro/bin/../lib/gcc/arm-linux-gnueabi/4.6.3/include/stdbool.h \
  /home/taga/NuttX/brandy/u-boot-2014.07/arch/arm/include/asm/string.h \
    $(wildcard include/config/use/arch/memcpy.h) \
    $(wildcard include/config/use/arch/memset.h) \
  include/config.h \
    $(wildcard include/config/sun8iw11p1.h) \
    $(wildcard include/config/sys/arch.h) \
    $(wildcard include/config/sys/cpu.h) \
    $(wildcard include/config/sys/board.h) \
    $(wildcard include/config/sys/vendor.h) \
    $(wildcard include/config/sys/soc.h) \
    $(wildcard include/config/boarddir.h) \
  include/config_cmd_defaults.h \
    $(wildcard include/config/cmd/defaults/h/.h) \
    $(wildcard include/config/cmd/bootm.h) \
    $(wildcard include/config/cmd/crc32.h) \
    $(wildcard include/config/cmd/exportenv.h) \
    $(wildcard include/config/cmd/go.h) \
    $(wildcard include/config/cmd/importenv.h) \
  include/config_defaults.h \
    $(wildcard include/config/defaults/h/.h) \
    $(wildcard include/config/bootm/linux.h) \
    $(wildcard include/config/bootm/netbsd.h) \
    $(wildcard include/config/bootm/plan9.h) \
    $(wildcard include/config/bootm/rtems.h) \
    $(wildcard include/config/bootm/vxworks.h) \
    $(wildcard include/config/gzip.h) \
    $(wildcard include/config/zlib.h) \
    $(wildcard include/config/partitions.h) \
  include/configs/sun8iw11p1.h \
    $(wildcard include/config/h.h) \
    $(wildcard include/config/mach/type.h) \
    $(wildcard include/config/sun8iw11p1/nor.h) \
    $(wildcard include/config/target/name.h) \
    $(wildcard include/config/sys/generic/board.h) \
    $(wildcard include/config/sunxi/wine/fpga.h) \
    $(wildcard include/config/allwinner.h) \
    $(wildcard include/config/sunxi.h) \
    $(wildcard include/config/arch/sun8iw11p1.h) \
    $(wildcard include/config/arm/a7.h) \
    $(wildcard include/config/sunxi/secure/storage.h) \
    $(wildcard include/config/sunxi/secure/system.h) \
    $(wildcard include/config/sunxi/hdcp/in/securestorage.h) \
    $(wildcard include/config/sys/sram/base.h) \
    $(wildcard include/config/sys/sram/size.h) \
    $(wildcard include/config/sys/srama3/base.h) \
    $(wildcard include/config/sys/srama3/size.h) \
    $(wildcard include/config/sys/srama4/base.h) \
    $(wildcard include/config/sys/srama4/size.h) \
    $(wildcard include/config/boot0/stack/bottom.h) \
    $(wildcard include/config/sys/text/base.h) \
    $(wildcard include/config/sys/sdram/base.h) \
    $(wildcard include/config/bootpkg/store/in/dram/base.h) \
    $(wildcard include/config/sunxi/fdt/addr.h) \
    $(wildcard include/config/sunxi/serial.h) \
    $(wildcard include/config/sys/init/ram/addr.h) \
    $(wildcard include/config/sys/init/ram/size.h) \
    $(wildcard include/config/sys/init/sp/offset.h) \
    $(wildcard include/config/sys/init/sp/addr.h) \
    $(wildcard include/config/nr/dram/banks.h) \
    $(wildcard include/config/noncache/memory.h) \
    $(wildcard include/config/noncache/memory/size.h) \
    $(wildcard include/config/sys/malloc/len.h) \
    $(wildcard include/config/env/size.h) \
    $(wildcard include/config/detect/rtc/boot/mode.h) \
    $(wildcard include/config/normal/debug/base.h) \
    $(wildcard include/config/membase.h) \
    $(wildcard include/config/sunxi/logbuffer.h) \
    $(wildcard include/config/boot0/ret/addr.h) \
    $(wildcard include/config/boot0/run/addr.h) \
    $(wildcard include/config/fes1/ret/addr.h) \
    $(wildcard include/config/fes1/run/addr.h) \
    $(wildcard include/config/sunxi/chipid.h) \
    $(wildcard include/config/sbromsw/base.h) \
    $(wildcard include/config/stack/base.h) \
    $(wildcard include/config/sys/srama2/base.h) \
    $(wildcard include/config/sys/srama2/size.h) \
    $(wildcard include/config/heap/base.h) \
    $(wildcard include/config/heap/size.h) \
    $(wildcard include/config/toc0/ret/addr.h) \
    $(wildcard include/config/toc0/run/addr.h) \
    $(wildcard include/config/toc0/config/addr.h) \
    $(wildcard include/config/addr.h) \
    $(wildcard include/config/toc1/store/in/dram/base.h) \
    $(wildcard include/config/display/cpuinfo.h) \
    $(wildcard include/config/display/boardinfo.h) \
    $(wildcard include/config/sys/ns16550.h) \
    $(wildcard include/config/sys/ns16550/serial.h) \
    $(wildcard include/config/sys/ns16550/reg/size.h) \
    $(wildcard include/config/sys/ns16550/clk.h) \
    $(wildcard include/config/sys/ns16550/com1.h) \
    $(wildcard include/config/sys/ns16550/com2.h) \
    $(wildcard include/config/sys/ns16550/com3.h) \
    $(wildcard include/config/sys/ns16550/com4.h) \
    $(wildcard include/config/ns16550/fifo/enable.h) \
    $(wildcard include/config/cons/index.h) \
    $(wildcard include/config/setup/memory/tags.h) \
    $(wildcard include/config/cmdline/tag.h) \
    $(wildcard include/config/initrd/tag.h) \
    $(wildcard include/config/cmdline/editing.h) \
    $(wildcard include/config/arp/timeout.h) \
    $(wildcard include/config/sys/longhelp.h) \
    $(wildcard include/config/sys/hush/parser.h) \
    $(wildcard include/config/sys/prompt/hush/ps2.h) \
    $(wildcard include/config/sys/prompt.h) \
    $(wildcard include/config/sys/cbsize.h) \
    $(wildcard include/config/sys/pbsize.h) \
    $(wildcard include/config/sys/maxargs.h) \
    $(wildcard include/config/sys/bargsize.h) \
    $(wildcard include/config/sys/memtest/start.h) \
    $(wildcard include/config/sys/memtest/end.h) \
    $(wildcard include/config/sys/load/addr.h) \
    $(wildcard include/config/sys/hz.h) \
    $(wildcard include/config/baudrate.h) \
    $(wildcard include/config/sys/baudrate/table.h) \
    $(wildcard include/config/sys/no/flash.h) \
    $(wildcard include/config/sys/monitor/len.h) \
    $(wildcard include/config/ident/string.h) \
    $(wildcard include/config/env/is/in/sunxi/flash.h) \
    $(wildcard include/config/sunxi/env/partition.h) \
    $(wildcard include/config/sunxi/nand/env/partition.h) \
    $(wildcard include/config/env/addr.h) \
    $(wildcard include/config/cmd/saveenv.h) \
    $(wildcard include/config/extra/env/settings.h) \
    $(wildcard include/config/sunxi/sprite/env/settings.h) \
    $(wildcard include/config/bootdelay.h) \
    $(wildcard include/config/bootcommand.h) \
    $(wildcard include/config/sys/boot/get/cmdline.h) \
    $(wildcard include/config/auto/complete.h) \
    $(wildcard include/config/dos/partition.h) \
    $(wildcard include/config/use/irq.h) \
    $(wildcard include/config/sunxi/dma.h) \
    $(wildcard include/config/of/libfdt.h) \
    $(wildcard include/config/of/control.h) \
    $(wildcard include/config/android/boot/image.h) \
    $(wildcard include/config/usbd/hs.h) \
    $(wildcard include/config/sunxi/key/burn.h) \
    $(wildcard include/config/sunxi/private/key.h) \
    $(wildcard include/config/sunxi/i2c.h) \
    $(wildcard include/config/cpux/i2c.h) \
    $(wildcard include/config/axp/use/i2c.h) \
    $(wildcard include/config/sys/i2c/speed.h) \
    $(wildcard include/config/sys/i2c/slave.h) \
    $(wildcard include/config/sunxi/key/support.h) \
    $(wildcard include/config/stacksize.h) \
    $(wildcard include/config/stacksize/irq.h) \
    $(wildcard include/config/stacksize/fiq.h) \
    $(wildcard include/config/sunxi/module/sprite.h) \
    $(wildcard include/config/sunxi/module/nand.h) \
    $(wildcard include/config/sunxi/module/sdmmc.h) \
    $(wildcard include/config/sunxi/module/spinor.h) \
    $(wildcard include/config/sunxi/module/axp.h) \
    $(wildcard include/config/sunxi/module/usb.h) \
    $(wildcard include/config/sunxi/module/display.h) \
    $(wildcard include/config/sunxi/module/hdmi.h) \
    $(wildcard include/config/sunxi/module/tv.h) \
    $(wildcard include/config/gpt/support.h) \
    $(wildcard include/config/sunxi/gpt.h) \
    $(wildcard include/config/efi/partition.h) \
    $(wildcard include/config/convert/card0/to/gpt.h) \
    $(wildcard include/config/cmd/boota.h) \
    $(wildcard include/config/cmd/run.h) \
    $(wildcard include/config/cmd/bootd.h) \
    $(wildcard include/config/cmd/fdt.h) \
    $(wildcard include/config/cmd/fat.h) \
    $(wildcard include/config/cmd/ext4.h) \
    $(wildcard include/config/cmd/irq.h) \
    $(wildcard include/config/cmd/elf.h) \
    $(wildcard include/config/cmd/memory.h) \
    $(wildcard include/config/cmd/fastboot.h) \
    $(wildcard include/config/cmd/sunxi/sprite.h) \
    $(wildcard include/config/cmd/sunxi/timer.h) \
    $(wildcard include/config/cmd/sunxi/efex.h) \
    $(wildcard include/config/cmd/sunxi/shutdown.h) \
    $(wildcard include/config/cmd/sunxi/bmp.h) \
    $(wildcard include/config/cmd/sunxi/burn.h) \
    $(wildcard include/config/cmd/sunxi/memtest.h) \
    $(wildcard include/config/auto/update.h) \
    $(wildcard include/config/storage/media/mmc.h) \
    $(wildcard include/config/mmc.h) \
    $(wildcard include/config/generic/mmc.h) \
    $(wildcard include/config/cmd/mmc.h) \
    $(wildcard include/config/mmc/sunxi.h) \
    $(wildcard include/config/mmc/sunxi/use/dma.h) \
    $(wildcard include/config/storage/emmc.h) \
    $(wildcard include/config/mmc/logical/offset.h) \
    $(wildcard include/config/storage/media/nand.h) \
    $(wildcard include/config/nand.h) \
    $(wildcard include/config/storage/nand.h) \
    $(wildcard include/config/nand/sunxi.h) \
    $(wildcard include/config/cmd/nand.h) \
    $(wildcard include/config/sys/max/nand/device.h) \
    $(wildcard include/config/sys/nand/base.h) \
    $(wildcard include/config/sunxi/display.h) \
    $(wildcard include/config/video/sunxi/v3.h) \
    $(wildcard include/config/sunxi/axp.h) \
    $(wildcard include/config/sunxi/axp22.h) \
    $(wildcard include/config/sunxi/axp20.h) \
    $(wildcard include/config/sunxi/axp/config/onoff.h) \
    $(wildcard include/config/onoff.h) \
    $(wildcard include/config/sunxi/spi.h) \
    $(wildcard include/config/sunxi/spinor.h) \
    $(wildcard include/config/spinor/logical/offset.h) \
    $(wildcard include/config/storage/media/spinor.h) \
    $(wildcard include/config/usb/ehci/sunxi.h) \
    $(wildcard include/config/ehci/dcache.h) \
    $(wildcard include/config/cmd/usb.h) \
    $(wildcard include/config/usb/storage.h) \
    $(wildcard include/config/usb/ehci.h) \
    $(wildcard include/config/usb/ether.h) \
    $(wildcard include/config/usb/eth/rndis.h) \
    $(wildcard include/config/usb/sunxi/udc0.h) \
    $(wildcard include/config/usb/gadget/dualspeed.h) \
    $(wildcard include/config/cmd/net.h) \
    $(wildcard include/config/net/multi.h) \
    $(wildcard include/config/cmd/ping.h) \
    $(wildcard include/config/cmd/nfs.h) \
    $(wildcard include/config/sys/dcache/off.h) \
    $(wildcard include/config/sunxi/geth.h) \
    $(wildcard include/config/sunxi/ext/phy.h) \
    $(wildcard include/config/cmd/mii.h) \
    $(wildcard include/config/ethaddr.h) \
    $(wildcard include/config/ipaddr.h) \
    $(wildcard include/config/serverip.h) \
    $(wildcard include/config/netmask.h) \
    $(wildcard include/config/gatewayip.h) \
    $(wildcard include/config/board/id/gpio.h) \
    $(wildcard include/config/board/id/gpio/max/num.h) \
  /home/taga/NuttX/brandy/u-boot-2014.07/arch/arm/include/asm/arch/platform.h \
  /home/taga/NuttX/brandy/u-boot-2014.07/arch/arm/include/asm/config.h \
    $(wildcard include/config/h/.h) \
    $(wildcard include/config/sys/generic/global/data.h) \
    $(wildcard include/config/lmb.h) \
    $(wildcard include/config/sys/boot/ramdisk/high.h) \
    $(wildcard include/config/phys/64bit.h) \
    $(wildcard include/config/static/rela.h) \
    $(wildcard include/config/fsl/lsch3.h) \
  include/config_fallbacks.h \
    $(wildcard include/config/fallbacks/h.h) \
    $(wildcard include/config/spl.h) \
    $(wildcard include/config/spl/pad/to.h) \
    $(wildcard include/config/spl/max/size.h) \
    $(wildcard include/config/fs/fat.h) \
    $(wildcard include/config/cmd/ext2.h) \
    $(wildcard include/config/fs/ext4.h) \
    $(wildcard include/config/cmd/ext4/write.h) \
    $(wildcard include/config/ext4/write.h) \
    $(wildcard include/config/cmd/ide.h) \
    $(wildcard include/config/cmd/sata.h) \
    $(wildcard include/config/cmd/scsi.h) \
    $(wildcard include/config/cmd/part.h) \
    $(wildcard include/config/cmd/gpt.h) \
    $(wildcard include/config/systemace.h) \
    $(wildcard include/config/sandbox.h) \
    $(wildcard include/config/partition/uuids.h) \
    $(wildcard include/config/random/uuid.h) \
    $(wildcard include/config/cmd/uuid.h) \
    $(wildcard include/config/bootp/pxe.h) \
    $(wildcard include/config/lib/uuid.h) \
    $(wildcard include/config/lib/rand.h) \
    $(wildcard include/config/lib/hw/rand.h) \
    $(wildcard include/config/api.h) \
    $(wildcard include/config/lcd.h) \
    $(wildcard include/config/cmd/bmp.h) \
    $(wildcard include/config/fit/signature.h) \
    $(wildcard include/config/image/format/legacy.h) \
    $(wildcard include/config/disable/image/legacy.h) \
  include/config_uncmd_spl.h \
    $(wildcard include/config/uncmd/spl/h//.h) \
    $(wildcard include/config/spl/build.h) \
    $(wildcard include/config/cmd/cdp.h) \
    $(wildcard include/config/cmd/dhcp.h) \
    $(wildcard include/config/cmd/dns.h) \
    $(wildcard include/config/cmd/link/local.h) \
    $(wildcard include/config/cmd/rarp.h) \
    $(wildcard include/config/cmd/sntp.h) \
    $(wildcard include/config/cmd/tftpput.h) \
    $(wildcard include/config/cmd/tftpsrv.h) \
  include/linux/linux_string.h \
  /home/taga/NuttX/brandy/u-boot-2014.07/arch/arm/include/asm/byteorder.h \
  include/linux/byteorder/little_endian.h \
  include/linux/compiler.h \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  include/linux/compiler-gcc4.h \
  include/linux/byteorder/swab.h \
  include/linux/byteorder/generic.h \
  include/linux/types.h \
  include/fdt.h \
  include/libfdt.h \
  lib/libfdt/libfdt_internal.h \

lib/libfdt/fdt_rw.o: $(deps_lib/libfdt/fdt_rw.o)

$(deps_lib/libfdt/fdt_rw.o):
