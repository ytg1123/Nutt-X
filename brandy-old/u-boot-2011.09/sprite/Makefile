#
# Copyright 2000-2008
# Wolfgang Denk, DENX Software Engineering, wd@denx.de.
#
# See file CREDITS for list of people who contributed to this
# project.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2 of
# the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston,
# MA 02111-1307 USA
#

include $(TOPDIR)/config.mk

LIB 	:= $(obj)libsprite.o

COBJS-y += sprite_verify.o
ifndef CONFIG_SUNXI_SPINOR_PLATFORM
COBJS-y	+= queue.o
COBJS-y += sprite_queue.o
COBJS-y += sprite_card.o
COBJS-y += encrypt/encrypt.o
COBJS-y += encrypt/twofish/twofish.o
COBJS-y += encrypt/twofish/twofish_new.o
COBJS-y += sparse/sparse.o
COBJS-y += sprite_download.o
COBJS-y += sprite_auto_update.o
COBJS-y += firmware/imgdecode.o
COBJS-y += sprite_privatedata.o
COBJS-y += sprite_main.o
COBJS-y += sprite_erase.o
COBJS-y += sprite_recovery.o
COBJS-y += sprite_led.o

COBJS-$(CONFIG_SUNXI_SECURE_STORAGE) += sprite_secstorage.o
COBJS-$(CONFIG_SUNXI_SECURE_STORAGE) += sprite_secure_object.o
COBJS-$(CONFIG_SUNXI_SECURE_SYSTEM) += sprite_storage_crypt.o
#COBJS-$(CONFIG_AUTO_UPDATE) += sprite_auto_update.o

endif
COBJS	:= $(COBJS-y)
SRCS	:= $(COBJS:.o=.c)
OBJS	:= $(addprefix $(obj),$(COBJS))

all:	$(LIB)

$(LIB):	$(obj).depend $(OBJS)
	$(call cmd_link_o_target, $(OBJS))


#########################################################################

# defines $(obj).depend target
include $(SRCTREE)/rules.mk

sinclude $(obj).depend

########################################################################
