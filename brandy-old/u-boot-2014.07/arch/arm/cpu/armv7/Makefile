#
# (C) Copyright 2000-2003
# Wolfgang Denk, DENX Software Engineering, wd@denx.de.
#
# SPDX-License-Identifier:	GPL-2.0+
#

extra-y	:= start.o
extra-y	+= spare_head.o
extra-y	+= uboot_hash.o

obj-y	+= cache_v7.o

obj-y	+= cpu.o
obj-y	+= syslib.o

ifneq ($(CONFIG_AM43XX)$(CONFIG_AM33XX)$(CONFIG_OMAP44XX)$(CONFIG_OMAP54XX)$(CONFIG_TEGRA)$(CONFIG_MX6)$(CONFIG_TI81XX)$(CONFIG_AT91FAMILY)$(CONFIG_SUNXI),)
ifneq ($(CONFIG_SKIP_LOWLEVEL_INIT),y)
obj-y	+= lowlevel_init.o
endif
endif

ifneq ($(CONFIG_ARMV7_NONSEC)$(CONFIG_ARMV7_VIRT),)
obj-y	+= nonsec_virt.o
obj-y	+= virt-v7.o
endif

obj-$(CONFIG_KONA) += kona-common/
obj-$(CONFIG_OMAP_COMMON) += omap-common/
obj-$(CONFIG_SYS_ARCH_TIMER) += arch_timer.o
obj-$(CONFIG_TEGRA) += tegra-common/

ifneq (,$(filter s5pc1xx exynos,$(SOC)))
obj-y += s5p-common/
endif

subdir-ccflags-$(CONFIG_SUNXI_FINS_FUNC_ARMV7_DIR) += -finstrument-functions
