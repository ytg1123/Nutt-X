
#define _NFTL_UBOOT_INTERFACE_C_

#include "../nftl_interface/nftl_blk.h"
#include "../phy/phy.h"
#include "../nftl/nftl_inc.h"

struct _nftl_blk nftl_blk_head = {0};

extern struct _nand_partition* build_nand_partition(struct _nand_phy_partition* phy_partition);
extern int free_nand_partition(struct _nand_partition*nand_partition);

int _nand_read(struct _nftl_blk *nftl_blk,uint32 start_sector,uint32 len,unsigned char *buf);
int _nand_write(struct _nftl_blk *nftl_blk,uint32 start_sector,uint32 len,unsigned char *buf);
int _nand_flush_write_cache(struct _nftl_blk *nftl_blk,uint32 num);
uint32 nftl_flush_write_cache(void);
int recovery_panic_data(struct _nftl_blk *nftl_blk);

/*****************************************************************************
*Name         :
*Description  :
*Parameter    :
*Return       :
*Note         :
*****************************************************************************/
int nftl_build_all(struct _nand_info*nand_info)
{
	struct _nand_phy_partition*  phy_partition;

	phy_partition = nand_info->phy_partition_head;

    nftl_blk_head.nftl_blk_next = NULL;
	while(phy_partition != NULL)
	{
		if(nftl_add(phy_partition) == NULL)
		{
			NFTL_ERR("[NE]nftl_build_all error!\n");
			return NFTL_FAILURE;
		}
		phy_partition = phy_partition->next_phy_partition;
	}

	return 0;
}

/*****************************************************************************
*Name         :
*Description  :
*Parameter    :
*Return       :
*Note         :
*****************************************************************************/
int nftl_build_one(struct _nand_info*nand_info,uint32 num)
{
	struct _nand_phy_partition*  phy_partition;

	phy_partition = nand_info->phy_partition_head;

	if(num == 0)
	    nftl_blk_head.nftl_blk_next = NULL;

	while(phy_partition != NULL)
	{
	    if(phy_partition->PartitionNO == num)
	    {
		    if(nftl_add(phy_partition) == NULL)
		    {
			    NFTL_ERR("[NE]nftl_build_all error!\n");
			    return NFTL_FAILURE;
		    }
		}
		phy_partition = phy_partition->next_phy_partition;
	}

	return 0;
}

/*****************************************************************************
*Name         :
*Description  :
*Parameter    :
*Return       :
*Note         :
*****************************************************************************/
struct _nftl_blk * nftl_add(struct _nand_phy_partition* phy_partition)
{
    struct _nftl_blk *nftl_blk;

    nftl_blk = nftl_malloc(sizeof(struct _nftl_blk));
    if (!nftl_blk)
    {
        NFTL_ERR("[NE]====no memory!!!!!=====\n");
        return NULL;
    }

     nftl_blk->nand = build_nand_partition(phy_partition);

//    nftl_blk->nftl_lock = nftl_malloc(sizeof(struct mutex));
//    if (!nftl_blk->nftl_lock)
//        return;

//    mutex_init(nftl_blk->nftl_lock);

//    nftl_blk->nb.notifier_call = nftl_reboot_notifier;
////  nftl_blk->nb.priority = 1;
//    nftl_blk->reboot_flag = 0;
//    register_reboot_notifier(&nftl_blk->nb);
//    nftl_blk->time_flush = NFTL_FLUSH_DATA_TIME * HZ;
    if (nftl_initialize(nftl_blk,phy_partition->PartitionNO)){
        NFTL_ERR("[NE]nftl_initialize failed\n");
        return NULL;
    }

//    nftl_blk->nftl_thread = kthread_run(nftl_thread, nftl_blk, "%sd", "nftl");
//    if (IS_ERR(nftl_blk->nftl_thread))
//        return;

    add_nftl_blk_list(&nftl_blk_head,nftl_blk);
    
    recovery_panic_data(nftl_blk);
    nftl_blk->flush_write_cache(nftl_blk,0xffff);
    
    NFTL_DBG("[ND]nftl_add ok\n");
    return nftl_blk;
}

/*****************************************************************************
*Name         :
*Description  :
*Parameter    :
*Return       :
*Note         :
*****************************************************************************/
int nand_ftl_exit(void)
{
    struct _nftl_blk *nftl_blk;

    nftl_blk = del_last_nftl_blk(&nftl_blk_head);
    while(nftl_blk != NULL)
    {
        nftl_exit(nftl_blk);
        nftl_free(nftl_blk);
        nftl_blk = del_last_nftl_blk(&nftl_blk_head);
    }
    return 0;
}

