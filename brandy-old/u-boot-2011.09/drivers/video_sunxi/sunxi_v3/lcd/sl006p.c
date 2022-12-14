#include "sl006p.h"
//#include "panels.h"

//extern s32 bsp_disp_get_panel_info(u32 screen_id, disp_panel_para *info);
static void LCD_power_on(u32 sel);
static void LCD_power_off(u32 sel);
static void LCD_bl_open(u32 sel);
static void LCD_bl_close(u32 sel);

static void LCD_panel_init(u32 sel);
static void LCD_panel_exit(u32 sel);

#ifdef CONFIG_ARCH_SUN9IW1P1
__s32 dsi_dcs_rd(__u32 sel,__u8	cmd,__u8* para_p,__u32*	num_p)
{
	return 0;
}
#endif

//static u8 const mipi_dcs_pixel_format[4] = {0x77,0x66,0x66,0x55};
//#define panel_reset(val) sunxi_lcd_gpio_set_value(sel, 1, val)
//#define power_en(val)  sunxi_lcd_gpio_set_value(sel, 0, val)

static void LCD_cfg_panel_info(panel_extend_para * info)
{
	u32 i = 0, j=0;
	u32 items;
	u8 lcd_gamma_tbl[][2] =
	{
		//{input value, corrected value}
		{0, 0},
		{15, 15},
		{30, 30},
		{45, 45},
		{60, 60},
		{75, 75},
		{90, 90},
		{105, 105},
		{120, 120},
		{135, 135},
		{150, 150},
		{165, 165},
		{180, 180},
		{195, 195},
		{210, 210},
		{225, 225},
		{240, 240},
		{255, 255},
	};

	u32 lcd_cmap_tbl[2][3][4] = {
	{
		{LCD_CMAP_G0,LCD_CMAP_B1,LCD_CMAP_G2,LCD_CMAP_B3},
		{LCD_CMAP_B0,LCD_CMAP_R1,LCD_CMAP_B2,LCD_CMAP_R3},
		{LCD_CMAP_R0,LCD_CMAP_G1,LCD_CMAP_R2,LCD_CMAP_G3},
		},
		{
		{LCD_CMAP_B3,LCD_CMAP_G2,LCD_CMAP_B1,LCD_CMAP_G0},
		{LCD_CMAP_R3,LCD_CMAP_B2,LCD_CMAP_R1,LCD_CMAP_B0},
		{LCD_CMAP_G3,LCD_CMAP_R2,LCD_CMAP_G1,LCD_CMAP_R0},
		},
	};

	items = sizeof(lcd_gamma_tbl)/2;
	for(i=0; i<items-1; i++) {
		u32 num = lcd_gamma_tbl[i+1][0] - lcd_gamma_tbl[i][0];

		for(j=0; j<num; j++) {
			u32 value = 0;

			value = lcd_gamma_tbl[i][1] + ((lcd_gamma_tbl[i+1][1] - lcd_gamma_tbl[i][1]) * j)/num;
			info->lcd_gamma_tbl[lcd_gamma_tbl[i][0] + j] = (value<<16) + (value<<8) + value;
		}
	}
	info->lcd_gamma_tbl[255] = (lcd_gamma_tbl[items-1][1]<<16) + (lcd_gamma_tbl[items-1][1]<<8) + lcd_gamma_tbl[items-1][1];

	memcpy(info->lcd_cmap_tbl, lcd_cmap_tbl, sizeof(lcd_cmap_tbl));

}

static s32 LCD_open_flow(u32 sel)
{
//	tick_printf("[huyanhu:uboot]LCD_open_flow---------------sl006p\n");
	LCD_OPEN_FUNC(sel, LCD_power_on, 20);   //open lcd power, and delay 50ms
	LCD_OPEN_FUNC(sel, LCD_panel_init, 10);   //open lcd power, than delay 200ms
	LCD_OPEN_FUNC(sel, sunxi_lcd_tcon_enable, 20);     //open lcd controller, and delay 100ms
	LCD_OPEN_FUNC(sel, LCD_bl_open, 0);     //open lcd backlight, and delay 0ms

	return 0;
}

static s32 LCD_close_flow(u32 sel)
{
//	tick_printf("[huyanhu:uboot]LCD_close_flow---------------sl006p\n");
	LCD_CLOSE_FUNC(sel, LCD_bl_close, 0);       //close lcd backlight, and delay 0ms
	LCD_CLOSE_FUNC(sel, sunxi_lcd_tcon_disable, 0);         //close lcd controller, and delay 0ms
	LCD_CLOSE_FUNC(sel, LCD_panel_exit,	100);   //open lcd power, than delay 200ms
	LCD_CLOSE_FUNC(sel, LCD_power_off, 500);   //close lcd power, and delay 500ms

	return 0;
}

static void LCD_power_on(u32 sel)
{
	sunxi_lcd_power_enable(sel, 0);//config lcd_power pin to open lcd power0
	sunxi_lcd_delay_ms(5);
	sunxi_lcd_power_enable(sel, 1);//config lcd_power pin to open lcd power1
	sunxi_lcd_delay_ms(5);
	sunxi_lcd_power_enable(sel, 2);//config lcd_power pin to open lcd power2
//	sunxi_lcd_delay_ms(5);
//	sunxi_lcd_pin_cfg(sel, 1);
}

