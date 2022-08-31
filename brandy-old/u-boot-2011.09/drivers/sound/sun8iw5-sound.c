#include <common.h>
#include <private_boot0.h>
#include <private_uboot.h>
#include <asm/arch/clock.h>
#include <asm/arch/timer.h>
#include <asm/arch/uart.h>
#include <asm/arch/dram.h>
#include <asm/arch/rtc_region.h>
#include <private_toc.h>
#include <malloc.h>
#include <sys_partition.h>
#include <asm/arch/ccmu.h>
#include <asm/arch/dma.h>
#include <sunxi_board.h>
#include <sys_config.h>
#include <asm/io.h>
#include "sun8iw5-sound.h"

static  sunxi_dma_setting_t * codec_tx_dma;
static  uint  codec_tx_dma_hd;
u16*  tone_buf_global;
int tone_size_global = 0;
int tone_skip_size_global = 44;
int codec_play_audio_enable = 1;
int set_factory_tone_size(void);
int set_boot_tone_size(void);
int set_sample_rate(int sample_rate);
int need_play_tone(void);

void sun8iw5_sound_mdelay(int i)
{
	__msdelay(i);
}

void sun8iw5_sound_udelay(int i)
{
	__usdelay(i);
}

typedef struct wav_header {
	/* RIFF Header */
	char riff_header[4]; /* Contains "RIFF" */
	int wav_size; /* Size of the wav portion of the file, which follows the first 8 bytes. File size - 8 */
	char wave_header[4]; /* Contains "WAVE" */

	/* Format Header */
	char fmt_header[4]; /* Contains "fmt " (includes trailing space) */
	int fmt_chunk_size; /* Should be 16 for PCM */
	short audio_format; /* Should be 1 for PCM. 3 for IEEE Float */
	short num_channels;
	int sample_rate;
	int byte_rate; /* Number of bytes per second. sample_rate * num_channels * Bytes Per Sample */
	short sample_alignment; /* num_channels * Bytes Per Sample */
	short bit_depth; /* Number of bits per sample */

	/* Data */
	char data_header[4]; /* Contains "data" */
	int data_bytes; /* Number of bytes in data. Number of samples * num_channels * sample byte size */
	/* uint8_t bytes[]; */  /* Remainder of wave file is bytes */
} wav_header;

int dump_wav_header(struct wav_header* wav)
{
	printf("*****************wav header*******************\n");
	printf("riff:%c%c%c%c\n",wav->riff_header[0],wav->riff_header[1],wav->riff_header[2],wav->riff_header[3]);
	printf("wav_size:%d\n",wav->wav_size);
	printf("wave_header:%c%c%c%c\n",wav->wave_header[0],wav->wave_header[1],wav->wave_header[2],wav->wave_header[3]);
	printf("fmt_header:%c%c%c%c\n",wav->fmt_header[0],wav->fmt_header[1],wav->fmt_header[2],wav->fmt_header[3]);
	printf("fmt_chunk_size:%d\n",wav->fmt_chunk_size);
	printf("audio_format:%d\n",wav->audio_format);
	printf("num_channels:%d\n",wav->num_channels);
	printf("sample_rate:%d\n",wav->sample_rate);
	printf("byte_rate:%d\n",wav->byte_rate);
	printf("sample_alignment:%d\n",wav->sample_alignment);
	printf("bit_depth:%d\n",wav->bit_depth);
	printf("data_header:%c%c%c%c\n",wav->data_header[0],wav->data_header[1],wav->data_header[2],wav->data_header[3]);
	printf("data_bytes:%d\n",wav->data_bytes);
	printf("**********************************************\n");
	return 0;
}

int is_valid_wav_header(struct wav_header* wav)
{
	if( strncmp("RIFF", wav->riff_header, 4) == 0)
		return 1;

	return 0;
}

