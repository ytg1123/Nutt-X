//*****************************************************************************
//	File name  : 				interface.h
//
//	Description:  This file provides all functions prototypes of the serial bus operation.
//	
//  written by :  jason
//	History    :
//                 2015/04/13      jason       v0.1    Initial version
//                 2015/05/31      jason       v1.0    added iSleep function
//******************************************************************************
#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include "type.h"

//i2c device address
#define SW2001_DEVICE_ADDR 0x3C

//sw2001 cipher text start address
#define SW2001_REG_CIPHER_TEXT_ADDR 0x10

//sw2001 plaint text start address
#define SW2001_REG_PLAINT_TEXT_ADDR 0x10

//sw2001 aes control addr
#define SW2001_REG_DECRYPT_CTRL 0x00

#define SW2001_AES_ENABLE (0x01)

#define SW2001_AES_STATUS (0x20) 

BOOL iDeviceInit(uint8_t device_addr, uint8_t speed);
BOOL iDeviceDeInit(void);
BOOL iWriteByte(uint8_t addr, uint8_t data);
BOOL iReadByte(uint8_t addr, uint8_t *data);
BOOL iSleep(uint8_t waittime);
BOOL iWriteData(uint8_t addr, uint8_t *data, uint8_t len) ;
BOOL iReadData(uint8_t addr, uint8_t *data, uint8_t len);
BOOL iSetBits(uint8_t addr, uint8_t bit);
BOOL iClearBits(uint8_t addr, uint8_t bit);BOOL iCheckBits(uint8_t addr, uint8_t mask, uint8_t ref);

#define TRUE (0)
#define FALSE (-1)
#endif
