/*
************************************************************************************************************************
*                                                         eGON
*                                         the Embedded GO-ON Bootloader System
*
*                             Copyright(C), 2006-2008, SoftWinners Microelectronic Co., Ltd.
*											       All Rights Reserved
*
* File Name   : boot0.h
*
* Author      : Gary.Wang
*
* Version     : 1.1.0
*
* Date        : 2009.05.21
*
* Description :
*
* Others      : None at present.
*
*
* History     :
*
*  <Author>        <time>       <version>      <description>
*
* Gary.Wang      2009.05.21       1.1.0        build the file
*
************************************************************************************************************************
*/
#ifndef  __boot0_v2_h
#define  __boot0_v2_h


#include "egon_def.h"
#include "egon_i.h"

#define UBOOT_BASE                      0x4a000000

#define BOOT0_START_BLK_NUM             0
#define BLKS_FOR_BOOT0                  2
#define BOOT0_LAST_BLK_NUM              ( BOOT0_START_BLK_NUM + BLKS_FOR_BOOT0 - 1 )

#define BOOT0_SPI_NOR_START_ADDR        0         // add for spi nor. by Gary,2009-12-8 11:47:17
#define SPI_NOR_SIZE_FOR_BOOT0          SZ_64K    // add for spi nor. by Gary,2009-12-8 11:47:17

#define BOOT0_MAGIC                     "eGON.BT0"

#define BOOT0_START_PAGE_NUM            0         // add for 1618
#define BOOT0_PAGE_ADVANCE              64        // add for 1618
#define BOOT0_PAGES_MAX_COUNT           ( BLKS_FOR_BOOT0 * 256 )      // add for 1618
#define BOOT0_PAGE_SIZE                 SZ_1K     // add for 1618
#define BOOT0_PAGE_SIZE_BIT_WIDTH       10        // add for 1618

#define BOOT0_23_START_PAGE_NUM         0         // add for 1623
#define BOOT0_23_PAGE_ADVANCE           64        // add for 1623
#define BOOT0_23_PAGES_MAX_COUNT        ( BOOT0_23_PAGE_ADVANCE * 8 )      // add for 1623
//#define BOOT0_23_PAGE_SIZE              SZ_1K     // add for 1623
#define BOOT0_23_PAGE_SIZE_BIT_WIDTH    10        // add for 1623

//??????????????????SDMMC??????????????????????????????
#define BOOT0_SDMMC_START_ADDR          16


typedef struct _boot_sdcard_info_t
{
	__s32				card_ctrl_num;                //?????????????????????
	__s32				boot_offset;                  //??????????????????????????????????????????????????????
	__s32 				card_no[4];                   //?????????????????????, 16-31:GPIO?????????0-15:????????????????????????
	__s32 				speed_mode[4];                //?????????????????????0???????????????????????????
	__s32				line_sel[4];                  //???????????????0: 1???????????????4???
	__s32				line_count[4];                //?????????????????????
}
boot_sdcard_info_t;

/******************************************************************************/
/*                              file head of Boot0                            */
/******************************************************************************/
typedef struct _boot0_private_head_t
{
	__u32                       prvt_head_size;
	__u8                        debug_mode;             // turn off print if realease
	__u8                        power_mode;             /*0:axp , 1: dummy pmu  */
	__u8                        reserve[2];
	unsigned int                dram_para[32];          // DRAM patameters for initialising dram. Original values is arbitrary,
	__s32                       uart_port;              // UART???????????????
	normal_gpio_cfg             uart_ctrl[2];           // UART?????????(???????????????)????????????
	__s32                       enable_jtag;            // 1 : enable,  0 : disable
	normal_gpio_cfg             jtag_gpio[5];           // ??????JTAG?????????GPIO??????
	normal_gpio_cfg             storage_gpio[32];       // ???????????? GPIO??????
	char                        storage_data[512 - sizeof(normal_gpio_cfg) * 32];      // ????????????????????????
	//boot_nand_connect_info_t    nand_connect_info;
}boot0_private_head_t;


typedef struct _boot0_file_head_t
{
	boot_file_head_t      boot_head;
	boot0_private_head_t  prvt_head;
}boot0_file_head_t;






#endif     //  ifndef __boot0_h

/* end of boot0.h */