void put_adda_wvalue(u32 addr, u32 data)
{
	u32 reg;
	reg=get_wvalue(ADDA_PR_CFG_REG);
	reg|=(0x1<<28);
	reg=put_wvalue(ADDA_PR_CFG_REG,reg);


	reg=get_wvalue(ADDA_PR_CFG_REG);
	reg&=~(0x1f<<16);
	reg|=(addr<<16);
	reg=put_wvalue(ADDA_PR_CFG_REG,reg);


	reg=get_wvalue(ADDA_PR_CFG_REG);
	reg&=~(0xff<<8);
	reg|=(data<<8);
	reg=put_wvalue(ADDA_PR_CFG_REG,reg);

	reg=get_wvalue(ADDA_PR_CFG_REG);
	reg|=(0x1<<24);
	reg=put_wvalue(ADDA_PR_CFG_REG,reg);


	reg=get_wvalue(ADDA_PR_CFG_REG);
	reg&=~(0x1<<24);
	reg=put_wvalue(ADDA_PR_CFG_REG,reg);
}

#define REAL_VOLUME_MAX (0x3c)  //for reg, volume value is 0 - REAL_VOLUME_MAX
#define VOLUME_MAX (100) //for sys_config, volume is 0 - VOLUME_MAX
#define DEFAULT_VOLUME (50)
int codec_audio_init(void)
{
	volatile int tmp_val = 0;
	volatile int cfg_reg = 0;

	int boottone_volume = DEFAULT_VOLUME;

	if (!script_parser_fetch("boottone", "boottone_volume", &boottone_volume, 1))
		printf("get volumn from sys_config:%d\n", boottone_volume);

	if(boottone_volume < 0 || boottone_volume > VOLUME_MAX)
	{
		printf("invalid volume %d, set to %d\n", boottone_volume, DEFAULT_VOLUME);
		boottone_volume = DEFAULT_VOLUME;
	}

	boottone_volume = boottone_volume*REAL_VOLUME_MAX/VOLUME_MAX;

	cfg_reg = _ADDA_CCU_BASE + ADDA_PLL_AUDIO_CTRL;
	tmp_val = 0x910d0d00;
	writel(tmp_val, cfg_reg);		//pll_audio setup
	writel(0xc000ac02,0x01c20284);		//decimal fractional frequency

	cfg_reg = _ADDA_CCU_BASE + 0x68;	//adda gating
	tmp_val = readl(cfg_reg);
	tmp_val |= 0x1 << 0;
	writel(tmp_val, cfg_reg);

	cfg_reg = _ADDA_CCU_BASE + 0x140;	//adda sclk 1X gating
	tmp_val = 0x80000000;
	writel(tmp_val, cfg_reg);

	cfg_reg = _ADDA_CCU_BASE + 0x224;	//pll_audio bias
	tmp_val = 0x10100000;
	writel(tmp_val, cfg_reg);

	cfg_reg = _ADDA_CCU_BASE + 0x2D0;	//adda reset
	tmp_val = readl(cfg_reg);
	tmp_val |= 0x1 << 0;
	writel(tmp_val, cfg_reg);

	sun8iw5_sound_udelay(100);

	cfg_reg = _ADDA_PHY_BASE + ADDA_I2S_APC;	//i2s_ap sdo_en
	tmp_val = readl(cfg_reg);
	tmp_val |= 0x1 << 8;
	writel(tmp_val, cfg_reg);

	cfg_reg = _ADDA_PHY_BASE + ADDA_I2S_AP_FORMAT0;	//i2s_ap word size:16 bclk
	tmp_val = readl(cfg_reg);
	tmp_val &= ~(0x3 << 2);
	tmp_val |= 0x0 << 2;
	writel(tmp_val, cfg_reg);

	cfg_reg = _ADDA_PHY_BASE + ADDA_I2S_AP_FORMAT0;	//i2s_ap word size
	tmp_val = readl(cfg_reg);
	tmp_val &= ~(0x3 << 2);
	tmp_val |= 0x0 << 2;	//0:16 bclk  3:32 bclk
	writel(tmp_val, cfg_reg);

	cfg_reg = _ADDA_PHY_BASE + ADDA_I2S_AP_FIFOC;	//tx_fifo input mode
	tmp_val = readl(cfg_reg);
	tmp_val &= ~(0x1 << 2);
	tmp_val |= 0x1 << 2;
	writel(tmp_val, cfg_reg);

	cfg_reg = _ADDA_PHY_BASE + ADDA_I2S_AP_CLKD;	//bclk divide
	tmp_val = readl(cfg_reg);
	tmp_val &= ~(0x7 << 4);
	tmp_val |= 0x3 << 4;
	writel(tmp_val, cfg_reg);

	cfg_reg = _ADDA_PHY_BASE + ADDA_I2S_AP_CLKD;	//mclk divide
	tmp_val = readl(cfg_reg);
	tmp_val &= ~(0xf << 0);
	tmp_val |= 0x3 << 0;   //3:div 6; for 16k  0:div2; for 48k
	writel(tmp_val, cfg_reg);

	cfg_reg = _ADDA_PHY_BASE + ADDA_I2S_AP_CLKD;	//mclk en
	tmp_val = readl(cfg_reg);
	tmp_val &= ~(0x1 << 7);
	tmp_val |= 0x1 << 7;
	writel(tmp_val, cfg_reg);

	cfg_reg = _ADDA_PHY_BASE + ADDA_I2S_AP_TXCHSEL;	//tx channel select
	tmp_val = readl(cfg_reg);
	tmp_val &= ~(0x7 << 0);
	tmp_val |= 0x0 << 0;  //0:1ch 1:2ch
	writel(tmp_val, cfg_reg);

	cfg_reg = _ADDA_PHY_BASE + ADDA_SYSCLK_CTL;	//sys and aif1 clk en
	tmp_val = readl(cfg_reg);
	tmp_val &= ~((0x1 << 11)|(0x3 << 8)|(0x1 << 3));
	tmp_val |= (0x1 << 11)|(0x2 << 8)|(0x1 << 3);
	writel(tmp_val, cfg_reg);

	cfg_reg = _ADDA_PHY_BASE + ADDA_SYS_SR_CTRL;	//aif1 sample rate
	tmp_val = readl(cfg_reg);
	tmp_val &= ~(0x7 << 12);
	tmp_val |= 0x3 << 12;				//3:16k	8:48k
	writel(tmp_val, cfg_reg);

	cfg_reg = _ADDA_PHY_BASE + ADDA_AIF1CLK_CTRL;	//aif1 master or slave mode
	tmp_val = readl(cfg_reg);
	tmp_val &= ~(0x1 << 15);
	tmp_val |= 0x1 << 15;				//0:master mode  1:slave mode
	writel(tmp_val, cfg_reg);

	cfg_reg = _ADDA_PHY_BASE + ADDA_AIF1CLK_CTRL;	//aif1 bclk divide
	tmp_val = readl(cfg_reg);
	tmp_val &= ~(0xf << 9);
	tmp_val |= 0x9 << 9;				//9:48 divide   4:8 divide
	writel(tmp_val, cfg_reg);

	cfg_reg = _ADDA_PHY_BASE + ADDA_AIF1CLK_CTRL;	//aif1 lrck divide
	tmp_val = readl(cfg_reg);
	tmp_val &= ~(0x7 << 6);
	tmp_val |= 0x1 << 6;				//1:32 divide		2:64 divide
	writel(tmp_val, cfg_reg);

	cfg_reg = _ADDA_PHY_BASE + ADDA_AIF1CLK_CTRL;	//aif1 word size
	tmp_val = readl(cfg_reg);
	tmp_val &= ~(0x3 << 4);
	tmp_val |= 0x1 << 4;				//16bit
	writel(tmp_val, cfg_reg);

	cfg_reg = _ADDA_PHY_BASE + ADDA_AIF1_DACDAT_CTRL;	//aif1 da0 en
	tmp_val = readl(cfg_reg);
	tmp_val &= ~(0x3 << 14);
	tmp_val |= 0x3 << 14;
	writel(tmp_val, cfg_reg);

	cfg_reg = _ADDA_PHY_BASE + ADDA_DAC_MXR_SRC;	//select DAC mixer source
	tmp_val = readl(cfg_reg);
	tmp_val &= ~((0x1 << 15)|(0x1 << 11));
	tmp_val |= (0x1 << 15)|(0x1 << 11);
	writel(tmp_val, cfg_reg);

	cfg_reg = _ADDA_PHY_BASE + ADDA_DAC_DIG_CTRL;	//enable digital dac
	tmp_val = readl(cfg_reg);
	tmp_val &= ~(0x1 << 15);
	tmp_val |= 0x1 << 15;
	writel(tmp_val, cfg_reg);

	cfg_reg = _ADDA_PHY_BASE + ADDA_MOD_CLK_ENA;	//aif1 clk en
	tmp_val = readl(cfg_reg);
	tmp_val &= ~(0x1 << 15);
	tmp_val |= 0x1 << 15;
	writel(tmp_val, cfg_reg);

	cfg_reg = _ADDA_PHY_BASE + ADDA_MOD_RST_CTL;	//aif1 reset
	tmp_val = readl(cfg_reg);
	tmp_val &= ~(0x1 << 15);
	tmp_val |= 0x1 << 15;
	writel(tmp_val, cfg_reg);

	cfg_reg = _ADDA_PHY_BASE + ADDA_MOD_CLK_ENA;	//dac clk en
	tmp_val = readl(cfg_reg);
	tmp_val &= ~(0x1 << 2);
	tmp_val |= 0x1 << 2;
	writel(tmp_val, cfg_reg);

	cfg_reg = _ADDA_PHY_BASE + ADDA_MOD_RST_CTL;	//dac reset
	tmp_val = readl(cfg_reg);
	tmp_val &= ~(0x1 << 2);
	tmp_val |= 0x1 << 2;
	writel(tmp_val, cfg_reg);

	cfg_reg = _ADDA_PHY_BASE + ADDA_I2S_APC;	//i2s_ap tx_en
	tmp_val = readl(cfg_reg);
	tmp_val |= 0x1 << 2;
	writel(tmp_val, cfg_reg);

	cfg_reg = _ADDA_PHY_BASE + ADDA_I2S_AP_INT;	//tx drq en
	tmp_val = readl(cfg_reg);
	tmp_val &= ~(0x1 << 7);
	tmp_val |= 0x1 << 7;
	writel(tmp_val, cfg_reg);

	cfg_reg = _ADDA_PHY_BASE + ADDA_I2S_APC;	//i2s_ap globe en
	tmp_val = readl(cfg_reg);
	tmp_val |= 0x1 << 0;
	writel(tmp_val, cfg_reg);

	put_adda_wvalue(0x0,boottone_volume);	//hp volume
	put_adda_wvalue(0x1,0x2);	//left output mixer select DACL
	put_adda_wvalue(0x2,0x2);	//right output mixer select DACR
	put_adda_wvalue(0x3,0xcc);	//dac en and PA input source select dac
	put_adda_wvalue(0x7,0x54);	// HPR inverting output
	sun8iw5_sound_mdelay(10);       //necessaey!!!
	put_adda_wvalue(0x7,0xD4);	//PA en

	return 0;
}

