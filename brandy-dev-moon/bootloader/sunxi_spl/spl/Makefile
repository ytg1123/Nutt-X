#
# (C) Copyright 2000-2011
# Wolfgang Denk, DENX Software Engineering, wd@denx.de.
#
# (C) Copyright 2011
# Daniel Schwierzeck, daniel.schwierzeck@googlemail.com.
#
# (C) Copyright 2011
# Texas Instruments Incorporated - http://www.ti.com/
# Aneesh V <aneesh@ti.com>
#
# This file is released under the terms of GPL v2 and any later version.
# See the file COPYING in the root directory of the source tree for details.
#
# Based on top-level Makefile.
#

include $(TOPDIR)/config.mk

CONFIG_SPL := y
export CONFIG_SPL

# We want the final binaries in this directory
obj := $(SPLBASE)/sunxi_spl/spl/


LIBS-y += $(OBJTREE)/arch/$(ARCH)/cpu/$(CPU)/$(SOC)/spl/libsource_spl.o
LIBS-$(CONFIG_STORAGE_MEDIA_MMC) += arch/$(ARCH)/cpu/$(CPU)/$(SOC)/mmc/libmmc.o
LIBS-$(CONFIG_STORAGE_MEDIA_NAND) += arch/$(ARCH)/cpu/$(CPU)/$(SOC)/nand/libnand.o
LIBS-y += arch/$(ARCH)/cpu/$(CPU)/$(SOC)/dram/libdram.o
LIBS-$(CONFIG_SUNXI_CHIPID) += arch/$(ARCH)/cpu/$(CPU)/$(SOC)/dram/libchipid.o
LIBS-y +=  $(SPLBASE)/sunxi_spl/spl/lib/libgeneral.o

LIBS := $(addprefix $(OBJTREE)/,$(sort $(LIBS-y)))

ALL-y	+= $(obj)libspl.o

all:	$(ALL-y)

$(obj)libspl.o: depend $(LIBS)

$(LIBS):	depend
	$(MAKE) -C $(SRCTREE)$(dir $(subst $(OBJTREE),,$@))

depend:	$(obj).depend
.PHONY: depend

# defines $(obj).depend target
include $(SRCTREE)/rules.mk