static void LCD_power_off(u32 sel)
{
	sunxi_lcd_pin_cfg(sel, 0);
	sunxi_lcd_delay_ms(10);
	sunxi_lcd_power_disable(sel, 2);//config lcd_power pin to close lcd power2
	sunxi_lcd_delay_ms(5);
	sunxi_lcd_power_disable(sel, 1);//config lcd_power pin to close lcd power1
	sunxi_lcd_delay_ms(5);
	sunxi_lcd_power_disable(sel, 0);//config lcd_power pin to close lcd power0
}

static void LCD_bl_open(u32 sel)
{
	sunxi_lcd_pwm_enable(sel);//open pwm module
	sunxi_lcd_delay_ms(5);
	sunxi_lcd_backlight_enable(sel);//config lcd_bl_en pin to open lcd backlight
}

static void LCD_bl_close(u32 sel)
{
	sunxi_lcd_backlight_disable(sel);//config lcd_bl_en pin to close lcd backlight
	sunxi_lcd_delay_ms(5);
	sunxi_lcd_pwm_disable(sel);//close pwm module
}

#define REGFLAG_DELAY             				0xFE
#define REGFLAG_END_OF_TABLE      				0xFA   // END OF REGISTERS MARKER

struct LCM_setting_table {
    __u8 cmd;
    __u32 count;
    __u8 para_list[64];
};

#if 0
static struct LCM_setting_table otm1283_test_config_para[] = {
	{0x00, 1, 0X00},
	{0xff, 3, {0x12, 0x83, 0x01}},
	{0x00, 1, 0x80},
	{0xff, 2 , {0x12, 0x83}},
	{REGFLAG_END_OF_TABLE, 0x00, {}}	
};
#endif
#if 0
static struct LCM_setting_table hx8394a_init_setting[] = {
#if 1	
	{0xB9,	3,	{0xFF,0x83,0x94}},
	{0xBA,	1,	{0x11}},//,0x82,0x00,0x16,0xC5,0x00,0x10,0xFF,0x0F,0x24,0x03,0x21,0x24,0x25,0x20,0x08}},   //set mipi 4 lane
	{0xB1,	16,	{0x01,0x00,0x54,0x87,0x01,0x11,0x11,0x35,0x3d,0x29,0x29,0x47,0x12,0x01,0xE6,0xE2}},
	{0xB4,	22, {0x80,0x08,0x32,0x10,0x06,0x32,0x15,0x08,0x32,0x10,0x08,0x33,0x05,0x44,0x0a,0x37,0x05,0x44,0x0A,0x68,0x68,0x0a}},//,0x06,0x44,0x06,0x5F,0x0A,0x6B,0x70,0x05,0x08}},
	{0xD5, 	54,	{0x00,0x00,0x0f,0x00,0x0A,0x00,0x01,0x00,0x00,0x00,0x33,0x00,0x45,0x67,0x01,0x23,0x01,0x23,0x88,0x88,0x88,0x99,0x88,0xaa,0xbb,0x99,0x99,0x99,0x88,0x88,0x88,0x88,0x32,0x10,0x76,0x54,0x32,0x10,0x88,0x88,0x88,0x88,0x99,0xbb,0xaa,0x99,0x99,0x99,0x88,0x88,0x88,0x88,0x1e,0x08}},
	{0xB6, 	1,	{0x16}},
	{0xE0, 	42,	{0x00,0x08,0x0d,0x37,0x3f,0x3f,0x1d,0x3f,0x07,0x0D,0x0e,0x11,0x13,0x11,0x12,0x11,0x18,0x00,0x08,0x0d,0x37,0x3f,0x3f,0x1d,0x3f,0x07,0x0D,0x0e,0x11,0x13,0x11,0x12,0x11,0x18,0x0B,0x17,0x06,0x11,0x0B,0x17,0x06,0x11}},
	{0xBF,	4,	{0x06,0x00,0x10,0x04}},
	{0xc0,	4,	{0x0c,0x14}},
	{0xC7, 	4,	{0x00,0x10,0x00,0x10}},
	{0xB2, 	6,	{0x00,0xC8,0x0f,0x05,0x00,0x22}},
	{0xCC, 	1,	{0x01}},//0x09
	{0xBC, 	1,	{0x07}},
	{0xC6, 	2,	{0x08,0x40}},
	{0xd4, 	1,	{0x32}},
	{0x35,	1,	{0x00}},    // set TE on
	{0x11,	0,	{}},     //sleep out
	{REGFLAG_DELAY, 200, {}},
	{0x29,	0,	{}},
	{REGFLAG_DELAY, 150, {}},
	{REGFLAG_END_OF_TABLE, 0x00, {}}
#else
	{0xB9,	3,	{0xFF,0x83,0x94}},
	{0xBA,	6,	{0x63,0x03,0x68,0x6b,0xb2,0xc0}},   //set mipi 4 lane
	{0xB1,	10,	{0x50,0x0F,0x6F,0x09,0x33,0x33,0x71,0x31,0x50,0x30}},
	{0xB2, 	6,	{0x65,0x80,0x64,0x0e,0x0d,0x2f}},
	{0xB4,	21, {0x33,0x7d,0x33,0x7d,0x33,0x7d,0x05,0x0D,0x8E,0x55,0x00,0x3f,0x33,0x7d,0x33,0x7d,0x33,0x7d,0x05,0x0d,0x8e}},
	{0xE0, 	62,	{0x00,0x00,0x06,0x37,0x3f,0x3f,0x1d,0x3f,0x07,0x0D,0x0e,0x11,0x13,0x11,0x12,0x11,0x18,0x00,0x08,0x0d,
				 0x37,0x3f,0x3f,0x1d,0x3f,0x07,0x0D,0x0e,0x11,0x13,0x11,0x12,0x11,0x18,0x0B,0x17,0x06,0x11,0x0B,0x17,
				 0x06,0x11}},
	
	
	{0xBF,	2,	{0x06, 0x02}},
	{0xB6, 	1,	{0xF7}},
	{0xD5, 	32,	{0x00,0x00,0x00,0x00,0x0A,0x00,0x01,0x66,0x00,0x00,0x66,0x11,0x10,0x10,0x32,0x54,0x76,0xA9,0xCB,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x54,0x88,0x88}},
	{0xCC, 	1,	{0x01}},//0x09			
	{0xC6, 	1,	{0x08}},
	{0xBC, 	1,	{0x07}},
	{0xC7, 	4,	{0x00,0x10,0x00,0x10}},
	{0xE0, 	42,	{0x19,0x2A,0x2E,0x2E,0x34,0x39,0x32,0x43,0x07,0x0D,0x0F,0x12,0x13,0x12,0x13,0x0F,0x17,0x09,0x19,0x1C,0x2E,0x34,0x39,0x23,0x3D,0x06,0x0D,0x0E,0x11,0x13,0x11,0x13,0x11,0x18,0x0B,0x18,0x05,0x11,0x0B,0x17,0x07,0x12}},
	{0x35,	1,	{0x00}},    // set TE on
	{REGFLAG_DELAY, 10, {}},
	{0x11,	0,	{}},     //sleep out
	{REGFLAG_DELAY, 200, {}},
	{0x29,	0,	{}},
	{REGFLAG_DELAY, 150, {}},
	{REGFLAG_END_OF_TABLE, 0x00, {}}
#endif
};

