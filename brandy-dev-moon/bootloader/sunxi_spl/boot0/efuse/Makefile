
##
## Makefile for Sunxi Secure Boot
##



include $(TOPDIR)/config.mk

LIB	:= $(obj)libcid.o

COBJS += efuse.o

SOBJS   := $(SOBJS)
COBJS	:= $(COBJS)
SRCS	:= $(SOBJS:.o=.S) $(COBJS:.o=.c)
OBJS	:= $(addprefix $(obj),$(COBJS) $(SOBJS))

all:	$(LIB)

$(LIB):	$(obj).depend $(OBJS)
	$(call cmd_link_o_target, $(OBJS))

#########################################################################

# defines $(obj).depend target
include $(SRCTREE)/rules.mk

sinclude $(obj).depend

#########################################################################