static int codec_dma_send_start(u16 * pbuf, uint byte_cnt)
{
	int ret =0;
	flush_cache((uint)pbuf, byte_cnt);

	ret = sunxi_dma_start(codec_tx_dma_hd, (uint)pbuf, _ADDA_PHY_BASE + ADDA_I2S_AP_TXDATA, byte_cnt);

	return ret;
}


int codec_dma_exit(void)
{
	if(codec_tx_dma)
		free(codec_tx_dma);

	sunxi_dma_release(codec_tx_dma_hd);

	return 0;
}

static void sunxi_dma_tx(void *data)
{
	static int  i = 0;
	//	i++;
	if (i < 100)
		return;

	sunxi_dma_stop(codec_tx_dma_hd);
	codec_dma_exit();
	printf("codec sunxi_dma_tx\n");
}

int set_reg_by_wav_header(struct wav_header* wav)
{
	if (is_valid_wav_header(wav))
	{
		printf("set sample_rate:%d\n",wav->sample_rate);
		set_sample_rate(wav->sample_rate);
	}
	return 0;
}

#if 0
int load_tone_from_partition(u16 **tone_buf_p, int *tone_size_p)
{

	uint   tone_start, tone_size;
	u16*  tone_buf ;
	sunxi_partition_init();
	tone_start = sunxi_partition_get_offset_byname("tone"); //tone partition
	//	tone_size =  sunxi_partition_get_size_byname("tone");
	tone_size = 128;  //TODO:fix me, why 512 not ok
	printf("tone_start = 0x%x\n", tone_start);
	printf("tone_size  =  %u\n", tone_size);
	if(tone_start && tone_size) {
		tone_buf = (u16*)malloc(tone_size*512);
		memset(tone_buf,0,tone_size*512);
		sunxi_flash_read(tone_start, tone_size, tone_buf);
		//sunxi_flash_read(tone_start + tone_size - (8192+512)/512, 1, buffer);
		sunxi_flash_flush();
		*tone_size_p = tone_size;
		*tone_buf_p = tone_buf;
		printf("tone_buf : %p tone_size  :  %u\n",tone_buf, tone_size);
		return 0;
	} else{
		*tone_buf_p = NULL;
		printf("fail to get tone partition\n");
		return -1;
	}

}
#endif
#if 0 //uboot2011 not support boot_package
int load_tone_from_boot0(u16 **tone_buf_p, int *tone_size_p)
{
	*tone_buf_p = (u16*)CONFIG_TONE_STORE_IN_DRAM_BASE;
	return 0;
}
#endif
int play_factory_tone(void)
{
	if (codec_play_audio_enable == 0)
	{
		printf("codec_play_audio_enable is 0\n");
		return 0;
	}
#ifdef CONFIG_LOAD_FACTORY_TONE_BY_ENV
	int ret = 0;
	/* here used to run load_factory_tone, but now just use load_boot_tone */
	printf("play same tone as boot, run load_boot_tone:%s\n", getenv("load_boot_tone"));
	ret = run_command(getenv("load_boot_tone"), 0);
	if (ret == 0)
	{
		printf("load factory tone success\n");
		set_factory_tone_size();
		printf("play factory tone\n");
		codec_play_audio();
		sun8iw5_sound_mdelay(1000);
	}
	else
	{
		printf("load factory tone fail\n");
	}
#else
	sun8iw5_sound_mdelay(50); /* make sure there is enough time between init regs and play, or the play may not complete */
	set_factory_tone_size();
	printf("play factory tone\n");
	codec_play_audio();
#endif
	codec_play_audio_enable = 0;
	return 0;
}

