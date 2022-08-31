/*
**********************************************************************************************************************
*
*						           the Embedded Secure Bootloader System
*
*
*						       Copyright(C), 2006-2014, Allwinnertech Co., Ltd.
*                                           All Rights Reserved
*
* File    :
*
* By      :
*
* Version : V2.00
*
* Date	  :
*
* Descript:
**********************************************************************************************************************
*/
#include <common.h>
#include <private_boot0.h>
#include <asm/arch/clock.h>
#include <asm/arch/timer.h>
#include <asm/arch/uart.h>
#include <asm/arch/dram.h>
#include <asm/arch/rtc_region.h>
#include <asm/arch/gpio.h>
#include "../libs/sbrom_libs.h"

#include <asm/arch/sw2001_verify/sw2001.h>
#include <asm/arch/rsb.h>
#include <power/axp22_reg.h>

#ifdef CONFIG_BOOT_A15
#include <asm/arch/cpu_switch.h>
#endif
// rsb AXP22x address
#define RSB_SADDR_AXP22x	0x3A3 

extern const boot0_file_head_t  BT0_head;

static void print_version(void);
static void print_commit_log(void);
static int boot0_clear_env(void);
#ifdef	SUNXI_OTA_TEST
static void print_ota_test(void);
#endif
static int boot0_check_uart_input(void);

extern int load_boot1(void);

extern void set_debugmode_flag(void);

void __attribute__((weak)) bias_calibration(void)
{
	return;
}

/**
 * 设置 AXP22x 中 DLDO1 输出电压大小，用于 sw2001
 * @param: 
 * 		vol - 输出电压 (0x00 ~ 0x1F) <=> (0.7 ~ 3.3), 100mV/step
 */
void AXP22X_setDLDO1(unsigned char vol)
{
	u8 rsb_txBuf[1] = {0};
	
	sunxi_rsb_init(AXP22_ADDR);
	sunxi_rsb_config(AXP22_ADDR, RSB_SADDR_AXP22x);
	// 打开 DLDO1 通路 	
	rsb_txBuf[0] = (1<<3);
	sunxi_rsb_write(AXP22_ADDR, BOOT_POWER22_OUTPUT_CTL2, rsb_txBuf, 1);
	// 设置 DLDO1 电压
	rsb_txBuf[0] = vol;
	sunxi_rsb_write(AXP22_ADDR, BOOT_POWER22_DLDO1_VOL, rsb_txBuf, 1);
}

/**
 * 关闭 DLDO1 通路，以免影响 uboot 阶段对 AXP 的配置
 */
void AXP22_closeDLDO1(void)
{
	u8 rsb_txBuf[1] = {0};
	u8 rsb_rxBuf[1] = {0};

	// close DLDO1 	
	sunxi_rsb_read(AXP22_ADDR, BOOT_POWER22_OUTPUT_CTL2, rsb_rxBuf, 1);
	rsb_txBuf[0] = rsb_rxBuf[0] & (~(0x01<<3));
	sunxi_rsb_write(AXP22_ADDR, BOOT_POWER22_OUTPUT_CTL2, rsb_txBuf, 1);
}

