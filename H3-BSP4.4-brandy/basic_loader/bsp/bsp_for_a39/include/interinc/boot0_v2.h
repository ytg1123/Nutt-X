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

#define FES1_RUN_ADDR                   (0x12000)
//fel?????fes_aide???????????????????, 0x7210
#define FES1_DRAM_RET_ADDR    			(EGON2_SRAM_BASE + 0x7210)
#define	SYS_PARA_LOG         			(0x4d415244)   //dram_log


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

//???????ṩ??SDMMC??ʹ?ã??̶????ɸı?
#define BOOT0_SDMMC_START_ADDR          16

typedef struct standard_Boot_file_head
{
	__u32  jump_instruction;   // one intruction jumping to real code
	__u8   magic[8];           // ="eGON.BT0" or "eGON.BT1",  not C-style string.
	__u32  check_sum;          // generated by PC
	__u32  length;             // generated by PC
	__u32  pub_head_size;      // the size of boot_file_head_t
	__u8   pub_head_vsn[4];    // the version of boot_file_head_t
	__u32  ret_addr;           // the return value
	__u32  run_addr;           // run addr
	__u8   eGON_vsn[4];        // eGON version
	__u8   platform[8];        // platform information
}standard_boot_file_head_t;
/******************************************************************************/
/*                              file head of Boot0                            */
/******************************************************************************/
typedef struct _boot0_private_head_t
{
	__u32                       prvt_head_size;
	char                        prvt_head_vsn[4];       // the version of boot0_private_head_t
	unsigned int                dram_para[32];          // DRAM patameters for initialising dram. Original values is arbitrary,
	__s32						uart_port;              // UART??????????
	normal_gpio_cfg             uart_ctrl[2];           // UART??????(???Դ?ӡ??)??????Ϣ
	__s32                       enable_jtag;            // 1 : enable,  0 : disable
    normal_gpio_cfg	            jtag_gpio[5];           // ????JTAG??ȫ??GPIO??Ϣ
    normal_gpio_cfg             storage_gpio[32];       // ?洢?豸 GPIO??Ϣ
    char                        storage_data[512 - sizeof(normal_gpio_cfg) * 32];      // ?û???????????Ϣ
    //boot_nand_connect_info_t    nand_connect_info;
}boot0_private_head_t;


typedef struct _boot0_file_head_t
{
	standard_boot_file_head_t   boot_head;
	boot0_private_head_t  		prvt_head;
}boot0_file_head_t;






#endif     //  ifndef __boot0_h

/* end of boot0.h */