int play_boot_tone(void)
{
	if (codec_play_audio_enable == 0)
	{
		printf("codec_play_audio_enable is 0\n");
		return 0;
	}
#ifdef CONFIG_LOAD_BOOT_TONE_BY_ENV
	int ret = 0;
	printf("run load_boot_tone:%s\n", getenv("load_boot_tone"));
	ret = run_command(getenv("load_boot_tone"), 0);
	if (ret == 0)
	{
		printf("load boot tone success\n");
		set_boot_tone_size();
		printf("play boot tone\n");
		codec_play_audio();
	}
	else
	{
		printf("load boot tone fail\n");
	}
#else
	sun8iw5_sound_mdelay(50); /* make sure there is enough time between init regs and play, or the play may not complete */
	set_boot_tone_size();
	printf("play boot tone\n");
	codec_play_audio();
#endif
	codec_play_audio_enable = 0;
	return 0;
}

int get_boot_work_mode(void)
{
	return uboot_spare_head.boot_data.work_mode;
}

int codec_play_audio(void)
{
	int ret = 0;
	int workmode = get_boot_work_mode();
	u16* buf_start;
	int buf_size = 0;

	printf("codec_play_audio\n");
	if (workmode != WORK_MODE_BOOT)
		return 0;

	if ( need_play_tone() == 0 )
		return 0;

	if (codec_play_audio_enable == 0)
	{
		printf("codec_play_audio_enable is 0\n");
		return 0;
	}

	set_reg_by_wav_header((struct wav_header*)tone_buf_global);
	printf("codec_play_audio start\n");
	buf_start = tone_buf_global + tone_skip_size_global;
	buf_size = tone_size_global - tone_skip_size_global;
	buf_size &= 0x3fc00;   /* limit to 256k , align to 1024bytes */
	printf("dma buff size:%d 0x%x\n", buf_size, buf_size);
	ret = codec_dma_send_start(buf_start, buf_size);
	if(ret < 0) {
		printf("codec_dma_send_start error = %d\n",ret);
	}

	//      exit will cause some error, so just let it go
	//	codec_dma_exit();


	printf("codec_play_audio end\n");
	return 0;
}

