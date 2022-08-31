/*
 * (C) Copyright 2012 Henrik Nordstrom <henrik@henriknordstrom.net>
 *
 * Based on sun4i linux kernle i2c.h
 * (C) Copyright 2007-2012
 * Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 * Tom Cubie <tanglaing@allwinnertech.com>
 * Victor Wei <weiziheng@allwinnertech.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */
#ifndef _SUNXI_I2C_H_
#define _SUNXI_I2C_H_

struct i2c {
    u32 saddr;	/*  31:8bit reserved,7-1bit for slave addr,0 bit for GCE */
    u32 xsaddr;	/*  31:8bit reserved,7-0bit for second addr in 10bit addr */
    u32 data;	/*  31:8bit reserved, 7-0bit send or receive data byte */
    u32 ctl;	/*  INT_EN,BUS_EN,M_STA,INT_FLAG,A_ACK */
    u32 status;	/*  28 interrupt types + 0xF8 normal type = 29  */
    u32 clkr;	/*  31:7bit reserved,6-3bit,CLK_M,2-0bit CLK_N */
    u32 reset;	/*  31:1bit reserved;0bit,write 1 to clear 0. */
    u32 efr;	/*  31:2bit reserved,1:0 bit data byte follow read comand */
    u32 lctl;	/*  31:6bits reserved  5:0bit for sda&scl control*/
};

/* TWI address register */
#define TWI_GCE_EN      	(0x1 <<0) /* general call address enable for slave mode */
#define TWI_ADDR_MASK   	(0x7f<<1) /* 7:1bits */
#define TWI_XADDR_MASK		(0xff) /* 7:0bits for extend slave address */

#define TWI_DATA_MASK		(0xff) /* 7:0bits for send or received */

/* TWI Control Register Bit Fields */
/* 1:0 bits reserved */
#define TWI_CTL_ACK		(0x1<<2) /* set 1 to send A_ACK,then low level on SDA */
#define TWI_CTL_INTFLG		(0x1<<3) /* INT_FLAG,interrupt status flag: set '1' when interrupt coming */
#define TWI_CTL_STP		(0x1<<4) /* M_STP,Automatic clear 0 */
#define TWI_CTL_STA		(0x1<<5) /* M_STA,atutomatic clear 0 */
#define TWI_CTL_BUSEN		(0x1<<6) /* BUS_EN, master mode should be set 1.*/
#define TWI_CTL_INTEN		(0x1<<7) /* INT_EN */
/* 31:8 bit reserved */


/* TWI Clock Register Bit Fields & Masks,default value:0x0000_0000 */
/*
Fin is APB CLOCK INPUT;
Fsample = F0 = Fin/2^CLK_N; 
          F1 = F0/(CLK_M+1);
          
Foscl = F1/10 = Fin/(2^CLK_N * (CLK_M+1)*10); 
Foscl is clock SCL;standard mode:100KHz or fast mode:400KHz        
*/
#define TWI_CLK_DIV_M		(0xF<<3) /* 6:3bit  */
#define TWI_CLK_DIV_N		(0x7<<0) /* 2:0bit */
#define TWI_CLK_DIV(N,M)	((((N)&0xF)<<3)|(((M)&0x7)<<0))


/* TWI Soft Reset Register Bit Fields & Masks  */
#define TWI_SRST_SRST		(0x1<<0) /* write 1 to clear 0, when complete soft reset clear 0 */


/* TWI Enhance Feature Register Bit Fields & Masks  */
/* default -- 0x0 */
#define TWI_EFR_MASK        (0x3<<0)		/* 00:no,01: 1byte, 10:2 bytes, 11: 3bytes */
#define TWI_EFR_WARC_0      (0x0<<0)
#define TWI_EFR_WARC_1      (0x1<<0)
#define TWI_EFR_WARC_2      (0x2<<0)
#define TWI_EFR_WARC_3      (0x3<<0)


/* twi line control register -default value: 0x0000_003a */
#define TWI_LCR_SDA_EN          (0x01<<0) 	/* SDA line state control enable ,1:enable;0:disable */
#define TWI_LCR_SDA_CTL         (0x01<<1) 	/* SDA line state control bit, 1:high level;0:low level */
#define TWI_LCR_SCL_EN          (0x01<<2) 	/* SCL line state control enable ,1:enable;0:disable */
#define TWI_LCR_SCL_CTL         (0x01<<3) 	/* SCL line state control bit, 1:high level;0:low level */
#define TWI_LCR_SDA_STATE_MASK  (0x01<<4)	/* current state of SDA,readonly bit */
#define TWI_LCR_SCL_STATE_MASK  (0x01<<5)	/* current state of SCL,readonly bit */
/* 31:6bits reserved */
#define TWI_LCR_IDLE_STATUS     (0x3a)