/*****************************************************************************
*Name         :
*Description  :
*Parameter    :
*Return       :
*Note         :
*****************************************************************************/
void print_all_nftl_blk(void)
{
    struct _nftl_blk * p;

    p = &nftl_blk_head;
    while(p->nftl_blk_next != NULL)
    {
        NFTL_DBG("[ND]cap: 0x%08x.\n",p->nftl_blk_next->nftl_logic_size);
        p = p->nftl_blk_next;
    }
}

/*****************************************************************************
*Name         :
*Description  :
*Parameter    :
*Return       :
*Note         :
*****************************************************************************/
uint32 get_nftl_num(void)
{
    uint32 num = 0;

    struct _nftl_blk * p;

    p = &nftl_blk_head;
    while(p->nftl_blk_next != NULL)
    {
		num++;
        p = p->nftl_blk_next;
    }
	return num;
}

/*****************************************************************************
*Name         :
*Description  :
*Parameter    :
*Return       :
*Note         :
*****************************************************************************/
uint32 get_nftl_cap(void)
{
	uint32 cap = 0;
    struct _nftl_blk * p;

    p = &nftl_blk_head;
    while(p->nftl_blk_next != NULL)
    {
		cap += p->nftl_blk_next->nftl_logic_size;
        p = p->nftl_blk_next;
    }
	return cap;
}

/*****************************************************************************
*Name         :
*Description  :
*Parameter    :
*Return       :
*Note         :
*****************************************************************************/
uint32 get_first_nftl_cap(void)
{
	uint32 cap = 0;
    struct _nftl_blk * p;
    p = &nftl_blk_head;
    return p->nftl_blk_next->nftl_logic_size;
}

/*****************************************************************************
*Name         :
*Description  :
*Parameter    :
*Return       :
*Note         :
*****************************************************************************/
uint32 nftl_read(uint32 start_sector,uint32 len,unsigned char *buf)
{
    struct _nftl_blk *nftl_blk;
    nftl_blk = nftl_blk_head.nftl_blk_next;

    if(len == 0)
    {
        return 0;
    }

    while(start_sector >= nftl_blk->nftl_logic_size)
    {
        start_sector -= nftl_blk->nftl_logic_size;
        nftl_blk = nftl_blk->nftl_blk_next;
        if(nftl_blk == NULL)
        {
            NFTL_ERR("[NE]parameter error %d,%d !\n",start_sector,len);
            return NFTL_FAILURE;
        }
    }

    return nftl_blk->read_data(nftl_blk,start_sector,len,buf);
}

/*****************************************************************************
*Name         :
*Description  :
*Parameter    :
*Return       :
*Note         :
*****************************************************************************/
uint32 nftl_write(uint32 start_sector,uint32 len,unsigned char *buf)
{
    struct _nftl_blk *nftl_blk;
    nftl_blk = nftl_blk_head.nftl_blk_next;

    if(len == 0)
    {
        return 0;
    }

    while(start_sector >= nftl_blk->nftl_logic_size)
    {
        start_sector -= nftl_blk->nftl_logic_size;
        nftl_blk = nftl_blk->nftl_blk_next;
        if(nftl_blk == NULL)
        {
            NFTL_ERR("[NE]parameter error %d,%d !\n",start_sector,len);
            return NFTL_FAILURE;
        }
    }

    return nftl_blk->write_data(nftl_blk,start_sector,len,buf);
}

/*****************************************************************************
*Name         :
*Description  :
*Parameter    :
*Return       :
*Note         :
*****************************************************************************/
uint32 nftl_discard(uint32 start_sector,uint32 len)
{
    struct _nftl_blk *nftl_blk;
    nftl_blk = nftl_blk_head.nftl_blk_next;

    if(len == 0)
    {
        return 0;
    }

    while(start_sector >= nftl_blk->nftl_logic_size)
    {
        start_sector -= nftl_blk->nftl_logic_size;
        nftl_blk = nftl_blk->nftl_blk_next;
        if(nftl_blk == NULL)
        {
            NFTL_ERR("[NE]parameter error %d,%d !\n",start_sector,len);
            return NFTL_FAILURE;
        }
    }

    return nftl_blk->discard(nftl_blk,start_sector,len);
}

/*****************************************************************************
*Name         :
*Description  :
*Parameter    :
*Return       :
*Note         :
*****************************************************************************/
uint32 nftl_flush_write_cache(void)
{
    struct _nftl_blk *nftl_blk;
    nftl_blk = nftl_blk_head.nftl_blk_next;

    while(nftl_blk != NULL)
    {
        nftl_blk->flush_write_cache(nftl_blk,0xffff);
        nftl_blk = nftl_blk->nftl_blk_next;
    }
	return 0;
}