int set_sample_rate(int sample_rate)
{
	return 0;
}

int get_tone_size_from_wav_header(struct wav_header* wav)
{
	int tone_size = -1;
	//dump_wav_header(wav);
	if (is_valid_wav_header(wav))
	{
		tone_size = wav->wav_size + 8;
		printf("get size from wav header:%d\n", tone_size);
	}
	else
	{
		printf("not a valid wav header\n");
	}

	return tone_size;
}

int get_boot_tone_size_from_sysconfig(void)
{
	int boottone_size = -1;
	if (!script_parser_fetch("boottone", "boottone_size", &boottone_size, 1))
		printf("get size from sys_config:%d\n", boottone_size);

	return boottone_size;
}

#if 0 //uboot2011 not support boot_package
int get_boot_tone_size_from_boot0(void)
{
	int tone_size = uboot_spare_head.boot_ext[1].data[0];
	printf("get size from boot0 :%d\n", tone_size);
	return tone_size;
}
#endif

int set_boot_tone_size(void)
{
	tone_size_global = get_boot_tone_size_from_sysconfig();

#if 0 //uboot2011 not support boot_package
	if (tone_size_global <= 0)
	{
		tone_size_global = get_boot_tone_size_from_boot0();
	}
#endif
	if (tone_size_global <= 0)
	{
		tone_size_global = get_tone_size_from_wav_header((struct wav_header*)tone_buf_global);
	}

	printf("tone_size_global:%d\n", tone_size_global);
	return 0;
}