/* TWI Status Register Bit Fields & Masks  */
#define TWI_STAT_MASK                   (0xff)
/* 7:0 bits use only,default is 0xF8 */
#define TWI_STAT_BUS_ERR		(0x00) 	/* BUS ERROR */
/* Master mode use only */
#define TWI_STAT_TX_STA			(0x08) 	/* START condition transmitted */
#define TWI_STAT_TX_RESTA		(0x10) 	/* Repeated START condition transmitted */
#define TWI_STAT_TX_AW_ACK		(0x18) 	/* Address+Write bit transmitted, ACK received */
#define TWI_STAT_TX_AW_NAK		(0x20) 	/* Address+Write bit transmitted, ACK not received */
#define TWI_STAT_TXD_ACK		(0x28) 	/* data byte transmitted in master mode,ack received */
#define TWI_STAT_TXD_NAK		(0x30) 	/* data byte transmitted in master mode ,ack not received */
#define TWI_STAT_ARBLOST		(0x38) 	/* arbitration lost in address or data byte */
#define TWI_STAT_TX_AR_ACK		(0x40) 	/* Address+Read bit transmitted, ACK received */
#define TWI_STAT_TX_AR_NAK		(0x48) 	/* Address+Read bit transmitted, ACK not received */
#define TWI_STAT_TX_2AW_ACK		(0xD0)	/* Second Address byte + Write bit transmitted, ACK received */
#define TWI_STAT_TX_2AW_NAK		(0xD8)	/* Second Address byte + Write bit transmitted, ACK received */
#define TWI_STAT_RXD_ACK		(0x50) 	/* data byte received in master mode ,ack transmitted */
#define TWI_STAT_RXD_NAK		(0x58) 	/* date byte received in master mode,not ack transmitted */
/* Slave mode use only */
#define TWI_STAT_RXWS_ACK		(0x60) 	/* Slave address+Write bit received, ACK transmitted */
#define TWI_STAT_ARBLOST_RXWS_ACK	(0x68)	/* Arbitration lost in address as master, slave address + Write bit received, ACK transmitted */
#define TWI_STAT_RXGCAS_ACK		(0x70) 	/* General Call address received, ACK transmitted */
#define TWI_STAT_ARBLOST_RXGCAS_ACK	(0x78)	/* Arbitration lost in address as master, General Call address received, ACK transmitted */
#define TWI_STAT_RXDS_ACK		(0x80)	/* Data byte received after slave address received, ACK transmitted */
#define TWI_STAT_RXDS_NAK		(0x88)	/* Data byte received after slave address received, not ACK transmitted */
#define TWI_STAT_RXDGCAS_ACK		(0x90)	/* Data byte received after General Call received, ACK transmitted */
#define TWI_STAT_RXDGCAS_NAK		(0x98)	/* Data byte received after General Call received, not ACK transmitted */
#define TWI_STAT_RXSTPS_RXRESTAS	(0xA0)	/* STOP or repeated START condition received in slave  */
#define TWI_STAT_RXRS_ACK		(0xA8)	/* Slave address + Read bit received, ACK transmitted */
#define TWI_STAT_ARBLOST_SLAR_ACK       (0xB0)	/* Arbitration lost in address as master, slave address + Read bit received, ACK transmitted */
#define TWI_STAT_TXDS_ACK		(0xB8)  /* Data byte transmitted in slave mode, ACK received */
#define TWI_STAT_TXDS_NAK		(0xC0)	/* Data byte transmitted in slave mode, ACK not received */
#define TWI_STAT_TXDSL_ACK		(0xC8)	/* Last byte transmitted in slave mode, ACK received */

/* 10bit Address, second part of address */
#define TWI_STAT_TX_SAW_ACK             (0xD0) 	/* Second Address byte+Write bit transmitted,ACK received */
#define TWI_STAT_TX_SAW_NAK             (0xD8) 	/* Second Address byte+Write bit transmitted,ACK not received */

#define TWI_STAT_IDLE			(0xF8) 	/* No relevant status infomation,INT_FLAG = 0 */

#endif