//static struct LCM_setting_table hx8394_test_config_para[] = {
//	{0xB9, 3, {0xFF, 0x83, 0x94}},
//	{REGFLAG_END_OF_TABLE, 0x00, {}}	
//};

static struct LCM_setting_table hx8394f_init_setting[] = {
#if 0	
	{0XB9,	3,	{0xFF,0x83,0x89}},
	{0XB1, 	20,	{0x7F,0x12,0x12,0x35,0x55,0x50,0xD0,0xF6,0x58,0x80,0x20,0x20,0xF8,0xAA,0xAA,0xA3,0x00,0x80,0x30,0x00}},
	{0XB2,	10,	{0x80,0x50,0x0C,0x12,0xF0,0x38,0x11,0x64,0x5D,0x09}},
	{0XB4, 	10,	{0x10,0x6C,0x10,0x6c,0x00,0x00,0x08,0x78,0x10,0x78}},
	{0XD3,	35,	{0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x32,0x10,0x07,0x00,0x07,0x03,0xCB,0x03,0xCB,0x00,0x00,0x00,0x00,0x37,0x04,0x09,0x09,0x37,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x0A,0x00,0x01}},
	{0XD5,  38,	{0x18,0x20,0x18,0x22,0x21,0x18,0x23,0x18,0x18,0x02,0x18,0x06,0x03,0x18,0x07,0x18,0x18,0x04,0x18,0x00,
			   0x05,0x18,0x01,0x18,0x27,0x18,0x25,0x18,0x18,0x26,0x18,0x24,0x18,0x00,0x18,0x18,0x18,0x18}},
	{0XD6, 38,	{0x18,0x27,0x18,0x25,0x26,0x18,0x24,0x18,0x18,0x01,0x18,0x05,0x00,0x18,0x04,0x18,0x18,0x07,0x18,0x03,
			   0x06,0x18,0x02,0x18,0x20,0x18,0x22,0x18,0x18,0x21,0x18,0x23,0x18,0x18,0x18,0x18,0x18,0x18}},
	{0XB6, 4,	{0x23,0x23,0x00,0x00}},
	{0XE0, 42,	{0x04,0x08,0x12,0x24,0x3d,0x3F,0x1a,0x39,0x06,0x08,0x09,0x16,0x0e,0x11,0x12,0x11,0x13,0x0b,0x16,0x16,
			   0x12,0x04,0x08,0x12,0x24,0x3d,0x3F,0x1a,0x39,0x06,0x08,0x09,0x16,0x0e,0x11,0x12,0x11,0x13,0x0b,0x16,
			   0x16,0x12}},
	{0XCC, 	1,	{0x02}},
	{0XD2, 	1,	{0x55}},	 
	{0XE4, 	2,	{0x00,0x01}},
	{REGFLAG_DELAY, 10, {}},
	{0X11, 	0,	{}},
	{REGFLAG_DELAY, 100, {}},
	{0X29, 	0,	{}},
	{REGFLAG_DELAY, 20, {}},
	{REGFLAG_END_OF_TABLE, 0x00, {}}
	
#else
	{0XB9,	3,	{0xFF,0x83,0x94}},
	{REGFLAG_DELAY, 10, {}},
	{0xBA,	6,	{0x63,0x03,0x68,0x6B,0xb2,0xC0}},//63=4lane,62=3lane
	{0XB1, 	10,	{0x50,0x0F,0x6F,0x09,0x33,0x33,0x71,0x31,0x50,0x30}},
	{0XB2,	6,	{0x65,0x80,0x64,0x0E,0x0D,0x2F}},
	{0XB4,	21,	{0x33,0x7D,0x33,0x7D,0x33,0x7D,0x05,0x0D,0x8E,0x55,0x00,0x3F,0x33,0x7D,0x33,0x7D,0x33,0x7D,0x05,0x0D,0x8E}},
	{REGFLAG_DELAY, 1, {}},
	{0XE0,	58,	{0x00,0x00,0x06,0x0B,0x0D,0x11,0x14,0x12,0x28,0x3A,0x4D,0x4E,0x59,0x6D,0x73,0x75,0x84,0x88,0x84,0x93,
				 0xA4,0x51,0x4F,0x52,0x56,0x58,0x5E,0x61,0x7F,0x00,0x00,0x06,0x0A,0x0D,0x10,0x13,0x12,0x28,0x3A,0x4D,
				 0x4E,0x59,0x6C,0x72,0x75,0x82,0x88,0x84,0x93,0xA4,0X51,0x4F,0x52,0x55,0x58,0x5D,0x61,0x7F}},
	{REGFLAG_DELAY, 1, {}},
	{0xD3, 	33,	{0x00,0x00,0x07,0x07,0x00,0x00,0x08,0x08,0x32,0x10,0x09,0x00,0x09,0x32,0x15,0x0D,0x05,0x0D,0x32,0x10,
				 0x08,0x00,0x00,0x37,0x33,0x0C,0X0C,0x27,0x02,0x02,0x27,0x0E,0x40}},
	{REGFLAG_DELAY, 1, {}},
	{0xD5, 	44,	{0x27,0x26,0x25,0x24,0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x00,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
				 0x18,0x18,0x18,0x18,0x18,0x18,0x1B,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x21,0x20,0x23,0x22,
				 0x18,0x18,0x18,0x18}},
	{REGFLAG_DELAY, 1, {}},
	{0xD6, 	44,	{0x20,0x21,0x22,0x23,0x04,0x05,0x06,0x07,0x00,0x01,0x02,0x03,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
				 0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x26,0x27,0x24,0x25,
				 0x18,0x18,0x18,0x18}},
	{REGFLAG_DELAY, 1, {}},
	{0xCC, 	1,	{0x0b}},
	{0xC0, 	2,	{0x1F,0x73}},
	{0xD4, 	1,	{0x02}},
	{0xBD, 	1,	{0x01}},
	{0xB1, 	1,	{0x60}},
	{0xBD, 	1,	{0x00}},
	{0xB6, 	2,	{0x2E,0x2E}},
	{0xBF, 	7,	{0x40,0x81,0x50,0x00,0x1A,0xFC,0x01}},
	{0X11, 	0,	{}},
	{REGFLAG_DELAY, 200, {}},
	{0X29, 	0,	{}},
	{REGFLAG_DELAY, 100, {}},
	{REGFLAG_END_OF_TABLE, 0x00, {}}
#endif
};
#endif