/*******************************************************************************
*函数名称: Boot0_C_part
*函数原型：void Boot0_C_part( void )
*函数功能: Boot0中用C语言编写的部分的主流程
*入口参数: void
*返 回 值: void
*备    注:
*******************************************************************************/
void main( void )
{
	__u32 status;
	__s32 dram_size;
	int   ddr_aotu_scan = 0;
#ifdef CONFIG_BOOT_A15
	special_gpio_cfg a15_power_gpio;	//a15 extern power enabel gpio
#endif
    __u32 fel_flag;
    __u32 boot_cpu=0;
    //normal_gpio_set_t gpio_pg10_pl7[] = {{ 7, 10, 1, -1, -1, 0, {0}}, { 12, 7, 0, -1, -1, -1, {0}}};
    //boot_set_gpio(gpio_pg10_pl7,2,1);
//#ifdef CONFIG_XXX    
    normal_gpio_set_t gpio_pg10 = { 7, 10, 1, -1, -1, 0, {0}};
    normal_gpio_set_t gpio_pl7 = { 12, 7, 0, -1, -1, -1, {0}};
    boot_set_one_gpio(&gpio_pg10, 1);
    boot_set_one_gpio(&gpio_pl7, 1);
{
/*---------------------------------------------------------------------------------------------------------
; port configuration:
; port_name = port:GPIO<mux><pull up/down><driver level><default value>
; mux: GPIO function configuration, 0-input, 1-output, 2+: special funciton for modules
; pull up/down: 1-pull up, 2-pull down
; driver level: 0,1,2,3. 2 is recommended
; default value: default output value when this IO is configured as an output IO
;---------------------------------------------------------------------------------------------------------*/
    #define SUNXI_PIO_BASE 0X01C20800
    #define SUNXI_R_PIO_BASE 0X01F02C00
    #define R_PIO_REG_DATA(n) ((volatile unsigned int *)( SUNXI_R_PIO_BASE + ((n)-12)*0x24 + 0x10))
    
    __u32 port;
    __u32 tmp_data_data = 0;
    __u32 port_num;
    volatile __u32 *tmp_data_addr = NULL;
    port = gpio_pl7.port;
    port_num = gpio_pl7.port_num;
    tmp_data_addr = R_PIO_REG_DATA(port);
    tmp_data_data = GPIO_REG_READ(tmp_data_addr);
    //printf("tmp_data_data=%d\n", tmp_data_data);
    if(!(tmp_data_data & (1 << port_num))){
        port = gpio_pg10.port;
        port_num = gpio_pg10.port_num;
        tmp_data_addr = PIO_REG_DATA(port);
        GPIO_REG_WRITE(tmp_data_addr, 1 << port_num);
    }

}
//#endif

    bias_calibration();
    timer_init();
    sunxi_serial_init( BT0_head.prvt_head.uart_port, (void *)BT0_head.prvt_head.uart_ctrl, 6 );
        set_debugmode_flag();
	if( BT0_head.prvt_head.enable_jtag )
    {
    	boot_set_gpio((normal_gpio_cfg *)BT0_head.prvt_head.jtag_gpio, 6, 1);
    }
	printf("HELLO! BOOT0 is starting!\n");
	print_version();
        print_commit_log();
	boot0_check_uart_input();
#ifdef	SUNXI_OTA_TEST
	print_ota_test();
#endif

#ifdef CONFIG_ARCH_SUN7I
	reset_cpux(1);
#endif
    fel_flag = rtc_region_probe_fel_flag();
    if(fel_flag == SUNXI_RUN_EFEX_FLAG)
    {
        rtc_region_clear_fel_flag();
    	printf("eraly jump fel\n");

    	goto __boot0_entry_err0;
    }
#ifdef CONFIG_BOOT_A15
//	printf("BT0_head.boot_head.boot_cpu=0x%x\n", BT0_head.boot_head.boot_cpu);
//	if(BT0_head.boot_head.boot_cpu)
//	{
//		fel_flag = BOOT_A7_FLAG;
//	}
//	else
//	{
//		fel_flag = BOOT_A15_FLAG;
//	}
/*
    boot_cpu  含义

	bit0~7                       bit8~15

	0:不需要保存标志位           1:当前应该切换a15启动
	1:通知u-boot保存             0:当前应该切换a7启动

	每次从brom读取的boot_cpu只能是0x100或者0
*/
	boot_cpu = BT0_head.boot_head.boot_cpu;
	a15_power_gpio = BT0_head.boot_head.a15_power_gpio;
	if(fel_flag == BOOT_A15_FLAG)
	{
		rtc_region_clear_fel_flag();
		if(boot_cpu == 0x00)    //如果原本是a7启动
			boot_cpu = 0x101;   //a15启动，需要保存标志位

		switch_to_a15(a15_power_gpio);
	}
	else if(fel_flag == BOOT_A7_FLAG)
	{
		rtc_region_clear_fel_flag();
		if(boot_cpu == 0x100)      //如果原本是a15启动
			boot_cpu = 0x01;       //a7启动，需要保存标志位
	}
	else
	{
		if(boot_cpu == 0x100)
		{
			switch_to_a15(a15_power_gpio);                //a15启动，不需要保存标志位
		}
		else
		{
			boot_cpu = 0x0;    //a7启动，不需要保存标志位
		}
	}
//  printf("BT0_head.boot_head.boot_cpu=0x%x\n", BT0_head.boot_head.boot_cpu);
#endif
	mmu_setup();

    ddr_aotu_scan = 0;
	dram_size = init_DRAM(ddr_aotu_scan, (void *)BT0_head.prvt_head.dram_para);
	if(dram_size)
	{
	    //mdfs_save_value();
		printf("dram size =%d\n", dram_size);
	}
	else
	{
		printf("initializing SDRAM Fail.\n");

		goto  __boot0_entry_err;
	}
#if defined(CONFIG_ARCH_SUN9IW1P1)
	__msdelay(100);
#endif

#ifdef CONFIG_ARCH_SUN7I
    check_super_standby_flag();
#endif 

	printf("========= sw2001_verify ============\n");
	AXP22X_setDLDO1(0x1F);	// 设置 DLDO1 电压为 3.3V
	if (sw2001_verify()) {
		printf("sw2001_verify success!\n");
	} else {
		printf("sw2001_verify failed!\n");
	}
	AXP22_closeDLDO1();
	printf("====================================\n");

	status = load_boot1();

	printf("Ready to disable icache.\n");

	mmu_turn_off( );                               // disable instruction cache

	if( status == 0 )
	{
		//跳转之前，把所有的dram参数写到boot1中
		set_dram_para((void *)&BT0_head.prvt_head.dram_para, dram_size, boot_cpu);
		printf("Jump to secend Boot.\n");

		boot0_jump(CONFIG_SYS_TEXT_BASE);		  // 如果载入Boot1成功，跳转到Boot1处执行
	}

__boot0_entry_err:
#ifdef CONFIG_BOOT_A15
	if(!(boot_cpu & 0xff00))
	{
		boot0_clear_env();

		boot0_jump(FEL_BASE);
	}
	else
	{
		rtc_region_set_flag(SUNXI_RUN_EFEX_FLAG);
		boot0_clear_env();

		watchdog_enable();
	}
#endif
__boot0_entry_err0:
	boot0_clear_env();

	boot0_jump(FEL_BASE);
}
/*
************************************************************************************************************
*
*                                             function
*
*    name          :
*
*    parmeters     :
*
*    return        :
*
*    note          :
*
*
************************************************************************************************************
*/
static void print_version(void)
{

	printf("boot0 version : %s\n", BT0_head.boot_head.platform + 2);

	return;
}