#define PANIC_NUM	4
struct panic_info {
	uint32 block;
	uint32 start_pages;
	uint32 pages;
	uint32 order;
	uint32 start_sector;
	uint32 sector_num;
	uint32 resver[2];
};//16Bytes align

struct panic_info _panic_info[PANIC_NUM] = {0};
uint32	g_panic_count = 0;

/*****************************************************************************
*Name         :
*Description  :
*Parameter    :
*Return       :
*Note         :
*****************************************************************************/
static int find_write_panic_info(struct _nftl_blk *nftl_blk, char *buf)
{
	int ret;
	struct _nftl_zone * zone;
	_phy_block_info* p_phy_panic_info_block;
	_physic_op_par phy_op_par;
	uint32 pg, j;
	int i;
	uchar spare_data[BYTES_OF_USER_PER_PAGE] = {0};
	uint16 erase_num;

    zone = nftl_blk->nftl_zone;
	p_phy_panic_info_block = zone->panic_data.block[MAX_PANIC_BLOCK_NUM - 1];
	NFTL_ERR("[ND]p_phy_panic_info_block->phy_block.Block_NO = %d\n", p_phy_panic_info_block->phy_block.Block_NO);//for debug

	for(pg = 4 * PANIC_NUM + 4; pg > 0; pg--)
	{
		NFTL_ERR("[ND]read panic info data block: %d page %d !\n", p_phy_panic_info_block->phy_block.Block_NO, pg);
		set_physic_op_par(&phy_op_par, p_phy_panic_info_block->phy_block.Block_NO, pg, zone->nand_chip->bitmap_per_page, buf, spare_data);//for debug
		ret = zone->nftl_nand_read_page(zone,&phy_op_par);
//		if (ret < 0)	//no need ret
//			continue;
		if((spare_data[SPARE_OFFSET_BAD_FLAG] == 0xff) 
			&& (spare_data[SPARE_OFFSET_SPECIAL_FLAG] == SPARE_SPECIAL_DATA)
			&& (spare_data[SPARE_OFFSET_PANIC_FLAG] == BLOCK_FOR_PANIC_INFO_BLK))
		{
			memcpy(_panic_info, buf, sizeof(struct panic_info) * PANIC_NUM);
			break;		
		}	
	}
	if (pg == 0)
	{
		NFTL_ERR("[ND]not find panic info!\n");
		return -1;	
	}	

	for (i = 3; i >= 0; i--)
	{
		NFTL_ERR("_panic_info[%d].order = %d\n", i, _panic_info[i].order);//for debug
		if(_panic_info[i].order == i) 
		{
			g_panic_count = _panic_info[i].order + 1;
			break;		
		}
	}
	NFTL_ERR("g_panic_count = %d !\n", g_panic_count);//for debug
	
	//for debug
	NFTL_ERR("panic_info :\n");
	for(i = 0; i < sizeof(struct panic_info) * PANIC_NUM; i++) 
	{
		if(i % 16 == 0)
			NFTL_ERR("%4d:	", i);
		NFTL_ERR("%.2x ", *buf++);
		if(i % 16 == 15)
			NFTL_ERR("\n");
	}

	//erase panic info block
    erase_num = p_phy_panic_info_block->erase_count+ 1;
	NFTL_ERR("[ND]%s[%d], phy_block.Block_NO = %d, erase_num = %d\n",
		__FUNCTION__, __LINE__, p_phy_panic_info_block->phy_block.Block_NO, erase_num);//for debug
    erase_block(zone, p_phy_panic_info_block, erase_num);

	return 0;
}