static struct LCM_setting_table ili9881c_init_setting[] = {
	#if 0
	{0xff,  3 ,{0x98,0x81,0x03}},
	{0x01,  1 ,{0x00}},
	{0x02,  1 ,{0x00}},
	{0x03,  1 ,{0x73}},
	{0x04,  1 ,{0x73}},
	{0x05,  1 ,{0x00}},
	{0x06,  1 ,{0x06}},
	{0x07,  1 ,{0x02}},
	{0x08,  1 ,{0x00}},
	{0x09,  1 ,{0x01}},
	{0x0A,  1 ,{0x01}},
	{0x0B,  1 ,{0x01}},
	{0x0C,  1 ,{0x01}},
	{0x0D,  1 ,{0x01}},
	{0x0E,  1 ,{0x01}},
	{0x0F,  1 ,{0x32}},
	{0x10,  1 ,{0x32}},
	{0x11,  1 ,{0x00}},
	{0x12,  1 ,{0x00}},
	{0x13,  1 ,{0x01}},
	{0x14,  1 ,{0x00}},
	{0x15,  1 ,{0x00}},
	{0x16,  1 ,{0x00}},
	{0x17,  1 ,{0x00}},
	{0x18,  1 ,{0x00}},
	{0x19,  1 ,{0x00}},
	{0x1A,  1 ,{0x00}},
	{0x1B,  1 ,{0x00}},
	{0x1C,  1 ,{0x00}},
	{0x1D,  1 ,{0x00}},
	{0x1E,  1 ,{0xc0}},
	{0x1F,  1 ,{0x80}},
	{0x20,  1 ,{0x03}},
	{0x21,  1 ,{0x04}},
	{0x22,  1 ,{0x00}},
	{0x23,  1 ,{0x00}},
	{0x24,  1 ,{0x00}},
	{0x25,  1 ,{0x00}},
	{0x26,  1 ,{0x00}},
	{0x27,  1 ,{0x00}},
	{0x28,  1 ,{0x33}},
	{0x29,  1 ,{0x02}},
	{0x2A,  1 ,{0x00}},
	{0x2B,  1 ,{0x00}},
	{0x2C,  1 ,{0x00}},
	{0x2D,  1 ,{0x00}},
	{0x2E,  1 ,{0x00}},
	{0x2F,  1 ,{0x00}},
	{0x30,  1 ,{0x00}},
	{0x31,  1 ,{0x00}},
	{0x32,  1 ,{0x00}},
	{0x33,  1 ,{0x00}},
	{0x34,  1 ,{0x03}},
	{0x35,  1 ,{0x00}},
	{0x36,  1 ,{0x03}},
	{0x37,  1 ,{0x00}},
	{0x38,  1 ,{0x00}},
	{0x39,  1 ,{0x00}},
	{0x3A,  1 ,{0x00}},
	{0x3B,  1 ,{0x00}},
	{0x3C,  1 ,{0x00}},
	{0x3D,  1 ,{0x00}},
	{0x3E,  1 ,{0x00}},
	{0x3F,  1 ,{0x00}},
	{0x40,  1 ,{0x00}},
	{0x41,  1 ,{0x00}},
	{0x42,  1 ,{0x00}},
	{0x43,  1 ,{0x00}},
	{0x44,  1 ,{0x00}},
	{0x50,  1 ,{0x01}},
	{0x51,  1 ,{0x23}},
	{0x52,  1 ,{0x45}},
	{0x53,  1 ,{0x67}},
	{0x54,  1 ,{0x89}},
	{0x55,  1 ,{0xab}},
	{0x56,  1 ,{0x01}},
	{0x57,  1 ,{0x23}},
	{0x58,  1 ,{0x45}},
	{0x59,  1 ,{0x67}},
	{0x5A,  1 ,{0x89}},
	{0x5B,  1 ,{0xab}},
	{0x5C,  1 ,{0xcd}},
	{0x5D,  1 ,{0xef}},
	{0x5E,  1 ,{0x10}},
	{0x5F,  1 ,{0x09}},
	{0x60,  1 ,{0x08}},
	{0x61,  1 ,{0x0f}},
	{0x62,  1 ,{0x0e}},
	{0x63,  1 ,{0x0d}},
	{0x64,  1 ,{0x0c}},
	{0x65,  1 ,{0x02}},
	{0x66,  1 ,{0x02}},
	{0x67,  1 ,{0x02}},
	{0x68,  1 ,{0x02}},
	{0x69,  1 ,{0x02}},
	{0x6A,  1 ,{0x00}},
	{0x6B,  1 ,{0x02}},
	{0x6C,  1 ,{0x02}},
	{0x6D,  1 ,{0x02}},
	{0x6E,  1 ,{0x02}},
	{0x6F,  1 ,{0x02}},
	{0x70,  1 ,{0x02}},
	{0x71,  1 ,{0x06}},
	{0x72,  1 ,{0x07}},
	{0x73,  1 ,{0x02}},
	{0x74,  1 ,{0x02}},
	{0x75,  1 ,{0x06}},
	{0x76,  1 ,{0x07}},
	{0x77,  1 ,{0x0e}},
	{0x78,  1 ,{0x0f}},
	{0x79,  1 ,{0x0c}},
	{0x7A,  1 ,{0x0d}},
	{0x7B,  1 ,{0x02}},
	{0x7C,  1 ,{0x02}},
	{0x7D,  1 ,{0x02}},
	{0x7E,  1 ,{0x02}},
	{0x7F,  1 ,{0x02}},
	{0x80,  1 ,{0x02}},
	{0x81,  1 ,{0x02}},
	{0x82,  1 ,{0x02}},
	{0x83,  1 ,{0x02}},
	{0x84,  1 ,{0x02}},
	{0x85,  1 ,{0x02}},
	{0x86,  1 ,{0x02}},
	{0x87,  1 ,{0x09}},
	{0x88,  1 ,{0x08}},
	{0x89,  1 ,{0x02}},
	{0x8A,  1 ,{0x02}},
	{0xff,  3 ,{0x98,0x81,0x04}},
	{0x6C,  1 ,{0x15}},
	{0x6E,  1 ,{0x2b}},
	{0x6F,  1 ,{0x32}},
	{0x3A,  1 ,{0xa4}},
	{0x8D,  1 ,{0x14}},
	{0x87,  1 ,{0xBA}},
	//{0x88,  1 ,{0x0B}},
	//{0x3C,  1 ,{0x81}},
	{0x26,  1 ,{0x76}},
	{0xB2,  1 ,{0xD1}},
	//{0xB5,  1 ,{0x06}},
	