int set_factory_tone_size(void)
{
	tone_size_global = get_tone_size_from_wav_header((struct wav_header*)tone_buf_global);

	printf("tone_size_global:%d\n", tone_size_global);
	return 0;
}

int need_play_tone(void)
{
	int boottone_used = 0;

	int workmode = get_boot_work_mode();
	if (workmode != WORK_MODE_BOOT)
		return 0;

	if (!script_parser_fetch("boottone", "boottone_used", &boottone_used, 1)) {
		printf("boottone_used = %d\n", boottone_used);
		if (boottone_used == 0)
			return 0;
	} else {
		printf("can not get boottone_used\n");
		return 0;
	}

	return 1;
}

/* Call me early enough to make sure codec have enough time to prepare */
int codec_play_audio_prepare_step1(void)
{
	if ( need_play_tone() == 0 )
		return 0;

	printf("codec_play_audio start\n");
	codec_audio_init();
	return 0;
}

/* Call me early, but after dma is ready */
int codec_play_audio_prepare_step2(void)
{
	int ret = 0;

	if ( need_play_tone() == 0 )
		return 0;


#if 0 //uboot2011 not support boot_package
	tone_buf_global = NULL;
	load_tone_from_boot0(&tone_buf_global, &tone_size_global);

	if(tone_buf_global == NULL) {
		printf("tone_buf is NULL\n");
		return 0;
	}
#endif

	codec_tx_dma  = malloc_noncache(sizeof(sunxi_dma_setting_t));
	if(!(codec_tx_dma)) {
		printf("no enough memory to malloc\n");
		return -1;
	}
	memset(codec_tx_dma , 0 , sizeof(sunxi_dma_setting_t));

	//codec_tx_dma_hd = sunxi_dma_request(DMAC_DMATYPE_NORMAL);
	codec_tx_dma_hd = sunxi_dma_request_from_last(DMAC_DMATYPE_NORMAL);
	if((codec_tx_dma_hd == 0)) {
		printf("codec_tx_dma_hd request dma failed\n");
		return -1;
	}

	codec_tx_dma->cfg.src_drq_type     = DMAC_CFG_TYPE_DRAM;
	codec_tx_dma->cfg.src_addr_mode    = DMAC_CFG_SRC_ADDR_TYPE_LINEAR_MODE;
	codec_tx_dma->cfg.src_burst_length = DMAC_CFG_SRC_1_BURST;
	codec_tx_dma->cfg.src_data_width   = DMAC_CFG_SRC_DATA_WIDTH_32BIT;//DMAC_CFG_SRC_DATA_WIDTH_32BIT;

	codec_tx_dma->cfg.dst_drq_type     = 0x0F;                           //DMAC_CFG_DEST_TYPE_CODEC
	codec_tx_dma->cfg.dst_addr_mode    = DMAC_CFG_DEST_ADDR_TYPE_IO_MODE;//DMAC_CFG_DEST_ADDR_TYPE_LINEAR_MODE;
	codec_tx_dma->cfg.dst_burst_length = DMAC_CFG_DEST_1_BURST;
	codec_tx_dma->cfg.dst_data_width   = DMAC_CFG_DEST_DATA_WIDTH_16BIT;//DMAC_CFG_DEST_DATA_WIDTH_32BIT
	codec_tx_dma->wait_cyc		   = 7;
	codec_tx_dma->loop_mode		   = 0;
	codec_tx_dma->data_block_size	   = 1 * 16/8;

	ret = sunxi_dma_setting(codec_tx_dma_hd, (void *)codec_tx_dma);
	if(ret < 0) {
		printf("sunxi_dma_setting error = %d\n",ret);
	}

	ret = sunxi_dma_enable_int(codec_tx_dma_hd);
	if(ret < 0) {
		printf("sunxi_dma_enable_int error = %d\n",ret);
	}

	sunxi_dma_install_int(codec_tx_dma_hd,sunxi_dma_tx,0);

	return 0;
}