/*****************************************************************************
*Name         :
*Description  :
*Parameter    :
*Return       :
*Note         :
*****************************************************************************/
int recovery_panic_data(struct _nftl_blk *nftl_blk)
{
    int ret;
    uchar* page_buf = NULL;
    uchar spare_data[BYTES_OF_USER_PER_PAGE];
    _physic_op_par phy_op_par;
    uint32 start_sector, i, j, k,total_len, data_pages,spare_sector;
    uint16 erase_num;
    struct _nftl_zone * zone;
	_phy_block_info* p_phy_panic_info_block;
	uint32 start_block = 0, start_page = 0;

    zone = nftl_blk->nftl_zone;

	NFTL_ERR("[ND]%s[%d]\n", __FUNCTION__, __LINE__);//for debug
#if 0	
    if(zone->panic_data.data_block_nums != zone->panic_data.block_nums)
    {
        NFTL_ERR("[ND]data_block_nums %d block_nums %d!!\n",zone->panic_data.data_block_nums,zone->panic_data.block_nums);
        for(i=0; i<MAX_PANIC_BLOCK_NUM; i++)
        {
            if(zone->panic_data.block[i] != NULL)
            {
                NFTL_ERR("[ND]erase panic block %d!\n",zone->panic_data.block[i]->phy_block.Block_NO);
                erase_num = zone->panic_data.block[i]->erase_count + 1;
                erase_block(zone,zone->panic_data.block[i],erase_num);
            }
        }
        return 1;
    }
#endif	

	NFTL_ERR("[ND]%s[%d]\n", __FUNCTION__, __LINE__);//for debug
    if(zone->panic_data.data_block_nums == 0)
    {
        NFTL_ERR("[ND]not find panic data!\n");
        return 0;
    }

    NFTL_ERR("[ND]recovery_panic_data start!\n");
    NFTL_ERR("[ND]logic_addr :%d sector_nums: %d!\n",zone->panic_data.logic_addr,zone->panic_data.sector_nums);
    NFTL_ERR("[ND]data_block_nums %d !\n",zone->panic_data.data_block_nums);
    for(i=0; i<zone->panic_data.data_block_nums; i++)
    {
        NFTL_ERR("[ND]block %d !\n",zone->panic_data.block[i]->phy_block.Block_NO);
    }

    page_buf = (uchar *)nftl_malloc(zone->nand_chip->bytes_per_page);
	if (page_buf == NULL)
	{
        NFTL_ERR("[ND]%s[%d] malloc fail\n", __FUNCTION__, __LINE__);
        return -1;		
	}

	if(find_write_panic_info(nftl_blk, page_buf) < 0)
		return -1;
	
    total_len = 0;
	for(i = 0; i < g_panic_count; i++)
	{
		start_sector = _panic_info[i].start_sector;
		data_pages = _panic_info[i].pages;
    	spare_sector = 0;
		/*align*/
	    if((zone->panic_data.sector_nums % zone->nand_chip->sector_per_page) != 0)
	    {
	        spare_sector = zone->panic_data.sector_nums % zone->nand_chip->sector_per_page;
	    }
		start_block = _panic_info[i].block;
		start_page = _panic_info[i].start_pages;

		NFTL_ERR("[ND]%s[%d], start_block = %d, start_page = %d, start_sector = %d, data_pages = %d, spare_sector = %d\n",
			__FUNCTION__, __LINE__, start_block, start_page, start_sector, data_pages, spare_sector);//for debug
		j = start_page;

	    for(k = 0; k < MAX_PANIC_BLOCK_NUM - 1; k++)
	    {
	        if(data_pages == 0)
	        {
	            break;
	        }
	        for(j; j < zone->nand_chip->pages_per_blk; j++)
	        {
		        set_physic_op_par(&phy_op_par, start_block, j ,zone->nand_chip->bitmap_per_page, page_buf,spare_data);
		        ret = zone->nftl_nand_read_page(zone,&phy_op_par);
		        
		        NFTL_ERR("[ND]read painc data block:%d page: %d  data:%d %d %d %d !\n", start_block, j, page_buf[0], page_buf[1], page_buf[2], page_buf[3]);
		        if((data_pages == 1)&& (spare_sector != 0))
		        {
		            ret = nftl_write(start_sector,spare_sector,page_buf);
		        }
		        else
		        {
		            ret = nftl_write(start_sector,zone->nand_chip->sector_per_page,page_buf);
		        }

		        start_sector += zone->nand_chip->sector_per_page;
		        data_pages--;
		        if(data_pages == 0)
		        {
					break;
		        }
				
	        }
			if (j >= zone->nand_chip->pages_per_blk)
			{
				start_block = _panic_info[i + 1].block;
				j = 0;
			}
		}
	}
#if 1
	for(i=0; i < zone->panic_data.block_nums; i++)
    {
    	p_phy_panic_info_block = zone->panic_data.block[i];
        erase_num = p_phy_panic_info_block->erase_count+ 1;
		NFTL_ERR("[ND]%s[%d], phy_block.Block_NO = %d, erase_num = %d\n",
			__FUNCTION__, __LINE__, p_phy_panic_info_block->phy_block.Block_NO, erase_num);
        erase_block(zone, p_phy_panic_info_block, erase_num);
    }
#endif
    nftl_free(page_buf);

    return ret;
}
