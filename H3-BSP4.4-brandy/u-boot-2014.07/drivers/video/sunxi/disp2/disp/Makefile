#
# Copyright (c) 2015 Allwinnertech, Inc.
# Tyle <tyle at allwinnertech.com>
#
#

obj-$(CONFIG_SUNXI_DISPLAY) += disp.o
obj-y += disp.o

disp-objs	:= dev_disp.o disp_sys_intf.o
disp-objs	+= de/disp_display.o de/disp_features.o de/disp_device.o de/disp_lcd.o de/disp_manager.o de/disp_private.o \
               de/disp_smart_backlight.o de/disp_enhance.o de/disp_capture.o de/disp_hdmi.o de/disp_tv.o  de/disp_vga.o de/disp_vdevice.o
disp-objs += lcd/panels.o lcd/lcd_source.o lcd/default_panel.o lcd/lt070me05000.o lcd/wtq05027d01.o lcd/t27p06.o lcd/dx0960be40a1.o lcd/tft720x1280.o lcd/S6D7AA0X01.o lcd/inet_dsi_panel.o

obj-$(CONFIG_ARCH_SUN50IW1P1) += de/lowlevel_sun50iw1/

obj-$(CONFIG_ARCH_SUN8IW10P1) += de/lowlevel_sun8iw10/

obj-$(CONFIG_ARCH_SUN8IW11P1) += de/lowlevel_v2x/

obj-$(CONFIG_ARCH_SUN50IW2P1) += de/lowlevel_v2x/

obj-$(CONFIG_ARCH_SUN8IW7P1) += de/lowlevel_v2x/

obj-$(CONFIG_ARCH_SUN50IW6P1) += de/lowlevel_v3x/

