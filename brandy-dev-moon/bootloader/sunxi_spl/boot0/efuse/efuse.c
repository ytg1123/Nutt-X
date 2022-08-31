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
#include <asm/io.h>
#include "efuse.h"

uint sid_read_key(uint key_index)
{
	uint reg_val;
	reg_val = readl(SID_PDKEY + key_index);

	return reg_val;
}

int sid_read_oemid(void)
{
	int ret= -1;
	uint val;
	uint chipid_index = EFUSE_OEM_ID;
	uint id_length = 1;
	uint i = 0;

	for (i = 0 ; i < id_length ; i++) {
		val = sid_read_key(chipid_index + i * 4);
		printf("cid:0x%x\n",val);
		if(val == 0x5A7213) {
			ret = 0;
		}

	}
	return ret;
}
