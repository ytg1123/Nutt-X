//*****************************************************************************
//	File name  : 				interface.h
//
//	Description:  This file provides all functions of i2c operation.
//
//  written by :  jason
//	History    :
//                 2015/04/13      jason       v0.1    Initial version
//                 2015/04/24      jason       v0.1    modify iWriteData()
//                 2015/05/31      jason       v1.0    added iSleep()
//******************************************************************************
#include <common.h>
#include <asm/arch/sw2001_verify/interface.h>
#include <asm/arch/twi.h>

uint8_t SLAVE_ADDR;

//******************************************************************************
// function    : iDeviceInit(uint8_t device_addr, uint8_t speed)
// description : initial the i2c, including configure pin, device address and speed
// parameters  :
//               devaddr : device address for i2c
//               speed: interface speed for i2c
//               |       0 : 100k
//               |       1 : 400k
// return      :
//               TRUE : sucess
//               FALSE : fail
//*******************************************************************************
BOOL iDeviceInit(uint8_t device_addr, uint8_t speed)
{
	//user implement, config pin, device address and speed
	SLAVE_ADDR = device_addr;
	i2c_init(speed, device_addr);

	return TRUE;
}

//*******************************************************************************
// function    : iDeviceDeInit()
// description : Deinitializes the i2c, release resource
// return      :
//               TRUE : success
//               FALSE : fail
//********************************************************************************
BOOL iDeviceDeInit(void)
{
	//user implement, release i2c resource
	i2c_exit();

	return TRUE;
}

//********************************************************************************
// function    : iWriteByte(uint8_t addr, uint8_t data)
// description : write data to byte addr(internal register address in device)
// parameters  :
//                addr : register address in device
//                data:  data
// return        :
//               TRUE : success
//               FALSE : fail
//*********************************************************************************
BOOL iWriteByte(uint8_t addr, uint8_t data)
{
	//user implement, transimit data to slave
	uint8_t txBuf[1];
	txBuf[0] = data;
	i2c_write(SLAVE_ADDR, addr, 1, txBuf, 1);

    return TRUE;
}

//*********************************************************************************
// function    : iReadByte(uint8_t addr, uint8_t data)
// description :  read data from addr(internal register address in device)
// parameters  :
//                  addr : register address in device
//                  data:  data
// return        :
//               TRUE : success
//               FALSE : fail
//*********************************************************************************
BOOL iReadByte(uint8_t addr, uint8_t *data)
{
	//user implement, receive data from slave
	i2c_read(SLAVE_ADDR, addr, 1, data, 1);

	return TRUE;
}

//*********************************************************************************
// function    : iSleep(uint8_t waittime)
// description :  host wait time, during this time  host cpu can do other thing
// parameters  :
//                  waittime : sleep time(ms)
// return        :
//               TRUE : success
//               FALSE : fail
//*********************************************************************************
BOOL iSleep(uint8_t waittime)
{
	//user implement, sleep
	return TRUE;
}

//********************************************************************************
// function    : iWriteData(uint8_t addr, uint8_t *data, uint8_t len)
// description : write len bytes data to byte addr(internal address in device)
// parameters  :
//                addr : byte address in device
//                data:  data pointer
//                len  :  data length
// return        :
//               TRUE : success
//               FALSE : fail
//*********************************************************************************
BOOL iWriteData(uint8_t addr, uint8_t *data, uint8_t len)
{
	uint8_t i;
	uint8_t *pt=data;
	for(i=0;i<len;i++)
	{
		if(iWriteByte(addr+i,*pt++)!=TRUE)
		{
			//printf("iwritedata function failed!");
			return FALSE;
		}
	}
	return TRUE;
}

//*********************************************************************************
// function    : iReadData(uint8_t addr, uint8_t *data, uint8_t len)
// description :  read len bytes from addr(internal address in device)
// parameters  :
//                  addr : byte address in device
//                  data:  data pointer
//                   len :  data length
// return        :
//               TRUE : success
//               FALSE : fail
//*********************************************************************************
BOOL iReadData(uint8_t addr, uint8_t *data, uint8_t len)
{
	uint8_t i;
	uint8_t temp,*pt=data;
	for(i=0;i<len;i++)
	{
        temp = 0;
		if(iReadByte(addr+i,&temp) != TRUE)
		{
			//printf("ireaddata failed\n");
			return FALSE;
		}
		*pt++ = temp;
	}
	return TRUE;
}


//*********************************************************************************
// function    : iSetBit(uint8_t addr, uint8_t bit)
// description :  set 1 to bit in byte
// parameters  :
//                   addr : byte address in device
//                   bit:  position for set in byte
// return        :
//               TRUE : success
//               FALSE : fail
//*********************************************************************************
BOOL iSetBits(uint8_t addr, uint8_t bit)
{
	uint8_t data;
	if(iReadByte(addr,&data)!=TRUE)
	{
		return FALSE;
	}
	data |= bit;
	if(iWriteByte(addr,data)!=TRUE)
	{
		return FALSE;
	}
	return TRUE;
}

//*********************************************************************************
// function    : iClearBit(uint8_t addr, uint8_t bit)
// description :  set 0 to bit in byte
// parameters  :
//                   addr : byte address in device
//                   bit:  position for clear in byte
// return        :
//               TRUE : success
//               FALSE : fail
//*********************************************************************************
BOOL iClearBits(uint8_t addr, uint8_t bit)
{
	uint8_t data;
	if(iReadByte(addr,&data)!=TRUE)
	{
		return FALSE;
	}
	data &= ~bit;
	if(iWriteByte(addr,data)!=TRUE)
	{
		return FALSE;
	}
	return TRUE;
}

//*********************************************************************************
// function    : iCheckBits(uint8_t addr, uint8_t mask, uint8_t ref)
// description :  wait the value  of register equal to ref
// parameters  :
//                   addr : register address in device
//                   mask:  mask bit
//                   ref:  compare data
// return        :
//               TRUE : success
//               FALSE : fail
//*********************************************************************************
BOOL iCheckBits(uint8_t addr, uint8_t mask, uint8_t ref)
{
	uint8_t data=0;
//	iSleep(3);  //wait for aes complete
                // it don't really used
	do
	{
		if(iReadByte(addr,&data)!=TRUE)
		{
			return FALSE;
		}
	}while((data&mask) != ref);

	return TRUE;
}