	//{0x2f,  1 ,{0x01}},//
	//{0x00,  1 ,{0x00}},
	{0xff,  3 ,{0x98,0x81,0x01}},
	{0x22,  1 ,{0x0A}},
	{0x31,  1 ,{0x0b}},
	//{0x40,  1 ,{0x33}},
	{0x53,  1 ,{0x40}},//0x77
	{0x55,  1 ,{0x50}},
	{0x50,  1 ,{0x9d}},
	{0x51,  1 ,{0x98}},
	{0x60,  1 ,{0x14}},
	{0xA0,  1 ,{0x08}},
	{0xA1,  1 ,{0x15}},
	{0xA2,  1 ,{0x20}},
	{0xA3,  1 ,{0x1f}},
	{0xA4,  1 ,{0x21}},
	{0xA5,  1 ,{0x31}},
	{0xA6,  1 ,{0x26}},
	{0xA7,  1 ,{0x24}},
	{0xA8,  1 ,{0x72}},
	{0xA9,  1 ,{0x1e}},
	{0xAA,  1 ,{0x2a}},
	{0xAB,  1 ,{0x5f}},
	{0xAC,  1 ,{0x1b}},
	{0xAD,  1 ,{0x19}},
	{0xAE,  1 ,{0x4d}},
	{0xAF,  1 ,{0x26}},
	{0xB0,  1 ,{0x27}},
	{0xB1,  1 ,{0x56}},
	{0xB2,  1 ,{0x69}},
	{0xB3,  1 ,{0x39}},
	{0xC0,  1 ,{0x08}},
	{0xC1,  1 ,{0x13}},
	{0xC2,  1 ,{0x1e}},
	{0xC3,  1 ,{0x03}},
	{0xC4,  1 ,{0x04}},
	{0xC5,  1 ,{0x1a}},
	{0xC6,  1 ,{0x10}},
	{0xC7,  1 ,{0x16}},
	{0xC8,  1 ,{0x6a}},
	{0xC9,  1 ,{0x18}},
	{0xCA,  1 ,{0x23}},
	{0xCB,  1 ,{0x60}},
	{0xCC,  1 ,{0x15}},
	{0xCD,  1 ,{0x14}},
	{0xCE,  1 ,{0x4a}},
	{0xCF,  1 ,{0x1c}},
	{0xD0,  1 ,{0x27}},
	{0xD1,  1 ,{0x59}},
	{0xD2,  1 ,{0x6b}},
	{0xD3,  1 ,{0x39}},
	
