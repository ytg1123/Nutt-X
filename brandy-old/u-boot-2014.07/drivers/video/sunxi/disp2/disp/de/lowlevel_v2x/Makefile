#
# Copyright (c) 2015 Allwinnertech, Inc.
# Tyle <tyle at allwinnertech.com>
#
#

ifeq ($(MIPI_DSI_IP_VERSION),40)
dsi_obj:=$(mydir)/de_dsi.o
else
dsi_obj:=$(mydir)/de_dsi_28.o
endif

obj-y += de_fcc.o de_gsu.o de_hal.o disp_al.o \
	de_peak.o de_rtmx.o de_scaler_table.o\
	de_vep_table.o de_vsu.o /de_feat.o \
	de_lcd.o de_lti.o de_fce.o \
	de_ase.o de_bws.o de_enhance.o \
	de_smbl.o de_ccsc.o de_dcsc.o \
	de_wb.o de_clock.o $(dsi_obj) \
	de_eink.o disp_eink_data.o disp_waveform.o \