/* Call me to enable speaker, enable too early may cause pop */
int codec_play_audio_prepare_step3(void)
{
	tone_buf_global = (u16 *)simple_strtoul(getenv("uboot_tone_addr"), NULL, 16);
	/* printf("tone_buf_global:%p\n", tone_buf_global); */
	gpio_request_simple("boottone", NULL);
	return 0;
}

int do_boottone (cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	//	sun8iw5_sound_mdelay(800);
	u16* tone_buf_global_tmp = NULL;
	int tone_size_global_tmp;
	int codec_play_audio_enable_tmp;

	if (argc >= 2)
	{
		tone_buf_global_tmp = tone_buf_global;
		tone_buf_global = (u16 *)simple_strtoul(argv[1], NULL, 16);
	}
	if (argc >= 3)
	{
		tone_size_global_tmp  = tone_size_global;
		tone_size_global = simple_strtoul(argv[2], NULL, 16);
	}
	printf("play tone buffer 0x%x\n",(int)tone_buf_global);
	printf("play tone size %d\n", tone_size_global);

	codec_play_audio_enable_tmp = codec_play_audio_enable;
	codec_play_audio_enable = 1;
	codec_play_audio();
	codec_play_audio_enable = codec_play_audio_enable_tmp;

	if (argc >= 2)
		tone_buf_global = tone_buf_global_tmp;

	if (argc >= 3)
		tone_size_global = tone_size_global_tmp;
	return 0;
}

int do_play_boot_tone (cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	play_boot_tone();
	return 0;
}

int do_play_factory_tone (cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	play_factory_tone();
	return 0;
}

U_BOOT_CMD(
		boottone,	4,	1,	do_boottone,
		"boottone   - play boot tone\n",
		"argv1: tone_buff\n argv2: tone_size"
	  );

U_BOOT_CMD(
		play_boot_tone,	1,	1,	do_play_boot_tone,
		"play_boot_tone   - play boot tone\n",
		"for debug"
	  );

U_BOOT_CMD(
		play_factory_tone,	1,	1,	do_play_factory_tone,
		"play_factory_tone   - play factory tone\n",
		"for debug"
	  );