	{0xff,  3 ,{0x98,0x81,0x00}},
	{0x11, 1, {0x00}},
	{REGFLAG_DELAY, 120, {}},

	{0x29, 1, {0x00}},
	{REGFLAG_DELAY, 120, {}},
	{REGFLAG_END_OF_TABLE, 0x00, {}}
#endif 

	{0xFF,3,{0x98,0x81,0x03}},																													
{0x01,1,{0x00}},										
{0x02,1,{0x00}},										
{0x03,1,{0x73}},										
{0x04,1,{0x73}},										
{0x05,1,{0x00}},										
{0x06,1,{0x06}},										
{0x07,1,{0x02}},										
{0x08,1,{0x00}},										
{0x09,1,{0x01}},										
{0x0a,1,{0x01}},										
{0x0b,1,{0x01}},										
{0x0c,1,{0x01}},										
{0x0d,1,{0x01}},										
{0x0e,1,{0x01}},										
{0x0f,1,{0x32}},										
{0x10,1,{0x32}}, 										
{0x11,1,{0x00}},										
{0x12,1,{0x00}},										
{0x13,1,{0x01}},										
{0x14,1,{0x00}},										
{0x15,1,{0x00}},										
{0x16,1,{0x00}}, 										
{0x17,1,{0x00}},										
{0x18,1,{0x00}},										
{0x19,1,{0x00}},										
{0x1a,1,{0x00}},										
{0x1b,1,{0x00}},										
{0x1c,1,{0x00}},										
{0x1d,1,{0x00}},										
{0x1e,1,{0xC0}},										
{0x1f,1,{0x80}},										
{0x20,1,{0x03}},										
{0x21,1,{0x04}},										
{0x22,1,{0x00}},										
{0x23,1,{0x00}},										
{0x24,1,{0x00}},										
{0x25,1,{0x00}},										
{0x26,1,{0x00}},										
{0x27,1,{0x00}},										
{0x28,1,{0x33}},										
{0x29,1,{0x02}},										
{0x2a,1,{0x00}},										
{0x2b,1,{0x00}},										
{0x2c,1,{0x00}},										
{0x2d,1,{0x00}},										
{0x2e,1,{0x00}},										
{0x2f,1,{0x00}},										
{0x30,1,{0x00}},										
{0x31,1,{0x00}},										
{0x32,1,{0x00}},										
{0x33,1,{0x00}},  										
{0x34,1,{0x03}},										
{0x35,1,{0x00}},										
{0x36,1,{0x03}},										
{0x37,1,{0x00}},										
{0x38,1,{0x00}},										
{0x39,1,{0x00}},										
{0x3a,1,{0x00}}, 										
{0x3b,1,{0x00}},										
{0x3c,1,{0x00}},										
{0x3d,1,{0x00}},										
{0x3e,1,{0x00}},										
{0x3f,1,{0x00}},										
{0x40,1,{0x00}},										
{0x41,1,{0x00}},										
{0x42,1,{0x00}},										
{0x43,1,{0x00}},										
{0x44,1,{0x00}},										
							
{0x50,1,{0x01}},									
{0x51,1,{0x23}},									
{0x52,1,{0x45}},									
{0x53,1,{0x67}},									
{0x54,1,{0x89}},									
{0x55,1,{0xab}},									
{0x56,1,{0x01}},									
{0x57,1,{0x23}},									
{0x58,1,{0x45}},									
{0x59,1,{0x67}},									
{0x5a,1,{0x89}},									
{0x5b,1,{0xab}},									
{0x5c,1,{0xcd}},									
{0x5d,1,{0xef}},													
					
{0x5e,1,{0x10}},										
{0x5f,1,{0x09}},										
{0x60,1,{0x08}},										
{0x61,1,{0x0F}},										
{0x62,1,{0x0E}},										
{0x63,1,{0x0D}},										
{0x64,1,{0x0C}},										
{0x65,1,{0x02}},										
{0x66,1,{0x02}},										
{0x67,1,{0x02}},										
{0x68,1,{0x02}},										
{0x69,1,{0x02}},										
{0x6a,1,{0x02}},										
{0x6b,1,{0x02}},										
{0x6c,1,{0x02}},										
{0x6d,1,{0x02}},										
{0x6e,1,{0x02}},										
{0x6f,1,{0x02}},										
{0x70,1,{0x02}},										
{0x71,1,{0x06}},										
{0x72,1,{0x07}},										
{0x73,1,{0x02}},										
{0x74,1,{0x02}},										
{0x75,1,{0x06}},										
{0x76,1,{0x07}},										
{0x77,1,{0x0E}},										
{0x78,1,{0x0F}},										
{0x79,1,{0x0C}},										
{0x7a,1,{0x0D}},										
{0x7b,1,{0x02}},										
{0x7c,1,{0x02}},										
{0x7d,1,{0x02}},										
{0x7e,1,{0x02}},										
{0x7f,1,{0x02}},										
{0x80,1,{0x02}},										
{0x81,1,{0x02}},										
{0x82,1,{0x02}},										
{0x83,1,{0x02}},										
{0x84,1,{0x02}},										
{0x85,1,{0x02}},										
{0x86,1,{0x02}},										
{0x87,1,{0x09}},										
{0x88,1,{0x08}},										
{0x89,1,{0x02}},										
{0x8A,1,{0x02}},										
					
					
{0xFF,3,{0x98,0x81,0x04}},										
{0x6C,1,{0x15}},                //Set VCORE voltage =1.5V										
{0x6E,1,{0x2b}},             //36   //di_pwr_reg=0 for power mode 2A //VGH clamp 15V										
{0x6F,1,{0x32}},             //42 52 // reg vcl + pumping ratio VGH=3.0x VGL=-2.5x										
{0x3A,1,{0xA4}},                										
{0x8D,1,{0x14}},               //VGL clamp -11V										
{0x87,1,{0xBA}},                              										
{0x26,1,{0x76}},            										
{0xB2,1,{0xD1}},										
							
						
						
{0xFF,3,{0x98,0x81,0x01}},										
{0x22,1,{0x0A}},		//BGR, SS								
{0x31,1,{0x0b}},		//Cloumn inversion								
{0x53,1,{0x40}},		//VCOM1								
{0x55,1,{0x50}},		//VCOM2								
{0x50,1,{0x9d}},		//VREG1OUT=4.8V								
{0x51,1,{0x98}},		//VREG2OUT=-4.8V								
{0x60,1,{0x14}},               //SDT										
		
{0xA0,1,{0x08}},
{0xA1,1,{0x15}},
{0xA2,1,{0x20}},
{0xA3,1,{0x1f}},
{0xA4,1,{0x21}},
{0xA5,1,{0x31}},
{0xA6,1,{0x26}},
{0xA7,1,{0x24}},
{0xA8,1,{0x72}},
{0xA9,1,{0x1e}},
{0xAA,1,{0x2a}},
{0xAB,1,{0x5f}},
{0xAC,1,{0x1b}},
{0xAD,1,{0x19}},
{0xAE,1,{0x4d}},
{0xAF,1,{0x26}},
{0xB0,1,{0x27}},
{0xB1,1,{0x56}},
{0xB2,1,{0x69}},
{0xB3,1,{0x39}},
 
{0xC0,1,{0x08}},
{0xC1,1,{0x13}},
{0xC2,1,{0x1e}},
{0xC3,1,{0x03}},
{0xC4,1,{0x04}},
{0xC5,1,{0x1a}},
{0xC6,1,{0x10}},
{0xC7,1,{0x16}},
{0xC8,1,{0x6a}},
{0xC9,1,{0x18}},
{0xCA,1,{0x23}},
{0xCB,1,{0x60}},
{0xCC,1,{0x15}},
{0xCD,1,{0x14}},
{0xCE,1,{0x4a}},
{0xCF,1,{0x1c}},
{0xD0,1,{0x27}},
{0xD1,1,{0x59}},
{0xD2,1,{0x6b}},
{0xD3,1,{0x39}},	
				
{0xff,  3 ,{0x98,0x81,0x00}},
{0x11, 1, {0x00}},
{REGFLAG_DELAY, 120, {}},
{0x29, 1, {0x00}},
{REGFLAG_DELAY, 120, {}},
{REGFLAG_END_OF_TABLE, 0x00, {}}

};