extern char boot0_hash_value[64];
static void print_commit_log(void)
{
        printf("boot0 commit : %s \n",boot0_hash_value);

        return ;
}
/*
************************************************************************************************************
*
*                                             function
*
*    name          :
*
*    parmeters     :
*
*    return        :
*
*    note          :
*
*
************************************************************************************************************
*/
static int boot0_clear_env(void)
{

	reset_pll();
	mmu_turn_off();

	__msdelay(10);

	return 0;
}


/*
************************************************************************************************************
*
*                                             function
*
*    name          :
*
*    parmeters     :
*
*    return        :
*
*    note          :
*
*
************************************************************************************************************
*/
#ifdef	SUNXI_OTA_TEST
static void print_ota_test(void)
{
	printf("*********************************************\n");
	printf("*********************************************\n");
	printf("*********************************************\n");
	printf("*********************************************\n");
	printf("********[OTA TEST]:update boot0 sucess*******\n");
	printf("*********************************************\n");
	printf("*********************************************\n");
	printf("*********************************************\n");
	printf("*********************************************\n");
	return;
}
#endif

static int boot0_check_uart_input(void)
{
        int c = 0;
        int i = 0;
        for(i = 0;i < 3;i++)
        {
                __msdelay(10);
                if(sunxi_serial_tstc())
                {
                        c = sunxi_serial_getc();
                        break;
                }
        }

        if(c == '2')
        {
		printf("enter 0x%x,ready jump to fes\n", c-0x30);  // ASCII to decimal digit
		boot0_clear_env();
		boot0_jump(FEL_BASE);
        }
        return 0;
}