static void LCD_panel_init(u32 sel)
{
	__u32 i;
	tick_printf("[huyanhu:uboot]LCD_panel_init!\n");
	
//	__u32 rx_num;
//	__u8 rx_bf0=0,rx_bf1=0,rx_bf2=0;
	//__u32 hx8394a_used=0;
	//__u32 hx8394f_used=0;
	//__u32 ili9881c_used=1;
#if 0
	if(ili9881c_used){
		panel_rst(1);	
		sunxi_lcd_delay_ms(50);
		panel_rst(0);
		sunxi_lcd_delay_ms(50);
		panel_rst(1);
		sunxi_lcd_delay_ms(120);
		}
	else{
		panel_rst(1);	
		sunxi_lcd_delay_ms(10);
		panel_rst(0);
		sunxi_lcd_delay_ms(50);
		panel_rst(1);
		sunxi_lcd_delay_ms(80);
		}
#endif
		panel_rst(1);	
		sunxi_lcd_delay_ms(50);
		panel_rst(0);
		sunxi_lcd_delay_ms(50);
		panel_rst(1);
		sunxi_lcd_delay_ms(120);
	sunxi_lcd_pin_cfg(sel, 1);
	sunxi_lcd_delay_ms(20);
	sunxi_lcd_dsi_clk_enable(sel);
	sunxi_lcd_delay_ms(20);
#if 0
	if (hx8394a_used==1) {
		for (i=0;;i++) {
			if(hx8394a_init_setting[i].cmd == REGFLAG_END_OF_TABLE)
				break;
			else if (hx8394a_init_setting[i].cmd == REGFLAG_DELAY)
				sunxi_lcd_delay_ms(hx8394a_init_setting[i].count);
			else
				dsi_dcs_wr(0,hx8394a_init_setting[i].cmd,hx8394a_init_setting[i].para_list,hx8394a_init_setting[i].count);
				
		}
		tick_printf("[huyanhu:uboot]hx8394a_init_setting i = %d end!\n",i);
	} else if(hx8394f_used==1){
		for (i=0;;i++) {
			if(hx8394f_init_setting[i].cmd == REGFLAG_END_OF_TABLE)
				break;
			else if (hx8394f_init_setting[i].cmd == REGFLAG_DELAY)
				sunxi_lcd_delay_ms(hx8394f_init_setting[i].count);
			else
//RGB			
//				dsi_dcs_wr(0,hx8394f_init_setting[i].cmd,hx8394f_init_setting[i].para_list,hx8394f_init_setting[i].count);	
				sunxi_lcd_dsi_dcs_write(0,hx8394f_init_setting[i].cmd,hx8394f_init_setting[i].para_list,hx8394f_init_setting[i].count);
			}
		tick_printf("[huyanhu:uboot]hx8394f_init_setting i = %d end#############!\n",i);
	}
	else if(ili9881c_used==1){
#endif 
			for (i=0;;i++) {
			if(ili9881c_init_setting[i].cmd == REGFLAG_END_OF_TABLE )
				break;
			else if (ili9881c_init_setting[i].cmd == REGFLAG_DELAY)
				sunxi_lcd_delay_ms(ili9881c_init_setting[i].count);
			else
				dsi_dcs_wr(0,ili9881c_init_setting[i].cmd,ili9881c_init_setting[i].para_list,ili9881c_init_setting[i].count);
				
		}
		tick_printf("[huyanhu:uboot]ili9881c_init_setting i = %d end!############\n",i);
	
//		}
//	sunxi_lcd_dsi_clk_enable(sel);
//	sunxi_lcd_dsi_dcs_write_0para(sel,DSI_DCS_SET_DISPLAY_ON);
//	sunxi_lcd_delay_ms(20);

	tick_printf("[huyanhu:uboot]LCD_panel_init-------------------exit\n");
	return;
}

static void LCD_panel_exit(u32 sel)
{
	sunxi_lcd_dsi_clk_disable(sel);
	sunxi_lcd_delay_ms(20);
	panel_rst(0);
//	sunxi_lcd_delay_ms(5);
	
//	sunxi_lcd_dsi_dcs_write_0para(sel,DSI_DCS_SET_DISPLAY_OFF);
//	sunxi_lcd_delay_ms(20);
//	sunxi_lcd_dsi_dcs_write_0para(sel,DSI_DCS_ENTER_SLEEP_MODE);
//	sunxi_lcd_delay_ms(80);

	return ;
}

//sel: 0:lcd0; 1:lcd1
static s32 LCD_user_defined_func(u32 sel, u32 para1, u32 para2, u32 para3)
{
	return 0;
}

//sel: 0:lcd0; 1:lcd1
static s32 LCD_set_bright(u32 sel, u32 bright)
{
	sunxi_lcd_dsi_dcs_write_1para(sel,0x51,bright);
	return 0;
}

__lcd_panel_t sl006p_panel = {
	/* panel driver name, must mach the name of lcd_drv_name in sys_config.fex */
	.name = "sl006p",
	.func = {
		.cfg_panel_info = LCD_cfg_panel_info,
		.cfg_open_flow = LCD_open_flow,
		.cfg_close_flow = LCD_close_flow,
		.lcd_user_defined_func = LCD_user_defined_func,
		.set_bright = LCD_set_bright,
	},
};
